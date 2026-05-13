#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(189, 452);
inline const PParam KNIGHT_MAT = S(848, 1364);
inline const PParam BISHOP_MAT = S(891, 1442);
inline const PParam ROOK_MAT   = S(1069, 2335);
inline const PParam QUEEN_MAT  = S(2581, 3697);
inline const PParam TEMPO_VAL  = S(63, 22);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, 15);
inline const PParam BISHOP_PAIR_VAL   = S(56, 227);
inline const PParam ROOK_OPEN_VAL     = S(122, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 34);
inline const PParam MINOR_BEHIND_PAWN = S(14, 43);
inline const PParam RESTRICTED_SQUARES = S(-24, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-19, -69);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -27);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(56, 55);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(45, -16);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(20, 56);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -1), S(33, 34), S(60, 64), S(141, 175), S(448, 242), S(569, 602),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(43, 43), S(41, 35), S(56, 45), S(87, 136), S(344, 204),
};
inline const std::array<std::array<PParam, 6>, 2> PASSED_PAWN = {{
  {{ S(-111, -228), S(-124, -183), S(-99, -69), S(-41, 43), S(83, 208), S(221, 326), }},
  {{ S(0, 0), S(-74, -255), S(-49, -104), S(17, 65), S(180, 233), S(344, 204), }},
}};
inline const std::array<std::array<PParam, 6>, 2> CANDIDATE_PASSED_PAWN = {{
  {{ S(-26, -2), S(-22, -14), S(-9, -8), S(27, 4), S(101, 62), S(0, 0), }},
  {{ S(0, 0), S(-1, -5), S(7, 40), S(61, 77), S(158, 137), S(0, 0), }},
}};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(31, -49), S(23, -4), S(16, 35), S(12, 114), S(82, 229), S(176, 389),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(7, -2), S(3, 30), S(-6, -5), S(-4, -41), S(-16, -133), S(-216, -263),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 223), S(-12, 195), S(-2, 106), S(11, 59), S(23, 58), S(69, 51), S(54, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-202, -58), S(10, 38), S(7, 111), S(42, 142), S(58, 173), S(70, 179), S(43, 177),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-100, -328), S(-35, -126), S(-2, -20), S(24, 18), S(55, 40), S(71, 75), S(92, 75), S(111, 84), S(144, 8),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-64, -273), S(-14, -118), S(37, -53), S(59, -1), S(82, 38), S(94, 66), S(100, 88), S(107, 101), S(107, 117), S(119, 107), S(123, 104), S(160, 53), S(163, 49), S(183, -26),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(116, -192), S(23, -10), S(45, 20), S(61, 33), S(72, 48), S(76, 60), S(82, 73), S(88, 77), S(93, 88), S(100, 92), S(108, 95), S(111, 100), S(111, 102), S(118, 80), S(191, -31),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-191, -132), S(-41, -40), S(-14, 79), S(8, 196), S(24, 233), S(32, 280), S(38, 311), S(45, 325), S(48, 348), S(51, 364), S(56, 372), S(58, 381), S(61, 383), S(63, 384), S(61, 387), S(58, 389), S(54, 388), S(58, 374), S(59, 365), S(65, 351), S(66, 327), S(78, 292), S(56, 305), S(29, 272), S(5, 263), S(-17, 252), S(-56, 251), S(-58, 205),
};

inline const PParam PAWN_THREAT_KNIGHT = S(208, 122);
inline const PParam PAWN_THREAT_BISHOP = S(191, 180);
inline const PParam PAWN_THREAT_ROOK   = S(210, 129);
inline const PParam PAWN_THREAT_QUEEN  = S(175, 8);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 118);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 89);
inline const PParam KNIGHT_THREAT_QUEEN  = S(160, -4);

inline const PParam BISHOP_THREAT_KNIGHT = S(98, 75);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 152);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 96);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -28), S(0, -11), S(-3, -20), S(-7, -31), S(-11, -41), S(-15, -48), S(-16, -60), S(-21, -61), S(-26, -71),
};

inline const PParam ROOK_LINEUP = S(16, 73);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(220, 223),    S(67, 321),     S(145, 270),    S(167, 206),    S(206, 136),    S(122, 216),    S(86, 255),     S(236, 189),    //
    S(23, 49),      S(23, 92),      S(15, 25),      S(14, -47),     S(8, -77),      S(-20, -18),    S(-27, 40),     S(-41, 62),     //
    S(20, -20),     S(-3, -10),     S(25, -61),     S(12, -91),     S(4, -104),     S(-20, -74),    S(-60, -23),    S(-57, 6),      //
    S(-11, -80),    S(-31, -56),    S(1, -76),      S(-9, -86),     S(-30, -92),    S(-43, -72),    S(-96, -38),    S(-87, -44),    //
    S(-10, -114),   S(26, -114),    S(9, -50),      S(-9, -59),     S(-35, -70),    S(-52, -65),    S(-84, -53),    S(-87, -62),    //
    S(10, -109),    S(91, -106),    S(69, -50),     S(26, -18),     S(-2, -43),     S(-23, -55),    S(-51, -41),    S(-67, -45),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-281, -451),  S(-268, 32),    S(-296, -84),   S(19, 19),      S(-87, 34),     S(-255, 48),    S(-390, 96),    S(-373, -330),  //
    S(-29, -17),    S(-19, 26),     S(87, 0),       S(88, 36),      S(99, 26),      S(37, 19),      S(-31, 22),     S(-42, -7),     //
    S(42, -36),     S(39, 12),      S(78, 56),      S(87, 74),      S(71, 85),      S(19, 81),      S(5, 20),       S(-40, 4),      //
    S(101, 11),     S(103, 44),     S(110, 68),     S(114, 108),    S(119, 104),    S(78, 84),      S(56, 42),      S(39, 23),      //
    S(76, 4),       S(114, -6),     S(103, 54),     S(91, 81),      S(79, 79),      S(76, 69),      S(65, 7),       S(22, 18),      //
    S(18, -52),     S(45, -19),     S(44, 25),      S(59, 54),      S(52, 52),      S(25, 22),      S(14, -7),      S(-27, -48),    //
    S(35, -37),     S(40, -26),     S(21, -27),     S(26, 1),       S(23, -1),      S(-1, -51),     S(-30, -17),    S(-36, -120),   //
    S(-36, -100),   S(11, -44),     S(30, -66),     S(48, -55),     S(29, -35),     S(-8, -67),     S(-19, -39),    S(-59, -145),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-130, 21),    S(-181, 97),    S(-484, 188),   S(-304, 104),   S(-313, 126),   S(-320, 121),   S(-209, 103),   S(-133, 53),    //
    S(-51, -12),    S(-97, 88),     S(-48, 37),     S(-98, 70),     S(-86, 61),     S(-44, 30),     S(-27, 30),     S(-52, 1),      //
    S(34, 14),      S(18, 45),      S(32, 52),      S(22, 53),      S(14, 36),      S(10, 38),      S(16, 28),      S(18, -6),      //
    S(11, -8),      S(53, 11),      S(70, 30),      S(78, 66),      S(104, 55),     S(50, 22),      S(47, -7),      S(-1, -9),      //
    S(52, -62),     S(53, -11),     S(83, 9),       S(95, 37),      S(83, 47),      S(70, 27),      S(23, 5),       S(20, -36),     //
    S(64, -36),     S(89, -31),     S(102, 1),      S(73, 26),      S(69, 8),       S(67, 16),      S(74, -5),      S(22, -22),     //
    S(40, -95),     S(117, -62),    S(76, -33),     S(51, -11),     S(36, -10),     S(56, -50),     S(54, -56),     S(48, -64),     //
    S(58, -91),     S(35, -44),     S(30, -12),     S(52, -38),     S(36, -31),     S(42, 6),       S(53, -29),     S(49, -63),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(192, 85),     S(235, 83),     S(184, 103),    S(169, 85),     S(227, 57),     S(177, 86),     S(201, 95),     S(181, 104),    //
    S(90, 161),     S(156, 157),    S(234, 108),    S(168, 133),    S(214, 119),    S(175, 134),    S(112, 165),    S(100, 167),    //
    S(54, 152),     S(184, 107),    S(219, 82),     S(198, 66),     S(192, 93),     S(128, 137),    S(132, 136),    S(68, 178),     //
    S(28, 110),     S(104, 122),    S(134, 93),     S(106, 97),     S(142, 79),     S(97, 128),     S(92, 130),     S(24, 153),     //
    S(0, 34),       S(78, 49),      S(65, 66),      S(33, 69),      S(47, 76),      S(36, 103),     S(15, 99),      S(-6, 95),      //
    S(15, -50),     S(95, -29),     S(78, -5),      S(56, -3),      S(65, 6),       S(38, 40),      S(47, 15),      S(-1, 25),      //
    S(-74, -51),    S(67, -91),     S(65, -54),     S(51, -23),     S(56, -22),     S(41, -9),      S(34, -28),     S(2, -18),      //
    S(-13, -77),    S(4, -45),      S(69, -56),     S(80, -58),     S(80, -46),     S(59, -24),     S(58, -36),     S(40, -30),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(47, 148),     S(157, 65),     S(68, 179),     S(11, 266),     S(50, 226),     S(74, 168),     S(69, 109),     S(-6, 172),     //
    S(50, 179),     S(57, 259),     S(35, 277),     S(-105, 376),   S(-55, 366),    S(-5, 291),     S(36, 186),     S(13, 179),     //
    S(20, 198),     S(43, 272),     S(12, 322),     S(-26, 344),    S(-10, 339),    S(35, 265),     S(66, 179),     S(63, 106),     //
    S(38, 98),      S(30, 198),     S(-14, 272),    S(-34, 342),    S(-18, 360),    S(19, 234),     S(62, 152),     S(35, 131),     //
    S(26, 86),      S(16, 136),     S(-2, 194),     S(-27, 270),    S(-15, 307),    S(8, 243),      S(18, 165),     S(44, 84),      //
    S(25, 7),       S(42, 37),      S(36, 122),     S(13, 142),     S(19, 167),     S(22, 201),     S(42, 136),     S(37, 75),      //
    S(-6, -128),    S(18, -78),     S(21, -19),     S(45, 17),      S(37, 68),      S(40, 48),      S(15, 73),      S(34, 36),      //
    S(-17, -114),   S(4, -257),     S(26, -238),    S(39, -126),    S(41, -26),     S(47, -78),     S(44, -50),     S(18, -13),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(34, -301),    S(322, 301),    S(207, 327),    S(-19, 224),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(246, -3),     S(269, 276),    S(121, 312),    S(-7, 207),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(144, 118),    S(170, 235),    S(68, 272),     S(-56, 222),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, 61),     S(64, 155),     S(-78, 232),    S(-138, 243),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-103, -16),   S(-40, 75),     S(-126, 153),   S(-230, 222),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -66),    S(27, 1),       S(-84, 95),     S(-155, 156),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -124),    S(46, -48),     S(-34, 14),     S(-110, 72),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-4, -225),    S(20, -119),    S(-74, -63),    S(-58, -86),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-85, -530);

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
  {{ S(15, 31), S(-7, 33), S(-6, -45), S(6, -23), S(8, -13), S(-10, 17), S(-21, 17), }},
  {{ S(-2, 121), S(-19, -276), S(-18, -79), S(-8, 16), S(-7, 56), S(-20, 89), S(-37, 86), }},
  {{ S(-5, 100), S(-11, -213), S(-10, 95), S(-3, 69), S(-3, 61), S(-13, 64), S(-38, 52), }},
  {{ S(5, 121), S(-11, 80), S(-2, 88), S(5, 73), S(4, 62), S(5, 75), S(1, 74), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(17, 151), S(-5, 81), S(-10, 98), S(-5, 105), S(11, 78),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, 142), S(-54, -429), S(-15, -363), S(7, -325), S(-4, 69), S(-8, 90), S(-7, 89), }},
  {{ S(8, 66), S(-27, -488), S(-2, -501), S(3, -460), S(-3, 27), S(-9, 52), S(0, 49), }},
  {{ S(-0, 82), S(-11, -418), S(1, -3), S(2, 17), S(-3, 45), S(-8, 64), S(-4, 58), }},
  {{ S(-1, 73), S(-2, -186), S(4, -8), S(2, 33), S(-6, 48), S(-13, 61), S(-9, 60), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1153, 290, -15, 64
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(123);
inline VParam WINNABLE_ASYM = V(108);
inline VParam WINNABLE_PAWN_ENDGAME = V(185);
inline VParam WINNABLE_BIAS = V(-506);

// Epoch duration: 8.32346s
// clang-format on
}  // namespace Clockwork
