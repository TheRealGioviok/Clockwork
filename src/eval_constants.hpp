#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(177, 163);
inline const PParam KNIGHT_MAT = S(744, 541);
inline const PParam BISHOP_MAT = S(784, 538);
inline const PParam ROOK_MAT   = S(747, 699);
inline const PParam QUEEN_MAT  = S(1628, 1195);
inline const PParam TEMPO_VAL  = S(59, 12);

inline const PParam BISHOP_PAIR_VAL   = S(74, 178);
inline const PParam ROOK_OPEN_VAL     = S(96, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(36, 25);

inline const PParam DOUBLED_PAWN_VAL = S(-35, -76);

inline const PParam POTENTIAL_CHECKER_VAL = S(-76, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(6, 49);
inline const PParam OUTPOST_BISHOP_VAL    = S(31, 18);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 17);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -13);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(35, 35);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(51, -45);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 22), S(61, 34), S(70, 76), S(175, 173), S(526, 440), S(771, 869),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(62, 45), S(59, 30), S(66, 53), S(150, 98), S(601, -56),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(2, 10), S(-19, 43), S(-18, 100), S(21, 155), S(52, 261), S(198, 323),
};
inline const std::array<PParam, 6> CANDIDATE_PASSED_PAWN = {
    S(48, -5), S(-39, -28), S(-107, -43), S(-43, -159), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(-29, 1), S(43, -22), S(32, 45), S(-78, 2), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(43, 37), S(-31, 2), S(11, 5), S(0, 0), S(0, 0), S(0, 0),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-232, -95), S(25, -84), S(116, -21), S(-5, 11), S(-29, -9), S(-42, -36), S(-34, -19),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(5, 26), S(1, -11), S(75, -22), S(-11, -142), S(-162, -77), S(-19, 36), S(-65, -53),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(0, -24), S(104, 136), S(158, 190), S(200, 225), S(245, 243), S(271, 282), S(306, 280), S(339, 284), S(383, 233),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(28, -68), S(99, 111), S(172, 174), S(206, 224), S(237, 256), S(254, 278), S(272, 295), S(290, 303), S(310, 307), S(324, 305), S(348, 294), S(412, 251), S(444, 225), S(505, 196),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(163, 230), S(291, 421), S(342, 487), S(374, 496), S(401, 515), S(415, 536), S(432, 549), S(452, 550), S(470, 558), S(487, 567), S(505, 569), S(521, 567), S(544, 565), S(554, 554), S(685, 438),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-2, 2), S(730, 355), S(824, 491), S(883, 655), S(895, 835), S(935, 928), S(940, 1030), S(966, 1038), S(972, 1089), S(984, 1112), S(994, 1134), S(1001, 1146), S(1021, 1134), S(1034, 1141), S(1042, 1132), S(1059, 1120), S(1069, 1106), S(1075, 1102), S(1108, 1046), S(1138, 999), S(1164, 964), S(1234, 871), S(1237, 866), S(1334, 744), S(1294, 749), S(1255, 745), S(1018, 814), S(927, 795),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(392, 261), S(146, -73), S(42, -2), S(26, 27), S(-2, 23), S(-34, 12), S(-17, 21), S(-25, 2), S(-21, -64),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(0, 0), S(87, -32), S(157, -79),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(0, 0), S(35, -13), S(135, -48),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(0, 0), S(67, -61), S(53, -70), S(92, -55), S(135, -109),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(0, 0), S(-52, 59), S(-85, 95), S(-49, 69), S(82, 9), S(204, -70),
};

inline const PParam PAWN_THREAT_KNIGHT = S(235, 57);
inline const PParam PAWN_THREAT_BISHOP = S(203, 100);
inline const PParam PAWN_THREAT_ROOK   = S(206, 57);
inline const PParam PAWN_THREAT_QUEEN  = S(175, -61);

inline const PParam KNIGHT_THREAT_BISHOP = S(103, 70);
inline const PParam KNIGHT_THREAT_ROOK   = S(239, -1);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -82);

inline const PParam BISHOP_THREAT_KNIGHT = S(107, 36);
inline const PParam BISHOP_THREAT_ROOK   = S(237, 52);
inline const PParam BISHOP_THREAT_QUEEN  = S(193, 31);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-0, -14), S(-2, -11), S(-1, -21), S(-7, -32), S(-12, -38), S(-18, -45), S(-19, -52), S(-26, -46), S(-35, -48),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(132, 370),    S(96, 418),     S(208, 363),    S(281, 199),    S(253, 185),    S(261, 266),    S(128, 316),    S(188, 297),    //
    S(169, 214),    S(273, 247),    S(260, 171),    S(264, 91),     S(219, 74),     S(175, 136),    S(137, 197),    S(94, 205),     //
    S(101, 161),    S(120, 165),    S(138, 119),    S(124, 99),     S(106, 99),     S(70, 109),     S(32, 162),     S(16, 183),     //
    S(78, 105),     S(94, 134),     S(90, 104),     S(70, 108),     S(44, 102),     S(26, 112),     S(-19, 164),    S(-29, 151),    //
    S(76, 73),      S(137, 72),     S(89, 117),     S(56, 124),     S(35, 117),     S(-2, 121),     S(-16, 137),    S(-32, 130),    //
    S(84, 78),      S(210, 75),     S(166, 114),    S(108, 136),    S(71, 128),     S(37, 130),     S(17, 156),     S(-13, 144),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-255, -2),    S(-209, 210),   S(-273, 348),   S(4, 214),      S(-118, 236),   S(-201, 246),   S(-407, 217),   S(-391, 136),   //
    S(119, 155),    S(183, 165),    S(286, 94),     S(233, 154),    S(234, 162),    S(177, 138),    S(119, 156),    S(96, 115),     //
    S(175, 127),    S(221, 165),    S(307, 157),    S(261, 177),    S(261, 163),    S(185, 170),    S(175, 147),    S(81, 157),     //
    S(230, 157),    S(223, 177),    S(252, 179),    S(233, 202),    S(240, 189),    S(210, 183),    S(185, 142),    S(161, 147),    //
    S(221, 138),    S(245, 134),    S(242, 155),    S(215, 171),    S(207, 178),    S(204, 171),    S(179, 146),    S(163, 92),     //
    S(136, 123),    S(167, 108),    S(163, 127),    S(173, 171),    S(179, 168),    S(124, 145),    S(129, 109),    S(90, 104),     //
    S(135, 145),    S(158, 108),    S(144, 112),    S(143, 133),    S(131, 128),    S(105, 107),    S(113, 101),    S(58, 37),      //
    S(88, 100),     S(128, 133),    S(145, 108),    S(154, 113),    S(146, 121),    S(101, 92),     S(87, 118),     S(38, 74),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-18, 264),    S(-41, 243),    S(-267, 265),   S(-152, 281),   S(-114, 289),   S(-271, 315),   S(-27, 293),    S(26, 263),     //
    S(145, 159),    S(129, 227),    S(153, 207),    S(133, 204),    S(106, 227),    S(141, 221),    S(120, 206),    S(86, 210),     //
    S(172, 213),    S(220, 204),    S(296, 205),    S(227, 205),    S(203, 207),    S(179, 217),    S(237, 196),    S(136, 213),    //
    S(187, 170),    S(202, 200),    S(237, 202),    S(236, 223),    S(243, 221),    S(182, 221),    S(173, 198),    S(126, 202),    //
    S(189, 142),    S(196, 179),    S(205, 193),    S(205, 215),    S(197, 231),    S(158, 225),    S(145, 185),    S(140, 144),    //
    S(202, 150),    S(241, 158),    S(247, 172),    S(189, 212),    S(172, 220),    S(172, 215),    S(200, 170),    S(168, 153),    //
    S(188, 123),    S(239, 135),    S(208, 149),    S(182, 179),    S(173, 166),    S(174, 156),    S(156, 171),    S(174, 111),    //
    S(184, 142),    S(171, 183),    S(178, 186),    S(188, 152),    S(197, 142),    S(193, 182),    S(184, 159),    S(166, 158),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(543, 474),    S(608, 473),    S(538, 503),    S(544, 490),    S(557, 471),    S(505, 483),    S(517, 482),    S(527, 487),    //
    S(460, 529),    S(548, 508),    S(618, 489),    S(551, 522),    S(568, 505),    S(519, 511),    S(461, 527),    S(455, 529),    //
    S(448, 502),    S(597, 468),    S(625, 460),    S(632, 446),    S(585, 453),    S(515, 492),    S(533, 478),    S(422, 521),    //
    S(423, 487),    S(498, 488),    S(531, 477),    S(553, 436),    S(524, 455),    S(467, 499),    S(449, 499),    S(382, 502),    //
    S(362, 438),    S(441, 444),    S(427, 462),    S(412, 459),    S(407, 454),    S(391, 494),    S(363, 491),    S(345, 478),    //
    S(342, 412),    S(414, 387),    S(409, 417),    S(389, 419),    S(406, 400),    S(357, 455),    S(356, 438),    S(334, 432),    //
    S(278, 430),    S(376, 363),    S(401, 378),    S(405, 384),    S(399, 391),    S(380, 406),    S(360, 383),    S(330, 399),    //
    S(312, 431),    S(343, 433),    S(395, 398),    S(420, 382),    S(406, 397),    S(394, 409),    S(379, 401),    S(361, 417),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(827, 772),    S(872, 746),    S(878, 755),    S(775, 872),    S(821, 818),    S(772, 836),    S(817, 772),    S(749, 791),    //
    S(766, 890),    S(693, 996),    S(707, 1020),   S(634, 1033),   S(647, 1002),   S(625, 1012),   S(664, 934),    S(709, 853),    //
    S(727, 920),    S(808, 940),    S(757, 996),    S(741, 1004),   S(698, 988),    S(660, 1001),   S(728, 902),    S(702, 856),    //
    S(785, 842),    S(784, 923),    S(748, 959),    S(734, 1025),   S(712, 1011),   S(706, 945),    S(740, 859),    S(736, 804),    //
    S(745, 877),    S(774, 851),    S(748, 925),    S(703, 991),    S(690, 983),    S(699, 936),    S(716, 846),    S(719, 795),    //
    S(752, 727),    S(774, 775),    S(772, 853),    S(716, 886),    S(727, 850),    S(731, 852),    S(744, 777),    S(726, 768),    //
    S(734, 630),    S(764, 534),    S(750, 676),    S(765, 757),    S(739, 777),    S(757, 708),    S(731, 767),    S(718, 755),    //
    S(680, 717),    S(738, 471),    S(733, 481),    S(758, 580),    S(760, 668),    S(763, 624),    S(752, 658),    S(700, 729),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-163, -362),  S(69, 18),      S(-43, 39),     S(-130, 58),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(150, -80),    S(-21, 210),    S(48, 179),     S(182, 100),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-51, 72),     S(58, 194),     S(138, 154),    S(154, 103),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-262, 82),    S(25, 142),     S(50, 139),     S(34, 118),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-234, 43),    S(-62, 111),    S(-30, 118),    S(-84, 153),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-147, 1),     S(32, 37),      S(-58, 98),     S(-89, 130),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(58, -96),     S(105, -28),    S(16, 28),      S(-63, 77),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-63, -154),   S(60, -113),    S(-39, -76),    S(-55, -75),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 7.17925s
// clang-format on
}  // namespace Clockwork
