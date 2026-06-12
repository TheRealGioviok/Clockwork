#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(194, 504);
inline const PParam KNIGHT_MAT = S(783, 1583);
inline const PParam BISHOP_MAT = S(819, 1661);
inline const PParam ROOK_MAT   = S(968, 2611);
inline const PParam QUEEN_MAT  = S(2224, 3959);

inline const PParam TEMPO_VAL  = S(69, 49);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -4);
inline const PParam BISHOP_PAIR_VAL   = S(65, 229);
inline const PParam ROOK_OPEN_VAL     = S(110, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 13);
inline const PParam MINOR_BEHIND_PAWN = S(15, 38);
inline const PParam RESTRICTED_SQUARES = S(20, 4);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -82);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -36);

inline const PParam POTENTIAL_CHECKER_VAL = S(-44, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 41);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 49);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(22, 59);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -54);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -0), S(31, 36), S(61, 62), S(129, 193), S(436, 271), S(712, 713),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 34), S(38, 25), S(56, 53), S(101, 167), S(409, 88),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-88, -255), S(-88, -220), S(-66, -82), S(-25, 54), S(75, 246), S(229, 408),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -40), S(25, -0), S(12, 41), S(10, 121), S(77, 246), S(95, 463),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -37), S(1, 10), S(-4, -23), S(-2, -58), S(-11, -164), S(-169, -331),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(12, 232), S(-0, 184), S(-3, 108), S(8, 66), S(18, 69), S(57, 69), S(52, 43),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-137, -65), S(14, -1), S(1, 101), S(28, 151), S(41, 187), S(54, 192), S(35, 181),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-60, -412), S(0, -172), S(29, -54), S(54, -8), S(82, 23), S(97, 59), S(115, 67), S(134, 75), S(153, 30),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-31, -317), S(16, -135), S(65, -60), S(87, -10), S(108, 30), S(119, 59), S(124, 82), S(127, 102), S(130, 115), S(136, 122), S(142, 119), S(162, 100), S(162, 102), S(145, 73),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(133, -211), S(48, -23), S(69, 9), S(85, 26), S(95, 44), S(99, 58), S(103, 73), S(109, 78), S(113, 91), S(119, 97), S(124, 101), S(126, 109), S(128, 114), S(131, 104), S(155, 60),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-99, -394), S(25, -103), S(49, 28), S(71, 152), S(87, 193), S(93, 245), S(100, 278), S(106, 294), S(110, 319), S(113, 336), S(119, 344), S(122, 353), S(125, 360), S(128, 365), S(128, 368), S(127, 372), S(123, 372), S(127, 364), S(125, 365), S(127, 359), S(122, 344), S(126, 326), S(89, 357), S(35, 354), S(-0, 362), S(-35, 385), S(-121, 443), S(-71, 362),
};

inline const PParam PAWN_THREAT_KNIGHT = S(194, 146);
inline const PParam PAWN_THREAT_BISHOP = S(170, 211);
inline const PParam PAWN_THREAT_ROOK   = S(196, 134);
inline const PParam PAWN_THREAT_QUEEN  = S(154, 20);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(6, 56), S(91, 91), S(102, 123), S(203, 122), S(159, 9), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 57), S(52, 93), S(72, 94), S(21, -5), S(148, -52), S(0, 0),
};
inline const PParam KING_THREAT  = S(-17, 156);
inline const PParam HANGING_PAWN  = S(32, 87);
inline const PParam HANGING_NON_PAWN  = S(69, 21);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -19), S(15, 13),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(40, 45), S(93, -80),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(36, 13), S(50, -9),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -16), S(4, -14), S(-0, -21), S(-6, -29), S(-12, -36), S(-16, -43), S(-18, -56), S(-24, -59), S(-28, -74),
};

inline const PParam ROOK_LINEUP = S(17, 78);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(179, 284),    S(35, 398),     S(51, 372),     S(138, 264),    S(186, 168),    S(116, 231),    S(83, 273),     S(223, 206),    //
    S(38, 68),      S(48, 111),     S(28, 52),      S(47, -26),     S(39, -58),     S(11, -21),     S(7, 32),       S(-20, 61),     //
    S(36, -10),     S(12, -3),      S(41, -48),     S(28, -72),     S(20, -90),     S(1, -75),      S(-38, -38),    S(-38, -0),     //
    S(-5, -73),     S(-30, -43),    S(3, -65),      S(-4, -78),     S(-25, -88),    S(-34, -76),    S(-81, -55),    S(-74, -52),    //
    S(-10, -110),   S(23, -109),    S(10, -51),     S(-4, -58),     S(-31, -67),    S(-46, -77),    S(-76, -72),    S(-78, -75),    //
    S(11, -107),    S(85, -98),     S(74, -49),     S(32, -25),     S(1, -44),      S(-18, -68),    S(-45, -60),    S(-58, -58),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-241, -508),  S(-238, 43),    S(-260, -78),   S(42, 11),      S(-78, 29),     S(-244, 58),    S(-348, 102),   S(-330, -408),  //
    S(9, -17),      S(16, 22),      S(110, 8),      S(94, 44),      S(101, 33),     S(70, 9),       S(-10, 17),     S(-13, 4),      //
    S(65, -42),     S(52, 19),      S(84, 36),      S(85, 59),      S(75, 55),      S(37, 43),      S(25, 20),      S(-25, 5),      //
    S(111, 12),     S(104, 39),     S(117, 53),     S(114, 99),     S(120, 98),     S(85, 62),      S(66, 29),      S(54, 22),      //
    S(93, 4),       S(119, -7),     S(112, 40),     S(106, 70),     S(92, 72),      S(88, 54),      S(77, 1),       S(39, 19),      //
    S(33, -48),     S(60, -28),     S(63, 12),      S(77, 46),      S(71, 44),      S(46, 6),       S(32, -20),     S(-8, -45),     //
    S(58, -38),     S(59, -22),     S(43, -23),     S(51, 3),       S(48, -2),      S(21, -49),     S(-12, -14),    S(-20, -103),   //
    S(-25, -85),    S(24, -32),     S(43, -50),     S(62, -38),     S(42, -20),     S(5, -56),      S(-2, -32),     S(-46, -139),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-108, 17),    S(-157, 100),   S(-402, 172),   S(-239, 76),    S(-277, 135),   S(-278, 140),   S(-193, 119),   S(-103, 60),    //
    S(-10, -21),    S(-56, 85),     S(-16, 47),     S(-50, 62),     S(-47, 65),     S(-14, 35),     S(12, 32),      S(-23, 12),     //
    S(54, 19),      S(34, 56),      S(52, 64),      S(46, 54),      S(41, 38),      S(38, 42),      S(32, 40),      S(37, 8),       //
    S(35, -8),      S(71, 16),      S(83, 32),      S(94, 53),      S(120, 39),     S(65, 14),      S(71, -12),     S(22, -10),     //
    S(62, -50),     S(66, -2),      S(98, 8),       S(113, 19),     S(96, 36),      S(90, 16),      S(41, 2),       S(40, -42),     //
    S(80, -36),     S(103, -31),    S(117, -2),     S(85, 26),      S(84, 8),       S(80, 10),      S(86, -11),     S(39, -24),     //
    S(49, -84),     S(135, -57),    S(90, -22),     S(69, -6),      S(51, -3),      S(73, -49),     S(70, -56),     S(63, -60),     //
    S(70, -83),     S(38, -16),     S(46, -11),     S(68, -37),     S(50, -26),     S(56, 10),      S(65, -23),     S(62, -61),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(214, 81),     S(247, 97),     S(190, 126),    S(174, 109),    S(243, 57),     S(203, 83),     S(216, 89),     S(190, 94),     //
    S(118, 138),    S(170, 139),    S(228, 102),    S(171, 105),    S(214, 84),     S(176, 109),    S(124, 140),    S(121, 140),    //
    S(83, 135),     S(203, 81),     S(227, 64),     S(204, 46),     S(205, 65),     S(145, 105),    S(147, 114),    S(94, 154),     //
    S(56, 104),     S(118, 109),    S(145, 81),     S(118, 87),     S(150, 68),     S(110, 114),    S(103, 122),    S(48, 147),     //
    S(23, 49),      S(88, 53),      S(81, 69),      S(51, 79),      S(62, 84),      S(51, 110),     S(33, 109),     S(12, 112),     //
    S(36, -28),     S(104, -4),     S(95, 18),      S(74, 27),      S(86, 34),      S(58, 62),      S(59, 45),      S(16, 53),      //
    S(-45, -27),    S(84, -65),     S(89, -29),     S(78, 3),       S(82, 1),       S(66, 19),      S(55, 3),       S(25, 10),      //
    S(17, -49),     S(32, -8),      S(103, -26),    S(113, -29),    S(113, -22),    S(90, 3),       S(88, -8),      S(69, -2),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(111, 143),    S(188, 111),    S(85, 270),     S(27, 369),     S(75, 308),     S(109, 215),    S(105, 137),    S(48, 183),     //
    S(95, 164),     S(121, 192),    S(80, 279),     S(-56, 413),    S(-1, 368),     S(50, 262),     S(98, 125),     S(70, 124),     //
    S(48, 226),     S(86, 252),     S(47, 341),     S(10, 373),     S(38, 343),     S(91, 215),     S(121, 120),    S(102, 74),     //
    S(50, 151),     S(51, 235),     S(19, 287),     S(10, 349),     S(28, 344),     S(61, 206),     S(99, 115),     S(68, 94),      //
    S(44, 139),     S(40, 163),     S(29, 213),     S(6, 275),      S(21, 288),     S(46, 213),     S(51, 146),     S(74, 54),      //
    S(37, 41),      S(66, 53),      S(63, 125),     S(43, 142),     S(53, 147),     S(56, 170),     S(77, 96),      S(55, 77),      //
    S(9, -102),     S(40, -99),     S(46, -26),     S(72, 6),       S(68, 44),      S(71, 19),      S(45, 50),      S(58, 26),      //
    S(-0, -90),     S(16, -234),    S(47, -238),    S(63, -132),    S(71, -57),     S(70, -89),     S(67, -66),     S(39, -21),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(272, -668),   S(575, -51),    S(351, 143),    S(33, 141),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(415, -210),   S(428, 115),    S(246, 166),    S(49, 129),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(222, 32),     S(260, 151),    S(145, 186),    S(-20, 165),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(38, 6),       S(114, 112),    S(1, 159),      S(-78, 179),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-107, -0),    S(-20, 78),     S(-77, 142),    S(-162, 189),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -26),    S(14, 38),      S(-69, 119),    S(-119, 162),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(13, -72),     S(21, 3),       S(-41, 64),     S(-116, 119),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-31, -186),   S(-7, -71),     S(-90, -5),     S(-87, -25),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-81, -544);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -5), S(9, 8), S(9, 3), S(4, 1), S(3, -8),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(4, 3), S(2, 1), S(3, -1), S(3, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -16), S(-7, 6), S(-3, -7), S(6, -13), S(10, -21), S(5, -40), S(-4, -34), }},
  {{ S(1, 1), S(-20, 1), S(-16, 7), S(-10, 13), S(-7, 7), S(-10, -7), S(-17, -19), }},
  {{ S(-3, -2), S(-11, -8), S(-12, 14), S(-8, 15), S(-7, 8), S(-7, -11), S(-21, -34), }},
  {{ S(6, 4), S(-9, 12), S(-7, 29), S(-3, 33), S(-2, 27), S(4, 9), S(7, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(8, 20), S(-5, 3), S(-7, 9), S(-5, 22), S(1, 35),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 8), S(-37, -68), S(-8, -28), S(-1, 4), S(-2, 3), S(-5, 8), S(-4, 7), }},
  {{ S(8, -1), S(-18, -102), S(-5, -22), S(-4, 3), S(-1, -2), S(-7, 4), S(1, 2), }},
  {{ S(-0, 8), S(-8, -54), S(5, -9), S(-1, 9), S(-3, 9), S(-9, 16), S(-5, 17), }},
  {{ S(1, 2), S(1, -39), S(-2, 23), S(-3, 22), S(-6, 10), S(-11, 12), S(-10, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1633, 1089, -21, -4
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(83);
inline VParam WINNABLE_PAWN_ENDGAME = V(105);
inline VParam WINNABLE_BIAS = V(-371);

// Epoch duration: 6.26926s
// clang-format on
}  // namespace Clockwork
