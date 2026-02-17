#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(140, 195);
inline const PParam KNIGHT_MAT = S(581, 602);
inline const PParam BISHOP_MAT = S(621, 627);
inline const PParam ROOK_MAT   = S(477, 666);
inline const PParam QUEEN_MAT  = S(1089, 1101);
inline const PParam TEMPO_VAL  = S(58, 20);

inline const PParam BISHOP_PAIR_VAL   = S(50, 197);
inline const PParam ROOK_OPEN_VAL     = S(108, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 20);

inline const PParam DOUBLED_PAWN_VAL = S(-8, -68);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -16);
inline const PParam OUTPOST_KNIGHT_VAL    = S(38, 60);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 32);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 9);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 53);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, 5), S(39, 27), S(59, 49), S(134, 141), S(355, 218), S(499, 670),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 34), S(43, 26), S(54, 52), S(113, 144), S(369, 103),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-70, -119), S(-68, -94), S(-50, 18), S(10, 116), S(96, 257), S(269, 359),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(39, -48), S(34, -5), S(25, 25), S(-0, 107), S(52, 218), S(222, 253),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -27), S(1, 11), S(1, -19), S(-2, -50), S(7, -142), S(-229, -222),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-4, 141), S(-19, 113), S(-14, 44), S(-4, 9), S(2, 8), S(41, 4), S(21, -4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-294, -63), S(-33, 13), S(-25, 66), S(15, 93), S(30, 112), S(43, 115), S(27, 112),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(70, -6), S(140, 166), S(174, 257), S(200, 294), S(241, 312), S(266, 346), S(299, 343), S(331, 354), S(384, 269),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(81, 9), S(125, 177), S(181, 238), S(208, 282), S(234, 313), S(251, 336), S(261, 353), S(277, 361), S(286, 376), S(314, 355), S(329, 355), S(383, 299), S(390, 305), S(428, 251),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(309, 244), S(229, 420), S(254, 446), S(271, 455), S(283, 467), S(289, 478), S(295, 488), S(304, 491), S(310, 501), S(322, 502), S(334, 502), S(342, 506), S(350, 503), S(369, 473), S(455, 371),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(498, 502), S(632, 534), S(657, 643), S(676, 749), S(692, 793), S(700, 838), S(707, 868), S(713, 880), S(716, 906), S(719, 923), S(725, 930), S(728, 941), S(736, 937), S(738, 942), S(742, 939), S(741, 941), S(742, 939), S(747, 935), S(754, 926), S(762, 923), S(770, 901), S(793, 862), S(784, 872), S(788, 815), S(786, 797), S(772, 780), S(728, 804), S(740, 743),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(37, 1503), S(30, -318), S(19, -324), S(13, -224), S(12, -182), S(13, -95), S(16, -85), S(22, -66), S(31, -17),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -12), S(6, -27), S(5, -1), S(2, 6), S(3, -57),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -32), S(2, -41), S(2, -30), S(2, -8), S(5, 283),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 91);
inline const PParam PAWN_THREAT_BISHOP = S(197, 139);
inline const PParam PAWN_THREAT_ROOK   = S(188, 130);
inline const PParam PAWN_THREAT_QUEEN  = S(171, -23);

inline const PParam KNIGHT_THREAT_BISHOP = S(111, 97);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 69);
inline const PParam KNIGHT_THREAT_QUEEN  = S(149, 6);

inline const PParam BISHOP_THREAT_KNIGHT = S(103, 56);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 121);
inline const PParam BISHOP_THREAT_QUEEN  = S(174, 96);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -36), S(-5, -8), S(-7, -17), S(-10, -27), S(-14, -37), S(-19, -42), S(-21, -54), S(-27, -52), S(-38, -56),
};

inline const PParam ROOK_LINEUP = S(13, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(299, 333),    S(171, 375),    S(323, 334),    S(288, 290),    S(321, 244),    S(207, 338),    S(144, 380),    S(255, 332),    //
    S(125, 191),    S(160, 213),    S(181, 156),    S(155, 118),    S(135, 102),    S(110, 151),    S(84, 206),     S(39, 231),     //
    S(93, 158),     S(74, 168),     S(102, 123),    S(101, 102),    S(91, 93),      S(64, 123),     S(15, 170),     S(8, 194),      //
    S(67, 111),     S(54, 138),     S(81, 111),     S(73, 108),     S(49, 109),     S(33, 131),     S(-29, 171),    S(-25, 161),    //
    S(70, 85),      S(112, 85),     S(90, 125),     S(72, 130),     S(40, 127),     S(16, 136),     S(-21, 155),    S(-25, 144),    //
    S(83, 83),      S(184, 71),     S(177, 123),    S(98, 152),     S(64, 145),     S(40, 141),     S(7, 155),      S(-9, 158),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-253, -90),   S(-163, 195),   S(-101, 42),    S(93, 183),     S(39, 180),     S(-123, 194),   S(-270, 260),   S(-293, -13),   //
    S(74, 156),     S(131, 165),    S(231, 126),    S(232, 141),    S(219, 158),    S(129, 179),    S(80, 194),     S(51, 171),     //
    S(171, 139),    S(228, 128),    S(241, 178),    S(249, 163),    S(201, 204),    S(129, 222),    S(130, 172),    S(89, 170),     //
    S(233, 172),    S(260, 182),    S(253, 203),    S(246, 230),    S(242, 240),    S(190, 230),    S(177, 206),    S(162, 184),    //
    S(205, 190),    S(256, 162),    S(227, 213),    S(218, 238),    S(191, 243),    S(188, 229),    S(188, 179),    S(139, 195),    //
    S(148, 158),    S(175, 170),    S(167, 204),    S(177, 227),    S(170, 227),    S(132, 211),    S(121, 180),    S(92, 150),     //
    S(155, 172),    S(172, 171),    S(147, 170),    S(150, 193),    S(140, 191),    S(112, 149),    S(100, 169),    S(87, 89),      //
    S(91, 122),     S(140, 183),    S(155, 148),    S(168, 145),    S(154, 163),    S(119, 137),    S(104, 164),    S(65, 87),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(2, 294),      S(-8, 290),     S(-267, 338),   S(-127, 279),   S(-131, 292),   S(-150, 289),   S(-42, 290),    S(38, 264),     //
    S(113, 216),    S(70, 279),     S(109, 224),    S(66, 248),     S(82, 245),     S(88, 251),     S(122, 252),    S(94, 234),     //
    S(198, 231),    S(219, 234),    S(213, 241),    S(200, 233),    S(160, 240),    S(159, 253),    S(175, 245),    S(164, 223),    //
    S(182, 211),    S(214, 223),    S(218, 243),    S(215, 282),    S(246, 266),    S(172, 248),    S(176, 219),    S(136, 217),    //
    S(200, 175),    S(213, 212),    S(218, 237),    S(226, 265),    S(202, 277),    S(185, 256),    S(151, 234),    S(147, 193),    //
    S(219, 189),    S(253, 208),    S(265, 234),    S(213, 258),    S(203, 240),    S(197, 252),    S(207, 224),    S(151, 217),    //
    S(187, 168),    S(278, 192),    S(239, 201),    S(205, 222),    S(186, 225),    S(190, 199),    S(193, 195),    S(189, 183),    //
    S(217, 169),    S(207, 189),    S(199, 229),    S(213, 191),    S(205, 199),    S(207, 240),    S(204, 217),    S(195, 193),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(435, 379),    S(444, 394),    S(426, 411),    S(450, 374),    S(430, 377),    S(390, 391),    S(388, 402),    S(377, 410),    //
    S(300, 456),    S(373, 444),    S(453, 415),    S(409, 421),    S(389, 433),    S(366, 435),    S(293, 470),    S(278, 476),    //
    S(289, 447),    S(392, 424),    S(455, 390),    S(432, 381),    S(380, 412),    S(338, 432),    S(336, 431),    S(268, 474),    //
    S(284, 415),    S(362, 413),    S(401, 391),    S(371, 398),    S(362, 406),    S(322, 430),    S(314, 427),    S(238, 461),    //
    S(259, 355),    S(326, 363),    S(318, 386),    S(296, 382),    S(271, 405),    S(261, 420),    S(227, 418),    S(207, 419),    //
    S(248, 305),    S(311, 324),    S(302, 347),    S(289, 342),    S(272, 354),    S(244, 382),    S(240, 358),    S(206, 368),    //
    S(138, 318),    S(269, 281),    S(284, 309),    S(278, 323),    S(260, 332),    S(250, 341),    S(232, 327),    S(208, 337),    //
    S(204, 304),    S(230, 319),    S(287, 308),    S(298, 302),    S(287, 310),    S(266, 329),    S(255, 325),    S(235, 337),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(547, 674),    S(593, 622),    S(518, 720),    S(491, 786),    S(490, 750),    S(502, 728),    S(541, 643),    S(479, 714),    //
    S(537, 728),    S(500, 817),    S(487, 822),    S(348, 916),    S(362, 898),    S(418, 863),    S(467, 752),    S(473, 740),    //
    S(485, 794),    S(538, 800),    S(478, 876),    S(439, 889),    S(412, 891),    S(463, 805),    S(501, 733),    S(507, 684),    //
    S(545, 704),    S(558, 767),    S(492, 845),    S(485, 871),    S(478, 868),    S(493, 764),    S(534, 701),    S(519, 673),    //
    S(568, 654),    S(552, 728),    S(525, 785),    S(503, 812),    S(497, 817),    S(501, 765),    S(517, 688),    S(542, 620),    //
    S(547, 597),    S(582, 646),    S(578, 711),    S(548, 700),    S(541, 695),    S(540, 710),    S(552, 639),    S(529, 615),    //
    S(530, 483),    S(564, 505),    S(573, 567),    S(587, 596),    S(574, 619),    S(568, 589),    S(532, 626),    S(539, 613),    //
    S(516, 487),    S(549, 342),    S(569, 375),    S(587, 473),    S(586, 540),    S(582, 489),    S(568, 522),    S(535, 552),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(43, -307),    S(238, 200),    S(153, 160),    S(67, 15),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(180, -26),    S(272, 214),    S(155, 197),    S(102, 86),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(177, 56),     S(272, 165),    S(184, 162),    S(126, 95),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(58, 6),       S(222, 99),     S(108, 126),    S(83, 130),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-42, -21),    S(120, 52),     S(84, 87),      S(6, 142),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-22, -42),    S(110, 22),     S(22, 68),      S(5, 110),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, -86),     S(58, -8),      S(-38, 33),     S(-82, 81),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-37, -184),   S(-8, -96),     S(-107, -60),   S(-111, -64),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(9, 130), S(-10, 169), S(-12, 196), S(-3, 118), S(-4, 109), S(-12, 195), S(-8, 147), }},
  {{ S(-1, 138), S(-24, -1780), S(-24, 108), S(-14, 61), S(-14, 64), S(-23, 105), S(-22, -1658), }},
  {{ S(-15, 276), S(-17, -1725), S(-25, 223), S(-23, 217), S(-21, 210), S(-24, 223), S(-17, -1762), }},
  {{ S(3, 68), S(-16, -989), S(-8, -18), S(-2, -35), S(-3, -20), S(-9, -2), S(-11, -1587), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 11), S(-15, -606), S(-18, -62), S(-13, 23), S(-10, -139),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-6, -88), S(-17, -73), S(-16, -73), S(-14, -89), S(-15, -136), S(-15, -111), S(-17, -83), }},
  {{ S(-8, -105), S(-15, -51), S(-21, -94), S(-17, -145), S(-17, -154), S(-20, -110), S(-14, -60), }},
  {{ S(-14, -76), S(-18, -60), S(-19, -64), S(-15, -107), S(-13, -686), S(-19, -87), S(-18, -54), }},
  {{ S(-16, 3), S(-20, 15), S(-21, -25), S(-15, -50), S(-13, -59), S(-20, -33), S(-21, -16), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1210, 168, -32, -157
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(126);
inline VParam WINNABLE_PAWN_ENDGAME = V(228);
inline VParam WINNABLE_BIAS = V(-656);

// Epoch duration: 7.95084s
// clang-format on
}  // namespace Clockwork
