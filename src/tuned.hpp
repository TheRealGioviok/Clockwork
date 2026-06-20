#pragma once

#include "util/types.hpp"
#include <string_view>

#define CLOCKWORK_IS_TUNING 1

#ifndef CLOCKWORK_IS_TUNING
    #define CLOCKWORK_IS_TUNING 0
#endif

namespace Clockwork::tuned {

#define CLOCKWORK_TUNABLES(TUNE, NO_TUNE)                         \
                                                                  \
    /* RFP Values */                                              \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                       \
    TUNE(rfp_margin, 4655, 2160, 8640, 324, 0.002)                \
    TUNE(rfp_improving, 3, 0, 4320, 216, 0.002)                   \
    TUNE(rfp_correction_weight, 9, 0, 128, 8, 0.002)              \
                                                                  \
    /* NMP Values */                                              \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                       \
    TUNE(nmp_base_r, 210, 96, 384, 14, 0.002)                     \
    TUNE(nmp_depth_r, 15, 8, 32, 1, 0.002)                        \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)            \
    TUNE(nmp_beta_margin_base, 222, 125, 500, 19, 0.002)          \
    TUNE(nmp_beta_depth_margin, 23, 1, 30, 3, 0.002)              \
    TUNE(nmp_beta_diff, 429, 200, 800, 38, 0.002)                 \
    TUNE(nmp_beta_improving, 0, 0, 160, 8, 0.002)                 \
    TUNE(nmp_improving_r, 65, 32, 128, 5, 0.002)                  \
                                                                  \
    /* ProbCut Values */                                          \
    TUNE(probcut_margin, 365, 169, 678, 25, 0.002)                \
    TUNE(probcut_see, 107, 57, 228, 8, 0.002)                     \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)              \
                                                                  \
    /* SEE Values */                                              \
    TUNE(quiesce_see_threshold, 3, -200, 200, 16, 0.002)         \
    TUNE(movepicker_see_capthist_divisor, 44, 16, 128, 6, 0.002)  \
    TUNE(see_pawn_val, 93, 86, 120, 3, 0.002)                     \
    TUNE(see_knight_val, 314, 290, 334, 4, 0.002)                 \
    TUNE(see_bishop_val, 305, 290, 334, 4, 0.002)                 \
    TUNE(see_rook_val, 563, 500, 640, 6, 0.002)                   \
    TUNE(see_queen_val, 946, 900, 1100, 8, 0.002)                 \
                                                                  \
    /* Stat Bonus */                                              \
    TUNE(stat_bonus_max, 1767, 948, 3792, 142, 0.002)             \
    TUNE(stat_bonus_quad, 5, 2, 8, .5, 0.002)                     \
    TUNE(stat_bonus_lin, 99, 60, 240, 9, 0.002)                   \
    TUNE(stat_bonus_sub, 139, 60, 240, 9, 0.002)                  \
                                                                  \
    /* Stat Malus */                                              \
    TUNE(stat_malus_max, 1125, 948, 3792, 142, 0.002)              \
    TUNE(stat_malus_quad, 3, 2, 8, .5, 0.002)                     \
    TUNE(stat_malus_lin, 131, 60, 240, 9, 0.002)                  \
    TUNE(stat_malus_sub, 107, 60, 240, 9, 0.002)                  \
                                                                  \
    /* Search Params */                                           \
    TUNE(asp_window_delta, 28, 12, 50, 3, 0.002)                  \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                    \
    TUNE(razor_margin, 712, 353, 1414, 53, 0.002)                 \
    TUNE(lmp_hh_div, 7601, 4096, 16384, 512, 0.002)               \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)                 \
                                                                  \
    /* Futility Pruning */                                        \
    TUNE(ffp_margin_base, 402070, 219648, 878592, 32947, 0.002)   \
    TUNE(ffp_margin_depth, 88859, 48640, 194560, 7296, 0.002)     \
    TUNE(ffp_margin_improving, 9013, 0, 204800, 10240, 0.002)        \
    TUNE(ffp_margin_hist, 45, 25, 100, 4, 0.002)                  \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                      \
                                                                  \
    /* Quiet History Pruning */                                   \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                      \
    TUNE(qhp_threshold, -2292, -4096, -1024, 154, 0.002)          \
                                                                  \
    /* SEE PVS */                                                 \
    TUNE(see_pvs_quiet_lin, -64, -118, -29, 5, 0.002)             \
    TUNE(see_pvs_noisy_quad, -14, -33, -1, 2, 0.002)              \
    TUNE(see_pvs_quiet_hist, 15, 8, 34, 2, 0.002)                 \
    TUNE(see_pvs_noisy_hist, 15, 8, 34, 2, 0.002)                 \
                                                                  \
    /* Singular Extensions */                                     \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                 \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)              \
    TUNE(sing_beta_exact_margin, 237, 126, 504, 19, 0.002)        \
    TUNE(sing_beta_margin, 230, 126, 504, 19, 0.002)              \
    TUNE(dext_margin, 40, 19, 76, 2, 0.002)                       \
    TUNE(dext_hist_div, 454, 249, 996, 39, 0.002)                 \
    TUNE(triext_margin, 112, 60, 240, 9, 0.002)                   \
    TUNE(triext_hist_div, 570, 267, 1068, 39, 0.002)              \
                                                                  \
    /* LMR */                                                     \
    TUNE(lmr_quiet_base, 672, 307, 1228, 46, 0.002)               \
    TUNE(lmr_quiet_div, 158, 86, 346, 12, 0.002)                  \
    TUNE(lmr_noisy_base, 222, 120, 482, 18, 0.002)                \
    TUNE(lmr_noisy_div, 239, 113, 452, 16, 0.002)                 \
    TUNE(lmr_pv_node_red, 1263, 663, 2652, 77, 0.002)             \
    TUNE(lmr_alpha_raise_red, 482, 259, 1036, 38, 0.002)          \
    TUNE(lmr_not_improving_red, 505, 272, 1088, 38, 0.002)        \
    TUNE(lmr_in_check_red, 1119, 520, 2080, 77, 0.002)            \
    TUNE(lmr_corrplexity, 1, 0, 1024, 52, 0.002)                  \
    TUNE(lmr_cutnode_red, 1179, 629, 2516, 77, 0.002)             \
    TUNE(lmr_exact_bound, 79, -1024, 1024, 77, 0.002)              \
    TUNE(lmr_no_tt_red, 841, 459, 1838, 68, 0.002)                \
    TUNE(lmr_ttpv_red, 901, 488, 1952, 73, 0.002)                 \
    TUNE(lmr_tt_capture_red, 1113, 512, 2048, 77, 0.002)          \
    TUNE(lmr_ttpv_fail_low, 1094, 512, 2048, 77, 0.002)           \
    TUNE(lmr_fail_high_red, 1014, 471, 1884, 70, 0.002)            \
    TUNE(lmr_fail_high_all, 409, 192, 768, 28, 0.002)             \
    TUNE(lmr_quiet_hist_base, 952, 439, 1758, 65, 0.002)          \
    TUNE(lmr_hist_div, 85, 39, 158, 5, 0.002)                     \
    TUNE(lmr_fut_red_base, 566, 265, 1060, 39, 0.002)             \
    TUNE(lmr_fut_red_mult, 116, 50, 200, 8, 0.002)                \
    TUNE(lmr_fut_red, 683, 317, 1268, 47, 0.002)                  \
    NO_TUNE(lmr_max_red, 3211, 1605, 6422, 512, 0.002)            \
                                                                  \
    /* DO DEEPER / SHALLOWER */                                   \
    TUNE(do_deeper_margin, 89, 74, 135, 5, 0.002)                 \
                                                                  \
    /* TIME MANAGEMENT */                                         \
    TUNE(time_hard_limit, 300, 143, 572, 15, 0.002)               \
    TUNE(time_soft_limit, 53, 25, 100, 3, 0.002)                  \
    TUNE(time_soft_increment, 532, 283, 1132, 30, 0.002)          \
    TUNE(nodetm_min_factor, 373, 200, 800, 30, 0.002)             \
    TUNE(nodetm_avg_factor, 2512, 1190, 4760, 128, 0.002)         \
    TUNE(nodetm_frac_factor, 2357, 1098, 4394, 128, 0.002)        \
    TUNE(d1plexity_base, 1052, 489, 1956, 64, 0.002)               \
    TUNE(d1plexity_max_complexity, 238, 111, 446, 16, 0.002)      \
    TUNE(d1plexity_divisor, 372, 205, 820, 30, 0.002)             \
                                                                  \
    TUNE(CONTHIST_WEIGHT_1, 928, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_WEIGHT_2, 1096, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_WEIGHT_4, 1096, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_WEIGHT_6, 954, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_STATS, 1908, 1024, 4192, 154, 0.002)            \
                                                                  \
    TUNE(CONTHIST_UPDATE_1, 1113, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_UPDATE_2, 954, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_UPDATE_4, 1096, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_UPDATE_6, 928, 512, 2048, 77, 0.002)

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
