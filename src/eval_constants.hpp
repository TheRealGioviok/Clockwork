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

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -4);
inline const PParam BISHOP_PAIR_VAL   = S(62, 238);
inline const PParam ROOK_OPEN_VAL     = S(109, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 10);
inline const PParam MINOR_BEHIND_PAWN = S(17, 43);
inline const PParam RESTRICTED_SQUARES = S(20, 5);

inline const PParam DOUBLED_PAWN_VAL = S(-24, -83);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -41);

inline const PParam POTENTIAL_CHECKER_VAL = S(-43, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 45);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(43, 5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -0), S(32, 35), S(62, 64), S(124, 214), S(390, 405), S(680, 823),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(50, 35), S(39, 27), S(55, 55), S(93, 183), S(386, 121),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -261), S(-94, -222), S(-67, -90), S(-22, 37), S(89, 199), S(229, 405),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-82, 53), S(-91, 36), S(-59, 105), S(-89, 231), S(-55, 342), S(51, 225),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-18, 69), S(-30, 58), S(-61, 107), S(-32, 135), S(73, 160), S(35, 195),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -39), S(23, -3), S(18, 36), S(23, 102), S(71, 272), S(335, 219),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -36), S(1, 7), S(-2, -27), S(-0, -69), S(-13, -178), S(-171, -459),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 231), S(9, 179), S(4, 105), S(12, 66), S(21, 72), S(59, 66), S(59, 35),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-132, -48), S(14, -2), S(2, 101), S(31, 154), S(47, 190), S(58, 198), S(41, 177),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-94, -395), S(-29, -142), S(5, -26), S(25, 21), S(53, 56), S(70, 93), S(88, 102), S(106, 110), S(126, 63),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-74, -352), S(-18, -129), S(31, -40), S(55, 12), S(77, 56), S(91, 88), S(95, 110), S(96, 131), S(101, 141), S(105, 148), S(115, 143), S(128, 125), S(129, 131), S(113, 94),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(98, -211), S(26, -10), S(46, 23), S(60, 42), S(71, 61), S(75, 74), S(79, 90), S(86, 97), S(90, 108), S(96, 116), S(100, 124), S(99, 131), S(102, 135), S(107, 122), S(126, 83),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-193, -204), S(-37, -89), S(-14, 51), S(4, 193), S(21, 236), S(29, 289), S(35, 326), S(42, 345), S(48, 368), S(52, 385), S(58, 394), S(63, 400), S(66, 407), S(68, 413), S(68, 415), S(67, 417), S(64, 420), S(66, 411), S(67, 408), S(71, 400), S(61, 391), S(73, 364), S(37, 393), S(-6, 384), S(-39, 383), S(-75, 405), S(-135, 433), S(-100, 368),
};

inline const PParam PAWN_THREAT_KNIGHT = S(195, 153);
inline const PParam PAWN_THREAT_BISHOP = S(170, 220);
inline const PParam PAWN_THREAT_ROOK   = S(190, 152);
inline const PParam PAWN_THREAT_QUEEN  = S(160, 21);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(9, 59), S(97, 95), S(103, 124), S(176, 92), S(162, 9), }},
  {{ S(7, 59), S(86, 93), S(102, 123), S(218, 613), S(149, 49), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 63), S(43, 106), S(60, 113), S(13, 12), S(151, -76), }},
  {{ S(4, 50), S(62, 82), S(96, 74), S(22, 11), S(365, 898), }},
}};
inline const PParam KING_THREAT  = S(-9, 157);
inline const PParam HANGING_PAWN  = S(34, 94);
inline const PParam HANGING_NON_PAWN  = S(70, 29);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(19, -18), S(20, 7),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(41, 45), S(112, -113),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(35, 13), S(49, -8),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(2, -19), S(4, -16), S(-2, -20), S(-7, -31), S(-11, -39), S(-18, -42), S(-17, -53), S(-26, -57), S(-31, -73),
};

inline const PParam ROOK_LINEUP = S(18, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(184, 276),    S(62, 398),     S(68, 386),     S(158, 271),    S(194, 169),    S(145, 209),    S(122, 239),    S(222, 181),    //
    S(42, 62),      S(56, 109),     S(36, 62),      S(50, -2),      S(42, -39),     S(15, -10),     S(17, 29),      S(-22, 52),     //
    S(38, -14),     S(13, -6),      S(46, -45),     S(27, -71),     S(20, -88),     S(6, -73),      S(-37, -46),    S(-39, -7),     //
    S(-8, -75),     S(-30, -45),    S(1, -63),      S(-10, -78),    S(-30, -87),    S(-35, -75),    S(-81, -56),    S(-74, -53),    //
    S(-14, -110),   S(19, -105),    S(1, -47),      S(-14, -49),    S(-41, -58),    S(-51, -69),    S(-79, -70),    S(-84, -74),    //
    S(11, -105),    S(85, -96),     S(74, -38),     S(23, -13),     S(-6, -33),     S(-26, -62),    S(-47, -57),    S(-60, -55),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-261, -500),  S(-257, 52),    S(-263, -29),   S(2, 43),       S(-88, 42),     S(-265, 81),    S(-346, 100),   S(-348, -406),  //
    S(-0, -11),     S(5, 27),       S(86, 25),      S(84, 61),      S(90, 49),      S(53, 28),      S(-16, 25),     S(-41, 21),     //
    S(41, -24),     S(42, 28),      S(58, 64),      S(76, 72),      S(57, 72),      S(22, 60),      S(9, 35),       S(-34, 12),     //
    S(91, 24),      S(93, 48),      S(100, 70),     S(103, 111),    S(110, 108),    S(73, 74),      S(53, 39),      S(33, 31),      //
    S(78, 15),      S(102, 3),      S(99, 51),      S(95, 80),      S(80, 82),      S(73, 65),      S(59, 21),      S(25, 26),      //
    S(18, -42),     S(42, -26),     S(52, 20),      S(61, 53),      S(58, 52),      S(30, 15),      S(15, -18),     S(-25, -42),    //
    S(36, -24),     S(41, -8),      S(28, -21),     S(37, 10),      S(34, 8),       S(4, -46),      S(-33, -2),     S(-50, -84),    //
    S(-43, -92),    S(9, -28),      S(27, -42),     S(46, -30),     S(26, -19),     S(-8, -51),     S(-19, -28),    S(-72, -142),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-130, 21),    S(-190, 102),   S(-399, 167),   S(-271, 97),    S(-303, 137),   S(-304, 151),   S(-226, 127),   S(-129, 72),    //
    S(-28, -21),    S(-64, 86),     S(-46, 61),     S(-68, 59),     S(-65, 75),     S(-38, 49),     S(-10, 40),     S(-52, 23),     //
    S(34, 17),      S(14, 58),      S(28, 67),      S(27, 54),      S(22, 43),      S(18, 45),      S(10, 42),      S(11, 12),      //
    S(13, -8),      S(47, 18),      S(58, 33),      S(79, 54),      S(103, 38),     S(40, 18),      S(45, -4),      S(-2, -2),      //
    S(36, -43),     S(44, 3),       S(75, 13),      S(91, 24),      S(73, 37),      S(65, 23),      S(18, 4),       S(10, -38),     //
    S(55, -31),     S(81, -25),     S(94, 4),       S(65, 28),      S(58, 10),      S(57, 13),      S(57, -6),      S(13, -25),     //
    S(27, -73),     S(110, -60),    S(66, -21),     S(46, -2),      S(30, -0),      S(46, -44),     S(43, -59),     S(39, -50),     //
    S(43, -73),     S(21, -26),     S(30, -12),     S(44, -32),     S(25, -21),     S(37, 12),      S(43, -18),     S(36, -63),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(174, 109),    S(205, 130),    S(158, 160),    S(142, 132),    S(204, 86),     S(161, 113),    S(170, 133),    S(153, 130),    //
    S(86, 150),     S(145, 155),    S(187, 127),    S(142, 113),    S(180, 99),     S(145, 124),    S(97, 156),     S(90, 159),     //
    S(58, 146),     S(179, 89),     S(205, 72),     S(177, 56),     S(180, 73),     S(121, 113),    S(117, 133),    S(64, 170),     //
    S(30, 110),     S(93, 119),     S(114, 94),     S(98, 95),      S(125, 75),     S(84, 116),     S(74, 132),     S(21, 157),     //
    S(6, 46),       S(64, 56),      S(58, 76),      S(28, 87),      S(35, 90),      S(24, 114),     S(8, 111),      S(-14, 118),    //
    S(16, -33),     S(85, -9),      S(75, 18),      S(50, 29),      S(61, 34),      S(37, 58),      S(33, 42),      S(-5, 48),      //
    S(-62, -40),    S(62, -76),     S(70, -37),     S(58, -3),      S(61, -3),      S(45, 9),       S(39, -7),      S(4, -4),       //
    S(1, -64),      S(23, -30),     S(85, -43),     S(96, -42),     S(98, -36),     S(75, -16),     S(67, -23),     S(50, -15),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(88, 153),     S(146, 154),    S(56, 299),     S(-3, 395),     S(35, 349),     S(71, 258),     S(72, 175),     S(25, 208),     //
    S(58, 184),     S(77, 238),     S(37, 322),     S(-82, 438),    S(-40, 405),    S(20, 288),     S(58, 175),     S(40, 146),     //
    S(19, 235),     S(60, 261),     S(29, 339),     S(-9, 373),     S(12, 363),     S(52, 259),     S(83, 155),     S(63, 119),     //
    S(16, 172),     S(27, 237),     S(-12, 307),    S(-11, 361),    S(5, 352),      S(22, 239),     S(59, 154),     S(36, 117),     //
    S(13, 146),     S(11, 170),     S(3, 219),      S(-23, 287),    S(-10, 303),    S(12, 239),     S(16, 175),     S(36, 80),      //
    S(5, 52),       S(35, 61),      S(33, 136),     S(12, 157),     S(21, 164),     S(21, 186),     S(42, 117),     S(23, 97),      //
    S(-25, -95),    S(4, -93),      S(13, -24),     S(41, 16),      S(37, 53),      S(37, 25),      S(12, 65),      S(24, 37),      //
    S(-41, -80),    S(-10, -240),   S(23, -243),    S(33, -133),    S(38, -57),     S(36, -75),     S(34, -61),     S(4, -6),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(164, -556),   S(473, 84),     S(312, 193),    S(19, 191),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(366, -185),   S(362, 187),    S(210, 203),    S(26, 156),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(195, 44),     S(229, 174),    S(112, 197),    S(-52, 178),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(35, 7),       S(111, 113),    S(-21, 173),    S(-119, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-112, 1),     S(-23, 75),     S(-87, 145),    S(-183, 197),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -34),    S(12, 33),      S(-69, 115),    S(-127, 158),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -93),     S(30, -10),     S(-36, 50),     S(-112, 105),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-26, -212),   S(4, -89),      S(-76, -28),    S(-83, -40),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-82, -449);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(6, -3), S(9, 10), S(8, 4), S(2, 1), S(2, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(6, -8), S(3, 3), S(2, 3), S(1, 0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(2, -2);
inline const PParam KS_FLANK_DEFENSE = S(-2, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -2);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -18), S(-9, 4), S(-2, -10), S(7, -17), S(13, -28), S(4, -56), S(-5, -47), }},
  {{ S(1, 4), S(-21, 1), S(-16, 11), S(-12, 16), S(-8, 9), S(-10, -12), S(-18, -20), }},
  {{ S(-4, -2), S(-12, -10), S(-10, 19), S(-8, 19), S(-9, 7), S(-7, -18), S(-22, -38), }},
  {{ S(5, 9), S(-9, 20), S(-7, 38), S(-1, 44), S(-2, 39), S(1, 18), S(8, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 26), S(-5, 2), S(-7, 9), S(-6, 29), S(-1, 47),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, 11), S(-43, -121), S(-9, -39), S(-1, 6), S(-2, 4), S(-8, 9), S(-4, 12), }},
  {{ S(6, -3), S(-26, -124), S(-8, -29), S(-4, 1), S(-1, -1), S(-10, 4), S(2, 6), }},
  {{ S(-1, 11), S(-8, -69), S(6, -14), S(2, 9), S(-4, 12), S(-10, 18), S(-8, 22), }},
  {{ S(-1, 2), S(1, -62), S(-0, 25), S(-3, 26), S(-5, 9), S(-11, 13), S(-11, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1427, 912, -22, -3
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(86);
inline VParam WINNABLE_PAWN_ENDGAME = V(77);
inline VParam WINNABLE_BIAS = V(-391);

// clang-format on
}  // namespace Clockwork
