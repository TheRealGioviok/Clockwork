#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(243, 395);
inline const PParam KNIGHT_MAT = S(979, 1230);
inline const PParam BISHOP_MAT = S(1013, 1272);
inline const PParam ROOK_MAT   = S(1230, 1954);
inline const PParam QUEEN_MAT  = S(2770, 2964);

inline const PParam TEMPO_VAL  = S(89, 47);

inline const PParam BISHOP_XRAY_PAWNS   = S(-16, -2);
inline const PParam BISHOP_PAIR_VAL   = S(92, 179);
inline const PParam ROOK_OPEN_VAL     = S(127, -16);
inline const PParam ROOK_SEMIOPEN_VAL = S(56, 2);
inline const PParam MINOR_BEHIND_PAWN = S(20, 35);
inline const PParam RESTRICTED_SQUARES = S(21, 5);
inline const PParam SPACE_VAL = S(123, -144);

inline const PParam DOUBLED_PAWN_VAL = S(-27, -64);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -31);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -32);
inline const PParam OUTPOST_KNIGHT_VAL    = S(59, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(52, 22);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(46, 42);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(47, 5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 53);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -44);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(25, -9), S(43, 18), S(67, 53), S(134, 176), S(472, 304), S(560, 750),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(66, 19), S(51, 14), S(53, 53), S(100, 151), S(403, 119),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-114, -217), S(-105, -186), S(-66, -70), S(-11, 38), S(101, 190), S(272, 344),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-122, 57), S(-98, 31), S(-82, 103), S(-122, 216), S(-62, 315), S(37, 245),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-39, 67), S(-31, 47), S(-51, 87), S(-27, 113), S(93, 121), S(41, 205),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -35), S(29, -7), S(16, 30), S(24, 79), S(68, 236), S(359, 236),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(10, -23), S(-2, 22), S(-11, -11), S(-4, -57), S(-26, -150), S(-213, -418),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(35, 196), S(16, 154), S(6, 91), S(13, 58), S(28, 52), S(62, 44), S(67, 25),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-168, -38), S(8, -8), S(11, 76), S(39, 115), S(52, 153), S(65, 162), S(41, 158),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-105, -302), S(-25, -108), S(9, -1), S(38, 42), S(66, 73), S(84, 104), S(106, 109), S(123, 112), S(143, 77),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-79, -246), S(-5, -61), S(63, -5), S(85, 49), S(107, 85), S(118, 114), S(124, 130), S(126, 148), S(126, 160), S(129, 167), S(141, 160), S(146, 149), S(158, 156), S(123, 125),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(119, -100), S(39, 61), S(68, 88), S(87, 100), S(99, 115), S(103, 128), S(108, 141), S(113, 147), S(117, 158), S(122, 165), S(126, 170), S(124, 179), S(128, 182), S(136, 170), S(146, 144),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-123, -79), S(23, 63), S(71, 149), S(105, 236), S(125, 281), S(136, 323), S(143, 355), S(150, 377), S(154, 396), S(157, 414), S(161, 426), S(167, 431), S(171, 438), S(172, 441), S(173, 445), S(172, 447), S(174, 448), S(169, 449), S(179, 433), S(184, 419), S(183, 412), S(195, 379), S(170, 402), S(129, 402), S(76, 407), S(39, 427), S(37, 424), S(51, 380),
};

inline const PParam PAWN_THREAT_KNIGHT = S(226, 107);
inline const PParam PAWN_THREAT_BISHOP = S(201, 164);
inline const PParam PAWN_THREAT_ROOK   = S(194, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(183, -5);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(14, 48), S(108, 80), S(119, 94), S(214, 50), S(200, -41), }},
  {{ S(12, 47), S(96, 79), S(116, 87), S(273, 479), S(133, -90), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(16, 53), S(60, 87), S(79, 87), S(9, 30), S(173, -73), }},
  {{ S(12, 37), S(85, 53), S(117, 51), S(11, 26), S(402, 673), }},
}};
inline const PParam KING_THREAT  = S(-12, 139);
inline const PParam HANGING_PAWN  = S(42, 76);
inline const PParam HANGING_NON_PAWN  = S(76, 25);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(28, -23), S(46, -16),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(56, 23), S(116, -82),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(46, -1), S(104, -65),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -18), S(7, -16), S(1, -21), S(-6, -26), S(-13, -29), S(-20, -33), S(-24, -37), S(-27, -44), S(-35, -59),
};

inline const PParam ROOK_LINEUP = S(21, 72);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(231, 251),    S(108, 358),    S(124, 329),    S(199, 225),    S(213, 179),    S(177, 181),    S(164, 227),    S(253, 181),    //
    S(69, 45),      S(62, 97),      S(45, 56),      S(39, 11),      S(21, -29),     S(6, -8),       S(7, 26),       S(-8, 49),      //
    S(52, -11),     S(14, -2),      S(33, -27),     S(3, -40),      S(-13, -53),    S(-19, -44),    S(-41, -26),    S(-34, -0),     //
    S(-4, -60),     S(-35, -30),    S(-4, -42),     S(-24, -44),    S(-46, -56),    S(-48, -50),    S(-97, -31),    S(-86, -33),    //
    S(-15, -84),    S(27, -89),     S(4, -23),      S(-13, -24),    S(-42, -29),    S(-62, -41),    S(-94, -41),    S(-103, -42),   //
    S(18, -91),     S(107, -89),    S(111, -45),    S(44, -5),      S(8, -22),      S(-20, -43),    S(-62, -32),    S(-77, -30),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-326, -333),  S(-276, 111),   S(-305, 177),   S(-11, 48),     S(-77, 85),     S(-241, 88),    S(-347, 144),   S(-409, -236),  //
    S(16, 4),       S(23, 27),      S(107, 14),     S(117, 49),     S(108, 50),     S(53, 27),      S(-7, 35),      S(-54, 33),     //
    S(37, 3),       S(38, 45),      S(71, 56),      S(101, 66),     S(61, 75),      S(34, 51),      S(-7, 31),      S(-36, 19),     //
    S(103, 33),     S(101, 46),     S(112, 62),     S(121, 95),     S(120, 92),     S(88, 54),      S(59, 31),      S(54, 22),      //
    S(104, 13),     S(113, 11),     S(119, 39),     S(103, 72),     S(98, 68),      S(87, 47),      S(71, 10),      S(39, 18),      //
    S(25, -21),     S(54, -14),     S(68, 11),      S(78, 43),      S(72, 39),      S(40, 7),       S(25, -24),     S(-24, -29),    //
    S(38, -23),     S(32, 26),      S(37, -14),     S(45, 7),       S(36, 7),       S(1, -32),      S(-31, -2),     S(-62, -62),    //
    S(-74, -50),    S(6, -5),       S(27, -27),     S(44, -18),     S(18, 8),       S(-14, -37),    S(-24, -17),    S(-101, -95),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-99, 14),     S(-201, 126),   S(-381, 189),   S(-221, 106),   S(-289, 178),   S(-234, 148),   S(-177, 130),   S(-110, 81),    //
    S(-29, 20),     S(-34, 95),     S(-36, 85),     S(-51, 88),     S(-49, 95),     S(-20, 60),     S(-6, 55),      S(-46, 49),     //
    S(41, 38),      S(29, 70),      S(53, 77),      S(49, 69),      S(47, 45),      S(32, 71),      S(23, 47),      S(14, 25),      //
    S(17, 23),      S(64, 36),      S(76, 55),      S(99, 68),      S(121, 62),     S(61, 35),      S(54, 19),      S(3, 22),       //
    S(47, -11),     S(58, 28),      S(93, 29),      S(108, 44),     S(98, 43),      S(77, 45),      S(25, 38),      S(14, 3),       //
    S(70, -15),     S(94, -0),      S(114, 17),     S(83, 40),      S(75, 38),      S(72, 24),      S(75, 8),       S(24, -2),      //
    S(53, -68),     S(137, -50),    S(83, -7),      S(58, 18),      S(37, 18),      S(52, -22),     S(59, -40),     S(50, -30),     //
    S(48, -41),     S(22, 4),       S(28, 21),      S(39, -7),      S(19, 17),      S(42, 31),      S(59, -10),     S(52, -49),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(190, 138),    S(237, 147),    S(187, 186),    S(163, 150),    S(189, 142),    S(183, 139),    S(180, 154),    S(159, 167),    //
    S(153, 147),    S(182, 176),    S(197, 149),    S(182, 132),    S(215, 113),    S(170, 146),    S(111, 185),    S(110, 180),    //
    S(110, 150),    S(232, 105),    S(228, 92),     S(193, 88),     S(197, 99),     S(153, 129),    S(143, 149),    S(83, 191),     //
    S(55, 139),     S(123, 145),    S(144, 116),    S(117, 119),    S(133, 118),    S(103, 146),    S(87, 169),     S(49, 178),     //
    S(38, 75),      S(92, 91),      S(61, 126),     S(38, 130),     S(45, 129),     S(38, 151),     S(21, 156),     S(1, 153),      //
    S(38, 14),      S(118, 20),     S(89, 61),      S(54, 82),      S(70, 80),      S(36, 114),     S(48, 92),      S(4, 101),      //
    S(-46, 14),     S(85, -23),     S(83, 16),      S(71, 41),      S(67, 52),      S(53, 60),      S(35, 53),      S(14, 46),      //
    S(23, -21),     S(43, 14),      S(112, -7),     S(120, -6),     S(115, 8),      S(95, 28),      S(91, 14),      S(67, 25),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(205, 151),    S(198, 200),    S(129, 300),    S(83, 360),     S(102, 348),    S(122, 282),    S(133, 211),    S(91, 227),     //
    S(132, 214),    S(139, 272),    S(112, 322),    S(-7, 434),     S(21, 425),     S(91, 286),     S(107, 212),    S(93, 198),     //
    S(102, 231),    S(138, 271),    S(93, 347),     S(75, 353),     S(101, 323),    S(129, 260),    S(144, 181),    S(125, 138),    //
    S(99, 170),     S(90, 255),     S(64, 299),     S(64, 345),     S(74, 352),     S(95, 241),     S(118, 179),    S(96, 146),     //
    S(71, 175),     S(67, 199),     S(70, 234),     S(46, 287),     S(55, 315),     S(71, 264),     S(76, 187),     S(91, 129),     //
    S(65, 98),      S(95, 94),      S(94, 166),     S(73, 174),     S(72, 211),     S(79, 217),     S(93, 169),     S(78, 134),     //
    S(28, -26),     S(52, -20),     S(74, 15),      S(100, 49),     S(97, 87),      S(95, 67),      S(68, 107),     S(85, 74),      //
    S(-14, 10),     S(21, -148),    S(60, -165),    S(69, -37),     S(92, -3),      S(83, -9),      S(87, -19),     S(49, 44),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(145, -388),   S(484, 106),    S(396, 133),    S(111, 137),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(345, -136),   S(359, 165),    S(220, 182),    S(64, 130),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(222, 26),     S(236, 163),    S(81, 192),     S(-90, 161),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, 21),      S(145, 90),     S(-21, 153),    S(-150, 176),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-108, 13),    S(-20, 70),     S(-104, 134),   S(-208, 172),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-58, -12),    S(10, 33),      S(-83, 107),    S(-152, 146),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(30, -77),     S(39, -11),     S(-44, 50),     S(-136, 109),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -173),   S(14, -86),     S(-87, -11),    S(-103, -22),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-95, -430);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -4), S(11, 16), S(11, 6), S(5, 0), S(3, -11),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(6, 3), S(3, 1), S(3, 0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -19), S(-9, 6), S(-5, -10), S(7, -17), S(14, -33), S(9, -75), S(-4, -72), }},
  {{ S(2, 6), S(-24, 3), S(-19, 13), S(-10, 20), S(-7, 9), S(-9, -25), S(-24, -40), }},
  {{ S(-4, 1), S(-12, -8), S(-14, 20), S(-8, 22), S(-6, 14), S(-6, -28), S(-22, -68), }},
  {{ S(3, 20), S(-15, 28), S(-10, 57), S(-3, 64), S(-1, 53), S(5, 30), S(6, -13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(8, 29), S(-9, 3), S(-11, 14), S(-8, 33), S(0, 66),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, 17), S(-53, -148), S(-10, -65), S(0, -1), S(-4, 7), S(-7, 13), S(-7, 9), }},
  {{ S(9, 2), S(-33, -148), S(-8, -48), S(-3, -6), S(-3, -2), S(-13, 7), S(-1, 6), }},
  {{ S(-2, 16), S(-9, -100), S(10, -32), S(1, 10), S(-6, 18), S(-12, 23), S(-8, 25), }},
  {{ S(-0, -5), S(3, -117), S(-1, 43), S(-2, 31), S(-8, 8), S(-14, 5), S(-9, 11), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1281, 718, -22, -2
);

inline VParam WINNABLE_PAWNS = V(-18);
inline VParam WINNABLE_SYM = V(98);
inline VParam WINNABLE_ASYM = V(82);
inline VParam WINNABLE_PAWN_ENDGAME = V(50);
inline VParam WINNABLE_BIAS = V(-326);

// clang-format on
}  // namespace Clockwork
