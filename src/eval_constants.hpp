#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(135, 212);
inline const PParam KNIGHT_MAT = S(644, 727);
inline const PParam BISHOP_MAT = S(641, 699);
inline const PParam ROOK_MAT   = S(501, 765);
inline const PParam QUEEN_MAT  = S(1192, 1178);
inline const PParam TEMPO_VAL  = S(61, 31);

inline const PParam BISHOP_PAIR_VAL   = S(54, 200);
inline const PParam ROOK_OPEN_VAL     = S(111, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(49, 10);
inline const PParam SEE_CONTROL_VALUE = S(-3, -6);
inline const PParam SEE_STABLE_PIECES_VALUE = S(7, -0);
inline const PParam SEE_RESTRICTED_SQUARES = S(11, -0);

inline const PParam DOUBLED_PAWN_VAL = S(-8, -68);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(33, 60);
inline const PParam OUTPOST_BISHOP_VAL    = S(38, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 37);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -13);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 49);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(64, -36);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 1), S(37, 32), S(62, 51), S(144, 144), S(368, 216), S(455, 698),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(50, 23), S(41, 14), S(50, 39), S(111, 125), S(409, 57),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-73, -118), S(-68, -98), S(-45, 10), S(7, 117), S(92, 263), S(261, 386),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(38, -45), S(34, -2), S(22, 34), S(-3, 114), S(43, 223), S(160, 293),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(19, -39), S(1, 9), S(2, -19), S(-5, -51), S(-13, -120), S(-210, -235),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 148), S(-16, 113), S(-13, 47), S(-6, 10), S(1, 8), S(37, 6), S(8, 3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-312, -37), S(-40, 24), S(-23, 59), S(12, 97), S(30, 114), S(48, 115), S(31, 108),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(3, -66), S(77, 111), S(112, 203), S(139, 240), S(176, 262), S(196, 295), S(223, 296), S(248, 313), S(296, 238),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(52, -47), S(98, 129), S(156, 197), S(185, 243), S(210, 279), S(227, 306), S(234, 330), S(246, 350), S(251, 375), S(276, 366), S(285, 380), S(332, 340), S(329, 364), S(355, 332),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(318, 198), S(211, 381), S(236, 408), S(254, 420), S(265, 433), S(272, 445), S(278, 457), S(287, 461), S(293, 475), S(304, 480), S(314, 486), S(322, 493), S(329, 495), S(347, 477), S(432, 382),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(491, 465), S(609, 511), S(634, 623), S(654, 730), S(671, 773), S(682, 815), S(689, 847), S(698, 856), S(703, 881), S(707, 895), S(715, 903), S(720, 913), S(730, 909), S(732, 918), S(739, 916), S(736, 926), S(740, 925), S(746, 926), S(753, 923), S(764, 920), S(771, 906), S(799, 865), S(792, 874), S(792, 825), S(778, 815), S(771, 798), S(709, 858), S(737, 760),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(493, -208), S(99, -108), S(25, -30), S(15, 4), S(-1, 5), S(-16, -3), S(-20, 9), S(-36, 21), S(-26, -13),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(15, -15), S(13, -12), S(5, -8), S(2, 314),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -10), S(6, -8), S(5, -5), S(6, 630),
};

inline const PParam PAWN_THREAT_KNIGHT = S(174, 42);
inline const PParam PAWN_THREAT_BISHOP = S(151, 88);
inline const PParam PAWN_THREAT_ROOK   = S(165, 73);
inline const PParam PAWN_THREAT_QUEEN  = S(76, 6);

inline const PParam KNIGHT_THREAT_BISHOP = S(85, 58);
inline const PParam KNIGHT_THREAT_ROOK   = S(205, 23);
inline const PParam KNIGHT_THREAT_QUEEN  = S(88, 2);

inline const PParam BISHOP_THREAT_KNIGHT = S(102, 48);
inline const PParam BISHOP_THREAT_ROOK   = S(196, 84);
inline const PParam BISHOP_THREAT_QUEEN  = S(116, 133);

inline const PParam HANGING_PAWN = S(11, -63);
inline const PParam HANGING_KNIGHT = S(-34, -75);
inline const PParam HANGING_BISHOP = S(-26, -55);
inline const PParam HANGING_ROOK = S(-20, -56);
inline const PParam HANGING_QUEEN = S(-88, 14);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(12, -31), S(-2, -4), S(-5, -13), S(-8, -23), S(-13, -34), S(-18, -40), S(-20, -53), S(-28, -50), S(-39, -51),
};

inline const PParam ROOK_LINEUP = S(11, 61);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 338),    S(141, 448),    S(281, 421),    S(285, 293),    S(310, 246),    S(205, 330),    S(149, 365),    S(264, 307),    //
    S(116, 212),    S(142, 259),    S(181, 174),    S(162, 114),    S(144, 97),     S(119, 152),    S(95, 205),     S(52, 221),     //
    S(82, 174),     S(66, 181),     S(110, 106),    S(109, 85),     S(97, 82),      S(70, 117),     S(20, 167),     S(14, 189),     //
    S(52, 126),     S(40, 153),     S(73, 99),      S(70, 91),      S(48, 95),      S(31, 123),     S(-26, 167),    S(-23, 154),    //
    S(51, 98),      S(86, 109),     S(69, 139),     S(63, 126),     S(35, 123),     S(14, 130),     S(-20, 148),    S(-23, 136),    //
    S(63, 97),      S(151, 119),    S(137, 175),    S(86, 157),     S(58, 144),     S(40, 140),     S(11, 155),     S(-5, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-256, -108),  S(-158, 153),   S(-112, 15),    S(88, 140),     S(14, 152),     S(-118, 149),   S(-244, 196),   S(-290, -42),   //
    S(64, 129),     S(99, 156),     S(191, 124),    S(190, 131),    S(180, 141),    S(95, 171),     S(60, 167),     S(34, 149),     //
    S(136, 121),    S(184, 125),    S(185, 178),    S(174, 162),    S(133, 195),    S(80, 218),     S(95, 166),     S(61, 146),     //
    S(204, 140),    S(206, 159),    S(207, 190),    S(199, 215),    S(198, 229),    S(151, 216),    S(136, 185),    S(136, 153),    //
    S(190, 144),    S(220, 129),    S(196, 186),    S(189, 209),    S(168, 218),    S(166, 201),    S(158, 152),    S(124, 155),    //
    S(127, 112),    S(154, 125),    S(143, 164),    S(153, 191),    S(149, 191),    S(115, 170),    S(102, 139),    S(72, 109),     //
    S(141, 122),    S(167, 116),    S(133, 132),    S(132, 153),    S(124, 149),    S(98, 109),     S(84, 124),     S(69, 50),      //
    S(74, 70),      S(118, 140),    S(133, 106),    S(150, 95),     S(132, 115),    S(99, 89),      S(86, 118),     S(49, 38),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(2, 286),      S(-11, 286),    S(-264, 330),   S(-135, 263),   S(-138, 282),   S(-160, 288),   S(-48, 283),    S(38, 259),     //
    S(115, 211),    S(66, 270),     S(98, 223),     S(51, 238),     S(63, 236),     S(86, 236),     S(119, 235),    S(95, 222),     //
    S(184, 234),    S(194, 235),    S(191, 241),    S(166, 242),    S(140, 233),    S(144, 244),    S(159, 235),    S(156, 220),    //
    S(152, 219),    S(194, 222),    S(195, 235),    S(186, 263),    S(214, 251),    S(150, 237),    S(164, 212),    S(118, 219),    //
    S(184, 170),    S(195, 204),    S(204, 218),    S(209, 240),    S(186, 250),    S(167, 241),    S(131, 230),    S(133, 190),    //
    S(207, 181),    S(232, 186),    S(245, 213),    S(196, 235),    S(193, 219),    S(183, 230),    S(187, 211),    S(133, 217),    //
    S(169, 153),    S(264, 174),    S(224, 185),    S(193, 206),    S(174, 208),    S(177, 185),    S(175, 184),    S(172, 179),    //
    S(202, 154),    S(186, 177),    S(183, 217),    S(200, 174),    S(189, 187),    S(192, 227),    S(188, 202),    S(182, 179),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(429, 395),    S(440, 415),    S(417, 426),    S(433, 395),    S(423, 393),    S(386, 408),    S(380, 426),    S(373, 429),    //
    S(310, 459),    S(382, 450),    S(451, 412),    S(400, 413),    S(384, 424),    S(364, 436),    S(304, 467),    S(287, 479),    //
    S(286, 455),    S(384, 437),    S(442, 394),    S(422, 387),    S(376, 416),    S(332, 442),    S(337, 440),    S(271, 483),    //
    S(282, 423),    S(358, 418),    S(396, 389),    S(373, 397),    S(361, 413),    S(320, 437),    S(318, 432),    S(245, 468),    //
    S(262, 357),    S(326, 361),    S(315, 380),    S(292, 387),    S(270, 411),    S(259, 426),    S(230, 424),    S(212, 425),    //
    S(246, 300),    S(306, 321),    S(293, 345),    S(280, 348),    S(267, 361),    S(239, 388),    S(240, 361),    S(207, 373),    //
    S(138, 315),    S(269, 277),    S(280, 308),    S(271, 332),    S(256, 340),    S(248, 347),    S(231, 335),    S(208, 348),    //
    S(204, 296),    S(225, 317),    S(279, 306),    S(293, 306),    S(282, 317),    S(263, 333),    S(253, 330),    S(233, 338),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(533, 642),    S(589, 589),    S(515, 717),    S(486, 785),    S(479, 762),    S(508, 715),    S(522, 636),    S(468, 681),    //
    S(546, 668),    S(522, 749),    S(513, 774),    S(365, 874),    S(384, 848),    S(445, 803),    S(489, 677),    S(481, 683),    //
    S(499, 753),    S(565, 745),    S(506, 843),    S(462, 860),    S(434, 861),    S(484, 778),    S(509, 708),    S(514, 653),    //
    S(539, 662),    S(546, 748),    S(497, 797),    S(485, 832),    S(476, 835),    S(489, 744),    S(524, 693),    S(500, 678),    //
    S(539, 642),    S(536, 694),    S(508, 744),    S(477, 794),    S(479, 791),    S(478, 753),    S(493, 688),    S(516, 621),    //
    S(511, 583),    S(540, 624),    S(535, 691),    S(502, 702),    S(501, 698),    S(493, 729),    S(508, 652),    S(493, 622),    //
    S(479, 488),    S(514, 494),    S(517, 562),    S(532, 608),    S(518, 643),    S(516, 608),    S(478, 650),    S(493, 632),    //
    S(458, 499),    S(486, 353),    S(508, 375),    S(523, 489),    S(517, 570),    S(518, 521),    S(508, 547),    S(480, 571),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-90, -325),   S(250, 188),    S(127, 141),    S(-6, -19),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(187, -51),    S(326, 162),    S(184, 153),    S(104, 0),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(200, 35),     S(364, 108),    S(259, 106),    S(153, 3),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(60, 2),       S(315, 47),     S(168, 67),     S(111, 26),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-38, -21),    S(214, 17),     S(148, 21),     S(36, 26),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-31, -13),    S(199, 10),     S(108, 14),     S(58, -5),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-10, -16),    S(70, 47),      S(-13, 45),     S(-70, 17),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-119, -77),   S(-29, -17),    S(-127, -13),   S(-126, -85),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(26, -13), S(8, 24), S(4, 25), S(11, 10), S(11, 7), S(4, 24), S(10, 24), }},
  {{ S(16, -4), S(-12, 28), S(-8, 22), S(1, 4), S(2, 5), S(-8, 27), S(-11, 37), }},
  {{ S(2, 7), S(-9, 32), S(-8, 12), S(-4, -2), S(-3, -0), S(-7, 12), S(-8, 28), }},
  {{ S(12, -14), S(-6, -15), S(2, -19), S(8, -22), S(6, -21), S(1, -16), S(-2, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 660), S(-9, 31), S(-6, 19), S(2, 7), S(2, -10),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, -1), S(-5, 8), S(-4, 8), S(-3, 8), S(-3, 2), S(-2, -2), S(-5, 6), }},
  {{ S(6, 0), S(-2, 7), S(-8, 12), S(-6, 11), S(-5, 7), S(-7, 9), S(-1, 6), }},
  {{ S(0, 3), S(-4, 0), S(-6, 8), S(-2, 8), S(-1, 7), S(-5, 6), S(-4, 1), }},
  {{ S(-0, 6), S(-5, 7), S(-6, 7), S(-2, 12), S(0, 12), S(-6, 7), S(-7, 7), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1179, 528, -93, 52
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(225);
inline VParam WINNABLE_BIAS = V(-662);

// Epoch duration: 8.37888s

// Epoch duration: 8.75036s
// clang-format on
}  // namespace Clockwork
