#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(204, 509);
inline const PParam KNIGHT_MAT = S(823, 1609);
inline const PParam BISHOP_MAT = S(878, 1695);
inline const PParam ROOK_MAT   = S(1048, 2690);
inline const PParam QUEEN_MAT  = S(2438, 4146);

inline const PParam TEMPO_VAL  = S(70, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(62, 242);
inline const PParam ROOK_OPEN_VAL     = S(110, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 14);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-25, -68);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -43);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 42);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(15, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -53);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, 2), S(34, 36), S(63, 53), S(116, 165), S(372, 401), S(679, 824),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 38), S(37, 27), S(51, 48), S(67, 149), S(305, 265),
};
inline const std::array<std::array<PParam, 6>, 2> PASSED_PAWN = {{
  {{ S(-106, -259), S(-119, -206), S(-90, -90), S(-45, 33), S(93, 193), S(215, 412), }},
  {{ S(0, 0), S(-78, -277), S(-50, -114), S(-2, 58), S(176, 233), S(305, 265), }},
}};
inline const std::array<std::array<PParam, 6>, 2> CANDIDATE_PASSED_PAWN = {{
  {{ S(-28, -12), S(-53, -8), S(-22, 35), S(20, 54), S(98, 106), S(0, 0), }},
  {{ S(-40, 19), S(-27, 24), S(-16, 78), S(25, 92), S(157, 97), S(0, 0), }},
}};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-95, 57), S(-91, 29), S(-56, 103), S(-84, 228), S(-61, 340), S(58, 214),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-24, 71), S(-33, 57), S(-59, 107), S(-32, 138), S(70, 158), S(37, 190),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -48), S(26, -7), S(21, 31), S(23, 109), S(68, 278), S(341, 220),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(8, -13), S(5, 15), S(-3, -16), S(-2, -65), S(-13, -174), S(-179, -451),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 246), S(10, 196), S(8, 113), S(17, 70), S(24, 75), S(66, 69), S(69, 40),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-116, -59), S(27, -2), S(4, 107), S(31, 160), S(48, 198), S(61, 206), S(47, 183),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-93, -400), S(-24, -143), S(6, -27), S(30, 23), S(57, 56), S(73, 93), S(91, 101), S(110, 109), S(130, 61),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-75, -355), S(-20, -131), S(33, -41), S(57, 15), S(77, 58), S(89, 89), S(94, 112), S(97, 133), S(101, 145), S(107, 153), S(117, 143), S(131, 129), S(130, 133), S(118, 95),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(101, -215), S(24, -9), S(45, 25), S(61, 43), S(72, 62), S(76, 76), S(80, 91), S(86, 97), S(91, 110), S(96, 118), S(100, 124), S(101, 133), S(103, 138), S(109, 125), S(128, 86),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-196, -200), S(-39, -85), S(-13, 52), S(5, 196), S(23, 239), S(30, 293), S(37, 332), S(44, 349), S(49, 373), S(52, 390), S(58, 398), S(62, 405), S(66, 412), S(68, 418), S(68, 420), S(68, 423), S(63, 426), S(67, 418), S(67, 414), S(72, 405), S(62, 396), S(74, 369), S(38, 398), S(-7, 389), S(-40, 386), S(-76, 410), S(-138, 444), S(-100, 373),
};

inline const PParam PAWN_THREAT_KNIGHT = S(197, 156);
inline const PParam PAWN_THREAT_BISHOP = S(172, 222);
inline const PParam PAWN_THREAT_ROOK   = S(191, 154);
inline const PParam PAWN_THREAT_QUEEN  = S(162, 17);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(8, 58), S(99, 97), S(104, 127), S(179, 95), S(166, 11), }},
  {{ S(6, 59), S(88, 95), S(104, 124), S(221, 618), S(148, 56), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(9, 65), S(45, 108), S(59, 112), S(13, 12), S(152, -77), }},
  {{ S(3, 50), S(63, 81), S(96, 71), S(23, 15), S(369, 898), }},
}};
inline const PParam KING_THREAT  = S(-12, 156);
inline const PParam HANGING_PAWN  = S(32, 93);
inline const PParam HANGING_NON_PAWN  = S(72, 32);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(22, 8),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(43, 45), S(112, -112),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 13), S(50, -8),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -18), S(4, -16), S(-0, -22), S(-6, -30), S(-12, -37), S(-17, -44), S(-19, -56), S(-24, -57), S(-30, -74),
};

inline const PParam ROOK_LINEUP = S(16, 83);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(196, 281),    S(73, 415),     S(85, 400),     S(165, 280),    S(202, 173),    S(153, 214),    S(131, 243),    S(231, 181),    //
    S(33, 69),      S(43, 121),     S(16, 75),      S(19, 7),       S(16, -33),     S(-5, -5),      S(0, 34),       S(-27, 56),     //
    S(40, -12),     S(18, -1),      S(45, -42),     S(26, -68),     S(17, -88),     S(4, -75),      S(-36, -42),    S(-37, -5),     //
    S(-5, -75),     S(-28, -43),    S(3, -62),      S(-9, -79),     S(-30, -90),    S(-35, -77),    S(-82, -58),    S(-76, -54),    //
    S(-12, -116),   S(22, -111),    S(6, -48),      S(-12, -55),    S(-39, -66),    S(-52, -76),    S(-78, -77),    S(-82, -80),    //
    S(10, -113),    S(86, -99),     S(74, -44),     S(25, -15),     S(-5, -37),     S(-24, -66),    S(-49, -65),    S(-63, -63),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-261, -507),  S(-256, 47),    S(-266, -27),   S(6, 37),       S(-90, 42),     S(-267, 82),    S(-349, 104),   S(-349, -408),  //
    S(-1, -10),     S(4, 28),       S(90, 21),      S(86, 59),      S(93, 46),      S(53, 27),      S(-15, 26),     S(-40, 16),     //
    S(42, -26),     S(43, 29),      S(56, 65),      S(75, 73),      S(58, 74),      S(21, 60),      S(9, 36),       S(-34, 10),     //
    S(90, 23),      S(93, 47),      S(103, 69),     S(106, 110),    S(110, 108),    S(74, 73),      S(52, 39),      S(34, 30),      //
    S(79, 15),      S(103, 2),      S(100, 50),     S(95, 82),      S(82, 85),      S(74, 65),      S(59, 19),      S(25, 25),      //
    S(19, -42),     S(45, -26),     S(52, 19),      S(64, 53),      S(59, 51),      S(32, 14),      S(15, -18),     S(-24, -41),    //
    S(37, -25),     S(39, -11),     S(27, -19),     S(38, 8),       S(34, 6),       S(5, -45),      S(-31, 1),      S(-49, -83),    //
    S(-44, -93),    S(10, -29),     S(28, -43),     S(45, -32),     S(29, -19),     S(-9, -51),     S(-20, -27),    S(-72, -142),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-130, 21),    S(-191, 102),   S(-401, 166),   S(-275, 102),   S(-304, 140),   S(-304, 150),   S(-225, 125),   S(-128, 71),    //
    S(-27, -20),    S(-64, 88),     S(-47, 66),     S(-69, 63),     S(-66, 76),     S(-38, 46),     S(-10, 45),     S(-52, 24),     //
    S(34, 18),      S(15, 61),      S(29, 71),      S(24, 59),      S(21, 43),      S(21, 47),      S(9, 44),       S(10, 15),      //
    S(16, -7),      S(49, 21),      S(61, 36),      S(79, 56),      S(103, 42),     S(42, 19),      S(43, -3),      S(-3, -2),      //
    S(36, -44),     S(44, 2),       S(76, 13),      S(92, 27),      S(75, 39),      S(65, 24),      S(19, 5),       S(8, -37),      //
    S(56, -30),     S(80, -25),     S(95, 5),       S(63, 29),      S(60, 13),      S(56, 14),      S(58, -5),      S(15, -23),     //
    S(26, -76),     S(113, -58),    S(65, -19),     S(46, -1),      S(30, -2),      S(44, -43),     S(44, -58),     S(37, -49),     //
    S(42, -72),     S(22, -25),     S(29, -10),     S(43, -32),     S(27, -20),     S(36, 15),      S(43, -17),     S(38, -60),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(176, 110),    S(203, 131),    S(156, 161),    S(142, 132),    S(201, 90),     S(161, 114),    S(168, 132),    S(152, 129),    //
    S(88, 151),     S(147, 154),    S(190, 126),    S(143, 113),    S(182, 98),     S(148, 123),    S(100, 156),    S(89, 159),     //
    S(58, 146),     S(180, 87),     S(206, 71),     S(177, 56),     S(181, 73),     S(122, 114),    S(115, 132),    S(63, 171),     //
    S(31, 110),     S(93, 120),     S(113, 94),     S(98, 92),      S(125, 76),     S(84, 118),     S(75, 133),     S(20, 158),     //
    S(5, 44),       S(64, 53),      S(56, 77),      S(25, 86),      S(35, 90),      S(24, 115),     S(7, 112),      S(-14, 115),    //
    S(17, -37),     S(85, -11),     S(73, 16),      S(51, 28),      S(60, 35),      S(38, 57),      S(34, 42),      S(-4, 48),      //
    S(-64, -42),    S(62, -76),     S(68, -38),     S(56, -5),      S(61, -6),      S(45, 9),       S(36, -8),      S(4, -3),       //
    S(-0, -63),     S(24, -31),     S(87, -42),     S(96, -43),     S(98, -38),     S(74, -16),     S(69, -22),     S(48, -16),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(91, 153),     S(148, 154),    S(56, 303),     S(-3, 401),     S(37, 350),     S(70, 263),     S(71, 177),     S(24, 211),     //
    S(58, 185),     S(78, 241),     S(38, 323),     S(-82, 441),    S(-38, 407),    S(19, 292),     S(60, 173),     S(40, 146),     //
    S(21, 233),     S(60, 261),     S(27, 342),     S(-9, 375),     S(10, 365),     S(52, 258),     S(83, 153),     S(63, 118),     //
    S(16, 171),     S(27, 240),     S(-11, 304),    S(-12, 360),    S(5, 353),      S(21, 239),     S(60, 155),     S(34, 120),     //
    S(12, 146),     S(10, 167),     S(4, 215),      S(-22, 287),    S(-11, 303),    S(11, 237),     S(17, 173),     S(36, 80),      //
    S(4, 48),       S(34, 59),      S(32, 132),     S(10, 156),     S(20, 164),     S(21, 189),     S(41, 117),     S(22, 93),      //
    S(-24, -98),    S(4, -95),      S(13, -26),     S(40, 13),      S(37, 55),      S(38, 27),      S(12, 65),      S(24, 40),      //
    S(-42, -83),    S(-11, -244),   S(21, -247),    S(33, -135),    S(40, -56),     S(37, -73),     S(36, -62),     S(5, -7),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(165, -568),   S(479, 76),     S(319, 191),    S(24, 189),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(370, -190),   S(365, 189),    S(213, 202),    S(33, 151),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(201, 41),     S(232, 175),    S(117, 197),    S(-45, 177),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(37, 6),       S(116, 111),    S(-20, 170),    S(-111, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-111, -4),    S(-19, 74),     S(-85, 146),    S(-180, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-55, -35),    S(11, 34),      S(-68, 115),    S(-124, 160),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -93),     S(29, -11),     S(-34, 51),     S(-110, 108),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -212),   S(3, -92),      S(-74, -28),    S(-84, -41),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-81, -454);

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
  {{ S(16, -20), S(-7, 4), S(-3, -11), S(6, -17), S(12, -30), S(7, -55), S(-3, -46), }},
  {{ S(2, 3), S(-21, 1), S(-17, 9), S(-10, 17), S(-6, 7), S(-9, -12), S(-18, -22), }},
  {{ S(-4, -2), S(-13, -9), S(-14, 16), S(-9, 18), S(-8, 9), S(-7, -18), S(-22, -37), }},
  {{ S(6, 8), S(-11, 17), S(-7, 38), S(-2, 43), S(-2, 38), S(3, 19), S(10, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(12, 24), S(-5, 4), S(-7, 10), S(-6, 29), S(-1, 50),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 12), S(-41, -126), S(-13, -38), S(-1, 6), S(-3, 5), S(-6, 11), S(-5, 10), }},
  {{ S(8, -1), S(-25, -135), S(-9, -33), S(-4, 1), S(-2, -1), S(-9, 5), S(1, 4), }},
  {{ S(-0, 11), S(-7, -76), S(4, -16), S(-0, 10), S(-3, 12), S(-9, 19), S(-6, 22), }},
  {{ S(0, 0), S(2, -63), S(-3, 21), S(-3, 26), S(-6, 9), S(-12, 11), S(-9, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1425, 918, -20, -1
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(94);
inline VParam WINNABLE_ASYM = V(83);
inline VParam WINNABLE_PAWN_ENDGAME = V(76);
inline VParam WINNABLE_BIAS = V(-391);

// clang-format on
}  // namespace Clockwork
