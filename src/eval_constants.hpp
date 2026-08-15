#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(204, 510);
inline const PParam KNIGHT_MAT = S(816, 1596);
inline const PParam BISHOP_MAT = S(870, 1686);
inline const PParam ROOK_MAT   = S(1040, 2675);
inline const PParam QUEEN_MAT  = S(2418, 4134);

inline const PParam TEMPO_VAL  = S(69, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(62, 241);
inline const PParam ROOK_OPEN_VAL     = S(109, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 11);
inline const PParam MINOR_BEHIND_PAWN = S(15, 41);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const std::array<PParam, 4> DOUBLED_PAWN_VAL = {
    S(-20, -158), S(-22, -103), S(-19, -73), S(-32, -48),
};
inline const std::array<PParam, 4> ISOLATED_PAWN_VAL = {
    S(-5, -14), S(-10, -42), S(-12, -40), S(-21, -58),
};

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 43);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 50);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 0), S(33, 33), S(59, 64), S(122, 212), S(395, 398), S(681, 828),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 32), S(39, 24), S(53, 54), S(91, 181), S(389, 122),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-97, -262), S(-98, -220), S(-71, -87), S(-25, 39), S(86, 200), S(229, 410),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-82, 54), S(-91, 32), S(-59, 102), S(-89, 228), S(-56, 341), S(51, 222),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-19, 67), S(-32, 59), S(-63, 107), S(-35, 136), S(72, 160), S(34, 195),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -40), S(24, 0), S(16, 35), S(21, 104), S(69, 275), S(333, 221),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -34), S(4, 9), S(-2, -25), S(0, -68), S(-14, -176), S(-169, -457),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 232), S(12, 178), S(7, 102), S(14, 62), S(19, 65), S(56, 58), S(61, 27),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-131, -46), S(16, -0), S(4, 102), S(30, 152), S(44, 185), S(53, 193), S(39, 172),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-91, -394), S(-22, -141), S(8, -25), S(32, 24), S(59, 56), S(74, 93), S(92, 101), S(111, 110), S(131, 63),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-73, -352), S(-19, -129), S(33, -40), S(57, 15), S(77, 57), S(89, 88), S(94, 111), S(97, 132), S(101, 143), S(108, 150), S(117, 143), S(131, 127), S(130, 133), S(114, 99),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -213), S(24, -10), S(45, 23), S(61, 42), S(71, 60), S(76, 74), S(80, 90), S(86, 95), S(90, 108), S(96, 116), S(100, 122), S(100, 132), S(103, 136), S(109, 123), S(127, 84),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-193, -202), S(-38, -89), S(-13, 51), S(5, 192), S(23, 235), S(30, 288), S(37, 326), S(44, 344), S(49, 367), S(52, 384), S(58, 393), S(62, 399), S(66, 406), S(68, 412), S(68, 415), S(68, 418), S(64, 419), S(67, 412), S(68, 407), S(72, 400), S(62, 391), S(74, 364), S(39, 392), S(-5, 383), S(-40, 382), S(-74, 405), S(-135, 435), S(-97, 367),
};

inline const PParam PAWN_THREAT_KNIGHT = S(196, 154);
inline const PParam PAWN_THREAT_BISHOP = S(171, 220);
inline const PParam PAWN_THREAT_ROOK   = S(190, 154);
inline const PParam PAWN_THREAT_QUEEN  = S(161, 17);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(8, 57), S(98, 95), S(104, 126), S(178, 94), S(164, 12), }},
  {{ S(6, 58), S(87, 94), S(103, 124), S(219, 614), S(148, 54), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(10, 65), S(45, 107), S(59, 112), S(12, 13), S(151, -78), }},
  {{ S(3, 50), S(62, 82), S(96, 72), S(22, 15), S(365, 898), }},
}};
inline const PParam KING_THREAT  = S(-11, 157);
inline const PParam HANGING_PAWN  = S(32, 92);
inline const PParam HANGING_NON_PAWN  = S(72, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(22, 9),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 45), S(113, -113),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 13), S(47, -4),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -18), S(4, -16), S(-0, -22), S(-6, -30), S(-12, -38), S(-17, -44), S(-19, -56), S(-24, -57), S(-30, -74),
};

inline const PParam ROOK_LINEUP = S(16, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(184, 259),    S(63, 407),     S(69, 387),     S(157, 283),    S(194, 181),    S(143, 213),    S(125, 253),    S(220, 165),    //
    S(40, 49),      S(56, 117),     S(32, 59),      S(44, 3),       S(38, -33),     S(10, -14),     S(17, 38),      S(-23, 40),     //
    S(36, -25),     S(17, 7),       S(41, -48),     S(24, -66),     S(17, -83),     S(1, -78),      S(-31, -30),    S(-40, -16),    //
    S(-8, -82),     S(-26, -29),    S(-2, -65),     S(-13, -75),    S(-32, -84),    S(-38, -78),    S(-76, -42),    S(-78, -63),    //
    S(-15, -119),   S(23, -91),     S(-1, -49),     S(-16, -49),    S(-41, -57),    S(-57, -74),    S(-74, -55),    S(-85, -84),    //
    S(7, -119),     S(87, -82),     S(67, -45),     S(21, -9),      S(-7, -29),     S(-28, -64),    S(-45, -45),    S(-65, -70),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-261, -501),  S(-257, 50),    S(-260, -34),   S(4, 40),       S(-87, 41),     S(-265, 84),    S(-346, 102),   S(-347, -407),  //
    S(0, -10),      S(5, 30),       S(86, 25),      S(82, 64),      S(89, 50),      S(51, 30),      S(-13, 26),     S(-40, 20),     //
    S(42, -25),     S(43, 30),      S(57, 63),      S(75, 72),      S(58, 74),      S(23, 58),      S(10, 37),      S(-33, 11),     //
    S(91, 22),      S(93, 47),      S(102, 69),     S(106, 110),    S(110, 108),    S(74, 73),      S(53, 40),      S(33, 33),      //
    S(79, 15),      S(102, 4),      S(101, 49),     S(96, 81),      S(82, 83),      S(74, 65),      S(59, 20),      S(25, 26),      //
    S(19, -40),     S(45, -24),     S(52, 20),      S(64, 53),      S(60, 51),      S(32, 15),      S(16, -17),     S(-23, -39),    //
    S(37, -23),     S(40, -12),     S(27, -18),     S(38, 10),      S(35, 7),       S(6, -43),      S(-30, 1),      S(-49, -81),    //
    S(-43, -93),    S(10, -29),     S(29, -43),     S(45, -33),     S(29, -18),     S(-9, -50),     S(-20, -27),    S(-71, -141),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-130, 22),    S(-191, 103),   S(-401, 168),   S(-271, 97),    S(-300, 137),   S(-302, 151),   S(-227, 128),   S(-128, 72),    //
    S(-25, -23),    S(-63, 88),     S(-46, 62),     S(-67, 59),     S(-65, 74),     S(-39, 49),     S(-7, 42),      S(-51, 25),     //
    S(34, 18),      S(16, 58),      S(30, 70),      S(26, 55),      S(22, 44),      S(20, 49),      S(9, 44),       S(11, 14),      //
    S(16, -9),      S(49, 19),      S(60, 36),      S(80, 55),      S(103, 41),     S(41, 20),      S(44, -4),      S(-1, -3),      //
    S(37, -44),     S(45, 1),       S(76, 13),      S(92, 27),      S(75, 39),      S(65, 24),      S(20, 5),       S(9, -38),      //
    S(57, -31),     S(80, -27),     S(95, 5),       S(64, 28),      S(60, 13),      S(57, 14),      S(58, -4),      S(16, -23),     //
    S(26, -74),     S(113, -58),    S(65, -20),     S(47, -2),      S(30, -2),      S(44, -43),     S(45, -58),     S(38, -51),     //
    S(43, -74),     S(22, -26),     S(30, -11),     S(43, -33),     S(27, -20),     S(37, 14),      S(43, -17),     S(39, -61),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(175, 108),    S(204, 129),    S(157, 158),    S(145, 129),    S(205, 84),     S(163, 111),    S(169, 129),    S(154, 126),    //
    S(86, 150),     S(144, 155),    S(187, 127),    S(143, 111),    S(180, 98),     S(148, 122),    S(100, 155),    S(89, 158),     //
    S(56, 144),     S(178, 85),     S(206, 70),     S(178, 55),     S(182, 73),     S(123, 113),    S(115, 132),    S(62, 170),     //
    S(30, 109),     S(94, 117),     S(113, 94),     S(99, 93),      S(127, 76),     S(86, 118),     S(76, 132),     S(20, 158),     //
    S(6, 44),       S(64, 53),      S(58, 74),      S(27, 85),      S(36, 90),      S(25, 115),     S(8, 111),      S(-13, 116),    //
    S(18, -35),     S(86, -12),     S(74, 15),      S(51, 29),      S(61, 35),      S(38, 58),      S(34, 43),      S(-4, 49),      //
    S(-62, -40),    S(63, -78),     S(68, -39),     S(57, -5),      S(61, -4),      S(46, 8),       S(36, -8),      S(5, -5),       //
    S(1, -62),      S(25, -31),     S(88, -42),     S(96, -42),     S(98, -37),     S(75, -15),     S(69, -21),     S(49, -16),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 152),     S(146, 152),    S(58, 296),     S(0, 393),      S(36, 346),     S(72, 255),     S(72, 173),     S(26, 206),     //
    S(58, 183),     S(79, 237),     S(38, 319),     S(-81, 437),    S(-39, 405),    S(20, 287),     S(60, 172),     S(40, 145),     //
    S(20, 233),     S(60, 258),     S(30, 335),     S(-7, 371),     S(12, 360),     S(52, 257),     S(82, 153),     S(63, 117),     //
    S(17, 166),     S(29, 235),     S(-12, 303),    S(-12, 360),    S(6, 350),      S(22, 236),     S(61, 152),     S(35, 116),     //
    S(14, 140),     S(10, 167),     S(2, 217),      S(-23, 287),    S(-11, 302),    S(11, 237),     S(16, 173),     S(37, 77),      //
    S(4, 48),       S(34, 59),      S(32, 133),     S(10, 157),     S(20, 164),     S(22, 186),     S(41, 114),     S(22, 93),      //
    S(-24, -94),    S(5, -95),      S(13, -27),     S(40, 12),      S(37, 53),      S(39, 24),      S(13, 64),      S(26, 35),      //
    S(-41, -81),    S(-10, -241),   S(22, -247),    S(34, -136),    S(40, -56),     S(38, -75),     S(36, -61),     S(6, -7),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(166, -562),   S(476, 82),     S(315, 195),    S(18, 195),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(369, -188),   S(367, 186),    S(213, 203),    S(27, 158),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(200, 40),     S(234, 172),    S(118, 198),    S(-46, 179),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, 5),       S(115, 111),    S(-19, 171),    S(-115, 203),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-113, -2),    S(-21, 75),     S(-83, 146),    S(-178, 197),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -35),    S(13, 32),      S(-66, 114),    S(-123, 160),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(24, -94),     S(30, -13),     S(-32, 49),     S(-108, 106),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-22, -213),   S(4, -92),      S(-73, -28),    S(-82, -42),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -447);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 1), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -17), S(-6, 5), S(-2, -9), S(7, -16), S(12, -29), S(7, -54), S(-3, -47), }},
  {{ S(2, 4), S(-20, 2), S(-16, 10), S(-10, 17), S(-6, 7), S(-9, -14), S(-19, -23), }},
  {{ S(-3, -1), S(-12, -8), S(-13, 17), S(-8, 18), S(-7, 10), S(-7, -17), S(-22, -37), }},
  {{ S(7, 9), S(-10, 19), S(-6, 39), S(-2, 43), S(-2, 39), S(4, 19), S(10, -13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 23), S(-6, 3), S(-8, 10), S(-7, 28), S(1, 49),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 11), S(-42, -114), S(-9, -38), S(-1, 4), S(-4, 4), S(-7, 10), S(-6, 9), }},
  {{ S(8, -1), S(-25, -122), S(-7, -29), S(-5, 1), S(-3, -2), S(-9, 4), S(0, 4), }},
  {{ S(-1, 11), S(-8, -70), S(6, -14), S(-1, 9), S(-4, 11), S(-10, 19), S(-6, 21), }},
  {{ S(-0, 0), S(2, -64), S(-1, 23), S(-3, 26), S(-6, 8), S(-12, 10), S(-10, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1422, 911, -21, -5
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(88);
inline VParam WINNABLE_PAWN_ENDGAME = V(75);
inline VParam WINNABLE_BIAS = V(-391);

// clang-format on
}  // namespace Clockwork
