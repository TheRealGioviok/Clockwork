#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(188, 452);
inline const PParam KNIGHT_MAT = S(848, 1365);
inline const PParam BISHOP_MAT = S(890, 1442);
inline const PParam ROOK_MAT   = S(1067, 2334);
inline const PParam QUEEN_MAT  = S(2582, 3694);
inline const PParam TEMPO_VAL  = S(63, 22);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, 15);
inline const PParam BISHOP_PAIR_VAL   = S(56, 227);
inline const PParam ROOK_OPEN_VAL     = S(122, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 34);
inline const PParam MINOR_BEHIND_PAWN = S(14, 43);
inline const PParam RESTRICTED_SQUARES = S(-24, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -69);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -27);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(56, 55);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(45, -16);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(20, 56);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -1), S(33, 34), S(60, 63), S(141, 173), S(448, 242), S(569, 602),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(43, 43), S(41, 35), S(57, 45), S(87, 136), S(346, 205),
};
inline const std::array<std::array<PParam, 6>, 2> PASSED_PAWN = {{
  {{ S(-110, -227), S(-123, -182), S(-98, -68), S(-40, 45), S(83, 210), S(224, 328), }},
  {{ S(0, 0), S(-74, -253), S(-49, -103), S(18, 67), S(181, 234), S(346, 205), }},
}};
inline const std::array<std::array<PParam, 6>, 2> CANDIDATE_PASSED_PAWN = {{
  {{ S(-27, -2), S(-23, -14), S(-10, -7), S(27, 4), S(101, 62), S(0, 0), }},
  {{ S(0, 0), S(-3, -5), S(3, 40), S(58, 78), S(158, 137), S(0, 0), }},
}};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(31, -49), S(23, -4), S(16, 35), S(12, 114), S(82, 229), S(176, 389),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(7, -3), S(3, 30), S(-6, -5), S(-4, -41), S(-16, -133), S(-216, -263),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(15, 224), S(-11, 196), S(-1, 107), S(13, 60), S(24, 59), S(70, 52), S(55, 38),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-204, -60), S(8, 36), S(5, 108), S(40, 139), S(55, 170), S(68, 176), S(41, 174),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-100, -328), S(-35, -127), S(-2, -20), S(24, 18), S(55, 39), S(71, 74), S(92, 75), S(111, 83), S(144, 8),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-65, -273), S(-14, -118), S(37, -53), S(59, -0), S(81, 38), S(94, 66), S(100, 88), S(106, 101), S(107, 117), S(119, 107), S(122, 105), S(159, 53), S(163, 49), S(183, -25),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(117, -191), S(24, -9), S(46, 21), S(62, 34), S(73, 49), S(77, 61), S(83, 74), S(89, 78), S(94, 89), S(101, 93), S(109, 96), S(112, 101), S(112, 103), S(119, 81), S(192, -30),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-191, -130), S(-41, -37), S(-14, 81), S(8, 198), S(24, 235), S(32, 282), S(38, 313), S(45, 327), S(48, 350), S(51, 366), S(55, 374), S(58, 383), S(61, 385), S(63, 386), S(61, 389), S(58, 391), S(54, 390), S(58, 376), S(59, 367), S(65, 353), S(66, 329), S(78, 294), S(56, 307), S(29, 274), S(5, 265), S(-17, 253), S(-56, 253), S(-58, 207),
};

inline const PParam PAWN_THREAT_KNIGHT = S(208, 121);
inline const PParam PAWN_THREAT_BISHOP = S(190, 180);
inline const PParam PAWN_THREAT_ROOK   = S(210, 129);
inline const PParam PAWN_THREAT_QUEEN  = S(175, 8);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 118);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 89);
inline const PParam KNIGHT_THREAT_QUEEN  = S(160, -5);

inline const PParam BISHOP_THREAT_KNIGHT = S(99, 75);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 152);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 96);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -28), S(0, -11), S(-3, -20), S(-7, -31), S(-11, -41), S(-15, -48), S(-16, -60), S(-21, -62), S(-26, -71),
};

inline const PParam ROOK_LINEUP = S(16, 73);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(219, 224),    S(66, 321),     S(144, 271),    S(166, 207),    S(205, 137),    S(121, 216),    S(85, 255),     S(235, 189),    //
    S(24, 49),      S(24, 92),      S(16, 25),      S(15, -47),     S(9, -77),      S(-19, -18),    S(-27, 40),     S(-40, 62),     //
    S(21, -19),     S(-3, -10),     S(26, -61),     S(13, -91),     S(5, -104),     S(-20, -73),    S(-60, -22),    S(-56, 7),      //
    S(-9, -80),     S(-30, -56),    S(2, -76),      S(-8, -85),     S(-29, -92),    S(-42, -71),    S(-95, -38),    S(-86, -44),    //
    S(-9, -114),    S(27, -114),    S(11, -50),     S(-7, -59),     S(-33, -70),    S(-51, -65),    S(-82, -53),    S(-86, -62),    //
    S(12, -109),    S(92, -106),    S(71, -50),     S(27, -18),     S(-0, -43),     S(-21, -55),    S(-50, -41),    S(-65, -45),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-282, -451),  S(-268, 31),    S(-297, -84),   S(19, 19),      S(-87, 34),     S(-256, 47),    S(-390, 96),    S(-373, -330),  //
    S(-29, -17),    S(-19, 26),     S(86, 0),       S(88, 36),      S(99, 26),      S(37, 19),      S(-32, 22),     S(-42, -7),     //
    S(42, -36),     S(39, 12),      S(77, 56),      S(87, 74),      S(71, 85),      S(19, 81),      S(5, 19),       S(-41, 3),      //
    S(101, 10),     S(103, 44),     S(110, 68),     S(114, 108),    S(119, 104),    S(78, 84),      S(55, 42),      S(39, 22),      //
    S(76, 4),       S(114, -6),     S(103, 54),     S(90, 81),      S(78, 79),      S(76, 69),      S(65, 7),       S(21, 17),      //
    S(18, -52),     S(44, -19),     S(44, 24),      S(58, 54),      S(52, 51),      S(24, 22),      S(14, -7),      S(-27, -48),    //
    S(35, -37),     S(39, -27),     S(21, -28),     S(26, 1),       S(22, -1),      S(-1, -51),     S(-30, -18),    S(-37, -120),   //
    S(-36, -100),   S(11, -44),     S(30, -66),     S(48, -55),     S(29, -35),     S(-8, -67),     S(-19, -40),    S(-60, -145),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-128, 20),    S(-179, 97),    S(-483, 188),   S(-302, 103),   S(-312, 126),   S(-317, 120),   S(-207, 102),   S(-132, 53),    //
    S(-49, -12),    S(-96, 87),     S(-46, 37),     S(-97, 70),     S(-84, 61),     S(-42, 29),     S(-25, 30),     S(-51, 0),      //
    S(36, 14),      S(20, 45),      S(34, 51),      S(24, 53),      S(16, 36),      S(11, 38),      S(18, 28),      S(20, -6),      //
    S(13, -8),      S(54, 11),      S(72, 30),      S(79, 66),      S(105, 55),     S(52, 22),      S(49, -7),      S(1, -9),       //
    S(54, -62),     S(55, -11),     S(84, 8),       S(97, 37),      S(84, 47),      S(72, 27),      S(25, 5),       S(21, -37),     //
    S(66, -37),     S(91, -31),     S(104, 1),      S(74, 25),      S(71, 8),       S(68, 16),      S(76, -6),      S(24, -22),     //
    S(42, -95),     S(119, -62),    S(78, -33),     S(53, -11),     S(38, -10),     S(58, -50),     S(55, -56),     S(50, -64),     //
    S(60, -91),     S(37, -44),     S(32, -12),     S(54, -38),     S(38, -31),     S(43, 6),       S(55, -29),     S(51, -63),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(192, 86),     S(234, 84),     S(184, 104),    S(169, 85),     S(227, 57),     S(177, 87),     S(201, 95),     S(181, 104),    //
    S(90, 161),     S(156, 157),    S(233, 108),    S(168, 133),    S(214, 119),    S(175, 135),    S(112, 165),    S(100, 167),    //
    S(54, 152),     S(184, 107),    S(218, 82),     S(198, 66),     S(192, 93),     S(128, 137),    S(132, 136),    S(68, 178),     //
    S(28, 110),     S(104, 123),    S(134, 93),     S(106, 97),     S(142, 80),     S(97, 128),     S(92, 131),     S(23, 154),     //
    S(0, 34),       S(78, 49),      S(65, 67),      S(33, 70),      S(47, 76),      S(36, 103),     S(15, 99),      S(-6, 96),      //
    S(15, -50),     S(95, -29),     S(78, -5),      S(56, -3),      S(65, 6),       S(38, 40),      S(47, 15),      S(-1, 25),      //
    S(-74, -50),    S(67, -91),     S(65, -54),     S(51, -23),     S(56, -22),     S(41, -8),      S(34, -27),     S(2, -18),      //
    S(-13, -77),    S(4, -44),      S(69, -56),     S(79, -58),     S(80, -46),     S(59, -23),     S(58, -36),     S(40, -30),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(47, 147),     S(157, 64),     S(68, 178),     S(11, 265),     S(50, 225),     S(74, 168),     S(69, 109),     S(-6, 171),     //
    S(50, 178),     S(56, 257),     S(34, 276),     S(-106, 375),   S(-56, 365),    S(-6, 290),     S(35, 185),     S(12, 179),     //
    S(20, 197),     S(43, 271),     S(12, 321),     S(-27, 343),    S(-11, 338),    S(35, 265),     S(66, 178),     S(62, 104),     //
    S(37, 98),      S(29, 197),     S(-14, 272),    S(-35, 341),    S(-18, 359),    S(19, 233),     S(61, 151),     S(35, 130),     //
    S(26, 86),      S(15, 135),     S(-2, 193),     S(-28, 269),    S(-16, 307),    S(7, 242),      S(18, 165),     S(44, 83),      //
    S(25, 6),       S(42, 36),      S(36, 121),     S(13, 141),     S(19, 166),     S(22, 200),     S(41, 136),     S(36, 75),      //
    S(-6, -128),    S(18, -79),     S(20, -19),     S(44, 16),      S(37, 67),      S(39, 47),      S(15, 72),      S(34, 36),      //
    S(-17, -115),   S(3, -258),     S(26, -239),    S(39, -127),    S(41, -27),     S(47, -79),     S(44, -51),     S(18, -14),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(33, -300),    S(322, 301),    S(207, 327),    S(-19, 224),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(245, -3),     S(268, 277),    S(121, 312),    S(-7, 207),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(143, 119),    S(170, 235),    S(68, 272),     S(-57, 222),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, 61),     S(64, 155),     S(-78, 232),    S(-138, 243),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-103, -16),   S(-41, 75),     S(-127, 153),   S(-231, 222),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -66),    S(27, 1),       S(-84, 95),     S(-156, 157),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(38, -124),    S(45, -48),     S(-35, 14),     S(-111, 72),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-5, -225),    S(19, -119),    S(-74, -63),    S(-59, -86),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-85, -529);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -7), S(14, -22), S(14, -2), S(6, -8), S(1, -25),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -10), S(6, -25), S(4, -13), S(4, -0), S(4, 4),
};

inline const PParam KS_FLANK_ATTACK = S(4, -8);
inline const PParam KS_FLANK_DEFENSE = S(-5, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -5);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, 30), S(-7, 33), S(-6, -44), S(6, -23), S(8, -13), S(-10, 17), S(-22, 17), }},
  {{ S(-2, 120), S(-19, -275), S(-18, -79), S(-8, 16), S(-7, 56), S(-20, 88), S(-37, 86), }},
  {{ S(-5, 100), S(-10, -213), S(-10, 95), S(-2, 69), S(-2, 61), S(-13, 63), S(-38, 51), }},
  {{ S(5, 120), S(-11, 79), S(-2, 88), S(5, 72), S(4, 62), S(5, 74), S(1, 73), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(17, 151), S(-5, 81), S(-10, 98), S(-5, 105), S(11, 78),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, 142), S(-54, -427), S(-15, -362), S(6, -324), S(-4, 69), S(-8, 90), S(-7, 89), }},
  {{ S(8, 66), S(-27, -487), S(-3, -501), S(3, -460), S(-3, 26), S(-9, 52), S(0, 49), }},
  {{ S(-1, 82), S(-11, -420), S(1, -3), S(2, 17), S(-3, 45), S(-9, 64), S(-4, 58), }},
  {{ S(-1, 73), S(-2, -188), S(4, -8), S(2, 33), S(-6, 48), S(-13, 61), S(-10, 60), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1153, 290, -15, 64
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(123);
inline VParam WINNABLE_ASYM = V(108);
inline VParam WINNABLE_PAWN_ENDGAME = V(185);
inline VParam WINNABLE_BIAS = V(-506);

// Epoch duration: 7.31794s
// clang-format on
}  // namespace Clockwork
