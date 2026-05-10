#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(189, 451);
inline const PParam KNIGHT_MAT = S(810, 1367);
inline const PParam BISHOP_MAT = S(862, 1390);
inline const PParam ROOK_MAT   = S(1052, 2294);
inline const PParam QUEEN_MAT  = S(2542, 3729);
inline const PParam TEMPO_VAL  = S(63, 23);

inline const PParam BISHOP_XRAY_PAWNS   = S(-12, 18);
inline const PParam BISHOP_PAIR_VAL   = S(57, 224);
inline const PParam ROOK_OPEN_VAL     = S(120, -20);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 32);
inline const PParam MINOR_BEHIND_PAWN = S(13, 43);
inline const PParam RESTRICTED_SQUARES = S(-24, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-18, -82);
inline const PParam ISOLATED_PAWN_VAL = S(-16, -27);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 59);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 41);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(46, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -32);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 1), S(32, 34), S(60, 61), S(127, 175), S(429, 250), S(583, 627),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 42), S(44, 37), S(61, 65), S(121, 167), S(469, 86),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -239), S(-94, -201), S(-72, -74), S(-25, 44), S(75, 216), S(231, 327),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -41), S(20, 1), S(11, 40), S(7, 121), S(87, 229), S(182, 394),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(9, -25), S(1, 18), S(3, -17), S(5, -47), S(-6, -139), S(-206, -263),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 216), S(-12, 182), S(-8, 101), S(4, 56), S(18, 53), S(60, 49), S(47, 39),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-223, -51), S(-7, 39), S(0, 107), S(38, 136), S(51, 167), S(63, 174), S(37, 169),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-59, -296), S(-57, -231), S(-22, 10), S(13, 35), S(43, 55), S(62, 84), S(85, 83), S(110, 82), S(145, 5),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-36, -208), S(-9, -155), S(9, -77), S(37, -26), S(61, 11), S(72, 41), S(82, 63), S(90, 79), S(93, 95), S(107, 88), S(114, 91), S(149, 45), S(151, 41), S(167, -37),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(3, -43), S(23, -17), S(46, -5), S(59, 14), S(66, 26), S(73, 39), S(79, 56), S(86, 59), S(92, 72), S(99, 76), S(104, 80), S(107, 86), S(109, 90), S(113, 71), S(189, -38),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-78, -238), S(-14, -82), S(-23, 79), S(0, 158), S(12, 213), S(20, 264), S(29, 289), S(35, 313), S(39, 339), S(44, 353), S(47, 367), S(52, 375), S(58, 377), S(61, 381), S(64, 381), S(61, 383), S(64, 375), S(69, 367), S(76, 347), S(78, 340), S(81, 316), S(93, 283), S(65, 304), S(50, 260), S(38, 255), S(7, 247), S(-44, 274), S(-28, 201),
};

inline const std::array<PParam, 2> KNIGHT_REACH_FACTOR = {
    S(15, 27), S(19, -10),
};
inline const std::array<PParam, 2> BISHOP_REACH_FACTOR = {
    S(6, 28), S(17, 24),
};
inline const std::array<PParam, 2> ROOK_REACH_FACTOR = {
    S(12, 11), S(15, 27),
};
inline const std::array<PParam, 2> QUEEN_REACH_FACTOR = {
    S(9, 15), S(23, 1),
};

inline const PParam PAWN_THREAT_KNIGHT = S(201, 124);
inline const PParam PAWN_THREAT_BISHOP = S(186, 175);
inline const PParam PAWN_THREAT_ROOK   = S(199, 130);
inline const PParam PAWN_THREAT_QUEEN  = S(169, 16);

inline const PParam KNIGHT_THREAT_BISHOP = S(106, 116);
inline const PParam KNIGHT_THREAT_ROOK   = S(217, 80);
inline const PParam KNIGHT_THREAT_QUEEN  = S(151, 8);

inline const PParam BISHOP_THREAT_KNIGHT = S(94, 75);
inline const PParam BISHOP_THREAT_ROOK   = S(205, 144);
inline const PParam BISHOP_THREAT_QUEEN  = S(171, 98);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -23), S(2, -5), S(-1, -13), S(-4, -24), S(-8, -33), S(-11, -40), S(-12, -52), S(-16, -53), S(-23, -62),
};

inline const PParam ROOK_LINEUP = S(17, 70);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(208, 227),    S(52, 315),     S(116, 257),    S(144, 210),    S(181, 139),    S(96, 216),     S(73, 258),     S(224, 199),    //
    S(27, 50),      S(27, 87),      S(15, 18),      S(25, -52),     S(12, -79),     S(-21, -22),    S(-26, 36),     S(-40, 64),     //
    S(17, -16),     S(-9, -10),     S(17, -58),     S(7, -86),      S(-3, -99),     S(-25, -70),    S(-64, -23),    S(-60, 10),     //
    S(-16, -76),    S(-40, -50),    S(-14, -73),    S(-20, -83),    S(-40, -89),    S(-53, -68),    S(-103, -34),   S(-92, -40),    //
    S(-4, -110),    S(28, -110),    S(15, -51),     S(-1, -58),     S(-28, -67),    S(-43, -63),    S(-81, -50),    S(-85, -55),    //
    S(17, -104),    S(96, -104),    S(76, -52),     S(39, -21),     S(12, -46),     S(-13, -54),    S(-47, -38),    S(-69, -36),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-304, -444),  S(-281, 42),    S(-303, -73),   S(-4, 35),      S(-103, 42),    S(-261, 51),    S(-412, 114),   S(-390, -329),  //
    S(-46, -7),     S(-36, 29),     S(73, 3),       S(62, 48),      S(77, 33),      S(24, 19),      S(-50, 23),     S(-57, -1),     //
    S(29, -26),     S(28, 19),      S(62, 63),      S(65, 80),      S(45, 90),      S(-0, 86),      S(-8, 23),      S(-51, 8),      //
    S(89, 20),      S(93, 51),      S(98, 79),      S(91, 121),     S(95, 116),     S(65, 90),      S(44, 47),      S(25, 29),      //
    S(59, 12),      S(101, 8),      S(94, 62),      S(64, 95),      S(53, 93),      S(64, 74),      S(52, 12),      S(2, 21),       //
    S(29, -34),     S(57, -18),     S(64, 19),      S(61, 55),      S(55, 52),      S(34, 20),      S(22, -11),     S(-27, -47),    //
    S(41, -29),     S(48, -23),     S(36, -31),     S(42, 4),       S(31, 2),       S(19, -53),     S(-20, -20),    S(-38, -115),   //
    S(-42, -108),   S(-6, -45),     S(13, -54),     S(33, -47),     S(12, -31),     S(-16, -63),    S(-27, -54),    S(-71, -153),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-155, 2),     S(-188, 77),    S(-501, 167),   S(-322, 79),    S(-332, 103),   S(-333, 97),    S(-216, 83),    S(-155, 29),    //
    S(-63, -26),    S(-102, 92),    S(-64, 38),     S(-113, 71),    S(-104, 62),    S(-66, 36),     S(-31, 36),     S(-60, -14),    //
    S(22, -2),      S(9, 47),       S(16, 54),      S(4, 48),       S(-4, 32),      S(-7, 39),      S(9, 28),       S(4, -21),      //
    S(-2, -22),     S(47, 9),       S(60, 27),      S(62, 66),      S(89, 53),      S(40, 20),      S(39, -6),      S(-11, -28),    //
    S(41, -80),     S(48, -12),     S(74, 3),       S(82, 31),      S(70, 41),      S(61, 23),      S(18, 2),       S(8, -60),      //
    S(58, -52),     S(89, -28),     S(96, -2),      S(72, 16),      S(66, 3),       S(66, 8),       S(70, -9),      S(9, -42),      //
    S(50, -89),     S(134, -49),    S(93, -30),     S(64, -9),      S(52, -8),      S(67, -48),     S(67, -46),     S(47, -80),     //
    S(47, -117),    S(15, -46),     S(4, -30),      S(39, -57),     S(22, -48),     S(26, -29),     S(39, -48),     S(33, -97),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(184, 72),     S(216, 76),     S(164, 91),     S(148, 71),     S(206, 43),     S(153, 76),     S(177, 87),     S(159, 97),     //
    S(86, 149),     S(143, 147),    S(210, 95),     S(139, 122),    S(186, 106),    S(146, 125),    S(90, 157),     S(82, 160),     //
    S(53, 132),     S(173, 84),     S(195, 57),     S(166, 45),     S(162, 66),     S(103, 110),    S(111, 115),    S(56, 155),     //
    S(31, 88),      S(98, 97),      S(115, 69),     S(83, 69),      S(116, 53),     S(75, 102),     S(74, 107),     S(13, 132),     //
    S(3, 16),       S(76, 24),      S(49, 40),      S(13, 43),      S(25, 48),      S(14, 77),      S(0, 76),       S(-18, 76),     //
    S(20, -64),     S(95, -45),     S(66, -29),     S(42, -25),     S(52, -20),     S(25, 15),      S(39, -5),      S(-12, 8),      //
    S(-68, -54),    S(69, -95),     S(59, -63),     S(45, -32),     S(51, -32),     S(37, -18),     S(27, -32),     S(-8, -20),     //
    S(8, -69),      S(27, -39),     S(61, -53),     S(75, -56),     S(72, -42),     S(51, -20),     S(53, -29),     S(26, -24),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(35, 140),     S(146, 59),     S(55, 171),     S(-5, 257),     S(27, 229),     S(56, 163),     S(55, 102),     S(-20, 165),    //
    S(37, 182),     S(41, 257),     S(14, 279),     S(-125, 370),   S(-82, 371),    S(-27, 290),    S(19, 184),     S(6, 168),      //
    S(14, 189),     S(33, 264),     S(-1, 315),     S(-47, 339),    S(-32, 338),    S(20, 258),     S(55, 172),     S(58, 90),      //
    S(30, 93),      S(17, 195),     S(-26, 265),    S(-44, 326),    S(-31, 351),    S(10, 223),     S(55, 136),     S(32, 115),     //
    S(22, 79),      S(16, 116),     S(-10, 183),    S(-37, 258),    S(-22, 289),    S(2, 229),      S(20, 145),     S(37, 72),      //
    S(29, -6),      S(46, 26),      S(35, 110),     S(16, 125),     S(23, 149),     S(28, 179),     S(46, 119),     S(33, 68),      //
    S(22, -138),    S(45, -103),    S(38, -34),     S(58, -4),      S(51, 43),      S(55, 23),      S(31, 45),      S(40, 19),      //
    S(-4, -83),     S(17, -258),    S(31, -243),    S(53, -153),    S(48, -48),     S(52, -96),     S(47, -62),     S(9, -6),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(41, -314),    S(325, 299),    S(213, 325),    S(-16, 224),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(247, -10),    S(268, 274),    S(117, 314),    S(-11, 209),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(144, 112),    S(166, 233),    S(58, 277),     S(-60, 224),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-34, 56),     S(57, 153),     S(-84, 234),    S(-145, 247),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-116, -18),   S(-50, 73),     S(-140, 155),   S(-245, 226),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-35, -68),    S(11, 2),       S(-100, 97),    S(-177, 162),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(22, -126),    S(28, -48),     S(-55, 16),     S(-116, 69),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-10, -229),   S(20, -121),    S(-64, -57),    S(-50, -70),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-84, -537);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -6), S(14, -23), S(13, -3), S(6, -9), S(1, -27),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -11), S(6, -23), S(4, -13), S(4, -1), S(4, 4),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -5);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, 22), S(-6, 32), S(-4, -55), S(6, -43), S(7, -29), S(-12, 6), S(-24, -0), }},
  {{ S(-2, 127), S(-20, -259), S(-20, -43), S(-9, 33), S(-8, 58), S(-22, 92), S(-40, 86), }},
  {{ S(-4, 112), S(-9, -238), S(-9, 106), S(-4, 77), S(-4, 71), S(-15, 73), S(-43, 44), }},
  {{ S(5, 117), S(-10, 84), S(-1, 89), S(5, 72), S(3, 60), S(5, 70), S(-0, 68), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(14, 121), S(-7, 80), S(-10, 99), S(-4, 109), S(14, 69),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 145), S(-56, -439), S(-12, -352), S(7, -357), S(-5, 60), S(-9, 82), S(-8, 83), }},
  {{ S(8, 52), S(-29, -516), S(-1, -429), S(-4, -30), S(-3, 10), S(-9, 35), S(0, 28), }},
  {{ S(-0, 80), S(-11, -422), S(4, -6), S(2, 10), S(-3, 42), S(-10, 62), S(-5, 54), }},
  {{ S(-0, 72), S(-3, -128), S(6, -13), S(4, 31), S(-6, 51), S(-14, 60), S(-10, 63), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1145, 284, -14, 76
);

inline VParam WINNABLE_PAWNS = V(-24);
inline VParam WINNABLE_SYM = V(130);
inline VParam WINNABLE_ASYM = V(113);
inline VParam WINNABLE_PAWN_ENDGAME = V(188);
inline VParam WINNABLE_BIAS = V(-513);

// Epoch duration: 7.97597s
// clang-format on
}  // namespace Clockwork
