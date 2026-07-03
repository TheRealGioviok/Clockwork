#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(202, 499);
inline const PParam KNIGHT_MAT = S(848, 1525);
inline const PParam BISHOP_MAT = S(890, 1603);
inline const PParam ROOK_MAT   = S(1063, 2491);
inline const PParam QUEEN_MAT  = S(2523, 3774);

inline const PParam TEMPO_VAL  = S(70, 52);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -3);
inline const PParam BISHOP_PAIR_VAL   = S(66, 232);
inline const PParam ROOK_OPEN_VAL     = S(111, -5);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 13);
inline const PParam MINOR_BEHIND_PAWN = S(15, 40);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -80);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 48);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -3), S(34, 33), S(62, 64), S(120, 213), S(402, 386), S(588, 713),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 32), S(39, 25), S(54, 56), S(93, 180), S(434, 96),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -251), S(-95, -210), S(-67, -79), S(-24, 44), S(89, 204), S(218, 416),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-77, 48), S(-89, 30), S(-56, 106), S(-96, 234), S(-68, 339), S(48, 215),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-16, 68), S(-33, 61), S(-57, 106), S(-28, 133), S(63, 160), S(37, 179),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -41), S(25, -3), S(14, 38), S(20, 104), S(71, 276), S(328, 228),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -36), S(2, 6), S(-4, -28), S(-2, -64), S(-13, -174), S(-164, -444),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 229), S(8, 175), S(3, 100), S(12, 61), S(23, 62), S(63, 58), S(66, 26),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-138, -44), S(20, -5), S(5, 96), S(30, 145), S(45, 180), S(56, 189), S(38, 175),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-91, -365), S(-32, -116), S(-4, -0), S(20, 48), S(47, 79), S(62, 116), S(80, 124), S(99, 132), S(119, 86),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-70, -281), S(-21, -87), S(30, -9), S(54, 40), S(74, 83), S(86, 112), S(92, 135), S(94, 156), S(98, 167), S(104, 173), S(111, 165), S(128, 151), S(142, 135), S(108, 117),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(103, -157), S(20, 42), S(41, 73), S(57, 90), S(67, 109), S(72, 123), S(76, 138), S(82, 144), S(87, 156), S(92, 163), S(97, 169), S(98, 177), S(100, 182), S(105, 170), S(127, 128),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-204, -165), S(-45, 28), S(-21, 165), S(0, 294), S(17, 338), S(24, 393), S(30, 425), S(37, 443), S(41, 468), S(45, 485), S(51, 491), S(55, 499), S(58, 506), S(60, 511), S(61, 513), S(61, 516), S(56, 519), S(60, 509), S(61, 507), S(65, 497), S(61, 482), S(70, 458), S(39, 481), S(-8, 472), S(-27, 463), S(-62, 491), S(-89, 478), S(-66, 413),
};

inline const PParam PAWN_THREAT_KNIGHT = S(195, 151);
inline const PParam PAWN_THREAT_BISHOP = S(173, 214);
inline const PParam PAWN_THREAT_ROOK   = S(193, 147);
inline const PParam PAWN_THREAT_QUEEN  = S(155, 19);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 56), S(92, 94), S(103, 123), S(206, 124), S(165, -3), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(8, 55), S(54, 92), S(75, 91), S(16, 10), S(150, -55), S(0, 0),
};
inline const PParam KING_THREAT  = S(-18, 157);
inline const PParam HANGING_PAWN  = S(31, 91);
inline const PParam HANGING_NON_PAWN  = S(68, 30);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(38, -15),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(40, 47), S(149, -153),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 11), S(70, -31),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -15), S(4, -15), S(-1, -20), S(-6, -29), S(-12, -36), S(-16, -44), S(-18, -54), S(-24, -58), S(-27, -79),
};

inline const PParam ROOK_LINEUP = S(17, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(184, 269),    S(43, 399),     S(72, 375),     S(153, 264),    S(200, 160),    S(144, 211),    S(100, 252),    S(231, 176),    //
    S(41, 62),      S(57, 106),     S(34, 58),      S(45, -10),     S(33, -40),     S(8, -13),      S(12, 29),      S(-23, 58),     //
    S(37, -10),     S(13, -1),      S(44, -45),     S(30, -69),     S(20, -85),     S(2, -73),      S(-39, -36),    S(-40, -0),     //
    S(-6, -70),     S(-31, -40),    S(2, -60),      S(-6, -74),     S(-28, -84),    S(-38, -71),    S(-85, -52),    S(-80, -47),    //
    S(-12, -107),   S(21, -103),    S(6, -42),      S(-9, -50),     S(-37, -58),    S(-52, -67),    S(-82, -64),    S(-84, -69),    //
    S(10, -102),    S(86, -93),     S(72, -37),     S(28, -13),     S(-4, -33),     S(-24, -56),    S(-51, -52),    S(-65, -51),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-261, -498),  S(-255, 66),    S(-281, -49),   S(17, 29),      S(-99, 49),     S(-279, 94),    S(-352, 114),   S(-365, -367),  //
    S(-15, -0),     S(-2, 37),      S(88, 31),      S(80, 63),      S(84, 56),      S(51, 27),      S(-27, 33),     S(-46, 31),     //
    S(40, -13),     S(39, 35),      S(64, 60),      S(69, 81),      S(55, 78),      S(21, 61),      S(6, 45),       S(-46, 25),     //
    S(91, 28),      S(90, 57),      S(100, 74),     S(100, 113),    S(104, 117),    S(69, 79),      S(47, 48),      S(31, 43),      //
    S(76, 23),      S(100, 13),     S(97, 56),      S(88, 89),      S(77, 89),      S(70, 69),      S(55, 20),      S(18, 40),      //
    S(13, -28),     S(40, -11),     S(47, 28),      S(60, 61),      S(54, 59),      S(27, 23),      S(11, -4),      S(-30, -31),    //
    S(33, -14),     S(37, -0),      S(26, -10),     S(32, 21),      S(30, 14),      S(1, -31),      S(-35, 8),      S(-49, -71),    //
    S(-48, -67),    S(3, -17),      S(21, -32),     S(39, -19),     S(21, -2),      S(-16, -37),    S(-25, -15),    S(-71, -119),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-135, 32),    S(-180, 118),   S(-418, 189),   S(-264, 101),   S(-294, 159),   S(-299, 158),   S(-211, 132),   S(-132, 95),    //
    S(-30, -11),    S(-72, 95),     S(-38, 68),     S(-68, 75),     S(-69, 91),     S(-32, 57),     S(-9, 52),      S(-45, 33),     //
    S(34, 34),      S(12, 75),      S(31, 83),      S(26, 71),      S(21, 59),      S(21, 61),      S(7, 62),       S(11, 25),      //
    S(12, 15),      S(49, 41),      S(58, 57),      S(77, 72),      S(102, 58),     S(44, 37),      S(47, 10),      S(-3, 15),      //
    S(41, -33),     S(48, 13),      S(77, 29),      S(90, 42),      S(74, 55),      S(66, 40),      S(23, 19),      S(16, -23),     //
    S(56, -14),     S(85, -14),     S(95, 17),      S(63, 45),      S(60, 30),      S(54, 33),      S(61, 9),       S(16, -3),      //
    S(29, -63),     S(112, -39),    S(67, -1),      S(45, 16),      S(27, 17),      S(48, -28),     S(46, -37),     S(36, -33),     //
    S(49, -63),     S(19, 2),       S(23, 10),      S(45, -20),     S(28, -4),      S(32, 29),      S(42, -1),      S(39, -42),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(165, 144),    S(200, 155),    S(143, 184),    S(146, 152),    S(198, 110),    S(164, 132),    S(172, 148),    S(151, 151),    //
    S(77, 189),     S(138, 181),    S(198, 139),    S(144, 141),    S(184, 123),    S(145, 150),    S(97, 180),     S(89, 183),     //
    S(54, 173),     S(171, 121),    S(205, 94),     S(181, 74),     S(175, 101),    S(114, 142),    S(121, 146),    S(60, 200),     //
    S(27, 139),     S(93, 140),     S(115, 119),    S(95, 116),     S(120, 103),    S(81, 149),     S(73, 161),     S(16, 187),     //
    S(0, 72),       S(61, 84),      S(58, 98),      S(27, 108),     S(35, 115),     S(25, 138),     S(6, 140),      S(-13, 142),    //
    S(14, -7),      S(85, 17),      S(71, 42),      S(52, 48),      S(63, 54),      S(35, 83),      S(37, 68),      S(-5, 71),      //
    S(-63, -15),    S(64, -52),     S(71, -16),     S(58, 20),      S(63, 16),      S(44, 35),      S(36, 18),      S(4, 21),       //
    S(-3, -35),     S(16, 1),       S(85, -15),     S(93, -15),     S(95, -10),     S(70, 16),      S(67, 5),       S(48, 12),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(84, 199),     S(149, 189),    S(59, 316),     S(1, 414),      S(40, 364),     S(75, 281),     S(69, 201),     S(16, 253),     //
    S(59, 222),     S(82, 261),     S(48, 332),     S(-85, 463),    S(-33, 430),    S(9, 330),      S(55, 203),     S(28, 200),     //
    S(27, 253),     S(55, 304),     S(24, 372),     S(-9, 400),     S(13, 382),     S(53, 285),     S(78, 194),     S(64, 144),     //
    S(26, 186),     S(27, 271),     S(-10, 332),    S(-17, 389),    S(1, 387),      S(24, 267),     S(57, 187),     S(28, 162),     //
    S(14, 182),     S(12, 194),     S(3, 245),      S(-25, 317),    S(-17, 343),    S(9, 266),      S(10, 207),     S(35, 112),     //
    S(8, 84),       S(37, 93),      S(32, 166),     S(9, 195),      S(15, 206),     S(15, 231),     S(36, 160),     S(18, 133),     //
    S(-20, -69),    S(7, -57),      S(14, 12),      S(36, 55),      S(32, 95),      S(33, 76),      S(8, 102),      S(23, 73),      //
    S(-34, -39),    S(-15, -186),   S(15, -194),    S(28, -83),     S(34, -3),      S(33, -38),     S(31, -18),     S(0, 37),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(90, -503),    S(459, 94),     S(295, 219),    S(-28, 207),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(320, -159),   S(354, 196),    S(192, 215),    S(1, 167),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(171, 52),     S(210, 185),    S(102, 207),    S(-51, 179),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(13, 13),      S(93, 118),     S(-26, 170),    S(-120, 197),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, 3),     S(-39, 80),     S(-107, 149),   S(-190, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-57, -35),    S(13, 28),      S(-76, 113),    S(-133, 160),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(26, -96),     S(33, -17),     S(-32, 46),     S(-107, 103),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, -213),   S(8, -94),      S(-72, -31),    S(-73, -49),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-85, -431);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 13), S(11, 5), S(5, 2), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -17), S(-8, 7), S(-4, -8), S(6, -14), S(12, -27), S(6, -57), S(-6, -50), }},
  {{ S(2, 5), S(-23, 2), S(-18, 10), S(-11, 19), S(-7, 9), S(-10, -12), S(-23, -23), }},
  {{ S(-4, -0), S(-13, -9), S(-14, 20), S(-9, 19), S(-7, 11), S(-8, -18), S(-25, -47), }},
  {{ S(6, 11), S(-11, 20), S(-7, 41), S(-2, 45), S(-2, 41), S(3, 22), S(8, -11), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 27), S(-5, 3), S(-8, 11), S(-6, 30), S(1, 55),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 13), S(-47, -112), S(-8, -44), S(0, 5), S(-3, 5), S(-6, 12), S(-5, 10), }},
  {{ S(10, -0), S(-25, -106), S(-5, -35), S(-3, 1), S(-1, -3), S(-8, 4), S(2, 3), }},
  {{ S(1, 10), S(-10, -100), S(9, -17), S(2, 7), S(-3, 10), S(-9, 18), S(-5, 20), }},
  {{ S(1, 0), S(7, -63), S(-0, 28), S(-2, 27), S(-6, 9), S(-13, 12), S(-10, 21), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1283, 833, -20, -4
);

inline VParam WINNABLE_PAWNS = V(-19);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(84);
inline VParam WINNABLE_PAWN_ENDGAME = V(83);
inline VParam WINNABLE_BIAS = V(-385);

// Epoch duration: 6.39037s
// clang-format on
}  // namespace Clockwork
