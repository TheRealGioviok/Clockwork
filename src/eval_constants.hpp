#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(181, 481);
inline const PParam KNIGHT_MAT = S(780, 1514);
inline const PParam BISHOP_MAT = S(817, 1609);
inline const PParam ROOK_MAT   = S(982, 2555);
inline const PParam QUEEN_MAT  = S(2314, 3845);
inline const PParam TEMPO_VAL  = S(61, 26);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 13);
inline const PParam BISHOP_PAIR_VAL   = S(61, 226);
inline const PParam ROOK_OPEN_VAL     = S(117, -10);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 36);
inline const PParam MINOR_BEHIND_PAWN = S(16, 40);
inline const PParam RESTRICTED_SQUARES = S(-23, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-44, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(57, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(55, 43);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(35, 11);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, -4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(23, 59);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -2), S(28, 37), S(57, 68), S(124, 200), S(416, 292), S(581, 609),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(45, 45), S(41, 40), S(59, 76), S(100, 207), S(411, 159),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-86, -263), S(-83, -226), S(-64, -90), S(-24, 42), S(68, 231), S(207, 376),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -41), S(23, -6), S(14, 33), S(12, 110), S(77, 234), S(129, 440),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -36), S(6, 11), S(-3, -23), S(1, -55), S(-5, -166), S(-165, -328),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(12, 229), S(-5, 183), S(-5, 105), S(6, 65), S(17, 66), S(57, 64), S(46, 49),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-124, -149), S(12, 21), S(1, 110), S(25, 157), S(35, 193), S(47, 200), S(29, 184),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-82, -364), S(-22, -150), S(5, -33), S(28, 11), S(56, 39), S(71, 76), S(88, 83), S(107, 92), S(125, 43),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-54, -295), S(-8, -131), S(39, -60), S(60, -4), S(81, 37), S(93, 66), S(99, 90), S(103, 108), S(105, 120), S(108, 124), S(116, 113), S(129, 95), S(129, 98), S(104, 68),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(109, -194), S(26, -18), S(46, 15), S(62, 29), S(72, 47), S(75, 61), S(81, 75), S(87, 80), S(92, 91), S(99, 96), S(107, 100), S(110, 105), S(109, 110), S(110, 94), S(135, 41),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-215, -140), S(-74, -25), S(-48, 95), S(-27, 215), S(-12, 257), S(-5, 308), S(1, 340), S(7, 356), S(10, 380), S(12, 399), S(17, 407), S(19, 417), S(22, 422), S(22, 429), S(21, 432), S(16, 438), S(10, 439), S(12, 429), S(12, 424), S(15, 415), S(9, 401), S(12, 377), S(-16, 400), S(-59, 385), S(-91, 389), S(-129, 412), S(-171, 424), S(-142, 348),
};

inline const PParam PAWN_THREAT_KNIGHT = S(195, 145);
inline const PParam PAWN_THREAT_BISHOP = S(181, 195);
inline const PParam PAWN_THREAT_ROOK   = S(200, 148);
inline const PParam PAWN_THREAT_QUEEN  = S(168, 24);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 125);
inline const PParam KNIGHT_THREAT_ROOK   = S(221, 97);
inline const PParam KNIGHT_THREAT_QUEEN  = S(160, -21);

inline const PParam BISHOP_THREAT_KNIGHT = S(95, 82);
inline const PParam BISHOP_THREAT_ROOK   = S(206, 163);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 103);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(2, -16), S(3, -15), S(-1, -23), S(-5, -32), S(-10, -41), S(-15, -48), S(-16, -61), S(-22, -63), S(-25, -80),
};

inline const PParam ROOK_LINEUP = S(16, 76);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(180, 254),    S(32, 359),     S(62, 333),     S(129, 240),    S(190, 142),    S(116, 208),    S(80, 250),     S(220, 200),    //
    S(34, 46),      S(43, 83),      S(25, 25),      S(42, -46),     S(37, -82),     S(5, -39),      S(-2, 15),      S(-26, 47),     //
    S(28, -22),     S(4, -14),      S(35, -58),     S(22, -82),     S(13, -101),    S(-7, -85),     S(-41, -51),    S(-45, -11),    //
    S(-12, -77),    S(-34, -44),    S(0, -66),      S(-9, -78),     S(-29, -90),    S(-38, -80),    S(-86, -59),    S(-79, -57),    //
    S(-13, -108),   S(22, -106),    S(9, -46),      S(-8, -53),     S(-33, -65),    S(-47, -75),    S(-76, -72),    S(-80, -76),    //
    S(10, -102),    S(85, -90),     S(72, -40),     S(25, -15),     S(-2, -39),     S(-22, -61),    S(-46, -57),    S(-59, -57),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-256, -510),  S(-283, 59),    S(-301, -82),   S(-10, 25),     S(-116, 44),    S(-286, 74),    S(-409, 123),   S(-348, -381),  //
    S(-28, -21),    S(-18, 26),     S(77, 3),       S(62, 46),      S(75, 32),      S(35, 15),      S(-29, 20),     S(-46, 2),      //
    S(35, -26),     S(30, 23),      S(71, 57),      S(76, 76),      S(68, 80),      S(24, 70),      S(9, 18),       S(-43, 12),     //
    S(94, 17),      S(96, 50),      S(105, 69),     S(108, 109),    S(115, 103),    S(81, 74),      S(57, 41),      S(37, 27),      //
    S(71, 12),      S(106, 2),      S(100, 54),     S(89, 77),      S(77, 75),      S(78, 64),      S(63, 10),      S(21, 20),      //
    S(17, -44),     S(47, -15),     S(50, 21),      S(63, 52),      S(57, 48),      S(31, 14),      S(20, -11),     S(-24, -50),    //
    S(37, -33),     S(43, -28),     S(25, -25),     S(32, -2),      S(29, -5),      S(3, -52),      S(-29, -11),    S(-36, -116),   //
    S(-40, -91),    S(11, -39),     S(32, -59),     S(50, -47),     S(30, -27),     S(-6, -62),     S(-16, -39),    S(-59, -143),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-122, 9),     S(-190, 117),   S(-503, 218),   S(-316, 111),   S(-340, 155),   S(-343, 163),   S(-223, 130),   S(-123, 46),    //
    S(-45, -21),    S(-97, 90),     S(-58, 52),     S(-109, 79),    S(-95, 71),     S(-48, 39),     S(-27, 35),     S(-55, 13),     //
    S(30, 16),      S(8, 63),       S(22, 68),      S(17, 59),      S(15, 36),      S(11, 42),      S(10, 44),      S(14, -0),      //
    S(9, -4),       S(52, 14),      S(62, 38),      S(75, 64),      S(103, 51),     S(47, 23),      S(50, -11),     S(1, -13),      //
    S(53, -62),     S(50, -7),      S(83, 9),       S(96, 31),      S(81, 44),      S(72, 21),      S(25, 1),       S(21, -41),     //
    S(65, -39),     S(90, -28),     S(102, 3),      S(73, 25),      S(69, 6),       S(68, 11),      S(76, -11),     S(25, -27),     //
    S(38, -96),     S(119, -67),    S(78, -32),     S(55, -16),     S(39, -15),     S(56, -53),     S(56, -63),     S(50, -68),     //
    S(56, -91),     S(27, -29),     S(32, -15),     S(57, -41),     S(38, -33),     S(45, 2),       S(53, -29),     S(50, -68),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(200, 79),     S(229, 92),     S(173, 119),    S(167, 90),     S(232, 47),     S(186, 75),     S(210, 80),     S(190, 89),     //
    S(93, 158),     S(162, 149),    S(231, 110),    S(172, 125),    S(216, 111),    S(173, 134),    S(114, 157),    S(102, 161),    //
    S(59, 150),     S(195, 94),     S(216, 84),     S(203, 58),     S(199, 83),     S(136, 124),    S(139, 125),    S(72, 173),     //
    S(32, 114),     S(105, 127),    S(132, 97),     S(111, 98),     S(141, 86),     S(100, 128),    S(93, 135),     S(25, 157),     //
    S(3, 41),       S(79, 51),      S(65, 69),      S(40, 68),      S(49, 78),      S(37, 106),     S(14, 105),     S(-7, 103),     //
    S(13, -42),     S(90, -20),     S(76, 3),       S(55, 5),       S(66, 10),      S(37, 44),      S(42, 24),      S(-6, 36),      //
    S(-73, -46),    S(62, -88),     S(62, -50),     S(49, -17),     S(55, -19),     S(39, -6),      S(30, -22),     S(-0, -14),     //
    S(-12, -77),    S(1, -37),      S(70, -54),     S(79, -54),     S(80, -44),     S(59, -21),     S(58, -35),     S(40, -29),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(23, 183),     S(122, 122),    S(26, 264),     S(-38, 371),    S(1, 328),      S(36, 236),     S(38, 155),     S(-33, 214),    //
    S(35, 183),     S(41, 258),     S(3, 330),      S(-143, 465),   S(-89, 434),    S(-33, 327),    S(20, 183),     S(2, 168),      //
    S(-12, 241),    S(16, 294),     S(-18, 372),    S(-64, 419),    S(-42, 404),    S(10, 289),     S(46, 178),     S(44, 102),     //
    S(8, 145),      S(-4, 251),     S(-39, 318),    S(-62, 399),    S(-43, 403),    S(-3, 260),     S(41, 156),     S(20, 118),     //
    S(1, 129),      S(-9, 170),     S(-26, 235),    S(-49, 307),    S(-33, 329),    S(-8, 250),     S(3, 167),      S(31, 73),      //
    S(3, 26),       S(25, 51),      S(17, 136),     S(-6, 159),     S(4, 168),      S(8, 197),      S(30, 123),     S(21, 75),      //
    S(-24, -131),   S(5, -113),     S(6, -30),      S(29, 8),       S(22, 56),      S(27, 30),      S(1, 61),       S(18, 35),      //
    S(-36, -105),   S(-18, -258),   S(11, -256),    S(27, -147),    S(31, -60),     S(34, -97),     S(31, -67),     S(5, -27),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(135, -575),   S(463, 17),     S(283, 172),    S(14, 136),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(326, -157),   S(337, 145),    S(172, 201),    S(3, 158),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(160, 72),     S(177, 208),    S(83, 227),     S(-54, 187),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-10, 31),     S(52, 158),     S(-54, 194),    S(-110, 203),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-125, 6),     S(-52, 95),     S(-120, 159),   S(-194, 200),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-49, -34),    S(6, 40),       S(-81, 117),    S(-128, 156),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(28, -92),     S(30, -10),     S(-32, 49),     S(-103, 98),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, -197),   S(9, -85),      S(-72, -26),    S(-65, -50),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-100, -436);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -7), S(9, 10), S(10, 5), S(4, 0), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(4, 3), S(3, 1), S(3, -1), S(3, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -19), S(-5, 5), S(-1, -8), S(10, -16), S(15, -30), S(9, -55), S(-1, -47), }},
  {{ S(2, 3), S(-21, 4), S(-17, 11), S(-9, 17), S(-7, 8), S(-7, -20), S(-18, -26), }},
  {{ S(-2, -2), S(-9, -9), S(-11, 17), S(-6, 17), S(-6, 9), S(-6, -20), S(-22, -39), }},
  {{ S(8, 6), S(-8, 15), S(-5, 36), S(-1, 41), S(-2, 35), S(7, 8), S(11, -21), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 27), S(-4, 4), S(-6, 10), S(-4, 27), S(2, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 10), S(-42, -143), S(-8, -50), S(1, 4), S(-0, 3), S(-4, 10), S(-4, 8), }},
  {{ S(11, -2), S(-24, -156), S(-4, -33), S(-1, 0), S(2, -4), S(-5, 3), S(4, 1), }},
  {{ S(1, 9), S(-9, -86), S(8, -20), S(1, 9), S(-2, 10), S(-8, 18), S(-4, 19), }},
  {{ S(3, 0), S(5, -64), S(-1, 30), S(-2, 26), S(-5, 10), S(-11, 12), S(-9, 20), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1406, 886, -19, -6
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(82);
inline VParam WINNABLE_PAWN_ENDGAME = V(102);
inline VParam WINNABLE_BIAS = V(-357);

// Epoch duration: 7.33087s
// clang-format on
}  // namespace Clockwork
