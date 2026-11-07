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
    TUNE(rfp_margin, 129, 40, 160, 4, 0.002)                      \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                       \
                                                                  \
    /* NMP Values */                                              \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                       \
    NO_TUNE(nmp_base_r, 192, 64, 384, 16, 0.002)                  \
    TUNE(nmp_depth_r, 18, 8, 32, 1, 0.002)                        \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)            \
    TUNE(nmp_beta_margin, 32, 10, 60, 3, 0.002)                   \
    TUNE(nmp_beta_diff, 393, 200, 800, 38, 0.002)                 \
    TUNE(nmp_improving_r, 62, 32, 128, 5, 0.002)                  \
                                                                  \
    /* ProbCut Values */                                          \
    TUNE(probcut_margin, 342, 166, 664, 25, 0.002)                \
    TUNE(probcut_see, 112, 54, 200, 10, 0.002)                    \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)              \
                                                                  \
    /* SEE Values */                                              \
    TUNE(quiesce_see_threshold, 23, -1000, 200, 20, 0.002)        \
    TUNE(movepicker_see_capthist_divisor, 53, 16, 192, 10, 0.002) \
    TUNE(see_pawn_val, 98, 50, 200, 8, 0.002)                     \
    TUNE(see_knight_val, 296, 150, 600, 23, 0.002)                \
    TUNE(see_bishop_val, 251, 150, 600, 23, 0.002)                \
    TUNE(see_rook_val, 563, 250, 1000, 38, 0.002)                 \
    TUNE(see_queen_val, 970, 450, 1800, 68, 0.002)                \
                                                                  \
    /* Stat Bonus */                                              \
    TUNE(stat_bonus_max, 1942, 948, 3792, 142, 0.002)             \
    TUNE(stat_bonus_quad, 65, 2, 8, .5, 0.002)                    \
    TUNE(stat_bonus_lin, 90, 60, 240, 9, 0.002)                   \
    TUNE(stat_bonus_sub, 147, 60, 240, 9, 0.002)                  \
                                                                  \
    /* Stat Malus */                                              \
    TUNE(stat_malus_max, 917, 948, 3792, 142, 0.002)              \
    TUNE(stat_malus_quad, 48, 2, 8, .5, 0.002)                    \
    TUNE(stat_malus_lin, 124, 60, 240, 9, 0.002)                  \
    TUNE(stat_malus_sub, 115, 60, 240, 9, 0.002)                  \
                                                                  \
    /* Search Params */                                           \
    TUNE(asp_window_delta, 25, 25, 100, 4, 0.002)                 \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                    \
    TUNE(razor_margin, 683, 353, 1414, 53, 0.002)                 \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)                 \
                                                                  \
    /* Futility Pruning */                                        \
    TUNE(ffp_margin_base, 441, 250, 1000, 38, 0.002)              \
    TUNE(ffp_margin_mult, 95, 50, 200, 8, 0.002)                  \
    TUNE(ffp_hist_div, 1328, 16, 64, 3, 0.002)                    \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                      \
                                                                  \
    /* Quiet History Pruning */                                   \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                      \
    TUNE(qhp_threshold, -2182, -4096, -1024, 154, 0.002)          \
                                                                  \
    /* SEE PVS */                                                 \
    TUNE(see_pvs_quiet, -55, -134, -33, 5, 0.002)                 \
    TUNE(see_pvs_noisy_quad, -669, -44, -11, 2, 0.002)            \
    TUNE(see_pvs_hist_mult, 17, 10, 40, 2, 0.002)                 \
                                                                  \
    /* Singular Extensions */                                     \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                 \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)              \
    TUNE(sing_beta_margin, 250, 160, 640, 19, 0.002)              \
    TUNE(dext_margin, 37, 20, 80, 3, 0.002)                       \
    TUNE(dext_hist_div, 481, 256, 1024, 39, 0.002)                \
    TUNE(triext_margin, 119, 60, 240, 9, 0.002)                   \
    TUNE(triext_hist_div, 546, 256, 1024, 39, 0.002)              \
                                                                  \
    /* LMR */                                                     \
    TUNE(lmr_quiet_base, 642, 394, 1576, 59, 0.002)               \
    TUNE(lmr_quiet_div, 167, 104, 416, 16, 0.002)                 \
    TUNE(lmr_noisy_base, 231, 128, 512, 20, 0.002)                \
    TUNE(lmr_noisy_div, 249, 98, 394, 15, 0.002)                  \
    TUNE(lmr_pv_node_red, 1338, 512, 2048, 77, 0.002)             \
    TUNE(lmr_alpha_raise_red, 511, 256, 1024, 38, 0.002)          \
    TUNE(lmr_not_improving_red, 569, 256, 1024, 38, 0.002)        \
    TUNE(lmr_in_check_red, 1032, 512, 2048, 77, 0.002)            \
    TUNE(lmr_cutnode_red, 1238, 512, 2048, 77, 0.002)             \
    TUNE(lmr_no_tt_red, 862, 512, 2048, 77, 0.002)                \
    TUNE(lmr_ttpv_red, 1018, 512, 2048, 77, 0.002)                \
    TUNE(lmr_tt_capture_red, 1004, 512, 2048, 77, 0.002)          \
    TUNE(lmr_ttpv_fail_low, 1048, 512, 2048, 77, 0.002)           \
    TUNE(lmr_fail_high_red, 920, 512, 2048, 77, 0.002)            \
    TUNE(lmr_quiet_hist_base, 820, 512, 2048, 77, 0.002)          \
    TUNE(lmr_hist_div, 837, 4, 16, 2, 0.002)                      \
    TUNE(lmr_fut_red_base, 535, 250, 1000, 38, 0.002)             \
    TUNE(lmr_fut_red_mult, 103, 50, 200, 8, 0.002)                \
    TUNE(lmr_fut_red, 580, 512, 2048, 77, 0.002)                  \
    TUNE(lmr_max_red, 3314, 1536, 6144, 231, 0.002)               \
                                                                  \
    /* TIME MANAGEMENT */                                         \
    TUNE(time_hard_limit, 275, 128, 512, 19, 0.002)               \
    TUNE(time_soft_limit, 52, 25, 100, 3, 0.002)                  \
    TUNE(time_soft_increment, 599, 256, 1024, 38, 0.002)          \
    TUNE(nodetm_min_factor, 415, 256, 1024, 38, 0.002)            \
    TUNE(nodetm_avg_factor, 2543, 1024, 4096, 153, 0.002)         \
    TUNE(nodetm_frac_factor, 2403, 948, 3792, 142, 0.002)         \
    TUNE(d1plexity_base, 978, 394, 1576, 59, 0.002)               \
    TUNE(d1plexity_max_complexity, 225, 100, 400, 15, 0.002)      \
    TUNE(d1plexity_divisor, 408, 193, 772, 29, 0.002)             \
                                                                  \
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
