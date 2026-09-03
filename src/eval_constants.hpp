#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(202, 507);
inline const PParam KNIGHT_MAT = S(821, 1596);
inline const PParam BISHOP_MAT = S(872, 1682);
inline const PParam ROOK_MAT   = S(1041, 2670);
inline const PParam QUEEN_MAT  = S(2419, 4123);

inline const PParam TEMPO_VAL  = S(69, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-8, -7);
inline const PParam BISHOP_PAIR_VAL   = S(60, 234);
inline const PParam ROOK_OPEN_VAL     = S(103, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(30, 17);
inline const PParam MINOR_BEHIND_PAWN = S(19, 56);
inline const PParam RESTRICTED_SQUARES = S(19, 2);

inline const PParam DOUBLED_PAWN_VAL = S(-4, -79);
inline const PParam ISOLATED_PAWN_VAL = S(-26, -42);

inline const PParam POTENTIAL_CHECKER_VAL = S(-32, -27);
inline const PParam OUTPOST_KNIGHT_VAL    = S(58, 41);
inline const PParam OUTPOST_BISHOP_VAL    = S(35, 27);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 55);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(23, 63);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -43);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(33, 18), S(43, 34), S(77, 71), S(132, 236), S(394, 408), S(681, 828),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(63, 45), S(51, 32), S(77, 48), S(86, 154), S(391, 111),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-86, -252), S(-82, -206), S(-62, -78), S(-8, 36), S(105, 211), S(222, 384),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-93, 42), S(-91, 28), S(-63, 99), S(-78, 253), S(-64, 368), S(49, 248),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-16, 75), S(-38, 55), S(-63, 104), S(-19, 153), S(80, 176), S(53, 208),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(33, -34), S(24, 3), S(17, 37), S(30, 95), S(71, 264), S(337, 220),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(19, -28), S(5, 17), S(-4, -33), S(6, -82), S(-14, -200), S(-176, -481),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(33, 228), S(9, 181), S(3, 110), S(22, 83), S(32, 78), S(78, 73), S(61, 52),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-127, -54), S(31, -6), S(8, 106), S(40, 167), S(56, 202), S(66, 208), S(49, 187),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-96, -402), S(-37, -143), S(3, -16), S(21, 27), S(49, 55), S(61, 82), S(84, 82), S(103, 98), S(107, 41),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-51, -329), S(-15, -141), S(38, -43), S(54, 8), S(77, 49), S(91, 75), S(89, 101), S(94, 129), S(96, 136), S(92, 148), S(110, 137), S(99, 121), S(124, 135), S(83, 85),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(93, -216), S(39, -5), S(57, 26), S(61, 52), S(67, 72), S(74, 78), S(78, 95), S(86, 98), S(91, 108), S(99, 110), S(102, 117), S(99, 126), S(101, 133), S(105, 112), S(94, 68),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-200, -209), S(-31, -84), S(6, 68), S(16, 208), S(29, 254), S(28, 300), S(32, 328), S(42, 347), S(45, 361), S(53, 374), S(56, 388), S(60, 395), S(63, 403), S(66, 411), S(66, 411), S(63, 411), S(62, 413), S(63, 405), S(61, 399), S(66, 393), S(58, 387), S(70, 363), S(33, 387), S(-4, 385), S(-44, 378), S(-74, 406), S(-136, 432), S(-91, 377),
};

inline const PParam PAWN_THREAT_KNIGHT = S(182, 139);
inline const PParam PAWN_THREAT_BISHOP = S(148, 208);
inline const PParam PAWN_THREAT_ROOK   = S(176, 138);
inline const PParam PAWN_THREAT_QUEEN  = S(162, 22);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 65), S(90, 88), S(101, 116), S(155, 68), S(152, 4), }},
  {{ S(1, 60), S(76, 83), S(94, 109), S(199, 590), S(152, 52), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(17, 64), S(37, 106), S(54, 118), S(20, 22), S(153, -67), }},
  {{ S(7, 56), S(55, 82), S(85, 78), S(17, 8), S(355, 893), }},
}};
inline const PParam KING_THREAT  = S(-4, 144);
inline const PParam HANGING_PAWN  = S(40, 99);
inline const PParam HANGING_NON_PAWN  = S(50, 14);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(29, -18), S(12, -4),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(33, 47), S(114, -103),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(25, 7), S(52, -2),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-10, -3), S(5, -12), S(3, -29), S(-3, -36), S(-4, -46), S(-3, -50), S(-9, -50), S(-18, -44), S(-34, -66),
};

inline const PParam ROOK_LINEUP = S(17, 74);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(159, 251),    S(58, 397),     S(52, 358),     S(156, 281),    S(207, 181),    S(155, 193),    S(130, 231),    S(220, 182),    //
    S(46, 41),      S(58, 101),     S(29, 47),      S(48, 15),      S(46, -36),     S(37, -2),      S(27, 24),      S(-26, 52),     //
    S(23, -20),     S(7, -19),      S(48, -76),     S(47, -62),     S(31, -75),     S(1, -79),      S(-22, -56),    S(-38, -25),    //
    S(-15, -69),    S(-26, -32),    S(12, -69),     S(11, -66),     S(-15, -79),    S(-19, -80),    S(-76, -56),    S(-71, -52),    //
    S(-3, -90),     S(30, -90),     S(8, -45),      S(-7, -24),     S(-43, -59),    S(-56, -68),    S(-81, -75),    S(-77, -82),    //
    S(16, -94),     S(95, -73),     S(82, -30),     S(30, -9),      S(3, -27),      S(-13, -44),    S(-53, -51),    S(-58, -62),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-253, -493),  S(-253, 59),    S(-249, -10),   S(6, 49),       S(-83, 45),     S(-253, 89),    S(-342, 103),   S(-347, -393),  //
    S(-0, -5),      S(9, 28),       S(78, 21),      S(80, 65),      S(83, 52),      S(52, 25),      S(-11, 23),     S(-24, 29),     //
    S(48, -18),     S(46, 31),      S(35, 58),      S(68, 72),      S(60, 76),      S(38, 56),      S(15, 24),      S(-32, 12),     //
    S(92, 34),      S(85, 40),      S(100, 70),     S(102, 100),    S(88, 81),      S(72, 59),      S(64, 30),      S(56, 43),      //
    S(81, 15),      S(89, 10),      S(79, 41),      S(88, 65),      S(69, 73),      S(71, 55),      S(61, 16),      S(37, 28),      //
    S(3, -35),      S(52, -16),     S(60, 22),      S(46, 43),      S(52, 44),      S(36, 12),      S(20, -20),     S(-23, -43),    //
    S(33, -18),     S(35, -5),      S(20, -24),     S(25, 4),       S(29, 8),       S(-19, -62),    S(-48, -14),    S(-55, -79),    //
    S(-28, -90),    S(-4, -30),     S(21, -39),     S(27, -41),     S(14, -25),     S(-24, -58),    S(-8, -24),     S(-74, -143),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-126, 21),    S(-202, 86),    S(-392, 164),   S(-271, 96),    S(-296, 146),   S(-299, 149),   S(-225, 127),   S(-121, 89),    //
    S(-41, -23),    S(-73, 82),     S(-47, 52),     S(-65, 62),     S(-75, 71),     S(-35, 54),     S(3, 44),       S(-49, 27),     //
    S(35, 14),      S(-1, 46),      S(17, 61),      S(16, 41),      S(25, 43),      S(12, 38),      S(8, 27),       S(19, 15),      //
    S(8, -25),      S(44, 24),      S(46, 26),      S(54, 47),      S(108, 49),     S(23, 8),       S(49, 3),       S(3, 0),        //
    S(34, -40),     S(39, -9),      S(69, 10),      S(92, 25),      S(65, 23),      S(59, 30),      S(19, -1),      S(6, -41),      //
    S(63, -29),     S(59, -32),     S(83, 6),       S(73, 24),      S(75, 28),      S(46, 7),       S(53, -1),      S(26, -19),     //
    S(33, -69),     S(110, -66),    S(66, -20),     S(38, -2),      S(30, -8),      S(51, -45),     S(51, -63),     S(24, -59),     //
    S(48, -61),     S(36, -24),     S(27, -19),     S(43, -21),     S(22, -26),     S(40, 6),       S(47, -40),     S(33, -70),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(173, 117),    S(209, 139),    S(165, 170),    S(149, 136),    S(207, 88),     S(163, 116),    S(186, 151),    S(153, 149),    //
    S(89, 144),     S(138, 141),    S(188, 123),    S(137, 101),    S(176, 81),     S(135, 108),    S(85, 142),     S(85, 157),     //
    S(63, 141),     S(171, 83),     S(212, 75),     S(176, 51),     S(181, 61),     S(116, 93),     S(110, 119),    S(76, 172),     //
    S(12, 102),     S(85, 107),     S(107, 87),     S(90, 86),      S(137, 73),     S(92, 112),     S(81, 129),     S(19, 156),     //
    S(-10, 52),     S(69, 55),      S(64, 80),      S(27, 81),      S(39, 84),      S(23, 104),     S(21, 118),     S(3, 136),      //
    S(17, -21),     S(82, -6),      S(77, 27),      S(49, 37),      S(60, 41),      S(33, 62),      S(36, 56),      S(2, 75),       //
    S(-77, -49),    S(53, -77),     S(75, -35),     S(61, -6),      S(63, -9),      S(42, 9),       S(39, 2),       S(8, 6),        //
    S(10, -79),     S(14, -32),     S(77, -47),     S(96, -44),     S(84, -32),     S(81, -9),      S(71, -15),     S(60, -13),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 153),     S(146, 153),    S(53, 292),     S(-8, 389),     S(26, 338),     S(72, 261),     S(74, 176),     S(23, 204),     //
    S(66, 188),     S(73, 231),     S(33, 321),     S(-90, 430),    S(-36, 404),    S(14, 281),     S(59, 169),     S(36, 145),     //
    S(27, 242),     S(64, 262),     S(35, 345),     S(-7, 370),     S(13, 361),     S(62, 262),     S(83, 148),     S(64, 113),     //
    S(25, 181),     S(26, 241),     S(-9, 309),     S(-10, 360),    S(10, 352),     S(30, 247),     S(66, 153),     S(47, 117),     //
    S(20, 154),     S(6, 168),      S(9, 225),      S(-24, 283),    S(3, 317),      S(13, 242),     S(23, 175),     S(30, 73),      //
    S(12, 57),      S(31, 68),      S(30, 135),     S(2, 155),      S(12, 159),     S(27, 189),     S(42, 110),     S(25, 101),     //
    S(-10, -93),    S(11, -89),     S(28, -20),     S(30, 5),       S(42, 46),      S(42, 21),      S(6, 55),       S(11, 26),      //
    S(-33, -75),    S(-10, -238),   S(17, -241),    S(27, -129),    S(33, -62),     S(27, -76),     S(25, -73),     S(-5, -8),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(168, -556),   S(467, 80),     S(302, 169),    S(29, 183),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(370, -186),   S(342, 166),    S(191, 186),    S(28, 156),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(192, 32),     S(209, 160),    S(93, 187),     S(-57, 177),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(25, -15),     S(94, 93),      S(-42, 156),    S(-140, 183),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-98, -5),     S(-38, 45),     S(-89, 132),    S(-205, 174),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-48, -16),    S(20, 43),      S(-69, 107),    S(-148, 132),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(24, -58),     S(43, 9),       S(-44, 62),     S(-121, 90),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -189),   S(7, -65),      S(-85, -2),     S(-61, -38),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-112, -449);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(11, 14), S(6, 8), S(3, 4), S(2, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(7, -9), S(4, 7), S(4, 6), S(2, -1), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(2, -2);
inline const PParam KS_FLANK_DEFENSE = S(-2, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-1, 3);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(9, -18), S(-9, 2), S(-6, -12), S(9, -13), S(18, -36), S(-4, -55), S(1, -45), }},
  {{ S(2, 3), S(-19, 5), S(-14, 9), S(-5, 14), S(-11, -2), S(-21, -24), S(-23, -17), }},
  {{ S(-12, 2), S(-13, -10), S(-11, 13), S(-6, 11), S(-7, 9), S(-2, -14), S(-26, -43), }},
  {{ S(2, 8), S(-16, 20), S(-11, 47), S(-8, 44), S(-1, 31), S(3, 12), S(1, -27), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(5, 22), S(-6, 15), S(-12, 8), S(-1, 23), S(-3, 50),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-0, 13), S(-52, -121), S(-9, -35), S(3, -5), S(1, 6), S(-9, 7), S(-4, 10), }},
  {{ S(11, -3), S(-32, -129), S(-7, -31), S(-8, -10), S(1, -9), S(-11, 6), S(1, 5), }},
  {{ S(-10, 8), S(-15, -75), S(14, 0), S(-5, 1), S(-4, 8), S(-7, 30), S(-9, 18), }},
  {{ S(-4, -3), S(10, -58), S(-0, 17), S(-12, 32), S(-6, 17), S(-14, 9), S(-7, 24), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1427, 911, -28, -10
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(98);
inline VParam WINNABLE_PAWN_ENDGAME = V(116);
inline VParam WINNABLE_BIAS = V(-437);

// clang-format on
}  // namespace Clockwork
