#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(180, 471);
inline const PParam KNIGHT_MAT = S(796, 1458);
inline const PParam BISHOP_MAT = S(833, 1555);
inline const PParam ROOK_MAT   = S(1007, 2470);
inline const PParam QUEEN_MAT  = S(2410, 4407);
inline const PParam TEMPO_VAL  = S(61, 25);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 14);
inline const PParam BISHOP_PAIR_VAL   = S(59, 229);
inline const PParam ROOK_OPEN_VAL     = S(119, -8);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 40);
inline const PParam MINOR_BEHIND_PAWN = S(17, 40);
inline const PParam RESTRICTED_SQUARES = S(-22, -8);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -76);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(3, 4);
inline const PParam OUTPOST_KNIGHT_VAL    = S(58, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(61, 31);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 8);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, -11);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 49);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -4), S(31, 33), S(56, 71), S(119, 213), S(280, 535), S(625, 667),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 43), S(42, 38), S(61, 73), S(96, 214), S(302, 339),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-91, -247), S(-86, -214), S(-60, -91), S(-9, 18), S(70, 253), S(237, 351),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -34), S(21, -2), S(9, 38), S(7, 112), S(104, 181), S(147, 408),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -29), S(10, 3), S(2, -34), S(6, -69), S(-24, -126), S(-208, -248),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(10, 217), S(-7, 177), S(-6, 102), S(3, 67), S(16, 64), S(53, 61), S(45, 40),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-160, -33), S(-7, 51), S(-5, 113), S(27, 151), S(40, 181), S(55, 184), S(34, 174),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-84, -348), S(-23, -139), S(5, -28), S(28, 15), S(56, 39), S(72, 72), S(90, 73), S(110, 75), S(128, 23),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-55, -294), S(-9, -133), S(37, -62), S(57, -5), S(78, 36), S(90, 65), S(95, 87), S(98, 104), S(102, 113), S(105, 115), S(113, 103), S(122, 85), S(129, 77), S(93, 51),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(108, -175), S(23, -9), S(44, 21), S(59, 37), S(69, 56), S(72, 70), S(77, 84), S(83, 89), S(88, 101), S(95, 107), S(102, 111), S(104, 118), S(101, 125), S(100, 109), S(127, 51),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-191, -91), S(-79, 130), S(-54, 249), S(-33, 369), S(-18, 408), S(-11, 456), S(-5, 487), S(1, 501), S(4, 525), S(7, 542), S(12, 549), S(15, 556), S(19, 559), S(19, 565), S(19, 565), S(15, 568), S(10, 568), S(10, 560), S(9, 552), S(13, 540), S(6, 527), S(6, 504), S(-27, 531), S(-68, 511), S(-100, 511), S(-137, 531), S(-197, 562), S(-158, 479),
};

inline const PParam PAWN_THREAT_KNIGHT = S(198, 140);
inline const PParam PAWN_THREAT_BISHOP = S(181, 189);
inline const PParam PAWN_THREAT_ROOK   = S(202, 135);
inline const PParam PAWN_THREAT_QUEEN  = S(168, 14);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 121);
inline const PParam KNIGHT_THREAT_ROOK   = S(217, 94);
inline const PParam KNIGHT_THREAT_QUEEN  = S(151, -10);

inline const PParam BISHOP_THREAT_KNIGHT = S(94, 85);
inline const PParam BISHOP_THREAT_ROOK   = S(206, 160);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 101);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(0, -10), S(3, -13), S(-1, -22), S(-5, -31), S(-10, -41), S(-14, -48), S(-15, -61), S(-20, -64), S(-22, -80),
};

inline const PParam ROOK_LINEUP = S(17, 73);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(198, 231),    S(34, 345),     S(67, 273),     S(127, 215),    S(174, 141),    S(105, 212),    S(71, 268),     S(221, 206),    //
    S(18, 49),      S(22, 98),      S(1, 44),       S(41, -59),     S(37, -98),     S(1, -47),      S(-9, 17),      S(-33, 53),     //
    S(23, -1),      S(-4, 20),      S(19, -12),     S(19, -77),     S(12, -102),    S(-9, -78),     S(-43, -39),    S(-47, 3),      //
    S(-15, -59),    S(-37, -21),    S(-3, -35),     S(-9, -84),     S(-24, -99),    S(-35, -82),    S(-83, -54),    S(-78, -50),    //
    S(-18, -93),    S(23, -101),    S(8, -26),      S(-4, -61),     S(-29, -72),    S(-44, -77),    S(-74, -70),    S(-80, -69),    //
    S(5, -75),      S(89, -107),    S(78, -90),     S(32, -38),     S(6, -58),      S(-15, -71),    S(-42, -57),    S(-57, -51),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-260, -503),  S(-277, 33),    S(-290, -110),  S(-9, 2),       S(-120, 31),    S(-288, 65),    S(-403, 105),   S(-351, -372),  //
    S(-28, -30),    S(-9, 9),       S(79, -12),     S(75, 13),      S(85, 5),       S(35, 4),       S(-26, 9),      S(-45, -11),    //
    S(38, -39),     S(34, 14),      S(71, 47),      S(77, 59),      S(68, 68),      S(27, 63),      S(8, 12),       S(-44, 4),      //
    S(101, 6),      S(96, 42),      S(109, 64),     S(111, 98),     S(128, 89),     S(82, 71),      S(61, 30),      S(40, 16),      //
    S(68, 15),      S(112, -3),     S(101, 56),     S(100, 76),     S(82, 74),      S(80, 67),      S(66, 4),       S(18, 17),      //
    S(11, -37),     S(39, -2),      S(40, 43),      S(55, 67),      S(50, 62),      S(23, 29),      S(13, -6),      S(-28, -52),    //
    S(32, -38),     S(31, -21),     S(19, -18),     S(24, 7),       S(22, 4),       S(-3, -42),     S(-35, -8),     S(-43, -106),   //
    S(-41, -89),    S(9, -42),      S(25, -55),     S(44, -42),     S(25, -23),     S(-10, -57),    S(-21, -38),    S(-63, -136),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-126, 17),    S(-184, 103),   S(-491, 179),   S(-320, 95),    S(-325, 119),   S(-339, 140),   S(-229, 134),   S(-125, 51),    //
    S(-44, -24),    S(-97, 83),     S(-58, 38),     S(-116, 69),    S(-102, 65),    S(-55, 41),     S(-31, 36),     S(-57, 6),      //
    S(21, 13),      S(11, 50),      S(21, 55),      S(20, 37),      S(12, 22),      S(10, 35),      S(9, 34),       S(11, -6),      //
    S(12, -13),     S(45, 12),      S(63, 24),      S(71, 53),      S(104, 41),     S(44, 13),      S(47, -14),     S(1, -18),      //
    S(48, -57),     S(50, -14),     S(80, 9),       S(95, 26),      S(81, 36),      S(75, 13),      S(24, -6),      S(22, -48),     //
    S(61, -36),     S(85, -24),     S(99, 5),       S(70, 28),      S(67, 5),       S(66, 8),       S(76, -15),     S(22, -33),     //
    S(35, -98),     S(118, -70),    S(78, -32),     S(52, -14),     S(37, -11),     S(54, -51),     S(54, -67),     S(46, -63),     //
    S(55, -86),     S(27, -32),     S(30, -14),     S(52, -33),     S(35, -28),     S(42, 6),       S(50, -26),     S(45, -62),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(192, 89),     S(225, 102),    S(176, 127),    S(176, 98),     S(230, 67),     S(181, 92),     S(206, 95),     S(182, 104),    //
    S(80, 172),     S(156, 167),    S(231, 127),    S(162, 153),    S(205, 135),    S(163, 155),    S(103, 177),    S(89, 175),     //
    S(47, 163),     S(179, 119),    S(206, 108),    S(193, 84),     S(189, 106),    S(125, 141),    S(127, 141),    S(58, 184),     //
    S(19, 125),     S(93, 143),     S(113, 125),    S(97, 122),     S(130, 101),    S(89, 137),     S(84, 141),     S(14, 159),     //
    S(-9, 51),      S(64, 66),      S(48, 91),      S(24, 85),      S(38, 86),      S(26, 110),     S(4, 109),      S(-16, 100),    //
    S(4, -37),      S(79, -7),      S(63, 19),      S(47, 13),      S(58, 11),      S(31, 41),      S(41, 16),      S(-10, 28),     //
    S(-81, -37),    S(52, -81),     S(53, -41),     S(42, -11),     S(50, -21),     S(35, -9),      S(27, -28),     S(-6, -18),     //
    S(-14, -81),    S(-1, -41),     S(66, -53),     S(76, -56),     S(76, -50),     S(55, -30),     S(54, -42),     S(37, -38),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(23, 224),     S(134, 140),    S(36, 281),     S(-26, 387),    S(12, 339),     S(44, 256),     S(38, 191),     S(-35, 251),    //
    S(26, 225),     S(44, 287),     S(11, 358),     S(-126, 469),   S(-77, 448),    S(-25, 353),    S(16, 224),     S(-13, 215),    //
    S(-4, 271),     S(10, 337),     S(-14, 395),    S(-50, 429),    S(-32, 414),    S(9, 318),      S(37, 222),     S(40, 136),     //
    S(7, 185),      S(-7, 292),     S(-38, 347),    S(-62, 424),    S(-41, 427),    S(-4, 294),     S(34, 197),     S(12, 158),     //
    S(-12, 187),    S(-18, 220),    S(-39, 286),    S(-60, 351),    S(-43, 373),    S(-17, 289),    S(-8, 211),     S(19, 110),     //
    S(-7, 77),      S(11, 108),     S(-1, 194),     S(-24, 218),    S(-12, 218),    S(-8, 241),     S(17, 163),     S(10, 116),     //
    S(-42, -62),    S(-6, -73),     S(-6, 18),      S(9, 66),       S(5, 108),      S(11, 80),      S(-12, 102),    S(4, 79),       //
    S(-50, -55),    S(-30, -208),   S(-6, -195),    S(6, -76),      S(12, -3),      S(16, -44),     S(15, -18),     S(-11, 21),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(213, -654),   S(526, -60),    S(304, 170),    S(20, 185),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(361, -212),   S(371, 91),     S(165, 229),    S(-26, 258),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(185, 36),     S(214, 164),    S(74, 275),     S(-84, 304),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-13, 15),     S(66, 136),     S(-93, 273),    S(-148, 325),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-131, -12),   S(-44, 78),     S(-143, 225),   S(-227, 312),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-55, -76),    S(3, 11),       S(-118, 174),   S(-173, 256),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(28, -163),    S(22, -62),     S(-69, 76),     S(-139, 174),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, -274),   S(1, -146),     S(-98, -18),    S(-85, 5),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-45, 55);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(5, -2), S(6, 3), S(6, 3), S(3, -1), S(2, -3),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, -1), S(2, 2), S(2, 1), S(2, -0), S(1, -0),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-2, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 2>, 4> KS_SAFE_CHECKS = {{
  {{ S(11, 6), S(11, 0), }},
  {{ S(4, 12), S(9, 22), }},
  {{ S(7, 9), S(-2, 24), }},
  {{ S(6, 3), S(15, -4), }},
}};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(8, -9), S(-6, 1), S(-4, -5), S(3, -8), S(7, -15), S(1, -20), S(-4, -20), }},
  {{ S(-3, -0), S(-16, -2), S(-13, 1), S(-7, 2), S(-5, -2), S(-10, -6), S(-16, -10), }},
  {{ S(-7, -3), S(-11, -9), S(-12, 5), S(-8, 4), S(-8, 0), S(-11, -7), S(-21, -17), }},
  {{ S(-1, 11), S(-8, 7), S(-5, 12), S(-3, 12), S(-2, 9), S(-2, 12), S(-1, 2), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(2, 18), S(-8, 6), S(-10, 10), S(-10, 19), S(-1, 18),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-1, 9), S(-19, -49), S(-1, -29), S(0, -3), S(-4, 4), S(-8, 9), S(-7, 8), }},
  {{ S(2, 3), S(-12, -43), S(4, -30), S(-2, -5), S(-2, -1), S(-8, 4), S(-2, 3), }},
  {{ S(-4, 7), S(-1, -36), S(11, -24), S(-2, 2), S(-6, 6), S(-11, 10), S(-8, 12), }},
  {{ S(-2, 1), S(11, -41), S(9, -24), S(-2, 3), S(-7, 6), S(-11, 5), S(-9, 8), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        2104, 1716, -26, -3
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(83);
inline VParam WINNABLE_PAWN_ENDGAME = V(130);
inline VParam WINNABLE_BIAS = V(-356);

// Epoch duration: 8.26069s
// clang-format on
}  // namespace Clockwork
