#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(171, 155);
inline const PParam KNIGHT_MAT = S(519, 316);
inline const PParam BISHOP_MAT = S(475, 276);
inline const PParam ROOK_MAT   = S(552, 409);
inline const PParam QUEEN_MAT  = S(1086, 558);
inline const PParam TEMPO_VAL  = S(63, 14);

inline const PParam BISHOP_PAIR_VAL   = S(77, 165);
inline const PParam ROOK_OPEN_VAL     = S(117, -27);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 17);

inline const PParam DOUBLED_PAWN_VAL = S(-33, -74);

inline const PParam POTENTIAL_CHECKER_VAL = S(-69, -10);
inline const PParam OUTPOST_KNIGHT_VAL    = S(53, 40);
inline const PParam OUTPOST_BISHOP_VAL    = S(66, 21);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(47, 4);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(71, 36);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 39);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(72, -18);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 11), S(52, 33), S(66, 69), S(173, 153), S(473, 217), S(816, 587),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(72, 37), S(61, 33), S(74, 65), S(177, 117), S(595, -13),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-82, -95), S(-84, -72), S(-53, 7), S(31, 76), S(113, 195), S(303, 278),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(47, -40), S(39, -6), S(26, 23), S(20, 69), S(95, 127), S(211, 210),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(10, -32), S(1, 11), S(-9, -17), S(-15, -35), S(-24, -84), S(-272, -103),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 114), S(-17, 92), S(-10, 33), S(1, 3), S(13, 4), S(59, 0), S(25, -10),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-307, -8), S(-34, 23), S(-11, 49), S(36, 59), S(40, 80), S(49, 88), S(16, 86),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(17, -65), S(115, 88), S(171, 162), S(211, 188), S(255, 200), S(284, 232), S(320, 226), S(357, 228), S(402, 168),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-10, -114), S(61, 39), S(121, 78), S(149, 124), S(178, 153), S(195, 174), S(203, 189), S(219, 195), S(228, 205), S(245, 197), S(263, 186), S(328, 139), S(332, 133), S(405, 93),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(286, 103), S(202, 260), S(231, 277), S(248, 281), S(261, 291), S(267, 303), S(275, 310), S(285, 309), S(293, 315), S(303, 317), S(315, 316), S(324, 315), S(331, 314), S(349, 295), S(455, 201),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(452, 60), S(535, 222), S(580, 272), S(610, 365), S(622, 421), S(637, 452), S(640, 494), S(649, 501), S(652, 524), S(657, 536), S(662, 546), S(667, 549), S(677, 539), S(682, 542), S(685, 539), S(689, 534), S(693, 527), S(694, 525), S(706, 505), S(719, 491), S(736, 470), S(754, 437), S(782, 415), S(895, 308), S(946, 253), S(979, 229), S(889, 266), S(925, 243),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(608, -327), S(238, -185), S(118, -87), S(78, -38), S(27, -22), S(-29, 2), S(-78, 40), S(-133, 70), S(-169, 57),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(229, 227), S(348, 180), S(450, 117),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(460, 369), S(282, 234), S(162, 67),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(315, 325), S(453, 311), S(503, 315), S(614, 363), S(780, 319),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(880, 749), S(590, 612), S(331, 461), S(135, 258), S(77, -16), S(24, -309),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-122, 63), S(27, -18), S(-218, -128), S(65, 34), S(-244, -155),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-28, 22), S(-21, 20), S(-19, 14), S(-15, 9), S(-20, -13),
};

inline const PParam PAWN_THREAT_KNIGHT = S(246, 57);
inline const PParam PAWN_THREAT_BISHOP = S(218, 114);
inline const PParam PAWN_THREAT_ROOK   = S(201, 101);
inline const PParam PAWN_THREAT_QUEEN  = S(179, -34);

inline const PParam KNIGHT_THREAT_BISHOP = S(117, 75);
inline const PParam KNIGHT_THREAT_ROOK   = S(259, 13);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -21);

inline const PParam BISHOP_THREAT_KNIGHT = S(114, 39);
inline const PParam BISHOP_THREAT_ROOK   = S(239, 72);
inline const PParam BISHOP_THREAT_QUEEN  = S(198, 46);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -20), S(-4, -8), S(-4, -18), S(-9, -25), S(-15, -32), S(-21, -36), S(-24, -46), S(-29, -50), S(-42, -47),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(301, 274),    S(182, 353),    S(304, 316),    S(303, 249),    S(344, 180),    S(251, 253),    S(200, 281),    S(313, 231),    //
    S(160, 174),    S(209, 216),    S(193, 167),    S(163, 129),    S(145, 100),    S(113, 140),    S(97, 177),     S(57, 189),     //
    S(104, 138),    S(104, 155),    S(120, 112),    S(104, 105),    S(90, 93),      S(60, 106),     S(29, 144),     S(12, 160),     //
    S(91, 91),      S(106, 122),    S(111, 94),     S(96, 94),      S(64, 91),      S(45, 98),      S(-3, 140),     S(-21, 128),    //
    S(88, 68),      S(151, 72),     S(95, 118),     S(80, 117),     S(48, 111),     S(16, 111),     S(-9, 127),     S(-27, 114),    //
    S(87, 75),      S(215, 84),     S(153, 130),    S(105, 147),    S(74, 131),     S(51, 117),     S(32, 137),     S(-9, 130),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-266, -81),   S(-211, 176),   S(-494, 452),   S(116, 137),    S(19, 154),     S(-105, 132),   S(-387, 210),   S(-344, 19),    //
    S(106, 123),    S(157, 122),    S(245, 79),     S(213, 120),    S(209, 131),    S(145, 126),    S(118, 132),    S(100, 110),    //
    S(187, 91),     S(190, 136),    S(253, 148),    S(213, 169),    S(182, 176),    S(131, 181),    S(142, 120),    S(115, 116),    //
    S(242, 132),    S(225, 151),    S(226, 174),    S(201, 204),    S(220, 195),    S(195, 180),    S(194, 138),    S(191, 117),    //
    S(232, 116),    S(269, 102),    S(245, 149),    S(228, 172),    S(218, 169),    S(219, 158),    S(217, 106),    S(178, 120),    //
    S(178, 92),     S(206, 88),     S(191, 123),    S(214, 143),    S(212, 144),    S(162, 131),    S(161, 99),     S(127, 84),     //
    S(190, 83),     S(200, 73),     S(185, 84),     S(182, 106),    S(169, 114),    S(149, 66),     S(150, 88),     S(110, 17),     //
    S(132, 61),     S(163, 123),    S(191, 71),     S(207, 60),     S(192, 80),     S(141, 58),     S(132, 99),     S(81, 34),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-32, 182),    S(-70, 169),    S(-381, 238),   S(-215, 205),   S(-187, 213),   S(-281, 246),   S(-103, 215),   S(-25, 198),    //
    S(84, 105),     S(29, 172),     S(71, 126),     S(-2, 174),     S(-13, 180),    S(48, 156),     S(79, 137),     S(60, 128),     //
    S(151, 122),    S(175, 126),    S(175, 152),    S(133, 144),    S(109, 143),    S(102, 154),    S(150, 129),    S(119, 115),    //
    S(123, 106),    S(139, 132),    S(166, 141),    S(148, 177),    S(175, 162),    S(117, 144),    S(118, 123),    S(93, 110),     //
    S(135, 85),     S(143, 112),    S(153, 136),    S(166, 153),    S(153, 164),    S(116, 155),    S(83, 127),     S(91, 97),      //
    S(159, 86),     S(192, 92),     S(210, 111),    S(158, 146),    S(149, 133),    S(156, 130),    S(163, 104),    S(107, 107),    //
    S(144, 36),     S(230, 54),     S(190, 71),     S(157, 95),     S(138, 108),    S(151, 77),     S(150, 83),     S(135, 44),     //
    S(149, 42),     S(134, 95),     S(139, 119),    S(159, 73),     S(165, 61),     S(156, 123),    S(152, 76),     S(131, 69),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(403, 245),    S(440, 254),    S(406, 274),    S(412, 258),    S(407, 259),    S(363, 266),    S(375, 269),    S(360, 279),    //
    S(302, 299),    S(353, 297),    S(455, 265),    S(386, 290),    S(393, 290),    S(346, 295),    S(263, 325),    S(267, 323),    //
    S(283, 290),    S(421, 251),    S(442, 246),    S(422, 247),    S(383, 258),    S(336, 280),    S(338, 279),    S(257, 313),    //
    S(263, 276),    S(337, 278),    S(372, 265),    S(353, 259),    S(353, 260),    S(309, 284),    S(288, 286),    S(231, 299),    //
    S(217, 232),    S(285, 244),    S(271, 259),    S(267, 246),    S(256, 256),    S(243, 284),    S(211, 275),    S(185, 273),    //
    S(185, 204),    S(251, 202),    S(257, 223),    S(239, 216),    S(242, 212),    S(214, 249),    S(205, 228),    S(167, 238),    //
    S(96, 221),     S(215, 164),    S(238, 184),    S(245, 190),    S(238, 188),    S(223, 202),    S(204, 183),    S(173, 202),    //
    S(148, 210),    S(162, 231),    S(239, 190),    S(265, 173),    S(245, 193),    S(233, 208),    S(219, 198),    S(200, 223),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(458, 417),    S(551, 340),    S(529, 378),    S(453, 479),    S(465, 435),    S(454, 437),    S(483, 372),    S(392, 444),    //
    S(485, 440),    S(433, 536),    S(433, 551),    S(300, 607),    S(300, 605),    S(363, 565),    S(390, 485),    S(416, 454),    //
    S(427, 489),    S(522, 478),    S(446, 553),    S(414, 568),    S(367, 569),    S(384, 518),    S(455, 429),    S(427, 398),    //
    S(499, 390),    S(474, 477),    S(453, 508),    S(422, 562),    S(413, 564),    S(418, 495),    S(461, 407),    S(469, 367),    //
    S(471, 405),    S(474, 430),    S(454, 471),    S(429, 512),    S(427, 517),    S(425, 475),    S(445, 404),    S(459, 351),    //
    S(470, 309),    S(495, 355),    S(500, 417),    S(463, 400),    S(457, 396),    S(466, 418),    S(467, 369),    S(460, 336),    //
    S(447, 189),    S(489, 152),    S(493, 241),    S(504, 288),    S(486, 318),    S(486, 289),    S(456, 336),    S(458, 313),    //
    S(407, 243),    S(454, 32),     S(453, 75),     S(484, 160),    S(492, 238),    S(493, 189),    S(484, 211),    S(434, 270),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-591, -155),  S(-125, 146),   S(46, 85),      S(-156, 63),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -39),     S(181, 58),     S(165, 70),     S(141, -9),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-42, 91),     S(206, 61),     S(239, 50),     S(140, 15),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-296, 104),   S(133, 34),     S(75, 41),      S(58, 32),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-303, 70),    S(75, -1),      S(89, 3),       S(10, 37),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-154, 36),    S(162, -36),    S(119, -9),     S(93, 10),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-3, -25),     S(182, -58),    S(136, -30),    S(61, 6),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-187, -16),   S(-18, -19),    S(-111, 14),    S(-110, -6),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 16.1818s
// clang-format on
}  // namespace Clockwork
