#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(193, 452);
inline const PParam KNIGHT_MAT = S(854, 1342);
inline const PParam BISHOP_MAT = S(898, 1420);
inline const PParam ROOK_MAT   = S(1077, 2306);
inline const PParam QUEEN_MAT  = S(2440, 3499);
inline const PParam TEMPO_VAL  = S(63, 21);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 14);
inline const PParam BISHOP_PAIR_VAL   = S(58, 224);
inline const PParam ROOK_OPEN_VAL     = S(120, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 32);
inline const PParam MINOR_BEHIND_PAWN = S(14, 43);
inline const PParam RESTRICTED_SQUARES = S(-24, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-16, -80);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -27);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -32);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 58);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(44, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -2), S(28, 33), S(60, 59), S(132, 173), S(443, 232), S(563, 608),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(45, 42), S(43, 35), S(64, 64), S(118, 168), S(453, 92),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -240), S(-91, -204), S(-70, -76), S(-27, 46), S(75, 218), S(233, 335),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -43), S(20, 0), S(10, 39), S(5, 121), S(74, 239), S(153, 403),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -28), S(4, 14), S(-5, -17), S(-3, -45), S(-18, -139), S(-193, -286),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(13, 218), S(-9, 177), S(-5, 96), S(8, 55), S(20, 54), S(59, 52), S(47, 41),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-173, -99), S(5, 27), S(4, 102), S(31, 143), S(45, 174), S(59, 179), S(35, 175),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-94, -327), S(-30, -130), S(0, -24), S(25, 14), S(56, 35), S(72, 68), S(93, 68), S(113, 74), S(148, -5),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-62, -273), S(-14, -119), S(37, -55), S(58, -3), S(81, 34), S(93, 61), S(100, 82), S(106, 95), S(107, 109), S(119, 99), S(124, 93), S(162, 40), S(167, 34), S(188, -44),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(111, -186), S(24, -15), S(45, 16), S(62, 28), S(73, 44), S(77, 57), S(82, 70), S(89, 74), S(94, 85), S(102, 89), S(109, 92), S(113, 97), S(113, 98), S(122, 72), S(194, -36),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-195, -149), S(-43, -67), S(-16, 48), S(6, 166), S(21, 205), S(28, 254), S(34, 286), S(40, 301), S(44, 325), S(46, 343), S(51, 351), S(53, 361), S(56, 365), S(56, 371), S(55, 375), S(51, 379), S(46, 381), S(47, 371), S(46, 367), S(50, 357), S(49, 338), S(63, 299), S(35, 325), S(13, 287), S(-1, 266), S(-27, 265), S(-61, 268), S(-53, 212),
};

inline const PParam PAWN_THREAT_KNIGHT = S(208, 122);
inline const PParam PAWN_THREAT_BISHOP = S(191, 174);
inline const PParam PAWN_THREAT_ROOK   = S(209, 130);
inline const PParam PAWN_THREAT_QUEEN  = S(175, 15);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 116);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 87);
inline const PParam KNIGHT_THREAT_QUEEN  = S(162, -20);

inline const PParam BISHOP_THREAT_KNIGHT = S(100, 72);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 152);
inline const PParam BISHOP_THREAT_QUEEN  = S(181, 95);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -26), S(-0, -8), S(-3, -17), S(-7, -28), S(-11, -37), S(-16, -45), S(-17, -58), S(-23, -59), S(-29, -70),
};

inline const PParam ROOK_LINEUP = S(15, 76);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(207, 219),    S(66, 314),     S(89, 297),     S(140, 219),    S(193, 134),    S(114, 207),    S(82, 245),     S(225, 187),    //
    S(34, 41),      S(44, 79),      S(25, 23),      S(41, -50),     S(35, -83),     S(0, -34),      S(-8, 21),      S(-31, 49),     //
    S(27, -23),     S(3, -11),      S(35, -59),     S(21, -83),     S(11, -100),    S(-11, -79),    S(-50, -38),    S(-52, -5),     //
    S(-15, -75),    S(-39, -40),    S(-1, -68),     S(-10, -79),    S(-32, -88),    S(-42, -75),    S(-97, -43),    S(-86, -50),    //
    S(-15, -105),   S(20, -103),    S(9, -51),      S(-7, -57),     S(-34, -68),    S(-50, -72),    S(-84, -61),    S(-87, -68),    //
    S(9, -100),     S(84, -88),     S(72, -45),     S(26, -21),     S(-3, -44),     S(-22, -63),    S(-52, -48),    S(-65, -51),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-287, -450),  S(-271, 34),    S(-312, -75),   S(4, 11),       S(-100, 28),    S(-267, 49),    S(-401, 102),   S(-381, -327),  //
    S(-27, -24),    S(-15, 20),     S(87, -9),      S(78, 26),      S(88, 18),      S(40, 9),       S(-27, 13),     S(-44, -6),     //
    S(41, -36),     S(44, 2),       S(81, 44),      S(86, 63),      S(69, 78),      S(21, 75),      S(12, 11),      S(-38, -1),     //
    S(100, 5),      S(104, 34),     S(111, 58),     S(115, 95),     S(118, 95),     S(80, 75),      S(58, 34),      S(39, 19),      //
    S(76, 1),       S(114, -13),    S(104, 47),     S(91, 72),      S(77, 73),      S(76, 66),      S(65, 2),       S(21, 16),      //
    S(16, -43),     S(46, -15),     S(46, 29),      S(61, 53),      S(53, 53),      S(25, 27),      S(16, -6),      S(-27, -45),    //
    S(38, -38),     S(44, -31),     S(23, -22),     S(28, 5),       S(24, 2),       S(1, -47),      S(-29, -16),    S(-38, -114),   //
    S(-41, -93),    S(7, -35),      S(32, -60),     S(50, -49),     S(30, -29),     S(-8, -61),     S(-21, -34),    S(-62, -139),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-134, 22),    S(-179, 92),    S(-493, 188),   S(-307, 94),    S(-317, 121),   S(-325, 123),   S(-210, 105),   S(-137, 60),    //
    S(-48, -16),    S(-91, 77),     S(-44, 28),     S(-97, 59),     S(-83, 50),     S(-47, 33),     S(-25, 28),     S(-51, 2),      //
    S(33, 10),      S(20, 40),      S(33, 50),      S(25, 43),      S(18, 30),      S(11, 38),      S(17, 30),      S(15, -4),      //
    S(12, -13),     S(55, 6),       S(68, 26),      S(75, 61),      S(102, 51),     S(48, 20),      S(48, -10),     S(-0, -12),     //
    S(56, -66),     S(53, -15),     S(84, 5),       S(94, 31),      S(79, 45),      S(70, 23),      S(23, 2),       S(20, -39),     //
    S(65, -39),     S(93, -32),     S(104, -2),     S(74, 23),      S(68, 6),       S(67, 13),      S(75, -9),      S(24, -27),     //
    S(41, -101),    S(121, -68),    S(79, -34),     S(53, -14),     S(37, -12),     S(56, -51),     S(54, -59),     S(50, -70),     //
    S(57, -91),     S(29, -36),     S(30, -13),     S(57, -40),     S(38, -31),     S(43, 4),       S(53, -29),     S(49, -65),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(198, 79),     S(239, 75),     S(189, 94),     S(179, 70),     S(234, 44),     S(189, 68),     S(207, 81),     S(184, 95),     //
    S(98, 152),     S(163, 148),    S(238, 98),     S(171, 123),    S(218, 107),    S(182, 122),    S(117, 154),    S(104, 159),    //
    S(61, 146),     S(190, 100),    S(223, 74),     S(204, 55),     S(202, 78),     S(139, 120),    S(139, 125),    S(73, 171),     //
    S(33, 108),     S(110, 116),    S(139, 85),     S(116, 86),     S(147, 76),     S(104, 120),    S(97, 127),     S(25, 154),     //
    S(5, 34),       S(81, 46),      S(70, 60),      S(41, 63),      S(53, 72),      S(40, 99),      S(16, 99),      S(-6, 97),      //
    S(15, -43),     S(93, -23),     S(81, -4),      S(58, -0),      S(69, 7),       S(40, 39),      S(46, 19),      S(-4, 32),      //
    S(-75, -42),    S(64, -86),     S(64, -51),     S(52, -20),     S(58, -20),     S(43, -9),      S(33, -26),     S(-0, -13),     //
    S(-16, -68),    S(-1, -32),     S(70, -51),     S(80, -52),     S(80, -40),     S(59, -19),     S(57, -31),     S(38, -23),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(44, 152),     S(151, 80),     S(49, 230),     S(-9, 323),     S(30, 280),     S(64, 195),     S(60, 123),     S(-19, 189),    //
    S(53, 161),     S(60, 234),     S(24, 300),     S(-125, 431),   S(-72, 405),    S(-17, 304),    S(35, 164),     S(16, 149),     //
    S(12, 205),     S(39, 262),     S(-6, 357),     S(-44, 388),    S(-24, 377),    S(24, 272),     S(61, 161),     S(59, 84),      //
    S(31, 110),     S(17, 221),     S(-22, 296),    S(-45, 372),    S(-28, 380),    S(11, 241),     S(57, 137),     S(34, 101),     //
    S(21, 103),     S(10, 142),     S(-6, 204),     S(-32, 279),    S(-21, 312),    S(6, 229),      S(16, 152),     S(45, 55),      //
    S(23, 1),       S(43, 29),      S(35, 113),     S(11, 136),     S(19, 145),     S(22, 178),     S(43, 107),     S(35, 59),      //
    S(-6, -151),    S(22, -129),    S(23, -46),     S(46, -11),     S(38, 37),      S(41, 16),      S(15, 45),      S(32, 19),      //
    S(-21, -123),   S(-3, -268),    S(28, -271),    S(43, -160),    S(46, -74),     S(50, -111),    S(46, -82),     S(19, -45),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(16, -324),    S(308, 266),    S(260, 251),    S(63, 132),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(235, -33),    S(277, 227),    S(172, 228),    S(68, 109),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(149, 88),     S(178, 199),    S(118, 196),    S(18, 127),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, 43),     S(68, 134),     S(-23, 167),    S(-73, 168),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-122, 2),     S(-52, 83),     S(-100, 137),   S(-190, 188),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-43, -43),    S(8, 28),       S(-73, 99),     S(-134, 146),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(30, -99),     S(32, -21),     S(-28, 34),     S(-105, 86),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, -196),   S(8, -93),      S(-69, -38),    S(-63, -61),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-90, -417);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(9, 10), S(10, 5), S(4, 2), S(3, -8),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(4, 3), S(2, 2), S(3, 1), S(3, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-11, 23), S(3, -1), S(1, 13), S(-6, 21), S(-10, 37), S(-6, 59), S(0, 48), }},
  {{ S(-2, 7), S(11, 9), S(8, 4), S(3, -1), S(2, 7), S(1, 37), S(9, 30), }},
  {{ S(-1, -2), S(4, 5), S(4, -20), S(1, -19), S(1, -9), S(1, 18), S(10, 35), }},
  {{ S(-5, -12), S(4, -22), S(2, -46), S(-1, -55), S(-1, -50), S(-6, -13), S(-9, 16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-12, -18), S(-3, -2), S(-2, -11), S(-3, -28), S(-7, -46),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-10, -8), S(18, 152), S(-0, 39), S(-8, 2), S(-6, -3), S(-3, -11), S(-3, -9), }},
  {{ S(-12, 1), S(7, 153), S(-4, 36), S(-5, 3), S(-7, 3), S(-2, -4), S(-7, -3), }},
  {{ S(-7, -8), S(-2, 111), S(-12, 23), S(-7, -5), S(-5, -9), S(-1, -17), S(-3, -18), }},
  {{ S(-7, 13), S(-8, 58), S(-7, -16), S(-5, -16), S(-3, 1), S(1, -1), S(-1, -5), }},
}};

inline const PParam KING_EXPOSED = S(-2, 3);
inline TunableSigmoid<32> KING_SHELTER_ACTIVATION(
        -257, -135, -5, -10
);
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1333, 936, 62, 62
);

inline VParam WINNABLE_PAWNS = V(-24);
inline VParam WINNABLE_SYM = V(130);
inline VParam WINNABLE_ASYM = V(114);
inline VParam WINNABLE_PAWN_ENDGAME = V(171);
inline VParam WINNABLE_BIAS = V(-507);

// Epoch duration: 7.73797s
// clang-format on
}  // namespace Clockwork
