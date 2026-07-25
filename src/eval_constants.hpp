#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(201, 504);
inline const PParam KNIGHT_MAT = S(815, 1584);
inline const PParam BISHOP_MAT = S(862, 1666);
inline const PParam ROOK_MAT   = S(1035, 2652);
inline const PParam QUEEN_MAT  = S(2401, 4092);

inline const PParam TEMPO_VAL  = S(69, 53);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -3);
inline const PParam BISHOP_PAIR_VAL   = S(61, 239);
inline const PParam ROOK_OPEN_VAL     = S(109, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 11);
inline const PParam MINOR_BEHIND_PAWN = S(15, 41);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -39);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 50);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -1), S(33, 35), S(59, 66), S(121, 212), S(386, 402), S(673, 815),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 32), S(39, 25), S(53, 56), S(90, 180), S(384, 121),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -259), S(-94, -218), S(-66, -86), S(-22, 39), S(87, 198), S(226, 404),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-80, 53), S(-92, 35), S(-58, 104), S(-88, 228), S(-55, 339), S(51, 221),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-16, 68), S(-28, 59), S(-60, 107), S(-32, 134), S(73, 158), S(34, 192),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -39), S(24, -2), S(16, 34), S(21, 103), S(70, 270), S(332, 215),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -36), S(2, 8), S(-3, -27), S(-0, -68), S(-14, -175), S(-166, -450),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 233), S(9, 181), S(3, 105), S(11, 66), S(19, 71), S(57, 66), S(60, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-131, -46), S(15, -2), S(2, 100), S(28, 150), S(44, 184), S(55, 193), S(41, 173),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-94, -393), S(-26, -141), S(4, -27), S(27, 22), S(55, 54), S(70, 91), S(88, 98), S(107, 106), S(126, 60),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-71, -348), S(-17, -128), S(35, -39), S(60, 15), S(79, 57), S(91, 88), S(96, 111), S(99, 132), S(103, 143), S(109, 149), S(118, 143), S(132, 126), S(132, 131), S(117, 96),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(98, -214), S(23, -12), S(44, 21), S(59, 40), S(70, 58), S(74, 73), S(79, 88), S(85, 94), S(89, 106), S(94, 114), S(98, 121), S(99, 130), S(102, 135), S(107, 121), S(126, 83),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-191, -205), S(-38, -91), S(-14, 51), S(5, 191), S(22, 233), S(29, 286), S(36, 324), S(43, 341), S(48, 364), S(51, 381), S(57, 389), S(61, 396), S(65, 403), S(67, 409), S(67, 411), S(67, 414), S(63, 416), S(66, 409), S(67, 404), S(71, 397), S(61, 387), S(72, 361), S(38, 389), S(-7, 381), S(-42, 381), S(-76, 402), S(-135, 431), S(-100, 365),
};

inline const PParam PAWN_THREAT_KNIGHT = S(196, 154);
inline const PParam PAWN_THREAT_BISHOP = S(171, 221);
inline const PParam PAWN_THREAT_ROOK   = S(187, 155);
inline const PParam PAWN_THREAT_QUEEN  = S(158, 13);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 57), S(93, 94), S(103, 125), S(205, 123), S(162, 3), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 57), S(53, 96), S(74, 95), S(17, 11), S(150, -48), S(0, 0),
};
inline const PParam KING_THREAT  = S(-11, 156);
inline const PParam HANGING_PAWN  = S(31, 93);
inline const PParam HANGING_NON_PAWN  = S(69, 28);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(21, 9),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 45), S(107, -105),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 11), S(47, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -17), S(4, -15), S(-1, -21), S(-6, -29), S(-12, -37), S(-17, -43), S(-19, -55), S(-25, -56), S(-30, -73),
};

inline const PParam ROOK_LINEUP = S(17, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(183, 275),    S(62, 395),     S(68, 384),     S(156, 269),    S(189, 169),    S(143, 209),    S(121, 239),    S(221, 179),    //
    S(41, 63),      S(54, 109),     S(33, 61),      S(47, -6),      S(39, -42),     S(12, -14),     S(13, 26),      S(-20, 53),     //
    S(38, -13),     S(15, -5),      S(43, -45),     S(25, -68),     S(17, -87),     S(3, -75),      S(-36, -44),    S(-38, -5),     //
    S(-7, -72),     S(-31, -43),    S(1, -61),      S(-10, -77),    S(-31, -87),    S(-36, -74),    S(-82, -57),    S(-76, -52),    //
    S(-14, -110),   S(18, -106),    S(3, -44),      S(-14, -50),    S(-40, -60),    S(-54, -70),    S(-80, -71),    S(-83, -74),    //
    S(8, -107),     S(82, -94),     S(71, -40),     S(24, -11),     S(-5, -32),     S(-24, -60),    S(-50, -59),    S(-63, -57),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-260, -499),  S(-257, 49),    S(-264, -30),   S(-0, 41),      S(-92, 42),     S(-266, 81),    S(-345, 98),    S(-346, -403),  //
    S(-2, -12),     S(2, 27),       S(86, 25),      S(83, 60),      S(88, 48),      S(50, 28),      S(-17, 24),     S(-45, 22),     //
    S(40, -25),     S(41, 28),      S(57, 59),      S(73, 70),      S(56, 71),      S(21, 56),      S(7, 35),       S(-35, 8),      //
    S(89, 21),      S(90, 47),      S(100, 68),     S(103, 108),    S(107, 106),    S(72, 71),      S(51, 37),      S(32, 31),      //
    S(77, 14),      S(101, 2),      S(98, 48),      S(93, 79),      S(80, 82),      S(72, 62),      S(57, 17),      S(24, 24),      //
    S(18, -42),     S(43, -25),     S(50, 19),      S(62, 52),      S(58, 50),      S(31, 14),      S(14, -18),     S(-24, -41),    //
    S(36, -25),     S(38, -11),     S(26, -19),     S(37, 8),       S(33, 6),       S(4, -44),      S(-31, -1),     S(-50, -83),    //
    S(-44, -93),    S(9, -29),      S(27, -44),     S(44, -33),     S(27, -19),     S(-10, -51),    S(-21, -27),    S(-71, -141),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-128, 21),    S(-189, 102),   S(-398, 166),   S(-271, 98),    S(-301, 140),   S(-301, 152),   S(-223, 126),   S(-126, 71),    //
    S(-26, -20),    S(-64, 87),     S(-46, 63),     S(-68, 61),     S(-65, 75),     S(-38, 47),     S(-10, 41),     S(-51, 25),     //
    S(34, 19),      S(17, 58),      S(31, 69),      S(28, 54),      S(22, 44),      S(21, 48),      S(9, 43),       S(11, 13),      //
    S(16, -6),      S(49, 21),      S(61, 35),      S(79, 55),      S(103, 41),     S(42, 20),      S(45, -3),      S(-1, -2),      //
    S(37, -44),     S(45, 3),       S(76, 13),      S(91, 27),      S(75, 38),      S(65, 25),      S(20, 5),       S(10, -37),     //
    S(57, -29),     S(80, -24),     S(95, 5),       S(64, 29),      S(60, 13),      S(57, 14),      S(58, -3),      S(16, -22),     //
    S(26, -72),     S(112, -57),    S(65, -18),     S(47, -1),      S(31, -2),      S(45, -43),     S(45, -57),     S(38, -49),     //
    S(43, -71),     S(23, -24),     S(30, -9),      S(43, -31),     S(28, -19),     S(37, 15),      S(43, -16),     S(39, -60),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(173, 107),    S(200, 128),    S(155, 157),    S(139, 130),    S(201, 84),     S(158, 112),    S(167, 127),    S(150, 125),    //
    S(86, 149),     S(143, 153),    S(185, 126),    S(140, 112),    S(176, 98),     S(144, 123),    S(97, 154),     S(88, 156),     //
    S(56, 143),     S(176, 86),     S(201, 70),     S(172, 56),     S(177, 72),     S(119, 113),    S(114, 129),    S(61, 168),     //
    S(29, 111),     S(92, 118),     S(111, 93),     S(94, 93),      S(122, 76),     S(82, 118),     S(74, 131),     S(20, 156),     //
    S(5, 43),       S(62, 53),      S(55, 75),      S(24, 85),      S(34, 89),      S(23, 114),     S(6, 111),      S(-14, 115),    //
    S(16, -36),     S(83, -10),     S(71, 15),      S(50, 27),      S(59, 35),      S(36, 57),      S(33, 42),      S(-5, 48),      //
    S(-63, -41),    S(61, -78),     S(67, -40),     S(55, -7),      S(59, -6),      S(44, 8),       S(35, -8),      S(4, -5),       //
    S(-0, -63),     S(23, -32),     S(86, -43),     S(94, -43),     S(96, -39),     S(73, -16),     S(68, -22),     S(47, -17),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(89, 152),     S(145, 153),    S(57, 294),     S(-3, 393),     S(34, 346),     S(72, 253),     S(71, 173),     S(26, 204),     //
    S(58, 181),     S(77, 236),     S(37, 318),     S(-81, 433),    S(-41, 406),    S(19, 285),     S(58, 172),     S(40, 143),     //
    S(20, 231),     S(59, 258),     S(28, 334),     S(-8, 369),     S(11, 357),     S(50, 255),     S(81, 153),     S(62, 116),     //
    S(16, 168),     S(28, 235),     S(-12, 302),    S(-11, 355),    S(5, 349),      S(22, 233),     S(60, 152),     S(35, 115),     //
    S(13, 142),     S(11, 164),     S(3, 214),      S(-22, 283),    S(-11, 299),    S(11, 232),     S(16, 171),     S(36, 79),      //
    S(4, 48),       S(35, 58),      S(31, 132),     S(10, 154),     S(20, 161),     S(22, 184),     S(41, 113),     S(21, 93),      //
    S(-24, -96),    S(5, -95),      S(13, -28),     S(40, 12),      S(37, 51),      S(39, 23),      S(13, 62),      S(25, 34),      //
    S(-41, -81),    S(-10, -241),   S(21, -245),    S(33, -135),    S(40, -57),     S(38, -75),     S(36, -62),     S(6, -8),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(166, -552),   S(473, 82),     S(313, 192),    S(19, 188),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(366, -183),   S(363, 187),    S(209, 201),    S(26, 154),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(197, 44),     S(230, 173),    S(114, 196),    S(-49, 177),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(38, 7),       S(113, 112),    S(-21, 170),    S(-117, 199),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-112, -2),    S(-22, 76),     S(-85, 145),    S(-181, 196),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -34),    S(12, 33),      S(-68, 114),    S(-123, 158),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -93),     S(29, -13),     S(-34, 49),     S(-108, 105),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -210),   S(3, -92),      S(-74, -28),    S(-82, -41),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -449);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 2), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -18), S(-7, 5), S(-3, -9), S(6, -16), S(12, -29), S(6, -53), S(-4, -45), }},
  {{ S(2, 4), S(-21, 2), S(-17, 10), S(-10, 18), S(-7, 8), S(-10, -12), S(-19, -21), }},
  {{ S(-4, -2), S(-12, -9), S(-13, 16), S(-8, 18), S(-7, 9), S(-7, -18), S(-23, -39), }},
  {{ S(6, 9), S(-10, 18), S(-7, 39), S(-2, 43), S(-2, 39), S(3, 20), S(9, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 24), S(-6, 3), S(-7, 10), S(-6, 29), S(1, 49),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 12), S(-41, -123), S(-9, -38), S(-1, 5), S(-3, 4), S(-6, 11), S(-5, 10), }},
  {{ S(8, -1), S(-25, -124), S(-6, -29), S(-4, 1), S(-2, -2), S(-9, 4), S(1, 4), }},
  {{ S(-0, 12), S(-8, -68), S(7, -15), S(-0, 9), S(-4, 12), S(-10, 19), S(-6, 22), }},
  {{ S(0, 1), S(2, -63), S(-1, 25), S(-3, 26), S(-6, 9), S(-12, 11), S(-9, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1422, 904, -22, -4
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(75);
inline VParam WINNABLE_BIAS = V(-386);

// Epoch duration: 7.37506s
// clang-format on
}  // namespace Clockwork
