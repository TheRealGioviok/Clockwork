#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(208, 512);
inline const PParam KNIGHT_MAT = S(780, 1594);
inline const PParam BISHOP_MAT = S(839, 1675);
inline const PParam ROOK_MAT   = S(1004, 2661);
inline const PParam QUEEN_MAT  = S(2510, 4060);

inline const PParam TEMPO_VAL  = S(69, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 2);
inline const PParam BISHOP_PAIR_VAL   = S(59, 234);
inline const PParam ROOK_OPEN_VAL     = S(112, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 22);
inline const PParam MINOR_BEHIND_PAWN = S(13, 39);
inline const PParam RESTRICTED_SQUARES = S(20, 5);

inline const PParam DOUBLED_PAWN_VAL = S(-24, -83);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -39);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 33);
inline const PParam OUTPOST_BISHOP_VAL    = S(35, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(35, 53);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 66);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -4), S(32, 31), S(59, 66), S(114, 219), S(386, 420), S(693, 827),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 35), S(39, 26), S(52, 57), S(90, 181), S(416, 106),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -256), S(-94, -213), S(-66, -85), S(-15, 32), S(90, 232), S(236, 408),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-95, 69), S(-91, 40), S(-58, 101), S(-69, 212), S(-15, 290), S(87, 174),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-26, 69), S(-32, 57), S(-55, 97), S(-18, 117), S(101, 112), S(51, 169),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(21, -32), S(19, 5), S(9, 41), S(18, 102), S(74, 248), S(338, 209),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(5, -35), S(2, 2), S(-4, -36), S(-2, -82), S(-24, -169), S(-208, -425),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(26, 230), S(6, 190), S(2, 114), S(10, 74), S(22, 70), S(62, 58), S(68, 24),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-145, 1), S(7, 14), S(1, 102), S(37, 137), S(52, 172), S(58, 188), S(43, 170),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-27, -325), S(3, -112), S(19, -25), S(33, 7), S(49, 33), S(55, 72), S(64, 90), S(73, 117), S(83, 88),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-79, -301), S(-25, -90), S(26, -18), S(49, 23), S(67, 51), S(78, 70), S(82, 83), S(83, 97), S(86, 104), S(89, 110), S(97, 102), S(105, 93), S(100, 96), S(74, 71),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(95, -173), S(19, 5), S(40, 30), S(55, 46), S(64, 59), S(67, 67), S(70, 77), S(74, 78), S(77, 88), S(81, 94), S(82, 101), S(79, 110), S(76, 117), S(72, 111), S(87, 74),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-182, -101), S(-43, -10), S(-19, 85), S(-4, 199), S(11, 220), S(17, 257), S(23, 284), S(30, 294), S(34, 313), S(37, 325), S(42, 332), S(47, 337), S(49, 344), S(52, 347), S(52, 351), S(51, 355), S(47, 357), S(52, 347), S(53, 344), S(58, 335), S(48, 331), S(66, 300), S(35, 327), S(-4, 318), S(-41, 324), S(-51, 325), S(-124, 372), S(-80, 314),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-24, -18), S(6, -2), S(18, 15), S(29, 20), S(36, 32), S(40, 45), S(45, 52), S(47, 51), S(50, 55), S(54, 51), S(58, 46), S(59, 46), S(60, 40), S(65, 30), S(71, 14), S(71, 4), S(76, -15), S(83, -34), S(88, -46), S(82, -62), S(48, -105),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(52, -38), S(48, -36), S(52, -25), S(55, -5), S(53, 8), S(54, 13), S(52, 22), S(51, 30), S(48, 38), S(48, 44), S(46, 52), S(48, 55), S(49, 60), S(51, 63), S(59, 61), S(62, 59), S(61, 63), S(28, 72),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(63, -12), S(60, 7), S(61, 16), S(64, 23), S(68, 25), S(71, 30), S(73, 35), S(75, 43), S(73, 54), S(74, 59), S(71, 70), S(71, 78), S(67, 90), S(66, 98), S(64, 103), S(59, 110), S(53, 121), S(47, 132), S(43, 134), S(29, 145),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(-8, 119), S(-13, 162), S(-4, 206), S(3, 227), S(7, 236), S(10, 252), S(11, 259), S(14, 270), S(14, 275), S(19, 269), S(18, 280), S(17, 287), S(21, 283), S(22, 284), S(26, 281), S(28, 278), S(30, 270), S(42, 256), S(47, 239), S(49, 243), S(69, 207), S(81, 187), S(106, 126),
};
inline const std::array<PParam, 4> REACH_CONTEST = {
    S(2, 7), S(4, 5), S(14, 2), S(-0, 22),
};

inline const PParam PAWN_THREAT_KNIGHT = S(199, 170);
inline const PParam PAWN_THREAT_BISHOP = S(170, 231);
inline const PParam PAWN_THREAT_ROOK   = S(187, 162);
inline const PParam PAWN_THREAT_QUEEN  = S(162, 25);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(12, 61), S(93, 117), S(106, 128), S(180, 105), S(159, 44), }},
  {{ S(10, 59), S(82, 113), S(105, 125), S(220, 633), S(137, 90), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(14, 69), S(44, 127), S(59, 136), S(11, 18), S(154, -67), }},
  {{ S(6, 55), S(60, 102), S(96, 97), S(23, 12), S(376, 898), }},
}};
inline const PParam KING_THREAT  = S(-28, 137);
inline const PParam REACH_THREAT = S(-14, 15);
inline const PParam REACH_THREAT_LOOSE = S(16, 28);
inline const PParam HANGING_PAWN  = S(38, 89);
inline const PParam HANGING_NON_PAWN  = S(83, 36);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(18, -7), S(20, 6),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(41, 45), S(91, -86),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, -1), S(39, 5),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(2, -16), S(2, -11), S(-2, -16), S(-7, -23), S(-13, -30), S(-18, -35), S(-20, -47), S(-25, -47), S(-32, -65),
};

inline const PParam ROOK_LINEUP = S(17, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(199, 259),    S(84, 347),     S(92, 287),     S(148, 304),    S(174, 212),    S(125, 260),    S(108, 286),    S(214, 221),    //
    S(33, 54),      S(43, 103),     S(17, 65),      S(27, 0),       S(20, -37),     S(-7, -5),      S(-4, 42),      S(-31, 63),     //
    S(33, 0),       S(3, 28),       S(25, 2),       S(16, -67),     S(8, -84),      S(-12, -49),    S(-50, -17),    S(-46, 15),     //
    S(-3, -66),     S(-29, -27),    S(-1, -48),     S(-2, -98),     S(-23, -106),   S(-36, -63),    S(-84, -40),    S(-77, -39),    //
    S(-14, -108),   S(23, -114),    S(5, -41),      S(-5, -65),     S(-30, -70),    S(-49, -62),    S(-80, -60),    S(-84, -64),    //
    S(11, -90),     S(95, -119),    S(76, -84),     S(41, -44),     S(12, -57),     S(-15, -59),    S(-46, -50),    S(-62, -49),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-272, -524),  S(-272, 28),    S(-271, -52),   S(-15, 57),     S(-116, 65),    S(-283, 80),    S(-369, 94),    S(-359, -427),  //
    S(-22, -23),    S(-20, 24),     S(68, 29),      S(62, 86),      S(64, 77),      S(29, 44),      S(-39, 20),     S(-63, 8),      //
    S(28, -25),     S(25, 33),      S(38, 61),      S(46, 102),     S(32, 98),      S(8, 45),       S(-9, 36),      S(-47, 8),      //
    S(80, 30),      S(77, 69),      S(88, 96),      S(81, 175),     S(86, 169),     S(59, 94),      S(37, 53),      S(24, 32),      //
    S(62, 15),      S(82, 20),      S(87, 61),      S(67, 148),     S(60, 133),     S(61, 74),      S(42, 35),      S(10, 17),      //
    S(15, -46),     S(50, -42),     S(61, -14),     S(63, 44),      S(63, 36),      S(46, -10),     S(23, -28),     S(-28, -48),    //
    S(43, -44),     S(49, -36),     S(47, -54),     S(54, -11),     S(51, -5),      S(25, -50),     S(-18, -4),     S(-47, -95),    //
    S(-42, -119),   S(15, -59),     S(34, -73),     S(39, -50),     S(24, -35),     S(-12, -55),    S(-24, -45),    S(-76, -164),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-134, 16),    S(-205, 109),   S(-420, 178),   S(-292, 113),   S(-317, 149),   S(-315, 153),   S(-230, 118),   S(-129, 58),    //
    S(-37, -21),    S(-81, 105),    S(-65, 75),     S(-86, 83),     S(-89, 99),     S(-57, 57),     S(-26, 54),     S(-56, 10),     //
    S(29, 18),      S(5, 64),       S(18, 82),      S(6, 78),       S(8, 60),       S(7, 63),       S(-3, 48),      S(6, 7),        //
    S(5, -2),       S(42, 29),      S(54, 47),      S(75, 70),      S(92, 58),      S(34, 25),      S(33, 4),       S(-6, -12),     //
    S(27, -37),     S(34, 5),       S(74, 12),      S(85, 31),      S(74, 30),      S(60, 29),      S(13, 8),       S(2, -36),      //
    S(49, -26),     S(68, -24),     S(89, -4),      S(60, 24),      S(60, 7),       S(56, 17),      S(51, 2),       S(12, -22),     //
    S(19, -71),     S(112, -71),    S(70, -47),     S(53, -19),     S(39, -14),     S(48, -38),     S(46, -48),     S(30, -40),     //
    S(36, -76),     S(22, -45),     S(29, -41),     S(36, -47),     S(21, -31),     S(30, 5),       S(35, -25),     S(31, -62),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(146, 123),    S(181, 137),    S(137, 168),    S(119, 146),    S(178, 109),    S(138, 129),    S(146, 142),    S(123, 147),    //
    S(73, 153),     S(124, 161),    S(177, 127),    S(134, 113),    S(162, 112),    S(129, 130),    S(80, 160),     S(80, 155),     //
    S(42, 140),     S(164, 79),     S(191, 68),     S(158, 54),     S(157, 80),     S(100, 113),    S(96, 127),     S(47, 164),     //
    S(15, 100),     S(79, 102),     S(95, 90),      S(76, 87),      S(103, 68),     S(65, 104),     S(58, 111),     S(9, 139),      //
    S(-14, 42),     S(44, 46),      S(34, 71),      S(4, 79),       S(15, 80),      S(5, 102),      S(-8, 94),      S(-28, 103),    //
    S(1, -52),      S(67, -37),     S(55, -12),     S(34, -1),      S(44, 10),      S(24, 32),      S(22, 9),       S(-16, 26),     //
    S(-67, -62),    S(55, -112),    S(61, -77),     S(46, -32),     S(50, -24),     S(34, -5),      S(24, -22),     S(-5, -16),     //
    S(-7, -67),     S(22, -51),     S(81, -67),     S(86, -57),     S(87, -40),     S(63, -16),     S(59, -24),     S(39, -20),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(76, 157),     S(138, 146),    S(58, 281),     S(1, 369),      S(36, 321),     S(55, 264),     S(67, 167),     S(13, 212),     //
    S(56, 177),     S(75, 234),     S(33, 318),     S(-83, 419),    S(-46, 393),    S(10, 286),     S(51, 178),     S(37, 141),     //
    S(12, 224),     S(52, 246),     S(19, 326),     S(-20, 363),    S(-5, 358),     S(41, 248),     S(70, 152),     S(54, 117),     //
    S(7, 152),      S(16, 212),     S(-24, 280),    S(-25, 321),    S(-11, 322),    S(10, 209),     S(47, 136),     S(23, 116),     //
    S(3, 110),      S(-0, 128),     S(-16, 180),    S(-38, 242),    S(-28, 264),    S(-5, 214),     S(3, 160),      S(21, 81),      //
    S(-3, -8),      S(26, -10),     S(19, 73),      S(-4, 102),     S(12, 116),     S(13, 157),     S(30, 95),      S(8, 84),       //
    S(-21, -149),   S(16, -186),    S(16, -116),    S(38, -37),     S(38, 3),       S(39, 0),       S(12, 47),      S(19, 28),      //
    S(-45, -123),   S(-5, -305),    S(20, -308),    S(22, -170),    S(29, -86),     S(27, -94),     S(25, -70),     S(-5, -21),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(147, -596),   S(439, 79),     S(242, 311),    S(-72, 354),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(320, -204),   S(295, 215),    S(115, 359),    S(-102, 402),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(169, 9),      S(189, 184),    S(53, 334),     S(-128, 398),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(18, -29),     S(103, 104),    S(-58, 291),    S(-172, 399),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-98, -71),    S(10, 27),      S(-74, 195),    S(-193, 318),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -123),   S(43, -35),     S(-51, 135),    S(-127, 244),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(38, -178),    S(47, -82),     S(-22, 39),     S(-102, 145),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, -302),   S(14, -170),    S(-72, -63),    S(-82, -36),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-65, -80);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -1), S(11, 0), S(10, 1), S(4, -2), S(2, -5),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -2), S(5, -2), S(2, -2), S(2, -1), S(2, 2),
};

inline const PParam REACH_INNER_RING = S(1, 0);
inline const PParam REACH_OUTER_RING = S(-0, 1);
inline const PParam REACH_RING_DEFENSE = S(-3, 3);
inline const PParam REACH_RING_TWICE = S(4, 1);

inline const PParam KS_FLANK_ATTACK = S(4, -3);
inline const PParam KS_FLANK_DEFENSE = S(-2, -2);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 0);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(9, -9), S(-12, 8), S(-7, -7), S(4, -13), S(9, -21), S(-1, -28), S(-1, -49), }},
  {{ S(-3, 6), S(-24, -0), S(-16, 1), S(-7, 3), S(-5, -3), S(-11, -9), S(-12, -39), }},
  {{ S(-9, 9), S(-19, -3), S(-14, 11), S(-8, 7), S(-7, 5), S(-13, 2), S(-17, -50), }},
  {{ S(-2, 20), S(-13, 11), S(-5, 15), S(1, 12), S(2, 6), S(1, 13), S(2, 8), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(1, 40), S(-13, 20), S(-15, 27), S(-11, 33), S(1, 30),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 27), S(-43, -203), S(-9, -40), S(-2, 9), S(-7, 15), S(-11, 22), S(-11, 22), }},
  {{ S(2, 17), S(-24, -249), S(-3, -42), S(-3, -2), S(-4, 7), S(-12, 17), S(-4, 17), }},
  {{ S(-6, 21), S(-3, -208), S(10, -23), S(1, 4), S(-6, 14), S(-13, 21), S(-9, 23), }},
  {{ S(-5, 14), S(14, -138), S(8, -15), S(-1, 15), S(-10, 21), S(-15, 17), S(-12, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1491, 1133, -24, -20
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(105);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(90);
inline VParam WINNABLE_BIAS = V(-404);


// clang-format on
}  // namespace Clockwork
