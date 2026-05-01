#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(183, 436);
inline const PParam KNIGHT_MAT = S(836, 1255);
inline const PParam BISHOP_MAT = S(870, 1315);
inline const PParam ROOK_MAT   = S(1037, 2101);
inline const PParam QUEEN_MAT  = S(2539, 3257);
inline const PParam TEMPO_VAL  = S(60, 21);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 14);
inline const PParam BISHOP_PAIR_VAL   = S(53, 220);
inline const PParam ROOK_OPEN_VAL     = S(114, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 31);
inline const PParam MINOR_BEHIND_PAWN = S(14, 40);
inline const PParam RESTRICTED_SQUARES = S(-23, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -77);
inline const PParam ISOLATED_PAWN_VAL = S(-17, -24);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 55);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(45, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 53);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -42);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 3), S(29, 35), S(58, 59), S(137, 167), S(364, 257), S(469, 510),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(44, 42), S(44, 34), S(60, 60), S(117, 162), S(413, 92),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-101, -216), S(-102, -183), S(-77, -62), S(-24, 50), S(64, 211), S(246, 301),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -41), S(23, -2), S(16, 33), S(5, 119), S(75, 236), S(171, 380),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -25), S(4, 19), S(1, -18), S(1, -46), S(-9, -136), S(-242, -244),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(18, 206), S(-6, 176), S(1, 97), S(8, 58), S(15, 59), S(52, 55), S(43, 38),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-265, -48), S(-8, 34), S(-2, 96), S(35, 126), S(55, 150), S(65, 156), S(43, 155),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-102, -298), S(-40, -105), S(-11, -4), S(15, 33), S(44, 54), S(60, 88), S(80, 88), S(100, 98), S(132, 26),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-68, -274), S(-20, -99), S(31, -24), S(54, 25), S(75, 62), S(87, 90), S(92, 111), S(100, 123), S(102, 139), S(114, 129), S(118, 129), S(154, 80), S(159, 73), S(183, 26),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(105, -146), S(24, 26), S(45, 56), S(61, 67), S(71, 82), S(76, 95), S(81, 107), S(88, 110), S(93, 122), S(101, 125), S(108, 129), S(111, 136), S(113, 136), S(121, 112), S(191, 8),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-163, -72), S(-33, 21), S(-8, 144), S(12, 256), S(27, 300), S(36, 344), S(41, 377), S(49, 385), S(52, 410), S(55, 426), S(61, 431), S(63, 441), S(68, 439), S(68, 446), S(70, 442), S(66, 446), S(64, 442), S(69, 428), S(73, 416), S(77, 403), S(75, 386), S(91, 343), S(73, 349), S(56, 299), S(27, 297), S(12, 268), S(-37, 286), S(-26, 222),
};

inline const PParam PAWN_THREAT_KNIGHT = S(205, 106);
inline const PParam PAWN_THREAT_BISHOP = S(192, 157);
inline const PParam PAWN_THREAT_ROOK   = S(197, 133);
inline const PParam PAWN_THREAT_QUEEN  = S(179, -15);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 114);
inline const PParam KNIGHT_THREAT_ROOK   = S(222, 86);
inline const PParam KNIGHT_THREAT_QUEEN  = S(153, -7);

inline const PParam BISHOP_THREAT_KNIGHT = S(97, 72);
inline const PParam BISHOP_THREAT_ROOK   = S(207, 142);
inline const PParam BISHOP_THREAT_QUEEN  = S(167, 112);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -26), S(0, -8), S(-3, -17), S(-6, -27), S(-11, -37), S(-14, -44), S(-16, -57), S(-21, -59), S(-34, -57),
};

inline const PParam ROOK_LINEUP = S(16, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(206, 227),    S(51, 280),     S(194, 212),    S(177, 182),    S(221, 108),    S(117, 201),    S(53, 252),     S(193, 191),    //
    S(42, 30),      S(70, 44),      S(75, 13),      S(54, -52),     S(48, -83),     S(27, -34),     S(7, 23),       S(-23, 51),     //
    S(25, -24),     S(3, -18),      S(34, -59),     S(20, -84),     S(16, -99),     S(-6, -71),     S(-51, -24),    S(-48, 3),      //
    S(-7, -77),     S(-26, -49),    S(2, -73),      S(-11, -80),    S(-33, -82),    S(-38, -67),    S(-92, -31),    S(-82, -38),    //
    S(-6, -108),    S(28, -110),    S(11, -54),     S(-4, -58),     S(-32, -67),    S(-48, -64),    S(-80, -50),    S(-80, -56),    //
    S(15, -107),    S(94, -110),    S(71, -61),     S(30, -25),     S(2, -45),      S(-20, -58),    S(-50, -43),    S(-62, -42),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-300, -394),  S(-283, 45),    S(-234, -188),  S(-30, 42),     S(-99, 38),     S(-235, 34),    S(-402, 107),   S(-376, -272),  //
    S(-44, -14),    S(-28, 31),     S(85, -5),      S(85, 28),      S(88, 24),      S(21, 30),      S(-43, 35),     S(-63, 6),      //
    S(25, -20),     S(36, 11),      S(72, 63),      S(90, 59),      S(61, 83),      S(16, 80),      S(5, 19),       S(-41, 11),     //
    S(88, 10),      S(96, 42),      S(105, 70),     S(106, 107),    S(112, 109),    S(71, 87),      S(45, 53),      S(30, 27),      //
    S(68, 12),      S(108, -4),     S(94, 60),      S(89, 79),      S(70, 81),      S(74, 68),      S(57, 18),      S(13, 31),      //
    S(10, -33),     S(37, -9),      S(37, 32),      S(50, 58),      S(44, 55),      S(16, 33),      S(7, -1),       S(-33, -34),    //
    S(27, -25),     S(36, -26),     S(14, -14),     S(21, 10),      S(19, 8),       S(-7, -39),     S(-32, -7),     S(-44, -102),   //
    S(-46, -86),    S(6, -26),      S(24, -51),     S(40, -44),     S(23, -24),     S(-11, -50),    S(-23, -33),    S(-66, -129),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-149, 73),    S(-170, 105),   S(-460, 177),   S(-310, 111),   S(-317, 126),   S(-343, 126),   S(-236, 119),   S(-125, 54),    //
    S(-46, -5),     S(-85, 86),     S(-56, 46),     S(-112, 76),    S(-89, 64),     S(-59, 46),     S(-21, 36),     S(-58, 14),     //
    S(21, 24),      S(7, 57),       S(23, 62),      S(17, 56),      S(0, 47),       S(11, 40),      S(10, 36),      S(4, 15),       //
    S(9, 2),        S(45, 15),      S(58, 39),      S(68, 71),      S(102, 52),     S(38, 29),      S(40, -6),      S(-8, 2),       //
    S(43, -52),     S(51, -7),      S(75, 17),      S(90, 39),      S(72, 51),      S(61, 33),      S(18, 9),       S(9, -28),      //
    S(62, -37),     S(83, -21),     S(99, 10),      S(65, 33),      S(61, 13),      S(60, 22),      S(64, 3),       S(10, -4),      //
    S(31, -79),     S(112, -56),    S(72, -29),     S(50, -7),      S(34, -5),      S(46, -38),     S(44, -49),     S(42, -54),     //
    S(52, -74),     S(34, -38),     S(31, -4),      S(48, -31),     S(34, -19),     S(39, 18),      S(48, -14),     S(44, -49),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(187, 99),     S(236, 95),     S(184, 119),    S(184, 84),     S(226, 68),     S(181, 94),     S(203, 98),     S(178, 115),    //
    S(82, 170),     S(168, 160),    S(225, 127),    S(169, 137),    S(206, 127),    S(168, 145),    S(116, 172),    S(97, 178),     //
    S(48, 167),     S(180, 125),    S(211, 101),    S(185, 95),     S(182, 115),    S(132, 148),    S(135, 149),    S(68, 190),     //
    S(24, 132),     S(106, 137),    S(134, 107),    S(111, 116),    S(142, 102),    S(95, 143),     S(99, 139),     S(26, 170),     //
    S(4, 53),       S(80, 61),      S(70, 77),      S(40, 82),      S(48, 94),      S(36, 121),     S(13, 116),     S(-3, 111),     //
    S(20, -32),     S(92, -6),      S(79, 14),      S(58, 14),      S(68, 21),      S(36, 58),      S(45, 33),      S(5, 43),       //
    S(-74, -26),    S(64, -64),     S(67, -37),     S(55, -10),     S(57, -5),      S(45, 6),       S(35, -7),      S(4, 7),        //
    S(-10, -46),    S(16, -24),     S(71, -35),     S(81, -37),     S(81, -27),     S(61, -6),      S(57, -12),     S(37, -6),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(51, 170),     S(144, 97),     S(71, 199),     S(20, 281),     S(55, 236),     S(53, 212),     S(74, 129),     S(1, 203),      //
    S(50, 195),     S(59, 290),     S(32, 308),     S(-95, 390),    S(-59, 388),    S(-10, 331),    S(38, 208),     S(16, 206),     //
    S(17, 237),     S(41, 296),     S(20, 343),     S(-24, 370),    S(-16, 374),    S(37, 284),     S(55, 215),     S(62, 132),     //
    S(34, 134),     S(36, 220),     S(-12, 296),    S(-25, 357),    S(-13, 374),    S(20, 255),     S(62, 176),     S(35, 152),     //
    S(37, 97),      S(24, 156),     S(1, 222),      S(-21, 286),    S(-8, 312),     S(6, 262),      S(30, 172),     S(48, 99),      //
    S(30, 20),      S(45, 66),      S(40, 147),     S(22, 154),     S(25, 180),     S(28, 211),     S(45, 148),     S(38, 97),      //
    S(3, -96),      S(19, -43),     S(27, 6),       S(53, 36),      S(45, 85),      S(45, 63),      S(18, 101),     S(35, 72),      //
    S(-9, -93),     S(15, -226),    S(40, -213),    S(55, -107),    S(50, -7),      S(56, -54),     S(51, -22),     S(26, 6),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-62, -294),   S(275, 288),    S(155, 285),    S(-18, 194),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(213, 6),      S(265, 239),    S(108, 287),    S(12, 192),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(132, 116),    S(170, 220),    S(66, 257),     S(-14, 196),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, 58),     S(63, 152),     S(-70, 220),    S(-104, 232),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-107, -12),   S(-31, 72),     S(-110, 143),   S(-201, 211),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -60),    S(31, 5),       S(-71, 88),     S(-130, 145),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(36, -114),    S(44, -42),     S(-32, 15),     S(-97, 68),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-9, -214),    S(16, -110),    S(-66, -64),    S(-60, -78),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-86, -542);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -20), S(15, -27), S(14, -4), S(6, -9), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -12), S(6, -23), S(4, -13), S(4, -0), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -4);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -7);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, 44), S(-4, 54), S(-2, -17), S(9, -20), S(8, -8), S(-3, -4), S(-3, 56), }},
  {{ S(-2, 160), S(-21, -235), S(-21, -4), S(-8, 55), S(-8, 77), S(-19, -12), S(-19, -225), }},
  {{ S(-4, 139), S(-9, -221), S(-10, 131), S(-4, 111), S(-3, 110), S(-10, 136), S(-8, -200), }},
  {{ S(6, 124), S(-11, 85), S(0, 95), S(7, 77), S(5, 79), S(-2, 93), S(-8, 85), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 61), S(-11, 47), S(-11, 73), S(-1, 78), S(3, 37),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(2, 116), S(-9, 41), S(-9, 43), S(-6, 37), S(-7, 28), S(-8, 41), S(-9, 49), }},
  {{ S(9, 9), S(1, -24), S(-9, -16), S(-3, -54), S(-4, -51), S(-7, -15), S(1, -19), }},
  {{ S(0, 59), S(-4, 36), S(-7, 40), S(-4, 33), S(-3, 17), S(-8, 37), S(-4, 27), }},
  {{ S(-1, 54), S(-7, 37), S(-11, 37), S(-5, 42), S(-4, 41), S(-10, 32), S(-9, 38), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1056, 267, -15, 92
);

inline VParam WINNABLE_PAWNS = V(-24);
inline VParam WINNABLE_SYM = V(126);
inline VParam WINNABLE_ASYM = V(108);
inline VParam WINNABLE_PAWN_ENDGAME = V(191);
inline VParam WINNABLE_BIAS = V(-487);

// Epoch duration: 5.23206s
// clang-format on
}  // namespace Clockwork
