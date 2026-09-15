#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(207, 518);
inline const PParam KNIGHT_MAT = S(782, 1615);
inline const PParam BISHOP_MAT = S(844, 1697);
inline const PParam ROOK_MAT   = S(1011, 2695);
inline const PParam QUEEN_MAT  = S(2546, 4337);

inline const PParam TEMPO_VAL  = S(69, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 4);
inline const PParam BISHOP_PAIR_VAL   = S(56, 239);
inline const PParam ROOK_OPEN_VAL     = S(113, -8);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 19);
inline const PParam MINOR_BEHIND_PAWN = S(13, 35);
inline const PParam RESTRICTED_SQUARES = S(20, 8);

inline const PParam DOUBLED_PAWN_VAL = S(-23, -85);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(48, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(36, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(34, 56);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 71);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -0), S(34, 33), S(60, 67), S(111, 222), S(400, 411), S(695, 836),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 33), S(40, 26), S(53, 58), S(96, 182), S(429, 109),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-94, -257), S(-97, -215), S(-69, -79), S(-15, 46), S(95, 217), S(238, 421),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-91, 61), S(-91, 38), S(-43, 98), S(-62, 218), S(-15, 321), S(95, 195),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-27, 66), S(-30, 57), S(-51, 98), S(-18, 123), S(94, 142), S(49, 192),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(22, -39), S(22, -1), S(13, 37), S(17, 110), S(66, 278), S(335, 224),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(8, -38), S(3, 4), S(-5, -33), S(-3, -78), S(-16, -186), S(-206, -454),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(27, 233), S(7, 188), S(3, 108), S(12, 66), S(23, 66), S(62, 58), S(64, 28),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-166, -13), S(6, 15), S(1, 107), S(36, 144), S(51, 182), S(60, 193), S(43, 175),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-27, -324), S(3, -106), S(18, -20), S(33, 12), S(49, 39), S(56, 77), S(64, 94), S(73, 120), S(84, 92),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-79, -288), S(-24, -78), S(26, -8), S(50, 30), S(68, 55), S(79, 73), S(83, 83), S(83, 97), S(86, 102), S(90, 107), S(97, 99), S(105, 89), S(100, 92), S(78, 67),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(92, -168), S(18, 10), S(39, 38), S(54, 53), S(64, 64), S(67, 71), S(70, 79), S(75, 79), S(78, 87), S(82, 93), S(84, 97), S(80, 106), S(77, 111), S(74, 103), S(86, 70),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-178, -90), S(-43, 9), S(-19, 109), S(-4, 221), S(12, 241), S(18, 279), S(24, 304), S(30, 314), S(34, 333), S(38, 345), S(42, 354), S(46, 359), S(49, 365), S(51, 369), S(51, 373), S(51, 376), S(47, 377), S(51, 369), S(52, 365), S(57, 356), S(47, 350), S(63, 323), S(36, 342), S(-8, 342), S(-44, 348), S(-62, 362), S(-128, 397), S(-90, 347),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-23, -11), S(7, 3), S(18, 22), S(29, 26), S(36, 39), S(40, 50), S(45, 56), S(48, 56), S(51, 57), S(55, 53), S(58, 49), S(60, 47), S(61, 41), S(66, 29), S(71, 15), S(70, 5), S(75, -15), S(80, -33), S(85, -45), S(79, -62), S(43, -104),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(50, -29), S(46, -30), S(50, -20), S(54, -1), S(52, 12), S(53, 16), S(51, 25), S(50, 32), S(47, 40), S(47, 46), S(46, 51), S(47, 57), S(48, 62), S(50, 64), S(57, 64), S(61, 61), S(62, 64), S(32, 71),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(64, -7), S(61, 9), S(62, 16), S(65, 23), S(69, 24), S(72, 29), S(74, 33), S(75, 41), S(74, 52), S(75, 56), S(71, 68), S(71, 77), S(67, 88), S(65, 96), S(63, 100), S(57, 109), S(53, 119), S(46, 130), S(43, 132), S(28, 145),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(-8, 142), S(-13, 182), S(-4, 226), S(3, 247), S(7, 255), S(10, 271), S(11, 278), S(14, 288), S(14, 292), S(19, 287), S(18, 294), S(16, 303), S(20, 300), S(22, 297), S(26, 293), S(27, 291), S(30, 280), S(41, 268), S(47, 247), S(45, 259), S(66, 221), S(81, 195), S(102, 137),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(2, 8), S(3, 5), S(13, 2), S(-1, 24),
};

inline const PParam PAWN_THREAT_KNIGHT = S(198, 172);
inline const PParam PAWN_THREAT_BISHOP = S(173, 234);
inline const PParam PAWN_THREAT_ROOK   = S(188, 166);
inline const PParam PAWN_THREAT_QUEEN  = S(161, 27);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(14, 61), S(91, 120), S(107, 128), S(182, 112), S(161, 47), }},
  {{ S(11, 60), S(80, 117), S(106, 127), S(220, 649), S(133, 112), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(15, 70), S(41, 131), S(55, 141), S(12, 20), S(155, -69), }},
  {{ S(7, 56), S(57, 105), S(94, 99), S(24, 16), S(381, 892), }},
}};
inline const PParam KING_THREAT  = S(-28, 146);
inline const PParam REACH_THREAT = S(-15, 16);
inline const PParam REACH_THREAT_LOOSE = S(15, 34);
inline const PParam REACH_THREAT_TWICE = S(9, 43);
inline const PParam HANGING_PAWN  = S(38, 95);
inline const PParam HANGING_NON_PAWN  = S(82, 44);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(18, -19), S(30, -19),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(40, 29), S(99, -109),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(35, -8), S(43, -1),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -17), S(2, -13), S(-2, -18), S(-7, -25), S(-12, -32), S(-17, -37), S(-19, -48), S(-25, -49), S(-31, -67),
};

inline const PParam ROOK_LINEUP = S(16, 71);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(186, 291),    S(53, 404),     S(98, 379),     S(165, 273),    S(195, 168),    S(135, 227),    S(110, 259),    S(215, 202),    //
    S(34, 73),      S(34, 129),     S(28, 64),      S(36, -9),      S(27, -47),     S(0, -8),       S(-7, 48),      S(-30, 68),     //
    S(31, -7),      S(7, 1),        S(34, -43),     S(18, -71),     S(10, -87),     S(-7, -66),     S(-49, -25),    S(-45, 11),     //
    S(-2, -75),     S(-25, -52),    S(4, -65),      S(-5, -81),     S(-27, -86),    S(-35, -69),    S(-82, -46),    S(-76, -43),    //
    S(-11, -115),   S(22, -114),    S(8, -42),      S(-8, -50),     S(-34, -58),    S(-49, -62),    S(-79, -61),    S(-83, -65),    //
    S(12, -116),    S(91, -110),    S(71, -44),     S(34, -7),      S(5, -27),      S(-18, -50),    S(-47, -45),    S(-64, -48),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-273, -527),  S(-276, 32),    S(-266, -56),   S(-7, 52),      S(-110, 63),    S(-279, 82),    S(-370, 101),   S(-356, -437),  //
    S(-21, -20),    S(-15, 27),     S(77, 26),      S(76, 83),      S(76, 78),      S(34, 41),      S(-33, 24),     S(-59, 8),      //
    S(34, -29),     S(38, 23),      S(50, 55),      S(61, 93),      S(44, 91),      S(14, 47),      S(-3, 36),      S(-43, 9),      //
    S(84, 24),      S(87, 61),      S(95, 89),      S(90, 168),     S(94, 165),     S(64, 92),      S(42, 53),      S(24, 36),      //
    S(64, 12),      S(86, 20),      S(92, 62),      S(74, 143),     S(64, 140),     S(63, 80),      S(44, 39),      S(9, 20),       //
    S(15, -45),     S(52, -37),     S(63, -8),      S(66, 46),      S(64, 41),      S(47, -10),     S(23, -28),     S(-29, -46),    //
    S(38, -34),     S(42, -14),     S(43, -39),     S(51, -3),      S(49, 3),       S(23, -50),     S(-20, -5),     S(-48, -98),    //
    S(-45, -116),   S(11, -48),     S(29, -57),     S(36, -44),     S(21, -30),     S(-15, -56),    S(-26, -42),    S(-78, -166),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-139, 16),    S(-207, 110),   S(-417, 176),   S(-283, 105),   S(-308, 139),   S(-306, 142),   S(-228, 115),   S(-131, 54),    //
    S(-36, -20),    S(-76, 103),    S(-52, 69),     S(-75, 75),     S(-76, 90),     S(-49, 58),     S(-18, 54),     S(-56, 18),     //
    S(33, 17),      S(18, 64),      S(29, 81),      S(19, 78),      S(18, 60),      S(17, 61),      S(4, 54),       S(8, 13),       //
    S(11, -8),      S(51, 20),      S(65, 39),      S(87, 61),      S(105, 52),     S(41, 25),      S(42, -0),      S(-5, -7),      //
    S(29, -49),     S(40, 4),       S(77, 11),      S(93, 26),      S(77, 37),      S(65, 31),      S(15, 11),      S(3, -38),      //
    S(50, -34),     S(70, -25),     S(91, 2),       S(62, 23),      S(61, 14),      S(57, 17),      S(52, -1),      S(10, -27),     //
    S(20, -73),     S(107, -48),    S(66, -27),     S(51, -6),      S(35, -1),      S(47, -38),     S(42, -45),     S(31, -50),     //
    S(35, -81),     S(18, -39),     S(25, -31),     S(32, -42),     S(18, -28),     S(27, 4),       S(34, -29),     S(29, -70),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(145, 119),    S(185, 128),    S(152, 147),    S(131, 126),    S(183, 93),     S(140, 120),    S(144, 139),    S(123, 140),    //
    S(75, 153),     S(133, 150),    S(188, 113),    S(145, 100),    S(171, 96),     S(135, 122),    S(84, 156),     S(78, 155),     //
    S(48, 137),     S(176, 67),     S(207, 49),     S(173, 37),     S(166, 64),     S(108, 104),    S(100, 125),    S(48, 165),     //
    S(16, 102),     S(87, 97),      S(106, 76),     S(85, 77),      S(110, 61),     S(68, 104),     S(61, 114),     S(8, 144),      //
    S(-14, 39),     S(49, 39),      S(43, 60),      S(11, 67),      S(20, 71),      S(7, 100),      S(-7, 97),      S(-29, 105),    //
    S(-2, -45),     S(69, -32),     S(57, -12),     S(37, -1),      S(45, 12),      S(22, 36),      S(16, 21),      S(-20, 33),     //
    S(-74, -52),    S(52, -95),     S(60, -64),     S(46, -27),     S(49, -23),     S(32, -4),      S(21, -16),     S(-10, -10),    //
    S(-11, -60),    S(17, -37),     S(77, -55),     S(83, -47),     S(83, -34),     S(58, -10),     S(53, -17),     S(33, -14),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(76, 150),     S(134, 145),    S(61, 261),     S(10, 338),     S(51, 277),     S(69, 232),     S(67, 160),     S(10, 211),     //
    S(53, 197),     S(77, 244),     S(49, 291),     S(-68, 384),    S(-30, 359),    S(17, 281),     S(49, 196),     S(32, 165),     //
    S(26, 206),     S(67, 243),     S(38, 294),     S(-5, 326),     S(4, 328),      S(50, 237),     S(71, 168),     S(56, 126),     //
    S(16, 136),     S(26, 200),     S(-17, 261),    S(-18, 304),    S(-5, 311),     S(9, 213),      S(47, 146),     S(21, 132),     //
    S(6, 101),      S(2, 134),      S(-12, 175),    S(-34, 238),    S(-25, 262),    S(-7, 219),     S(2, 161),      S(16, 91),      //
    S(-5, 5),       S(22, 18),      S(16, 98),      S(-6, 120),     S(6, 143),      S(10, 171),     S(24, 110),     S(4, 90),       //
    S(-27, -114),   S(0, -99),      S(5, -59),      S(33, -6),      S(32, 38),      S(33, 21),      S(7, 63),       S(12, 40),      //
    S(-51, -102),   S(-14, -265),   S(10, -262),    S(17, -142),    S(22, -50),     S(20, -69),     S(20, -54),     S(-12, -8),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(146, -558),   S(427, 115),    S(244, 258),    S(-81, 264),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(309, -150),   S(287, 255),    S(119, 312),    S(-91, 282),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(160, 57),     S(177, 225),    S(58, 284),     S(-119, 275),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(14, 15),      S(97, 133),     S(-50, 224),    S(-155, 262),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-86, -35),    S(9, 56),       S(-67, 139),    S(-178, 206),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -61),    S(45, 3),       S(-45, 94),     S(-114, 151),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(30, -106),    S(41, -28),     S(-22, 26),     S(-94, 87),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -227),   S(10, -107),    S(-75, -52),    S(-77, -67),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-76, -442);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -18), S(14, -7), S(11, 5), S(4, -0), S(1, -17),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -18), S(6, -8), S(2, -8), S(2, -0), S(3, 9),
};

inline const PParam REACH_INNER_RING = S(2, -1);
inline const PParam REACH_OUTER_RING = S(0, 1);
inline const PParam REACH_RING_DEFENSE = S(-3, 13);
inline const PParam REACH_RING_TWICE = S(4, -16);

inline const PParam KS_FLANK_ATTACK = S(3, -8);
inline const PParam KS_FLANK_DEFENSE = S(-3, -4);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -6);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(10, 28), S(-10, 55), S(-8, -16), S(1, -4), S(3, -15), S(-14, 33), S(-26, 5), }},
  {{ S(0, 87), S(-16, -193), S(-14, -80), S(-6, -4), S(-6, 32), S(-18, 76), S(-34, 41), }},
  {{ S(-8, 71), S(-16, -133), S(-13, 82), S(-7, 61), S(-7, 47), S(-16, 59), S(-39, 24), }},
  {{ S(2, 105), S(-14, 88), S(-3, 92), S(3, 76), S(2, 56), S(3, 78), S(1, 65), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 138), S(-10, 59), S(-12, 79), S(-5, 94), S(10, 50),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(0, 113), S(-52, -300), S(-12, -209), S(4, -204), S(-8, 51), S(-11, 67), S(-11, 67), }},
  {{ S(3, 58), S(-31, -377), S(-3, -340), S(0, -292), S(-7, 23), S(-13, 46), S(-4, 41), }},
  {{ S(-4, 65), S(-11, -377), S(5, -86), S(0, 6), S(-6, 37), S(-11, 56), S(-7, 54), }},
  {{ S(-4, 46), S(-0, -278), S(3, 6), S(2, 44), S(-8, 46), S(-14, 43), S(-10, 46), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1287, 347, -24, 52
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(107);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(100);
inline VParam WINNABLE_BIAS = V(-420);

// clang-format on
}  // namespace Clockwork
