#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(178, 136);
inline const PParam KNIGHT_MAT = S(721, 311);
inline const PParam BISHOP_MAT = S(771, 319);
inline const PParam ROOK_MAT   = S(670, 347);
inline const PParam QUEEN_MAT  = S(2149, -864);
inline const PParam TEMPO_VAL  = S(64, 12);

inline const PParam BISHOP_PAIR_VAL   = S(79, 144);
inline const PParam ROOK_OPEN_VAL     = S(109, -23);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 9);

inline const PParam DOUBLED_PAWN_VAL = S(-34, -60);

inline const PParam POTENTIAL_CHECKER_VAL = S(-63, -3);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 47);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 27);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(5, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(6, -11);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(4, 18);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(7, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 21), S(52, 35), S(71, 64), S(173, 139), S(497, 161), S(655, 571),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(67, 42), S(57, 33), S(73, 61), S(164, 117), S(565, -7),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-91, -98), S(-84, -79), S(-49, 0), S(19, 82), S(119, 194), S(333, 252),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(33, -32), S(33, -5), S(26, 22), S(18, 75), S(80, 144), S(160, 235),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -29), S(3, 11), S(-2, -14), S(-10, -34), S(-25, -87), S(-264, -123),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(33, 81), S(1, 80), S(-8, 39), S(-10, 16), S(-9, 18), S(24, 15), S(1, -4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-304, -42), S(-12, -1), S(-6, 36), S(21, 74), S(33, 92), S(46, 101), S(23, 91),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(90, -103), S(179, 68), S(224, 147), S(257, 185), S(301, 201), S(328, 237), S(362, 234), S(397, 240), S(445, 179),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(112, -143), S(167, 61), S(232, 130), S(264, 176), S(291, 210), S(309, 232), S(318, 250), S(334, 258), S(345, 270), S(365, 259), S(383, 252), S(433, 212), S(439, 211), S(498, 163),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(338, 106), S(284, 272), S(311, 295), S(330, 304), S(342, 319), S(349, 331), S(356, 341), S(366, 342), S(374, 350), S(384, 351), S(397, 350), S(407, 349), S(415, 347), S(434, 329), S(538, 240),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(699, -226), S(812, -149), S(845, -53), S(867, 64), S(882, 122), S(895, 164), S(902, 198), S(912, 204), S(917, 227), S(923, 235), S(929, 244), S(935, 246), S(944, 239), S(947, 244), S(951, 239), S(953, 237), S(955, 233), S(959, 228), S(966, 214), S(981, 197), S(997, 172), S(1024, 138), S(1058, 102), S(1155, 2), S(1199, -45), S(1262, -88), S(1296, -123), S(1235, -105),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(559, -138), S(127, -69), S(40, 9), S(27, 27), S(5, 14), S(-20, 8), S(-21, 2), S(-39, -2), S(-42, -46),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(-7, 32), S(20, 38), S(31, 40),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(-4, 35), S(-10, 20), S(-17, 6),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(-5, 43), S(16, 56), S(16, 63), S(23, 78), S(396, 63),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(435, 549), S(299, 321), S(166, 175), S(36, 73), S(-83, 60), S(-217, 48),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(13, 4), S(0, -2), S(23, 16), S(-4, -11), S(134, 184),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, 2), S(8, 1), S(7, -0), S(6, 0), S(7, 267),
};

inline const PParam PAWN_THREAT_KNIGHT = S(24, 30);
inline const PParam PAWN_THREAT_BISHOP = S(21, 41);
inline const PParam PAWN_THREAT_ROOK   = S(21, 35);
inline const PParam PAWN_THREAT_QUEEN  = S(17, 7);

inline const PParam KNIGHT_THREAT_BISHOP = S(13, 27);
inline const PParam KNIGHT_THREAT_ROOK   = S(24, 16);
inline const PParam KNIGHT_THREAT_QUEEN  = S(16, 5);

inline const PParam BISHOP_THREAT_KNIGHT = S(13, 17);
inline const PParam BISHOP_THREAT_ROOK   = S(24, 31);
inline const PParam BISHOP_THREAT_QUEEN  = S(20, 31);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -22), S(-4, -11), S(-5, -21), S(-10, -28), S(-16, -32), S(-22, -35), S(-26, -43), S(-33, -41), S(-44, -41),
};

inline const PParam ROOK_LINEUP = S(13, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(347, 247),    S(227, 318),    S(352, 291),    S(316, 229),    S(338, 184),    S(271, 244),    S(211, 272),    S(307, 222),    //
    S(145, 158),    S(208, 180),    S(216, 128),    S(187, 93),     S(166, 79),     S(146, 113),    S(135, 151),    S(78, 165),     //
    S(105, 133),    S(110, 133),    S(132, 82),     S(122, 70),     S(109, 68),     S(83, 93),      S(51, 136),     S(32, 151),     //
    S(70, 105),     S(81, 123),     S(96, 84),      S(83, 82),      S(61, 85),      S(50, 103),     S(9, 145),      S(-5, 128),     //
    S(61, 79),      S(121, 80),     S(95, 103),     S(79, 103),     S(49, 108),     S(27, 110),     S(10, 129),     S(-9, 112),     //
    S(80, 83),      S(190, 91),     S(166, 135),    S(111, 132),    S(80, 129),     S(58, 123),     S(44, 137),     S(10, 128),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-301, -6),    S(-206, 221),   S(-271, 219),   S(47, 175),     S(-12, 172),    S(-135, 172),   S(-313, 228),   S(-357, 68),    //
    S(85, 156),     S(155, 145),    S(231, 97),     S(219, 117),    S(203, 136),    S(153, 128),    S(115, 160),    S(72, 152),     //
    S(182, 119),    S(227, 125),    S(247, 148),    S(233, 147),    S(202, 161),    S(151, 175),    S(159, 134),    S(111, 147),    //
    S(244, 139),    S(266, 138),    S(259, 157),    S(251, 177),    S(253, 184),    S(208, 178),    S(205, 155),    S(185, 142),    //
    S(245, 134),    S(277, 115),    S(260, 148),    S(255, 164),    S(232, 173),    S(227, 164),    S(216, 132),    S(184, 137),    //
    S(181, 110),    S(213, 107),    S(205, 138),    S(219, 157),    S(216, 156),    S(175, 142),    S(165, 113),    S(130, 92),     //
    S(192, 114),    S(215, 112),    S(191, 107),    S(195, 126),    S(184, 124),    S(152, 90),     S(146, 112),    S(110, 55),     //
    S(126, 85),     S(171, 124),    S(191, 108),    S(206, 103),    S(190, 113),    S(151, 93),     S(138, 112),    S(90, 48),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(3, 252),      S(-14, 245),    S(-267, 290),   S(-173, 269),   S(-156, 284),   S(-219, 296),   S(-77, 292),    S(25, 257),     //
    S(142, 170),    S(98, 227),     S(117, 198),    S(54, 229),     S(56, 233),     S(103, 221),    S(138, 209),    S(111, 203),    //
    S(216, 178),    S(234, 188),    S(230, 203),    S(201, 197),    S(170, 199),    S(183, 200),    S(206, 195),    S(182, 179),    //
    S(191, 169),    S(222, 182),    S(222, 196),    S(223, 225),    S(252, 211),    S(181, 199),    S(191, 178),    S(148, 183),    //
    S(213, 133),    S(235, 156),    S(243, 180),    S(247, 197),    S(226, 210),    S(206, 199),    S(167, 182),    S(161, 151),    //
    S(240, 133),    S(279, 144),    S(293, 164),    S(241, 190),    S(232, 177),    S(226, 181),    S(233, 160),    S(172, 165),    //
    S(218, 105),    S(308, 112),    S(270, 130),    S(239, 150),    S(218, 153),    S(220, 129),    S(217, 127),    S(210, 119),    //
    S(238, 114),    S(224, 140),    S(231, 156),    S(243, 134),    S(239, 133),    S(238, 167),    S(232, 147),    S(217, 136),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(462, 303),    S(511, 299),    S(462, 320),    S(470, 306),    S(471, 296),    S(440, 303),    S(435, 315),    S(417, 328),    //
    S(362, 349),    S(452, 331),    S(515, 313),    S(455, 332),    S(448, 334),    S(431, 337),    S(363, 363),    S(342, 371),    //
    S(342, 343),    S(462, 307),    S(495, 301),    S(477, 298),    S(445, 311),    S(399, 335),    S(399, 334),    S(327, 371),    //
    S(332, 329),    S(419, 320),    S(450, 307),    S(433, 308),    S(424, 316),    S(380, 340),    S(368, 339),    S(299, 362),    //
    S(299, 288),    S(367, 289),    S(363, 307),    S(344, 308),    S(327, 321),    S(314, 341),    S(285, 336),    S(264, 334),    //
    S(281, 244),    S(345, 253),    S(339, 278),    S(327, 274),    S(321, 275),    S(293, 303),    S(283, 288),    S(247, 296),    //
    S(188, 257),    S(310, 211),    S(328, 234),    S(326, 245),    S(315, 248),    S(301, 258),    S(281, 243),    S(251, 257),    //
    S(240, 241),    S(266, 254),    S(325, 244),    S(340, 236),    S(330, 242),    S(311, 255),    S(297, 251),    S(277, 268),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(641, 233),    S(689, 204),    S(659, 249),    S(615, 326),    S(626, 293),    S(618, 285),    S(642, 217),    S(570, 282),    //
    S(640, 284),    S(612, 364),    S(598, 400),    S(463, 483),    S(471, 471),    S(529, 427),    S(564, 329),    S(573, 302),    //
    S(614, 314),    S(674, 325),    S(614, 405),    S(566, 432),    S(538, 426),    S(563, 385),    S(614, 291),    S(608, 246),    //
    S(653, 257),    S(669, 314),    S(611, 383),    S(596, 430),    S(582, 433),    S(581, 362),    S(630, 276),    S(615, 244),    //
    S(654, 247),    S(656, 287),    S(628, 348),    S(595, 400),    S(593, 394),    S(595, 345),    S(606, 278),    S(625, 211),    //
    S(631, 198),    S(666, 235),    S(665, 291),    S(632, 293),    S(624, 290),    S(626, 299),    S(633, 230),    S(613, 203),    //
    S(610, 94),     S(642, 92),     S(652, 144),    S(666, 178),    S(652, 206),    S(644, 179),    S(614, 211),    S(620, 185),    //
    S(584, 98),     S(615, -36),    S(637, -38),    S(657, 55),     S(658, 118),    S(654, 77),     S(644, 99),     S(605, 140),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-346, -252),  S(144, 90),     S(131, 37),     S(-165, 26),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(176, -88),    S(281, 120),    S(153, 127),    S(75, 56),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(110, 28),     S(320, 97),     S(228, 101),    S(99, 65),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-79, 26),     S(217, 80),     S(63, 101),     S(-4, 99),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-142, 10),    S(120, 58),     S(43, 82),      S(-73, 123),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-65, -16),    S(162, 20),     S(51, 58),      S(3, 85),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(18, -60),     S(111, 10),     S(23, 28),      S(-36, 49),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-102, -120),  S(10, -55),     S(-83, -60),    S(-92, -97),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-44, -33), S(-58, -33), S(-66, -34), S(-59, -35), S(-59, -35), S(-65, -33), S(-56, -33), }},
  {{ S(-56, -36), S(-83, -37), S(-81, -39), S(-71, -42), S(-71, -40), S(-79, -38), S(-81, -36), }},
  {{ S(-72, -47), S(-82, -45), S(-81, -49), S(-78, -51), S(-77, -50), S(-80, -49), S(-80, -46), }},
  {{ S(-56, -34), S(-76, -41), S(-67, -41), S(-62, -40), S(-64, -40), S(-68, -41), S(-72, -39), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-38, -23), S(-64, -28), S(-63, -28), S(-54, -28), S(-62, -30),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-50, -29), S(-64, -27), S(-62, -27), S(-61, -28), S(-62, -29), S(-60, -27), S(-64, -27), }},
  {{ S(-50, -28), S(-60, -27), S(-67, -27), S(-62, -30), S(-63, -30), S(-66, -27), S(-59, -27), }},
  {{ S(-55, -31), S(-62, -29), S(-63, -28), S(-58, -29), S(-58, -29), S(-63, -28), S(-61, -29), }},
  {{ S(-56, -32), S(-67, -29), S(-67, -30), S(-59, -29), S(-57, -28), S(-67, -30), S(-68, -30), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        894, 2102, -123, 34
);
inline TunableSigmoid<32> THREATS_ACTIVATION(
        1508, 1138, -42, -92
);
// Epoch duration: 10.1912s
// clang-format on
}  // namespace Clockwork
