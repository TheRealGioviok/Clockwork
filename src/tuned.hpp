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
    TUNE(rfp_margin, 134, 67, 270, 7, 0.002)                     \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                      \
                                                                 \
    /* NMP Values */                                             \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                      \
    NO_TUNE(nmp_base_r, 192, 64, 384, 16, 0.002)                 \
    TUNE(nmp_depth_r, 19, 8, 32, 1, 0.002)                       \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)           \
    TUNE(nmp_beta_margin, 33, 16, 66, 2, 0.002)                  \
    TUNE(nmp_beta_diff, 393, 195, 780, 10, 0.002)                \
    TUNE(nmp_eval_r_cap, 198, 96, 384, 5, 0.002)                 \
    TUNE(nmp_improving_r, 60, 30, 122, 2, 0.002)                 \
                                                                 \
    /* ProbCut Values */                                         \
    TUNE(probcut_margin, 334, 170, 678, 17, 0.002)               \
    TUNE(probcut_see, 110, 57, 228, 6, 0.002)                    \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)             \
                                                                 \
    /* SEE Values */                                             \
    TUNE(quiesce_see_threshold, 16, -100, 150, 8, 0.002)         \
    TUNE(movepicker_see_capthist_divisor, 53, 25, 102, 3, 0.002) \
    TUNE(see_pawn_val, 99, 48, 192, 5, 0.002)                    \
    TUNE(see_knight_val, 294, 155, 620, 15, 0.002)               \
    TUNE(see_bishop_val, 259, 139, 556, 14, 0.002)               \
    TUNE(see_rook_val, 566, 285, 1140, 28, 0.002)                \
    TUNE(see_queen_val, 993, 470, 1878, 47, 0.002)               \
                                                                 \
    /* Move ordering */                                          \
    TUNE(mvv_pawn, 812, 400, 1600, 20, 0.002)                    \
    TUNE(mvv_knight, 2467, 1200, 4800, 60, 0.002)                \
    TUNE(mvv_bishop, 2435, 1200, 4800, 60, 0.002)                \
    TUNE(mvv_rook, 4771, 2400, 9600, 120, 0.002)                 \
    TUNE(mvv_queen, 6992, 3600, 14400, 180, 0.002)               \
    TUNE(promo_order_base, 517, 250, 1000, 12, 0.002)            \
                                                                 \
    TUNE(stat_bonus_max, 1916, 941, 3764, 94, 0.002)             \
    TUNE(stat_bonus_quad, 63, 32, 128, 2, 0.002)                 \
    TUNE(stat_bonus_lin, 91, 45, 182, 2, 0.002)                  \
    TUNE(stat_bonus_sub, 151, 75, 298, 4, 0.002)                 \
                                                                 \
    TUNE(stat_malus_max, 951, 498, 1992, 50, 0.002)              \
    TUNE(stat_malus_quad, 49, 24, 96, 1, 0.002)                  \
    TUNE(stat_malus_lin, 125, 61, 244, 3, 0.002)                 \
    TUNE(stat_malus_sub, 116, 59, 236, 3, 0.002)                 \
                                                                 \
    /* History */                                                \
    TUNE(conthist_bonus_mult, 477, 256, 1024, 26, 0.002)         \
    TUNE(hist_bonus_depth_margin, 109, 50, 200, 5, 0.002)        \
                                                                 \
    TUNE(corrhist_weight_max, 15, 8, 32, 1, 0.002)               \
    TUNE(corrhist_weight_base, 67, 32, 128, 3, 0.002)            \
    TUNE(corrhist_weight_depth, 62, 32, 128, 3, 0.002)           \
                                                                 \
    /* Search Params */                                          \
    TUNE(asp_window_delta, 25, 12, 50, 1, 0.002)                 \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                   \
    TUNE(razor_margin, 668, 328, 1314, 33, 0.002)                \
                                                                 \
    NO_TUNE(lmp_not_improving_mult, 512, 256, 1024, 26, 0.002)   \
    TUNE(lmp_improving_mult, 930, 512, 2048, 51, 0.002)          \
    TUNE(lmp_base, 219, 64, 512, 12, 0.002)                      \
    TUNE(lmp_lin, 11, -192, 192, 10, 0.002)                      \
    TUNE(lmp_quad, 62, 32, 128, 3, 0.002)                        \
    TUNE(adj_shuffle_div, 192, 100, 400, 10, 0.002)              \
    TUNE(capt_ext_material, 1136, 570, 2280, 57, 0.002)          \
                                                                 \
    /* Futility Pruning */                                       \
    TUNE(ffp_margin_base, 443, 215, 858, 11, 0.002)              \
    TUNE(ffp_margin_mult, 95, 47, 190, 3, 0.002)                 \
    TUNE(ffp_hist_div, 1301, 672, 2688, 34, 0.002)               \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                     \
                                                                 \
    /* Bad Noisy Futility Pruning */                             \
    TUNE(bnfp_margin_mult, 71, 37, 150, 4, 0.002)                \
    NO_TUNE(bnfp_depth, 8, 1, 20, 0.5, 0.002)                    \
                                                                 \
    /* Quiet History Pruning */                                  \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                     \
    TUNE(qhp_threshold, -2078, -4266, -1066, 107, 0.002)         \
                                                                 \
    /* SEE PVS */                                                \
    TUNE(see_pvs_quiet, -51, -118, -30, 3, 0.002)                \
    TUNE(see_pvs_noisy_quad, -664, -1408, -352, 35, 0.002)       \
    TUNE(see_pvs_hist_mult, 17, 8, 34, 1, 0.002)                 \
                                                                 \
    /* Singular Extensions */                                    \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)             \
    TUNE(sing_beta_margin, 231, 126, 504, 13, 0.002)             \
    TUNE(dext_margin, 33, 19, 76, 2, 0.002)                      \
    TUNE(dext_hist_div, 481, 249, 996, 25, 0.002)                \
    TUNE(triext_margin, 115, 60, 240, 6, 0.002)                  \
    TUNE(triext_hist_div, 568, 267, 1068, 27, 0.002)             \
                                                                 \
    /* LMR */                                                    \
    TUNE(lmr_quiet_base, 646, 307, 1228, 31, 0.002)              \
    TUNE(lmr_quiet_div, 172, 86, 346, 9, 0.002)                  \
    TUNE(lmr_noisy_base, 233, 120, 482, 12, 0.002)               \
    TUNE(lmr_noisy_div, 244, 113, 452, 11, 0.002)                \
    TUNE(lmr_pv_node_red, 1310, 663, 2652, 66, 0.002)            \
    TUNE(lmr_alpha_raise_red, 504, 259, 1036, 26, 0.002)         \
    TUNE(lmr_not_improving_red, 594, 272, 1088, 27, 0.002)       \
    TUNE(lmr_in_check_red, 1024, 520, 2080, 52, 0.002)           \
    TUNE(lmr_cutnode_red, 1271, 629, 2516, 63, 0.002)            \
    TUNE(lmr_no_tt_red, 874, 460, 1838, 46, 0.002)               \
    TUNE(lmr_ttpv_red, 1045, 488, 1952, 49, 0.002)               \
    TUNE(lmr_tt_capture_red, 1047, 512, 2048, 51, 0.002)         \
    TUNE(lmr_ttpv_fail_low, 1057, 512, 2048, 51, 0.002)          \
    TUNE(lmr_fail_high_red, 924, 471, 1884, 47, 0.002)           \
    TUNE(lmr_quiet_hist_base, 800, 440, 1758, 44, 0.002)         \
    TUNE(lmr_hist_div, 807, 416, 1664, 42, 0.002)                \
    TUNE(lmr_fut_red_base, 541, 265, 1060, 13, 0.002)            \
    TUNE(lmr_fut_red_mult, 101, 53, 214, 3, 0.002)               \
    TUNE(lmr_fut_red, 575, 317, 1268, 32, 0.002)                 \
    TUNE(lmr_max_red, 3247, 1605, 6422, 160, 0.002)              \
    TUNE(lmr_deeper_margin, 94, 47, 188, 5, 0.002)               \
    TUNE(lmr_shallower_mult, 965, 512, 2048, 51, 0.002)          \
                                                                 \
    /* TIME MANAGEMENT */                                        \
    TUNE(time_hard_limit, 285, 143, 572, 14, 0.002)              \
    TUNE(time_soft_limit, 53, 25, 100, 2, 0.002)                 \
    TUNE(time_soft_increment, 610, 283, 1132, 28, 0.002)         \
    TUNE(nodetm_min_factor, 400, 200, 800, 20, 0.002)            \
    TUNE(nodetm_avg_factor, 2605, 1190, 4760, 119, 0.002)        \
    TUNE(nodetm_frac_factor, 2447, 1098, 4394, 110, 0.002)       \
    TUNE(tm_complexity_mult, 574, 300, 1200, 15, 0.002)          \
    TUNE(d1plexity_base, 975, 489, 1956, 24, 0.002)              \
    TUNE(d1plexity_max_complexity, 228, 111, 446, 6, 0.002)      \
    TUNE(d1plexity_divisor, 394, 205, 820, 10, 0.002)            \
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
