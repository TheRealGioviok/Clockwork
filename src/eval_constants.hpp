#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(134, 205);
inline const PParam KNIGHT_MAT = S(591, 618);
inline const PParam BISHOP_MAT = S(617, 629);
inline const PParam ROOK_MAT   = S(474, 654);
inline const PParam QUEEN_MAT  = S(1035, 461);
inline const PParam TEMPO_VAL  = S(58, 20);

inline const PParam BISHOP_PAIR_VAL   = S(54, 192);
inline const PParam ROOK_OPEN_VAL     = S(105, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 24);
inline const PParam MINOR_BEHIND_PAWN = S(9, 37);

inline const PParam DOUBLED_PAWN_VAL = S(-5, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 56);
inline const PParam OUTPOST_BISHOP_VAL    = S(54, 41);
inline const PParam REACHABLE_OUTPOST_KNIGHT_VAL    = S(38, 29);
inline const PParam REACHABLE_OUTPOST_BISHOP_VAL    = S(29, 18);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(28, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(69, -43);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, 1), S(38, 24), S(59, 48), S(135, 147), S(379, 206), S(438, 720),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(53, 33), S(47, 27), S(57, 55), S(121, 138), S(423, 77),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -104), S(-77, -87), S(-48, 12), S(16, 106), S(105, 244), S(283, 354),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(38, -41), S(38, -4), S(26, 30), S(5, 107), S(62, 203), S(217, 262),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(16, -25), S(2, 22), S(0, -10), S(-3, -40), S(-3, -123), S(-228, -207),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(0, 144), S(-18, 115), S(-11, 42), S(-4, 5), S(1, 6), S(36, 5), S(11, -3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-319, -32), S(-39, 30), S(-31, 73), S(16, 85), S(36, 101), S(53, 102), S(34, 94),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(58, -1), S(128, 169), S(162, 259), S(187, 294), S(226, 309), S(248, 338), S(278, 334), S(307, 343), S(350, 272),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(85, -7), S(128, 167), S(181, 237), S(207, 282), S(231, 314), S(247, 337), S(253, 355), S(265, 365), S(271, 380), S(294, 361), S(306, 360), S(350, 310), S(352, 319), S(380, 273),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(324, 241), S(238, 422), S(263, 450), S(280, 460), S(290, 474), S(296, 485), S(301, 496), S(310, 498), S(315, 509), S(326, 510), S(337, 511), S(344, 516), S(350, 513), S(367, 485), S(445, 391),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(438, 200), S(588, 200), S(613, 312), S(630, 431), S(646, 478), S(654, 524), S(660, 557), S(667, 567), S(671, 592), S(674, 605), S(680, 612), S(684, 620), S(691, 617), S(693, 622), S(698, 617), S(697, 619), S(698, 617), S(703, 613), S(709, 604), S(719, 597), S(725, 575), S(744, 539), S(736, 545), S(740, 481), S(721, 482), S(716, 445), S(656, 490), S(679, 392),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(483, -200), S(101, -119), S(21, -23), S(9, 8), S(-6, 4), S(-13, 2), S(-15, 5), S(-28, 16), S(-27, 1),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -36), S(13, -22), S(12, -4), S(5, -12), S(2, 133),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -23), S(5, -33), S(5, -21), S(5, -6), S(5, 288),
};

inline const PParam KS_NO_QUEEN = S(-70, -741);
inline const PParam PAWN_THREAT_KNIGHT = S(213, 95);
inline const PParam PAWN_THREAT_BISHOP = S(192, 139);
inline const PParam PAWN_THREAT_ROOK   = S(193, 130);
inline const PParam PAWN_THREAT_QUEEN  = S(173, -24);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(224, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -8);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 127);
inline const PParam BISHOP_THREAT_QUEEN  = S(182, 84);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -28), S(-2, -5), S(-5, -14), S(-8, -24), S(-11, -33), S(-16, -38), S(-18, -49), S(-25, -46), S(-36, -46),
};

inline const PParam ROOK_LINEUP = S(12, 70);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(325, 313),    S(185, 395),    S(311, 370),    S(305, 287),    S(328, 242),    S(216, 331),    S(154, 380),    S(271, 310),    //
    S(117, 217),    S(162, 240),    S(195, 179),    S(162, 138),    S(146, 114),    S(115, 173),    S(90, 224),     S(42, 242),     //
    S(91, 161),     S(81, 172),     S(111, 126),    S(104, 108),    S(93, 99),      S(66, 128),     S(21, 171),     S(8, 198),      //
    S(64, 113),     S(52, 145),     S(78, 115),     S(71, 108),     S(50, 109),     S(33, 130),     S(-25, 169),    S(-23, 162),    //
    S(60, 91),      S(94, 95),      S(75, 133),     S(66, 129),     S(38, 124),     S(13, 133),     S(-20, 151),    S(-25, 144),    //
    S(74, 91),      S(156, 110),    S(134, 157),    S(86, 164),     S(58, 151),     S(37, 140),     S(10, 157),     S(-7, 157),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-274, -76),   S(-172, 200),   S(5, -84),      S(75, 205),     S(38, 180),     S(-109, 173),   S(-262, 243),   S(-309, -7),    //
    S(62, 149),     S(110, 170),    S(194, 150),    S(189, 171),    S(183, 175),    S(102, 189),    S(64, 186),     S(36, 171),     //
    S(147, 146),    S(186, 151),    S(209, 202),    S(204, 205),    S(166, 239),    S(107, 237),    S(107, 182),    S(73, 169),     //
    S(217, 174),    S(224, 206),    S(224, 229),    S(210, 266),    S(214, 266),    S(170, 248),    S(160, 216),    S(152, 182),    //
    S(198, 181),    S(235, 170),    S(211, 219),    S(204, 238),    S(181, 243),    S(180, 227),    S(172, 182),    S(134, 182),    //
    S(151, 139),    S(178, 158),    S(170, 193),    S(177, 214),    S(173, 214),    S(138, 195),    S(127, 164),    S(96, 130),     //
    S(159, 147),    S(174, 141),    S(150, 158),    S(153, 183),    S(146, 180),    S(117, 140),    S(97, 154),     S(89, 71),      //
    S(89, 96),      S(138, 159),    S(151, 135),    S(170, 136),    S(151, 155),    S(118, 132),    S(103, 145),    S(64, 54),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-6, 298),     S(-12, 300),    S(-279, 354),   S(-145, 289),   S(-143, 301),   S(-164, 306),   S(-50, 303),    S(29, 276),     //
    S(120, 212),    S(66, 286),     S(97, 238),     S(41, 263),     S(58, 261),     S(82, 256),     S(117, 262),    S(96, 234),     //
    S(179, 242),    S(202, 244),    S(192, 261),    S(171, 261),    S(140, 262),    S(149, 264),    S(163, 252),    S(158, 225),    //
    S(158, 230),    S(194, 238),    S(200, 257),    S(193, 303),    S(224, 289),    S(153, 264),    S(165, 232),    S(126, 230),    //
    S(190, 183),    S(208, 224),    S(212, 251),    S(217, 276),    S(194, 288),    S(176, 270),    S(143, 246),    S(140, 200),    //
    S(214, 194),    S(251, 212),    S(262, 236),    S(206, 263),    S(201, 241),    S(197, 250),    S(203, 229),    S(139, 226),    //
    S(176, 163),    S(277, 176),    S(236, 198),    S(206, 219),    S(187, 223),    S(189, 198),    S(188, 188),    S(180, 182),    //
    S(209, 168),    S(195, 194),    S(197, 215),    S(212, 194),    S(202, 203),    S(202, 240),    S(200, 218),    S(189, 187),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(421, 387),    S(431, 408),    S(420, 417),    S(429, 390),    S(409, 396),    S(376, 405),    S(373, 418),    S(369, 417),    //
    S(300, 472),    S(376, 465),    S(458, 430),    S(403, 441),    S(385, 452),    S(366, 454),    S(298, 485),    S(285, 486),    //
    S(271, 466),    S(374, 448),    S(432, 415),    S(409, 403),    S(363, 433),    S(320, 456),    S(322, 453),    S(261, 489),    //
    S(275, 430),    S(354, 436),    S(392, 409),    S(363, 415),    S(361, 417),    S(318, 446),    S(313, 443),    S(240, 469),    //
    S(259, 365),    S(324, 381),    S(310, 406),    S(294, 395),    S(275, 413),    S(264, 429),    S(230, 428),    S(209, 429),    //
    S(249, 313),    S(305, 344),    S(295, 363),    S(282, 358),    S(270, 365),    S(242, 393),    S(241, 368),    S(205, 381),    //
    S(139, 329),    S(271, 291),    S(282, 318),    S(275, 337),    S(260, 343),    S(250, 351),    S(234, 335),    S(210, 348),    //
    S(207, 305),    S(228, 329),    S(284, 320),    S(297, 314),    S(288, 320),    S(267, 338),    S(257, 335),    S(239, 341),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(494, 448),    S(550, 392),    S(484, 495),    S(453, 561),    S(442, 535),    S(473, 486),    S(489, 417),    S(432, 475),    //
    S(499, 494),    S(464, 589),    S(460, 608),    S(319, 697),    S(330, 678),    S(387, 640),    S(429, 519),    S(436, 502),    //
    S(463, 562),    S(513, 575),    S(456, 661),    S(405, 676),    S(381, 669),    S(429, 592),    S(466, 512),    S(481, 438),    //
    S(509, 463),    S(515, 551),    S(452, 624),    S(444, 651),    S(435, 651),    S(449, 552),    S(491, 488),    S(474, 453),    //
    S(525, 428),    S(511, 507),    S(485, 555),    S(456, 597),    S(456, 597),    S(458, 540),    S(472, 469),    S(499, 390),    //
    S(501, 374),    S(537, 417),    S(527, 487),    S(498, 483),    S(496, 469),    S(492, 488),    S(504, 411),    S(482, 389),    //
    S(484, 249),    S(521, 258),    S(525, 322),    S(535, 372),    S(523, 398),    S(518, 361),    S(481, 400),    S(489, 384),    //
    S(465, 256),    S(495, 106),    S(519, 129),    S(533, 240),    S(530, 314),    S(528, 263),    S(518, 287),    S(487, 318),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-178, -162),  S(176, 290),    S(101, 281),    S(-60, 200),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(101, 56),     S(251, 205),    S(158, 233),    S(108, 116),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(101, 108),    S(263, 154),    S(222, 160),    S(170, 81),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-13, 36),     S(230, 65),     S(151, 97),     S(137, 84),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-83, -28),    S(163, -6),     S(131, 40),     S(48, 88),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -65),    S(174, -45),    S(100, 14),     S(58, 55),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(8, -81),      S(84, -39),     S(9, 9),        S(-41, 39),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-107, -117),  S(-10, -72),    S(-103, -36),   S(-98, -54),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, 52), S(-1, 54), S(-4, 54), S(3, 16), S(2, 12), S(-4, 54), S(1, 54), }},
  {{ S(7, 124), S(-18, 102), S(-14, 90), S(-4, 44), S(-4, 51), S(-13, 92), S(-17, 106), }},
  {{ S(2, 116), S(-10, 106), S(-6, 84), S(-3, 56), S(-2, 47), S(-6, 83), S(-9, 105), }},
  {{ S(7, 116), S(-9, 58), S(-0, 74), S(3, 61), S(2, 60), S(-1, 70), S(-6, 69), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(2, -151), S(-18, 99), S(-15, 40), S(-9, 107), S(-10, 71),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-7, 132), S(-15, 119), S(-14, 96), S(-13, 95), S(-14, 103), S(-13, 97), S(-15, 120), }},
  {{ S(-6, 67), S(-12, 54), S(-18, 45), S(-14, 18), S(-15, 6), S(-17, 31), S(-11, 49), }},
  {{ S(-11, 80), S(-15, 62), S(-16, 62), S(-12, 54), S(-12, 43), S(-16, 55), S(-14, 61), }},
  {{ S(-11, 79), S(-17, 71), S(-18, 51), S(-12, 49), S(-11, 50), S(-17, 57), S(-18, 66), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1384, 1629, -42, 136
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(136);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(240);
inline VParam WINNABLE_BIAS = V(-650);

// Epoch duration: 8.08981s
// clang-format on
}  // namespace Clockwork
