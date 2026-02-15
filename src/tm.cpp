#include "tm.hpp"
#include "tuned.hpp"
#include "uci.hpp"
#include "util/types.hpp"
#include <iostream>

namespace Clockwork::TM {
time::TimePoint compute_hard_limit(time::TimePoint               search_start,
                                   const Search::SearchSettings& settings,
                                   const Color                   stm) {
    using namespace std;
    using namespace time;

    auto hard_limit = TimePoint::max();

    if (settings.w_time >= 0) {
        const auto compute_buffer_time = [&]() -> i64 {
            if (stm == Color::White) {
                return settings.w_time * tuned::time_hard_limit / 1024;
            } else {
                return settings.b_time * tuned::time_hard_limit / 1024;
            }
        };
        hard_limit = min(hard_limit, search_start + Milliseconds(compute_buffer_time()));
    }

    if (settings.move_time >= 0) {
        hard_limit = min(hard_limit, search_start + Milliseconds(settings.move_time));
    }

    return hard_limit - UCI_LATENCY;
}

template<bool ADJUST_FOR_NODES_TM>
time::TimePoint compute_soft_limit(time::TimePoint               search_start,
                                   const Search::SearchSettings& settings,
                                   const Color                   stm,
                                   const f64                     nodes_tm_fraction,
                                   const f64                     complexity,
                                   const usize                   bm_streak) {
    using namespace std;
    using namespace time;

    auto soft_limit = TimePoint::max();

    if (settings.w_time >= 0) {

        // Base time calculation
        const auto compute_buffer_time = [&]() -> f64 {
            if (stm == Color::White) {
                return static_cast<f64>(settings.w_time * tuned::time_soft_limit / 1024
                                        + settings.w_inc * tuned::time_soft_increment / 1024);
            } else {
                return static_cast<f64>(settings.b_time * tuned::time_soft_limit / 1024
                                        + settings.b_inc * tuned::time_soft_increment / 1024);
            }
        };

        // Adjustment based on mainline nodes vs total nodes
        const auto compute_nodestm_factor = [&]() -> f64 {
            if constexpr (!ADJUST_FOR_NODES_TM) {
                return 1.0;
            }
            return std::max<f64>(tuned::nodetm_min_factor / 1024.0,
                                 tuned::nodetm_avg_factor / 1024.0
                                   - nodes_tm_fraction * (tuned::nodetm_frac_factor / 1024.0));
        };

        // Adjustment based on difference between depth 1 search score and current score
        // This essentially estimates the complexity of a position
        const auto compute_complexitytm_factor = [&]() -> f64 {
            return std::max<f64>(
              tuned::d1plexity_base / 1024.0
                + std::clamp<f64>(complexity, 0.0,
                                  static_cast<f64>(tuned::d1plexity_max_complexity))
                    / static_cast<f64>(tuned::d1plexity_divisor),
              1.0);
        };

        // Adjustment based on the amount of moves in a row that the bestmove holds between iterations
        const auto compute_bmstability = [&]() -> f64 {
            const std::array<f64, 5> multipliers = {
              static_cast<f64>(tuned::bmstability0) / 1000.0,
              static_cast<f64>(tuned::bmstability1) / 1000.0,
              static_cast<f64>(tuned::bmstability2) / 1000.0,
              static_cast<f64>(tuned::bmstability3) / 1000.0,
              static_cast<f64>(tuned::bmstability4) / 1000.0,
            };
            return multipliers[std::min(bm_streak, static_cast<usize>(4))];
        };

        soft_limit = min(soft_limit, search_start
                                       + Milliseconds(static_cast<i64>(
                                         compute_buffer_time() * compute_nodestm_factor()
                                         * compute_complexitytm_factor() * compute_bmstability())));
    }

    return soft_limit;
}

// Explicit instantiations
template time::TimePoint compute_soft_limit<true>(
  time::TimePoint, const Search::SearchSettings&, const Color, const f64, const f64, const usize);

template time::TimePoint compute_soft_limit<false>(
  time::TimePoint, const Search::SearchSettings&, const Color, const f64, const f64, const usize);
}  // namespace Clockwork::TM
