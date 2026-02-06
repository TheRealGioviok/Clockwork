#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 201);
inline const PParam KNIGHT_MAT = S(566, 619);
inline const PParam BISHOP_MAT = S(605, 650);
inline const PParam ROOK_MAT   = S(471, 685);
inline const PParam QUEEN_MAT  = S(1096, 1092);
inline const PParam TEMPO_VAL  = S(57, 22);

inline const PParam BISHOP_PAIR_VAL   = S(51, 196);
inline const PParam ROOK_OPEN_VAL     = S(105, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 22);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -70);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(39, 62);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(44, 27);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(64, 63);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(42, 66);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, 4);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, 1), S(32, 27), S(51, 51), S(134, 143), S(359, 199), S(459, 692),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 35), S(45, 28), S(54, 55), S(119, 140), S(414, 79),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -122), S(-68, -98), S(-47, 14), S(12, 121), S(99, 266), S(258, 383),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(37, -46), S(34, -6), S(18, 33), S(-6, 110), S(32, 223), S(196, 283),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(24, -37), S(3, 13), S(-2, -19), S(-9, -51), S(-18, -124), S(-202, -240),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-8, 152), S(-17, 113), S(-10, 43), S(-2, 5), S(5, 3), S(38, 5), S(12, -1),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-314, -46), S(-47, 31), S(-24, 60), S(13, 95), S(32, 111), S(50, 111), S(33, 103),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(57, 7), S(127, 178), S(162, 266), S(190, 302), S(231, 319), S(256, 353), S(289, 350), S(321, 362), S(376, 275),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(99, 6), S(140, 180), S(195, 243), S(221, 288), S(246, 319), S(262, 344), S(268, 363), S(280, 374), S(283, 392), S(308, 372), S(317, 374), S(365, 320), S(361, 331), S(391, 281),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(311, 238), S(228, 420), S(253, 444), S(271, 454), S(281, 468), S(287, 479), S(294, 489), S(302, 491), S(308, 502), S(319, 503), S(331, 505), S(338, 509), S(343, 509), S(360, 481), S(447, 376),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(485, 518), S(627, 530), S(652, 639), S(668, 755), S(684, 799), S(692, 845), S(698, 877), S(705, 887), S(709, 910), S(712, 924), S(718, 932), S(722, 939), S(731, 932), S(733, 938), S(737, 933), S(735, 937), S(737, 933), S(743, 927), S(751, 917), S(761, 909), S(767, 889), S(791, 847), S(790, 844), S(790, 789), S(778, 775), S(771, 746), S(706, 802), S(730, 708),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(487, -188), S(105, -107), S(29, -27), S(14, 7), S(-4, 7), S(-22, 2), S(-27, 10), S(-42, 18), S(-31, -21),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(16, -15), S(13, -12), S(6, -8), S(2, 200),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 415),
};

inline const PParam PAWN_THREAT_KNIGHT = S(210, 95);
inline const PParam PAWN_THREAT_BISHOP = S(186, 146);
inline const PParam PAWN_THREAT_ROOK   = S(191, 124);
inline const PParam PAWN_THREAT_QUEEN  = S(159, -10);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 68);
inline const PParam KNIGHT_THREAT_QUEEN  = S(149, -0);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(174, 99);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -34), S(-6, -8), S(-8, -17), S(-11, -27), S(-15, -36), S(-20, -42), S(-22, -54), S(-28, -51), S(-40, -51),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(292, 349),    S(143, 446),    S(291, 412),    S(302, 278),    S(320, 238),    S(213, 322),    S(151, 359),    S(257, 317),    //
    S(113, 214),    S(149, 251),    S(190, 167),    S(181, 99),     S(158, 85),     S(129, 138),    S(99, 196),     S(45, 224),     //
    S(79, 174),     S(69, 176),     S(116, 99),     S(117, 76),     S(105, 73),     S(76, 108),     S(25, 159),     S(9, 189),      //
    S(56, 126),     S(50, 148),     S(87, 95),      S(88, 84),      S(66, 87),      S(45, 115),     S(-17, 160),    S(-21, 153),    //
    S(54, 100),     S(95, 106),     S(81, 137),     S(74, 122),     S(46, 118),     S(23, 125),     S(-13, 143),    S(-23, 137),    //
    S(68, 102),     S(158, 118),    S(143, 173),    S(93, 155),     S(65, 142),     S(45, 137),     S(14, 150),     S(-5, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-244, -75),   S(-145, 195),   S(-95, 50),     S(99, 185),     S(39, 185),     S(-109, 191),   S(-241, 240),   S(-282, -6),    //
    S(83, 160),     S(122, 190),    S(210, 148),    S(204, 158),    S(200, 165),    S(117, 189),    S(81, 203),     S(54, 182),     //
    S(167, 158),    S(213, 154),    S(211, 214),    S(211, 199),    S(171, 233),    S(111, 247),    S(125, 192),    S(92, 183),     //
    S(234, 181),    S(240, 205),    S(234, 230),    S(222, 261),    S(221, 269),    S(176, 254),    S(171, 223),    S(166, 192),    //
    S(213, 186),    S(249, 169),    S(214, 228),    S(214, 246),    S(190, 250),    S(185, 236),    S(185, 186),    S(149, 189),    //
    S(159, 152),    S(182, 165),    S(171, 202),    S(179, 228),    S(175, 227),    S(140, 207),    S(132, 176),    S(105, 139),    //
    S(171, 155),    S(193, 152),    S(159, 161),    S(161, 185),    S(152, 182),    S(125, 139),    S(115, 159),    S(101, 78),     //
    S(109, 104),    S(153, 170),    S(169, 137),    S(184, 131),    S(166, 153),    S(134, 125),    S(119, 150),    S(82, 70),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-6, 285),     S(-22, 296),    S(-283, 342),   S(-150, 280),   S(-161, 300),   S(-172, 296),   S(-57, 294),    S(24, 268),     //
    S(116, 195),    S(59, 278),     S(91, 233),     S(37, 251),     S(52, 250),     S(78, 249),     S(114, 247),    S(90, 223),     //
    S(187, 226),    S(200, 240),    S(193, 251),    S(170, 249),    S(140, 245),    S(147, 255),    S(163, 244),    S(158, 216),    //
    S(154, 221),    S(182, 239),    S(190, 256),    S(190, 293),    S(216, 284),    S(146, 258),    S(154, 226),    S(117, 221),    //
    S(176, 180),    S(191, 215),    S(192, 243),    S(203, 269),    S(179, 283),    S(160, 262),    S(131, 237),    S(129, 191),    //
    S(208, 185),    S(236, 203),    S(250, 229),    S(195, 254),    S(192, 231),    S(187, 243),    S(191, 221),    S(136, 214),    //
    S(176, 156),    S(275, 174),    S(232, 189),    S(199, 206),    S(178, 211),    S(183, 187),    S(184, 183),    S(177, 178),    //
    S(208, 159),    S(196, 176),    S(194, 210),    S(208, 174),    S(198, 184),    S(198, 226),    S(195, 204),    S(187, 181),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(423, 382),    S(436, 400),    S(411, 414),    S(430, 377),    S(411, 382),    S(376, 394),    S(372, 410),    S(368, 411),    //
    S(302, 462),    S(376, 459),    S(452, 425),    S(398, 431),    S(383, 438),    S(362, 444),    S(295, 475),    S(278, 481),    //
    S(271, 457),    S(372, 444),    S(428, 406),    S(410, 391),    S(358, 424),    S(317, 446),    S(321, 442),    S(255, 482),    //
    S(275, 418),    S(354, 427),    S(390, 399),    S(363, 403),    S(351, 416),    S(314, 436),    S(311, 432),    S(234, 460),    //
    S(253, 351),    S(319, 368),    S(306, 386),    S(287, 384),    S(263, 408),    S(253, 419),    S(225, 414),    S(204, 411),    //
    S(248, 293),    S(307, 322),    S(294, 345),    S(278, 343),    S(266, 351),    S(240, 375),    S(238, 351),    S(203, 359),    //
    S(140, 305),    S(271, 271),    S(281, 301),    S(271, 323),    S(256, 327),    S(249, 331),    S(231, 319),    S(207, 329),    //
    S(205, 291),    S(228, 311),    S(284, 302),    S(296, 298),    S(284, 307),    S(265, 322),    S(254, 317),    S(235, 327),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(563, 644),    S(616, 591),    S(539, 718),    S(508, 784),    S(491, 770),    S(527, 710),    S(547, 634),    S(500, 671),    //
    S(564, 695),    S(526, 793),    S(514, 830),    S(373, 921),    S(378, 914),    S(440, 862),    S(486, 732),    S(496, 713),    //
    S(526, 763),    S(574, 782),    S(506, 889),    S(455, 907),    S(429, 903),    S(479, 821),    S(517, 738),    S(535, 660),    //
    S(558, 690),    S(548, 786),    S(496, 849),    S(486, 883),    S(481, 875),    S(490, 784),    S(524, 724),    S(522, 680),    //
    S(564, 661),    S(550, 736),    S(517, 793),    S(495, 832),    S(493, 831),    S(493, 779),    S(512, 702),    S(542, 620),    //
    S(554, 599),    S(581, 655),    S(576, 718),    S(545, 713),    S(543, 699),    S(538, 726),    S(551, 644),    S(536, 613),    //
    S(536, 488),    S(574, 498),    S(578, 564),    S(589, 602),    S(575, 629),    S(570, 594),    S(534, 632),    S(547, 606),    //
    S(521, 499),    S(553, 347),    S(577, 365),    S(591, 477),    S(586, 552),    S(585, 499),    S(573, 523),    S(541, 554),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-72, -319),   S(261, 195),    S(135, 153),    S(23, -26),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(210, -55),    S(321, 175),    S(181, 165),    S(112, 4),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(198, 46),     S(354, 118),    S(247, 116),    S(159, 5),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(53, 14),      S(300, 57),     S(154, 76),     S(103, 34),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-35, -20),    S(214, 13),     S(145, 20),     S(24, 32),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -16),    S(208, -5),     S(110, 7),      S(60, -10),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(0, -23),      S(84, 29),      S(-0, 33),      S(-56, 10),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-111, -74),   S(-13, -29),    S(-113, -21),   S(-116, -89),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -17), S(-1, 18), S(-5, 21), S(2, 7), S(2, 3), S(-5, 21), S(1, 19), }},
  {{ S(7, -5), S(-21, 28), S(-18, 22), S(-8, 4), S(-7, 4), S(-17, 27), S(-20, 36), }},
  {{ S(-12, 4), S(-24, 30), S(-22, 11), S(-18, -3), S(-18, -2), S(-22, 11), S(-22, 26), }},
  {{ S(3, -14), S(-16, -14), S(-7, -18), S(-1, -23), S(-3, -21), S(-8, -16), S(-11, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(7, 22), S(-15, 30), S(-13, 20), S(-5, 7), S(-5, -8),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-1, 2), S(-12, 11), S(-10, 8), S(-9, 9), S(-9, 4), S(-8, -1), S(-12, 9), }},
  {{ S(-0, 1), S(-8, 7), S(-15, 12), S(-12, 9), S(-11, 5), S(-14, 8), S(-8, 6), }},
  {{ S(-7, 5), S(-11, 3), S(-12, 9), S(-8, 8), S(-8, 7), S(-12, 7), S(-11, 3), }},
  {{ S(-7, 6), S(-12, 8), S(-13, 7), S(-8, 12), S(-6, 12), S(-12, 8), S(-14, 8), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1161, 538, -42, 57
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(135);
inline VParam WINNABLE_ASYM = V(123);
inline VParam WINNABLE_BIAS = V(-643);

// Epoch duration: 8.39399s

// Epoch duration: 7.52381s
// clang-format on
}  // namespace Clockwork
