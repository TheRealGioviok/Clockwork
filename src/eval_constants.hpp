#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(17, 67);
inline const PParam KNIGHT_MAT = S(44, 58);
inline const PParam BISHOP_MAT = S(37, 51);
inline const PParam ROOK_MAT   = S(85, 165);
inline const PParam QUEEN_MAT  = S(143, 138);
inline const PParam TEMPO_VAL  = S(66, 16);

inline const PParam BISHOP_PAIR_VAL   = S(6, -2);
inline const PParam ROOK_OPEN_VAL     = S(114, -22);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 24);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -104);

inline const PParam POTENTIAL_CHECKER_VAL = S(-63, -17);
inline const PParam OUTPOST_KNIGHT_VAL    = S(55, 32);
inline const PParam OUTPOST_BISHOP_VAL    = S(59, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 16);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(48, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(31, 51);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -25);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, 23), S(48, 51), S(73, 90), S(165, 210), S(415, 327), S(540, 738),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(61, 55), S(54, 49), S(65, 89), S(155, 190), S(499, 117),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-70, -69), S(-67, -50), S(-42, 28), S(34, 91), S(126, 183), S(278, 219),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(35, -38), S(44, -1), S(34, 22), S(25, 72), S(82, 131), S(188, 182),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(6, -27), S(-5, 14), S(-11, -9), S(-20, -37), S(-16, -100), S(-238, -153),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(3, 106), S(-2, 80), S(-6, 37), S(-2, 14), S(4, 25), S(46, 20), S(25, -5),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-275, -26), S(-51, 28), S(-28, 56), S(29, 61), S(34, 71), S(46, 83), S(24, 90),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-188, -453), S(-106, -220), S(-67, -80), S(-36, -26), S(1, 24), S(22, 69), S(55, 82), S(91, 85), S(128, 53),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-135, -410), S(-82, -187), S(-30, -93), S(-5, -25), S(18, 28), S(32, 51), S(43, 78), S(54, 88), S(61, 98), S(85, 88), S(108, 75), S(155, 47), S(168, 39), S(209, 26),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(29, -163), S(-35, -15), S(-14, 32), S(1, 49), S(16, 76), S(20, 86), S(25, 100), S(31, 102), S(37, 113), S(44, 116), S(52, 117), S(54, 120), S(67, 120), S(84, 99), S(103, 80),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-108, -389), S(-47, -268), S(-4, -197), S(11, -104), S(29, -30), S(37, 4), S(40, 53), S(52, 59), S(50, 85), S(56, 98), S(59, 123), S(59, 120), S(73, 113), S(75, 134), S(75, 126), S(70, 133), S(70, 134), S(65, 140), S(67, 135), S(81, 127), S(89, 119), S(62, 136), S(111, 87), S(83, 94), S(175, 9), S(5, 119), S(105, 33), S(1, 89),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(669, -355), S(252, -189), S(106, -61), S(71, -21), S(22, -14), S(-35, 3), S(-84, 34), S(-135, 68), S(-183, 50),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(-12, 50), S(87, 37), S(163, -2),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(28, 57), S(22, 41), S(68, -1),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(-17, 115), S(92, 119), S(127, 135), S(218, 188), S(317, 180),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(128, 218), S(45, 207), S(-27, 177), S(-31, 110), S(84, -20), S(166, -144),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-124, 63), S(15, -6), S(-48, -15), S(45, 43), S(-45, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-27, 24), S(-20, 10), S(-19, 8), S(-14, 7), S(-19, -14),
};

inline const PParam PAWN_THREAT_KNIGHT = S(217, 116);
inline const PParam PAWN_THREAT_BISHOP = S(195, 161);
inline const PParam PAWN_THREAT_ROOK   = S(165, 163);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -15);

inline const PParam KNIGHT_THREAT_BISHOP = S(112, 89);
inline const PParam KNIGHT_THREAT_ROOK   = S(237, 35);
inline const PParam KNIGHT_THREAT_QUEEN  = S(142, -7);

inline const PParam BISHOP_THREAT_KNIGHT = S(100, 76);
inline const PParam BISHOP_THREAT_ROOK   = S(216, 101);
inline const PParam BISHOP_THREAT_QUEEN  = S(186, 82);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-0, -17), S(-2, -16), S(2, -31), S(-3, -40), S(-13, -55), S(-20, -64), S(-22, -77), S(-26, -90), S(-34, -101),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(337, 146),    S(204, 247),    S(306, 236),    S(276, 220),    S(291, 173),    S(205, 256),    S(141, 283),    S(287, 172),    //
    S(79, 82),      S(129, 124),    S(108, 96),     S(71, 89),      S(46, 66),      S(24, 86),      S(15, 114),     S(-18, 128),    //
    S(22, 57),      S(17, 81),      S(25, 42),      S(16, 32),      S(6, 16),       S(-25, 25),     S(-58, 58),     S(-75, 71),     //
    S(7, 9),        S(20, 45),      S(25, 18),      S(8, 14),       S(-18, 6),      S(-34, 11),     S(-82, 57),     S(-99, 34),     //
    S(12, -23),     S(63, -1),      S(16, 52),      S(-12, 44),     S(-42, 41),     S(-69, 35),     S(-85, 53),     S(-103, 23),    //
    S(11, -19),     S(125, 17),     S(63, 68),      S(14, 97),      S(-11, 70),     S(-31, 49),     S(-50, 56),     S(-83, 36),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-399, -213),  S(-384, 173),   S(-360, 119),   S(-97, 92),     S(-171, 106),   S(-312, 104),   S(-548, 163),   S(-414, -197),  //
    S(-82, 82),     S(-11, 54),     S(75, -10),     S(47, 37),      S(52, 23),      S(-21, 2),      S(-45, 48),     S(-81, 43),     //
    S(12, 42),      S(33, 57),      S(99, 49),      S(55, 33),      S(34, 46),      S(-28, 43),     S(-27, 9),      S(-77, 53),     //
    S(68, 80),      S(64, 55),      S(70, 53),      S(47, 88),      S(67, 82),      S(34, 55),      S(38, 30),      S(36, 48),      //
    S(54, 62),      S(93, 27),      S(83, 44),      S(73, 66),      S(54, 51),      S(63, 45),      S(53, 17),      S(12, 31),      //
    S(20, 15),      S(54, -12),     S(35, 3),       S(45, 29),      S(53, 34),      S(9, -3),       S(3, -28),      S(-30, -40),    //
    S(7, 34),       S(25, 6),       S(30, -18),     S(24, 3),       S(15, -1),      S(-11, -57),    S(-28, 1),      S(-59, -48),    //
    S(-30, -6),     S(4, 15),       S(20, 7),       S(39, 0),       S(18, 4),       S(-29, -32),    S(-31, -23),    S(-75, -85),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-143, 100),   S(-188, 90),    S(-470, 146),   S(-329, 108),   S(-284, 104),   S(-366, 116),   S(-203, 89),    S(-124, 81),    //
    S(-68, 32),     S(-103, 93),    S(-79, 49),     S(-125, 81),    S(-132, 80),    S(-88, 56),     S(-54, 42),     S(-85, 43),     //
    S(18, 49),      S(42, 17),      S(36, 60),      S(0, 61),       S(-30, 42),     S(-22, 57),     S(19, 25),      S(-9, 19),      //
    S(-3, 31),      S(6, 35),       S(40, 37),      S(28, 89),      S(37, 62),      S(-10, 46),     S(-10, 24),     S(-44, -2),     //
    S(9, -6),       S(14, 10),      S(38, 40),      S(40, 54),      S(30, 65),      S(-8, 56),      S(-41, 30),     S(-33, 11),     //
    S(27, -8),      S(51, 8),       S(73, 22),      S(30, 50),      S(21, 36),      S(27, 27),      S(30, 9),       S(-20, 3),      //
    S(8, -42),      S(89, -30),     S(59, -12),     S(27, 6),       S(13, 17),      S(10, -25),     S(19, -18),     S(1, -47),      //
    S(16, -29),     S(5, 19),       S(12, 27),      S(21, -2),      S(34, -19),     S(24, 26),      S(19, -9),      S(5, -16),      //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(152, 80),     S(178, 109),    S(150, 132),    S(171, 112),    S(165, 95),     S(128, 91),     S(136, 88),     S(134, 88),     //
    S(61, 137),     S(119, 144),    S(204, 117),    S(147, 121),    S(151, 120),    S(123, 113),    S(37, 141),     S(45, 141),     //
    S(41, 140),     S(161, 111),    S(194, 104),    S(186, 91),     S(149, 94),     S(109, 108),    S(103, 112),    S(30, 150),     //
    S(24, 134),     S(90, 146),     S(129, 123),    S(122, 109),    S(118, 112),    S(73, 125),     S(54, 130),     S(1, 141),      //
    S(-7, 94),      S(43, 116),     S(31, 121),     S(36, 94),      S(17, 102),     S(8, 125),      S(-20, 112),    S(-41, 116),    //
    S(-43, 42),     S(6, 42),       S(19, 76),      S(3, 62),       S(10, 49),      S(-11, 86),     S(-14, 70),     S(-67, 72),     //
    S(-121, 43),    S(-19, -12),    S(11, 18),      S(13, 28),      S(4, 30),       S(-7, 42),      S(-28, 20),     S(-53, 18),     //
    S(-61, -5),     S(-48, 43),     S(18, 8),       S(42, -5),      S(24, 17),      S(13, 26),      S(-0, 18),      S(-15, 4),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(29, 126),     S(77, 86),      S(92, 97),      S(25, 156),     S(42, 104),     S(29, 104),     S(78, 50),      S(-10, 107),    //
    S(64, 142),     S(16, 207),     S(32, 218),     S(-95, 259),    S(-90, 232),    S(-31, 188),    S(7, 140),      S(9, 132),      //
    S(-3, 198),     S(70, 162),     S(35, 195),     S(11, 208),     S(-26, 202),    S(-7, 164),     S(41, 93),      S(24, 91),      //
    S(79, 114),     S(70, 160),     S(48, 156),     S(37, 200),     S(17, 189),     S(28, 160),     S(68, 75),      S(59, 61),      //
    S(57, 103),     S(68, 117),     S(58, 133),     S(37, 153),     S(44, 153),     S(30, 124),     S(43, 57),      S(59, 32),      //
    S(56, 14),      S(90, 30),      S(91, 81),      S(56, 55),      S(61, 53),      S(65, 67),      S(65, 20),      S(49, 4),       //
    S(30, -92),     S(72, -171),    S(80, -94),     S(94, -43),     S(76, -23),     S(78, -52),     S(56, -9),      S(42, -14),     //
    S(0, -100),     S(37, -238),    S(35, -245),    S(85, -163),    S(79, -105),    S(85, -140),    S(67, -112),    S(22, -82),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-463, -104),  S(-104, 87),    S(-53, 76),     S(-230, 111),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-42, -20),    S(233, -7),     S(153, 49),     S(135, 49),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-80, 76),     S(214, 33),     S(256, 35),     S(179, 38),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-279, 98),    S(164, 25),     S(138, 47),     S(157, 34),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-286, 75),    S(89, 11),      S(119, 19),     S(58, 39),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-155, 44),    S(159, -9),     S(118, 21),     S(95, 35),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-9, -37),     S(177, -45),    S(127, -18),    S(52, 23),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-189, -36),   S(-20, -25),    S(-98, 7),      S(-109, -28),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 6>, 6> IMBALANCE_OWN_QUAD = {{
    {{ S(6, -2),   S(-13, 29),  S(-19, 22),  S(6, -2),    S(-5, 17),   S(19, -10) }},
    {{ S(-13, 29), S(-1, 21),   S(1, 89),    S(5, 83),    S(-11, 132), S(-49, 271) }},
    {{ S(-19, 22), S(1, 89),    S(42, -19),  S(82, -28),  S(151, -30), S(135, 66) }},
    {{ S(6, -2),   S(5, 83),    S(82, -28),  S(21, 29),   S(136, -14), S(67, 125) }},
    {{ S(-5, 17),  S(-11, 132), S(151, -30), S(136, -14), S(111, -14), S(212, 101) }},
    {{ S(19, -10), S(-49, 271), S(135, 66),  S(67, 125),  S(212, 101), S(13, 92) }},
}};

inline const std::array<std::array<PParam, 6>, 6> IMBALANCE_OPP_QUAD = {{
    {{ S(0, 0),    S(8, -8),    S(16, -21),  S(9, -36),   S(22, -5),   S(9, -4) }},
    {{ S(-8, 8),   S(0, 0),     S(20, -95),  S(24, -104), S(42, -143), S(41, -277) }},
    {{ S(-16, 21), S(-20, 95),  S(0, 0),     S(-15, 11),  S(17, 2),    S(-161, 46) }},
    {{ S(-9, 36),  S(-24, 104), S(15, -11),  S(0, 0),     S(38, -1),   S(-83, -9) }},
    {{ S(-22, 5),  S(-42, 143), S(-17, -2),  S(-38, 1),   S(0, 0),     S(-123, -9) }},
    {{ S(-9, 4),   S(-41, 277), S(161, -46), S(83, 9),    S(123, 9),   S(0, 0) }},
}};

// Epoch duration: 26.0838s
// clang-format on
}  // namespace Clockwork
