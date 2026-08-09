#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(203, 513);
inline const PParam KNIGHT_MAT = S(823, 1615);
inline const PParam BISHOP_MAT = S(876, 1698);
inline const PParam ROOK_MAT   = S(1049, 2697);
inline const PParam QUEEN_MAT  = S(2436, 4162);

inline const PParam TEMPO_VAL  = S(61, 47);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(62, 242);
inline const PParam ROOK_OPEN_VAL     = S(110, -6);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 8);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(20, 6);

inline const PParam DOUBLED_PAWN_VAL = S(-22, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 42);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -2), S(33, 36), S(60, 66), S(122, 215), S(392, 408), S(684, 828),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 34), S(40, 27), S(55, 59), S(93, 182), S(394, 117),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-96, -262), S(-96, -220), S(-68, -87), S(-23, 41), S(87, 202), S(230, 418),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-80, 51), S(-94, 34), S(-61, 104), S(-91, 230), S(-56, 342), S(57, 224),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-17, 68), S(-29, 59), S(-62, 109), S(-32, 134), S(74, 159), S(35, 200),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -42), S(24, -2), S(17, 35), S(23, 102), S(74, 272), S(342, 218),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -38), S(3, 7), S(-3, -27), S(1, -69), S(-14, -178), S(-173, -465),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 240), S(10, 184), S(5, 107), S(12, 68), S(20, 73), S(58, 68), S(62, 39),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-130, -50), S(14, -4), S(2, 99), S(28, 150), S(44, 185), S(56, 193), S(42, 173),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-94, -397), S(-26, -141), S(5, -26), S(28, 23), S(56, 56), S(71, 93), S(89, 100), S(108, 108), S(129, 61),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-72, -350), S(-18, -126), S(35, -36), S(59, 18), S(79, 61), S(91, 92), S(96, 115), S(99, 135), S(103, 147), S(109, 153), S(117, 146), S(131, 128), S(129, 135), S(114, 96),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(101, -213), S(23, -9), S(45, 25), S(60, 44), S(71, 63), S(75, 77), S(80, 93), S(86, 100), S(90, 112), S(96, 120), S(100, 127), S(100, 135), S(103, 140), S(109, 125), S(128, 86),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-196, -201), S(-39, -87), S(-15, 56), S(5, 198), S(22, 243), S(29, 297), S(36, 337), S(43, 355), S(48, 379), S(51, 396), S(57, 405), S(61, 412), S(65, 418), S(67, 423), S(68, 426), S(68, 426), S(63, 429), S(68, 418), S(68, 414), S(73, 402), S(62, 394), S(72, 367), S(38, 394), S(-8, 386), S(-42, 384), S(-77, 405), S(-139, 436), S(-101, 365),
};

inline const PParam PAWN_THREAT_KNIGHT = S(202, 154);
inline const PParam PAWN_THREAT_BISHOP = S(183, 218);
inline const PParam PAWN_THREAT_ROOK   = S(198, 166);
inline const PParam PAWN_THREAT_QUEEN  = S(182, 32);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(10, 72), S(102, 98), S(113, 132), S(195, 106), S(184, 45), }},
  {{ S(4, 55), S(88, 86), S(103, 111), S(217, 569), S(137, -57), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(11, 86), S(73, 108), S(79, 119), S(28, 25), S(190, -52), }},
  {{ S(-0, 48), S(45, 69), S(86, 62), S(16, 3), S(337, 830), }},
}};
inline const PParam KING_THREAT  = S(-10, 171);
inline const PParam HANGING_PAWN  = S(42, 108);
inline const PParam HANGING_NON_PAWN  = S(77, 203);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -16), S(21, 11),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(43, 44), S(111, -109),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 13), S(48, -5),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -18), S(4, -16), S(-1, -22), S(-6, -29), S(-13, -37), S(-18, -43), S(-19, -55), S(-25, -57), S(-31, -75),
};

inline const PParam ROOK_LINEUP = S(17, 83);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(189, 278),    S(64, 403),     S(68, 396),     S(158, 280),    S(198, 169),    S(145, 217),    S(123, 246),    S(222, 189),    //
    S(40, 65),      S(53, 113),     S(33, 64),      S(47, -4),      S(39, -41),     S(10, -11),     S(11, 29),      S(-23, 55),     //
    S(37, -15),     S(14, -5),      S(42, -46),     S(25, -69),     S(17, -88),     S(2, -76),      S(-38, -45),    S(-39, -7),     //
    S(-7, -75),     S(-32, -44),    S(0, -63),      S(-11, -79),    S(-32, -89),    S(-37, -77),    S(-84, -59),    S(-78, -54),    //
    S(-15, -113),   S(17, -109),    S(2, -45),      S(-15, -51),    S(-41, -62),    S(-54, -73),    S(-81, -73),    S(-84, -76),    //
    S(9, -109),     S(83, -96),     S(72, -40),     S(24, -11),     S(-5, -34),     S(-24, -62),    S(-50, -60),    S(-64, -59),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-264, -499),  S(-255, 50),    S(-262, -27),   S(4, 41),       S(-92, 46),     S(-269, 89),    S(-349, 105),   S(-349, -405),  //
    S(-1, -12),     S(0, 34),       S(86, 27),      S(83, 63),      S(87, 52),      S(53, 28),      S(-17, 27),     S(-41, 17),     //
    S(42, -26),     S(43, 30),      S(53, 70),      S(73, 75),      S(57, 74),      S(20, 62),      S(9, 36),       S(-33, 8),      //
    S(90, 22),      S(92, 48),      S(102, 71),     S(106, 110),    S(110, 110),    S(73, 75),      S(52, 40),      S(33, 33),      //
    S(79, 14),      S(103, 2),      S(101, 50),     S(95, 82),      S(82, 85),      S(74, 66),      S(60, 18),      S(25, 24),      //
    S(20, -45),     S(46, -26),     S(53, 20),      S(65, 53),      S(61, 51),      S(33, 15),      S(17, -18),     S(-22, -44),    //
    S(39, -28),     S(41, -14),     S(28, -20),     S(39, 8),       S(36, 6),       S(6, -45),      S(-30, -1),     S(-50, -83),    //
    S(-43, -96),    S(12, -33),     S(30, -45),     S(47, -35),     S(30, -22),     S(-7, -53),     S(-19, -29),    S(-70, -145),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-132, 23),    S(-193, 108),   S(-401, 170),   S(-277, 104),   S(-300, 136),   S(-301, 152),   S(-229, 130),   S(-129, 70),    //
    S(-28, -24),    S(-66, 92),     S(-49, 67),     S(-72, 67),     S(-67, 77),     S(-42, 51),     S(-14, 50),     S(-55, 25),     //
    S(32, 20),      S(15, 62),      S(28, 74),      S(25, 58),      S(19, 48),      S(19, 51),      S(6, 49),       S(11, 10),      //
    S(15, -8),      S(47, 22),      S(59, 39),      S(79, 58),      S(103, 43),     S(41, 22),      S(43, -1),      S(-3, -2),      //
    S(35, -47),     S(44, 2),       S(77, 13),      S(92, 29),      S(75, 41),      S(65, 26),      S(19, 7),       S(8, -38),      //
    S(56, -31),     S(80, -25),     S(96, 7),       S(64, 30),      S(61, 15),      S(57, 17),      S(59, -3),      S(15, -23),     //
    S(26, -77),     S(113, -58),    S(65, -18),     S(47, -0),      S(30, -1),      S(44, -42),     S(44, -57),     S(38, -53),     //
    S(42, -74),     S(22, -24),     S(30, -11),     S(43, -32),     S(28, -20),     S(37, 15),      S(44, -17),     S(39, -61),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(171, 114),    S(203, 128),    S(156, 159),    S(139, 132),    S(200, 88),     S(161, 112),    S(169, 130),    S(150, 131),    //
    S(85, 152),     S(144, 155),    S(189, 126),    S(142, 113),    S(179, 101),    S(147, 124),    S(98, 157),     S(87, 160),     //
    S(53, 149),     S(177, 88),     S(205, 71),     S(175, 56),     S(179, 75),     S(120, 116),    S(114, 134),    S(60, 174),     //
    S(28, 114),     S(91, 121),     S(112, 94),     S(95, 97),      S(123, 79),     S(83, 120),     S(75, 134),     S(18, 161),     //
    S(5, 45),       S(63, 54),      S(55, 78),      S(24, 88),      S(34, 93),      S(23, 117),     S(5, 116),      S(-15, 119),    //
    S(16, -34),     S(85, -10),     S(73, 16),      S(51, 29),      S(60, 35),      S(37, 59),      S(34, 44),      S(-5, 51),      //
    S(-64, -42),    S(62, -77),     S(67, -37),     S(55, -3),      S(60, -5),      S(45, 9),       S(35, -6),      S(3, -4),       //
    S(-0, -63),     S(24, -32),     S(87, -44),     S(95, -43),     S(97, -38),     S(74, -15),     S(68, -21),     S(48, -16),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(88, 157),     S(149, 149),    S(60, 292),     S(-3, 397),     S(32, 353),     S(73, 253),     S(71, 176),     S(25, 208),     //
    S(58, 188),     S(83, 241),     S(39, 329),     S(-79, 445),    S(-34, 410),    S(21, 297),     S(63, 178),     S(41, 149),     //
    S(21, 234),     S(59, 268),     S(31, 345),     S(-9, 381),     S(13, 367),     S(53, 266),     S(82, 163),     S(64, 120),     //
    S(15, 171),     S(29, 238),     S(-13, 314),    S(-12, 371),    S(5, 363),      S(21, 249),     S(60, 163),     S(35, 120),     //
    S(13, 143),     S(9, 171),      S(2, 221),      S(-23, 296),    S(-10, 311),    S(11, 245),     S(17, 178),     S(38, 79),      //
    S(4, 47),       S(36, 57),      S(32, 136),     S(10, 159),     S(20, 167),     S(22, 190),     S(43, 118),     S(22, 97),      //
    S(-25, -98),    S(3, -94),      S(12, -26),     S(39, 14),      S(36, 53),      S(38, 27),      S(12, 62),      S(24, 37),      //
    S(-43, -87),    S(-11, -248),   S(21, -252),    S(33, -141),    S(39, -59),     S(38, -77),     S(36, -64),     S(5, -9),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(171, -560),   S(484, 79),     S(317, 196),    S(20, 191),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(374, -185),   S(364, 195),    S(214, 202),    S(25, 158),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(199, 46),     S(229, 181),    S(114, 201),    S(-48, 179),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(40, 7),       S(114, 116),    S(-20, 172),    S(-117, 202),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-113, 0),     S(-21, 78),     S(-87, 149),    S(-180, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -33),    S(12, 35),      S(-68, 116),    S(-124, 162),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -93),     S(29, -10),     S(-34, 52),     S(-109, 108),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -210),   S(3, -90),      S(-75, -27),    S(-83, -40),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-81, -448);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 1), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -19), S(-7, 5), S(-3, -10), S(6, -16), S(12, -29), S(6, -54), S(-4, -44), }},
  {{ S(1, 4), S(-22, 2), S(-17, 10), S(-11, 18), S(-7, 8), S(-10, -12), S(-20, -21), }},
  {{ S(-4, -2), S(-12, -9), S(-13, 17), S(-9, 18), S(-7, 9), S(-7, -17), S(-23, -40), }},
  {{ S(6, 8), S(-11, 17), S(-7, 38), S(-3, 42), S(-2, 37), S(3, 19), S(9, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 23), S(-6, 3), S(-7, 9), S(-6, 28), S(1, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 11), S(-41, -119), S(-8, -39), S(-1, 4), S(-3, 3), S(-6, 10), S(-5, 9), }},
  {{ S(9, -1), S(-24, -128), S(-6, -31), S(-4, 0), S(-2, -3), S(-8, 4), S(1, 3), }},
  {{ S(0, 11), S(-7, -68), S(7, -15), S(0, 8), S(-3, 11), S(-9, 18), S(-6, 21), }},
  {{ S(1, 0), S(4, -67), S(-1, 24), S(-2, 25), S(-6, 8), S(-12, 10), S(-9, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1425, 924, -20, -1
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(88);
inline VParam WINNABLE_PAWN_ENDGAME = V(74);
inline VParam WINNABLE_BIAS = V(-394);

// Epoch duration: 7.87222s
// clang-format on
}  // namespace Clockwork
