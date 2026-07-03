#include "eval_constants.hpp"
#include "eval_types.hpp"
#include "evaluation.hpp"
#include "position.hpp"

#include "tuning/gamefile.hpp"
#include "tuning/graph.hpp"
#include "tuning/loss.hpp"
#include "tuning/optim.hpp"
#include "tuning/pgn.hpp"
#include "tuning/value.hpp"

#include "util/mem.hpp"
#include "util/pretty.hpp"
#include "util/types.hpp"

#include <algorithm>
#include <array>
#include <atomic>
#include <barrier>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <span>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>

using namespace Clockwork;
using namespace Clockwork::Autograd;

void print_params();

namespace {

struct GameRecord {
    Position             start;
    std::span<const u16> moves;
    std::span<const u8>  flags;
    f64                  result;  // white POV: 1.0 / 0.5 / 0.0
};

// Desired (unnormalized) phase distribution shape, ported from scripts/phase-dist-filter.py.
f64 phase_scale_factor(u8 phase) {
    f64 odd_scale = std::min(0.9, -0.09793221 * (phase - 23.0) + 0.189393939);
    f64 p16       = std::abs(phase - 16.0);
    f64 base      = phase > 16 ? 1.0 - 0.875 * (p16 / 8.0) * (p16 / 8.0)
                               : 1.0 - 0.95 * (p16 / 16.0) * (p16 / 16.0);
    if (phase % 2 != 0 && phase > 12) {
        return odd_scale * base;
    }
    return base;
}

// Replays every game once, keeping eligible positions with per-phase probability.
// positions/results have fixed capacity; returns the number of slots filled.
usize sample_positions(const std::vector<GameRecord>& games,
                       const std::array<f64, 25>&     keep_probs,
                       std::vector<Position>&         positions,
                       std::vector<f64>&              results,
                       u64                            seed,
                       u32                            thread_count) {
    constexpr u32 MAX_PER_GAME = 10;

    const usize capacity = positions.size();

    // Shuffle game traversal order so that, if the buffer fills before every
    // game is scanned, the skipped games are a random subset rather than
    // always the tail of the concatenated input files.
    std::vector<usize> order(games.size());
    std::iota(order.begin(), order.end(), 0);
    {
        std::mt19937_64 order_rng(seed ^ 0xD1B54A32D192ED03ULL);
        std::shuffle(order.begin(), order.end(), order_rng);
    }

    std::atomic<usize> cursor{0};
    std::atomic<usize> out{0};
    std::atomic<usize> games_used{0};         // games that wrote >=1 position
    std::atomic<usize> games_reservoired{0};  // games that exceeded MAX_PER_GAME and were thinned
    std::atomic<usize> games_truncated{0};    // games cut short (partially or fully) by capacity

    std::vector<std::thread> threads;
    threads.reserve(thread_count);
    for (u32 t = 0; t < thread_count; ++t) {
        threads.emplace_back([&, t]() {
            std::mt19937_64                     rng(seed ^ (0x9E3779B97F4A7C15ULL * (t + 1)));
            std::uniform_real_distribution<f64> uni(0.0, 1.0);
            std::vector<u32>                    accepted;

            for (;;) {
                usize slot = cursor.fetch_add(1, std::memory_order_relaxed);
                if (slot >= order.size()) {
                    return;
                }
                usize             g    = order[slot];
                const GameRecord& game = games[g];

                // Pre-roll acceptance so games with no accepted positions are skipped
                // entirely and replay stops at the last accepted ply.
                accepted.clear();
                for (u32 i = 0; i < game.flags.size(); ++i) {
                    u8 f = game.flags[i];
                    if (Tuning::is_eligible(f) && uni(rng) < keep_probs[Tuning::phase_of(f)]) {
                        accepted.push_back(i);
                    }
                }
                if (accepted.empty()) {
                    continue;
                }

                // Thin to at most MAX_PER_GAME via reservoir sampling, preserving ply
                // order for the replay loop below.
                if (accepted.size() > MAX_PER_GAME) {
                    for (u32 k = MAX_PER_GAME; k < accepted.size(); ++k) {
                        std::uniform_int_distribution<u32> pick(0, k);
                        u32                                j = pick(rng);
                        if (j < MAX_PER_GAME) {
                            accepted[j] = accepted[k];
                        }
                    }
                    accepted.resize(MAX_PER_GAME);
                    std::sort(accepted.begin(), accepted.end());
                    games_reservoired.fetch_add(1, std::memory_order_relaxed);
                }

                usize idx = out.fetch_add(accepted.size(), std::memory_order_relaxed);
                if (idx >= capacity) {
                    games_truncated.fetch_add(1, std::memory_order_relaxed);
                    return;
                }
                usize writable = std::min(accepted.size(), capacity - idx);

                games_used.fetch_add(1, std::memory_order_relaxed);
                if (writable < accepted.size()) {
                    games_truncated.fetch_add(1, std::memory_order_relaxed);
                }

                Position pos = game.start;
                usize    k   = 0;
                for (u32 i = 0; k < writable; ++i) {
                    Move m;
                    m.raw = game.moves[i];
                    pos   = pos.move(m);
                    if (i == accepted[k]) {
                        positions[idx + k] = pos;
                        results[idx + k]   = game.result;
                        ++k;
                    }
                }
            }
        });
    }
    for (auto& th : threads) {
        th.join();
    }

    const usize scanned = std::min(cursor.load(), games.size());
    std::cout << "Games scanned: " << scanned << " / " << games.size();
    if (scanned < games.size()) {
        std::cout << "  [WARNING: buffer filled early, " << (games.size() - scanned)
                  << " games never inspected]";
    }
    std::cout << "\n";
    std::cout << "Games used: " << games_used.load() << " / " << games.size() << " ("
              << games_reservoired.load() << " reservoir-thinned to " << MAX_PER_GAME << ", "
              << games_truncated.load() << " truncated by capacity)\n";

    return std::min(out.load(), capacity);
}

}  // namespace

// Converts selfplay PGN files into a single .ckg binary game file.
// Usage: clockwork-evaltune pack out.ckg in1.pgn [in2.pgn ...]
static int run_pack(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "usage: clockwork-evaltune pack out.ckg in1.pgn [in2.pgn ...]\n";
        return 1;
    }

    std::ofstream out(argv[2], std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "Error opening " << argv[2] << " for writing\n";
        return 1;
    }
    Tuning::CkgWriter writer{out};

    const u32 thread_count = std::max<u32>(1, std::thread::hardware_concurrency());

    u64 dropped        = 0;
    u64 total_plies    = 0;
    u64 total_eligible = 0;

    constexpr size_t CHUNK = 8192;

    for (int arg = 3; arg < argc; ++arg) {
        std::ifstream in(argv[arg]);
        if (!in) {
            std::cerr << "Error opening " << argv[arg] << "\n";
            return 1;
        }
        Tuning::PgnSplitter splitter(in);

        std::vector<std::string>                    raw;
        std::vector<std::optional<Tuning::PgnGame>> parsed;
        raw.reserve(CHUNK);

        bool done = false;
        while (!done) {
            raw.clear();
            while (raw.size() < CHUNK) {
                auto game_text = splitter.next();
                if (!game_text) {
                    done = true;
                    break;
                }
                raw.push_back(std::move(*game_text));
            }
            if (raw.empty()) {
                break;
            }

            parsed.assign(raw.size(), std::nullopt);
            {
                std::vector<std::thread> threads;
                threads.reserve(thread_count);
                for (u32 t = 0; t < thread_count; ++t) {
                    threads.emplace_back([&, t]() {
                        for (size_t i = t; i < raw.size(); i += thread_count) {
                            parsed[i] = Tuning::parse_pgn_game(raw[i]);
                        }
                    });
                }
                for (auto& th : threads) {
                    th.join();
                }
            }

            for (const auto& game : parsed) {
                if (!game) {
                    dropped++;
                    continue;
                }
                writer.write(*game);
                total_plies += game->moves.size();
                for (u8 f : game->flags) {
                    total_eligible += Tuning::is_eligible(f);
                }
            }

            std::cout << "\r" << writer.games_written() << " games packed (" << dropped
                      << " dropped)" << std::flush;
        }
    }

    writer.finish();
    if (!out) {
        std::cerr << "\nError writing " << argv[2] << "\n";
        return 1;
    }

    std::cout << "\r" << writer.games_written() << " games packed (" << dropped << " dropped), "
              << total_plies << " positions, " << total_eligible << " eligible\n";
    return 0;
}

// Tunes eval parameters against a fresh phase-balanced sample drawn from .ckg game files
// every --refresh epochs.
// Usage: clockwork-evaltune tune data.ckg [more.ckg ...] [--target N] [--epochs N]
//        [--refresh N] [--seed N]
static int run_tune(int argc, char* argv[]) {
    // Todo: make these CLI-specifiable
    const size_t batch_size       = 16 * 16384;
    const size_t micro_batch_size = 160;

    std::vector<std::string> files;
    u64                      target  = 78 * (16384 * 16);
    i32                      epochs  = 450;
    i32                      refresh = 1;
    u64                      seed    = std::random_device{}();

    bool cli_ok = true;
    for (int i = 2; i < argc; ++i) {
        std::string_view arg = argv[i];
        if (!arg.starts_with("--")) {
            files.emplace_back(arg);
            continue;
        }
        if (i + 1 >= argc) {
            cli_ok = false;
            break;
        }
        const char* value = argv[++i];
        if (arg == "--target") {
            target = std::strtoull(value, nullptr, 10);
        } else if (arg == "--epochs") {
            epochs = std::atoi(value);
        } else if (arg == "--refresh") {
            refresh = std::atoi(value);
        } else if (arg == "--seed") {
            seed = std::strtoull(value, nullptr, 10);
        } else {
            cli_ok = false;
            break;
        }
    }
    if (!cli_ok || files.empty() || epochs <= 0 || refresh <= 0 || target == 0) {
        std::cerr << "usage: clockwork-evaltune tune data.ckg [more.ckg ...] [--target N] "
                     "[--epochs N] [--refresh N] [--seed N]\n";
        return 1;
    }

    const u32 thread_count = std::max<u32>(1, std::thread::hardware_concurrency());

    std::cout << "Running on " << thread_count << " threads\n";

    // Load game files. The raw bytes stay alive for the whole run: game views hold
    // spans into them.
    std::vector<std::vector<u8>>     file_data;
    std::vector<Tuning::CkgGameView> views;

    for (const std::string& filename : files) {
        std::ifstream in(filename, std::ios::binary);
        if (!in) {
            std::cerr << "Error opening " << filename << "\n";
            return 1;
        }
        in.seekg(0, std::ios::end);
        std::streamsize size = in.tellg();
        in.seekg(0);
        std::vector<u8> data(static_cast<usize>(size));
        if (!in.read(reinterpret_cast<char*>(data.data()), size)) {
            std::cerr << "Error reading " << filename << "\n";
            return 1;
        }
        file_data.push_back(std::move(data));

        auto reader = Tuning::CkgReader::open(file_data.back());
        if (!reader) {
            std::cerr << filename << " is not a valid .ckg file\n";
            return 1;
        }
        views.reserve(views.size() + reader->game_count());
        while (auto view = reader->next()) {
            views.push_back(*view);
        }
        if (reader->games_read() < reader->game_count()) {
            std::cerr << filename << ": corrupt record after " << reader->games_read() << " of "
                      << reader->game_count() << " games\n";
            return 1;
        }
        std::cout << filename << ": " << reader->games_read() << " games\n";
    }

    if (views.empty()) {
        std::cerr << "No games loaded\n";
        return 1;
    }

    // Rebuild start positions (once: this is the expensive attack table build) and
    // histogram the eligible positions by phase.
    std::vector<GameRecord> games(views.size());
    std::array<u64, 25>     observed{};
    std::atomic<usize>      bad{0};
    {
        std::vector<std::array<u64, 25>> thread_hist(thread_count);
        std::vector<std::thread>         threads;
        threads.reserve(thread_count);
        for (u32 t = 0; t < thread_count; ++t) {
            threads.emplace_back([&, t]() {
                for (usize i = t; i < views.size(); i += thread_count) {
                    auto start = Tuning::reconstruct_start_position(views[i]);
                    if (!start) {
                        bad.fetch_add(1, std::memory_order_relaxed);
                        continue;
                    }
                    games[i] =
                      GameRecord{*start, views[i].moves, views[i].flags,
                                 1.0 - 0.5 * static_cast<f64>(static_cast<u8>(views[i].result))};
                    for (u8 f : views[i].flags) {
                        if (Tuning::is_eligible(f)) {
                            thread_hist[t][Tuning::phase_of(f)]++;
                        }
                    }
                }
            });
        }
        for (auto& th : threads) {
            th.join();
        }
        for (const auto& hist : thread_hist) {
            for (usize p = 0; p < observed.size(); ++p) {
                observed[p] += hist[p];
            }
        }
    }
    if (bad.load() > 0) {
        std::cerr << bad.load() << " games failed start position reconstruction\n";
        return 1;
    }

    // Per-phase keep probabilities: reshape the eligible pool into the desired phase
    // distribution, then scale to the per-epoch target.
    u64 total_eligible = 0;
    for (u64 count : observed) {
        total_eligible += count;
    }

    std::array<f64, 25> keep_probs{};
    f64                 norm_const = std::numeric_limits<f64>::infinity();
    for (usize p = 0; p < keep_probs.size(); ++p) {
        if (observed[p] == 0) {
            continue;
        }
        f64 obs       = static_cast<f64>(observed[p]) / static_cast<f64>(total_eligible);
        f64 desired   = phase_scale_factor(static_cast<u8>(p));
        keep_probs[p] = desired / obs;
        norm_const    = std::min(norm_const, obs / desired);
    }
    f64 expected = 0;
    for (usize p = 0; p < keep_probs.size(); ++p) {
        keep_probs[p] = std::min(keep_probs[p] * norm_const, 1.0);
        expected += static_cast<f64>(observed[p]) * keep_probs[p];
    }
    if (expected > static_cast<f64>(target)) {
        f64 scale = static_cast<f64>(target) / expected;
        for (f64& kp : keep_probs) {
            kp *= scale;
        }
        expected = static_cast<f64>(target);
    } else {
        std::cout << "Note: phase distribution caps the epoch at ~" << static_cast<u64>(expected)
                  << " positions (--target " << target << ")\n";
    }

    std::cout << "Eligible pool: " << total_eligible << " positions over " << games.size()
              << " games, ~" << static_cast<u64>(expected) << " sampled per epoch\n";
    for (usize p = 0; p < keep_probs.size(); ++p) {
        std::cout << "Phase " << p << ": " << observed[p] << " eligible, keep probability "
                  << keep_probs[p] << "\n";
    }

    // Fixed-capacity sample buffers, refilled in place every --refresh epochs.
    const usize capacity = static_cast<usize>(expected * 1.02) + 65536;

    std::vector<Position> positions(capacity);
    std::vector<f64>      results(capacity);
    size_t                n_sampled = 0;

    advise_huge_pages(positions.data(), positions.capacity() * sizeof(Position));
    advise_huge_pages(results.data(), results.capacity() * sizeof(f64));

    // Setup tuning
    const ParameterCountInfo parameter_count = Globals::get().get_parameter_counts();

    // This line loads the defaults from your S() macros
    Parameters current_parameter_values = Graph::get().get_all_parameter_values();

    // Uncomment for zero tune: Overwrite them all with zeros.
    current_parameter_values = Parameters::rand_init(parameter_count);

    // The optimizer will now start with all-zero parameters
    AdamW optim(parameter_count, 1, 0.9, 0.999, 1e-8, 0.0);

#ifdef PROFILE_RUN
    epochs = 8;
#endif

    const f64 K = 1.0 / 400;

    std::mt19937        rng(static_cast<std::mt19937::result_type>(seed));
    std::vector<size_t> indices(capacity);

    advise_huge_pages(indices.data(), indices.size() * sizeof(size_t));

    // Per-thread gradient buffers for lock-free accumulation
    std::vector<Parameters> thread_grads(thread_count, Parameters::zeros(parameter_count));

    for (auto& tg : thread_grads) {
        advise_huge_pages(tg.parameters.data(), tg.parameters.size() * sizeof(f64));
        advise_huge_pages(tg.pair_parameters.data(), tg.pair_parameters.size() * sizeof(f64x2));
    }

    // Running batch loss accumulator
    std::atomic<f64> running_loss_accum{0.0};

    std::barrier epoch_barrier{thread_count + 1};

    std::barrier batch_barrier{thread_count + 1, [&]() noexcept {
                                   // Reduce all thread gradients into thread_grads[0]
                                   for (u32 i = 1; i < thread_count; ++i) {
                                       thread_grads[0].accumulate(thread_grads[i]);
                                   }

                                   // Apply optimizer
                                   optim.step(current_parameter_values, thread_grads[0]);
                               }};

    // Spawn worker threads
    for (u32 t = 0; t < thread_count; ++t) {
        std::thread([&, t]() {
            // Pre-allocated buffers (reused across micro-batches)
            std::vector<ValueHandle> outputs;
            std::vector<f64>         targets;

            outputs.reserve(micro_batch_size);
            targets.reserve(micro_batch_size);

            for (int epoch = 0; epoch < epochs; ++epoch) {

                epoch_barrier.arrive_and_wait();

                for (size_t batch_start = 0; batch_start < n_sampled; batch_start += batch_size) {

                    size_t batch_end       = std::min(batch_start + batch_size, n_sampled);
                    size_t this_batch_size = batch_end - batch_start;

                    size_t sub_size  = (this_batch_size + thread_count - 1) / thread_count;
                    size_t sub_start = batch_start + sub_size * t;
                    size_t sub_end   = std::min(sub_start + sub_size, batch_end);

                    // Clear thread-local gradients for this batch
                    auto& my_grads = thread_grads[t];

                    std::fill(my_grads.parameters.begin(), my_grads.parameters.end(), 0.0);

                    for (auto& p : my_grads.pair_parameters) {
                        p = f64x2::zero();
                    }

                    Graph::get().copy_parameter_values(current_parameter_values);

                    // Thread-local scalar loss accumulator
                    f64 local_batch_loss = 0.0;

                    // Process micro-batches to keep tape small
                    for (size_t mb_start = sub_start; mb_start < sub_end;
                         mb_start += micro_batch_size) {

                        size_t mb_end = std::min(mb_start + micro_batch_size, sub_end);

                        outputs.clear();
                        targets.clear();

                        // Forward pass for this micro-batch
                        for (size_t j = mb_start; j < mb_end; ++j) {

                            size_t idx = indices[j];
                            outputs.push_back((evaluate_white_pov(positions[idx]) * K).sigmoid());
                            targets.push_back(results[idx]);
                        }

                        // Backward pass
                        ValueHandle loss = mse<f64, Reduction::Sum>(outputs, targets);

                        local_batch_loss += loss.get_value();

                        ValueHandle scaled_loss =
                          loss * ValueHandle::create(1.0 / double(this_batch_size));

                        Graph::get().backward();

                        // Accumulate to thread-local buffer (no lock needed)
                        my_grads.accumulate(Graph::get().get_all_parameter_gradients());

                        Graph::get().cleanup();
                        Graph::get().zero_grad();
                    }

                    // Publish loss once per batch (very low overhead)
                    running_loss_accum.fetch_add(local_batch_loss / double(this_batch_size),
                                                 std::memory_order_relaxed);

                    batch_barrier.arrive_and_wait();
                }
            }
        }).detach();
    }

    // Freeze all parameters before tuning, except for material parameters.
    ParameterCountInfo counts = Globals::get().get_parameter_counts();

    // Freeze all value
    Globals::get().freeze_value_range(0, counts.parameter_count);

    // Freeze all pair, except first 5 (material parameters)
    Globals::get().freeze_pair_range(5, counts.pair_parameter_count);

    // Epoch loop
    for (int epoch = 0; epoch < epochs; ++epoch) {

        if (epoch == 24) {
            // Unfreeze all parameters after 24 epochs. Dont unfreeze king safety just yet
            Globals::get().unfreeze_value_range(0, counts.parameter_count);
            Globals::get().unfreeze_pair_range(
              0, counts.pair_parameter_count - (28 + 7 + 28 + 5 + 5 + 1 + 1 + 1 + 1 + 1 + 2));
            optim.set_lr(.1);
        }
        if (epoch == 96) {
            // Unfreeze king safety parameters after 96 epochs
            Globals::get().unfreeze_pair_range(0, counts.pair_parameter_count);
        }


        if (epoch < 24) {
            optim.set_lr(20.0 * std::pow(0.0333, double(epoch) / 24.0));
        } else if (epoch < 72) {
            optim.set_lr(2 * std::pow(0.0667, double(epoch - 24) / 28.0));
        } else {
            optim.set_lr(std::pow(0.1, double(epoch - 72) / 128.0));
        }

        std::cout << "Epoch " << epoch + 1 << "/" << epochs << "\n";

        const auto start = time::Clock::now();

        if (epoch % refresh == 0) {
            n_sampled = sample_positions(games, keep_probs, positions, results,
                                         seed + 0x9E3779B97F4A7C15ULL * static_cast<u64>(epoch + 1),
                                         thread_count);
            std::cout << "Sampled " << n_sampled << " positions in "
                      << time::cast<time::FloatSeconds>(time::Clock::now() - start).count()
                      << "s\n";
            if (n_sampled == 0) {
                std::cerr << "No positions sampled\n";
                return 1;
            }
        }

        const size_t total_batches = (n_sampled + batch_size - 1) / batch_size;

        auto sampled_end = indices.begin() + static_cast<isize>(n_sampled);
        std::iota(indices.begin(), sampled_end, size_t{0});
        std::shuffle(indices.begin(), sampled_end, rng);

        epoch_barrier.arrive_and_wait();

        for (size_t bi = 0, bstart = 0; bstart < n_sampled; bstart += batch_size, ++bi) {

            batch_barrier.arrive_and_wait();

            const f64 running_loss = running_loss_accum.exchange(0.0, std::memory_order_relaxed);

            print_progress(bi + 1, total_batches, running_loss);
        }

        std::cout << "\n";

        // Dump current parameter values
        Graph::get().copy_parameter_values(current_parameter_values);

        Graph::get().cleanup();
        Graph::get().zero_grad();

#ifndef PROFILE_RUN
        print_params();
#endif

        const auto end = time::Clock::now();

        std::cout << "// Epoch duration: " << time::cast<time::FloatSeconds>(end - start).count()
                  << "s\n";
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc >= 2 && std::string_view(argv[1]) == "pack") {
        return run_pack(argc, argv);
    }
    if (argc >= 2 && std::string_view(argv[1]) == "tune") {
        return run_tune(argc, argv);
    }
    std::cerr << "usage:\n"
                 "  clockwork-evaltune tune data.ckg [more.ckg ...] [--target N] [--epochs N] "
                 "[--refresh N] [--seed N]\n"
                 "  clockwork-evaltune pack out.ckg in1.pgn [in2.pgn ...]\n";
    return 1;
}

void print_params() {

    auto print_table = [](const std::string& name, const auto& table) {
        std::cout << "inline const std::array<PParam, " << table.size() << "> " << name << " = {"
                  << std::endl
                  << "   ";
        for (const auto& val : table) {
            std::cout << " " << val << ",";
        }
        std::cout << std::endl << "};" << std::endl;
    };

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

    auto print_2d_array = [](const std::string& name, const auto& arr) {
        std::cout << "inline const std::array<std::array<PParam, " << arr[0].size() << ">, "
                  << arr.size() << "> " << name << " = {{" << std::endl;
        for (const auto& subarr : arr) {
            std::cout << "  {{";
            for (const auto& val : subarr) {
                std::cout << " " << val << ",";
            }
            std::cout << " }}," << std::endl;
        }
        std::cout << "}};" << std::endl;
    };

    auto print_sigmoid = [](const std::string& name, const auto& sigmoid, const i32 templ) {
        PairHandle a_h = static_cast<PairHandle>(sigmoid.a());
        PairHandle c_h = static_cast<PairHandle>(sigmoid.c());
        std::cout << "inline TunableSigmoid<" << templ << "> " << name << "(\n"
                  << "\t" << std::lround(a_h.first()) << ", " << std::lround(a_h.second()) << ", "
                  << std::lround(c_h.first()) << ", " << std::lround(c_h.second()) << "\n"
                  << ");\n";
    };

    std::cout << "inline const PParam PAWN_MAT   = " << PAWN_MAT << ";" << std::endl;
    std::cout << "inline const PParam KNIGHT_MAT = " << KNIGHT_MAT << ";" << std::endl;
    std::cout << "inline const PParam BISHOP_MAT = " << BISHOP_MAT << ";" << std::endl;
    std::cout << "inline const PParam ROOK_MAT   = " << ROOK_MAT << ";" << std::endl;
    std::cout << "inline const PParam QUEEN_MAT  = " << QUEEN_MAT << ";" << std::endl;
    std::cout << std::endl;

    std::cout << "inline const PParam TEMPO_VAL  = " << TEMPO_VAL << ";" << std::endl;
    std::cout << std::endl;

    std::cout << "inline const PParam BISHOP_XRAY_PAWNS   = " << BISHOP_XRAY_PAWNS << ";"
              << std::endl;
    std::cout << "inline const PParam BISHOP_PAIR_VAL   = " << BISHOP_PAIR_VAL << ";" << std::endl;
    std::cout << "inline const PParam ROOK_OPEN_VAL     = " << ROOK_OPEN_VAL << ";" << std::endl;
    std::cout << "inline const PParam ROOK_SEMIOPEN_VAL = " << ROOK_SEMIOPEN_VAL << ";"
              << std::endl;
    std::cout << "inline const PParam MINOR_BEHIND_PAWN = " << MINOR_BEHIND_PAWN << ";"
              << std::endl;
    std::cout << "inline const PParam RESTRICTED_SQUARES = " << RESTRICTED_SQUARES << ";"
              << std::endl;

    std::cout << std::endl;
    std::cout << "inline const PParam DOUBLED_PAWN_VAL = " << DOUBLED_PAWN_VAL << ";" << std::endl;
    std::cout << "inline const PParam ISOLATED_PAWN_VAL = " << ISOLATED_PAWN_VAL << ";"
              << std::endl;
    std::cout << std::endl;

    std::cout << "inline const PParam POTENTIAL_CHECKER_VAL = " << POTENTIAL_CHECKER_VAL << ";"
              << std::endl;

    std::cout << "inline const PParam OUTPOST_KNIGHT_VAL    = " << OUTPOST_KNIGHT_VAL << ";"
              << std::endl;
    std::cout << "inline const PParam OUTPOST_BISHOP_VAL    = " << OUTPOST_BISHOP_VAL << ";"
              << std::endl;

    std::cout << std::endl;

    std::cout << "inline const PParam PAWN_PUSH_THREAT_KNIGHT = " << PAWN_PUSH_THREAT_KNIGHT << ";"
              << std::endl;
    std::cout << "inline const PParam PAWN_PUSH_THREAT_BISHOP = " << PAWN_PUSH_THREAT_BISHOP << ";"
              << std::endl;
    std::cout << "inline const PParam PAWN_PUSH_THREAT_ROOK   = " << PAWN_PUSH_THREAT_ROOK << ";"
              << std::endl;
    std::cout << "inline const PParam PAWN_PUSH_THREAT_QUEEN  = " << PAWN_PUSH_THREAT_QUEEN << ";"
              << std::endl;
    std::cout << std::endl;

    print_table("PAWN_PHALANX", PAWN_PHALANX);
    print_table("DEFENDED_PAWN", DEFENDED_PAWN);
    print_table("PASSED_PAWN", PASSED_PAWN);
    print_table("PASSED_CLEAR_STOPPERS", PASSED_CLEAR_STOPPERS);
    print_table("PASSED_CLEAR_FORWARD", PASSED_CLEAR_FORWARD);
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

    print_table("MINOR_THREAT", MINOR_THREAT);
    print_table("ROOK_THREAT", ROOK_THREAT);
    std::cout << "inline const PParam KING_THREAT  = " << KING_THREAT << ";" << std::endl;
    std::cout << "inline const PParam HANGING_PAWN  = " << HANGING_PAWN << ";" << std::endl;
    std::cout << "inline const PParam HANGING_NON_PAWN  = " << HANGING_NON_PAWN << ";" << std::endl
              << std::endl;
    print_table("KNIGHT_ON_QUEEN", KNIGHT_ON_QUEEN);
    print_table("BISHOP_ON_QUEEN", BISHOP_ON_QUEEN);
    print_table("ROOK_ON_QUEEN", ROOK_ON_QUEEN);
    std::cout << std::endl;

    print_table("BISHOP_PAWNS", BISHOP_PAWNS);
    std::cout << std::endl;
    std::cout << "inline const PParam ROOK_LINEUP = " << ROOK_LINEUP << ";" << std::endl;
    std::cout << std::endl;


    printPsqtArray("PAWN_PSQT", PAWN_PSQT);
    printPsqtArray("KNIGHT_PSQT", KNIGHT_PSQT);
    printPsqtArray("BISHOP_PSQT", BISHOP_PSQT);
    printPsqtArray("ROOK_PSQT", ROOK_PSQT);
    printPsqtArray("QUEEN_PSQT", QUEEN_PSQT);
    printPsqtArray("KING_PSQT", KING_PSQT);
    std::cout << std::endl;


    std::cout << "inline const PParam KS_NO_QUEEN = " << KS_NO_QUEEN << ";" << std::endl;
    std::cout << std::endl;

    print_table("PT_INNER_RING_ATTACKS", PT_INNER_RING_ATTACKS);
    print_table("PT_OUTER_RING_ATTACKS", PT_OUTER_RING_ATTACKS);
    std::cout << std::endl;


    std::cout << "inline const PParam KS_FLANK_ATTACK = " << KS_FLANK_ATTACK << ";" << std::endl;
    std::cout << "inline const PParam KS_FLANK_DEFENSE = " << KS_FLANK_DEFENSE << ";" << std::endl;
    std::cout << "inline const PParam KS_FLANK_DOUBLE_ATTACK   = " << KS_FLANK_DOUBLE_ATTACK << ";"
              << std::endl;
    std::cout << "inline const PParam KS_FLANK_DOUBLE_DEFENSE  = " << KS_FLANK_DOUBLE_DEFENSE << ";"
              << std::endl;
    std::cout << std::endl;

    print_2d_array("KING_SHELTER", KING_SHELTER);
    print_table("BLOCKED_SHELTER_STORM", BLOCKED_SHELTER_STORM);
    print_2d_array("SHELTER_STORM", SHELTER_STORM);


    print_sigmoid("KING_SAFETY_ACTIVATION", KING_SAFETY_ACTIVATION, 32);
    std::cout << std::endl;

    std::cout << "inline VParam WINNABLE_PAWNS = " << WINNABLE_PAWNS << ";\n";
    std::cout << "inline VParam WINNABLE_SYM = " << WINNABLE_SYM << ";\n";
    std::cout << "inline VParam WINNABLE_ASYM = " << WINNABLE_ASYM << ";\n";
    std::cout << "inline VParam WINNABLE_PAWN_ENDGAME = " << WINNABLE_PAWN_ENDGAME << ";\n";
    std::cout << "inline VParam WINNABLE_BIAS = " << WINNABLE_BIAS << ";\n";
    std::cout << std::endl;
}
