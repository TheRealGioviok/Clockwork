#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(139, 202);
inline const PParam KNIGHT_MAT = S(544, 606);
inline const PParam BISHOP_MAT = S(589, 639);
inline const PParam ROOK_MAT   = S(511, 719);
inline const PParam QUEEN_MAT  = S(1088, 1091);
inline const PParam TEMPO_VAL  = S(57, 22);

inline const PParam BISHOP_PAIR_VAL   = S(50, 199);
inline const PParam ROOK_OPEN_VAL     = S(47, -5);
inline const PParam ROOK_SEMIOPEN_VAL = S(23, 13);
inline const std::array<PParam, 2> OPEN_FILE_ACCESS_VAL = {
    S(38, 21), S(46, 53),
};
inline const std::array<PParam, 2> SEMIOPEN_FILE_ACCESS_VAL = {
    S(-2, -35), S(-3, -9),
};

inline const PParam DOUBLED_PAWN_VAL = S(-5, -68);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(36, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -35);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -1), S(37, 27), S(57, 52), S(135, 147), S(378, 206), S(447, 694),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 35), S(43, 27), S(53, 55), S(117, 143), S(406, 89),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-73, -125), S(-70, -101), S(-49, 10), S(7, 119), S(90, 268), S(260, 382),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(35, -44), S(34, -5), S(22, 32), S(0, 110), S(46, 223), S(204, 284),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(22, -38), S(3, 10), S(2, -23), S(-1, -55), S(-9, -127), S(-209, -232),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-4, 151), S(-14, 114), S(-10, 46), S(-4, 10), S(1, 9), S(36, 8), S(11, 2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-303, -53), S(-39, 27), S(-24, 63), S(14, 100), S(33, 116), S(50, 117), S(32, 111),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(76, 12), S(147, 184), S(181, 274), S(209, 310), S(249, 329), S(273, 364), S(305, 362), S(336, 378), S(389, 291),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(103, 10), S(145, 187), S(200, 250), S(227, 295), S(252, 328), S(268, 352), S(275, 372), S(289, 382), S(295, 400), S(321, 381), S(332, 383), S(380, 331), S(379, 344), S(409, 291),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(289, 237), S(206, 413), S(231, 436), S(247, 440), S(257, 450), S(263, 458), S(269, 465), S(277, 466), S(282, 476), S(293, 477), S(304, 478), S(311, 483), S(318, 483), S(336, 455), S(419, 353),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(498, 513), S(637, 536), S(662, 650), S(679, 761), S(695, 810), S(703, 854), S(709, 885), S(717, 896), S(721, 919), S(724, 933), S(730, 940), S(734, 948), S(743, 941), S(744, 947), S(749, 943), S(746, 948), S(750, 942), S(756, 936), S(763, 928), S(773, 920), S(782, 895), S(803, 857), S(800, 857), S(799, 802), S(787, 788), S(779, 759), S(716, 809), S(736, 721),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(496, -199), S(109, -104), S(28, -23), S(15, 10), S(-5, 9), S(-21, 0), S(-25, 7), S(-39, 13), S(-26, -30),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -7), S(16, -15), S(13, -12), S(6, -8), S(2, 200),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 403),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 95);
inline const PParam PAWN_THREAT_BISHOP = S(190, 146);
inline const PParam PAWN_THREAT_ROOK   = S(192, 119);
inline const PParam PAWN_THREAT_QUEEN  = S(166, -15);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 67);
inline const PParam KNIGHT_THREAT_QUEEN  = S(150, -2);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(174, 102);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -37), S(-4, -9), S(-6, -17), S(-9, -28), S(-13, -37), S(-18, -43), S(-21, -55), S(-28, -53), S(-40, -54),
};

inline const PParam ROOK_LINEUP = S(12, 62);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 346),    S(144, 446),    S(288, 413),    S(295, 285),    S(318, 236),    S(213, 319),    S(152, 358),    S(263, 314),    //
    S(117, 209),    S(146, 249),    S(185, 168),    S(171, 101),    S(150, 84),     S(123, 138),    S(95, 195),     S(47, 223),     //
    S(79, 174),     S(66, 176),     S(108, 102),    S(109, 79),     S(97, 76),      S(69, 108),     S(21, 158),     S(10, 188),     //
    S(55, 126),     S(44, 149),     S(81, 97),      S(77, 88),      S(55, 91),      S(38, 116),     S(-22, 159),    S(-21, 153),    //
    S(52, 98),      S(93, 105),     S(78, 136),     S(71, 122),     S(42, 118),     S(19, 124),     S(-15, 141),    S(-24, 135),    //
    S(64, 100),     S(155, 116),    S(139, 172),    S(92, 155),     S(63, 141),     S(43, 135),     S(13, 147),     S(-7, 149),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-232, -66),   S(-137, 205),   S(-89, 64),     S(104, 200),    S(43, 201),     S(-103, 204),   S(-240, 262),   S(-271, 6),     //
    S(86, 179),     S(130, 199),    S(214, 163),    S(212, 169),    S(212, 172),    S(124, 200),    S(87, 218),     S(62, 195),     //
    S(172, 171),    S(218, 167),    S(219, 222),    S(221, 205),    S(180, 241),    S(119, 258),    S(132, 202),    S(100, 192),    //
    S(240, 193),    S(248, 214),    S(244, 238),    S(232, 268),    S(233, 276),    S(187, 263),    S(180, 230),    S(174, 204),    //
    S(223, 199),    S(258, 182),    S(227, 238),    S(224, 257),    S(200, 262),    S(198, 246),    S(195, 196),    S(159, 203),    //
    S(167, 165),    S(193, 175),    S(184, 211),    S(192, 237),    S(188, 237),    S(152, 217),    S(141, 185),    S(113, 151),    //
    S(178, 169),    S(200, 165),    S(168, 174),    S(169, 197),    S(161, 195),    S(134, 152),    S(121, 175),    S(109, 86),     //
    S(116, 117),    S(159, 187),    S(176, 153),    S(193, 147),    S(174, 170),    S(142, 141),    S(127, 169),    S(88, 85),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(6, 302),      S(-8, 311),     S(-270, 353),   S(-138, 292),   S(-148, 313),   S(-160, 308),   S(-45, 308),    S(40, 277),     //
    S(127, 212),    S(66, 296),     S(102, 248),    S(49, 265),     S(67, 262),     S(91, 263),     S(125, 261),    S(101, 238),    //
    S(196, 243),    S(209, 255),    S(202, 265),    S(181, 262),    S(151, 259),    S(158, 269),    S(173, 259),    S(170, 230),    //
    S(166, 236),    S(201, 244),    S(203, 265),    S(201, 303),    S(229, 295),    S(162, 267),    S(172, 233),    S(132, 233),    //
    S(194, 192),    S(211, 225),    S(216, 249),    S(220, 278),    S(196, 292),    S(182, 271),    S(149, 248),    S(146, 204),    //
    S(221, 200),    S(254, 213),    S(265, 241),    S(210, 266),    S(206, 244),    S(201, 255),    S(207, 233),    S(148, 229),    //
    S(187, 169),    S(286, 190),    S(242, 204),    S(209, 222),    S(191, 224),    S(194, 202),    S(195, 198),    S(188, 191),    //
    S(220, 173),    S(207, 192),    S(205, 231),    S(221, 192),    S(210, 203),    S(211, 250),    S(206, 222),    S(198, 197),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(409, 367),    S(422, 387),    S(401, 399),    S(421, 362),    S(401, 366),    S(364, 380),    S(356, 397),    S(351, 397),    //
    S(295, 452),    S(372, 446),    S(447, 412),    S(395, 416),    S(379, 425),    S(358, 429),    S(291, 460),    S(268, 468),    //
    S(265, 449),    S(365, 435),    S(424, 393),    S(403, 381),    S(355, 410),    S(311, 434),    S(314, 429),    S(245, 473),    //
    S(271, 410),    S(347, 414),    S(382, 388),    S(357, 390),    S(345, 405),    S(306, 425),    S(300, 421),    S(227, 450),    //
    S(255, 342),    S(318, 355),    S(305, 378),    S(283, 373),    S(258, 399),    S(249, 409),    S(218, 405),    S(198, 406),    //
    S(247, 283),    S(307, 309),    S(292, 331),    S(276, 329),    S(262, 338),    S(236, 361),    S(234, 337),    S(198, 348),    //
    S(141, 292),    S(270, 255),    S(278, 284),    S(266, 305),    S(252, 311),    S(244, 314),    S(225, 302),    S(201, 314),    //
    S(207, 279),    S(229, 295),    S(281, 281),    S(293, 280),    S(282, 289),    S(262, 303),    S(250, 300),    S(230, 309),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(563, 652),    S(614, 599),    S(534, 729),    S(501, 798),    S(480, 788),    S(517, 728),    S(540, 649),    S(497, 684),    //
    S(562, 709),    S(524, 808),    S(514, 842),    S(373, 932),    S(379, 923),    S(442, 870),    S(485, 745),    S(494, 727),    //
    S(524, 778),    S(569, 801),    S(502, 906),    S(455, 918),    S(427, 917),    S(479, 832),    S(514, 755),    S(533, 674),    //
    S(563, 696),    S(566, 786),    S(503, 858),    S(495, 887),    S(486, 886),    S(499, 789),    S(541, 723),    S(527, 688),    //
    S(576, 666),    S(565, 734),    S(535, 792),    S(506, 835),    S(504, 835),    S(507, 781),    S(526, 700),    S(552, 625),    //
    S(556, 605),    S(591, 658),    S(582, 727),    S(553, 719),    S(551, 704),    S(544, 732),    S(558, 652),    S(536, 625),    //
    S(538, 490),    S(577, 507),    S(579, 575),    S(592, 611),    S(579, 637),    S(573, 603),    S(536, 641),    S(544, 622),    //
    S(522, 502),    S(554, 357),    S(577, 379),    S(593, 490),    S(587, 574),    S(587, 514),    S(574, 537),    S(541, 563),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-56, -330),   S(291, 172),    S(160, 133),    S(30, -28),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(232, -68),    S(348, 162),    S(202, 155),    S(120, 9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(227, 27),     S(384, 106),    S(267, 109),    S(164, 11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(87, -9),      S(337, 42),     S(180, 66),     S(118, 32),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -31),    S(236, 7),      S(157, 18),     S(40, 29),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -21),    S(215, -3),     S(112, 9),      S(61, -5),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-1, -22),     S(83, 35),      S(-7, 40),      S(-61, 17),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-113, -75),   S(-14, -28),    S(-115, -20),   S(-116, -83),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(22, -17), S(4, 19), S(0, 20), S(7, 6), S(8, 2), S(0, 20), S(6, 20), }},
  {{ S(10, -6), S(-18, 27), S(-14, 21), S(-4, 3), S(-4, 3), S(-13, 25), S(-17, 35), }},
  {{ S(-7, 1), S(-18, 26), S(-16, 8), S(-12, -6), S(-12, -4), S(-16, 8), S(-17, 23), }},
  {{ S(6, -15), S(-12, -15), S(-3, -18), S(3, -22), S(2, -21), S(-4, -16), S(-7, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(6, 28), S(-16, 35), S(-14, 24), S(-6, 12), S(-6, -5),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 6), S(-13, 15), S(-11, 13), S(-10, 13), S(-10, 8), S(-9, 4), S(-12, 13), }},
  {{ S(-1, 5), S(-9, 11), S(-16, 16), S(-13, 14), S(-12, 10), S(-15, 13), S(-9, 11), }},
  {{ S(-8, 10), S(-13, 7), S(-13, 14), S(-9, 13), S(-9, 12), S(-13, 12), S(-12, 8), }},
  {{ S(-8, 11), S(-13, 13), S(-14, 13), S(-9, 17), S(-7, 17), S(-13, 13), S(-15, 13), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1193, 565, -54, 47
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(140);
inline VParam WINNABLE_ASYM = V(128);
inline VParam WINNABLE_PAWN_ENDGAME = V(231);
inline VParam WINNABLE_BIAS = V(-673);
// Epoch duration: 7.52381s
// clang-format on
}  // namespace Clockwork
