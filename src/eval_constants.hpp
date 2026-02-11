#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 200);
inline const PParam KNIGHT_MAT = S(568, 628);
inline const PParam BISHOP_MAT = S(593, 646);
inline const PParam ROOK_MAT   = S(470, 679);
inline const PParam QUEEN_MAT  = S(1105, 1083);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(52, 197);
inline const PParam ROOK_OPEN_VAL     = S(105, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 21);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -70);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 66);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 41);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -37);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 2), S(38, 27), S(58, 51), S(135, 146), S(378, 204), S(457, 694),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(53, 36), S(44, 27), S(54, 55), S(117, 142), S(407, 85),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -121), S(-68, -99), S(-47, 12), S(10, 119), S(92, 268), S(262, 381),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -44), S(34, -5), S(22, 32), S(1, 109), S(47, 221), S(201, 284),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(23, -38), S(3, 11), S(3, -22), S(-1, -54), S(-8, -126), S(-210, -233),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-4, 148), S(-16, 113), S(-11, 45), S(-5, 10), S(0, 9), S(36, 7), S(10, 2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-306, -56), S(-42, 26), S(-26, 61), S(12, 97), S(30, 114), S(47, 115), S(30, 107),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(68, -1), S(138, 171), S(173, 260), S(201, 297), S(241, 315), S(265, 350), S(297, 348), S(328, 362), S(381, 276),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(98, 3), S(141, 177), S(195, 240), S(222, 285), S(247, 318), S(262, 342), S(270, 362), S(284, 371), S(289, 390), S(314, 371), S(325, 374), S(372, 322), S(370, 336), S(399, 285),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(313, 245), S(231, 425), S(256, 450), S(274, 460), S(285, 472), S(291, 483), S(297, 493), S(306, 495), S(312, 506), S(323, 507), S(334, 509), S(342, 514), S(347, 513), S(364, 485), S(448, 382),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(494, 513), S(635, 530), S(659, 644), S(677, 756), S(693, 803), S(701, 847), S(707, 879), S(715, 890), S(719, 913), S(722, 927), S(728, 935), S(732, 942), S(741, 936), S(744, 941), S(749, 936), S(747, 940), S(750, 934), S(756, 927), S(761, 922), S(772, 913), S(781, 889), S(802, 851), S(800, 849), S(799, 794), S(788, 778), S(780, 748), S(720, 795), S(738, 709),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(491, -191), S(99, -94), S(23, -16), S(12, 13), S(-5, 10), S(-19, -2), S(-21, 2), S(-33, 4), S(-19, -41),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(22, -10), S(30, -26), S(25, -21), S(11, -13), S(5, -44),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(8, -1), S(13, -19), S(11, -15), S(10, -9), S(10, 129),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 92);
inline const PParam PAWN_THREAT_BISHOP = S(190, 144);
inline const PParam PAWN_THREAT_ROOK   = S(191, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(167, -17);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 67);
inline const PParam KNIGHT_THREAT_QUEEN  = S(150, -0);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 97);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -18), S(-9, -28), S(-13, -37), S(-18, -42), S(-20, -55), S(-27, -52), S(-39, -53),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(296, 347),    S(145, 447),    S(290, 417),    S(301, 282),    S(324, 236),    S(218, 319),    S(155, 357),    S(264, 310),    //
    S(116, 211),    S(147, 252),    S(185, 169),    S(171, 103),    S(152, 85),     S(125, 138),    S(99, 193),     S(49, 220),     //
    S(81, 175),     S(68, 177),     S(109, 104),    S(110, 81),     S(99, 78),      S(71, 109),     S(23, 159),     S(12, 187),     //
    S(57, 127),     S(46, 150),     S(81, 100),     S(79, 90),      S(58, 93),      S(41, 117),     S(-19, 160),    S(-19, 153),    //
    S(55, 101),     S(95, 108),     S(80, 138),     S(73, 124),     S(45, 119),     S(22, 125),     S(-12, 141),    S(-20, 135),    //
    S(69, 102),     S(159, 117),    S(144, 173),    S(95, 154),     S(67, 141),     S(46, 135),     S(16, 147),     S(-2, 150),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-254, -76),   S(-156, 194),   S(-101, 46),    S(89, 187),     S(28, 187),     S(-115, 189),   S(-249, 239),   S(-292, -5),    //
    S(71, 162),     S(114, 188),    S(202, 147),    S(196, 156),    S(193, 162),    S(107, 190),    S(71, 206),     S(46, 182),     //
    S(156, 158),    S(203, 154),    S(205, 210),    S(204, 197),    S(166, 230),    S(104, 247),    S(117, 190),    S(84, 180),     //
    S(225, 179),    S(232, 199),    S(228, 225),    S(215, 256),    S(216, 264),    S(171, 249),    S(164, 217),    S(159, 188),    //
    S(208, 182),    S(243, 166),    S(213, 224),    S(209, 244),    S(185, 248),    S(183, 232),    S(181, 181),    S(144, 188),    //
    S(154, 146),    S(179, 158),    S(169, 196),    S(178, 223),    S(173, 222),    S(138, 202),    S(128, 169),    S(98, 137),     //
    S(165, 151),    S(187, 148),    S(154, 157),    S(156, 181),    S(147, 179),    S(120, 136),    S(107, 158),    S(95, 72),      //
    S(100, 103),    S(146, 169),    S(161, 134),    S(178, 127),    S(158, 151),    S(126, 123),    S(111, 148),    S(73, 69),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(4, 298),      S(-9, 307),     S(-268, 348),   S(-136, 287),   S(-149, 310),   S(-159, 305),   S(-44, 304),    S(36, 277),     //
    S(126, 209),    S(69, 288),     S(102, 242),    S(47, 261),     S(64, 259),     S(88, 260),     S(126, 255),    S(102, 233),    //
    S(197, 238),    S(210, 250),    S(203, 260),    S(179, 259),    S(151, 253),    S(159, 262),    S(174, 254),    S(171, 225),    //
    S(167, 229),    S(202, 239),    S(204, 259),    S(200, 298),    S(230, 288),    S(161, 264),    S(174, 228),    S(133, 226),    //
    S(195, 188),    S(212, 221),    S(217, 244),    S(221, 273),    S(197, 288),    S(182, 266),    S(150, 243),    S(147, 200),    //
    S(222, 196),    S(256, 207),    S(267, 236),    S(212, 261),    S(208, 238),    S(202, 250),    S(209, 227),    S(149, 224),    //
    S(189, 167),    S(288, 185),    S(245, 198),    S(212, 216),    S(192, 220),    S(196, 196),    S(196, 194),    S(189, 189),    //
    S(220, 168),    S(208, 186),    S(207, 221),    S(221, 183),    S(211, 194),    S(210, 236),    S(207, 216),    S(199, 192),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(426, 379),    S(436, 401),    S(413, 414),    S(432, 376),    S(411, 383),    S(378, 393),    S(374, 409),    S(369, 411),    //
    S(298, 467),    S(375, 462),    S(452, 427),    S(396, 434),    S(380, 443),    S(360, 447),    S(294, 477),    S(278, 483),    //
    S(267, 461),    S(369, 448),    S(427, 407),    S(407, 396),    S(358, 425),    S(315, 449),    S(319, 445),    S(252, 486),    //
    S(273, 419),    S(349, 430),    S(385, 404),    S(358, 408),    S(349, 419),    S(310, 441),    S(306, 435),    S(233, 461),    //
    S(255, 353),    S(319, 371),    S(308, 391),    S(287, 388),    S(263, 413),    S(255, 424),    S(225, 418),    S(204, 416),    //
    S(248, 294),    S(308, 324),    S(295, 349),    S(280, 347),    S(267, 355),    S(242, 378),    S(239, 354),    S(205, 359),    //
    S(141, 305),    S(273, 272),    S(284, 300),    S(272, 325),    S(258, 329),    S(250, 333),    S(231, 320),    S(207, 330),    //
    S(205, 291),    S(228, 311),    S(284, 302),    S(296, 299),    S(285, 307),    S(265, 322),    S(254, 318),    S(235, 327),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(557, 633),    S(605, 589),    S(528, 713),    S(497, 779),    S(481, 763),    S(516, 706),    S(536, 633),    S(489, 675),    //
    S(553, 698),    S(514, 798),    S(505, 826),    S(364, 914),    S(372, 901),    S(432, 857),    S(477, 733),    S(486, 716),    //
    S(516, 768),    S(563, 780),    S(495, 886),    S(450, 895),    S(422, 894),    S(475, 809),    S(508, 735),    S(526, 664),    //
    S(556, 681),    S(563, 763),    S(501, 831),    S(491, 862),    S(482, 864),    S(492, 772),    S(536, 705),    S(521, 673),    //
    S(570, 655),    S(558, 722),    S(530, 774),    S(498, 819),    S(497, 822),    S(499, 769),    S(518, 690),    S(545, 615),    //
    S(550, 595),    S(584, 647),    S(576, 712),    S(546, 706),    S(542, 693),    S(536, 721),    S(551, 640),    S(530, 614),    //
    S(531, 485),    S(568, 497),    S(573, 562),    S(584, 600),    S(571, 628),    S(564, 594),    S(527, 634),    S(538, 612),    //
    S(513, 498),    S(545, 346),    S(568, 368),    S(582, 479),    S(578, 552),    S(577, 497),    S(565, 524),    S(533, 555),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-43, -344),   S(297, 166),    S(169, 123),    S(40, -41),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(239, -77),    S(351, 163),    S(203, 154),    S(120, 6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(238, 20),     S(387, 109),    S(267, 109),    S(161, 9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(94, -12),     S(341, 46),     S(182, 66),     S(115, 31),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-10, -34),    S(239, 12),     S(162, 17),     S(38, 28),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, -24),    S(215, 2),      S(115, 8),      S(58, -6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(3, -23),      S(81, 42),      S(-5, 40),      S(-64, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-108, -78),   S(-14, -26),    S(-115, -23),   S(-118, -94),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(27, -23), S(-9, 43), S(-16, 44), S(-1, 16), S(-1, 10), S(-15, 43), S(-5, 44), }},
  {{ S(7, -7), S(-47, 52), S(-39, 41), S(-21, 8), S(-20, 9), S(-38, 49), S(-46, 66), }},
  {{ S(-13, 2), S(-35, 49), S(-31, 16), S(-24, -9), S(-23, -6), S(-30, 16), S(-32, 43), }},
  {{ S(-1, -23), S(-35, -22), S(-18, -28), S(-8, -35), S(-11, -32), S(-20, -24), S(-27, -24), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(12, 48), S(-30, 54), S(-25, 37), S(-10, 17), S(-9, -13),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 4), S(-23, 22), S(-20, 18), S(-18, 17), S(-18, 7), S(-16, 2), S(-22, 19), }},
  {{ S(-0, 3), S(-16, 16), S(-29, 24), S(-22, 17), S(-22, 11), S(-26, 19), S(-15, 14), }},
  {{ S(-13, 11), S(-23, 11), S(-24, 20), S(-16, 18), S(-15, 16), S(-23, 17), S(-21, 11), }},
  {{ S(-14, 15), S(-24, 19), S(-26, 18), S(-16, 24), S(-13, 25), S(-24, 18), S(-27, 18), }},
}};
inline TunableSigmoid<64> KING_SAFETY_ACTIVATION(
        1269, 656, -84, 97
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(226);
inline VParam WINNABLE_BIAS = V(-656);

// Epoch duration: 7.11641s
// clang-format on
}  // namespace Clockwork
