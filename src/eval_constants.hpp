#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(210, 402);
inline const PParam KNIGHT_MAT = S(910, 1019);
inline const PParam BISHOP_MAT = S(947, 1073);
inline const PParam ROOK_MAT   = S(1149, 1720);
inline const PParam QUEEN_MAT  = S(2683, 2711);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_PAIR_VAL   = S(52, 200);
inline const PParam ROOK_OPEN_VAL     = S(118, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 27);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);
inline const PParam RESTRICTED_SQUARES = S(-24, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -18);
inline const PParam BACKWARD_PAWN_VAL = S(-22, -56);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(59, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -2), S(32, 27), S(61, 48), S(144, 141), S(381, 208), S(437, 526),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(25, -24), S(25, -30), S(40, -6), S(99, 85), S(386, 68),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-106, -182), S(-107, -154), S(-79, -49), S(-22, 48), S(74, 183), S(254, 253),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -37), S(21, 2), S(15, 32), S(1, 111), S(82, 203), S(256, 254),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -16), S(0, 24), S(-2, -10), S(0, -40), S(-5, -128), S(-229, -158),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 179), S(-6, 152), S(0, 84), S(7, 49), S(14, 50), S(51, 46), S(44, 28),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-274, -36), S(-11, 34), S(-4, 89), S(38, 112), S(59, 130), S(70, 135), S(49, 134),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-111, -244), S(-46, -75), S(-15, 13), S(12, 44), S(44, 60), S(60, 89), S(83, 84), S(103, 95), S(148, 7),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-81, -231), S(-36, -68), S(17, -2), S(42, 42), S(66, 72), S(80, 95), S(88, 110), S(100, 117), S(104, 130), S(124, 110), S(129, 110), S(177, 53), S(176, 56), S(209, 2),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -114), S(16, 45), S(38, 72), S(55, 82), S(65, 95), S(70, 107), S(75, 117), S(83, 120), S(87, 131), S(95, 133), S(104, 134), S(107, 140), S(111, 137), S(125, 109), S(209, 3),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-129, -86), S(12, -31), S(38, 81), S(59, 186), S(75, 225), S(83, 265), S(89, 296), S(97, 304), S(100, 326), S(102, 341), S(108, 346), S(110, 355), S(116, 353), S(116, 358), S(117, 356), S(114, 357), S(111, 358), S(114, 347), S(120, 333), S(122, 326), S(118, 313), S(136, 272), S(112, 284), S(109, 223), S(79, 217), S(73, 182), S(16, 202), S(25, 154),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 85);
inline const PParam PAWN_THREAT_BISHOP = S(208, 128);
inline const PParam PAWN_THREAT_ROOK   = S(197, 124);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -10);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(228, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -18);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 56);
inline const PParam BISHOP_THREAT_ROOK   = S(214, 122);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 89);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -30), S(-3, -3), S(-5, -12), S(-7, -23), S(-11, -32), S(-14, -40), S(-15, -52), S(-20, -54), S(-35, -50),
};

inline const PParam ROOK_LINEUP = S(14, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(224, 172),    S(60, 227),     S(192, 181),    S(171, 160),    S(217, 93),     S(111, 178),    S(51, 219),     S(191, 165),    //
    S(56, 58),      S(83, 75),      S(83, 53),      S(57, 4),       S(52, -26),     S(30, 20),      S(11, 70),      S(-20, 95),     //
    S(32, 21),      S(8, 30),       S(39, -8),      S(28, -32),     S(23, -45),     S(-0, -18),     S(-47, 27),     S(-43, 49),     //
    S(-1, -25),     S(-21, 2),      S(7, -22),      S(-4, -30),     S(-27, -29),    S(-33, -13),    S(-89, 23),     S(-78, 14),     //
    S(2, -55),      S(33, -53),     S(16, -5),      S(3, -8),       S(-26, -15),    S(-42, -11),    S(-77, 5),      S(-74, -3),     //
    S(20, -51),     S(100, -53),    S(77, -11),     S(36, 22),      S(6, 6),        S(-14, -6),     S(-46, 12),     S(-58, 12),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-334, -307),  S(-270, 20),    S(-252, -87),   S(-3, 17),      S(-79, 21),     S(-229, 33),    S(-397, 89),    S(-408, -203),  //
    S(-45, -8),     S(-18, 18),     S(101, -19),    S(106, 2),      S(102, 11),     S(23, 30),      S(-41, 33),     S(-66, 14),     //
    S(23, -10),     S(57, -17),     S(88, 43),      S(103, 43),     S(67, 73),      S(19, 74),      S(8, 17),       S(-40, 12),     //
    S(90, 9),       S(104, 29),     S(110, 61),     S(114, 89),     S(119, 92),     S(72, 81),      S(47, 48),      S(33, 22),      //
    S(70, 9),       S(114, -10),    S(95, 57),      S(91, 72),      S(70, 78),      S(73, 67),      S(60, 15),      S(14, 27),      //
    S(7, -23),      S(33, 1),       S(31, 42),      S(47, 61),      S(40, 59),      S(9, 43),       S(4, 8),        S(-37, -24),    //
    S(24, -17),     S(33, -15),     S(8, -0),       S(16, 21),      S(14, 18),      S(-10, -28),    S(-32, -7),     S(-46, -91),    //
    S(-50, -73),    S(-0, -13),     S(21, -39),     S(37, -34),     S(19, -15),     S(-16, -40),    S(-28, -22),    S(-69, -116),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-155, 77),    S(-159, 81),    S(-442, 139),   S(-290, 84),    S(-285, 86),    S(-308, 81),    S(-212, 81),    S(-131, 62),    //
    S(-47, 4),      S(-85, 80),     S(-44, 25),     S(-100, 55),    S(-79, 47),     S(-59, 43),     S(-20, 34),     S(-54, 13),     //
    S(27, 19),      S(16, 40),      S(30, 47),      S(19, 48),      S(-2, 47),      S(4, 47),       S(8, 37),       S(9, 11),       //
    S(12, 1),       S(45, 17),      S(52, 43),      S(54, 81),      S(87, 66),      S(30, 38),      S(38, 1),       S(-6, 3),       //
    S(44, -44),     S(51, -5),      S(67, 27),      S(73, 57),      S(54, 67),      S(51, 45),      S(16, 15),      S(10, -23),     //
    S(64, -31),     S(80, -13),     S(90, 21),      S(53, 46),      S(49, 27),      S(48, 37),      S(59, 12),      S(11, -2),      //
    S(25, -59),     S(104, -38),    S(67, -17),     S(48, -1),      S(31, 4),       S(38, -23),     S(35, -30),     S(39, -42),     //
    S(47, -58),     S(30, -28),     S(35, -4),      S(53, -28),     S(39, -18),     S(42, 18),      S(43, -5),      S(38, -34),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(194, 86),     S(231, 94),     S(186, 108),    S(180, 83),     S(222, 71),     S(177, 92),     S(200, 95),     S(180, 106),    //
    S(82, 157),     S(168, 149),    S(229, 115),    S(169, 128),    S(206, 120),    S(174, 129),    S(119, 157),    S(100, 163),    //
    S(46, 155),     S(171, 126),    S(217, 87),     S(184, 89),     S(181, 110),    S(135, 134),    S(138, 136),    S(74, 169),     //
    S(15, 130),     S(106, 123),    S(134, 97),     S(108, 109),    S(140, 97),     S(93, 134),     S(98, 130),     S(23, 159),     //
    S(-7, 63),      S(73, 65),      S(64, 79),      S(33, 85),      S(42, 96),      S(33, 116),     S(6, 116),      S(-10, 112),    //
    S(8, -10),      S(82, 11),      S(73, 22),      S(50, 25),      S(61, 30),      S(28, 65),      S(37, 42),      S(-4, 52),      //
    S(-87, -5),     S(54, -42),     S(58, -20),     S(47, 2),       S(50, 7),       S(37, 18),      S(29, 4),       S(-4, 19),      //
    S(-24, -21),    S(2, -2),       S(61, -15),     S(72, -19),     S(71, -7),      S(51, 10),      S(48, 5),       S(27, 11),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 112),     S(187, 48),     S(112, 143),    S(54, 227),     S(92, 181),     S(84, 168),     S(112, 82),     S(36, 149),     //
    S(70, 170),     S(84, 250),     S(54, 271),     S(-71, 337),    S(-30, 329),    S(13, 288),     S(60, 179),     S(37, 180),     //
    S(40, 204),     S(64, 258),     S(33, 313),     S(1, 316),      S(8, 323),      S(58, 250),     S(76, 189),     S(85, 109),     //
    S(60, 100),     S(60, 185),     S(11, 253),     S(-5, 314),     S(9, 327),      S(44, 216),     S(85, 148),     S(59, 123),     //
    S(61, 69),      S(43, 133),     S(23, 188),     S(-2, 252),     S(12, 277),     S(27, 230),     S(52, 144),     S(69, 81),      //
    S(52, 3),       S(67, 47),      S(62, 120),     S(44, 128),     S(47, 151),     S(47, 186),     S(66, 126),     S(60, 77),      //
    S(26, -108),    S(41, -53),     S(49, -9),      S(76, 16),      S(67, 64),      S(66, 45),      S(37, 86),      S(57, 52),      //
    S(11, -97),     S(34, -216),    S(61, -212),    S(77, -114),    S(71, -21),     S(76, -61),     S(72, -34),     S(47, -10),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-63, -204),   S(301, 245),    S(202, 225),    S(70, 119),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(235, 24),     S(318, 206),    S(186, 220),    S(132, 99),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(178, 85),     S(234, 168),    S(153, 185),    S(104, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, 36),      S(133, 100),    S(17, 152),     S(-13, 164),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-90, -16),    S(-2, 50),      S(-59, 104),    S(-145, 165),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -48),    S(29, 8),       S(-64, 77),     S(-114, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(18, -87),     S(28, -25),     S(-46, 23),     S(-110, 71),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -174),   S(-0, -87),     S(-82, -45),    S(-77, -57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -564);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -26), S(14, -27), S(14, -7), S(5, -10), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -28), S(4, -18), S(4, -2), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, 44), S(-4, 55), S(-2, -15), S(9, -27), S(8, -22), S(-3, -6), S(-3, 56), }},
  {{ S(-2, 167), S(-20, -256), S(-21, 1), S(-8, 49), S(-8, 66), S(-19, -8), S(-19, -239), }},
  {{ S(-3, 146), S(-8, -241), S(-9, 130), S(-3, 109), S(-2, 107), S(-9, 135), S(-8, -216), }},
  {{ S(7, 126), S(-11, 81), S(1, 92), S(7, 70), S(5, 73), S(-1, 92), S(-7, 80), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 60), S(-11, 53), S(-10, 78), S(-1, 84), S(3, 32),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 118), S(-8, 36), S(-9, 38), S(-6, 35), S(-6, 31), S(-8, 37), S(-9, 48), }},
  {{ S(9, 4), S(1, -34), S(-8, -21), S(-3, -55), S(-4, -55), S(-7, -24), S(1, -27), }},
  {{ S(0, 60), S(-4, 35), S(-7, 39), S(-4, 36), S(-3, 19), S(-7, 35), S(-3, 24), }},
  {{ S(-0, 56), S(-6, 35), S(-10, 37), S(-5, 46), S(-4, 46), S(-10, 32), S(-8, 36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1074, 247, -13, 95
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-653);

// Epoch duration: 7.21424s
// clang-format on
}  // namespace Clockwork
