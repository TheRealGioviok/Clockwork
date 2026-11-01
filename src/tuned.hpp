#pragma once

#include "util/types.hpp"
#include <string_view>

#define CLOCKWORK_IS_TUNING 1

#ifndef CLOCKWORK_IS_TUNING
    #define CLOCKWORK_IS_TUNING 0
#endif

namespace Clockwork::tuned {

#define CLOCKWORK_TUNABLES(TUNE, NO_TUNE)                            \
                                                                     \
    /* RFP Values */                                                 \
    TUNE(rfp_margin, 135, 67, 270, 7, 0.002)                         \
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                          \
                                                                     \
    /* NMP Values */        \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                          \
    NO_TUNE(nmp_base_r, 192, 64, 384, 16, 0.002)                     \
    TUNE(nmp_depth_r, 16, 8, 32, 1, 0.002)                           \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)               \
    TUNE(nmp_beta_margin, 33, 16, 66, 2, 0.002)                      \
    TUNE(nmp_beta_diff, 390, 195, 780, 10, 0.002)                    \
    TUNE(nmp_eval_r_cap, 192, 96, 384, 5, 0.002)                     \
    TUNE(nmp_improving_r, 61, 30, 122, 2, 0.002)                     \
                                                                     \
    /* ProbCut Values */                                             \
    TUNE(probcut_margin, 339, 170, 678, 17, 0.002)                   \
    TUNE(probcut_see, 114, 57, 228, 6, 0.002)                        \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)                 \
                                                                     \
    /* SEE Values */                                                 \
    TUNE(quiesce_see_threshold, 18, -100, 150, 8, 0.002)             \
    TUNE(movepicker_see_capthist_divisor, 51, 25, 102, 3, 0.002)     \
    TUNE(see_pawn_val, 96, 48, 192, 5, 0.002)                        \
    TUNE(see_knight_val, 310, 155, 620, 15, 0.002)                   \
    TUNE(see_bishop_val, 278, 139, 556, 14, 0.002)                   \
    TUNE(see_rook_val, 570, 285, 1140, 28, 0.002)                    \
    TUNE(see_queen_val, 939, 470, 1878, 47, 0.002)                   \
                                                                     \
    /* Move ordering (relative scale vs capthist: half step) */      \
    TUNE(mvv_pawn, 800, 400, 1600, 20, 0.002)                        \
    TUNE(mvv_knight, 2400, 1200, 4800, 60, 0.002)                    \
    TUNE(mvv_bishop, 2400, 1200, 4800, 60, 0.002)                    \
    TUNE(mvv_rook, 4800, 2400, 9600, 120, 0.002)                     \
    TUNE(mvv_queen, 7200, 3600, 14400, 180, 0.002)                   \
    TUNE(promo_order_base, 500, 250, 1000, 12, 0.002)                \
                                                                     \
    TUNE(stat_bonus_max, 1882, 941, 3764, 94, 0.002)                 \
    TUNE(stat_bonus_quad, 64, 32, 128, 2, 0.002)                     \
    TUNE(stat_bonus_lin, 91, 45, 182, 2, 0.002)                      \
    TUNE(stat_bonus_sub, 149, 75, 298, 4, 0.002)                     \
                                                                     \
    TUNE(stat_malus_max, 996, 498, 1992, 50, 0.002)                  \
    TUNE(stat_malus_quad, 48, 24, 96, 1, 0.002)                      \
    TUNE(stat_malus_lin, 122, 61, 244, 3, 0.002)                     \
    TUNE(stat_malus_sub, 118, 59, 236, 3, 0.002)                     \
                                                                     \
    /* History */                                                    \
    TUNE(conthist_bonus_mult, 512, 256, 1024, 26, 0.002)             \
    TUNE(hist_bonus_depth_margin, 100, 50, 200, 5, 0.002)            \
                                                                     \
    TUNE(corrhist_weight_max, 16, 8, 32, 1, 0.002)                   \
    TUNE(corrhist_weight_base, 64, 32, 128, 3, 0.002)                \
    TUNE(corrhist_weight_depth, 64, 32, 128, 3, 0.002)               \
                                                                     \
    /* Search Params */                                              \
    TUNE(asp_window_delta, 25, 12, 50, 1, 0.002)                     \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                       \
    TUNE(razor_margin, 657, 328, 1314, 33, 0.002)                    \
                                                                     \
    NO_TUNE(lmp_not_improving_mult, 512, 256, 1024, 26, 0.002)       \
    TUNE(lmp_improving_mult, 1024, 512, 2048, 51, 0.002)             \
    TUNE(lmp_base, 192, 64, 512, 12, 0.002)                          \
    TUNE(lmp_lin, 0, -192, 192, 10, 0.002)                           \
    TUNE(lmp_quad, 64, 32, 128, 3, 0.002)                            \
    TUNE(adj_shuffle_div, 200, 100, 400, 10, 0.002)                  \
    TUNE(capt_ext_material, 1140, 570, 2280, 57, 0.002)              \
                                                                     \
    /* Futility Pruning (one margin: half step; hist_div x64) */     \
    TUNE(ffp_margin_base, 429, 215, 858, 11, 0.002)                  \
    TUNE(ffp_margin_mult, 95, 47, 190, 3, 0.002)                     \
    TUNE(ffp_hist_div, 1344, 672, 2688, 34, 0.002)                   \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                         \
                                                                     \
    /* Bad Noisy Futility Pruning */                                 \
    TUNE(bnfp_margin_mult, 75, 37, 150, 4, 0.002)                    \
    NO_TUNE(bnfp_depth, 8, 1, 20, 0.5, 0.002)                        \
                                                                     \
    /* Quiet History Pruning */                                      \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                         \
    TUNE(qhp_threshold, -2133, -4266, -1066, 107, 0.002)             \
                                                                     \
    /* SEE PVS (noisy_quad in 1/64 units) */                         \
    TUNE(see_pvs_quiet, -59, -118, -30, 3, 0.002)                    \
    TUNE(see_pvs_noisy_quad, -704, -1408, -352, 35, 0.002)           \
    TUNE(see_pvs_hist_mult, 17, 8, 34, 1, 0.002)                     \
                                                                     \
    /* Singular Extensions */                                        \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                    \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)                 \
    TUNE(sing_beta_margin, 252, 126, 504, 13, 0.002)                 \
    TUNE(dext_margin, 38, 19, 76, 2, 0.002)                          \
    TUNE(dext_hist_div, 498, 249, 996, 25, 0.002)                    \
    TUNE(triext_margin, 120, 60, 240, 6, 0.002)                      \
    TUNE(triext_hist_div, 534, 267, 1068, 27, 0.002)                 \
                                                                     \
    /* LMR */                                                        \
    TUNE(lmr_quiet_base, 614, 307, 1228, 31, 0.002)                  \
    TUNE(lmr_quiet_div, 173, 86, 346, 9, 0.002)                      \
    TUNE(lmr_noisy_base, 241, 120, 482, 12, 0.002)                   \
    TUNE(lmr_noisy_div, 226, 113, 452, 11, 0.002)                    \
    TUNE(lmr_pv_node_red, 1326, 663, 2652, 66, 0.002)                \
    TUNE(lmr_alpha_raise_red, 518, 259, 1036, 26, 0.002)             \
    TUNE(lmr_not_improving_red, 544, 272, 1088, 27, 0.002)           \
    TUNE(lmr_in_check_red, 1040, 520, 2080, 52, 0.002)               \
    TUNE(lmr_cutnode_red, 1258, 629, 2516, 63, 0.002)                \
    TUNE(lmr_no_tt_red, 919, 460, 1838, 46, 0.002)                   \
    TUNE(lmr_ttpv_red, 976, 488, 1952, 49, 0.002)                    \
    TUNE(lmr_tt_capture_red, 1024, 512, 2048, 51, 0.002)             \
    TUNE(lmr_ttpv_fail_low, 1024, 512, 2048, 51, 0.002)              \
    TUNE(lmr_fail_high_red, 942, 471, 1884, 47, 0.002)               \
    TUNE(lmr_quiet_hist_base, 879, 440, 1758, 44, 0.002)             \
    TUNE(lmr_hist_div, 832, 416, 1664, 42, 0.002)                    \
    TUNE(lmr_fut_red_base, 530, 265, 1060, 13, 0.002)                \
    TUNE(lmr_fut_red_mult, 107, 53, 214, 3, 0.002)                   \
    TUNE(lmr_fut_red, 634, 317, 1268, 32, 0.002)                     \
    TUNE(lmr_max_red, 3211, 1605, 6422, 160, 0.002)                  \
    TUNE(lmr_deeper_margin, 94, 47, 188, 5, 0.002)                   \
    TUNE(lmr_shallower_mult, 1024, 512, 2048, 51, 0.002)             \
                                                                     \
    /* TIME MANAGEMENT (complexity terms interact: half step) */     \
    TUNE(time_hard_limit, 286, 143, 572, 14, 0.002)                  \
    TUNE(time_soft_limit, 50, 25, 100, 2, 0.002)                     \
    TUNE(time_soft_increment, 566, 283, 1132, 28, 0.002)             \
    TUNE(nodetm_min_factor, 400, 200, 800, 20, 0.002)                \
    TUNE(nodetm_avg_factor, 2380, 1190, 4760, 119, 0.002)            \
    TUNE(nodetm_frac_factor, 2197, 1098, 4394, 110, 0.002)           \
    TUNE(tm_complexity_mult, 600, 300, 1200, 15, 0.002)              \
    TUNE(d1plexity_base, 978, 489, 1956, 24, 0.002)                  \
    TUNE(d1plexity_max_complexity, 223, 111, 446, 6, 0.002)          \
    TUNE(d1plexity_divisor, 410, 205, 820, 10, 0.002)                \
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
