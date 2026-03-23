#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(139, 207);
inline const PParam KNIGHT_MAT = S(605, 649);
inline const PParam BISHOP_MAT = S(627, 668);
inline const PParam ROOK_MAT   = S(468, 687);
inline const PParam QUEEN_MAT  = S(1123, 1115);
inline const PParam TEMPO_VAL  = S(58, 22);

inline const PParam BISHOP_PAIR_VAL   = S(55, 199);
inline const PParam ROOK_OPEN_VAL     = S(105, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 21);
inline const PParam MINOR_BEHIND_PAWN = S(10, 42);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -76);
inline const PParam ISOLATED_PAWN_VAL = S(-21, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(36, 67);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 49);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(53, -24);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 58);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -37);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 3), S(37, 27), S(59, 46), S(132, 144), S(400, 172), S(488, 615),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(56, 35), S(44, 29), S(55, 56), S(109, 145), S(399, 92),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-70, -130), S(-69, -105), S(-47, 7), S(2, 121), S(89, 272), S(267, 387),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -41), S(33, -0), S(21, 34), S(-1, 118), S(51, 225), S(195, 300),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(24, -31), S(4, 17), S(8, -13), S(8, -45), S(-8, -116), S(-210, -226),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-5, 151), S(-14, 115), S(-12, 47), S(-3, 8), S(-0, 8), S(35, 7), S(14, -3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-312, -61), S(-38, 27), S(-23, 60), S(12, 100), S(33, 116), S(47, 120), S(30, 115),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(53, -9), S(124, 168), S(156, 255), S(183, 293), S(223, 311), S(247, 345), S(279, 341), S(310, 354), S(363, 268),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(81, -39), S(122, 158), S(179, 235), S(210, 277), S(233, 312), S(251, 337), S(258, 356), S(272, 366), S(278, 384), S(303, 365), S(307, 374), S(361, 316), S(357, 324), S(392, 273),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(319, 242), S(239, 431), S(264, 457), S(281, 470), S(292, 483), S(299, 495), S(304, 506), S(313, 508), S(319, 519), S(330, 521), S(341, 521), S(348, 528), S(355, 527), S(370, 500), S(445, 405),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(500, 438), S(648, 540), S(672, 653), S(690, 767), S(706, 814), S(713, 862), S(720, 894), S(728, 903), S(732, 930), S(736, 941), S(740, 952), S(746, 956), S(754, 953), S(756, 957), S(760, 952), S(760, 955), S(760, 950), S(767, 948), S(772, 940), S(781, 932), S(787, 908), S(812, 872), S(809, 865), S(804, 815), S(781, 822), S(788, 775), S(724, 805), S(742, 756),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(513, -169), S(119, -113), S(36, -26), S(18, 5), S(-2, 5), S(-20, -1), S(-27, 7), S(-45, 16), S(-34, -26),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -9), S(16, -15), S(13, -12), S(6, -8), S(2, 186),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -1), S(7, -11), S(6, -9), S(5, -5), S(6, 388),
};

inline const PParam PAWN_THREAT_KNIGHT = S(210, 97);
inline const PParam PAWN_THREAT_BISHOP = S(188, 147);
inline const PParam PAWN_THREAT_ROOK   = S(201, 113);
inline const PParam PAWN_THREAT_QUEEN  = S(174, -18);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(224, 74);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -15);

inline const PParam BISHOP_THREAT_KNIGHT = S(109, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(216, 131);
inline const PParam BISHOP_THREAT_QUEEN  = S(169, 119);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -34), S(-3, -6), S(-5, -14), S(-9, -23), S(-13, -31), S(-17, -35), S(-19, -46), S(-27, -42), S(-41, -36),
};

inline const PParam ROOK_LINEUP = S(13, 64);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(308, 350),    S(158, 459),    S(299, 422),    S(308, 290),    S(324, 237),    S(218, 321),    S(153, 361),    S(262, 306),    //
    S(122, 209),    S(154, 253),    S(190, 168),    S(180, 103),    S(160, 90),     S(136, 138),    S(109, 191),    S(53, 215),     //
    S(88, 173),     S(77, 178),     S(119, 102),    S(117, 81),     S(107, 79),     S(81, 111),     S(28, 161),     S(15, 187),     //
    S(61, 126),     S(51, 151),     S(82, 99),      S(81, 90),      S(59, 96),      S(43, 120),     S(-17, 162),    S(-18, 155),    //
    S(58, 99),      S(93, 110),     S(78, 138),     S(70, 123),     S(41, 123),     S(22, 127),     S(-12, 146),    S(-20, 138),    //
    S(70, 102),     S(157, 120),    S(142, 174),    S(94, 156),     S(63, 149),     S(44, 137),     S(13, 152),     S(-4, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-271, -56),   S(-164, 188),   S(-36, -21),    S(105, 159),    S(6, 183),      S(-138, 193),   S(-271, 260),   S(-300, -32),   //
    S(67, 170),     S(125, 181),    S(201, 155),    S(202, 158),    S(188, 172),    S(123, 183),    S(61, 206),     S(45, 179),     //
    S(155, 141),    S(202, 143),    S(198, 209),    S(208, 188),    S(165, 229),    S(111, 233),    S(116, 182),    S(73, 173),     //
    S(214, 170),    S(226, 193),    S(230, 219),    S(219, 250),    S(215, 263),    S(167, 246),    S(159, 214),    S(152, 184),    //
    S(205, 169),    S(236, 165),    S(209, 218),    S(206, 236),    S(182, 245),    S(176, 229),    S(174, 178),    S(140, 177),    //
    S(149, 136),    S(172, 158),    S(163, 199),    S(169, 223),    S(166, 220),    S(134, 202),    S(123, 166),    S(96, 132),     //
    S(159, 131),    S(173, 145),    S(145, 156),    S(149, 180),    S(142, 179),    S(111, 138),    S(97, 147),     S(86, 71),      //
    S(84, 93),      S(133, 161),    S(149, 126),    S(163, 137),    S(146, 153),    S(114, 127),    S(99, 146),     S(56, 58),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-21, 292),    S(-39, 322),    S(-254, 328),   S(-142, 284),   S(-179, 315),   S(-179, 297),   S(-92, 326),    S(22, 274),     //
    S(115, 205),    S(68, 283),     S(91, 247),     S(56, 247),     S(54, 262),     S(74, 260),     S(116, 262),    S(95, 229),     //
    S(179, 220),    S(192, 244),    S(196, 246),    S(175, 251),    S(151, 251),    S(154, 252),    S(168, 240),    S(154, 210),    //
    S(158, 218),    S(188, 229),    S(189, 258),    S(190, 294),    S(219, 281),    S(154, 250),    S(162, 217),    S(122, 215),    //
    S(178, 177),    S(203, 216),    S(213, 236),    S(206, 268),    S(187, 277),    S(173, 260),    S(142, 235),    S(135, 181),    //
    S(212, 186),    S(249, 202),    S(255, 230),    S(201, 252),    S(195, 231),    S(188, 240),    S(191, 226),    S(136, 213),    //
    S(172, 157),    S(270, 169),    S(231, 187),    S(201, 210),    S(181, 209),    S(182, 185),    S(178, 175),    S(174, 182),    //
    S(207, 160),    S(196, 182),    S(201, 198),    S(209, 181),    S(200, 194),    S(200, 229),    S(194, 215),    S(184, 180),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(438, 395),    S(453, 408),    S(427, 421),    S(439, 390),    S(438, 378),    S(405, 400),    S(384, 419),    S(373, 425),    //
    S(307, 480),    S(382, 481),    S(458, 446),    S(405, 451),    S(386, 460),    S(383, 454),    S(314, 491),    S(289, 496),    //
    S(279, 473),    S(376, 457),    S(434, 422),    S(413, 412),    S(375, 435),    S(326, 468),    S(328, 461),    S(265, 498),    //
    S(283, 434),    S(356, 444),    S(395, 418),    S(369, 425),    S(368, 426),    S(325, 450),    S(316, 450),    S(243, 476),    //
    S(260, 375),    S(318, 386),    S(316, 408),    S(289, 412),    S(271, 428),    S(263, 437),    S(237, 430),    S(215, 433),    //
    S(256, 305),    S(314, 339),    S(301, 361),    S(287, 364),    S(275, 375),    S(255, 386),    S(248, 367),    S(214, 376),    //
    S(152, 317),    S(277, 286),    S(291, 314),    S(282, 333),    S(267, 342),    S(263, 344),    S(244, 333),    S(214, 347),    //
    S(214, 308),    S(241, 324),    S(296, 314),    S(307, 312),    S(299, 317),    S(278, 332),    S(266, 331),    S(245, 338),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(582, 636),    S(614, 611),    S(545, 731),    S(503, 807),    S(495, 780),    S(535, 713),    S(544, 650),    S(522, 674),    //
    S(557, 720),    S(538, 798),    S(518, 847),    S(379, 943),    S(382, 924),    S(449, 873),    S(489, 756),    S(505, 717),    //
    S(527, 781),    S(573, 791),    S(504, 913),    S(458, 920),    S(439, 912),    S(479, 844),    S(525, 752),    S(534, 686),    //
    S(559, 702),    S(568, 789),    S(506, 859),    S(503, 887),    S(492, 884),    S(506, 787),    S(540, 732),    S(529, 683),    //
    S(577, 671),    S(570, 735),    S(539, 793),    S(507, 840),    S(506, 838),    S(508, 792),    S(521, 718),    S(547, 638),    //
    S(553, 609),    S(591, 662),    S(584, 720),    S(554, 724),    S(549, 719),    S(545, 733),    S(565, 649),    S(533, 636),    //
    S(536, 513),    S(568, 523),    S(579, 578),    S(592, 617),    S(581, 643),    S(572, 612),    S(537, 646),    S(544, 622),    //
    S(520, 517),    S(552, 368),    S(578, 388),    S(590, 496),    S(588, 561),    S(583, 515),    S(572, 543),    S(537, 580),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-111, -302),  S(275, 187),    S(138, 152),    S(4, -5),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(231, -71),    S(320, 225),    S(202, 176),    S(119, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(225, 29),     S(385, 108),    S(286, 104),    S(174, 1),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(94, -6),      S(345, 34),     S(209, 50),     S(122, 19),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -31),    S(235, 1),      S(180, 7),      S(56, 14),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -18),    S(214, -9),     S(123, 3),      S(71, -14),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-8, -16),     S(84, 34),      S(4, 37),       S(-53, 11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-124, -70),   S(-19, -23),    S(-115, -16),   S(-126, -84),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -17), S(-2, 17), S(-6, 19), S(0, 5), S(1, 1), S(-6, 19), S(0, 19), }},
  {{ S(7, -4), S(-20, 30), S(-17, 23), S(-8, 5), S(-7, 5), S(-15, 27), S(-19, 38), }},
  {{ S(-10, -2), S(-21, 22), S(-19, 3), S(-16, -10), S(-16, -8), S(-19, 3), S(-20, 20), }},
  {{ S(2, -15), S(-16, -14), S(-7, -20), S(-0, -25), S(-3, -22), S(-8, -17), S(-11, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(4, 21), S(-20, 36), S(-17, 25), S(-8, 10), S(-10, -6),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, 6), S(-16, 16), S(-14, 13), S(-13, 14), S(-13, 6), S(-12, 3), S(-15, 12), }},
  {{ S(-5, 4), S(-13, 10), S(-20, 17), S(-17, 14), S(-17, 9), S(-18, 12), S(-12, 9), }},
  {{ S(-10, 8), S(-14, 4), S(-16, 12), S(-12, 12), S(-11, 12), S(-15, 9), S(-14, 6), }},
  {{ S(-12, 12), S(-16, 12), S(-17, 13), S(-12, 17), S(-11, 18), S(-16, 13), S(-18, 12), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1166, 537, -32, 51
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(127);
inline VParam WINNABLE_PAWN_ENDGAME = V(224);
inline VParam WINNABLE_BIAS = V(-669);

// Epoch duration: 5.65594s
// clang-format on
}  // namespace Clockwork
