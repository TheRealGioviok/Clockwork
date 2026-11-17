#pragma once

#include "util/types.hpp"
#include <string_view>

#define CLOCKWORK_IS_TUNING 0

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
    TUNE(nmp_depth_r, 18, 8, 32, 1, 0.002)                           \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)               \
    TUNE(nmp_beta_margin, 32, 16, 66, 2, 0.002)                      \
    TUNE(nmp_beta_diff, 399, 195, 780, 10, 0.002)                    \
    TUNE(nmp_eval_r_cap, 197, 96, 384, 5, 0.002)                     \
    TUNE(nmp_improving_r, 61, 30, 122, 2, 0.002)                     \
                                                                     \
    /* ProbCut Values */                                             \
    TUNE(probcut_margin, 343, 170, 678, 17, 0.002)                   \
    TUNE(probcut_see, 108, 57, 228, 6, 0.002)                        \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)                 \
                                                                     \
    /* SEE Values */                                                 \
    TUNE(quiesce_see_threshold, 15, -100, 150, 8, 0.002)             \
    TUNE(movepicker_see_capthist_divisor, 53, 25, 102, 3, 0.002)     \
    TUNE(see_pawn_val, 98, 48, 192, 5, 0.002)                        \
    TUNE(see_knight_val, 289, 155, 620, 15, 0.002)                   \
    TUNE(see_bishop_val, 253, 139, 556, 14, 0.002)                   \
    TUNE(see_rook_val, 565, 285, 1140, 28, 0.002)                    \
    TUNE(see_queen_val, 964, 470, 1878, 47, 0.002)                   \
                                                                     \
    /* Move ordering (relative scale vs capthist: half step) */      \
    TUNE(mvv_pawn, 806, 400, 1600, 20, 0.002)                        \
    TUNE(mvv_knight, 2425, 1200, 4800, 60, 0.002)                    \
    TUNE(mvv_bishop, 2440, 1200, 4800, 60, 0.002)                    \
    TUNE(mvv_rook, 4706, 2400, 9600, 120, 0.002)                     \
    TUNE(mvv_queen, 7105, 3600, 14400, 180, 0.002)                   \
    TUNE(promo_order_base, 513, 250, 1000, 12, 0.002)                \
                                                                     \
    TUNE(stat_bonus_max, 1940, 941, 3764, 94, 0.002)                 \
    TUNE(stat_bonus_quad, 65, 32, 128, 2, 0.002)                     \
    TUNE(stat_bonus_lin, 91, 45, 182, 2, 0.002)                      \
    TUNE(stat_bonus_sub, 150, 75, 298, 4, 0.002)                     \
                                                                     \
    TUNE(stat_malus_max, 949, 498, 1992, 50, 0.002)                  \
    TUNE(stat_malus_quad, 48, 24, 96, 1, 0.002)                      \
    TUNE(stat_malus_lin, 126, 61, 244, 3, 0.002)                     \
    TUNE(stat_malus_sub, 115, 59, 236, 3, 0.002)                     \
                                                                     \
    /* History */                                                    \
    TUNE(conthist_bonus_mult, 475, 256, 1024, 26, 0.002)             \
    TUNE(hist_bonus_depth_margin, 110, 50, 200, 5, 0.002)            \
                                                                     \
    TUNE(corrhist_weight_max, 15, 8, 32, 1, 0.002)                   \
    TUNE(corrhist_weight_base, 65, 32, 128, 3, 0.002)                \
    TUNE(corrhist_weight_depth, 62, 32, 128, 3, 0.002)               \
                                                                     \
    /* Search Params */                                              \
    TUNE(asp_window_delta, 25, 12, 50, 1, 0.002)                     \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                       \
    TUNE(razor_margin, 667, 328, 1314, 33, 0.002)                    \
                                                                     \
    NO_TUNE(lmp_not_improving_mult, 512, 256, 1024, 26, 0.002)       \
    TUNE(lmp_improving_mult, 965, 512, 2048, 51, 0.002)             \
    TUNE(lmp_base, 218, 64, 512, 12, 0.002)                          \
    TUNE(lmp_lin, 12, -192, 192, 10, 0.002)                           \
    TUNE(lmp_quad, 62, 32, 128, 3, 0.002)                            \
    TUNE(adj_shuffle_div, 194, 100, 400, 10, 0.002)                  \
    TUNE(capt_ext_material, 1101, 570, 2280, 57, 0.002)              \
                                                                     \
    /* Futility Pruning (one margin: half step; hist_div x64) */     \
    TUNE(ffp_margin_base, 445, 215, 858, 11, 0.002)                  \
    TUNE(ffp_margin_mult, 96, 47, 190, 3, 0.002)                     \
    TUNE(ffp_hist_div, 1318, 672, 2688, 34, 0.002)                   \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                         \
                                                                     \
    /* Bad Noisy Futility Pruning */                                 \
    TUNE(bnfp_margin_mult, 74, 37, 150, 4, 0.002)                    \
    NO_TUNE(bnfp_depth, 8, 1, 20, 0.5, 0.002)                        \
                                                                     \
    /* Quiet History Pruning */                                      \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                         \
    TUNE(qhp_threshold, -2098, -4266, -1066, 107, 0.002)             \
                                                                     \
    /* SEE PVS (noisy_quad in 1/64 units) */                         \
    TUNE(see_pvs_quiet, -53, -118, -30, 3, 0.002)                    \
    TUNE(see_pvs_noisy_quad, -673, -1408, -352, 35, 0.002)           \
    TUNE(see_pvs_hist_mult, 17, 8, 34, 1, 0.002)                     \
                                                                     \
    /* Singular Extensions */                                        \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                    \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)                 \
    TUNE(sing_beta_margin, 237, 126, 504, 13, 0.002)                 \
    TUNE(dext_margin, 35, 19, 76, 2, 0.002)                          \
    TUNE(dext_hist_div, 489, 249, 996, 25, 0.002)                    \
    TUNE(triext_margin, 117, 60, 240, 6, 0.002)                      \
    TUNE(triext_hist_div, 554, 267, 1068, 27, 0.002)                 \
                                                                     \
    /* LMR */                                                        \
    TUNE(lmr_quiet_base, 651, 307, 1228, 31, 0.002)                  \
    TUNE(lmr_quiet_div, 166, 86, 346, 9, 0.002)                      \
    TUNE(lmr_noisy_base, 225, 120, 482, 12, 0.002)                   \
    TUNE(lmr_noisy_div, 243, 113, 452, 11, 0.002)                    \
    TUNE(lmr_pv_node_red, 1339, 663, 2652, 66, 0.002)                \
    TUNE(lmr_alpha_raise_red, 510, 259, 1036, 26, 0.002)             \
    TUNE(lmr_not_improving_red, 578, 272, 1088, 27, 0.002)           \
    TUNE(lmr_in_check_red, 1023, 520, 2080, 52, 0.002)               \
    TUNE(lmr_cutnode_red, 1214, 629, 2516, 63, 0.002)                \
    TUNE(lmr_no_tt_red, 888, 460, 1838, 46, 0.002)                   \
    TUNE(lmr_ttpv_red, 1027, 488, 1952, 49, 0.002)                    \
    TUNE(lmr_tt_capture_red, 1029, 512, 2048, 51, 0.002)             \
    TUNE(lmr_ttpv_fail_low, 1020, 512, 2048, 51, 0.002)              \
    TUNE(lmr_fail_high_red, 942, 471, 1884, 47, 0.002)               \
    TUNE(lmr_quiet_hist_base, 797, 440, 1758, 44, 0.002)             \
    TUNE(lmr_hist_div, 814, 416, 1664, 42, 0.002)                    \
    TUNE(lmr_fut_red_base, 539, 265, 1060, 13, 0.002)                \
    TUNE(lmr_fut_red_mult, 101, 53, 214, 3, 0.002)                   \
    TUNE(lmr_fut_red, 576, 317, 1268, 32, 0.002)                     \
    TUNE(lmr_max_red, 3172, 1605, 6422, 160, 0.002)                  \
    TUNE(lmr_deeper_margin, 93, 47, 188, 5, 0.002)                   \
    TUNE(lmr_shallower_mult, 990, 512, 2048, 51, 0.002)             \
                                                                     \
    /* TIME MANAGEMENT (complexity terms interact: half step) */     \
    TUNE(time_hard_limit, 278, 143, 572, 14, 0.002)                  \
    TUNE(time_soft_limit, 54, 25, 100, 2, 0.002)                     \
    TUNE(time_soft_increment, 607, 283, 1132, 28, 0.002)             \
    TUNE(nodetm_min_factor, 409, 200, 800, 20, 0.002)                \
    TUNE(nodetm_avg_factor, 2585, 1190, 4760, 119, 0.002)            \
    TUNE(nodetm_frac_factor, 2435, 1098, 4394, 110, 0.002)           \
    TUNE(tm_complexity_mult, 580, 300, 1200, 15, 0.002)              \
    TUNE(d1plexity_base, 978, 489, 1956, 24, 0.002)                  \
    TUNE(d1plexity_max_complexity, 225, 111, 446, 6, 0.002)          \
    TUNE(d1plexity_divisor, 403, 205, 820, 10, 0.002)                \
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
