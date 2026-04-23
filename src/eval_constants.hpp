#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(193, 381);
inline const PParam KNIGHT_MAT = S(863, 980);
inline const PParam BISHOP_MAT = S(909, 1021);
inline const PParam ROOK_MAT   = S(1104, 1646);
inline const PParam QUEEN_MAT  = S(2637, 2598);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 14);
inline const PParam BISHOP_PAIR_VAL   = S(50, 204);
inline const PParam ROOK_OPEN_VAL     = S(119, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 27);
inline const PParam MINOR_BEHIND_PAWN = S(12, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-11, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(47, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 43);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, -3), S(31, 27), S(60, 48), S(143, 141), S(379, 211), S(439, 527),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 33), S(47, 26), S(63, 50), S(120, 141), S(413, 84),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-109, -190), S(-109, -162), S(-82, -57), S(-24, 40), S(72, 177), S(258, 257),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -38), S(21, 2), S(15, 32), S(0, 113), S(82, 203), S(256, 255),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -18), S(1, 23), S(-2, -10), S(0, -41), S(-6, -129), S(-252, -212),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 184), S(-4, 157), S(2, 88), S(8, 54), S(15, 55), S(53, 50), S(44, 34),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-271, -36), S(-9, 37), S(-2, 92), S(39, 115), S(61, 133), S(72, 138), S(52, 135),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-151, -188), S(-71, -49), S(-31, 23), S(2, 43), S(37, 52), S(58, 73), S(83, 64), S(104, 71), S(148, -15),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-92, -252), S(-45, -89), S(8, -25), S(31, 22), S(52, 56), S(64, 82), S(70, 101), S(79, 111), S(79, 129), S(98, 110), S(99, 115), S(147, 56), S(139, 67), S(177, 8),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(73, -156), S(-12, 12), S(11, 41), S(27, 53), S(38, 68), S(43, 80), S(48, 91), S(56, 94), S(61, 105), S(69, 108), S(78, 109), S(83, 114), S(87, 112), S(101, 83), S(186, -22),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-204, -71), S(-39, -139), S(-13, -38), S(8, 65), S(25, 99), S(35, 135), S(42, 162), S(51, 168), S(54, 188), S(57, 203), S(63, 207), S(65, 216), S(70, 214), S(70, 220), S(71, 216), S(67, 219), S(63, 218), S(67, 207), S(71, 196), S(72, 190), S(67, 177), S(84, 139), S(59, 152), S(56, 91), S(25, 87), S(17, 55), S(-41, 78), S(-33, 35),
};

inline const std::array<PParam, 7> KNIGHT_REACHABILITY = {
    S(80, -1), S(68, 26), S(60, 38), S(50, 56), S(40, 79), S(11, 109), S(0, 0),
};
inline const std::array<PParam, 8> BISHOP_REACHABILITY = {
    S(65, 64), S(57, 66), S(63, 66), S(62, 69), S(63, 53), S(64, 40), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 9> ROOK_REACHABILITY = {
    S(114, 165), S(115, 164), S(114, 147), S(115, 145), S(110, 147), S(105, 122), S(88, 89), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 9> QUEEN_REACHABILITY = {
    S(164, 361), S(147, 435), S(164, 413), S(159, 422), S(151, 452), S(138, 484), S(145, 434), S(0, 0), S(0, 0),
};

inline const PParam PAWN_THREAT_KNIGHT = S(209, 93);
inline const PParam PAWN_THREAT_BISHOP = S(195, 138);
inline const PParam PAWN_THREAT_ROOK   = S(197, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(178, -6);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(228, 67);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -11);

inline const PParam BISHOP_THREAT_KNIGHT = S(100, 63);
inline const PParam BISHOP_THREAT_ROOK   = S(210, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(169, 102);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(13, -32), S(-1, -5), S(-4, -13), S(-7, -22), S(-12, -31), S(-15, -38), S(-17, -50), S(-23, -51), S(-38, -46),
};

inline const PParam ROOK_LINEUP = S(15, 60);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(231, 183),    S(65, 241),     S(192, 199),    S(173, 176),    S(220, 107),    S(114, 193),    S(57, 230),     S(198, 176),    //
    S(46, 24),      S(71, 44),      S(68, 23),      S(43, -27),     S(38, -57),     S(17, -13),     S(-0, 38),      S(-29, 61),     //
    S(23, -12),     S(-2, -2),      S(28, -40),     S(17, -64),     S(12, -77),     S(-11, -50),    S(-57, -6),     S(-52, 16),     //
    S(-10, -59),    S(-31, -30),    S(-3, -54),     S(-14, -62),    S(-37, -61),    S(-42, -46),    S(-99, -9),     S(-87, -19),    //
    S(-8, -88),     S(26, -87),     S(8, -38),      S(-4, -43),     S(-33, -50),    S(-51, -44),    S(-85, -29),    S(-84, -36),    //
    S(13, -86),     S(93, -85),     S(71, -45),     S(31, -13),     S(1, -29),      S(-20, -40),    S(-54, -21),    S(-66, -22),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-326, -327),  S(-270, 11),    S(-264, -81),   S(-11, 12),     S(-86, 16),     S(-235, 28),    S(-402, 89),    S(-400, -224),  //
    S(-48, -13),    S(-21, 12),     S(90, -13),     S(98, 2),       S(92, 13),      S(17, 30),      S(-46, 30),     S(-66, 5),      //
    S(19, -16),     S(46, -11),     S(74, 50),      S(91, 46),      S(57, 71),      S(8, 76),       S(-1, 21),      S(-43, 6),      //
    S(88, 3),       S(98, 26),      S(100, 62),     S(108, 82),     S(113, 84),     S(64, 80),      S(42, 44),      S(32, 14),      //
    S(70, -0),      S(109, -12),    S(89, 56),      S(87, 67),      S(65, 74),      S(67, 65),      S(56, 12),      S(15, 16),      //
    S(4, -25),      S(26, 5),       S(24, 47),      S(41, 61),      S(35, 59),      S(2, 49),       S(-3, 13),      S(-40, -26),    //
    S(23, -23),     S(31, -19),     S(1, 4),        S(12, 20),      S(10, 19),      S(-17, -22),    S(-33, -9),     S(-46, -98),    //
    S(-50, -78),    S(-2, -16),     S(19, -42),     S(37, -40),     S(19, -19),     S(-17, -42),    S(-30, -23),    S(-71, -118),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-167, 83),    S(-168, 85),    S(-447, 139),   S(-295, 84),    S(-292, 86),    S(-313, 80),    S(-218, 82),    S(-144, 68),    //
    S(-60, 10),     S(-89, 77),     S(-46, 20),     S(-101, 48),    S(-82, 43),     S(-64, 42),     S(-26, 35),     S(-66, 17),     //
    S(14, 24),      S(8, 39),       S(25, 41),      S(14, 42),      S(-8, 41),      S(-1, 42),      S(2, 35),       S(-3, 15),      //
    S(2, 4),        S(38, 16),      S(50, 37),      S(57, 70),      S(90, 55),      S(28, 32),      S(29, 2),       S(-17, 6),      //
    S(35, -43),     S(44, -4),      S(66, 21),      S(78, 42),      S(60, 53),      S(50, 38),      S(9, 15),       S(-0, -19),     //
    S(52, -28),     S(73, -12),     S(89, 15),      S(54, 37),      S(50, 18),      S(49, 28),      S(54, 10),      S(1, 1),        //
    S(20, -60),     S(103, -44),    S(65, -22),     S(41, 0),       S(25, 3),       S(37, -29),     S(35, -36),     S(33, -42),     //
    S(43, -60),     S(26, -29),     S(21, 5),       S(40, -21),     S(26, -10),     S(30, 25),      S(39, -7),      S(34, -37),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(175, 72),     S(210, 80),     S(162, 98),     S(158, 70),     S(198, 60),     S(154, 81),     S(176, 85),     S(162, 91),     //
    S(63, 144),     S(148, 136),    S(208, 103),    S(147, 117),    S(187, 107),    S(154, 118),    S(98, 144),     S(81, 150),     //
    S(28, 142),     S(151, 113),    S(196, 77),     S(163, 80),     S(158, 102),    S(114, 124),    S(117, 125),    S(56, 156),     //
    S(-4, 119),     S(88, 110),     S(114, 87),     S(88, 99),      S(120, 87),     S(75, 121),     S(77, 119),     S(4, 148),      //
    S(-28, 53),     S(54, 52),      S(44, 69),      S(13, 74),      S(21, 86),      S(14, 104),     S(-14, 104),    S(-29, 100),    //
    S(-12, -22),    S(63, -1),      S(52, 12),      S(29, 14),      S(41, 19),      S(8, 53),       S(17, 30),      S(-23, 40),     //
    S(-107, -18),   S(32, -54),     S(37, -32),     S(25, -9),      S(29, -6),      S(16, 5),       S(7, -9),       S(-24, 6),      //
    S(-44, -36),    S(-18, -17),    S(40, -30),     S(51, -33),     S(49, -22),     S(30, -5),      S(26, -10),     S(5, -4),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(66, 52),      S(164, -16),    S(84, 87),      S(27, 170),     S(64, 127),     S(59, 110),     S(86, 24),      S(14, 84),      //
    S(48, 105),     S(56, 195),     S(29, 211),     S(-100, 283),   S(-58, 273),    S(-14, 231),    S(35, 119),     S(14, 118),     //
    S(18, 139),     S(39, 199),     S(7, 255),      S(-26, 260),    S(-22, 273),    S(29, 198),     S(50, 131),     S(61, 47),      //
    S(36, 41),      S(35, 126),     S(-14, 195),    S(-32, 260),    S(-17, 269),    S(17, 160),     S(59, 91),      S(36, 60),      //
    S(38, 5),       S(20, 72),      S(-2, 130),     S(-28, 196),    S(-16, 223),    S(1, 174),      S(27, 84),      S(46, 18),      //
    S(30, -62),     S(42, -10),     S(37, 63),      S(18, 72),      S(21, 97),      S(21, 132),     S(40, 69),      S(36, 17),      //
    S(3, -167),     S(15, -108),    S(23, -62),     S(51, -39),     S(41, 10),      S(40, -8),      S(10, 32),      S(32, -5),      //
    S(-13, -153),   S(10, -271),    S(37, -267),    S(53, -170),    S(47, -75),     S(52, -117),    S(46, -86),     S(22, -63),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-59, -210),   S(305, 241),    S(206, 221),    S(73, 116),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(239, 20),     S(319, 206),    S(189, 218),    S(135, 98),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(182, 82),     S(237, 167),    S(157, 183),    S(107, 116),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(15, 32),      S(134, 100),    S(21, 151),     S(-10, 163),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-89, -16),    S(-1, 50),      S(-59, 104),    S(-144, 165),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -47),    S(28, 8),       S(-65, 77),     S(-116, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -87),     S(28, -24),     S(-46, 24),     S(-110, 72),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -174),   S(1, -86),      S(-81, -44),    S(-75, -56),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-82, -565);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -27), S(14, -26), S(14, -7), S(5, -10), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -27), S(4, -19), S(4, -2), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, 43), S(-4, 54), S(-2, -18), S(10, -29), S(8, -22), S(-3, -9), S(-3, 55), }},
  {{ S(-2, 168), S(-20, -253), S(-21, 2), S(-8, 48), S(-8, 64), S(-19, -8), S(-19, -237), }},
  {{ S(-3, 147), S(-8, -241), S(-9, 130), S(-3, 109), S(-2, 108), S(-9, 136), S(-8, -214), }},
  {{ S(7, 127), S(-10, 83), S(1, 93), S(7, 71), S(6, 75), S(-1, 93), S(-7, 82), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 64), S(-10, 54), S(-10, 78), S(-1, 83), S(4, 32),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 119), S(-8, 36), S(-9, 37), S(-5, 36), S(-6, 30), S(-7, 35), S(-8, 47), }},
  {{ S(10, 4), S(1, -35), S(-8, -23), S(-3, -55), S(-4, -55), S(-7, -25), S(1, -28), }},
  {{ S(1, 60), S(-3, 35), S(-6, 38), S(-3, 37), S(-3, 20), S(-7, 34), S(-3, 23), }},
  {{ S(-0, 55), S(-6, 34), S(-10, 37), S(-5, 45), S(-3, 46), S(-9, 32), S(-8, 35), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1078, 244, -15, 93
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(126);
inline VParam WINNABLE_PAWN_ENDGAME = V(222);
inline VParam WINNABLE_BIAS = V(-656);

// Epoch duration: 5.3564s
// clang-format on
}  // namespace Clockwork
