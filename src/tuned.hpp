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
    NO_TUNE(rfp_depth, 7, 4, 10, .5, 0.002)                      \
    TUNE(rfp_margin, 5787, 2160, 8640, 324, 0.002)               \
    TUNE(rfp_improving, 1514, 0, 4320, 216, 0.002)               \
    TUNE(rfp_correction_weight, 34, 0, 128, 8, 0.002)            \
                                                                 \
    /* NMP Values */                                             \
    NO_TUNE(nmp_depth, 3, 1, 10, .5, 0.002)                      \
    TUNE(nmp_base_r, 264, 96, 384, 14, 0.002)                    \
    TUNE(nmp_depth_r, 15, 8, 32, 1, 0.002)                       \
    NO_TUNE(nmp_verif_min_depth, 14, 1, 40, .5, 0.002)           \
    TUNE(nmp_beta_margin_base, 241, 125, 500, 19, 0.002)         \
    TUNE(nmp_beta_depth_margin, 15, 1, 30, 3, 0.002)             \
    TUNE(nmp_beta_diff, 515, 200, 800, 38, 0.002)                \
    TUNE(nmp_beta_improving, 16, 0, 160, 8, 0.002)               \
    TUNE(nmp_improving_r, 40, 32, 128, 5, 0.002)                 \
                                                                 \
    /* ProbCut Values */                                         \
    TUNE(probcut_margin, 451, 169, 678, 25, 0.002)               \
    TUNE(probcut_see, 85, 57, 228, 8, 0.002)                     \
    NO_TUNE(probcut_min_depth, 5, 1, 20, 0.5, 0.002)             \
                                                                 \
    /* SEE Values */                                             \
    TUNE(quiesce_see_threshold, 142, -200, 200, 16, 0.002)       \
    TUNE(movepicker_see_capthist_divisor, 23, 16, 128, 6, 0.002) \
    TUNE(see_pawn_val, 95, 86, 120, 3, 0.002)                    \
    TUNE(see_knight_val, 295, 290, 334, 4, 0.002)                \
    TUNE(see_bishop_val, 333, 290, 334, 4, 0.002)                \
    TUNE(see_rook_val, 610, 500, 640, 6, 0.002)                  \
    TUNE(see_queen_val, 911, 900, 1100, 8, 0.002)                \
                                                                 \
    /* Stat Bonus */                                             \
    TUNE(stat_bonus_max, 2989, 948, 3792, 142, 0.002)            \
    TUNE(stat_bonus_quad, 7, 2, 8, .5, 0.002)                    \
    TUNE(stat_bonus_lin, 60, 60, 240, 9, 0.002)                  \
    TUNE(stat_bonus_sub, 84, 60, 240, 9, 0.002)                  \
                                                                 \
    /* Stat Malus */                                             \
    TUNE(stat_malus_max, 1189, 948, 3792, 142, 0.002)            \
    TUNE(stat_malus_quad, 3, 2, 8, .5, 0.002)                    \
    TUNE(stat_malus_lin, 111, 60, 240, 9, 0.002)                 \
    TUNE(stat_malus_sub, 61, 60, 240, 9, 0.002)                  \
                                                                 \
    /* Search Params */                                          \
    TUNE(asp_window_delta, 20, 12, 50, 3, 0.002)                 \
    NO_TUNE(razor_depth, 7, 1, 20, 0.5, 0.002)                   \
    TUNE(razor_margin, 1078, 353, 1414, 53, 0.002)               \
    TUNE(lmp_hh_div, 4508, 4096, 16384, 512, 0.002)              \
    NO_TUNE(lmp_depth_mult, 3, 1, 20, 0.5, 0.002)                \
                                                                 \
    /* Futility Pruning */                                       \
    TUNE(ffp_margin_base, 553339, 219648, 878592, 32947, 0.002)  \
    TUNE(ffp_margin_depth, 49939, 48640, 194560, 7296, 0.002)    \
    TUNE(ffp_margin_improving, 321, 0, 204800, 10240, 0.002)     \
    TUNE(ffp_margin_hist, 59, 25, 100, 4, 0.002)                 \
    NO_TUNE(ffp_depth, 8, 1, 20, 0.5, 0.002)                     \
                                                                 \
    /* Quiet History Pruning */                                  \
    NO_TUNE(qhp_depth, 4, 1, 20, 0.5, 0.002)                     \
    TUNE(qhp_threshold, -2838, -4096, -1024, 154, 0.002)         \
                                                                 \
    /* SEE PVS */                                                \
    TUNE(see_pvs_quiet_lin, -63, -118, -29, 5, 0.002)            \
    TUNE(see_pvs_noisy_quad, -8, -33, -1, 2, 0.002)              \
    TUNE(see_pvs_quiet_hist, 12, 8, 34, 2, 0.002)                \
    TUNE(see_pvs_noisy_hist, 13, 8, 34, 2, 0.002)                \
                                                                 \
    /* Singular Extensions */                                    \
    NO_TUNE(sing_min_depth, 6, 1, 20, 0.5, 0.002)                \
    NO_TUNE(sing_depth_margin, 3, 1, 20, 0.5, 0.002)             \
    TUNE(sing_beta_exact_margin, 309, 126, 504, 19, 0.002)       \
    TUNE(sing_beta_margin, 181, 126, 504, 19, 0.002)             \
    TUNE(dext_margin, 34, 19, 76, 2, 0.002)                      \
    TUNE(dext_hist_div, 970, 249, 996, 39, 0.002)                \
    TUNE(triext_margin, 125, 60, 240, 9, 0.002)                  \
    TUNE(triext_hist_div, 410, 267, 1068, 39, 0.002)             \
                                                                 \
    /* LMR */                                                    \
    TUNE(lmr_quiet_base, 436, 307, 1228, 46, 0.002)              \
    TUNE(lmr_quiet_div, 168, 86, 346, 12, 0.002)                 \
    TUNE(lmr_noisy_base, 182, 120, 482, 18, 0.002)               \
    TUNE(lmr_noisy_div, 114, 113, 452, 16, 0.002)                \
    TUNE(lmr_pv_node_red, 1916, 663, 2652, 77, 0.002)            \
    TUNE(lmr_alpha_raise_red, 532, 259, 1036, 38, 0.002)         \
    TUNE(lmr_not_improving_red, 300, 272, 1088, 38, 0.002)       \
    TUNE(lmr_in_check_red, 1564, 520, 2080, 77, 0.002)           \
    TUNE(lmr_corrplexity, 126, 0, 1024, 52, 0.002)                \
    TUNE(lmr_cutnode_red, 1035, 629, 2516, 77, 0.002)            \
    TUNE(lmr_exact_bound, -403, -1024, 1024, 77, 0.002)          \
    TUNE(lmr_no_tt_red, 908, 459, 1838, 68, 0.002)               \
    TUNE(lmr_ttpv_red, 1336, 488, 1952, 73, 0.002)               \
    TUNE(lmr_tt_capture_red, 551, 512, 2048, 77, 0.002)          \
    TUNE(lmr_ttpv_fail_low, 923, 512, 2048, 77, 0.002)           \
    TUNE(lmr_fail_high_red, 1779, 471, 1884, 70, 0.002)          \
    TUNE(lmr_fail_high_all, 509, 192, 768, 28, 0.002)            \
    TUNE(lmr_quiet_hist_base, 819, 439, 1758, 65, 0.002)         \
    TUNE(lmr_hist_div, 82, 39, 158, 5, 0.002)                    \
    TUNE(lmr_fut_red_base, 590, 265, 1060, 39, 0.002)            \
    TUNE(lmr_fut_red_mult, 59, 50, 200, 8, 0.002)                \
    TUNE(lmr_fut_red, 555, 317, 1268, 47, 0.002)                 \
    NO_TUNE(lmr_max_red, 3211, 1605, 6422, 512, 0.002)           \
                                                                 \
    /* DO DEEPER / SHALLOWER */                                  \
    TUNE(do_deeper_margin, 126, 74, 135, 5, 0.002)               \
                                                                 \
    /* TIME MANAGEMENT */                                        \
    TUNE(time_hard_limit, 234, 143, 572, 15, 0.002)              \
    TUNE(time_soft_limit, 54, 25, 100, 3, 0.002)                 \
    TUNE(time_soft_increment, 320, 283, 1132, 30, 0.002)         \
    TUNE(nodetm_min_factor, 503, 200, 800, 30, 0.002)            \
    TUNE(nodetm_avg_factor, 2508, 1190, 4760, 128, 0.002)        \
    TUNE(nodetm_frac_factor, 3126, 1098, 4394, 128, 0.002)       \
    TUNE(d1plexity_base, 1278, 489, 1956, 64, 0.002)             \
    TUNE(d1plexity_max_complexity, 248, 111, 446, 16, 0.002)     \
    TUNE(d1plexity_divisor, 289, 205, 820, 30, 0.002)            \
                                                                 \
    TUNE(CONTHIST_WEIGHT_1, 1264, 512, 2048, 77, 0.002)          \
    TUNE(CONTHIST_WEIGHT_2, 1242, 512, 2048, 77, 0.002)          \
    TUNE(CONTHIST_WEIGHT_4, 1525, 512, 2048, 77, 0.002)          \
    TUNE(CONTHIST_WEIGHT_6, 1459, 512, 2048, 77, 0.002)          \
    TUNE(CONTHIST_STATS, 2698, 1024, 4192, 154, 0.002)           \
                                                                 \
    TUNE(CONTHIST_UPDATE_1, 922, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_UPDATE_2, 1064, 512, 2048, 77, 0.002)          \
    TUNE(CONTHIST_UPDATE_4, 766, 512, 2048, 77, 0.002)           \
    TUNE(CONTHIST_UPDATE_6, 1196, 512, 2048, 77, 0.002)

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
