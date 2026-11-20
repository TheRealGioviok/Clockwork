#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(113, 297);
inline const PParam KNIGHT_MAT = S(473, 910);
inline const PParam BISHOP_MAT = S(414, 810);
inline const PParam ROOK_MAT   = S(317, 935);
inline const PParam QUEEN_MAT  = S(632, 2155);

inline const PParam TEMPO_VAL  = S(71, 62);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 3);
inline const PParam BISHOP_PAIR_VAL   = S(56, 251);
inline const PParam ROOK_OPEN_VAL     = S(114, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 21);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 8);
inline const PParam SPACE_VAL = S(94, -103);

inline const PParam DOUBLED_PAWN_VAL = S(-19, -96);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -44);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -36);
inline const PParam OUTPOST_KNIGHT_VAL    = S(48, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(37, 27);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 65);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 9);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -8), S(36, 28), S(51, 78), S(112, 237), S(333, 632), S(842, 966),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 29), S(40, 25), S(40, 73), S(82, 198), S(324, 289),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -196), S(-66, -151), S(-36, -20), S(14, 99), S(86, 353), S(218, 593),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-74, 53), S(-75, 31), S(-37, 94), S(-69, 222), S(7, 251), S(125, 111),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-14, 59), S(-15, 51), S(-55, 103), S(-6, 116), S(129, 65), S(51, 142),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(19, -33), S(16, 3), S(6, 43), S(13, 111), S(98, 202), S(350, 215),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(0, -30), S(-1, 5), S(-11, -34), S(-8, -82), S(-32, -153), S(-222, -397),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 199), S(-4, 144), S(-7, 62), S(6, 20), S(22, 17), S(57, 7), S(62, -19),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-147, -11), S(3, -17), S(-10, 77), S(22, 119), S(36, 157), S(45, 166), S(35, 138),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(76, -43), S(118, 177), S(136, 260), S(147, 296), S(159, 330), S(165, 370), S(175, 387), S(184, 409), S(195, 378),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(42, 22), S(103, 234), S(157, 298), S(176, 351), S(192, 382), S(202, 403), S(207, 414), S(207, 428), S(209, 430), S(211, 437), S(223, 422), S(223, 415), S(218, 422), S(171, 387),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(262, 356), S(189, 530), S(210, 558), S(226, 573), S(236, 586), S(239, 593), S(241, 603), S(246, 604), S(249, 612), S(252, 620), S(254, 624), S(249, 632), S(246, 639), S(247, 626), S(258, 593),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(328, 684), S(455, 836), S(482, 940), S(500, 1059), S(518, 1078), S(526, 1112), S(530, 1146), S(532, 1168), S(535, 1189), S(537, 1203), S(540, 1216), S(545, 1220), S(547, 1229), S(551, 1229), S(549, 1239), S(551, 1239), S(546, 1243), S(545, 1239), S(544, 1241), S(550, 1234), S(533, 1234), S(557, 1199), S(518, 1240), S(482, 1233), S(448, 1228), S(417, 1259), S(341, 1331), S(396, 1229),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(102, 270), S(131, 288), S(139, 320), S(145, 331), S(153, 341), S(156, 356), S(158, 370), S(163, 361), S(167, 364), S(172, 358), S(175, 356), S(177, 356), S(176, 351), S(182, 340), S(189, 322), S(190, 311), S(190, 295), S(194, 278), S(201, 262), S(197, 241), S(166, 193),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(214, 322), S(210, 324), S(212, 332), S(210, 363), S(210, 373), S(211, 374), S(209, 383), S(211, 383), S(209, 394), S(207, 399), S(204, 410), S(205, 411), S(206, 414), S(207, 419), S(215, 419), S(222, 411), S(216, 421), S(188, 421),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(244, 424), S(241, 444), S(240, 453), S(241, 465), S(245, 468), S(246, 476), S(246, 484), S(248, 491), S(245, 506), S(248, 511), S(244, 523), S(244, 531), S(239, 546), S(240, 548), S(237, 557), S(230, 569), S(229, 573), S(228, 577), S(221, 583), S(203, 597),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(423, 933), S(412, 995), S(413, 1069), S(420, 1073), S(418, 1105), S(419, 1118), S(421, 1122), S(423, 1139), S(425, 1136), S(429, 1136), S(424, 1154), S(430, 1144), S(434, 1140), S(437, 1137), S(438, 1143), S(443, 1132), S(446, 1119), S(450, 1117), S(458, 1097), S(455, 1107), S(480, 1063), S(485, 1055), S(504, 994),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(2, 5), S(3, 4), S(12, 2), S(0, 16),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 191);
inline const PParam PAWN_THREAT_BISHOP = S(164, 255);
inline const PParam PAWN_THREAT_ROOK   = S(191, 160);
inline const PParam PAWN_THREAT_QUEEN  = S(155, 48);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(14, 56), S(92, 125), S(107, 128), S(184, 103), S(171, 30), }},
  {{ S(11, 58), S(82, 115), S(106, 122), S(214, 637), S(156, -25), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(12, 74), S(43, 140), S(61, 141), S(18, 22), S(163, -61), }},
  {{ S(1, 62), S(57, 110), S(100, 98), S(16, 15), S(197, 1277), }},
}};
inline const PParam KING_THREAT  = S(-24, 149);
inline const PParam REACH_THREAT = S(-12, 11);
inline const PParam REACH_THREAT_LOOSE = S(18, 27);
inline const PParam REACH_PILEUP = S(3, 8);
inline const PParam HANGING_PAWN  = S(36, 99);
inline const PParam HANGING_NON_PAWN  = S(82, 41);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -13), S(12, 28),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(49, 30), S(83, -76),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(39, -5), S(37, -5),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -13), S(-1, -18), S(-6, -25), S(-12, -31), S(-19, -34), S(-21, -43), S(-27, -39), S(-27, -91),
};

inline const PParam ROOK_LINEUP = S(16, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 493),    S(159, 621),    S(149, 587),    S(251, 491),    S(251, 424),    S(223, 462),    S(216, 502),    S(313, 454),    //
    S(126, 313),    S(102, 395),    S(84, 328),     S(104, 245),    S(100, 197),    S(76, 228),     S(75, 292),     S(59, 315),     //
    S(117, 246),    S(80, 271),     S(97, 244),     S(72, 205),     S(60, 183),     S(56, 192),     S(34, 209),     S(40, 254),     //
    S(76, 182),     S(45, 220),     S(78, 203),     S(65, 173),     S(44, 159),     S(42, 167),     S(1, 188),      S(5, 195),      //
    S(60, 142),     S(94, 144),     S(87, 217),     S(75, 192),     S(55, 178),     S(33, 172),     S(-1, 176),     S(-10, 177),    //
    S(85, 160),     S(167, 144),    S(175, 170),    S(130, 219),    S(103, 198),    S(75, 177),     S(32, 197),     S(14, 196),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-204, -401),  S(-195, 175),   S(-237, 245),   S(57, 184),     S(-44, 200),    S(-260, 271),   S(-275, 231),   S(-294, -315),  //
    S(65, 130),     S(53, 173),     S(134, 158),    S(130, 211),    S(141, 191),    S(102, 171),    S(49, 161),     S(10, 162),     //
    S(101, 118),    S(107, 167),    S(112, 176),    S(124, 212),    S(106, 215),    S(78, 181),     S(58, 185),     S(22, 152),     //
    S(148, 179),    S(149, 201),    S(149, 233),    S(148, 301),    S(150, 297),    S(126, 231),    S(108, 186),    S(82, 193),     //
    S(127, 178),    S(145, 169),    S(156, 210),    S(129, 301),    S(128, 294),    S(121, 236),    S(105, 191),    S(74, 170),     //
    S(81, 116),     S(120, 121),    S(129, 158),    S(130, 214),    S(128, 212),    S(111, 153),    S(88, 129),     S(36, 109),     //
    S(106, 126),    S(105, 154),    S(110, 123),    S(118, 163),    S(113, 171),    S(88, 120),     S(35, 169),     S(11, 69),      //
    S(12, 49),      S(74, 110),     S(92, 110),     S(100, 129),    S(86, 138),     S(45, 113),     S(31, 130),     S(-30, 7),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(12, 229),     S(-102, 366),   S(-293, 445),   S(-152, 350),   S(-161, 370),   S(-140, 390),   S(-72, 366),    S(-16, 340),    //
    S(89, 242),     S(45, 366),     S(66, 328),     S(54, 324),     S(55, 333),     S(86, 305),     S(99, 318),     S(66, 284),     //
    S(172, 267),    S(152, 308),    S(151, 328),    S(147, 307),    S(146, 298),    S(139, 316),    S(122, 314),    S(146, 246),    //
    S(139, 241),    S(179, 278),    S(190, 287),    S(212, 309),    S(221, 310),    S(161, 284),    S(161, 267),    S(125, 244),    //
    S(163, 212),    S(162, 268),    S(203, 270),    S(217, 286),    S(204, 294),    S(190, 286),    S(141, 267),    S(129, 220),    //
    S(178, 235),    S(200, 240),    S(217, 267),    S(191, 284),    S(188, 281),    S(185, 276),    S(181, 256),    S(149, 215),    //
    S(153, 183),    S(244, 198),    S(191, 242),    S(178, 260),    S(166, 264),    S(175, 225),    S(177, 212),    S(158, 214),    //
    S(154, 191),    S(142, 227),    S(150, 237),    S(158, 229),    S(142, 241),    S(155, 269),    S(158, 240),    S(152, 195),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(307, 489),    S(337, 495),    S(295, 538),    S(281, 509),    S(329, 472),    S(276, 500),    S(298, 511),    S(288, 504),    //
    S(250, 514),    S(284, 519),    S(335, 479),    S(291, 479),    S(321, 465),    S(288, 486),    S(234, 521),    S(234, 523),    //
    S(219, 499),    S(331, 429),    S(361, 422),    S(320, 405),    S(317, 424),    S(257, 462),    S(239, 494),    S(198, 534),    //
    S(178, 479),    S(238, 478),    S(245, 465),    S(231, 453),    S(251, 433),    S(217, 475),    S(201, 496),    S(160, 519),    //
    S(147, 422),    S(202, 419),    S(187, 451),    S(155, 457),    S(166, 449),    S(156, 473),    S(142, 477),    S(118, 484),    //
    S(149, 347),    S(223, 345),    S(206, 374),    S(183, 391),    S(190, 396),    S(176, 411),    S(167, 398),    S(124, 420),    //
    S(82, 340),     S(204, 281),    S(206, 322),    S(191, 370),    S(199, 363),    S(180, 380),    S(169, 370),    S(138, 372),    //
    S(142, 317),    S(165, 344),    S(227, 329),    S(232, 341),    S(234, 352),    S(207, 380),    S(203, 369),    S(183, 373),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(428, 683),    S(493, 674),    S(385, 851),    S(330, 944),    S(351, 917),    S(406, 807),    S(408, 708),    S(359, 728),    //
    S(399, 732),    S(399, 787),    S(356, 889),    S(247, 1003),   S(291, 963),    S(359, 807),    S(391, 717),    S(381, 672),    //
    S(360, 763),    S(397, 807),    S(349, 901),    S(312, 939),    S(331, 919),    S(375, 808),    S(419, 677),    S(399, 653),    //
    S(352, 715),    S(350, 792),    S(303, 873),    S(301, 920),    S(327, 893),    S(335, 785),    S(381, 695),    S(369, 654),    //
    S(335, 691),    S(334, 705),    S(322, 758),    S(298, 828),    S(306, 839),    S(335, 759),    S(344, 693),    S(359, 613),    //
    S(333, 577),    S(365, 565),    S(351, 667),    S(322, 700),    S(342, 700),    S(344, 723),    S(365, 643),    S(348, 622),    //
    S(309, 416),    S(350, 385),    S(346, 476),    S(368, 542),    S(367, 582),    S(371, 559),    S(350, 588),    S(361, 550),    //
    S(273, 456),    S(321, 260),    S(343, 275),    S(347, 404),    S(362, 471),    S(358, 467),    S(355, 484),    S(325, 530),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(356, -688),   S(583, 8),      S(461, 158),    S(71, 237),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(420, -273),   S(382, 149),    S(240, 227),    S(10, 223),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(243, -33),    S(252, 151),    S(87, 263),     S(-108, 285),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(64, -41),     S(136, 103),    S(-45, 256),    S(-172, 311),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-83, -46),    S(6, 76),       S(-77, 217),    S(-201, 293),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -82),    S(31, 28),      S(-64, 177),    S(-139, 246),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -153),    S(40, -23),     S(-30, 93),     S(-113, 184),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -289),   S(7, -140),     S(-77, -13),    S(-82, 1),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
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
  {{ S(17, -12), S(-7, 6), S(-2, -7), S(9, -11), S(17, -25), S(9, -34), S(4, -40), }},
  {{ S(6, 6), S(-17, 2), S(-11, 6), S(-2, 7), S(2, 2), S(-5, -4), S(-11, -20), }},
  {{ S(3, 9), S(-6, 3), S(-5, 23), S(1, 20), S(3, 12), S(-2, 2), S(-14, -20), }},
  {{ S(7, 17), S(-7, 16), S(-1, 27), S(5, 27), S(5, 23), S(6, 22), S(14, -3), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 23), S(-15, -0), S(-16, 4), S(-16, 20), S(-5, 23),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 5), S(-50, -75), S(-12, -46), S(-4, -10), S(-10, -3), S(-13, 3), S(-13, 2), }},
  {{ S(0, -6), S(-32, -77), S(-5, -56), S(-7, -16), S(-8, -12), S(-16, -6), S(-6, -6), }},
  {{ S(-8, 2), S(-7, -65), S(8, -37), S(-5, -3), S(-11, 2), S(-17, 7), S(-14, 8), }},
  {{ S(-7, -9), S(5, -73), S(9, -46), S(-7, 6), S(-13, 0), S(-18, -4), S(-15, 1), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1435, 1214, -26, -11
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(111);
inline VParam WINNABLE_ASYM = V(97);
inline VParam WINNABLE_PAWN_ENDGAME = V(79);
inline VParam WINNABLE_BIAS = V(-449);

// clang-format on
}  // namespace Clockwork
