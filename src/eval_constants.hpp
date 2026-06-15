#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(195, 499);
inline const PParam KNIGHT_MAT = S(824, 1540);
inline const PParam BISHOP_MAT = S(866, 1624);
inline const PParam ROOK_MAT   = S(1031, 2552);
inline const PParam QUEEN_MAT  = S(2441, 3889);

inline const PParam TEMPO_VAL  = S(69, 51);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -3);
inline const PParam BISHOP_PAIR_VAL   = S(64, 231);
inline const PParam ROOK_OPEN_VAL     = S(112, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 39);
inline const PParam RESTRICTED_SQUARES = S(19, 6);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 42);
inline const PParam OUTPOST_BISHOP_VAL    = S(41, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 48);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 67);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -2), S(32, 35), S(60, 65), S(121, 213), S(392, 386), S(618, 744),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(46, 33), S(38, 25), S(55, 55), S(96, 178), S(411, 105),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-90, -249), S(-92, -208), S(-67, -79), S(-22, 43), S(88, 202), S(221, 406),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-85, 50), S(-91, 33), S(-58, 107), S(-90, 229), S(-51, 331), S(53, 209),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-21, 71), S(-37, 62), S(-54, 103), S(-28, 133), S(73, 158), S(37, 179),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -40), S(25, -4), S(16, 35), S(22, 104), S(67, 277), S(327, 222),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -36), S(2, 7), S(-3, -28), S(-0, -67), S(-11, -175), S(-159, -442),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 230), S(5, 177), S(2, 101), S(11, 62), S(22, 65), S(63, 60), S(61, 31),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-147, -44), S(23, -6), S(5, 94), S(30, 143), S(44, 177), S(53, 186), S(40, 168),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-88, -374), S(-28, -134), S(1, -16), S(25, 31), S(53, 62), S(68, 97), S(86, 105), S(105, 113), S(124, 67),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-62, -284), S(-14, -105), S(34, -29), S(57, 21), S(78, 61), S(89, 90), S(95, 112), S(97, 132), S(101, 144), S(108, 150), S(115, 144), S(136, 124), S(142, 117), S(123, 93),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(109, -180), S(24, 11), S(45, 43), S(61, 60), S(71, 78), S(75, 92), S(80, 107), S(86, 112), S(90, 125), S(96, 131), S(100, 137), S(101, 147), S(104, 150), S(109, 139), S(137, 92),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-206, -163), S(-52, 6), S(-27, 133), S(-5, 257), S(11, 296), S(17, 349), S(24, 383), S(31, 398), S(35, 422), S(38, 440), S(43, 448), S(47, 455), S(51, 462), S(52, 467), S(53, 469), S(52, 473), S(48, 474), S(53, 465), S(53, 463), S(57, 453), S(54, 436), S(58, 417), S(30, 438), S(-18, 431), S(-45, 429), S(-74, 447), S(-116, 453), S(-87, 395),
};

inline const PParam PAWN_THREAT_KNIGHT = S(193, 150);
inline const PParam PAWN_THREAT_BISHOP = S(170, 215);
inline const PParam PAWN_THREAT_ROOK   = S(190, 152);
inline const PParam PAWN_THREAT_QUEEN  = S(154, 25);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 54), S(90, 92), S(102, 123), S(202, 125), S(159, 11), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(6, 55), S(50, 93), S(72, 91), S(15, 15), S(148, -51), S(0, 0),
};
inline const PParam KING_THREAT  = S(-14, 154);
inline const PParam HANGING_PAWN  = S(31, 91);
inline const PParam HANGING_NON_PAWN  = S(68, 27);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -19), S(29, -6),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(39, 48), S(120, -118),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(36, 10), S(50, -10),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -16), S(4, -14), S(-0, -20), S(-6, -28), S(-12, -36), S(-17, -43), S(-19, -55), S(-25, -58), S(-28, -73),
};

inline const PParam ROOK_LINEUP = S(17, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(184, 265),    S(42, 397),     S(71, 373),     S(143, 265),    S(198, 156),    S(135, 213),    S(101, 249),    S(237, 171),    //
    S(42, 59),      S(57, 104),     S(30, 57),      S(45, -13),     S(35, -44),     S(11, -17),     S(13, 24),      S(-16, 52),     //
    S(38, -13),     S(13, -4),      S(42, -47),     S(28, -69),     S(19, -86),     S(1, -73),      S(-36, -40),    S(-37, -2),     //
    S(-6, -71),     S(-30, -41),    S(3, -61),      S(-5, -74),     S(-26, -84),    S(-35, -73),    S(-82, -53),    S(-75, -50),    //
    S(-10, -108),   S(23, -105),    S(8, -44),      S(-7, -50),     S(-34, -60),    S(-48, -70),    S(-77, -69),    S(-80, -72),    //
    S(11, -105),    S(84, -92),     S(69, -38),     S(27, -13),     S(-4, -34),     S(-21, -60),    S(-47, -55),    S(-60, -54),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-263, -496),  S(-256, 50),    S(-276, -70),   S(14, 26),      S(-105, 45),    S(-270, 80),    S(-365, 111),   S(-351, -388),  //
    S(-11, -5),     S(-2, 34),      S(84, 31),      S(76, 56),      S(80, 49),      S(51, 24),      S(-28, 30),     S(-34, 22),     //
    S(45, -26),     S(43, 26),      S(72, 49),      S(73, 69),      S(58, 69),      S(23, 57),      S(10, 33),      S(-42, 18),     //
    S(91, 25),      S(93, 48),      S(101, 67),     S(98, 110),     S(102, 112),    S(69, 75),      S(51, 41),      S(34, 36),      //
    S(75, 18),      S(102, 7),      S(97, 51),      S(89, 83),      S(76, 84),      S(73, 65),      S(62, 11),      S(22, 32),      //
    S(17, -34),     S(45, -17),     S(49, 23),      S(62, 57),      S(57, 54),      S(30, 17),      S(15, -8),      S(-24, -32),    //
    S(41, -20),     S(45, -8),      S(29, -13),     S(35, 15),      S(32, 11),      S(6, -40),      S(-30, 3),      S(-42, -76),    //
    S(-41, -74),    S(8, -20),      S(28, -39),     S(46, -27),     S(26, -8),      S(-11, -45),    S(-19, -20),    S(-62, -129),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-125, 22),    S(-177, 107),   S(-426, 190),   S(-261, 92),    S(-299, 151),   S(-300, 155),   S(-213, 131),   S(-121, 71),    //
    S(-29, -14),    S(-72, 91),     S(-32, 53),     S(-66, 69),     S(-67, 79),     S(-35, 49),     S(-6, 43),      S(-45, 29),     //
    S(41, 23),      S(21, 62),      S(39, 71),      S(32, 61),      S(24, 51),      S(19, 56),      S(17, 48),      S(18, 20),      //
    S(15, 5),       S(52, 28),      S(63, 44),      S(77, 63),      S(102, 48),     S(45, 28),      S(51, 3),       S(1, 5),        //
    S(44, -39),     S(45, 12),      S(78, 20),      S(93, 32),      S(77, 47),      S(69, 30),      S(21, 14),      S(20, -29),     //
    S(60, -22),     S(85, -20),     S(99, 10),      S(65, 39),      S(64, 21),      S(61, 23),      S(66, 0),       S(20, -12),     //
    S(31, -72),     S(117, -46),    S(72, -10),     S(50, 7),       S(31, 9),       S(53, -37),     S(51, -46),     S(43, -46),     //
    S(52, -73),     S(21, -7),      S(27, 1),       S(50, -25),     S(32, -14),     S(37, 22),      S(47, -12),     S(44, -52),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(179, 120),    S(205, 139),    S(151, 165),    S(143, 138),    S(206, 91),     S(169, 116),    S(175, 134),    S(150, 139),    //
    S(82, 170),     S(135, 168),    S(191, 131),    S(138, 126),    S(180, 108),    S(141, 134),    S(90, 168),     S(88, 168),     //
    S(53, 159),     S(171, 105),    S(198, 83),     S(176, 63),     S(174, 86),     S(116, 126),    S(119, 134),    S(64, 179),     //
    S(33, 120),     S(90, 127),     S(119, 97),     S(94, 101),     S(125, 84),     S(85, 128),     S(76, 141),     S(21, 167),     //
    S(2, 57),       S(63, 66),      S(58, 79),      S(29, 89),      S(39, 95),      S(27, 121),     S(9, 120),      S(-9, 122),     //
    S(18, -26),     S(83, 0),       S(74, 23),      S(55, 30),      S(66, 37),      S(38, 65),      S(39, 49),      S(-1, 52),      //
    S(-61, -30),    S(68, -68),     S(73, -31),     S(61, 2),       S(65, -1),      S(47, 18),      S(37, 0),       S(10, 2),       //
    S(-1, -53),     S(15, -14),     S(86, -30),     S(95, -33),     S(95, -26),     S(72, -1),      S(70, -12),     S(51, -6),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(70, 189),     S(144, 168),    S(58, 303),     S(-5, 408),     S(41, 349),     S(72, 262),     S(66, 187),     S(2, 242),      //
    S(55, 205),     S(75, 250),     S(42, 320),     S(-91, 451),    S(-42, 415),    S(6, 314),      S(49, 187),     S(25, 178),     //
    S(18, 247),     S(52, 285),     S(19, 361),     S(-22, 398),    S(-0, 379),     S(48, 268),     S(79, 169),     S(58, 126),     //
    S(16, 179),     S(18, 262),     S(-15, 312),    S(-28, 380),    S(-11, 376),    S(18, 249),     S(56, 165),     S(26, 140),     //
    S(9, 167),      S(6, 185),      S(-4, 233),     S(-31, 303),    S(-19, 323),    S(6, 250),      S(9, 187),      S(33, 95),      //
    S(2, 68),       S(31, 79),      S(27, 154),     S(6, 172),      S(14, 180),     S(17, 204),     S(37, 133),     S(17, 108),     //
    S(-27, -69),    S(5, -68),      S(11, 1),       S(35, 41),      S(30, 78),      S(33, 52),      S(7, 84),       S(21, 55),      //
    S(-37, -56),    S(-20, -201),   S(11, -205),    S(24, -94),     S(32, -19),     S(31, -53),     S(30, -35),     S(1, 14),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(108, -506),   S(456, 86),     S(290, 217),    S(-15, 206),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(337, -161),   S(347, 200),    S(195, 212),    S(12, 163),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(188, 52),     S(217, 184),    S(112, 207),    S(-47, 185),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(16, 19),      S(90, 127),     S(-22, 176),    S(-103, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-119, 4),     S(-35, 83),     S(-92, 150),    S(-175, 199),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-50, -37),    S(12, 31),      S(-74, 115),    S(-127, 162),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -93),     S(27, -14),     S(-37, 49),     S(-114, 105),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -212),   S(3, -93),      S(-79, -27),    S(-74, -49),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-84, -462);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(4, -1), S(6, 11), S(6, 12), S(0, 3), S(3, -11),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(4, 5), S(2, 3), S(3, -0), S(3, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<PParam, 4> KS_INNER_WEIGHTS = {
    S(3, 1), S(2, -5), S(4, 0), S(-1, 4),
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -19), S(-7, 7), S(-3, -8), S(8, -16), S(13, -28), S(7, -56), S(-5, -46), }},
  {{ S(3, 2), S(-22, 2), S(-17, 8), S(-9, 16), S(-6, 7), S(-9, -13), S(-21, -20), }},
  {{ S(-2, -1), S(-12, -10), S(-13, 19), S(-7, 18), S(-6, 10), S(-7, -17), S(-23, -40), }},
  {{ S(7, 8), S(-10, 18), S(-6, 39), S(-1, 42), S(-1, 38), S(5, 16), S(9, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(12, 20), S(-4, 1), S(-7, 9), S(-5, 28), S(1, 50),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 9), S(-42, -114), S(-8, -42), S(0, 2), S(-2, 2), S(-5, 9), S(-5, 7), }},
  {{ S(10, -2), S(-21, -125), S(-4, -37), S(-3, -1), S(-0, -4), S(-7, 3), S(2, 2), }},
  {{ S(-0, 10), S(-9, -78), S(8, -18), S(1, 7), S(-3, 9), S(-9, 18), S(-5, 19), }},
  {{ S(1, -1), S(5, -60), S(-0, 26), S(-2, 25), S(-5, 8), S(-12, 11), S(-9, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1363, 852, -18, -7
);

inline VParam WINNABLE_PAWNS = V(-19);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(84);
inline VParam WINNABLE_PAWN_ENDGAME = V(89);
inline VParam WINNABLE_BIAS = V(-389);

// Epoch duration: 6.74334s
// clang-format on
}  // namespace Clockwork
