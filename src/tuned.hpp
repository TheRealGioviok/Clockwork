#pragma once

#include "util/types.hpp"
#include <string_view>

#ifndef CLOCKWORK_IS_TUNING
    #define CLOCKWORK_IS_TUNING 1
#endif

namespace Clockwork::tuned {

#define CLOCKWORK_TUNABLES(TUNE, NO_TUNE)                       \
                                                                \
    /* RFP Values */                                            \
    TUNE(rfp_margin, 147, 74, 294, 22, 0.002)                   \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                     \
                                                                \
    /* NMP Values */                                            \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                     \
    NO_TUNE(nmp_base_r, 3, 1, 10, .5, 0.002)                    \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)          \
    TUNE(nmp_beta_margin, 23, 12, 46, 4, 0.002)                 \
    TUNE(nmp_beta_diff, 402, 201, 804, 61, 0.002)               \
                                                                \
    /* ProbCut Values */                                        \
    TUNE(probcut_margin, 372, 186, 744, 56, 0.002)              \
    TUNE(probcut_see, 204, 102, 408, 31, 0.002)                 \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)            \
                                                                \
    /* SEE Values */                                            \
    TUNE(quiesce_see_threshold, 26, 13, 52, 4, 0.002)           \
    TUNE(movepicker_see_capthist_divisor, 47, 24, 94, 7, 0.002) \
                                                                \
    /* Stat Bonus */                                            \
    TUNE(stat_bonus_max, 2387, 1194, 4774, 358, 0.002)          \
    TUNE(stat_bonus_quad, 8, 4, 16, 2, 0.002)                   \
    TUNE(stat_bonus_lin, 82, 41, 164, 13, 0.002)                \
    TUNE(stat_bonus_sub, 82, 41, 164, 13, 0.002)                \
                                                                \
    /* Stat Malus */                                            \
    TUNE(stat_malus_max, 816, 408, 1632, 123, 0.002)            \
    TUNE(stat_malus_quad, 4, 2, 8, 1, 0.002)                    \
    TUNE(stat_malus_lin, 134, 67, 268, 21, 0.002)               \
    TUNE(stat_malus_sub, 118, 59, 236, 18, 0.002)               \
                                                                \
    /* Search Params */                                         \
    TUNE(asp_window_delta, 22, 11, 44, 4, 0.002)                \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                  \
    TUNE(razor_margin, 502, 251, 1004, 76, 0.002)               \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)               \
                                                                \
    /* Futility Pruning */                                      \
    TUNE(ffp_margin_base, 335, 168, 670, 51, 0.002)             \
    TUNE(ffp_margin_mult, 95, 48, 190, 15, 0.002)               \
    TUNE(ffp_hist_div, 16, 8, 32, 3, 0.002)                     \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                    \
                                                                \
    /* Quiet History Pruning */                                 \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                    \
    TUNE(qhp_threshold, -1424, -2848, -712, 214, 0.002)         \
                                                                \
    /* SEE PVS */                                               \
    TUNE(see_pvs_quiet, -48, -96, -24, 8, 0.002)                \
    TUNE(see_pvs_noisy_quad, -10, -20, -5, 2, 0.002)            \
    TUNE(see_pvs_hist_mult, 10, 5, 20, 2, 0.002)                \
                                                                \
    /* Singular Extensions */                                   \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)               \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)            \
    TUNE(sing_beta_margin, 5, 3, 10, 1, 0.002)                  \
    TUNE(dext_margin, 27, 14, 54, 4, 0.002)                     \
    TUNE(dext_hist_div, 248, 124, 496, 38, 0.002)               \
    TUNE(triext_margin, 117, 59, 234, 18, 0.002)                \
    TUNE(triext_hist_div, 742, 371, 1484, 112, 0.002)           \
                                                                \
    /* LMR */                                                   \
    TUNE(lmr_quiet_base, 583, 292, 1166, 88, 0.002)             \
    TUNE(lmr_quiet_div, 165, 83, 330, 25, 0.002)                \
    TUNE(lmr_noisy_base, 247, 124, 494, 37, 0.002)              \
    TUNE(lmr_noisy_div, 180, 90, 360, 27, 0.002)                \
    TUNE(lmr_pv_node_red, 632, 316, 1264, 95, 0.002)            \
    TUNE(lmr_alpha_raise_red, 370, 185, 740, 56, 0.002)         \
    TUNE(lmr_not_improving_red, 1012, 506, 2024, 152, 0.002)    \
    TUNE(lmr_in_check_red, 610, 305, 1220, 92, 0.002)           \
    TUNE(lmr_cutnode_red, 994, 497, 1988, 150, 0.002)           \
    TUNE(lmr_no_tt_red, 1204, 602, 2408, 181, 0.002)            \
    TUNE(lmr_ttpv_red, 1410, 705, 2820, 212, 0.002)             \
    TUNE(lmr_tt_capture_red, 1143, 572, 2286, 172, 0.002)       \
    TUNE(lmr_fail_high_red, 1313, 657, 2626, 197, 0.002)        \
    TUNE(lmr_quiet_hist_base, 1220, 610, 2440, 183, 0.002)      \
    TUNE(lmr_hist_div, 9, 5, 18, 2, 0.002)                      \
    TUNE(lmr_fut_red_base, 422, 211, 844, 64, 0.002)            \
    TUNE(lmr_fut_red_mult, 55, 28, 110, 9, 0.002)               \
    TUNE(lmr_fut_red, 701, 351, 1402, 106, 0.002)               \
    TUNE(lmr_max_red, 3569, 1785, 7138, 536, 0.002)             \
                                                                \
    /* TIME MANAGEMENT */                                       \
    NO_TUNE(time_hard_limit, 256, 128, 512, 19, 0.002)          \
    NO_TUNE(time_soft_limit, 51, 25, 100, 3, 0.002)             \
    NO_TUNE(time_soft_increment, 512, 256, 1024, 38, 0.002)     \
    NO_TUNE(nodetm_min_factor, 512, 256, 1024, 38, 0.002)       \
    NO_TUNE(nodetm_avg_factor, 2048, 1024, 4096, 153, 0.002)    \
    NO_TUNE(nodetm_frac_factor, 1895, 948, 3792, 142, 0.002)    \
    NO_TUNE(d1plexity_base, 788, 394, 1576, 59, 0.002)          \
    NO_TUNE(d1plexity_max_complexity, 200, 100, 400, 15, 0.002) \
    NO_TUNE(d1plexity_divisor, 386, 193, 772, 29, 0.002)        \
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
