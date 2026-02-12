#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(133, 207);
inline const PParam KNIGHT_MAT = S(613, 676);
inline const PParam BISHOP_MAT = S(598, 645);
inline const PParam ROOK_MAT   = S(469, 675);
inline const PParam QUEEN_MAT  = S(1099, 1076);
inline const PParam TEMPO_VAL  = S(61, 30);

inline const PParam BISHOP_PAIR_VAL   = S(54, 195);
inline const PParam ROOK_OPEN_VAL     = S(108, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 12);
inline const PParam SEE_STABLE_PIECES_VALUE = S(8, 5);
inline const PParam SEE_RESTRICTED_SQUARES = S(9, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-8, -71);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -23);
inline const PParam OUTPOST_KNIGHT_VAL    = S(33, 58);
inline const PParam OUTPOST_BISHOP_VAL    = S(36, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 36);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -35);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 0), S(36, 30), S(61, 49), S(144, 144), S(372, 208), S(457, 690),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 24), S(42, 14), S(51, 39), S(111, 126), S(408, 61),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-73, -119), S(-69, -99), S(-46, 10), S(7, 117), S(95, 259), S(258, 384),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -46), S(33, -3), S(20, 34), S(-5, 114), S(42, 227), S(172, 288),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -36), S(0, 11), S(-1, -18), S(-8, -49), S(-15, -120), S(-215, -236),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-4, 150), S(-16, 113), S(-12, 46), S(-5, 9), S(1, 8), S(37, 5), S(10, 3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-311, -35), S(-41, 27), S(-22, 61), S(13, 98), S(32, 114), S(50, 115), S(32, 108),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(30, -36), S(105, 138), S(140, 227), S(167, 264), S(203, 284), S(222, 316), S(249, 315), S(275, 329), S(322, 251),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(84, -13), S(128, 158), S(185, 222), S(213, 266), S(237, 299), S(252, 324), S(258, 345), S(269, 360), S(272, 383), S(296, 370), S(304, 379), S(351, 333), S(346, 354), S(371, 320),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(338, 243), S(231, 424), S(256, 448), S(273, 459), S(284, 471), S(291, 480), S(297, 490), S(306, 493), S(311, 504), S(322, 506), S(332, 509), S(339, 514), S(345, 514), S(363, 491), S(446, 395),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(527, 512), S(643, 557), S(668, 662), S(687, 768), S(704, 811), S(713, 850), S(720, 879), S(728, 886), S(733, 908), S(736, 921), S(743, 927), S(748, 935), S(757, 928), S(760, 933), S(766, 928), S(764, 934), S(768, 929), S(772, 929), S(780, 919), S(788, 917), S(798, 895), S(822, 856), S(814, 861), S(814, 808), S(798, 797), S(788, 777), S(723, 832), S(750, 734),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(512, -233), S(104, -114), S(28, -32), S(15, 2), S(-2, 4), S(-19, -1), S(-26, 12), S(-42, 24), S(-33, -11),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -10), S(15, -15), S(13, -12), S(5, -8), S(2, 237),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -1), S(7, -10), S(6, -8), S(5, -5), S(6, 417),
};

inline const PParam PAWN_THREAT_KNIGHT = S(174, 42);
inline const PParam PAWN_THREAT_BISHOP = S(151, 81);
inline const PParam PAWN_THREAT_ROOK   = S(165, 72);
inline const PParam PAWN_THREAT_QUEEN  = S(76, -2);

inline const PParam KNIGHT_THREAT_BISHOP = S(85, 57);
inline const PParam KNIGHT_THREAT_ROOK   = S(206, 20);
inline const PParam KNIGHT_THREAT_QUEEN  = S(87, 4);

inline const PParam BISHOP_THREAT_KNIGHT = S(101, 49);
inline const PParam BISHOP_THREAT_ROOK   = S(196, 84);
inline const PParam BISHOP_THREAT_QUEEN  = S(117, 129);

inline const PParam HANGING_PAWN = S(8, -68);
inline const PParam HANGING_KNIGHT = S(-36, -81);
inline const PParam HANGING_BISHOP = S(-30, -60);
inline const PParam HANGING_ROOK = S(-23, -62);
inline const PParam HANGING_QUEEN = S(-89, 3);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(12, -32), S(-2, -5), S(-5, -13), S(-9, -23), S(-13, -32), S(-18, -38), S(-20, -50), S(-28, -46), S(-38, -47),
};

inline const PParam ROOK_LINEUP = S(11, 62);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(299, 342),    S(143, 447),    S(284, 417),    S(290, 289),    S(315, 242),    S(205, 330),    S(147, 367),    S(264, 312),    //
    S(111, 216),    S(133, 262),    S(174, 175),    S(157, 113),    S(138, 96),     S(112, 152),    S(88, 204),     S(47, 224),     //
    S(82, 176),     S(63, 178),     S(109, 101),    S(109, 81),     S(97, 78),      S(69, 113),     S(19, 163),     S(13, 190),     //
    S(52, 128),     S(38, 151),     S(73, 97),      S(71, 89),      S(48, 93),      S(31, 121),     S(-28, 165),    S(-22, 156),    //
    S(52, 100),     S(86, 108),     S(69, 138),     S(64, 123),     S(35, 120),     S(14, 126),     S(-21, 144),    S(-23, 137),    //
    S(65, 99),      S(152, 118),    S(137, 173),    S(88, 153),     S(60, 140),     S(41, 136),     S(10, 150),     S(-4, 150),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-258, -90),   S(-161, 168),   S(-119, 32),    S(84, 153),     S(12, 163),     S(-119, 158),   S(-246, 209),   S(-293, -24),   //
    S(60, 147),     S(97, 168),     S(184, 132),    S(183, 140),    S(178, 145),    S(90, 174),     S(58, 179),     S(34, 161),     //
    S(135, 132),    S(178, 134),    S(177, 180),    S(169, 162),    S(127, 196),    S(74, 215),     S(90, 169),     S(58, 158),     //
    S(204, 154),    S(206, 167),    S(205, 192),    S(197, 218),    S(197, 229),    S(148, 216),    S(135, 189),    S(137, 164),    //
    S(193, 158),    S(223, 139),    S(198, 189),    S(192, 215),    S(171, 220),    S(166, 202),    S(159, 157),    S(127, 165),    //
    S(131, 130),    S(158, 136),    S(148, 171),    S(158, 197),    S(154, 197),    S(119, 173),    S(106, 147),    S(76, 120),     //
    S(146, 142),    S(173, 131),    S(138, 143),    S(138, 165),    S(130, 160),    S(104, 117),    S(88, 139),     S(76, 62),      //
    S(80, 90),      S(124, 155),    S(139, 121),    S(155, 108),    S(138, 126),    S(105, 99),     S(91, 131),     S(54, 53),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(13, 304),     S(3, 297),      S(-255, 346),   S(-120, 276),   S(-128, 299),   S(-150, 306),   S(-38, 302),    S(50, 278),     //
    S(128, 224),    S(75, 283),     S(109, 235),    S(61, 250),     S(72, 253),     S(94, 254),     S(130, 250),    S(107, 239),    //
    S(197, 251),    S(206, 247),    S(201, 251),    S(178, 252),    S(151, 245),    S(156, 256),    S(171, 249),    S(169, 238),    //
    S(167, 234),    S(209, 233),    S(208, 245),    S(200, 271),    S(228, 258),    S(162, 248),    S(179, 221),    S(132, 233),    //
    S(199, 188),    S(211, 216),    S(221, 230),    S(225, 247),    S(202, 258),    S(184, 250),    S(146, 239),    S(149, 203),    //
    S(221, 199),    S(248, 201),    S(261, 226),    S(213, 248),    S(209, 228),    S(199, 239),    S(203, 219),    S(148, 230),    //
    S(186, 170),    S(281, 191),    S(242, 201),    S(210, 222),    S(192, 221),    S(195, 196),    S(193, 195),    S(189, 192),    //
    S(217, 173),    S(202, 194),    S(198, 232),    S(216, 189),    S(205, 200),    S(207, 238),    S(204, 214),    S(198, 192),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(414, 381),    S(426, 403),    S(401, 417),    S(420, 380),    S(405, 381),    S(370, 392),    S(366, 408),    S(356, 413),    //
    S(298, 448),    S(371, 442),    S(442, 405),    S(390, 405),    S(374, 413),    S(353, 423),    S(292, 454),    S(272, 466),    //
    S(273, 446),    S(373, 430),    S(433, 388),    S(411, 379),    S(364, 407),    S(321, 429),    S(324, 428),    S(256, 472),    //
    S(270, 416),    S(349, 413),    S(386, 387),    S(363, 392),    S(351, 405),    S(311, 426),    S(308, 420),    S(231, 457),    //
    S(252, 351),    S(317, 359),    S(308, 379),    S(285, 383),    S(263, 406),    S(252, 417),    S(223, 412),    S(201, 414),    //
    S(240, 295),    S(299, 319),    S(289, 342),    S(275, 343),    S(263, 355),    S(234, 378),    S(231, 353),    S(198, 363),    //
    S(132, 308),    S(265, 270),    S(276, 301),    S(265, 324),    S(250, 329),    S(242, 337),    S(225, 323),    S(200, 336),    //
    S(198, 293),    S(220, 314),    S(275, 303),    S(289, 300),    S(277, 310),    S(257, 326),    S(247, 322),    S(227, 331),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(548, 644),    S(600, 594),    S(525, 722),    S(495, 789),    S(489, 765),    S(520, 713),    S(534, 639),    S(485, 678),    //
    S(562, 672),    S(535, 754),    S(525, 784),    S(377, 885),    S(398, 854),    S(458, 811),    S(503, 682),    S(496, 686),    //
    S(515, 762),    S(578, 753),    S(516, 856),    S(474, 870),    S(450, 864),    S(496, 785),    S(525, 711),    S(531, 655),    //
    S(556, 674),    S(564, 756),    S(513, 807),    S(501, 840),    S(494, 838),    S(507, 746),    S(541, 698),    S(518, 680),    //
    S(561, 652),    S(555, 711),    S(529, 759),    S(498, 804),    S(500, 796),    S(499, 758),    S(514, 689),    S(538, 620),    //
    S(533, 597),    S(565, 638),    S(561, 702),    S(531, 707),    S(528, 701),    S(519, 729),    S(533, 650),    S(515, 625),    //
    S(504, 503),    S(543, 504),    S(548, 569),    S(561, 614),    S(547, 645),    S(544, 608),    S(505, 650),    S(518, 631),    //
    S(484, 517),    S(512, 366),    S(535, 389),    S(552, 500),    S(546, 579),    S(546, 527),    S(534, 552),    S(505, 574),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-69, -304),   S(272, 195),    S(147, 152),    S(8, -7),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(208, -47),    S(342, 153),    S(201, 146),    S(117, -4),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(215, 40),     S(379, 97),     S(276, 97),     S(168, -4),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(72, 7),       S(329, 34),     S(183, 58),     S(125, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -16),    S(224, 4),      S(160, 12),     S(47, 19),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-27, -8),     S(205, -3),     S(116, 4),      S(64, -13),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-3, -11),     S(80, 34),      S(-0, 34),      S(-58, 6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-116, -65),   S(-22, -18),    S(-119, -13),   S(-118, -87),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -15), S(-4, 20), S(-8, 23), S(-0, 9), S(-0, 6), S(-8, 22), S(-2, 21), }},
  {{ S(5, -3), S(-23, 29), S(-20, 24), S(-10, 6), S(-10, 6), S(-19, 29), S(-22, 37), }},
  {{ S(-9, 1), S(-20, 25), S(-19, 6), S(-15, -8), S(-14, -6), S(-18, 7), S(-19, 22), }},
  {{ S(0, -13), S(-18, -15), S(-9, -18), S(-3, -22), S(-5, -20), S(-10, -16), S(-13, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(5, 25), S(-18, 37), S(-15, 25), S(-6, 12), S(-7, -3),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 7), S(-14, 15), S(-12, 15), S(-11, 15), S(-12, 9), S(-11, 6), S(-14, 13), }},
  {{ S(-2, 6), S(-10, 12), S(-17, 17), S(-14, 16), S(-14, 12), S(-16, 14), S(-10, 11), }},
  {{ S(-8, 10), S(-13, 6), S(-14, 14), S(-10, 14), S(-10, 13), S(-14, 12), S(-13, 8), }},
  {{ S(-9, 12), S(-14, 13), S(-15, 12), S(-10, 18), S(-9, 18), S(-14, 13), S(-16, 13), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1143, 515, -36, 38
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(222);
inline VParam WINNABLE_BIAS = V(-664);

// Epoch duration: 8.0466s
// clang-format on
}  // namespace Clockwork
