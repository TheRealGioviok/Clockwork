#pragma once

#include "util/types.hpp"
#include <string_view>

#ifndef CLOCKWORK_IS_TUNING
    #define CLOCKWORK_IS_TUNING 1
#endif

namespace Clockwork::tuned {

#define CLOCKWORK_TUNABLES(TUNE, NO_TUNE)                         \
                                                                  \
    /* RFP Values */                                              \
    TUNE(rfp_margin, 144, 72, 288, 22, 0.002)                      \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                       \
                                                                  \
    /* NMP Values */                                              \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                       \
    NO_TUNE(nmp_base_r, 3, 1, 10, .5, 0.002)                      \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)            \
    TUNE(nmp_beta_margin, 30, 15, 60, 5, 0.002)                   \
    TUNE(nmp_beta_diff, 428, 214, 856, 65, 0.002)                 \
                                                                  \
    /* ProbCut Values */                                          \
    TUNE(probcut_margin, 332, 166, 664, 50, 0.002)                \
    TUNE(probcut_see, 108, 54, 216, 17, 0.002)                     \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)              \
                                                                  \
    /* SEE Values */                                              \
    TUNE(quiesce_see_threshold, 18, 9, 36, 3, 0.002)        \
    TUNE(movepicker_see_capthist_divisor, 54, 27, 108, 9, 0.002) \
                                                                  \
    /* Stat Bonus */                                              \
    TUNE(stat_bonus_max, 1828, 914, 3656, 275, 0.002)             \
    TUNE(stat_bonus_quad, 4, 2, 8, 1, 0.002)                     \
    TUNE(stat_bonus_lin, 118, 59, 236, 18, 0.002)                  \
    TUNE(stat_bonus_sub, 123, 62, 246, 19, 0.002)                  \
                                                                  \
    /* Stat Malus */                                              \
    TUNE(stat_malus_max, 1627, 814, 3254, 244, 0.002)             \
    TUNE(stat_malus_quad, 4, 2, 8, 1, 0.002)                     \
    TUNE(stat_malus_lin, 137, 69, 274, 21, 0.002)                  \
    TUNE(stat_malus_sub, 111, 56, 222, 17, 0.002)                  \
                                                                  \
    /* Search Params */                                           \
    TUNE(asp_window_delta, 32, 16, 64, 5, 0.002)                 \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                    \
    TUNE(razor_margin, 681, 341, 1362, 103, 0.002)                 \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)                 \
                                                                  \
    /* Futility Pruning */                                        \
    TUNE(ffp_margin_base, 437, 219, 874, 66, 0.002)              \
    TUNE(ffp_margin_mult, 89, 45, 178, 14, 0.002)                  \
    TUNE(ffp_hist_div, 25, 13, 50, 4, 0.002)                      \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                      \
                                                                  \
    /* Quiet History Pruning */                                   \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                      \
    TUNE(qhp_threshold, -2183, -1091, -4366, -327, 0.002)          \
                                                                  \
    /* SEE PVS */                                                 \
    TUNE(see_pvs_quiet, -65, -32, -130, -9, 0.002)                 \
    TUNE(see_pvs_noisy_quad, -20, -10, -40, -3, 0.002)             \
    TUNE(see_pvs_hist_mult, 16, 8, 32, 3, 0.002)                 \
                                                                  \
    /* Singular Extensions */                                     \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                 \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)              \
    TUNE(sing_beta_margin, 5, 3, 10, 1, 0.002)                    \
    TUNE(dext_margin, 40, 20, 80, 6, 0.002)                       \
    TUNE(dext_hist_div, 491, 246, 982, 74, 0.002)                \
    TUNE(triext_margin, 126, 63, 252, 19, 0.002)                   \
    TUNE(triext_hist_div, 573, 287, 1146, 86, 0.002)              \
                                                                  \
    /* LMR */                                                     \
    TUNE(lmr_quiet_base, 638, 319, 1276, 96, 0.002)               \
    TUNE(lmr_quiet_div, 164, 82, 328, 25, 0.002)                 \
    TUNE(lmr_noisy_base, 258, 129, 516, 39, 0.002)                \
    TUNE(lmr_noisy_div, 193, 97, 386, 29, 0.002)                  \
    TUNE(lmr_pv_node_red, 1207, 604, 2414, 181, 0.002)             \
    TUNE(lmr_alpha_raise_red, 514, 257, 1028, 78, 0.002)          \
    TUNE(lmr_not_improving_red, 520, 260, 1040, 78, 0.002)        \
    TUNE(lmr_in_check_red, 1021, 511, 2042, 154, 0.002)            \
    TUNE(lmr_cutnode_red, 1087, 544, 2174, 163, 0.002)             \
    TUNE(lmr_no_tt_red, 997, 499, 1994, 150, 0.002)                \
    TUNE(lmr_ttpv_red, 1097, 549, 2194, 165, 0.002)                \
    TUNE(lmr_tt_capture_red, 968, 484, 1936, 146, 0.002)           \
    TUNE(lmr_fail_high_red, 980, 490, 1960, 147, 0.002)            \
    TUNE(lmr_quiet_hist_base, 940, 470, 1880, 141, 0.002)          \
    TUNE(lmr_hist_div, 12, 6, 24, 2, 0.002)                       \
    TUNE(lmr_fut_red_base, 562, 281, 1124, 85, 0.002)             \
    TUNE(lmr_fut_red_mult, 99, 50, 198, 15, 0.002)                 \
    TUNE(lmr_fut_red, 864, 432, 1728, 130, 0.002)                  \
    TUNE(lmr_max_red, 2985, 1493, 5970, 448, 0.002)               \
                                                                  \
    /* TIME MANAGEMENT */                                         \
    NO_TUNE(time_hard_limit, 256, 128, 512, 19, 0.002)            \
    NO_TUNE(time_soft_limit, 51, 25, 100, 3, 0.002)               \
    NO_TUNE(time_soft_increment, 512, 256, 1024, 38, 0.002)       \
    NO_TUNE(nodetm_min_factor, 512, 256, 1024, 38, 0.002)         \
    NO_TUNE(nodetm_avg_factor, 2048, 1024, 4096, 153, 0.002)      \
    NO_TUNE(nodetm_frac_factor, 1895, 948, 3792, 142, 0.002)      \
    NO_TUNE(d1plexity_base, 788, 394, 1576, 59, 0.002)            \
    NO_TUNE(d1plexity_max_complexity, 200, 100, 400, 15, 0.002)   \
    NO_TUNE(d1plexity_divisor, 386, 193, 772, 29, 0.002)          \
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
