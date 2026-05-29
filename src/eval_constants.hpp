#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(187, 493);
inline const PParam KNIGHT_MAT = S(797, 1537);
inline const PParam BISHOP_MAT = S(841, 1638);
inline const PParam ROOK_MAT   = S(1004, 2578);
inline const PParam QUEEN_MAT  = S(2365, 3899);
inline const PParam TEMPO_VAL  = S(57, 33);

inline const PParam BISHOP_XRAY_PAWNS   = S(-16, -9);
inline const PParam BISHOP_PAIR_VAL   = S(62, 225);
inline const PParam ROOK_OPEN_VAL     = S(107, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, -1);
inline const PParam MINOR_BEHIND_PAWN = S(15, 36);
inline const PParam RESTRICTED_SQUARES = S(-23, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -77);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-44, -38);
inline const PParam OUTPOST_KNIGHT_VAL    = S(60, 46);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 42);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(33, 53);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(35, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(23, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(56, -42);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -5), S(29, 39), S(57, 69), S(126, 199), S(426, 292), S(624, 646),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(44, 34), S(37, 28), S(51, 64), S(95, 195), S(394, 139),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -266), S(-91, -230), S(-67, -94), S(-26, 42), S(72, 233), S(220, 388),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -43), S(27, -7), S(17, 33), S(14, 110), S(77, 239), S(134, 428),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(16, -39), S(5, 7), S(-6, -22), S(-7, -54), S(-13, -163), S(-177, -322),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(18, 235), S(2, 185), S(0, 109), S(10, 68), S(22, 70), S(62, 67), S(49, 50),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-129, -153), S(17, 20), S(4, 112), S(27, 160), S(38, 196), S(50, 202), S(34, 183),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-82, -365), S(-25, -132), S(3, -17), S(25, 24), S(52, 50), S(66, 82), S(83, 86), S(101, 92), S(118, 44),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-61, -275), S(-14, -109), S(34, -39), S(55, 10), S(76, 47), S(87, 71), S(93, 92), S(98, 109), S(102, 119), S(108, 124), S(120, 114), S(137, 95), S(143, 100), S(124, 67),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(103, -201), S(22, -14), S(42, 20), S(58, 35), S(68, 54), S(72, 68), S(77, 82), S(83, 87), S(87, 100), S(94, 105), S(99, 110), S(102, 116), S(105, 119), S(108, 109), S(138, 60),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-212, -133), S(-66, -19), S(-40, 99), S(-18, 220), S(-3, 263), S(4, 315), S(10, 348), S(16, 365), S(20, 389), S(22, 409), S(27, 416), S(30, 427), S(33, 430), S(34, 436), S(34, 438), S(29, 443), S(25, 442), S(26, 434), S(26, 428), S(28, 420), S(22, 405), S(24, 381), S(-5, 408), S(-47, 389), S(-81, 397), S(-117, 416), S(-159, 429), S(-132, 352),
};

inline const PParam SAFE_PAWN_THREAT = S(221, 166);
inline const std::array<PParam, 6> MINOR_THREAT = {
    S(6, 69), S(96, 91), S(109, 126), S(210, 131), S(168, 34), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(3, 67), S(66, 83), S(76, 93), S(-20, 32), S(193, -12), S(0, 0),
};
inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -18), S(4, -15), S(-1, -21), S(-6, -29), S(-12, -37), S(-17, -44), S(-19, -57), S(-24, -60), S(-27, -80),
};

inline const PParam ROOK_LINEUP = S(15, 75);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(181, 264),    S(50, 363),     S(75, 341),     S(147, 242),    S(201, 149),    S(128, 211),    S(93, 253),     S(221, 206),    //
    S(40, 49),      S(48, 90),      S(37, 30),      S(50, -43),     S(42, -78),     S(14, -37),     S(3, 22),       S(-21, 52),     //
    S(35, -19),     S(10, -10),     S(43, -54),     S(32, -78),     S(23, -97),     S(-0, -80),     S(-36, -45),    S(-40, -5),     //
    S(-10, -73),    S(-31, -41),    S(2, -63),      S(-6, -75),     S(-26, -86),    S(-37, -74),    S(-84, -54),    S(-78, -53),    //
    S(-14, -106),   S(19, -104),    S(5, -45),      S(-9, -52),     S(-34, -65),    S(-50, -73),    S(-78, -69),    S(-80, -73),    //
    S(7, -101),     S(78, -89),     S(66, -37),     S(22, -15),     S(-6, -41),     S(-25, -62),    S(-51, -56),    S(-61, -55),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-251, -524),  S(-250, 28),    S(-277, -99),   S(20, 3),       S(-76, 12),     S(-252, 54),    S(-371, 98),    S(-340, -396),  //
    S(-11, -29),    S(-8, 16),      S(99, -7),      S(83, 39),      S(96, 25),      S(53, 11),      S(-21, 18),     S(-32, -4),     //
    S(36, -40),     S(35, 25),      S(74, 47),      S(82, 57),      S(70, 60),      S(25, 65),      S(13, 24),      S(-38, -1),     //
    S(93, 9),       S(88, 36),      S(99, 67),      S(104, 105),    S(111, 105),    S(75, 75),      S(49, 36),      S(36, 23),      //
    S(69, 12),      S(99, 4),       S(96, 58),      S(89, 87),      S(76, 89),      S(75, 72),      S(61, 11),      S(20, 23),      //
    S(16, -38),     S(44, -12),     S(48, 34),      S(62, 66),      S(57, 64),      S(30, 30),      S(18, -5),      S(-24, -41),    //
    S(36, -27),     S(42, -15),     S(26, -7),      S(34, 20),      S(31, 16),      S(6, -36),      S(-27, -4),     S(-35, -111),   //
    S(-42, -89),    S(8, -27),      S(29, -42),     S(47, -32),     S(27, -10),     S(-8, -47),     S(-18, -28),    S(-60, -146),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-118, 15),    S(-165, 96),    S(-446, 187),   S(-273, 85),    S(-287, 129),   S(-294, 138),   S(-192, 107),   S(-114, 45),    //
    S(-32, -26),    S(-79, 91),     S(-34, 46),     S(-76, 70),     S(-65, 64),     S(-31, 41),     S(-8, 32),      S(-47, 8),      //
    S(20, 21),      S(1, 69),       S(17, 75),      S(22, 62),      S(16, 44),      S(8, 50),       S(2, 50),       S(4, 12),       //
    S(4, -12),      S(38, 14),      S(51, 39),      S(66, 57),      S(94, 42),      S(36, 29),      S(37, -6),      S(-2, -13),     //
    S(42, -62),     S(40, -7),      S(74, 9),       S(92, 30),      S(75, 48),      S(64, 22),      S(17, 3),       S(15, -40),     //
    S(62, -43),     S(83, -28),     S(99, 8),       S(69, 39),      S(68, 21),      S(65, 22),      S(72, -11),     S(22, -28),     //
    S(37, -96),     S(118, -54),    S(75, -12),     S(53, 2),       S(37, 5),       S(57, -40),     S(55, -51),     S(50, -73),     //
    S(54, -89),     S(25, -18),     S(28, -5),      S(50, -29),     S(34, -22),     S(41, 13),      S(52, -21),     S(49, -63),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(160, 87),     S(200, 97),     S(150, 124),    S(141, 97),     S(196, 61),     S(156, 84),     S(173, 90),     S(141, 103),    //
    S(79, 136),     S(145, 123),    S(195, 92),     S(147, 93),     S(191, 74),     S(140, 106),    S(93, 132),     S(86, 135),     //
    S(54, 135),     S(175, 81),     S(202, 62),     S(184, 38),     S(181, 63),     S(124, 103),    S(126, 108),    S(68, 154),     //
    S(32, 102),     S(95, 110),     S(121, 80),     S(102, 83),     S(130, 70),     S(93, 111),     S(89, 118),     S(27, 145),     //
    S(5, 42),       S(72, 50),      S(60, 67),      S(36, 73),      S(44, 84),      S(32, 109),     S(12, 108),     S(-5, 106),     //
    S(17, -31),     S(86, -11),     S(74, 15),      S(55, 22),      S(66, 28),      S(35, 63),      S(43, 38),      S(-1, 48),      //
    S(-68, -27),    S(64, -68),     S(68, -30),     S(55, 6),       S(58, 4),       S(43, 18),      S(33, -0),      S(6, 5),        //
    S(-4, -60),     S(7, -17),      S(80, -37),     S(88, -35),     S(88, -27),     S(66, -3),      S(65, -17),     S(48, -12),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(55, 161),     S(142, 109),    S(42, 263),     S(-16, 367),    S(25, 320),     S(60, 225),     S(57, 149),     S(-6, 198),     //
    S(47, 176),     S(58, 246),     S(21, 323),     S(-119, 459),   S(-63, 422),    S(-14, 323),    S(37, 173),     S(11, 165),     //
    S(-4, 240),     S(27, 289),     S(-5, 371),     S(-44, 411),    S(-25, 398),    S(25, 282),     S(58, 172),     S(50, 102),     //
    S(9, 152),      S(-5, 262),     S(-33, 324),    S(-51, 404),    S(-32, 406),    S(2, 268),      S(42, 165),     S(20, 126),     //
    S(3, 140),      S(-10, 181),    S(-22, 244),    S(-42, 317),    S(-29, 342),    S(-7, 262),     S(4, 176),      S(31, 81),      //
    S(5, 35),       S(23, 64),      S(19, 151),     S(-4, 175),     S(9, 175),      S(10, 209),     S(32, 127),     S(22, 85),      //
    S(-22, -119),   S(4, -97),      S(9, -13),      S(32, 24),      S(28, 65),      S(31, 39),      S(5, 68),       S(20, 44),      //
    S(-36, -98),    S(-20, -240),   S(11, -244),    S(25, -130),    S(33, -51),     S(34, -83),     S(32, -59),     S(5, -18),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(135, -597),   S(478, 6),      S(288, 167),    S(14, 131),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(338, -172),   S(350, 142),    S(183, 197),    S(8, 156),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(170, 69),     S(195, 203),    S(95, 225),     S(-40, 181),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-2, 26),      S(68, 152),     S(-40, 191),    S(-93, 199),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-119, 3),     S(-40, 92),     S(-103, 155),   S(-175, 196),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-51, -34),    S(10, 40),      S(-71, 116),    S(-120, 157),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -89),     S(27, -9),      S(-34, 54),     S(-105, 103),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -204),   S(3, -86),      S(-76, -25),    S(-70, -48),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-95, -437);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -7), S(9, 9), S(10, 3), S(4, 1), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(4, 4), S(2, 2), S(3, -0), S(3, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -18), S(-6, 6), S(-2, -8), S(9, -16), S(14, -28), S(8, -53), S(-3, -43), }},
  {{ S(2, 3), S(-22, 3), S(-17, 10), S(-9, 17), S(-6, 8), S(-7, -19), S(-17, -24), }},
  {{ S(-1, -2), S(-10, -9), S(-12, 17), S(-6, 17), S(-5, 10), S(-5, -19), S(-20, -39), }},
  {{ S(7, 7), S(-9, 15), S(-6, 35), S(-2, 41), S(-2, 37), S(6, 12), S(10, -17), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 26), S(-4, 4), S(-7, 11), S(-5, 28), S(2, 49),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 11), S(-44, -155), S(-9, -51), S(-0, 5), S(-1, 4), S(-5, 11), S(-4, 9), }},
  {{ S(9, -0), S(-26, -173), S(-5, -34), S(-3, 2), S(1, -2), S(-7, 5), S(2, 3), }},
  {{ S(0, 10), S(-10, -93), S(8, -22), S(0, 10), S(-3, 11), S(-9, 19), S(-5, 20), }},
  {{ S(2, 2), S(4, -69), S(-1, 28), S(-2, 27), S(-6, 11), S(-11, 13), S(-10, 22), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1411, 899, -19, -10
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(83);
inline VParam WINNABLE_PAWN_ENDGAME = V(102);
inline VParam WINNABLE_BIAS = V(-368);

// Epoch duration: 6.71942s
// Epoch duration: 7.9106s
// clang-format on
}  // namespace Clockwork
