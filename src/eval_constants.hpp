#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(188, 460);
inline const PParam KNIGHT_MAT = S(846, 1364);
inline const PParam BISHOP_MAT = S(892, 1441);
inline const PParam ROOK_MAT   = S(1077, 2319);
inline const PParam QUEEN_MAT  = S(3594, 3252);
inline const PParam TEMPO_VAL  = S(62, 24);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, 16);
inline const PParam BISHOP_PAIR_VAL   = S(55, 234);
inline const PParam ROOK_OPEN_VAL     = S(122, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 37);
inline const PParam MINOR_BEHIND_PAWN = S(14, 43);
inline const PParam RESTRICTED_SQUARES = S(-22, -9);

inline const PParam DOUBLED_PAWN_VAL = S(-16, -85);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -26);

inline const PParam POTENTIAL_CHECKER_VAL = S(-4, -4);
inline const PParam OUTPOST_KNIGHT_VAL    = S(53, 63);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 37);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(44, -13);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(28, 48);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -44);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -3), S(30, 32), S(58, 63), S(132, 186), S(424, 286), S(615, 657),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 44), S(42, 37), S(64, 67), S(119, 170), S(459, 78),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-91, -239), S(-86, -209), S(-61, -86), S(-13, 28), S(74, 245), S(252, 326),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -36), S(20, 7), S(9, 44), S(4, 123), S(86, 216), S(169, 397),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -31), S(7, 10), S(0, -25), S(0, -58), S(-27, -124), S(-207, -260),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(11, 216), S(-10, 176), S(-7, 98), S(4, 60), S(16, 58), S(55, 56), S(41, 44),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-151, -37), S(1, 51), S(-5, 115), S(27, 148), S(43, 173), S(58, 176), S(37, 173),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-96, -317), S(-33, -113), S(-2, -8), S(23, 29), S(54, 46), S(70, 76), S(92, 72), S(112, 75), S(148, -8),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-63, -282), S(-17, -118), S(33, -49), S(54, 7), S(76, 45), S(89, 73), S(95, 95), S(102, 107), S(103, 123), S(114, 113), S(120, 106), S(157, 55), S(157, 57), S(196, -36),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(113, -180), S(21, -2), S(43, 28), S(58, 43), S(69, 62), S(72, 76), S(77, 90), S(83, 96), S(88, 108), S(94, 115), S(101, 121), S(104, 127), S(103, 129), S(112, 105), S(187, -7),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-123, -128), S(16, 8), S(44, 115), S(65, 234), S(81, 273), S(88, 320), S(94, 350), S(100, 364), S(104, 384), S(107, 400), S(112, 405), S(115, 412), S(119, 413), S(120, 416), S(119, 417), S(116, 420), S(112, 417), S(115, 406), S(115, 399), S(117, 392), S(116, 369), S(123, 339), S(95, 362), S(61, 333), S(40, 314), S(8, 316), S(-36, 326), S(-41, 288),
};

inline const PParam PAWN_THREAT_KNIGHT = S(206, 126);
inline const PParam PAWN_THREAT_BISHOP = S(188, 181);
inline const PParam PAWN_THREAT_ROOK   = S(211, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(174, 7);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 119);
inline const PParam KNIGHT_THREAT_ROOK   = S(221, 86);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -17);

inline const PParam BISHOP_THREAT_KNIGHT = S(98, 76);
inline const PParam BISHOP_THREAT_ROOK   = S(210, 155);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 101);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -23), S(-0, -6), S(-3, -16), S(-7, -27), S(-11, -37), S(-15, -46), S(-16, -59), S(-21, -60), S(-28, -70),
};

inline const PParam ROOK_LINEUP = S(14, 83);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(212, 190),    S(71, 285),     S(91, 244),     S(133, 226),    S(177, 150),    S(92, 236),     S(67, 275),     S(214, 205),    //
    S(33, 27),      S(46, 72),      S(25, 28),      S(46, -63),     S(40, -99),     S(5, -49),      S(-8, 18),      S(-33, 46),     //
    S(25, -4),      S(-1, 23),      S(24, -7),      S(27, -97),     S(16, -113),    S(-11, -76),    S(-51, -31),    S(-54, 2),      //
    S(-13, -57),    S(-39, -2),     S(-2, -29),     S(-6, -99),     S(-25, -106),   S(-39, -79),    S(-96, -39),    S(-86, -48),    //
    S(-16, -88),    S(22, -83),     S(7, -12),      S(1, -75),      S(-30, -77),    S(-47, -80),    S(-85, -61),    S(-89, -65),    //
    S(8, -71),      S(90, -85),     S(81, -77),     S(35, -50),     S(5, -65),      S(-18, -75),    S(-53, -49),    S(-66, -49),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-285, -482),  S(-262, 6),     S(-313, -84),   S(17, -11),     S(-89, 6),      S(-260, 29),    S(-393, 78),    S(-378, -353),  //
    S(-27, -33),    S(-11, 13),     S(91, -8),      S(93, 17),      S(105, 6),      S(43, -0),      S(-26, 0),      S(-38, -31),    //
    S(51, -47),     S(49, 12),      S(86, 60),      S(90, 79),      S(70, 99),      S(25, 77),      S(16, 4),       S(-29, -22),    //
    S(108, -0),     S(102, 47),     S(119, 72),     S(113, 110),    S(130, 100),    S(81, 79),      S(65, 24),      S(45, 3),       //
    S(72, 11),      S(120, -1),     S(98, 71),      S(99, 88),      S(74, 94),      S(75, 77),      S(70, -4),      S(20, 4),       //
    S(10, -32),     S(35, 19),      S(35, 63),      S(51, 81),      S(42, 82),      S(16, 42),      S(11, -6),      S(-30, -58),    //
    S(33, -44),     S(38, -25),     S(19, -13),     S(23, 12),      S(19, 10),      S(-6, -41),     S(-30, -25),    S(-42, -121),   //
    S(-42, -101),   S(9, -49),      S(27, -66),     S(44, -49),     S(26, -33),     S(-11, -67),    S(-22, -51),    S(-62, -153),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-135, 17),    S(-174, 81),    S(-485, 178),   S(-299, 85),    S(-307, 110),   S(-314, 112),   S(-210, 106),   S(-134, 53),    //
    S(-53, -16),    S(-97, 76),     S(-45, 22),     S(-103, 62),    S(-82, 47),     S(-51, 36),     S(-32, 33),     S(-59, 3),      //
    S(27, 11),      S(21, 48),      S(26, 54),      S(26, 38),      S(10, 33),      S(7, 41),       S(10, 37),      S(11, -8),      //
    S(13, -8),      S(47, 18),      S(70, 25),      S(71, 60),      S(102, 52),     S(44, 16),      S(44, -9),      S(0, -20),      //
    S(51, -59),     S(49, -2),      S(78, 22),      S(92, 40),      S(74, 53),      S(72, 16),      S(22, -7),      S(22, -55),     //
    S(64, -33),     S(85, -10),     S(97, 19),      S(69, 40),      S(63, 20),      S(64, 11),      S(76, -19),     S(23, -37),     //
    S(37, -97),     S(118, -60),    S(78, -25),     S(49, -8),      S(33, -2),      S(54, -53),     S(51, -64),     S(50, -76),     //
    S(55, -83),     S(30, -34),     S(28, -17),     S(51, -35),     S(33, -28),     S(40, 5),       S(50, -29),     S(47, -68),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(194, 78),     S(240, 73),     S(201, 99),     S(188, 86),     S(237, 47),     S(193, 69),     S(212, 70),     S(185, 81),     //
    S(85, 163),     S(162, 153),    S(242, 119),    S(170, 148),    S(217, 113),    S(178, 129),    S(115, 148),    S(100, 146),    //
    S(55, 159),     S(190, 108),    S(213, 110),    S(194, 93),     S(193, 97),     S(129, 134),    S(134, 121),    S(70, 160),     //
    S(21, 137),     S(99, 153),     S(118, 138),    S(99, 133),     S(132, 104),    S(90, 143),     S(88, 137),     S(17, 154),     //
    S(-11, 65),     S(69, 77),      S(49, 107),     S(22, 101),     S(39, 90),      S(27, 112),     S(8, 101),      S(-13, 93),     //
    S(-1, -22),     S(79, 3),       S(61, 33),      S(44, 24),      S(58, 11),      S(29, 43),      S(43, 9),       S(-8, 20),      //
    S(-91, -20),    S(54, -70),     S(49, -24),     S(39, 2),       S(50, -17),     S(33, -4),      S(28, -32),     S(-7, -21),     //
    S(-28, -57),    S(-10, -24),    S(57, -34),     S(69, -40),     S(71, -40),     S(49, -18),     S(51, -37),     S(32, -33),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(59, 167),     S(168, 93),     S(74, 229),     S(27, 316),     S(64, 270),     S(93, 188),     S(80, 134),     S(2, 196),      //
    S(62, 177),     S(78, 248),     S(59, 296),     S(-71, 403),    S(-21, 373),    S(18, 293),     S(54, 176),     S(29, 160),     //
    S(56, 197),     S(70, 266),     S(40, 339),     S(4, 370),      S(17, 356),     S(55, 257),     S(83, 168),     S(87, 78),      //
    S(61, 116),     S(46, 229),     S(15, 293),     S(-9, 364),     S(7, 368),      S(41, 234),     S(79, 140),     S(57, 101),     //
    S(37, 125),     S(29, 169),     S(8, 239),      S(-10, 289),    S(-2, 317),     S(28, 229),     S(37, 152),     S(62, 56),      //
    S(32, 35),      S(53, 67),      S(42, 152),     S(17, 169),     S(28, 168),     S(33, 190),     S(59, 114),     S(54, 60),      //
    S(-5, -101),    S(27, -92),     S(29, -12),     S(49, 26),      S(42, 69),      S(50, 35),      S(27, 56),      S(48, 22),      //
    S(-16, -93),    S(5, -237),     S(29, -222),    S(40, -107),    S(45, -28),     S(54, -83),     S(54, -65),     S(29, -32),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(38, -377),    S(306, 239),    S(252, 248),    S(75, 113),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(236, -89),    S(263, 190),    S(155, 227),    S(65, 111),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(108, 68),     S(152, 180),    S(87, 224),     S(-4, 162),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-52, 22),     S(39, 131),     S(-67, 220),    S(-111, 226),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-148, -10),   S(-73, 91),     S(-148, 200),   S(-227, 257),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -73),    S(-11, 31),     S(-117, 157),   S(-168, 207),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(27, -132),    S(19, -23),     S(-67, 76),     S(-140, 129),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-11, -239),   S(8, -114),     S(-87, -39),    S(-75, -65),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(389, -72);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(5, 0), S(9, 2), S(9, 3), S(5, 1), S(5, -3),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, -0), S(5, 1), S(3, 1), S(3, 0), S(3, -0),
};

inline const PParam KS_FLANK_ATTACK = S(3, -1);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, 0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, 1);

inline const std::array<std::array<PParam, 2>, 4> KS_SAFE_CHECKS = {{
  {{ S(-6, -15), S(-14, -11), }},
  {{ S(-1, -11), S(-7, -16), }},
  {{ S(-4, -13), S(-26, -13), }},
  {{ S(-7, -6), S(-16, -7), }},
}};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -4), S(-4, 3), S(-2, -2), S(9, -4), S(12, -7), S(6, -15), S(16, -31), }},
  {{ S(-0, 2), S(-22, 1), S(-17, 3), S(-7, 4), S(-6, 2), S(-10, -4), S(-6, -22), }},
  {{ S(2, -4), S(-6, -8), S(-5, 1), S(1, -1), S(-0, -1), S(-5, -6), S(-8, -27), }},
  {{ S(6, 5), S(-4, 0), S(2, 2), S(6, 2), S(5, 1), S(5, 5), S(7, -1), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, 22), S(-10, 11), S(-13, 13), S(-8, 16), S(3, 17),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(1, 13), S(-10, -123), S(4, -28), S(1, 5), S(-5, 8), S(-9, 11), S(-9, 11), }},
  {{ S(5, 10), S(-2, -68), S(8, -25), S(1, 1), S(-2, 6), S(-10, 9), S(-2, 10), }},
  {{ S(-1, 9), S(6, -40), S(15, -11), S(2, 5), S(-5, 8), S(-11, 11), S(-7, 12), }},
  {{ S(-1, 7), S(12, -28), S(8, -3), S(-2, 10), S(-10, 11), S(-13, 9), S(-11, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1432, 2109, 4, -18
);

inline VParam WINNABLE_PAWNS = V(-22);
inline VParam WINNABLE_SYM = V(128);
inline VParam WINNABLE_ASYM = V(115);
inline VParam WINNABLE_PAWN_ENDGAME = V(174);
inline VParam WINNABLE_BIAS = V(-529);

// Epoch duration: 8.71211s
// clang-format on
}  // namespace Clockwork
