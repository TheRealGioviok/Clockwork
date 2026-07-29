#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(201, 508);
inline const PParam KNIGHT_MAT = S(810, 1596);
inline const PParam BISHOP_MAT = S(866, 1677);
inline const PParam ROOK_MAT   = S(1041, 2672);
inline const PParam QUEEN_MAT  = S(2419, 4122);

inline const PParam TEMPO_VAL  = S(70, 54);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(61, 242);
inline const PParam ROOK_OPEN_VAL     = S(109, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -42);
inline const PParam OUTPOST_KNIGHT_UNDEFENDED_VAL    = S(32, -26);
inline const PParam OUTPOST_BISHOP_UNDEFENDED_VAL    = S(36, 15);
inline const PParam OUTPOST_KNIGHT_DEFENDED_VAL    = S(31, 59);
inline const PParam OUTPOST_BISHOP_DEFENDED_VAL    = S(21, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(34, 54);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(35, -6);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -1), S(33, 36), S(59, 66), S(121, 214), S(390, 404), S(675, 819),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 33), S(39, 26), S(53, 57), S(90, 182), S(388, 121),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-94, -260), S(-95, -219), S(-66, -87), S(-22, 39), S(86, 201), S(229, 406),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-80, 53), S(-93, 36), S(-60, 106), S(-90, 230), S(-55, 341), S(51, 223),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-16, 68), S(-28, 59), S(-61, 108), S(-34, 136), S(72, 160), S(34, 194),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -39), S(23, -1), S(15, 35), S(19, 105), S(69, 273), S(334, 219),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -37), S(-3, 10), S(-4, -26), S(-2, -68), S(-15, -176), S(-168, -453),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 235), S(9, 182), S(4, 106), S(11, 67), S(20, 72), S(58, 67), S(62, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-131, -48), S(15, -3), S(2, 99), S(29, 150), S(44, 185), S(55, 193), S(41, 174),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-90, -394), S(-22, -141), S(8, -25), S(31, 24), S(58, 57), S(73, 94), S(91, 102), S(109, 112), S(129, 65),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-73, -353), S(-19, -131), S(33, -41), S(57, 13), S(77, 56), S(89, 87), S(93, 109), S(95, 130), S(99, 141), S(105, 146), S(112, 139), S(124, 122), S(123, 126), S(103, 89),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -216), S(23, -13), S(45, 21), S(60, 40), S(71, 58), S(75, 72), S(80, 88), S(86, 94), S(90, 107), S(95, 114), S(99, 121), S(100, 130), S(103, 135), S(109, 121), S(128, 83),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-194, -207), S(-38, -96), S(-13, 47), S(5, 188), S(22, 231), S(30, 285), S(37, 323), S(43, 341), S(48, 364), S(52, 381), S(57, 389), S(62, 396), S(65, 403), S(67, 408), S(68, 410), S(68, 414), S(64, 416), S(67, 408), S(67, 404), S(72, 396), S(62, 387), S(74, 359), S(39, 388), S(-7, 380), S(-41, 380), S(-74, 400), S(-134, 429), S(-99, 364),
};

inline const PParam PAWN_THREAT_KNIGHT = S(189, 162);
inline const PParam PAWN_THREAT_BISHOP = S(161, 211);
inline const PParam PAWN_THREAT_ROOK   = S(188, 155);
inline const PParam PAWN_THREAT_QUEEN  = S(159, 13);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(8, 56), S(93, 95), S(103, 125), S(204, 125), S(163, 3), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(8, 57), S(55, 95), S(75, 96), S(17, 11), S(151, -49), S(0, 0),
};
inline const PParam KING_THREAT  = S(-9, 157);
inline const PParam HANGING_PAWN  = S(32, 93);
inline const PParam HANGING_NON_PAWN  = S(70, 28);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -18), S(21, 9),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 46), S(110, -108),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 12), S(47, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -15), S(-1, -22), S(-7, -29), S(-13, -37), S(-18, -43), S(-20, -55), S(-25, -56), S(-31, -74),
};

inline const PParam ROOK_LINEUP = S(17, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(184, 276),    S(62, 397),     S(69, 385),     S(157, 269),    S(190, 169),    S(143, 211),    S(121, 241),    S(222, 180),    //
    S(43, 62),      S(58, 108),     S(37, 60),      S(50, -7),      S(42, -43),     S(15, -15),     S(16, 26),      S(-19, 53),     //
    S(40, -14),     S(18, -6),      S(47, -46),     S(29, -70),     S(20, -89),     S(6, -76),      S(-33, -45),    S(-36, -6),     //
    S(-5, -74),     S(-28, -44),    S(4, -63),      S(-7, -79),     S(-28, -88),    S(-34, -76),    S(-80, -58),    S(-75, -53),    //
    S(-12, -112),   S(20, -108),    S(5, -45),      S(-12, -51),    S(-38, -61),    S(-52, -71),    S(-79, -73),    S(-82, -75),    //
    S(10, -108),    S(83, -95),     S(72, -41),     S(25, -12),     S(-5, -33),     S(-24, -60),    S(-50, -60),    S(-62, -58),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-256, -505),  S(-252, 46),    S(-258, -34),   S(6, 38),       S(-85, 38),     S(-261, 78),    S(-340, 95),    S(-343, -408),  //
    S(4, -15),      S(8, 25),       S(95, 19),      S(90, 56),      S(96, 43),      S(58, 24),      S(-10, 22),     S(-38, 18),     //
    S(17, -4),      S(24, 44),      S(40, 75),      S(56, 85),      S(39, 87),      S(4, 71),       S(-9, 49),      S(-57, 28),     //
    S(76, 34),      S(86, 52),      S(94, 75),      S(99, 114),     S(101, 115),    S(65, 79),      S(45, 44),      S(18, 44),      //
    S(73, 20),      S(100, 6),      S(98, 51),      S(93, 82),      S(78, 86),      S(71, 66),      S(55, 22),      S(17, 31),      //
    S(24, -45),     S(48, -28),     S(56, 16),      S(68, 48),      S(64, 46),      S(37, 10),      S(19, -21),     S(-19, -44),    //
    S(42, -28),     S(45, -15),     S(33, -23),     S(43, 5),       S(40, 3),       S(11, -48),     S(-25, -4),     S(-44, -86),    //
    S(-39, -95),    S(15, -32),     S(34, -47),     S(50, -36),     S(34, -22),     S(-4, -54),     S(-15, -30),    S(-66, -144),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-123, 24),    S(-184, 105),   S(-395, 171),   S(-265, 102),   S(-295, 143),   S(-295, 153),   S(-218, 130),   S(-122, 75),    //
    S(-20, -18),    S(-57, 91),     S(-39, 67),     S(-59, 62),     S(-59, 79),     S(-31, 51),     S(-2, 45),      S(-45, 27),     //
    S(7, 6),        S(-7, 48),      S(10, 59),      S(7, 43),       S(1, 33),       S(-0, 37),      S(-14, 33),     S(-16, 0),      //
    S(-1, -20),     S(44, 8),       S(50, 24),      S(71, 45),      S(93, 31),      S(30, 9),       S(37, -17),     S(-21, -16),    //
    S(30, -59),     S(44, -7),      S(77, 6),       S(90, 20),      S(72, 31),      S(64, 17),      S(17, -4),      S(-2, -50),     //
    S(62, -26),     S(85, -21),     S(101, 9),      S(69, 32),      S(65, 18),      S(62, 18),      S(63, -0),      S(22, -19),     //
    S(32, -70),     S(119, -53),    S(72, -15),     S(53, 2),       S(36, 1),       S(51, -40),     S(51, -55),     S(44, -46),     //
    S(49, -69),     S(29, -22),     S(35, -6),      S(49, -28),     S(34, -16),     S(43, 18),      S(49, -13),     S(45, -57),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(175, 106),    S(202, 128),    S(156, 157),    S(142, 129),    S(202, 83),     S(160, 111),    S(169, 126),    S(152, 124),    //
    S(87, 149),     S(145, 152),    S(187, 125),    S(141, 111),    S(178, 97),     S(145, 123),    S(98, 154),     S(89, 155),     //
    S(57, 143),     S(178, 85),     S(203, 69),     S(174, 56),     S(178, 72),     S(120, 113),    S(114, 129),    S(62, 169),     //
    S(30, 110),     S(93, 117),     S(112, 92),     S(95, 93),      S(122, 76),     S(83, 117),     S(75, 131),     S(20, 156),     //
    S(6, 42),       S(63, 53),      S(56, 75),      S(25, 84),      S(35, 88),      S(24, 113),     S(7, 111),      S(-14, 115),    //
    S(18, -38),     S(85, -12),     S(72, 14),      S(50, 26),      S(60, 33),      S(37, 56),      S(34, 40),      S(-5, 47),      //
    S(-62, -43),    S(62, -79),     S(68, -41),     S(56, -8),      S(60, -7),      S(45, 7),       S(36, -9),      S(5, -6),       //
    S(1, -65),      S(24, -34),     S(87, -44),     S(95, -45),     S(98, -40),     S(74, -17),     S(69, -24),     S(48, -19),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(89, 154),     S(146, 155),    S(56, 297),     S(-3, 396),     S(34, 349),     S(71, 256),     S(72, 174),     S(26, 206),     //
    S(58, 183),     S(78, 237),     S(37, 320),     S(-82, 437),    S(-42, 409),    S(18, 288),     S(58, 174),     S(40, 145),     //
    S(20, 234),     S(59, 261),     S(28, 338),     S(-9, 372),     S(10, 360),     S(49, 258),     S(81, 154),     S(63, 118),     //
    S(16, 170),     S(28, 237),     S(-14, 306),    S(-13, 359),    S(4, 352),      S(21, 236),     S(59, 155),     S(34, 117),     //
    S(13, 144),     S(10, 167),     S(2, 216),      S(-23, 286),    S(-12, 301),    S(10, 235),     S(15, 174),     S(36, 80),      //
    S(3, 50),       S(34, 58),      S(31, 134),     S(9, 155),      S(19, 163),     S(21, 185),     S(41, 114),     S(21, 94),      //
    S(-24, -96),    S(4, -95),      S(13, -26),     S(40, 13),      S(36, 52),      S(39, 24),      S(12, 63),      S(25, 35),      //
    S(-42, -80),    S(-10, -242),   S(21, -247),    S(33, -135),    S(40, -56),     S(38, -75),     S(36, -62),     S(5, -7),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(165, -556),   S(475, 82),     S(314, 193),    S(19, 190),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(366, -184),   S(362, 189),    S(209, 203),    S(25, 155),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(196, 44),     S(229, 174),    S(112, 198),    S(-51, 178),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(36, 7),       S(111, 113),    S(-24, 171),    S(-121, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-114, -3),    S(-24, 77),     S(-87, 146),    S(-183, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-55, -35),    S(11, 32),      S(-69, 114),    S(-125, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -94),     S(30, -14),     S(-33, 49),     S(-107, 105),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -212),   S(4, -93),      S(-74, -29),    S(-82, -42),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -447);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 2), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -18), S(-7, 5), S(-4, -9), S(6, -15), S(11, -28), S(6, -53), S(-5, -45), }},
  {{ S(1, 4), S(-21, 2), S(-17, 10), S(-11, 18), S(-7, 9), S(-10, -12), S(-20, -20), }},
  {{ S(-4, 0), S(-12, -7), S(-13, 18), S(-9, 20), S(-8, 11), S(-7, -15), S(-23, -36), }},
  {{ S(5, 8), S(-11, 17), S(-8, 38), S(-3, 42), S(-3, 38), S(3, 19), S(9, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 22), S(-6, 2), S(-7, 9), S(-6, 27), S(1, 47),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 10), S(-41, -119), S(-9, -39), S(-1, 3), S(-3, 3), S(-6, 10), S(-5, 9), }},
  {{ S(8, -2), S(-25, -123), S(-6, -30), S(-4, -0), S(-2, -4), S(-9, 3), S(1, 2), }},
  {{ S(-0, 10), S(-8, -70), S(7, -15), S(-0, 8), S(-4, 10), S(-9, 18), S(-6, 20), }},
  {{ S(0, 0), S(2, -62), S(-1, 24), S(-3, 25), S(-6, 8), S(-12, 10), S(-9, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1427, 916, -20, -2
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(75);
inline VParam WINNABLE_BIAS = V(-389);

// Epoch duration: 7.10899s
// clang-format on
}  // namespace Clockwork
