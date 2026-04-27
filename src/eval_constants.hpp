#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(198, 385);
inline const PParam KNIGHT_MAT = S(910, 1021);
inline const PParam BISHOP_MAT = S(951, 1068);
inline const PParam ROOK_MAT   = S(1149, 1716);
inline const PParam QUEEN_MAT  = S(2679, 2701);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 13);
inline const PParam BISHOP_PAIR_VAL   = S(53, 199);
inline const PParam ROOK_OPEN_VAL     = S(119, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 29);
inline const PParam MINOR_BEHIND_PAWN = S(12, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -85);
inline const PParam DDOUBLED_PAWN_VAL = S(-8, -40);
inline const PParam DOUBLED_PAWN_DEFENDED_VAL = S(-10, 35);
inline const PParam ISOLATED_PAWN_VAL = S(-17, -15);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 53);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(47, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 44);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -5), S(32, 26), S(61, 47), S(143, 141), S(381, 210), S(440, 528),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 31), S(46, 26), S(62, 50), S(121, 142), S(416, 82),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-108, -186), S(-108, -159), S(-79, -54), S(-21, 44), S(74, 179), S(261, 260),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -37), S(21, 3), S(14, 32), S(-0, 112), S(82, 202), S(255, 255),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -15), S(-1, 25), S(-4, -9), S(-1, -39), S(-6, -127), S(-250, -211),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 179), S(-4, 152), S(1, 85), S(8, 50), S(14, 50), S(51, 46), S(45, 27),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-273, -38), S(-11, 33), S(-4, 89), S(37, 111), S(59, 129), S(70, 134), S(49, 132),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-112, -245), S(-47, -76), S(-16, 12), S(11, 43), S(43, 59), S(59, 88), S(82, 83), S(102, 94), S(148, 6),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-76, -235), S(-29, -73), S(24, -8), S(48, 37), S(70, 69), S(82, 93), S(88, 110), S(97, 119), S(98, 135), S(115, 117), S(117, 120), S(163, 64), S(157, 73), S(189, 19),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -113), S(15, 45), S(37, 73), S(53, 83), S(64, 96), S(68, 107), S(74, 118), S(81, 120), S(85, 131), S(93, 133), S(102, 135), S(105, 140), S(109, 138), S(122, 110), S(207, 4),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-127, -82), S(14, -25), S(39, 88), S(60, 192), S(76, 231), S(84, 272), S(90, 302), S(98, 310), S(101, 331), S(104, 347), S(109, 351), S(112, 361), S(117, 359), S(117, 365), S(119, 362), S(116, 362), S(112, 363), S(116, 352), S(120, 341), S(122, 333), S(118, 319), S(136, 278), S(113, 290), S(109, 229), S(79, 224), S(72, 189), S(15, 212), S(24, 164),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 85);
inline const PParam PAWN_THREAT_BISHOP = S(197, 138);
inline const PParam PAWN_THREAT_ROOK   = S(198, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(181, -11);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -17);

inline const PParam BISHOP_THREAT_KNIGHT = S(101, 60);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(172, 91);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(14, -31), S(-1, -5), S(-3, -14), S(-7, -23), S(-12, -32), S(-15, -39), S(-17, -50), S(-23, -51), S(-38, -46),
};

inline const PParam ROOK_LINEUP = S(14, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(227, 182),    S(66, 236),     S(197, 191),    S(175, 170),    S(221, 102),    S(113, 190),    S(55, 230),     S(194, 174),    //
    S(47, 21),      S(76, 39),      S(74, 19),      S(47, -30),     S(42, -59),     S(20, -14),     S(3, 35),       S(-28, 58),     //
    S(22, -15),     S(1, -3),       S(31, -41),     S(19, -67),     S(13, -80),     S(-10, -53),    S(-56, -7),     S(-53, 13),     //
    S(-10, -62),    S(-29, -30),    S(0, -54),      S(-14, -64),    S(-37, -64),    S(-42, -47),    S(-99, -9),     S(-88, -21),    //
    S(-10, -90),    S(25, -86),     S(7, -39),      S(-6, -43),     S(-35, -50),    S(-53, -45),    S(-86, -28),    S(-86, -37),    //
    S(10, -87),     S(90, -84),     S(68, -44),     S(26, -12),     S(-3, -28),     S(-24, -39),    S(-56, -19),    S(-69, -22),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-332, -312),  S(-269, 19),    S(-252, -88),   S(-2, 14),      S(-77, 17),     S(-229, 33),    S(-397, 90),    S(-408, -204),  //
    S(-46, -9),     S(-18, 17),     S(100, -20),    S(107, -0),     S(100, 11),     S(23, 28),      S(-43, 34),     S(-66, 12),     //
    S(24, -13),     S(57, -19),     S(85, 44),      S(102, 42),     S(64, 74),      S(17, 75),      S(8, 17),       S(-40, 12),     //
    S(90, 8),       S(102, 30),     S(108, 61),     S(112, 88),     S(117, 93),     S(71, 80),      S(46, 49),      S(33, 21),      //
    S(70, 9),       S(113, -10),    S(94, 56),      S(90, 72),      S(69, 77),      S(72, 67),      S(60, 15),      S(14, 26),      //
    S(6, -22),      S(32, 0),       S(30, 42),      S(46, 60),      S(39, 59),      S(8, 44),       S(3, 7),        S(-37, -24),    //
    S(25, -19),     S(33, -16),     S(7, -0),       S(16, 20),      S(13, 18),      S(-11, -28),    S(-30, -9),     S(-44, -94),    //
    S(-50, -72),    S(-1, -12),     S(21, -40),     S(37, -35),     S(19, -15),     S(-15, -40),    S(-28, -22),    S(-69, -114),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-162, 86),    S(-163, 88),    S(-441, 141),   S(-288, 85),    S(-283, 86),    S(-311, 86),    S(-213, 85),    S(-138, 69),    //
    S(-54, 12),     S(-82, 80),     S(-41, 26),     S(-95, 52),     S(-76, 46),     S(-57, 43),     S(-20, 36),     S(-60, 20),     //
    S(22, 26),      S(17, 41),      S(35, 44),      S(24, 46),      S(0, 47),       S(8, 44),       S(9, 38),       S(5, 17),       //
    S(9, 5),        S(44, 20),      S(59, 40),      S(65, 74),      S(97, 60),      S(36, 35),      S(37, 5),       S(-9, 9),       //
    S(41, -40),     S(51, -3),      S(73, 24),      S(87, 46),      S(69, 57),      S(58, 41),      S(16, 17),      S(7, -17),      //
    S(60, -25),     S(81, -11),     S(96, 18),      S(62, 40),      S(58, 21),      S(57, 32),      S(62, 12),      S(8, 4),        //
    S(27, -58),     S(109, -41),    S(71, -18),     S(47, 2),       S(31, 5),       S(44, -26),     S(41, -33),     S(41, -41),     //
    S(50, -58),     S(31, -27),     S(27, 6),       S(46, -19),     S(31, -9),      S(35, 26),      S(45, -5),      S(41, -34),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(196, 88),     S(234, 95),     S(188, 110),    S(183, 83),     S(223, 74),     S(180, 93),     S(201, 98),     S(181, 108),    //
    S(83, 160),     S(171, 150),    S(231, 117),    S(170, 129),    S(208, 122),    S(176, 131),    S(119, 161),    S(101, 166),    //
    S(49, 157),     S(171, 130),    S(217, 90),     S(185, 92),     S(180, 114),    S(136, 137),    S(138, 140),    S(75, 171),     //
    S(17, 132),     S(108, 124),    S(136, 99),     S(108, 112),    S(141, 99),     S(95, 136),     S(99, 133),     S(24, 161),     //
    S(-6, 65),      S(75, 66),      S(65, 81),      S(33, 87),      S(42, 99),      S(34, 118),     S(8, 117),      S(-9, 113),     //
    S(9, -8),       S(84, 11),      S(74, 25),      S(50, 28),      S(62, 33),      S(30, 67),      S(39, 44),      S(-2, 54),      //
    S(-86, -3),     S(55, -40),     S(60, -18),     S(49, 4),       S(51, 9),       S(39, 19),      S(29, 7),       S(-2, 21),      //
    S(-23, -18),    S(4, 1),        S(63, -13),     S(74, -18),     S(73, -6),      S(53, 12),      S(49, 7),       S(28, 14),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(89, 112),     S(186, 47),     S(113, 141),    S(51, 229),     S(88, 187),     S(82, 171),     S(110, 84),     S(35, 149),     //
    S(69, 169),     S(81, 254),     S(54, 269),     S(-74, 340),    S(-30, 328),    S(12, 289),     S(59, 180),     S(35, 182),     //
    S(38, 204),     S(62, 260),     S(31, 314),     S(-1, 316),     S(6, 324),      S(56, 251),     S(76, 188),     S(84, 109),     //
    S(58, 101),     S(58, 185),     S(11, 251),     S(-5, 312),     S(8, 326),      S(43, 216),     S(85, 146),     S(57, 124),     //
    S(60, 69),      S(42, 134),     S(22, 188),     S(-3, 251),     S(11, 275),     S(27, 228),     S(51, 144),     S(69, 79),      //
    S(52, 2),       S(66, 46),      S(61, 119),     S(43, 127),     S(46, 150),     S(47, 184),     S(66, 123),     S(59, 78),      //
    S(26, -109),    S(40, -54),     S(47, -7),      S(76, 15),      S(66, 64),      S(67, 43),      S(37, 85),      S(57, 51),      //
    S(10, -98),     S(33, -215),    S(61, -213),    S(77, -115),    S(71, -22),     S(77, -64),     S(72, -34),     S(47, -10),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-63, -205),   S(302, 244),    S(204, 224),    S(72, 119),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(235, 23),     S(320, 205),    S(187, 219),    S(134, 98),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(179, 84),     S(234, 169),    S(154, 184),    S(104, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(12, 35),      S(133, 99),     S(17, 152),     S(-12, 164),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-90, -16),    S(-2, 50),      S(-60, 104),    S(-145, 166),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -47),    S(29, 7),       S(-63, 76),     S(-114, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -87),     S(29, -25),     S(-45, 23),     S(-108, 71),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -174),   S(1, -87),      S(-81, -46),    S(-75, -58),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -563);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -26), S(14, -26), S(14, -7), S(5, -10), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -28), S(4, -18), S(4, -2), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 43), S(-3, 55), S(-1, -16), S(10, -27), S(9, -22), S(-2, -6), S(-2, 56), }},
  {{ S(-1, 166), S(-19, -252), S(-20, 2), S(-7, 51), S(-7, 68), S(-19, -6), S(-18, -237), }},
  {{ S(-3, 145), S(-8, -240), S(-9, 130), S(-3, 112), S(-2, 110), S(-9, 135), S(-8, -216), }},
  {{ S(8, 125), S(-10, 81), S(2, 91), S(8, 70), S(7, 73), S(-0, 91), S(-6, 80), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 60), S(-11, 54), S(-10, 80), S(-2, 84), S(4, 30),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 120), S(-8, 37), S(-9, 37), S(-6, 36), S(-6, 32), S(-8, 37), S(-9, 48), }},
  {{ S(9, 5), S(1, -34), S(-8, -22), S(-3, -54), S(-4, -56), S(-7, -25), S(1, -27), }},
  {{ S(1, 61), S(-4, 34), S(-7, 38), S(-4, 36), S(-3, 19), S(-7, 34), S(-3, 23), }},
  {{ S(-0, 58), S(-7, 36), S(-11, 37), S(-5, 46), S(-4, 47), S(-10, 32), S(-8, 36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1076, 248, -14, 94
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(136);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 5.55034s
// clang-format on
}  // namespace Clockwork
