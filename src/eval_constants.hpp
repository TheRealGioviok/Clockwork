#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(202, 507);
inline const PParam KNIGHT_MAT = S(821, 1596);
inline const PParam BISHOP_MAT = S(872, 1682);
inline const PParam ROOK_MAT   = S(1041, 2670);
inline const PParam QUEEN_MAT  = S(2419, 4123);

inline const PParam TEMPO_VAL  = S(83, 126);

inline const PParam BISHOP_XRAY_PAWNS   = S(-24, -13);
inline const PParam BISHOP_PAIR_VAL   = S(66, 277);
inline const PParam ROOK_OPEN_VAL     = S(110, -31);
inline const PParam ROOK_SEMIOPEN_VAL = S(36, 13);
inline const PParam MINOR_BEHIND_PAWN = S(15, 48);
inline const PParam RESTRICTED_SQUARES = S(18, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-8, -45);
inline const PParam ISOLATED_PAWN_VAL = S(-24, -43);

inline const PParam POTENTIAL_CHECKER_VAL = S(-29, -38);
inline const PParam OUTPOST_KNIGHT_VAL    = S(39, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(76, 42);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(47, 58);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(45, 32);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(8, 57);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -37);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(39, 5), S(43, 27), S(78, 84), S(109, 231), S(380, 428), S(679, 832),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 55), S(47, 23), S(65, 53), S(96, 156), S(406, 145),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-109, -243), S(-113, -216), S(-80, -65), S(-28, 59), S(128, 244), S(257, 425),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-89, 38), S(-95, 19), S(-61, 101), S(-94, 242), S(-63, 378), S(71, 297),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-42, 61), S(-35, 70), S(-70, 113), S(-16, 169), S(91, 196), S(61, 210),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(21, -43), S(-5, 8), S(12, 32), S(34, 73), S(51, 248), S(338, 220),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(-5, -36), S(-18, 8), S(22, -13), S(3, -85), S(6, -181), S(-135, -468),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 277), S(28, 205), S(5, 119), S(15, 89), S(35, 79), S(43, 63), S(46, 66),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-122, -25), S(0, -9), S(-9, 116), S(27, 186), S(36, 224), S(84, 232), S(41, 223),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-91, -409), S(-39, -151), S(-37, -51), S(17, 2), S(17, 9), S(29, 62), S(61, 68), S(67, 84), S(74, 28),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-46, -329), S(-3, -131), S(43, -45), S(30, -19), S(64, 27), S(75, 61), S(79, 75), S(80, 94), S(85, 104), S(81, 117), S(84, 131), S(76, 119), S(105, 132), S(71, 91),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(111, -233), S(14, -53), S(45, -12), S(52, 22), S(61, 41), S(59, 54), S(66, 65), S(77, 74), S(82, 85), S(97, 88), S(99, 92), S(90, 104), S(94, 107), S(85, 98), S(94, 46),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-192, -202), S(-36, -88), S(-0, 45), S(6, 187), S(26, 231), S(34, 288), S(33, 325), S(35, 354), S(44, 362), S(46, 373), S(49, 385), S(57, 394), S(59, 397), S(66, 403), S(69, 395), S(63, 392), S(56, 390), S(62, 380), S(56, 391), S(58, 374), S(53, 376), S(68, 361), S(45, 388), S(2, 381), S(-29, 383), S(-67, 402), S(-128, 437), S(-93, 370),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 199);
inline const PParam PAWN_THREAT_BISHOP = S(173, 273);
inline const PParam PAWN_THREAT_ROOK   = S(195, 177);
inline const PParam PAWN_THREAT_QUEEN  = S(146, 12);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(16, 64), S(75, 105), S(80, 99), S(123, 52), S(127, -9), }},
  {{ S(19, 74), S(70, 118), S(94, 120), S(239, 693), S(185, 84), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(13, 79), S(26, 109), S(45, 126), S(-1, -7), S(130, -84), }},
  {{ S(10, 64), S(63, 99), S(98, 107), S(44, 47), S(398, 947), }},
}};
inline const PParam KING_THREAT  = S(21, 148);
inline const PParam HANGING_PAWN  = S(43, 112);
inline const PParam HANGING_NON_PAWN  = S(73, 64);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(16, -26), S(24, 17),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(27, 57), S(102, -120),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(24, 6), S(70, 13),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, 3), S(4, -4), S(1, -31), S(-2, -43), S(-2, -69), S(-6, -87), S(-15, -98), S(-24, -68), S(-57, -90),
};

inline const PParam ROOK_LINEUP = S(28, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(178, 244),    S(79, 439),     S(101, 426),    S(155, 279),    S(222, 179),    S(167, 214),    S(118, 234),    S(221, 181),    //
    S(70, 56),      S(69, 135),     S(28, 92),      S(62, 22),      S(95, -13),     S(36, -3),      S(-4, 21),      S(-16, 67),     //
    S(24, 22),      S(3, -21),      S(32, -38),     S(55, -50),     S(73, -62),     S(16, -49),     S(-21, -64),    S(-41, -4),     //
    S(-8, -50),     S(-7, -49),     S(27, -34),     S(49, -59),     S(-17, -72),    S(-30, -53),    S(-83, -82),    S(-54, -28),    //
    S(-16, -83),    S(52, -47),     S(-15, -39),    S(-10, -31),    S(-38, -37),    S(-39, -89),    S(-83, -76),    S(-78, -71),    //
    S(22, -82),     S(99, -61),     S(91, -4),      S(28, -9),      S(-33, -93),    S(-20, -20),    S(-57, -56),    S(-51, -66),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-232, -450),  S(-234, 86),    S(-228, 14),    S(10, 65),      S(-73, 51),     S(-259, 95),    S(-342, 93),    S(-313, -369),  //
    S(24, -11),     S(11, 47),      S(73, 24),      S(76, 65),      S(92, 51),      S(74, 33),      S(13, 46),      S(-14, 30),     //
    S(38, 6),       S(-5, 11),      S(26, 53),      S(52, 71),      S(62, 86),      S(3, 48),       S(11, 55),      S(-2, 25),      //
    S(79, 10),      S(97, 62),      S(92, 75),      S(84, 108),     S(93, 87),      S(65, 74),      S(67, 27),      S(32, -2),      //
    S(80, 40),      S(89, 8),       S(67, 28),      S(52, 75),      S(55, 50),      S(79, 38),      S(89, 43),      S(37, 8),       //
    S(-15, -56),    S(35, -37),     S(55, 5),       S(67, 56),      S(46, 34),      S(20, -13),     S(25, -31),     S(-38, -85),    //
    S(32, -21),     S(35, -25),     S(-3, -62),     S(5, -18),      S(-9, -38),     S(-26, -63),    S(-64, -37),    S(-36, -95),    //
    S(-49, -91),    S(-29, -76),    S(7, -74),      S(14, -39),     S(21, -51),     S(11, -80),     S(-47, -73),    S(-108, -182),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-122, 27),    S(-192, 88),    S(-424, 129),   S(-275, 113),   S(-301, 133),   S(-300, 149),   S(-238, 98),    S(-107, 87),    //
    S(-32, -8),     S(-116, 55),    S(-1, 82),      S(-56, 64),     S(-60, 92),     S(-21, 39),     S(-5, 35),      S(-40, -3),     //
    S(2, -3),       S(32, 69),      S(40, 63),      S(29, 44),      S(2, 14),       S(-10, 20),     S(8, 23),       S(17, -20),     //
    S(10, 2),       S(53, 28),      S(43, 17),      S(61, 62),      S(107, 46),     S(27, 9),       S(21, -21),     S(16, -21),     //
    S(51, -49),     S(8, -19),      S(41, -11),     S(75, 22),      S(57, 40),      S(60, 28),      S(6, -28),      S(21, -39),     //
    S(35, 2),       S(54, -44),     S(59, -4),      S(87, 7),       S(62, 30),      S(76, -10),     S(52, 7),       S(-11, -26),    //
    S(59, -83),     S(113, -36),    S(72, -43),     S(38, -7),      S(33, -59),     S(51, -43),     S(38, -45),     S(98, -50),     //
    S(36, -82),     S(6, -55),      S(-10, -2),     S(46, -84),     S(17, -22),     S(6, -51),      S(81, -24),     S(7, -65),      //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(187, 125),    S(201, 153),    S(176, 175),    S(142, 147),    S(191, 99),     S(165, 128),    S(192, 161),    S(167, 169),    //
    S(100, 145),    S(130, 137),    S(164, 108),    S(133, 97),     S(176, 86),     S(126, 116),    S(85, 144),     S(109, 154),    //
    S(56, 121),     S(151, 53),     S(206, 66),     S(170, 42),     S(188, 54),     S(105, 75),     S(121, 106),    S(67, 160),     //
    S(18, 104),     S(101, 108),    S(104, 102),    S(95, 69),      S(137, 65),     S(75, 98),      S(89, 128),     S(25, 160),     //
    S(-3, 56),      S(83, 70),      S(80, 110),     S(5, 73),       S(36, 81),      S(18, 111),     S(45, 142),     S(22, 135),     //
    S(18, -41),     S(92, -6),      S(82, 20),      S(75, 30),      S(28, 7),       S(17, 46),      S(48, 63),      S(-12, 24),     //
    S(-65, -76),    S(58, -74),     S(61, -62),     S(30, -16),     S(44, -20),     S(4, -35),      S(27, -26),     S(-37, -34),    //
    S(2, -115),     S(21, -34),     S(70, -61),     S(91, -43),     S(90, -47),     S(71, -55),     S(66, -48),     S(42, -41),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(72, 146),     S(142, 154),    S(43, 292),     S(-8, 389),     S(10, 337),     S(45, 243),     S(71, 183),     S(13, 191),     //
    S(62, 180),     S(63, 228),     S(30, 295),     S(-78, 439),    S(-40, 396),    S(46, 290),     S(36, 160),     S(26, 133),     //
    S(22, 242),     S(80, 270),     S(47, 341),     S(7, 382),      S(3, 354),      S(51, 245),     S(97, 149),     S(46, 121),     //
    S(29, 188),     S(35, 243),     S(27, 325),     S(5, 374),      S(6, 340),      S(33, 238),     S(46, 158),     S(42, 112),     //
    S(14, 167),     S(-5, 167),     S(-9, 215),     S(-26, 288),    S(-4, 296),     S(20, 249),     S(7, 151),      S(51, 63),      //
    S(-21, 57),     S(15, 50),      S(37, 148),     S(10, 157),     S(2, 167),      S(34, 189),     S(44, 106),     S(6, 63),       //
    S(-46, -111),   S(-10, -118),   S(32, -10),     S(44, 30),      S(30, 36),      S(40, 11),      S(12, 57),      S(25, 23),      //
    S(-49, -92),    S(-28, -253),   S(21, -254),    S(46, -153),    S(56, -51),     S(18, -62),     S(24, -75),     S(-21, -36),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(171, -574),   S(432, 54),     S(296, 162),    S(18, 158),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(358, -166),   S(324, 189),    S(206, 221),    S(37, 160),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(173, 31),     S(207, 194),    S(111, 216),    S(-31, 214),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(28, -10),     S(95, 102),     S(-6, 196),     S(-109, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-92, -15),    S(-3, 59),      S(-72, 118),    S(-150, 173),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-12, -22),    S(27, 33),      S(-38, 90),     S(-125, 115),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(32, -51),     S(35, 34),      S(-85, 43),     S(-96, 66),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-39, -195),   S(-9, -48),     S(-95, -8),     S(-49, -61),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-132, -449);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -14), S(10, 18), S(12, -2), S(3, 4), S(1, -4),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(1, 10), S(5, -7), S(1, 1), S(3, -0),
};

inline const PParam KS_FLANK_ATTACK = S(2, -3);
inline const PParam KS_FLANK_DEFENSE = S(-2, -3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, 2);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-1, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(10, -45), S(-24, 16), S(-13, -9), S(2, -16), S(12, -31), S(-6, -60), S(-12, -50), }},
  {{ S(2, 9), S(-26, -0), S(-3, 13), S(-6, 13), S(-15, -8), S(-12, -18), S(-12, -18), }},
  {{ S(-8, -6), S(-18, -17), S(-12, 18), S(-12, 25), S(-6, 17), S(8, -32), S(-49, -59), }},
  {{ S(4, 9), S(1, 40), S(-6, 46), S(0, 15), S(-3, 27), S(7, -7), S(9, -26), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(0, 11), S(-9, 12), S(-15, 3), S(-10, 25), S(0, 32),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 23), S(-29, -115), S(-15, -40), S(15, 27), S(-5, 16), S(-6, 1), S(-7, 12), }},
  {{ S(12, -15), S(-22, -124), S(-34, -27), S(-18, 11), S(4, -10), S(-7, 1), S(-1, 19), }},
  {{ S(-3, -3), S(-1, -75), S(-7, -7), S(4, 5), S(-7, 15), S(-8, -4), S(-9, 30), }},
  {{ S(2, 2), S(-8, -72), S(-20, 25), S(-6, 14), S(-12, 15), S(-19, -6), S(-14, 3), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1422, 929, -33, -17
);

inline VParam WINNABLE_PAWNS = V(-22);
inline VParam WINNABLE_SYM = V(103);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(106);
inline VParam WINNABLE_BIAS = V(-510);


// Epoch duration: 9.56388s
// Epoch duration: 7.65336s
// clang-format on
}  // namespace Clockwork
