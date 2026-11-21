#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(113, 288);
inline const PParam KNIGHT_MAT = S(573, 1086);
inline const PParam BISHOP_MAT = S(524, 1023);
inline const PParam ROOK_MAT   = S(401, 1103);
inline const PParam QUEEN_MAT  = S(875, 1876);

inline const PParam TEMPO_VAL  = S(72, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(63, 248);
inline const PParam ROOK_OPEN_VAL     = S(114, -10);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 8);
inline const PParam MINOR_BEHIND_PAWN = S(17, 46);
inline const PParam RESTRICTED_SQUARES = S(20, 5);
inline const PParam SPACE_VAL = S(96, -107);

inline const PParam DOUBLED_PAWN_VAL = S(-17, -90);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -42);

inline const PParam POTENTIAL_CHECKER_VAL = S(-44, -50);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 30);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 31);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 56);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 65);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -55);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -13), S(40, 25), S(51, 80), S(115, 225), S(389, 469), S(796, 1036),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 24), S(42, 23), S(41, 73), S(87, 186), S(381, 143),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -185), S(-72, -143), S(-39, -18), S(9, 99), S(93, 328), S(235, 547),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-55, 52), S(-66, 30), S(-36, 89), S(-72, 209), S(-27, 289), S(84, 182),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(7, 57), S(-1, 47), S(-52, 101), S(-5, 106), S(108, 97), S(32, 179),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -34), S(18, 4), S(12, 38), S(24, 94), S(89, 226), S(398, 144),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(5, -25), S(-3, 15), S(-9, -24), S(-8, -68), S(-22, -161), S(-188, -447),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(16, 184), S(-1, 137), S(-7, 61), S(3, 22), S(18, 21), S(55, 11), S(61, -15),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-130, -36), S(-4, -13), S(-11, 77), S(23, 114), S(36, 150), S(44, 162), S(31, 136),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(54, -31), S(131, 241), S(162, 365), S(182, 419), S(204, 457), S(219, 497), S(238, 503), S(258, 508), S(277, 461),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(92, 23), S(154, 258), S(208, 348), S(226, 423), S(242, 475), S(253, 515), S(258, 543), S(259, 568), S(263, 580), S(268, 591), S(283, 580), S(285, 575), S(285, 588), S(247, 546),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(327, 404), S(239, 615), S(262, 648), S(277, 670), S(288, 690), S(291, 705), S(295, 723), S(299, 733), S(303, 746), S(308, 758), S(310, 768), S(309, 779), S(311, 787), S(317, 774), S(333, 741),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(437, 503), S(561, 753), S(586, 908), S(605, 1060), S(625, 1101), S(633, 1153), S(637, 1203), S(639, 1232), S(641, 1261), S(644, 1280), S(647, 1294), S(653, 1300), S(656, 1309), S(661, 1309), S(662, 1314), S(665, 1313), S(660, 1318), S(662, 1306), S(661, 1306), S(670, 1293), S(654, 1292), S(675, 1253), S(635, 1292), S(590, 1289), S(553, 1284), S(515, 1310), S(442, 1372), S(485, 1281),
};

inline const PParam PAWN_THREAT_KNIGHT = S(206, 177);
inline const PParam PAWN_THREAT_BISHOP = S(169, 257);
inline const PParam PAWN_THREAT_ROOK   = S(199, 154);
inline const PParam PAWN_THREAT_QUEEN  = S(162, 34);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(9, 58), S(99, 111), S(104, 139), S(184, 104), S(172, 32), }},
  {{ S(6, 60), S(90, 101), S(104, 132), S(210, 644), S(164, -60), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 70), S(50, 130), S(70, 123), S(20, 14), S(167, -73), }},
  {{ S(0, 59), S(68, 95), S(109, 80), S(18, 9), S(207, 1234), }},
}};
inline const PParam KING_THREAT  = S(26, 134);
inline const PParam HANGING_PAWN  = S(33, 92);
inline const PParam LOOSE_PIECES = S(-10, -22);
inline const PParam HANGING_NON_PAWN  = S(68, 14);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(19, -6), S(39, -12),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(50, 35), S(112, -113),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(42, 5), S(51, -10),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(6, -18), S(6, -16), S(1, -21), S(-5, -28), S(-12, -36), S(-17, -40), S(-19, -50), S(-25, -47), S(-25, -94),
};

inline const PParam ROOK_LINEUP = S(19, 68);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(298, 464),    S(175, 578),    S(174, 443),    S(251, 505),    S(253, 435),    S(221, 473),    S(226, 481),    S(319, 419),    //
    S(129, 294),    S(128, 343),    S(103, 312),    S(108, 248),    S(100, 209),    S(78, 237),     S(85, 277),     S(64, 296),     //
    S(119, 244),    S(85, 274),     S(96, 265),     S(78, 196),     S(64, 181),     S(55, 205),     S(35, 212),     S(40, 248),     //
    S(75, 178),     S(42, 220),     S(66, 209),     S(59, 152),     S(38, 142),     S(33, 179),     S(-7, 191),     S(-2, 194),     //
    S(60, 141),     S(91, 144),     S(72, 223),     S(67, 180),     S(46, 172),     S(21, 184),     S(-10, 181),    S(-16, 179),    //
    S(85, 163),     S(161, 138),    S(158, 162),    S(120, 197),    S(93, 176),     S(64, 179),     S(23, 191),     S(9, 193),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-157, -317),  S(-161, 281),   S(-180, 339),   S(125, 279),    S(29, 281),     S(-200, 348),   S(-237, 321),   S(-249, -230),  //
    S(104, 224),    S(91, 254),     S(187, 240),    S(182, 318),    S(202, 285),    S(157, 252),    S(92, 240),     S(49, 248),     //
    S(134, 202),    S(135, 268),    S(139, 300),    S(166, 324),    S(151, 322),    S(111, 294),    S(94, 271),     S(55, 234),     //
    S(184, 262),    S(181, 294),    S(185, 320),    S(193, 361),    S(197, 346),    S(164, 305),    S(146, 255),    S(121, 263),    //
    S(172, 242),    S(192, 229),    S(196, 274),    S(183, 320),    S(179, 305),    S(160, 288),    S(152, 236),    S(119, 229),    //
    S(114, 157),    S(137, 173),    S(142, 228),    S(152, 274),    S(149, 269),    S(123, 223),    S(106, 187),    S(69, 157),     //
    S(132, 170),    S(123, 202),    S(119, 171),    S(131, 213),    S(127, 214),    S(98, 167),     S(56, 217),     S(41, 120),     //
    S(43, 101),     S(108, 157),    S(118, 154),    S(134, 176),    S(121, 182),    S(82, 154),     S(69, 181),     S(6, 65),       //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(80, 334),     S(-39, 478),    S(-220, 553),   S(-93, 475),    S(-107, 503),   S(-80, 504),    S(-13, 469),    S(44, 445),     //
    S(148, 339),    S(106, 452),    S(124, 430),    S(119, 433),    S(122, 438),    S(146, 398),    S(162, 393),    S(128, 372),    //
    S(222, 376),    S(194, 407),    S(206, 420),    S(202, 413),    S(201, 401),    S(197, 403),    S(174, 404),    S(203, 340),    //
    S(187, 355),    S(224, 386),    S(241, 387),    S(258, 419),    S(270, 413),    S(218, 379),    S(215, 361),    S(177, 348),    //
    S(212, 326),    S(213, 359),    S(250, 365),    S(265, 385),    S(253, 385),    S(241, 376),    S(193, 361),    S(183, 323),    //
    S(233, 331),    S(254, 321),    S(267, 343),    S(239, 380),    S(234, 364),    S(230, 362),    S(235, 342),    S(201, 324),    //
    S(202, 278),    S(292, 261),    S(234, 317),    S(222, 336),    S(208, 335),    S(220, 304),    S(227, 282),    S(210, 317),    //
    S(208, 284),    S(198, 319),    S(202, 334),    S(211, 321),    S(198, 322),    S(214, 363),    S(217, 333),    S(208, 293),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(359, 622),    S(381, 647),    S(340, 686),    S(320, 654),    S(375, 622),    S(331, 641),    S(359, 646),    S(350, 634),    //
    S(294, 644),    S(332, 658),    S(382, 621),    S(336, 612),    S(378, 604),    S(342, 624),    S(292, 656),    S(288, 652),    //
    S(271, 621),    S(377, 571),    S(414, 559),    S(371, 549),    S(376, 570),    S(317, 604),    S(300, 627),    S(260, 661),    //
    S(235, 594),    S(292, 604),    S(299, 600),    S(282, 593),    S(313, 567),    S(283, 600),    S(268, 617),    S(225, 637),    //
    S(208, 525),    S(259, 544),    S(244, 579),    S(209, 588),    S(227, 579),    S(219, 601),    S(206, 599),    S(183, 601),    //
    S(216, 429),    S(287, 454),    S(267, 489),    S(240, 510),    S(251, 518),    S(235, 536),    S(236, 506),    S(191, 527),    //
    S(145, 423),    S(265, 377),    S(262, 426),    S(246, 479),    S(255, 476),    S(239, 493),    S(234, 473),    S(206, 467),    //
    S(209, 381),    S(225, 415),    S(283, 410),    S(291, 414),    S(297, 423),    S(273, 450),    S(270, 438),    S(253, 438),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(514, 821),    S(589, 793),    S(465, 969),    S(419, 1032),   S(445, 1019),   S(495, 920),    S(491, 842),    S(442, 869),    //
    S(476, 840),    S(484, 891),    S(439, 982),    S(331, 1079),   S(380, 1053),   S(444, 909),    S(481, 817),    S(465, 782),    //
    S(440, 862),    S(476, 892),    S(438, 969),    S(411, 991),    S(429, 996),    S(472, 889),    S(506, 782),    S(490, 753),    //
    S(435, 805),    S(439, 863),    S(400, 929),    S(403, 974),    S(431, 959),    S(434, 866),    S(480, 774),    S(464, 743),    //
    S(421, 780),    S(423, 775),    S(417, 822),    S(395, 889),    S(403, 916),    S(432, 851),    S(437, 793),    S(455, 718),    //
    S(418, 669),    S(452, 642),    S(442, 732),    S(417, 763),    S(433, 771),    S(431, 815),    S(457, 744),    S(440, 731),    //
    S(388, 488),    S(426, 453),    S(426, 546),    S(451, 615),    S(450, 656),    S(457, 636),    S(433, 670),    S(444, 658),    //
    S(361, 505),    S(404, 308),    S(424, 344),    S(433, 463),    S(451, 528),    S(447, 532),    S(443, 552),    S(414, 613),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(336, -630),   S(559, 49),     S(420, 279),    S(14, 424),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(416, -265),   S(363, 154),    S(203, 313),    S(-42, 374),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(216, -28),    S(225, 127),    S(52, 303),     S(-175, 414),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(44, -51),     S(116, 60),     S(-89, 286),    S(-245, 428),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-88, -82),    S(-21, 18),     S(-99, 208),    S(-253, 357),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-40, -112),   S(17, -36),     S(-76, 161),    S(-161, 285),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(43, -183),    S(41, -100),    S(-31, 54),     S(-122, 183),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-7, -282),    S(18, -168),    S(-69, -21),    S(-77, 29),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-72, -73);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -1), S(11, 1), S(10, 1), S(5, -1), S(3, -5),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -1), S(6, -1), S(3, -1), S(3, -0), S(3, 0),
};

inline const PParam KS_FLANK_ATTACK = S(4, -3);
inline const PParam KS_FLANK_DEFENSE = S(-2, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(13, -2), S(-7, 10), S(-3, -1), S(7, -4), S(13, -11), S(3, -16), S(4, -35), }},
  {{ S(2, 12), S(-18, 6), S(-13, 9), S(-4, 10), S(-1, 8), S(-7, -0), S(-10, -16), }},
  {{ S(-2, 21), S(-10, 11), S(-7, 23), S(-1, 21), S(-1, 20), S(-6, 15), S(3, -365), }},
  {{ S(1, 26), S(-8, 16), S(-1, 20), S(4, 19), S(4, 16), S(4, 21), S(5, 16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-6, 23), S(-19, 6), S(-20, 11), S(-17, 16), S(-3, 15),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-6, 10), S(-47, -310), S(-13, -49), S(-7, -4), S(-13, 2), S(-16, 7), S(-15, 6), }},
  {{ S(-3, 2), S(-28, -279), S(-7, -54), S(-8, -11), S(-11, -4), S(-19, 4), S(-10, 3), }},
  {{ S(-10, 6), S(-2, -245), S(5, -30), S(-5, -7), S(-12, 2), S(-18, 7), S(-14, 8), }},
  {{ S(-9, 1), S(5, -67), S(5, -23), S(-6, 3), S(-16, 6), S(-21, 3), S(-17, 4), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1522, 1488, -19, -8
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(107);
inline VParam WINNABLE_ASYM = V(94);
inline VParam WINNABLE_PAWN_ENDGAME = V(73);
inline VParam WINNABLE_BIAS = V(-415);

// clang-format on
}  // namespace Clockwork
