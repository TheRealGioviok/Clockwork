#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(197, 500);
inline const PParam KNIGHT_MAT = S(827, 1542);
inline const PParam BISHOP_MAT = S(870, 1626);
inline const PParam ROOK_MAT   = S(1032, 2550);
inline const PParam QUEEN_MAT  = S(2454, 3873);

inline const PParam TEMPO_VAL  = S(69, 50);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -4);
inline const PParam BISHOP_PAIR_VAL   = S(64, 230);
inline const PParam ROOK_OPEN_VAL     = S(109, -2);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 13);
inline const PParam MINOR_BEHIND_PAWN = S(16, 38);
inline const PParam RESTRICTED_SQUARES = S(20, 4);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -82);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -36);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 42);
inline const PParam OUTPOST_BISHOP_VAL    = S(41, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 48);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(22, 59);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, 0), S(32, 36), S(60, 62), S(128, 194), S(441, 263), S(567, 549),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 34), S(38, 25), S(54, 54), S(99, 170), S(410, 90),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-86, -270), S(-87, -234), S(-64, -96), S(-25, 42), S(71, 237), S(216, 412),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -39), S(25, -1), S(12, 41), S(11, 121), S(77, 247), S(107, 454),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -37), S(2, 9), S(-5, -23), S(-1, -59), S(-9, -167), S(-169, -335),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 240), S(1, 192), S(-2, 116), S(9, 73), S(20, 77), S(59, 75), S(54, 50),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-139, -60), S(15, 4), S(0, 107), S(25, 158), S(38, 194), S(51, 199), S(31, 190),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-83, -373), S(-5, -117), S(3, -16), S(23, 28), S(49, 60), S(64, 96), S(82, 104), S(101, 113), S(120, 67),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-65, -284), S(-7, -95), S(36, -24), S(56, 21), S(75, 61), S(86, 90), S(91, 112), S(94, 132), S(97, 145), S(103, 152), S(110, 148), S(129, 130), S(131, 130), S(112, 103),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(119, -188), S(11, 19), S(43, 51), S(63, 60), S(72, 76), S(75, 90), S(80, 106), S(86, 111), S(90, 123), S(96, 130), S(101, 134), S(103, 142), S(105, 146), S(108, 137), S(133, 92),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-208, -165), S(-52, 115), S(-34, 206), S(-0, 262), S(14, 291), S(19, 344), S(26, 377), S(32, 393), S(36, 417), S(39, 435), S(44, 444), S(48, 451), S(52, 457), S(54, 462), S(55, 466), S(54, 468), S(51, 468), S(56, 458), S(55, 458), S(58, 451), S(55, 434), S(59, 416), S(27, 442), S(-17, 430), S(-47, 432), S(-76, 449), S(-119, 461), S(-86, 389),
};

inline const std::array<PParam, 5> KNIGHT_TRAP_FACTOR = {
    S(-73, -38), S(-37, -96), S(-35, -74), S(-37, -59), S(-47, -38),
};
inline const std::array<PParam, 5> BISHOP_TRAP_FACTOR = {
    S(-10, 14), S(-33, -39), S(-12, -36), S(-16, -31), S(-14, -13),
};
inline const std::array<PParam, 6> ROOK_TRAP_FACTOR = {
    S(31, -7), S(30, -42), S(-10, -39), S(7, -6), S(-12, -12), S(-7, -9),
};
inline const std::array<PParam, 9> QUEEN_TRAP_FACTOR = {
    S(3, -199), S(47, -147), S(18, -207), S(-23, -136), S(-18, -117), S(-20, -46), S(-15, -21), S(-11, -63), S(1, -60),
};

inline const PParam PAWN_THREAT_KNIGHT = S(194, 147);
inline const PParam PAWN_THREAT_BISHOP = S(170, 212);
inline const PParam PAWN_THREAT_ROOK   = S(195, 137);
inline const PParam PAWN_THREAT_QUEEN  = S(155, 17);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(6, 56), S(90, 91), S(102, 124), S(203, 123), S(158, 11), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 56), S(52, 93), S(72, 94), S(21, -6), S(148, -51), S(0, 0),
};
inline const PParam KING_THREAT  = S(-19, 157);
inline const PParam HANGING_PAWN  = S(32, 88);
inline const PParam HANGING_NON_PAWN  = S(69, 22);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -19), S(26, -1),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(40, 46), S(123, -120),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(36, 12), S(51, -9),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -16), S(4, -14), S(-0, -21), S(-5, -29), S(-11, -37), S(-16, -44), S(-18, -56), S(-23, -60), S(-27, -74),
};

inline const PParam ROOK_LINEUP = S(17, 78);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(188, 277),    S(42, 392),     S(66, 362),     S(146, 259),    S(196, 159),    S(123, 226),    S(88, 269),     S(229, 202),    //
    S(38, 70),      S(50, 111),     S(29, 54),      S(46, -23),     S(37, -56),     S(9, -16),      S(6, 36),       S(-23, 66),     //
    S(33, -5),      S(9, 2),        S(40, -44),     S(26, -67),     S(16, -85),     S(-3, -69),     S(-41, -32),    S(-42, 6),      //
    S(-8, -68),     S(-32, -38),    S(2, -60),      S(-6, -73),     S(-28, -83),    S(-38, -70),    S(-86, -48),    S(-79, -45),    //
    S(-11, -107),   S(21, -104),    S(9, -46),      S(-7, -52),     S(-35, -61),    S(-50, -70),    S(-81, -65),    S(-82, -69),    //
    S(10, -104),    S(86, -95),     S(72, -43),     S(30, -19),     S(-2, -39),     S(-22, -62),    S(-49, -54),    S(-63, -52),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-274, -510),  S(-258, 55),    S(-270, -72),   S(33, 17),      S(-93, 41),     S(-262, 74),    S(-377, 123),   S(-368, -402),  //
    S(-6, -4),      S(0, 37),       S(97, 20),      S(80, 56),      S(85, 49),      S(55, 23),      S(-27, 30),     S(-30, 18),     //
    S(47, -28),     S(38, 31),      S(70, 48),      S(71, 71),      S(61, 67),      S(21, 56),      S(9, 34),       S(-43, 20),     //
    S(94, 26),      S(89, 51),      S(102, 66),     S(100, 111),    S(104, 112),    S(69, 76),      S(50, 44),      S(35, 39),      //
    S(73, 18),      S(103, 7),      S(98, 52),      S(91, 84),      S(77, 86),      S(73, 67),      S(60, 16),      S(18, 35),      //
    S(21, -33),     S(49, -18),     S(51, 24),      S(63, 59),      S(58, 56),      S(32, 18),      S(17, -7),      S(-23, -29),    //
    S(44, -23),     S(44, -7),      S(30, -11),     S(37, 15),      S(34, 11),      S(7, -37),      S(-27, 0),      S(-36, -87),    //
    S(-56, -72),    S(6, -20),      S(27, -36),     S(40, -21),     S(23, -5),      S(-14, -39),    S(-22, -19),    S(-76, -128),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-131, 29),    S(-181, 115),   S(-423, 187),   S(-257, 88),    S(-291, 142),   S(-297, 152),   S(-212, 129),   S(-125, 74),    //
    S(-31, -9),     S(-78, 100),    S(-37, 61),     S(-68, 71),     S(-67, 77),     S(-35, 48),     S(-9, 44),      S(-43, 26),     //
    S(35, 30),      S(15, 68),      S(32, 77),      S(25, 69),      S(22, 50),      S(18, 54),      S(12, 52),      S(15, 21),      //
    S(15, 5),       S(51, 28),      S(62, 47),      S(75, 67),      S(100, 52),     S(45, 26),      S(51, 1),       S(1, 4),        //
    S(43, -39),     S(47, 9),       S(78, 21),      S(94, 33),      S(76, 50),      S(68, 30),      S(21, 16),      S(18, -27),     //
    S(60, -24),     S(85, -20),     S(98, 11),      S(65, 39),      S(63, 21),      S(60, 23),      S(65, 2),       S(18, -11),     //
    S(30, -71),     S(116, -44),    S(73, -11),     S(51, 6),       S(33, 9),       S(54, -37),     S(50, -43),     S(42, -46),     //
    S(47, -69),     S(22, -7),      S(25, 1),       S(46, -23),     S(29, -12),     S(36, 22),      S(44, -10),     S(39, -48),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(191, 93),     S(221, 110),    S(163, 142),    S(149, 122),    S(216, 71),     S(177, 97),     S(190, 102),    S(165, 107),    //
    S(95, 151),     S(147, 151),    S(204, 115),    S(149, 116),    S(190, 97),     S(151, 122),    S(100, 152),    S(97, 153),     //
    S(63, 145),     S(181, 92),     S(206, 74),     S(183, 56),     S(182, 77),     S(121, 118),    S(124, 125),    S(70, 166),     //
    S(35, 115),     S(96, 121),     S(124, 92),     S(97, 97),      S(127, 81),     S(87, 125),     S(79, 135),     S(24, 159),     //
    S(3, 57),       S(67, 63),      S(61, 79),      S(30, 90),      S(39, 95),      S(28, 121),     S(10, 120),     S(-10, 123),    //
    S(17, -20),     S(84, 5),       S(74, 27),      S(54, 36),      S(64, 44),      S(36, 72),      S(37, 55),      S(-5, 62),      //
    S(-60, -22),    S(65, -58),     S(69, -19),     S(57, 13),      S(61, 11),      S(45, 28),      S(34, 11),      S(6, 17),       //
    S(-4, -41),     S(12, 1),       S(82, -16),     S(91, -19),     S(91, -12),     S(69, 12),      S(66, 2),       S(46, 7),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(78, 172),     S(151, 145),    S(62, 286),     S(7, 379),      S(51, 323),     S(80, 239),     S(72, 165),     S(10, 220),     //
    S(61, 196),     S(83, 233),     S(49, 305),     S(-84, 435),    S(-33, 395),    S(12, 300),     S(57, 170),     S(29, 171),     //
    S(20, 247),     S(57, 277),     S(20, 361),     S(-18, 395),    S(4, 374),      S(52, 257),     S(83, 161),     S(62, 120),     //
    S(19, 178),     S(21, 262),     S(-11, 310),    S(-22, 378),    S(-8, 380),     S(22, 247),     S(60, 158),     S(30, 135),     //
    S(11, 170),     S(8, 192),      S(-2, 241),     S(-27, 307),    S(-17, 329),    S(7, 256),      S(10, 191),     S(33, 102),     //
    S(4, 73),       S(33, 88),      S(29, 159),     S(7, 181),      S(15, 189),     S(17, 213),     S(37, 143),     S(16, 119),     //
    S(-24, -65),    S(4, -58),      S(12, 10),      S(35, 48),      S(31, 87),      S(32, 64),      S(6, 95),       S(15, 78),      //
    S(-36, -51),    S(-22, -189),   S(10, -195),    S(21, -80),     S(31, -10),     S(31, -44),     S(27, -19),     S(-0, 24),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(99, -576),    S(481, 5),      S(295, 177),    S(2, 153),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(340, -177),   S(376, 135),    S(207, 179),    S(19, 136),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(187, 44),     S(227, 159),    S(120, 190),    S(-38, 165),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(16, 11),      S(96, 113),     S(-17, 160),    S(-91, 177),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-115, -2),    S(-32, 78),     S(-89, 141),    S(-173, 188),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-53, -30),    S(14, 34),      S(-73, 116),    S(-125, 160),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -81),     S(29, -5),      S(-35, 57),     S(-111, 112),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -199),   S(3, -82),      S(-79, -16),    S(-79, -36),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-86, -435);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -4), S(10, 11), S(10, 5), S(5, 1), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -20), S(-6, 5), S(-2, -9), S(8, -16), S(12, -27), S(6, -54), S(-5, -45), }},
  {{ S(3, 2), S(-21, 0), S(-17, 8), S(-10, 17), S(-7, 7), S(-10, -11), S(-20, -23), }},
  {{ S(-2, -2), S(-11, -11), S(-12, 18), S(-7, 18), S(-6, 10), S(-8, -16), S(-24, -43), }},
  {{ S(7, 9), S(-10, 19), S(-7, 40), S(-2, 44), S(-2, 39), S(4, 17), S(8, -13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 25), S(-6, 3), S(-8, 11), S(-6, 28), S(2, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 11), S(-46, -143), S(-9, -45), S(-1, 5), S(-3, 4), S(-6, 11), S(-5, 9), }},
  {{ S(9, 0), S(-25, -130), S(-6, -32), S(-4, 1), S(-1, -3), S(-8, 4), S(1, 3), }},
  {{ S(-0, 10), S(-10, -82), S(6, -15), S(0, 9), S(-4, 10), S(-10, 19), S(-6, 20), }},
  {{ S(1, -1), S(2, -60), S(-1, 27), S(-3, 25), S(-6, 9), S(-12, 11), S(-10, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1362, 854, -20, -4
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(84);
inline VParam WINNABLE_PAWN_ENDGAME = V(105);
inline VParam WINNABLE_BIAS = V(-378);

// Epoch duration: 6.66072s
// clang-format on
}  // namespace Clockwork
