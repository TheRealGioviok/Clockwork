#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(172, 175);
inline const PParam KNIGHT_MAT = S(612, 401);
inline const PParam BISHOP_MAT = S(580, 335);
inline const PParam ROOK_MAT   = S(634, 561);
inline const PParam QUEEN_MAT  = S(1339, 795);
inline const PParam TEMPO_VAL  = S(59, 16);

inline const PParam BISHOP_PAIR_VAL   = S(78, 183);
inline const PParam ROOK_OPEN_VAL     = S(101, -27);
inline const PParam ROOK_SEMIOPEN_VAL = S(36, 15);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -77);

inline const PParam POTENTIAL_CHECKER_VAL = S(-66, -8);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 27);
inline const PParam OUTPOST_BISHOP_VAL    = S(72, -1);

inline const PParam SUPER_KNIGHT_OUTPOST_VAL = S(-0, 33);
inline const PParam SUPER_BISHOP_OUTPOST_VAL = S(-36, 121);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(48, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 31);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 19), S(62, 30), S(76, 70), S(186, 145), S(538, 262), S(944, 1142),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(66, 40), S(60, 31), S(67, 58), S(150, 121), S(688, -83),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-78, -91), S(-77, -70), S(-51, 6), S(25, 75), S(89, 197), S(293, 304),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(32, -2), S(20, 28), S(27, 72), S(106, 142), S(152, 291),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -43), S(-1, 6), S(-3, -21), S(3, -43), S(-3, -88), S(-212, -130),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 113), S(-14, 85), S(-7, 32), S(2, 4), S(11, 8), S(38, 7), S(17, -5),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-272, -19), S(-34, 18), S(-13, 45), S(29, 55), S(32, 82), S(50, 84), S(3, 103),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-39, -61), S(69, 100), S(126, 152), S(169, 186), S(216, 200), S(244, 238), S(281, 233), S(316, 235), S(362, 178),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-39, -170), S(33, 13), S(104, 78), S(138, 129), S(166, 162), S(182, 184), S(199, 200), S(217, 207), S(235, 211), S(248, 208), S(272, 196), S(336, 152), S(363, 132), S(423, 99),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(22, 129), S(175, 279), S(227, 343), S(260, 352), S(285, 377), S(299, 399), S(317, 411), S(336, 417), S(352, 430), S(369, 439), S(386, 442), S(397, 445), S(417, 448), S(428, 434), S(572, 309),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(28, 22), S(510, -134), S(600, 21), S(653, 225), S(660, 431), S(696, 537), S(698, 647), S(723, 659), S(727, 715), S(739, 739), S(747, 764), S(752, 779), S(770, 770), S(780, 781), S(786, 775), S(799, 770), S(805, 760), S(804, 766), S(829, 723), S(851, 684), S(868, 663), S(913, 595), S(925, 587), S(1088, 409), S(1124, 365), S(1361, 211), S(1185, 298), S(1428, 166),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(644, -109), S(250, -194), S(119, -87), S(81, -37), S(32, -19), S(-31, 5), S(-78, 47), S(-126, 69), S(-161, 47),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(213, 236), S(315, 190), S(388, 132),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(373, 389), S(225, 249), S(143, 78),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(414, 433), S(513, 417), S(535, 431), S(614, 467), S(686, 440),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(1033, 1003), S(716, 813), S(424, 618), S(207, 352), S(108, 38), S(31, -330),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-110, 64), S(8, -15), S(-181, -134), S(33, 33), S(-278, -206),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-27, 23), S(-21, 18), S(-25, 14), S(-15, 9), S(-22, -8),
};

inline const PParam PAWN_THREAT_KNIGHT = S(234, 62);
inline const PParam PAWN_THREAT_BISHOP = S(204, 105);
inline const PParam PAWN_THREAT_ROOK   = S(199, 56);
inline const PParam PAWN_THREAT_QUEEN  = S(175, -53);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 71);
inline const PParam KNIGHT_THREAT_ROOK   = S(245, 5);
inline const PParam KNIGHT_THREAT_QUEEN  = S(161, -69);

inline const PParam BISHOP_THREAT_KNIGHT = S(111, 35);
inline const PParam BISHOP_THREAT_ROOK   = S(244, 57);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 54);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-0, -12), S(-3, -6), S(-3, -16), S(-8, -27), S(-14, -32), S(-19, -40), S(-20, -47), S(-26, -42), S(-34, -49),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(247, 317),    S(213, 378),    S(297, 340),    S(361, 220),    S(309, 214),    S(300, 275),    S(188, 300),    S(267, 264),    //
    S(136, 216),    S(228, 255),    S(207, 201),    S(214, 142),    S(176, 121),    S(126, 166),    S(91, 208),     S(55, 204),     //
    S(92, 166),     S(101, 178),    S(113, 138),    S(108, 121),    S(97, 114),     S(61, 116),     S(22, 162),     S(4, 178),      //
    S(86, 106),     S(98, 141),     S(96, 108),     S(80, 110),     S(58, 99),      S(41, 106),     S(-10, 156),    S(-28, 143),    //
    S(82, 78),      S(141, 87),     S(90, 134),     S(66, 132),     S(47, 122),     S(10, 118),     S(-9, 132),     S(-31, 125),    //
    S(81, 89),      S(205, 99),     S(157, 138),    S(109, 151),    S(77, 135),     S(48, 125),     S(22, 150),     S(-12, 137),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-290, -39),   S(-237, 177),   S(-348, 351),   S(-18, 188),    S(-150, 215),   S(-217, 211),   S(-459, 202),   S(-429, 96),    //
    S(111, 116),    S(178, 130),    S(271, 70),     S(219, 131),    S(226, 135),    S(156, 117),    S(115, 125),    S(95, 78),      //
    S(164, 92),     S(190, 147),    S(272, 145),    S(226, 167),    S(223, 158),    S(151, 163),    S(148, 130),    S(67, 129),     //
    S(212, 130),    S(198, 158),    S(215, 173),    S(196, 198),    S(209, 183),    S(176, 175),    S(163, 124),    S(143, 125),    //
    S(205, 113),    S(229, 116),    S(215, 151),    S(195, 160),    S(183, 171),    S(188, 160),    S(166, 127),    S(154, 64),     //
    S(133, 89),     S(162, 81),     S(155, 103),    S(167, 147),    S(175, 142),    S(120, 117),    S(127, 77),     S(89, 68),      //
    S(142, 100),    S(164, 73),     S(145, 82),     S(144, 101),    S(132, 94),     S(103, 74),     S(116, 59),     S(59, -10),     //
    S(91, 51),      S(127, 97),     S(149, 71),     S(158, 77),     S(148, 85),     S(101, 55),     S(87, 79),      S(40, 25),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-89, 197),    S(-107, 176),   S(-352, 202),   S(-227, 213),   S(-184, 217),   S(-345, 241),   S(-85, 217),    S(-41, 195),    //
    S(86, 84),      S(72, 156),     S(88, 141),     S(55, 148),     S(35, 161),     S(87, 147),     S(66, 137),     S(30, 140),     //
    S(122, 137),    S(162, 126),    S(229, 138),    S(159, 137),    S(131, 143),    S(114, 150),    S(181, 118),    S(90, 134),     //
    S(127, 97),     S(126, 137),    S(163, 136),    S(165, 160),    S(176, 157),    S(114, 155),    S(111, 128),    S(72, 131),     //
    S(121, 74),     S(141, 109),    S(149, 126),    S(151, 146),    S(145, 161),    S(112, 149),    S(94, 113),     S(81, 72),      //
    S(144, 76),     S(191, 86),     S(201, 98),     S(136, 141),    S(123, 144),    S(127, 137),    S(152, 95),     S(116, 77),     //
    S(136, 41),     S(200, 55),     S(171, 68),     S(141, 99),     S(128, 86),     S(129, 76),     S(111, 89),     S(126, 29),     //
    S(136, 57),     S(121, 106),    S(136, 106),    S(146, 72),     S(154, 62),     S(143, 107),    S(138, 77),     S(117, 76),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(438, 345),    S(507, 343),    S(434, 373),    S(431, 370),    S(444, 357),    S(395, 369),    S(407, 370),    S(413, 375),    //
    S(351, 399),    S(434, 377),    S(505, 357),    S(427, 402),    S(450, 387),    S(401, 394),    S(344, 410),    S(339, 414),    //
    S(330, 382),    S(474, 343),    S(499, 341),    S(496, 340),    S(457, 346),    S(389, 383),    S(411, 368),    S(294, 416),    //
    S(306, 372),    S(381, 367),    S(408, 361),    S(426, 328),    S(404, 346),    S(348, 390),    S(333, 388),    S(260, 396),    //
    S(245, 323),    S(325, 329),    S(308, 348),    S(291, 349),    S(293, 342),    S(276, 380),    S(250, 375),    S(228, 366),    //
    S(224, 301),    S(297, 277),    S(292, 306),    S(272, 307),    S(292, 286),    S(244, 339),    S(243, 321),    S(219, 319),    //
    S(165, 310),    S(267, 250),    S(288, 266),    S(290, 271),    S(285, 274),    S(266, 290),    S(248, 266),    S(216, 283),    //
    S(201, 308),    S(229, 315),    S(283, 281),    S(306, 265),    S(294, 280),    S(282, 291),    S(266, 282),    S(249, 299),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(579, 572),    S(619, 534),    S(617, 542),    S(492, 674),    S(564, 591),    S(519, 613),    S(594, 527),    S(530, 556),    //
    S(567, 617),    S(496, 714),    S(484, 761),    S(382, 792),    S(411, 741),    S(428, 736),    S(477, 655),    S(515, 592),    //
    S(525, 644),    S(602, 641),    S(531, 719),    S(507, 729),    S(470, 710),    S(446, 713),    S(535, 605),    S(507, 578),    //
    S(590, 551),    S(579, 620),    S(542, 658),    S(531, 717),    S(525, 698),    S(519, 639),    S(561, 544),    S(554, 517),    //
    S(556, 580),    S(589, 545),    S(562, 613),    S(527, 665),    S(523, 658),    S(531, 620),    S(546, 539),    S(547, 489),    //
    S(572, 428),    S(597, 485),    S(602, 546),    S(550, 560),    S(567, 525),    S(574, 532),    S(585, 462),    S(556, 467),    //
    S(562, 330),    S(600, 238),    S(594, 361),    S(608, 426),    S(581, 450),    S(598, 384),    S(574, 447),    S(554, 447),    //
    S(508, 419),    S(572, 168),    S(576, 168),    S(603, 251),    S(604, 345),    S(604, 297),    S(591, 340),    S(537, 417),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-257, -298),  S(41, 22),      S(-106, 75),    S(-211, 102),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(131, -66),    S(102, 91),     S(147, 69),     S(255, -0),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-58, 91),     S(194, 74),     S(261, 32),     S(238, -9),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-265, 112),   S(182, 26),     S(192, 15),     S(133, -2),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-237, 66),    S(113, -6),     S(168, -22),    S(80, 12),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-171, 48),    S(175, -44),    S(133, -18),    S(104, -3),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-11, -14),    S(177, -58),    S(129, -35),    S(65, -2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-211, 7),     S(-30, -12),    S(-108, 10),    S(-122, 9),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};
// Epoch duration: 6.87929s
// clang-format on
}  // namespace Clockwork
