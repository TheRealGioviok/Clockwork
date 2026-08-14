#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(208, 510);
inline const PParam KNIGHT_MAT = S(1112, 1612);
inline const PParam BISHOP_MAT = S(1199, 1740);
inline const PParam ROOK_MAT   = S(1474, 2699);
inline const PParam QUEEN_MAT  = S(3145, 4488);

inline const PParam TEMPO_VAL  = S(65, 62);

inline const PParam BISHOP_XRAY_PAWNS   = S(-16, -1);
inline const PParam BISHOP_PAIR_VAL   = S(51, 244);
inline const PParam ROOK_OPEN_VAL     = S(109, -2);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 10);
inline const PParam MINOR_BEHIND_PAWN = S(16, 40);
inline const PParam RESTRICTED_SQUARES = S(18, 8);

inline const PParam DOUBLED_PAWN_VAL = S(-26, -79);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -39);

inline const PParam POTENTIAL_CHECKER_VAL = S(-51, -35);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(36, 42);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(51, 41);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 9);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(13, 79);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -53);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(10, 7), S(33, 39), S(65, 67), S(120, 221), S(382, 404), S(661, 818),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 36), S(40, 27), S(52, 59), S(75, 191), S(356, 130),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-100, -263), S(-95, -223), S(-69, -87), S(-27, 44), S(76, 217), S(195, 438),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-84, 47), S(-110, 33), S(-85, 108), S(-122, 236), S(-105, 354), S(4, 229),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-31, 69), S(-54, 63), S(-88, 113), S(-65, 144), S(29, 174), S(22, 198),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(34, -47), S(29, -9), S(12, 31), S(2, 108), S(41, 286), S(317, 208),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(19, -36), S(5, 8), S(-3, -25), S(2, -68), S(-3, -183), S(-156, -464),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(7, 246), S(-1, 194), S(0, 112), S(13, 70), S(24, 74), S(61, 70), S(56, 44),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-147, -45), S(4, -7), S(-1, 100), S(22, 153), S(42, 191), S(55, 199), S(37, 180),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-32, -380), S(-28, -128), S(-26, -16), S(-25, 41), S(-24, 86), S(-24, 133), S(-24, 160), S(-24, 187), S(-26, 197),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-38, -367), S(-32, -154), S(-28, -47), S(-26, 11), S(-25, 60), S(-24, 94), S(-24, 117), S(-24, 139), S(-24, 151), S(-25, 171), S(-24, 164), S(-26, 190), S(-24, 165), S(-29, 191),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-15, -142), S(-21, 12), S(-19, 54), S(-18, 84), S(-17, 104), S(-17, 116), S(-16, 129), S(-15, 135), S(-15, 145), S(-15, 153), S(-15, 161), S(-15, 169), S(-15, 174), S(-16, 175), S(-16, 158),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-53, -106), S(-47, 137), S(-45, 212), S(-42, 272), S(-40, 296), S(-39, 323), S(-38, 342), S(-37, 354), S(-36, 363), S(-36, 370), S(-35, 374), S(-35, 378), S(-35, 383), S(-35, 389), S(-35, 392), S(-35, 396), S(-35, 396), S(-35, 396), S(-35, 397), S(-36, 397), S(-36, 395), S(-36, 385), S(-38, 406), S(-40, 405), S(-41, 409), S(-41, 414), S(-44, 439), S(-42, 399),
};

inline const PParam PAWN_THREAT_KNIGHT = S(187, 170);
inline const PParam PAWN_THREAT_BISHOP = S(167, 227);
inline const PParam PAWN_THREAT_ROOK   = S(177, 172);
inline const PParam PAWN_THREAT_QUEEN  = S(160, 11);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(11, 54), S(97, 100), S(100, 131), S(175, 98), S(161, 15), }},
  {{ S(9, 55), S(87, 97), S(100, 129), S(207, 625), S(137, 94), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 67), S(41, 115), S(55, 122), S(5, 17), S(145, -75), }},
  {{ S(5, 50), S(59, 86), S(92, 79), S(17, 18), S(352, 893), }},
}};
inline const PParam KING_THREAT  = S(-22, 172);
inline const PParam HANGING_PAWN  = S(29, 98);
inline const PParam HANGING_NON_PAWN  = S(66, 35);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(24, -21), S(-34, 67),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(44, 40), S(58, -47),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(41, -8), S(-39, 65),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -19), S(7, -18), S(3, -25), S(-3, -33), S(-9, -39), S(-15, -45), S(-17, -56), S(-23, -57), S(-30, -73),
};

inline const PParam ROOK_LINEUP = S(18, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(175, 282),    S(53, 405),     S(83, 385),     S(146, 279),    S(183, 170),    S(133, 227),    S(108, 253),    S(205, 203),    //
    S(44, 52),      S(61, 93),      S(48, 40),      S(56, -13),     S(46, -48),     S(17, -22),     S(13, 26),      S(-27, 59),     //
    S(43, -19),     S(25, -10),     S(64, -57),     S(40, -79),     S(27, -91),     S(7, -74),      S(-40, -35),    S(-44, 4),      //
    S(-3, -80),     S(-20, -54),    S(15, -72),     S(-3, -85),     S(-27, -90),    S(-39, -68),    S(-90, -47),    S(-87, -41),    //
    S(-11, -122),   S(24, -117),    S(5, -51),      S(-19, -48),    S(-45, -55),    S(-61, -60),    S(-91, -58),    S(-94, -64),    //
    S(12, -118),    S(92, -112),    S(70, -42),     S(16, -10),     S(-15, -23),    S(-33, -45),    S(-58, -46),    S(-74, -45),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-189, -535),  S(-222, 77),    S(-218, -8),    S(13, 65),      S(-72, 63),     S(-244, 107),   S(-325, 136),   S(-297, -421),  //
    S(15, 13),      S(19, 44),      S(101, 29),     S(95, 67),      S(100, 56),     S(58, 46),      S(-8, 50),      S(-34, 46),     //
    S(64, -17),     S(76, 19),      S(103, 26),     S(117, 33),     S(101, 35),     S(67, 26),      S(32, 38),      S(-18, 25),     //
    S(104, 40),     S(127, 33),     S(151, 31),     S(147, 81),     S(146, 86),     S(116, 46),     S(80, 38),      S(43, 52),      //
    S(87, 36),      S(124, 7),      S(136, 30),     S(126, 70),     S(116, 69),     S(110, 49),     S(76, 30),      S(29, 50),      //
    S(24, -22),     S(71, -31),     S(99, -12),     S(105, 30),     S(100, 30),     S(76, -7),      S(39, -12),     S(-17, -23),    //
    S(36, 17),      S(42, 24),      S(46, -15),     S(53, 17),      S(50, 16),      S(24, -36),     S(-25, 25),     S(-50, -52),    //
    S(-43, -60),    S(5, 3),        S(32, -8),      S(49, -5),      S(33, 2),       S(-8, -25),     S(-25, 4),      S(-71, -109),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-103, 31),    S(-161, 112),   S(-362, 176),   S(-250, 112),   S(-274, 147),   S(-273, 160),   S(-199, 132),   S(-99, 75),     //
    S(1, -9),       S(-36, 96),     S(-20, 71),     S(-41, 64),     S(-41, 79),     S(-13, 53),     S(16, 47),      S(-26, 31),     //
    S(72, 7),       S(53, 53),      S(71, 54),      S(58, 48),      S(57, 30),      S(53, 41),      S(38, 45),      S(38, 16),      //
    S(48, -8),      S(84, 14),      S(101, 23),     S(123, 35),     S(139, 29),     S(74, 12),      S(72, -3),      S(22, 4),       //
    S(59, -37),     S(73, -2),      S(112, 2),      S(126, 17),     S(110, 27),     S(94, 27),      S(45, 8),       S(28, -26),     //
    S(78, -25),     S(104, -26),    S(120, 2),      S(92, 25),      S(90, 10),      S(81, 18),      S(78, 6),       S(35, -13),     //
    S(49, -67),     S(127, -46),    S(83, -11),     S(64, 6),       S(49, 5),       S(63, -34),     S(62, -46),     S(54, -34),     //
    S(66, -51),     S(41, -9),      S(38, 11),      S(58, -17),     S(43, -13),     S(50, 21),      S(58, -2),      S(59, -43),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(195, 116),    S(217, 141),    S(160, 173),    S(147, 137),    S(204, 103),    S(172, 123),    S(182, 142),    S(164, 143),    //
    S(105, 156),    S(153, 165),    S(193, 133),    S(156, 112),    S(185, 112),    S(157, 131),    S(108, 170),    S(100, 172),    //
    S(87, 140),     S(199, 87),     S(227, 63),     S(201, 45),     S(195, 78),     S(139, 116),    S(132, 139),    S(80, 180),     //
    S(65, 97),      S(125, 108),    S(145, 78),     S(131, 75),     S(148, 73),     S(110, 112),    S(100, 130),    S(42, 160),     //
    S(39, 31),      S(96, 43),      S(85, 65),      S(56, 73),      S(59, 89),      S(47, 115),     S(30, 115),     S(8, 120),      //
    S(44, -42),     S(109, -15),    S(94, 12),      S(71, 27),      S(76, 43),      S(54, 65),      S(51, 50),      S(13, 58),      //
    S(-33, -48),    S(84, -78),     S(88, -43),     S(78, -10),     S(78, -2),      S(63, 12),      S(52, 1),       S(23, -0),      //
    S(26, -66),     S(50, -36),     S(109, -48),    S(116, -46),    S(117, -35),    S(94, -13),     S(88, -17),     S(69, -12),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(120, 158),    S(170, 163),    S(74, 304),     S(17, 392),     S(57, 339),     S(81, 267),     S(86, 180),     S(51, 206),     //
    S(72, 203),     S(86, 262),     S(51, 324),     S(-55, 426),    S(-19, 400),    S(29, 293),     S(61, 198),     S(44, 170),     //
    S(36, 251),     S(81, 259),     S(51, 330),     S(20, 353),     S(33, 343),     S(67, 250),     S(87, 169),     S(72, 135),     //
    S(42, 177),     S(63, 232),     S(26, 282),     S(25, 330),     S(31, 332),     S(42, 230),     S(83, 146),     S(48, 132),     //
    S(34, 158),     S(37, 175),     S(28, 215),     S(8, 266),      S(13, 286),     S(29, 230),     S(33, 174),     S(49, 88),      //
    S(14, 69),      S(44, 81),      S(44, 151),     S(24, 161),     S(32, 168),     S(30, 200),     S(48, 126),     S(30, 105),     //
    S(-23, -62),    S(4, -63),      S(12, 10),      S(43, 42),      S(40, 78),      S(42, 50),      S(16, 87),      S(28, 60),      //
    S(-37, -76),    S(-9, -208),    S(19, -203),    S(34, -97),     S(42, -19),     S(40, -38),     S(37, -27),     S(12, 5),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(194, -539),   S(460, 118),    S(294, 221),    S(25, 211),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(398, -157),   S(380, 220),    S(232, 221),    S(66, 164),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(215, 65),     S(251, 186),    S(136, 203),    S(-19, 175),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(45, 26),      S(123, 117),    S(-4, 169),     S(-110, 197),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-124, 12),    S(-45, 85),     S(-98, 149),    S(-201, 200),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-81, -16),    S(-20, 46),     S(-87, 121),    S(-151, 169),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(17, -96),     S(21, -14),     S(-38, 46),     S(-118, 107),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-22, -222),   S(10, -107),    S(-66, -47),    S(-73, -65),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-32, -445);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(5, 0), S(9, 15), S(8, 10), S(3, 4), S(4, -8),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, -5), S(4, 5), S(1, 3), S(2, 2), S(3, 1),
};

inline const PParam KS_FLANK_ATTACK = S(2, -1);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, 1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(9, -7), S(-8, 4), S(-5, -10), S(2, -10), S(5, -13), S(-3, -29), S(0, -47), }},
  {{ S(-0, 4), S(-15, -11), S(-10, -5), S(-5, 5), S(-5, 5), S(-9, -11), S(-4, -49), }},
  {{ S(-8, -2), S(-12, -15), S(-12, 6), S(-8, 10), S(-8, 6), S(-11, -10), S(-14, -50), }},
  {{ S(1, 8), S(-9, 0), S(-7, 21), S(-2, 26), S(-2, 21), S(3, 14), S(6, -10), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 16), S(-4, -4), S(-6, 1), S(-5, 14), S(2, 29),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 7), S(-38, -62), S(-14, -17), S(-5, 4), S(-6, -1), S(-8, 4), S(-8, 4), }},
  {{ S(6, -2), S(-15, -94), S(-7, -23), S(-7, -1), S(-5, -6), S(-11, -1), S(-3, 1), }},
  {{ S(0, 3), S(-11, -39), S(1, -1), S(-2, 6), S(-5, 4), S(-9, 8), S(-7, 12), }},
  {{ S(-0, -0), S(-3, -35), S(-4, 17), S(-4, 20), S(-6, 4), S(-11, 2), S(-6, 4), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1814, 1006, -20, -14
);

inline const PParam KS_MOBILITY = S(-43, -2);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(62);
inline VParam WINNABLE_BIAS = V(-376);

// Epoch duration: 9.01049s
// clang-format on
}  // namespace Clockwork
