#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(193, 387);
inline const PParam KNIGHT_MAT = S(820, 961);
inline const PParam BISHOP_MAT = S(944, 1074);
inline const PParam ROOK_MAT   = S(1142, 1726);
inline const PParam QUEEN_MAT  = S(2670, 2716);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 15);
inline const PParam BISHOP_PAIR_VAL   = S(48, 208);
inline const PParam ROOK_OPEN_VAL     = S(118, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 27);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);
inline const PParam RESTRICTED_SQUARES = S(-24, -4);
inline const std::array<PParam, 5> KNIGHT_CLOSED_BONUS = {
    S(79, -46), S(51, 71), S(68, 83), S(73, 104), S(82, 125),
};

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -19);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 39);
inline const PParam OUTPOST_BISHOP_VAL    = S(59, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(48, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -4), S(30, 30), S(60, 52), S(142, 145), S(382, 210), S(437, 528),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 34), S(46, 27), S(63, 50), S(121, 141), S(416, 82),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-105, -186), S(-106, -157), S(-79, -49), S(-22, 49), S(72, 187), S(259, 266),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(28, -38), S(24, -2), S(15, 32), S(2, 111), S(82, 203), S(262, 247),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -21), S(1, 20), S(0, -16), S(2, -47), S(-3, -136), S(-249, -218),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 185), S(-5, 156), S(1, 86), S(8, 52), S(15, 53), S(52, 48), S(44, 31),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-271, -43), S(-13, 34), S(-5, 87), S(36, 111), S(57, 131), S(68, 137), S(47, 135),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-176, -173), S(-87, -69), S(-45, -2), S(-12, 19), S(22, 36), S(44, 61), S(67, 64), S(89, 75), S(124, 17),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-74, -235), S(-31, -66), S(23, 0), S(46, 44), S(68, 76), S(80, 99), S(86, 115), S(95, 120), S(97, 135), S(115, 114), S(117, 116), S(167, 51), S(162, 60), S(196, 1),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(98, -104), S(14, 53), S(36, 79), S(53, 90), S(63, 103), S(68, 114), S(73, 125), S(80, 127), S(85, 137), S(93, 140), S(102, 141), S(106, 145), S(112, 140), S(123, 114), S(201, 15),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-123, -85), S(16, -19), S(43, 88), S(62, 196), S(77, 236), S(86, 276), S(92, 305), S(100, 313), S(103, 335), S(105, 350), S(111, 355), S(113, 364), S(118, 364), S(119, 368), S(121, 364), S(118, 365), S(116, 364), S(119, 354), S(126, 338), S(128, 331), S(126, 314), S(138, 282), S(118, 287), S(106, 238), S(80, 226), S(65, 205), S(14, 214), S(17, 181),
};

inline const std::array<PParam, 7> KNIGHT_REACHABILITY = {
    S(71, -49), S(40, 40), S(38, 46), S(32, 58), S(18, 74), S(-3, 81), S(0, 0),
};

inline const PParam PAWN_THREAT_KNIGHT = S(203, 106);
inline const PParam PAWN_THREAT_BISHOP = S(196, 141);
inline const PParam PAWN_THREAT_ROOK   = S(199, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -8);

inline const PParam KNIGHT_THREAT_BISHOP = S(111, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(230, 69);
inline const PParam KNIGHT_THREAT_QUEEN  = S(159, -17);

inline const PParam BISHOP_THREAT_KNIGHT = S(99, 63);
inline const PParam BISHOP_THREAT_ROOK   = S(210, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(171, 93);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(15, -29), S(-1, 2), S(-4, -5), S(-8, -14), S(-12, -22), S(-15, -29), S(-17, -39), S(-23, -40), S(-38, -36),
};

inline const PParam ROOK_LINEUP = S(15, 62);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(230, 182),    S(65, 241),     S(190, 200),    S(169, 179),    S(217, 110),    S(114, 190),    S(58, 229),     S(201, 171),    //
    S(49, 19),      S(73, 41),      S(69, 21),      S(46, -31),     S(41, -61),     S(21, -19),     S(2, 34),       S(-26, 55),     //
    S(24, -17),     S(-2, -4),      S(28, -42),     S(17, -69),     S(12, -81),     S(-11, -54),    S(-57, -9),     S(-51, 11),     //
    S(-9, -63),     S(-31, -33),    S(-4, -57),     S(-15, -66),    S(-37, -66),    S(-42, -50),    S(-99, -13),    S(-86, -24),    //
    S(-7, -93),     S(26, -90),     S(7, -42),      S(-5, -46),     S(-34, -53),    S(-52, -47),    S(-84, -33),    S(-83, -41),    //
    S(14, -91),     S(90, -87),     S(67, -46),     S(28, -16),     S(-1, -32),     S(-22, -44),    S(-55, -23),    S(-65, -27),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-347, -306),  S(-297, 49),    S(-341, 23),    S(-43, 49),     S(-110, 46),    S(-251, 45),    S(-428, 124),   S(-416, -210),  //
    S(-74, 23),     S(-44, 38),     S(66, 2),       S(79, 16),      S(68, 31),      S(1, 36),       S(-60, 42),     S(-84, 27),     //
    S(2, 1),        S(14, 18),      S(59, 45),      S(76, 43),      S(47, 62),      S(1, 61),       S(-20, 29),     S(-63, 28),     //
    S(73, 15),      S(83, 32),      S(89, 55),      S(98, 80),      S(105, 80),     S(54, 69),      S(30, 45),      S(16, 27),      //
    S(58, 8),       S(93, -4),      S(80, 45),      S(76, 63),      S(55, 67),      S(58, 51),      S(43, 13),      S(3, 22),       //
    S(-5, -28),     S(20, -11),     S(20, 14),      S(39, 34),      S(32, 32),      S(-0, 17),      S(-8, -6),      S(-47, -32),    //
    S(16, -27),     S(23, -23),     S(-3, -13),     S(10, 1),       S(7, -2),       S(-20, -44),    S(-40, -18),    S(-55, -95),    //
    S(-58, -76),    S(-8, -18),     S(13, -49),     S(31, -46),     S(13, -26),     S(-23, -51),    S(-36, -27),    S(-80, -111),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-162, 75),    S(-162, 80),    S(-441, 134),   S(-284, 76),    S(-285, 82),    S(-303, 73),    S(-208, 72),    S(-137, 57),    //
    S(-54, 6),      S(-83, 78),     S(-43, 25),     S(-95, 51),     S(-73, 42),     S(-56, 40),     S(-20, 35),     S(-58, 9),      //
    S(22, 23),      S(14, 45),      S(35, 48),      S(22, 49),      S(2, 47),       S(7, 51),       S(10, 37),      S(2, 20),       //
    S(9, 3),        S(45, 21),      S(58, 44),      S(66, 78),      S(98, 64),      S(37, 38),      S(36, 8),       S(-10, 10),     //
    S(41, -40),     S(51, -1),      S(72, 28),      S(86, 51),      S(67, 62),      S(56, 47),      S(15, 23),      S(7, -18),      //
    S(59, -23),     S(80, -7),      S(94, 21),      S(60, 45),      S(56, 26),      S(55, 36),      S(60, 18),      S(8, 4),        //
    S(28, -62),     S(108, -40),    S(70, -18),     S(46, 5),       S(29, 8),       S(43, -24),     S(40, -33),     S(39, -40),     //
    S(48, -60),     S(30, -30),     S(25, 5),       S(45, -20),     S(29, -8),      S(34, 24),      S(45, -9),      S(40, -37),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(197, 84),     S(229, 96),     S(192, 104),    S(181, 84),     S(217, 79),     S(181, 92),     S(198, 101),    S(180, 109),    //
    S(85, 156),     S(171, 148),    S(234, 111),    S(170, 130),    S(207, 123),    S(178, 128),    S(118, 162),    S(100, 166),    //
    S(47, 157),     S(175, 123),    S(216, 90),     S(183, 94),     S(181, 114),    S(138, 135),    S(138, 140),    S(75, 171),     //
    S(16, 131),     S(108, 125),    S(133, 102),    S(110, 111),    S(138, 105),    S(94, 138),     S(97, 135),     S(25, 160),     //
    S(-8, 66),      S(74, 67),      S(62, 84),      S(33, 88),      S(40, 102),     S(32, 121),     S(6, 120),      S(-10, 114),    //
    S(7, -6),       S(82, 14),      S(71, 27),      S(48, 31),      S(60, 35),      S(27, 70),      S(37, 47),      S(-5, 58),      //
    S(-88, -0),     S(53, -38),     S(57, -15),     S(46, 7),       S(48, 12),      S(36, 22),      S(27, 10),      S(-5, 24),      //
    S(-25, -16),    S(1, 3),        S(60, -10),     S(71, -13),     S(70, -2),      S(50, 16),      S(46, 11),      S(25, 17),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 116),     S(192, 44),     S(115, 144),    S(54, 233),     S(87, 195),     S(84, 173),     S(114, 84),     S(39, 149),     //
    S(73, 170),     S(89, 246),     S(61, 264),     S(-70, 341),    S(-25, 329),    S(15, 291),     S(61, 184),     S(42, 176),     //
    S(43, 203),     S(65, 263),     S(41, 305),     S(3, 318),      S(12, 322),     S(62, 250),     S(78, 191),     S(89, 107),     //
    S(62, 102),     S(61, 188),     S(14, 253),     S(-1, 315),     S(13, 326),     S(47, 217),     S(89, 148),     S(63, 122),     //
    S(62, 72),      S(46, 133),     S(24, 192),     S(0, 253),      S(13, 281),     S(28, 236),     S(55, 145),     S(72, 83),      //
    S(56, 0),       S(69, 48),      S(63, 121),     S(45, 131),     S(49, 153),     S(49, 188),     S(68, 129),     S(63, 78),      //
    S(29, -106),    S(43, -53),     S(50, -4),      S(79, 16),      S(68, 68),      S(69, 48),      S(39, 89),      S(60, 56),      //
    S(13, -95),     S(37, -216),    S(66, -216),    S(81, -116),    S(74, -21),     S(80, -61),     S(76, -33),     S(49, -6),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-50, -217),   S(312, 236),    S(218, 202),    S(63, 124),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(238, 23),     S(325, 197),    S(195, 209),    S(126, 102),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(182, 84),     S(242, 159),    S(150, 185),    S(101, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, 36),      S(133, 100),    S(18, 152),     S(-13, 163),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-93, -13),    S(-0, 49),      S(-56, 103),    S(-141, 163),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-33, -44),    S(28, 8),       S(-65, 77),     S(-112, 121),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(18, -85),     S(28, -24),     S(-44, 23),     S(-108, 70),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -173),   S(1, -87),      S(-81, -46),    S(-74, -60),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-79, -532);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -26), S(14, -13), S(14, -6), S(5, -12), S(1, -27),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -15), S(4, -18), S(4, -3), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -5);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -9);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 38), S(-3, 48), S(-0, -19), S(11, -27), S(9, -15), S(-2, -10), S(-2, 51), }},
  {{ S(-1, 158), S(-19, -225), S(-20, -7), S(-8, 50), S(-7, 65), S(-18, -14), S(-18, -211), }},
  {{ S(-3, 134), S(-9, -211), S(-9, 121), S(-3, 102), S(-3, 101), S(-9, 128), S(-8, -188), }},
  {{ S(8, 122), S(-9, 80), S(2, 92), S(8, 72), S(6, 74), S(-0, 90), S(-6, 80), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 67), S(-11, 54), S(-10, 76), S(-2, 81), S(3, 33),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 114), S(-8, 35), S(-9, 39), S(-6, 34), S(-6, 31), S(-8, 38), S(-9, 47), }},
  {{ S(9, 6), S(1, -30), S(-8, -19), S(-3, -47), S(-4, -49), S(-7, -18), S(1, -22), }},
  {{ S(0, 57), S(-4, 34), S(-7, 39), S(-4, 35), S(-3, 18), S(-7, 34), S(-3, 22), }},
  {{ S(-1, 51), S(-6, 30), S(-11, 34), S(-5, 46), S(-4, 46), S(-10, 30), S(-8, 34), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1075, 249, -15, 94
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(224);
inline VParam WINNABLE_BIAS = V(-659);

// Epoch duration: 5.26844s
// clang-format on
}  // namespace Clockwork
