#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(204, 490);
inline const PParam KNIGHT_MAT = S(861, 1512);
inline const PParam BISHOP_MAT = S(905, 1570);
inline const PParam ROOK_MAT   = S(1103, 2363);
inline const PParam QUEEN_MAT  = S(2588, 3561);

inline const PParam TEMPO_VAL  = S(52, 56);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -2);
inline const PParam BISHOP_PAIR_VAL   = S(61, 241);
inline const PParam ROOK_OPEN_VAL     = S(113, -6);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 8);
inline const PParam MINOR_BEHIND_PAWN = S(17, 44);
inline const PParam RESTRICTED_SQUARES = S(19, 8);
inline const PParam SPACE_VAL = S(81, -74);

inline const PParam DOUBLED_PAWN_VAL = S(-18, -85);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -42);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 54);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -45);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, -9), S(40, 26), S(52, 73), S(122, 208), S(440, 381), S(564, 641),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 23), S(42, 21), S(42, 68), S(88, 178), S(408, 111),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -249), S(-92, -210), S(-59, -82), S(-15, 43), S(75, 220), S(219, 434),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-72, 49), S(-92, 40), S(-51, 97), S(-91, 221), S(-65, 336), S(51, 227),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-3, 57), S(-14, 53), S(-61, 106), S(-20, 122), S(82, 147), S(43, 195),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -39), S(20, 2), S(14, 36), S(24, 96), S(74, 262), S(314, 259),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(7, -29), S(-1, 13), S(-12, -19), S(-8, -60), S(-15, -171), S(-187, -459),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(23, 222), S(8, 172), S(2, 97), S(14, 56), S(26, 61), S(61, 55), S(69, 28),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-121, -58), S(18, -8), S(3, 98), S(31, 144), S(45, 182), S(56, 190), S(41, 169),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-114, -359), S(-38, -95), S(-7, 24), S(13, 76), S(36, 113), S(50, 153), S(69, 159), S(87, 164), S(107, 117),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-88, -287), S(-26, -65), S(30, 16), S(49, 82), S(67, 129), S(79, 161), S(85, 185), S(87, 205), S(91, 214), S(97, 221), S(110, 209), S(115, 197), S(121, 199), S(80, 165),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(90, -102), S(9, 108), S(30, 142), S(46, 161), S(57, 180), S(61, 193), S(65, 210), S(70, 217), S(75, 229), S(80, 237), S(84, 243), S(83, 252), S(86, 257), S(93, 241), S(107, 208),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-175, -96), S(-20, 15), S(4, 177), S(22, 333), S(42, 375), S(50, 427), S(55, 472), S(58, 499), S(61, 526), S(63, 544), S(67, 557), S(73, 560), S(76, 569), S(81, 568), S(82, 571), S(84, 571), S(80, 574), S(81, 565), S(82, 560), S(91, 547), S(75, 545), S(101, 501), S(65, 534), S(23, 528), S(2, 507), S(-40, 538), S(-19, 491), S(-12, 431),
};

inline const PParam PAWN_THREAT_KNIGHT = S(203, 157);
inline const PParam PAWN_THREAT_BISHOP = S(169, 230);
inline const PParam PAWN_THREAT_ROOK   = S(198, 143);
inline const PParam PAWN_THREAT_QUEEN  = S(159, 30);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(11, 50), S(99, 89), S(106, 118), S(191, 75), S(178, 9), }},
  {{ S(4, 62), S(89, 94), S(101, 121), S(205, 598), S(138, -32), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(14, 59), S(51, 106), S(70, 101), S(23, 11), S(171, -80), }},
  {{ S(-5, 57), S(56, 88), S(95, 73), S(7, 23), S(416, 612), }},
}};
inline const PParam KING_THREAT  = S(3, 152);
inline const PParam HANGING_PAWN  = S(31, 94);
inline const PParam HANGING_NON_PAWN  = S(74, 32);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(22, -17), S(95, -75),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(50, 34), S(211, -235),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(41, 8), S(128, -112),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -18), S(4, -16), S(0, -22), S(-6, -29), S(-13, -36), S(-19, -40), S(-21, -49), S(-27, -45), S(-27, -92),
};

inline const PParam ROOK_LINEUP = S(16, 88);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(195, 278),    S(63, 401),     S(72, 390),     S(178, 270),    S(186, 193),    S(155, 219),    S(137, 244),    S(227, 199),    //
    S(55, 68),      S(52, 115),     S(34, 71),      S(39, 13),      S(29, -24),     S(7, -0),       S(8,42),       S(-16, 66),     //
    S(36, 0),       S(8, 7),        S(28, -22),     S(-1, -36),     S(-17, -50),    S(-23, -46),    S(-48, -31),    S(-45, 10),     //
    S(-10, -60),    S(-37, -31),    S(-7, -46),     S(-27, -56),    S(-50, -65),    S(-52, -55),    S(-93, -43),    S(-88, -38),    //
    S(-22, -94),    S(8, -87),      S(-4, -25),     S(-21, -33),    S(-45, -44),    S(-67, -47),    S(-96, -50),    S(-102, -53),   //
    S(3, -91),      S(80, -75),     S(84, -30),     S(31, 2),       S(1, -23),      S(-26, -44),    S(-64, -36),    S(-78, -36),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-296, -444),  S(-243, 55),    S(-292, 133),   S(27, 52),      S(-72, 62),     S(-301, 135),   S(-334, 118),   S(-387, -358),  //
    S(2, 18),       S(-8, 53),      S(84, 33),      S(83, 90),      S(95, 70),      S(49, 45),      S(-9, 39),      S(-54, 47),     //
    S(35, -7),      S(44, 44),      S(49, 74),      S(73, 94),      S(57, 92),      S(12, 83),      S(-4, 60),      S(-45, 26),     //
    S(82, 50),      S(88, 65),      S(90, 92),      S(99, 129),     S(100, 121),    S(66, 89),      S(45, 49),      S(16, 62),      //
    S(69, 40),      S(91, 22),      S(99, 62),      S(83, 104),     S(78, 101),     S(60, 88),      S(47, 40),      S(13, 37),      //
    S(11, -28),     S(41, -17),     S(46, 35),      S(56, 72),      S(50, 74),      S(22, 33),      S(5,1),        S(-36, -26),    //
    S(25, -1),      S(20, 23),      S(19, -8),      S(29, 25),      S(24, 25),      S(-5, -24),     S(-49, 24),     S(-68, -62),    //
    S(-66, -68),    S(-4, -11),     S(14, -17),     S(31, -7),      S(15, 0),       S(-27, -29),    S(-42, 7),      S(-102, -108),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-121, 21),    S(-227, 145),   S(-405, 216),   S(-272, 136),   S(-280, 155),   S(-260, 166),   S(-194, 135),   S(-153, 127),   //
    S(-39, 18),     S(-77, 125),    S(-56, 102),    S(-63, 98),     S(-60, 106),    S(-38, 77),     S(-22, 72),     S(-64, 61),     //
    S(40, 44),      S(17, 82),      S(27, 95),      S(22, 87),      S(23, 69),      S(13, 84),      S(-7, 81),      S(13, 25),      //
    S(7, 24),       S(45, 55),      S(60, 61),      S(79, 87),      S(92, 81),      S(35, 57),      S(31, 41),      S(-10, 32),     //
    S(32, -10),     S(33, 39),      S(69, 45),      S(84, 64),      S(71, 72),      S(55, 63),      S(8,44),       S(-4, 2),       //
    S(46, 9),       S(75, 4),       S(87, 34),      S(58, 60),      S(51, 52),      S(47, 48),      S(50, 29),      S(13, 3),       //
    S(20, -37),     S(108, -33),    S(53, 16),      S(36, 32),      S(23, 30),      S(36, -14),     S(39, -26),     S(25, -11),     //
    S(24, -34),     S(13, 6),       S(15, 28),      S(29, 6),       S(13, 12),      S(26, 46),      S(30, 18),      S(23, -26),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(162, 174),    S(184, 193),    S(148, 224),    S(138, 186),    S(185, 158),    S(135, 184),    S(153, 198),    S(146, 186),    //
    S(90, 211),     S(131, 218),    S(186, 173),    S(138, 171),    S(174, 162),    S(139, 184),    S(86, 219),     S(79, 219),     //
    S(66, 195),     S(175, 142),    S(216, 117),    S(175, 107),    S(176, 127),    S(111, 172),    S(92, 199),     S(50, 233),     //
    S(29, 171),     S(89, 181),     S(100, 161),    S(87, 153),     S(108, 142),    S(74, 180),     S(56, 203),     S(10, 221),     //
    S(2, 106),      S(57, 117),     S(42, 150),     S(9, 156),      S(21, 156),     S(12, 179),     S(-5, 183),     S(-31, 187),    //
    S(4, 37),       S(81, 50),      S(60, 83),      S(35, 101),     S(42, 108),     S(25, 126),     S(21, 109),     S(-24, 123),    //
    S(-71, 29),     S(51, -11),     S(54, 29),      S(40, 69),      S(46, 65),      S(29, 79),      S(19, 66),      S(-11, 59),     //
    S(-11, -3),     S(10, 33),      S(74, 24),      S(82, 24),      S(84, 31),      S(59, 55),      S(55, 46),      S(35, 50),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(109, 219),    S(173, 206),    S(79, 355),     S(42, 415),     S(44, 430),     S(104, 311),    S(72, 266),     S(28, 283),     //
    S(71, 259),     S(72, 320),     S(45, 390),     S(-52, 476),    S(-16, 467),    S(40, 333),     S(62, 263),     S(48, 224),     //
    S(51, 263),     S(95, 294),     S(53, 382),     S(22, 404),     S(34, 415),     S(64, 331),     S(98, 223),     S(78, 192),     //
    S(43, 221),     S(49, 288),     S(7, 357),      S(8, 412),      S(28, 406),     S(29, 310),     S(70, 233),     S(52, 193),     //
    S(26, 209),     S(29, 210),     S(25, 260),     S(-2, 339),     S(0, 374),      S(24, 306),     S(25, 250),     S(42, 166),     //
    S(21, 116),     S(55, 102),     S(47, 189),     S(19, 227),     S(29, 239),     S(26, 274),     S(46, 207),     S(29, 184),     //
    S(-17, -30),    S(21, -48),     S(26, 32),      S(50, 81),      S(45, 126),     S(46, 102),     S(22, 138),     S(37, 104),     //
    S(-47, 0),      S(-1, -190),    S(24, -165),    S(34, -60),     S(49, 11),      S(45, 5),       S(40, 17),      S(7, 82),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(128, -435),   S(488, 110),    S(441, 133),    S(71, 190),     S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
    S(336, -170),   S(334, 183),    S(234, 171),    S(30, 125),     S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
    S(189, 26),     S(206, 160),    S(78, 183),     S(-88, 167),    S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
    S(31, 3),       S(107, 93),     S(-46, 162),    S(-162, 195),   S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
    S(-113, -4),    S(-38, 75),     S(-95, 142),    S(-201, 190),   S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
    S(-62, -26),    S(-3, 39),      S(-81, 120),    S(-136, 159),   S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
    S(29, -94),     S(29, -10),     S(-33, 54),     S(-111, 112),   S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
    S(-18, -202),   S(8, -89),      S(-70, -23),    S(-74, -42),    S(0, 0),        S(0, 0),        S(0,0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-87, -432);
inline const PParam KS_TEMPO = S(11, -4);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -1), S(12, 15), S(12, 7), S(5, 3), S(3, -8),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -5), S(6, 6), S(3, 2), S(3, 0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -14), S(-11, 7), S(-7, -9), S(4, -12), S(12, -29), S(6, -54), S(-6, -50), }},
  {{ S(0, 11), S(-26, 4), S(-22, 14), S(-14, 23), S(-9, 14), S(-11, -15), S(-23, -24), }},
  {{ S(-6, 3), S(-14, -5), S(-17, 22), S(-10, 23), S(-9, 11), S(-9, -14), S(-23, -54), }},
  {{ S(5, 14), S(-12, 21), S(-9, 47), S(-3, 51), S(-2, 45), S(2, 25), S(13, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 29), S(-9, 6), S(-10, 12), S(-10, 35), S(2, 54),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 16), S(-54, -116), S(-11, -41), S(0, 3), S(-5, 7), S(-8, 13), S(-7, 12), }},
  {{ S(9, 2), S(-30, -113), S(-6, -45), S(-4, -1), S(-4, -1), S(-13, 5), S(-1, 5), }},
  {{ S(-1, 14), S(-4, -85), S(9, -12), S(2, 8), S(-5, 15), S(-12, 21), S(-7, 23), }},
  {{ S(-1, 1), S(3, -74), S(-0, 26), S(-4, 35), S(-9, 14), S(-16, 10), S(-11, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1148, 858, -27, 3
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(44);
inline VParam WINNABLE_BIAS = V(-377);

// Epoch duration: 4.54468s
// clang-format on
}  // namespace Clockwork
