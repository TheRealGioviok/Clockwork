#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(139, 192);
inline const PParam KNIGHT_MAT = S(587, 592);
inline const PParam BISHOP_MAT = S(631, 615);
inline const PParam ROOK_MAT   = S(498, 645);
inline const PParam QUEEN_MAT  = S(1165, 1015);
inline const PParam TEMPO_VAL  = S(25, 31);

inline const PParam BISHOP_PAIR_VAL   = S(53, 190);
inline const PParam ROOK_OPEN_VAL     = S(106, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 23);

inline const PParam DOUBLED_PAWN_VAL = S(-6, -67);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -20);

inline const PParam POTENTIAL_CHECKER_VAL = S(-51, -21);
inline const PParam OUTPOST_KNIGHT_VAL    = S(36, 63);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(29, 51);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(70, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -0), S(40, 23), S(58, 50), S(136, 147), S(368, 233), S(445, 730),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 32), S(45, 24), S(55, 52), S(121, 139), S(424, 69),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-79, -111), S(-75, -87), S(-49, 18), S(12, 121), S(105, 254), S(284, 359),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(34, -40), S(33, -1), S(20, 39), S(3, 111), S(56, 213), S(218, 274),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(24, -47), S(5, 4), S(1, -23), S(-4, -52), S(-15, -113), S(-226, -214),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-7, 151), S(-16, 117), S(-9, 45), S(-2, 9), S(2, 7), S(34, 7), S(4, 5),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-333, -36), S(-49, 24), S(-27, 58), S(12, 98), S(33, 116), S(54, 117), S(33, 116),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(70, -4), S(141, 168), S(175, 255), S(203, 290), S(243, 307), S(268, 340), S(300, 339), S(331, 353), S(384, 269),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(95, -2), S(137, 169), S(192, 230), S(219, 274), S(244, 304), S(261, 327), S(268, 346), S(283, 355), S(289, 373), S(313, 357), S(326, 356), S(374, 306), S(374, 318), S(400, 276),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(314, 233), S(235, 408), S(260, 431), S(278, 440), S(289, 453), S(295, 464), S(301, 473), S(311, 474), S(317, 484), S(329, 484), S(341, 485), S(350, 487), S(355, 487), S(370, 462), S(474, 342),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(496, 527), S(653, 493), S(678, 603), S(695, 718), S(711, 764), S(719, 808), S(725, 839), S(732, 849), S(736, 873), S(739, 886), S(746, 890), S(750, 898), S(759, 892), S(763, 894), S(767, 891), S(767, 891), S(770, 886), S(778, 876), S(785, 866), S(792, 863), S(802, 837), S(827, 794), S(821, 796), S(818, 740), S(806, 730), S(796, 703), S(731, 764), S(755, 658),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(489, -185), S(106, -103), S(28, -23), S(15, 9), S(-4, 8), S(-21, 2), S(-21, 3), S(-34, 8), S(-20, -35),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -6), S(14, -15), S(12, -12), S(5, -7), S(2, 150),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(6, -10), S(5, -8), S(5, -5), S(6, 429),
};

inline const PParam KING_SAFETY_TEMPO = S(-9, 9);

inline const PParam PAWN_THREAT_KNIGHT = S(212, 89);
inline const PParam PAWN_THREAT_BISHOP = S(190, 139);
inline const PParam PAWN_THREAT_ROOK   = S(200, 112);
inline const PParam PAWN_THREAT_QUEEN  = S(168, -17);

inline const PParam KNIGHT_THREAT_BISHOP = S(112, 95);
inline const PParam KNIGHT_THREAT_ROOK   = S(235, 55);
inline const PParam KNIGHT_THREAT_QUEEN  = S(149, 14);

inline const PParam BISHOP_THREAT_KNIGHT = S(106, 55);
inline const PParam BISHOP_THREAT_ROOK   = S(217, 117);
inline const PParam BISHOP_THREAT_QUEEN  = S(174, 112);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -31), S(-3, -10), S(-6, -18), S(-9, -28), S(-13, -37), S(-18, -42), S(-20, -54), S(-27, -51), S(-39, -51),
};

inline const PParam ROOK_LINEUP = S(10, 73);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(319, 325),    S(172, 419),    S(306, 402),    S(315, 269),    S(335, 226),    S(230, 305),    S(167, 344),    S(268, 307),    //
    S(119, 209),    S(150, 243),    S(190, 163),    S(176, 101),    S(155, 85),     S(127, 137),    S(100, 191),    S(54, 216),     //
    S(83, 169),     S(70, 170),     S(112, 101),    S(113, 81),     S(101, 77),     S(73, 108),     S(26, 155),     S(15, 184),     //
    S(57, 126),     S(47, 147),     S(82, 102),     S(81, 91),      S(60, 92),      S(44, 115),     S(-17, 157),    S(-16, 150),    //
    S(55, 101),     S(95, 106),     S(80, 138),     S(74, 124),     S(46, 119),     S(24, 123),     S(-11, 139),    S(-18, 135),    //
    S(71, 101),     S(163, 113),    S(149, 169),    S(98, 152),     S(69, 140),     S(49, 131),     S(19, 144),     S(1, 148),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-263, -66),   S(-147, 184),   S(-148, 98),    S(92, 184),     S(38, 179),     S(-119, 199),   S(-233, 213),   S(-303, 6),     //
    S(68, 165),     S(118, 181),    S(206, 143),    S(192, 167),    S(184, 180),    S(112, 186),    S(72, 205),     S(48, 176),     //
    S(164, 148),    S(198, 168),    S(210, 204),    S(207, 199),    S(173, 224),    S(109, 240),    S(121, 187),    S(87, 176),     //
    S(231, 172),    S(240, 193),    S(236, 216),    S(223, 248),    S(223, 255),    S(178, 240),    S(171, 209),    S(166, 179),    //
    S(213, 177),    S(247, 162),    S(219, 216),    S(216, 234),    S(191, 239),    S(188, 225),    S(187, 173),    S(150, 179),    //
    S(157, 146),    S(184, 152),    S(174, 190),    S(182, 216),    S(179, 213),    S(143, 195),    S(132, 163),    S(102, 134),    //
    S(168, 149),    S(190, 142),    S(159, 153),    S(161, 174),    S(152, 174),    S(124, 132),    S(109, 157),    S(97, 75),      //
    S(102, 103),    S(149, 163),    S(166, 129),    S(183, 122),    S(164, 144),    S(131, 118),    S(116, 143),    S(77, 69),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-6, 290),     S(-17, 300),    S(-284, 353),   S(-155, 292),   S(-163, 313),   S(-188, 323),   S(-64, 312),    S(20, 282),     //
    S(119, 200),    S(61, 283),     S(90, 241),     S(30, 271),     S(44, 270),     S(75, 259),     S(116, 250),    S(98, 222),     //
    S(190, 230),    S(201, 245),    S(199, 248),    S(175, 248),    S(143, 247),    S(149, 257),    S(167, 244),    S(164, 215),    //
    S(161, 220),    S(198, 225),    S(196, 254),    S(195, 286),    S(227, 272),    S(155, 254),    S(166, 218),    S(128, 215),    //
    S(189, 179),    S(206, 208),    S(212, 233),    S(218, 259),    S(194, 272),    S(177, 252),    S(144, 231),    S(138, 195),    //
    S(215, 187),    S(251, 196),    S(262, 223),    S(207, 248),    S(203, 227),    S(197, 238),    S(204, 214),    S(142, 216),    //
    S(183, 157),    S(282, 175),    S(240, 188),    S(206, 207),    S(186, 210),    S(191, 185),    S(190, 185),    S(184, 177),    //
    S(214, 161),    S(201, 181),    S(201, 210),    S(218, 169),    S(206, 184),    S(205, 224),    S(202, 203),    S(193, 182),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(427, 375),    S(454, 382),    S(428, 397),    S(439, 369),    S(414, 380),    S(386, 385),    S(379, 403),    S(370, 409),    //
    S(310, 452),    S(391, 443),    S(469, 407),    S(413, 416),    S(393, 429),    S(377, 428),    S(304, 463),    S(284, 472),    //
    S(276, 450),    S(381, 433),    S(437, 396),    S(421, 380),    S(372, 408),    S(329, 432),    S(330, 432),    S(260, 474),    //
    S(282, 411),    S(363, 414),    S(397, 391),    S(373, 391),    S(364, 402),    S(325, 422),    S(320, 419),    S(244, 448),    //
    S(264, 346),    S(332, 357),    S(320, 378),    S(300, 375),    S(279, 395),    S(268, 410),    S(235, 408),    S(215, 405),    //
    S(255, 288),    S(319, 314),    S(306, 337),    S(292, 335),    S(276, 347),    S(252, 367),    S(246, 348),    S(211, 355),    //
    S(149, 298),    S(280, 267),    S(290, 296),    S(282, 316),    S(267, 321),    S(256, 329),    S(241, 310),    S(215, 324),    //
    S(211, 288),    S(234, 310),    S(292, 298),    S(304, 295),    S(292, 303),    S(272, 318),    S(262, 314),    S(241, 323),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(564, 608),    S(621, 551),    S(542, 681),    S(506, 756),    S(492, 738),    S(517, 694),    S(544, 609),    S(490, 659),    //
    S(561, 675),    S(529, 764),    S(512, 812),    S(376, 896),    S(380, 886),    S(442, 836),    S(483, 714),    S(497, 688),    //
    S(529, 734),    S(571, 765),    S(515, 852),    S(454, 889),    S(429, 880),    S(477, 804),    S(521, 709),    S(538, 632),    //
    S(571, 647),    S(575, 735),    S(510, 815),    S(498, 850),    S(486, 857),    S(500, 756),    S(551, 670),    S(531, 649),    //
    S(583, 619),    S(573, 686),    S(541, 751),    S(512, 793),    S(509, 796),    S(509, 749),    S(530, 660),    S(556, 585),    //
    S(563, 561),    S(597, 618),    S(590, 680),    S(559, 677),    S(555, 665),    S(550, 689),    S(564, 609),    S(542, 583),    //
    S(544, 453),    S(584, 461),    S(588, 526),    S(599, 570),    S(583, 600),    S(577, 566),    S(542, 598),    S(552, 578),    //
    S(526, 467),    S(557, 324),    S(583, 340),    S(597, 452),    S(593, 524),    S(592, 470),    S(580, 492),    S(546, 529),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-64, -366),   S(272, 200),    S(175, 121),    S(65, -51),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(250, -98),    S(333, 192),    S(185, 182),    S(168, -21),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(229, 21),     S(385, 101),    S(284, 95),     S(208, -15),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(81, -7),      S(331, 45),     S(182, 63),     S(133, 31),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-31, -21),    S(235, 9),      S(163, 19),     S(41, 44),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -17),    S(204, -1),     S(110, 14),     S(79, 2),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-6, -20),     S(73, 36),      S(-9, 44),      S(-52, 28),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-118, -74),   S(-19, -26),    S(-118, -16),   S(-113, -76),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -16), S(-2, 17), S(-6, 21), S(1, 7), S(1, 4), S(-6, 21), S(0, 20), }},
  {{ S(5, -5), S(-21, 27), S(-19, 22), S(-10, 5), S(-9, 5), S(-18, 27), S(-20, 35), }},
  {{ S(-11, 0), S(-21, 26), S(-20, 9), S(-17, -4), S(-16, -3), S(-20, 9), S(-19, 22), }},
  {{ S(4, -11), S(-13, -10), S(-5, -13), S(-1, -17), S(-2, -15), S(-6, -11), S(-9, -11), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(4, 18), S(-16, 28), S(-14, 19), S(-7, 8), S(-7, -6),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 5), S(-13, 13), S(-12, 11), S(-11, 11), S(-11, 6), S(-10, 3), S(-13, 10), }},
  {{ S(-3, 2), S(-10, 7), S(-17, 13), S(-14, 9), S(-13, 5), S(-16, 9), S(-10, 7), }},
  {{ S(-9, 5), S(-13, 4), S(-14, 9), S(-10, 8), S(-10, 7), S(-14, 8), S(-13, 4), }},
  {{ S(-10, 7), S(-14, 9), S(-15, 9), S(-11, 11), S(-10, 12), S(-15, 8), S(-15, 8), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1348, 610, -33, 53
);

inline VParam WINNABLE_PAWNS = V(47);
inline VParam WINNABLE_BIAS = V(-448);

// Epoch duration: 7.06832s
// clang-format on
}  // namespace Clockwork
