#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(197, 499);
inline const PParam KNIGHT_MAT = S(824, 1540);
inline const PParam BISHOP_MAT = S(864, 1621);
inline const PParam ROOK_MAT   = S(1032, 2551);
inline const PParam QUEEN_MAT  = S(2449, 3882);

inline const PParam TEMPO_VAL  = S(69, 51);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -4);
inline const PParam BISHOP_PAIR_VAL   = S(64, 231);
inline const PParam ROOK_OPEN_VAL     = S(111, -6);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 39);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(41, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 48);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -2), S(33, 35), S(61, 65), S(121, 212), S(386, 387), S(618, 744),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 33), S(38, 25), S(56, 55), S(97, 177), S(411, 104),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -253), S(-95, -213), S(-69, -84), S(-22, 38), S(86, 198), S(217, 403),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-85, 50), S(-91, 34), S(-59, 107), S(-91, 229), S(-53, 331), S(54, 208),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-20, 71), S(-36, 62), S(-55, 103), S(-29, 132), S(74, 156), S(39, 177),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -40), S(25, -4), S(16, 35), S(21, 105), S(68, 276), S(327, 222),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -36), S(2, 6), S(-3, -29), S(-2, -65), S(-12, -175), S(-161, -440),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(18, 231), S(7, 179), S(3, 103), S(11, 64), S(22, 67), S(63, 62), S(60, 33),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-138, -41), S(20, -2), S(6, 97), S(32, 145), S(45, 180), S(56, 189), S(41, 171),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-88, -372), S(-27, -133), S(2, -15), S(26, 31), S(54, 62), S(69, 98), S(86, 105), S(106, 113), S(125, 66),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-51, -272), S(-10, -98), S(38, -27), S(60, 23), S(79, 61), S(87, 89), S(91, 110), S(93, 129), S(96, 139), S(101, 144), S(109, 138), S(127, 118), S(135, 112), S(114, 88),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(107, -179), S(24, 12), S(45, 43), S(61, 60), S(71, 78), S(75, 92), S(79, 107), S(85, 112), S(90, 125), S(95, 131), S(100, 137), S(101, 146), S(104, 150), S(107, 139), S(132, 93),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-204, -163), S(-51, 5), S(-27, 132), S(-5, 256), S(12, 296), S(18, 348), S(25, 382), S(31, 397), S(35, 421), S(38, 439), S(44, 447), S(48, 454), S(51, 460), S(53, 466), S(54, 468), S(53, 472), S(49, 472), S(54, 463), S(54, 461), S(59, 450), S(56, 433), S(61, 412), S(32, 435), S(-16, 427), S(-42, 423), S(-74, 443), S(-119, 452), S(-90, 393),
};

inline const PParam PAWN_THREAT_KNIGHT = S(193, 149);
inline const PParam PAWN_THREAT_BISHOP = S(169, 213);
inline const PParam PAWN_THREAT_ROOK   = S(189, 152);
inline const PParam PAWN_THREAT_QUEEN  = S(154, 19);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(5, 54), S(86, 92), S(102, 124), S(201, 125), S(158, 12), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 55), S(52, 92), S(73, 90), S(16, 12), S(148, -50), S(0, 0),
};
inline const PParam KING_THREAT  = S(-19, 155);
inline const PParam HANGING_PAWN  = S(31, 90);
inline const PParam HANGING_NON_PAWN  = S(68, 27);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -18), S(30, -7),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(39, 48), S(121, -119),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(36, 11), S(50, -8),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -15), S(4, -14), S(0, -20), S(-5, -28), S(-11, -35), S(-16, -42), S(-18, -54), S(-24, -57), S(-28, -72),
};

inline const PParam BISHOP_LONG_DIAG = S(42, 42);

inline const PParam ROOK_LINEUP = S(16, 78);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(181, 264),    S(37, 394),     S(71, 369),     S(144, 261),    S(198, 153),    S(134, 210),    S(97, 246),     S(235, 170),    //
    S(42, 58),      S(53, 105),     S(27, 58),      S(42, -11),     S(33, -43),     S(8, -17),      S(10, 25),      S(-18, 52),     //
    S(37, -14),     S(12, -4),      S(41, -47),     S(20, -68),     S(10, -86),     S(-0, -75),     S(-38, -41),    S(-39, -2),     //
    S(-7, -71),     S(-30, -41),    S(2, -62),      S(0, -74),      S(-23, -84),    S(-38, -73),    S(-84, -53),    S(-77, -51),    //
    S(-12, -108),   S(22, -106),    S(10, -46),     S(-10, -51),    S(-37, -60),    S(-49, -71),    S(-80, -69),    S(-82, -73),    //
    S(11, -106),    S(84, -95),     S(69, -41),     S(25, -15),     S(-8, -35),     S(-24, -61),    S(-49, -57),    S(-62, -56),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-256, -497),  S(-250, 52),    S(-271, -68),   S(27, 24),      S(-95, 44),     S(-266, 81),    S(-364, 113),   S(-348, -388),  //
    S(-6, -7),      S(-1, 35),      S(92, 28),      S(80, 57),      S(86, 49),      S(54, 24),      S(-28, 30),     S(-32, 20),     //
    S(48, -27),     S(36, 32),      S(66, 55),      S(71, 75),      S(59, 72),      S(19, 59),      S(7, 36),       S(-41, 18),     //
    S(94, 25),      S(89, 51),      S(101, 68),     S(93, 113),     S(98, 114),     S(69, 76),      S(49, 43),      S(37, 35),      //
    S(76, 18),      S(102, 9),      S(97, 52),      S(95, 83),      S(81, 84),      S(72, 66),      S(61, 12),      S(22, 32),      //
    S(17, -36),     S(45, -17),     S(52, 22),      S(61, 57),      S(56, 54),      S(32, 17),      S(15, -8),      S(-25, -33),    //
    S(39, -23),     S(42, -10),     S(27, -14),     S(33, 14),      S(31, 10),      S(5, -40),      S(-30, 1),      S(-42, -78),    //
    S(-42, -75),    S(7, -22),      S(28, -42),     S(45, -28),     S(24, -9),      S(-11, -47),    S(-20, -22),    S(-63, -131),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-151, -10),   S(-171, 111),   S(-417, 194),   S(-253, 97),    S(-290, 154),   S(-292, 159),   S(-206, 133),   S(-148, 38),    //
    S(-23, -11),    S(-101, 65),    S(-26, 63),     S(-56, 75),     S(-59, 86),     S(-27, 56),     S(-35, 14),     S(-40, 31),     //
    S(42, 30),      S(25, 72),      S(16, 47),      S(39, 72),      S(33, 60),      S(-3, 30),      S(22, 56),      S(20, 25),      //
    S(20, 10),      S(60, 35),      S(75, 51),      S(83, 72),      S(110, 57),     S(55, 35),      S(57, 10),      S(6, 9),        //
    S(47, -35),     S(53, 18),      S(86, 28),      S(104, 40),     S(88, 53),      S(75, 39),      S(28, 20),      S(24, -26),     //
    S(64, -19),     S(88, -14),     S(77, -21),     S(71, 46),      S(70, 28),      S(39, -8),      S(69, 7),       S(23, -8),      //
    S(33, -70),     S(102, -69),    S(75, -6),      S(52, 13),      S(34, 14),      S(57, -32),     S(37, -71),     S(45, -43),     //
    S(34, -95),     S(22, -6),      S(25, 4),       S(47, -21),     S(31, -11),     S(36, 24),      S(47, -9),      S(24, -77),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(176, 121),    S(203, 140),    S(148, 167),    S(138, 142),    S(203, 93),     S(167, 117),    S(172, 135),    S(149, 138),    //
    S(84, 169),     S(137, 168),    S(197, 128),    S(143, 125),    S(184, 107),    S(144, 134),    S(93, 168),     S(89, 168),     //
    S(54, 159),     S(174, 103),    S(201, 82),     S(180, 63),     S(177, 86),     S(117, 127),    S(119, 135),    S(63, 180),     //
    S(32, 121),     S(92, 126),     S(121, 96),     S(91, 103),     S(120, 88),     S(85, 129),     S(76, 142),     S(19, 168),     //
    S(1, 57),       S(66, 64),      S(59, 80),      S(33, 89),      S(40, 95),      S(26, 122),     S(9, 120),      S(-12, 123),    //
    S(18, -28),     S(84, -0),      S(77, 21),      S(54, 31),      S(64, 38),      S(39, 65),      S(38, 50),      S(-3, 53),      //
    S(-62, -31),    S(66, -67),     S(71, -31),     S(58, 3),       S(63, -0),      S(46, 18),      S(36, 0),       S(8, 2),        //
    S(-2, -53),     S(14, -14),     S(85, -31),     S(95, -33),     S(94, -26),     S(72, -1),      S(69, -12),     S(50, -7),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(72, 181),     S(146, 163),    S(58, 300),     S(-5, 404),     S(39, 348),     S(71, 260),     S(63, 190),     S(0, 240),      //
    S(56, 203),     S(75, 253),     S(45, 317),     S(-89, 449),    S(-41, 415),    S(6, 316),      S(49, 190),     S(23, 181),     //
    S(17, 248),     S(52, 288),     S(19, 360),     S(-18, 397),    S(4, 377),      S(47, 269),     S(78, 172),     S(59, 123),     //
    S(17, 180),     S(20, 261),     S(-12, 314),    S(-26, 381),    S(-12, 385),    S(20, 251),     S(56, 166),     S(27, 138),     //
    S(10, 167),     S(8, 187),      S(-2, 236),     S(-25, 306),    S(-14, 324),    S(6, 254),      S(9, 189),      S(33, 97),      //
    S(4, 69),       S(33, 81),      S(30, 156),     S(7, 176),      S(15, 183),     S(18, 206),     S(36, 137),     S(17, 110),     //
    S(-25, -74),    S(5, -70),      S(11, -0),      S(34, 41),      S(30, 79),      S(32, 53),      S(6, 85),       S(20, 56),      //
    S(-37, -57),    S(-20, -205),   S(11, -210),    S(24, -95),     S(32, -20),     S(30, -53),     S(28, -32),     S(-1, 16),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(106, -511),   S(449, 84),     S(281, 216),    S(-21, 200),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(334, -165),   S(343, 197),    S(190, 212),    S(7, 162),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(184, 49),     S(214, 182),    S(110, 205),    S(-50, 183),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(13, 17),      S(87, 125),     S(-27, 175),    S(-112, 199),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-121, 2),     S(-36, 81),     S(-101, 150),   S(-185, 200),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-51, -38),    S(13, 29),      S(-75, 113),    S(-133, 161),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(26, -96),     S(32, -17),     S(-34, 47),     S(-112, 103),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, -213),   S(7, -94),      S(-76, -27),    S(-74, -49),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-85, -436);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 4), S(5, 1), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 4), S(2, 2), S(3, -0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -20), S(-6, 5), S(-2, -9), S(9, -16), S(13, -28), S(8, -57), S(-4, -49), }},
  {{ S(3, 2), S(-21, 0), S(-16, 8), S(-9, 17), S(-6, 7), S(-9, -14), S(-21, -22), }},
  {{ S(-3, -2), S(-12, -11), S(-13, 18), S(-8, 17), S(-7, 9), S(-8, -19), S(-24, -43), }},
  {{ S(7, 9), S(-9, 19), S(-6, 41), S(-1, 44), S(-1, 40), S(5, 18), S(9, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 23), S(-5, 1), S(-8, 10), S(-6, 28), S(1, 51),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 10), S(-44, -128), S(-9, -43), S(-0, 3), S(-2, 3), S(-6, 10), S(-5, 8), }},
  {{ S(9, -1), S(-24, -125), S(-6, -32), S(-4, -1), S(-1, -3), S(-8, 3), S(1, 2), }},
  {{ S(-0, 10), S(-10, -81), S(8, -19), S(0, 7), S(-3, 10), S(-10, 18), S(-6, 20), }},
  {{ S(1, -2), S(5, -65), S(-1, 26), S(-2, 24), S(-6, 8), S(-13, 11), S(-10, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1353, 847, -21, -2
);

inline VParam WINNABLE_PAWNS = V(-19);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(84);
inline VParam WINNABLE_PAWN_ENDGAME = V(89);
inline VParam WINNABLE_BIAS = V(-388);

// Epoch duration: 5.9791s
// clang-format on
}  // namespace Clockwork
