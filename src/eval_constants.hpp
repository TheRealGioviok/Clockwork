#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(136, 203);
inline const PParam KNIGHT_MAT = S(576, 634);
inline const PParam BISHOP_MAT = S(605, 653);
inline const PParam ROOK_MAT   = S(470, 684);
inline const PParam QUEEN_MAT  = S(1088, 1092);
inline const PParam TEMPO_VAL  = S(57, 22);

inline const PParam BISHOP_PAIR_VAL   = S(53, 196);
inline const PParam ROOK_OPEN_VAL     = S(105, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 20);

inline const PParam DOUBLED_PAWN_VAL = S(-6, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 67);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 42);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 8);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 57);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -35);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 1), S(38, 28), S(58, 51), S(135, 145), S(384, 189), S(507, 632),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 35), S(44, 27), S(53, 54), S(119, 136), S(419, 76),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-65, -125), S(-64, -101), S(-45, 9), S(9, 116), S(89, 263), S(258, 381),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(35, -42), S(35, -7), S(24, 26), S(2, 103), S(46, 214), S(193, 282),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(22, -35), S(3, 11), S(3, -22), S(-0, -54), S(-6, -127), S(-210, -230),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 142), S(-15, 106), S(-12, 40), S(-5, 5), S(1, 4), S(38, 5), S(11, 2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-300, -55), S(-37, 26), S(-23, 58), S(13, 91), S(28, 107), S(44, 108), S(25, 99),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(59, -5), S(129, 167), S(164, 256), S(191, 293), S(232, 311), S(256, 346), S(288, 343), S(319, 357), S(371, 271),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(94, -1), S(136, 173), S(191, 236), S(217, 281), S(242, 313), S(258, 337), S(265, 357), S(279, 367), S(285, 385), S(310, 366), S(320, 369), S(368, 317), S(364, 333), S(394, 279),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(308, 246), S(229, 423), S(254, 447), S(271, 457), S(282, 470), S(288, 480), S(295, 491), S(303, 493), S(309, 504), S(321, 505), S(332, 507), S(339, 512), S(344, 511), S(362, 482), S(438, 389),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(488, 530), S(632, 535), S(656, 647), S(674, 759), S(690, 806), S(699, 849), S(705, 882), S(712, 892), S(716, 916), S(719, 931), S(724, 939), S(729, 945), S(738, 939), S(740, 945), S(745, 939), S(743, 944), S(745, 940), S(751, 933), S(757, 925), S(767, 918), S(775, 894), S(797, 855), S(793, 856), S(794, 799), S(780, 787), S(773, 757), S(717, 792), S(732, 717),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(495, -172), S(107, -108), S(28, -26), S(16, 6), S(-4, 5), S(-20, -1), S(-26, 8), S(-41, 15), S(-31, -24),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(16, -15), S(13, -12), S(6, -8), S(2, 228),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 428),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 96);
inline const PParam PAWN_THREAT_BISHOP = S(189, 145);
inline const PParam PAWN_THREAT_ROOK   = S(190, 128);
inline const PParam PAWN_THREAT_QUEEN  = S(168, -21);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(224, 70);
inline const PParam KNIGHT_THREAT_QUEEN  = S(149, 1);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(174, 101);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -37), S(-4, -8), S(-6, -17), S(-10, -27), S(-14, -37), S(-19, -42), S(-21, -54), S(-28, -52), S(-39, -52),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(295, 344),    S(137, 444),    S(289, 409),    S(294, 283),    S(325, 231),    S(212, 321),    S(151, 355),    S(264, 310),    //
    S(116, 214),    S(147, 252),    S(188, 167),    S(173, 103),    S(153, 87),     S(126, 140),    S(98, 196),     S(50, 222),     //
    S(82, 175),     S(69, 176),     S(112, 101),    S(113, 79),     S(100, 77),     S(73, 109),     S(25, 159),     S(13, 188),     //
    S(58, 126),     S(48, 149),     S(85, 95),      S(80, 89),      S(59, 92),      S(42, 117),     S(-18, 161),    S(-18, 154),    //
    S(58, 99),      S(96, 106),     S(82, 136),     S(74, 122),     S(45, 118),     S(23, 124),     S(-12, 143),    S(-20, 137),    //
    S(70, 101),     S(160, 116),    S(146, 170),    S(96, 154),     S(67, 141),     S(46, 136),     S(16, 149),     S(-2, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-252, -78),   S(-155, 192),   S(-93, 39),     S(93, 181),     S(29, 185),     S(-115, 186),   S(-252, 241),   S(-286, -13),   //
    S(70, 162),     S(116, 184),    S(205, 142),    S(205, 144),    S(200, 151),    S(110, 185),    S(73, 201),     S(48, 177),     //
    S(159, 153),    S(210, 142),    S(207, 206),    S(209, 189),    S(169, 224),    S(109, 239),    S(120, 185),    S(83, 182),     //
    S(226, 177),    S(235, 195),    S(231, 219),    S(219, 248),    S(219, 258),    S(174, 244),    S(166, 214),    S(161, 185),    //
    S(211, 177),    S(244, 164),    S(215, 219),    S(210, 240),    S(187, 243),    S(183, 231),    S(182, 178),    S(144, 185),    //
    S(155, 145),    S(179, 156),    S(170, 194),    S(178, 220),    S(174, 219),    S(138, 199),    S(128, 167),    S(99, 136),     //
    S(164, 152),    S(186, 148),    S(155, 155),    S(156, 179),    S(147, 177),    S(120, 135),    S(107, 156),    S(95, 72),      //
    S(100, 102),    S(146, 167),    S(162, 133),    S(178, 125),    S(159, 149),    S(126, 121),    S(111, 146),    S(74, 66),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-1, 288),     S(-18, 303),    S(-272, 336),   S(-140, 277),   S(-149, 296),   S(-162, 294),   S(-50, 295),    S(31, 269),     //
    S(118, 204),    S(61, 282),     S(96, 234),     S(44, 249),     S(58, 251),     S(83, 252),     S(116, 254),    S(95, 229),     //
    S(190, 233),    S(204, 244),    S(196, 253),    S(172, 254),    S(144, 248),    S(151, 259),    S(166, 250),    S(165, 217),    //
    S(160, 226),    S(195, 234),    S(196, 256),    S(194, 292),    S(223, 282),    S(155, 256),    S(167, 223),    S(127, 220),    //
    S(189, 181),    S(203, 218),    S(210, 239),    S(214, 268),    S(190, 283),    S(176, 260),    S(144, 236),    S(140, 194),    //
    S(215, 190),    S(248, 204),    S(259, 231),    S(204, 257),    S(201, 234),    S(194, 247),    S(201, 223),    S(141, 221),    //
    S(182, 161),    S(280, 180),    S(237, 195),    S(204, 212),    S(184, 216),    S(188, 192),    S(188, 191),    S(181, 186),    //
    S(212, 166),    S(199, 184),    S(199, 217),    S(213, 179),    S(202, 191),    S(202, 233),    S(199, 212),    S(191, 187),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(425, 384),    S(433, 408),    S(412, 420),    S(430, 381),    S(412, 386),    S(378, 396),    S(374, 413),    S(370, 413),    //
    S(303, 465),    S(377, 464),    S(455, 428),    S(398, 436),    S(384, 444),    S(364, 447),    S(297, 478),    S(280, 485),    //
    S(271, 463),    S(375, 447),    S(427, 414),    S(408, 399),    S(363, 425),    S(322, 447),    S(322, 447),    S(255, 489),    //
    S(278, 420),    S(352, 432),    S(389, 404),    S(361, 410),    S(353, 420),    S(313, 443),    S(309, 439),    S(234, 467),    //
    S(259, 354),    S(323, 373),    S(310, 396),    S(291, 389),    S(268, 413),    S(257, 428),    S(226, 423),    S(207, 420),    //
    S(250, 298),    S(311, 326),    S(297, 352),    S(282, 351),    S(271, 357),    S(246, 378),    S(242, 355),    S(206, 363),    //
    S(144, 307),    S(276, 272),    S(286, 303),    S(276, 326),    S(261, 331),    S(253, 336),    S(235, 321),    S(209, 333),    //
    S(208, 294),    S(231, 314),    S(287, 304),    S(299, 300),    S(288, 308),    S(268, 325),    S(257, 320),    S(238, 329),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(560, 642),    S(604, 604),    S(530, 724),    S(500, 789),    S(483, 773),    S(518, 717),    S(542, 637),    S(497, 672),    //
    S(557, 701),    S(518, 802),    S(508, 834),    S(365, 927),    S(379, 904),    S(436, 863),    S(482, 734),    S(493, 713),    //
    S(520, 770),    S(567, 790),    S(500, 892),    S(450, 907),    S(425, 902),    S(476, 821),    S(513, 739),    S(533, 659),    //
    S(562, 682),    S(562, 778),    S(502, 842),    S(492, 876),    S(484, 875),    S(494, 782),    S(539, 712),    S(522, 683),    //
    S(575, 653),    S(562, 726),    S(532, 785),    S(502, 827),    S(501, 828),    S(507, 766),    S(523, 691),    S(550, 613),    //
    S(555, 595),    S(588, 651),    S(580, 716),    S(551, 707),    S(546, 700),    S(541, 722),    S(557, 639),    S(536, 612),    //
    S(536, 484),    S(574, 495),    S(576, 568),    S(589, 603),    S(576, 628),    S(569, 595),    S(534, 630),    S(543, 611),    //
    S(519, 496),    S(550, 350),    S(574, 369),    S(588, 478),    S(583, 554),    S(582, 500),    S(570, 525),    S(539, 553),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-64, -301),   S(288, 171),    S(153, 143),    S(19, -12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(223, -51),    S(347, 155),    S(202, 153),    S(114, 14),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(216, 40),     S(377, 109),    S(266, 113),    S(158, 16),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(76, 3),       S(327, 48),     S(185, 67),     S(121, 31),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -22),    S(231, 9),      S(161, 19),     S(45, 27),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-22, -18),    S(215, -5),     S(119, 7),      S(65, -9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-2, -19),     S(84, 34),      S(-0, 38),      S(-57, 12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-116, -69),   S(-16, -24),    S(-116, -15),   S(-120, -86),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -16), S(-3, 20), S(-7, 22), S(1, 8), S(1, 4), S(-6, 21), S(-1, 21), }},
  {{ S(5, -3), S(-22, 30), S(-19, 24), S(-9, 6), S(-9, 6), S(-18, 28), S(-21, 38), }},
  {{ S(-11, 5), S(-22, 30), S(-20, 12), S(-17, -2), S(-16, -1), S(-20, 12), S(-20, 27), }},
  {{ S(1, -13), S(-17, -14), S(-8, -18), S(-3, -22), S(-4, -20), S(-9, -15), S(-12, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, 26), S(-19, 34), S(-16, 22), S(-9, 10), S(-9, -7),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, 3), S(-15, 12), S(-14, 10), S(-13, 11), S(-13, 5), S(-12, 1), S(-15, 10), }},
  {{ S(-4, 2), S(-12, 9), S(-19, 14), S(-15, 12), S(-15, 7), S(-17, 10), S(-11, 8), }},
  {{ S(-10, 7), S(-15, 4), S(-16, 11), S(-12, 12), S(-11, 10), S(-16, 10), S(-15, 6), }},
  {{ S(-11, 8), S(-16, 10), S(-17, 10), S(-12, 14), S(-10, 14), S(-16, 10), S(-18, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1167, 536, -30, 46
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_PASSERS = V(40);
inline VParam WINNABLE_SYM = V(147);
inline VParam WINNABLE_ASYM = V(115);
inline VParam WINNABLE_PAWN_ENDGAME = V(236);
inline VParam WINNABLE_BIAS = V(-707);

// Epoch duration: 7.5738s
// clang-format on
}  // namespace Clockwork
