#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(196, 501);
inline const PParam KNIGHT_MAT = S(826, 1543);
inline const PParam BISHOP_MAT = S(868, 1628);
inline const PParam ROOK_MAT   = S(1034, 2547);
inline const PParam QUEEN_MAT  = S(2453, 3868);

inline const PParam TEMPO_VAL  = S(69, 50);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -4);
inline const PParam BISHOP_PAIR_VAL   = S(64, 231);
inline const PParam ROOK_OPEN_VAL     = S(109, -2);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 13);
inline const PParam MINOR_BEHIND_PAWN = S(15, 38);
inline const PParam RESTRICTED_SQUARES = S(20, 4);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -36);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 42);
inline const PParam OUTPOST_BISHOP_VAL    = S(41, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 48);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(22, 59);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -1), S(32, 36), S(60, 62), S(128, 194), S(442, 264), S(569, 549),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 34), S(38, 25), S(53, 54), S(100, 169), S(410, 89),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-88, -268), S(-89, -232), S(-66, -94), S(-26, 44), S(70, 239), S(215, 412),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -39), S(25, -1), S(12, 41), S(11, 121), S(78, 247), S(108, 453),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -37), S(2, 9), S(-5, -23), S(-1, -59), S(-9, -167), S(-168, -336),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(15, 237), S(2, 189), S(-2, 113), S(10, 71), S(20, 74), S(59, 73), S(55, 47),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-138, -59), S(16, 4), S(1, 108), S(27, 158), S(39, 194), S(52, 200), S(32, 191),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-83, -373), S(1, -91), S(7, -12), S(26, 27), S(51, 58), S(65, 94), S(84, 102), S(103, 111), S(122, 65),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-63, -285), S(-3, -71), S(38, -20), S(58, 19), S(76, 59), S(87, 88), S(92, 110), S(95, 130), S(98, 143), S(104, 150), S(111, 146), S(130, 128), S(131, 128), S(112, 102),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(96, -160), S(44, -20), S(49, 45), S(65, 61), S(71, 79), S(75, 93), S(79, 108), S(85, 113), S(90, 125), S(96, 132), S(101, 136), S(103, 144), S(105, 149), S(108, 139), S(133, 94),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-206, -161), S(-49, 31), S(-37, 187), S(0, 258), S(15, 293), S(20, 347), S(27, 379), S(33, 395), S(37, 420), S(40, 438), S(45, 447), S(49, 454), S(53, 461), S(55, 465), S(55, 469), S(55, 471), S(52, 471), S(57, 461), S(56, 460), S(59, 453), S(56, 436), S(60, 418), S(28, 445), S(-17, 433), S(-46, 435), S(-75, 452), S(-118, 463), S(-86, 392),
};

inline const std::array<PParam, 5> KNIGHT_TRAP_FACTOR = {
    S(-79, -63), S(-48, -125), S(-65, -101), S(-32, -70), S(-23, -63),
};
inline const std::array<PParam, 5> BISHOP_TRAP_FACTOR = {
    S(-9, -13), S(-34, -106), S(-10, -72), S(-17, -54), S(-14, -22),
};
inline const std::array<PParam, 6> ROOK_TRAP_FACTOR = {
    S(-44, 79), S(9, 5), S(-29, -9), S(-12, 8), S(-24, -18), S(-16, -3),
};
inline const std::array<PParam, 9> QUEEN_TRAP_FACTOR = {
    S(-6, -20), S(58, -20), S(26, -167), S(-8, -152), S(-14, -153), S(-29, -112), S(-10, -112), S(-16, -8), S(3, -148),
};

inline const PParam PAWN_THREAT_KNIGHT = S(194, 147);
inline const PParam PAWN_THREAT_BISHOP = S(170, 212);
inline const PParam PAWN_THREAT_ROOK   = S(195, 137);
inline const PParam PAWN_THREAT_QUEEN  = S(156, 17);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(6, 56), S(91, 90), S(102, 124), S(202, 124), S(158, 11), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 57), S(52, 93), S(72, 94), S(21, -6), S(148, -52), S(0, 0),
};
inline const PParam KING_THREAT  = S(-19, 157);
inline const PParam HANGING_PAWN  = S(32, 88);
inline const PParam HANGING_NON_PAWN  = S(69, 22);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -19), S(25, -0),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(40, 45), S(123, -120),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(36, 12), S(49, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -16), S(4, -15), S(-0, -21), S(-5, -29), S(-11, -37), S(-16, -44), S(-18, -56), S(-23, -60), S(-27, -76),
};

inline const PParam ROOK_LINEUP = S(17, 78);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(188, 277),    S(42, 393),     S(66, 363),     S(146, 260),    S(196, 159),    S(124, 227),    S(88, 270),     S(229, 204),    //
    S(38, 70),      S(50, 111),     S(29, 54),      S(46, -24),     S(37, -56),     S(9, -17),      S(7, 35),       S(-22, 66),     //
    S(34, -6),      S(8, 1),        S(40, -45),     S(25, -68),     S(16, -87),     S(-2, -71),     S(-42, -33),    S(-41, 5),      //
    S(-7, -69),     S(-31, -39),    S(2, -61),      S(-6, -74),     S(-28, -84),    S(-38, -71),    S(-85, -49),    S(-79, -46),    //
    S(-9, -108),    S(23, -105),    S(10, -47),     S(-6, -53),     S(-34, -62),    S(-49, -71),    S(-80, -66),    S(-81, -70),    //
    S(11, -105),    S(86, -96),     S(73, -44),     S(31, -20),     S(-1, -39),     S(-21, -63),    S(-48, -55),    S(-62, -53),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-268, -510),  S(-256, 53),    S(-268, -74),   S(33, 19),      S(-93, 41),     S(-262, 75),    S(-371, 120),   S(-357, -402),  //
    S(-10, -3),     S(-1, 37),      S(98, 20),      S(80, 57),      S(84, 50),      S(55, 23),      S(-28, 32),     S(-34, 18),     //
    S(46, -27),     S(38, 31),      S(71, 48),      S(72, 71),      S(62, 68),      S(23, 55),      S(9, 35),       S(-44, 21),     //
    S(92, 26),      S(89, 52),      S(102, 67),     S(100, 112),    S(105, 113),    S(69, 76),      S(50, 44),      S(35, 37),      //
    S(70, 17),      S(102, 8),      S(98, 53),      S(90, 84),      S(77, 87),      S(73, 68),      S(59, 16),      S(16, 33),      //
    S(20, -32),     S(49, -17),     S(51, 25),      S(63, 60),      S(57, 57),      S(32, 19),      S(17, -6),      S(-25, -29),    //
    S(44, -22),     S(45, -6),      S(30, -11),     S(38, 16),      S(34, 13),      S(7, -35),      S(-25, 1),      S(-36, -88),    //
    S(-50, -75),    S(8, -24),      S(28, -36),     S(40, -22),     S(23, -7),      S(-14, -39),    S(-20, -25),    S(-75, -131),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-129, 30),    S(-176, 113),   S(-421, 187),   S(-255, 88),    S(-290, 142),   S(-295, 152),   S(-208, 128),   S(-123, 74),    //
    S(-30, -8),     S(-77, 100),    S(-36, 61),     S(-66, 71),     S(-65, 77),     S(-33, 48),     S(-7, 45),      S(-43, 27),     //
    S(35, 31),      S(16, 68),      S(33, 78),      S(27, 69),      S(24, 51),      S(18, 56),      S(15, 51),      S(16, 21),      //
    S(16, 5),       S(52, 30),      S(64, 47),      S(76, 67),      S(101, 53),     S(47, 26),      S(51, 2),       S(2, 5),        //
    S(43, -38),     S(48, 10),      S(80, 21),      S(95, 33),      S(78, 50),      S(69, 30),      S(22, 16),      S(19, -27),     //
    S(62, -25),     S(86, -19),     S(100, 11),     S(66, 39),      S(65, 21),      S(62, 23),      S(67, 2),       S(19, -13),     //
    S(33, -69),     S(118, -42),    S(76, -11),     S(53, 6),       S(35, 10),      S(56, -37),     S(52, -41),     S(45, -44),     //
    S(49, -71),     S(24, -5),      S(28, -1),      S(47, -24),     S(30, -13),     S(38, 21),      S(46, -10),     S(40, -49),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(191, 92),     S(222, 108),    S(164, 141),    S(150, 120),    S(216, 70),     S(178, 95),     S(190, 102),    S(166, 105),    //
    S(95, 150),     S(148, 149),    S(205, 113),    S(150, 114),    S(191, 95),     S(152, 119),    S(101, 151),    S(98, 151),     //
    S(63, 143),     S(181, 91),     S(206, 73),     S(183, 54),     S(182, 75),     S(122, 117),    S(125, 124),    S(71, 164),     //
    S(36, 113),     S(96, 120),     S(124, 91),     S(97, 96),      S(127, 79),     S(87, 124),     S(80, 133),     S(25, 157),     //
    S(3, 56),       S(68, 62),      S(61, 79),      S(31, 88),      S(40, 93),      S(28, 120),     S(10, 118),     S(-10, 122),    //
    S(17, -21),     S(84, 4),       S(75, 26),      S(54, 35),      S(64, 43),      S(37, 71),      S(38, 54),      S(-6, 62),      //
    S(-66, -16),    S(63, -57),     S(69, -21),     S(57, 11),      S(61, 10),      S(45, 27),      S(34, 11),      S(1, 21),       //
    S(-3, -42),     S(15, -3),      S(83, -19),     S(92, -22),     S(92, -15),     S(70, 10),      S(67, -1),      S(47, 5),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(76, 170),     S(149, 143),    S(60, 283),     S(5, 377),      S(49, 322),     S(77, 238),     S(70, 164),     S(9, 216),      //
    S(59, 193),     S(80, 232),     S(47, 302),     S(-87, 434),    S(-35, 394),    S(10, 298),     S(54, 168),     S(26, 170),     //
    S(17, 245),     S(54, 275),     S(17, 359),     S(-20, 394),    S(3, 371),      S(50, 256),     S(81, 159),     S(60, 118),     //
    S(17, 177),     S(18, 261),     S(-13, 308),    S(-24, 376),    S(-10, 378),    S(20, 245),     S(58, 156),     S(27, 134),     //
    S(8, 170),      S(6, 190),      S(-4, 239),     S(-29, 304),    S(-19, 327),    S(6, 253),      S(8, 191),      S(31, 101),     //
    S(3, 71),       S(31, 86),      S(29, 156),     S(5, 178),      S(13, 187),     S(16, 211),     S(35, 140),     S(14, 118),     //
    S(-26, -67),    S(2, -61),      S(10, 7),       S(34, 44),      S(29, 84),      S(30, 62),      S(5, 92),       S(14, 75),      //
    S(-35, -53),    S(-22, -194),   S(10, -201),    S(20, -85),     S(30, -13),     S(31, -49),     S(27, -24),     S(-1, 20),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(100, -577),   S(484, 4),      S(297, 176),    S(2, 152),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(343, -179),   S(379, 134),    S(209, 178),    S(20, 136),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(189, 42),     S(229, 158),    S(122, 188),    S(-37, 164),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(18, 10),      S(97, 112),     S(-15, 159),    S(-91, 176),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-114, -3),    S(-31, 77),     S(-87, 139),    S(-172, 187),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-52, -32),    S(15, 33),      S(-71, 115),    S(-124, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -82),     S(30, -6),      S(-34, 56),     S(-110, 111),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -199),   S(4, -83),      S(-77, -17),    S(-79, -36),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-86, -436);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -4), S(10, 11), S(10, 5), S(5, 1), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 4), S(2, 2), S(3, -0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -19), S(-7, 6), S(-3, -8), S(8, -15), S(12, -26), S(6, -53), S(-5, -44), }},
  {{ S(2, 3), S(-22, 1), S(-17, 9), S(-10, 17), S(-7, 8), S(-10, -10), S(-20, -23), }},
  {{ S(-3, -1), S(-11, -10), S(-13, 19), S(-8, 18), S(-7, 11), S(-8, -15), S(-25, -42), }},
  {{ S(7, 10), S(-10, 19), S(-7, 41), S(-2, 44), S(-2, 40), S(3, 18), S(8, -13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 25), S(-5, 3), S(-8, 11), S(-6, 28), S(2, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 11), S(-46, -144), S(-9, -44), S(-0, 5), S(-3, 4), S(-6, 11), S(-5, 9), }},
  {{ S(9, 0), S(-24, -131), S(-6, -31), S(-4, 1), S(-1, -2), S(-8, 4), S(1, 3), }},
  {{ S(-0, 10), S(-10, -81), S(6, -15), S(0, 9), S(-3, 10), S(-10, 19), S(-6, 20), }},
  {{ S(1, -1), S(2, -60), S(-1, 27), S(-3, 25), S(-6, 9), S(-13, 11), S(-10, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1367, 856, -19, -7
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(84);
inline VParam WINNABLE_PAWN_ENDGAME = V(104);
inline VParam WINNABLE_BIAS = V(-377);

// Epoch duration: 6.65615s
// clang-format on
}  // namespace Clockwork
