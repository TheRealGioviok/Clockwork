#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(154, 216);
inline const PParam KNIGHT_MAT = S(653, 699);
inline const PParam BISHOP_MAT = S(698, 708);
inline const PParam ROOK_MAT   = S(512, 711);
inline const PParam QUEEN_MAT  = S(1268, 1160);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(60, 206);
inline const PParam ROOK_OPEN_VAL     = S(108, -10);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 25);
inline const PParam MINOR_BEHIND_PAWN = S(11, 44);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-23, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(41, 60);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(45, 8);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(50, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 63);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(74, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, 2), S(44, 26), S(62, 51), S(141, 149), S(439, 186), S(576, 803),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(61, 32), S(50, 25), S(60, 53), S(131, 136), S(429, 83),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-84, -127), S(-75, -111), S(-48, 8), S(14, 112), S(106, 273), S(296, 390),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(44, -50), S(31, 0), S(15, 40), S(-3, 118), S(74, 217), S(227, 316),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -24), S(-1, 28), S(-10, -3), S(-1, -37), S(-17, -111), S(-261, -220),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(4, 152), S(-15, 122), S(-9, 49), S(-6, 11), S(5, 6), S(39, 6), S(13, -3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-325, -57), S(-31, 27), S(-24, 62), S(16, 98), S(36, 116), S(55, 123), S(37, 112),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(77, -33), S(146, 165), S(184, 254), S(213, 293), S(253, 310), S(278, 342), S(312, 341), S(342, 351), S(394, 264),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(101, -40), S(144, 166), S(198, 233), S(225, 284), S(251, 316), S(267, 340), S(278, 359), S(290, 368), S(296, 385), S(319, 372), S(333, 370), S(383, 319), S(428, 297), S(427, 274),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(338, 262), S(271, 450), S(297, 473), S(313, 487), S(323, 503), S(329, 512), S(336, 524), S(344, 528), S(351, 537), S(362, 539), S(372, 543), S(378, 546), S(387, 545), S(406, 514), S(483, 417),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(591, 473), S(701, 576), S(732, 685), S(750, 798), S(764, 856), S(774, 900), S(777, 941), S(786, 955), S(791, 973), S(796, 982), S(801, 991), S(808, 990), S(814, 994), S(819, 991), S(817, 997), S(818, 999), S(821, 992), S(821, 991), S(827, 982), S(837, 973), S(842, 952), S(876, 905), S(857, 913), S(860, 863), S(843, 851), S(832, 825), S(770, 858), S(798, 851),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(293, 74), S(127, -117), S(37, -34), S(24, -2), S(-0, 1), S(-18, -2), S(-32, 14), S(-54, 23), S(-47, -12),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(13, -10), S(17, -16), S(14, -12), S(6, -8), S(2, 211),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -1), S(8, -12), S(6, -10), S(6, -5), S(6, 483),
};

inline const PParam PAWN_THREAT_KNIGHT = S(228, 92);
inline const PParam PAWN_THREAT_BISHOP = S(200, 155);
inline const PParam PAWN_THREAT_ROOK   = S(197, 139);
inline const PParam PAWN_THREAT_QUEEN  = S(188, -39);

inline const PParam KNIGHT_THREAT_BISHOP = S(111, 99);
inline const PParam KNIGHT_THREAT_ROOK   = S(250, 46);
inline const PParam KNIGHT_THREAT_QUEEN  = S(148, -5);

inline const PParam BISHOP_THREAT_KNIGHT = S(113, 56);
inline const PParam BISHOP_THREAT_ROOK   = S(236, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(201, 69);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -31), S(-3, -5), S(-5, -14), S(-9, -22), S(-13, -32), S(-17, -38), S(-21, -42), S(-25, -48), S(-46, -35),
};

inline const PParam ROOK_LINEUP = S(10, 77);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(323, 347),    S(185, 468),    S(283, 434),    S(337, 284),    S(350, 231),    S(292, 288),    S(176, 389),    S(286, 335),    //
    S(120, 225),    S(165, 242),    S(196, 159),    S(179, 97),     S(178, 79),     S(139, 138),    S(108, 193),    S(50, 227),     //
    S(84, 183),     S(79, 178),     S(125, 103),    S(127, 79),     S(110, 83),     S(80, 119),     S(28, 171),     S(15, 194),     //
    S(60, 129),     S(50, 154),     S(88, 97),      S(88, 90),      S(64, 94),      S(46, 123),     S(-16, 168),    S(-21, 157),    //
    S(55, 103),     S(98, 108),     S(77, 141),     S(72, 126),     S(43, 122),     S(22, 132),     S(-14, 151),    S(-25, 146),    //
    S(68, 107),     S(165, 121),    S(151, 174),    S(100, 158),    S(71, 141),     S(44, 146),     S(15, 158),     S(-7, 157),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-224, -170),  S(-120, 174),   S(-156, 76),    S(87, 165),     S(58, 174),     S(-106, 150),   S(-317, 217),   S(-313, -17),   //
    S(76, 145),     S(124, 185),    S(188, 128),    S(209, 155),    S(192, 163),    S(130, 166),    S(102, 174),    S(58, 153),     //
    S(137, 146),    S(211, 124),    S(213, 196),    S(224, 182),    S(177, 220),    S(118, 232),    S(139, 164),    S(81, 165),     //
    S(227, 165),    S(245, 178),    S(228, 230),    S(233, 234),    S(235, 239),    S(196, 223),    S(173, 198),    S(166, 166),    //
    S(218, 161),    S(255, 146),    S(227, 206),    S(220, 225),    S(192, 237),    S(183, 228),    S(176, 184),    S(155, 166),    //
    S(156, 133),    S(185, 143),    S(182, 178),    S(186, 205),    S(184, 209),    S(145, 190),    S(130, 156),    S(103, 122),    //
    S(166, 126),    S(177, 118),    S(161, 134),    S(162, 167),    S(147, 172),    S(122, 122),    S(105, 139),    S(93, 46),      //
    S(84, 88),      S(142, 151),    S(162, 102),    S(176, 120),    S(167, 134),    S(133, 100),    S(107, 130),    S(59, 46),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(7, 257),      S(-23, 291),    S(-290, 346),   S(-126, 288),   S(-105, 282),   S(-189, 292),   S(-49, 320),    S(20, 315),     //
    S(121, 203),    S(73, 276),     S(92, 238),     S(59, 249),     S(76, 233),     S(86, 251),     S(121, 242),    S(114, 211),    //
    S(195, 197),    S(203, 233),    S(192, 249),    S(165, 250),    S(144, 241),    S(145, 257),    S(154, 236),    S(144, 210),    //
    S(163, 196),    S(185, 227),    S(191, 248),    S(191, 290),    S(225, 275),    S(152, 252),    S(168, 208),    S(133, 207),    //
    S(197, 170),    S(208, 200),    S(207, 233),    S(208, 259),    S(192, 277),    S(176, 252),    S(147, 216),    S(125, 190),    //
    S(213, 175),    S(258, 189),    S(265, 216),    S(208, 244),    S(195, 234),    S(194, 239),    S(199, 220),    S(141, 208),    //
    S(179, 143),    S(282, 150),    S(233, 186),    S(208, 198),    S(185, 207),    S(187, 176),    S(186, 177),    S(189, 162),    //
    S(206, 154),    S(193, 171),    S(198, 202),    S(208, 175),    S(204, 183),    S(198, 227),    S(200, 204),    S(189, 179),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(477, 389),    S(471, 425),    S(442, 449),    S(483, 372),    S(441, 409),    S(429, 406),    S(405, 430),    S(406, 435),    //
    S(341, 476),    S(402, 485),    S(461, 463),    S(421, 468),    S(417, 467),    S(404, 459),    S(317, 501),    S(307, 504),    //
    S(301, 481),    S(406, 462),    S(447, 436),    S(448, 420),    S(407, 432),    S(372, 456),    S(361, 466),    S(294, 502),    //
    S(296, 444),    S(381, 448),    S(403, 433),    S(396, 422),    S(378, 443),    S(339, 459),    S(323, 465),    S(268, 473),    //
    S(275, 380),    S(346, 401),    S(342, 405),    S(313, 415),    S(292, 425),    S(278, 446),    S(254, 441),    S(243, 425),    //
    S(268, 321),    S(338, 331),    S(324, 367),    S(300, 371),    S(289, 373),    S(265, 393),    S(271, 371),    S(224, 385),    //
    S(153, 332),    S(289, 295),    S(310, 321),    S(297, 346),    S(289, 343),    S(285, 345),    S(266, 335),    S(237, 339),    //
    S(228, 312),    S(254, 326),    S(310, 321),    S(325, 314),    S(317, 321),    S(295, 339),    S(283, 336),    S(264, 345),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(576, 652),    S(625, 595),    S(530, 749),    S(500, 796),    S(512, 763),    S(516, 736),    S(554, 642),    S(502, 692),    //
    S(532, 767),    S(546, 776),    S(478, 877),    S(364, 946),    S(385, 908),    S(445, 871),    S(489, 728),    S(505, 722),    //
    S(530, 756),    S(578, 798),    S(492, 911),    S(475, 894),    S(437, 888),    S(485, 833),    S(525, 725),    S(507, 700),    //
    S(570, 685),    S(550, 810),    S(506, 850),    S(495, 886),    S(496, 877),    S(499, 795),    S(544, 703),    S(525, 690),    //
    S(557, 671),    S(562, 722),    S(525, 791),    S(493, 839),    S(493, 842),    S(513, 761),    S(514, 704),    S(549, 628),    //
    S(560, 580),    S(579, 658),    S(583, 713),    S(538, 731),    S(544, 700),    S(535, 738),    S(555, 657),    S(532, 629),    //
    S(520, 477),    S(568, 468),    S(579, 545),    S(592, 595),    S(571, 630),    S(570, 595),    S(538, 616),    S(548, 591),    //
    S(503, 524),    S(546, 325),    S(559, 377),    S(576, 487),    S(581, 559),    S(577, 510),    S(559, 532),    S(529, 573),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(14, -312),    S(321, 196),    S(231, 171),    S(54, -17),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(252, -46),    S(370, 205),    S(248, 160),    S(137, 7),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(278, 28),     S(400, 122),    S(313, 101),    S(195, 2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(122, 6),      S(360, 33),     S(252, 37),     S(148, 14),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-0, -20),     S(251, 1),      S(184, -4),     S(40, 8),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -7),     S(210, -8),     S(125, -7),     S(63, -22),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-4, -13),     S(90, 34),      S(14, 21),      S(-59, -1),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-132, -50),   S(-25, -11),    S(-128, -5),    S(-138, -83),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(20, -9), S(1, 31), S(-5, 31), S(3, 15), S(3, 14), S(-2, 27), S(2, 33), }},
  {{ S(12, -6), S(-19, 31), S(-15, 21), S(-2, 1), S(-4, 1), S(-13, 23), S(-15, 34), }},
  {{ S(-7, 10), S(-21, 36), S(-17, 12), S(-14, -0), S(-13, 1), S(-16, 14), S(-18, 34), }},
  {{ S(8, -17), S(-11, -20), S(-0, -25), S(3, -28), S(3, -26), S(-4, -21), S(-9, -19), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, 413), S(-16, 34), S(-13, 20), S(-2, 5), S(-5, -9),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-0, -5), S(-12, 5), S(-12, 0), S(-10, 0), S(-10, -2), S(-7, -7), S(-11, 2), }},
  {{ S(2, -0), S(-7, 6), S(-15, 15), S(-11, 8), S(-10, 4), S(-13, 7), S(-7, 4), }},
  {{ S(-7, 6), S(-12, 3), S(-13, 9), S(-9, 9), S(-8, 7), S(-14, 9), S(-12, 4), }},
  {{ S(-8, 8), S(-13, 8), S(-15, 10), S(-10, 13), S(-7, 13), S(-16, 9), S(-16, 9), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1025, 512, -51, 50
);

inline VParam WINNABLE_PAWNS = V(-17);
inline VParam WINNABLE_SYM = V(144);
inline VParam WINNABLE_ASYM = V(129);
inline VParam WINNABLE_PAWN_ENDGAME = V(219);
inline VParam WINNABLE_BIAS = V(-673);

// Epoch duration: 12.7091s
// clang-format on
}  // namespace Clockwork
