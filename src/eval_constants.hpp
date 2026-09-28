#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(215, 491);
inline const PParam KNIGHT_MAT = S(838, 1504);
inline const PParam BISHOP_MAT = S(897, 1562);
inline const PParam ROOK_MAT   = S(1111, 2370);
inline const PParam QUEEN_MAT  = S(2549, 3535);

inline const PParam TEMPO_VAL  = S(60, 48);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, -1);
inline const PParam BISHOP_PAIR_VAL   = S(65, 233);
inline const PParam ROOK_OPEN_VAL     = S(111, -9);
inline const PParam ROOK_SEMIOPEN_VAL = S(41, -1);
inline const PParam MINOR_BEHIND_PAWN = S(22, 51);
inline const PParam RESTRICTED_SQUARES = S(19, 4);
inline const PParam SPACE_VAL = S(97, -60);

inline const PParam DOUBLED_PAWN_VAL = S(-32, -92);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-36, -39);
inline const PParam OUTPOST_KNIGHT_VAL    = S(43, 32);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 29);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(48, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(35, 5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(9, 66);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(24, 0), S(40, 29), S(64, 66), S(136, 216), S(446, 380), S(562, 638),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(58, 27), S(42, 20), S(45, 58), S(105, 173), S(408, 118),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-100, -250), S(-97, -217), S(-70, -85), S(-12, 38), S(94, 217), S(218, 414),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-77, 46), S(-90, 43), S(-44, 94), S(-93, 201), S(-79, 314), S(37, 219),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(5, 65), S(-13, 51), S(-58, 100), S(-24, 114), S(78, 135), S(35, 183),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(13, -39), S(21, -2), S(19, 36), S(21, 85), S(80, 261), S(310, 253),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(-11, -42), S(-4, 11), S(-13, -16), S(-8, -56), S(5, -159), S(-173, -467),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 217), S(3, 166), S(-9, 86), S(8, 52), S(39, 63), S(71, 54), S(60, 22),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-137, -70), S(6, -26), S(-3, 98), S(24, 138), S(48, 172), S(58, 182), S(56, 179),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-116, -363), S(-45, -103), S(-16, 15), S(7, 77), S(25, 119), S(41, 150), S(62, 155), S(83, 156), S(108, 109),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-64, -258), S(-22, -51), S(29, 28), S(40, 78), S(70, 128), S(81, 156), S(88, 178), S(85, 196), S(88, 213), S(91, 211), S(111, 209), S(115, 197), S(118, 191), S(81, 169),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(93, -99), S(7, 108), S(26, 150), S(52, 161), S(55, 185), S(61, 195), S(68, 211), S(75, 213), S(80, 227), S(85, 231), S(85, 246), S(87, 248), S(79, 252), S(83, 240), S(100, 213),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-173, -97), S(-17, 21), S(3, 179), S(33, 339), S(41, 382), S(49, 426), S(48, 471), S(51, 493), S(52, 517), S(57, 534), S(59, 546), S(70, 552), S(75, 553), S(81, 558), S(87, 569), S(79, 567), S(77, 565), S(73, 563), S(70, 557), S(81, 542), S(82, 548), S(101, 510), S(61, 527), S(28, 527), S(7, 503), S(-29, 534), S(-13, 488), S(-7, 433),
};

inline const PParam PAWN_THREAT_KNIGHT = S(215, 162);
inline const PParam PAWN_THREAT_BISHOP = S(178, 230);
inline const PParam PAWN_THREAT_ROOK   = S(196, 140);
inline const PParam PAWN_THREAT_QUEEN  = S(154, 19);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(8, 56), S(94, 82), S(95, 113), S(180, 73), S(168, -0), }},
  {{ S(2, 56), S(82, 78), S(91, 107), S(210, 581), S(152, -24), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 71), S(54, 118), S(62, 105), S(4, 16), S(158, -87), }},
  {{ S(1, 61), S(72, 85), S(101, 61), S(26, 18), S(428, 608), }},
}};
inline const PParam KING_THREAT  = S(8, 151);
inline const PParam HANGING_PAWN  = S(23, 100);
inline const PParam HANGING_NON_PAWN  = S(70, 18);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(26, -14), S(107, -67),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(47, 27), S(214, -230),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(41, 12), S(129, -104),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -16), S(7, -11), S(2, -17), S(-8, -22), S(-14, -35), S(-21, -45), S(-21, -58), S(-30, -35), S(-31, -88),
};

inline const PParam ROOK_LINEUP = S(20, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(201, 276),    S(54, 385),     S(71, 375),     S(176, 269),    S(196, 191),    S(154, 218),    S(127, 233),    S(227, 191),    //
    S(53, 65),      S(42, 101),     S(32, 54),      S(51, 23),      S(47, -18),     S(29, 10),      S(2, 35),       S(-11, 64),     //
    S(44, -6),      S(-8, -6),      S(22, -32),     S(17, -36),     S(2, -33),      S(-17, -36),    S(-42, -37),    S(-31, 5),      //
    S(-17, -56),    S(-35, -33),    S(-13, -48),    S(-30, -64),    S(-46, -73),    S(-51, -64),    S(-81, -39),    S(-80, -36),    //
    S(-21, -80),    S(13, -83),     S(-10, -33),    S(-31, -37),    S(-60, -47),    S(-71, -49),    S(-89, -59),    S(-105, -61),   //
    S(10, -81),     S(79, -71),     S(80, -29),     S(29, 6),       S(-6, -29),     S(-15, -28),    S(-58, -26),    S(-74, -26),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-292, -433),  S(-233, 61),    S(-291, 136),   S(35, 53),      S(-68, 66),     S(-302, 138),   S(-326, 123),   S(-379, -347),  //
    S(8, 10),       S(-5, 56),      S(81, 40),      S(99, 99),      S(102, 67),     S(45, 48),      S(-12, 43),     S(-40, 54),     //
    S(48, 8),       S(37, 43),      S(41, 70),      S(86, 108),     S(57, 96),      S(22, 90),      S(-9, 57),      S(-48, 31),     //
    S(90, 61),      S(87, 62),      S(85, 85),      S(95, 125),     S(96, 113),     S(52, 82),      S(43, 54),      S(16, 67),      //
    S(75, 31),      S(103, 35),     S(104, 68),     S(79, 109),     S(69, 94),      S(58, 77),      S(39, 36),      S(26, 47),      //
    S(-9, -34),     S(33, -10),     S(46, 24),      S(58, 73),      S(44, 67),      S(23, 25),      S(6, -3),       S(-53, -36),    //
    S(37, 10),      S(24, 22),      S(1, -9),       S(27, 28),      S(14, 24),      S(-16, -25),    S(-52, 23),     S(-76, -67),    //
    S(-63, -62),    S(-16, -24),    S(8, -25),      S(33, 4),       S(15, 1),       S(-46, -41),    S(-51, -3),     S(-110, -113),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-103, 34),    S(-227, 136),   S(-402, 226),   S(-259, 145),   S(-265, 165),   S(-253, 165),   S(-194, 138),   S(-133, 143),   //
    S(-44, 7),      S(-85, 121),    S(-48, 105),    S(-52, 104),    S(-49, 110),    S(-40, 75),     S(-18, 74),     S(-45, 67),     //
    S(44, 52),      S(21, 84),      S(21, 101),     S(31, 93),      S(35, 69),      S(18, 89),      S(3, 79),       S(11, 27),      //
    S(17, 28),      S(33, 45),      S(68, 56),      S(76, 78),      S(87, 73),      S(29, 49),      S(31, 38),      S(-7, 29),      //
    S(35, -19),     S(38, 35),      S(69, 36),      S(74, 58),      S(67, 67),      S(64, 68),      S(-7, 28),      S(14, 8),       //
    S(43, 14),      S(69, 4),       S(77, 31),      S(55, 48),      S(50, 37),      S(53, 47),      S(63, 33),      S(3, 4),        //
    S(30, -31),     S(95, -35),     S(64, 23),      S(29, 21),      S(16, 24),      S(57, 0),       S(36, -27),     S(42, -3),      //
    S(27, -31),     S(27, 8),       S(19, 34),      S(24, 13),      S(13, 20),      S(23, 43),      S(42, 17),      S(29, -21),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(172, 176),    S(191, 195),    S(148, 221),    S(124, 188),    S(194, 168),    S(138, 182),    S(148, 198),    S(150, 191),    //
    S(99, 217),     S(140, 220),    S(177, 173),    S(134, 170),    S(179, 162),    S(146, 185),    S(81, 215),     S(78, 216),     //
    S(71, 203),     S(186, 147),    S(212, 121),    S(179, 118),    S(184, 141),    S(108, 175),    S(100, 208),    S(58, 244),     //
    S(46, 185),     S(105, 193),    S(95, 165),     S(88, 160),     S(117, 146),    S(86, 184),     S(58, 203),     S(9, 225),      //
    S(2, 110),      S(70, 127),     S(44, 165),     S(12, 157),     S(33, 149),     S(22, 184),     S(-8, 181),     S(-16, 193),    //
    S(21, 53),      S(79, 57),      S(76, 98),      S(42, 108),     S(48, 109),     S(16, 126),     S(17, 114),     S(-19, 118),    //
    S(-64, 31),     S(57, -13),     S(60, 33),      S(41, 62),      S(51, 67),      S(31, 78),      S(9, 57),       S(-14, 51),     //
    S(-9, -2),      S(20, 41),      S(66, 15),      S(73, 13),      S(90, 30),      S(58, 48),      S(55, 43),      S(28, 44),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(114, 226),    S(177, 212),    S(82, 353),     S(35, 401),     S(40, 413),     S(91, 295),     S(78, 268),     S(30, 279),     //
    S(94, 273),     S(66, 313),     S(46, 384),     S(-54, 471),    S(-23, 456),    S(37, 336),     S(58, 265),     S(50, 215),     //
    S(56, 269),     S(89, 295),     S(61, 390),     S(21, 405),     S(33, 412),     S(74, 332),     S(94, 217),     S(79, 183),     //
    S(60, 240),     S(41, 294),     S(0, 348),      S(-6, 398),     S(19, 400),     S(28, 306),     S(61, 229),     S(58, 195),     //
    S(35, 221),     S(29, 212),     S(25, 260),     S(-9, 340),     S(-9, 360),     S(17, 298),     S(18, 240),     S(43, 162),     //
    S(25, 119),     S(54, 103),     S(51, 193),     S(16, 219),     S(26, 228),     S(33, 267),     S(52, 207),     S(31, 183),     //
    S(-24, -42),    S(30, -47),     S(31, 28),      S(43, 74),      S(38, 115),     S(40, 98),      S(11, 124),     S(42, 100),     //
    S(-33, 6),      S(-8, -193),    S(21, -159),    S(39, -51),     S(50, 17),      S(36, -1),      S(31, 11),      S(-14, 67),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(134, -424),   S(484, 111),    S(430, 134),    S(76, 189),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(338, -156),   S(327, 182),    S(235, 185),    S(25, 125),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(189, 33),     S(208, 167),    S(88, 196),     S(-83, 175),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(45, 19),      S(103, 89),     S(-38, 174),    S(-152, 200),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-100, -11),   S(-26, 75),     S(-102, 135),   S(-201, 185),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-65, -26),    S(-12, 26),     S(-80, 113),    S(-141, 146),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(34, -90),     S(37, -19),     S(-46, 39),     S(-119, 101),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-12, -193),   S(7, -84),      S(-87, -24),    S(-63, -31),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-97, -434);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -2), S(13, 13), S(11, 3), S(3, 4), S(1, -6),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(6, -6), S(6, 1), S(4, 1), S(4, -2), S(3, -3),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-2, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, 0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(12, -16), S(-9, 0), S(-11, -2), S(5, -19), S(10, -35), S(2, -54), S(-10, -50), }},
  {{ S(2, 10), S(-28, 0), S(-20, 13), S(-13, 23), S(-2, 12), S(-1, -10), S(-15, -11), }},
  {{ S(-5, 2), S(-16, -6), S(-17, 24), S(-8, 14), S(-3, 11), S(-9, -16), S(-20, -49), }},
  {{ S(6, 13), S(-8, 35), S(-8, 37), S(-8, 57), S(-9, 49), S(-14, 16), S(5, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 18), S(-4, 5), S(-8, 11), S(-6, 30), S(-2, 46),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 13), S(-64, -127), S(-14, -48), S(1, -1), S(-7, 9), S(-12, 14), S(-6, 16), }},
  {{ S(13, -4), S(-32, -114), S(-18, -46), S(-2, -0), S(-3, -3), S(-14, 6), S(-2, 7), }},
  {{ S(-2, 14), S(-17, -93), S(4, -13), S(-0, 13), S(-4, 13), S(-16, 24), S(-4, 17), }},
  {{ S(1, -0), S(9, -68), S(7, 28), S(-5, 31), S(-13, 7), S(-19, 8), S(-22, 22), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1124, 854, -27, -5
);

inline VParam WINNABLE_PAWNS = V(-18);
inline VParam WINNABLE_SYM = V(105);
inline VParam WINNABLE_ASYM = V(83);
inline VParam WINNABLE_PAWN_ENDGAME = V(15);
inline VParam WINNABLE_BIAS = V(-384);
// clang-format on
}  // namespace Clockwork
