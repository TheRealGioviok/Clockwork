#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(206, 509);
inline const PParam KNIGHT_MAT = S(786, 1599);
inline const PParam BISHOP_MAT = S(837, 1673);
inline const PParam ROOK_MAT   = S(1014, 2661);
inline const PParam QUEEN_MAT  = S(2507, 4030);

inline const PParam TEMPO_VAL  = S(69, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 3);
inline const PParam BISHOP_PAIR_VAL   = S(61, 232);
inline const PParam ROOK_OPEN_VAL     = S(107, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 22);
inline const PParam MINOR_BEHIND_PAWN = S(14, 39);
inline const PParam RESTRICTED_SQUARES = S(19, 3);

inline const PParam DOUBLED_PAWN_VAL = S(-24, -84);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -39);
inline const PParam OUTPOST_KNIGHT_VAL    = S(44, 34);
inline const PParam OUTPOST_BISHOP_VAL    = S(33, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 66);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -4), S(33, 30), S(59, 66), S(115, 220), S(378, 427), S(689, 823),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 34), S(40, 25), S(52, 58), S(89, 182), S(408, 109),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -259), S(-93, -218), S(-64, -92), S(-14, 25), S(89, 229), S(234, 408),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-94, 65), S(-92, 39), S(-60, 100), S(-70, 210), S(-13, 283), S(85, 170),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-26, 68), S(-32, 55), S(-57, 97), S(-19, 117), S(103, 107), S(47, 166),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -33), S(20, 4), S(10, 41), S(19, 102), S(81, 242), S(345, 203),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(6, -36), S(3, 2), S(-2, -36), S(-1, -82), S(-22, -166), S(-201, -421),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(25, 234), S(5, 195), S(0, 119), S(9, 79), S(20, 77), S(61, 65), S(66, 30),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-145, 6), S(6, 16), S(-0, 102), S(34, 139), S(49, 172), S(56, 187), S(41, 169),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-32, -332), S(-1, -118), S(14, -30), S(29, 3), S(45, 31), S(53, 70), S(62, 90), S(72, 118), S(83, 89),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-77, -300), S(-24, -90), S(26, -17), S(50, 24), S(68, 53), S(79, 73), S(83, 86), S(84, 101), S(85, 108), S(88, 114), S(96, 107), S(104, 97), S(101, 97), S(76, 74),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(92, -176), S(17, 2), S(39, 27), S(54, 44), S(64, 57), S(67, 65), S(71, 76), S(75, 78), S(79, 87), S(83, 94), S(85, 101), S(82, 111), S(81, 119), S(78, 113), S(94, 77),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-184, -114), S(-41, -26), S(-17, 71), S(-2, 188), S(14, 212), S(19, 253), S(26, 281), S(32, 293), S(36, 312), S(39, 326), S(44, 334), S(49, 338), S(52, 346), S(54, 350), S(54, 354), S(54, 358), S(50, 360), S(54, 351), S(54, 349), S(60, 340), S(51, 332), S(68, 302), S(34, 332), S(-2, 317), S(-43, 327), S(-51, 324), S(-128, 378), S(-77, 307),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-28, -21), S(3, -5), S(14, 14), S(26, 19), S(33, 31), S(37, 45), S(42, 51), S(45, 51), S(47, 55), S(52, 51), S(56, 47), S(57, 47), S(58, 41), S(63, 31), S(70, 15), S(70, 5), S(76, -14), S(83, -33), S(88, -44), S(84, -61), S(52, -105),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(49, -37), S(45, -35), S(49, -24), S(53, -4), S(51, 10), S(52, 14), S(50, 24), S(49, 32), S(47, 40), S(47, 45), S(45, 53), S(47, 57), S(48, 63), S(51, 66), S(59, 64), S(63, 62), S(61, 66), S(29, 75),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(53, -9), S(51, 9), S(53, 19), S(57, 26), S(62, 27), S(66, 32), S(69, 37), S(72, 44), S(73, 54), S(76, 58), S(74, 69), S(76, 76), S(73, 87), S(74, 95), S(74, 98), S(70, 106), S(67, 116), S(62, 126), S(61, 127), S(55, 137),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(-8, 107), S(-12, 151), S(-4, 199), S(3, 221), S(7, 229), S(10, 248), S(10, 255), S(14, 268), S(14, 273), S(18, 269), S(16, 281), S(16, 290), S(19, 290), S(21, 287), S(25, 288), S(27, 286), S(31, 275), S(43, 262), S(50, 245), S(53, 249), S(76, 210), S(88, 194), S(116, 136),
};

inline const PParam PAWN_THREAT_KNIGHT = S(198, 171);
inline const PParam PAWN_THREAT_BISHOP = S(169, 233);
inline const PParam PAWN_THREAT_ROOK   = S(188, 162);
inline const PParam PAWN_THREAT_QUEEN  = S(163, 21);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(14, 62), S(94, 117), S(106, 128), S(180, 108), S(159, 48), }},
  {{ S(12, 61), S(83, 113), S(105, 125), S(218, 637), S(141, 72), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(16, 71), S(48, 128), S(63, 137), S(14, 18), S(155, -67), }},
  {{ S(8, 57), S(65, 104), S(100, 99), S(26, 13), S(376, 899), }},
}};
inline const PParam KING_THREAT  = S(-25, 138);
inline const PParam REACH_THREAT = S(-16, 13);
inline const PParam REACH_THREAT_LOOSE = S(13, 26);
inline const PParam HANGING_PAWN  = S(37, 86);
inline const PParam HANGING_NON_PAWN  = S(80, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(18, -7), S(19, 7),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 47), S(100, -94),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(38, 5), S(43, -0),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -15), S(3, -11), S(-1, -16), S(-7, -23), S(-12, -30), S(-17, -35), S(-19, -46), S(-25, -46), S(-31, -63),
};

inline const PParam ROOK_LINEUP = S(18, 61);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(202, 253),    S(85, 348),     S(95, 290),     S(149, 300),    S(173, 213),    S(124, 262),    S(109, 285),    S(216, 216),    //
    S(32, 54),      S(41, 104),     S(15, 64),      S(22, 2),       S(16, -37),     S(-11, -4),     S(-6, 41),      S(-31, 62),     //
    S(35, 2),       S(3, 30),       S(25, 5),       S(17, -69),     S(8, -86),      S(-13, -49),    S(-51, -17),    S(-45, 15),     //
    S(-2, -64),     S(-29, -25),    S(-2, -46),     S(-3, -100),    S(-25, -108),   S(-38, -64),    S(-86, -40),    S(-77, -39),    //
    S(-14, -105),   S(23, -112),    S(4, -39),      S(-7, -65),     S(-33, -71),    S(-52, -62),    S(-83, -59),    S(-84, -62),    //
    S(12, -87),     S(97, -121),    S(78, -91),     S(40, -47),     S(10, -59),     S(-17, -59),    S(-47, -50),    S(-61, -49),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-274, -523),  S(-272, 25),    S(-272, -51),   S(-14, 55),     S(-115, 62),    S(-281, 76),    S(-370, 95),    S(-361, -426),  //
    S(-21, -26),    S(-18, 23),     S(73, 23),      S(65, 83),      S(67, 76),      S(34, 39),      S(-34, 16),     S(-60, 5),      //
    S(29, -29),     S(24, 30),      S(35, 58),      S(45, 100),     S(30, 97),      S(8, 43),       S(-8, 33),      S(-47, 7),      //
    S(79, 29),      S(75, 68),      S(84, 96),      S(78, 175),     S(82, 170),     S(55, 95),      S(34, 53),      S(24, 30),      //
    S(64, 13),      S(82, 20),      S(85, 61),      S(64, 149),     S(58, 134),     S(59, 75),      S(43, 34),      S(12, 17),      //
    S(16, -47),     S(51, -44),     S(61, -15),     S(62, 43),      S(62, 35),      S(44, -10),     S(23, -28),     S(-26, -47),    //
    S(46, -47),     S(52, -38),     S(49, -57),     S(55, -12),     S(50, -5),      S(24, -49),     S(-18, -2),     S(-44, -97),    //
    S(-41, -119),   S(17, -59),     S(36, -75),     S(40, -50),     S(25, -34),     S(-11, -53),    S(-22, -44),    S(-75, -164),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-135, 18),    S(-204, 109),   S(-417, 175),   S(-292, 112),   S(-316, 147),   S(-314, 151),   S(-229, 117),   S(-129, 60),    //
    S(-34, -23),    S(-78, 104),    S(-60, 71),     S(-82, 81),     S(-85, 100),    S(-52, 53),     S(-21, 52),     S(-54, 10),     //
    S(29, 16),      S(4, 66),       S(17, 82),      S(5, 78),       S(7, 59),       S(6, 62),       S(-4, 49),      S(6, 7),        //
    S(4, -2),       S(40, 31),      S(51, 48),      S(70, 72),      S(89, 59),      S(31, 26),      S(31, 4),       S(-7, -12),     //
    S(26, -38),     S(33, 5),       S(72, 12),      S(82, 33),      S(71, 32),      S(58, 29),      S(12, 9),       S(1, -35),      //
    S(49, -26),     S(69, -26),     S(89, -4),      S(59, 25),      S(59, 7),       S(55, 17),      S(51, 3),       S(11, -22),     //
    S(22, -74),     S(116, -74),    S(73, -49),     S(55, -20),     S(40, -14),     S(49, -37),     S(47, -48),     S(31, -39),     //
    S(37, -76),     S(24, -45),     S(33, -41),     S(40, -47),     S(24, -31),     S(33, 7),       S(36, -23),     S(32, -62),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(144, 123),    S(179, 139),    S(134, 171),    S(118, 149),    S(177, 112),    S(139, 129),    S(150, 139),    S(128, 141),    //
    S(74, 151),     S(124, 161),    S(176, 130),    S(136, 116),    S(166, 113),    S(131, 131),    S(84, 159),     S(83, 153),     //
    S(43, 141),     S(164, 82),     S(191, 72),     S(159, 58),     S(156, 87),     S(101, 117),    S(99, 127),     S(50, 163),     //
    S(19, 101),     S(81, 105),     S(97, 94),      S(77, 93),      S(104, 74),     S(68, 108),     S(62, 113),     S(14, 138),     //
    S(-10, 43),     S(47, 49),      S(36, 76),      S(5, 86),       S(15, 87),      S(7, 107),      S(-4, 96),      S(-22, 102),    //
    S(7, -51),      S(73, -34),     S(59, -8),      S(38, 4),       S(47, 15),      S(27, 37),      S(27, 12),      S(-9, 26),      //
    S(-62, -62),    S(61, -113),    S(66, -75),     S(50, -28),     S(53, -21),     S(37, -1),      S(30, -21),     S(2, -16),      //
    S(-3, -68),     S(27, -53),     S(87, -69),     S(91, -57),     S(91, -40),     S(67, -16),     S(64, -24),     S(44, -22),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(74, 155),     S(136, 144),    S(51, 285),     S(-15, 388),    S(25, 334),     S(46, 272),     S(62, 170),     S(11, 212),     //
    S(55, 179),     S(74, 234),     S(28, 323),     S(-87, 431),    S(-51, 407),    S(9, 289),      S(52, 174),     S(37, 142),     //
    S(10, 230),     S(48, 252),     S(12, 338),     S(-26, 376),    S(-11, 370),    S(37, 257),     S(69, 154),     S(55, 119),     //
    S(9, 155),      S(16, 217),     S(-24, 287),    S(-26, 334),    S(-10, 331),    S(12, 216),     S(50, 137),     S(29, 113),     //
    S(6, 112),      S(2, 133),      S(-13, 189),    S(-34, 250),    S(-24, 270),    S(2, 216),      S(9, 162),      S(27, 82),      //
    S(2, -6),       S(30, -1),      S(24, 82),      S(2, 108),      S(17, 123),     S(20, 160),     S(37, 99),      S(15, 86),      //
    S(-15, -151),   S(23, -186),    S(24, -112),    S(45, -33),     S(45, 8),       S(45, 5),       S(19, 50),      S(26, 28),      //
    S(-39, -128),   S(1, -309),     S(27, -307),    S(30, -171),    S(37, -86),     S(33, -92),     S(32, -69),     S(0, -22),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(148, -606),   S(445, 63),     S(245, 306),    S(-71, 366),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(326, -217),   S(295, 203),    S(118, 354),    S(-102, 412),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(167, 2),      S(183, 176),    S(47, 335),     S(-132, 407),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(13, -32),     S(96, 101),     S(-60, 292),    S(-176, 412),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-102, -74),   S(3, 25),       S(-78, 201),    S(-197, 334),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -129),   S(38, -37),     S(-54, 141),    S(-129, 259),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -185),    S(44, -87),     S(-24, 43),     S(-105, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-12, -313),   S(16, -180),    S(-69, -65),    S(-79, -29),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-65, -74);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -1), S(11, 0), S(10, 0), S(4, -2), S(2, -5),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -1), S(5, -1), S(2, -1), S(2, -1), S(2, 1),
};

inline const PParam REACH_INNER_RING = S(1, 0);
inline const PParam REACH_OUTER_RING = S(-0, 0);
inline const PParam REACH_RING_DEFENSE = S(-3, 3);
inline const PParam REACH_RING_TWICE = S(4, 1);

inline const PParam KS_FLANK_ATTACK = S(4, -3);
inline const PParam KS_FLANK_DEFENSE = S(-2, -2);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 0);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(9, -7), S(-13, 8), S(-8, -5), S(3, -10), S(8, -17), S(-1, -24), S(-2, -41), }},
  {{ S(-3, 5), S(-24, 0), S(-17, 2), S(-8, 3), S(-5, -1), S(-11, -8), S(-12, -31), }},
  {{ S(-9, 6), S(-18, -4), S(-13, 8), S(-8, 5), S(-7, 4), S(-13, -0), S(-18, -38), }},
  {{ S(-3, 19), S(-13, 10), S(-5, 14), S(0, 12), S(2, 7), S(1, 13), S(2, 8), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(1, 34), S(-13, 17), S(-15, 23), S(-11, 28), S(1, 26),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 23), S(-41, -191), S(-8, -39), S(-2, 8), S(-7, 13), S(-12, 19), S(-12, 19), }},
  {{ S(2, 14), S(-22, -216), S(-2, -40), S(-2, -2), S(-5, 6), S(-12, 15), S(-4, 15), }},
  {{ S(-6, 17), S(-0, -167), S(11, -23), S(1, 3), S(-6, 13), S(-13, 18), S(-9, 20), }},
  {{ S(-5, 12), S(14, -80), S(9, -15), S(-1, 13), S(-11, 18), S(-15, 14), S(-12, 16), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1500, 1304, -23, -18
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(88);
inline VParam WINNABLE_PAWN_ENDGAME = V(89);
inline VParam WINNABLE_BIAS = V(-397);

// clang-format on
}  // namespace Clockwork
