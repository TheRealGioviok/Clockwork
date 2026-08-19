#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(198, 503);
inline const PParam KNIGHT_MAT = S(821, 1597);
inline const PParam BISHOP_MAT = S(858, 1672);
inline const PParam ROOK_MAT   = S(1012, 2597);
inline const PParam QUEEN_MAT  = S(2374, 3933);

inline const PParam TEMPO_VAL  = S(69, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -2);
inline const PParam BISHOP_PAIR_VAL   = S(62, 240);
inline const PParam ROOK_OPEN_VAL     = S(109, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-22, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -39);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 71);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -2), S(33, 36), S(60, 66), S(122, 214), S(389, 406), S(690, 771),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 33), S(39, 26), S(54, 57), S(91, 181), S(387, 122),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-91, -271), S(-92, -230), S(-65, -97), S(-20, 30), S(90, 190), S(237, 399),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-81, 54), S(-92, 36), S(-59, 105), S(-89, 230), S(-54, 341), S(51, 224),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-18, 69), S(-29, 60), S(-60, 108), S(-33, 135), S(73, 160), S(34, 195),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -40), S(24, -2), S(16, 35), S(22, 103), S(71, 273), S(319, 240),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -36), S(2, 8), S(-3, -26), S(-0, -68), S(-14, -176), S(-170, -457),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 242), S(9, 189), S(3, 113), S(11, 74), S(19, 79), S(57, 74), S(61, 44),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-133, -45), S(12, 1), S(-0, 104), S(26, 154), S(42, 189), S(53, 197), S(39, 178),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-100, -395), S(-32, -141), S(-1, -25), S(22, 23), S(49, 56), S(65, 93), S(83, 101), S(102, 109), S(122, 62),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-69, -341), S(-16, -119), S(36, -29), S(61, 25), S(81, 68), S(93, 99), S(98, 122), S(100, 143), S(105, 154), S(111, 161), S(120, 155), S(134, 138), S(133, 143), S(118, 108),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(106, -182), S(31, 18), S(52, 52), S(67, 71), S(78, 89), S(82, 103), S(87, 119), S(93, 125), S(97, 137), S(103, 145), S(107, 151), S(107, 161), S(110, 165), S(115, 152), S(135, 113),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-192, -104), S(-30, -17), S(-6, 123), S(12, 266), S(29, 309), S(37, 362), S(43, 401), S(50, 419), S(55, 442), S(58, 459), S(64, 467), S(69, 474), S(72, 481), S(74, 487), S(75, 489), S(74, 492), S(71, 494), S(73, 486), S(74, 482), S(78, 473), S(68, 465), S(80, 437), S(44, 467), S(0, 456), S(-33, 456), S(-68, 478), S(-122, 500), S(-90, 438),
};

inline const PParam PAWN_THREAT_KNIGHT = S(196, 155);
inline const PParam PAWN_THREAT_BISHOP = S(171, 221);
inline const PParam PAWN_THREAT_ROOK   = S(190, 154);
inline const PParam PAWN_THREAT_QUEEN  = S(160, 21);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(8, 57), S(98, 96), S(104, 125), S(178, 94), S(164, 10), }},
  {{ S(6, 58), S(87, 94), S(103, 124), S(219, 615), S(146, 58), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 64), S(44, 107), S(59, 112), S(12, 12), S(151, -77), }},
  {{ S(4, 49), S(62, 82), S(95, 72), S(23, 12), S(414, 771), }},
}};
inline const PParam KING_THREAT  = S(-9, 156);
inline const PParam HANGING_PAWN  = S(32, 93);
inline const PParam HANGING_NON_PAWN  = S(72, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(22, 9),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 45), S(111, -111),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 13), S(48, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -17), S(4, -15), S(-1, -21), S(-6, -29), S(-12, -37), S(-17, -43), S(-19, -55), S(-25, -57), S(-31, -74),
};

inline const PParam ROOK_LINEUP = S(17, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(186, 281),    S(65, 403),     S(69, 391),     S(159, 275),    S(194, 172),    S(145, 216),    S(124, 245),    S(224, 186),    //
    S(46, 67),      S(59, 113),     S(39, 65),      S(52, -1),      S(44, -38),     S(17, -9),      S(19, 30),      S(-16, 58),     //
    S(43, -9),      S(19, -0),      S(48, -42),     S(30, -66),     S(22, -84),     S(8, -71),      S(-32, -40),    S(-33, -1),     //
    S(-2, -69),     S(-26, -39),    S(4, -57),      S(-6, -74),     S(-27, -83),    S(-31, -71),    S(-78, -52),    S(-72, -47),    //
    S(-9, -107),    S(22, -103),    S(7, -41),      S(-9, -46),     S(-36, -56),    S(-49, -66),    S(-75, -67),    S(-79, -69),    //
    S(13, -103),    S(87, -92),     S(75, -36),     S(29, -7),      S(-0, -28),     S(-20, -55),    S(-45, -54),    S(-58, -52),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-257, -502),  S(-254, 51),    S(-260, -30),   S(5, 42),       S(-86, 42),     S(-261, 81),    S(-342, 100),   S(-343, -407),  //
    S(4, -11),      S(8, 27),       S(90, 24),      S(88, 60),      S(94, 48),      S(56, 27),      S(-11, 27),     S(-37, 21),     //
    S(45, -25),     S(47, 28),      S(59, 63),      S(78, 70),      S(62, 71),      S(25, 59),      S(14, 35),      S(-30, 11),     //
    S(94, 23),      S(96, 46),      S(106, 68),     S(109, 109),    S(113, 107),    S(77, 73),      S(56, 38),      S(37, 32),      //
    S(83, 15),      S(106, 3),      S(104, 50),     S(99, 81),      S(85, 83),      S(77, 64),      S(62, 19),      S(29, 25),      //
    S(22, -40),     S(48, -25),     S(55, 20),      S(67, 52),      S(63, 51),      S(35, 14),      S(19, -17),     S(-19, -40),    //
    S(40, -22),     S(43, -10),     S(31, -19),     S(42, 9),       S(38, 7),       S(10, -43),     S(-26, 1),      S(-44, -84),    //
    S(-40, -92),    S(14, -28),     S(33, -43),     S(49, -32),     S(33, -18),     S(-4, -51),     S(-16, -26),    S(-67, -140),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-121, 23),    S(-181, 104),   S(-390, 167),   S(-262, 99),    S(-293, 140),   S(-294, 153),   S(-216, 128),   S(-119, 74),    //
    S(-17, -18),    S(-53, 89),     S(-36, 63),     S(-58, 60),     S(-56, 75),     S(-30, 50),     S(2, 43),       S(-41, 26),     //
    S(44, 18),      S(25, 60),      S(39, 69),      S(36, 55),      S(32, 43),      S(30, 47),      S(19, 44),      S(22, 14),      //
    S(25, -6),      S(58, 21),      S(70, 36),      S(89, 55),      S(113, 40),     S(51, 21),      S(54, -3),      S(8, -1),       //
    S(46, -43),     S(54, 3),       S(86, 14),      S(101, 27),     S(84, 38),      S(75, 25),      S(30, 7),       S(19, -37),     //
    S(66, -29),     S(89, -25),     S(105, 5),      S(73, 29),      S(69, 14),      S(67, 15),      S(68, -2),      S(26, -21),     //
    S(35, -73),     S(122, -56),    S(75, -18),     S(57, -0),      S(39, -0),      S(54, -42),     S(54, -56),     S(47, -49),     //
    S(52, -72),     S(32, -23),     S(39, -9),      S(54, -32),     S(38, -19),     S(46, 16),      S(52, -15),     S(48, -60),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(190, 129),    S(219, 149),    S(172, 179),    S(157, 151),    S(219, 106),    S(177, 133),    S(184, 151),    S(168, 148),    //
    S(102, 171),    S(160, 175),    S(203, 147),    S(157, 132),    S(194, 119),    S(161, 145),    S(114, 177),    S(104, 179),    //
    S(72, 165),     S(193, 108),    S(219, 91),     S(191, 76),     S(195, 94),     S(136, 135),    S(130, 152),    S(78, 190),     //
    S(45, 131),     S(107, 140),    S(128, 114),    S(112, 113),    S(140, 96),     S(100, 138),    S(90, 153),     S(36, 178),     //
    S(20, 64),      S(78, 75),      S(72, 96),      S(41, 105),     S(50, 111),     S(40, 135),     S(23, 132),     S(1, 137),      //
    S(32, -14),     S(100, 10),     S(88, 35),      S(66, 48),      S(76, 55),      S(53, 78),      S(49, 63),      S(11, 68),      //
    S(-47, -21),    S(78, -55),     S(83, -19),     S(71, 14),      S(75, 16),      S(61, 29),      S(52, 12),      S(20, 16),      //
    S(16, -42),     S(39, -10),     S(102, -22),    S(111, -23),    S(113, -17),    S(90, 5),       S(84, -1),      S(63, 5),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(105, 186),    S(163, 185),    S(73, 330),     S(15, 427),     S(52, 380),     S(87, 289),     S(88, 207),     S(41, 240),     //
    S(74, 216),     S(94, 272),     S(53, 354),     S(-66, 469),    S(-23, 438),    S(36, 321),     S(74, 207),     S(56, 178),     //
    S(36, 267),     S(76, 293),     S(45, 370),     S(8, 405),      S(27, 394),     S(67, 291),     S(98, 187),     S(79, 151),     //
    S(31, 204),     S(43, 271),     S(2, 340),      S(3, 393),      S(20, 386),     S(37, 271),     S(76, 187),     S(51, 150),     //
    S(28, 178),     S(25, 202),     S(18, 251),     S(-8, 320),     S(4, 336),      S(26, 271),     S(32, 207),     S(52, 113),     //
    S(19, 84),      S(49, 93),      S(46, 168),     S(25, 190),     S(35, 197),     S(37, 220),     S(57, 149),     S(37, 127),     //
    S(-9, -62),     S(19, -60),     S(28, 7),       S(55, 46),      S(52, 86),      S(54, 58),      S(27, 98),      S(40, 70),      //
    S(-27, -47),    S(4, -207),     S(36, -213),    S(48, -101),    S(55, -23),     S(53, -42),     S(51, -28),     S(21, 27),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(101, -531),   S(440, 90),     S(282, 201),    S(-11, 196),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(334, -177),   S(331, 195),    S(180, 210),    S(-4, 161),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(165, 51),     S(198, 181),    S(84, 205),     S(-80, 185),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(6, 14),       S(81, 120),     S(-52, 178),    S(-147, 207),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-144, 5),     S(-53, 83),     S(-116, 152),   S(-211, 204),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-86, -28),    S(-19, 40),     S(-98, 121),    S(-153, 166),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-10, -86),    S(-4, -6),      S(-65, 56),     S(-140, 114),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-57, -205),   S(-30, -86),    S(-107, -21),   S(-115, -33),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-84, -419);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 1), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -18), S(-6, 6), S(-2, -9), S(7, -15), S(13, -28), S(8, -53), S(-2, -45), }},
  {{ S(3, 4), S(-20, 3), S(-16, 11), S(-9, 18), S(-6, 9), S(-9, -12), S(-18, -20), }},
  {{ S(-4, 1), S(-13, -7), S(-13, 19), S(-9, 20), S(-8, 11), S(-7, -15), S(-23, -36), }},
  {{ S(7, 9), S(-10, 19), S(-6, 39), S(-1, 44), S(-1, 39), S(4, 20), S(11, -13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(12, 27), S(-3, 6), S(-5, 13), S(-3, 32), S(4, 52),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(8, 15), S(-39, -163), S(-6, -35), S(2, 8), S(-0, 7), S(-3, 14), S(-3, 13), }},
  {{ S(11, 2), S(-22, -163), S(-4, -26), S(-2, 4), S(1, 1), S(-6, 8), S(3, 7), }},
  {{ S(3, 15), S(-5, -66), S(9, -12), S(3, 12), S(-1, 15), S(-7, 22), S(-3, 25), }},
  {{ S(3, 4), S(5, -59), S(2, 28), S(-0, 29), S(-3, 12), S(-9, 14), S(-6, 23), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1415, 914, -30, -19
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(75);
inline VParam WINNABLE_BIAS = V(-390);

// Epoch duration: 7.65336s
// clang-format on
}  // namespace Clockwork
