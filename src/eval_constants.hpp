#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(221, 436);
inline const PParam KNIGHT_MAT = S(909, 1349);
inline const PParam BISHOP_MAT = S(956, 1426);
inline const PParam ROOK_MAT   = S(1166, 2286);
inline const PParam QUEEN_MAT  = S(2842, 3655);

inline const PParam TEMPO_VAL  = S(62, 41);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -0);
inline const PParam BISHOP_PAIR_VAL   = S(62, 213);
inline const PParam ROOK_OPEN_VAL     = S(108, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 8);
inline const PParam MINOR_BEHIND_PAWN = S(16, 37);
inline const PParam RESTRICTED_SQUARES = S(16, 9);

inline const PParam DOUBLED_PAWN_VAL = S(-24, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -31);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -19);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 38);
inline const PParam OUTPOST_BISHOP_VAL    = S(48, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 39);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, -5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 61);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -47);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, 0), S(36, 27), S(63, 58), S(130, 182), S(456, 312), S(594, 794),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 24), S(42, 18), S(60, 42), S(116, 141), S(442, 69),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-98, -213), S(-98, -183), S(-71, -66), S(-21, 37), S(91, 188), S(234, 317),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-78, 55), S(-63, 37), S(-39, 96), S(-43, 191), S(-34, 287), S(65, 164),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-22, 62), S(-24, 55), S(-40, 93), S(-22, 123), S(62, 137), S(69, 134),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(22, -42), S(23, -2), S(18, 33), S(26, 96), S(81, 248), S(293, 172),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(2, -21), S(-6, 18), S(-13, -16), S(2, -63), S(-9, -152), S(-195, -357),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(39, 199), S(10, 165), S(2, 90), S(10, 52), S(24, 53), S(66, 46), S(65, 24),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-105, -24), S(32, 1), S(14, 89), S(40, 122), S(52, 153), S(54, 169), S(36, 165),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-88, -343), S(-29, -129), S(4, -29), S(29, 8), S(57, 33), S(72, 61), S(90, 64), S(107, 68), S(123, 19),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-45, -224), S(-12, -97), S(32, -49), S(50, -3), S(73, 30), S(85, 53), S(91, 70), S(96, 82), S(101, 91), S(109, 88), S(121, 79), S(133, 54), S(149, 44), S(83, 43),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(104, -185), S(25, -11), S(44, 15), S(59, 27), S(69, 42), S(73, 53), S(79, 65), S(84, 69), S(89, 78), S(95, 83), S(101, 87), S(102, 94), S(106, 95), S(111, 80), S(144, 20),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-153, -96), S(-16, -26), S(13, 58), S(32, 144), S(45, 183), S(52, 222), S(58, 249), S(64, 265), S(68, 281), S(72, 294), S(76, 305), S(81, 310), S(84, 313), S(88, 313), S(89, 314), S(90, 310), S(90, 307), S(94, 296), S(99, 284), S(107, 267), S(104, 256), S(111, 229), S(79, 261), S(51, 240), S(5, 273), S(-0, 262), S(-75, 327), S(19, 222),
};

inline const PParam PAWN_THREAT_KNIGHT = S(203, 106);
inline const PParam PAWN_THREAT_BISHOP = S(177, 170);
inline const PParam PAWN_THREAT_ROOK   = S(173, 133);
inline const PParam PAWN_THREAT_QUEEN  = S(162, -25);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(11, 47), S(86, 79), S(98, 104), S(216, 77), S(150, 9), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(11, 47), S(55, 82), S(76, 72), S(8, 24), S(130, -16), S(0, 0),
};
inline const PParam KING_THREAT  = S(-4, 137);
inline const PParam HANGING_PAWN  = S(33, 80);
inline const PParam HANGING_NON_PAWN  = S(62, 24);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(17, -4), S(46, -34),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(37, 49), S(127, -121),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(27, 38), S(18, 31),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -18), S(5, -13), S(1, -18), S(-4, -25), S(-10, -33), S(-15, -40), S(-18, -48), S(-21, -57), S(-29, -71),
};

inline const PParam ROOK_LINEUP = S(15, 72);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(231, 133),    S(42, 318),     S(84, 315),     S(142, 228),    S(173, 158),    S(117, 215),    S(87, 250),     S(257, 121),    //
    S(52, -3),      S(54, 47),      S(39, 16),      S(35, -33),     S(23, -64),     S(2, -27),      S(-11, 19),     S(-22, 37),     //
    S(25, -23),     S(4, -20),      S(32, -55),     S(22, -76),     S(10, -80),     S(-13, -56),    S(-43, -25),    S(-47, 5),      //
    S(-7, -78),     S(-26, -62),    S(-4, -70),     S(-5, -75),     S(-29, -77),    S(-42, -53),    S(-85, -30),    S(-81, -34),    //
    S(-7, -109),    S(26, -115),    S(4, -42),      S(-10, -43),    S(-35, -51),    S(-55, -43),    S(-79, -44),    S(-84, -46),    //
    S(12, -108),    S(81, -113),    S(60, -52),     S(24, -16),     S(-7, -34),     S(-29, -36),    S(-48, -35),    S(-65, -35),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-285, -452),  S(-279, 58),    S(-35, -458),   S(24, 4),       S(-69, 36),     S(-266, 67),    S(-376, 101),   S(-394, -319),  //
    S(-0, -29),     S(3, 14),       S(102, -22),    S(103, 26),     S(105, 27),     S(67, 10),      S(-26, 32),     S(-39, 15),     //
    S(27, -27),     S(39, 4),       S(91, 29),      S(97, 43),      S(86, 41),      S(31, 54),      S(5, 30),       S(-36, 7),      //
    S(99, 6),       S(96, 22),      S(104, 55),     S(104, 91),     S(106, 90),     S(72, 67),      S(49, 34),      S(46, 25),      //
    S(72, 9),       S(107, -10),    S(101, 38),     S(85, 76),      S(72, 74),      S(68, 65),      S(56, 18),      S(23, 31),      //
    S(8, -31),      S(41, -25),     S(43, 14),      S(59, 49),      S(48, 47),      S(24, 21),      S(12, -1),      S(-21, -20),    //
    S(26, -20),     S(26, -4),      S(23, -17),     S(29, 11),      S(23, 14),      S(-0, -30),     S(-29, -6),     S(-39, -79),    //
    S(-39, -83),    S(11, -23),     S(21, -45),     S(41, -29),     S(26, -16),     S(-6, -51),     S(-14, -11),    S(-56, -124),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-98, -8),     S(-163, 75),    S(-348, 146),   S(-204, 81),    S(-244, 104),   S(-272, 119),   S(-195, 111),   S(-109, 50),    //
    S(-33, -8),     S(-63, 82),     S(-29, 45),     S(-49, 58),     S(-56, 66),     S(-41, 48),     S(-14, 28),     S(-43, 26),     //
    S(42, -8),      S(41, 14),      S(36, 49),      S(30, 53),      S(22, 36),      S(9, 46),       S(14, 21),      S(0, 15),       //
    S(26, -19),     S(54, 3),       S(74, 15),      S(78, 45),      S(100, 28),     S(44, 18),      S(44, -1),      S(-2, 1),       //
    S(50, -51),     S(46, -15),     S(70, 4),       S(93, 14),      S(78, 26),      S(64, 21),      S(21, 9),       S(15, -20),     //
    S(59, -38),     S(80, -43),     S(90, -4),      S(67, 23),      S(62, 11),      S(57, 19),      S(70, -7),      S(23, -16),     //
    S(31, -71),     S(102, -52),    S(65, -28),     S(46, -1),      S(26, 3),       S(52, -38),     S(48, -41),     S(52, -60),     //
    S(56, -79),     S(28, -47),     S(23, -4),      S(40, -30),     S(27, -21),     S(34, 13),      S(49, -33),     S(42, -55),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(177, 87),     S(197, 114),    S(164, 126),    S(140, 96),     S(191, 84),     S(178, 92),     S(176, 112),    S(147, 131),    //
    S(89, 134),     S(135, 146),    S(190, 98),     S(151, 90),     S(193, 88),     S(149, 110),    S(87, 156),     S(94, 151),     //
    S(44, 135),     S(167, 91),     S(196, 57),     S(173, 43),     S(175, 64),     S(121, 107),    S(121, 122),    S(65, 162),     //
    S(16, 91),      S(84, 88),      S(117, 59),     S(96, 54),      S(119, 63),     S(86, 101),     S(72, 115),     S(29, 134),     //
    S(-8, 34),      S(62, 38),      S(51, 48),      S(27, 54),      S(36, 67),      S(25, 97),      S(13, 98),      S(-2, 93),      //
    S(2, -36),      S(78, -33),     S(70, -14),     S(45, 4),       S(59, 15),      S(30, 47),      S(36, 32),      S(-5, 38),      //
    S(-80, -35),    S(53, -73),     S(73, -63),     S(64, -40),     S(60, -19),     S(50, -6),      S(33, -12),     S(9, -13),      //
    S(-6, -59),     S(3, -29),      S(73, -49),     S(87, -53),     S(83, -37),     S(68, -17),     S(64, -23),     S(51, -19),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(87, 134),     S(150, 104),    S(86, 196),     S(42, 254),     S(71, 242),     S(100, 174),    S(100, 126),    S(21, 190),     //
    S(66, 176),     S(84, 224),     S(68, 246),     S(-43, 323),    S(-1, 316),     S(33, 245),     S(55, 170),     S(37, 154),     //
    S(29, 182),     S(87, 206),     S(49, 261),     S(16, 287),     S(31, 285),     S(61, 227),     S(83, 162),     S(60, 112),     //
    S(36, 103),     S(42, 172),     S(20, 210),     S(9, 266),      S(12, 291),     S(32, 205),     S(71, 132),     S(46, 106),     //
    S(32, 57),      S(23, 102),     S(17, 141),     S(-9, 205),     S(-1, 238),     S(20, 195),     S(25, 147),     S(44, 81),      //
    S(23, -12),     S(45, -7),      S(39, 75),      S(18, 93),      S(22, 118),     S(26, 148),     S(41, 115),     S(32, 70),      //
    S(-1, -144),    S(4, -90),      S(21, -58),     S(40, -1),      S(36, 30),      S(38, 23),      S(20, 41),      S(34, 22),      //
    S(3, -153),     S(-2, -268),    S(11, -233),    S(23, -120),    S(33, -34),     S(38, -72),     S(35, -56),     S(15, -27),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(86, -379),    S(398, 159),    S(265, 258),    S(1, 242),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(264, -92),    S(298, 172),    S(173, 224),    S(12, 203),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(155, 87),     S(207, 168),    S(98, 209),     S(-43, 218),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(46, 38),      S(111, 100),    S(-38, 206),    S(-109, 228),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-62, -18),    S(-18, 58),     S(-103, 138),   S(-191, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, -45),    S(20, -1),      S(-83, 95),     S(-148, 155),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(40, -110),    S(39, -45),     S(-44, 16),     S(-120, 83),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-3, -190),    S(21, -113),    S(-82, -46),    S(-63, -62),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-62, -617);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -16), S(21, -25), S(20, -6), S(7, -6), S(0, -12),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, -14), S(9, -23), S(4, -11), S(6, -2), S(6, 9),
};

inline const PParam KS_FLANK_ATTACK = S(4, -10);
inline const PParam KS_FLANK_DEFENSE = S(-9, 2);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -4);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-4, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(37, 17), S(8, 21), S(10, -77), S(22, -35), S(19, -18), S(-14, 18), S(-38, -1), }},
  {{ S(9, 162), S(-21, -336), S(-17, -83), S(-5, 18), S(-11, 102), S(-32, 140), S(-62, 134), }},
  {{ S(14, 118), S(-4, -260), S(-0, 110), S(8, 84), S(7, 80), S(-10, 102), S(-62, 128), }},
  {{ S(22, 146), S(-5, 102), S(7, 112), S(16, 97), S(9, 88), S(17, 104), S(8, 103), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(34, 139), S(3, 86), S(0, 94), S(15, 108), S(37, 66),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(19, 171), S(-113, -414), S(-25, -255), S(20, -378), S(1, 81), S(-3, 108), S(-4, 117), }},
  {{ S(26, 44), S(-47, -542), S(-17, -270), S(5, -178), S(3, 3), S(-5, 34), S(7, 32), }},
  {{ S(16, 86), S(-25, -232), S(8, -24), S(13, 25), S(4, 50), S(-3, 70), S(5, 61), }},
  {{ S(13, 68), S(-7, -107), S(8, -6), S(14, 45), S(-1, 53), S(-11, 57), S(-2, 58), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        614, 286, 1, 85
);

inline VParam WINNABLE_PAWNS = V(-19);
inline VParam WINNABLE_SYM = V(109);
inline VParam WINNABLE_ASYM = V(93);
inline VParam WINNABLE_PAWN_ENDGAME = V(133);
inline VParam WINNABLE_BIAS = V(-410);

// Epoch duration: 11.1529s
// clang-format on
}  // namespace Clockwork
