#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(132, 206);
inline const PParam KNIGHT_MAT = S(592, 615);
inline const PParam BISHOP_MAT = S(617, 618);
inline const PParam ROOK_MAT   = S(480, 669);
inline const PParam QUEEN_MAT  = S(962, 1129);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_PAIR_VAL   = S(53, 199);
inline const PParam ROOK_OPEN_VAL     = S(117, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 27);
inline const PParam MINOR_BEHIND_PAWN = S(11, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -71);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-51, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(45, 63);
inline const PParam OUTPOST_BISHOP_VAL    = S(60, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, -1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(12, 3), S(28, 29), S(58, 49), S(145, 142), S(383, 202), S(607, 619),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 37), S(45, 26), S(61, 51), S(121, 138), S(444, 65),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-67, -125), S(-66, -98), S(-40, 12), S(11, 115), S(94, 253), S(262, 373),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -39), S(22, 4), S(14, 37), S(3, 113), S(78, 209), S(241, 274),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -22), S(4, 19), S(0, -14), S(2, -43), S(-4, -134), S(-237, -228),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(3, 143), S(-16, 111), S(-12, 41), S(-4, 6), S(3, 8), S(41, 7), S(35, -11),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-261, -72), S(-17, 15), S(-23, 62), S(11, 93), S(32, 114), S(43, 120), S(25, 116),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(86, 7), S(153, 176), S(186, 262), S(213, 292), S(246, 307), S(263, 335), S(287, 330), S(307, 339), S(358, 245),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(99, 5), S(142, 170), S(195, 237), S(220, 282), S(244, 313), S(258, 336), S(266, 352), S(277, 360), S(282, 373), S(303, 353), S(309, 351), S(362, 290), S(356, 304), S(410, 230),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(333, 245), S(246, 410), S(268, 438), S(284, 448), S(294, 462), S(299, 473), S(304, 484), S(311, 488), S(315, 499), S(323, 502), S(330, 506), S(334, 512), S(337, 511), S(353, 481), S(443, 373),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(477, 489), S(609, 584), S(635, 693), S(655, 798), S(670, 840), S(679, 879), S(685, 905), S(693, 912), S(697, 931), S(699, 944), S(706, 946), S(709, 951), S(715, 947), S(715, 950), S(716, 948), S(712, 950), S(709, 948), S(712, 939), S(715, 928), S(715, 923), S(714, 903), S(725, 872), S(706, 879), S(696, 824), S(670, 816), S(664, 779), S(602, 806), S(610, 769),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(467, -171), S(73, -80), S(19, -9), S(4, 21), S(-9, 11), S(-5, -3), S(-13, 8), S(-33, 14), S(-13, -31),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -97), S(14, -82), S(14, -73), S(6, -106), S(1, -51),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -123), S(6, -115), S(4, -101), S(4, -107), S(4, 20),
};

inline const PParam KS_NO_QUEEN = S(-594, -786);

inline const PParam KS_FLANK_ATTACK = S(3, -112);
inline const PParam KS_FLANK_DEFENSE = S(-5, -108);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -125);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -109);

inline const PParam PAWN_THREAT_KNIGHT = S(217, 84);
inline const PParam PAWN_THREAT_BISHOP = S(208, 131);
inline const PParam PAWN_THREAT_ROOK   = S(201, 121);
inline const PParam PAWN_THREAT_QUEEN  = S(185, -21);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -20);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 55);
inline const PParam BISHOP_THREAT_ROOK   = S(213, 123);
inline const PParam BISHOP_THREAT_QUEEN  = S(178, 79);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -29), S(-3, -2), S(-5, -11), S(-8, -22), S(-12, -32), S(-15, -40), S(-16, -52), S(-22, -53), S(-37, -49),
};

inline const PParam ROOK_LINEUP = S(13, 70);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(315, 323),    S(122, 436),    S(274, 379),    S(254, 326),    S(305, 250),    S(206, 324),    S(147, 359),    S(282, 309),    //
    S(124, 204),    S(139, 247),    S(152, 194),    S(122, 150),    S(118, 118),    S(97, 159),     S(80, 203),     S(45, 226),     //
    S(92, 163),     S(68, 180),     S(104, 133),    S(88, 109),     S(82, 95),      S(61, 115),     S(13, 158),     S(15, 179),     //
    S(59, 118),     S(33, 156),     S(66, 124),     S(53, 117),     S(30, 112),     S(26, 122),     S(-32, 156),    S(-21, 146),    //
    S(60, 85),      S(89, 95),      S(74, 131),     S(61, 128),     S(32, 120),     S(16, 119),     S(-22, 136),    S(-19, 127),    //
    S(77, 85),      S(157, 101),    S(140, 142),    S(92, 157),     S(64, 140),     S(45, 123),     S(13, 140),     S(0, 141),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-215, -165),  S(-149, 172),   S(-171, 105),   S(119, 163),    S(40, 170),     S(-105, 180),   S(-270, 232),   S(-287, -65),   //
    S(80, 141),     S(108, 168),    S(223, 140),    S(237, 150),    S(234, 156),    S(153, 176),    S(84, 181),     S(59, 161),     //
    S(147, 141),    S(186, 138),    S(213, 208),    S(230, 208),    S(191, 240),    S(141, 234),    S(141, 160),    S(90, 152),     //
    S(214, 159),    S(229, 183),    S(234, 218),    S(237, 246),    S(240, 251),    S(196, 235),    S(175, 193),    S(161, 163),    //
    S(195, 156),    S(237, 143),    S(217, 211),    S(213, 226),    S(190, 233),    S(194, 219),    S(185, 160),    S(140, 171),    //
    S(132, 127),    S(155, 155),    S(153, 197),    S(169, 214),    S(162, 214),    S(132, 194),    S(128, 155),    S(89, 121),     //
    S(147, 133),    S(158, 130),    S(133, 148),    S(142, 169),    S(137, 168),    S(112, 122),    S(94, 139),     S(83, 46),      //
    S(79, 71),      S(126, 132),    S(145, 109),    S(160, 114),    S(144, 133),    S(109, 107),    S(98, 121),     S(59, 28),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(3, 284),      S(-4, 294),     S(-285, 351),   S(-124, 288),   S(-128, 299),   S(-151, 294),   S(-54, 295),    S(27, 274),     //
    S(114, 210),    S(79, 282),     S(116, 238),    S(70, 259),     S(89, 251),     S(101, 255),    S(138, 245),    S(109, 218),    //
    S(184, 233),    S(175, 255),    S(190, 264),    S(178, 266),    S(160, 260),    S(164, 259),    S(171, 245),    S(167, 222),    //
    S(166, 217),    S(206, 230),    S(213, 257),    S(213, 298),    S(246, 281),    S(193, 246),    S(198, 210),    S(153, 212),    //
    S(205, 166),    S(205, 214),    S(226, 241),    S(230, 272),    S(210, 284),    S(207, 256),    S(175, 223),    S(169, 186),    //
    S(223, 180),    S(239, 200),    S(248, 235),    S(214, 256),    S(206, 239),    S(208, 243),    S(217, 221),    S(171, 206),    //
    S(183, 147),    S(264, 167),    S(228, 189),    S(206, 207),    S(190, 210),    S(198, 181),    S(195, 175),    S(199, 163),    //
    S(208, 151),    S(191, 182),    S(196, 200),    S(212, 177),    S(197, 189),    S(202, 223),    S(202, 203),    S(198, 172),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(411, 393),    S(460, 391),    S(413, 414),    S(412, 385),    S(449, 371),    S(413, 385),    S(427, 390),    S(400, 407),    //
    S(301, 465),    S(389, 456),    S(453, 427),    S(389, 440),    S(430, 424),    S(401, 431),    S(342, 457),    S(321, 465),    //
    S(265, 467),    S(391, 440),    S(433, 409),    S(405, 405),    S(404, 418),    S(356, 444),    S(361, 437),    S(295, 471),    //
    S(231, 448),    S(324, 445),    S(347, 423),    S(326, 428),    S(359, 411),    S(315, 445),    S(319, 440),    S(245, 465),    //
    S(210, 377),    S(290, 385),    S(277, 400),    S(252, 399),    S(263, 405),    S(254, 424),    S(229, 420),    S(211, 417),    //
    S(223, 305),    S(299, 324),    S(289, 339),    S(267, 338),    S(281, 336),    S(247, 372),    S(257, 349),    S(217, 357),    //
    S(124, 312),    S(270, 267),    S(272, 293),    S(264, 313),    S(270, 311),    S(257, 323),    S(251, 306),    S(218, 322),    //
    S(193, 289),    S(219, 310),    S(278, 296),    S(290, 290),    S(291, 298),    S(272, 316),    S(270, 309),    S(249, 315),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(532, 669),    S(623, 619),    S(554, 710),    S(506, 774),    S(535, 748),    S(535, 723),    S(562, 636),    S(480, 715),    //
    S(516, 723),    S(530, 808),    S(504, 825),    S(380, 890),    S(417, 894),    S(456, 859),    S(504, 753),    S(485, 742),    //
    S(488, 757),    S(522, 794),    S(486, 862),    S(446, 883),    S(455, 895),    S(504, 822),    S(530, 751),    S(533, 677),    //
    S(512, 638),    S(512, 729),    S(467, 794),    S(449, 857),    S(455, 886),    S(492, 779),    S(534, 712),    S(509, 682),    //
    S(513, 609),    S(494, 672),    S(474, 731),    S(449, 794),    S(456, 837),    S(473, 793),    S(496, 715),    S(514, 651),    //
    S(497, 554),    S(518, 582),    S(513, 658),    S(491, 679),    S(490, 710),    S(492, 747),    S(508, 697),    S(502, 651),    //
    S(466, 449),    S(494, 454),    S(503, 508),    S(523, 567),    S(511, 624),    S(510, 607),    S(479, 656),    S(500, 625),    //
    S(454, 461),    S(481, 325),    S(504, 343),    S(519, 451),    S(513, 549),    S(521, 500),    S(517, 527),    S(491, 556),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(10, -334),    S(315, 170),    S(270, 123),    S(187, -11),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(247, -59),    S(311, 171),    S(240, 154),    S(207, 21),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(167, 34),     S(235, 136),    S(197, 136),    S(161, 46),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(5, -3),       S(135, 78),     S(59, 107),     S(28, 105),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-110, -23),   S(-3, 49),      S(-53, 90),     S(-133, 136),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-47, -45),    S(27, 19),      S(-47, 70),     S(-93, 105),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(22, -73),     S(45, -8),      S(-22, 36),     S(-83, 66),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-50, -139),   S(13, -73),     S(-70, -41),    S(-69, -61),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(23, -85), S(5, -99), S(4, -98), S(14, -89), S(14, -46), S(3, -82), S(7, -87), }},
  {{ S(7, -76), S(-21, -69), S(-13, -99), S(-1, -101), S(0, -49), S(-12, -53), S(-19, -2), }},
  {{ S(2, -61), S(-11, -110), S(-5, -107), S(2, -84), S(2, -35), S(-5, -77), S(-10, 6), }},
  {{ S(15, -20), S(-3, -82), S(8, -87), S(13, -86), S(12, 1), S(6, 38), S(0, 12), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, -33), S(-12, -82), S(-9, -131), S(0, -59), S(3, -65),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, -88), S(-9, -93), S(-8, -69), S(-6, -78), S(-7, -78), S(-7, -107), S(-9, -118), }},
  {{ S(8, -68), S(0, -54), S(-10, -117), S(-7, -101), S(-7, 15), S(-8, -82), S(0, -142), }},
  {{ S(2, -107), S(-2, -95), S(-6, 78), S(-4, 53), S(-4, -54), S(-7, -55), S(-2, -119), }},
  {{ S(2, -79), S(-7, -16), S(-11, 61), S(-4, -23), S(-3, -119), S(-10, -146), S(-9, -36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1056, 555, -3, -98
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(127);
inline VParam WINNABLE_PAWN_ENDGAME = V(209);
inline VParam WINNABLE_BIAS = V(-665);

// Epoch duration: 9.72937s
// clang-format on
}  // namespace Clockwork
