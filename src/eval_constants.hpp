#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(178, 165);
inline const PParam KNIGHT_MAT = S(573, 386);
inline const PParam BISHOP_MAT = S(617, 377);
inline const PParam ROOK_MAT   = S(570, 515);
inline const PParam QUEEN_MAT  = S(1295, 922);
inline const PParam TEMPO_VAL  = S(59, 13);

inline const PParam BISHOP_PAIR_VAL   = S(75, 181);
inline const PParam ROOK_OPEN_VAL     = S(98, -16);
inline const PParam ROOK_SEMIOPEN_VAL = S(37, 25);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -76);

inline const PParam POTENTIAL_CHECKER_VAL = S(-74, -5);
inline const PParam OUTPOST_KNIGHT_VAL    = S(6, 50);
inline const PParam OUTPOST_BISHOP_VAL    = S(31, 19);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 17);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -12);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(36, 35);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(53, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 23), S(62, 34), S(71, 77), S(177, 176), S(532, 452), S(805, 900),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(62, 46), S(59, 31), S(67, 54), S(151, 101), S(609, -54),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(3, 10), S(-19, 43), S(-18, 101), S(21, 157), S(52, 266), S(199, 330),
};
inline const std::array<PParam, 6> CANDIDATE_PASSED_PAWN = {
    S(54, -1), S(-34, -25), S(-102, -45), S(-48, -153), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(-32, -5), S(45, -21), S(43, 19), S(-68, 11), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(41, 35), S(-27, 4), S(11, 6), S(0, 0), S(0, 0), S(0, 0),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-214, -88), S(10, -99), S(107, 5), S(-3, 8), S(-32, -6), S(-47, -46), S(-30, -17),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(5, 25), S(6, -9), S(78, -31), S(-8, -133), S(-172, -65), S(-11, 37), S(-64, -51),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-31, -82), S(74, 82), S(129, 137), S(171, 172), S(217, 190), S(242, 229), S(278, 228), S(312, 232), S(355, 182),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-34, -154), S(39, 29), S(112, 92), S(147, 143), S(177, 174), S(195, 197), S(213, 214), S(231, 222), S(251, 226), S(265, 224), S(290, 213), S(354, 171), S(387, 143), S(448, 115),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(13, 94), S(150, 267), S(201, 333), S(233, 342), S(260, 362), S(274, 383), S(292, 396), S(312, 397), S(330, 406), S(348, 415), S(366, 417), S(381, 415), S(405, 414), S(414, 403), S(548, 284),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-2, 3), S(504, 130), S(607, 202), S(665, 370), S(677, 556), S(716, 653), S(720, 759), S(745, 770), S(751, 824), S(763, 849), S(772, 872), S(778, 887), S(798, 877), S(809, 887), S(816, 881), S(832, 873), S(839, 863), S(841, 866), S(872, 816), S(897, 776), S(918, 749), S(976, 670), S(979, 668), S(1071, 556), S(1049, 551), S(1008, 565), S(825, 619), S(761, 621),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(396, 263), S(148, -73), S(43, -0), S(27, 30), S(-1, 25), S(-34, 14), S(-18, 24), S(-26, 5), S(-22, -62),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(226, 259), S(314, 224), S(384, 176),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(286, 327), S(323, 312), S(423, 277),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(474, 518), S(543, 453), S(532, 441), S(574, 454), S(626, 394),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(775, 818), S(736, 840), S(717, 853), S(771, 799), S(934, 702), S(1084, 599),
};

inline const PParam PAWN_THREAT_KNIGHT = S(237, 59);
inline const PParam PAWN_THREAT_BISHOP = S(205, 102);
inline const PParam PAWN_THREAT_ROOK   = S(208, 58);
inline const PParam PAWN_THREAT_QUEEN  = S(175, -57);

inline const PParam KNIGHT_THREAT_BISHOP = S(104, 72);
inline const PParam KNIGHT_THREAT_ROOK   = S(241, 0);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -78);

inline const PParam BISHOP_THREAT_KNIGHT = S(108, 37);
inline const PParam BISHOP_THREAT_ROOK   = S(239, 54);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 41);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-0, -15), S(-2, -12), S(-1, -22), S(-6, -33), S(-12, -39), S(-18, -46), S(-19, -52), S(-26, -47), S(-35, -50),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(132, 379),    S(94, 427),     S(209, 369),    S(285, 202),    S(257, 188),    S(265, 270),    S(129, 322),    S(189, 303),    //
    S(172, 218),    S(276, 252),    S(263, 174),    S(269, 92),     S(223, 74),     S(178, 138),    S(139, 200),    S(96, 208),     //
    S(103, 164),    S(123, 168),    S(140, 122),    S(127, 102),    S(108, 101),    S(72, 111),     S(34, 165),     S(17, 186),     //
    S(79, 108),     S(97, 137),     S(92, 107),     S(72, 111),     S(46, 104),     S(28, 114),     S(-18, 167),    S(-28, 153),    //
    S(78, 75),      S(140, 75),     S(92, 121),     S(58, 127),     S(37, 120),     S(-0, 124),     S(-14, 140),    S(-31, 132),    //
    S(86, 80),      S(215, 78),     S(170, 117),    S(111, 140),    S(74, 132),     S(39, 133),     S(19, 159),     S(-12, 146),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-274, -35),   S(-231, 187),   S(-306, 339),   S(-11, 191),    S(-136, 213),   S(-222, 225),   S(-436, 198),   S(-415, 107),   //
    S(108, 129),    S(173, 139),    S(278, 66),     S(222, 130),    S(225, 137),    S(166, 111),    S(108, 130),    S(85, 88),      //
    S(164, 101),    S(210, 143),    S(300, 131),    S(252, 152),    S(252, 137),    S(176, 142),    S(165, 121),    S(69, 131),     //
    S(220, 132),    S(212, 152),    S(243, 153),    S(222, 177),    S(232, 163),    S(200, 156),    S(175, 116),    S(151, 121),    //
    S(211, 113),    S(237, 108),    S(233, 130),    S(206, 145),    S(198, 152),    S(195, 145),    S(169, 119),    S(153, 66),     //
    S(125, 98),     S(156, 82),     S(152, 102),    S(162, 145),    S(169, 143),    S(113, 119),    S(118, 83),     S(78, 77),      //
    S(124, 120),    S(147, 82),     S(133, 86),     S(132, 108),    S(120, 103),    S(93, 81),      S(102, 75),     S(46, 9),       //
    S(77, 72),      S(116, 107),    S(134, 83),     S(143, 88),     S(135, 96),     S(90, 66),      S(76, 92),      S(26, 45),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-64, 209),    S(-87, 187),    S(-319, 211),   S(-202, 227),   S(-164, 235),   S(-322, 262),   S(-74, 239),    S(-22, 209),    //
    S(101, 101),    S(85, 171),     S(108, 151),    S(88, 148),     S(61, 171),     S(97, 165),     S(76, 150),     S(42, 154),     //
    S(128, 157),    S(177, 148),    S(254, 148),    S(185, 149),    S(161, 150),    S(136, 160),    S(194, 139),    S(93, 156),     //
    S(145, 113),    S(159, 144),    S(195, 145),    S(194, 167),    S(201, 165),    S(139, 164),    S(130, 141),    S(83, 145),     //
    S(147, 85),     S(154, 123),    S(163, 136),    S(163, 158),    S(155, 174),    S(115, 169),    S(102, 128),    S(97, 86),      //
    S(159, 93),     S(199, 101),    S(205, 116),    S(147, 155),    S(129, 164),    S(130, 158),    S(158, 113),    S(125, 95),     //
    S(145, 65),     S(196, 78),     S(166, 92),     S(140, 123),    S(131, 109),    S(132, 99),     S(113, 113),    S(131, 53),     //
    S(141, 84),     S(129, 126),    S(135, 130),    S(145, 96),     S(154, 85),     S(150, 125),    S(142, 101),    S(123, 99),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(410, 334),    S(475, 334),    S(405, 365),    S(410, 351),    S(423, 332),    S(372, 344),    S(383, 344),    S(392, 348),    //
    S(323, 391),    S(412, 370),    S(483, 351),    S(414, 386),    S(432, 368),    S(382, 374),    S(323, 390),    S(317, 393),    //
    S(312, 364),    S(462, 329),    S(490, 321),    S(497, 307),    S(450, 314),    S(378, 354),    S(397, 340),    S(284, 383),    //
    S(287, 348),    S(362, 350),    S(394, 339),    S(418, 298),    S(388, 316),    S(330, 361),    S(312, 361),    S(245, 363),    //
    S(225, 299),    S(305, 306),    S(291, 325),    S(276, 321),    S(271, 316),    S(254, 355),    S(226, 352),    S(208, 339),    //
    S(204, 273),    S(277, 248),    S(272, 279),    S(252, 281),    S(270, 261),    S(220, 317),    S(219, 300),    S(196, 293),    //
    S(139, 291),    S(239, 224),    S(264, 240),    S(268, 246),    S(262, 252),    S(243, 267),    S(223, 244),    S(192, 260),    //
    S(175, 291),    S(205, 294),    S(258, 258),    S(283, 242),    S(269, 258),    S(257, 270),    S(242, 261),    S(224, 277),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(656, 626),    S(693, 607),    S(701, 610),    S(597, 727),    S(649, 664),    S(600, 681),    S(650, 613),    S(586, 628),    //
    S(613, 716),    S(538, 821),    S(543, 862),    S(468, 874),    S(487, 833),    S(471, 833),    S(518, 743),    S(561, 666),    //
    S(569, 752),    S(656, 761),    S(601, 821),    S(586, 830),    S(546, 806),    S(514, 806),    S(584, 703),    S(557, 659),    //
    S(639, 655),    S(641, 731),    S(604, 769),    S(593, 827),    S(573, 809),    S(566, 741),    S(604, 645),    S(597, 597),    //
    S(604, 679),    S(636, 649),    S(610, 720),    S(570, 776),    S(558, 764),    S(566, 720),    S(580, 634),    S(584, 580),    //
    S(614, 520),    S(638, 567),    S(637, 640),    S(584, 667),    S(595, 628),    S(600, 629),    S(610, 559),    S(590, 556),    //
    S(598, 418),    S(631, 315),    S(617, 456),    S(634, 532),    S(608, 552),    S(625, 484),    S(599, 545),    S(583, 542),    //
    S(545, 498),    S(605, 249),    S(599, 261),    S(627, 353),    S(629, 440),    S(632, 397),    S(619, 436),    S(566, 510),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-166, -380),  S(73, 16),      S(-24, 33),     S(-123, 55),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(157, -86),    S(-20, 212),    S(48, 181),     S(180, 101),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-47, 71),     S(56, 196),     S(140, 155),    S(151, 104),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-262, 82),    S(24, 143),     S(48, 140),     S(32, 120),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-235, 43),    S(-63, 112),    S(-33, 119),    S(-90, 156),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-148, 1),     S(33, 36),      S(-59, 98),     S(-92, 131),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(59, -97),     S(107, -31),    S(17, 26),      S(-64, 76),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-64, -155),   S(61, -115),    S(-39, -77),    S(-56, -76),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 7.33858s
// clang-format on
}  // namespace Clockwork
