#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 204);
inline const PParam KNIGHT_MAT = S(570, 624);
inline const PParam BISHOP_MAT = S(606, 647);
inline const PParam ROOK_MAT   = S(469, 680);
inline const PParam QUEEN_MAT  = S(1094, 1089);
inline const PParam TEMPO_VAL  = S(58, 23);

inline const PParam BISHOP_PAIR_VAL   = S(54, 194);
inline const PParam ROOK_OPEN_VAL     = S(105, -9);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 23);
inline const PParam MINOR_BEHIND_PAWN = S(10, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -18);
inline const PParam PRESSURED_CHAIN_BASE = S(-24, -96);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(37, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 43);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 9);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(52, -24);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -1), S(37, 23), S(57, 47), S(133, 143), S(376, 202), S(461, 682),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 35), S(44, 28), S(54, 58), S(116, 147), S(396, 107),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -123), S(-68, -99), S(-47, 11), S(8, 117), S(91, 267), S(264, 381),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -43), S(35, -4), S(23, 32), S(1, 111), S(48, 223), S(200, 286),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -31), S(3, 19), S(3, -11), S(2, -43), S(-5, -117), S(-212, -225),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-6, 148), S(-17, 113), S(-12, 46), S(-4, 8), S(1, 7), S(37, 5), S(11, 0),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-312, -54), S(-41, 28), S(-24, 60), S(13, 98), S(32, 114), S(49, 115), S(31, 107),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(63, 9), S(133, 176), S(167, 265), S(194, 300), S(234, 317), S(257, 349), S(289, 345), S(320, 358), S(371, 274),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(83, -7), S(126, 168), S(182, 234), S(209, 279), S(233, 311), S(250, 335), S(257, 354), S(271, 364), S(277, 382), S(302, 364), S(313, 365), S(360, 315), S(358, 330), S(387, 279),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(314, 247), S(231, 422), S(257, 449), S(274, 459), S(284, 472), S(290, 482), S(296, 493), S(305, 494), S(311, 505), S(322, 506), S(333, 507), S(341, 512), S(346, 511), S(363, 484), S(446, 381),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(493, 522), S(634, 538), S(660, 647), S(678, 759), S(693, 804), S(702, 849), S(708, 881), S(715, 890), S(719, 915), S(722, 929), S(727, 936), S(732, 944), S(740, 937), S(742, 944), S(747, 940), S(746, 941), S(747, 938), S(753, 932), S(761, 923), S(770, 918), S(778, 894), S(801, 853), S(798, 852), S(796, 798), S(784, 784), S(778, 752), S(713, 807), S(734, 716),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(498, -190), S(113, -113), S(32, -28), S(18, 5), S(-3, 6), S(-19, 1), S(-26, 9), S(-42, 17), S(-30, -23),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(15, -15), S(13, -12), S(6, -8), S(2, 204),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 409),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 92);
inline const PParam PAWN_THREAT_BISHOP = S(189, 142);
inline const PParam PAWN_THREAT_ROOK   = S(191, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(167, -14);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 99);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(152, -1);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 129);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 101);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -32), S(-3, -5), S(-5, -13), S(-8, -22), S(-12, -31), S(-16, -35), S(-18, -47), S(-25, -44), S(-36, -44),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 344),    S(149, 445),    S(291, 414),    S(297, 283),    S(318, 239),    S(214, 323),    S(156, 356),    S(264, 308),    //
    S(117, 208),    S(148, 249),    S(187, 164),    S(171, 105),    S(153, 86),     S(124, 139),    S(99, 194),     S(48, 220),     //
    S(81, 173),     S(70, 176),     S(111, 102),    S(111, 81),     S(99, 78),      S(72, 111),     S(25, 160),     S(11, 188),     //
    S(56, 125),     S(47, 149),     S(81, 96),      S(78, 90),      S(57, 94),      S(39, 119),     S(-20, 163),    S(-21, 154),    //
    S(55, 100),     S(92, 108),     S(76, 136),     S(69, 124),     S(41, 121),     S(19, 128),     S(-15, 147),    S(-23, 139),    //
    S(66, 102),     S(156, 119),    S(139, 173),    S(90, 156),     S(61, 144),     S(40, 138),     S(12, 151),     S(-6, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-255, -72),   S(-147, 190),   S(-98, 47),     S(104, 176),    S(35, 184),     S(-112, 190),   S(-245, 240),   S(-289, -6),    //
    S(73, 167),     S(118, 190),    S(209, 149),    S(201, 162),    S(198, 169),    S(112, 197),    S(78, 206),     S(49, 184),     //
    S(154, 150),    S(200, 151),    S(204, 209),    S(209, 198),    S(169, 233),    S(109, 242),    S(115, 188),    S(78, 178),     //
    S(226, 173),    S(233, 191),    S(232, 220),    S(217, 253),    S(217, 263),    S(174, 244),    S(165, 208),    S(161, 181),    //
    S(209, 177),    S(245, 163),    S(214, 222),    S(209, 241),    S(186, 244),    S(184, 230),    S(182, 178),    S(144, 181),    //
    S(156, 144),    S(181, 161),    S(170, 200),    S(177, 224),    S(173, 223),    S(138, 204),    S(129, 172),    S(101, 133),    //
    S(163, 148),    S(183, 142),    S(152, 157),    S(155, 183),    S(148, 181),    S(120, 137),    S(106, 153),    S(95, 68),      //
    S(95, 91),      S(142, 162),    S(156, 130),    S(174, 130),    S(156, 153),    S(124, 123),    S(108, 142),    S(69, 53),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-3, 300),     S(-17, 303),    S(-273, 344),   S(-144, 288),   S(-151, 307),   S(-166, 304),   S(-49, 299),    S(30, 276),     //
    S(119, 213),    S(62, 292),     S(96, 242),     S(46, 258),     S(59, 260),     S(80, 262),     S(123, 256),    S(96, 235),     //
    S(184, 227),    S(197, 244),    S(193, 253),    S(173, 255),    S(145, 250),    S(152, 255),    S(165, 244),    S(159, 215),    //
    S(159, 222),    S(193, 228),    S(195, 253),    S(192, 291),    S(223, 281),    S(154, 257),    S(165, 218),    S(125, 221),    //
    S(188, 177),    S(206, 214),    S(210, 238),    S(212, 264),    S(189, 279),    S(175, 258),    S(144, 235),    S(139, 191),    //
    S(214, 186),    S(249, 205),    S(258, 229),    S(202, 256),    S(197, 232),    S(192, 244),    S(202, 224),    S(141, 215),    //
    S(176, 154),    S(275, 169),    S(233, 191),    S(201, 211),    S(182, 216),    S(186, 189),    S(185, 182),    S(180, 176),    //
    S(209, 158),    S(197, 179),    S(193, 211),    S(210, 183),    S(201, 194),    S(199, 232),    S(197, 212),    S(188, 179),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(423, 386),    S(438, 403),    S(413, 419),    S(433, 381),    S(413, 387),    S(378, 399),    S(375, 412),    S(369, 416),    //
    S(301, 467),    S(377, 462),    S(449, 431),    S(396, 433),    S(381, 441),    S(360, 448),    S(298, 476),    S(279, 485),    //
    S(270, 462),    S(371, 449),    S(428, 410),    S(409, 394),    S(359, 425),    S(318, 449),    S(323, 444),    S(255, 488),    //
    S(275, 421),    S(349, 432),    S(386, 405),    S(361, 408),    S(353, 418),    S(313, 441),    S(308, 436),    S(234, 465),    //
    S(256, 355),    S(320, 373),    S(309, 393),    S(289, 391),    S(265, 417),    S(256, 427),    S(224, 423),    S(205, 419),    //
    S(249, 299),    S(309, 325),    S(295, 351),    S(281, 350),    S(268, 359),    S(242, 382),    S(240, 357),    S(206, 364),    //
    S(141, 312),    S(272, 277),    S(283, 307),    S(273, 329),    S(258, 334),    S(251, 338),    S(232, 324),    S(208, 336),    //
    S(205, 298),    S(228, 318),    S(284, 309),    S(297, 305),    S(286, 312),    S(266, 328),    S(255, 323),    S(236, 333),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(554, 644),    S(609, 587),    S(526, 724),    S(493, 795),    S(480, 775),    S(518, 712),    S(534, 642),    S(491, 673),    //
    S(556, 694),    S(514, 797),    S(503, 829),    S(361, 920),    S(371, 904),    S(434, 852),    S(479, 730),    S(487, 716),    //
    S(517, 766),    S(561, 790),    S(495, 894),    S(447, 906),    S(422, 899),    S(475, 814),    S(510, 735),    S(529, 657),    //
    S(555, 689),    S(558, 779),    S(496, 847),    S(488, 876),    S(479, 875),    S(491, 780),    S(536, 709),    S(520, 678),    //
    S(571, 654),    S(558, 728),    S(529, 782),    S(499, 824),    S(498, 825),    S(500, 771),    S(519, 692),    S(545, 615),    //
    S(550, 600),    S(585, 646),    S(574, 719),    S(546, 711),    S(543, 699),    S(537, 723),    S(552, 639),    S(529, 617),    //
    S(532, 489),    S(569, 501),    S(573, 566),    S(585, 604),    S(572, 631),    S(566, 595),    S(529, 634),    S(539, 614),    //
    S(515, 503),    S(546, 352),    S(569, 372),    S(584, 481),    S(579, 556),    S(577, 503),    S(566, 527),    S(535, 557),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-59, -322),   S(289, 176),    S(157, 138),    S(31, -30),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(234, -68),    S(352, 157),    S(204, 152),    S(122, -0),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(226, 28),     S(386, 101),    S(271, 105),    S(169, 1),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(84, -4),      S(339, 37),     S(187, 61),     S(122, 24),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -25),    S(238, 5),      S(164, 14),     S(46, 22),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-25, -13),    S(213, -4),     S(116, 7),      S(64, -11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-5, -15),     S(83, 35),      S(-1, 38),      S(-59, 13),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-118, -65),   S(-18, -21),    S(-120, -13),   S(-122, -86),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -19), S(-3, 17), S(-7, 19), S(0, 4), S(0, 1), S(-7, 18), S(-1, 18), }},
  {{ S(5, -6), S(-23, 27), S(-19, 21), S(-9, 3), S(-9, 3), S(-18, 25), S(-22, 35), }},
  {{ S(-13, 1), S(-24, 27), S(-23, 7), S(-19, -6), S(-18, -5), S(-22, 7), S(-22, 23), }},
  {{ S(0, -16), S(-17, -16), S(-8, -20), S(-3, -24), S(-5, -22), S(-9, -17), S(-13, -17), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(4, 22), S(-18, 32), S(-15, 22), S(-7, 10), S(-8, -6),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 4), S(-14, 13), S(-13, 11), S(-12, 12), S(-12, 6), S(-11, 2), S(-14, 11), }},
  {{ S(-3, 2), S(-11, 9), S(-17, 14), S(-14, 11), S(-14, 7), S(-16, 11), S(-10, 8), }},
  {{ S(-9, 7), S(-14, 4), S(-15, 11), S(-11, 11), S(-10, 10), S(-15, 9), S(-13, 5), }},
  {{ S(-10, 9), S(-15, 10), S(-15, 9), S(-11, 14), S(-9, 14), S(-15, 10), S(-16, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1189, 550, -31, 56
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(224);
inline VParam WINNABLE_BIAS = V(-657);

// Epoch duration: 7.77607s
// clang-format on
}  // namespace Clockwork
