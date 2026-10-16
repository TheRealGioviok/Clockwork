#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(196, 481);
inline const PParam KNIGHT_MAT = S(785, 1363);
inline const PParam BISHOP_MAT = S(852, 1397);
inline const PParam ROOK_MAT   = S(1163, 2308);
inline const PParam QUEEN_MAT  = S(2759, 3406);

inline const PParam TEMPO_VAL  = S(71, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, 3);
inline const PParam BISHOP_PAIR_VAL   = S(59, 241);
inline const PParam ROOK_OPEN_VAL     = S(127, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(40, 10);
inline const PParam MINOR_BEHIND_PAWN = S(17, 41);
inline const PParam RESTRICTED_SQUARES = S(17, 6);
inline const PParam SPACE_VAL = S(82, -78);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -84);
inline const PParam ISOLATED_PAWN_VAL = S(-11, -43);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -38);
inline const PParam OUTPOST_KNIGHT_VAL    = S(48, 48);
inline const PParam OUTPOST_BISHOP_VAL    = S(47, 30);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 47);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 7);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(15, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -42);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -7), S(37, 26), S(49, 73), S(110, 207), S(416, 396), S(571, 651),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 24), S(40, 22), S(44, 65), S(92, 177), S(413, 128),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-81, -251), S(-80, -211), S(-51, -80), S(-10, 40), S(66, 219), S(214, 442),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-76, 51), S(-99, 46), S(-48, 97), S(-84, 228), S(-51, 336), S(49, 229),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-2, 60), S(-15, 57), S(-52, 106), S(-7, 126), S(100, 146), S(36, 196),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(19, -38), S(14, -1), S(10, 31), S(20, 94), S(79, 263), S(308, 262),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(2, -34), S(-5, 8), S(-11, -22), S(-1, -58), S(-3, -173), S(-202, -475),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(23, 226), S(8, 173), S(3, 97), S(14, 56), S(26, 62), S(62, 53), S(66, 28),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-116, -59), S(11, -7), S(-7, 98), S(23, 142), S(36, 180), S(46, 187), S(33, 164),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-34, -186), S(23, 55), S(36, 130), S(35, 134), S(32, 121), S(20, 105), S(9, 53), S(-2, -4), S(-9, -109),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-10, -94), S(20, 88), S(52, 124), S(52, 144), S(49, 143), S(38, 129), S(26, 105), S(9, 78), S(-6, 38), S(-18, -2), S(-23, -53), S(-38, -109), S(-50, -140), S(-107, -219),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(40, -58), S(-13, 124), S(13, 153), S(34, 175), S(50, 192), S(60, 203), S(71, 216), S(83, 220), S(95, 228), S(107, 230), S(120, 229), S(130, 229), S(144, 227), S(163, 206), S(187, 168),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-266, -78), S(-126, 118), S(-83, 237), S(-52, 372), S(-19, 393), S(2, 425), S(20, 449), S(36, 454), S(52, 460), S(68, 455), S(85, 446), S(104, 427), S(121, 410), S(140, 384), S(155, 364), S(172, 339), S(181, 318), S(195, 286), S(212, 256), S(234, 220), S(236, 190), S(274, 129), S(249, 139), S(226, 107), S(216, 67), S(189, 76), S(141, 106), S(221, -37),
};

inline const PParam PAWN_THREAT_KNIGHT = S(201, 162);
inline const PParam PAWN_THREAT_BISHOP = S(179, 240);
inline const PParam PAWN_THREAT_ROOK   = S(195, 152);
inline const PParam PAWN_THREAT_QUEEN  = S(161, 32);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(4, 49), S(74, 96), S(101, 126), S(183, 83), S(163, 15), }},
  {{ S(1, 52), S(65, 88), S(102, 119), S(212, 590), S(155, -13), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(3, 64), S(32, 124), S(49, 113), S(20, 17), S(149, -69), }},
  {{ S(-5, 51), S(49, 89), S(87, 67), S(20, 14), S(416, 609), }},
}};
inline const PParam KING_THREAT  = S(4, 153);
inline const PParam HANGING_PAWN  = S(25, 94);
inline const PParam HANGING_NON_PAWN  = S(69, 27);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(25, -20), S(76, -52),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(39, 51), S(156, -160),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(26, 31), S(87, -58),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -9), S(6, -9), S(2, -17), S(-4, -25), S(-11, -34), S(-17, -38), S(-20, -48), S(-26, -43), S(-27, -88),
};

inline const PParam ROOK_LINEUP = S(17, 83);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(214, 278),    S(81, 415),     S(65, 402),     S(139, 301),    S(149, 221),    S(144, 232),    S(153, 256),    S(246, 198),    //
    S(60, 86),      S(65, 135),     S(30, 103),     S(26, 44),      S(18, 5),       S(8, 26),       S(22, 63),      S(-10, 83),     //
    S(33, 17),      S(8, 27),       S(16, -0),      S(-18, -13),    S(-31, -29),    S(-30, -29),    S(-43, -14),    S(-46, 26),     //
    S(-8, -45),     S(-32, -21),    S(-7, -37),     S(-25, -47),    S(-47, -57),    S(-49, -50),    S(-83, -37),    S(-83, -24),    //
    S(-27, -84),    S(18, -87),     S(13, -35),     S(-12, -37),    S(-34, -49),    S(-49, -61),    S(-83, -53),    S(-103, -46),   //
    S(-10, -76),    S(73, -71),     S(83, -32),     S(30, 3),       S(-2, -22),     S(-26, -47),    S(-68, -36),    S(-89, -24),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-277, -454),  S(-271, -15),   S(-273, 61),    S(54, 84),      S(-51, 99),     S(-285, 67),    S(-359, 40),    S(-374, -358),  //
    S(-50, -86),    S(-76, -33),    S(7, -22),      S(-16, 7),      S(1, -19),      S(-28, -12),    S(-78, -47),    S(-107, -55),   //
    S(33, -1),      S(39, 3),       S(53, 17),      S(83, 90),      S(67, 88),      S(18, 21),      S(-5, 14),      S(-44, 25),     //
    S(85, 38),      S(120, 95),     S(119, 83),     S(102, 130),    S(99, 125),     S(99, 78),      S(79, 78),      S(18, 52),      //
    S(28, -15),     S(16, -20),     S(67, 57),      S(29, 81),      S(31, 77),      S(33, 79),      S(-22, -3),     S(-26, -18),    //
    S(-2, -43),     S(55, 6),       S(59, 55),      S(54, 77),      S(51, 74),      S(40, 47),      S(20, 20),      S(-46, -42),    //
    S(3, -19),      S(-10, 3),      S(25, 30),      S(40, 52),      S(36, 54),      S(3, 12),       S(-80, 5),      S(-85, -86),    //
    S(-85, -85),    S(-18, -24),    S(-11, -18),    S(-0, -15),     S(-11, -12),    S(-58, -33),    S(-59, -7),     S(-124, -123),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-219, -33),   S(-236, 129),   S(-421, 200),   S(-265, 76),    S(-273, 95),    S(-278, 148),   S(-213, 124),   S(-250, 65),    //
    S(-24, -66),    S(-77, 89),     S(-17, 39),     S(-5, 79),      S(4, 78),       S(2, 8),        S(-30, 37),     S(-52, -26),    //
    S(63, 45),      S(75, 74),      S(83, 32),      S(121, 54),     S(126, 33),     S(65, 20),      S(48, 72),      S(32, 28),      //
    S(14, 5),       S(55, 62),      S(106, 71),     S(63, 68),      S(69, 64),      S(77, 63),      S(39, 49),      S(0, 9),        //
    S(27, -40),     S(27, 39),      S(37, 22),      S(33, 29),      S(17, 37),      S(20, 44),      S(4, 40),       S(-7, -31),     //
    S(16, -0),      S(69, 3),       S(64, 34),      S(44, 55),      S(41, 53),      S(32, 47),      S(44, 24),      S(-18, -6),     //
    S(-10, -70),    S(95, -92),     S(30, -28),     S(-6, -33),     S(-17, -34),    S(15, -59),     S(28, -86),     S(-7, -43),     //
    S(-43, -66),    S(-14, -9),     S(-14, 63),     S(-8, 37),      S(-19, 40),     S(-7, 77),      S(-3, -5),      S(-49, -62),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(433, 14),     S(436, 76),     S(457, 123),    S(459, 47),     S(491, 26),     S(421, 94),     S(376, 95),     S(397, 41),     //
    S(134, 202),    S(190, 197),    S(198, 143),    S(140, 150),    S(172, 140),    S(152, 153),    S(151, 193),    S(122, 214),    //
    S(24, 181),     S(122, 94),     S(142, 91),     S(105, 74),     S(111, 93),     S(46, 140),     S(49, 150),     S(4, 221),      //
    S(29, 146),     S(67, 132),     S(70, 121),     S(69, 99),      S(89, 88),      S(49, 139),     S(39, 153),     S(13, 196),     //
    S(8, 95),       S(33, 95),      S(20, 137),     S(-8, 130),     S(2, 130),      S(-9, 166),     S(-22, 160),    S(-22, 173),    //
    S(2, 38),       S(53, 42),      S(23, 92),      S(-4, 99),      S(2, 107),      S(-14, 139),    S(2, 100),      S(-23, 120),    //
    S(-89, 62),     S(36, 18),      S(23, 67),      S(2, 114),      S(10, 108),     S(1, 112),      S(4, 90),       S(-35, 93),     //
    S(-20, 26),     S(-9, 80),      S(50, 71),      S(62, 56),      S(67, 59),      S(32, 102),     S(27, 96),      S(22, 79),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(143, 203),    S(212, 173),    S(130, 346),    S(114, 356),    S(118, 360),    S(154, 303),    S(124, 217),    S(65, 264),     //
    S(75, 269),     S(93, 251),     S(116, 215),    S(74, 210),     S(112, 194),    S(108, 161),    S(85, 196),     S(58, 227),     //
    S(68, 141),     S(124, 170),    S(63, 269),     S(50, 247),     S(61, 257),     S(80, 210),     S(127, 95),     S(91, 74),      //
    S(43, 170),     S(49, 189),     S(11, 229),     S(-10, 307),    S(11, 291),     S(32, 173),     S(76, 132),     S(53, 152),     //
    S(4, 207),      S(19, 146),     S(12, 168),     S(-28, 226),    S(-24, 247),    S(17, 203),     S(25, 176),     S(27, 161),     //
    S(7, 84),       S(32, 75),      S(30, 104),     S(6, 135),      S(22, 144),     S(22, 177),     S(34, 175),     S(24, 136),     //
    S(-18, -40),    S(30, -99),     S(33, -13),     S(35, 59),      S(32, 103),     S(61, 41),      S(37, 66),      S(45, 66),      //
    S(-50, 32),     S(-3, -188),    S(20, -148),    S(44, -101),    S(57, -36),     S(39, 18),      S(35, 21),      S(7, 131),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(130, -441),   S(476, 98),     S(413, 140),    S(66, 185),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(332, -177),   S(321, 182),    S(226, 174),    S(34, 120),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(188, 21),     S(204, 158),    S(84, 182),     S(-74, 163),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(35, -4),      S(116, 89),     S(-35, 158),    S(-145, 190),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-98, -12),    S(-25, 68),     S(-77, 131),    S(-181, 180),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-48, -32),    S(12, 32),      S(-64, 109),    S(-117, 150),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -100),    S(41, -18),     S(-16, 44),     S(-90, 106),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-7, -204),    S(5, -92),      S(-77, -22),    S(-80, -45),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 32>, 4> MOBILITY_PSQT = {{
{{
    S(1, -2),       S(6, 38),       S(18, 65),      S(20, 71),      //
    S(-12, 45),     S(-35, 15),     S(-23, 3),      S(-23, 79),     //
    S(38, 51),      S(33, 56),      S(38, 60),      S(32, 60),      //
    S(17, 49),      S(24, 92),      S(31, 83),      S(40, 88),      //
    S(15, 56),      S(26, 56),      S(30, 58),      S(34, 64),      //
    S(6, 36),       S(18, 37),      S(27, 39),      S(29, 47),      //
    S(13, 43),      S(5, 38),       S(17, 26),      S(13, 23),      //
    S(-3, 7),       S(-4, 7),       S(3, 28),       S(17, 14),      //
}},
{{
    S(-38, 61),     S(-54, 61),     S(-51, 35),     S(-57, 60),     //
    S(-11, 14),     S(17, 38),      S(-6, 50),      S(-14, 65),     //
    S(27, 29),      S(33, 67),      S(48, 59),      S(50, 54),      //
    S(14, 41),      S(17, 60),      S(31, 74),      S(48, 87),      //
    S(7, 29),       S(9, 40),       S(18, 50),      S(34, 75),      //
    S(-15, 24),     S(27, 42),      S(46, 61),      S(22, 65),      //
    S(-1, 20),      S(32, 10),      S(10, 27),      S(12, 10),      //
    S(-6, 38),      S(12, 32),      S(21, 57),      S(17, 55),      //
}},
{{
    S(-55, 1),      S(-97, 48),     S(-81, 57),     S(-81, 43),     //
    S(-4, 13),      S(-1, 14),      S(-28, 5),      S(-40, 16),     //
    S(-5, 28),      S(15, 10),      S(14, 6),       S(15, 8),       //
    S(-18, 35),     S(-19, 22),     S(-10, 17),     S(1, 13),       //
    S(-12, 16),     S(-15, 11),     S(-10, 11),     S(-7, 13),      //
    S(-5, 1),       S(-1, -1),      S(-5, 8),       S(-8, 13),      //
    S(-29, -6),     S(-8, -5),      S(-2, -8),      S(-9, 9),       //
    S(-33, 1),      S(-28, 17),     S(-11, -1),     S(-5, -0),      //
}},
{{
    S(-5, -8),      S(-27, 19),     S(-49, 61),     S(-61, 64),     //
    S(-34, 56),     S(-38, 71),     S(-51, 60),     S(-47, 64),     //
    S(-13, 15),     S(-6, 31),      S(-11, 57),     S(-10, 54),     //
    S(-23, 30),     S(-24, 49),     S(-19, 44),     S(-17, 65),     //
    S(-32, 46),     S(-17, 39),     S(-16, 33),     S(-21, 46),     //
    S(-31, 39),     S(-21, 50),     S(-16, 44),     S(-24, 60),     //
    S(-29, 22),     S(-29, 39),     S(-23, 37),     S(-28, 63),     //
    S(-41, 53),     S(-43, 39),     S(-40, 52),     S(-28, 31),     //
}},
}};

inline const PParam KS_NO_QUEEN = S(-94, -433);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -2), S(12, 15), S(13, 6), S(5, 3), S(3, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -6), S(6, 6), S(3, 3), S(3, 1), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -3);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -15), S(-10, 5), S(-6, -10), S(5, -13), S(15, -30), S(8, -55), S(-3, -54), }},
  {{ S(0, 11), S(-25, 3), S(-22, 13), S(-14, 23), S(-9, 14), S(-10, -16), S(-24, -20), }},
  {{ S(-6, 3), S(-13, -6), S(-17, 22), S(-10, 22), S(-8, 10), S(-9, -14), S(-22, -53), }},
  {{ S(6, 15), S(-11, 21), S(-8, 46), S(-2, 49), S(-2, 45), S(2, 30), S(16, -18), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 29), S(-7, 6), S(-9, 12), S(-10, 36), S(2, 56),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 16), S(-53, -118), S(-11, -43), S(2, 2), S(-4, 8), S(-7, 14), S(-6, 13), }},
  {{ S(10, 1), S(-32, -106), S(-7, -42), S(-2, -3), S(-3, -1), S(-12, 6), S(1, 5), }},
  {{ S(-0, 15), S(-5, -74), S(8, -12), S(2, 7), S(-4, 15), S(-11, 22), S(-7, 23), }},
  {{ S(0, 0), S(2, -66), S(1, 23), S(-5, 33), S(-8, 13), S(-16, 11), S(-11, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1110, 844, -26, 0
);

inline VParam WINNABLE_PAWNS = V(-19);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(45);
inline VParam WINNABLE_BIAS = V(-392);

// clang-format on
}  // namespace Clockwork
