#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 200);
inline const PParam KNIGHT_MAT = S(584, 581);
inline const PParam BISHOP_MAT = S(613, 586);
inline const PParam ROOK_MAT   = S(492, 629);
inline const PParam QUEEN_MAT  = S(898, 1186);
inline const PParam TEMPO_VAL  = S(59, 19);

inline const PParam BISHOP_PAIR_VAL   = S(50, 196);
inline const PParam ROOK_OPEN_VAL     = S(107, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 25);
inline const PParam MINOR_BEHIND_PAWN = S(11, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-14, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-21, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -28);
inline const PParam OUTPOST_KNIGHT_VAL    = S(41, 56);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(30, 50);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -45);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -2), S(35, 27), S(61, 46), S(138, 138), S(373, 200), S(595, 613),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(51, 34), S(45, 25), S(62, 48), S(122, 134), S(428, 73),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-69, -125), S(-71, -96), S(-49, 14), S(8, 113), S(102, 247), S(272, 364),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(30, -40), S(27, -3), S(17, 30), S(4, 106), S(70, 205), S(240, 253),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(16, -21), S(6, 17), S(3, -15), S(4, -43), S(6, -129), S(-234, -218),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 139), S(-17, 110), S(-10, 41), S(-3, 8), S(4, 8), S(39, 6), S(30, -8),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-296, -71), S(-31, 13), S(-24, 61), S(14, 94), S(35, 115), S(48, 119), S(31, 111),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(82, -4), S(147, 164), S(179, 256), S(207, 290), S(246, 306), S(270, 336), S(301, 333), S(331, 341), S(386, 248),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(113, 2), S(152, 169), S(200, 233), S(223, 281), S(247, 311), S(261, 335), S(269, 352), S(283, 359), S(290, 372), S(315, 352), S(325, 349), S(381, 289), S(379, 298), S(429, 232),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(325, 255), S(243, 411), S(265, 439), S(282, 448), S(292, 462), S(296, 474), S(301, 485), S(308, 488), S(313, 498), S(322, 500), S(331, 501), S(336, 505), S(342, 502), S(360, 471), S(453, 362),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(479, 228), S(608, 348), S(632, 457), S(650, 575), S(664, 619), S(669, 668), S(674, 700), S(680, 713), S(682, 739), S(683, 758), S(688, 766), S(690, 777), S(695, 777), S(695, 788), S(696, 789), S(693, 794), S(691, 794), S(694, 791), S(699, 781), S(697, 782), S(694, 773), S(709, 739), S(694, 747), S(676, 705), S(658, 691), S(644, 669), S(582, 701), S(588, 656),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(506, -231), S(94, -91), S(30, -22), S(13, 12), S(-4, 8), S(-17, 6), S(-24, 12), S(-49, 21), S(-38, -22),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(9, 8), S(9, 4), S(4, -1), S(4, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -6), S(4, 2), S(3, 0), S(3, -1), S(4, -3),
};

inline const PParam KS_NO_QUEEN = S(-89, -1455);
inline const PParam KS_FLANK_ATTACK = S(2, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, 3);

inline const std::array<std::array<PParam, 5>, 2> PAWN_THREAT = {{
    {S(0, 0), S(17, 17), S(30, 30), S(40, 40), S(50, 50)},
    {S(0, 0), S(11, 11), S(20, 20), S(28, 28), S(35, 35)},
}};
inline const std::array<std::array<PParam, 5>, 2> KNIGHT_THREAT = {{
    {S(0, 0), S(17, 17), S(30, 30), S(40, 40), S(50, 50)},
    {S(0, 0), S(11, 11), S(20, 20), S(28, 28), S(35, 35)},
}};
inline const std::array<std::array<PParam, 5>, 2> BISHOP_THREAT = {{
    {S(0, 0), S(17, 17), S(30, 30), S(40, 40), S(50, 50)},
    {S(0, 0), S(11, 11), S(20, 20), S(28, 28), S(35, 35)},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
    {S(0, 0), S(17, 17), S(30, 30), S(40, 40), S(50, 50)},
    {S(0, 0), S(11, 11), S(20, 20), S(28, 28), S(35, 35)},
}};
inline const std::array<std::array<PParam, 5>, 2> QUEEN_THREAT = {{
    {S(0, 0), S(17, 17), S(30, 30), S(40, 40), S(50, 50)},
    {S(0, 0), S(11, 11), S(20, 20), S(28, 28), S(35, 35)},
}};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -31), S(-4, -3), S(-5, -11), S(-8, -20), S(-12, -28), S(-15, -34), S(-17, -45), S(-23, -45), S(-38, -41),
};

inline const PParam ROOK_LINEUP = S(13, 70);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(314, 324),    S(131, 429),    S(271, 383),    S(270, 325),    S(324, 251),    S(228, 322),    S(161, 363),    S(282, 311),    //
    S(124, 202),    S(146, 240),    S(165, 191),    S(135, 153),    S(132, 121),    S(107, 160),    S(90, 206),     S(50, 227),     //
    S(95, 165),     S(80, 182),     S(118, 139),    S(102, 117),    S(95, 100),     S(74, 120),     S(27, 162),     S(20, 183),     //
    S(60, 118),     S(49, 152),     S(87, 123),     S(74, 114),     S(50, 110),     S(41, 123),     S(-18, 157),    S(-15, 148),    //
    S(59, 88),      S(97, 91),      S(86, 130),     S(71, 128),     S(40, 123),     S(26, 123),     S(-12, 140),    S(-15, 131),    //
    S(70, 98),      S(152, 101),    S(127, 138),    S(92, 160),     S(63, 147),     S(44, 131),     S(16, 148),     S(-1, 147),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-202, -137),  S(-132, 189),   S(-168, 121),   S(126, 166),    S(45, 180),     S(-103, 197),   S(-260, 256),   S(-274, -30),   //
    S(88, 156),     S(121, 173),    S(217, 135),    S(214, 140),    S(205, 158),    S(148, 175),    S(93, 193),     S(74, 173),     //
    S(156, 148),    S(176, 140),    S(188, 198),    S(198, 197),    S(163, 229),    S(124, 228),    S(138, 166),    S(103, 160),    //
    S(227, 171),    S(234, 185),    S(229, 206),    S(219, 238),    S(226, 243),    S(189, 231),    S(185, 200),    S(178, 176),    //
    S(210, 170),    S(247, 148),    S(216, 205),    S(217, 221),    S(191, 228),    S(195, 218),    S(199, 165),    S(157, 186),    //
    S(150, 145),    S(167, 160),    S(163, 198),    S(177, 214),    S(170, 215),    S(141, 198),    S(140, 166),    S(112, 135),    //
    S(174, 144),    S(183, 139),    S(148, 160),    S(157, 182),    S(154, 180),    S(129, 133),    S(117, 156),    S(107, 67),     //
    S(99, 95),      S(146, 159),    S(170, 125),    S(189, 131),    S(168, 153),    S(135, 123),    S(123, 143),    S(83, 51),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(10, 298),     S(14, 290),     S(-280, 352),   S(-129, 293),   S(-131, 304),   S(-146, 297),   S(-41, 296),    S(35, 284),     //
    S(124, 215),    S(85, 284),     S(113, 235),    S(49, 261),     S(72, 255),     S(93, 260),     S(139, 251),    S(111, 232),    //
    S(186, 234),    S(184, 248),    S(186, 258),    S(167, 256),    S(145, 259),    S(159, 261),    S(174, 250),    S(169, 231),    //
    S(171, 216),    S(199, 229),    S(198, 253),    S(195, 295),    S(232, 278),    S(174, 254),    S(190, 215),    S(153, 219),    //
    S(202, 175),    S(207, 211),    S(220, 240),    S(223, 265),    S(202, 280),    S(202, 255),    S(173, 226),    S(168, 195),    //
    S(222, 183),    S(248, 203),    S(255, 233),    S(211, 256),    S(202, 238),    S(211, 244),    S(226, 222),    S(172, 208),    //
    S(185, 155),    S(280, 169),    S(237, 195),    S(217, 208),    S(195, 217),    S(206, 187),    S(208, 179),    S(203, 172),    //
    S(211, 162),    S(190, 198),    S(206, 213),    S(231, 184),    S(213, 198),    S(211, 234),    S(211, 209),    S(204, 180),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(424, 399),    S(468, 395),    S(419, 417),    S(426, 383),    S(468, 369),    S(426, 385),    S(434, 399),    S(408, 416),    //
    S(308, 471),    S(391, 460),    S(452, 428),    S(394, 439),    S(434, 427),    S(403, 433),    S(337, 470),    S(320, 479),    //
    S(265, 467),    S(378, 443),    S(419, 404),    S(396, 397),    S(392, 416),    S(349, 439),    S(353, 443),    S(290, 481),    //
    S(244, 439),    S(324, 434),    S(357, 405),    S(334, 411),    S(359, 406),    S(320, 436),    S(316, 440),    S(249, 467),    //
    S(224, 373),    S(295, 382),    S(287, 393),    S(268, 392),    S(272, 405),    S(263, 424),    S(234, 425),    S(216, 425),    //
    S(232, 314),    S(303, 331),    S(298, 345),    S(281, 345),    S(289, 350),    S(258, 380),    S(260, 363),    S(222, 372),    //
    S(136, 324),    S(277, 278),    S(284, 306),    S(277, 328),    S(281, 328),    S(267, 338),    S(256, 323),    S(227, 338),    //
    S(198, 306),    S(220, 327),    S(286, 312),    S(298, 308),    S(297, 316),    S(277, 333),    S(272, 326),    S(253, 335),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(518, 575),    S(605, 525),    S(506, 665),    S(437, 775),    S(487, 703),    S(495, 655),    S(540, 532),    S(468, 602),    //
    S(508, 591),    S(502, 678),    S(441, 769),    S(306, 870),    S(349, 848),    S(405, 765),    S(477, 604),    S(473, 595),    //
    S(450, 664),    S(464, 709),    S(405, 811),    S(360, 839),    S(374, 831),    S(444, 709),    S(481, 620),    S(505, 531),    //
    S(478, 562),    S(458, 657),    S(402, 737),    S(389, 793),    S(404, 787),    S(440, 676),    S(496, 572),    S(488, 531),    //
    S(491, 524),    S(468, 583),    S(442, 647),    S(420, 698),    S(432, 709),    S(458, 633),    S(484, 554),    S(517, 471),    //
    S(486, 452),    S(516, 473),    S(510, 538),    S(491, 541),    S(492, 549),    S(503, 564),    S(525, 498),    S(509, 478),    //
    S(474, 311),    S(507, 315),    S(514, 382),    S(539, 405),    S(530, 446),    S(534, 421),    S(506, 457),    S(519, 446),    //
    S(462, 320),    S(487, 192),    S(525, 174),    S(545, 265),    S(544, 342),    S(546, 303),    S(538, 333),    S(509, 375),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(27, -321),    S(367, 166),    S(275, 127),    S(160, 11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(295, -49),    S(385, 172),    S(268, 159),    S(215, 35),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(211, 39),     S(292, 141),    S(226, 137),    S(183, 50),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(24, 6),       S(183, 77),     S(93, 106),     S(65, 105),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-119, -13),   S(24, 45),      S(-15, 85),     S(-91, 133),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-75, -36),    S(32, 15),      S(-27, 65),     S(-68, 103),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-3, -78),     S(38, -15),     S(-13, 28),     S(-75, 70),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-80, -139),   S(-9, -82),     S(-80, -39),    S(-81, -48),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(28, -9), S(4, 15), S(9, 2), S(19, -6), S(18, -6), S(8, 3), S(6, 13), }},
  {{ S(11, 7), S(-12, 10), S(-9, 16), S(-1, 23), S(-0, 21), S(-9, 19), S(-12, 12), }},
  {{ S(10, 9), S(0, 2), S(0, 22), S(3, 27), S(4, 26), S(-1, 25), S(1, 2), }},
  {{ S(16, 18), S(1, 20), S(4, 38), S(7, 44), S(5, 47), S(2, 41), S(2, 25), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-8, 6), S(-18, -17), S(-20, -8), S(-16, 4), S(-3, -26),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-6, -12), S(-16, -12), S(-18, -9), S(-14, -14), S(-15, -14), S(-18, -7), S(-17, -10), }},
  {{ S(-1, -21), S(-9, -15), S(-19, -11), S(-14, -16), S(-15, -15), S(-17, -13), S(-9, -15), }},
  {{ S(-10, -12), S(-15, -3), S(-18, -5), S(-15, -9), S(-14, -12), S(-18, -7), S(-15, -4), }},
  {{ S(-9, -20), S(-18, -7), S(-20, -11), S(-16, -11), S(-15, -12), S(-20, -11), S(-21, -1), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1453, 882, -15, 20
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(135);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(208);
inline VParam WINNABLE_BIAS = V(-644);

// Epoch duration: 9.72937s
// clang-format on
}  // namespace Clockwork
