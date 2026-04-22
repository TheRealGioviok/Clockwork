#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(196, 382);
inline const PParam KNIGHT_MAT = S(908, 1017);
inline const PParam BISHOP_MAT = S(947, 1069);
inline const PParam ROOK_MAT   = S(1150, 1715);
inline const PParam QUEEN_MAT  = S(2681, 2699);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_PAIR_VAL   = S(52, 200);
inline const PParam ROOK_OPEN_VAL     = S(118, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 26);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);
inline const PParam RESTRICTED_SQUARES = S(-24, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 55);
inline const PParam OUTPOST_BISHOP_VAL    = S(59, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -2), S(32, 27), S(61, 49), S(144, 141), S(381, 208), S(437, 527),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 33), S(47, 26), S(62, 51), S(121, 141), S(416, 80),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-107, -185), S(-108, -158), S(-80, -52), S(-23, 45), S(73, 180), S(264, 258),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(28, -38), S(21, 2), S(15, 32), S(1, 112), S(82, 202), S(255, 256),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -17), S(-0, 24), S(-2, -10), S(0, -40), S(-5, -129), S(-251, -211),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 182), S(-4, 155), S(2, 87), S(9, 52), S(15, 54), S(52, 49), S(46, 31),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-275, -36), S(-11, 34), S(-5, 89), S(37, 112), S(59, 130), S(70, 135), S(50, 132),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-111, -243), S(-45, -75), S(-14, 13), S(13, 44), S(45, 60), S(61, 89), S(84, 84), S(104, 95), S(149, 7),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-81, -227), S(-36, -64), S(17, 1), S(42, 45), S(66, 75), S(80, 98), S(88, 113), S(100, 120), S(104, 133), S(124, 113), S(129, 113), S(177, 55), S(177, 57), S(210, 5),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(98, -113), S(14, 46), S(37, 73), S(53, 83), S(64, 96), S(68, 107), S(74, 118), S(81, 121), S(86, 132), S(94, 134), S(102, 135), S(106, 141), S(110, 138), S(123, 110), S(208, 4),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-127, -80), S(13, -25), S(39, 87), S(60, 192), S(76, 231), S(84, 271), S(90, 301), S(98, 309), S(101, 331), S(104, 346), S(109, 351), S(112, 360), S(117, 359), S(118, 363), S(119, 361), S(115, 363), S(112, 363), S(116, 352), S(121, 339), S(123, 331), S(119, 318), S(137, 278), S(113, 290), S(110, 228), S(80, 223), S(74, 188), S(17, 208), S(25, 164),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 86);
inline const PParam PAWN_THREAT_BISHOP = S(208, 128);
inline const PParam PAWN_THREAT_ROOK   = S(198, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -10);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -18);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 56);
inline const PParam BISHOP_THREAT_ROOK   = S(214, 122);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 90);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -30), S(-3, -3), S(-5, -12), S(-7, -23), S(-11, -32), S(-14, -40), S(-15, -52), S(-20, -54), S(-35, -50),
};

inline const PParam ROOK_LINEUP = S(15, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(226, 182),    S(64, 236),     S(194, 190),    S(175, 168),    S(221, 101),    S(112, 190),    S(55, 227),     S(194, 175),    //
    S(48, 21),      S(76, 37),      S(75, 15),      S(49, -34),     S(44, -63),     S(22, -17),     S(3, 32),       S(-28, 58),     //
    S(24, -16),     S(0, -7),       S(32, -46),     S(20, -70),     S(15, -83),     S(-8, -56),     S(-55, -10),    S(-51, 12),     //
    S(-9, -63),     S(-29, -36),    S(-1, -59),     S(-12, -67),    S(-35, -66),    S(-41, -50),    S(-97, -14),    S(-87, -23),    //
    S(-6, -92),     S(25, -90),     S(9, -43),      S(-5, -45),     S(-34, -52),    S(-51, -48),    S(-85, -32),    S(-83, -40),    //
    S(12, -89),     S(92, -90),     S(69, -48),     S(27, -15),     S(-2, -31),     S(-23, -43),    S(-54, -25),    S(-67, -25),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-332, -307),  S(-270, 23),    S(-251, -86),   S(-3, 19),      S(-80, 23),     S(-228, 35),    S(-396, 91),    S(-406, -203),  //
    S(-44, -7),     S(-16, 17),     S(102, -18),    S(107, 3),      S(102, 13),     S(24, 31),      S(-40, 34),     S(-65, 14),     //
    S(24, -10),     S(58, -16),     S(88, 44),      S(104, 44),     S(68, 74),      S(20, 75),      S(9, 18),       S(-39, 13),     //
    S(91, 11),      S(105, 29),     S(110, 62),     S(115, 90),     S(120, 93),     S(73, 82),      S(48, 49),      S(34, 23),      //
    S(72, 10),      S(115, -9),     S(96, 57),      S(92, 73),      S(70, 79),      S(73, 68),      S(61, 16),      S(14, 28),      //
    S(8, -21),      S(34, 2),       S(32, 43),      S(47, 62),      S(41, 61),      S(10, 45),      S(4, 9),        S(-36, -23),    //
    S(25, -16),     S(33, -14),     S(9, 0),        S(17, 22),      S(15, 19),      S(-10, -27),    S(-31, -5),     S(-44, -91),    //
    S(-49, -71),    S(0, -11),      S(21, -38),     S(37, -33),     S(19, -13),     S(-15, -39),    S(-27, -21),    S(-68, -115),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-155, 77),    S(-160, 82),    S(-442, 140),   S(-288, 83),    S(-285, 86),    S(-308, 82),    S(-211, 81),    S(-130, 61),    //
    S(-47, 4),      S(-84, 80),     S(-44, 27),     S(-99, 55),     S(-77, 46),     S(-59, 44),     S(-20, 35),     S(-55, 14),     //
    S(27, 19),      S(16, 40),      S(30, 47),      S(19, 50),      S(-2, 47),      S(4, 47),       S(9, 37),       S(10, 11),      //
    S(12, 1),       S(45, 18),      S(53, 44),      S(54, 82),      S(87, 67),      S(30, 39),      S(38, 2),       S(-5, 3),       //
    S(45, -44),     S(51, -4),      S(67, 28),      S(73, 58),      S(54, 68),      S(51, 46),      S(15, 17),      S(10, -22),     //
    S(63, -30),     S(81, -13),     S(90, 22),      S(53, 47),      S(49, 28),      S(48, 38),      S(59, 13),      S(11, -1),      //
    S(26, -59),     S(104, -37),    S(67, -17),     S(48, 0),       S(31, 5),       S(38, -23),     S(35, -29),     S(40, -42),     //
    S(47, -57),     S(30, -27),     S(35, -3),      S(53, -27),     S(39, -17),     S(42, 19),      S(43, -5),      S(38, -33),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(196, 86),     S(231, 96),     S(187, 111),    S(182, 84),     S(222, 74),     S(178, 95),     S(201, 97),     S(182, 107),    //
    S(84, 159),     S(170, 150),    S(230, 117),    S(169, 131),    S(207, 122),    S(175, 131),    S(120, 159),    S(101, 165),    //
    S(47, 157),     S(172, 128),    S(219, 88),     S(185, 92),     S(182, 112),    S(137, 135),    S(139, 137),    S(75, 170),     //
    S(16, 132),     S(108, 124),    S(135, 100),    S(109, 111),    S(141, 99),     S(95, 136),     S(99, 132),     S(25, 160),     //
    S(-6, 65),      S(74, 67),      S(65, 80),      S(34, 86),      S(43, 97),      S(34, 118),     S(8, 117),      S(-9, 114),     //
    S(9, -8),       S(84, 12),      S(74, 23),      S(51, 28),      S(62, 32),      S(30, 67),      S(38, 45),      S(-3, 55),      //
    S(-86, -3),     S(55, -39),     S(60, -18),     S(49, 4),       S(51, 9),       S(38, 19),      S(30, 6),       S(-3, 21),      //
    S(-23, -18),    S(4, 0),        S(62, -13),     S(73, -17),     S(72, -5),      S(52, 12),      S(49, 8),       S(28, 14),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 112),     S(187, 47),     S(111, 145),    S(54, 227),     S(92, 181),     S(83, 169),     S(111, 83),     S(35, 151),     //
    S(70, 170),     S(83, 251),     S(53, 272),     S(-72, 338),    S(-30, 328),    S(13, 287),     S(60, 180),     S(37, 180),     //
    S(39, 204),     S(64, 258),     S(33, 313),     S(1, 316),      S(8, 324),      S(57, 250),     S(77, 187),     S(84, 109),     //
    S(60, 100),     S(60, 184),     S(11, 252),     S(-5, 314),     S(9, 327),      S(43, 217),     S(85, 147),     S(58, 123),     //
    S(61, 69),      S(43, 133),     S(22, 189),     S(-3, 253),     S(11, 277),     S(27, 230),     S(51, 144),     S(69, 81),      //
    S(52, 2),       S(66, 47),      S(62, 119),     S(43, 129),     S(46, 151),     S(47, 186),     S(65, 125),     S(60, 77),      //
    S(26, -107),    S(41, -53),     S(48, -8),      S(76, 16),      S(67, 63),      S(66, 45),      S(37, 86),      S(57, 52),      //
    S(11, -97),     S(34, -216),    S(61, -211),    S(77, -115),    S(71, -20),     S(76, -61),     S(72, -34),     S(47, -10),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-63, -204),   S(302, 245),    S(203, 225),    S(71, 119),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(236, 23),     S(319, 205),    S(187, 220),    S(133, 99),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(179, 85),     S(235, 168),    S(154, 185),    S(104, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(11, 34),      S(134, 99),     S(18, 152),     S(-12, 164),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-88, -17),    S(-1, 50),      S(-58, 104),    S(-144, 165),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -49),    S(30, 7),       S(-62, 76),     S(-114, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -88),     S(29, -26),     S(-45, 23),     S(-109, 71),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -175),   S(1, -87),      S(-81, -46),    S(-76, -58),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -566);

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
  {{ S(18, 44), S(-4, 55), S(-1, -16), S(10, -27), S(9, -22), S(-3, -6), S(-2, 56), }},
  {{ S(-1, 169), S(-20, -256), S(-20, 1), S(-8, 51), S(-8, 68), S(-19, -5), S(-19, -239), }},
  {{ S(-3, 148), S(-9, -240), S(-10, 132), S(-4, 110), S(-3, 108), S(-10, 135), S(-8, -219), }},
  {{ S(7, 126), S(-10, 81), S(1, 93), S(8, 70), S(6, 73), S(-1, 92), S(-7, 81), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 61), S(-11, 53), S(-11, 79), S(-2, 86), S(3, 34),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(2, 118), S(-9, 37), S(-9, 38), S(-6, 36), S(-7, 30), S(-8, 36), S(-9, 49), }},
  {{ S(9, 3), S(0, -36), S(-9, -24), S(-4, -58), S(-5, -55), S(-7, -25), S(0, -27), }},
  {{ S(-0, 59), S(-4, 33), S(-7, 37), S(-4, 34), S(-3, 19), S(-8, 35), S(-4, 25), }},
  {{ S(-1, 56), S(-7, 34), S(-11, 37), S(-5, 45), S(-4, 46), S(-10, 33), S(-9, 37), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1077, 245, -12, 95
);

inline TunableSigmoid<256> KING_SAFETY_ACTIVATION2(
        -5, 11
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(224);
inline VParam WINNABLE_BIAS = V(-653);

// Epoch duration: 7.51909s
// clang-format on
}  // namespace Clockwork
