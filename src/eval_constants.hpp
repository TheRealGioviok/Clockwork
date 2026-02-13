#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(142, 201);
inline const PParam KNIGHT_MAT = S(578, 625);
inline const PParam BISHOP_MAT = S(628, 644);
inline const PParam ROOK_MAT   = S(486, 663);
inline const PParam QUEEN_MAT  = S(1142, 1104);
inline const PParam TEMPO_VAL  = S(57, 20);

inline const PParam BISHOP_PAIR_VAL   = S(55, 200);
inline const PParam ROOK_OPEN_VAL     = S(107, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 21);

inline const PParam DOUBLED_PAWN_VAL = S(-9, -68);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(40, 63);
inline const PParam OUTPOST_BISHOP_VAL    = S(53, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 10);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -16);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(23, 60);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(70, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, 3), S(40, 29), S(59, 53), S(137, 148), S(398, 197), S(433, 918),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(57, 35), S(46, 27), S(56, 54), S(120, 141), S(445, 78),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-77, -124), S(-70, -104), S(-47, 12), S(15, 115), S(95, 272), S(282, 383),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(40, -50), S(31, -3), S(18, 36), S(-4, 115), S(60, 220), S(236, 299),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(20, -37), S(-4, 21), S(-8, -14), S(-4, -51), S(-10, -128), S(-240, -228),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(1, 151), S(-15, 117), S(-12, 50), S(-4, 9), S(2, 8), S(36, 7), S(6, 9),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-310, -48), S(-40, 28), S(-21, 60), S(15, 96), S(33, 114), S(49, 118), S(28, 114),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(80, -4), S(151, 184), S(188, 267), S(217, 302), S(257, 324), S(282, 358), S(316, 356), S(345, 369), S(398, 284),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(110, -5), S(150, 181), S(205, 245), S(231, 292), S(255, 325), S(272, 351), S(282, 369), S(294, 380), S(302, 396), S(326, 378), S(335, 382), S(385, 329), S(410, 323), S(411, 300),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(337, 238), S(251, 437), S(276, 459), S(293, 471), S(303, 484), S(309, 495), S(316, 506), S(324, 510), S(331, 519), S(341, 522), S(352, 525), S(358, 529), S(366, 526), S(386, 496), S(471, 394),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(564, 519), S(680, 561), S(709, 668), S(726, 770), S(741, 820), S(751, 863), S(756, 900), S(762, 915), S(767, 933), S(772, 946), S(778, 954), S(783, 958), S(788, 961), S(793, 958), S(793, 961), S(793, 962), S(796, 958), S(799, 953), S(806, 944), S(814, 936), S(822, 915), S(850, 874), S(839, 879), S(850, 819), S(824, 823), S(817, 787), S(760, 827), S(794, 773),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(427, -56), S(117, -125), S(31, -37), S(18, -1), S(-3, 3), S(-21, 1), S(-33, 17), S(-53, 27), S(-52, -1),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(13, -11), S(17, -16), S(14, -12), S(6, -9), S(1, 216),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -1), S(8, -12), S(6, -9), S(5, -5), S(6, 390),
};

inline const PParam PAWN_THREAT_KNIGHT = S(223, 86);
inline const PParam PAWN_THREAT_BISHOP = S(185, 151);
inline const PParam PAWN_THREAT_ROOK   = S(189, 121);
inline const PParam PAWN_THREAT_QUEEN  = S(173, -33);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 105);
inline const PParam KNIGHT_THREAT_ROOK   = S(239, 48);
inline const PParam KNIGHT_THREAT_QUEEN  = S(147, -7);

inline const PParam BISHOP_THREAT_KNIGHT = S(108, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(225, 114);
inline const PParam BISHOP_THREAT_QUEEN  = S(188, 77);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -34), S(-5, -8), S(-7, -19), S(-10, -27), S(-14, -37), S(-18, -44), S(-22, -53), S(-27, -54), S(-42, -55),
};

inline const PParam ROOK_LINEUP = S(11, 71);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(323, 343),    S(164, 462),    S(304, 414),    S(317, 290),    S(327, 240),    S(253, 318),    S(172, 372),    S(272, 334),    //
    S(126, 223),    S(163, 246),    S(201, 165),    S(182, 105),    S(157, 93),     S(132, 144),    S(102, 203),    S(53, 230),     //
    S(84, 189),     S(73, 185),     S(119, 110),    S(116, 90),     S(102, 89),     S(73, 123),     S(29, 169),     S(17, 197),     //
    S(64, 134),     S(52, 156),     S(88, 102),     S(85, 97),      S(63, 98),      S(46, 124),     S(-14, 169),    S(-15, 162),    //
    S(58, 108),     S(102, 109),    S(81, 147),     S(76, 132),     S(48, 126),     S(27, 134),     S(-9, 151),     S(-18, 146),    //
    S(73, 111),     S(164, 126),    S(151, 181),    S(100, 165),    S(72, 150),     S(50, 145),     S(20, 157),     S(1, 159),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-211, -107),  S(-128, 227),   S(-100, 72),    S(110, 190),    S(61, 202),     S(-115, 201),   S(-239, 220),   S(-292, 7),     //
    S(101, 172),    S(149, 192),    S(215, 154),    S(231, 163),    S(215, 179),    S(147, 192),    S(116, 202),    S(73, 186),     //
    S(161, 181),    S(241, 156),    S(242, 213),    S(233, 212),    S(205, 236),    S(143, 257),    S(151, 199),    S(106, 193),    //
    S(252, 194),    S(262, 214),    S(253, 248),    S(250, 265),    S(251, 269),    S(210, 257),    S(196, 226),    S(189, 199),    //
    S(242, 190),    S(275, 182),    S(249, 233),    S(241, 257),    S(219, 260),    S(212, 249),    S(205, 203),    S(186, 194),    //
    S(181, 162),    S(210, 167),    S(204, 206),    S(213, 234),    S(206, 237),    S(171, 213),    S(157, 179),    S(135, 150),    //
    S(195, 165),    S(208, 171),    S(191, 162),    S(192, 190),    S(177, 193),    S(149, 153),    S(137, 166),    S(126, 76),     //
    S(130, 115),    S(183, 176),    S(196, 139),    S(210, 143),    S(195, 162),    S(163, 128),    S(144, 164),    S(101, 78),     //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(34, 276),     S(-5, 303),     S(-232, 355),   S(-97, 307),    S(-110, 313),   S(-160, 324),   S(-38, 333),    S(47, 321),     //
    S(133, 231),    S(90, 301),     S(125, 254),    S(85, 262),     S(81, 273),     S(102, 269),    S(142, 263),    S(122, 246),    //
    S(224, 238),    S(222, 268),    S(226, 269),    S(190, 278),    S(171, 269),    S(175, 272),    S(187, 257),    S(174, 242),    //
    S(190, 233),    S(214, 253),    S(217, 278),    S(215, 313),    S(241, 306),    S(176, 282),    S(184, 249),    S(149, 232),    //
    S(217, 203),    S(229, 229),    S(230, 261),    S(234, 287),    S(217, 303),    S(198, 280),    S(172, 246),    S(158, 222),    //
    S(237, 213),    S(275, 217),    S(285, 248),    S(233, 271),    S(219, 261),    S(220, 260),    S(226, 242),    S(176, 229),    //
    S(211, 178),    S(307, 196),    S(260, 216),    S(231, 230),    S(210, 231),    S(209, 209),    S(212, 208),    S(216, 191),    //
    S(234, 188),    S(226, 197),    S(230, 234),    S(237, 198),    S(230, 206),    S(229, 249),    S(228, 224),    S(218, 204),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(472, 400),    S(454, 433),    S(448, 441),    S(467, 387),    S(424, 416),    S(426, 414),    S(391, 445),    S(399, 440),    //
    S(339, 485),    S(406, 495),    S(470, 458),    S(423, 462),    S(409, 474),    S(397, 470),    S(321, 506),    S(306, 511),    //
    S(296, 487),    S(405, 467),    S(453, 435),    S(436, 428),    S(407, 437),    S(358, 468),    S(349, 476),    S(287, 511),    //
    S(302, 447),    S(380, 458),    S(410, 430),    S(401, 427),    S(376, 452),    S(339, 472),    S(321, 471),    S(260, 492),    //
    S(277, 387),    S(344, 405),    S(338, 413),    S(314, 421),    S(298, 430),    S(276, 456),    S(258, 446),    S(236, 440),    //
    S(266, 331),    S(344, 337),    S(323, 373),    S(301, 379),    S(295, 382),    S(272, 400),    S(268, 383),    S(226, 389),    //
    S(159, 335),    S(296, 298),    S(312, 330),    S(301, 352),    S(290, 353),    S(282, 356),    S(264, 343),    S(238, 346),    //
    S(229, 322),    S(254, 338),    S(311, 330),    S(326, 326),    S(316, 330),    S(296, 348),    S(282, 347),    S(264, 354),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(613, 630),    S(635, 608),    S(562, 722),    S(537, 772),    S(534, 754),    S(557, 709),    S(584, 638),    S(519, 693),    //
    S(568, 726),    S(541, 805),    S(521, 852),    S(401, 928),    S(401, 916),    S(476, 847),    S(509, 738),    S(523, 711),    //
    S(541, 768),    S(597, 789),    S(525, 884),    S(490, 893),    S(468, 875),    S(498, 828),    S(546, 724),    S(539, 683),    //
    S(582, 689),    S(577, 797),    S(537, 840),    S(521, 878),    S(508, 878),    S(518, 797),    S(566, 710),    S(553, 672),    //
    S(579, 679),    S(585, 721),    S(557, 784),    S(525, 831),    S(519, 840),    S(535, 766),    S(539, 710),    S(568, 630),    //
    S(578, 595),    S(608, 656),    S(607, 714),    S(567, 723),    S(566, 704),    S(566, 722),    S(578, 655),    S(556, 619),    //
    S(557, 485),    S(590, 491),    S(603, 551),    S(610, 609),    S(596, 633),    S(591, 604),    S(558, 629),    S(561, 617),    //
    S(533, 516),    S(571, 338),    S(592, 377),    S(600, 495),    S(605, 563),    S(600, 515),    S(585, 536),    S(554, 581),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(35, -328),    S(330, 199),    S(201, 144),    S(51, -10),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(276, -52),    S(378, 150),    S(250, 132),    S(169, -23),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(260, 33),     S(407, 104),    S(310, 88),     S(203, -5),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(108, 15),     S(357, 29),     S(234, 41),     S(150, 21),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-8, -14),     S(238, 3),      S(180, 0),      S(57, 12),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -5),     S(217, -12),    S(125, -1),     S(72, -15),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(2, -12),      S(93, 29),      S(15, 26),      S(-50, 6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-119, -51),   S(-18, -14),    S(-122, -4),    S(-126, -77),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -11), S(-2, 26), S(-7, 28), S(1, 12), S(1, 11), S(-6, 27), S(-0, 24), }},
  {{ S(7, -2), S(-23, 33), S(-18, 24), S(-8, 6), S(-8, 7), S(-17, 27), S(-21, 38), }},
  {{ S(-10, 2), S(-23, 27), S(-20, 6), S(-16, -8), S(-16, -6), S(-20, 8), S(-21, 25), }},
  {{ S(3, -13), S(-15, -16), S(-7, -19), S(-1, -23), S(-3, -22), S(-8, -16), S(-13, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(1, 51), S(-18, 33), S(-15, 21), S(-6, 8), S(-6, -10),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 0), S(-15, 11), S(-13, 6), S(-12, 6), S(-12, 1), S(-10, -2), S(-14, 6), }},
  {{ S(-1, 0), S(-10, 6), S(-17, 14), S(-14, 8), S(-14, 6), S(-16, 9), S(-10, 5), }},
  {{ S(-8, 6), S(-14, 4), S(-15, 10), S(-10, 11), S(-10, 10), S(-15, 8), S(-14, 7), }},
  {{ S(-9, 8), S(-15, 9), S(-16, 10), S(-11, 14), S(-9, 14), S(-16, 10), S(-17, 9), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1010, 487, -32, 48
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(135);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(225);
inline VParam WINNABLE_BIAS = V(-653);

// Epoch duration: 9.80184s

// clang-format on
}  // namespace Clockwork
