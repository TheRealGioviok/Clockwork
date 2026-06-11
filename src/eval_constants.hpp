#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(172, 507);
inline const PParam KNIGHT_MAT = S(247, 970);
inline const PParam BISHOP_MAT = S(552, 1625);
inline const PParam ROOK_MAT   = S(602, 2549);
inline const PParam QUEEN_MAT  = S(2009, 2835);

inline const PParam TEMPO_VAL  = S(69, 50);

inline const PParam BISHOP_XRAY_PAWNS   = S(-12, -3);
inline const PParam BISHOP_PAIR_VAL   = S(61, 231);
inline const PParam ROOK_OPEN_VAL     = S(111, -2);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 14);
inline const PParam MINOR_BEHIND_PAWN = S(14, 40);
inline const PParam RESTRICTED_SQUARES = S(20, 5);

inline const PParam DOUBLED_PAWN_VAL = S(-22, -83);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -36);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 41);
inline const PParam OUTPOST_BISHOP_VAL    = S(35, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 46);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 59);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -1), S(28, 38), S(59, 61), S(127, 193), S(435, 274), S(574, 554),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 35), S(36, 24), S(53, 52), S(97, 172), S(422, 82),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-90, -266), S(-91, -230), S(-69, -89), S(-29, 49), S(65, 247), S(225, 411),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -39), S(23, 1), S(10, 44), S(8, 125), S(78, 248), S(119, 449),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(11, -39), S(1, 9), S(-4, -27), S(-2, -63), S(-6, -170), S(-167, -331),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(12, 232), S(-1, 185), S(-4, 108), S(7, 66), S(17, 69), S(58, 65), S(51, 42),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-135, -58), S(21, 7), S(8, 110), S(33, 160), S(46, 196), S(58, 203), S(39, 190),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(359, 114), S(180, 105), S(202, 207), S(221, 248), S(243, 281), S(254, 321), S(267, 335), S(282, 349), S(301, 303),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(199, -262), S(87, -89), S(126, -34), S(145, 2), S(163, 31), S(170, 49), S(172, 63), S(171, 75), S(170, 83), S(174, 85), S(177, 83), S(193, 63), S(191, 65), S(170, 36),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(355, -152), S(137, -1), S(152, 26), S(168, 41), S(176, 55), S(178, 65), S(181, 77), S(185, 79), S(187, 90), S(191, 95), S(194, 99), S(193, 105), S(193, 109), S(194, 98), S(218, 51),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(203, 363), S(25, 240), S(58, 314), S(82, 397), S(98, 417), S(104, 452), S(110, 473), S(116, 481), S(119, 500), S(122, 514), S(126, 521), S(129, 529), S(132, 537), S(133, 543), S(133, 546), S(132, 551), S(129, 551), S(134, 542), S(135, 540), S(141, 529), S(140, 507), S(149, 482), S(120, 506), S(79, 488), S(56, 481), S(29, 493), S(-6, 493), S(27, 418),
};

inline const std::array<PParam, 14> KNIGHT_TRAP_FACTOR = {
    S(215, 211), S(223, 225), S(229, 229), S(236, 243), S(241, 254), S(246, 268), S(251, 276), S(254, 277), S(258, 278), S(259, 275), S(263, 264), S(266, 255), S(271, 235), S(276, 223),
};
inline const std::array<PParam, 14> BISHOP_TRAP_FACTOR = {
    S(149, -12), S(150, -23), S(159, -4), S(161, 4), S(162, 16), S(169, 28), S(172, 27), S(170, 36), S(173, 40), S(174, 47), S(175, 51), S(176, 57), S(177, 65), S(179, 75),
};
inline const std::array<PParam, 9> ROOK_TRAP_FACTOR = {
    S(143, 29), S(149, 40), S(155, 37), S(159, 48), S(157, 55), S(159, 56), S(164, 53), S(166, 59), S(169, 83),
};
inline const std::array<PParam, 19> QUEEN_TRAP_FACTOR = {
    S(243, 660), S(203, 738), S(212, 749), S(209, 795), S(213, 813), S(217, 830), S(217, 854), S(223, 852), S(229, 850), S(230, 872), S(233, 876), S(234, 892), S(235, 907), S(234, 920), S(241, 918), S(238, 937), S(239, 943), S(247, 935), S(247, 946),
};

inline const PParam KNIGHT_REACH_LIN = S(5, -17);
inline const PParam BISHOP_REACH_LIN = S(3, -0);
inline const PParam ROOK_REACH_LIN   = S(2, 1);
inline const PParam QUEEN_REACH_LIN  = S(7, -11);

inline const PParam PAWN_THREAT_KNIGHT = S(193, 162);
inline const PParam PAWN_THREAT_BISHOP = S(169, 208);
inline const PParam PAWN_THREAT_ROOK   = S(199, 130);
inline const PParam PAWN_THREAT_QUEEN  = S(156, 21);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(5, 57), S(89, 89), S(103, 123), S(201, 118), S(153, 14), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(5, 54), S(52, 89), S(68, 91), S(17, -4), S(143, -64), S(0, 0),
};
inline const PParam KING_THREAT  = S(-20, 157);
inline const PParam HANGING_PAWN  = S(30, 88);
inline const PParam HANGING_NON_PAWN  = S(69, 22);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(19, -16), S(14, 16),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(37, 51), S(105, -96),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(35, 11), S(45, -4),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -15), S(4, -12), S(-0, -17), S(-5, -24), S(-11, -32), S(-15, -39), S(-17, -50), S(-23, -52), S(-27, -66),
};

inline const PParam ROOK_LINEUP = S(19, 82);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(195, 283),    S(44, 401),     S(61, 374),     S(145, 270),    S(192, 172),    S(122, 232),    S(90, 278),     S(234, 211),    //
    S(61, 65),      S(69, 105),     S(42, 49),      S(59, -27),     S(51, -62),     S(24, -23),     S(24, 31),      S(0, 59),       //
    S(57, -9),      S(28, -1),      S(58, -48),     S(44, -71),     S(33, -88),     S(15, -74),     S(-23, -34),    S(-19, 2),      //
    S(21, -74),     S(-6, -41),     S(28, -66),     S(20, -78),     S(-3, -87),     S(-14, -75),    S(-62, -51),    S(-52, -51),    //
    S(17, -113),    S(50, -110),    S(39, -55),     S(23, -59),     S(-5, -67),     S(-20, -78),    S(-52, -71),    S(-54, -75),    //
    S(38, -110),    S(116, -99),    S(102, -48),    S(63, -24),     S(32, -43),     S(10, -67),     S(-19, -57),    S(-36, -58),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-139, -417),  S(-132, 136),   S(-147, 14),    S(141, 126),    S(15, 149),     S(-142, 163),   S(-250, 203),   S(-230, -310),  //
    S(112, 79),     S(116, 124),    S(211, 109),    S(181, 168),    S(188, 158),    S(167, 111),    S(86, 118),     S(83, 109),     //
    S(167, 60),     S(154, 117),    S(184, 132),    S(178, 177),    S(167, 171),    S(136, 134),    S(124, 118),    S(75, 107),     //
    S(212, 120),    S(204, 157),    S(215, 176),    S(197, 269),    S(201, 268),    S(179, 186),    S(162, 152),    S(152, 135),    //
    S(193, 112),    S(219, 114),    S(217, 157),    S(191, 241),    S(180, 241),    S(190, 172),    S(171, 128),    S(137, 129),    //
    S(149, 60),     S(188, 66),     S(199, 96),     S(198, 143),    S(193, 141),    S(176, 94),     S(155, 75),     S(103, 59),     //
    S(171, 70),     S(181, 82),     S(175, 71),     S(181, 101),    S(178, 99),     S(154, 50),     S(110, 92),     S(92, 0),       //
    S(86, 16),      S(136, 72),     S(156, 58),     S(168, 72),     S(149, 90),     S(114, 55),     S(106, 73),     S(59, -37),     //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-90, 13),     S(-128, 87),    S(-382, 163),   S(-215, 64),    S(-252, 119),   S(-253, 126),   S(-159, 101),   S(-82, 48),     //
    S(20, -32),     S(-22, 96),     S(10, 54),      S(-23, 63),     S(-27, 74),     S(11, 43),      S(44, 43),      S(4, 5),        //
    S(86, 7),       S(68, 62),      S(82, 71),      S(71, 60),      S(68, 40),      S(65, 49),      S(64, 43),      S(63, -1),      //
    S(65, -19),     S(108, 17),     S(115, 36),     S(127, 56),     S(152, 42),     S(95, 17),      S(103, -6),     S(48, -18),     //
    S(91, -64),     S(104, -3),     S(135, 7),      S(149, 22),     S(132, 37),     S(122, 18),     S(75, 3),       S(67, -53),     //
    S(110, -44),    S(139, -26),    S(159, -1),     S(125, 26),     S(124, 10),     S(122, 13),     S(122, -9),     S(66, -33),     //
    S(86, -85),     S(181, -37),    S(141, -14),    S(122, 3),      S(104, 7),      S(121, -38),    S(115, -39),    S(96, -63),     //
    S(101, -96),    S(74, -24),     S(77, -20),     S(100, -43),    S(82, -27),     S(88, 2),       S(95, -26),     S(91, -76),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(249, 74),     S(275, 93),     S(218, 120),    S(203, 102),    S(264, 54),     S(227, 77),     S(234, 92),     S(211, 96),     //
    S(153, 133),    S(199, 138),    S(255, 97),     S(196, 101),    S(236, 80),     S(198, 105),    S(147, 139),    S(147, 138),    //
    S(121, 121),    S(234, 72),     S(255, 52),     S(231, 31),     S(225, 55),     S(168, 94),     S(172, 104),    S(121, 145),    //
    S(98, 87),      S(155, 96),     S(179, 68),     S(149, 74),     S(177, 56),     S(138, 101),    S(130, 111),    S(77, 136),     //
    S(65, 35),      S(130, 39),     S(119, 56),     S(89, 66),      S(96, 70),      S(82, 98),      S(64, 97),      S(44, 100),     //
    S(80, -44),     S(147, -21),    S(136, -3),     S(117, 6),      S(124, 16),     S(97, 43),      S(95, 29),      S(51, 38),      //
    S(-5, -35),     S(126, -77),    S(131, -42),    S(122, -10),    S(125, -12),    S(107, 6),      S(94, -8),      S(60, 3),       //
    S(60, -51),     S(82, -11),     S(150, -32),    S(162, -32),    S(159, -23),    S(134, 2),      S(131, -8),     S(108, -5),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(97, 186),     S(172, 154),    S(86, 287),     S(27, 386),     S(73, 325),     S(97, 249),     S(89, 178),     S(27, 232),     //
    S(87, 200),     S(107, 241),    S(68, 317),     S(-68, 448),    S(-20, 412),    S(31, 309),     S(80, 174),     S(52, 173),     //
    S(45, 256),     S(81, 287),     S(40, 378),     S(-5, 418),     S(15, 398),     S(73, 267),     S(105, 167),    S(87, 121),     //
    S(43, 188),     S(45, 271),     S(11, 326),     S(-5, 398),     S(7, 401),      S(44, 258),     S(82, 165),     S(53, 139),     //
    S(38, 179),     S(36, 199),     S(21, 257),     S(-5, 324),     S(7, 340),      S(32, 262),     S(37, 194),     S(55, 104),     //
    S(35, 75),      S(64, 93),      S(61, 163),     S(39, 184),     S(47, 192),     S(54, 209),     S(66, 147),     S(42, 122),     //
    S(9, -52),      S(47, -54),     S(51, 13),      S(75, 50),      S(72, 86),      S(67, 76),      S(44, 104),     S(48, 82),      //
    S(-1, -37),     S(16, -181),    S(45, -183),    S(59, -70),     S(65, 17),      S(64, -18),     S(61, -1),      S(31, 37),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(114, -597),   S(500, -12),    S(307, 165),    S(11, 142),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(356, -192),   S(391, 123),    S(220, 169),    S(28, 129),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(200, 32),     S(241, 149),    S(132, 183),    S(-24, 155),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(28, -0),      S(108, 105),    S(-3, 153),     S(-82, 171),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-107, -11),   S(-20, 69),     S(-77, 133),    S(-161, 181),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-49, -37),    S(18, 28),      S(-64, 107),    S(-118, 152),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -86),     S(33, -12),     S(-28, 48),     S(-97, 102),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -205),   S(7, -87),      S(-74, -23),    S(-74, -44),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-85, -437);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -4), S(10, 12), S(10, 5), S(5, 1), S(4, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 4), S(2, 2), S(3, -1), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -19), S(-7, 6), S(-3, -9), S(7, -15), S(11, -26), S(5, -53), S(-7, -42), }},
  {{ S(2, 3), S(-22, 1), S(-17, 8), S(-10, 17), S(-7, 8), S(-11, -10), S(-22, -22), }},
  {{ S(-2, -1), S(-11, -11), S(-13, 18), S(-7, 18), S(-7, 10), S(-8, -17), S(-26, -44), }},
  {{ S(6, 10), S(-10, 18), S(-7, 40), S(-3, 44), S(-3, 40), S(3, 16), S(7, -12), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 26), S(-6, 2), S(-9, 10), S(-7, 28), S(1, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 11), S(-47, -147), S(-10, -44), S(-1, 5), S(-4, 4), S(-7, 10), S(-6, 9), }},
  {{ S(8, 0), S(-26, -133), S(-7, -33), S(-5, 1), S(-2, -2), S(-9, 3), S(0, 2), }},
  {{ S(-1, 10), S(-11, -81), S(6, -16), S(-1, 9), S(-4, 10), S(-11, 18), S(-6, 20), }},
  {{ S(1, -1), S(2, -64), S(-2, 27), S(-3, 25), S(-7, 8), S(-13, 11), S(-11, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1363, 845, -21, -5
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(84);
inline VParam WINNABLE_PAWN_ENDGAME = V(105);
inline VParam WINNABLE_BIAS = V(-382);

// Epoch duration: 6.60885s
// clang-format on
}  // namespace Clockwork
