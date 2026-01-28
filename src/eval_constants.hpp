#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(165, 156);
inline const PParam KNIGHT_MAT = S(828, 544);
inline const PParam BISHOP_MAT = S(791, 508);
inline const PParam ROOK_MAT   = S(646, 544);
inline const PParam QUEEN_MAT  = S(1488, 778);
inline const PParam TEMPO_VAL  = S(64, 13);

inline const PParam BISHOP_PAIR_VAL   = S(76, 161);
inline const PParam ROOK_OPEN_VAL     = S(107, -23);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 16);
inline const PParam SEE_CONTROL_VALUE = S(9, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-29, -73);

inline const PParam POTENTIAL_CHECKER_VAL = S(-58, -8);
inline const PParam OUTPOST_KNIGHT_VAL    = S(42, 47);
inline const PParam OUTPOST_BISHOP_VAL    = S(50, 32);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(45, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -22);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(35, 39);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(70, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(23, 11), S(51, 37), S(69, 68), S(171, 147), S(482, 182), S(666, 633),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(68, 39), S(56, 37), S(70, 66), S(160, 120), S(566, -14),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -98), S(-83, -78), S(-48, 3), S(20, 86), S(117, 205), S(318, 281),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(33, -31), S(32, -4), S(24, 22), S(18, 72), S(89, 137), S(189, 230),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(19, -33), S(2, 8), S(-4, -16), S(-12, -37), S(-29, -80), S(-284, -100),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(15, 108), S(-8, 88), S(-12, 37), S(-8, 7), S(-2, 5), S(34, 2), S(8, -7),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-335, -10), S(-32, 17), S(-11, 41), S(23, 71), S(38, 86), S(52, 90), S(27, 86),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-15, -91), S(78, 76), S(123, 149), S(155, 183), S(197, 197), S(221, 233), S(251, 230), S(283, 237), S(327, 179),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(83, -108), S(135, 89), S(199, 149), S(228, 195), S(252, 229), S(267, 252), S(273, 271), S(284, 281), S(290, 296), S(304, 290), S(316, 287), S(360, 253), S(361, 256), S(408, 218),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(326, 123), S(259, 296), S(286, 317), S(305, 325), S(316, 337), S(323, 348), S(329, 356), S(338, 357), S(344, 363), S(354, 365), S(365, 365), S(373, 365), S(378, 366), S(387, 354), S(485, 266),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(629, 186), S(722, 300), S(753, 395), S(774, 511), S(788, 567), S(798, 609), S(804, 642), S(812, 649), S(815, 673), S(819, 682), S(822, 691), S(827, 694), S(833, 688), S(835, 692), S(837, 689), S(837, 687), S(837, 684), S(839, 680), S(845, 667), S(858, 650), S(872, 626), S(897, 595), S(931, 557), S(1021, 463), S(1067, 412), S(1122, 377), S(1144, 350), S(1097, 359),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(532, -217), S(126, -137), S(41, -50), S(27, -11), S(4, -3), S(-20, 4), S(-25, 17), S(-42, 28), S(-45, -4),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -12), S(16, -16), S(14, -12), S(6, -9), S(3, 306),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -2), S(7, -10), S(6, -8), S(6, -6), S(7, 459),
};

inline const PParam PAWN_THREAT_KNIGHT = S(237, 68);
inline const PParam PAWN_THREAT_BISHOP = S(209, 121);
inline const PParam PAWN_THREAT_ROOK   = S(217, 87);
inline const PParam PAWN_THREAT_QUEEN  = S(181, -42);

inline const PParam KNIGHT_THREAT_BISHOP = S(122, 75);
inline const PParam KNIGHT_THREAT_ROOK   = S(257, 17);
inline const PParam KNIGHT_THREAT_QUEEN  = S(167, -39);

inline const PParam BISHOP_THREAT_KNIGHT = S(118, 41);
inline const PParam BISHOP_THREAT_ROOK   = S(247, 72);
inline const PParam BISHOP_THREAT_QUEEN  = S(202, 52);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -23), S(-3, -10), S(-5, -19), S(-10, -26), S(-16, -32), S(-22, -35), S(-26, -44), S(-32, -44), S(-43, -43),
};

inline const PParam ROOK_LINEUP = S(13, 74);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(315, 283),    S(179, 372),    S(309, 340),    S(328, 212),    S(352, 162),    S(272, 237),    S(213, 267),    S(309, 219),    //
    S(123, 184),    S(169, 221),    S(193, 142),    S(185, 88),     S(162, 76),     S(135, 120),    S(119, 160),    S(68, 174),     //
    S(94, 145),     S(89, 151),     S(122, 76),     S(124, 62),     S(111, 63),     S(79, 95),      S(43, 140),     S(28, 155),     //
    S(63, 107),     S(63, 133),     S(87, 76),      S(86, 69),      S(63, 74),      S(48, 99),      S(3, 144),      S(-6, 128),     //
    S(54, 84),      S(103, 96),     S(77, 119),     S(75, 104),     S(46, 106),     S(23, 111),     S(4, 129),      S(-12, 113),    //
    S(76, 87),      S(175, 105),    S(158, 145),    S(112, 131),    S(81, 124),     S(57, 122),     S(38, 138),     S(9, 129),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-338, -14),   S(-246, 171),   S(-341, 242),   S(23, 138),     S(-35, 134),    S(-166, 128),   S(-339, 167),   S(-403, 61),    //
    S(37, 115),     S(96, 117),     S(165, 85),     S(166, 102),    S(151, 119),    S(81, 113),     S(56, 129),     S(22, 103),     //
    S(123, 90),     S(150, 126),    S(160, 154),    S(154, 152),    S(127, 159),    S(63, 175),     S(84, 117),     S(51, 110),     //
    S(197, 109),    S(200, 127),    S(196, 154),    S(191, 175),    S(194, 176),    S(140, 170),    S(135, 136),    S(134, 106),    //
    S(191, 105),    S(216, 98),     S(193, 141),    S(189, 158),    S(167, 161),    S(158, 152),    S(152, 107),    S(127, 103),    //
    S(125, 84),     S(150, 86),     S(140, 120),    S(154, 142),    S(151, 140),    S(110, 125),    S(101, 90),     S(71, 66),      //
    S(142, 71),     S(163, 74),     S(131, 81),     S(138, 99),     S(128, 97),     S(93, 66),      S(93, 73),      S(61, 12),      //
    S(75, 51),      S(117, 107),    S(137, 70),     S(151, 64),     S(135, 78),     S(96, 58),      S(83, 85),      S(35, 27),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-20, 250),    S(-44, 244),    S(-299, 288),   S(-199, 264),   S(-188, 282),   S(-248, 295),   S(-106, 288),   S(-2, 254),     //
    S(111, 166),    S(60, 231),     S(80, 203),     S(18, 234),     S(23, 235),     S(66, 220),     S(100, 207),    S(84, 187),     //
    S(187, 176),    S(194, 197),    S(191, 211),    S(168, 201),    S(139, 198),    S(146, 201),    S(168, 192),    S(153, 166),    //
    S(165, 165),    S(193, 181),    S(193, 201),    S(191, 230),    S(222, 212),    S(152, 199),    S(161, 170),    S(120, 171),    //
    S(187, 130),    S(204, 160),    S(212, 180),    S(215, 200),    S(195, 211),    S(175, 198),    S(137, 179),    S(135, 142),    //
    S(212, 135),    S(245, 147),    S(259, 165),    S(209, 193),    S(200, 176),    S(192, 184),    S(197, 161),    S(142, 164),    //
    S(189, 100),    S(278, 117),    S(241, 127),    S(209, 150),    S(189, 153),    S(190, 129),    S(185, 133),    S(182, 118),    //
    S(206, 118),    S(194, 143),    S(198, 166),    S(211, 128),    S(206, 131),    S(203, 175),    S(199, 151),    S(183, 142),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(481, 336),    S(527, 337),    S(478, 356),    S(481, 344),    S(479, 335),    S(447, 343),    S(447, 354),    S(433, 364),    //
    S(373, 396),    S(472, 372),    S(542, 347),    S(482, 362),    S(471, 366),    S(448, 372),    S(376, 402),    S(350, 413),    //
    S(349, 383),    S(478, 345),    S(519, 330),    S(496, 327),    S(459, 341),    S(410, 367),    S(409, 368),    S(329, 409),    //
    S(340, 361),    S(434, 353),    S(467, 338),    S(447, 337),    S(437, 344),    S(395, 366),    S(381, 365),    S(303, 391),    //
    S(312, 318),    S(384, 321),    S(381, 334),    S(357, 338),    S(342, 349),    S(330, 365),    S(300, 359),    S(273, 361),    //
    S(293, 279),    S(362, 286),    S(357, 306),    S(342, 304),    S(337, 304),    S(310, 329),    S(298, 314),    S(258, 326),    //
    S(200, 295),    S(328, 245),    S(342, 266),    S(336, 280),    S(324, 282),    S(312, 290),    S(294, 275),    S(261, 293),    //
    S(252, 290),    S(280, 300),    S(340, 272),    S(356, 265),    S(342, 276),    S(323, 292),    S(310, 289),    S(287, 309),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(624, 519),    S(672, 489),    S(637, 542),    S(586, 627),    S(597, 596),    S(594, 577),    S(623, 503),    S(553, 564),    //
    S(624, 574),    S(596, 655),    S(579, 692),    S(436, 784),    S(446, 770),    S(514, 714),    S(552, 613),    S(558, 591),    //
    S(599, 613),    S(649, 631),    S(592, 711),    S(545, 739),    S(519, 730),    S(546, 685),    S(594, 590),    S(593, 541),    //
    S(635, 544),    S(651, 607),    S(592, 673),    S(576, 720),    S(563, 723),    S(563, 653),    S(615, 564),    S(597, 534),    //
    S(643, 522),    S(648, 561),    S(622, 621),    S(586, 675),    S(585, 666),    S(584, 623),    S(595, 557),    S(616, 485),    //
    S(625, 462),    S(662, 504),    S(665, 559),    S(634, 557),    S(625, 554),    S(622, 570),    S(626, 503),    S(603, 478),    //
    S(607, 358),    S(645, 353),    S(655, 410),    S(670, 446),    S(653, 476),    S(645, 444),    S(609, 484),    S(613, 465),    //
    S(579, 384),    S(612, 233),    S(636, 241),    S(658, 335),    S(657, 398),    S(650, 357),    S(637, 384),    S(596, 429),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-237, -280),  S(242, 67),     S(167, 38),     S(-141, 21),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(293, -115),   S(359, 81),     S(195, 99),     S(92, 8),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(219, 20),     S(420, 53),     S(292, 67),     S(140, 7),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(6, 24),       S(317, 30),     S(143, 52),     S(56, 24),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-85, 15),     S(203, 10),     S(138, 16),     S(29, 19),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-57, 21),     S(186, 2),      S(96, 16),      S(68, -12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(4, -8),       S(88, 23),      S(4, 33),       S(-42, 3),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-118, -35),   S(-11, -12),    S(-108, 2),     S(-117, -62),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(28, -24), S(9, 9), S(4, 17), S(11, 3), S(11, 2), S(5, 17), S(11, 14), }},
  {{ S(18, -6), S(-13, 33), S(-10, 27), S(-1, 7), S(-0, 11), S(-9, 35), S(-12, 46), }},
  {{ S(-12, 8), S(-25, 33), S(-25, 15), S(-21, -0), S(-21, 1), S(-24, 17), S(-23, 32), }},
  {{ S(14, -14), S(-5, -20), S(2, -21), S(7, -25), S(7, -22), S(1, -17), S(-1, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 16), S(-16, 32), S(-13, 20), S(-5, 7), S(-9, -5),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 8), S(-12, 14), S(-11, 13), S(-10, 7), S(-11, 3), S(-10, 3), S(-12, 11), }},
  {{ S(-1, 6), S(-9, 12), S(-17, 18), S(-13, 6), S(-13, 4), S(-15, 13), S(-9, 10), }},
  {{ S(-7, 7), S(-12, 0), S(-13, 8), S(-8, 6), S(-8, 4), S(-13, 6), S(-11, 2), }},
  {{ S(-8, 8), S(-14, 8), S(-15, 7), S(-9, 11), S(-8, 11), S(-15, 6), S(-16, 6), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1074, 414, -61, 47
);
// Epoch duration: 9.30939s
// clang-format on
}  // namespace Clockwork
