#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(195, 385);
inline const PParam KNIGHT_MAT = S(910, 1019);
inline const PParam BISHOP_MAT = S(949, 1064);
inline const PParam ROOK_MAT   = S(1153, 1704);
inline const PParam QUEEN_MAT  = S(2653, 2795);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_PAIR_VAL   = S(55, 196);
inline const PParam ROOK_OPEN_VAL     = S(119, -16);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 28);
inline const PParam MINOR_BEHIND_PAWN = S(12, 37);
inline const PParam RESTRICTED_SQUARES = S(-25, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-11, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -15);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 47);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 42);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, 1), S(30, 26), S(59, 47), S(143, 139), S(394, 183), S(438, 519),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(51, 34), S(46, 27), S(61, 49), S(121, 135), S(438, 65),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-110, -175), S(-109, -155), S(-77, -59), S(-16, 32), S(73, 175), S(271, 251),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -29), S(22, 3), S(13, 34), S(2, 109), S(80, 199), S(256, 247),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -24), S(-1, 25), S(-1, -11), S(1, -43), S(-7, -124), S(-250, -205),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(17, 184), S(-6, 158), S(-0, 86), S(6, 51), S(14, 50), S(53, 45), S(46, 29),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-299, -5), S(-19, 51), S(-9, 100), S(41, 105), S(63, 123), S(74, 126), S(53, 125),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-115, -246), S(-47, -78), S(-15, 8), S(12, 40), S(44, 56), S(60, 86), S(82, 84), S(102, 94), S(141, 21),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-77, -241), S(-34, -71), S(18, -3), S(43, 42), S(66, 74), S(80, 97), S(88, 113), S(100, 119), S(104, 134), S(124, 114), S(128, 115), S(175, 58), S(182, 53), S(201, 18),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(102, -122), S(16, 39), S(38, 67), S(54, 78), S(64, 92), S(69, 103), S(74, 114), S(81, 117), S(85, 129), S(93, 131), S(101, 133), S(105, 139), S(109, 137), S(121, 111), S(205, 7),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-125, -83), S(13, -11), S(37, 106), S(57, 213), S(72, 254), S(81, 294), S(87, 319), S(95, 329), S(99, 347), S(101, 360), S(107, 362), S(110, 370), S(115, 366), S(116, 371), S(117, 367), S(114, 369), S(111, 368), S(115, 359), S(119, 349), S(120, 344), S(120, 326), S(137, 287), S(112, 307), S(107, 249), S(79, 249), S(70, 223), S(22, 247), S(29, 205),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(332, -19), S(72, -94), S(16, -16), S(2, 13), S(-11, 5), S(-11, -1), S(-20, 2), S(-49, 18), S(-52, 3),
};

inline const PParam PAWN_THREAT_KNIGHT = S(214, 90);
inline const PParam PAWN_THREAT_BISHOP = S(207, 132);
inline const PParam PAWN_THREAT_ROOK   = S(200, 120);
inline const PParam PAWN_THREAT_QUEEN  = S(185, -22);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 100);
inline const PParam KNIGHT_THREAT_ROOK   = S(228, 70);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -22);

inline const PParam BISHOP_THREAT_KNIGHT = S(104, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(213, 123);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 83);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(12, -30), S(-3, -3), S(-5, -12), S(-8, -22), S(-11, -32), S(-14, -40), S(-15, -51), S(-21, -53), S(-36, -48),
};

inline const PParam ROOK_LINEUP = S(14, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(237, 175),    S(47, 261),     S(179, 235),    S(184, 148),    S(225, 87),     S(115, 178),    S(50, 224),     S(201, 156),    //
    S(49, 27),      S(69, 52),      S(82, 4),       S(59, -40),     S(52, -67),     S(22, -11),     S(4, 38),       S(-26, 60),     //
    S(26, -19),     S(5, -5),       S(37, -52),     S(21, -66),     S(14, -78),     S(-9, -49),     S(-58, -1),     S(-55, 18),     //
    S(-5, -70),     S(-28, -37),    S(1, -68),      S(-12, -69),    S(-35, -68),    S(-41, -46),    S(-99, -8),     S(-89, -19),    //
    S(-6, -96),     S(21, -91),     S(6, -52),      S(-5, -52),     S(-36, -55),    S(-53, -46),    S(-91, -26),    S(-87, -37),    //
    S(12, -94),     S(88, -83),     S(73, -38),     S(27, -31),     S(-2, -42),     S(-22, -45),    S(-56, -24),    S(-67, -26),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-345, -292),  S(-272, 25),    S(-217, -137),  S(-2, 22),      S(-80, 28),     S(-224, 29),    S(-397, 87),    S(-415, -197),  //
    S(-45, -9),     S(-19, 19),     S(96, -5),      S(103, 16),     S(99, 22),      S(25, 34),      S(-43, 34),     S(-61, 3),      //
    S(19, -5),      S(58, -15),     S(85, 55),      S(101, 56),     S(68, 80),      S(20, 76),      S(13, 13),      S(-38, 10),     //
    S(89, 16),      S(103, 36),     S(110, 71),     S(112, 101),    S(118, 101),    S(74, 86),      S(51, 47),      S(35, 22),      //
    S(68, 15),      S(112, -3),     S(94, 61),      S(89, 82),      S(68, 84),      S(73, 68),      S(61, 17),      S(15, 26),      //
    S(8, -26),      S(32, -1),      S(32, 36),      S(46, 59),      S(40, 57),      S(12, 37),      S(5, 3),        S(-34, -30),    //
    S(25, -21),     S(36, -23),     S(12, -9),      S(19, 15),      S(15, 13),      S(-11, -29),    S(-30, -8),     S(-45, -92),    //
    S(-43, -85),    S(5, -25),      S(22, -45),     S(37, -39),     S(21, -20),     S(-14, -43),    S(-25, -31),    S(-65, -119),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-159, 80),    S(-167, 88),    S(-444, 140),   S(-290, 83),    S(-285, 85),    S(-310, 81),    S(-208, 76),    S(-131, 58),    //
    S(-49, 5),      S(-83, 72),     S(-49, 32),     S(-100, 59),    S(-81, 53),     S(-58, 38),     S(-21, 29),     S(-47, -4),     //
    S(20, 22),      S(12, 41),      S(27, 54),      S(13, 58),      S(-6, 53),      S(3, 49),       S(13, 25),      S(9, 6),        //
    S(6, 4),        S(43, 22),      S(52, 47),      S(52, 88),      S(85, 68),      S(31, 37),      S(36, 3),       S(-5, -4),      //
    S(44, -44),     S(46, 2),       S(65, 32),      S(70, 61),      S(52, 68),      S(47, 48),      S(14, 14),      S(10, -26),     //
    S(60, -25),     S(77, -9),      S(88, 22),      S(52, 48),      S(46, 30),      S(46, 36),      S(57, 13),      S(9, -1),       //
    S(21, -60),     S(105, -43),    S(69, -24),     S(46, -3),      S(29, 1),       S(36, -23),     S(34, -31),     S(36, -38),     //
    S(48, -57),     S(33, -31),     S(37, -10),     S(52, -31),     S(37, -20),     S(42, 15),      S(42, -6),      S(37, -32),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(197, 86),     S(236, 92),     S(187, 112),    S(188, 82),     S(222, 79),     S(187, 90),     S(205, 98),     S(186, 105),    //
    S(86, 154),     S(175, 147),    S(236, 117),    S(171, 133),    S(211, 124),    S(178, 132),    S(124, 157),    S(107, 160),    //
    S(48, 154),     S(173, 130),    S(217, 94),     S(188, 92),     S(187, 112),    S(139, 135),    S(142, 136),    S(78, 167),     //
    S(17, 133),     S(104, 132),    S(132, 108),    S(107, 118),    S(143, 101),    S(98, 135),     S(102, 131),    S(29, 157),     //
    S(-7, 69),      S(71, 78),      S(59, 93),      S(32, 94),      S(45, 99),      S(36, 119),     S(12, 116),     S(-5, 111),     //
    S(10, -12),     S(85, 10),      S(74, 26),      S(50, 28),      S(64, 30),      S(31, 65),      S(43, 38),      S(4, 46),       //
    S(-85, -7),     S(57, -47),     S(57, -20),     S(48, 1),       S(52, 6),       S(39, 19),      S(33, 2),       S(3, 13),       //
    S(-20, -24),    S(6, -5),       S(62, -15),     S(75, -21),     S(76, -10),     S(56, 8),       S(54, 1),       S(34, 5),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(88, 119),     S(180, 72),     S(105, 165),    S(52, 232),     S(86, 199),     S(87, 176),     S(112, 97),     S(26, 181),     //
    S(71, 172),     S(86, 254),     S(56, 274),     S(-76, 349),    S(-39, 353),    S(5, 313),      S(56, 204),     S(36, 197),     //
    S(37, 212),     S(71, 242),     S(37, 304),     S(-7, 333),     S(3, 343),      S(54, 268),     S(77, 205),     S(81, 135),     //
    S(61, 93),      S(57, 186),     S(15, 247),     S(-1, 303),     S(6, 333),      S(42, 229),     S(84, 162),     S(60, 134),     //
    S(61, 70),      S(43, 131),     S(23, 186),     S(1, 242),      S(10, 279),     S(26, 241),     S(48, 167),     S(68, 100),     //
    S(48, 10),      S(70, 34),      S(65, 109),     S(44, 127),     S(46, 154),     S(48, 191),     S(64, 141),     S(58, 96),      //
    S(22, -107),    S(51, -98),     S(58, -43),     S(77, 14),      S(66, 68),      S(66, 55),      S(35, 102),     S(53, 77),      //
    S(10, -93),     S(39, -236),    S(61, -212),    S(75, -104),    S(69, -7),      S(77, -53),     S(73, -26),     S(46, 6),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-123, -93),   S(276, 345),    S(193, 332),    S(66, 256),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(189, 140),    S(326, 304),    S(192, 332),    S(127, 236),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(133, 194),    S(227, 274),    S(144, 289),    S(88, 233),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-39, 143),    S(112, 202),    S(3, 247),      S(-21, 256),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-136, 68),    S(-10, 125),    S(-61, 173),    S(-145, 233),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-74, 26),     S(16, 78),      S(-65, 140),    S(-112, 187),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-8, -13),     S(24, 44),      S(-47, 90),     S(-112, 132),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-86, -59),    S(-21, -8),     S(-108, 31),    S(-107, 17),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-84, 4);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -24), S(13, -19), S(12, -3), S(5, -7), S(1, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -23), S(5, -26), S(3, -10), S(3, -2), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -5);
inline const PParam KS_FLANK_DEFENSE = S(-4, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -11);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -1), S(1, 10), S(-1, -6), S(9, -42), S(8, -48), S(-2, -1), S(2, 9), }},
  {{ S(2, 27), S(-24, 9), S(-17, -6), S(-4, -35), S(-4, -27), S(-16, -3), S(-22, 14), }},
  {{ S(1, 4), S(-11, -3), S(-5, -19), S(1, -44), S(1, -43), S(-5, -18), S(-9, -4), }},
  {{ S(9, 22), S(-6, -16), S(4, -9), S(8, -19), S(6, -18), S(2, -9), S(-3, -10), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 8), S(-9, -2), S(-6, 7), S(2, 22), S(5, -31),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 18), S(-6, 2), S(-5, -7), S(-3, -15), S(-4, -17), S(-4, -6), S(-6, 2), }},
  {{ S(9, -10), S(3, -24), S(-6, -26), S(-4, -49), S(-5, -51), S(-5, -30), S(3, -24), }},
  {{ S(3, 3), S(-0, -11), S(-4, -12), S(-2, -21), S(-2, -27), S(-5, -15), S(0, -11), }},
  {{ S(2, 5), S(-5, 2), S(-8, -10), S(-2, -7), S(-1, -6), S(-7, -7), S(-6, 2), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1169, 797, -14, -30
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(123);
inline VParam WINNABLE_PAWN_ENDGAME = V(240);
inline VParam WINNABLE_BIAS = V(-633);

// Epoch duration: 7.54089s
// clang-format on
}  // namespace Clockwork
