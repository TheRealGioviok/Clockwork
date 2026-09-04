#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(209, 518);
inline const PParam KNIGHT_MAT = S(785, 1595);
inline const PParam BISHOP_MAT = S(845, 1675);
inline const PParam ROOK_MAT   = S(1012, 2667);
inline const PParam QUEEN_MAT  = S(2526, 4050);

inline const PParam TEMPO_VAL  = S(69, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 4);
inline const PParam BISHOP_PAIR_VAL   = S(60, 233);
inline const PParam ROOK_OPEN_VAL     = S(112, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 27);
inline const PParam MINOR_BEHIND_PAWN = S(13, 39);
inline const PParam RESTRICTED_SQUARES = S(20, 5);

inline const PParam DOUBLED_PAWN_VAL = S(-23, -85);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -39);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 36);
inline const PParam OUTPOST_BISHOP_VAL    = S(35, 32);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 51);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 68);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -5), S(33, 30), S(60, 67), S(114, 223), S(384, 431), S(695, 828),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 28), S(39, 18), S(52, 49), S(90, 173), S(411, 105),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -247), S(-93, -207), S(-65, -80), S(-14, 38), S(91, 238), S(238, 419),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-92, 70), S(-89, 43), S(-58, 104), S(-69, 214), S(-16, 290), S(87, 170),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-24, 69), S(-30, 58), S(-54, 98), S(-18, 118), S(101, 113), S(52, 166),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(21, -30), S(19, 5), S(9, 42), S(18, 104), S(74, 251), S(339, 211),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(5, -36), S(3, 1), S(-4, -39), S(-2, -86), S(-24, -170), S(-210, -424),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(28, 219), S(6, 186), S(2, 109), S(10, 69), S(22, 65), S(62, 53), S(67, 21),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-145, -2), S(7, 13), S(-0, 103), S(35, 139), S(50, 173), S(57, 189), S(42, 171),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-29, -331), S(3, -115), S(18, -28), S(33, 5), S(49, 32), S(56, 70), S(64, 88), S(73, 113), S(84, 85),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-78, -310), S(-24, -95), S(27, -22), S(51, 20), S(70, 50), S(81, 70), S(85, 83), S(86, 98), S(89, 106), S(92, 114), S(100, 108), S(108, 100), S(106, 99), S(79, 78),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(94, -177), S(18, 3), S(39, 28), S(55, 44), S(64, 57), S(67, 65), S(70, 75), S(74, 76), S(77, 86), S(81, 92), S(82, 98), S(79, 107), S(76, 114), S(73, 108), S(88, 71),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-186, -108), S(-45, -18), S(-20, 78), S(-6, 192), S(10, 215), S(16, 253), S(22, 280), S(29, 290), S(33, 309), S(36, 323), S(41, 330), S(46, 334), S(49, 341), S(51, 345), S(51, 349), S(51, 352), S(47, 355), S(52, 346), S(53, 344), S(58, 336), S(48, 332), S(66, 302), S(35, 329), S(-4, 321), S(-41, 328), S(-52, 331), S(-125, 380), S(-79, 321),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-25, -18), S(6, -1), S(17, 16), S(28, 20), S(36, 32), S(40, 45), S(45, 51), S(47, 50), S(50, 53), S(54, 49), S(58, 43), S(60, 44), S(61, 37), S(66, 27), S(72, 12), S(71, 3), S(77, -17), S(84, -35), S(89, -47), S(84, -64), S(49, -106),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(51, -35), S(47, -35), S(51, -25), S(54, -6), S(52, 8), S(53, 11), S(51, 20), S(50, 27), S(47, 35), S(47, 41), S(45, 48), S(47, 50), S(48, 56), S(51, 57), S(58, 56), S(62, 53), S(60, 58), S(26, 68),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(63, -10), S(60, 7), S(61, 16), S(64, 24), S(68, 24), S(71, 29), S(73, 34), S(75, 41), S(74, 53), S(75, 57), S(71, 68), S(72, 75), S(67, 87), S(66, 94), S(65, 98), S(59, 106), S(54, 117), S(47, 127), S(44, 128), S(32, 136),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(-7, 130), S(-12, 169), S(-3, 213), S(4, 234), S(7, 240), S(10, 256), S(11, 262), S(14, 273), S(14, 276), S(19, 269), S(18, 278), S(16, 286), S(20, 283), S(21, 281), S(25, 276), S(27, 274), S(29, 265), S(40, 251), S(46, 232), S(47, 236), S(69, 197), S(81, 176), S(106, 112),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(2, 7), S(4, 5), S(14, 3), S(-0, 23),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 171);
inline const PParam PAWN_THREAT_BISHOP = S(171, 231);
inline const PParam PAWN_THREAT_ROOK   = S(187, 166);
inline const PParam PAWN_THREAT_QUEEN  = S(164, 16);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 65), S(94, 119), S(107, 128), S(181, 106), S(160, 45), }},
  {{ S(11, 65), S(83, 115), S(105, 125), S(221, 637), S(139, 88), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(14, 76), S(44, 129), S(58, 138), S(10, 20), S(155, -69), }},
  {{ S(5, 63), S(60, 105), S(96, 99), S(24, 9), S(379, 897), }},
}};
inline const PParam KING_THREAT  = S(-28, 138);
inline const PParam REACH_THREAT = S(-14, 14);
inline const PParam REACH_THREAT_LOOSE = S(16, 29);
inline const PParam REACH_PAWN_THREAT_LOOSE = S(5, 30);
inline const PParam HANGING_PAWN  = S(40, 97);
inline const PParam HANGING_NON_PAWN  = S(84, 37);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(18, -6), S(20, 6),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(41, 46), S(93, -88),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, -1), S(41, 4),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(2, -15), S(2, -11), S(-2, -15), S(-7, -23), S(-13, -30), S(-18, -35), S(-20, -46), S(-26, -46), S(-32, -62),
};

inline const PParam ROOK_LINEUP = S(17, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(201, 263),    S(84, 357),     S(95, 299),     S(147, 309),    S(173, 219),    S(127, 264),    S(110, 292),    S(217, 223),    //
    S(35, 60),      S(44, 112),     S(19, 72),      S(27, 8),       S(21, -29),     S(-5, 2),       S(-1, 48),      S(-28, 68),     //
    S(34, 7),       S(4, 35),       S(26, 9),       S(18, -63),     S(9, -79),      S(-11, -43),    S(-49, -12),    S(-44, 20),     //
    S(-2, -60),     S(-28, -21),    S(0, -43),      S(-1, -95),     S(-23, -103),   S(-36, -59),    S(-84, -35),    S(-76, -34),    //
    S(-14, -103),   S(24, -110),    S(6, -38),      S(-4, -62),     S(-30, -67),    S(-49, -59),    S(-80, -57),    S(-84, -60),    //
    S(11, -87),     S(97, -118),    S(77, -87),     S(42, -41),     S(12, -54),     S(-14, -56),    S(-45, -47),    S(-62, -47),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-274, -518),  S(-272, 27),    S(-269, -56),   S(-13, 55),     S(-116, 65),    S(-282, 80),    S(-369, 92),    S(-360, -424),  //
    S(-20, -24),    S(-17, 22),     S(70, 26),      S(65, 82),      S(67, 74),      S(31, 42),      S(-38, 21),     S(-60, 6),      //
    S(31, -26),     S(27, 31),      S(40, 59),      S(48, 97),      S(34, 93),      S(9, 45),       S(-7, 35),      S(-45, 8),      //
    S(82, 30),      S(79, 69),      S(90, 94),      S(83, 171),     S(87, 166),     S(60, 91),      S(39, 51),      S(25, 32),      //
    S(63, 15),      S(84, 19),      S(88, 59),      S(68, 142),     S(61, 126),     S(61, 70),      S(42, 32),      S(11, 17),      //
    S(16, -45),     S(51, -43),     S(63, -17),     S(64, 42),      S(65, 33),      S(47, -15),     S(23, -29),     S(-27, -50),    //
    S(45, -42),     S(51, -37),     S(49, -53),     S(55, -10),     S(53, -5),      S(26, -50),     S(-18, -3),     S(-45, -94),    //
    S(-41, -115),   S(16, -55),     S(35, -73),     S(40, -48),     S(25, -34),     S(-12, -55),    S(-23, -43),    S(-75, -161),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-136, 19),    S(-207, 112),   S(-423, 182),   S(-294, 114),   S(-320, 152),   S(-315, 155),   S(-232, 121),   S(-129, 61),    //
    S(-38, -18),    S(-82, 106),    S(-65, 71),     S(-88, 82),     S(-92, 101),    S(-59, 57),     S(-26, 54),     S(-56, 12),     //
    S(30, 20),      S(5, 63),       S(17, 79),      S(5, 73),       S(7, 56),       S(6, 60),       S(-4, 50),      S(6, 9),        //
    S(5, 2),        S(43, 28),      S(55, 42),      S(75, 63),      S(93, 51),      S(33, 23),      S(33, 2),       S(-6, -11),     //
    S(28, -35),     S(34, 4),       S(74, 7),       S(86, 26),      S(73, 25),      S(60, 22),      S(13, 5),       S(2, -34),      //
    S(50, -24),     S(68, -28),     S(89, -7),      S(60, 22),      S(60, 2),       S(56, 11),      S(50, -5),      S(11, -21),     //
    S(19, -69),     S(113, -73),    S(70, -49),     S(53, -21),     S(39, -16),     S(48, -41),     S(46, -50),     S(30, -37),     //
    S(36, -72),     S(22, -43),     S(29, -40),     S(36, -47),     S(20, -32),     S(30, 3),       S(34, -26),     S(31, -62),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(151, 118),    S(184, 135),    S(141, 166),    S(122, 143),    S(182, 104),    S(143, 124),    S(151, 136),    S(128, 141),    //
    S(75, 153),     S(127, 161),    S(179, 127),    S(138, 110),    S(167, 107),    S(133, 126),    S(83, 158),     S(83, 153),     //
    S(43, 141),     S(166, 78),     S(193, 67),     S(162, 51),     S(159, 79),     S(102, 111),    S(98, 125),     S(48, 163),     //
    S(17, 98),      S(79, 101),     S(96, 89),      S(77, 85),      S(104, 66),     S(66, 102),     S(59, 109),     S(11, 137),     //
    S(-14, 41),     S(45, 43),      S(35, 68),      S(5, 75),       S(16, 76),      S(6, 97),       S(-7, 90),      S(-27, 100),    //
    S(1, -55),      S(68, -41),     S(56, -16),     S(35, -5),      S(46, 4),       S(25, 28),      S(22, 5),       S(-16, 23),     //
    S(-67, -64),    S(56, -117),    S(61, -80),     S(46, -34),     S(50, -28),     S(34, -9),      S(25, -25),     S(-5, -18),     //
    S(-8, -65),     S(22, -49),     S(82, -63),     S(87, -55),     S(87, -37),     S(64, -15),     S(59, -22),     S(38, -18),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(76, 161),     S(139, 149),    S(57, 287),     S(-4, 381),     S(32, 332),     S(56, 267),     S(67, 172),     S(12, 219),     //
    S(55, 187),     S(76, 243),     S(32, 327),     S(-85, 430),    S(-47, 403),    S(10, 295),     S(50, 187),     S(37, 146),     //
    S(11, 233),     S(52, 253),     S(17, 333),     S(-22, 367),    S(-7, 363),     S(39, 253),     S(69, 157),     S(53, 122),     //
    S(6, 160),      S(15, 217),     S(-25, 283),    S(-26, 322),    S(-11, 321),    S(9, 211),      S(46, 135),     S(22, 120),     //
    S(2, 114),      S(-1, 127),     S(-17, 177),    S(-38, 236),    S(-28, 256),    S(-5, 203),     S(2, 154),      S(20, 78),      //
    S(-4, -8),      S(26, -18),     S(19, 67),      S(-5, 95),      S(10, 107),     S(12, 145),     S(28, 82),      S(7, 78),       //
    S(-22, -152),   S(16, -195),    S(15, -125),    S(38, -48),     S(37, -6),      S(37, -10),     S(10, 39),      S(17, 26),      //
    S(-46, -122),   S(-7, -304),    S(20, -309),    S(22, -173),    S(28, -90),     S(25, -98),     S(24, -74),     S(-7, -24),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(142, -602),   S(442, 71),     S(240, 313),    S(-75, 359),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(325, -215),   S(300, 207),    S(119, 355),    S(-103, 407),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(171, 2),      S(194, 175),    S(54, 334),     S(-129, 400),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(17, -33),     S(104, 99),     S(-58, 292),    S(-174, 404),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-99, -74),    S(11, 20),      S(-75, 196),    S(-197, 325),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -129),   S(42, -43),     S(-51, 134),    S(-129, 250),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(38, -179),    S(46, -85),     S(-22, 42),     S(-104, 153),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, -304),   S(14, -173),    S(-72, -59),    S(-83, -28),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-66, -78);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -1), S(11, 0), S(10, 1), S(4, -2), S(2, -4),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -2), S(5, -2), S(2, -1), S(2, -1), S(2, 2),
};

inline const PParam REACH_INNER_RING = S(1, 0);
inline const PParam REACH_OUTER_RING = S(-0, 0);
inline const PParam REACH_RING_DEFENSE = S(-3, 3);
inline const PParam REACH_RING_TWICE = S(3, 1);

inline const PParam KS_FLANK_ATTACK = S(4, -3);
inline const PParam KS_FLANK_DEFENSE = S(-2, -2);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 0);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(10, -9), S(-12, 9), S(-7, -6), S(4, -12), S(9, -19), S(-1, -26), S(-0, -46), }},
  {{ S(-2, 6), S(-23, 2), S(-16, 3), S(-7, 4), S(-4, -1), S(-11, -8), S(-12, -34), }},
  {{ S(-10, 7), S(-19, -3), S(-14, 10), S(-8, 6), S(-7, 4), S(-13, 1), S(-18, -42), }},
  {{ S(-2, 21), S(-13, 13), S(-4, 16), S(1, 13), S(2, 7), S(1, 14), S(2, 9), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(1, 38), S(-13, 19), S(-15, 25), S(-11, 31), S(1, 28),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 25), S(-42, -192), S(-9, -39), S(-2, 8), S(-7, 14), S(-11, 21), S(-11, 21), }},
  {{ S(2, 16), S(-23, -225), S(-3, -40), S(-3, -2), S(-4, 7), S(-12, 16), S(-4, 16), }},
  {{ S(-6, 19), S(-1, -178), S(10, -23), S(1, 4), S(-6, 13), S(-12, 20), S(-9, 22), }},
  {{ S(-5, 13), S(14, -96), S(9, -15), S(-1, 14), S(-10, 20), S(-15, 16), S(-12, 17), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1499, 1209, -25, -21
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(105);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(87);
inline VParam WINNABLE_BIAS = V(-405);


// clang-format on
}  // namespace Clockwork
