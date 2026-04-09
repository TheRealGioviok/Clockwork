#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(132, 205);
inline const PParam KNIGHT_MAT = S(584, 593);
inline const PParam BISHOP_MAT = S(613, 619);
inline const PParam ROOK_MAT   = S(490, 678);
inline const PParam QUEEN_MAT  = S(933, 1169);
inline const PParam TEMPO_VAL  = S(59, 18);

inline const PParam BISHOP_PAIR_VAL   = S(46, 208);
inline const PParam ROOK_OPEN_VAL     = S(108, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 25);
inline const PParam MINOR_BEHIND_PAWN = S(12, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -19);

inline const PParam POTENTIAL_CHECKER_VAL = S(8, 8);
inline const PParam OUTPOST_KNIGHT_VAL    = S(40, 57);
inline const PParam OUTPOST_BISHOP_VAL    = S(61, 31);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 4);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(50, -24);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(29, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -1), S(36, 25), S(59, 47), S(136, 139), S(397, 189), S(574, 654),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 34), S(45, 26), S(61, 50), S(122, 139), S(429, 78),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -122), S(-73, -94), S(-50, 17), S(12, 116), S(111, 253), S(285, 367),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(32, -42), S(28, -5), S(18, 30), S(5, 110), S(76, 208), S(255, 261),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -23), S(6, 20), S(2, -14), S(2, -41), S(5, -131), S(-242, -219),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-8, 142), S(-18, 113), S(-8, 42), S(-1, 8), S(5, 9), S(40, 5), S(29, -5),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-296, -80), S(-47, 13), S(-28, 61), S(14, 95), S(36, 115), S(50, 119), S(28, 117),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(74, 13), S(138, 176), S(170, 268), S(198, 301), S(236, 316), S(260, 345), S(291, 338), S(321, 345), S(375, 250),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(107, -2), S(145, 165), S(193, 228), S(216, 276), S(239, 307), S(254, 331), S(261, 347), S(274, 354), S(282, 366), S(306, 345), S(314, 342), S(369, 281), S(370, 287), S(413, 218),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(327, 255), S(242, 414), S(265, 440), S(281, 451), S(291, 464), S(295, 476), S(300, 487), S(307, 490), S(311, 500), S(319, 504), S(327, 506), S(332, 511), S(337, 509), S(354, 479), S(442, 370),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(497, 357), S(626, 486), S(650, 598), S(668, 714), S(682, 757), S(689, 803), S(694, 834), S(702, 845), S(704, 868), S(707, 884), S(712, 891), S(715, 899), S(722, 897), S(722, 905), S(725, 902), S(723, 906), S(723, 902), S(727, 893), S(731, 883), S(729, 882), S(728, 866), S(743, 828), S(723, 840), S(709, 792), S(676, 787), S(672, 758), S(610, 774), S(630, 730),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(478, -194), S(91, -86), S(26, -14), S(14, 18), S(-3, 12), S(-16, 7), S(-25, 9), S(-48, 15), S(-33, -30),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -5), S(7, 26), S(7, 16), S(2, 3), S(-3, -2),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -11), S(2, 5), S(2, 2), S(2, 2), S(1, 1),
};

inline const PParam KS_NO_QUEEN = S(-41, -904);

inline const PParam KS_FLANK_ATTACK = S(1, -6);
inline const PParam KS_FLANK_DEFENSE = S(-2, -4);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -3);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 2>, 4> KS_SAFE_CHECKS = {{
  {{ S(1, 9), S(2, -34), }},
  {{ S(3, 6), S(3, -7), }},
  {{ S(4, 6), S(5, 20), }},
  {{ S(6, 23), S(10, -67), }},
}};

inline const PParam PAWN_THREAT_KNIGHT = S(216, 84);
inline const PParam PAWN_THREAT_BISHOP = S(199, 128);
inline const PParam PAWN_THREAT_ROOK   = S(195, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(169, -1);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 69);
inline const PParam KNIGHT_THREAT_QUEEN  = S(149, -11);

inline const PParam BISHOP_THREAT_KNIGHT = S(104, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(178, 85);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -32), S(-3, -4), S(-5, -12), S(-7, -21), S(-11, -30), S(-14, -35), S(-16, -45), S(-21, -46), S(-36, -41),
};

inline const PParam ROOK_LINEUP = S(14, 69);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(319, 316),    S(151, 410),    S(276, 374),    S(269, 319),    S(323, 246),    S(228, 320),    S(165, 358),    S(281, 310),    //
    S(120, 194),    S(150, 226),    S(166, 178),    S(135, 139),    S(130, 110),    S(107, 151),    S(87, 200),     S(45, 225),     //
    S(97, 161),     S(82, 175),     S(116, 131),    S(102, 108),    S(95, 94),      S(74, 115),     S(28, 160),     S(20, 182),     //
    S(65, 113),     S(54, 144),     S(90, 116),     S(76, 106),     S(53, 105),     S(45, 121),     S(-14, 156),    S(-13, 147),    //
    S(61, 82),      S(101, 83),     S(88, 124),     S(75, 126),     S(42, 119),     S(28, 124),     S(-10, 141),    S(-14, 133),    //
    S(73, 91),      S(154, 93),     S(127, 136),    S(94, 159),     S(67, 146),     S(46, 133),     S(17, 149),     S(-1, 149),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-191, -147),  S(-120, 182),   S(-149, 107),   S(123, 172),    S(52, 174),     S(-87, 190),    S(-257, 258),   S(-262, -41),   //
    S(92, 153),     S(127, 171),    S(220, 136),    S(210, 149),    S(207, 161),    S(149, 182),    S(101, 188),    S(76, 173),     //
    S(155, 148),    S(178, 142),    S(185, 208),    S(194, 199),    S(162, 230),    S(128, 240),    S(138, 171),    S(103, 162),    //
    S(231, 168),    S(233, 185),    S(228, 218),    S(221, 244),    S(233, 252),    S(189, 243),    S(188, 204),    S(180, 177),    //
    S(210, 168),    S(250, 149),    S(217, 212),    S(224, 233),    S(193, 239),    S(196, 229),    S(200, 172),    S(154, 190),    //
    S(146, 142),    S(162, 157),    S(157, 200),    S(174, 220),    S(165, 221),    S(137, 205),    S(137, 171),    S(110, 133),    //
    S(171, 141),    S(172, 140),    S(145, 158),    S(154, 182),    S(152, 179),    S(127, 132),    S(115, 154),    S(104, 66),     //
    S(98, 90),      S(143, 155),    S(166, 125),    S(187, 129),    S(166, 152),    S(132, 124),    S(120, 142),    S(82, 48),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(14, 280),     S(16, 276),     S(-277, 341),   S(-128, 280),   S(-134, 291),   S(-141, 279),   S(-37, 279),    S(34, 272),     //
    S(126, 203),    S(87, 273),     S(114, 221),    S(45, 248),     S(70, 241),     S(90, 246),     S(141, 234),    S(112, 216),    //
    S(181, 217),    S(175, 241),    S(187, 241),    S(165, 239),    S(143, 241),    S(160, 247),    S(168, 240),    S(168, 218),    //
    S(171, 200),    S(193, 214),    S(193, 242),    S(191, 282),    S(228, 267),    S(171, 243),    S(187, 204),    S(152, 208),    //
    S(199, 160),    S(202, 198),    S(212, 229),    S(218, 257),    S(195, 272),    S(199, 249),    S(169, 220),    S(167, 185),    //
    S(217, 172),    S(240, 189),    S(247, 220),    S(206, 247),    S(197, 229),    S(206, 237),    S(223, 216),    S(165, 204),    //
    S(179, 143),    S(271, 157),    S(232, 183),    S(212, 200),    S(189, 209),    S(201, 180),    S(201, 172),    S(199, 164),    //
    S(207, 149),    S(185, 187),    S(199, 207),    S(224, 180),    S(207, 188),    S(205, 227),    S(206, 200),    S(198, 172),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(419, 388),    S(456, 397),    S(409, 415),    S(415, 377),    S(462, 368),    S(417, 384),    S(423, 400),    S(398, 415),    //
    S(297, 465),    S(381, 462),    S(442, 426),    S(375, 442),    S(422, 431),    S(392, 434),    S(324, 473),    S(309, 478),    //
    S(248, 462),    S(366, 440),    S(403, 403),    S(376, 395),    S(377, 418),    S(336, 438),    S(339, 441),    S(274, 480),    //
    S(226, 426),    S(302, 429),    S(332, 398),    S(304, 408),    S(340, 399),    S(304, 427),    S(299, 434),    S(232, 460),    //
    S(207, 353),    S(275, 368),    S(267, 379),    S(246, 377),    S(255, 395),    S(247, 412),    S(220, 413),    S(203, 409),    //
    S(219, 291),    S(287, 316),    S(281, 329),    S(266, 326),    S(276, 337),    S(247, 366),    S(251, 347),    S(213, 354),    //
    S(124, 299),    S(253, 265),    S(270, 284),    S(265, 307),    S(270, 311),    S(258, 318),    S(246, 306),    S(216, 320),    //
    S(189, 278),    S(210, 303),    S(273, 291),    S(287, 284),    S(287, 296),    S(268, 310),    S(264, 304),    S(245, 311),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(569, 616),    S(659, 559),    S(557, 699),    S(501, 788),    S(523, 762),    S(548, 689),    S(576, 593),    S(510, 658),    //
    S(545, 652),    S(543, 740),    S(492, 809),    S(353, 899),    S(396, 887),    S(443, 832),    S(507, 685),    S(501, 680),    //
    S(503, 691),    S(518, 741),    S(455, 838),    S(414, 854),    S(424, 867),    S(477, 784),    S(519, 693),    S(534, 616),    //
    S(520, 594),    S(501, 686),    S(447, 757),    S(432, 817),    S(441, 839),    S(476, 737),    S(519, 664),    S(511, 626),    //
    S(519, 572),    S(496, 619),    S(471, 676),    S(445, 749),    S(451, 790),    S(479, 722),    S(504, 647),    S(530, 580),    //
    S(510, 511),    S(538, 516),    S(527, 587),    S(506, 609),    S(505, 637),    S(510, 675),    S(536, 607),    S(524, 584),    //
    S(492, 381),    S(522, 371),    S(529, 445),    S(550, 483),    S(539, 537),    S(542, 527),    S(513, 568),    S(532, 545),    //
    S(476, 400),    S(501, 262),    S(533, 260),    S(554, 353),    S(548, 445),    S(551, 407),    S(546, 436),    S(520, 472),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(52, -324),    S(415, 165),    S(289, 130),    S(170, 17),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(334, -54),    S(427, 184),    S(273, 176),    S(198, 60),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(263, 34),     S(337, 148),    S(244, 143),    S(183, 55),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(75, 2),       S(232, 80),     S(115, 109),    S(69, 103),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-84, -14),    S(62, 48),      S(15, 84),      S(-79, 131),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-66, -30),    S(51, 20),      S(-18, 63),     S(-75, 104),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-2, -75),     S(38, -10),     S(-24, 28),     S(-87, 70),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-69, -141),   S(-6, -83),     S(-88, -45),    S(-79, -57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(13, 79), S(-2, 131), S(-0, 107), S(6, 98), S(5, 98), S(-1, 105), S(-1, 126), }},
  {{ S(3, -157), S(-13, -157), S(-10, -136), S(-5, -120), S(-5, -117), S(-10, -133), S(-12, -155), }},
  {{ S(-1, 38), S(-7, -1), S(-6, 62), S(-4, 64), S(-3, 64), S(-7, 67), S(-7, 0), }},
  {{ S(3, 168), S(-6, 145), S(-3, 218), S(1, 205), S(0, 196), S(-4, 216), S(-5, 164), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-3, 44), S(-14, -1), S(-15, 26), S(-10, 43), S(-5, -8),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 7), S(-12, 15), S(-13, 22), S(-11, 13), S(-11, 11), S(-12, 22), S(-12, 19), }},
  {{ S(-1, -18), S(-8, 4), S(-15, 14), S(-11, -1), S(-11, 5), S(-13, 10), S(-7, 3), }},
  {{ S(-9, 18), S(-12, 34), S(-15, 38), S(-11, 19), S(-10, 4), S(-14, 32), S(-11, 32), }},
  {{ S(-8, -33), S(-12, -13), S(-16, 7), S(-12, 9), S(-11, 19), S(-15, -3), S(-13, -10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1854, 372, -23, 37
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(126);
inline VParam WINNABLE_PAWN_ENDGAME = V(216);
inline VParam WINNABLE_BIAS = V(-655);

// Epoch duration: 11.0405s
// clang-format on
}  // namespace Clockwork
