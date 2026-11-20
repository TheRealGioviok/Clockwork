#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(110, 295);
inline const PParam KNIGHT_MAT = S(472, 909);
inline const PParam BISHOP_MAT = S(414, 811);
inline const PParam ROOK_MAT   = S(320, 934);
inline const PParam QUEEN_MAT  = S(635, 2148);

inline const PParam TEMPO_VAL  = S(71, 62);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 3);
inline const PParam BISHOP_PAIR_VAL   = S(56, 249);
inline const PParam ROOK_OPEN_VAL     = S(114, -6);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 22);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(20, 8);
inline const PParam SPACE_VAL = S(94, -102);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -97);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -44);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -36);
inline const PParam OUTPOST_KNIGHT_VAL    = S(48, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(37, 27);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 65);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 9);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -9), S(35, 27), S(52, 79), S(113, 238), S(335, 631), S(843, 966),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 29), S(41, 26), S(42, 75), S(86, 200), S(329, 293),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-65, -195), S(-66, -150), S(-36, -20), S(13, 98), S(85, 352), S(217, 589),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-73, 53), S(-71, 30), S(-39, 95), S(-71, 222), S(5, 253), S(122, 113),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-14, 59), S(-14, 50), S(-55, 103), S(-6, 117), S(129, 65), S(51, 141),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(19, -34), S(16, 3), S(6, 42), S(13, 110), S(99, 203), S(352, 213),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(0, -31), S(-0, 5), S(-10, -33), S(-7, -81), S(-32, -153), S(-221, -397),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 198), S(-4, 144), S(-7, 62), S(5, 20), S(21, 17), S(56, 7), S(61, -20),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-147, -11), S(3, -17), S(-10, 77), S(21, 119), S(35, 157), S(45, 165), S(34, 138),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(74, -48), S(117, 173), S(135, 258), S(147, 295), S(159, 329), S(165, 371), S(175, 388), S(184, 411), S(195, 381),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(41, 20), S(103, 232), S(157, 297), S(175, 350), S(192, 382), S(202, 403), S(207, 414), S(207, 428), S(209, 431), S(212, 438), S(225, 423), S(224, 416), S(219, 422), S(172, 387),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(261, 354), S(189, 530), S(210, 557), S(226, 573), S(236, 586), S(239, 593), S(242, 603), S(246, 604), S(249, 613), S(253, 620), S(255, 624), S(250, 632), S(247, 638), S(248, 626), S(259, 593),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(327, 683), S(455, 831), S(482, 934), S(500, 1056), S(518, 1075), S(526, 1111), S(531, 1145), S(532, 1166), S(535, 1188), S(537, 1203), S(540, 1216), S(545, 1220), S(547, 1228), S(551, 1229), S(550, 1238), S(551, 1239), S(547, 1243), S(545, 1239), S(544, 1240), S(550, 1235), S(534, 1234), S(557, 1200), S(517, 1241), S(482, 1234), S(447, 1230), S(417, 1260), S(341, 1331), S(396, 1230),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(104, 272), S(133, 290), S(141, 321), S(147, 333), S(154, 343), S(157, 357), S(158, 371), S(163, 362), S(167, 364), S(171, 358), S(175, 356), S(176, 356), S(175, 350), S(180, 339), S(187, 321), S(188, 310), S(189, 293), S(193, 277), S(199, 260), S(195, 240), S(166, 189),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(215, 323), S(211, 325), S(212, 334), S(211, 365), S(210, 375), S(211, 376), S(209, 384), S(211, 385), S(209, 395), S(206, 399), S(204, 409), S(204, 410), S(206, 414), S(207, 417), S(215, 417), S(222, 408), S(217, 417), S(189, 417),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(244, 424), S(240, 445), S(239, 454), S(241, 466), S(244, 468), S(246, 477), S(246, 485), S(248, 492), S(246, 507), S(249, 511), S(245, 523), S(244, 531), S(240, 544), S(241, 548), S(238, 557), S(231, 568), S(231, 570), S(229, 576), S(222, 582), S(205, 594),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(423, 929), S(413, 990), S(414, 1067), S(421, 1071), S(419, 1103), S(420, 1118), S(421, 1122), S(423, 1138), S(424, 1136), S(429, 1135), S(424, 1154), S(429, 1144), S(434, 1139), S(437, 1135), S(437, 1143), S(442, 1132), S(445, 1121), S(450, 1115), S(458, 1097), S(454, 1108), S(480, 1064), S(486, 1054), S(505, 992),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(3, 6), S(5, 5), S(14, 2), S(2, 17),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 189);
inline const PParam PAWN_THREAT_BISHOP = S(163, 253);
inline const PParam PAWN_THREAT_ROOK   = S(191, 160);
inline const PParam PAWN_THREAT_QUEEN  = S(156, 44);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 56), S(92, 125), S(107, 128), S(184, 103), S(171, 29), }},
  {{ S(10, 57), S(83, 115), S(106, 122), S(214, 636), S(153, -18), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(11, 74), S(43, 138), S(61, 139), S(17, 22), S(163, -59), }},
  {{ S(1, 61), S(57, 109), S(99, 98), S(14, 16), S(198, 1269), }},
}};
inline const PParam KING_THREAT  = S(-24, 149);
inline const PParam REACH_THREAT = S(-13, 11);
inline const PParam REACH_THREAT_LOOSE = S(18, 27);
inline const PParam REACH_PAWN_SUPPORT = S(8, 6);
inline const PParam HANGING_PAWN  = S(37, 99);
inline const PParam HANGING_NON_PAWN  = S(82, 42);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -13), S(11, 30),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(49, 32), S(80, -70),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(40, -5), S(38, -5),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -16), S(4, -14), S(-0, -19), S(-6, -26), S(-13, -31), S(-19, -34), S(-21, -43), S(-26, -38), S(-26, -90),
};

inline const PParam ROOK_LINEUP = S(16, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(298, 495),    S(160, 617),    S(148, 586),    S(251, 487),    S(250, 422),    S(222, 460),    S(216, 500),    S(313, 456),    //
    S(127, 312),    S(101, 393),    S(82, 325),     S(102, 240),    S(97, 194),     S(74, 225),     S(73, 289),     S(60, 315),     //
    S(118, 246),    S(80, 268),     S(97, 242),     S(71, 203),     S(58, 181),     S(55, 190),     S(33, 206),     S(41, 254),     //
    S(76, 183),     S(43, 217),     S(74, 201),     S(60, 172),     S(39, 158),     S(38, 165),     S(-3, 185),     S(5, 195),      //
    S(62, 144),     S(95, 144),     S(86, 218),     S(75, 193),     S(54, 179),     S(33, 173),     S(0, 177),      S(-7, 178),     //
    S(88, 162),     S(169, 146),    S(177, 172),    S(131, 221),    S(104, 199),    S(77, 178),     S(34, 198),     S(18, 198),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-204, -402),  S(-194, 175),   S(-237, 244),   S(58, 184),     S(-44, 200),    S(-258, 270),   S(-275, 231),   S(-294, -316),  //
    S(65, 131),     S(54, 174),     S(136, 157),    S(131, 213),    S(143, 191),    S(104, 169),    S(51, 160),     S(10, 163),     //
    S(101, 119),    S(106, 169),    S(110, 176),    S(125, 210),    S(106, 213),    S(77, 179),     S(58, 184),     S(22, 152),     //
    S(148, 181),    S(150, 202),    S(149, 232),    S(149, 301),    S(150, 296),    S(127, 229),    S(109, 187),    S(83, 193),     //
    S(128, 180),    S(145, 171),    S(156, 210),    S(129, 301),    S(127, 293),    S(121, 235),    S(106, 190),    S(75, 171),     //
    S(82, 117),     S(120, 121),    S(128, 157),    S(129, 213),    S(127, 211),    S(110, 153),    S(89, 129),     S(36, 110),     //
    S(106, 127),    S(104, 155),    S(108, 122),    S(116, 162),    S(111, 170),    S(86, 119),     S(35, 170),     S(11, 70),      //
    S(12, 50),      S(74, 110),     S(93, 111),     S(100, 130),    S(86, 139),     S(45, 114),     S(31, 131),     S(-30, 10),     //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(13, 229),     S(-101, 368),   S(-291, 443),   S(-150, 349),   S(-162, 372),   S(-140, 391),   S(-71, 367),    S(-16, 341),    //
    S(90, 241),     S(46, 365),     S(67, 328),     S(56, 321),     S(56, 333),     S(88, 303),     S(100, 317),    S(68, 282),     //
    S(172, 267),    S(152, 309),    S(152, 328),    S(148, 306),    S(147, 296),    S(140, 315),    S(123, 315),    S(146, 247),    //
    S(139, 242),    S(179, 279),    S(191, 286),    S(212, 307),    S(220, 310),    S(162, 283),    S(161, 268),    S(125, 245),    //
    S(163, 212),    S(161, 268),    S(203, 270),    S(217, 286),    S(204, 294),    S(191, 287),    S(141, 265),    S(129, 221),    //
    S(178, 236),    S(199, 240),    S(216, 268),    S(191, 284),    S(187, 282),    S(184, 276),    S(181, 255),    S(150, 215),    //
    S(153, 183),    S(244, 197),    S(190, 242),    S(177, 261),    S(164, 264),    S(175, 224),    S(177, 211),    S(158, 215),    //
    S(154, 192),    S(143, 227),    S(150, 238),    S(159, 229),    S(143, 241),    S(155, 270),    S(159, 242),    S(153, 196),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(305, 491),    S(337, 495),    S(296, 537),    S(284, 507),    S(330, 472),    S(279, 498),    S(300, 509),    S(287, 503),    //
    S(248, 514),    S(283, 520),    S(335, 478),    S(293, 476),    S(324, 462),    S(288, 485),    S(234, 521),    S(233, 522),    //
    S(218, 500),    S(331, 430),    S(361, 424),    S(322, 406),    S(319, 425),    S(258, 463),    S(240, 495),    S(199, 533),    //
    S(177, 481),    S(237, 482),    S(247, 466),    S(233, 455),    S(254, 434),    S(218, 477),    S(202, 498),    S(161, 519),    //
    S(147, 421),    S(201, 419),    S(186, 450),    S(154, 457),    S(166, 448),    S(155, 473),    S(141, 477),    S(119, 483),    //
    S(149, 347),    S(223, 344),    S(204, 375),    S(181, 392),    S(190, 394),    S(175, 411),    S(167, 398),    S(124, 420),    //
    S(82, 340),     S(204, 281),    S(206, 322),    S(191, 370),    S(199, 362),    S(180, 380),    S(169, 371),    S(139, 372),    //
    S(142, 317),    S(165, 344),    S(226, 329),    S(232, 341),    S(234, 352),    S(207, 379),    S(204, 368),    S(184, 373),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(428, 682),    S(494, 672),    S(384, 852),    S(330, 944),    S(352, 916),    S(406, 806),    S(406, 710),    S(360, 726),    //
    S(399, 732),    S(398, 789),    S(355, 890),    S(245, 1006),   S(290, 963),    S(358, 808),    S(391, 715),    S(381, 669),    //
    S(361, 762),    S(397, 809),    S(350, 902),    S(313, 938),    S(333, 917),    S(377, 806),    S(420, 677),    S(400, 651),    //
    S(352, 718),    S(351, 794),    S(305, 873),    S(303, 921),    S(329, 893),    S(337, 786),    S(383, 696),    S(370, 654),    //
    S(334, 692),    S(333, 706),    S(322, 755),    S(298, 826),    S(306, 835),    S(336, 756),    S(344, 692),    S(360, 611),    //
    S(332, 578),    S(364, 565),    S(351, 665),    S(322, 698),    S(342, 698),    S(344, 723),    S(365, 644),    S(349, 620),    //
    S(307, 419),    S(350, 384),    S(344, 478),    S(367, 543),    S(367, 583),    S(371, 559),    S(349, 591),    S(361, 551),    //
    S(273, 455),    S(321, 260),    S(343, 276),    S(347, 404),    S(362, 470),    S(358, 467),    S(355, 484),    S(326, 530),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(355, -689),   S(584, 7),      S(462, 158),    S(72, 239),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(419, -274),   S(383, 148),    S(240, 229),    S(12, 222),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(242, -35),    S(251, 149),    S(86, 263),     S(-109, 286),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(64, -44),     S(135, 102),    S(-47, 257),    S(-172, 312),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-84, -47),    S(5, 75),       S(-80, 217),    S(-203, 293),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -85),    S(30, 27),      S(-66, 177),    S(-141, 246),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(40, -153),    S(40, -22),     S(-30, 93),     S(-114, 184),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -289),   S(8, -140),     S(-76, -12),    S(-81, 2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-71, 66);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -2), S(9, 13), S(9, 6), S(3, -1), S(2, -5),
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
  {{ S(17, -13), S(-6, 6), S(-2, -7), S(9, -12), S(17, -26), S(10, -35), S(4, -41), }},
  {{ S(6, 6), S(-17, 2), S(-11, 6), S(-2, 8), S(2, 2), S(-5, -4), S(-10, -21), }},
  {{ S(3, 9), S(-6, 3), S(-5, 23), S(1, 20), S(3, 12), S(-2, 1), S(-14, -21), }},
  {{ S(8, 18), S(-7, 17), S(-1, 28), S(5, 28), S(5, 25), S(6, 22), S(14, -3), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 23), S(-15, -1), S(-16, 4), S(-16, 21), S(-5, 24),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 6), S(-50, -75), S(-12, -46), S(-4, -10), S(-10, -3), S(-13, 3), S(-13, 2), }},
  {{ S(0, -6), S(-32, -78), S(-5, -57), S(-6, -16), S(-8, -12), S(-16, -6), S(-6, -6), }},
  {{ S(-8, 2), S(-7, -65), S(8, -37), S(-5, -3), S(-11, 2), S(-17, 7), S(-13, 9), }},
  {{ S(-7, -10), S(6, -74), S(9, -46), S(-7, 6), S(-13, -0), S(-18, -4), S(-15, 1), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1435, 1202, -26, -11
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(110);
inline VParam WINNABLE_ASYM = V(97);
inline VParam WINNABLE_PAWN_ENDGAME = V(81);
inline VParam WINNABLE_BIAS = V(-449);

// clang-format on
}  // namespace Clockwork
