#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(205, 512);
inline const PParam KNIGHT_MAT = S(787, 1596);
inline const PParam BISHOP_MAT = S(848, 1671);
inline const PParam ROOK_MAT   = S(1021, 2652);
inline const PParam QUEEN_MAT  = S(2439, 4081);

inline const PParam TEMPO_VAL  = S(69, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 2);
inline const PParam BISHOP_PAIR_VAL   = S(58, 240);
inline const PParam ROOK_OPEN_VAL     = S(110, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 19);
inline const PParam MINOR_BEHIND_PAWN = S(14, 41);
inline const PParam RESTRICTED_SQUARES = S(19, 8);

inline const PParam DOUBLED_PAWN_VAL = S(-23, -84);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(47, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(37, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(35, 57);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 71);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -1), S(31, 35), S(59, 65), S(122, 214), S(398, 403), S(684, 834),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 34), S(39, 26), S(53, 57), S(91, 182), S(399, 122),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -269), S(-94, -224), S(-68, -89), S(-21, 37), S(87, 204), S(222, 420),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-99, 56), S(-104, 38), S(-73, 110), S(-101, 240), S(-57, 345), S(50, 223),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-31, 69), S(-37, 58), S(-67, 108), S(-33, 137), S(77, 160), S(35, 202),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -39), S(22, -1), S(14, 37), S(19, 109), S(67, 285), S(343, 233),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(11, -40), S(3, 5), S(-5, -29), S(-1, -72), S(-12, -182), S(-174, -462),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 240), S(9, 186), S(3, 109), S(11, 69), S(19, 73), S(58, 67), S(62, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-134, -47), S(15, -0), S(3, 104), S(30, 155), S(46, 190), S(56, 199), S(42, 178),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-33, -346), S(-2, -126), S(14, -36), S(29, 0), S(46, 31), S(54, 74), S(64, 96), S(75, 126), S(88, 96),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-79, -299), S(-28, -86), S(24, -14), S(48, 26), S(67, 54), S(78, 73), S(81, 85), S(82, 98), S(84, 104), S(86, 109), S(93, 102), S(105, 85), S(101, 89), S(84, 57),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(88, -180), S(15, 3), S(35, 33), S(51, 48), S(61, 61), S(65, 69), S(68, 79), S(74, 79), S(78, 88), S(82, 93), S(85, 97), S(83, 105), S(84, 109), S(88, 96), S(108, 57),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-190, -123), S(-43, -36), S(-19, 70), S(-5, 188), S(10, 216), S(16, 258), S(23, 287), S(29, 299), S(34, 318), S(37, 333), S(42, 340), S(47, 347), S(50, 353), S(52, 359), S(52, 363), S(51, 369), S(48, 369), S(51, 362), S(53, 358), S(58, 351), S(48, 343), S(60, 316), S(26, 346), S(-19, 336), S(-50, 333), S(-87, 358), S(-145, 385), S(-111, 321),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-26, -14), S(4, 1), S(15, 19), S(26, 24), S(33, 35), S(37, 48), S(42, 54), S(44, 54), S(47, 56), S(51, 53), S(55, 49), S(58, 47), S(59, 42), S(64, 32), S(69, 17), S(69, 6), S(76, -14), S(82, -33), S(89, -47), S(87, -67), S(59, -113),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(43, -32), S(42, -33), S(46, -22), S(50, -3), S(48, 11), S(49, 15), S(48, 25), S(47, 33), S(45, 41), S(46, 47), S(45, 54), S(48, 57), S(50, 62), S(56, 62), S(63, 63), S(71, 58), S(73, 60), S(50, 61),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(53, -11), S(51, 6), S(53, 15), S(57, 24), S(62, 25), S(66, 31), S(70, 36), S(73, 44), S(74, 55), S(77, 60), S(76, 71), S(78, 79), S(76, 90), S(77, 98), S(78, 102), S(75, 110), S(73, 119), S(70, 129), S(70, 130), S(75, 135),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(-16, 84), S(-20, 131), S(-11, 178), S(-5, 204), S(-0, 214), S(4, 231), S(5, 242), S(9, 256), S(9, 263), S(15, 261), S(14, 274), S(12, 289), S(17, 289), S(20, 290), S(24, 292), S(28, 292), S(32, 285), S(40, 285), S(49, 267), S(53, 274), S(80, 233), S(93, 217), S(118, 180),
};

inline const PParam PAWN_THREAT_KNIGHT = S(203, 162);
inline const PParam PAWN_THREAT_BISHOP = S(175, 219);
inline const PParam PAWN_THREAT_ROOK   = S(198, 152);
inline const PParam PAWN_THREAT_QUEEN  = S(166, 21);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(14, 56), S(101, 104), S(114, 115), S(185, 89), S(169, 10), }},
  {{ S(11, 57), S(90, 101), S(113, 112), S(226, 613), S(149, 59), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(12, 69), S(49, 114), S(60, 125), S(12, 20), S(152, -80), }},
  {{ S(5, 54), S(67, 87), S(98, 82), S(24, 19), S(372, 905), }},
}};
inline const PParam KING_THREAT  = S(-12, 157);
inline const PParam HANGING_PAWN  = S(33, 92);
inline const PParam HANGING_NON_PAWN  = S(75, 30);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(19, -13), S(8, 29),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(41, 51), S(96, -89),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 10), S(51, -12),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -16), S(3, -13), S(-2, -18), S(-7, -26), S(-13, -32), S(-18, -38), S(-20, -48), S(-26, -48), S(-32, -65),
};

inline const PParam ROOK_LINEUP = S(17, 83);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(184, 286),    S(58, 405),     S(60, 393),     S(149, 279),    S(184, 173),    S(136, 215),    S(116, 246),    S(223, 187),    //
    S(37, 65),      S(43, 113),     S(16, 64),      S(30, -3),      S(22, -41),     S(-4, -12),     S(-0, 33),      S(-26, 57),     //
    S(35, -10),     S(6, -1),       S(33, -42),     S(13, -67),     S(4, -85),      S(-8, -73),     S(-47, -39),    S(-42, -1),     //
    S(-3, -72),     S(-31, -40),    S(2, -62),      S(-9, -78),     S(-31, -87),    S(-36, -75),    S(-84, -54),    S(-75, -51),    //
    S(-12, -111),   S(20, -106),    S(8, -44),      S(-8, -49),     S(-36, -58),    S(-49, -70),    S(-78, -70),    S(-82, -73),    //
    S(13, -107),    S(89, -92),     S(79, -36),     S(34, -6),      S(5, -27),      S(-16, -56),    S(-45, -53),    S(-60, -55),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-278, -519),  S(-276, 38),    S(-280, -42),   S(-22, 44),     S(-121, 53),    S(-288, 80),    S(-372, 98),    S(-370, -420),  //
    S(-16, -25),    S(-15, 20),     S(67, 18),      S(53, 73),      S(56, 64),      S(28, 26),      S(-37, 19),     S(-62, 10),     //
    S(30, -33),     S(27, 21),      S(36, 44),      S(43, 82),      S(28, 76),      S(0, 35),       S(-9, 27),      S(-49, 4),      //
    S(79, 21),      S(78, 54),      S(82, 79),      S(73, 161),     S(76, 161),     S(50, 86),      S(33, 51),      S(18, 32),      //
    S(68, 12),      S(90, 13),      S(91, 56),      S(72, 136),     S(59, 135),     S(61, 72),      S(42, 33),      S(11, 24),      //
    S(21, -39),     S(60, -38),     S(72, -11),     S(74, 40),      S(70, 37),      S(50, -15),     S(27, -30),     S(-24, -43),    //
    S(42, -25),     S(49, -15),     S(47, -31),     S(56, 0),       S(52, 1),       S(27, -55),     S(-18, -1),     S(-46, -90),    //
    S(-45, -101),   S(10, -38),     S(31, -47),     S(40, -34),     S(25, -21),     S(-10, -49),    S(-23, -35),    S(-77, -152),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-150, 21),    S(-210, 98),    S(-423, 160),   S(-293, 89),    S(-321, 126),   S(-319, 137),   S(-240, 114),   S(-144, 62),    //
    S(-40, -24),    S(-82, 93),     S(-66, 60),     S(-89, 55),     S(-92, 77),     S(-62, 49),     S(-28, 48),     S(-66, 19),     //
    S(25, 11),      S(5, 57),       S(16, 71),      S(7, 59),       S(4, 45),       S(4, 50),       S(-7, 45),      S(-2, 8),       //
    S(7, -15),      S(42, 16),      S(48, 36),      S(67, 54),      S(89, 41),      S(25, 20),      S(34, -6),      S(-13, -12),    //
    S(28, -51),     S(39, -0),      S(73, 10),      S(86, 24),      S(69, 36),      S(59, 24),      S(11, 4),       S(0, -44),      //
    S(48, -30),     S(75, -20),     S(97, 6),       S(64, 27),      S(60, 15),      S(58, 17),      S(55, -2),      S(9, -27),      //
    S(20, -68),     S(111, -42),    S(70, -14),     S(54, 2),       S(38, 5),       S(50, -38),     S(45, -45),     S(32, -49),     //
    S(36, -73),     S(18, -28),     S(25, -17),     S(40, -37),     S(24, -21),     S(33, 10),      S(37, -21),     S(31, -65),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(166, 101),    S(191, 116),    S(145, 142),    S(126, 120),    S(184, 76),     S(141, 102),    S(146, 123),    S(134, 122),    //
    S(78, 143),     S(128, 145),    S(169, 114),    S(122, 101),    S(157, 87),     S(123, 114),    S(75, 148),     S(71, 150),     //
    S(50, 130),     S(167, 67),     S(187, 54),     S(159, 34),     S(160, 51),     S(100, 95),     S(96, 114),     S(45, 157),     //
    S(26, 96),      S(86, 99),      S(102, 76),     S(84, 73),      S(111, 55),     S(69, 98),      S(59, 115),     S(7, 145),      //
    S(2, 37),       S(58, 40),      S(50, 59),      S(18, 68),      S(26, 71),      S(12, 97),      S(-6, 97),      S(-25, 106),    //
    S(16, -41),     S(84, -26),     S(71, -5),      S(49, 7),       S(57, 13),      S(33, 37),      S(27, 23),      S(-12, 37),     //
    S(-65, -44),    S(58, -85),     S(67, -52),     S(55, -19),     S(59, -20),     S(42, -5),      S(30, -16),     S(-2, -8),      //
    S(-4, -45),     S(21, -21),     S(85, -36),     S(94, -33),     S(95, -25),     S(71, -3),      S(65, -10),     S(41, -1),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(76, 141),     S(135, 130),    S(43, 277),     S(-20, 381),    S(14, 333),     S(50, 244),     S(58, 152),     S(10, 189),     //
    S(50, 163),     S(66, 221),     S(19, 308),     S(-107, 432),   S(-61, 391),    S(1, 270),      S(47, 149),     S(31, 117),     //
    S(13, 211),     S(48, 241),     S(9, 330),      S(-35, 368),    S(-17, 357),    S(32, 242),     S(67, 135),     S(52, 92),      //
    S(9, 146),      S(15, 222),     S(-29, 292),    S(-32, 350),    S(-16, 341),    S(4, 222),      S(47, 130),     S(23, 93),      //
    S(7, 123),      S(2, 147),      S(-9, 198),     S(-33, 266),    S(-22, 280),    S(1, 212),      S(8, 146),      S(26, 52),      //
    S(3, 21),       S(33, 34),      S(30, 104),     S(6, 130),      S(18, 136),     S(25, 154),     S(41, 84),      S(15, 69),      //
    S(-21, -113),   S(12, -122),    S(17, -55),     S(44, -15),     S(44, 21),      S(44, 1),       S(18, 43),      S(25, 14),      //
    S(-44, -87),    S(-9, -260),    S(20, -269),    S(31, -151),    S(37, -67),     S(36, -83),     S(34, -70),     S(0, -21),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(177, -574),   S(485, 77),     S(317, 195),    S(21, 193),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(375, -188),   S(370, 193),    S(216, 205),    S(30, 159),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(207, 42),     S(241, 175),    S(121, 204),    S(-35, 176),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(43, 7),       S(121, 116),    S(-11, 174),    S(-108, 203),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-110, -2),    S(-14, 77),     S(-79, 148),    S(-175, 200),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-55, -31),    S(13, 35),      S(-65, 115),    S(-123, 161),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(22, -91),     S(31, -11),     S(-30, 50),     S(-102, 106),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-25, -214),   S(1, -92),      S(-76, -29),    S(-85, -42),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-77, -454);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -3), S(10, 13), S(10, 6), S(4, 2), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -18), S(-7, 6), S(-3, -9), S(6, -15), S(11, -28), S(6, -53), S(-5, -46), }},
  {{ S(2, 5), S(-21, 3), S(-17, 11), S(-10, 19), S(-7, 10), S(-10, -11), S(-19, -21), }},
  {{ S(-5, 0), S(-13, -8), S(-14, 18), S(-10, 19), S(-9, 11), S(-9, -16), S(-25, -37), }},
  {{ S(6, 10), S(-10, 18), S(-7, 39), S(-2, 44), S(-3, 40), S(2, 21), S(8, -12), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 24), S(-6, 3), S(-8, 10), S(-6, 29), S(2, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 12), S(-42, -114), S(-9, -38), S(-1, 6), S(-4, 4), S(-6, 11), S(-6, 10), }},
  {{ S(8, -0), S(-24, -121), S(-7, -30), S(-5, 2), S(-3, -2), S(-9, 4), S(0, 3), }},
  {{ S(-0, 11), S(-7, -72), S(7, -14), S(0, 9), S(-4, 11), S(-10, 18), S(-6, 21), }},
  {{ S(0, 1), S(4, -67), S(-1, 24), S(-3, 26), S(-6, 9), S(-12, 11), S(-9, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1422, 907, -24, -7
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(88);
inline VParam WINNABLE_PAWN_ENDGAME = V(76);
inline VParam WINNABLE_BIAS = V(-403);

// Epoch duration: 7.87035s
// clang-format on
}  // namespace Clockwork
