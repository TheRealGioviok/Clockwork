#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(202, 507);
inline const PParam KNIGHT_MAT = S(821, 1596);
inline const PParam BISHOP_MAT = S(872, 1682);
inline const PParam ROOK_MAT   = S(1041, 2670);
inline const PParam QUEEN_MAT  = S(2419, 4123);

inline const PParam TEMPO_VAL  = S(69, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-12, -3);
inline const PParam BISHOP_PAIR_VAL   = S(51, 236);
inline const PParam ROOK_OPEN_VAL     = S(94, -18);
inline const PParam ROOK_SEMIOPEN_VAL = S(36, 17);
inline const PParam MINOR_BEHIND_PAWN = S(8, 48);
inline const PParam RESTRICTED_SQUARES = S(15, 6);

inline const PParam DOUBLED_PAWN_VAL = S(-27, -88);
inline const PParam ISOLATED_PAWN_VAL = S(-24, -31);

inline const PParam POTENTIAL_CHECKER_VAL = S(-31, -44);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 39);
inline const PParam OUTPOST_BISHOP_VAL    = S(45, 50);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(35, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(35, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(20, 64);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(47, -47);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, 8), S(41, 39), S(59, 76), S(112, 231), S(387, 422), S(683, 834),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 50), S(39, 33), S(53, 53), S(90, 176), S(411, 155),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-108, -289), S(-105, -233), S(-65, -82), S(-4, 58), S(109, 247), S(239, 454),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-90, 44), S(-98, 29), S(-74, 107), S(-101, 268), S(-69, 419), S(66, 304),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-41, 62), S(-47, 54), S(-70, 108), S(-20, 149), S(104, 191), S(59, 222),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -60), S(18, -14), S(18, 24), S(16, 93), S(57, 255), S(334, 218),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -42), S(5, 7), S(-4, -27), S(2, -84), S(-13, -204), S(-167, -466),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 267), S(18, 195), S(13, 117), S(11, 84), S(17, 82), S(68, 78), S(61, 60),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-110, -22), S(23, -4), S(6, 119), S(28, 176), S(50, 216), S(60, 223), S(46, 202),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-76, -394), S(-22, -146), S(10, -25), S(29, 28), S(47, 64), S(59, 90), S(76, 107), S(90, 114), S(104, 87),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-30, -328), S(2, -121), S(35, -33), S(46, 12), S(65, 51), S(72, 73), S(76, 91), S(75, 107), S(79, 120), S(78, 126), S(91, 126), S(95, 118), S(114, 120), S(87, 105),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(92, -215), S(36, -22), S(47, 10), S(55, 31), S(61, 48), S(63, 60), S(66, 73), S(71, 82), S(75, 91), S(79, 94), S(82, 101), S(82, 112), S(85, 120), S(88, 104), S(113, 77),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-177, -201), S(-30, -83), S(4, 66), S(23, 197), S(33, 242), S(36, 296), S(40, 331), S(42, 345), S(45, 361), S(47, 376), S(49, 387), S(53, 393), S(55, 399), S(57, 402), S(59, 406), S(59, 408), S(58, 411), S(58, 405), S(63, 403), S(66, 397), S(60, 386), S(70, 366), S(36, 389), S(4, 389), S(-30, 388), S(-65, 414), S(-131, 434), S(-93, 376),
};

inline const PParam PAWN_THREAT_KNIGHT = S(159, 140);
inline const PParam PAWN_THREAT_BISHOP = S(138, 220);
inline const PParam PAWN_THREAT_ROOK   = S(166, 128);
inline const PParam PAWN_THREAT_QUEEN  = S(149, 13);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(6, 49), S(71, 85), S(81, 109), S(145, 67), S(141, 4), }},
  {{ S(7, 77), S(63, 101), S(75, 106), S(173, 567), S(158, 55), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(6, 51), S(26, 92), S(36, 104), S(21, 29), S(158, -58), }},
  {{ S(14, 71), S(52, 94), S(76, 88), S(25, 19), S(340, 888), }},
}};
inline const PParam KING_THREAT  = S(5, 153);
inline const PParam HANGING_PAWN  = S(33, 101);
inline const PParam HANGING_NON_PAWN  = S(53, 25);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(20, -6), S(30, 13),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(28, 46), S(115, -105),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(28, 9), S(52, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(2, -20), S(2, -16), S(0, -24), S(-4, -40), S(-7, -49), S(-11, -51), S(-16, -64), S(-20, -62), S(-22, -69),
};

inline const PParam ROOK_LINEUP = S(13, 77);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(185, 309),    S(75, 441),     S(87, 418),     S(159, 270),    S(182, 161),    S(147, 215),    S(126, 251),    S(219, 184),    //
    S(46, 90),      S(69, 149),     S(48, 96),      S(63, 14),      S(48, -35),     S(21, -2),      S(18, 45),      S(-13, 63),     //
    S(36, -1),      S(21, 13),      S(51, -18),     S(35, -66),     S(19, -83),     S(9, -66),      S(-29, -35),    S(-31, -0),     //
    S(2, -61),      S(-13, -25),    S(13, -46),     S(3, -68),      S(-16, -86),    S(-30, -74),    S(-68, -50),    S(-61, -49),    //
    S(-13, -94),    S(26, -91),     S(7, -36),      S(-8, -47),     S(-40, -58),    S(-49, -76),    S(-75, -69),    S(-82, -73),    //
    S(24, -98),     S(80, -78),     S(71, -37),     S(13, -22),     S(-0, -50),     S(-23, -57),    S(-48, -53),    S(-63, -49),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-246, -481),  S(-244, 67),    S(-235, 3),     S(17, 55),      S(-71, 56),     S(-250, 90),    S(-338, 104),   S(-331, -382),  //
    S(16, -4),      S(9, 40),       S(78, 25),      S(87, 75),      S(93, 56),      S(54, 29),      S(-4, 34),      S(-18, 24),     //
    S(46, -7),      S(34, 40),      S(50, 64),      S(76, 80),      S(51, 71),      S(28, 63),      S(7, 27),       S(-18, 17),     //
    S(88, 30),      S(78, 51),      S(78, 74),      S(78, 111),     S(83, 105),     S(65, 64),      S(57, 29),      S(45, 29),      //
    S(75, 24),      S(87, 14),      S(84, 58),      S(69, 78),      S(60, 78),      S(69, 58),      S(58, 13),      S(46, 18),      //
    S(18, -27),     S(43, -11),     S(40, 17),      S(62, 55),      S(57, 55),      S(26, 7),       S(20, -20),     S(-5, -47),     //
    S(33, -27),     S(44, -1),      S(20, -11),     S(29, 6),       S(24, 3),       S(13, -53),     S(-17, -11),    S(-35, -85),    //
    S(-39, -85),    S(6, -41),      S(35, -33),     S(45, -29),     S(31, -24),     S(-7, -55),     S(-6, -48),     S(-66, -143),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-127, 20),    S(-186, 90),    S(-383, 159),   S(-256, 98),    S(-289, 135),   S(-299, 146),   S(-210, 127),   S(-128, 73),    //
    S(-39, -25),    S(-76, 77),     S(-37, 52),     S(-56, 57),     S(-58, 65),     S(-29, 49),     S(-26, 36),     S(-44, 23),     //
    S(24, 2),       S(22, 55),      S(16, 58),      S(27, 55),      S(22, 36),      S(16, 36),      S(14, 36),      S(12, -1),      //
    S(13, -11),     S(37, 9),       S(52, 35),      S(57, 50),      S(81, 35),      S(43, 17),      S(42, -4),      S(-1, -10),     //
    S(38, -47),     S(39, 3),       S(61, 11),      S(70, 24),      S(64, 35),      S(54, 21),      S(17, -3),      S(14, -40),     //
    S(47, -32),     S(67, -28),     S(80, 5),       S(56, 20),      S(52, 16),      S(55, 13),      S(60, -19),     S(11, -31),     //
    S(44, -78),     S(93, -48),     S(73, -21),     S(41, -7),      S(27, -3),      S(50, -50),     S(42, -63),     S(45, -62),     //
    S(41, -67),     S(19, -32),     S(24, -13),     S(40, -36),     S(18, -26),     S(25, -13),     S(37, -42),     S(36, -58),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(173, 108),    S(198, 127),    S(152, 152),    S(132, 131),    S(188, 87),     S(150, 108),    S(157, 125),    S(136, 132),    //
    S(100, 139),    S(138, 138),    S(174, 111),    S(134, 107),    S(169, 91),     S(137, 116),    S(93, 144),     S(90, 153),     //
    S(62, 131),     S(177, 81),     S(190, 65),     S(169, 59),     S(162, 63),     S(117, 102),    S(110, 120),    S(68, 160),     //
    S(35, 108),     S(94, 116),     S(108, 95),     S(83, 92),      S(117, 81),     S(84, 111),     S(73, 135),     S(35, 154),     //
    S(4, 49),       S(65, 64),      S(57, 80),      S(26, 84),      S(36, 86),      S(32, 109),     S(12, 112),     S(2, 122),      //
    S(19, -28),     S(73, -11),     S(70, 22),      S(43, 19),      S(48, 30),      S(31, 47),      S(27, 51),      S(0, 58),       //
    S(-57, -45),    S(62, -76),     S(61, -32),     S(45, -14),     S(51, -17),     S(40, 1),       S(30, -21),     S(3, -8),       //
    S(23, -77),     S(19, -40),     S(69, -49),     S(78, -52),     S(75, -37),     S(62, -25),     S(58, -39),     S(53, -39),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(102, 165),    S(146, 158),    S(50, 299),     S(-13, 383),    S(24, 343),     S(66, 258),     S(73, 179),     S(28, 209),     //
    S(76, 191),     S(63, 233),     S(34, 315),     S(-75, 436),    S(-32, 399),    S(22, 282),     S(41, 169),     S(37, 145),     //
    S(21, 234),     S(53, 259),     S(24, 337),     S(-11, 365),    S(10, 354),     S(51, 253),     S(76, 150),     S(55, 110),     //
    S(22, 175),     S(24, 240),     S(-2, 311),     S(-10, 357),    S(7, 344),      S(25, 233),     S(57, 151),     S(38, 106),     //
    S(14, 149),     S(14, 172),     S(1, 220),      S(-20, 283),    S(-7, 302),     S(18, 231),     S(21, 171),     S(36, 80),      //
    S(14, 57),      S(32, 64),      S(30, 146),     S(11, 157),     S(25, 161),     S(21, 177),     S(40, 107),     S(23, 93),      //
    S(-14, -92),    S(18, -85),     S(25, -18),     S(33, 19),      S(36, 51),      S(38, 26),      S(15, 59),      S(18, 30),      //
    S(-37, -79),    S(-13, -236),   S(15, -244),    S(27, -115),    S(26, -47),     S(30, -68),     S(31, -62),     S(6, -11),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(170, -549),   S(445, 72),     S(299, 173),    S(30, 179),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(363, -170),   S(347, 200),    S(217, 223),    S(53, 186),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(201, 52),     S(229, 203),    S(123, 226),    S(-18, 216),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(55, 28),      S(116, 129),    S(-1, 189),     S(-97, 201),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-89, 3),      S(-4, 74),      S(-66, 141),    S(-158, 176),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-41, -32),    S(10, 35),      S(-62, 98),     S(-116, 129),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(3, -84),      S(14, -6),      S(-51, 41),     S(-112, 81),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-47, -204),   S(-11, -91),    S(-78, -40),    S(-65, -60),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-120, -449);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(6, -1), S(8, 15), S(8, 4), S(3, 0), S(2, -8),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 0), S(3, -0), S(3, -2),
};

inline const PParam KS_FLANK_ATTACK = S(2, -1);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(14, -21), S(-11, 0), S(-6, -12), S(5, -17), S(11, -27), S(4, -51), S(-3, -49), }},
  {{ S(4, 5), S(-25, -0), S(-16, 11), S(-9, 21), S(-5, 6), S(-6, -14), S(-23, -28), }},
  {{ S(-4, 0), S(-16, -10), S(-12, 21), S(-9, 16), S(-6, 11), S(-6, -20), S(-28, -44), }},
  {{ S(5, 7), S(-13, 23), S(-10, 43), S(-4, 52), S(-2, 33), S(7, 16), S(4, -20), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(7, 25), S(-7, 2), S(-10, 14), S(-11, 38), S(1, 49),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 17), S(-45, -123), S(-7, -42), S(2, 6), S(-1, 3), S(-3, 9), S(-5, 7), }},
  {{ S(8, -4), S(-28, -126), S(-11, -39), S(-3, -6), S(0, -5), S(-12, 5), S(-1, 5), }},
  {{ S(-2, 11), S(-10, -76), S(3, -19), S(1, 3), S(-4, 8), S(-12, 21), S(-10, 24), }},
  {{ S(-0, -4), S(4, -60), S(4, 21), S(-3, 28), S(-6, 15), S(-19, 19), S(-18, 27), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1409, 924, -25, -7
);

inline VParam WINNABLE_PAWNS = V(-31);
inline VParam WINNABLE_SYM = V(94);
inline VParam WINNABLE_ASYM = V(85);
inline VParam WINNABLE_PAWN_ENDGAME = V(147);
inline VParam WINNABLE_BIAS = V(-339);

// clang-format on
}  // namespace Clockwork
