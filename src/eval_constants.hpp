#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(136, 211);
inline const PParam KNIGHT_MAT = S(528, 558);
inline const PParam BISHOP_MAT = S(562, 577);
inline const PParam ROOK_MAT   = S(404, 604);
inline const PParam QUEEN_MAT  = S(854, 993);
inline const PParam TEMPO_VAL  = S(58, 20);

inline const PParam BISHOP_PAIR_VAL   = S(50, 200);
inline const PParam ROOK_OPEN_VAL     = S(105, -9);
inline const PParam ROOK_SEMIOPEN_VAL = S(40, 29);
inline const PParam MINOR_BEHIND_PAWN = S(10, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-8, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-17, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(40, 55);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -28);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(29, 48);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(69, -45);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, 6), S(39, 23), S(59, 47), S(135, 144), S(363, 225), S(451, 677),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 33), S(46, 26), S(55, 53), S(116, 141), S(413, 83),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-73, -118), S(-70, -93), S(-45, 14), S(12, 115), S(98, 252), S(274, 374),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(33, -39), S(37, -7), S(27, 25), S(4, 106), S(63, 204), S(241, 252),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -29), S(4, 19), S(2, -10), S(0, -42), S(-1, -128), S(-223, -217),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(3, 149), S(-16, 115), S(-10, 41), S(-4, 4), S(-0, 5), S(34, 4), S(9, -4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-283, -68), S(-28, 21), S(-26, 64), S(9, 95), S(29, 113), S(47, 113), S(31, 101),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(37, -9), S(108, 158), S(143, 244), S(170, 280), S(211, 294), S(236, 325), S(268, 319), S(300, 329), S(353, 240),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(69, -36), S(112, 143), S(166, 214), S(193, 261), S(218, 295), S(234, 318), S(242, 338), S(256, 347), S(263, 364), S(290, 340), S(303, 340), S(356, 279), S(354, 293), S(399, 227),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(284, 201), S(197, 383), S(222, 411), S(239, 422), S(249, 436), S(255, 447), S(260, 460), S(269, 461), S(273, 474), S(284, 475), S(295, 476), S(301, 483), S(306, 483), S(324, 451), S(401, 354),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(365, 415), S(511, 424), S(536, 541), S(554, 658), S(569, 705), S(578, 750), S(583, 785), S(591, 795), S(594, 819), S(598, 833), S(603, 840), S(607, 849), S(615, 845), S(617, 848), S(621, 845), S(621, 847), S(621, 846), S(626, 842), S(634, 831), S(641, 827), S(648, 805), S(661, 775), S(661, 770), S(655, 719), S(639, 713), S(629, 685), S(576, 723), S(585, 651),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(480, -207), S(98, -112), S(20, -19), S(8, 9), S(-6, 0), S(-13, -3), S(-14, 6), S(-27, 20), S(-19, 0),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-11, -94), S(-16, -30), S(-14, -8), S(-6, -39), S(-2, 145),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-3, -4), S(-6, -25), S(-5, -23), S(-6, -17), S(-6, 385),
};

inline const PParam KS_NO_QUEEN = S(71, -392);
inline const PParam PAWN_THREAT_KNIGHT = S(215, 88);
inline const PParam PAWN_THREAT_BISHOP = S(191, 138);
inline const PParam PAWN_THREAT_ROOK   = S(194, 121);
inline const PParam PAWN_THREAT_QUEEN  = S(172, -25);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(222, 75);
inline const PParam KNIGHT_THREAT_QUEEN  = S(150, 0);

inline const PParam BISHOP_THREAT_KNIGHT = S(107, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 128);
inline const PParam BISHOP_THREAT_QUEEN  = S(178, 97);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -33), S(-3, -5), S(-6, -12), S(-8, -22), S(-12, -31), S(-16, -36), S(-18, -48), S(-25, -45), S(-36, -45),
};

inline const PParam ROOK_LINEUP = S(13, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(324, 318),    S(183, 410),    S(314, 395),    S(291, 308),    S(320, 252),    S(216, 330),    S(160, 369),    S(264, 318),    //
    S(121, 215),    S(161, 248),    S(186, 198),    S(159, 147),    S(145, 119),    S(120, 170),    S(100, 215),    S(47, 240),     //
    S(86, 170),     S(76, 181),     S(109, 130),    S(107, 105),    S(96, 97),      S(72, 123),     S(26, 168),     S(13, 193),     //
    S(60, 119),     S(49, 151),     S(77, 116),     S(73, 106),     S(53, 105),     S(38, 126),     S(-20, 168),    S(-19, 157),    //
    S(57, 94),      S(93, 97),      S(77, 135),     S(70, 124),     S(41, 121),     S(20, 128),     S(-14, 148),    S(-21, 139),    //
    S(71, 93),      S(158, 111),    S(144, 174),    S(91, 155),     S(63, 142),     S(43, 135),     S(15, 150),     S(-3, 150),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-270, -84),   S(-169, 190),   S(-96, 25),     S(90, 183),     S(48, 161),     S(-124, 186),   S(-266, 237),   S(-305, -21),   //
    S(67, 144),     S(116, 165),    S(202, 146),    S(200, 161),    S(196, 166),    S(111, 185),    S(69, 184),     S(44, 160),     //
    S(147, 139),    S(197, 132),    S(208, 196),    S(208, 197),    S(163, 240),    S(101, 238),    S(109, 170),    S(75, 157),     //
    S(215, 168),    S(222, 194),    S(220, 223),    S(205, 260),    S(206, 265),    S(162, 246),    S(153, 210),    S(149, 176),    //
    S(199, 172),    S(236, 158),    S(206, 214),    S(201, 233),    S(176, 238),    S(176, 220),    S(173, 170),    S(135, 170),    //
    S(147, 126),    S(171, 148),    S(160, 189),    S(169, 208),    S(165, 205),    S(129, 187),    S(120, 154),    S(91, 118),     //
    S(151, 137),    S(170, 133),    S(141, 143),    S(145, 169),    S(137, 168),    S(108, 126),    S(94, 142),     S(86, 49),      //
    S(84, 76),      S(130, 144),    S(144, 118),    S(163, 120),    S(145, 140),    S(112, 114),    S(96, 132),     S(58, 40),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-14, 276),    S(-24, 283),    S(-279, 329),   S(-139, 264),   S(-140, 278),   S(-162, 278),   S(-52, 273),    S(18, 255),     //
    S(107, 192),    S(53, 267),     S(89, 217),     S(42, 241),     S(54, 244),     S(69, 241),     S(108, 238),    S(82, 218),     //
    S(164, 224),    S(183, 229),    S(183, 238),    S(161, 240),    S(125, 247),    S(134, 249),    S(146, 233),    S(141, 206),    //
    S(141, 215),    S(178, 221),    S(180, 246),    S(174, 288),    S(204, 275),    S(136, 247),    S(148, 212),    S(108, 209),    //
    S(174, 167),    S(191, 205),    S(196, 230),    S(195, 262),    S(173, 272),    S(159, 251),    S(127, 224),    S(123, 181),    //
    S(199, 175),    S(237, 189),    S(245, 214),    S(190, 243),    S(184, 221),    S(179, 229),    S(187, 209),    S(124, 206),    //
    S(162, 142),    S(261, 152),    S(220, 173),    S(189, 195),    S(170, 199),    S(173, 174),    S(173, 163),    S(166, 162),    //
    S(195, 146),    S(179, 175),    S(180, 193),    S(196, 172),    S(187, 180),    S(186, 219),    S(183, 201),    S(174, 168),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(376, 373),    S(388, 391),    S(369, 407),    S(389, 369),    S(369, 374),    S(327, 390),    S(332, 396),    S(324, 400),    //
    S(259, 458),    S(338, 447),    S(411, 421),    S(360, 429),    S(344, 436),    S(324, 438),    S(257, 467),    S(242, 470),    //
    S(238, 440),    S(339, 424),    S(393, 397),    S(372, 383),    S(323, 414),    S(282, 434),    S(283, 431),    S(221, 468),    //
    S(239, 404),    S(317, 409),    S(357, 379),    S(329, 385),    S(323, 389),    S(277, 421),    S(274, 415),    S(200, 444),    //
    S(222, 337),    S(287, 352),    S(277, 371),    S(258, 364),    S(237, 382),    S(226, 399),    S(193, 397),    S(173, 397),    //
    S(214, 282),    S(272, 311),    S(263, 328),    S(249, 323),    S(236, 332),    S(209, 358),    S(206, 336),    S(169, 349),    //
    S(106, 294),    S(238, 257),    S(249, 283),    S(242, 303),    S(227, 307),    S(218, 315),    S(200, 301),    S(174, 315),    //
    S(173, 268),    S(194, 295),    S(251, 285),    S(264, 278),    S(254, 285),    S(234, 302),    S(223, 300),    S(205, 304),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(450, 567),    S(499, 517),    S(434, 623),    S(405, 687),    S(391, 666),    S(427, 609),    S(442, 540),    S(386, 597),    //
    S(454, 615),    S(418, 713),    S(414, 732),    S(270, 828),    S(280, 812),    S(340, 767),    S(380, 648),    S(385, 636),    //
    S(417, 683),    S(469, 690),    S(406, 789),    S(358, 799),    S(330, 800),    S(382, 715),    S(420, 630),    S(431, 567),    //
    S(462, 588),    S(470, 670),    S(405, 748),    S(396, 777),    S(385, 782),    S(401, 676),    S(441, 614),    S(428, 573),    //
    S(478, 553),    S(468, 625),    S(436, 686),    S(409, 725),    S(407, 726),    S(411, 667),    S(425, 596),    S(452, 515),    //
    S(455, 498),    S(493, 540),    S(483, 610),    S(453, 609),    S(450, 597),    S(446, 616),    S(458, 538),    S(435, 516),    //
    S(437, 375),    S(473, 391),    S(477, 459),    S(490, 497),    S(478, 525),    S(472, 488),    S(434, 528),    S(443, 509),    //
    S(417, 383),    S(446, 237),    S(470, 260),    S(486, 370),    S(483, 441),    S(481, 392),    S(469, 418),    S(440, 443),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-108, -281),  S(256, 220),    S(163, 179),    S(28, 53),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(148, 10),     S(289, 182),    S(203, 166),    S(132, 45),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(138, 80),     S(289, 139),    S(250, 125),    S(187, 42),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, 21),      S(234, 63),     S(166, 78),     S(142, 73),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-71, -32),    S(143, 9),      S(119, 43),     S(38, 92),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -58),    S(157, -32),    S(79, 21),      S(41, 61),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(7, -65),      S(81, -29),     S(3, 13),       S(-45, 42),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-103, -109),  S(-14, -46),    S(-104, -25),   S(-99, -38),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-5, 42), S(14, 68), S(18, 60), S(10, 29), S(10, 31), S(18, 61), S(12, 67), }},
  {{ S(5, 54), S(34, 46), S(31, 28), S(19, -11), S(19, -5), S(30, 31), S(32, 52), }},
  {{ S(7, 48), S(18, 87), S(18, 35), S(14, 1), S(13, 1), S(17, 35), S(17, 87), }},
  {{ S(5, 71), S(24, 25), S(14, 27), S(10, 18), S(11, 20), S(15, 13), S(20, 29), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-3, 135), S(19, 43), S(17, 63), S(10, 88), S(11, 35),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 87), S(18, 75), S(16, 62), S(14, 37), S(15, 36), S(15, 66), S(18, 77), }},
  {{ S(6, 70), S(14, 37), S(21, 36), S(16, -0), S(17, 4), S(20, 33), S(14, 37), }},
  {{ S(12, 67), S(18, 53), S(18, 68), S(14, 46), S(13, 39), S(19, 59), S(17, 54), }},
  {{ S(12, 59), S(19, 72), S(21, 57), S(14, 44), S(12, 48), S(20, 58), S(21, 71), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        -1044, 240, -1, 62
);

inline VParam WINNABLE_PAWNS = V(-17);
inline VParam WINNABLE_SYM = V(140);
inline VParam WINNABLE_ASYM = V(127);
inline VParam WINNABLE_PAWN_ENDGAME = V(239);
inline VParam WINNABLE_BIAS = V(-662);

// Epoch duration: 11.598s
// clang-format on
}  // namespace Clockwork
