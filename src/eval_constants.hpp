#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(203, 507);
inline const PParam KNIGHT_MAT = S(815, 1594);
inline const PParam BISHOP_MAT = S(869, 1679);
inline const PParam ROOK_MAT   = S(1042, 2668);
inline const PParam QUEEN_MAT  = S(2430, 4148);

inline const PParam TEMPO_VAL  = S(70, 53);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(62, 241);
inline const PParam ROOK_OPEN_VAL     = S(109, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 11);
inline const PParam MINOR_BEHIND_PAWN = S(14, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -82);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -39);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 51);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -47);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, 0), S(33, 36), S(60, 66), S(121, 212), S(389, 402), S(673, 819),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 32), S(39, 25), S(54, 57), S(92, 179), S(388, 120),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-94, -259), S(-95, -218), S(-67, -86), S(-24, 41), S(86, 202), S(227, 409),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-81, 54), S(-93, 36), S(-57, 105), S(-87, 229), S(-53, 340), S(53, 223),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-17, 68), S(-29, 59), S(-59, 107), S(-30, 135), S(75, 158), S(36, 193),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -40), S(24, -2), S(16, 35), S(21, 104), S(71, 272), S(336, 219),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -38), S(6, 7), S(0, -26), S(4, -68), S(-7, -178), S(-167, -453),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 235), S(10, 182), S(4, 106), S(11, 67), S(20, 72), S(58, 66), S(63, 36),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-128, -51), S(12, -5), S(1, 99), S(28, 150), S(44, 185), S(54, 194), S(40, 174),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-91, -395), S(-23, -142), S(8, -27), S(31, 22), S(59, 54), S(74, 91), S(92, 99), S(111, 107), S(131, 60),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-73, -350), S(-18, -129), S(34, -40), S(59, 15), S(79, 57), S(91, 88), S(96, 111), S(98, 132), S(102, 144), S(109, 150), S(117, 143), S(131, 127), S(132, 131), S(117, 96),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -214), S(24, -12), S(45, 22), S(60, 41), S(71, 59), S(75, 73), S(80, 89), S(86, 95), S(90, 108), S(96, 115), S(100, 122), S(100, 131), S(103, 136), S(109, 122), S(128, 84),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-193, -206), S(-39, -88), S(-14, 53), S(5, 193), S(22, 238), S(29, 292), S(36, 329), S(43, 347), S(48, 370), S(51, 387), S(57, 395), S(62, 401), S(65, 408), S(68, 414), S(68, 417), S(68, 418), S(65, 419), S(67, 412), S(68, 408), S(72, 400), S(64, 387), S(74, 364), S(41, 388), S(-6, 382), S(-41, 379), S(-75, 400), S(-136, 430), S(-103, 366),
};

inline const PParam PAWN_THREAT_KNIGHT = S(198, 155);
inline const PParam PAWN_THREAT_BISHOP = S(173, 222);
inline const PParam PAWN_THREAT_ROOK   = S(189, 155);
inline const PParam PAWN_THREAT_QUEEN  = S(161, 12);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(8, 57), S(93, 95), S(104, 125), S(206, 124), S(163, 4), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 57), S(53, 96), S(74, 96), S(18, 11), S(151, -48), S(0, 0),
};
inline const PParam KING_THREAT  = S(-11, 157);
inline const PParam HANGING_PAWN  = S(32, 93);
inline const PParam HANGING_NON_PAWN  = S(70, 28);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(25, 4),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(43, 44), S(112, -112),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(38, 12), S(45, -3),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -18), S(4, -16), S(0, -22), S(-5, -30), S(-12, -37), S(-17, -44), S(-19, -55), S(-24, -57), S(-30, -74),
};

inline const PParam ROOK_LINEUP = S(17, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(179, 277),    S(57, 399),     S(64, 388),     S(158, 270),    S(191, 169),    S(143, 210),    S(121, 239),    S(221, 179),    //
    S(38, 64),      S(51, 111),     S(29, 63),      S(46, -4),      S(38, -41),     S(12, -14),     S(12, 27),      S(-21, 53),     //
    S(37, -13),     S(14, -4),      S(42, -45),     S(27, -70),     S(18, -88),     S(4, -76),      S(-37, -44),    S(-38, -6),     //
    S(-7, -72),     S(-32, -42),    S(-1, -61),     S(-10, -78),    S(-31, -87),    S(-36, -76),    S(-83, -58),    S(-77, -53),    //
    S(-14, -110),   S(16, -105),    S(1, -44),      S(-13, -51),    S(-40, -60),    S(-53, -71),    S(-80, -71),    S(-83, -75),    //
    S(9, -108),     S(82, -95),     S(67, -38),     S(24, -11),     S(-5, -33),     S(-23, -61),    S(-49, -60),    S(-63, -59),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-259, -505),  S(-256, 49),    S(-263, -30),   S(4, 40),       S(-90, 43),     S(-265, 83),    S(-345, 98),    S(-347, -405),  //
    S(0, -13),      S(4, 27),       S(89, 25),      S(87, 60),      S(92, 48),      S(52, 29),      S(-16, 27),     S(-44, 23),     //
    S(42, -27),     S(41, 31),      S(58, 62),      S(76, 71),      S(60, 72),      S(23, 57),      S(10, 35),      S(-33, 9),      //
    S(92, 22),      S(93, 46),      S(104, 68),     S(107, 109),    S(111, 107),    S(75, 72),      S(53, 38),      S(34, 32),      //
    S(81, 14),      S(104, 2),      S(102, 48),     S(97, 80),      S(83, 84),      S(75, 64),      S(60, 18),      S(26, 26),      //
    S(22, -43),     S(49, -28),     S(56, 16),      S(66, 51),      S(61, 50),      S(33, 14),      S(17, -18),     S(-22, -41),    //
    S(38, -24),     S(41, -11),     S(29, -20),     S(39, 9),       S(36, 8),       S(7, -44),      S(-29, -0),     S(-48, -82),    //
    S(-42, -93),    S(11, -28),     S(30, -43),     S(46, -32),     S(29, -17),     S(-8, -50),     S(-19, -26),    S(-69, -141),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-131, 22),    S(-191, 102),   S(-403, 167),   S(-273, 98),    S(-304, 140),   S(-304, 152),   S(-225, 126),   S(-128, 71),    //
    S(-27, -22),    S(-66, 87),     S(-47, 62),     S(-69, 62),     S(-67, 76),     S(-40, 48),     S(-12, 42),     S(-53, 25),     //
    S(33, 19),      S(13, 59),      S(29, 70),      S(26, 56),      S(21, 45),      S(20, 48),      S(8, 44),       S(10, 12),      //
    S(15, -6),      S(48, 21),      S(61, 35),      S(80, 55),      S(103, 42),     S(42, 19),      S(44, -4),      S(-3, -2),      //
    S(38, -46),     S(46, 1),       S(77, 13),      S(93, 26),      S(75, 38),      S(65, 25),      S(19, 6),       S(8, -36),      //
    S(57, -30),     S(83, -27),     S(98, 3),       S(65, 28),      S(61, 13),      S(57, 15),      S(59, -4),      S(16, -22),     //
    S(26, -73),     S(113, -58),    S(66, -20),     S(47, -2),      S(30, -2),      S(45, -44),     S(44, -57),     S(37, -49),     //
    S(43, -72),     S(23, -25),     S(29, -9),      S(43, -31),     S(27, -18),     S(37, 15),      S(43, -17),     S(39, -60),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(174, 109),    S(202, 130),    S(156, 159),    S(142, 131),    S(203, 87),     S(161, 113),    S(168, 130),    S(153, 126),    //
    S(89, 149),     S(145, 154),    S(189, 125),    S(144, 112),    S(179, 99),     S(145, 125),    S(98, 156),     S(89, 158),     //
    S(57, 143),     S(177, 87),     S(202, 73),     S(174, 57),     S(179, 73),     S(120, 115),    S(115, 130),    S(62, 170),     //
    S(31, 110),     S(94, 118),     S(114, 92),     S(95, 96),      S(122, 78),     S(84, 118),     S(74, 134),     S(20, 158),     //
    S(6, 44),       S(64, 53),      S(58, 75),      S(25, 85),      S(35, 90),      S(24, 116),     S(7, 113),      S(-15, 117),    //
    S(18, -36),     S(87, -12),     S(74, 14),      S(51, 28),      S(60, 36),      S(37, 58),      S(33, 43),      S(-5, 49),      //
    S(-63, -41),    S(61, -78),     S(67, -40),     S(56, -6),      S(59, -5),      S(45, 9),       S(35, -7),      S(4, -4),       //
    S(0, -63),      S(23, -31),     S(86, -42),     S(95, -43),     S(97, -37),     S(74, -15),     S(68, -21),     S(47, -16),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(89, 160),     S(146, 159),    S(59, 298),     S(1, 394),      S(36, 350),     S(72, 260),     S(73, 178),     S(25, 213),     //
    S(56, 190),     S(76, 247),     S(39, 319),     S(-76, 431),    S(-37, 404),    S(17, 294),     S(56, 183),     S(39, 151),     //
    S(21, 230),     S(57, 263),     S(31, 329),     S(-4, 364),     S(14, 356),     S(52, 258),     S(79, 161),     S(62, 122),     //
    S(18, 166),     S(30, 229),     S(-9, 300),     S(-7, 351),     S(8, 349),      S(22, 239),     S(59, 158),     S(31, 127),     //
    S(15, 142),     S(12, 162),     S(6, 209),      S(-18, 277),    S(-10, 302),    S(11, 239),     S(14, 181),     S(36, 82),      //
    S(6, 49),       S(38, 54),      S(36, 128),     S(12, 153),     S(19, 167),     S(22, 191),     S(40, 123),     S(20, 101),     //
    S(-23, -98),    S(6, -99),      S(13, -26),     S(39, 16),      S(36, 57),      S(38, 29),      S(10, 71),      S(24, 42),      //
    S(-42, -81),    S(-11, -239),   S(21, -243),    S(32, -131),    S(39, -54),     S(37, -72),     S(35, -57),     S(4, -4),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(146, -556),   S(455, 76),     S(289, 193),    S(-2, 183),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(345, -183),   S(345, 188),    S(189, 205),    S(5, 156),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(180, 44),     S(213, 176),    S(99, 200),     S(-66, 181),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(22, 10),      S(101, 115),    S(-32, 173),    S(-128, 203),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, 1),     S(-25, 79),     S(-87, 147),    S(-183, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-55, -32),    S(12, 34),      S(-63, 114),    S(-120, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(24, -90),     S(30, -11),     S(-28, 48),     S(-102, 104),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -208),   S(5, -90),      S(-68, -30),    S(-76, -43),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -453);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -5), S(10, 13), S(10, 6), S(4, 1), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -1), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(20, -22), S(-9, 4), S(-6, -11), S(4, -16), S(9, -30), S(3, -55), S(-7, -50), }},
  {{ S(6, 1), S(-21, -2), S(-18, 9), S(-12, 18), S(-8, 7), S(-12, -18), S(-22, -25), }},
  {{ S(2, -2), S(-13, -8), S(-14, 18), S(-9, 19), S(-8, 9), S(-9, -17), S(-26, -39), }},
  {{ S(9, 9), S(-12, 15), S(-8, 36), S(-4, 39), S(-4, 34), S(1, 17), S(6, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 23), S(-4, 2), S(-5, 8), S(-4, 28), S(3, 50),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 10), S(-42, -135), S(-9, -46), S(-2, 6), S(-3, 3), S(-6, 10), S(-6, 10), }},
  {{ S(10, -3), S(-26, -134), S(-7, -30), S(-4, 0), S(-2, -5), S(-8, 1), S(1, 1), }},
  {{ S(2, 10), S(-9, -67), S(6, -17), S(0, 8), S(-3, 10), S(-9, 17), S(-5, 19), }},
  {{ S(3, -2), S(2, -65), S(-1, 24), S(-2, 25), S(-5, 6), S(-11, 7), S(-8, 16), }},
}};
inline const std::array<PParam, 4> SHELTER_RAM_PUSHES = {
    S(-16, 12), S(-10, 10), S(-7, 7), S(-4, 4),
};
inline const std::array<std::array<PParam, 4>, 4> SHELTER_RAMMABLE = {{
  {{ S(-14, -11), S(0, 0), S(0, 0), S(0, 0), }},
  {{ S(-8, 4), S(-15, 9), S(0, 0), S(0, 0), }},
  {{ S(-2, 6), S(-7, 7), S(-8, 8), S(0, 0), }},
  {{ S(2, 1), S(-2, -4), S(-3, 5), S(-12, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1438, 882, -15, -4
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(75);
inline VParam WINNABLE_BIAS = V(-389);

// Epoch duration: 7.31455s
// clang-format on
}  // namespace Clockwork
