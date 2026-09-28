#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(215, 509);
inline const PParam KNIGHT_MAT = S(870, 1531);
inline const PParam BISHOP_MAT = S(919, 1574);
inline const PParam ROOK_MAT   = S(1134, 2380);
inline const PParam QUEEN_MAT  = S(2729, 3616);

inline const PParam TEMPO_VAL  = S(75, 60);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, 3);
inline const PParam BISHOP_PAIR_VAL   = S(61, 242);
inline const PParam ROOK_OPEN_VAL     = S(121, -10);
inline const PParam ROOK_SEMIOPEN_VAL = S(53, 17);
inline const PParam MINOR_BEHIND_PAWN = S(15, 44);
inline const PParam RESTRICTED_SQUARES = S(21, 8);
inline const PParam SPACE_VAL = S(95, -112);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -92);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -42);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -38);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(37, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(35, 59);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(20, 69);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -10), S(39, 23), S(54, 74), S(119, 219), S(460, 409), S(574, 651),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 26), S(43, 22), S(43, 70), S(91, 185), S(447, 109),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -256), S(-93, -211), S(-61, -80), S(-9, 42), S(86, 254), S(237, 448),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-94, 70), S(-91, 44), S(-50, 93), S(-78, 211), S(-39, 311), S(82, 195),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-7, 56), S(-15, 51), S(-57, 97), S(-11, 109), S(103, 118), S(49, 193),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(21, -33), S(16, 6), S(7, 43), S(20, 100), S(71, 262), S(322, 259),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(-2, -28), S(-4, 13), S(-14, -25), S(-12, -72), S(-24, -174), S(-228, -449),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(31, 222), S(5, 182), S(-2, 104), S(12, 60), S(26, 59), S(68, 42), S(76, 12),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-144, -16), S(13, 9), S(4, 107), S(42, 139), S(56, 178), S(61, 196), S(47, 172),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-56, -286), S(-11, -66), S(7, 23), S(18, 60), S(31, 93), S(37, 135), S(47, 152), S(56, 176), S(68, 145),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-99, -249), S(-34, -30), S(24, 34), S(44, 88), S(61, 121), S(72, 143), S(78, 156), S(77, 172), S(79, 177), S(82, 184), S(94, 172), S(94, 167), S(94, 171), S(46, 139),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(83, -71), S(-1, 121), S(22, 148), S(39, 164), S(49, 176), S(53, 183), S(56, 193), S(60, 195), S(63, 203), S(67, 210), S(68, 216), S(64, 225), S(60, 231), S(60, 222), S(71, 191),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-171, -21), S(-35, 119), S(-7, 232), S(14, 347), S(34, 363), S(43, 394), S(48, 427), S(51, 448), S(54, 470), S(57, 485), S(60, 497), S(65, 501), S(67, 510), S(72, 509), S(71, 517), S(74, 516), S(69, 520), S(70, 511), S(71, 507), S(81, 496), S(65, 495), S(95, 453), S(71, 472), S(30, 473), S(5, 459), S(-26, 488), S(-13, 448), S(3, 393),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-34, 6), S(-2, 20), S(6, 52), S(13, 63), S(22, 74), S(25, 88), S(27, 103), S(32, 95), S(37, 97), S(41, 91), S(45, 89), S(46, 92), S(46, 87), S(51, 77), S(59, 59), S(60, 48), S(60, 33), S(66, 15), S(70, 6), S(66, -14), S(30, -53),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(47, 21), S(42, 21), S(44, 30), S(42, 64), S(41, 74), S(43, 76), S(41, 85), S(43, 88), S(42, 100), S(39, 106), S(37, 116), S(38, 118), S(39, 123), S(41, 127), S(51, 126), S(57, 119), S(51, 131), S(21, 134),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(53, 71), S(49, 94), S(48, 103), S(50, 114), S(54, 117), S(55, 124), S(56, 131), S(58, 137), S(56, 151), S(60, 154), S(57, 166), S(56, 174), S(52, 188), S(53, 191), S(51, 199), S(44, 212), S(45, 213), S(41, 221), S(35, 227), S(14, 249),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(35, 150), S(24, 217), S(23, 304), S(30, 313), S(27, 350), S(27, 367), S(28, 375), S(30, 393), S(30, 397), S(35, 398), S(28, 420), S(33, 415), S(37, 414), S(40, 412), S(41, 417), S(46, 411), S(48, 400), S(56, 391), S(62, 377), S(61, 385), S(87, 343), S(90, 339), S(110, 279),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(3, 6), S(5, 3), S(15, 2), S(0, 21),
};

inline const PParam PAWN_THREAT_KNIGHT = S(215, 181);
inline const PParam PAWN_THREAT_BISHOP = S(176, 254);
inline const PParam PAWN_THREAT_ROOK   = S(203, 158);
inline const PParam PAWN_THREAT_QUEEN  = S(168, 35);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(14, 59), S(98, 121), S(112, 128), S(196, 94), S(181, 28), }},
  {{ S(11, 61), S(88, 111), S(111, 120), S(229, 631), S(158, -12), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(13, 72), S(47, 137), S(67, 136), S(16, 25), S(178, -81), }},
  {{ S(2, 60), S(63, 105), S(107, 92), S(15, 16), S(464, 635), }},
}};
inline const PParam KING_THREAT  = S(-20, 141);
inline const PParam REACH_THREAT = S(-14, 13);
inline const PParam REACH_THREAT_LOOSE = S(18, 28);
inline const PParam HANGING_PAWN  = S(39, 96);
inline const PParam HANGING_NON_PAWN  = S(86, 39);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(20, -7), S(94, -77),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(50, 36), S(190, -207),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(42, -6), S(127, -106),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -13), S(-1, -18), S(-7, -25), S(-13, -31), S(-20, -34), S(-22, -43), S(-29, -38), S(-28, -90),
};

inline const PParam ROOK_LINEUP = S(19, 72);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(209, 278),    S(78, 384),     S(91, 313),     S(188, 299),    S(183, 233),    S(145, 270),    S(132, 294),    S(231, 240),    //
    S(50, 74),      S(39, 131),     S(18, 84),      S(23, 20),      S(15, -20),     S(-11, 13),     S(-7, 62),      S(-24, 82),     //
    S(36, 15),      S(-0, 38),      S(12, 21),      S(-11, -25),    S(-27, -40),    S(-37, -17),    S(-59, -3),     S(-51, 33),     //
    S(-4, -53),     S(-36, -19),    S(-11, -32),    S(-20, -68),    S(-44, -77),    S(-53, -40),    S(-95, -25),    S(-89, -21),    //
    S(-20, -94),    S(16, -98),     S(-1, -19),     S(-11, -40),    S(-34, -49),    S(-61, -37),    S(-97, -36),    S(-104, -39),   //
    S(8, -79),      S(95, -96),     S(94, -57),     S(49, -21),     S(19, -40),     S(-15, -38),    S(-59, -23),    S(-78, -23),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-319, -482),  S(-270, 45),    S(-313, 136),   S(9, 74),       S(-99, 85),     S(-333, 145),   S(-363, 112),   S(-410, -399),  //
    S(-19, 13),     S(-30, 48),     S(69, 37),      S(71, 115),     S(77, 99),      S(33, 57),      S(-33, 38),     S(-76, 41),     //
    S(25, -3),      S(32, 48),      S(37, 72),      S(51, 123),     S(37, 113),     S(0, 71),       S(-18, 61),     S(-58, 29),     //
    S(80, 54),      S(78, 91),      S(83, 120),     S(81, 197),     S(83, 184),     S(57, 112),     S(34, 63),      S(10, 63),      //
    S(57, 38),      S(78, 35),      S(92, 73),      S(62, 170),     S(61, 151),     S(52, 98),      S(34, 57),      S(1, 30),       //
    S(9, -36),      S(49, -38),     S(59, -0),      S(60, 62),      S(58, 58),      S(39, 6),       S(15, -13),     S(-40, -33),    //
    S(34, -22),     S(32, -2),      S(40, -42),     S(47, 7),       S(43, 13),      S(15, -33),     S(-38, 21),     S(-65, -81),    //
    S(-65, -99),    S(2, -42),      S(21, -48),     S(27, -26),     S(14, -19),     S(-30, -38),    S(-45, -14),    S(-109, -140),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-134, 22),    S(-249, 153),   S(-448, 242),   S(-304, 158),   S(-309, 170),   S(-287, 175),   S(-216, 138),   S(-161, 120),   //
    S(-52, 17),     S(-96, 146),    S(-78, 120),    S(-87, 123),    S(-88, 131),    S(-56, 83),     S(-42, 90),     S(-70, 48),     //
    S(38, 44),      S(14, 82),      S(16, 109),     S(6, 102),      S(11, 81),      S(4, 92),       S(-17, 86),     S(9, 19),       //
    S(-0, 24),      S(45, 55),      S(58, 68),      S(79, 98),      S(89, 91),      S(30, 61),      S(24, 43),      S(-15, 23),     //
    S(27, -11),     S(26, 37),      S(71, 38),      S(86, 60),      S(74, 60),      S(56, 62),      S(3, 46),       S(-10, 2),      //
    S(43, 7),       S(66, -1),      S(85, 22),      S(59, 51),      S(54, 43),      S(50, 48),      S(45, 34),      S(12, -2),      //
    S(16, -42),     S(112, -50),    S(58, -9),      S(44, 15),      S(32, 19),      S(41, -12),     S(42, -19),     S(21, -9),      //
    S(19, -43),     S(11, -13),     S(17, -5),      S(24, -11),     S(8, -3),       S(22, 34),      S(24, 6),       S(18, -34),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(142, 193),    S(172, 204),    S(146, 226),    S(122, 197),    S(168, 179),    S(116, 203),    S(138, 217),    S(125, 212),    //
    S(84, 212),     S(122, 222),    S(183, 171),    S(137, 165),    S(166, 170),    S(130, 188),    S(70, 230),     S(71, 227),     //
    S(55, 193),     S(173, 127),    S(218, 102),    S(165, 97),     S(161, 129),    S(96, 168),     S(79, 196),     S(36, 235),     //
    S(17, 156),     S(82, 156),     S(92, 143),     S(71, 135),     S(93, 125),     S(59, 165),     S(44, 181),     S(2, 203),      //
    S(-16, 97),     S(39, 106),     S(27, 131),     S(-9, 139),     S(4, 139),      S(-5, 163),     S(-20, 165),    S(-46, 176),    //
    S(-12, 15),     S(65, 16),      S(48, 42),      S(20, 65),      S(28, 80),      S(13, 98),      S(8, 78),       S(-36, 100),    //
    S(-79, 2),      S(46, -57),     S(50, -19),     S(32, 36),      S(37, 42),      S(19, 61),      S(8, 49),       S(-20, 44),     //
    S(-19, -13),    S(6, 12),       S(70, -7),      S(75, 5),       S(77, 24),      S(51, 50),      S(47, 40),      S(26, 43),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(103, 234),    S(174, 214),    S(85, 351),     S(49, 393),     S(58, 398),     S(99, 318),     S(79, 260),     S(25, 293),     //
    S(72, 268),     S(78, 319),     S(50, 383),     S(-59, 467),    S(-18, 450),    S(37, 332),     S(62, 267),     S(53, 221),     //
    S(41, 274),     S(90, 293),     S(52, 361),     S(18, 382),     S(26, 398),     S(60, 319),     S(96, 217),     S(80, 184),     //
    S(35, 208),     S(41, 263),     S(-5, 338),     S(-4, 374),     S(18, 369),     S(20, 286),     S(65, 208),     S(46, 192),     //
    S(14, 182),     S(16, 175),     S(5, 224),      S(-17, 295),    S(-17, 340),    S(12, 284),     S(16, 234),     S(32, 164),     //
    S(9, 72),       S(44, 41),      S(33, 135),     S(4, 177),      S(22, 196),     S(19, 248),     S(37, 190),     S(22, 166),     //
    S(-19, -81),    S(24, -126),    S(25, -52),     S(48, 31),      S(47, 80),      S(49, 76),      S(23, 122),     S(33, 94),      //
    S(-52, -50),    S(-1, -255),    S(23, -241),    S(24, -106),    S(39, -24),     S(34, -18),     S(31, 2),       S(-2, 61),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(108, -457),   S(475, 113),    S(380, 241),    S(-10, 313),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(300, -172),   S(273, 236),    S(124, 351),    S(-113, 358),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(166, 12),     S(158, 197),    S(2, 331),      S(-204, 382),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, -17),     S(94, 99),      S(-102, 287),   S(-245, 373),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-90, -70),    S(-3, 26),      S(-94, 179),    S(-233, 278),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-26, -107),   S(34, -27),     S(-67, 128),    S(-154, 213),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(49, -168),    S(52, -74),     S(-20, 32),     S(-111, 125),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-8, -277),    S(22, -155),    S(-69, -55),    S(-81, -50),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -111);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -3), S(14, 1), S(12, 1), S(4, -1), S(2, -5),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -4), S(7, -2), S(3, -2), S(3, -1), S(2, 3),
};

inline const PParam REACH_INNER_RING = S(1, 0);
inline const PParam REACH_OUTER_RING = S(-0, 1);
inline const PParam REACH_RING_DEFENSE = S(-4, 4);
inline const PParam REACH_RING_TWICE = S(4, -0);

inline const PParam KS_FLANK_ATTACK = S(5, -4);
inline const PParam KS_FLANK_DEFENSE = S(-2, -3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -2);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(10, -10), S(-15, 11), S(-8, -13), S(3, -18), S(11, -32), S(-5, -31), S(-0, -77), }},
  {{ S(-3, 16), S(-26, 1), S(-19, 5), S(-9, 9), S(-5, 2), S(-16, -1), S(-19, -41), }},
  {{ S(-11, 15), S(-20, -0), S(-16, 18), S(-8, 13), S(-8, 9), S(-16, 5), S(-13, -124), }},
  {{ S(-3, 30), S(-16, 16), S(-6, 24), S(-0, 20), S(1, 12), S(-0, 19), S(2, 13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(1, 58), S(-14, 24), S(-16, 34), S(-12, 43), S(7, 36),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 36), S(-58, -199), S(-14, -42), S(0, 6), S(-7, 17), S(-12, 26), S(-12, 27), }},
  {{ S(4, 19), S(-33, -197), S(-6, -51), S(-2, -6), S(-4, 6), S(-14, 18), S(-4, 18), }},
  {{ S(-6, 26), S(-4, -173), S(10, -22), S(3, 2), S(-5, 17), S(-13, 26), S(-10, 29), }},
  {{ S(-3, 14), S(9, -101), S(10, -19), S(2, 16), S(-10, 24), S(-16, 18), S(-12, 21), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1221, 866, -27, -2
);

inline VParam WINNABLE_PAWNS = V(-22);
inline VParam WINNABLE_SYM = V(109);
inline VParam WINNABLE_ASYM = V(94);
inline VParam WINNABLE_PAWN_ENDGAME = V(69);
inline VParam WINNABLE_BIAS = V(-406);

// Epoch duration: 4.83904s
// clang-format on
}  // namespace Clockwork
