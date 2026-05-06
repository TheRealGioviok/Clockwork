#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(182, 442);
inline const PParam KNIGHT_MAT = S(836, 1273);
inline const PParam BISHOP_MAT = S(873, 1334);
inline const PParam ROOK_MAT   = S(1030, 2138);
inline const PParam QUEEN_MAT  = S(2582, 3257);
inline const PParam TEMPO_VAL  = S(61, 21);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 14);
inline const PParam BISHOP_PAIR_VAL   = S(52, 225);
inline const PParam ROOK_OPEN_VAL     = S(115, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 32);
inline const PParam MINOR_BEHIND_PAWN = S(14, 40);
inline const PParam RESTRICTED_SQUARES = S(-23, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -78);
inline const PParam ISOLATED_PAWN_VAL = S(-17, -24);

inline const PParam POTENTIAL_CHECKER_VAL = S(-51, -23);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 56);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(44, -16);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 51);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 3), S(29, 36), S(58, 60), S(127, 171), S(400, 242), S(469, 508),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(44, 42), S(43, 35), S(62, 60), S(116, 160), S(421, 85),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-100, -220), S(-102, -186), S(-79, -63), S(-30, 52), S(81, 209), S(245, 311),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -40), S(23, -1), S(16, 34), S(9, 117), S(78, 233), S(149, 380),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -24), S(4, 19), S(-0, -18), S(-1, -50), S(-19, -133), S(-208, -253),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 207), S(-2, 177), S(2, 100), S(8, 62), S(19, 59), S(58, 54), S(46, 41),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-207, -61), S(-6, 29), S(0, 95), S(36, 126), S(52, 151), S(61, 159), S(37, 160),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-98, -306), S(-37, -112), S(-8, -10), S(17, 28), S(47, 49), S(63, 83), S(83, 83), S(103, 93), S(135, 20),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-67, -281), S(-20, -105), S(32, -31), S(55, 19), S(77, 55), S(89, 82), S(94, 104), S(102, 116), S(104, 132), S(117, 121), S(120, 121), S(157, 69), S(165, 59), S(189, 11),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(108, -149), S(28, 20), S(50, 50), S(66, 61), S(76, 76), S(81, 89), S(86, 101), S(93, 104), S(98, 115), S(105, 118), S(113, 122), S(116, 129), S(118, 128), S(125, 105), S(194, -0),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-148, -83), S(-19, 13), S(5, 137), S(26, 251), S(41, 296), S(49, 342), S(54, 377), S(62, 386), S(65, 410), S(67, 428), S(73, 433), S(75, 443), S(81, 439), S(80, 449), S(82, 445), S(77, 448), S(75, 446), S(80, 432), S(82, 422), S(89, 405), S(87, 387), S(105, 340), S(84, 353), S(71, 296), S(43, 290), S(29, 264), S(-22, 286), S(-8, 215),
};

inline const PParam PAWN_THREAT_KNIGHT = S(205, 107);
inline const PParam PAWN_THREAT_BISHOP = S(193, 157);
inline const PParam PAWN_THREAT_ROOK   = S(201, 130);
inline const PParam PAWN_THREAT_QUEEN  = S(179, -14);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 114);
inline const PParam KNIGHT_THREAT_ROOK   = S(222, 87);
inline const PParam KNIGHT_THREAT_QUEEN  = S(153, -7);

inline const PParam BISHOP_THREAT_KNIGHT = S(98, 72);
inline const PParam BISHOP_THREAT_ROOK   = S(207, 143);
inline const PParam BISHOP_THREAT_QUEEN  = S(168, 107);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -27), S(0, -8), S(-3, -17), S(-6, -28), S(-11, -37), S(-14, -45), S(-16, -58), S(-21, -60), S(-34, -57),
};

inline const PParam ROOK_LINEUP = S(16, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(215, 203),    S(84, 297),     S(137, 264),    S(155, 192),    S(197, 114),    S(110, 202),    S(87, 236),     S(210, 178),    //
    S(32, 39),      S(44, 81),      S(38, 11),      S(39, -49),     S(31, -82),     S(-4, -24),     S(-13, 33),     S(-36, 57),     //
    S(29, -23),     S(10, -16),     S(33, -60),     S(21, -86),     S(16, -101),    S(-6, -71),     S(-47, -25),    S(-48, 4),      //
    S(-7, -78),     S(-26, -54),    S(5, -76),      S(-7, -83),     S(-28, -85),    S(-35, -68),    S(-91, -33),    S(-80, -39),    //
    S(-5, -112),    S(30, -116),    S(16, -58),     S(-0, -62),     S(-29, -70),    S(-45, -66),    S(-77, -52),    S(-79, -57),    //
    S(15, -109),    S(93, -114),    S(72, -65),     S(32, -29),     S(3, -48),      S(-18, -59),    S(-48, -43),    S(-61, -42),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-300, -396),  S(-282, 44),    S(-233, -188),  S(-27, 39),     S(-97, 37),     S(-233, 32),    S(-397, 103),   S(-376, -274),  //
    S(-41, -17),    S(-24, 27),     S(89, -10),     S(88, 24),      S(89, 23),      S(24, 28),      S(-40, 32),     S(-60, 4),      //
    S(28, -24),     S(38, 8),       S(78, 56),      S(94, 53),      S(65, 77),      S(19, 77),      S(8, 16),       S(-37, 7),      //
    S(90, 8),       S(98, 38),      S(107, 66),     S(109, 103),    S(116, 105),    S(72, 86),      S(48, 51),      S(32, 25),      //
    S(69, 10),      S(110, -7),     S(96, 57),      S(92, 76),      S(72, 79),      S(75, 66),      S(59, 15),      S(14, 30),      //
    S(11, -36),     S(38, -12),     S(38, 30),      S(52, 56),      S(46, 52),      S(18, 31),      S(9, -2),       S(-32, -35),    //
    S(27, -26),     S(37, -29),     S(15, -17),     S(22, 8),       S(20, 7),       S(-6, -42),     S(-31, -8),     S(-43, -104),   //
    S(-46, -85),    S(6, -26),      S(25, -54),     S(40, -46),     S(23, -25),     S(-11, -51),    S(-23, -32),    S(-67, -127),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-148, 72),    S(-166, 103),   S(-453, 171),   S(-304, 107),   S(-316, 125),   S(-337, 121),   S(-229, 111),   S(-123, 50),    //
    S(-44, -8),     S(-80, 81),     S(-50, 36),     S(-108, 70),    S(-86, 61),     S(-56, 42),     S(-17, 30),     S(-55, 10),     //
    S(23, 19),      S(11, 50),      S(26, 58),      S(21, 51),      S(5, 40),       S(14, 35),      S(13, 31),      S(7, 12),       //
    S(12, -4),      S(48, 11),      S(61, 35),      S(70, 68),      S(104, 49),     S(40, 27),      S(43, -9),      S(-6, -1),      //
    S(44, -57),     S(54, -13),     S(77, 13),      S(92, 37),      S(74, 49),      S(63, 32),      S(20, 7),       S(11, -30),     //
    S(64, -42),     S(84, -26),     S(100, 7),      S(66, 30),      S(63, 9),       S(61, 20),      S(67, 1),       S(11, -7),      //
    S(33, -80),     S(112, -58),    S(74, -33),     S(51, -10),     S(35, -7),      S(47, -40),     S(45, -50),     S(43, -54),     //
    S(54, -76),     S(35, -41),     S(32, -6),      S(48, -32),     S(35, -20),     S(39, 16),      S(48, -15),     S(44, -50),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(190, 97),     S(235, 97),     S(185, 117),    S(182, 86),     S(223, 72),     S(181, 94),     S(203, 101),    S(180, 116),    //
    S(86, 168),     S(171, 158),    S(231, 120),    S(174, 130),    S(209, 125),    S(172, 143),    S(119, 171),    S(102, 176),    //
    S(51, 165),     S(184, 120),    S(212, 98),     S(190, 87),     S(188, 109),    S(135, 145),    S(139, 146),    S(72, 188),     //
    S(26, 127),     S(109, 131),    S(135, 104),    S(114, 111),    S(146, 98),     S(98, 141),     S(102, 135),    S(28, 167),     //
    S(5, 48),       S(84, 54),      S(73, 71),      S(43, 76),      S(51, 91),      S(40, 117),     S(16, 112),     S(0, 107),      //
    S(23, -38),     S(95, -13),     S(83, 5),       S(61, 7),       S(71, 16),      S(39, 54),      S(47, 29),      S(7, 39),       //
    S(-72, -31),    S(67, -72),     S(69, -42),     S(57, -15),     S(59, -10),     S(47, 1),       S(37, -10),     S(6, 3),        //
    S(-9, -49),     S(17, -28),     S(73, -39),     S(83, -41),     S(83, -30),     S(63, -10),     S(59, -15),     S(39, -8),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(61, 168),     S(152, 99),     S(75, 206),     S(19, 297),     S(56, 248),     S(58, 221),     S(82, 130),     S(7, 209),      //
    S(57, 197),     S(64, 301),     S(37, 319),     S(-92, 400),    S(-51, 391),    S(-2, 337),     S(47, 212),     S(25, 209),     //
    S(22, 244),     S(47, 301),     S(26, 348),     S(-17, 374),    S(-11, 383),    S(45, 291),     S(63, 220),     S(70, 135),     //
    S(42, 132),     S(44, 219),     S(-5, 300),     S(-17, 362),    S(-7, 383),     S(28, 260),     S(70, 179),     S(43, 155),     //
    S(45, 93),      S(30, 158),     S(8, 223),      S(-12, 285),    S(0, 317),      S(15, 267),     S(36, 177),     S(58, 97),      //
    S(39, 15),      S(53, 66),      S(49, 144),     S(32, 151),     S(35, 178),     S(38, 211),     S(54, 147),     S(47, 97),      //
    S(13, -103),    S(29, -48),     S(35, 4),       S(62, 33),      S(54, 82),      S(54, 61),      S(27, 99),      S(45, 68),      //
    S(-0, -98),     S(23, -226),    S(47, -212),    S(63, -110),    S(58, -7),      S(64, -57),     S(58, -22),     S(33, 8),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-66, -283),   S(270, 300),    S(150, 294),    S(-31, 204),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(198, 26),     S(263, 257),    S(100, 309),    S(1, 208),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(119, 137),    S(161, 237),    S(54, 280),     S(-28, 214),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-42, 76),     S(56, 164),     S(-86, 239),    S(-122, 248),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-108, -11),   S(-33, 75),     S(-121, 151),   S(-219, 221),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, -67),    S(36, -3),      S(-72, 86),     S(-138, 149),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(44, -128),    S(50, -53),     S(-29, 8),      S(-99, 66),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-2, -229),    S(24, -123),    S(-62, -72),    S(-58, -84),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-81, -494);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -7), S(15, -24), S(14, -2), S(6, -9), S(1, -26),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -9), S(6, -22), S(4, -11), S(4, -1), S(4, 5),
};

inline const PParam KS_FLANK_ATTACK = S(4, -8);
inline const PParam KS_FLANK_DEFENSE = S(-5, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -5);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -7);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, 25), S(-4, 28), S(-2, -46), S(9, -29), S(9, -21), S(-10, 14), S(-20, 15), }},
  {{ S(-1, 118), S(-19, -240), S(-19, -49), S(-8, 30), S(-8, 54), S(-21, 89), S(-35, 90), }},
  {{ S(-3, 100), S(-9, -209), S(-8, 91), S(-2, 69), S(-3, 63), S(-13, 70), S(-38, 79), }},
  {{ S(6, 110), S(-10, 74), S(0, 83), S(7, 67), S(3, 57), S(7, 73), S(1, 73), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(15, 105), S(-7, 68), S(-10, 88), S(-1, 100), S(15, 69),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, 131), S(-50, -351), S(-10, -280), S(9, -319), S(-5, 56), S(-9, 79), S(-8, 82), }},
  {{ S(10, 49), S(-28, -464), S(-8, -157), S(-2, -47), S(-2, 7), S(-8, 31), S(2, 26), }},
  {{ S(1, 71), S(-12, -314), S(5, -13), S(3, 2), S(-3, 34), S(-8, 57), S(-3, 50), }},
  {{ S(0, 64), S(-2, -95), S(8, -13), S(6, 26), S(-5, 42), S(-12, 53), S(-7, 54), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1048, 287, -16, 75
);

inline VParam WINNABLE_PAWNS = V(-24);
inline VParam WINNABLE_SYM = V(127);
inline VParam WINNABLE_ASYM = V(110);
inline VParam WINNABLE_PAWN_ENDGAME = V(194);
inline VParam WINNABLE_BIAS = V(-497);

// Epoch duration: 4.54512s
// clang-format on
}  // namespace Clockwork
