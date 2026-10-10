#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(201, 492);
inline const PParam KNIGHT_MAT = S(852, 1508);
inline const PParam BISHOP_MAT = S(899, 1576);
inline const PParam ROOK_MAT   = S(1106, 2368);
inline const PParam QUEEN_MAT  = S(2590, 3564);

inline const PParam TEMPO_VAL  = S(73, 56);

inline const PParam BISHOP_XRAY_PAWNS   = S(-16, 2);
inline const PParam BISHOP_PAIR_VAL   = S(62, 243);
inline const PParam ROOK_OPEN_VAL     = S(108, 4);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 8);
inline const PParam MINOR_BEHIND_PAWN = S(17, 42);
inline const PParam RESTRICTED_SQUARES = S(18, 5);
inline const PParam SPACE_VAL = S(77, -60);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -86);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -43);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 46);
inline const PParam OUTPOST_BISHOP_VAL    = S(46, 26);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(35, 46);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(43, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(35, 48);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -56);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, -9), S(42, 21), S(52, 70), S(117, 205), S(434, 385), S(560, 652),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 23), S(43, 19), S(44, 66), S(94, 177), S(419, 113),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-86, -257), S(-88, -214), S(-55, -85), S(-14, 39), S(61, 225), S(210, 440),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-89, 75), S(-109, 64), S(-60, 111), S(-82, 223), S(-49, 325), S(66, 216),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-14, 78), S(-23, 71), S(-59, 113), S(-10, 122), S(100, 142), S(40, 198),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(14, -30), S(9, 10), S(5, 41), S(18, 98), S(87, 257), S(345, 250),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(-1, -28), S(-9, 13), S(-15, -18), S(-2, -61), S(0, -180), S(-195, -470),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 225), S(4, 175), S(-0, 98), S(10, 59), S(23, 64), S(60, 56), S(62, 34),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-116, -58), S(17, -6), S(2, 100), S(34, 143), S(47, 181), S(57, 187), S(42, 167),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-90, -387), S(-16, -109), S(8, 27), S(20, 90), S(32, 129), S(38, 163), S(49, 153), S(60, 135), S(73, 75),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-41, -300), S(4, -64), S(47, 20), S(59, 85), S(66, 128), S(69, 159), S(69, 180), S(65, 196), S(64, 201), S(66, 207), S(71, 202), S(70, 191), S(75, 202), S(32, 171),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(61, -79), S(7, 119), S(29, 146), S(46, 166), S(58, 183), S(63, 196), S(68, 213), S(74, 220), S(81, 230), S(88, 236), S(94, 240), S(94, 247), S(98, 252), S(115, 228), S(134, 193),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-171, -107), S(-26, 28), S(11, 163), S(30, 319), S(50, 364), S(58, 415), S(63, 463), S(66, 492), S(68, 521), S(71, 539), S(73, 555), S(78, 562), S(80, 571), S(84, 572), S(84, 577), S(84, 579), S(79, 583), S(76, 578), S(76, 577), S(81, 570), S(68, 564), S(91, 527), S(43, 577), S(6, 566), S(-25, 559), S(-71, 600), S(-39, 548), S(-39, 491),
};

inline const PParam PAWN_THREAT_KNIGHT = S(204, 164);
inline const PParam PAWN_THREAT_BISHOP = S(187, 230);
inline const PParam PAWN_THREAT_ROOK   = S(220, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(175, -1);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(3, 50), S(80, 95), S(107, 122), S(191, 76), S(175, -8), }},
  {{ S(-0, 53), S(72, 86), S(108, 114), S(220, 587), S(151, -39), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(1, 70), S(46, 114), S(70, 99), S(10, 26), S(159, -85), }},
  {{ S(-9, 59), S(65, 78), S(109, 56), S(12, 14), S(427, 609), }},
}};
inline const PParam KING_THREAT  = S(5, 151);
inline const PParam HANGING_PAWN  = S(26, 97);
inline const PParam HANGING_NON_PAWN  = S(68, 32);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(25, -22), S(102, -85),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(48, 34), S(215, -246),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(33, 17), S(122, -106),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(6, -7), S(6, -8), S(2, -16), S(-5, -25), S(-11, -33), S(-17, -37), S(-20, -48), S(-26, -44), S(-26, -91),
};

inline const PParam ROOK_LINEUP = S(19, 91);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(202, 279),    S(83, 404),     S(54, 399),     S(148, 281),    S(159, 200),    S(149, 214),    S(161, 238),    S(237, 204),    //
    S(64, 75),      S(70, 120),     S(32, 90),      S(29, 30),      S(22, -8),      S(10, 14),      S(24, 48),      S(-8, 72),      //
    S(35, 7),       S(11, 18),      S(17, -8),      S(-15, -19),    S(-28, -38),    S(-30, -36),    S(-44, -22),    S(-47, 15),     //
    S(-6, -55),     S(-37, -24),    S(-6, -43),     S(-25, -56),    S(-48, -66),    S(-52, -56),    S(-92, -39),    S(-84, -36),    //
    S(-22, -97),    S(13, -88),     S(5, -38),      S(-16, -44),    S(-40, -55),    S(-67, -58),    S(-97, -50),    S(-110, -54),   //
    S(-2, -91),     S(79, -79),     S(87, -38),     S(31, -5),      S(-1, -28),     S(-32, -51),    S(-76, -41),    S(-98, -33),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-418, -226),  S(-272, -7),    S(-262, 84),    S(-25, 76),     S(-103, 96),    S(-300, 107),   S(-293, -6),    S(-484, -176),  //
    S(11, -57),     S(-36, 1),      S(169, -40),    S(117, -10),    S(114, -2),     S(145, -49),    S(-18, -40),    S(-25, -31),    //
    S(34, 38),      S(125, 66),     S(80, 94),      S(83, 57),      S(71, 55),      S(60, 61),      S(94, 52),      S(-44, 74),     //
    S(83, 5),       S(73, 130),     S(73, 128),     S(49, 173),     S(54, 157),     S(68, 103),     S(40, 113),     S(14, 63),      //
    S(52, 10),      S(65, -1),      S(87, 70),      S(70, 87),      S(71, 89),      S(70, 73),      S(44, 38),      S(1, 41),       //
    S(-10, -46),    S(46, -20),     S(54, -5),      S(70, 33),      S(72, 26),      S(47, -18),     S(26, -11),     S(-48, -37),    //
    S(21, -14),     S(5, -5),       S(39, 0),       S(40, 6),       S(40, -7),      S(30, -33),     S(-54, -30),    S(-78, -46),    //
    S(-88, -22),    S(-16, 30),     S(-15, 37),     S(10, 40),      S(6, 46),       S(-38, 34),     S(-55, 59),     S(-121, -42),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-158, 65),    S(-182, 69),    S(-247, 123),   S(-222, 99),    S(-196, 97),    S(-195, 73),    S(-185, 76),    S(-190, 62),    //
    S(-39, -45),    S(29, 8),       S(2, 3),        S(27, -5),      S(19, 24),      S(15, -2),      S(64, -6),      S(-34, -28),    //
    S(86, -5),      S(99, 60),      S(123, 58),     S(110, 64),     S(120, 38),     S(94, 44),      S(54, 65),      S(33, 12),      //
    S(21, 25),      S(42, 59),      S(83, 88),      S(92, 104),     S(99, 101),     S(65, 71),      S(52, 32),      S(13, 16),      //
    S(3, 0),        S(20, 20),      S(35, 24),      S(49, 76),      S(48, 84),      S(25, 55),      S(17, 25),      S(-5, 0),       //
    S(11, -35),     S(67, 19),      S(78, 51),      S(53, 43),      S(51, 62),      S(66, 81),      S(57, 30),      S(-4, -33),     //
    S(-7, -14),     S(115, -38),    S(52, -7),      S(30, -42),     S(1, -36),      S(18, -45),     S(20, -53),     S(-18, -42),    //
    S(-44, -30),    S(-28, 10),     S(-29, 80),     S(-5, 44),      S(-14, 72),     S(9, 108),      S(6, 27),       S(-16, -47),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(40, 338),     S(36, 357),     S(63, 387),     S(37, 343),     S(55, 338),     S(75, 329),     S(51, 341),     S(88, 341),     //
    S(102, 231),    S(113, 264),    S(54, 259),     S(58, 236),     S(50, 242),     S(62, 246),     S(93, 246),     S(84, 242),     //
    S(93, 133),     S(103, 136),    S(100, 158),    S(103, 120),    S(98, 136),     S(96, 139),     S(99, 153),     S(71, 170),     //
    S(81, 119),     S(72, 160),     S(81, 148),     S(85, 131),     S(89, 132),     S(72, 162),     S(65, 173),     S(73, 169),     //
    S(70, 59),      S(60, 95),      S(67, 110),     S(68, 89),      S(72, 95),      S(66, 132),     S(58, 121),     S(62, 121),     //
    S(85, -25),     S(81, 25),      S(76, 34),      S(67, 36),      S(74, 49),      S(67, 77),      S(61, 62),      S(57, 55),      //
    S(38, -69),     S(53, -17),     S(75, 6),       S(66, 28),      S(78, 35),      S(63, 52),      S(61, 32),      S(33, 16),      //
    S(-3, -24),     S(55, 1),       S(72, 29),      S(87, 38),      S(73, 37),      S(59, 57),      S(67, 45),      S(57, 41),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(65, 278),     S(41, 330),     S(15, 407),     S(4, 447),      S(16, 441),     S(41, 378),     S(44, 259),     S(50, 227),     //
    S(51, 306),     S(41, 334),     S(3, 432),      S(-4, 416),     S(3, 417),      S(13, 322),     S(51, 239),     S(43, 248),     //
    S(57, 203),     S(75, 290),     S(63, 337),     S(57, 318),     S(69, 337),     S(72, 253),     S(75, 203),     S(50, 165),     //
    S(45, 211),     S(43, 276),     S(35, 271),     S(44, 332),     S(61, 315),     S(44, 252),     S(51, 242),     S(45, 196),     //
    S(29, 206),     S(57, 163),     S(46, 220),     S(34, 254),     S(27, 293),     S(41, 258),     S(42, 207),     S(37, 183),     //
    S(27, 130),     S(65, 125),     S(53, 169),     S(45, 200),     S(40, 209),     S(46, 240),     S(50, 177),     S(31, 183),     //
    S(8, -4),       S(35, 25),      S(53, 86),      S(46, 126),     S(46, 142),     S(42, 111),     S(38, 111),     S(36, 122),     //
    S(14, -24),     S(-8, -118),    S(29, -90),     S(36, 4),       S(51, 85),      S(45, 88),      S(38, 79),      S(20, 98),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(146, -449),   S(497, 97),     S(447, 129),    S(74, 189),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(336, -171),   S(339, 176),    S(240, 171),    S(34, 124),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(191, 23),     S(215, 155),    S(90, 182),     S(-84, 173),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -5),      S(123, 89),     S(-32, 160),    S(-152, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-101, -7),    S(-23, 72),     S(-81, 139),    S(-187, 187),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-48, -29),    S(12, 37),      S(-69, 117),    S(-122, 158),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(47, -102),    S(44, -17),     S(-23, 52),     S(-100, 116),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(4, -210),     S(-10, -86),    S(-90, -14),    S(-92, -28),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<PParam, 4> PSQT_MOBILITY_BLEND = {
    S(130, 421), S(360, 581), S(772, -34), S(496, 44),
};

inline const PParam KS_NO_QUEEN = S(-92, -432);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -2), S(12, 15), S(13, 5), S(5, 3), S(4, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -5), S(7, 6), S(3, 3), S(3, 1), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -15), S(-10, 5), S(-6, -9), S(5, -13), S(14, -29), S(8, -53), S(-4, -51), }},
  {{ S(-1, 10), S(-27, 4), S(-23, 13), S(-15, 22), S(-10, 13), S(-12, -15), S(-24, -24), }},
  {{ S(-6, 2), S(-13, -6), S(-16, 20), S(-11, 21), S(-8, 9), S(-9, -15), S(-22, -56), }},
  {{ S(6, 14), S(-13, 20), S(-9, 44), S(-3, 47), S(-2, 42), S(2, 26), S(15, -17), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 28), S(-8, 6), S(-10, 12), S(-11, 34), S(1, 53),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 16), S(-52, -109), S(-11, -41), S(1, 2), S(-5, 7), S(-8, 13), S(-7, 13), }},
  {{ S(10, 1), S(-32, -104), S(-7, -42), S(-4, -2), S(-3, -1), S(-12, 5), S(-1, 5), }},
  {{ S(-1, 14), S(-5, -72), S(7, -8), S(2, 8), S(-5, 15), S(-12, 22), S(-7, 23), }},
  {{ S(-1, 1), S(2, -63), S(-0, 23), S(-5, 33), S(-9, 13), S(-17, 10), S(-12, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1112, 884, -25, 3
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(42);
inline VParam WINNABLE_BIAS = V(-383);

// Epoch duration: 7.24362s
// clang-format on
}  // namespace Clockwork
