#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(142, 205);
inline const PParam KNIGHT_MAT = S(592, 647);
inline const PParam BISHOP_MAT = S(625, 669);
inline const PParam ROOK_MAT   = S(481, 703);
inline const PParam QUEEN_MAT  = S(1134, 1129);
inline const PParam TEMPO_VAL  = S(58, 22);

inline const PParam BISHOP_PAIR_VAL   = S(55, 202);
inline const PParam ROOK_OPEN_VAL     = S(107, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 20);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-21, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(36, 67);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 47);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(44, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -17);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(23, 61);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -37);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 4), S(38, 29), S(60, 51), S(138, 147), S(399, 191), S(600, 612),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(56, 36), S(44, 29), S(55, 56), S(115, 147), S(413, 82),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-69, -128), S(-70, -103), S(-44, 7), S(7, 120), S(93, 276), S(265, 389),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -41), S(34, -1), S(19, 37), S(-0, 117), S(53, 221), S(205, 294),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -33), S(5, 10), S(5, -22), S(5, -56), S(-12, -125), S(-209, -238),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 150), S(-16, 117), S(-12, 47), S(-3, 8), S(-0, 9), S(36, 9), S(18, -6),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-306, -57), S(-37, 24), S(-24, 61), S(12, 99), S(31, 118), S(46, 120), S(24, 120),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(65, -8), S(135, 173), S(169, 264), S(198, 300), S(238, 319), S(262, 355), S(295, 354), S(325, 368), S(380, 281),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(95, -8), S(138, 176), S(192, 244), S(222, 286), S(246, 319), S(262, 347), S(271, 364), S(284, 373), S(291, 390), S(313, 375), S(318, 381), S(376, 321), S(374, 323), S(404, 281),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(323, 257), S(239, 436), S(264, 458), S(281, 470), S(293, 482), S(299, 494), S(305, 505), S(314, 506), S(320, 517), S(331, 520), S(342, 520), S(349, 527), S(356, 525), S(370, 500), S(448, 402),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(495, 394), S(647, 547), S(669, 664), S(689, 778), S(705, 822), S(713, 868), S(719, 899), S(727, 911), S(731, 934), S(734, 950), S(740, 957), S(745, 963), S(753, 960), S(756, 963), S(760, 959), S(759, 963), S(760, 958), S(768, 951), S(773, 945), S(778, 939), S(785, 916), S(808, 883), S(802, 880), S(801, 825), S(776, 834), S(786, 782), S(720, 806), S(736, 793),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(486, -208), S(109, -100), S(29, -22), S(13, 11), S(-6, 10), S(-21, 1), S(-27, 9), S(-45, 15), S(-27, -30),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -7), S(16, -15), S(13, -12), S(6, -8), S(2, 214),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 421),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 95);
inline const PParam PAWN_THREAT_BISHOP = S(195, 141);
inline const PParam PAWN_THREAT_ROOK   = S(196, 116);
inline const PParam PAWN_THREAT_QUEEN  = S(171, -11);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 106);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 70);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -24);

inline const PParam BISHOP_THREAT_KNIGHT = S(107, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(217, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(168, 113);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -36), S(-4, -9), S(-6, -19), S(-9, -29), S(-14, -37), S(-19, -44), S(-21, -55), S(-28, -56), S(-47, -44),
};

inline const PParam ROOK_LINEUP = S(13, 64);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(308, 349),    S(133, 465),    S(291, 421),    S(318, 285),    S(331, 228),    S(217, 322),    S(144, 366),    S(263, 312),    //
    S(125, 204),    S(154, 242),    S(184, 161),    S(179, 95),     S(158, 80),     S(131, 132),    S(104, 186),    S(51, 216),     //
    S(84, 174),     S(71, 176),     S(115, 100),    S(115, 79),     S(104, 77),     S(75, 109),     S(23, 162),     S(13, 188),     //
    S(58, 127),     S(47, 148),     S(82, 99),      S(81, 90),      S(57, 94),      S(41, 120),     S(-18, 160),    S(-20, 153),    //
    S(57, 99),      S(95, 106),     S(81, 136),     S(74, 122),     S(44, 121),     S(22, 127),     S(-14, 144),    S(-20, 137),    //
    S(69, 103),     S(159, 117),    S(145, 173),    S(97, 156),     S(66, 146),     S(46, 137),     S(15, 152),     S(-4, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-219, -120),  S(-152, 179),   S(-95, 34),     S(115, 167),    S(11, 189),     S(-126, 195),   S(-287, 269),   S(-297, -51),   //
    S(75, 173),     S(126, 187),    S(210, 148),    S(204, 157),    S(194, 168),    S(125, 187),    S(61, 209),     S(50, 189),     //
    S(174, 153),    S(214, 147),    S(207, 213),    S(211, 197),    S(170, 229),    S(118, 239),    S(131, 183),    S(88, 185),     //
    S(229, 182),    S(238, 204),    S(238, 223),    S(225, 252),    S(224, 266),    S(180, 247),    S(170, 223),    S(162, 198),    //
    S(215, 180),    S(250, 164),    S(221, 223),    S(214, 243),    S(193, 249),    S(188, 234),    S(185, 179),    S(146, 201),    //
    S(160, 146),    S(182, 159),    S(174, 198),    S(182, 224),    S(177, 224),    S(143, 203),    S(132, 170),    S(106, 143),    //
    S(175, 142),    S(187, 157),    S(159, 161),    S(160, 184),    S(152, 183),    S(123, 139),    S(109, 160),    S(92, 82),      //
    S(102, 108),    S(146, 174),    S(165, 136),    S(178, 137),    S(160, 156),    S(128, 125),    S(115, 155),    S(74, 72),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-13, 292),    S(-32, 317),    S(-285, 338),   S(-137, 289),   S(-166, 314),   S(-172, 299),   S(-79, 320),    S(29, 284),     //
    S(123, 204),    S(67, 288),     S(105, 242),    S(56, 248),     S(59, 260),     S(84, 257),     S(122, 257),    S(107, 223),    //
    S(198, 230),    S(205, 254),    S(209, 251),    S(181, 253),    S(157, 258),    S(155, 264),    S(179, 248),    S(162, 231),    //
    S(167, 225),    S(197, 241),    S(198, 266),    S(198, 300),    S(225, 288),    S(164, 254),    S(177, 222),    S(132, 221),    //
    S(184, 194),    S(209, 222),    S(218, 246),    S(215, 276),    S(195, 289),    S(179, 270),    S(151, 237),    S(143, 197),    //
    S(220, 199),    S(256, 206),    S(263, 239),    S(209, 262),    S(203, 242),    S(198, 251),    S(201, 232),    S(148, 223),    //
    S(185, 171),    S(284, 188),    S(242, 199),    S(210, 218),    S(189, 221),    S(195, 193),    S(193, 190),    S(184, 189),    //
    S(216, 171),    S(203, 191),    S(208, 218),    S(218, 184),    S(206, 196),    S(208, 238),    S(203, 216),    S(194, 194),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(432, 391),    S(444, 408),    S(423, 417),    S(433, 383),    S(427, 380),    S(395, 397),    S(378, 417),    S(365, 423),    //
    S(308, 472),    S(368, 485),    S(454, 443),    S(396, 451),    S(387, 453),    S(372, 451),    S(299, 488),    S(286, 488),    //
    S(271, 472),    S(378, 454),    S(430, 414),    S(409, 404),    S(367, 432),    S(320, 461),    S(321, 456),    S(258, 491),    //
    S(280, 431),    S(349, 444),    S(386, 419),    S(360, 420),    S(363, 415),    S(315, 448),    S(306, 447),    S(236, 473),    //
    S(252, 369),    S(310, 385),    S(310, 404),    S(284, 404),    S(267, 418),    S(256, 435),    S(230, 427),    S(208, 426),    //
    S(248, 301),    S(309, 333),    S(299, 353),    S(280, 355),    S(269, 364),    S(246, 383),    S(242, 363),    S(208, 367),    //
    S(146, 312),    S(274, 279),    S(286, 308),    S(276, 329),    S(263, 333),    S(256, 336),    S(241, 322),    S(210, 336),    //
    S(207, 301),    S(231, 319),    S(289, 310),    S(300, 305),    S(290, 312),    S(270, 328),    S(259, 324),    S(240, 333),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(562, 658),    S(611, 615),    S(535, 735),    S(502, 807),    S(494, 769),    S(516, 734),    S(533, 656),    S(509, 681),    //
    S(554, 719),    S(530, 801),    S(501, 862),    S(369, 950),    S(374, 929),    S(437, 873),    S(473, 766),    S(499, 716),    //
    S(521, 782),    S(567, 804),    S(495, 921),    S(449, 928),    S(429, 913),    S(474, 834),    S(513, 760),    S(522, 684),    //
    S(557, 703),    S(557, 799),    S(502, 859),    S(489, 897),    S(478, 895),    S(499, 789),    S(541, 716),    S(526, 678),    //
    S(572, 674),    S(558, 745),    S(533, 793),    S(498, 840),    S(499, 837),    S(501, 791),    S(518, 711),    S(542, 633),    //
    S(552, 605),    S(587, 662),    S(583, 716),    S(550, 719),    S(541, 720),    S(540, 732),    S(555, 661),    S(529, 637),    //
    S(531, 504),    S(568, 510),    S(576, 571),    S(588, 615),    S(576, 641),    S(567, 614),    S(530, 647),    S(540, 609),    //
    S(514, 522),    S(546, 359),    S(571, 382),    S(584, 494),    S(581, 568),    S(579, 514),    S(568, 532),    S(532, 577),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-96, -305),   S(280, 177),    S(140, 157),    S(8, 2),        S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(238, -69),    S(321, 220),    S(195, 181),    S(117, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(237, 25),     S(377, 115),    S(277, 113),    S(175, 7),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(88, -1),      S(340, 39),     S(206, 57),     S(110, 28),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -31),    S(228, 9),      S(167, 13),     S(40, 20),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-27, -23),    S(209, -5),     S(115, 7),      S(57, -12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-6, -22),     S(81, 33),      S(0, 35),       S(-63, 9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, -73),   S(-18, -27),    S(-117, -18),   S(-122, -94),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(14, -16), S(-4, 20), S(-8, 21), S(-1, 5), S(-1, 3), S(-8, 22), S(-2, 22), }},
  {{ S(6, -4), S(-22, 29), S(-18, 22), S(-9, 5), S(-8, 5), S(-17, 27), S(-21, 38), }},
  {{ S(-10, 6), S(-21, 31), S(-19, 12), S(-16, -1), S(-15, 0), S(-19, 12), S(-20, 28), }},
  {{ S(1, -16), S(-18, -16), S(-9, -21), S(-3, -26), S(-5, -23), S(-10, -19), S(-13, -18), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(2, 265), S(-19, 34), S(-17, 24), S(-9, 9), S(-10, -10),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, 2), S(-16, 12), S(-14, 11), S(-13, 9), S(-14, 4), S(-12, 1), S(-15, 8), }},
  {{ S(-5, 2), S(-13, 9), S(-20, 15), S(-17, 12), S(-16, 8), S(-19, 11), S(-12, 8), }},
  {{ S(-10, 6), S(-15, 1), S(-16, 10), S(-12, 10), S(-11, 9), S(-15, 7), S(-15, 4), }},
  {{ S(-11, 10), S(-17, 12), S(-18, 13), S(-12, 15), S(-10, 15), S(-17, 13), S(-18, 11), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1161, 544, -29, 51
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(140);
inline VParam WINNABLE_ASYM = V(127);
inline VParam WINNABLE_PAWN_ENDGAME = V(221);
inline VParam WINNABLE_BIAS = V(-671);

// Epoch duration: 6.90778s

// Epoch duration: 7.52381s
// clang-format on
}  // namespace Clockwork
