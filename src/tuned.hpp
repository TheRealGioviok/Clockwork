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
    TUNE(rfp_margin, 144, 288, 72, 15, 0.002)                      \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                       \
                                                                  \
    /* NMP Values */                                              \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                       \
    NO_TUNE(nmp_base_r, 3, 1, 10, .5, 0.002)                      \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)            \
    TUNE(nmp_beta_margin, 30, 60, 15, 3, 0.002)                   \
    TUNE(nmp_beta_diff, 428, 856, 214, 43, 0.002)                 \
                                                                  \
    /* ProbCut Values */                                          \
    TUNE(probcut_margin, 332, 664, 166, 34, 0.002)                \
    TUNE(probcut_see, 108, 216, 54, 11, 0.002)                     \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)              \
                                                                  \
    /* SEE Values */                                              \
    TUNE(quiesce_see_threshold, 18, 36, 9, 2, 0.002)        \
    TUNE(movepicker_see_capthist_divisor, 54, 108, 27, 6, 0.002) \
                                                                  \
    /* Stat Bonus */                                              \
    TUNE(stat_bonus_max, 1828, 3656, 914, 183, 0.002)             \
    TUNE(stat_bonus_quad, 4, 8, 2, 1, 0.002)                     \
    TUNE(stat_bonus_lin, 118, 236, 59, 12, 0.002)                  \
    TUNE(stat_bonus_sub, 123, 246, 62, 13, 0.002)                  \
                                                                  \
    /* Stat Malus */                                              \
    TUNE(stat_malus_max, 1627, 3254, 814, 163, 0.002)             \
    TUNE(stat_malus_quad, 4, 8, 2, 1, 0.002)                     \
    TUNE(stat_malus_lin, 137, 274, 69, 14, 0.002)                  \
    TUNE(stat_malus_sub, 111, 222, 56, 12, 0.002)                  \
                                                                  \
    /* Search Params */                                           \
    TUNE(asp_window_delta, 32, 64, 16, 4, 0.002)                 \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                    \
    TUNE(razor_margin, 681, 1362, 341, 69, 0.002)                 \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)                 \
                                                                  \
    /* Futility Pruning */                                        \
    TUNE(ffp_margin_base, 437, 874, 219, 44, 0.002)              \
    TUNE(ffp_margin_mult, 89, 178, 45, 9, 0.002)                  \
    TUNE(ffp_hist_div, 25, 50, 13, 3, 0.002)                      \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                      \
                                                                  \
    /* Quiet History Pruning */                                   \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                      \
    TUNE(qhp_threshold, -2183, -4366, -1091, -218, 0.002)          \
                                                                  \
    /* SEE PVS */                                                 \
    TUNE(see_pvs_quiet, -65, -130, -32, -6, 0.002)                 \
    TUNE(see_pvs_noisy_quad, -20, -40, -10, -2, 0.002)             \
    TUNE(see_pvs_hist_mult, 16, 32, 8, 2, 0.002)                 \
                                                                  \
    /* Singular Extensions */                                     \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                 \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)              \
    TUNE(sing_beta_margin, 5, 10, 3, 1, 0.002)                    \
    TUNE(dext_margin, 40, 80, 20, 4, 0.002)                       \
    TUNE(dext_hist_div, 491, 982, 246, 50, 0.002)                \
    TUNE(triext_margin, 126, 252, 63, 13, 0.002)                   \
    TUNE(triext_hist_div, 573, 1146, 287, 58, 0.002)              \
                                                                  \
    /* LMR */                                                     \
    TUNE(lmr_quiet_base, 638, 1276, 319, 64, 0.002)               \
    TUNE(lmr_quiet_div, 164, 328, 82, 17, 0.002)                 \
    TUNE(lmr_noisy_base, 258, 516, 129, 26, 0.002)                \
    TUNE(lmr_noisy_div, 193, 386, 97, 20, 0.002)                  \
    TUNE(lmr_pv_node_red, 1207, 2414, 604, 121, 0.002)             \
    TUNE(lmr_alpha_raise_red, 514, 1028, 257, 52, 0.002)          \
    TUNE(lmr_not_improving_red, 520, 1040, 260, 52, 0.002)        \
    TUNE(lmr_in_check_red, 1021, 2042, 511, 103, 0.002)            \
    TUNE(lmr_cutnode_red, 1087, 2174, 544, 109, 0.002)             \
    TUNE(lmr_no_tt_red, 997, 1994, 499, 100, 0.002)                \
    TUNE(lmr_ttpv_red, 1097, 2194, 549, 110, 0.002)                \
    TUNE(lmr_tt_capture_red, 968, 1936, 484, 97, 0.002)           \
    TUNE(lmr_fail_high_red, 980, 1960, 490, 98, 0.002)            \
    TUNE(lmr_quiet_hist_base, 940, 1880, 470, 94, 0.002)          \
    TUNE(lmr_hist_div, 12, 24, 6, 2, 0.002)                       \
    TUNE(lmr_fut_red_base, 562, 1124, 281, 57, 0.002)             \
    TUNE(lmr_fut_red_mult, 99, 198, 50, 10, 0.002)                 \
    TUNE(lmr_fut_red, 864, 1728, 432, 87, 0.002)                  \
    TUNE(lmr_max_red, 2985, 5970, 1493, 299, 0.002)               \
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
