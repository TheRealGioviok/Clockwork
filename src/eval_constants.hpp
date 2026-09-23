#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(198, 494);
inline const PParam KNIGHT_MAT = S(855, 1515);
inline const PParam BISHOP_MAT = S(897, 1570);
inline const PParam ROOK_MAT   = S(1097, 2366);
inline const PParam QUEEN_MAT  = S(2571, 3564);

inline const PParam TEMPO_VAL  = S(72, 57);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(60, 240);
inline const PParam ROOK_OPEN_VAL     = S(113, -6);
inline const PParam ROOK_SEMIOPEN_VAL = S(49, 7);
inline const PParam MINOR_BEHIND_PAWN = S(17, 44);
inline const PParam RESTRICTED_SQUARES = S(19, 8);
inline const PParam SPACE_VAL = S(131, -27);

inline const PParam DOUBLED_PAWN_VAL = S(-16, -87);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -42);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 56);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, -10), S(40, 24), S(52, 72), S(122, 208), S(440, 379), S(564, 639),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 22), S(41, 22), S(47, 63), S(92, 175), S(408, 112),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-91, -251), S(-90, -211), S(-57, -84), S(-15, 43), S(74, 220), S(216, 434),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-70, 48), S(-89, 39), S(-46, 94), S(-88, 218), S(-63, 333), S(44, 228),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-1, 55), S(-12, 52), S(-58, 105), S(-17, 119), S(81, 145), S(40, 195),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(22, -37), S(20, 2), S(15, 35), S(26, 94), S(74, 261), S(311, 256),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(6, -28), S(-2, 14), S(-12, -17), S(-8, -59), S(-16, -171), S(-182, -459),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(24, 220), S(9, 169), S(2, 96), S(13, 56), S(25, 61), S(61, 55), S(70, 27),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-115, -62), S(21, -10), S(4, 99), S(33, 144), S(46, 182), S(56, 191), S(42, 169),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-112, -363), S(-38, -97), S(-9, 23), S(11, 76), S(34, 113), S(48, 154), S(66, 161), S(85, 166), S(105, 119),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-87, -286), S(-25, -65), S(30, 17), S(49, 85), S(67, 130), S(79, 163), S(84, 187), S(85, 209), S(89, 217), S(95, 224), S(108, 213), S(113, 201), S(122, 199), S(81, 166),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(90, -102), S(6, 108), S(28, 142), S(44, 160), S(55, 179), S(59, 193), S(63, 210), S(68, 218), S(73, 229), S(78, 238), S(82, 244), S(81, 253), S(83, 257), S(91, 242), S(106, 209),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-179, -98), S(-25, 13), S(1, 170), S(20, 325), S(38, 369), S(46, 421), S(51, 467), S(54, 494), S(57, 520), S(59, 540), S(63, 553), S(68, 558), S(70, 566), S(75, 566), S(76, 571), S(78, 570), S(74, 573), S(74, 564), S(75, 561), S(86, 547), S(71, 543), S(96, 502), S(61, 534), S(24, 525), S(0, 508), S(-34, 532), S(-15, 487), S(-8, 431),
};

inline const PParam PAWN_THREAT_KNIGHT = S(202, 162);
inline const PParam PAWN_THREAT_BISHOP = S(169, 233);
inline const PParam PAWN_THREAT_ROOK   = S(195, 147);
inline const PParam PAWN_THREAT_QUEEN  = S(158, 28);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(10, 54), S(99, 96), S(105, 122), S(184, 84), S(175, 4), }},
  {{ S(7, 57), S(89, 88), S(104, 117), S(217, 590), S(152, -28), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(9, 64), S(45, 115), S(64, 109), S(16, 20), S(165, -82), }},
  {{ S(-1, 53), S(63, 80), S(103, 64), S(14, 16), S(426, 612), }},
}};
inline const PParam KING_THREAT  = S(-1, 152);
inline const PParam HANGING_PAWN  = S(31, 94);
inline const PParam HANGING_NON_PAWN  = S(72, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(22, -16), S(96, -77),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(51, 32), S(212, -237),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(41, 7), S(128, -112),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -17), S(4, -15), S(0, -22), S(-6, -29), S(-13, -35), S(-19, -39), S(-21, -49), S(-26, -45), S(-23, -95),
};

inline const PParam ROOK_LINEUP = S(17, 86);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(194, 277),    S(61, 402),     S(70, 390),     S(173, 273),    S(182, 195),    S(153, 219),    S(136, 244),    S(225, 198),    //
    S(51, 72),      S(49, 117),     S(31, 74),      S(33, 19),      S(25, -20),     S(5, 2),        S(5, 44),       S(-21, 70),     //
    S(34, 3),       S(5, 10),       S(22, -17),     S(-8, -30),     S(-24, -43),    S(-28, -40),    S(-51, -27),    S(-47, 12),     //
    S(-11, -58),    S(-40, -29),    S(-12, -42),    S(-36, -47),    S(-59, -56),    S(-57, -51),    S(-94, -41),    S(-88, -37),    //
    S(-23, -92),    S(8, -86),      S(-5, -23),     S(-24, -29),    S(-47, -40),    S(-68, -45),    S(-97, -48),    S(-102, -52),   //
    S(0, -87),      S(76, -72),     S(83, -29),     S(32, 2),       S(2, -24),      S(-25, -44),    S(-66, -33),    S(-80, -33),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-295, -445),  S(-244, 56),    S(-291, 132),   S(26, 50),      S(-75, 62),     S(-303, 137),   S(-333, 116),   S(-388, -357),  //
    S(3, 17),       S(-10, 54),     S(81, 32),      S(81, 88),      S(94, 69),      S(48, 43),      S(-10, 39),     S(-53, 46),     //
    S(34, -6),      S(42, 45),      S(49, 71),      S(72, 93),      S(57, 88),      S(12, 82),      S(-3, 57),      S(-46, 27),     //
    S(80, 51),      S(85, 66),      S(88, 91),      S(98, 128),     S(99, 120),     S(65, 88),      S(42, 50),      S(15, 62),      //
    S(68, 40),      S(89, 21),      S(97, 62),      S(81, 104),     S(76, 100),     S(59, 86),      S(47, 39),      S(12, 36),      //
    S(9, -28),      S(40, -18),     S(45, 34),      S(55, 70),      S(50, 73),      S(21, 31),      S(4, -0),       S(-37, -26),    //
    S(23, -1),      S(19, 23),      S(18, -7),      S(28, 25),      S(23, 25),      S(-6, -24),     S(-50, 24),     S(-69, -62),    //
    S(-68, -66),    S(-6, -12),     S(12, -17),     S(29, -7),      S(13, 3),       S(-30, -27),    S(-44, 7),      S(-106, -104),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-119, 22),    S(-226, 145),   S(-407, 217),   S(-274, 138),   S(-280, 156),   S(-261, 169),   S(-193, 135),   S(-150, 126),   //
    S(-37, 17),     S(-76, 127),    S(-56, 103),    S(-64, 100),    S(-59, 106),    S(-36, 77),     S(-20, 73),     S(-61, 61),     //
    S(41, 45),      S(18, 82),      S(28, 96),      S(23, 86),      S(24, 69),      S(15, 84),      S(-5, 80),      S(14, 25),      //
    S(8, 24),       S(45, 57),      S(59, 64),      S(79, 88),      S(92, 83),      S(36, 59),      S(32, 41),      S(-8, 32),      //
    S(33, -10),     S(33, 40),      S(69, 46),      S(85, 65),      S(71, 73),      S(56, 63),      S(10, 45),      S(-2, 1),       //
    S(47, 9),       S(75, 5),       S(88, 34),      S(59, 61),      S(53, 53),      S(49, 48),      S(52, 30),      S(15, 3),       //
    S(21, -36),     S(110, -34),    S(55, 16),      S(38, 32),      S(24, 30),      S(38, -14),     S(40, -25),     S(27, -11),     //
    S(25, -32),     S(13, 8),       S(16, 30),      S(29, 8),       S(13, 14),      S(27, 48),      S(31, 19),      S(24, -24),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(160, 176),    S(181, 194),    S(145, 225),    S(133, 189),    S(180, 161),    S(132, 185),    S(150, 200),    S(144, 187),    //
    S(89, 211),     S(130, 218),    S(182, 175),    S(135, 172),    S(171, 163),    S(139, 182),    S(85, 220),     S(79, 219),     //
    S(65, 195),     S(172, 144),    S(214, 118),    S(174, 106),    S(174, 130),    S(111, 171),    S(90, 201),     S(49, 233),     //
    S(28, 170),     S(87, 182),     S(98, 161),     S(85, 153),     S(108, 141),    S(74, 180),     S(56, 203),     S(9, 221),      //
    S(1, 106),      S(55, 119),     S(41, 149),     S(8, 157),      S(21, 155),     S(12, 178),     S(-6, 184),     S(-31, 186),    //
    S(5, 35),       S(80, 50),      S(60, 82),      S(34, 101),     S(42, 108),     S(26, 126),     S(21, 109),     S(-24, 123),    //
    S(-72, 29),     S(51, -12),     S(54, 29),      S(40, 69),      S(45, 67),      S(28, 80),      S(18, 67),      S(-11, 59),     //
    S(-11, -3),     S(9, 33),       S(73, 24),      S(82, 24),      S(84, 30),      S(59, 55),      S(55, 45),      S(34, 49),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(108, 221),    S(170, 213),    S(78, 356),     S(43, 412),     S(48, 423),     S(104, 311),    S(74, 265),     S(30, 282),     //
    S(71, 260),     S(69, 322),     S(42, 390),     S(-57, 477),    S(-20, 467),    S(38, 334),     S(61, 264),     S(48, 225),     //
    S(50, 264),     S(93, 294),     S(51, 379),     S(20, 404),     S(31, 415),     S(63, 332),     S(97, 225),     S(79, 192),     //
    S(41, 222),     S(46, 292),     S(5, 359),      S(7, 410),      S(26, 405),     S(28, 311),     S(68, 238),     S(51, 197),     //
    S(24, 210),     S(27, 212),     S(23, 261),     S(-4, 339),     S(-1, 374),     S(23, 306),     S(25, 251),     S(41, 170),     //
    S(19, 120),     S(55, 101),     S(47, 188),     S(19, 227),     S(29, 239),     S(27, 274),     S(46, 208),     S(29, 184),     //
    S(-17, -31),    S(21, -48),     S(26, 31),      S(50, 81),      S(46, 126),     S(48, 101),     S(23, 136),     S(36, 106),     //
    S(-46, 1),      S(-2, -187),    S(23, -165),    S(34, -58),     S(49, 11),      S(45, 6),       S(40, 17),      S(6, 83),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(124, -432),   S(480, 112),    S(434, 134),    S(66, 190),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(330, -168),   S(327, 185),    S(227, 174),    S(24, 126),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(187, 28),     S(203, 161),    S(76, 182),     S(-92, 166),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(32, 1),       S(108, 93),     S(-48, 162),    S(-165, 194),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-110, -5),    S(-36, 75),     S(-94, 140),    S(-206, 191),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-57, -28),    S(2, 37),       S(-80, 119),    S(-140, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(32, -97),     S(33, -13),     S(-33, 53),     S(-115, 113),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -204),   S(9, -91),      S(-71, -23),    S(-78, -40),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-88, -432);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -1), S(12, 15), S(12, 7), S(5, 3), S(3, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -5), S(6, 5), S(3, 2), S(3, 0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -15), S(-10, 6), S(-5, -10), S(6, -14), S(15, -30), S(8, -53), S(-4, -51), }},
  {{ S(1, 10), S(-25, 4), S(-20, 12), S(-13, 21), S(-8, 13), S(-11, -13), S(-24, -21), }},
  {{ S(-5, 3), S(-13, -5), S(-15, 21), S(-9, 21), S(-7, 10), S(-8, -14), S(-21, -54), }},
  {{ S(6, 14), S(-13, 22), S(-9, 47), S(-3, 50), S(-2, 45), S(2, 27), S(15, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 28), S(-8, 6), S(-8, 12), S(-8, 34), S(4, 52),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 16), S(-55, -119), S(-11, -40), S(1, 2), S(-4, 7), S(-7, 13), S(-6, 13), }},
  {{ S(10, 1), S(-31, -110), S(-7, -40), S(-3, -1), S(-3, -1), S(-12, 5), S(1, 5), }},
  {{ S(1, 14), S(-5, -82), S(8, -9), S(2, 9), S(-4, 15), S(-11, 21), S(-6, 23), }},
  {{ S(1, -0), S(3, -71), S(0, 26), S(-4, 35), S(-8, 13), S(-15, 10), S(-10, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1121, 870, -26, 5
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(45);
inline VParam WINNABLE_BIAS = V(-383);

// clang-format on
}  // namespace Clockwork
