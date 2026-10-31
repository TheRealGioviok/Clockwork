#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(112, 296);
inline const PParam KNIGHT_MAT = S(475, 909);
inline const PParam BISHOP_MAT = S(415, 811);
inline const PParam ROOK_MAT   = S(321, 934);
inline const PParam QUEEN_MAT  = S(643, 2136);

inline const PParam TEMPO_VAL  = S(71, 62);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 3);
inline const PParam BISHOP_PAIR_VAL   = S(56, 248);
inline const PParam ROOK_OPEN_VAL     = S(114, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 21);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(20, 8);
inline const PParam SPACE_VAL = S(93, -102);

inline const PParam DOUBLED_PAWN_VAL = S(-19, -97);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -44);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -36);
inline const PParam OUTPOST_KNIGHT_VAL    = S(48, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(36, 27);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 65);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 9);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -9), S(36, 28), S(50, 78), S(112, 237), S(338, 626), S(848, 956),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(53, 29), S(40, 25), S(39, 72), S(82, 197), S(327, 285),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -196), S(-66, -151), S(-36, -19), S(15, 99), S(87, 352), S(217, 592),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-76, 54), S(-73, 31), S(-37, 94), S(-68, 222), S(7, 252), S(126, 112),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-15, 59), S(-14, 50), S(-54, 102), S(-5, 116), S(128, 65), S(52, 141),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(19, -34), S(16, 3), S(7, 42), S(14, 109), S(98, 202), S(348, 215),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(1, -31), S(-1, 5), S(-11, -34), S(-8, -81), S(-33, -153), S(-221, -399),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 198), S(-4, 144), S(-7, 62), S(6, 20), S(22, 17), S(56, 7), S(62, -20),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-148, -10), S(3, -16), S(-11, 77), S(22, 119), S(36, 157), S(45, 166), S(34, 139),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(77, -47), S(118, 176), S(136, 258), S(147, 295), S(159, 328), S(165, 369), S(174, 386), S(183, 408), S(194, 377),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(42, 19), S(105, 235), S(158, 297), S(176, 349), S(193, 381), S(203, 402), S(208, 413), S(208, 427), S(210, 429), S(213, 436), S(225, 422), S(225, 414), S(220, 422), S(174, 387),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(255, 391), S(189, 529), S(210, 556), S(226, 572), S(236, 585), S(239, 592), S(242, 602), S(246, 603), S(249, 611), S(253, 619), S(255, 623), S(250, 631), S(247, 638), S(248, 625), S(259, 592),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(344, 672), S(454, 837), S(482, 935), S(499, 1056), S(517, 1076), S(525, 1111), S(530, 1144), S(532, 1165), S(535, 1186), S(537, 1201), S(539, 1215), S(545, 1218), S(547, 1226), S(551, 1227), S(550, 1236), S(552, 1236), S(547, 1240), S(546, 1236), S(544, 1238), S(550, 1232), S(535, 1231), S(558, 1196), S(518, 1238), S(483, 1230), S(449, 1225), S(419, 1255), S(349, 1319), S(399, 1224),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(101, 271), S(130, 288), S(139, 319), S(145, 331), S(153, 341), S(156, 355), S(158, 369), S(163, 361), S(167, 364), S(172, 357), S(175, 356), S(177, 356), S(177, 351), S(182, 340), S(189, 322), S(190, 311), S(191, 295), S(195, 278), S(201, 262), S(198, 241), S(168, 192),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(214, 325), S(211, 325), S(212, 332), S(211, 363), S(210, 373), S(212, 374), S(210, 383), S(212, 384), S(210, 394), S(208, 399), S(206, 410), S(206, 411), S(207, 414), S(209, 418), S(217, 418), S(224, 410), S(219, 418), S(191, 419),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(242, 423), S(239, 443), S(239, 453), S(240, 465), S(244, 468), S(245, 476), S(245, 484), S(248, 491), S(245, 506), S(248, 510), S(245, 522), S(244, 530), S(240, 545), S(241, 547), S(239, 556), S(232, 568), S(231, 571), S(229, 576), S(223, 582), S(206, 594),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(422, 933), S(411, 991), S(413, 1067), S(420, 1072), S(418, 1104), S(418, 1118), S(420, 1123), S(423, 1139), S(424, 1136), S(429, 1136), S(424, 1155), S(430, 1145), S(434, 1141), S(438, 1137), S(438, 1144), S(444, 1134), S(446, 1122), S(452, 1118), S(459, 1100), S(457, 1109), S(481, 1068), S(487, 1058), S(507, 997),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(3, 6), S(5, 4), S(14, 2), S(1, 16),
};

inline const std::array<PParam, 4> TRAPPED_PIECE = {
    S(-23, 18), S(-37, 95), S(13, -183), S(-216, 15),
};
inline const std::array<PParam, 4> TRAPPED_CONFINED = {
    S(-109, -62), S(-201, -110), S(-162, -54), S(-412, 193),
};
inline const PParam TRAPPED_WALL      = S(-23, -111);
inline const PParam TRAPPED_PAWN_CAGE = S(17, 5);
inline const PParam TRAPPED_ZONE_UTIL = S(103, -37);
inline const PParam TRAPPED_SOFT_WALL = S(127, 100);

inline const PParam PAWN_THREAT_KNIGHT = S(200, 190);
inline const PParam PAWN_THREAT_BISHOP = S(164, 254);
inline const PParam PAWN_THREAT_ROOK   = S(191, 160);
inline const PParam PAWN_THREAT_QUEEN  = S(155, 48);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 56), S(92, 124), S(107, 127), S(184, 103), S(172, 28), }},
  {{ S(10, 58), S(83, 114), S(106, 121), S(215, 636), S(153, -17), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(11, 73), S(43, 139), S(62, 139), S(17, 20), S(163, -60), }},
  {{ S(1, 61), S(57, 110), S(99, 98), S(14, 14), S(199, 1266), }},
}};
inline const PParam KING_THREAT  = S(-24, 149);
inline const PParam REACH_THREAT = S(-13, 11);
inline const PParam REACH_THREAT_LOOSE = S(17, 27);
inline const PParam HANGING_PAWN  = S(36, 99);
inline const PParam HANGING_NON_PAWN  = S(82, 42);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -13), S(11, 31),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(49, 33), S(83, -73),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(40, -5), S(39, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -13), S(-1, -18), S(-6, -25), S(-12, -31), S(-19, -34), S(-21, -43), S(-27, -38), S(-26, -92),
};

inline const PParam ROOK_LINEUP = S(16, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 492),    S(158, 619),    S(148, 588),    S(252, 490),    S(250, 425),    S(222, 462),    S(216, 502),    S(312, 454),    //
    S(126, 312),    S(102, 396),    S(84, 327),     S(104, 244),    S(100, 197),    S(75, 228),     S(75, 292),     S(59, 316),     //
    S(117, 246),    S(80, 271),     S(97, 244),     S(72, 205),     S(59, 183),     S(56, 192),     S(34, 209),     S(40, 254),     //
    S(77, 182),     S(46, 220),     S(77, 203),     S(64, 173),     S(43, 159),     S(41, 167),     S(1, 188),      S(6, 195),      //
    S(61, 142),     S(94, 143),     S(86, 217),     S(74, 192),     S(54, 179),     S(33, 172),     S(-1, 176),     S(-9, 176),     //
    S(86, 160),     S(168, 144),    S(176, 170),    S(130, 220),    S(103, 198),    S(75, 177),     S(32, 197),     S(16, 196),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-204, -396),  S(-195, 174),   S(-236, 245),   S(57, 184),     S(-46, 203),    S(-256, 269),   S(-271, 231),   S(-293, -315),  //
    S(64, 131),     S(51, 175),     S(134, 157),    S(130, 212),    S(142, 190),    S(101, 173),    S(48, 161),     S(9, 162),      //
    S(100, 118),    S(105, 167),    S(110, 178),    S(124, 210),    S(106, 214),    S(78, 180),     S(58, 183),     S(21, 153),     //
    S(147, 181),    S(148, 201),    S(149, 233),    S(148, 301),    S(150, 296),    S(127, 230),    S(107, 187),    S(82, 194),     //
    S(127, 180),    S(144, 171),    S(156, 210),    S(129, 301),    S(127, 294),    S(121, 236),    S(105, 191),    S(74, 170),     //
    S(81, 116),     S(119, 121),    S(128, 158),    S(129, 213),    S(127, 211),    S(110, 153),    S(88, 129),     S(36, 110),     //
    S(106, 127),    S(104, 155),    S(110, 123),    S(117, 163),    S(112, 171),    S(88, 120),     S(35, 169),     S(11, 69),      //
    S(12, 49),      S(74, 109),     S(93, 111),     S(100, 130),    S(86, 138),     S(45, 114),     S(31, 130),     S(-31, 9),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(13, 231),     S(-99, 366),    S(-292, 445),   S(-152, 348),   S(-161, 369),   S(-140, 389),   S(-66, 362),    S(-14, 340),    //
    S(89, 241),     S(46, 363),     S(65, 327),     S(55, 320),     S(55, 332),     S(86, 304),     S(99, 316),     S(67, 284),     //
    S(172, 266),    S(151, 308),    S(150, 327),    S(146, 306),    S(146, 296),    S(139, 315),    S(122, 313),    S(145, 247),    //
    S(139, 242),    S(178, 278),    S(190, 286),    S(211, 307),    S(219, 309),    S(161, 284),    S(160, 267),    S(125, 245),    //
    S(163, 211),    S(161, 268),    S(202, 269),    S(216, 284),    S(203, 293),    S(190, 286),    S(140, 266),    S(129, 220),    //
    S(177, 235),    S(199, 240),    S(216, 267),    S(190, 283),    S(187, 281),    S(184, 275),    S(180, 256),    S(149, 216),    //
    S(153, 183),    S(244, 197),    S(190, 242),    S(177, 260),    S(165, 264),    S(175, 224),    S(176, 211),    S(158, 216),    //
    S(153, 190),    S(144, 226),    S(149, 237),    S(158, 230),    S(143, 240),    S(155, 269),    S(158, 241),    S(153, 194),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(305, 491),    S(336, 496),    S(295, 537),    S(281, 510),    S(328, 472),    S(276, 500),    S(299, 510),    S(288, 503),    //
    S(248, 515),    S(283, 519),    S(335, 478),    S(293, 477),    S(323, 463),    S(288, 485),    S(233, 522),    S(233, 523),    //
    S(218, 500),    S(331, 428),    S(360, 422),    S(321, 405),    S(318, 424),    S(257, 462),    S(239, 494),    S(198, 534),    //
    S(177, 480),    S(237, 479),    S(245, 464),    S(231, 452),    S(252, 433),    S(216, 476),    S(200, 497),    S(160, 518),    //
    S(147, 422),    S(201, 419),    S(186, 451),    S(154, 457),    S(166, 449),    S(156, 473),    S(141, 477),    S(119, 484),    //
    S(149, 347),    S(223, 344),    S(205, 375),    S(181, 392),    S(190, 395),    S(175, 411),    S(167, 398),    S(124, 421),    //
    S(82, 339),     S(204, 280),    S(206, 322),    S(191, 369),    S(199, 362),    S(180, 380),    S(169, 370),    S(138, 373),    //
    S(142, 317),    S(165, 343),    S(227, 328),    S(232, 340),    S(234, 351),    S(207, 379),    S(204, 367),    S(184, 373),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(432, 682),    S(495, 675),    S(386, 853),    S(331, 944),    S(354, 916),    S(409, 804),    S(407, 713),    S(363, 727),    //
    S(401, 732),    S(400, 789),    S(356, 890),    S(247, 1004),   S(293, 961),    S(359, 808),    S(392, 716),    S(383, 672),    //
    S(362, 762),    S(399, 805),    S(351, 900),    S(314, 937),    S(333, 918),    S(378, 805),    S(421, 677),    S(401, 653),    //
    S(354, 714),    S(351, 792),    S(305, 872),    S(302, 919),    S(329, 892),    S(336, 786),    S(382, 695),    S(371, 654),    //
    S(335, 693),    S(335, 704),    S(323, 757),    S(299, 828),    S(307, 838),    S(337, 759),    S(345, 694),    S(361, 614),    //
    S(334, 578),    S(365, 566),    S(352, 667),    S(324, 700),    S(343, 701),    S(345, 725),    S(366, 646),    S(350, 624),    //
    S(309, 419),    S(351, 385),    S(346, 479),    S(369, 544),    S(368, 585),    S(372, 561),    S(350, 594),    S(363, 553),    //
    S(274, 458),    S(322, 261),    S(344, 277),    S(348, 406),    S(363, 472),    S(359, 469),    S(356, 485),    S(326, 533),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(349, -681),   S(581, 13),     S(462, 159),    S(73, 236),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(416, -268),   S(382, 150),    S(241, 227),    S(12, 221),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(241, -32),    S(251, 151),    S(87, 262),     S(-108, 284),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(64, -41),     S(136, 102),    S(-45, 255),    S(-172, 310),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-84, -45),    S(6, 75),       S(-78, 216),    S(-202, 292),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -82),    S(31, 27),      S(-65, 177),    S(-141, 246),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -153),    S(40, -23),     S(-30, 93),     S(-113, 183),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -287),   S(8, -139),     S(-77, -12),    S(-82, 1),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
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
  {{ S(18, -12), S(-6, 7), S(-2, -7), S(9, -11), S(17, -25), S(10, -34), S(5, -41), }},
  {{ S(7, 6), S(-17, 2), S(-11, 7), S(-1, 8), S(2, 3), S(-5, -3), S(-10, -21), }},
  {{ S(3, 9), S(-6, 3), S(-5, 23), S(1, 20), S(3, 12), S(-1, 2), S(-14, -20), }},
  {{ S(8, 18), S(-6, 17), S(-0, 28), S(5, 28), S(6, 25), S(6, 23), S(14, -2), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 22), S(-15, -1), S(-16, 3), S(-16, 21), S(-4, 23),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 5), S(-50, -76), S(-12, -46), S(-4, -10), S(-10, -3), S(-13, 2), S(-13, 2), }},
  {{ S(0, -7), S(-32, -79), S(-5, -57), S(-6, -17), S(-8, -13), S(-16, -6), S(-6, -6), }},
  {{ S(-8, 2), S(-7, -66), S(8, -38), S(-5, -4), S(-11, 2), S(-17, 6), S(-13, 8), }},
  {{ S(-7, -10), S(5, -75), S(9, -47), S(-7, 6), S(-13, -0), S(-18, -5), S(-15, 1), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1432, 1196, -28, -11
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(111);
inline VParam WINNABLE_ASYM = V(97);
inline VParam WINNABLE_PAWN_ENDGAME = V(79);
inline VParam WINNABLE_BIAS = V(-447);

// clang-format on
}  // namespace Clockwork
