#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(195, 384);
inline const PParam KNIGHT_MAT = S(838, 979);
inline const PParam BISHOP_MAT = S(947, 1075);
inline const PParam ROOK_MAT   = S(1144, 1724);
inline const PParam QUEEN_MAT  = S(2672, 2714);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 14);
inline const PParam BISHOP_PAIR_VAL   = S(50, 204);
inline const PParam ROOK_OPEN_VAL     = S(118, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 26);
inline const PParam MINOR_BEHIND_PAWN = S(13, 37);
inline const PParam RESTRICTED_SQUARES = S(-24, -4);
inline const std::array<PParam, 5> KNIGHT_CLOSED_BONUS = {
    S(115, -65), S(69, 84), S(82, 102), S(85, 126), S(91, 152),
};

inline const PParam DOUBLED_PAWN_VAL = S(-12, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -19);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 40);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 41);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(48, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, -2), S(31, 28), S(61, 49), S(143, 142), S(384, 207), S(439, 525),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 34), S(46, 28), S(63, 51), S(120, 142), S(413, 85),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-106, -185), S(-107, -156), S(-80, -50), S(-22, 48), S(73, 185), S(261, 263),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -38), S(22, 2), S(15, 33), S(1, 113), S(81, 204), S(256, 254),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -19), S(0, 21), S(-3, -11), S(-1, -43), S(-6, -132), S(-253, -212),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(18, 182), S(-6, 153), S(0, 84), S(7, 50), S(14, 51), S(50, 46), S(44, 27),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-270, -40), S(-11, 34), S(-3, 88), S(38, 113), S(60, 131), S(71, 137), S(50, 136),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-127, -280), S(-62, -109), S(-32, -17), S(-6, 20), S(24, 45), S(40, 76), S(60, 83), S(80, 99), S(115, 39),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-78, -232), S(-31, -70), S(22, -3), S(45, 41), S(67, 72), S(80, 94), S(85, 111), S(95, 116), S(96, 132), S(114, 110), S(116, 112), S(164, 51), S(161, 56), S(190, 3),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -109), S(14, 52), S(36, 78), S(52, 88), S(63, 102), S(67, 113), S(73, 124), S(80, 126), S(85, 136), S(93, 138), S(101, 139), S(106, 144), S(111, 139), S(123, 113), S(204, 10),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-123, -85), S(14, -14), S(40, 94), S(61, 198), S(77, 238), S(85, 278), S(91, 307), S(100, 315), S(103, 337), S(105, 352), S(111, 356), S(113, 366), S(118, 365), S(119, 369), S(121, 365), S(117, 367), S(115, 366), S(119, 355), S(125, 340), S(127, 333), S(124, 318), S(139, 282), S(115, 293), S(110, 235), S(81, 226), S(70, 199), S(15, 214), S(21, 176),
};

inline const PParam PAWN_THREAT_KNIGHT = S(210, 95);
inline const PParam PAWN_THREAT_BISHOP = S(196, 142);
inline const PParam PAWN_THREAT_ROOK   = S(198, 124);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -7);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(229, 71);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -10);

inline const PParam BISHOP_THREAT_KNIGHT = S(100, 62);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(171, 93);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(14, -27), S(-1, 2), S(-4, -5), S(-8, -15), S(-12, -23), S(-16, -29), S(-17, -39), S(-23, -40), S(-38, -36),
};

inline const PParam ROOK_LINEUP = S(15, 62);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(230, 181),    S(64, 241),     S(192, 197),    S(171, 176),    S(218, 108),    S(114, 189),    S(59, 226),     S(198, 174),    //
    S(48, 20),      S(74, 39),      S(71, 18),      S(47, -33),     S(42, -63),     S(21, -21),     S(2, 33),       S(-27, 56),     //
    S(24, -17),     S(-1, -6),      S(28, -44),     S(17, -70),     S(12, -82),     S(-11, -56),    S(-56, -10),    S(-52, 11),     //
    S(-9, -63),     S(-30, -35),    S(-3, -59),     S(-14, -67),    S(-37, -68),    S(-42, -51),    S(-99, -14),    S(-87, -24),    //
    S(-8, -92),     S(24, -90),     S(6, -42),      S(-6, -46),     S(-36, -53),    S(-53, -48),    S(-86, -32),    S(-85, -39),    //
    S(12, -89),     S(90, -88),     S(66, -47),     S(27, -15),     S(-3, -31),     S(-24, -43),    S(-56, -23),    S(-67, -25),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-353, -284),  S(-289, 43),    S(-313, -12),   S(-30, 38),     S(-99, 37),     S(-245, 42),    S(-420, 118),   S(-421, -191),  //
    S(-68, 18),     S(-37, 32),     S(80, -11),     S(88, 9),       S(77, 26),      S(8, 31),       S(-55, 38),     S(-82, 26),     //
    S(5, 1),        S(30, -1),      S(70, 35),      S(88, 32),      S(55, 57),      S(10, 53),      S(-9, 16),      S(-57, 22),     //
    S(74, 17),      S(89, 28),      S(97, 49),      S(101, 80),     S(107, 81),     S(62, 65),      S(36, 41),      S(19, 27),      //
    S(55, 18),      S(97, -6),      S(84, 45),      S(80, 63),      S(60, 65),      S(63, 51),      S(47, 12),      S(0, 32),       //
    S(-5, -21),     S(23, -10),     S(24, 15),      S(39, 39),      S(33, 37),      S(3, 18),       S(-5, -4),      S(-47, -26),    //
    S(10, -9),      S(21, -15),     S(-1, -10),     S(7, 10),       S(6, 6),        S(-19, -40),    S(-43, -8),     S(-58, -87),    //
    S(-62, -62),    S(-11, -6),     S(11, -39),     S(27, -33),     S(9, -13),      S(-25, -40),    S(-39, -18),    S(-81, -103),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-161, 74),    S(-163, 81),    S(-441, 134),   S(-285, 77),    S(-285, 83),    S(-305, 75),    S(-210, 75),    S(-138, 60),    //
    S(-51, 1),      S(-83, 78),     S(-43, 24),     S(-96, 52),     S(-73, 42),     S(-56, 39),     S(-20, 34),     S(-57, 9),      //
    S(22, 23),      S(16, 41),      S(36, 46),      S(23, 48),      S(4, 44),       S(7, 51),       S(11, 36),      S(3, 17),       //
    S(10, 1),       S(45, 21),      S(58, 43),      S(66, 77),      S(98, 63),      S(37, 37),      S(37, 6),       S(-9, 7),       //
    S(41, -41),     S(52, -2),      S(73, 27),      S(86, 50),      S(68, 60),      S(57, 45),      S(15, 21),      S(7, -18),      //
    S(60, -25),     S(81, -9),      S(95, 19),      S(61, 43),      S(57, 25),      S(56, 34),      S(61, 16),      S(8, 3),        //
    S(27, -61),     S(108, -41),    S(70, -18),     S(46, 4),       S(30, 7),       S(42, -24),     S(40, -34),     S(39, -41),     //
    S(49, -63),     S(31, -30),     S(26, 3),       S(45, -22),     S(30, -10),     S(35, 21),      S(45, -10),     S(40, -38),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(198, 86),     S(231, 98),     S(189, 109),    S(185, 83),     S(222, 77),     S(179, 96),     S(199, 102),    S(181, 110),    //
    S(86, 158),     S(171, 150),    S(233, 115),    S(168, 135),    S(208, 126),    S(177, 133),    S(119, 162),    S(101, 168),    //
    S(50, 157),     S(175, 126),    S(218, 91),     S(186, 94),     S(182, 116),    S(139, 136),    S(140, 140),    S(76, 173),     //
    S(18, 132),     S(109, 126),    S(135, 102),    S(111, 112),    S(139, 106),    S(95, 139),     S(99, 136),     S(25, 163),     //
    S(-6, 67),      S(74, 70),      S(63, 86),      S(34, 90),      S(43, 101),     S(33, 123),     S(8, 120),      S(-9, 116),     //
    S(9, -6),       S(84, 15),      S(72, 28),      S(49, 32),      S(62, 35),      S(29, 71),      S(38, 49),      S(-3, 59),      //
    S(-87, 1),      S(56, -38),     S(58, -13),     S(48, 8),       S(51, 12),      S(38, 23),      S(30, 9),       S(-3, 25),      //
    S(-23, -16),    S(3, 3),        S(62, -11),     S(73, -14),     S(72, -2),      S(52, 16),      S(48, 11),      S(27, 17),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(88, 117),     S(191, 44),     S(112, 146),    S(55, 229),     S(86, 194),     S(85, 169),     S(110, 87),     S(38, 146),     //
    S(73, 168),     S(84, 251),     S(57, 269),     S(-70, 338),    S(-27, 330),    S(14, 291),     S(60, 182),     S(39, 179),     //
    S(41, 204),     S(62, 264),     S(37, 310),     S(2, 317),      S(11, 321),     S(61, 249),     S(78, 190),     S(88, 106),     //
    S(61, 100),     S(60, 186),     S(12, 253),     S(-3, 315),     S(11, 327),     S(46, 216),     S(87, 147),     S(61, 123),     //
    S(62, 68),      S(45, 133),     S(24, 189),     S(-0, 251),     S(13, 278),     S(28, 233),     S(53, 145),     S(71, 80),      //
    S(54, -0),      S(68, 46),      S(62, 121),     S(44, 129),     S(47, 153),     S(48, 187),     S(67, 127),     S(62, 77),      //
    S(28, -108),    S(43, -55),     S(49, -7),      S(78, 15),      S(67, 67),      S(68, 46),      S(38, 88),      S(60, 49),      //
    S(13, -99),     S(36, -216),    S(65, -217),    S(80, -117),    S(73, -21),     S(79, -63),     S(74, -33),     S(49, -11),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-54, -210),   S(308, 241),    S(211, 213),    S(66, 123),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(239, 23),     S(324, 202),    S(191, 215),    S(129, 103),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(182, 85),     S(239, 165),    S(154, 185),    S(105, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(13, 35),      S(135, 100),    S(17, 154),     S(-11, 165),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-94, -11),    S(-2, 52),      S(-58, 105),    S(-142, 165),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-33, -43),    S(27, 10),      S(-64, 77),     S(-114, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(17, -83),     S(28, -23),     S(-45, 24),     S(-109, 71),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -172),   S(0, -86),      S(-82, -45),    S(-75, -58),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-79, -539);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -27), S(14, -16), S(14, -7), S(5, -11), S(1, -27),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -18), S(4, -18), S(4, -3), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -5);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 41), S(-3, 51), S(-0, -18), S(11, -26), S(9, -17), S(-2, -9), S(-2, 54), }},
  {{ S(-1, 162), S(-19, -231), S(-20, -5), S(-7, 50), S(-7, 64), S(-18, -13), S(-18, -215), }},
  {{ S(-2, 137), S(-8, -218), S(-8, 123), S(-2, 104), S(-2, 102), S(-9, 129), S(-7, -194), }},
  {{ S(8, 125), S(-9, 81), S(2, 94), S(8, 73), S(7, 76), S(-0, 92), S(-6, 81), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 67), S(-10, 54), S(-10, 76), S(-1, 81), S(4, 31),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 115), S(-7, 34), S(-8, 38), S(-5, 34), S(-6, 30), S(-7, 38), S(-8, 48), }},
  {{ S(10, 6), S(2, -31), S(-7, -20), S(-3, -50), S(-4, -52), S(-6, -20), S(2, -24), }},
  {{ S(1, 57), S(-3, 34), S(-6, 39), S(-3, 35), S(-2, 17), S(-7, 33), S(-3, 22), }},
  {{ S(-0, 52), S(-6, 31), S(-10, 35), S(-4, 45), S(-3, 46), S(-9, 31), S(-8, 35), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1077, 248, -18, 91
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(228);
inline VParam WINNABLE_BIAS = V(-661);

// Epoch duration: 5.69911s
// clang-format on
}  // namespace Clockwork
