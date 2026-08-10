#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(203, 512);
inline const PParam KNIGHT_MAT = S(819, 1610);
inline const PParam BISHOP_MAT = S(872, 1696);
inline const PParam ROOK_MAT   = S(1049, 2692);
inline const PParam QUEEN_MAT  = S(2441, 4154);

inline const PParam TEMPO_VAL  = S(70, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(63, 242);
inline const PParam ROOK_OPEN_VAL     = S(110, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-22, -82);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -43);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 51);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 71);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -2), S(33, 36), S(60, 66), S(123, 215), S(394, 407), S(684, 825),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 33), S(40, 26), S(54, 57), S(91, 183), S(390, 124),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-95, -263), S(-96, -221), S(-68, -87), S(-23, 40), S(87, 201), S(232, 412),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-82, 54), S(-94, 36), S(-60, 106), S(-89, 231), S(-55, 344), S(52, 225),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-18, 70), S(-29, 60), S(-61, 108), S(-33, 137), S(74, 160), S(34, 198),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -40), S(24, -2), S(16, 35), S(21, 104), S(72, 274), S(337, 220),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -36), S(3, 8), S(-3, -27), S(-0, -68), S(-14, -176), S(-171, -462),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 236), S(9, 184), S(3, 107), S(11, 68), S(19, 73), S(58, 67), S(62, 38),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-132, -49), S(16, -3), S(3, 101), S(30, 151), S(46, 186), S(57, 195), S(43, 175),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-88, -397), S(-19, -137), S(11, -24), S(33, 24), S(60, 57), S(75, 94), S(93, 101), S(112, 110), S(132, 62),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-73, -351), S(-18, -123), S(34, -37), S(59, 17), S(79, 60), S(91, 91), S(96, 113), S(99, 134), S(103, 146), S(110, 152), S(119, 146), S(133, 129), S(133, 134), S(117, 99),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -213), S(24, -11), S(46, 23), S(61, 43), S(72, 61), S(76, 75), S(81, 91), S(87, 97), S(91, 110), S(97, 118), S(101, 124), S(101, 134), S(104, 138), S(110, 124), S(129, 86),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-196, -201), S(-39, -89), S(-15, 54), S(4, 197), S(22, 240), S(29, 294), S(36, 332), S(42, 350), S(47, 373), S(51, 390), S(57, 399), S(61, 406), S(65, 412), S(66, 419), S(67, 420), S(67, 424), S(63, 425), S(66, 418), S(67, 414), S(71, 406), S(60, 397), S(73, 369), S(37, 399), S(-7, 389), S(-41, 387), S(-76, 410), S(-136, 438), S(-100, 372),
};

inline const std::array<std::array<PParam, 4>, 2> KNIGHT_NO_BACKWARD_MOBILITY = {{
  {{ S(-1, -43), S(12, 65), S(-53, -7), S(-156, -166), }},
  {{ S(10, -17), S(-49, 16), S(-68, -30), S(0, 0), }},
}};
inline const std::array<std::array<PParam, 4>, 2> BISHOP_NO_BACKWARD_MOBILITY = {{
  {{ S(27, -16), S(13, 3), S(-54, -48), S(-177, -312), }},
  {{ S(25, -13), S(8, -9), S(-57, 8), S(0, 0), }},
}};
inline const PParam PAWN_THREAT_KNIGHT = S(198, 156);
inline const PParam PAWN_THREAT_BISHOP = S(172, 223);
inline const PParam PAWN_THREAT_ROOK   = S(192, 154);
inline const PParam PAWN_THREAT_QUEEN  = S(161, 20);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(8, 57), S(99, 97), S(105, 126), S(178, 95), S(165, 11), }},
  {{ S(6, 58), S(88, 95), S(104, 124), S(220, 621), S(150, 50), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 65), S(45, 108), S(59, 113), S(12, 12), S(152, -77), }},
  {{ S(4, 50), S(62, 82), S(96, 72), S(24, 12), S(369, 900), }},
}};
inline const PParam KING_THREAT  = S(-11, 158);
inline const PParam HANGING_PAWN  = S(32, 93);
inline const PParam HANGING_NON_PAWN  = S(72, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(23, 8),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(43, 45), S(113, -113),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 13), S(50, -7),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -17), S(4, -15), S(-0, -22), S(-6, -29), S(-12, -37), S(-17, -43), S(-19, -55), S(-25, -57), S(-31, -74),
};

inline const PParam ROOK_LINEUP = S(17, 82);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(186, 279),    S(63, 402),     S(69, 390),     S(159, 273),    S(194, 170),    S(145, 213),    S(123, 243),    S(224, 182),    //
    S(42, 65),      S(57, 111),     S(35, 63),      S(48, -3),      S(40, -41),     S(13, -12),     S(15, 28),      S(-20, 55),     //
    S(39, -13),     S(16, -4),      S(45, -45),     S(26, -69),     S(18, -88),     S(4, -75),      S(-36, -44),    S(-38, -5),     //
    S(-6, -73),     S(-31, -43),    S(1, -62),      S(-10, -78),    S(-31, -88),    S(-36, -76),    S(-83, -57),    S(-77, -53),    //
    S(-13, -112),   S(18, -108),    S(3, -45),      S(-13, -51),    S(-40, -61),    S(-54, -71),    S(-81, -72),    S(-84, -75),    //
    S(9, -108),     S(84, -96),     S(72, -40),     S(25, -11),     S(-5, -32),     S(-24, -60),    S(-50, -60),    S(-63, -58),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-264, -509),  S(-257, 48),    S(-264, -33),   S(5, 38),       S(-86, 38),     S(-265, 80),    S(-347, 98),    S(-349, -416),  //
    S(26, -20),     S(13, 23),      S(93, 21),      S(91, 58),      S(97, 45),      S(59, 25),      S(-7, 21),      S(-19, 11),     //
    S(52, -31),     S(49, 25),      S(61, 61),      S(80, 69),      S(63, 70),      S(26, 57),      S(15, 33),      S(-26, 7),      //
    S(99, 18),      S(98, 45),      S(107, 67),     S(110, 108),    S(114, 106),    S(77, 71),      S(58, 36),      S(39, 30),      //
    S(81, 8),       S(106, 1),      S(104, 47),     S(99, 79),      S(85, 81),      S(77, 62),      S(62, 16),      S(27, 18),      //
    S(21, -45),     S(48, -28),     S(55, 18),      S(67, 50),      S(63, 49),      S(35, 12),      S(18, -20),     S(-21, -44),    //
    S(38, -27),     S(41, -14),     S(30, -22),     S(41, 6),       S(38, 4),       S(9, -47),      S(-29, -3),     S(-48, -88),    //
    S(-53, -73),    S(2, -13),      S(21, -24),     S(37, -13),     S(20, 1),       S(-17, -32),    S(-29, -10),    S(-80, -122),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-127, 21),    S(-187, 99),    S(-398, 165),   S(-269, 96),    S(-300, 138),   S(-300, 150),   S(-222, 125),   S(-125, 72),    //
    S(-9, -18),     S(-59, 86),     S(-40, 61),     S(-62, 58),     S(-60, 73),     S(-34, 47),     S(-3, 40),      S(-35, 28),     //
    S(41, 17),      S(21, 57),      S(35, 68),      S(32, 53),      S(28, 40),      S(26, 45),      S(14, 41),      S(19, 11),      //
    S(23, -7),      S(55, 18),      S(66, 34),      S(85, 53),      S(109, 38),     S(47, 18),      S(50, -6),      S(5, -4),       //
    S(40, -48),     S(49, -1),      S(81, 11),      S(97, 24),      S(80, 35),      S(70, 22),      S(24, 4),       S(13, -42),     //
    S(61, -33),     S(84, -27),     S(101, 3),      S(69, 26),      S(65, 11),      S(62, 11),      S(63, -6),      S(21, -26),     //
    S(31, -78),     S(118, -61),    S(70, -22),     S(52, -5),      S(35, -4),      S(49, -46),     S(50, -61),     S(43, -55),     //
    S(23, -65),     S(2, -15),      S(9, -0),       S(23, -22),     S(8, -10),      S(17, 24),      S(23, -7),      S(19, -53),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(175, 109),    S(203, 130),    S(156, 160),    S(143, 130),    S(204, 85),     S(161, 113),    S(168, 131),    S(152, 127),    //
    S(87, 151),     S(144, 156),    S(188, 127),    S(142, 112),    S(179, 99),     S(146, 124),    S(98, 157),     S(89, 158),     //
    S(57, 145),     S(178, 88),     S(206, 70),     S(176, 56),     S(180, 74),     S(121, 114),    S(115, 132),    S(62, 170),     //
    S(30, 111),     S(93, 120),     S(113, 94),     S(97, 94),      S(125, 76),     S(84, 118),     S(75, 133),     S(20, 158),     //
    S(4, 44),       S(63, 55),      S(56, 76),      S(25, 86),      S(34, 91),      S(24, 115),     S(7, 112),      S(-15, 117),    //
    S(16, -35),     S(85, -11),     S(73, 15),      S(50, 29),      S(61, 34),      S(37, 58),      S(33, 42),      S(-5, 48),      //
    S(-64, -42),    S(62, -77),     S(67, -39),     S(56, -6),      S(60, -5),      S(45, 8),       S(36, -9),      S(4, -6),       //
    S(-0, -63),     S(23, -32),     S(87, -43),     S(96, -43),     S(98, -38),     S(74, -16),     S(69, -22),     S(48, -17),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 153),     S(147, 154),    S(57, 299),     S(-2, 398),     S(36, 349),     S(72, 258),     S(72, 174),     S(25, 209),     //
    S(58, 184),     S(78, 240),     S(38, 322),     S(-83, 440),    S(-39, 408),    S(20, 289),     S(59, 175),     S(41, 145),     //
    S(20, 235),     S(60, 261),     S(29, 338),     S(-8, 375),     S(11, 362),     S(51, 259),     S(82, 155),     S(63, 118),     //
    S(16, 171),     S(28, 238),     S(-13, 307),    S(-12, 361),    S(5, 354),      S(22, 238),     S(60, 154),     S(35, 116),     //
    S(13, 144),     S(10, 168),     S(2, 218),      S(-23, 287),    S(-11, 303),    S(10, 238),     S(16, 175),     S(36, 80),      //
    S(4, 49),       S(35, 60),      S(32, 134),     S(10, 156),     S(19, 165),     S(22, 187),     S(41, 115),     S(22, 94),      //
    S(-24, -97),    S(4, -95),      S(13, -27),     S(40, 13),      S(37, 53),      S(39, 25),      S(12, 64),      S(25, 36),      //
    S(-42, -82),    S(-11, -243),   S(21, -248),    S(33, -136),    S(40, -57),     S(38, -75),     S(36, -62),     S(5, -7),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(164, -558),   S(477, 85),     S(317, 195),    S(20, 192),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(370, -186),   S(367, 190),    S(213, 203),    S(26, 156),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(200, 44),     S(233, 176),    S(116, 199),    S(-48, 179),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, 7),       S(115, 114),    S(-20, 172),    S(-116, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-112, -2),    S(-20, 76),     S(-84, 146),    S(-181, 197),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-52, -36),    S(14, 32),      S(-66, 114),    S(-123, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(25, -95),     S(31, -13),     S(-32, 49),     S(-108, 106),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -214),   S(5, -94),      S(-73, -29),    S(-82, -42),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -448);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 1), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -19), S(-7, 5), S(-3, -10), S(6, -16), S(12, -29), S(6, -54), S(-4, -46), }},
  {{ S(2, 3), S(-21, 2), S(-17, 9), S(-10, 17), S(-7, 7), S(-10, -13), S(-19, -22), }},
  {{ S(-4, -0), S(-12, -8), S(-13, 18), S(-8, 19), S(-7, 10), S(-7, -16), S(-23, -37), }},
  {{ S(6, 8), S(-11, 18), S(-7, 38), S(-2, 43), S(-2, 38), S(3, 19), S(9, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 23), S(-6, 2), S(-7, 9), S(-6, 28), S(1, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 10), S(-41, -123), S(-9, -40), S(-1, 4), S(-3, 3), S(-6, 10), S(-5, 9), }},
  {{ S(9, -2), S(-25, -126), S(-6, -30), S(-4, 0), S(-2, -3), S(-9, 4), S(1, 3), }},
  {{ S(-0, 11), S(-7, -70), S(7, -16), S(0, 8), S(-3, 11), S(-9, 18), S(-6, 21), }},
  {{ S(1, -0), S(2, -64), S(-1, 24), S(-3, 25), S(-5, 8), S(-12, 10), S(-9, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1433, 914, -22, -1
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(88);
inline VParam WINNABLE_PAWN_ENDGAME = V(76);
inline VParam WINNABLE_BIAS = V(-393);

// Epoch duration: 8.07791s
// clang-format on
}  // namespace Clockwork
