#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(200, 493);
inline const PParam KNIGHT_MAT = S(848, 1520);
inline const PParam BISHOP_MAT = S(889, 1585);
inline const PParam ROOK_MAT   = S(1239, 2400);
inline const PParam QUEEN_MAT  = S(2652, 3628);

inline const PParam TEMPO_VAL  = S(72, 57);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(64, 237);
inline const PParam REDUNDANT_ROOK_PENALTY  = S(97, 158);
inline const PParam REDUNDANT_QUEEN_PENALTY = S(53, 108);
inline const PParam ROOK_OPEN_VAL     = S(112, -2);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 12);
inline const PParam MINOR_BEHIND_PAWN = S(17, 43);
inline const PParam RESTRICTED_SQUARES = S(19, 8);
inline const PParam SPACE_VAL = S(83, -77);

inline const PParam DOUBLED_PAWN_VAL = S(-19, -84);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -42);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 54);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 65);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -42);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -9), S(39, 26), S(52, 71), S(121, 209), S(434, 388), S(561, 639),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 22), S(42, 21), S(41, 68), S(86, 182), S(401, 123),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -250), S(-92, -210), S(-60, -82), S(-16, 43), S(74, 222), S(211, 442),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-73, 52), S(-97, 47), S(-56, 104), S(-105, 233), S(-78, 347), S(40, 228),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-1, 57), S(-15, 56), S(-63, 110), S(-24, 126), S(73, 154), S(38, 198),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -38), S(20, 2), S(14, 37), S(25, 94), S(74, 260), S(314, 253),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(8, -30), S(-1, 11), S(-11, -21), S(-7, -62), S(-13, -175), S(-176, -466),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 224), S(7, 173), S(1, 97), S(13, 56), S(26, 60), S(62, 54), S(69, 27),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-124, -52), S(16, -4), S(3, 100), S(32, 145), S(47, 182), S(57, 190), S(43, 169),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-112, -357), S(-35, -96), S(-4, 21), S(15, 75), S(38, 113), S(52, 153), S(71, 160), S(89, 167), S(107, 125),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-86, -289), S(-24, -71), S(32, 10), S(52, 77), S(69, 124), S(81, 156), S(86, 181), S(88, 202), S(91, 211), S(96, 221), S(107, 213), S(111, 204), S(118, 204), S(76, 175),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(84, -72), S(3, 133), S(24, 167), S(41, 185), S(52, 204), S(56, 217), S(60, 232), S(66, 239), S(71, 249), S(77, 256), S(81, 262), S(80, 269), S(83, 273), S(91, 256), S(104, 222),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-188, -101), S(-36, 21), S(-11, 182), S(7, 339), S(27, 380), S(35, 431), S(40, 476), S(43, 503), S(46, 530), S(49, 548), S(52, 561), S(58, 566), S(61, 573), S(66, 573), S(66, 579), S(68, 579), S(64, 581), S(65, 572), S(66, 568), S(75, 556), S(61, 552), S(88, 507), S(53, 541), S(18, 529), S(-5, 512), S(-41, 539), S(-22, 492), S(-16, 437),
};

inline const PParam PAWN_THREAT_KNIGHT = S(202, 162);
inline const PParam PAWN_THREAT_BISHOP = S(170, 232);
inline const PParam PAWN_THREAT_ROOK   = S(198, 138);
inline const PParam PAWN_THREAT_QUEEN  = S(159, 27);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(10, 53), S(99, 96), S(105, 122), S(186, 78), S(175, 5), }},
  {{ S(6, 57), S(90, 87), S(104, 117), S(221, 577), S(150, -13), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 62), S(46, 114), S(64, 108), S(15, 21), S(165, -83), }},
  {{ S(0, 51), S(62, 81), S(101, 67), S(14, 14), S(425, 616), }},
}};
inline const PParam KING_THREAT  = S(-1, 150);
inline const PParam HANGING_PAWN  = S(30, 95);
inline const PParam HANGING_NON_PAWN  = S(72, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(22, -13), S(100, -86),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(49, 40), S(218, -248),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(42, 1), S(119, -99),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -16), S(4, -15), S(0, -22), S(-6, -30), S(-12, -37), S(-18, -41), S(-20, -51), S(-26, -47), S(-25, -95),
};

inline const PParam ROOK_LINEUP = S(18, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(194, 283),    S(62, 404),     S(64, 398),     S(176, 270),    S(185, 193),    S(154, 219),    S(139, 243),    S(228, 199),    //
    S(56, 67),      S(53, 114),     S(33, 71),      S(39, 10),      S(30, -27),     S(8, -3),       S(10, 39),      S(-14, 63),     //
    S(38, -2),      S(9, 7),        S(28, -23),     S(-0, -37),     S(-16, -51),    S(-20, -47),    S(-45, -33),    S(-43, 8),      //
    S(-8, -62),     S(-37, -32),    S(-7, -46),     S(-25, -57),    S(-47, -67),    S(-50, -58),    S(-89, -46),    S(-85, -40),    //
    S(-19, -96),    S(11, -89),     S(-2, -26),     S(-18, -35),    S(-41, -47),    S(-64, -51),    S(-93, -52),    S(-99, -56),    //
    S(5, -92),      S(81, -76),     S(84, -31),     S(33, 0),       S(4, -25),      S(-23, -46),    S(-61, -39),    S(-75, -39),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-298, -425),  S(-244, 62),    S(-296, 142),   S(28, 52),      S(-76, 66),     S(-301, 136),   S(-336, 122),   S(-390, -342),  //
    S(5, 19),       S(-8, 57),      S(81, 37),      S(79, 95),      S(94, 73),      S(49, 47),      S(-6, 38),      S(-51, 48),     //
    S(35, -0),      S(43, 49),      S(49, 75),      S(71, 95),      S(57, 91),      S(13, 83),      S(-2, 60),      S(-45, 31),     //
    S(84, 51),      S(88, 65),      S(90, 91),      S(100, 127),    S(101, 118),    S(68, 87),      S(47, 48),      S(19, 60),      //
    S(71, 40),      S(93, 20),      S(100, 61),     S(85, 102),     S(81, 98),      S(63, 84),      S(50, 39),      S(16, 36),      //
    S(14, -30),     S(44, -19),     S(50, 30),      S(60, 67),      S(54, 70),      S(27, 27),      S(10, -4),      S(-32, -28),    //
    S(29, -4),      S(24, 21),      S(23, -10),     S(33, 22),      S(28, 22),      S(-1, -27),     S(-45, 22),     S(-64, -63),    //
    S(-61, -71),    S(0, -16),      S(18, -18),     S(35, -10),     S(19, -2),      S(-23, -32),    S(-38, 1),      S(-99, -108),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-122, 25),    S(-227, 145),   S(-412, 224),   S(-276, 142),   S(-286, 163),   S(-266, 174),   S(-196, 139),   S(-153, 127),   //
    S(-36, 15),     S(-77, 128),    S(-59, 109),    S(-67, 105),    S(-61, 110),    S(-36, 78),     S(-21, 74),     S(-61, 62),     //
    S(42, 43),      S(20, 79),      S(29, 94),      S(23, 85),      S(25, 67),      S(16, 82),      S(-4, 81),      S(15, 25),      //
    S(10, 22),      S(47, 53),      S(61, 61),      S(82, 83),      S(94, 80),      S(37, 56),      S(34, 39),      S(-8, 33),      //
    S(36, -14),     S(35, 38),      S(72, 42),      S(87, 61),      S(74, 70),      S(59, 59),      S(11, 43),      S(-1, 2),       //
    S(50, 4),       S(78, 2),       S(91, 31),      S(62, 57),      S(55, 49),      S(52, 44),      S(54, 26),      S(18, -2),      //
    S(24, -40),     S(113, -37),    S(56, 16),      S(41, 28),      S(27, 26),      S(40, -16),     S(43, -29),     S(30, -15),     //
    S(29, -38),     S(17, 3),       S(20, 24),      S(33, 2),       S(18, 7),       S(31, 39),      S(35, 13),      S(28, -29),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(152, 178),    S(174, 195),    S(139, 226),    S(124, 194),    S(171, 167),    S(122, 190),    S(140, 204),    S(136, 190),    //
    S(77, 218),     S(117, 225),    S(170, 182),    S(122, 182),    S(159, 172),    S(127, 191),    S(73, 225),     S(66, 227),     //
    S(54, 200),     S(162, 146),    S(201, 124),    S(160, 115),    S(162, 135),    S(100, 175),    S(80, 203),     S(39, 235),     //
    S(17, 172),     S(75, 186),     S(86, 165),     S(71, 161),     S(94, 147),     S(61, 186),     S(43, 207),     S(-2, 223),     //
    S(-13, 112),    S(41, 125),     S(26, 157),     S(-6, 164),     S(7, 163),      S(-3, 186),     S(-18, 188),    S(-45, 192),    //
    S(-12, 47),     S(64, 59),      S(44, 92),      S(20, 109),     S(28, 115),     S(11, 134),     S(6, 119),      S(-38, 130),    //
    S(-87, 38),     S(36, -2),      S(37, 41),      S(23, 81),      S(29, 77),      S(14, 88),      S(4, 76),       S(-27, 69),     //
    S(-28, 11),     S(-8, 47),      S(56, 38),      S(65, 38),      S(68, 45),      S(43, 68),      S(38, 58),      S(18, 62),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(99, 221),     S(163, 210),    S(70, 357),     S(35, 412),     S(41, 420),     S(96, 310),     S(65, 265),     S(19, 283),     //
    S(63, 260),     S(63, 320),     S(36, 389),     S(-65, 478),    S(-28, 468),    S(30, 334),     S(54, 262),     S(41, 224),     //
    S(42, 264),     S(84, 297),     S(43, 381),     S(10, 408),     S(24, 415),     S(55, 333),     S(90, 226),     S(70, 196),     //
    S(33, 222),     S(39, 289),     S(-3, 358),     S(-1, 408),     S(18, 404),     S(20, 312),     S(61, 238),     S(43, 198),     //
    S(16, 210),     S(19, 211),     S(15, 258),     S(-11, 334),    S(-9, 372),     S(16, 304),     S(17, 251),     S(34, 169),     //
    S(12, 117),     S(48, 97),      S(38, 186),     S(9, 228),      S(21, 238),     S(19, 271),     S(38, 209),     S(21, 183),     //
    S(-23, -36),    S(14, -53),     S(18, 29),      S(42, 79),      S(37, 125),     S(39, 102),     S(15, 137),     S(30, 103),     //
    S(-53, -5),     S(-9, -192),    S(16, -167),    S(27, -60),     S(42, 9),       S(38, 3),       S(33, 16),      S(-0, 80),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(126, -441),   S(480, 110),    S(433, 132),    S(67, 189),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(328, -167),   S(323, 189),    S(222, 178),    S(19, 130),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(184, 30),     S(198, 165),    S(70, 186),     S(-100, 172),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(29, 3),       S(104, 95),     S(-55, 165),    S(-178, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-113, -2),    S(-42, 78),     S(-102, 144),   S(-213, 193),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-58, -29),    S(-2, 39),      S(-83, 120),    S(-142, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(31, -95),     S(32, -12),     S(-33, 51),     S(-114, 111),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, -203),   S(9, -91),      S(-71, -25),    S(-77, -44),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-90, -435);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -1), S(12, 15), S(12, 7), S(5, 2), S(3, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -5), S(6, 6), S(3, 3), S(3, -0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -14), S(-11, 7), S(-6, -9), S(5, -13), S(13, -29), S(7, -51), S(-5, -48), }},
  {{ S(1, 9), S(-25, 3), S(-21, 11), S(-13, 20), S(-9, 12), S(-11, -12), S(-23, -24), }},
  {{ S(-4, 3), S(-13, -5), S(-15, 21), S(-9, 21), S(-7, 10), S(-7, -15), S(-20, -54), }},
  {{ S(5, 14), S(-13, 21), S(-9, 45), S(-4, 49), S(-3, 44), S(2, 24), S(14, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 27), S(-9, 6), S(-9, 12), S(-8, 33), S(3, 51),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 15), S(-53, -113), S(-12, -37), S(1, 1), S(-4, 6), S(-7, 13), S(-7, 12), }},
  {{ S(10, 1), S(-30, -104), S(-7, -40), S(-4, -1), S(-3, -1), S(-12, 5), S(-0, 5), }},
  {{ S(0, 14), S(-4, -77), S(7, -8), S(2, 8), S(-4, 15), S(-11, 21), S(-7, 23), }},
  {{ S(1, 0), S(2, -66), S(0, 25), S(-4, 34), S(-8, 13), S(-15, 10), S(-11, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1131, 891, -24, 4
);

inline VParam WINNABLE_PAWNS = V(-19);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(91);
inline VParam WINNABLE_PAWN_ENDGAME = V(43);
inline VParam WINNABLE_BIAS = V(-391);

// Epoch duration: 4.27714s
// clang-format on
}  // namespace Clockwork
