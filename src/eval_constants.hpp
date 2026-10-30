#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(112, 296);
inline const PParam KNIGHT_MAT = S(474, 909);
inline const PParam BISHOP_MAT = S(415, 810);
inline const PParam ROOK_MAT   = S(321, 933);
inline const PParam QUEEN_MAT  = S(642, 2138);

inline const PParam TEMPO_VAL  = S(71, 62);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 3);
inline const PParam BISHOP_PAIR_VAL   = S(56, 248);
inline const PParam ROOK_OPEN_VAL     = S(114, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 22);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(20, 8);
inline const PParam SPACE_VAL = S(93, -103);

inline const PParam DOUBLED_PAWN_VAL = S(-19, -96);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -44);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -36);
inline const PParam OUTPOST_KNIGHT_VAL    = S(47, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(36, 27);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 65);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 9);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -9), S(36, 28), S(50, 78), S(112, 237), S(336, 627), S(847, 958),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 29), S(40, 25), S(39, 72), S(82, 197), S(328, 283),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -196), S(-66, -150), S(-36, -19), S(15, 99), S(86, 352), S(217, 592),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-75, 53), S(-74, 30), S(-36, 94), S(-68, 222), S(7, 252), S(126, 112),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-15, 59), S(-14, 50), S(-54, 102), S(-5, 116), S(129, 65), S(51, 141),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(19, -34), S(16, 3), S(6, 43), S(14, 110), S(98, 202), S(350, 211),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(0, -31), S(-1, 4), S(-11, -34), S(-8, -81), S(-33, -153), S(-221, -399),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 198), S(-4, 144), S(-7, 63), S(6, 20), S(22, 17), S(56, 8), S(62, -19),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-148, -10), S(3, -17), S(-11, 77), S(22, 119), S(36, 157), S(45, 166), S(34, 139),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(76, -44), S(119, 175), S(136, 259), S(147, 296), S(159, 329), S(165, 370), S(175, 387), S(184, 409), S(195, 378),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(41, 21), S(103, 233), S(157, 297), S(176, 350), S(192, 382), S(202, 403), S(208, 414), S(207, 428), S(209, 430), S(212, 437), S(225, 423), S(225, 415), S(219, 423), S(173, 388),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(261, 355), S(189, 529), S(210, 557), S(226, 572), S(236, 586), S(239, 593), S(242, 603), S(246, 604), S(249, 612), S(253, 620), S(254, 624), S(250, 631), S(247, 638), S(248, 626), S(259, 593),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(330, 669), S(455, 832), S(482, 936), S(499, 1058), S(518, 1077), S(525, 1112), S(530, 1145), S(532, 1167), S(535, 1188), S(538, 1202), S(540, 1216), S(546, 1219), S(547, 1228), S(552, 1228), S(550, 1237), S(552, 1238), S(548, 1241), S(546, 1237), S(544, 1239), S(551, 1233), S(535, 1232), S(558, 1198), S(518, 1239), S(484, 1231), S(449, 1227), S(419, 1257), S(349, 1320), S(399, 1226),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(102, 270), S(130, 288), S(139, 319), S(145, 331), S(153, 341), S(156, 355), S(158, 370), S(163, 361), S(167, 364), S(172, 357), S(176, 355), S(177, 356), S(177, 351), S(182, 340), S(189, 322), S(190, 311), S(191, 295), S(195, 278), S(202, 262), S(198, 241), S(168, 192),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(214, 322), S(210, 324), S(211, 332), S(210, 364), S(209, 373), S(211, 374), S(209, 384), S(211, 384), S(210, 394), S(207, 400), S(205, 410), S(205, 411), S(207, 415), S(208, 418), S(217, 418), S(223, 410), S(218, 418), S(190, 419),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(243, 423), S(240, 444), S(239, 454), S(240, 465), S(244, 468), S(246, 477), S(246, 484), S(248, 491), S(246, 506), S(249, 511), S(245, 523), S(244, 531), S(240, 545), S(241, 548), S(239, 556), S(232, 568), S(232, 571), S(230, 576), S(223, 582), S(207, 595),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(422, 926), S(411, 989), S(413, 1065), S(420, 1070), S(418, 1102), S(419, 1116), S(420, 1120), S(423, 1137), S(424, 1134), S(429, 1134), S(424, 1153), S(430, 1142), S(434, 1139), S(438, 1134), S(438, 1143), S(444, 1132), S(446, 1120), S(452, 1116), S(459, 1098), S(457, 1107), S(482, 1065), S(487, 1056), S(507, 994),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(3, 6), S(5, 4), S(14, 2), S(1, 16),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 190);
inline const PParam PAWN_THREAT_BISHOP = S(164, 255);
inline const PParam PAWN_THREAT_ROOK   = S(191, 160);
inline const PParam PAWN_THREAT_QUEEN  = S(155, 47);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 56), S(92, 124), S(107, 127), S(184, 103), S(171, 28), }},
  {{ S(10, 58), S(83, 114), S(106, 122), S(215, 635), S(153, -17), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(11, 73), S(43, 139), S(62, 138), S(17, 20), S(162, -60), }},
  {{ S(1, 61), S(57, 110), S(100, 97), S(14, 13), S(199, 1265), }},
}};
inline const PParam KING_THREAT  = S(-24, 149);
inline const PParam REACH_THREAT = S(-13, 11);
inline const PParam REACH_THREAT_LOOSE = S(18, 27);
inline const PParam HANGING_PAWN  = S(36, 99);
inline const PParam HANGING_NON_PAWN  = S(82, 42);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -13), S(11, 30),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(49, 33), S(84, -75),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(40, -5), S(39, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -13), S(-0, -18), S(-6, -25), S(-12, -31), S(-19, -34), S(-21, -44), S(-27, -38), S(-26, -92),
};

inline const PParam ROOK_LINEUP = S(16, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 492),    S(158, 619),    S(148, 589),    S(251, 491),    S(251, 424),    S(223, 462),    S(216, 501),    S(312, 454),    //
    S(126, 312),    S(102, 396),    S(85, 328),     S(104, 245),    S(100, 197),    S(75, 229),     S(75, 292),     S(59, 316),     //
    S(117, 245),    S(80, 271),     S(97, 244),     S(72, 206),     S(59, 183),     S(56, 192),     S(34, 209),     S(40, 254),     //
    S(76, 182),     S(45, 220),     S(77, 203),     S(64, 173),     S(43, 159),     S(41, 167),     S(0, 188),      S(6, 195),      //
    S(61, 142),     S(94, 143),     S(86, 217),     S(74, 192),     S(54, 178),     S(33, 172),     S(-1, 176),     S(-9, 176),     //
    S(86, 160),     S(168, 144),    S(176, 170),    S(130, 220),    S(103, 198),    S(75, 177),     S(32, 197),     S(16, 196),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-203, -401),  S(-196, 176),   S(-238, 246),   S(58, 183),     S(-45, 201),    S(-260, 272),   S(-275, 232),   S(-294, -315),  //
    S(65, 131),     S(52, 175),     S(135, 157),    S(130, 211),    S(142, 190),    S(102, 171),    S(49, 161),     S(10, 162),     //
    S(100, 118),    S(106, 167),    S(110, 177),    S(125, 210),    S(106, 214),    S(78, 180),     S(58, 184),     S(21, 152),     //
    S(148, 180),    S(149, 201),    S(149, 232),    S(149, 300),    S(150, 295),    S(127, 229),    S(107, 186),    S(82, 193),     //
    S(128, 179),    S(145, 170),    S(156, 210),    S(129, 300),    S(127, 293),    S(121, 235),    S(105, 190),    S(74, 170),     //
    S(81, 116),     S(120, 121),    S(128, 157),    S(130, 213),    S(128, 211),    S(111, 153),    S(89, 129),     S(36, 110),     //
    S(107, 127),    S(105, 155),    S(110, 122),    S(118, 163),    S(113, 171),    S(88, 120),     S(36, 169),     S(12, 69),      //
    S(12, 49),      S(74, 110),     S(93, 111),     S(101, 129),    S(87, 138),     S(46, 114),     S(31, 131),     S(-30, 8),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(12, 231),     S(-102, 368),   S(-293, 445),   S(-152, 349),   S(-161, 371),   S(-141, 390),   S(-72, 366),    S(-16, 341),    //
    S(90, 241),     S(45, 365),     S(67, 326),     S(56, 321),     S(55, 333),     S(87, 304),     S(99, 317),     S(67, 284),     //
    S(172, 267),    S(152, 309),    S(151, 327),    S(147, 307),    S(147, 297),    S(140, 316),    S(123, 314),    S(145, 248),    //
    S(139, 242),    S(179, 278),    S(190, 286),    S(211, 307),    S(220, 309),    S(162, 284),    S(161, 267),    S(126, 245),    //
    S(164, 211),    S(162, 268),    S(203, 269),    S(217, 285),    S(203, 294),    S(190, 286),    S(141, 266),    S(129, 220),    //
    S(177, 236),    S(200, 240),    S(217, 267),    S(191, 284),    S(187, 281),    S(185, 276),    S(181, 256),    S(150, 216),    //
    S(153, 183),    S(244, 197),    S(191, 242),    S(178, 260),    S(165, 264),    S(176, 225),    S(177, 212),    S(158, 215),    //
    S(154, 191),    S(144, 226),    S(150, 238),    S(159, 230),    S(144, 241),    S(156, 269),    S(159, 242),    S(153, 196),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(305, 490),    S(336, 496),    S(295, 537),    S(281, 510),    S(330, 472),    S(277, 500),    S(299, 510),    S(288, 503),    //
    S(248, 515),    S(283, 520),    S(335, 478),    S(293, 477),    S(323, 464),    S(288, 486),    S(234, 522),    S(234, 523),    //
    S(218, 500),    S(331, 429),    S(361, 422),    S(321, 405),    S(318, 424),    S(258, 462),    S(240, 495),    S(198, 534),    //
    S(177, 480),    S(237, 479),    S(245, 464),    S(231, 453),    S(252, 433),    S(217, 476),    S(201, 496),    S(160, 518),    //
    S(148, 421),    S(201, 419),    S(186, 451),    S(154, 457),    S(167, 449),    S(156, 473),    S(142, 477),    S(119, 484),    //
    S(149, 347),    S(224, 344),    S(205, 375),    S(182, 392),    S(190, 395),    S(175, 411),    S(167, 398),    S(125, 421),    //
    S(82, 339),     S(204, 280),    S(206, 322),    S(191, 369),    S(199, 362),    S(180, 380),    S(169, 370),    S(139, 372),    //
    S(142, 317),    S(165, 343),    S(227, 329),    S(233, 340),    S(234, 351),    S(208, 379),    S(204, 368),    S(184, 373),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(428, 684),    S(493, 674),    S(385, 852),    S(330, 944),    S(353, 915),    S(408, 804),    S(407, 711),    S(359, 728),    //
    S(399, 731),    S(398, 788),    S(355, 889),    S(246, 1003),   S(292, 960),    S(358, 808),    S(391, 716),    S(381, 671),    //
    S(361, 760),    S(397, 804),    S(350, 899),    S(312, 936),    S(333, 917),    S(377, 804),    S(419, 676),    S(400, 651),    //
    S(352, 714),    S(350, 790),    S(304, 870),    S(301, 917),    S(328, 890),    S(335, 784),    S(381, 694),    S(370, 653),    //
    S(335, 691),    S(334, 703),    S(322, 756),    S(298, 826),    S(307, 837),    S(336, 758),    S(344, 692),    S(360, 612),    //
    S(333, 577),    S(365, 564),    S(351, 665),    S(323, 699),    S(342, 699),    S(344, 724),    S(365, 645),    S(349, 622),    //
    S(308, 419),    S(350, 384),    S(345, 478),    S(368, 543),    S(367, 583),    S(371, 560),    S(350, 592),    S(362, 551),    //
    S(273, 457),    S(321, 261),    S(343, 276),    S(347, 404),    S(362, 471),    S(358, 468),    S(355, 484),    S(325, 531),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(350, -682),   S(581, 12),     S(462, 158),    S(72, 236),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(417, -269),   S(383, 149),    S(241, 227),    S(13, 220),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(242, -32),    S(251, 151),    S(87, 262),     S(-108, 284),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(64, -41),     S(137, 102),    S(-45, 255),    S(-172, 310),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-84, -45),    S(7, 75),       S(-78, 216),    S(-201, 292),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -82),    S(30, 27),      S(-65, 176),    S(-141, 245),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -153),    S(40, -23),     S(-30, 92),     S(-113, 183),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -288),   S(8, -139),     S(-77, -13),    S(-82, 1),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
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
  {{ S(17, -12), S(-6, 6), S(-2, -7), S(9, -12), S(17, -26), S(10, -35), S(4, -41), }},
  {{ S(6, 6), S(-17, 2), S(-11, 6), S(-2, 8), S(2, 2), S(-5, -4), S(-11, -21), }},
  {{ S(3, 9), S(-6, 3), S(-5, 23), S(1, 20), S(3, 12), S(-2, 1), S(-14, -21), }},
  {{ S(8, 17), S(-7, 17), S(-0, 28), S(5, 28), S(5, 24), S(6, 22), S(14, -2), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 23), S(-15, -0), S(-16, 4), S(-16, 21), S(-4, 24),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 6), S(-51, -76), S(-12, -46), S(-4, -10), S(-10, -3), S(-13, 3), S(-13, 3), }},
  {{ S(0, -6), S(-32, -78), S(-5, -57), S(-6, -17), S(-8, -12), S(-16, -6), S(-6, -6), }},
  {{ S(-8, 2), S(-7, -66), S(8, -38), S(-5, -3), S(-11, 2), S(-17, 7), S(-13, 9), }},
  {{ S(-7, -9), S(5, -74), S(8, -47), S(-7, 6), S(-13, 0), S(-19, -4), S(-15, 1), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1430, 1193, -26, -11
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(111);
inline VParam WINNABLE_ASYM = V(97);
inline VParam WINNABLE_PAWN_ENDGAME = V(79);
inline VParam WINNABLE_BIAS = V(-447);

// Epoch duration: tuned from log reach_contest_rebased_tune.log (epoch 450)
// clang-format on
}  // namespace Clockwork
