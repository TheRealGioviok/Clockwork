#pragma once

#include "util/types.hpp"
#include <string_view>

#define CLOCKWORK_IS_TUNING 0

#ifndef CLOCKWORK_IS_TUNING
    #define CLOCKWORK_IS_TUNING 0
#endif

namespace Clockwork::tuned {

#define CLOCKWORK_TUNABLES(TUNE, NO_TUNE)                         \
                                                                  \
    /* RFP Values */                                              \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                       \
    TUNE(rfp_margin, 4999, 2160, 8640, 324, 0.002)                \
    TUNE(rfp_improving, -36, -4320, 0, 162, 0.002)                \
    TUNE(rfp_correction_weight, 105, 0, 128, 8, 0.002)             \
                                                                  \
    /* NMP Values */                                              \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                       \
    TUNE(nmp_base_r, 322, 96, 384, 14, 0.002)                     \
    TUNE(nmp_depth_r, 15, 8, 32, 1, 0.002)                        \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)            \
    TUNE(nmp_beta_margin_base, 246, 125, 500, 19, 0.002)          \
    TUNE(nmp_beta_depth_margin, 30, 1, 30, 3, 0.002)              \
    TUNE(nmp_beta_diff, 800, 200, 800, 38, 0.002)                 \
    TUNE(nmp_beta_improving, 0, 0, 160, 5, 0.002)                 \
    TUNE(nmp_improving_r, 49, 32, 128, 5, 0.002)                  \
                                                                  \
    /* ProbCut Values */                                          \
    TUNE(probcut_margin, 386, 169, 678, 25, 0.002)                \
    TUNE(probcut_see, 105, 57, 228, 8, 0.002)                     \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)              \
                                                                  \
    /* SEE Values */                                              \
    TUNE(quiesce_see_threshold, -8, -1000, 200, 20, 0.002)        \
    TUNE(movepicker_see_capthist_divisor, 192, 16, 192, 10, 0.002) \
    NO_TUNE(see_pawn_val, 58, 50, 200, 8, 0.002)                 \
    NO_TUNE(see_knight_val, 498, 150, 600, 23, 0.002)             \
    NO_TUNE(see_bishop_val, 251, 150, 600, 23, 0.002)             \
    NO_TUNE(see_rook_val, 416, 250, 1000, 38, 0.002)              \
    NO_TUNE(see_queen_val, 1206, 450, 1800, 68, 0.002)             \
                                                                  \
    /* Stat Bonus */                                              \
    TUNE(stat_bonus_max, 1356, 948, 3792, 142, 0.002)             \
    TUNE(stat_bonus_quad, 2, 2, 8, .5, 0.002)                     \
    TUNE(stat_bonus_lin, 99, 60, 240, 9, 0.002)                  \
    TUNE(stat_bonus_sub, 170, 60, 240, 9, 0.002)                  \
                                                                  \
    /* Stat Malus */                                              \
    TUNE(stat_malus_max, 1676, 948, 3792, 142, 0.002)             \
    TUNE(stat_malus_quad, 2, 2, 8, .5, 0.002)                     \
    TUNE(stat_malus_lin, 111, 60, 240, 9, 0.002)                   \
    TUNE(stat_malus_sub, 101, 60, 240, 9, 0.002)                   \
                                                                  \
    /* Search Params */                                           \
    TUNE(asp_window_delta, 12, 12, 50, 3, 0.002)                  \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                    \
    TUNE(razor_margin, 537, 353, 1414, 53, 0.002)                 \
    TUNE(lmp_hh_div, 7550, 4096, 16384, 512, 0.002)               \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)                 \
                                                                  \
    /* Futility Pruning */                                        \
    TUNE(ffp_margin_base, 261950, 219648, 878592, 32947, 0.002)   \
    TUNE(ffp_margin_depth, 99603, 48640, 194560, 7296, 0.002)     \
    TUNE(ffp_margin_improving, 24064, 0, 204800, 10240, 0.002)    \
    TUNE(ffp_margin_hist, 39, 25, 100, 4, 0.002)                  \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                      \
                                                                  \
    /* Quiet History Pruning */                                   \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                      \
    TUNE(qhp_threshold, -2344, -4096, -1024, 154, 0.002)          \
                                                                  \
    /* SEE PVS */                                                 \
    TUNE(see_pvs_quiet_lin, -118, -118, -29, 5, 0.002)             \
    TUNE(see_pvs_noisy_quad, -7, -33, -1, 2, 0.002)              \
    TUNE(see_pvs_quiet_hist, 29, 8, 34, 2, 0.002)                 \
    TUNE(see_pvs_noisy_hist, 18, 8, 34, 2, 0.002)                 \
                                                                  \
    /* Singular Extensions */                                     \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                 \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)              \
    TUNE(sing_beta_exact_margin, 504, 126, 504, 19, 0.002)        \
    TUNE(sing_beta_margin, 299, 126, 504, 19, 0.002)              \
    TUNE(dext_margin, 33, 19, 76, 2, 0.002)                       \
    TUNE(dext_hist_div, 250, 249, 996, 39, 0.002)                 \
    TUNE(triext_margin, 60, 60, 240, 9, 0.002)                    \
    TUNE(triext_hist_div, 558, 267, 1068, 39, 0.002)              \
                                                                  \
    /* LMR */                                                     \
    TUNE(lmr_quiet_base, 675, 307, 1228, 46, 0.002)               \
    TUNE(lmr_quiet_div, 274, 86, 346, 12, 0.002)                  \
    TUNE(lmr_noisy_base, 372, 120, 482, 18, 0.002)                \
    TUNE(lmr_noisy_div, 169, 113, 452, 16, 0.002)                 \
    TUNE(lmr_pv_node_red, 2206, 663, 2652, 99, 0.002)             \
    TUNE(lmr_alpha_raise_red, 259, 259, 1036, 38, 0.002)          \
    TUNE(lmr_not_improving_red, 272, 272, 1088, 40, 0.002)        \
    TUNE(lmr_in_check_red, 1125, 520, 2080, 78, 0.002)            \
    TUNE(lmr_corrplexity, 0, 0, 1024, 52, 0.002)                 \
    TUNE(lmr_cutnode_red, 1546, 629, 2516, 94, 0.002)             \
    TUNE(lmr_exact_bound, 311, -1024, 1024, 103, 0.002)           \
    TUNE(lmr_no_tt_red, 1120, 459, 1838, 68, 0.002)               \
    TUNE(lmr_ttpv_red, 1053, 488, 1952, 73, 0.002)                \
    TUNE(lmr_tt_capture_red, 1950, 512, 2048, 77, 0.002)          \
    TUNE(lmr_ttpv_fail_low, 512, 512, 2048, 77, 0.002)            \
    TUNE(lmr_fail_high_red, 680, 471, 1884, 70, 0.002)            \
    TUNE(lmr_fail_high_all, 192, 192, 768, 28, 0.002)             \
    TUNE(lmr_quiet_hist_base, 1186, 439, 1758, 65, 0.002)         \
    TUNE(lmr_hist_div, 103, 39, 158, 5, 0.002)                     \
    TUNE(lmr_fut_red_base, 265, 265, 1060, 39, 0.002)             \
    TUNE(lmr_fut_red_mult, 62, 50, 200, 8, 0.002)                 \
    TUNE(lmr_fut_red, 616, 317, 1268, 47, 0.002)                  \
    TUNE(lmr_max_red, 3082, 1605, 6422, 512, 0.002)               \
                                                                  \
    /* DO DEEPER / SHALLOWER */                                   \
    TUNE(do_deeper_margin, 160, 47, 188, 7, 0.002)                 \
                                                                  \
    /* TIME MANAGEMENT */                                         \
    TUNE(time_hard_limit, 475, 143, 572, 11, 0.002)               \
    TUNE(time_soft_limit, 53, 25, 100, 3, 0.002)                  \
    TUNE(time_soft_increment, 771, 283, 1132, 21, 0.002)          \
    TUNE(nodetm_min_factor, 738, 200, 800, 15, 0.002)             \
    TUNE(nodetm_avg_factor, 1769, 1190, 4760, 90, 0.002)          \
    TUNE(nodetm_frac_factor, 2009, 1098, 4394, 80, 0.002)         \
    TUNE(d1plexity_base, 489, 489, 1956, 37, 0.002)               \
    TUNE(d1plexity_max_complexity, 294, 111, 446, 8, 0.002)      \
    TUNE(d1plexity_divisor, 205, 205, 820, 15, 0.002)             \
                                                                  \
    TUNE(CONTHIST_WEIGHT_1, 1165, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_WEIGHT_2, 779, 512, 2048, 77, 0.002)            \
    TUNE(CONTHIST_WEIGHT_4, 1131, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_WEIGHT_6, 1640, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_STATS, 3456, 1024, 4192, 154, 0.002)            \
                                                                  \
    TUNE(CONTHIST_UPDATE_1, 957, 512, 2048, 77, 0.002)            \
    TUNE(CONTHIST_UPDATE_2, 660, 512, 2048, 77, 0.002)            \
    TUNE(CONTHIST_UPDATE_4, 993, 512, 2048, 77, 0.002)            \
    TUNE(CONTHIST_UPDATE_6, 762, 512, 2048, 77, 0.002)

/* End of Tunables */

#define DEFINE_VARIABLE(NAME, DEFAULT, ...) inline i32 NAME = DEFAULT;
#define DEFINE_CONSTANT(NAME, DEFAULT, ...) constexpr i32 NAME = DEFAULT;

#if CLOCKWORK_IS_TUNING
// TUNEs are defined as variables, NO_TUNEs are defined as constexpr constants.
CLOCKWORK_TUNABLES(DEFINE_VARIABLE, DEFINE_CONSTANT)
#else
// Both TUNEs and NO_TUNEs are defined as constexpr constants.
CLOCKWORK_TUNABLES(DEFINE_CONSTANT, DEFINE_CONSTANT)
#endif

#undef DEFINE_VARIABLE
#undef DEFINE_CONSTANT

void uci_print_tunable_options();
void uci_print_tunable_values();
bool uci_parse_tunable(std::string_view name, std::string_view value);

}  // namespace Clockwork::tuned
