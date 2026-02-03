#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(141, 192);
inline const PParam KNIGHT_MAT = S(589, 591);
inline const PParam BISHOP_MAT = S(635, 618);
inline const PParam ROOK_MAT   = S(493, 642);
inline const PParam QUEEN_MAT  = S(1162, 1019);
inline const PParam TEMPO_VAL  = S(59, 19);

inline const PParam BISHOP_PAIR_VAL   = S(54, 190);
inline const PParam ROOK_OPEN_VAL     = S(106, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 22);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -66);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -20);

inline const PParam POTENTIAL_CHECKER_VAL = S(-51, -21);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 64);
inline const PParam OUTPOST_BISHOP_VAL    = S(50, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(28, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(69, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -1), S(40, 24), S(58, 49), S(136, 149), S(352, 253), S(440, 741),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(56, 32), S(46, 24), S(55, 51), S(120, 142), S(418, 80),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -111), S(-75, -87), S(-48, 18), S(13, 119), S(103, 261), S(282, 359),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(34, -41), S(32, 0), S(20, 41), S(2, 114), S(57, 213), S(206, 278),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(23, -47), S(6, 3), S(0, -23), S(-7, -48), S(-18, -113), S(-227, -211),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 149), S(-15, 115), S(-10, 45), S(-4, 10), S(1, 7), S(33, 7), S(4, 4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-322, -41), S(-44, 23), S(-26, 59), S(13, 99), S(33, 119), S(54, 119), S(33, 118),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(66, 1), S(137, 172), S(173, 258), S(201, 293), S(241, 310), S(266, 343), S(298, 341), S(329, 356), S(381, 272),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(90, -1), S(134, 169), S(189, 229), S(216, 273), S(241, 304), S(258, 326), S(265, 346), S(280, 355), S(286, 372), S(310, 356), S(322, 356), S(371, 304), S(372, 314), S(393, 280),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(317, 238), S(238, 413), S(263, 436), S(281, 445), S(292, 458), S(298, 468), S(305, 478), S(314, 479), S(320, 489), S(332, 490), S(344, 491), S(353, 493), S(359, 492), S(375, 466), S(478, 346),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(502, 525), S(657, 497), S(682, 608), S(700, 720), S(715, 767), S(724, 810), S(730, 841), S(738, 851), S(741, 875), S(745, 887), S(752, 892), S(756, 900), S(765, 894), S(768, 897), S(773, 893), S(773, 893), S(775, 890), S(783, 880), S(791, 870), S(796, 869), S(808, 841), S(833, 799), S(825, 805), S(826, 746), S(812, 739), S(805, 711), S(739, 776), S(762, 672),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(481, -171), S(105, -104), S(27, -23), S(15, 8), S(-4, 7), S(-21, 2), S(-22, 6), S(-36, 12), S(-23, -31),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -7), S(15, -16), S(13, -12), S(6, -8), S(2, 189),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 418),
};

inline const PParam PAWN_THREAT_KNIGHT = S(216, 87);
inline const PParam PAWN_THREAT_BISHOP = S(193, 139);
inline const PParam PAWN_THREAT_ROOK   = S(196, 117);
inline const PParam PAWN_THREAT_QUEEN  = S(176, -38);

inline const PParam KNIGHT_THREAT_BISHOP = S(113, 95);
inline const PParam KNIGHT_THREAT_ROOK   = S(233, 56);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -7);

inline const PParam BISHOP_THREAT_KNIGHT = S(107, 55);
inline const PParam BISHOP_THREAT_ROOK   = S(216, 116);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 93);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -32), S(-3, -10), S(-6, -18), S(-9, -27), S(-14, -36), S(-18, -42), S(-21, -53), S(-28, -51), S(-39, -50),
};

inline const PParam ROOK_LINEUP = S(11, 72);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(318, 325),    S(168, 421),    S(301, 404),    S(312, 269),    S(334, 224),    S(229, 306),    S(169, 339),    S(270, 303),    //
    S(122, 202),    S(152, 236),    S(194, 154),    S(176, 94),     S(155, 78),     S(129, 129),    S(101, 184),    S(54, 212),     //
    S(83, 168),     S(70, 169),     S(112, 99),     S(112, 80),     S(100, 77),     S(72, 107),     S(25, 154),     S(14, 183),     //
    S(56, 126),     S(47, 145),     S(82, 99),      S(80, 90),      S(58, 92),      S(42, 115),     S(-18, 156),    S(-17, 149),    //
    S(55, 101),     S(96, 105),     S(80, 137),     S(73, 123),     S(45, 118),     S(23, 123),     S(-11, 139),    S(-19, 134),    //
    S(69, 102),     S(161, 112),    S(146, 169),    S(96, 151),     S(67, 140),     S(47, 133),     S(18, 144),     S(-1, 149),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-262, -64),   S(-141, 183),   S(-138, 90),    S(97, 180),     S(41, 176),     S(-117, 199),   S(-228, 214),   S(-299, 4),     //
    S(71, 166),     S(121, 180),    S(205, 146),    S(191, 167),    S(184, 180),    S(113, 188),    S(75, 205),     S(54, 175),     //
    S(166, 149),    S(198, 169),    S(211, 205),    S(205, 201),    S(173, 224),    S(113, 239),    S(123, 188),    S(89, 178),     //
    S(232, 174),    S(240, 194),    S(237, 216),    S(224, 248),    S(225, 254),    S(180, 241),    S(172, 210),    S(168, 179),    //
    S(215, 178),    S(248, 163),    S(220, 216),    S(217, 235),    S(193, 241),    S(190, 226),    S(189, 174),    S(151, 181),    //
    S(159, 147),    S(186, 153),    S(176, 191),    S(185, 217),    S(181, 214),    S(145, 196),    S(134, 165),    S(104, 135),    //
    S(170, 150),    S(193, 144),    S(161, 154),    S(164, 175),    S(154, 175),    S(126, 133),    S(111, 158),    S(99, 76),      //
    S(104, 105),    S(151, 165),    S(168, 131),    S(184, 124),    S(165, 145),    S(132, 120),    S(116, 144),    S(77, 72),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-6, 289),     S(-12, 296),    S(-284, 353),   S(-154, 291),   S(-164, 314),   S(-183, 317),   S(-58, 305),    S(19, 282),     //
    S(121, 198),    S(64, 280),     S(90, 241),     S(30, 268),     S(46, 267),     S(76, 259),     S(117, 250),    S(99, 221),     //
    S(192, 227),    S(201, 246),    S(198, 249),    S(174, 249),    S(144, 246),    S(151, 256),    S(170, 242),    S(165, 215),    //
    S(162, 218),    S(198, 226),    S(196, 252),    S(196, 284),    S(227, 272),    S(156, 253),    S(168, 217),    S(129, 215),    //
    S(190, 177),    S(207, 207),    S(212, 232),    S(218, 257),    S(194, 272),    S(178, 252),    S(145, 231),    S(139, 194),    //
    S(216, 186),    S(252, 195),    S(263, 222),    S(207, 248),    S(203, 226),    S(198, 238),    S(206, 214),    S(143, 215),    //
    S(184, 157),    S(283, 174),    S(241, 187),    S(207, 206),    S(187, 209),    S(192, 184),    S(191, 185),    S(185, 177),    //
    S(215, 159),    S(202, 179),    S(202, 210),    S(218, 169),    S(206, 183),    S(205, 224),    S(202, 204),    S(193, 182),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(428, 373),    S(455, 380),    S(424, 398),    S(441, 365),    S(417, 374),    S(385, 385),    S(381, 400),    S(371, 406),    //
    S(307, 455),    S(390, 443),    S(466, 407),    S(412, 414),    S(390, 429),    S(378, 425),    S(304, 463),    S(283, 473),    //
    S(276, 450),    S(378, 435),    S(435, 396),    S(418, 380),    S(370, 409),    S(328, 431),    S(329, 432),    S(261, 473),    //
    S(281, 411),    S(360, 416),    S(394, 392),    S(372, 391),    S(362, 403),    S(325, 421),    S(320, 418),    S(243, 449),    //
    S(263, 345),    S(331, 356),    S(320, 377),    S(299, 375),    S(278, 395),    S(267, 410),    S(234, 409),    S(214, 405),    //
    S(255, 289),    S(318, 313),    S(306, 336),    S(292, 334),    S(277, 345),    S(253, 365),    S(246, 346),    S(210, 356),    //
    S(149, 297),    S(280, 265),    S(291, 293),    S(282, 313),    S(268, 319),    S(257, 328),    S(242, 308),    S(215, 321),    //
    S(210, 287),    S(234, 308),    S(291, 296),    S(304, 293),    S(293, 302),    S(273, 316),    S(261, 313),    S(241, 322),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(562, 609),    S(614, 558),    S(540, 682),    S(505, 755),    S(493, 735),    S(518, 691),    S(545, 605),    S(489, 659),    //
    S(559, 671),    S(526, 765),    S(508, 811),    S(369, 897),    S(376, 885),    S(440, 832),    S(479, 717),    S(496, 683),    //
    S(523, 739),    S(565, 769),    S(511, 849),    S(450, 885),    S(425, 879),    S(473, 803),    S(516, 709),    S(535, 631),    //
    S(566, 647),    S(570, 738),    S(505, 814),    S(495, 846),    S(483, 854),    S(496, 755),    S(547, 670),    S(527, 651),    //
    S(578, 622),    S(569, 687),    S(537, 750),    S(509, 789),    S(505, 795),    S(505, 748),    S(528, 657),    S(552, 586),    //
    S(559, 564),    S(593, 617),    S(587, 678),    S(554, 677),    S(551, 665),    S(546, 688),    S(561, 609),    S(539, 581),    //
    S(539, 456),    S(579, 464),    S(585, 526),    S(595, 570),    S(579, 601),    S(573, 566),    S(538, 598),    S(548, 579),    //
    S(523, 466),    S(553, 324),    S(578, 341),    S(592, 453),    S(588, 526),    S(587, 472),    S(575, 495),    S(541, 530),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-74, -351),   S(284, 194),    S(182, 115),    S(50, -51),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(254, -98),    S(351, 177),    S(195, 172),    S(143, -19),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(249, 10),     S(399, 89),     S(291, 86),     S(188, -19),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(96, -16),     S(345, 32),     S(186, 56),     S(117, 23),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -26),    S(239, 2),      S(153, 19),     S(27, 33),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -16),    S(214, -3),     S(107, 14),     S(57, -2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-2, -18),     S(81, 35),      S(-8, 43),      S(-64, 21),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-116, -69),   S(-18, -23),    S(-121, -12),   S(-123, -79),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(14, -16), S(-4, 20), S(-8, 22), S(-1, 8), S(-1, 4), S(-7, 21), S(-2, 21), }},
  {{ S(3, -5), S(-24, 28), S(-20, 22), S(-12, 5), S(-11, 5), S(-20, 28), S(-23, 37), }},
  {{ S(-13, -0), S(-25, 26), S(-23, 7), S(-19, -6), S(-19, -5), S(-22, 8), S(-23, 23), }},
  {{ S(-0, -13), S(-18, -13), S(-10, -16), S(-5, -20), S(-6, -18), S(-11, -13), S(-14, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(2, 228), S(-17, 32), S(-15, 21), S(-7, 9), S(-8, -8),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 4), S(-14, 13), S(-13, 10), S(-12, 10), S(-12, 5), S(-11, 2), S(-14, 9), }},
  {{ S(-3, 3), S(-11, 9), S(-18, 14), S(-15, 12), S(-14, 7), S(-16, 11), S(-10, 8), }},
  {{ S(-9, 6), S(-14, 4), S(-15, 10), S(-11, 10), S(-10, 8), S(-14, 9), S(-13, 5), }},
  {{ S(-10, 8), S(-15, 10), S(-16, 10), S(-11, 13), S(-10, 14), S(-15, 10), S(-17, 9), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1209, 553, -27, 55
);

inline VParam WINNABLE_PAWNS = V(47);
inline VParam WINNABLE_PAWN_ENDGAME = V(169);
inline VParam WINNABLE_BIAS = V(-460);

// Epoch duration: 6.95479s
// clang-format on
}  // namespace Clockwork
