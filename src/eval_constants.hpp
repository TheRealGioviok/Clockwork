#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(110, 291);
inline const PParam KNIGHT_MAT = S(472, 905);
inline const PParam BISHOP_MAT = S(413, 808);
inline const PParam ROOK_MAT   = S(320, 938);
inline const PParam QUEEN_MAT  = S(638, 2158);

inline const PParam TEMPO_VAL  = S(71, 62);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 1);
inline const PParam BISHOP_PAIR_VAL   = S(56, 249);
inline const PParam ROOK_OPEN_VAL     = S(114, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(49, 22);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(21, 10);
inline const PParam SPACE_VAL = S(94, -103);

inline const PParam DOUBLED_PAWN_VAL = S(-17, -93);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -44);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -37);
inline const PParam OUTPOST_KNIGHT_VAL    = S(48, 36);
inline const PParam OUTPOST_BISHOP_VAL    = S(38, 31);
inline const PParam MINOR_PUSH_COVER      = S(3, 26);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 65);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 8);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -7), S(37, 30), S(51, 82), S(113, 241), S(335, 637), S(842, 968),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 29), S(40, 26), S(39, 74), S(82, 199), S(320, 294),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -194), S(-66, -149), S(-36, -19), S(14, 99), S(87, 353), S(220, 590),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-77, 56), S(-73, 32), S(-39, 98), S(-69, 224), S(9, 250), S(127, 113),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-17, 60), S(-17, 53), S(-54, 102), S(-7, 116), S(128, 65), S(51, 142),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(19, -39), S(16, -3), S(6, 37), S(13, 104), S(99, 193), S(342, 204),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(1, -31), S(-0, 5), S(-10, -32), S(-8, -79), S(-33, -154), S(-223, -396),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 199), S(-4, 145), S(-7, 63), S(6, 21), S(22, 16), S(56, 8), S(61, -18),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-147, -10), S(4, -18), S(-11, 77), S(21, 120), S(36, 158), S(45, 167), S(35, 140),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(79, -37), S(120, 184), S(137, 264), S(148, 298), S(159, 329), S(164, 368), S(173, 383), S(182, 404), S(191, 371),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(42, 26), S(103, 236), S(157, 300), S(176, 352), S(192, 383), S(202, 403), S(207, 412), S(206, 426), S(209, 428), S(211, 435), S(223, 420), S(223, 412), S(216, 421), S(172, 383),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(260, 356), S(188, 525), S(210, 557), S(226, 573), S(236, 586), S(239, 593), S(242, 603), S(246, 605), S(249, 613), S(253, 621), S(255, 625), S(250, 633), S(247, 640), S(249, 627), S(260, 594),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(328, 683), S(454, 834), S(482, 939), S(499, 1058), S(518, 1077), S(526, 1112), S(531, 1145), S(532, 1167), S(535, 1188), S(538, 1203), S(540, 1217), S(546, 1220), S(547, 1229), S(552, 1230), S(550, 1239), S(551, 1240), S(547, 1244), S(546, 1239), S(544, 1242), S(550, 1236), S(534, 1236), S(557, 1201), S(517, 1243), S(482, 1234), S(448, 1231), S(417, 1261), S(340, 1334), S(397, 1231),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(101, 265), S(129, 282), S(138, 314), S(144, 326), S(152, 338), S(155, 352), S(157, 367), S(162, 359), S(167, 362), S(172, 357), S(176, 355), S(177, 356), S(177, 351), S(182, 341), S(190, 322), S(190, 312), S(191, 297), S(195, 281), S(201, 266), S(196, 247), S(168, 198),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(214, 320), S(209, 323), S(211, 332), S(210, 363), S(209, 373), S(211, 374), S(209, 383), S(211, 383), S(209, 395), S(207, 399), S(205, 409), S(205, 411), S(206, 415), S(208, 418), S(216, 419), S(223, 411), S(217, 421), S(190, 421),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(243, 424), S(240, 444), S(239, 455), S(240, 467), S(244, 470), S(245, 478), S(246, 486), S(248, 493), S(245, 507), S(248, 512), S(245, 524), S(244, 531), S(240, 545), S(241, 548), S(239, 556), S(233, 567), S(232, 570), S(230, 576), S(223, 581), S(207, 593),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(423, 926), S(412, 992), S(413, 1067), S(420, 1073), S(418, 1103), S(419, 1119), S(421, 1123), S(423, 1139), S(424, 1136), S(429, 1137), S(423, 1156), S(429, 1146), S(434, 1141), S(438, 1135), S(438, 1144), S(444, 1132), S(446, 1120), S(451, 1118), S(458, 1100), S(454, 1112), S(481, 1065), S(490, 1050), S(507, 992),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(3, 8), S(5, 4), S(14, 2), S(1, 16),
};

inline const PParam PAWN_THREAT_KNIGHT = S(199, 188);
inline const PParam PAWN_THREAT_BISHOP = S(164, 254);
inline const PParam PAWN_THREAT_ROOK   = S(189, 160);
inline const PParam PAWN_THREAT_QUEEN  = S(155, 47);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 52), S(91, 120), S(106, 127), S(183, 104), S(172, 27), }},
  {{ S(10, 54), S(82, 110), S(106, 120), S(214, 639), S(151, -11), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(12, 73), S(43, 139), S(61, 140), S(17, 19), S(163, -63), }},
  {{ S(2, 60), S(58, 109), S(99, 97), S(13, 16), S(198, 1270), }},
}};
inline const PParam KING_THREAT  = S(-24, 148);
inline const PParam REACH_THREAT = S(-13, 10);
inline const PParam REACH_THREAT_LOOSE = S(18, 27);
inline const PParam HANGING_PAWN  = S(37, 99);
inline const PParam HANGING_NON_PAWN  = S(82, 42);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -13), S(11, 33),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(49, 31), S(81, -71),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(40, -7), S(40, -8),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -22), S(3, -16), S(-0, -20), S(-6, -24), S(-12, -29), S(-18, -30), S(-21, -38), S(-26, -32), S(-26, -84),
};

inline const PParam ROOK_LINEUP = S(16, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(298, 492),    S(160, 618),    S(149, 586),    S(251, 491),    S(250, 426),    S(223, 463),    S(217, 500),    S(314, 452),    //
    S(128, 313),    S(104, 395),    S(85, 328),     S(106, 244),    S(102, 197),    S(77, 228),     S(76, 293),     S(61, 316),     //
    S(117, 247),    S(81, 271),     S(98, 243),     S(73, 204),     S(60, 181),     S(57, 190),     S(35, 208),     S(41, 255),     //
    S(77, 183),     S(45, 219),     S(77, 202),     S(64, 172),     S(43, 158),     S(42, 165),     S(1, 187),      S(7, 195),      //
    S(60, 143),     S(94, 144),     S(84, 216),     S(73, 190),     S(53, 176),     S(32, 169),     S(-0, 175),     S(-8, 177),     //
    S(86, 162),     S(167, 145),    S(173, 169),    S(128, 218),    S(101, 196),    S(74, 176),     S(32, 197),     S(16, 197),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-203, -394),  S(-195, 179),   S(-236, 252),   S(63, 183),     S(-42, 204),    S(-254, 271),   S(-274, 235),   S(-294, -305),  //
    S(66, 135),     S(52, 177),     S(138, 161),    S(133, 214),    S(144, 194),    S(105, 175),    S(51, 162),     S(11, 167),     //
    S(104, 117),    S(106, 172),    S(112, 177),    S(127, 213),    S(108, 217),    S(80, 183),     S(60, 187),     S(23, 155),     //
    S(147, 176),    S(147, 196),    S(147, 229),    S(147, 294),    S(150, 292),    S(127, 226),    S(106, 184),    S(82, 192),     //
    S(127, 176),    S(144, 173),    S(154, 206),    S(127, 294),    S(126, 285),    S(120, 230),    S(105, 193),    S(74, 171),     //
    S(82, 120),     S(121, 126),    S(129, 162),    S(129, 212),    S(128, 211),    S(111, 158),    S(89, 134),     S(36, 113),     //
    S(107, 120),    S(105, 156),    S(108, 117),    S(116, 158),    S(111, 164),    S(87, 116),     S(36, 173),     S(12, 70),      //
    S(11, 48),      S(73, 105),     S(92, 108),     S(100, 129),    S(86, 141),     S(45, 116),     S(31, 128),     S(-30, 6),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(13, 234),     S(-100, 367),   S(-289, 441),   S(-150, 353),   S(-162, 376),   S(-141, 392),   S(-74, 369),    S(-16, 346),    //
    S(91, 243),     S(48, 366),     S(67, 327),     S(56, 320),     S(55, 331),     S(87, 300),     S(100, 317),    S(68, 286),     //
    S(172, 271),    S(151, 311),    S(152, 327),    S(144, 304),    S(144, 293),    S(141, 312),    S(123, 313),    S(145, 252),    //
    S(139, 240),    S(180, 278),    S(189, 285),    S(210, 308),    S(219, 309),    S(162, 282),    S(161, 269),    S(126, 248),    //
    S(163, 210),    S(160, 263),    S(202, 269),    S(216, 287),    S(203, 298),    S(189, 288),    S(139, 266),    S(129, 222),    //
    S(178, 234),    S(201, 241),    S(216, 267),    S(191, 289),    S(188, 286),    S(185, 278),    S(181, 261),    S(151, 215),    //
    S(152, 177),    S(243, 192),    S(189, 238),    S(177, 255),    S(165, 261),    S(175, 224),    S(177, 209),    S(157, 214),    //
    S(154, 192),    S(144, 229),    S(150, 239),    S(160, 222),    S(143, 235),    S(156, 268),    S(159, 244),    S(154, 200),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(305, 490),    S(335, 496),    S(295, 537),    S(282, 508),    S(329, 471),    S(277, 499),    S(298, 510),    S(286, 504),    //
    S(248, 515),    S(282, 521),    S(336, 478),    S(293, 478),    S(323, 462),    S(287, 488),    S(234, 521),    S(234, 522),    //
    S(218, 501),    S(330, 431),    S(361, 423),    S(322, 407),    S(318, 425),    S(258, 464),    S(239, 496),    S(200, 533),    //
    S(177, 480),    S(237, 481),    S(246, 466),    S(232, 455),    S(252, 435),    S(217, 477),    S(201, 497),    S(160, 519),    //
    S(148, 422),    S(201, 420),    S(187, 452),    S(154, 459),    S(166, 451),    S(156, 474),    S(142, 478),    S(120, 483),    //
    S(149, 348),    S(223, 345),    S(205, 375),    S(181, 394),    S(190, 395),    S(176, 410),    S(166, 398),    S(124, 420),    //
    S(82, 340),     S(205, 277),    S(206, 323),    S(190, 371),    S(198, 363),    S(180, 380),    S(170, 369),    S(138, 373),    //
    S(142, 316),    S(166, 342),    S(227, 329),    S(232, 340),    S(234, 352),    S(208, 378),    S(204, 367),    S(184, 372),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(426, 686),    S(494, 669),    S(384, 851),    S(331, 941),    S(353, 912),    S(405, 807),    S(406, 709),    S(361, 723),    //
    S(400, 730),    S(400, 783),    S(356, 887),    S(246, 1003),   S(292, 959),    S(359, 805),    S(392, 711),    S(382, 668),    //
    S(362, 760),    S(398, 806),    S(350, 901),    S(313, 940),    S(335, 915),    S(378, 804),    S(421, 673),    S(400, 650),    //
    S(352, 717),    S(349, 797),    S(304, 875),    S(301, 922),    S(328, 894),    S(336, 785),    S(382, 693),    S(369, 654),    //
    S(334, 694),    S(333, 711),    S(322, 761),    S(298, 831),    S(307, 839),    S(336, 759),    S(343, 696),    S(360, 611),    //
    S(333, 577),    S(364, 567),    S(351, 671),    S(322, 702),    S(342, 702),    S(344, 723),    S(365, 642),    S(349, 619),    //
    S(306, 423),    S(350, 383),    S(344, 481),    S(367, 545),    S(367, 585),    S(371, 558),    S(350, 587),    S(362, 548),    //
    S(273, 456),    S(321, 260),    S(343, 276),    S(346, 405),    S(362, 471),    S(358, 466),    S(355, 483),    S(325, 529),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(352, -693),   S(580, 4),      S(457, 158),    S(67, 236),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(418, -277),   S(383, 144),    S(240, 226),    S(8, 225),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(245, -40),    S(254, 147),    S(86, 265),     S(-110, 288),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(64, -45),     S(139, 101),    S(-45, 258),    S(-174, 315),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-82, -48),    S(8, 75),       S(-79, 220),    S(-201, 295),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -85),    S(30, 29),      S(-64, 179),    S(-141, 249),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(41, -156),    S(40, -22),     S(-30, 94),     S(-114, 186),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -291),   S(8, -141),     S(-77, -13),    S(-82, 2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-71, 66);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -2), S(9, 13), S(9, 6), S(3, -0), S(2, -5),
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
  {{ S(17, -13), S(-6, 6), S(-2, -7), S(9, -12), S(17, -26), S(9, -34), S(4, -41), }},
  {{ S(6, 5), S(-17, 2), S(-11, 6), S(-2, 7), S(2, 2), S(-6, -4), S(-11, -20), }},
  {{ S(3, 9), S(-6, 2), S(-5, 22), S(1, 20), S(3, 12), S(-2, 1), S(-14, -20), }},
  {{ S(8, 17), S(-7, 16), S(-1, 28), S(4, 27), S(5, 23), S(6, 22), S(13, -2), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 23), S(-15, -1), S(-16, 4), S(-16, 20), S(-4, 23),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 5), S(-50, -75), S(-12, -46), S(-4, -10), S(-10, -3), S(-13, 2), S(-13, 2), }},
  {{ S(0, -7), S(-32, -77), S(-5, -56), S(-7, -17), S(-8, -12), S(-16, -6), S(-6, -6), }},
  {{ S(-8, 2), S(-7, -65), S(8, -37), S(-5, -3), S(-11, 2), S(-17, 7), S(-13, 8), }},
  {{ S(-7, -10), S(5, -73), S(9, -47), S(-7, 7), S(-13, 0), S(-18, -5), S(-15, 1), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1440, 1212, -26, -12
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(111);
inline VParam WINNABLE_ASYM = V(97);
inline VParam WINNABLE_PAWN_ENDGAME = V(81);
inline VParam WINNABLE_BIAS = V(-448);

// clang-format on
}  // namespace Clockwork
