#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(222, 499);
inline const PParam KNIGHT_MAT = S(909, 1555);
inline const PParam BISHOP_MAT = S(955, 1612);
inline const PParam ROOK_MAT   = S(1165, 2427);
inline const PParam QUEEN_MAT  = S(2715, 3648);

inline const PParam TEMPO_VAL  = S(75, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, -2);
inline const PParam BISHOP_PAIR_VAL   = S(64, 250);
inline const PParam ROOK_OPEN_VAL     = S(116, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 12);
inline const PParam MINOR_BEHIND_PAWN = S(16, 48);
inline const PParam RESTRICTED_SQUARES = S(20, 8);

inline const PParam DOUBLED_PAWN_VAL = S(-27, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -44);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 47);
inline const PParam OUTPOST_BISHOP_VAL    = S(45, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 51);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(45, 0);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 73);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(64, -53);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -4), S(40, 28), S(64, 65), S(128, 216), S(458, 396), S(570, 643),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 28), S(43, 23), S(57, 59), S(95, 185), S(423, 119),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-99, -258), S(-97, -217), S(-63, -85), S(-20, 47), S(77, 228), S(232, 446),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-80, 58), S(-96, 43), S(-53, 101), S(-98, 230), S(-75, 353), S(46, 237),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-5, 63), S(-17, 59), S(-67, 114), S(-25, 131), S(76, 159), S(41, 205),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -42), S(22, 1), S(12, 41), S(22, 101), S(72, 276), S(323, 263),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(10, -32), S(1, 11), S(-11, -20), S(-5, -65), S(-14, -180), S(-190, -477),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 234), S(6, 182), S(-1, 104), S(13, 60), S(25, 65), S(62, 60), S(69, 33),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-133, -51), S(17, -5), S(1, 104), S(31, 151), S(48, 188), S(61, 194), S(45, 173),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-126, -354), S(-43, -88), S(-8, 29), S(16, 79), S(43, 114), S(59, 154), S(78, 160), S(96, 167), S(117, 119),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-95, -285), S(-29, -57), S(30, 25), S(54, 89), S(75, 133), S(89, 164), S(95, 189), S(97, 210), S(102, 219), S(108, 225), S(122, 215), S(127, 203), S(136, 203), S(92, 169),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(95, -104), S(11, 112), S(33, 149), S(49, 170), S(61, 189), S(66, 202), S(71, 219), S(77, 226), S(82, 237), S(88, 246), S(91, 253), S(90, 262), S(93, 267), S(101, 249), S(116, 215),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-173, -94), S(-15, 26), S(10, 198), S(28, 363), S(48, 406), S(58, 458), S(65, 503), S(70, 525), S(76, 547), S(80, 562), S(86, 572), S(92, 577), S(94, 585), S(99, 585), S(98, 591), S(99, 592), S(95, 595), S(95, 586), S(96, 582), S(105, 570), S(91, 564), S(117, 522), S(82, 555), S(44, 543), S(21, 523), S(-16, 552), S(9, 500), S(16, 442),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 163);
inline const PParam PAWN_THREAT_BISHOP = S(180, 237);
inline const PParam PAWN_THREAT_ROOK   = S(203, 152);
inline const PParam PAWN_THREAT_QUEEN  = S(173, 10);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(9, 57), S(104, 97), S(110, 126), S(192, 87), S(184, 0), }},
  {{ S(6, 61), S(94, 89), S(109, 121), S(229, 610), S(159, -30), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 65), S(47, 119), S(68, 111), S(16, 22), S(172, -85), }},
  {{ S(1, 53), S(67, 81), S(108, 67), S(14, 16), S(454, 619), }},
}};
inline const PParam KING_THREAT  = S(-1, 157);
inline const PParam HANGING_PAWN  = S(32, 98);
inline const PParam HANGING_NON_PAWN  = S(74, 33);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(23, -18), S(104, -84),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(50, 38), S(220, -243),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(41, 11), S(134, -117),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -18), S(3, -15), S(-1, -23), S(-7, -30), S(-13, -38), S(-19, -43), S(-20, -54), S(-26, -49), S(-22, -102),
};

inline const PParam ROOK_LINEUP = S(17, 92);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(203, 284),    S(70, 408),     S(83, 393),     S(186, 277),    S(196, 195),    S(161, 227),    S(142, 252),    S(233, 206),    //
    S(59, 68),      S(68, 107),     S(55, 60),      S(64, -6),      S(55, -44),     S(25, -13),     S(21, 33),      S(-17, 67),     //
    S(39, -1),      S(14, 4),       S(50, -37),     S(30, -62),     S(15, -78),     S(-3, -64),     S(-44, -34),    S(-46, 10),     //
    S(-8, -63),     S(-35, -34),    S(2, -53),      S(-12, -71),    S(-35, -82),    S(-46, -63),    S(-93, -46),    S(-90, -39),    //
    S(-16, -102),   S(16, -96),     S(-0, -29),     S(-20, -34),    S(-46, -45),    S(-67, -52),    S(-94, -56),    S(-100, -59),   //
    S(10, -99),     S(91, -86),     S(80, -26),     S(25, 10),      S(-6, -16),     S(-32, -41),    S(-58, -46),    S(-74, -44),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-305, -469),  S(-248, 52),    S(-300, 136),   S(32, 52),      S(-78, 68),     S(-310, 137),   S(-342, 118),   S(-401, -376),  //
    S(6, 15),       S(-7, 55),      S(85, 38),      S(86, 94),      S(100, 72),     S(51, 48),      S(-7, 39),      S(-52, 45),     //
    S(37, -4),      S(45, 49),      S(51, 79),      S(74, 100),     S(58, 98),      S(13, 88),      S(-4, 64),      S(-45, 27),     //
    S(88, 50),      S(94, 65),      S(96, 95),      S(108, 130),    S(109, 122),    S(72, 92),      S(50, 49),      S(18, 63),      //
    S(72, 43),      S(94, 24),      S(102, 67),     S(87, 108),     S(82, 106),     S(63, 92),      S(48, 45),      S(14, 38),      //
    S(10, -26),     S(40, -12),     S(48, 37),      S(60, 74),      S(54, 77),      S(24, 33),      S(3, 4),        S(-39, -24),    //
    S(24, 2),       S(21, 23),      S(18, -4),      S(29, 29),      S(23, 30),      S(-7, -22),     S(-52, 27),     S(-71, -62),    //
    S(-63, -80),    S(-3, -14),     S(16, -20),     S(35, -11),     S(18, -1),      S(-26, -33),    S(-42, 4),      S(-101, -122),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-127, 25),    S(-229, 144),   S(-423, 224),   S(-279, 138),   S(-286, 157),   S(-270, 174),   S(-196, 137),   S(-158, 132),   //
    S(-39, 17),     S(-79, 131),    S(-60, 111),    S(-66, 104),    S(-60, 111),    S(-37, 81),     S(-22, 77),     S(-65, 64),     //
    S(40, 49),      S(21, 85),      S(28, 102),     S(23, 92),      S(25, 74),      S(13, 90),      S(-4, 84),      S(13, 28),      //
    S(10, 23),      S(50, 56),      S(65, 63),      S(87, 88),      S(101, 82),     S(39, 61),      S(35, 42),      S(-8, 34),      //
    S(36, -10),     S(36, 42),      S(75, 46),      S(90, 66),      S(76, 74),      S(61, 64),      S(12, 46),      S(-1, 3),       //
    S(51, 10),      S(78, 8),       S(92, 35),      S(63, 62),      S(57, 53),      S(50, 51),      S(54, 32),      S(16, 4),       //
    S(23, -39),     S(111, -29),    S(55, 19),      S(37, 38),      S(23, 36),      S(38, -12),     S(39, -22),     S(28, -10),     //
    S(30, -40),     S(16, 5),       S(19, 27),      S(33, 5),       S(17, 11),      S(31, 45),      S(36, 13),      S(30, -32),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(173, 180),    S(198, 196),    S(159, 230),    S(144, 196),    S(194, 164),    S(146, 188),    S(164, 204),    S(157, 192),    //
    S(98, 217),     S(141, 225),    S(197, 179),    S(147, 177),    S(186, 166),    S(150, 189),    S(96, 225),     S(86, 228),     //
    S(73, 202),     S(188, 144),    S(228, 121),    S(186, 110),    S(185, 134),    S(119, 177),    S(102, 204),    S(58, 239),     //
    S(33, 177),     S(96, 188),     S(107, 166),    S(93, 159),     S(117, 145),    S(81, 187),     S(63, 210),     S(14, 229),     //
    S(3, 113),      S(61, 123),     S(46, 155),     S(12, 163),     S(25, 162),     S(16, 185),     S(-3, 191),     S(-31, 195),    //
    S(6, 39),       S(86, 52),      S(65, 86),      S(39, 105),     S(47, 112),     S(29, 131),     S(24, 116),     S(-22, 127),    //
    S(-73, 32),     S(56, -12),     S(59, 30),      S(44, 72),      S(50, 69),      S(33, 82),      S(22, 70),      S(-10, 63),     //
    S(-9, -2),      S(12, 35),      S(79, 25),      S(88, 25),      S(91, 32),      S(65, 58),      S(59, 49),      S(37, 54),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(121, 226),    S(190, 213),    S(94, 363),     S(60, 418),     S(64, 430),     S(123, 315),    S(88, 270),     S(36, 293),     //
    S(83, 262),     S(86, 322),     S(59, 393),     S(-46, 487),    S(-7, 474),     S(52, 339),     S(76, 264),     S(60, 225),     //
    S(58, 272),     S(108, 298),    S(65, 388),     S(36, 407),     S(47, 420),     S(75, 341),     S(113, 225),    S(88, 196),     //
    S(51, 226),     S(59, 295),     S(17, 363),     S(19, 420),     S(38, 416),     S(39, 318),     S(81, 241),     S(60, 202),     //
    S(32, 219),     S(36, 217),     S(32, 266),     S(3, 348),      S(4, 389),      S(31, 315),     S(32, 260),     S(50, 174),     //
    S(26, 123),     S(61, 109),     S(53, 197),     S(24, 235),     S(35, 246),     S(31, 287),     S(50, 220),     S(35, 193),     //
    S(-14, -26),    S(23, -42),     S(28, 39),      S(53, 92),      S(48, 138),     S(50, 111),     S(23, 154),     S(39, 119),     //
    S(-44, 3),      S(3, -196),     S(28, -168),    S(37, -53),     S(52, 22),      S(48, 14),      S(46, 21),      S(12, 88),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(111, -442),   S(491, 120),    S(446, 140),    S(66, 198),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(330, -170),   S(333, 192),    S(230, 181),    S(16, 135),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(187, 29),     S(204, 168),    S(74, 190),     S(-103, 175),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, 6),       S(106, 96),     S(-57, 170),    S(-179, 204),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-124, -3),    S(-48, 81),     S(-111, 152),   S(-226, 205),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-64, -29),    S(-4, 39),      S(-91, 127),    S(-152, 169),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(33, -102),    S(35, -17),     S(-33, 51),     S(-116, 111),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -213),   S(12, -98),     S(-70, -30),    S(-74, -51),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-89, -437);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -2), S(12, 15), S(12, 7), S(5, 3), S(3, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -7), S(6, 6), S(3, 2), S(3, 1), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -14), S(-10, 7), S(-5, -9), S(6, -13), S(15, -31), S(8, -55), S(-4, -52), }},
  {{ S(1, 10), S(-25, 5), S(-21, 13), S(-13, 22), S(-8, 12), S(-10, -15), S(-23, -24), }},
  {{ S(-6, 4), S(-15, -4), S(-16, 23), S(-10, 24), S(-8, 12), S(-9, -13), S(-23, -52), }},
  {{ S(7, 12), S(-12, 19), S(-8, 44), S(-2, 49), S(-2, 45), S(2, 26), S(16, -18), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 28), S(-8, 6), S(-9, 12), S(-9, 35), S(3, 54),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 15), S(-55, -115), S(-11, -41), S(2, 1), S(-4, 6), S(-7, 12), S(-7, 12), }},
  {{ S(10, 0), S(-31, -108), S(-7, -41), S(-3, -1), S(-2, -3), S(-12, 4), S(0, 4), }},
  {{ S(0, 14), S(-5, -81), S(8, -9), S(2, 8), S(-4, 15), S(-11, 22), S(-6, 24), }},
  {{ S(0, 2), S(2, -65), S(0, 26), S(-4, 35), S(-8, 13), S(-15, 12), S(-11, 21), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1151, 897, -25, 3
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(92);
inline VParam WINNABLE_PAWN_ENDGAME = V(49);
inline VParam WINNABLE_BIAS = V(-383);

// Epoch duration: 4.48049s - K: 0.0025
// clang-format on
}  // namespace Clockwork
