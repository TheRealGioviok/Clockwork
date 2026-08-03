#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(208, 473);
inline const PParam KNIGHT_MAT = S(851, 1477);
inline const PParam BISHOP_MAT = S(895, 1536);
inline const PParam ROOK_MAT   = S(1091, 2319);
inline const PParam QUEEN_MAT  = S(2551, 3495);

inline const PParam TEMPO_VAL  = S(70, 52);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, -2);
inline const PParam BISHOP_PAIR_VAL   = S(60, 237);
inline const PParam ROOK_OPEN_VAL     = S(110, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 11);
inline const PParam MINOR_BEHIND_PAWN = S(15, 45);
inline const PParam RESTRICTED_SQUARES = S(19, 8);

inline const PParam DOUBLED_PAWN_VAL = S(-25, -76);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -41);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 49);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 1);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(16, 69);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -4), S(37, 27), S(60, 62), S(121, 204), S(428, 379), S(566, 640),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 27), S(41, 22), S(54, 56), S(90, 175), S(398, 113),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -242), S(-91, -203), S(-59, -78), S(-18, 47), S(74, 217), S(216, 419),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-75, 53), S(-90, 41), S(-49, 95), S(-92, 218), S(-69, 333), S(44, 223),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-4, 59), S(-15, 55), S(-64, 109), S(-23, 124), S(73, 149), S(37, 194),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -41), S(21, 0), S(11, 38), S(21, 96), S(67, 260), S(312, 249),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(10, -31), S(0, 10), S(-10, -19), S(-5, -61), S(-13, -170), S(-175, -450),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 218), S(7, 169), S(0, 95), S(13, 53), S(25, 58), S(60, 53), S(65, 28),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-126, -47), S(14, -3), S(-0, 100), S(28, 144), S(44, 179), S(55, 185), S(40, 166),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-118, -336), S(-40, -85), S(-7, 26), S(15, 72), S(41, 105), S(55, 142), S(73, 148), S(91, 155), S(110, 110),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-88, -275), S(-26, -58), S(30, 19), S(52, 79), S(72, 121), S(85, 151), S(90, 174), S(92, 194), S(97, 202), S(102, 208), S(115, 199), S(120, 187), S(129, 186), S(87, 155),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(90, -109), S(11, 97), S(31, 132), S(46, 152), S(58, 170), S(62, 182), S(67, 198), S(72, 205), S(77, 216), S(82, 224), S(86, 231), S(85, 239), S(87, 244), S(95, 228), S(109, 196),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-174, -100), S(-26, 16), S(-3, 180), S(15, 334), S(34, 374), S(42, 424), S(49, 466), S(54, 487), S(59, 508), S(64, 522), S(69, 531), S(74, 535), S(77, 544), S(81, 544), S(80, 550), S(81, 551), S(77, 555), S(77, 546), S(78, 543), S(87, 531), S(72, 527), S(96, 487), S(63, 518), S(26, 510), S(3, 491), S(-33, 518), S(-17, 479), S(-9, 421),
};

inline const PParam PAWN_THREAT_KNIGHT = S(201, 156);
inline const PParam PAWN_THREAT_BISHOP = S(171, 225);
inline const PParam PAWN_THREAT_ROOK   = S(190, 145);
inline const PParam PAWN_THREAT_QUEEN  = S(162, 3);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 56), S(94, 89), S(103, 118), S(208, 109), S(172, -9), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(5, 56), S(54, 97), S(79, 89), S(15, 17), S(162, -57), S(0, 0),
};
inline const PParam KING_THREAT  = S(-1, 148);
inline const PParam HANGING_PAWN  = S(30, 93);
inline const PParam HANGING_NON_PAWN  = S(68, 30);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(22, -16), S(90, -71),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(47, 37), S(198, -218),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(39, 9), S(118, -101),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -15), S(-1, -22), S(-6, -29), S(-12, -36), S(-17, -41), S(-19, -51), S(-24, -47), S(-21, -97),
};

inline const PParam ROOK_LINEUP = S(16, 86);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(192, 271),    S(65, 389),     S(75, 376),     S(173, 267),    S(184, 188),    S(152, 217),    S(133, 242),    S(223, 195),    //
    S(55, 63),      S(63, 101),     S(50, 57),      S(60, -5),      S(52, -43),     S(23, -13),     S(18, 32),      S(-16, 63),     //
    S(37, -2),      S(14, 3),       S(47, -35),     S(28, -59),     S(14, -74),     S(-2, -62),     S(-41, -34),    S(-43, 8),      //
    S(-7, -60),     S(-33, -33),    S(2, -51),      S(-11, -68),    S(-33, -79),    S(-43, -61),    S(-87, -45),    S(-84, -39),    //
    S(-15, -98),    S(15, -92),     S(0, -28),      S(-19, -34),    S(-43, -43),    S(-63, -50),    S(-88, -55),    S(-93, -58),    //
    S(9, -95),      S(85, -82),     S(76, -26),     S(24, 8),       S(-5, -16),     S(-29, -40),    S(-54, -45),    S(-69, -43),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-283, -449),  S(-236, 51),    S(-285, 129),   S(26, 50),      S(-76, 63),     S(-291, 128),   S(-325, 114),   S(-374, -360),  //
    S(5, 13),       S(-6, 49),      S(81, 36),      S(82, 87),      S(95, 68),      S(47, 47),      S(-6, 34),      S(-50, 44),     //
    S(35, -4),      S(42, 45),      S(48, 74),      S(69, 95),      S(54, 92),      S(12, 81),      S(-4, 60),      S(-42, 24),     //
    S(83, 46),      S(89, 61),      S(90, 90),      S(102, 123),    S(103, 115),    S(68, 86),      S(48, 45),      S(18, 58),      //
    S(69, 38),      S(88, 23),      S(96, 63),      S(83, 102),     S(78, 99),      S(60, 86),      S(46, 41),      S(15, 34),      //
    S(11, -26),     S(39, -12),     S(46, 35),      S(57, 69),      S(52, 72),      S(24, 30),      S(5, 2),        S(-35, -25),    //
    S(24, 1),       S(21, 22),      S(18, -5),      S(29, 26),      S(23, 27),      S(-6, -22),     S(-48, 24),     S(-66, -60),    //
    S(-57, -78),    S(-1, -15),     S(16, -20),     S(34, -12),     S(19, -4),      S(-22, -34),    S(-37, 1),      S(-93, -118),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-118, 18),    S(-216, 133),   S(-401, 210),   S(-266, 129),   S(-271, 148),   S(-255, 162),   S(-184, 126),   S(-149, 123),   //
    S(-38, 13),     S(-77, 122),    S(-57, 103),    S(-64, 98),     S(-58, 102),    S(-34, 72),     S(-24, 72),     S(-63, 59),     //
    S(37, 44),      S(17, 81),      S(26, 94),      S(22, 85),      S(23, 69),      S(12, 83),      S(-5, 77),      S(11, 25),      //
    S(9, 20),       S(46, 51),      S(60, 58),      S(81, 82),      S(94, 77),      S(36, 55),      S(33, 37),      S(-9, 30),      //
    S(34, -12),     S(34, 37),      S(70, 41),      S(85, 60),      S(71, 68),      S(58, 57),      S(11, 40),      S(-1, -0),      //
    S(47, 6),       S(73, 5),       S(87, 31),      S(59, 56),      S(53, 47),      S(48, 45),      S(50, 28),      S(15, 1),       //
    S(21, -39),     S(104, -29),    S(52, 16),      S(35, 33),      S(21, 31),      S(36, -15),     S(37, -24),     S(27, -13),     //
    S(28, -40),     S(15, 2),       S(18, 23),      S(31, 2),       S(16, 8),       S(29, 41),      S(34, 9),       S(28, -33),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(163, 169),    S(185, 185),    S(149, 217),    S(136, 182),    S(184, 153),    S(137, 176),    S(155, 190),    S(149, 178),    //
    S(94, 203),     S(135, 209),    S(186, 167),    S(138, 166),    S(174, 156),    S(142, 178),    S(91, 211),     S(82, 213),     //
    S(69, 189),     S(177, 135),    S(213, 114),    S(174, 104),    S(176, 123),    S(113, 166),    S(98, 189),     S(55, 224),     //
    S(32, 166),     S(90, 176),     S(101, 155),    S(86, 150),     S(109, 136),    S(77, 176),     S(60, 197),     S(14, 214),     //
    S(3, 105),      S(57, 116),     S(43, 146),     S(11, 151),     S(24, 150),     S(14, 174),     S(-2, 178),     S(-28, 182),    //
    S(7, 34),       S(81, 48),      S(63, 77),      S(37, 97),      S(45, 104),     S(28, 122),     S(24, 106),     S(-20, 118),    //
    S(-68, 27),     S(53, -15),     S(56, 25),      S(42, 66),      S(47, 63),      S(31, 76),      S(22, 63),      S(-9, 57),      //
    S(-8, -5),      S(12, 30),      S(76, 20),      S(84, 21),      S(87, 27),      S(62, 52),      S(56, 43),      S(36, 47),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(110, 215),    S(175, 200),    S(81, 347),     S(45, 404),     S(53, 410),     S(109, 301),    S(78, 257),     S(31, 277),     //
    S(74, 248),     S(77, 303),     S(50, 373),     S(-50, 465),    S(-13, 451),    S(45, 320),     S(68, 247),     S(53, 210),     //
    S(48, 261),     S(95, 285),     S(54, 369),     S(28, 386),     S(39, 398),     S(66, 321),     S(102, 212),    S(79, 186),     //
    S(42, 216),     S(50, 282),     S(11, 345),     S(12, 399),     S(30, 395),     S(32, 301),     S(72, 226),     S(52, 190),     //
    S(24, 209),     S(28, 208),     S(25, 253),     S(-2, 331),     S(-1, 368),     S(26, 297),     S(26, 246),     S(43, 163),     //
    S(20, 118),     S(52, 106),     S(45, 188),     S(18, 224),     S(29, 232),     S(26, 270),     S(44, 207),     S(29, 180),     //
    S(-19, -22),    S(18, -40),     S(22, 37),      S(45, 87),      S(41, 131),     S(43, 105),     S(19, 143),     S(34, 110),     //
    S(-45, 1),      S(-2, -184),    S(22, -158),    S(31, -51),     S(45, 20),      S(42, 12),      S(39, 19),      S(8, 82),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(128, -433),   S(472, 107),    S(426, 129),    S(63, 186),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(323, -166),   S(322, 180),    S(222, 170),    S(17, 129),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(184, 25),     S(198, 158),    S(72, 181),     S(-95, 168),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(24, 5),       S(103, 91),     S(-51, 161),    S(-168, 196),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-113, -3),    S(-44, 78),     S(-102, 144),   S(-209, 194),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-59, -26),    S(-2, 39),      S(-83, 121),    S(-141, 161),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(31, -94),     S(33, -14),     S(-31, 50),     S(-108, 106),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, -199),   S(12, -91),     S(-66, -26),    S(-70, -45),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-88, -431);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -2), S(11, 15), S(12, 6), S(5, 3), S(3, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -7), S(6, 5), S(3, 2), S(3, 0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -14), S(-10, 7), S(-5, -9), S(5, -13), S(14, -31), S(8, -55), S(-4, -51), }},
  {{ S(1, 10), S(-25, 5), S(-20, 13), S(-13, 22), S(-8, 12), S(-10, -15), S(-23, -23), }},
  {{ S(-6, 3), S(-14, -5), S(-16, 22), S(-10, 22), S(-8, 11), S(-8, -14), S(-22, -52), }},
  {{ S(6, 12), S(-13, 19), S(-9, 44), S(-3, 48), S(-3, 45), S(2, 25), S(15, -19), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 28), S(-8, 6), S(-8, 12), S(-8, 34), S(3, 53),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 15), S(-54, -117), S(-11, -41), S(2, 1), S(-4, 6), S(-7, 12), S(-6, 11), }},
  {{ S(10, -0), S(-31, -106), S(-7, -41), S(-3, -1), S(-2, -3), S(-11, 4), S(0, 4), }},
  {{ S(0, 14), S(-5, -79), S(8, -10), S(2, 8), S(-4, 15), S(-11, 22), S(-6, 24), }},
  {{ S(0, 2), S(2, -65), S(0, 25), S(-4, 35), S(-7, 13), S(-15, 12), S(-11, 22), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1121, 856, -24, 2
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(98);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(47);
inline VParam WINNABLE_BIAS = V(-365);

// Epoch duration: 4.42203s
// clang-format on
}  // namespace Clockwork
