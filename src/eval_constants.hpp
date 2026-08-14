#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(203, 512);
inline const PParam KNIGHT_MAT = S(824, 1606);
inline const PParam BISHOP_MAT = S(877, 1694);
inline const PParam ROOK_MAT   = S(1048, 2692);
inline const PParam QUEEN_MAT  = S(2433, 4166);

inline const PParam TEMPO_VAL  = S(70, 59);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -2);
inline const PParam BISHOP_PAIR_VAL   = S(63, 241);
inline const PParam ROOK_OPEN_VAL     = S(111, -5);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -82);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -43);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 51);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 71);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -2), S(34, 36), S(60, 67), S(122, 217), S(399, 407), S(683, 826),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 33), S(40, 26), S(54, 58), S(92, 183), S(391, 125),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-95, -263), S(-96, -221), S(-69, -87), S(-24, 40), S(86, 203), S(232, 412),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-82, 54), S(-92, 34), S(-58, 105), S(-87, 231), S(-52, 344), S(52, 226),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-18, 71), S(-29, 60), S(-59, 108), S(-32, 137), S(73, 162), S(32, 199),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -40), S(23, -1), S(17, 35), S(22, 105), S(71, 275), S(336, 220),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -36), S(2, 8), S(-3, -27), S(-0, -70), S(-15, -178), S(-171, -463),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 235), S(8, 183), S(3, 105), S(11, 66), S(20, 71), S(58, 67), S(62, 36),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-138, -49), S(22, -4), S(4, 102), S(30, 153), S(46, 187), S(57, 196), S(43, 177),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-93, -398), S(-24, -141), S(6, -26), S(30, 24), S(58, 57), S(73, 94), S(91, 102), S(110, 110), S(130, 63),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-73, -353), S(-18, -129), S(35, -39), S(59, 16), S(79, 59), S(92, 90), S(97, 113), S(99, 134), S(104, 146), S(111, 152), S(120, 146), S(134, 129), S(135, 132), S(122, 96),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -211), S(24, -10), S(46, 24), S(61, 43), S(72, 61), S(76, 76), S(81, 92), S(87, 98), S(91, 110), S(97, 118), S(101, 125), S(100, 135), S(104, 139), S(112, 125), S(133, 86),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-194, -207), S(-38, -90), S(-14, 53), S(5, 196), S(22, 240), S(30, 292), S(36, 332), S(43, 349), S(48, 373), S(51, 390), S(57, 399), S(61, 405), S(65, 412), S(67, 417), S(68, 420), S(67, 423), S(63, 425), S(66, 417), S(65, 415), S(70, 406), S(60, 397), S(70, 372), S(36, 399), S(-9, 390), S(-42, 388), S(-76, 411), S(-133, 436), S(-98, 373),
};

inline const PParam PAWN_THREAT_KNIGHT = S(197, 156);
inline const PParam PAWN_THREAT_BISHOP = S(173, 224);
inline const PParam PAWN_THREAT_ROOK   = S(193, 154);
inline const PParam PAWN_THREAT_QUEEN  = S(162, 24);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(8, 58), S(98, 97), S(105, 126), S(179, 96), S(165, 12), }},
  {{ S(6, 58), S(87, 95), S(105, 123), S(222, 618), S(155, 72), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(9, 65), S(42, 109), S(57, 113), S(11, 14), S(152, -79), }},
  {{ S(3, 50), S(61, 82), S(95, 71), S(24, 12), S(371, 896), }},
}};
inline const PParam KING_THREAT  = S(-6, 156);
inline const PParam HANGING_PAWN  = S(32, 94);
inline const PParam HANGING_NON_PAWN  = S(72, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(22, -17), S(21, 10),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(43, 47), S(114, -114),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 12), S(49, -8),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -18), S(4, -15), S(-1, -22), S(-6, -29), S(-12, -37), S(-17, -43), S(-19, -55), S(-25, -57), S(-31, -74),
};

inline const PParam ROOK_LINEUP = S(17, 83);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(186, 278),    S(64, 402),     S(68, 391),     S(157, 272),    S(193, 169),    S(144, 213),    S(125, 241),    S(224, 182),    //
    S(42, 63),      S(59, 108),     S(36, 60),      S(50, -8),      S(41, -44),     S(14, -15),     S(17, 25),      S(-20, 53),     //
    S(39, -14),     S(16, -5),      S(45, -46),     S(26, -70),     S(18, -88),     S(4, -76),      S(-36, -45),    S(-38, -5),     //
    S(-6, -73),     S(-31, -43),    S(1, -62),      S(-10, -78),    S(-31, -88),    S(-36, -76),    S(-83, -58),    S(-77, -53),    //
    S(-14, -112),   S(18, -107),    S(3, -45),      S(-13, -51),    S(-40, -61),    S(-53, -72),    S(-80, -73),    S(-83, -75),    //
    S(9, -108),     S(82, -94),     S(71, -39),     S(24, -10),     S(-5, -32),     S(-24, -60),    S(-50, -59),    S(-63, -58),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-269, -503),  S(-262, 50),    S(-272, -29),   S(-12, 45),     S(-100, 43),    S(-272, 83),    S(-351, 101),   S(-353, -408),  //
    S(-4, -9),      S(2, 28),       S(82, 25),      S(82, 61),      S(86, 50),      S(50, 29),      S(-16, 27),     S(-45, 23),     //
    S(41, -25),     S(51, 24),      S(64, 58),      S(81, 66),      S(60, 70),      S(26, 56),      S(14, 32),      S(-35, 11),     //
    S(87, 24),      S(98, 44),      S(104, 68),     S(106, 107),    S(110, 107),    S(75, 72),      S(55, 37),      S(30, 34),      //
    S(78, 15),      S(103, 4),      S(100, 50),     S(96, 81),      S(82, 84),      S(74, 64),      S(60, 19),      S(24, 26),      //
    S(18, -39),     S(44, -24),     S(51, 22),      S(64, 54),      S(60, 52),      S(32, 15),      S(15, -17),     S(-24, -40),    //
    S(37, -21),     S(42, -10),     S(29, -18),     S(39, 10),      S(35, 8),       S(5, -43),      S(-30, 1),      S(-50, -82),    //
    S(-44, -92),    S(10, -27),     S(29, -41),     S(46, -31),     S(29, -18),     S(-9, -50),     S(-20, -26),    S(-72, -141),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-133, 22),    S(-194, 103),   S(-405, 168),   S(-276, 99),    S(-308, 141),   S(-307, 153),   S(-228, 128),   S(-130, 72),    //
    S(-28, -20),    S(-64, 88),     S(-46, 62),     S(-68, 59),     S(-66, 74),     S(-40, 49),     S(-9, 42),      S(-53, 25),     //
    S(37, 15),      S(20, 57),      S(35, 66),      S(28, 53),      S(24, 40),      S(23, 45),      S(12, 40),      S(12, 12),      //
    S(15, -6),      S(49, 20),      S(60, 36),      S(80, 54),      S(104, 39),     S(41, 20),      S(45, -4),      S(-3, -2),      //
    S(36, -45),     S(43, 3),       S(75, 13),      S(91, 27),      S(74, 38),      S(65, 25),      S(18, 7),       S(8, -37),      //
    S(56, -29),     S(80, -24),     S(96, 6),       S(63, 29),      S(60, 14),      S(57, 14),      S(58, -4),      S(16, -22),     //
    S(26, -74),     S(114, -57),    S(66, -19),     S(47, -1),      S(30, -1),      S(44, -43),     S(44, -57),     S(37, -51),     //
    S(43, -72),     S(22, -22),     S(30, -9),      S(44, -32),     S(27, -19),     S(36, 15),      S(43, -16),     S(39, -62),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(177, 108),    S(205, 130),    S(159, 159),    S(145, 131),    S(205, 86),     S(163, 113),    S(169, 131),    S(154, 128),    //
    S(85, 152),     S(142, 156),    S(182, 130),    S(137, 115),    S(174, 101),    S(142, 126),    S(96, 158),     S(86, 160),     //
    S(56, 146),     S(176, 89),     S(202, 72),     S(173, 59),     S(178, 75),     S(119, 115),    S(114, 132),    S(62, 171),     //
    S(30, 111),     S(90, 121),     S(111, 95),     S(97, 94),      S(125, 76),     S(85, 118),     S(75, 133),     S(21, 158),     //
    S(5, 45),       S(61, 56),      S(55, 77),      S(26, 85),      S(35, 91),      S(24, 115),     S(7, 112),      S(-13, 116),    //
    S(17, -35),     S(84, -10),     S(72, 16),      S(51, 28),      S(61, 35),      S(37, 58),      S(33, 43),      S(-4, 47),      //
    S(-63, -41),    S(65, -78),     S(69, -39),     S(57, -5),      S(61, -6),      S(45, 8),       S(36, -8),      S(5, -5),       //
    S(0, -63),      S(24, -31),     S(87, -43),     S(96, -43),     S(98, -38),     S(74, -16),     S(69, -22),     S(48, -16),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(88, 161),     S(146, 158),    S(58, 303),     S(-1, 402),     S(38, 351),     S(75, 258),     S(75, 174),     S(27, 209),     //
    S(58, 186),     S(78, 240),     S(37, 326),     S(-82, 442),    S(-38, 407),    S(19, 290),     S(59, 176),     S(41, 147),     //
    S(21, 236),     S(62, 261),     S(31, 339),     S(-10, 377),    S(10, 364),     S(53, 259),     S(84, 155),     S(63, 122),     //
    S(15, 174),     S(27, 243),     S(-15, 309),    S(-15, 363),    S(4, 351),      S(21, 238),     S(60, 159),     S(34, 121),     //
    S(12, 147),     S(9, 169),      S(1, 217),      S(-24, 287),    S(-12, 303),    S(11, 236),     S(16, 174),     S(37, 80),      //
    S(2, 52),       S(34, 60),      S(31, 135),     S(9, 158),      S(20, 164),     S(23, 186),     S(42, 115),     S(21, 94),      //
    S(-24, -95),    S(5, -92),      S(13, -24),     S(40, 16),      S(37, 55),      S(39, 25),      S(13, 65),      S(25, 38),      //
    S(-43, -77),    S(-12, -236),   S(21, -242),    S(33, -132),    S(40, -53),     S(38, -73),     S(37, -61),     S(6, -5),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(170, -556),   S(483, 87),     S(325, 197),    S(28, 194),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(373, -182),   S(369, 191),    S(217, 204),    S(30, 157),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(203, 46),     S(234, 177),    S(118, 200),    S(-47, 180),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(43, 8),       S(117, 114),    S(-15, 172),    S(-109, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-110, -2),    S(-21, 77),     S(-77, 145),    S(-173, 197),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-51, -37),    S(13, 32),      S(-65, 114),    S(-120, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -94),     S(26, -12),     S(-36, 50),     S(-113, 108),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -214),   S(1, -94),      S(-76, -30),    S(-83, -43),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -458);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(4, -1), S(6, 11), S(6, 11), S(0, 3), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(4, 5), S(2, 3), S(3, -0), S(4, -2),
};

inline const PParam KS_KNIGHT_ATTACK_WEIGHT = S(72, 73);
inline const PParam KS_BISHOP_ATTACK_WEIGHT = S(68, -131);
inline const PParam KS_ROOK_ATTACK_WEIGHT = S(106, 22);
inline const PParam KS_QUEEN_ATTACK_WEIGHT = S(-9, 82);

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -20), S(-6, 5), S(-3, -10), S(7, -17), S(13, -30), S(7, -55), S(-3, -46), }},
  {{ S(3, 2), S(-21, 2), S(-16, 9), S(-9, 16), S(-5, 7), S(-8, -14), S(-18, -20), }},
  {{ S(-3, -1), S(-12, -8), S(-13, 18), S(-8, 18), S(-6, 9), S(-6, -16), S(-22, -36), }},
  {{ S(7, 7), S(-10, 17), S(-6, 37), S(-1, 40), S(-1, 36), S(5, 18), S(11, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 20), S(-6, 2), S(-7, 9), S(-6, 28), S(1, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 10), S(-41, -100), S(-9, -40), S(-1, 3), S(-3, 3), S(-6, 9), S(-5, 8), }},
  {{ S(8, -3), S(-23, -121), S(-5, -35), S(-4, -0), S(-2, -4), S(-8, 3), S(1, 2), }},
  {{ S(-0, 10), S(-7, -69), S(7, -15), S(-0, 8), S(-3, 10), S(-9, 18), S(-6, 20), }},
  {{ S(0, 0), S(2, -60), S(-1, 23), S(-3, 25), S(-5, 7), S(-12, 10), S(-9, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1431, 915, -19, -4
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(88);
inline VParam WINNABLE_PAWN_ENDGAME = V(77);
inline VParam WINNABLE_BIAS = V(-395);

// Epoch duration: 8.4658s
// clang-format on
}  // namespace Clockwork
