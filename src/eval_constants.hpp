#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(112, 296);
inline const PParam KNIGHT_MAT = S(478, 913);
inline const PParam BISHOP_MAT = S(416, 811);
inline const PParam ROOK_MAT   = S(322, 931);
inline const PParam QUEEN_MAT  = S(642, 2129);

inline const PParam TEMPO_VAL  = S(71, 61);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 3);
inline const PParam BISHOP_PAIR_VAL   = S(56, 247);
inline const PParam ROOK_OPEN_VAL     = S(114, -5);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 24);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(20, 8);
inline const PParam SPACE_VAL = S(93, -103);

inline const PParam DOUBLED_PAWN_VAL = S(-19, -98);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -37);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -36);
inline const PParam OUTPOST_KNIGHT_VAL    = S(47, 36);
inline const PParam OUTPOST_BISHOP_VAL    = S(36, 26);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 65);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 9);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 69);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -8), S(36, 28), S(51, 78), S(112, 236), S(334, 626), S(846, 957),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 30), S(40, 24), S(40, 71), S(82, 196), S(328, 282),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -194), S(-66, -150), S(-35, -20), S(14, 99), S(86, 350), S(218, 591),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-74, 54), S(-73, 32), S(-35, 94), S(-67, 222), S(9, 250), S(124, 112),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-12, 56), S(-14, 51), S(-53, 103), S(-6, 117), S(129, 66), S(52, 140),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(19, -35), S(16, 2), S(7, 42), S(14, 110), S(98, 202), S(352, 207),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(0, -31), S(-1, 3), S(-10, -37), S(-8, -83), S(-32, -155), S(-221, -399),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(15, 195), S(-4, 146), S(-8, 63), S(6, 21), S(21, 18), S(56, 9), S(62, -18),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-147, -13), S(3, -17), S(-11, 77), S(21, 120), S(35, 158), S(45, 167), S(34, 140),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(76, -48), S(118, 172), S(135, 255), S(146, 293), S(159, 325), S(164, 366), S(174, 383), S(183, 405), S(195, 373),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(41, 18), S(103, 229), S(157, 293), S(176, 346), S(193, 378), S(203, 399), S(208, 410), S(208, 425), S(210, 427), S(212, 436), S(225, 421), S(224, 417), S(219, 423), S(174, 389),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(261, 353), S(189, 528), S(210, 556), S(226, 571), S(236, 584), S(239, 591), S(242, 601), S(246, 602), S(250, 610), S(254, 617), S(255, 622), S(251, 629), S(248, 635), S(249, 623), S(260, 591),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(329, 668), S(454, 831), S(482, 936), S(499, 1057), S(518, 1075), S(525, 1111), S(530, 1144), S(532, 1165), S(535, 1187), S(537, 1201), S(540, 1214), S(545, 1218), S(547, 1227), S(552, 1226), S(550, 1236), S(551, 1238), S(547, 1241), S(546, 1236), S(544, 1239), S(550, 1234), S(534, 1233), S(558, 1199), S(517, 1243), S(484, 1233), S(450, 1227), S(418, 1262), S(348, 1325), S(399, 1231),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(100, 266), S(128, 285), S(137, 317), S(143, 328), S(151, 339), S(154, 352), S(156, 367), S(161, 358), S(165, 360), S(170, 354), S(174, 352), S(175, 352), S(175, 347), S(180, 336), S(188, 318), S(188, 308), S(189, 291), S(194, 275), S(200, 259), S(197, 237), S(167, 188),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(213, 322), S(209, 323), S(210, 331), S(209, 362), S(208, 372), S(210, 373), S(208, 382), S(211, 382), S(209, 393), S(206, 398), S(204, 407), S(205, 409), S(206, 412), S(208, 416), S(216, 416), S(222, 407), S(217, 416), S(190, 415),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(243, 423), S(239, 444), S(239, 453), S(240, 465), S(244, 468), S(245, 476), S(246, 483), S(247, 491), S(245, 505), S(248, 510), S(245, 522), S(244, 530), S(240, 544), S(241, 547), S(239, 555), S(232, 566), S(232, 568), S(230, 574), S(224, 579), S(207, 591),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(424, 929), S(413, 991), S(414, 1068), S(421, 1073), S(419, 1104), S(420, 1118), S(422, 1122), S(425, 1137), S(426, 1135), S(431, 1135), S(425, 1153), S(431, 1144), S(435, 1140), S(439, 1134), S(439, 1142), S(445, 1131), S(447, 1120), S(453, 1115), S(460, 1097), S(456, 1109), S(481, 1067), S(488, 1054), S(506, 994),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(3, 6), S(5, 5), S(14, 2), S(1, 17),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 189);
inline const PParam PAWN_THREAT_BISHOP = S(164, 253);
inline const PParam PAWN_THREAT_ROOK   = S(191, 160);
inline const PParam PAWN_THREAT_QUEEN  = S(156, 45);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 59), S(92, 125), S(108, 125), S(184, 103), S(172, 27), }},
  {{ S(10, 61), S(83, 115), S(106, 120), S(215, 633), S(151, -11), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(11, 77), S(42, 141), S(61, 140), S(17, 20), S(162, -60), }},
  {{ S(1, 64), S(57, 111), S(100, 97), S(14, 15), S(199, 1269), }},
}};
inline const PParam KING_THREAT  = S(-26, 151);
inline const PParam REACH_THREAT = S(-13, 10);
inline const PParam REACH_THREAT_LOOSE = S(18, 27);
inline const PParam REACH_ISOLATED_LOOSE = S(6, 27);
inline const PParam HANGING_PAWN  = S(35, 93);
inline const PParam HANGING_NON_PAWN  = S(82, 42);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -13), S(12, 29),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(49, 32), S(84, -75),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(40, -5), S(37, -4),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -16), S(3, -13), S(-1, -18), S(-6, -25), S(-12, -31), S(-19, -34), S(-21, -43), S(-28, -37), S(-27, -90),
};

inline const PParam ROOK_LINEUP = S(16, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 492),    S(156, 623),    S(148, 589),    S(252, 491),    S(251, 424),    S(222, 463),    S(215, 500),    S(313, 452),    //
    S(126, 314),    S(102, 399),    S(85, 329),     S(104, 248),    S(101, 198),    S(76, 230),     S(75, 294),     S(60, 317),     //
    S(117, 247),    S(81, 272),     S(97, 246),     S(72, 207),     S(59, 184),     S(55, 194),     S(34, 209),     S(40, 255),     //
    S(76, 183),     S(46, 221),     S(77, 203),     S(64, 174),     S(43, 160),     S(41, 168),     S(0, 188),      S(6, 196),      //
    S(61, 143),     S(95, 144),     S(86, 216),     S(74, 193),     S(54, 178),     S(32, 172),     S(-1, 174),     S(-9, 176),     //
    S(87, 159),     S(168, 144),    S(176, 169),    S(130, 219),    S(103, 196),    S(75, 177),     S(32, 195),     S(16, 195),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-205, -400),  S(-197, 175),   S(-242, 251),   S(58, 181),     S(-45, 198),    S(-262, 272),   S(-275, 227),   S(-295, -312),  //
    S(63, 131),     S(51, 175),     S(134, 155),    S(129, 211),    S(140, 190),    S(100, 171),    S(48, 159),     S(10, 160),     //
    S(99, 119),     S(104, 168),    S(110, 176),    S(123, 208),    S(105, 210),    S(77, 179),     S(58, 180),     S(20, 153),     //
    S(147, 178),    S(148, 199),    S(148, 231),    S(148, 298),    S(149, 293),    S(126, 226),    S(107, 184),    S(82, 191),     //
    S(127, 179),    S(143, 169),    S(155, 208),    S(128, 298),    S(127, 290),    S(121, 233),    S(104, 188),    S(74, 167),     //
    S(81, 114),     S(119, 119),    S(128, 155),    S(129, 211),    S(127, 209),    S(110, 150),    S(88, 127),     S(36, 107),     //
    S(107, 124),    S(104, 153),    S(109, 121),    S(117, 161),    S(113, 169),    S(88, 117),     S(35, 168),     S(12, 67),      //
    S(11, 49),      S(74, 109),     S(92, 110),     S(100, 129),    S(86, 136),     S(45, 111),     S(31, 129),     S(-31, 8),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(11, 232),     S(-101, 367),   S(-294, 446),   S(-150, 347),   S(-164, 374),   S(-140, 389),   S(-70, 364),    S(-16, 341),    //
    S(87, 246),     S(44, 368),     S(66, 325),     S(56, 317),     S(54, 333),     S(86, 303),     S(100, 314),    S(69, 281),     //
    S(173, 266),    S(152, 309),    S(153, 323),    S(146, 304),    S(147, 293),    S(141, 310),    S(123, 311),    S(146, 247),    //
    S(139, 244),    S(178, 278),    S(191, 284),    S(212, 303),    S(220, 306),    S(162, 281),    S(160, 265),    S(125, 247),    //
    S(164, 212),    S(161, 269),    S(203, 268),    S(217, 281),    S(204, 289),    S(190, 283),    S(140, 264),    S(129, 220),    //
    S(177, 237),    S(200, 239),    S(217, 265),    S(191, 282),    S(187, 278),    S(185, 273),    S(181, 252),    S(150, 216),    //
    S(153, 182),    S(244, 197),    S(191, 240),    S(178, 259),    S(165, 262),    S(175, 223),    S(177, 210),    S(158, 217),    //
    S(154, 191),    S(144, 225),    S(151, 237),    S(160, 229),    S(143, 241),    S(156, 268),    S(159, 239),    S(153, 195),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(305, 490),    S(337, 494),    S(296, 535),    S(283, 507),    S(330, 470),    S(278, 497),    S(298, 510),    S(289, 500),    //
    S(249, 513),    S(283, 518),    S(335, 478),    S(294, 473),    S(323, 461),    S(289, 483),    S(235, 519),    S(234, 520),    //
    S(218, 500),    S(332, 426),    S(360, 420),    S(321, 403),    S(319, 421),    S(258, 460),    S(239, 493),    S(199, 531),    //
    S(177, 478),    S(237, 478),    S(245, 463),    S(230, 452),    S(251, 431),    S(215, 474),    S(200, 495),    S(161, 516),    //
    S(148, 420),    S(202, 417),    S(186, 449),    S(155, 454),    S(166, 446),    S(156, 470),    S(142, 473),    S(118, 483),    //
    S(149, 346),    S(223, 343),    S(205, 373),    S(181, 391),    S(190, 392),    S(176, 407),    S(166, 397),    S(124, 418),    //
    S(81, 339),     S(204, 277),    S(206, 320),    S(191, 367),    S(198, 360),    S(180, 378),    S(169, 368),    S(137, 372),    //
    S(141, 317),    S(165, 344),    S(226, 329),    S(232, 341),    S(234, 352),    S(207, 380),    S(203, 368),    S(183, 373),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(426, 691),    S(493, 676),    S(383, 857),    S(328, 948),    S(352, 918),    S(406, 810),    S(406, 716),    S(358, 731),    //
    S(398, 736),    S(397, 792),    S(355, 890),    S(245, 1006),   S(291, 962),    S(358, 809),    S(391, 716),    S(380, 673),    //
    S(360, 766),    S(398, 806),    S(350, 899),    S(312, 936),    S(333, 916),    S(376, 804),    S(419, 678),    S(399, 650),    //
    S(352, 718),    S(350, 790),    S(304, 870),    S(301, 916),    S(328, 886),    S(336, 781),    S(381, 693),    S(369, 654),    //
    S(334, 693),    S(334, 702),    S(321, 755),    S(298, 823),    S(307, 833),    S(336, 752),    S(344, 690),    S(360, 610),    //
    S(332, 578),    S(364, 560),    S(351, 663),    S(322, 696),    S(342, 697),    S(344, 719),    S(365, 639),    S(348, 620),    //
    S(307, 421),    S(350, 382),    S(345, 476),    S(368, 540),    S(367, 580),    S(371, 555),    S(349, 588),    S(361, 550),    //
    S(272, 459),    S(320, 262),    S(343, 276),    S(346, 405),    S(362, 470),    S(357, 468),    S(355, 483),    S(324, 531),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(348, -679),   S(582, 12),     S(463, 159),    S(73, 239),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(421, -273),   S(384, 150),    S(240, 231),    S(18, 217),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(241, -30),    S(249, 153),    S(86, 264),     S(-106, 284),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(63, -39),     S(137, 102),    S(-44, 255),    S(-169, 309),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-84, -45),    S(7, 74),       S(-76, 214),    S(-199, 290),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -84),    S(31, 25),      S(-64, 175),    S(-138, 242),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -153),    S(39, -22),     S(-30, 93),     S(-113, 182),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, -287),   S(8, -140),     S(-77, -12),    S(-81, 2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-71, 66);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -2), S(9, 13), S(9, 6), S(3, -1), S(2, -5),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -2), S(5, 3), S(1, 2), S(2, -0), S(3, -1),
};

inline const PParam REACH_INNER_RING = S(1, 0);
inline const PParam REACH_OUTER_RING = S(-0, 1);
inline const PParam REACH_RING_DEFENSE = S(-3, 3);
inline const PParam REACH_RING_TWICE = S(2, 3);

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -12), S(-6, 6), S(-1, -7), S(9, -12), S(18, -26), S(10, -35), S(5, -41), }},
  {{ S(7, 6), S(-17, 2), S(-11, 6), S(-1, 8), S(3, 2), S(-5, -4), S(-11, -21), }},
  {{ S(4, 9), S(-5, 2), S(-4, 22), S(2, 20), S(4, 12), S(-1, 1), S(-13, -21), }},
  {{ S(8, 18), S(-6, 17), S(0, 29), S(5, 28), S(6, 25), S(6, 23), S(14, -2), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 23), S(-15, 0), S(-16, 4), S(-16, 22), S(-4, 24),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 6), S(-51, -76), S(-12, -46), S(-3, -9), S(-10, -2), S(-13, 3), S(-13, 3), }},
  {{ S(0, -6), S(-32, -78), S(-5, -57), S(-6, -16), S(-8, -12), S(-15, -5), S(-6, -6), }},
  {{ S(-8, 3), S(-7, -65), S(8, -37), S(-5, -3), S(-11, 3), S(-17, 8), S(-13, 10), }},
  {{ S(-7, -9), S(5, -74), S(8, -46), S(-7, 7), S(-13, 1), S(-18, -4), S(-15, 2), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1430, 1192, -29, -13
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(110);
inline VParam WINNABLE_ASYM = V(97);
inline VParam WINNABLE_PAWN_ENDGAME = V(78);
inline VParam WINNABLE_BIAS = V(-448);

// Epoch duration: tuned from log reach_isolated_tune.log (epoch 450)
// clang-format on
}  // namespace Clockwork
