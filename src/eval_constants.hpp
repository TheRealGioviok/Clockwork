#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(130, 208);
inline const PParam KNIGHT_MAT = S(564, 627);
inline const PParam BISHOP_MAT = S(596, 638);
inline const PParam ROOK_MAT   = S(471, 677);
inline const PParam QUEEN_MAT  = S(994, 324);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(50, 198);
inline const PParam ROOK_OPEN_VAL     = S(109, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 26);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(43, 48);
inline const PParam OUTPOST_BISHOP_VAL    = S(53, 41);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(31, 49);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -36);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, 1), S(37, 24), S(59, 50), S(137, 146), S(368, 213), S(533, 696),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 32), S(45, 28), S(58, 54), S(119, 141), S(434, 72),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-77, -107), S(-77, -86), S(-47, 12), S(18, 103), S(104, 247), S(289, 355),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(29, -36), S(28, -1), S(19, 31), S(6, 110), S(83, 194), S(259, 243),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -21), S(2, 25), S(2, -11), S(3, -42), S(-0, -123), S(-252, -199),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(1, 141), S(-20, 117), S(-13, 45), S(-4, 7), S(5, 6), S(42, 2), S(30, -11),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-332, -28), S(-45, 29), S(-34, 77), S(20, 81), S(44, 98), S(57, 100), S(36, 101),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(72, 6), S(137, 175), S(171, 266), S(199, 302), S(236, 320), S(259, 352), S(289, 352), S(317, 365), S(360, 293),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(103, 6), S(143, 173), S(190, 240), S(214, 288), S(236, 321), S(250, 346), S(258, 364), S(271, 372), S(277, 388), S(299, 370), S(306, 371), S(357, 317), S(360, 317), S(389, 276),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(324, 253), S(235, 420), S(257, 448), S(273, 459), S(282, 472), S(287, 484), S(292, 495), S(298, 499), S(302, 510), S(310, 513), S(319, 513), S(324, 519), S(329, 518), S(343, 491), S(428, 387),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(457, 233), S(592, 326), S(615, 439), S(634, 549), S(647, 594), S(655, 636), S(660, 665), S(666, 676), S(669, 696), S(671, 711), S(677, 714), S(680, 721), S(686, 717), S(687, 722), S(690, 718), S(688, 718), S(687, 717), S(693, 706), S(699, 695), S(701, 691), S(705, 670), S(721, 635), S(706, 643), S(702, 585), S(681, 582), S(677, 543), S(618, 572), S(625, 530),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(489, -225), S(90, -125), S(25, -35), S(10, 2), S(-7, 0), S(-8, -0), S(-17, 9), S(-44, 27), S(-48, 17),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -19), S(13, -17), S(12, -3), S(4, -7), S(-0, 88),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -17), S(5, -23), S(3, -10), S(4, -2), S(5, 286),
};

inline const PParam KS_NO_QUEEN = S(-86, -778);

inline const PParam KS_FLANK_ATTACK = S(1, -4);
inline const PParam KS_FLANK_DEFENSE = S(-5, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(5, -8);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, -4);

inline const PParam KS_WEAK_FLANK = S(4, 1);

inline const PParam PAWN_THREAT_KNIGHT = S(212, 93);
inline const PParam PAWN_THREAT_BISHOP = S(198, 133);
inline const PParam PAWN_THREAT_ROOK   = S(196, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(171, -9);

inline const PParam KNIGHT_THREAT_BISHOP = S(106, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 71);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -15);

inline const PParam BISHOP_THREAT_KNIGHT = S(101, 60);
inline const PParam BISHOP_THREAT_ROOK   = S(209, 129);
inline const PParam BISHOP_THREAT_QUEEN  = S(174, 89);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -33), S(-4, -4), S(-5, -13), S(-7, -22), S(-10, -31), S(-13, -37), S(-14, -47), S(-20, -48), S(-36, -42),
};

inline const PParam ROOK_LINEUP = S(12, 74);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(335, 307),    S(160, 396),    S(284, 382),    S(299, 287),    S(337, 235),    S(224, 333),    S(158, 379),    S(294, 303),    //
    S(120, 214),    S(155, 235),    S(177, 172),    S(148, 136),    S(141, 111),    S(107, 175),    S(86, 226),     S(43, 247),     //
    S(97, 161),     S(88, 171),     S(124, 119),    S(107, 109),    S(99, 100),     S(73, 130),     S(23, 180),     S(12, 203),     //
    S(67, 109),     S(51, 140),     S(84, 107),     S(73, 108),     S(49, 111),     S(38, 136),     S(-21, 174),    S(-21, 166),    //
    S(61, 87),      S(92, 94),      S(77, 131),     S(66, 134),     S(35, 130),     S(19, 140),     S(-21, 163),    S(-23, 152),    //
    S(72, 90),      S(154, 104),    S(132, 154),    S(90, 163),     S(60, 151),     S(38, 146),     S(10, 166),     S(-8, 165),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-203, -137),  S(-142, 199),   S(-34, -25),    S(116, 200),    S(41, 203),     S(-79, 183),    S(-256, 254),   S(-275, -36),   //
    S(86, 157),     S(106, 187),    S(206, 155),    S(205, 179),    S(202, 187),    S(137, 198),    S(86, 198),     S(73, 171),     //
    S(148, 156),    S(175, 143),    S(180, 216),    S(194, 218),    S(162, 244),    S(120, 238),    S(132, 176),    S(94, 175),     //
    S(219, 185),    S(224, 202),    S(218, 231),    S(208, 266),    S(217, 266),    S(180, 248),    S(177, 214),    S(169, 190),    //
    S(197, 184),    S(236, 159),    S(203, 220),    S(205, 240),    S(179, 244),    S(186, 228),    S(190, 180),    S(148, 196),    //
    S(145, 140),    S(157, 156),    S(154, 191),    S(165, 216),    S(160, 216),    S(134, 196),    S(132, 168),    S(106, 136),    //
    S(164, 144),    S(171, 142),    S(142, 152),    S(150, 179),    S(146, 177),    S(120, 133),    S(105, 165),    S(95, 79),      //
    S(98, 86),      S(147, 146),    S(160, 123),    S(177, 130),    S(160, 150),    S(126, 125),    S(117, 140),    S(79, 49),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(0, 298),      S(-6, 305),     S(-289, 361),   S(-140, 308),   S(-135, 304),   S(-153, 295),   S(-48, 291),    S(29, 275),     //
    S(109, 219),    S(69, 290),     S(95, 250),     S(36, 280),     S(61, 268),     S(86, 254),     S(130, 244),    S(110, 213),    //
    S(175, 233),    S(172, 249),    S(171, 267),    S(151, 271),    S(133, 266),    S(148, 264),    S(171, 239),    S(165, 221),    //
    S(158, 219),    S(185, 234),    S(189, 259),    S(186, 302),    S(221, 283),    S(170, 252),    S(179, 218),    S(148, 212),    //
    S(191, 174),    S(189, 216),    S(204, 243),    S(210, 270),    S(190, 281),    S(188, 261),    S(163, 228),    S(160, 193),    //
    S(207, 190),    S(229, 204),    S(237, 233),    S(196, 258),    S(187, 241),    S(198, 247),    S(212, 228),    S(158, 217),    //
    S(169, 157),    S(263, 168),    S(225, 188),    S(201, 209),    S(181, 216),    S(191, 190),    S(194, 183),    S(189, 178),    //
    S(202, 159),    S(188, 186),    S(196, 209),    S(212, 187),    S(197, 196),    S(198, 234),    S(198, 211),    S(193, 181),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(413, 412),    S(444, 425),    S(400, 442),    S(400, 412),    S(447, 407),    S(410, 417),    S(423, 428),    S(406, 433),    //
    S(300, 481),    S(380, 477),    S(442, 446),    S(382, 461),    S(430, 450),    S(391, 461),    S(334, 486),    S(324, 486),    //
    S(256, 478),    S(373, 456),    S(413, 418),    S(384, 417),    S(388, 436),    S(340, 462),    S(349, 461),    S(290, 492),    //
    S(230, 452),    S(306, 454),    S(336, 428),    S(309, 437),    S(346, 424),    S(309, 456),    S(311, 452),    S(246, 477),    //
    S(211, 385),    S(277, 400),    S(267, 412),    S(247, 412),    S(263, 418),    S(254, 439),    S(232, 433),    S(215, 431),    //
    S(229, 308),    S(296, 331),    S(287, 348),    S(270, 348),    S(284, 353),    S(253, 387),    S(263, 360),    S(228, 366),    //
    S(131, 316),    S(271, 277),    S(276, 303),    S(268, 327),    S(275, 331),    S(262, 342),    S(255, 323),    S(229, 335),    //
    S(199, 298),    S(223, 319),    S(280, 310),    S(294, 303),    S(296, 313),    S(276, 331),    S(274, 323),    S(257, 329),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(515, 545),    S(595, 492),    S(513, 588),    S(471, 647),    S(496, 609),    S(503, 586),    S(531, 507),    S(457, 586),    //
    S(503, 591),    S(494, 689),    S(459, 704),    S(333, 766),    S(366, 766),    S(407, 738),    S(457, 633),    S(462, 605),    //
    S(461, 629),    S(492, 664),    S(437, 734),    S(391, 757),    S(396, 756),    S(450, 685),    S(484, 616),    S(498, 543),    //
    S(497, 505),    S(483, 603),    S(431, 660),    S(414, 712),    S(419, 739),    S(452, 642),    S(499, 574),    S(486, 546),    //
    S(505, 467),    S(482, 535),    S(459, 591),    S(435, 639),    S(440, 677),    S(452, 636),    S(479, 560),    S(503, 500),    //
    S(492, 421),    S(519, 447),    S(512, 521),    S(492, 528),    S(488, 557),    S(493, 587),    S(508, 533),    S(496, 498),    //
    S(470, 304),    S(504, 313),    S(514, 368),    S(531, 427),    S(519, 472),    S(520, 454),    S(487, 500),    S(501, 477),    //
    S(458, 315),    S(489, 168),    S(512, 188),    S(528, 306),    S(525, 401),    S(530, 346),    S(524, 369),    S(496, 407),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-63, -137),   S(273, 298),    S(171, 293),    S(47, 180),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(199, 76),     S(317, 230),    S(181, 263),    S(126, 142),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(137, 129),    S(227, 195),    S(145, 209),    S(94, 136),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, 69),     S(115, 121),    S(12, 161),     S(-5, 156),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-110, -15),   S(16, 30),      S(-31, 76),     S(-107, 128),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-44, -61),    S(53, -24),     S(-28, 38),     S(-78, 83),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(27, -107),    S(62, -62),     S(-13, -12),    S(-81, 28),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-55, -146),   S(16, -104),    S(-74, -64),    S(-76, -82),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(25, 78), S(6, 77), S(5, 74), S(15, 48), S(15, 45), S(4, 76), S(7, 77), }},
  {{ S(10, 136), S(-20, 115), S(-11, 107), S(2, 83), S(3, 88), S(-10, 108), S(-18, 119), }},
  {{ S(9, 138), S(-7, 129), S(1, 110), S(7, 90), S(8, 89), S(1, 110), S(-5, 129), }},
  {{ S(16, 134), S(-3, 97), S(9, 103), S(14, 92), S(13, 93), S(8, 101), S(1, 100), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(4, -187), S(-19, 100), S(-16, 84), S(-7, 97), S(-4, 75),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 128), S(-15, 113), S(-15, 106), S(-13, 106), S(-14, 106), S(-14, 105), S(-15, 110), }},
  {{ S(1, 73), S(-6, 58), S(-17, 58), S(-14, 55), S(-15, 53), S(-16, 50), S(-6, 58), }},
  {{ S(-5, 86), S(-8, 68), S(-14, 73), S(-11, 73), S(-11, 67), S(-14, 69), S(-8, 69), }},
  {{ S(-6, 79), S(-13, 73), S(-17, 67), S(-12, 71), S(-10, 71), S(-17, 68), S(-15, 69), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1110, 1536, 7, 130
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(231);
inline VParam WINNABLE_BIAS = V(-646);

// Epoch duration: 9.41509s
// clang-format on
}  // namespace Clockwork
