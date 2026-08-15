#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(204, 515);
inline const PParam KNIGHT_MAT = S(825, 1610);
inline const PParam BISHOP_MAT = S(877, 1696);
inline const PParam ROOK_MAT   = S(1050, 2693);
inline const PParam QUEEN_MAT  = S(2435, 4162);

inline const PParam TEMPO_VAL  = S(70, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(62, 243);
inline const PParam ROOK_OPEN_VAL     = S(110, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 11);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const std::array<PParam, 4> DOUBLED_PAWN_VAL = {
    S(-20, -159), S(-22, -104), S(-19, -73), S(-33, -48),
};
inline const std::array<PParam, 4> ISOLATED_PAWN_VAL = {
    S(-5, -14), S(-10, -42), S(-12, -41), S(-22, -59),
};

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -43);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 50);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 0), S(33, 33), S(59, 64), S(123, 213), S(398, 401), S(684, 830),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 32), S(39, 24), S(53, 55), S(92, 182), S(392, 123),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-96, -265), S(-96, -223), S(-69, -89), S(-23, 38), S(89, 200), S(232, 411),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-83, 55), S(-92, 33), S(-59, 103), S(-90, 229), S(-56, 343), S(52, 224),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-19, 68), S(-32, 60), S(-63, 108), S(-35, 137), S(72, 161), S(35, 196),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -40), S(24, 0), S(16, 35), S(21, 104), S(70, 277), S(335, 222),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -34), S(4, 9), S(-2, -26), S(0, -68), S(-14, -177), S(-171, -460),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 237), S(12, 183), S(7, 106), S(14, 65), S(19, 69), S(56, 61), S(61, 30),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-133, -49), S(14, -2), S(2, 101), S(28, 151), S(43, 184), S(52, 192), S(37, 171),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-95, -398), S(-26, -144), S(5, -27), S(29, 22), S(56, 55), S(72, 92), S(89, 100), S(108, 109), S(128, 62),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-73, -354), S(-18, -129), S(34, -39), S(59, 16), S(79, 58), S(91, 90), S(96, 112), S(99, 133), S(103, 145), S(110, 151), S(119, 145), S(133, 128), S(132, 134), S(116, 101),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -214), S(23, -10), S(44, 24), S(60, 42), S(71, 61), S(75, 75), S(80, 91), S(86, 97), S(90, 109), S(95, 117), S(100, 124), S(100, 133), S(103, 137), S(109, 125), S(127, 85),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-195, -201), S(-38, -89), S(-13, 51), S(5, 194), S(23, 237), S(30, 290), S(37, 329), S(44, 347), S(49, 370), S(52, 387), S(58, 396), S(62, 402), S(66, 408), S(68, 414), S(68, 418), S(68, 420), S(64, 422), S(67, 414), S(68, 410), S(72, 403), S(62, 394), S(74, 366), S(40, 395), S(-6, 386), S(-40, 385), S(-74, 407), S(-135, 437), S(-98, 369),
};

inline const PParam PAWN_THREAT_KNIGHT = S(198, 155);
inline const PParam PAWN_THREAT_BISHOP = S(172, 222);
inline const PParam PAWN_THREAT_ROOK   = S(191, 155);
inline const PParam PAWN_THREAT_QUEEN  = S(162, 18);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(8, 57), S(99, 96), S(104, 127), S(179, 94), S(165, 12), }},
  {{ S(6, 58), S(88, 95), S(104, 125), S(221, 618), S(148, 55), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 65), S(45, 108), S(59, 112), S(12, 13), S(152, -78), }},
  {{ S(4, 50), S(62, 82), S(96, 72), S(22, 15), S(370, 898), }},
}};
inline const PParam KING_THREAT  = S(-11, 158);
inline const PParam HANGING_PAWN  = S(32, 93);
inline const PParam HANGING_NON_PAWN  = S(72, 32);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(22, 9),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(43, 46), S(113, -114),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 13), S(48, -4),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -18), S(4, -16), S(-0, -23), S(-6, -30), S(-12, -38), S(-17, -45), S(-19, -56), S(-25, -58), S(-30, -75),
};

inline const PParam ROOK_LINEUP = S(16, 82);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(187, 260),    S(65, 410),     S(71, 389),     S(159, 284),    S(197, 182),    S(145, 214),    S(127, 254),    S(223, 166),    //
    S(41, 48),      S(58, 117),     S(33, 58),      S(46, 2),       S(40, -34),     S(11, -15),     S(18, 37),      S(-22, 40),     //
    S(38, -26),     S(19, 6),       S(43, -50),     S(25, -67),     S(18, -85),     S(2, -79),      S(-30, -31),    S(-39, -17),    //
    S(-6, -84),     S(-25, -30),    S(-1, -67),     S(-11, -77),    S(-31, -85),    S(-37, -79),    S(-76, -43),    S(-78, -64),    //
    S(-14, -121),   S(25, -93),     S(-0, -50),     S(-15, -50),    S(-40, -59),    S(-56, -76),    S(-74, -56),    S(-84, -85),    //
    S(8, -120),     S(89, -84),     S(68, -46),     S(23, -10),     S(-6, -30),     S(-27, -65),    S(-44, -46),    S(-64, -71),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-263, -506),  S(-258, 50),    S(-263, -35),   S(4, 38),       S(-88, 40),     S(-267, 84),    S(-349, 102),   S(-350, -411),  //
    S(-0, -11),     S(4, 29),       S(87, 25),      S(83, 64),      S(90, 50),      S(51, 29),      S(-14, 25),     S(-41, 19),     //
    S(42, -26),     S(43, 29),      S(57, 63),      S(76, 72),      S(58, 73),      S(23, 58),      S(10, 36),      S(-34, 10),     //
    S(91, 21),      S(93, 47),      S(103, 69),     S(107, 110),    S(111, 108),    S(74, 73),      S(53, 39),      S(33, 32),      //
    S(80, 14),      S(103, 3),      S(101, 49),     S(96, 80),      S(82, 83),      S(74, 64),      S(59, 19),      S(25, 25),      //
    S(19, -42),     S(45, -25),     S(52, 19),      S(64, 52),      S(60, 50),      S(32, 14),      S(16, -18),     S(-24, -40),    //
    S(37, -24),     S(39, -13),     S(27, -20),     S(38, 9),       S(35, 7),       S(5, -44),      S(-31, 0),      S(-50, -83),    //
    S(-44, -94),    S(10, -30),     S(29, -44),     S(45, -34),     S(28, -19),     S(-9, -52),     S(-20, -28),    S(-71, -143),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-132, 22),    S(-193, 104),   S(-405, 170),   S(-274, 98),    S(-304, 138),   S(-305, 153),   S(-230, 129),   S(-130, 73),    //
    S(-27, -23),    S(-64, 89),     S(-48, 63),     S(-69, 60),     S(-67, 75),     S(-41, 50),     S(-8, 43),      S(-52, 25),     //
    S(33, 18),      S(15, 58),      S(29, 71),      S(25, 56),      S(21, 45),      S(19, 50),      S(8, 45),       S(9, 15),       //
    S(15, -8),      S(48, 20),      S(59, 37),      S(80, 55),      S(103, 42),     S(40, 21),      S(43, -3),      S(-2, -3),      //
    S(36, -44),     S(44, 1),       S(76, 14),      S(91, 28),      S(75, 39),      S(65, 25),      S(19, 5),       S(8, -37),      //
    S(56, -31),     S(80, -27),     S(95, 5),       S(63, 29),      S(59, 14),      S(56, 15),      S(57, -4),      S(15, -22),     //
    S(25, -74),     S(112, -57),    S(65, -19),     S(46, -1),      S(29, -1),      S(43, -43),     S(44, -58),     S(37, -50),     //
    S(42, -74),     S(21, -25),     S(28, -10),     S(42, -33),     S(26, -20),     S(36, 15),      S(42, -16),     S(38, -61),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(175, 109),    S(204, 129),    S(158, 159),    S(145, 130),    S(206, 84),     S(164, 112),    S(170, 130),    S(154, 127),    //
    S(86, 152),     S(145, 156),    S(188, 128),    S(144, 112),    S(181, 99),     S(149, 123),    S(100, 156),    S(88, 159),     //
    S(55, 145),     S(179, 86),     S(207, 70),     S(179, 56),     S(182, 73),     S(123, 114),    S(115, 133),    S(62, 171),     //
    S(29, 110),     S(94, 118),     S(113, 95),     S(99, 93),      S(127, 76),     S(86, 118),     S(75, 133),     S(19, 160),     //
    S(5, 44),       S(64, 53),      S(58, 75),      S(26, 86),      S(36, 91),      S(25, 116),     S(8, 112),      S(-14, 117),    //
    S(17, -35),     S(86, -12),     S(74, 15),      S(51, 29),      S(61, 35),      S(38, 58),      S(34, 43),      S(-5, 50),      //
    S(-63, -40),    S(63, -78),     S(68, -39),     S(56, -5),      S(60, -4),      S(46, 8),       S(36, -8),      S(5, -5),       //
    S(1, -63),      S(24, -32),     S(88, -42),     S(96, -42),     S(98, -37),     S(75, -15),     S(69, -22),     S(48, -16),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(91, 155),     S(147, 155),    S(59, 299),     S(1, 397),      S(37, 350),     S(73, 259),     S(73, 176),     S(27, 208),     //
    S(59, 186),     S(80, 241),     S(39, 322),     S(-82, 441),    S(-39, 410),    S(20, 290),     S(61, 175),     S(41, 148),     //
    S(21, 236),     S(61, 261),     S(30, 339),     S(-7, 375),     S(12, 364),     S(52, 260),     S(83, 155),     S(64, 120),     //
    S(18, 169),     S(29, 238),     S(-12, 307),    S(-12, 364),    S(6, 354),      S(22, 239),     S(61, 155),     S(35, 118),     //
    S(14, 143),     S(11, 169),     S(3, 220),      S(-23, 290),    S(-11, 305),    S(11, 240),     S(17, 176),     S(37, 80),      //
    S(5, 50),       S(35, 61),      S(32, 135),     S(10, 159),     S(20, 167),     S(22, 189),     S(42, 117),     S(22, 96),      //
    S(-24, -93),    S(5, -94),      S(13, -25),     S(41, 14),      S(37, 55),      S(39, 26),      S(13, 66),      S(26, 38),      //
    S(-41, -80),    S(-10, -241),   S(22, -247),    S(34, -136),    S(41, -55),     S(39, -74),     S(37, -60),     S(6, -5),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(165, -564),   S(478, 84),     S(317, 198),    S(18, 197),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(371, -188),   S(369, 189),    S(214, 205),    S(27, 160),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(201, 41),     S(236, 174),    S(119, 200),    S(-46, 181),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, 5),       S(116, 113),    S(-19, 173),    S(-116, 205),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-113, -2),    S(-20, 76),     S(-84, 147),    S(-179, 199),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -35),    S(13, 33),      S(-66, 115),    S(-123, 161),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(25, -94),     S(31, -12),     S(-32, 50),     S(-108, 108),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-22, -213),   S(5, -92),      S(-73, -28),    S(-82, -41),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -447);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 1), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -17), S(-6, 5), S(-2, -9), S(7, -16), S(12, -29), S(7, -54), S(-3, -47), }},
  {{ S(2, 4), S(-20, 2), S(-16, 10), S(-10, 17), S(-6, 7), S(-9, -14), S(-19, -23), }},
  {{ S(-4, -2), S(-13, -9), S(-14, 17), S(-9, 18), S(-8, 9), S(-7, -17), S(-23, -38), }},
  {{ S(7, 9), S(-10, 19), S(-6, 39), S(-2, 43), S(-2, 39), S(4, 19), S(10, -13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 23), S(-5, 2), S(-7, 9), S(-6, 28), S(2, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 10), S(-41, -115), S(-8, -39), S(-0, 4), S(-3, 3), S(-6, 10), S(-5, 9), }},
  {{ S(9, -2), S(-24, -123), S(-6, -30), S(-4, 0), S(-2, -3), S(-8, 4), S(1, 3), }},
  {{ S(0, 11), S(-7, -71), S(7, -15), S(1, 8), S(-3, 11), S(-9, 18), S(-5, 21), }},
  {{ S(1, -0), S(3, -65), S(-0, 23), S(-2, 25), S(-5, 8), S(-11, 10), S(-8, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1429, 916, -23, -2
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(104);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(76);
inline VParam WINNABLE_BIAS = V(-394);

// Epoch duration: 9.00245s
// clang-format on
}  // namespace Clockwork
