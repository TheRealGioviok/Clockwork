#pragma once

#include "util/types.hpp"
#include <string_view>

#define CLOCKWORK_IS_TUNING 0

#ifndef CLOCKWORK_IS_TUNING
    #define CLOCKWORK_IS_TUNING 0
#endif

namespace Clockwork::tuned {

#define CLOCKWORK_TUNABLES(TUNE, NO_TUNE)                        \
                                                                 \
    /* RFP Values */                                             \
    TUNE(rfp_margin, 138, 40, 160, 4, 0.002)                     \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                      \
                                                                 \
    /* NMP Values */                                             \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                      \
    NO_TUNE(nmp_base_r, 192, 64, 384, 16, 0.002)                 \
    TUNE(nmp_depth_r, 21, 8, 32, 1, 0.002)                       \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)           \
    TUNE(nmp_beta_margin, 16, 10, 60, 3, 0.002)                  \
    TUNE(nmp_beta_diff, 319, 200, 800, 38, 0.002)                \
    TUNE(nmp_improving_r, 34, 32, 128, 5, 0.002)                 \
                                                                 \
    /* ProbCut Values */                                         \
    TUNE(probcut_margin, 197, 166, 664, 25, 0.002)               \
    TUNE(probcut_see, 107, 54, 200, 10, 0.002)                   \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)             \
                                                                 \
    /* SEE Values */                                             \
    TUNE(quiesce_see_threshold, -62, -200, 200, 18, 0.002)        \
    TUNE(movepicker_see_capthist_divisor, 32, 16, 102, 6, 0.002) \
    TUNE(see_pawn_val, 99, 80, 120, 6, 0.002)                    \
    TUNE(see_knight_val, 245, 240, 360, 18, 0.002)               \
    TUNE(see_bishop_val, 246, 240, 360, 18, 0.002)               \
    TUNE(see_rook_val, 572, 490, 620, 30, 0.002)                 \
    TUNE(see_queen_val, 964, 890, 1350, 54, 0.002)               \
                                                                 \
    /* Stat Bonus */                                             \
    TUNE(stat_bonus_max, 1637, 948, 3792, 142, 0.002)            \
    TUNE(stat_bonus_quad, 7, 2, 8, .5, 0.002)                    \
    TUNE(stat_bonus_lin, 99, 60, 240, 9, 0.002)                  \
    TUNE(stat_bonus_sub, 132, 60, 240, 9, 0.002)                 \
                                                                 \
    /* Stat Malus */                                             \
    TUNE(stat_malus_max, 1177, 948, 3792, 142, 0.002)             \
    TUNE(stat_malus_quad, 2, 2, 8, .5, 0.002)                    \
    TUNE(stat_malus_lin, 163, 60, 240, 9, 0.002)                 \
    TUNE(stat_malus_sub, 85, 60, 240, 9, 0.002)                 \
                                                                 \
    /* Search Params */                                          \
    TUNE(asp_window_delta, 35, 12, 50, 3, 0.002)                 \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                   \
    TUNE(razor_margin, 537, 353, 1414, 53, 0.002)                \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)                \
                                                                 \
    /* Futility Pruning */                                       \
    TUNE(ffp_margin_base, 645, 250, 1000, 38, 0.002)             \
    TUNE(ffp_margin_mult, 55, 50, 200, 8, 0.002)                 \
    TUNE(ffp_hist_div, 18, 12, 48, 3, 0.002)                     \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                     \
                                                                 \
    /* Quiet History Pruning */                                  \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                     \
    TUNE(qhp_threshold, -2156, -4096, -1024, 154, 0.002)         \
                                                                 \
    /* SEE PVS */                                                \
    TUNE(see_pvs_quiet, -64, -134, -33, 5, 0.002)                \
    TUNE(see_pvs_noisy_quad, -20, -33, -1, 2, 0.002)             \
    TUNE(see_pvs_hist_mult, 20, 10, 40, 2, 0.002)                \
                                                                 \
    /* Singular Extensions */                                    \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)             \
    TUNE(sing_beta_margin, 175, 160, 640, 19, 0.002)             \
    TUNE(dext_margin, 47, 20, 80, 3, 0.002)                      \
    TUNE(dext_hist_div, 702, 256, 1024, 32, 0.002)               \
    TUNE(triext_margin, 156, 60, 240, 9, 0.002)                  \
    TUNE(triext_hist_div, 494, 256, 1024, 32, 0.002)             \
                                                                 \
    /* LMR */                                                    \
    TUNE(lmr_quiet_base, 782, 480, 840, 32, 0.002)               \
    TUNE(lmr_quiet_div, 167, 96, 296, 14, 0.002)                 \
    TUNE(lmr_noisy_base, 249, 160, 320, 16, 0.002)               \
    TUNE(lmr_noisy_div, 164, 98, 394, 14, 0.002)                 \
    TUNE(lmr_pv_node_red, 1030, 1024, 2048, 53, 0.002)           \
    TUNE(lmr_alpha_raise_red, 566, 256, 1024, 32, 0.002)         \
    TUNE(lmr_not_improving_red, 543, 256, 1024, 32, 0.002)       \
    TUNE(lmr_in_check_red, 1021, 512, 2048, 64, 0.002)           \
    TUNE(lmr_cutnode_red, 1433, 512, 2048, 64, 0.002)            \
    TUNE(lmr_no_tt_red, 1181, 512, 2048, 64, 0.002)               \
    TUNE(lmr_ttpv_red, 964, 512, 2048, 64, 0.002)                \
    TUNE(lmr_tt_capture_red, 578, 512, 2048, 64, 0.002)         \
    TUNE(lmr_ttpv_fail_low, 1396, 512, 2048, 77, 0.002)          \
    TUNE(lmr_fail_high_red, 592, 512, 2048, 64, 0.002)           \
    TUNE(lmr_quiet_hist_base, 855, 512, 2048, 64, 0.002)         \
    TUNE(lmr_hist_div, 17, 4, 32, 3, 0.002)                      \
    TUNE(lmr_fut_red_base, 330, 250, 1000, 38, 0.002)            \
    TUNE(lmr_fut_red_mult, 99, 50, 200, 8, 0.002)               \
    TUNE(lmr_fut_red, 314, 256, 1536, 53, 0.002)                 \
    TUNE(lmr_max_red, 2406, 1536, 6144, 231, 0.002)              \
                                                                 \
    /* TIME MANAGEMENT */                                        \
    TUNE(time_hard_limit, 403, 128, 512, 19, 0.002)              \
    TUNE(time_soft_limit, 32, 25, 100, 3, 0.002)                 \
    TUNE(time_soft_increment, 543, 256, 1024, 38, 0.002)         \
    TUNE(nodetm_min_factor, 287, 256, 1024, 38, 0.002)           \
    TUNE(nodetm_avg_factor, 2946, 1024, 4096, 128, 0.002)        \
    TUNE(nodetm_frac_factor, 2195, 948, 3792, 128, 0.002)        \
    TUNE(d1plexity_base, 711, 394, 1576, 59, 0.002)              \
    TUNE(d1plexity_max_complexity, 224, 100, 400, 15, 0.002)     \
    TUNE(d1plexity_divisor, 397, 193, 772, 29, 0.002)            \
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
