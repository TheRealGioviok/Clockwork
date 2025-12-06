#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(185, 168);
inline const PParam KNIGHT_MAT = S(776, 559);
inline const PParam BISHOP_MAT = S(808, 552);
inline const PParam ROOK_MAT   = S(765, 723);
inline const PParam QUEEN_MAT  = S(1724, 1227);
inline const PParam TEMPO_VAL  = S(59, 16);

inline const PParam BISHOP_PAIR_VAL   = S(77, 179);
inline const PParam ROOK_OPEN_VAL     = S(103, -28);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 13);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -78);

inline const PParam POTENTIAL_CHECKER_VAL = S(-76, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(10, 56);
inline const PParam OUTPOST_BISHOP_VAL    = S(28, 28);
inline const PParam REACHABLE_OUTPOST_KNIGHT_VAL    = S(9, 23);
inline const PParam REACHABLE_OUTPOST_BISHOP_VAL    = S(6, 8);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(52, 13);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(56, -13);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(33, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(54, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 20), S(62, 30), S(73, 70), S(189, 143), S(547, 250), S(797, 880),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(63, 43), S(60, 31), S(65, 57), S(144, 121), S(670, -80),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-68, -98), S(-59, -80), S(-32, -4), S(22, 76), S(45, 218), S(284, 308),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(51, -44), S(38, -4), S(23, 29), S(24, 77), S(92, 152), S(148, 295),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(16, -46), S(5, 3), S(-1, -28), S(5, -48), S(3, -96), S(-191, -146),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(12, 101), S(-22, 88), S(-14, 37), S(-0, 7), S(9, 12), S(39, 9), S(18, -3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-185, -55), S(29, -8), S(-13, 41), S(10, 71), S(14, 96), S(34, 96), S(-15, 115),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(1, -6), S(108, 158), S(164, 210), S(206, 242), S(250, 255), S(274, 290), S(308, 285), S(340, 285), S(383, 229),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(33, -56), S(107, 128), S(180, 190), S(215, 239), S(245, 269), S(262, 289), S(281, 303), S(299, 308), S(318, 312), S(331, 308), S(356, 295), S(419, 247), S(450, 226), S(510, 189),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(166, 253), S(304, 428), S(356, 492), S(389, 503), S(415, 526), S(429, 549), S(447, 560), S(465, 566), S(482, 579), S(500, 588), S(518, 589), S(531, 592), S(551, 595), S(563, 581), S(709, 453),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(2, 3), S(788, 342), S(889, 435), S(948, 615), S(958, 812), S(997, 910), S(1001, 1018), S(1026, 1030), S(1031, 1084), S(1044, 1108), S(1053, 1132), S(1058, 1146), S(1078, 1136), S(1088, 1147), S(1095, 1141), S(1110, 1135), S(1117, 1125), S(1117, 1130), S(1145, 1083), S(1169, 1043), S(1187, 1020), S(1243, 941), S(1258, 930), S(1405, 767), S(1401, 751), S(1430, 733), S(1162, 866), S(1114, 861),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(381, 116), S(142, -117), S(39, -28), S(24, 10), S(-3, 13), S(-37, 18), S(-16, 19), S(-26, 13), S(-25, -36),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(0, 0), S(87, -31), S(157, -78),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(0, 0), S(35, -6), S(136, -45),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(0, 0), S(68, -49), S(51, -63), S(103, -63), S(160, -128),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(0, 0), S(-41, 35), S(-64, 52), S(-14, 13), S(136, -61), S(301, -176),
};

inline const PParam PAWN_THREAT_KNIGHT = S(237, 59);
inline const PParam PAWN_THREAT_BISHOP = S(207, 105);
inline const PParam PAWN_THREAT_ROOK   = S(198, 59);
inline const PParam PAWN_THREAT_QUEEN  = S(178, -61);

inline const PParam KNIGHT_THREAT_BISHOP = S(106, 76);
inline const PParam KNIGHT_THREAT_ROOK   = S(242, 7);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -67);

inline const PParam BISHOP_THREAT_KNIGHT = S(110, 36);
inline const PParam BISHOP_THREAT_ROOK   = S(241, 57);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 46);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(0, -8), S(-2, -4), S(-2, -14), S(-8, -26), S(-14, -32), S(-19, -40), S(-20, -47), S(-27, -42), S(-36, -46),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(235, 324),    S(227, 371),    S(293, 338),    S(357, 218),    S(303, 213),    S(289, 277),    S(183, 300),    S(242, 277),    //
    S(182, 193),    S(295, 222),    S(272, 164),    S(273, 106),    S(227, 89),     S(172, 138),    S(133, 185),    S(82, 188),     //
    S(103, 159),    S(122, 162),    S(139, 118),    S(126, 104),    S(110, 99),     S(68, 105),     S(27, 153),     S(1, 175),      //
    S(75, 110),     S(93, 138),     S(88, 104),     S(69, 107),     S(44, 98),      S(24, 106),     S(-26, 156),    S(-44, 145),    //
    S(73, 80),      S(133, 83),     S(84, 126),     S(53, 128),     S(32, 118),     S(-6, 117),     S(-24, 131),    S(-46, 126),    //
    S(84, 88),      S(213, 93),     S(168, 130),    S(110, 148),    S(73, 135),     S(38, 130),     S(12, 153),     S(-25, 140),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-280, -23),   S(-231, 197),   S(-334, 372),   S(-15, 212),    S(-139, 235),   S(-220, 240),   S(-447, 219),   S(-420, 117),   //
    S(114, 133),    S(178, 148),    S(281, 83),     S(224, 149),    S(225, 156),    S(165, 131),    S(104, 148),    S(88, 102),     //
    S(169, 108),    S(210, 155),    S(302, 150),    S(253, 171),    S(254, 162),    S(173, 172),    S(161, 145),    S(66, 149),     //
    S(224, 145),    S(216, 173),    S(246, 179),    S(225, 204),    S(233, 191),    S(202, 187),    S(174, 143),    S(149, 146),    //
    S(212, 126),    S(238, 128),    S(235, 153),    S(206, 169),    S(198, 178),    S(195, 173),    S(166, 146),    S(151, 86),     //
    S(125, 114),    S(157, 107),    S(152, 124),    S(162, 168),    S(168, 164),    S(114, 144),    S(117, 107),    S(77, 98),      //
    S(128, 133),    S(146, 102),    S(134, 112),    S(133, 131),    S(122, 126),    S(95, 105),     S(102, 88),     S(47, 21),      //
    S(81, 85),      S(120, 128),    S(138, 108),    S(146, 115),    S(139, 122),    S(92, 91),      S(79, 114),     S(30, 60),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-29, 263),    S(-50, 245),    S(-289, 271),   S(-170, 283),   S(-122, 286),   S(-288, 313),   S(-32, 290),    S(15, 266),     //
    S(142, 152),    S(124, 230),    S(144, 209),    S(120, 213),    S(96, 228),     S(135, 220),    S(113, 212),    S(80, 213),     //
    S(171, 212),    S(217, 202),    S(293, 209),    S(222, 207),    S(197, 211),    S(173, 223),    S(233, 196),    S(132, 213),    //
    S(189, 167),    S(202, 200),    S(236, 202),    S(235, 228),    S(242, 228),    S(179, 225),    S(170, 202),    S(122, 208),    //
    S(190, 140),    S(199, 179),    S(205, 196),    S(206, 220),    S(198, 237),    S(157, 227),    S(142, 190),    S(136, 146),    //
    S(201, 147),    S(240, 163),    S(245, 178),    S(186, 217),    S(169, 223),    S(170, 219),    S(198, 175),    S(166, 151),    //
    S(188, 113),    S(238, 138),    S(209, 151),    S(182, 180),    S(173, 165),    S(174, 154),    S(155, 169),    S(173, 103),    //
    S(184, 131),    S(171, 178),    S(176, 186),    S(186, 152),    S(195, 142),    S(192, 182),    S(184, 154),    S(166, 150),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(567, 481),    S(632, 480),    S(562, 509),    S(561, 504),    S(571, 493),    S(518, 506),    S(526, 509),    S(534, 514),    //
    S(478, 537),    S(564, 513),    S(638, 491),    S(563, 534),    S(579, 521),    S(527, 531),    S(467, 548),    S(459, 554),    //
    S(466, 515),    S(614, 473),    S(644, 468),    S(643, 464),    S(598, 474),    S(524, 515),    S(542, 502),    S(423, 552),    //
    S(436, 508),    S(512, 502),    S(543, 493),    S(566, 457),    S(534, 481),    S(473, 529),    S(455, 528),    S(384, 535),    //
    S(372, 459),    S(452, 465),    S(438, 482),    S(421, 483),    S(416, 480),    S(398, 519),    S(368, 516),    S(349, 504),    //
    S(348, 438),    S(422, 413),    S(417, 443),    S(397, 444),    S(413, 425),    S(364, 479),    S(363, 461),    S(340, 458),    //
    S(287, 449),    S(386, 389),    S(410, 404),    S(414, 407),    S(407, 412),    S(388, 428),    S(368, 405),    S(338, 421),    //
    S(321, 450),    S(352, 455),    S(405, 420),    S(430, 403),    S(416, 418),    S(403, 430),    S(388, 422),    S(371, 438),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(826, 862),    S(878, 814),    S(887, 820),    S(765, 952),    S(829, 879),    S(769, 910),    S(826, 833),    S(758, 861),    //
    S(800, 919),    S(726, 1015),   S(724, 1067),   S(641, 1095),   S(665, 1046),   S(652, 1048),   S(699, 955),    S(736, 892),    //
    S(758, 951),    S(846, 950),    S(787, 1025),   S(770, 1038),   S(729, 1021),   S(695, 1022),   S(765, 917),    S(732, 887),    //
    S(823, 870),    S(826, 939),    S(790, 976),    S(778, 1042),   S(755, 1028),   S(746, 961),    S(783, 870),    S(771, 835),    //
    S(786, 898),    S(820, 862),    S(794, 932),    S(753, 993),    S(741, 981),    S(747, 937),    S(759, 858),    S(762, 807),    //
    S(795, 742),    S(819, 786),    S(819, 857),    S(766, 885),    S(777, 843),    S(781, 848),    S(792, 776),    S(769, 781),    //
    S(780, 639),    S(812, 541),    S(800, 676),    S(816, 750),    S(790, 769),    S(807, 699),    S(781, 761),    S(765, 760),    //
    S(726, 715),    S(786, 471),    S(781, 482),    S(807, 578),    S(810, 661),    S(814, 615),    S(801, 653),    S(748, 728),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-212, -356),  S(53, -5),      S(-91, 42),     S(-185, 63),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(159, -101),   S(-14, 155),    S(4, 140),      S(112, 69),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-57, 68),     S(47, 147),     S(87, 115),     S(73, 69),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-278, 92),    S(13, 107),     S(6, 105),      S(-49, 89),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-249, 48),    S(-66, 80),     S(-49, 85),     S(-131, 121),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-154, 18),    S(37, 22),      S(-53, 73),     S(-97, 98),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(61, -73),     S(114, -32),    S(26, 15),      S(-55, 58),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-61, -102),   S(67, -91),     S(-32, -55),    S(-50, -54),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 7.49312s
// clang-format on
}  // namespace Clockwork
