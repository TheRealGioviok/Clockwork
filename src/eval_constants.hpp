#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(177, 135);
inline const PParam KNIGHT_MAT = S(711, 309);
inline const PParam BISHOP_MAT = S(758, 316);
inline const PParam ROOK_MAT   = S(666, 346);
inline const PParam QUEEN_MAT  = S(2160, -855);
inline const PParam TEMPO_VAL  = S(65, 12);

inline const PParam BISHOP_PAIR_VAL   = S(80, 143);
inline const PParam ROOK_OPEN_VAL     = S(109, -23);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 10);

inline const PParam DOUBLED_PAWN_VAL = S(-34, -60);

inline const PParam POTENTIAL_CHECKER_VAL = S(-62, -4);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 47);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 27);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(46, 9);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(57, -22);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 44);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(70, -60);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 21), S(52, 35), S(71, 64), S(172, 139), S(499, 161), S(661, 572),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(67, 42), S(57, 33), S(73, 61), S(164, 117), S(566, -7),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -97), S(-84, -78), S(-49, 1), S(19, 83), S(120, 194), S(334, 251),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(33, -32), S(33, -5), S(26, 22), S(18, 75), S(80, 144), S(160, 234),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -29), S(3, 11), S(-2, -14), S(-10, -35), S(-25, -87), S(-265, -122),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(32, 81), S(1, 80), S(-8, 39), S(-10, 16), S(-9, 18), S(24, 15), S(2, -4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-310, -41), S(-14, -1), S(-6, 35), S(21, 73), S(34, 91), S(46, 100), S(23, 91),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(96, -98), S(185, 72), S(230, 151), S(263, 188), S(307, 204), S(335, 239), S(369, 236), S(404, 242), S(452, 180),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(119, -146), S(174, 59), S(238, 128), S(270, 174), S(297, 208), S(315, 230), S(324, 248), S(339, 257), S(350, 269), S(371, 258), S(388, 251), S(438, 211), S(444, 211), S(502, 163),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(340, 108), S(286, 273), S(314, 297), S(332, 305), S(345, 320), S(352, 332), S(359, 342), S(369, 343), S(376, 351), S(387, 352), S(400, 351), S(410, 350), S(418, 348), S(437, 330), S(540, 241),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(689, -220), S(802, -145), S(835, -49), S(857, 69), S(872, 126), S(885, 168), S(892, 202), S(902, 209), S(907, 231), S(913, 239), S(919, 248), S(925, 250), S(934, 244), S(937, 248), S(941, 243), S(943, 241), S(945, 237), S(949, 232), S(956, 218), S(971, 201), S(987, 176), S(1014, 142), S(1048, 105), S(1145, 6), S(1188, -41), S(1250, -83), S(1283, -118), S(1222, -99),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(554, -134), S(123, -66), S(37, 11), S(24, 29), S(3, 14), S(-21, 8), S(-23, 2), S(-42, -2), S(-44, -46),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(-6, 32), S(17, 38), S(26, 41),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(-4, 35), S(5, 14), S(10, -6),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(-4, 44), S(16, 56), S(17, 63), S(24, 77), S(39, 83),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(302, 375), S(204, 239), S(108, 72), S(16, 74), S(-67, 60), S(-164, 36),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, 5), S(1, -2), S(7, 23), S(-5, -11), S(96, 160),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, 2), S(7, 1), S(6, -0), S(5, 0), S(6, 265),
};

inline const PParam KS_NOQUEEN_ATTACK = S(-428, -198);
inline const PParam PAWN_THREAT_KNIGHT = S(240, 68);
inline const PParam PAWN_THREAT_BISHOP = S(215, 116);
inline const PParam PAWN_THREAT_ROOK   = S(216, 97);
inline const PParam PAWN_THREAT_QUEEN  = S(191, -55);

inline const PParam KNIGHT_THREAT_BISHOP = S(123, 78);
inline const PParam KNIGHT_THREAT_ROOK   = S(255, 22);
inline const PParam KNIGHT_THREAT_QUEEN  = S(170, -48);

inline const PParam BISHOP_THREAT_KNIGHT = S(117, 51);
inline const PParam BISHOP_THREAT_ROOK   = S(247, 81);
inline const PParam BISHOP_THREAT_QUEEN  = S(204, 52);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -22), S(-4, -11), S(-5, -21), S(-10, -28), S(-16, -32), S(-22, -34), S(-26, -43), S(-33, -41), S(-45, -41),
};

inline const PParam ROOK_LINEUP = S(13, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(349, 248),    S(226, 319),    S(352, 292),    S(316, 231),    S(339, 185),    S(273, 245),    S(213, 273),    S(309, 223),    //
    S(144, 159),    S(207, 181),    S(215, 130),    S(186, 94),     S(166, 80),     S(145, 115),    S(135, 151),    S(79, 166),     //
    S(106, 133),    S(111, 134),    S(132, 82),     S(122, 70),     S(109, 69),     S(83, 93),      S(52, 136),     S(34, 151),     //
    S(71, 106),     S(83, 124),     S(96, 85),      S(84, 83),      S(62, 86),      S(51, 103),     S(10, 145),     S(-3, 128),     //
    S(61, 80),      S(121, 80),     S(95, 103),     S(80, 103),     S(50, 108),     S(29, 110),     S(12, 129),     S(-8, 112),     //
    S(82, 83),      S(189, 92),     S(167, 134),    S(112, 132),    S(81, 129),     S(60, 124),     S(46, 137),     S(12, 128),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-297, -6),    S(-201, 220),   S(-267, 218),   S(51, 175),     S(-7, 171),     S(-130, 171),   S(-308, 228),   S(-352, 67),    //
    S(88, 156),     S(159, 145),    S(236, 98),     S(223, 118),    S(207, 136),    S(157, 129),    S(119, 160),    S(76, 151),     //
    S(186, 119),    S(231, 126),    S(250, 150),    S(237, 148),    S(205, 162),    S(155, 177),    S(164, 135),    S(116, 147),    //
    S(248, 139),    S(270, 140),    S(263, 159),    S(255, 179),    S(257, 186),    S(212, 180),    S(210, 156),    S(190, 142),    //
    S(250, 134),    S(282, 116),    S(264, 150),    S(259, 166),    S(236, 174),    S(231, 166),    S(221, 133),    S(189, 137),    //
    S(187, 109),    S(219, 108),    S(210, 139),    S(224, 158),    S(221, 157),    S(180, 143),    S(169, 113),    S(135, 91),     //
    S(197, 113),    S(220, 112),    S(196, 107),    S(200, 126),    S(189, 125),    S(157, 90),     S(151, 111),    S(115, 54),     //
    S(131, 84),     S(177, 123),    S(196, 108),    S(211, 103),    S(195, 113),    S(156, 92),     S(143, 111),    S(95, 47),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(10, 257),     S(-7, 250),     S(-260, 295),   S(-168, 274),   S(-150, 289),   S(-212, 300),   S(-70, 297),    S(33, 262),     //
    S(148, 176),    S(105, 232),    S(124, 203),    S(61, 233),     S(64, 237),     S(110, 226),    S(145, 214),    S(118, 209),    //
    S(223, 183),    S(241, 193),    S(238, 207),    S(209, 201),    S(178, 203),    S(191, 203),    S(214, 200),    S(189, 184),    //
    S(198, 174),    S(230, 185),    S(231, 199),    S(231, 228),    S(261, 214),    S(189, 203),    S(199, 181),    S(155, 187),    //
    S(221, 137),    S(243, 160),    S(251, 184),    S(255, 200),    S(234, 213),    S(214, 203),    S(175, 186),    S(169, 155),    //
    S(248, 137),    S(287, 149),    S(301, 168),    S(249, 195),    S(240, 181),    S(234, 185),    S(240, 165),    S(179, 169),    //
    S(225, 110),    S(316, 117),    S(278, 134),    S(247, 155),    S(226, 158),    S(227, 134),    S(224, 132),    S(218, 124),    //
    S(245, 120),    S(231, 146),    S(239, 161),    S(250, 139),    S(246, 139),    S(246, 172),    S(239, 152),    S(224, 141),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(464, 300),    S(510, 297),    S(465, 317),    S(472, 303),    S(472, 293),    S(439, 301),    S(434, 313),    S(417, 326),    //
    S(359, 348),    S(449, 331),    S(513, 313),    S(451, 332),    S(445, 334),    S(428, 336),    S(360, 363),    S(340, 370),    //
    S(341, 341),    S(461, 305),    S(496, 299),    S(476, 297),    S(443, 310),    S(397, 334),    S(397, 332),    S(324, 370),    //
    S(329, 328),    S(416, 319),    S(447, 307),    S(430, 308),    S(422, 316),    S(378, 339),    S(365, 339),    S(296, 361),    //
    S(297, 287),    S(365, 289),    S(360, 307),    S(341, 307),    S(324, 321),    S(311, 340),    S(282, 335),    S(261, 333),    //
    S(278, 244),    S(343, 252),    S(337, 277),    S(325, 274),    S(319, 274),    S(291, 302),    S(280, 288),    S(244, 296),    //
    S(186, 256),    S(308, 210),    S(325, 233),    S(323, 245),    S(312, 247),    S(298, 257),    S(279, 242),    S(248, 257),    //
    S(238, 240),    S(263, 253),    S(322, 243),    S(337, 235),    S(327, 242),    S(308, 254),    S(294, 250),    S(274, 267),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(630, 237),    S(678, 209),    S(648, 254),    S(604, 331),    S(614, 299),    S(607, 290),    S(633, 221),    S(560, 286),    //
    S(630, 287),    S(602, 368),    S(588, 404),    S(452, 487),    S(461, 475),    S(519, 431),    S(554, 333),    S(563, 306),    //
    S(604, 318),    S(664, 330),    S(603, 409),    S(555, 436),    S(528, 430),    S(553, 390),    S(604, 295),    S(598, 250),    //
    S(645, 257),    S(661, 314),    S(603, 382),    S(588, 430),    S(574, 434),    S(573, 362),    S(622, 275),    S(607, 245),    //
    S(645, 248),    S(649, 286),    S(621, 347),    S(587, 400),    S(586, 395),    S(587, 345),    S(598, 279),    S(617, 212),    //
    S(622, 200),    S(658, 236),    S(656, 293),    S(623, 294),    S(616, 292),    S(618, 301),    S(625, 232),    S(604, 206),    //
    S(601, 98),     S(633, 95),     S(643, 147),    S(657, 181),    S(643, 209),    S(635, 182),    S(605, 214),    S(611, 189),    //
    S(574, 104),    S(605, -32),    S(627, -34),    S(647, 59),     S(648, 122),    S(645, 81),     S(634, 103),    S(595, 144),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-343, -254),  S(150, 88),     S(130, 37),     S(-166, 26),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(180, -89),    S(290, 118),    S(159, 126),    S(78, 56),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(120, 26),     S(338, 94),     S(241, 99),     S(110, 64),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-68, 23),     S(236, 77),     S(78, 99),      S(9, 98),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-134, 8),     S(138, 54),     S(60, 79),      S(-56, 120),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-63, -16),    S(169, 19),     S(59, 57),      S(14, 83),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(17, -59),     S(110, 12),     S(20, 30),      S(-36, 51),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-103, -120),  S(7, -54),      S(-86, -59),    S(-95, -95),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-21, -8), S(-34, -9), S(-41, -9), S(-34, -10), S(-34, -10), S(-40, -9), S(-32, -8), }},
  {{ S(-32, -12), S(-56, -13), S(-54, -15), S(-46, -18), S(-45, -16), S(-53, -14), S(-55, -12), }},
  {{ S(-49, -12), S(-58, -10), S(-57, -14), S(-54, -16), S(-53, -16), S(-56, -14), S(-56, -11), }},
  {{ S(-32, -10), S(-50, -17), S(-42, -17), S(-37, -16), S(-39, -16), S(-42, -17), S(-46, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-29, -3), S(-53, -8), S(-51, -8), S(-44, -8), S(-50, -10),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-40, -9), S(-51, -7), S(-50, -7), S(-49, -8), S(-50, -9), S(-49, -7), S(-51, -7), }},
  {{ S(-39, -8), S(-48, -7), S(-55, -7), S(-51, -10), S(-51, -10), S(-54, -7), S(-48, -7), }},
  {{ S(-44, -12), S(-50, -9), S(-51, -8), S(-47, -9), S(-47, -9), S(-52, -9), S(-50, -9), }},
  {{ S(-46, -12), S(-54, -9), S(-55, -10), S(-48, -9), S(-46, -8), S(-55, -10), S(-56, -10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1059, 2080, -99, 88
);
// Epoch duration: 9.86598s
// clang-format on
}  // namespace Clockwork
