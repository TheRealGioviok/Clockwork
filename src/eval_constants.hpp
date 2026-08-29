#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(205, 513);
inline const PParam KNIGHT_MAT = S(784, 1600);
inline const PParam BISHOP_MAT = S(841, 1674);
inline const PParam ROOK_MAT   = S(1017, 2654);
inline const PParam QUEEN_MAT  = S(2429, 4096);

inline const PParam TEMPO_VAL  = S(69, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 2);
inline const PParam BISHOP_PAIR_VAL   = S(57, 240);
inline const PParam ROOK_OPEN_VAL     = S(110, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 19);
inline const PParam REACH_TERRITORY = S(7, -3);
inline const PParam MINOR_BEHIND_PAWN = S(14, 41);
inline const PParam RESTRICTED_SQUARES = S(19, 8);

inline const PParam DOUBLED_PAWN_VAL = S(-23, -84);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(38, 37);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(35, 57);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 72);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -2), S(31, 35), S(58, 65), S(122, 213), S(401, 397), S(684, 832),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 34), S(39, 26), S(52, 57), S(91, 182), S(400, 119),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -263), S(-94, -219), S(-67, -84), S(-21, 42), S(87, 208), S(226, 421),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-103, 58), S(-111, 42), S(-76, 111), S(-103, 239), S(-61, 346), S(49, 223),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-35, 70), S(-42, 61), S(-69, 108), S(-35, 137), S(75, 159), S(35, 200),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -39), S(21, 0), S(16, 36), S(21, 108), S(69, 285), S(341, 233),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(11, -39), S(3, 5), S(-6, -28), S(-1, -72), S(-13, -180), S(-176, -457),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 237), S(9, 184), S(3, 106), S(11, 67), S(20, 70), S(58, 65), S(62, 36),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-132, -52), S(15, -4), S(2, 101), S(29, 152), S(45, 187), S(56, 196), S(41, 176),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-32, -346), S(-0, -128), S(15, -38), S(30, -2), S(47, 30), S(54, 73), S(63, 95), S(74, 126), S(87, 96),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-76, -301), S(-26, -87), S(26, -15), S(50, 25), S(68, 54), S(80, 72), S(83, 85), S(84, 98), S(86, 104), S(89, 109), S(96, 100), S(108, 84), S(105, 87), S(87, 56),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(88, -179), S(16, 3), S(36, 32), S(52, 47), S(62, 60), S(65, 68), S(69, 78), S(74, 78), S(78, 87), S(82, 92), S(85, 96), S(83, 105), S(84, 109), S(87, 97), S(107, 58),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-191, -130), S(-42, -45), S(-18, 60), S(-4, 180), S(11, 209), S(17, 251), S(24, 279), S(29, 292), S(34, 312), S(37, 327), S(42, 334), S(46, 340), S(49, 347), S(51, 353), S(52, 356), S(50, 362), S(47, 363), S(51, 357), S(52, 352), S(57, 345), S(48, 336), S(59, 312), S(25, 341), S(-21, 332), S(-53, 329), S(-90, 356), S(-148, 384), S(-114, 319),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-26, -15), S(4, 0), S(15, 18), S(25, 24), S(33, 34), S(36, 47), S(41, 53), S(43, 53), S(46, 55), S(50, 52), S(54, 48), S(56, 46), S(58, 40), S(62, 30), S(68, 15), S(68, 5), S(75, -16), S(81, -34), S(88, -48), S(86, -67), S(57, -113),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(46, -33), S(44, -34), S(48, -24), S(51, -4), S(49, 10), S(50, 14), S(49, 24), S(48, 31), S(46, 39), S(47, 45), S(45, 53), S(48, 56), S(51, 60), S(56, 60), S(64, 62), S(71, 56), S(74, 58), S(49, 61),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(55, -11), S(53, 6), S(55, 15), S(58, 24), S(64, 25), S(67, 31), S(71, 35), S(74, 43), S(75, 54), S(77, 59), S(76, 70), S(79, 78), S(77, 89), S(78, 97), S(79, 100), S(75, 108), S(73, 119), S(69, 129), S(70, 129), S(73, 136),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(-10, 84), S(-15, 132), S(-6, 179), S(-0, 205), S(3, 215), S(7, 232), S(7, 242), S(11, 256), S(11, 262), S(16, 260), S(14, 274), S(13, 287), S(17, 288), S(19, 289), S(23, 290), S(27, 289), S(30, 284), S(38, 283), S(47, 263), S(50, 271), S(76, 231), S(91, 213), S(115, 175),
};

inline const PParam PAWN_THREAT_KNIGHT = S(203, 163);
inline const PParam PAWN_THREAT_BISHOP = S(175, 220);
inline const PParam PAWN_THREAT_ROOK   = S(197, 153);
inline const PParam PAWN_THREAT_QUEEN  = S(165, 24);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(14, 56), S(101, 104), S(114, 115), S(185, 89), S(169, 10), }},
  {{ S(12, 57), S(90, 101), S(113, 112), S(227, 612), S(150, 56), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(13, 68), S(49, 114), S(61, 124), S(13, 19), S(153, -79), }},
  {{ S(6, 54), S(67, 87), S(99, 81), S(24, 18), S(372, 905), }},
}};
inline const PParam KING_THREAT  = S(-10, 155);
inline const PParam HANGING_PAWN  = S(35, 91);
inline const PParam HANGING_NON_PAWN  = S(76, 30);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(19, -13), S(7, 30),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(41, 52), S(96, -89),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 8), S(51, -13),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -13), S(-1, -18), S(-7, -26), S(-13, -32), S(-18, -37), S(-20, -48), S(-26, -48), S(-32, -65),
};

inline const PParam ROOK_LINEUP = S(17, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(186, 284),    S(60, 403),     S(62, 394),     S(151, 279),    S(186, 173),    S(139, 214),    S(119, 243),    S(224, 186),    //
    S(41, 63),      S(48, 110),     S(21, 60),      S(34, -5),      S(27, -44),     S(1, -14),      S(5, 29),       S(-23, 54),     //
    S(37, -12),     S(9, -3),       S(36, -45),     S(16, -69),     S(7, -87),      S(-5, -75),     S(-43, -41),    S(-40, -3),     //
    S(-2, -73),     S(-28, -43),    S(5, -63),      S(-7, -80),     S(-29, -89),    S(-34, -77),    S(-81, -56),    S(-74, -52),    //
    S(-12, -111),   S(20, -106),    S(7, -44),      S(-9, -49),     S(-37, -58),    S(-50, -70),    S(-79, -70),    S(-83, -74),    //
    S(12, -107),    S(88, -91),     S(77, -36),     S(33, -6),      S(3, -27),      S(-18, -56),    S(-47, -53),    S(-60, -56),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-277, -519),  S(-274, 37),    S(-276, -46),   S(-20, 41),     S(-124, 56),    S(-284, 76),    S(-369, 95),    S(-367, -421),  //
    S(-12, -29),    S(-11, 19),     S(72, 14),      S(56, 72),      S(59, 64),      S(31, 25),      S(-32, 16),     S(-60, 8),      //
    S(33, -36),     S(27, 21),      S(39, 42),      S(44, 81),      S(29, 76),      S(3, 34),       S(-10, 27),     S(-46, 1),      //
    S(80, 19),      S(79, 53),      S(83, 79),      S(73, 161),     S(75, 162),     S(50, 85),      S(33, 50),      S(19, 31),      //
    S(67, 12),      S(90, 12),      S(91, 56),      S(71, 135),     S(59, 134),     S(61, 72),      S(40, 33),      S(9, 24),       //
    S(21, -40),     S(61, -39),     S(72, -12),     S(73, 39),      S(68, 37),      S(49, -16),     S(28, -31),     S(-25, -44),    //
    S(42, -26),     S(48, -16),     S(46, -32),     S(54, -0),      S(51, -1),      S(26, -56),     S(-19, -2),     S(-47, -89),    //
    S(-45, -103),   S(9, -38),      S(30, -48),     S(39, -35),     S(24, -22),     S(-12, -50),    S(-24, -36),    S(-78, -153),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-147, 19),    S(-207, 97),    S(-418, 159),   S(-287, 86),    S(-314, 123),   S(-316, 138),   S(-235, 112),   S(-140, 59),    //
    S(-37, -26),    S(-77, 90),     S(-61, 58),     S(-86, 54),     S(-89, 75),     S(-55, 45),     S(-22, 44),     S(-63, 18),     //
    S(28, 10),      S(9, 56),       S(18, 71),      S(10, 57),      S(7, 43),       S(8, 48),       S(-0, 41),      S(2, 4),        //
    S(10, -17),     S(43, 15),      S(48, 36),      S(67, 54),      S(89, 41),      S(27, 20),      S(35, -7),      S(-10, -13),    //
    S(31, -51),     S(41, -1),      S(75, 9),       S(88, 23),      S(70, 35),      S(61, 23),      S(12, 4),       S(2, -45),      //
    S(50, -30),     S(76, -20),     S(98, 5),       S(65, 26),      S(60, 15),      S(58, 16),      S(53, -2),      S(9, -29),      //
    S(21, -68),     S(111, -42),    S(69, -13),     S(54, 2),       S(38, 4),       S(49, -38),     S(44, -45),     S(34, -51),     //
    S(37, -73),     S(19, -30),     S(25, -17),     S(40, -37),     S(23, -20),     S(32, 10),      S(37, -21),     S(32, -65),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(172, 98),     S(198, 112),    S(154, 138),    S(133, 117),    S(191, 72),     S(148, 98),     S(152, 120),    S(139, 119),    //
    S(82, 141),     S(133, 142),    S(176, 111),    S(128, 98),     S(163, 84),     S(128, 111),    S(80, 145),     S(75, 147),     //
    S(53, 128),     S(169, 67),     S(190, 51),     S(161, 33),     S(162, 50),     S(101, 95),     S(97, 113),     S(47, 155),     //
    S(28, 96),      S(89, 98),      S(105, 74),     S(87, 73),      S(113, 54),     S(71, 97),      S(60, 115),     S(7, 145),      //
    S(0, 39),       S(55, 42),      S(47, 61),      S(15, 70),      S(22, 73),      S(8, 100),      S(-9, 98),      S(-28, 107),    //
    S(14, -40),     S(81, -24),     S(69, -3),      S(46, 10),      S(54, 15),      S(29, 39),      S(23, 25),      S(-16, 39),     //
    S(-68, -44),    S(55, -84),     S(63, -50),     S(51, -16),     S(55, -18),     S(37, -2),      S(25, -14),     S(-6, -6),      //
    S(-7, -44),     S(19, -20),     S(83, -36),     S(90, -32),     S(91, -24),     S(67, -2),      S(61, -9),      S(37, -0),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(82, 143),     S(144, 129),    S(55, 275),     S(-8, 380),     S(28, 329),     S(61, 243),     S(68, 150),     S(17, 188),     //
    S(56, 166),     S(74, 224),     S(30, 307),     S(-99, 434),    S(-53, 392),    S(11, 271),     S(55, 152),     S(36, 119),     //
    S(17, 214),     S(55, 243),     S(15, 331),     S(-30, 370),    S(-11, 357),    S(37, 242),     S(74, 136),     S(56, 93),      //
    S(11, 151),     S(18, 224),     S(-25, 294),    S(-29, 351),    S(-12, 342),    S(8, 222),      S(49, 131),     S(26, 94),      //
    S(8, 125),      S(4, 147),      S(-9, 199),     S(-35, 267),    S(-23, 279),    S(-1, 210),     S(7, 145),      S(26, 52),      //
    S(2, 23),       S(30, 35),      S(30, 104),     S(5, 128),      S(16, 134),     S(21, 151),     S(36, 81),      S(13, 67),      //
    S(-23, -114),   S(9, -122),     S(14, -56),     S(42, -18),     S(41, 19),      S(40, -2),      S(13, 40),      S(22, 11),      //
    S(-46, -87),    S(-11, -261),   S(18, -272),    S(29, -155),    S(34, -71),     S(32, -87),     S(31, -73),     S(-2, -24),     // 
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(196, -577),   S(510, 63),     S(340, 184),    S(44, 181),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(398, -197),   S(399, 177),    S(241, 194),    S(54, 147),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(226, 34),     S(266, 164),    S(144, 192),    S(-17, 168),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(53, 4),       S(134, 110),    S(0, 169),      S(-99, 200),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-104, -3),    S(-10, 77),     S(-75, 148),    S(-172, 200),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-56, -29),    S(9, 39),       S(-69, 120),    S(-127, 165),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(20, -87),     S(26, -7),      S(-35, 55),     S(-107, 111),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -210),   S(-2, -88),     S(-79, -24),    S(-89, -38),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-77, -454);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -3), S(10, 13), S(10, 6), S(4, 2), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -18), S(-7, 6), S(-4, -9), S(6, -15), S(11, -28), S(5, -52), S(-5, -47), }},
  {{ S(2, 5), S(-21, 3), S(-17, 11), S(-11, 18), S(-7, 9), S(-10, -12), S(-20, -22), }},
  {{ S(-4, -1), S(-13, -9), S(-14, 16), S(-9, 18), S(-8, 9), S(-8, -17), S(-24, -38), }},
  {{ S(5, 10), S(-11, 18), S(-8, 39), S(-3, 43), S(-3, 39), S(2, 20), S(8, -12), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 23), S(-7, 3), S(-8, 9), S(-7, 28), S(1, 47),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, 11), S(-42, -115), S(-9, -38), S(-2, 5), S(-4, 4), S(-7, 11), S(-6, 10), }},
  {{ S(8, -1), S(-25, -122), S(-7, -31), S(-6, 1), S(-3, -2), S(-10, 4), S(-0, 3), }},
  {{ S(-1, 11), S(-7, -71), S(6, -15), S(-1, 8), S(-5, 11), S(-10, 18), S(-7, 20), }},
  {{ S(-1, 0), S(3, -67), S(-1, 22), S(-3, 25), S(-7, 8), S(-13, 10), S(-10, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1421, 912, -23, -4
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(88);
inline VParam WINNABLE_PAWN_ENDGAME = V(78);
inline VParam WINNABLE_BIAS = V(-401);

// Epoch duration: 9.68486s
// clang-format on
}  // namespace Clockwork
