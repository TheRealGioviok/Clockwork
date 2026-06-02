#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(192, 496);
inline const PParam KNIGHT_MAT = S(799, 1543);
inline const PParam BISHOP_MAT = S(847, 1639);
inline const PParam ROOK_MAT   = S(1004, 2584);
inline const PParam QUEEN_MAT  = S(2425, 3904);
inline const PParam TEMPO_VAL  = S(68, 49);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -5);
inline const PParam BISHOP_PAIR_VAL   = S(63, 226);
inline const PParam ROOK_OPEN_VAL     = S(109, -5);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 12);
inline const PParam MINOR_BEHIND_PAWN = S(14, 37);
inline const PParam RESTRICTED_SQUARES = S(-22, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -80);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -36);

inline const PParam POTENTIAL_CHECKER_VAL = S(-47, -37);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 42);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 53);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -44);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -3), S(31, 35), S(59, 65), S(125, 196), S(425, 285), S(583, 603),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(43, 34), S(37, 24), S(53, 53), S(100, 168), S(406, 90),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-87, -266), S(-86, -232), S(-64, -94), S(-25, 42), S(65, 237), S(213, 406),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -43), S(25, -3), S(15, 38), S(13, 116), S(73, 247), S(105, 440),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -39), S(1, 10), S(-7, -22), S(-4, -58), S(-7, -168), S(-166, -334),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(11, 240), S(-2, 190), S(-1, 112), S(9, 72), S(20, 74), S(58, 71), S(49, 51),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-141, -48), S(16, 4), S(1, 108), S(25, 157), S(38, 193), S(51, 199), S(36, 181),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-83, -367), S(-24, -137), S(5, -20), S(29, 24), S(57, 51), S(72, 85), S(90, 89), S(109, 95), S(127, 47),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-66, -273), S(-18, -108), S(33, -40), S(55, 8), S(78, 46), S(90, 71), S(97, 92), S(102, 109), S(106, 121), S(115, 125), S(126, 116), S(142, 100), S(150, 97), S(127, 74),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -185), S(23, -10), S(44, 23), S(60, 37), S(70, 55), S(74, 69), S(79, 83), S(85, 88), S(89, 100), S(96, 105), S(102, 110), S(105, 116), S(108, 120), S(112, 109), S(143, 57),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-204, -131), S(-61, -10), S(-35, 108), S(-14, 231), S(2, 270), S(10, 318), S(16, 351), S(23, 365), S(27, 388), S(29, 406), S(35, 413), S(38, 423), S(41, 426), S(42, 432), S(42, 434), S(39, 440), S(36, 440), S(38, 431), S(40, 427), S(42, 422), S(40, 405), S(44, 382), S(17, 410), S(-17, 388), S(-43, 389), S(-70, 405), S(-113, 432), S(-79, 347),
};

inline const PParam PAWN_THREAT_KNIGHT = S(192, 142);
inline const PParam PAWN_THREAT_BISHOP = S(171, 206);
inline const PParam PAWN_THREAT_ROOK   = S(189, 146);
inline const PParam PAWN_THREAT_QUEEN  = S(148, 13);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 51), S(92, 91), S(104, 120), S(201, 120), S(158, 16), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 44), S(50, 85), S(69, 90), S(-24, 9), S(176, -51), S(0, 0),
};
inline const PParam KING_THREAT  = S(-33, 164);
inline const PParam HANGING_PAWN  = S(30, 93);
inline const PParam HANGING_NON_PAWN  = S(67, 25);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -17), S(5, -14), S(-0, -20), S(-5, -29), S(-11, -37), S(-16, -44), S(-18, -57), S(-23, -60), S(-26, -78),
};

inline const PParam ROOK_LINEUP = S(14, 78);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(178, 272),    S(48, 376),     S(76, 346),     S(135, 251),    S(191, 159),    S(118, 225),    S(79, 273),     S(220, 207),    //
    S(41, 64),      S(53, 104),     S(39, 43),      S(46, -30),     S(41, -66),     S(11, -21),     S(5, 37),       S(-21, 69),     //
    S(33, -7),      S(8, 0),        S(44, -48),     S(27, -72),     S(17, -88),     S(-6, -70),     S(-41, -33),    S(-42, 6),      //
    S(-10, -68),    S(-33, -39),    S(4, -64),      S(-7, -75),     S(-29, -84),    S(-40, -70),    S(-88, -46),    S(-79, -45),    //
    S(-13, -106),   S(21, -106),    S(8, -48),      S(-8, -53),     S(-35, -64),    S(-53, -69),    S(-80, -65),    S(-82, -67),    //
    S(10, -104),    S(85, -97),     S(70, -43),     S(24, -17),     S(-5, -40),     S(-25, -59),    S(-49, -54),    S(-61, -51),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-256, -503),  S(-242, 40),    S(-258, -95),   S(28, 15),      S(-76, 27),     S(-241, 56),    S(-357, 100),   S(-338, -384),  //
    S(-1, -23),     S(4, 20),       S(103, 6),      S(86, 46),      S(96, 35),      S(57, 16),      S(-14, 15),     S(-28, 5),      //
    S(46, -37),     S(38, 25),      S(76, 45),      S(82, 59),      S(71, 59),      S(32, 53),      S(14, 26),      S(-34, 4),      //
    S(100, 13),     S(96, 33),      S(105, 62),     S(110, 101),    S(113, 105),    S(77, 71),      S(52, 34),      S(39, 27),      //
    S(78, 13),      S(107, 1),      S(104, 52),     S(95, 84),      S(83, 83),      S(80, 65),      S(65, 10),      S(24, 26),      //
    S(18, -36),     S(48, -19),     S(51, 26),      S(65, 60),      S(60, 57),      S(32, 21),      S(17, -7),      S(-24, -39),    //
    S(38, -21),     S(45, -16),     S(28, -11),     S(35, 18),      S(32, 12),      S(6, -40),      S(-26, -4),     S(-35, -99),    //
    S(-41, -80),    S(5, -21),      S(27, -37),     S(49, -32),     S(27, -9),      S(-9, -48),     S(-19, -25),    S(-61, -135),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-124, 23),    S(-165, 90),    S(-430, 186),   S(-262, 82),    S(-281, 128),   S(-289, 139),   S(-188, 99),    S(-120, 56),    //
    S(-28, -16),    S(-77, 91),     S(-34, 48),     S(-67, 62),     S(-61, 63),     S(-27, 36),     S(-5, 31),      S(-44, 18),     //
    S(41, 17),      S(12, 63),      S(32, 69),      S(28, 60),      S(25, 36),      S(20, 44),      S(12, 45),      S(16, 16),      //
    S(17, -7),      S(60, 13),      S(64, 36),      S(76, 56),      S(103, 42),     S(47, 22),      S(52, -6),      S(4, -6),       //
    S(53, -58),     S(50, -5),      S(81, 10),      S(98, 25),      S(79, 43),      S(69, 22),      S(22, 8),       S(21, -34),     //
    S(63, -39),     S(85, -30),     S(98, 6),       S(67, 34),      S(65, 14),      S(62, 18),      S(69, -10),     S(22, -22),     //
    S(35, -93),     S(113, -52),    S(72, -16),     S(49, 2),       S(33, 4),       S(54, -43),     S(51, -50),     S(47, -64),     //
    S(51, -84),     S(20, -18),     S(20, 1),       S(49, -30),     S(31, -21),     S(37, 13),      S(47, -22),     S(44, -61),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(168, 86),     S(204, 104),    S(152, 135),    S(140, 110),    S(197, 72),     S(161, 87),     S(178, 94),     S(152, 98),     //
    S(86, 141),     S(146, 136),    S(196, 103),    S(143, 104),    S(188, 84),     S(140, 112),    S(95, 138),     S(90, 142),     //
    S(66, 130),     S(182, 83),     S(209, 61),     S(182, 48),     S(180, 69),     S(128, 99),     S(129, 110),    S(73, 154),     //
    S(40, 98),      S(105, 103),    S(126, 79),     S(105, 81),     S(132, 69),     S(95, 108),     S(90, 116),     S(30, 144),     //
    S(11, 34),      S(80, 46),      S(67, 62),      S(42, 67),      S(50, 77),      S(37, 103),     S(16, 102),     S(-5, 104),     //
    S(22, -34),     S(93, -13),     S(81, 12),      S(63, 16),      S(72, 23),      S(40, 58),      S(45, 36),      S(-0, 47),      //
    S(-65, -28),    S(67, -70),     S(73, -34),     S(60, 0),       S(63, -3),      S(46, 14),      S(35, -1),      S(7, 4),        //
    S(-4, -59),     S(10, -16),     S(82, -32),     S(91, -35),     S(90, -26),     S(68, -3),      S(66, -14),     S(47, -9),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(49, 174),     S(131, 129),    S(50, 266),     S(4, 349),      S(46, 304),     S(68, 230),     S(62, 149),     S(-16, 220),    //
    S(54, 173),     S(48, 254),     S(25, 302),     S(-112, 423),   S(-62, 396),    S(-15, 303),    S(24, 176),     S(9, 171),      //
    S(7, 240),      S(37, 278),     S(5, 350),      S(-34, 377),    S(-18, 375),    S(26, 269),     S(55, 165),     S(43, 115),     //
    S(25, 145),     S(13, 246),     S(-19, 297),    S(-39, 368),    S(-23, 371),    S(4, 247),      S(41, 163),     S(18, 132),     //
    S(13, 141),     S(7, 169),      S(-9, 227),     S(-32, 289),    S(-23, 316),    S(-4, 249),     S(2, 178),      S(30, 83),      //
    S(12, 44),      S(33, 67),      S(27, 148),     S(2, 169),      S(11, 175),     S(10, 209),     S(28, 134),     S(19, 94),      //
    S(-17, -101),   S(10, -87),     S(13, -10),     S(35, 31),      S(29, 71),      S(31, 49),      S(5, 84),       S(20, 63),      //
    S(-34, -66),    S(-18, -219),   S(10, -218),    S(27, -110),    S(32, -29),     S(34, -64),     S(32, -42),     S(5, 1),        //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(101, -581),   S(435, 33),     S(276, 188),    S(28, 145),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(303, -163),   S(340, 120),    S(179, 184),    S(33, 141),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(159, 52),     S(197, 163),    S(102, 189),    S(-12, 163),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-11, 18),     S(71, 119),     S(-42, 168),    S(-68, 181),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-130, 3),     S(-49, 82),     S(-115, 149),   S(-171, 199),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-60, -27),    S(2, 40),       S(-85, 120),    S(-121, 167),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -85),     S(27, -6),      S(-37, 58),     S(-90, 106),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -201),   S(4, -84),      S(-78, -19),    S(-45, -56),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-86, -371);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -2), S(11, 12), S(12, 5), S(4, 4), S(3, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(5, 5), S(2, 3), S(3, 2), S(3, -0),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -21), S(-12, 2), S(-8, -12), S(3, -17), S(8, -27), S(-3, -43), S(-12, -49), }},
  {{ S(16, 9), S(-10, 5), S(-5, 12), S(3, 22), S(4, 18), S(-1, -1), S(-9, -15), }},
  {{ S(-3, -3), S(-12, -11), S(-14, 16), S(-8, 15), S(-8, 11), S(-12, -10), S(-26, -46), }},
  {{ S(2, 7), S(-16, 12), S(-12, 33), S(-7, 36), S(-9, 35), S(-5, 22), S(-1, -9), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(8, 23), S(-9, 3), S(-12, 11), S(-8, 24), S(5, 38),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 11), S(-54, -135), S(-15, -39), S(-2, 2), S(-6, 4), S(-10, 11), S(-9, 10), }},
  {{ S(9, -2), S(-30, -132), S(-9, -34), S(-6, -3), S(-3, -4), S(-11, 2), S(-1, 1), }},
  {{ S(-3, 9), S(-14, -75), S(3, -9), S(-2, 7), S(-7, 10), S(-14, 18), S(-8, 17), }},
  {{ S(-2, 2), S(-3, -42), S(-2, 24), S(-4, 24), S(-10, 12), S(-17, 11), S(-13, 19), }},
}};
inline TunableSigmoid<32> SAME_SIDE_KS_ACTIVATION(
        1258, 915, -23, 4
);
inline TunableSigmoid<32> OPP_SIDE_KS_ACTIVATION(
        1069, 759, -8, 7
);
inline TunableSigmoid<32> OCOS_C_SIDE_KS_ACTIVATION(
        1004, 807, -15, 3
);
inline TunableSigmoid<32> OCOS_S_SIDE_KS_ACTIVATION(
        971, 792, 18, 2
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(83);
inline VParam WINNABLE_PAWN_ENDGAME = V(109);
inline VParam WINNABLE_BIAS = V(-379);

// Epoch duration: 7.25715s
// clang-format on
}  // namespace Clockwork
