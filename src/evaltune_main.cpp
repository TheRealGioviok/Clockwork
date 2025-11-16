#include "eval_constants.hpp"
#include "eval_types.hpp"
#include "evaluation.hpp"
#include "tuning/dataset.hpp"
#include "position.hpp"
#include "tuning/graph.hpp"
#include "tuning/loss.hpp"
#include "tuning/optim.hpp"
#include "tuning/value.hpp"
#include "util/pretty.hpp"
#include "util/types.hpp"

#include <algorithm>
#include <atomic>
#include <barrier>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <numeric>
#include <optional>
#include <random>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>

using namespace Clockwork;

class ArgParser {
public:
    ArgParser(std::span<char*> args) {
        for (size_t i = 1; i < args.size(); ++i) {
            std::string_view key = args[i];
            if (key.rfind("--", 0) == 0) {
                if (i + 1 >= args.size()) {
                    throw std::runtime_error("Missing value after " + std::string(key));
                }
                std::string_view val       = args[i + 1];
                options_[std::string(key)] = std::string(val);
                ++i;
            }
        }
    }

    template<typename T>
    std::optional<T> get(std::string_view name) const {
        auto it = options_.find(std::string(name));
        if (it == options_.end()) {
            return std::nullopt;
        }
        return convert<T>(it->second);
    }

private:
    std::unordered_map<std::string, std::string> options_;

    template<typename T>
    static T convert(const std::string& s) {
        if constexpr (std::is_same_v<T, std::string>) {
            return s;
        } else if constexpr (std::is_integral_v<T>) {
            return static_cast<T>(std::stoll(s));
        } else if constexpr (std::is_floating_point_v<T>) {
            return static_cast<T>(std::stod(s));
        } else {
            static_assert(!sizeof(T*), "Unsupported type in ArgParser::get");
        }
    }
};

int main(int argc, char* argv[]) {
    // CLI
    std::span<char*> args(argv, argc);
    ArgParser        ap(args);

    u32    thread_count = std::max<u32>(1, std::thread::hardware_concurrency() / 2);
    i32    epochs       = 1000;
    size_t batch_size   = 16 * 16384;

    if (auto t = ap.get<u32>("--threads")) {
        thread_count = *t;
    }
    if (auto t = ap.get<u32>("--t")) {
        thread_count = *t;
    }
    if (auto bs = ap.get<size_t>("--batch")) {
        batch_size = *bs;
    }
    if (auto e = ap.get<int>("--epochs")) {
        epochs = *e;
    }

    std::cout << "Running on " << thread_count << " threads" << std::endl;

    // Construct dataset (files)
    Clockwork::Autograd::PersyFormatDataset dataset{"data/dfrcv1.txt", "data/dfrcv0.txt", "data/v2.2.txt",
                               "data/v2.1.txt", "data/v3.txt"};

    // Load parsed positions/results into memory
    dataset.load();

    std::cout << "Loaded " << dataset.size() << " FENs." << std::endl;
    if (dataset.size() == 0) {
        std::cerr << "No positions loaded!" << std::endl;
        return 1;
    }

    using namespace Clockwork::Autograd;

    const ParameterCountInfo parameter_count          = Globals::get().get_parameter_counts();
    Parameters               current_parameter_values = Parameters::zeros(parameter_count);

    AdamW        optim(parameter_count, 10, 0.9, 0.999, 1e-8, 0.0);
    const f64    K = 1.0 / 400.0;
    std::mt19937 rng(std::random_device{}());

    const size_t total_batches = (dataset.size() + batch_size - 1) / batch_size;

    Parameters          batch_gradients = Parameters::zeros(parameter_count);
    std::atomic<size_t> current_batch_size_global{0};

    std::mutex   mutex;
    std::barrier epoch_barrier{static_cast<int>(thread_count + 1)};

    // Barrier completion: normalize accumulated gradients and step optimizer.
    std::barrier batch_barrier{static_cast<int>(thread_count + 1), [&]() noexcept {
                                   const size_t N =
                                     current_batch_size_global.load(std::memory_order_relaxed);
                                   if (N == 0) {
                                       std::cerr << "Error: batch size is zero!" << std::endl;
                                       return;
                                   }

                                   std::lock_guard guard{mutex};
                                   batch_gradients.scale(1.0 / static_cast<double>(N));
                                   optim.step(current_parameter_values, batch_gradients);
                                   batch_gradients = Parameters::zeros(parameter_count);
                               }};

    // Worker threads
    for (u32 thread_idx = 0; thread_idx < thread_count; ++thread_idx) {
        std::thread([&, thread_idx] {
            Graph::get().cleanup();

            std::vector<ValuePtr> subbatch_outputs;
            std::vector<f64>      subbatch_targets;

            const size_t prefetch_depth = 2;  // tuneable

            for (i32 epoch = 0; epoch < epochs; ++epoch) {
                // wait until main has shuffled and is ready
                epoch_barrier.arrive_and_wait();

                // Iterate over zero-copy batches (span-based)
                for (auto it  = dataset.batches(batch_size, prefetch_depth).begin(),
                          end = dataset.batches(batch_size, prefetch_depth).end();
                     it != end; ++it) {

                    auto batch =
                      *it;  // BatchView: { std::span<const Position>, std::span<const f64> }
                    const size_t current_batch_size = batch.positions.size();

                    // Split this batch among threads (index slicing)
                    const size_t subbatch_size =
                      (current_batch_size + thread_count - 1) / thread_count;
                    const size_t subbatch_start =
                      std::min(subbatch_size * static_cast<size_t>(thread_idx), current_batch_size);
                    const size_t subbatch_end =
                      std::min(subbatch_start + subbatch_size, current_batch_size);
                    const size_t current_subbatch_size =
                      (subbatch_end > subbatch_start) ? (subbatch_end - subbatch_start) : 0;

                    subbatch_outputs.clear();
                    subbatch_targets.clear();
                    subbatch_outputs.reserve(current_subbatch_size);
                    subbatch_targets.reserve(current_subbatch_size);

                    // Copy the latest parameters into this thread's graph
                    Graph::get().copy_parameter_values(current_parameter_values);

                    // Process items in this thread's slice; produce microbatches of 1024 as before
                    uint32_t i = 0;
                    for (size_t local_idx = subbatch_start; local_idx < subbatch_end; ++local_idx) {
                        const Position& pos = batch.positions[local_idx];
                        f64             y   = batch.results[local_idx];

                        auto result = (evaluate_white_pov(pos) * K)->sigmoid();
                        subbatch_outputs.push_back(result);
                        subbatch_targets.push_back(y);

                        if (++i == 1024) {
                            i = 0;
                            auto subbatch_loss =
                              mse<f64, Reduction::Sum>(subbatch_outputs, subbatch_targets);
                            Graph::get().backward();
                            Graph::get().clear_backwardables();
                            subbatch_outputs.clear();
                            subbatch_targets.clear();
                        }
                    }

                    // final microbatch for this thread's slice
                    if (!subbatch_outputs.empty()) {
                        auto subbatch_loss =
                          mse<f64, Reduction::Sum>(subbatch_outputs, subbatch_targets);
                        Graph::get().backward();
                        Graph::get().clear_backwardables();
                        subbatch_outputs.clear();
                        subbatch_targets.clear();
                    }

                    // Extract accumulated parameter gradients for this thread's work
                    Parameters subbatch_gradients = Graph::get().get_all_parameter_gradients();
                    {
                        std::lock_guard guard{mutex};
                        batch_gradients.accumulate(subbatch_gradients);
                    }

                    // Wait for main thread to set global batch size + other workers
                    batch_barrier.arrive_and_wait();

                    Graph::get().cleanup();
                }  // end batch loop
            }  // end epoch
        }).detach();
    }  // end spawn threads

    // Main thread: orchestrates epochs and barrier sync. Uses same batch iteration order.
    const size_t prefetch_depth_main = 2;
    for (i32 epoch = 0; epoch < epochs; ++epoch) {
        std::cout << "Epoch " << (epoch + 1) << "/" << epochs << std::endl;
        const auto epoch_start_time = time::Clock::now();

        // shuffle dataset indices before workers start
        dataset.shuffle_indices(rng);

        // let workers start epoch
        epoch_barrier.arrive_and_wait();

        // Iterate batches in the same order as workers; for each batch set global batch size
        size_t batch_idx = 0;
        for (auto it  = dataset.batches(batch_size, prefetch_depth_main).begin(),
                  end = dataset.batches(batch_size, prefetch_depth_main).end();
             it != end; ++it, ++batch_idx) {

            auto         batch              = *it;
            const size_t current_batch_size = batch.positions.size();

            // publish true (possibly smaller for last batch) batch size
            current_batch_size_global.store(current_batch_size, std::memory_order_relaxed);

            // synchronize with workers; barrier completion will normalize & step optimizer
            batch_barrier.arrive_and_wait();

            // print progress
            print_progress(batch_idx + 1, total_batches);
        }

        const auto epoch_end_time = time::Clock::now();
        std::cout << std::endl;  // finish progress bar line

        // show parameter snapshot
        Graph::get().copy_parameter_values(current_parameter_values);

        std::cout << "inline const PParam PAWN_MAT   = " << PAWN_MAT << ";" << std::endl;
        std::cout << "inline const PParam KNIGHT_MAT = " << KNIGHT_MAT << ";" << std::endl;
        std::cout << "inline const PParam BISHOP_MAT = " << BISHOP_MAT << ";" << std::endl;
        std::cout << "inline const PParam ROOK_MAT   = " << ROOK_MAT << ";" << std::endl;
        std::cout << "inline const PParam QUEEN_MAT  = " << QUEEN_MAT << ";" << std::endl;
        std::cout << "inline const PParam TEMPO_VAL  = " << TEMPO_VAL << ";" << std::endl;
        std::cout << std::endl;

        std::cout << "inline const PParam BISHOP_PAIR_VAL   = " << BISHOP_PAIR_VAL << ";"
                  << std::endl;
        std::cout << "inline const PParam ROOK_OPEN_VAL     = " << ROOK_OPEN_VAL << ";"
                  << std::endl;
        std::cout << "inline const PParam ROOK_SEMIOPEN_VAL = " << ROOK_SEMIOPEN_VAL << ";"
                  << std::endl;
        std::cout << std::endl;
        std::cout << "inline const PParam DOUBLED_PAWN_VAL = " << DOUBLED_PAWN_VAL << ";"
                  << std::endl;
        std::cout << std::endl;

        std::cout << "inline const PParam POTENTIAL_CHECKER_VAL = " << POTENTIAL_CHECKER_VAL << ";"
                  << std::endl;

        std::cout << "inline const PParam OUTPOST_KNIGHT_VAL    = " << OUTPOST_KNIGHT_VAL << ";"
                  << std::endl;
        std::cout << "inline const PParam OUTPOST_BISHOP_VAL    = " << OUTPOST_BISHOP_VAL << ";"
                  << std::endl;

        std::cout << std::endl;

        std::cout << "inline const PParam PAWN_PUSH_THREAT_KNIGHT = " << PAWN_PUSH_THREAT_KNIGHT
                  << ";" << std::endl;
        std::cout << "inline const PParam PAWN_PUSH_THREAT_BISHOP = " << PAWN_PUSH_THREAT_BISHOP
                  << ";" << std::endl;
        std::cout << "inline const PParam PAWN_PUSH_THREAT_ROOK   = " << PAWN_PUSH_THREAT_ROOK
                  << ";" << std::endl;
        std::cout << "inline const PParam PAWN_PUSH_THREAT_QUEEN  = " << PAWN_PUSH_THREAT_QUEEN
                  << ";" << std::endl;
        std::cout << std::endl;

        auto print_table = [](const std::string& name, const auto& table) {
            std::cout << "inline const std::array<PParam, " << table.size() << "> " << name
                      << " = {" << std::endl
                      << "   ";
            for (const auto& val : table) {
                std::cout << " " << val << ",";
            }
            std::cout << std::endl << "};" << std::endl;
        };

        print_table("PAWN_PHALANX", PAWN_PHALANX);
        print_table("DEFENDED_PAWN", DEFENDED_PAWN);
        print_table("PASSED_PAWN", PASSED_PAWN);
        print_table("DEFENDED_PASSED_PUSH", DEFENDED_PASSED_PUSH);
        print_table("BLOCKED_PASSED_PAWN", BLOCKED_PASSED_PAWN);
        std::cout << std::endl;

        print_table("FRIENDLY_KING_PASSED_PAWN_DISTANCE", FRIENDLY_KING_PASSED_PAWN_DISTANCE);
        print_table("ENEMY_KING_PASSED_PAWN_DISTANCE", ENEMY_KING_PASSED_PAWN_DISTANCE);
        std::cout << std::endl;

        print_table("KNIGHT_MOBILITY", KNIGHT_MOBILITY);
        print_table("BISHOP_MOBILITY", BISHOP_MOBILITY);
        print_table("ROOK_MOBILITY", ROOK_MOBILITY);
        print_table("QUEEN_MOBILITY", QUEEN_MOBILITY);
        print_table("KING_MOBILITY", KING_MOBILITY);
        std::cout << std::endl;

        print_table("KNIGHT_KING_RING", KNIGHT_KING_RING);
        print_table("BISHOP_KING_RING", BISHOP_KING_RING);
        print_table("ROOK_KING_RING", ROOK_KING_RING);
        print_table("QUEEN_KING_RING", QUEEN_KING_RING);
        std::cout << std::endl;

        std::cout << "inline const PParam PAWN_THREAT_KNIGHT = " << PAWN_THREAT_KNIGHT << ";"
                  << std::endl;
        std::cout << "inline const PParam PAWN_THREAT_BISHOP = " << PAWN_THREAT_BISHOP << ";"
                  << std::endl;
        std::cout << "inline const PParam PAWN_THREAT_ROOK   = " << PAWN_THREAT_ROOK << ";"
                  << std::endl;
        std::cout << "inline const PParam PAWN_THREAT_QUEEN  = " << PAWN_THREAT_QUEEN << ";"
                  << std::endl;
        std::cout << std::endl;

        std::cout << "inline const PParam KNIGHT_THREAT_BISHOP = " << KNIGHT_THREAT_BISHOP << ";"
                  << std::endl;
        std::cout << "inline const PParam KNIGHT_THREAT_ROOK   = " << KNIGHT_THREAT_ROOK << ";"
                  << std::endl;
        std::cout << "inline const PParam KNIGHT_THREAT_QUEEN  = " << KNIGHT_THREAT_QUEEN << ";"
                  << std::endl;
        std::cout << std::endl;

        std::cout << "inline const PParam BISHOP_THREAT_KNIGHT = " << BISHOP_THREAT_KNIGHT << ";"
                  << std::endl;
        std::cout << "inline const PParam BISHOP_THREAT_ROOK   = " << BISHOP_THREAT_ROOK << ";"
                  << std::endl;
        std::cout << "inline const PParam BISHOP_THREAT_QUEEN  = " << BISHOP_THREAT_QUEEN << ";"
                  << std::endl;
        std::cout << std::endl;

        print_table("BISHOP_PAWNS", BISHOP_PAWNS);
        std::cout << std::endl;

        auto printPsqtArray = [](const std::string& name, const auto& arr) {
            std::cout << "inline const std::array<PParam, " << arr.size() << "> " << name << " = {"
                      << std::endl;
            for (std::size_t i = 0; i < arr.size(); ++i) {
                if ((i & 7) == 0) {
                    std::cout << "    ";
                }
                std::stringstream ss;
                ss << arr[i] << ",";
                std::cout << std::left << std::setw(16) << ss.str();
                if ((i & 7) == 7) {
                    std::cout << "//" << std::endl;
                }
            }
            std::cout << "};" << std::endl;
        };

        printPsqtArray("PAWN_PSQT", PAWN_PSQT);
        printPsqtArray("KNIGHT_PSQT", KNIGHT_PSQT);
        printPsqtArray("BISHOP_PSQT", BISHOP_PSQT);
        printPsqtArray("ROOK_PSQT", ROOK_PSQT);
        printPsqtArray("QUEEN_PSQT", QUEEN_PSQT);
        printPsqtArray("KING_PSQT", KING_PSQT);

        std::cout << "// Epoch duration: "
                  << time::cast<time::FloatSeconds>(epoch_end_time - epoch_start_time).count()
                  << "s" << std::endl;

        if (epoch > 5) {
            optim.set_lr(optim.get_lr() * 0.975);
        }
    }

    return 0;
}
