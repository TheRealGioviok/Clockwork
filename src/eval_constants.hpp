#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(193, 384);
inline const PParam KNIGHT_MAT = S(852, 992);
inline const PParam BISHOP_MAT = S(904, 1030);
inline const PParam ROOK_MAT   = S(1103, 1653);
inline const PParam QUEEN_MAT  = S(2635, 2594);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 12);
inline const PParam BISHOP_PAIR_VAL   = S(51, 200);
inline const PParam ROOK_OPEN_VAL     = S(121, -17);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 27);
inline const PParam MINOR_BEHIND_PAWN = S(12, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -19);

inline const PParam POTENTIAL_CHECKER_VAL = S(-53, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(53, 48);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 37);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(47, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, -4), S(30, 30), S(59, 52), S(142, 145), S(393, 189), S(446, 526),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 34), S(46, 26), S(63, 49), S(122, 139), S(420, 72),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-106, -190), S(-107, -162), S(-80, -53), S(-24, 46), S(72, 185), S(253, 270),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(29, -40), S(24, -4), S(15, 33), S(3, 113), S(78, 214), S(259, 246),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -20), S(1, 21), S(-1, -18), S(3, -49), S(-2, -141), S(-246, -223),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 187), S(-6, 162), S(1, 91), S(7, 56), S(13, 57), S(53, 51), S(45, 35),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-272, -37), S(-8, 32), S(-3, 90), S(37, 115), S(59, 133), S(69, 139), S(47, 137),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-171, -80), S(-77, -4), S(-31, 45), S(6, 46), S(39, 51), S(59, 67), S(81, 61), S(105, 54), S(140, -21),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-105, -184), S(-37, -59), S(10, 2), S(36, 36), S(56, 65), S(67, 88), S(73, 103), S(81, 110), S(82, 122), S(101, 103), S(102, 105), S(146, 49), S(135, 63), S(156, 10),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-46, 14), S(-6, 41), S(22, 60), S(35, 68), S(42, 75), S(49, 83), S(55, 95), S(62, 97), S(68, 107), S(77, 108), S(83, 108), S(89, 110), S(93, 107), S(97, 88), S(184, -17),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(114, 130), S(-15, -98), S(-2, -4), S(20, 50), S(30, 95), S(36, 139), S(43, 157), S(47, 174), S(50, 197), S(54, 207), S(57, 218), S(62, 220), S(68, 221), S(69, 222), S(71, 219), S(68, 221), S(72, 210), S(77, 199), S(80, 186), S(83, 171), S(80, 156), S(79, 138), S(53, 139), S(29, 126), S(11, 100), S(-18, 107), S(-62, 94), S(-48, 84),
};

inline const std::array<PParam, 8> KNIGHT_REACHABILITY = {
    S(96, -50), S(71, 25), S(56, 66), S(50, 85), S(34, 112), S(13, 127), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 9> BISHOP_REACHABILITY = {
    S(65, 33), S(42, 77), S(47, 81), S(50, 85), S(49, 80), S(44, 45), S(0, 0), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 10> ROOK_REACHABILITY = {
    S(132, 108), S(125, 105), S(98, 166), S(96, 168), S(92, 170), S(90, 154), S(82, 142), S(0, 0), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 10> QUEEN_REACHABILITY = {
    S(-168, -65), S(-343, 50), S(171, 165), S(178, 227), S(175, 457), S(176, 477), S(170, 475), S(178, 326), S(0, 0), S(0, 0),
};

inline const PParam PAWN_THREAT_KNIGHT = S(202, 107);
inline const PParam PAWN_THREAT_BISHOP = S(192, 143);
inline const PParam PAWN_THREAT_ROOK   = S(196, 122);
inline const PParam PAWN_THREAT_QUEEN  = S(175, 0);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 99);
inline const PParam KNIGHT_THREAT_ROOK   = S(224, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -14);

inline const PParam BISHOP_THREAT_KNIGHT = S(99, 63);
inline const PParam BISHOP_THREAT_ROOK   = S(207, 129);
inline const PParam BISHOP_THREAT_QUEEN  = S(169, 100);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(14, -33), S(-0, -6), S(-3, -12), S(-7, -22), S(-11, -31), S(-15, -39), S(-16, -50), S(-22, -52), S(-37, -47),
};

inline const PParam ROOK_LINEUP = S(14, 64);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(226, 186),    S(61, 251),     S(188, 211),    S(170, 185),    S(220, 112),    S(114, 196),    S(56, 237),     S(198, 180),    //
    S(46, 26),      S(71, 49),      S(68, 30),      S(43, -21),     S(36, -49),     S(16, -7),      S(1, 40),       S(-28, 63),     //
    S(24, -12),     S(-2, 2),       S(27, -34),     S(18, -62),     S(12, -73),     S(-12, -46),    S(-57, -2),     S(-51, 17),     //
    S(-9, -58),     S(-33, -25),    S(-4, -49),     S(-15, -58),    S(-37, -58),    S(-43, -41),    S(-100, -5),    S(-85, -19),    //
    S(-7, -90),     S(25, -85),     S(7, -35),      S(-5, -40),     S(-35, -47),    S(-52, -41),    S(-85, -27),    S(-85, -36),    //
    S(16, -87),     S(92, -84),     S(65, -39),     S(29, -11),     S(1, -30),      S(-19, -42),    S(-53, -22),    S(-69, -20),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-342, -341),  S(-282, 21),    S(-299, -27),   S(-25, 32),     S(-104, 42),    S(-243, 45),    S(-419, 108),   S(-416, -237),  //
    S(-64, 2),      S(-35, 31),     S(75, 9),       S(82, 22),      S(74, 36),      S(4, 51),       S(-60, 48),     S(-81, 24),     //
    S(7, -5),       S(25, 24),      S(57, 80),      S(81, 69),      S(47, 95),      S(1, 98),       S(-13, 47),     S(-62, 36),     //
    S(78, 9),       S(89, 40),      S(93, 79),      S(100, 99),     S(105, 101),    S(57, 97),      S(34, 59),      S(18, 29),      //
    S(68, -6),      S(102, 1),      S(87, 62),      S(80, 79),      S(61, 82),      S(62, 75),      S(49, 20),      S(9, 13),       //
    S(21, -31),     S(33, -4),      S(46, 33),      S(50, 54),      S(43, 52),      S(8, 41),       S(-1, 6),       S(-42, -34),    //
    S(28, -42),     S(34, -34),     S(4, -7),       S(29, 5),       S(18, 3),       S(-9, -36),     S(-32, -27),    S(-51, -107),   //
    S(-47, -104),   S(-14, -32),    S(7, -52),      S(36, -60),     S(12, -34),     S(-20, -59),    S(-36, -44),    S(-70, -142),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-171, 80),    S(-169, 89),    S(-448, 144),   S(-294, 85),    S(-292, 89),    S(-310, 79),    S(-217, 85),    S(-147, 68),    //
    S(-60, 8),      S(-88, 84),     S(-52, 35),     S(-103, 57),    S(-83, 48),     S(-62, 45),     S(-24, 39),     S(-63, 17),     //
    S(12, 29),      S(5, 50),       S(23, 56),      S(12, 54),      S(-9, 52),      S(1, 50),       S(5, 39),       S(-3, 22),      //
    S(0, 9),        S(38, 23),      S(49, 46),      S(56, 81),      S(92, 61),      S(30, 37),      S(29, 10),      S(-16, 12),     //
    S(34, -38),     S(43, 2),       S(65, 31),      S(80, 50),      S(63, 60),      S(53, 45),      S(10, 20),      S(-2, -15),     //
    S(55, -20),     S(75, -4),      S(90, 26),      S(59, 43),      S(52, 26),      S(53, 32),      S(54, 14),      S(-0, 3),       //
    S(39, -50),     S(105, -35),    S(74, -11),     S(44, 6),       S(32, 5),       S(37, -25),     S(34, -31),     S(30, -44),     //
    S(46, -69),     S(14, -23),     S(9, 6),        S(37, -26),     S(20, -13),     S(22, 15),      S(37, -13),     S(36, -49),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(159, 83),     S(199, 87),     S(155, 100),    S(148, 75),     S(187, 68),     S(149, 83),     S(157, 101),    S(145, 103),    //
    S(60, 146),     S(152, 133),    S(213, 96),     S(147, 116),    S(184, 109),    S(152, 117),    S(94, 150),     S(76, 155),     //
    S(26, 143),     S(155, 107),    S(196, 73),     S(160, 79),     S(157, 98),     S(113, 120),    S(114, 123),    S(52, 156),     //
    S(-3, 114),     S(88, 107),     S(113, 85),     S(86, 95),      S(114, 89),     S(73, 118),     S(75, 116),     S(1, 145),      //
    S(-26, 48),     S(55, 52),      S(41, 68),      S(9, 75),       S(19, 84),      S(9, 106),      S(-17, 104),    S(-32, 99),     //
    S(-11, -25),    S(66, -4),      S(49, 14),      S(27, 15),      S(37, 21),      S(5, 53),       S(15, 29),      S(-27, 39),     //
    S(-109, -19),   S(35, -49),     S(35, -28),     S(25, -5),      S(28, -2),      S(13, 10),      S(4, -6),       S(-28, 6),      //
    S(-25, -35),    S(-5, -12),     S(39, -13),     S(53, -24),     S(51, -13),     S(28, 5),       S(23, -1),      S(-1, 8),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(42, 96),      S(146, 19),     S(74, 109),     S(11, 198),     S(51, 152),     S(47, 131),     S(64, 60),      S(-9, 123),     //
    S(44, 116),     S(60, 197),     S(37, 208),     S(-98, 291),    S(-53, 278),    S(-12, 239),    S(36, 129),     S(16, 121),     //
    S(15, 148),     S(39, 209),     S(22, 237),     S(-21, 260),    S(-13, 267),    S(39, 188),     S(55, 133),     S(62, 55),      //
    S(31, 55),      S(35, 135),     S(-13, 200),    S(-26, 256),    S(-10, 264),    S(23, 158),     S(63, 93),      S(34, 72),      //
    S(35, 18),      S(23, 73),      S(1, 131),      S(-22, 191),    S(-6, 211),     S(5, 175),      S(29, 90),      S(44, 29),      //
    S(26, -44),     S(48, -10),     S(41, 62),      S(28, 62),      S(27, 90),      S(28, 122),     S(44, 65),      S(36, 21),      //
    S(7, -136),     S(28, -111),    S(37, -71),     S(60, -47),     S(49, 0),       S(44, -14),     S(15, 25),      S(32, -5),      //
    S(-10, -109),   S(8, -234),     S(49, -272),    S(66, -186),    S(51, -81),     S(50, -114),    S(46, -85),     S(19, -53),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(35, -211),    S(292, 199),    S(199, 172),    S(54, 127),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(254, 16),     S(319, 185),    S(175, 206),    S(114, 111),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(184, 81),     S(229, 162),    S(139, 187),    S(99, 121),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(2, 41),       S(120, 104),    S(9, 153),      S(-16, 166),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-99, -10),    S(-13, 54),     S(-72, 108),    S(-156, 169),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-42, -43),    S(14, 13),      S(-75, 80),     S(-125, 126),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(8, -84),      S(19, -23),     S(-58, 27),     S(-106, 68),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -174),   S(6, -88),      S(-73, -44),    S(-71, -59),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -534);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -25), S(14, -19), S(14, -6), S(5, -12), S(1, -28),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -22), S(6, -21), S(4, -16), S(4, -3), S(4, 8),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -7);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 38), S(-3, 51), S(-1, -18), S(11, -28), S(9, -17), S(-2, -8), S(-2, 53), }},
  {{ S(-2, 159), S(-20, -226), S(-21, 3), S(-9, 54), S(-8, 67), S(-19, -6), S(-19, -209), }},
  {{ S(-2, 139), S(-7, -216), S(-8, 124), S(-2, 106), S(-2, 104), S(-8, 130), S(-7, -196), }},
  {{ S(7, 121), S(-10, 80), S(1, 90), S(7, 69), S(6, 72), S(-1, 89), S(-7, 81), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 66), S(-11, 50), S(-10, 75), S(-1, 80), S(4, 29),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 114), S(-8, 34), S(-9, 38), S(-6, 39), S(-6, 31), S(-7, 35), S(-8, 43), }},
  {{ S(10, 4), S(1, -34), S(-8, -21), S(-3, -44), S(-4, -46), S(-7, -20), S(1, -26), }},
  {{ S(1, 56), S(-3, 29), S(-6, 36), S(-3, 35), S(-3, 18), S(-7, 33), S(-3, 18), }},
  {{ S(-0, 53), S(-6, 30), S(-10, 34), S(-5, 46), S(-3, 44), S(-9, 29), S(-8, 33), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1072, 249, -11, 96
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(136);
inline VParam WINNABLE_ASYM = V(123);
inline VParam WINNABLE_PAWN_ENDGAME = V(213);
inline VParam WINNABLE_BIAS = V(-643);

// Epoch duration: 6.13343s
// clang-format on
}  // namespace Clockwork
