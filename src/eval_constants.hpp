#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(205, 511);
inline const PParam KNIGHT_MAT = S(787, 1596);
inline const PParam BISHOP_MAT = S(843, 1666);
inline const PParam ROOK_MAT   = S(1020, 2648);
inline const PParam QUEEN_MAT  = S(2437, 4085);

inline const PParam TEMPO_VAL  = S(69, 58);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 3);
inline const PParam BISHOP_PAIR_VAL   = S(60, 235);
inline const PParam ROOK_OPEN_VAL     = S(108, -8);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 18);
inline const PParam MINOR_BEHIND_PAWN = S(14, 40);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-23, -84);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -34);
inline const PParam OUTPOST_KNIGHT_VAL    = S(45, 32);
inline const PParam OUTPOST_BISHOP_VAL    = S(34, 29);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 57);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -47);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -1), S(31, 35), S(59, 65), S(121, 215), S(397, 406), S(682, 832),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 35), S(39, 26), S(53, 57), S(92, 181), S(401, 118),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-90, -265), S(-93, -221), S(-66, -88), S(-20, 39), S(87, 204), S(222, 421),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-92, 54), S(-99, 40), S(-68, 110), S(-96, 239), S(-58, 348), S(45, 226),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-28, 66), S(-36, 58), S(-66, 109), S(-32, 136), S(76, 158), S(24, 200),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(22, -40), S(21, -2), S(13, 36), S(18, 108), S(67, 276), S(337, 224),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(11, -40), S(5, 4), S(-4, -29), S(-1, -74), S(-11, -182), S(-173, -460),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 239), S(8, 187), S(3, 110), S(10, 70), S(19, 73), S(58, 66), S(62, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-133, -45), S(12, -2), S(1, 101), S(28, 152), S(44, 187), S(55, 196), S(40, 176),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-32, -333), S(-1, -119), S(14, -32), S(28, 3), S(45, 31), S(53, 71), S(62, 91), S(73, 119), S(86, 89),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-79, -293), S(-29, -84), S(23, -14), S(47, 26), S(67, 53), S(78, 72), S(83, 84), S(85, 97), S(87, 103), S(91, 110), S(101, 101), S(112, 88), S(106, 95), S(92, 62),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(85, -169), S(16, 3), S(36, 32), S(52, 47), S(62, 59), S(66, 68), S(69, 77), S(75, 78), S(79, 87), S(83, 92), S(86, 96), S(85, 104), S(87, 108), S(93, 95), S(116, 56),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-195, -123), S(-43, -47), S(-20, 60), S(-6, 180), S(9, 211), S(15, 252), S(22, 282), S(28, 295), S(33, 314), S(36, 330), S(42, 337), S(47, 344), S(50, 351), S(53, 357), S(54, 362), S(54, 366), S(52, 367), S(55, 361), S(57, 359), S(63, 350), S(55, 342), S(70, 314), S(34, 347), S(-8, 338), S(-45, 342), S(-72, 364), S(-135, 397), S(-92, 331),
};

inline const std::array<PParam, 21> KNIGHT_REACH = {
    S(-31, -17), S(0, -1), S(12, 18), S(22, 23), S(31, 34), S(35, 47), S(40, 54), S(43, 53), S(47, 55), S(52, 52), S(57, 48), S(60, 46), S(61, 41), S(67, 30), S(73, 15), S(74, 5), S(80, -14), S(87, -32), S(94, -45), S(92, -64), S(65, -110),
};
inline const std::array<PParam, 18> BISHOP_REACH = {
    S(43, -30), S(41, -31), S(46, -21), S(50, -1), S(49, 12), S(51, 15), S(50, 24), S(50, 31), S(48, 38), S(49, 44), S(49, 50), S(51, 53), S(54, 58), S(59, 58), S(67, 58), S(74, 54), S(77, 55), S(53, 58),
};
inline const std::array<PParam, 20> ROOK_REACH = {
    S(52, -10), S(50, 7), S(53, 16), S(56, 25), S(62, 27), S(66, 32), S(69, 37), S(73, 45), S(74, 56), S(77, 60), S(76, 71), S(79, 79), S(77, 89), S(79, 96), S(80, 100), S(77, 107), S(76, 116), S(72, 126), S(74, 126), S(81, 128),
};
inline const std::array<PParam, 23> QUEEN_REACH = {
    S(-17, 97), S(-21, 146), S(-12, 193), S(-4, 215), S(0, 225), S(4, 241), S(6, 248), S(10, 261), S(11, 268), S(17, 263), S(16, 276), S(15, 288), S(20, 288), S(23, 286), S(27, 287), S(31, 288), S(33, 283), S(42, 280), S(52, 258), S(54, 268), S(80, 226), S(94, 208), S(119, 168),
};

inline const PParam PAWN_THREAT_KNIGHT = S(198, 172);
inline const PParam PAWN_THREAT_BISHOP = S(171, 228);
inline const PParam PAWN_THREAT_ROOK   = S(193, 163);
inline const PParam PAWN_THREAT_QUEEN  = S(163, 34);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(13, 59), S(96, 114), S(109, 123), S(181, 106), S(166, 27), }},
  {{ S(11, 59), S(85, 112), S(108, 120), S(223, 626), S(150, 79), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(14, 71), S(47, 128), S(60, 140), S(14, 19), S(158, -71), }},
  {{ S(7, 56), S(63, 103), S(97, 99), S(26, 18), S(380, 910), }},
}};
inline const PParam KING_THREAT  = S(-6, 160);
inline const PParam REACH_THREAT = S(-13, 9);
inline const PParam REACH_THREAT_LOOSE = S(13, 27);
inline const PParam HANGING_PAWN  = S(35, 91);
inline const PParam HANGING_NON_PAWN  = S(77, 36);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -18), S(7, 26),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 48), S(95, -89),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(38, 7), S(51, -17),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -15), S(3, -11), S(-1, -17), S(-7, -24), S(-13, -30), S(-18, -35), S(-20, -46), S(-26, -45), S(-32, -62),
};

inline const PParam ROOK_LINEUP = S(17, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(188, 282),    S(59, 405),     S(59, 394),     S(148, 279),    S(182, 175),    S(135, 216),    S(117, 245),    S(222, 188),    //
    S(37, 65),      S(41, 114),     S(14, 65),      S(26, -1),      S(20, -40),     S(-6, -11),     S(-1, 32),      S(-27, 58),     //
    S(35, -11),     S(5, -1),       S(31, -42),     S(12, -66),     S(2, -84),      S(-10, -72),    S(-48, -39),    S(-43, -1),     //
    S(-3, -73),     S(-31, -41),    S(2, -62),      S(-9, -78),     S(-32, -87),    S(-37, -76),    S(-85, -54),    S(-74, -51),    //
    S(-11, -112),   S(21, -108),    S(9, -47),      S(-7, -51),     S(-34, -61),    S(-48, -71),    S(-78, -71),    S(-81, -74),    //
    S(14, -109),    S(89, -95),     S(80, -41),     S(37, -11),     S(7, -31),      S(-15, -59),    S(-44, -55),    S(-58, -56),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-273, -516),  S(-267, 36),    S(-279, -37),   S(-22, 48),     S(-120, 56),    S(-283, 80),    S(-364, 96),    S(-362, -423),  //
    S(-8, -28),     S(-9, 22),      S(71, 21),      S(54, 77),      S(57, 70),      S(31, 31),      S(-32, 23),     S(-56, 11),     //
    S(34, -32),     S(31, 22),      S(38, 46),      S(41, 84),      S(26, 80),      S(3, 37),       S(-7, 29),      S(-45, 6),      //
    S(82, 20),      S(80, 52),      S(84, 79),      S(75, 156),     S(76, 158),     S(51, 87),      S(34, 50),      S(21, 33),      //
    S(69, 11),      S(88, 12),      S(88, 55),      S(68, 134),     S(55, 134),     S(58, 74),      S(39, 35),      S(11, 24),      //
    S(20, -43),     S(57, -40),     S(68, -13),     S(69, 39),      S(66, 37),      S(47, -13),     S(24, -29),     S(-26, -43),    //
    S(42, -30),     S(48, -20),     S(46, -35),     S(55, -2),      S(51, 2),       S(27, -50),     S(-17, 1),      S(-45, -89),    //
    S(-43, -110),   S(10, -41),     S(31, -54),     S(39, -38),     S(25, -25),     S(-9, -51),     S(-22, -38),    S(-77, -158),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-140, 24),    S(-202, 101),   S(-418, 166),   S(-290, 97),    S(-316, 132),   S(-314, 143),   S(-232, 118),   S(-131, 59),    //
    S(-35, -17),    S(-79, 95),     S(-63, 65),     S(-88, 61),     S(-92, 83),     S(-59, 55),     S(-26, 53),     S(-58, 21),     //
    S(30, 15),      S(5, 63),       S(14, 76),      S(5, 63),       S(3, 49),       S(2, 55),       S(-7, 50),      S(3, 12),       //
    S(9, -10),      S(41, 17),      S(46, 36),      S(62, 55),      S(83, 44),      S(23, 22),      S(32, -3),      S(-10, -7),     //
    S(31, -48),     S(38, -1),      S(72, 7),       S(82, 21),      S(65, 33),      S(57, 25),      S(9, 8),        S(1, -38),      //
    S(51, -33),     S(74, -26),     S(95, -3),      S(62, 19),      S(58, 11),      S(55, 14),      S(52, -2),      S(11, -27),     //
    S(21, -73),     S(111, -49),    S(69, -24),     S(55, -3),      S(38, 2),       S(51, -38),     S(46, -44),     S(33, -46),     //
    S(36, -77),     S(18, -32),     S(25, -22),     S(41, -39),     S(25, -22),     S(34, 9),       S(37, -22),     S(32, -67),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(173, 99),     S(196, 116),    S(149, 144),    S(132, 119),    S(187, 80),     S(148, 102),    S(153, 123),    S(136, 124),    //
    S(86, 141),     S(131, 143),    S(171, 114),    S(125, 102),    S(157, 92),     S(124, 117),    S(80, 147),     S(76, 151),     //
    S(54, 132),     S(168, 66),     S(187, 52),     S(158, 37),     S(158, 56),     S(98, 100),     S(95, 119),     S(47, 161),     //
    S(28, 99),      S(84, 98),      S(101, 73),     S(81, 76),      S(106, 59),     S(64, 102),     S(55, 118),     S(8, 148),      //
    S(3, 37),       S(56, 38),      S(48, 56),      S(16, 69),      S(24, 71),      S(8, 100),      S(-7, 100),     S(-25, 109),    //
    S(14, -41),     S(78, -28),     S(68, -9),      S(45, 6),       S(53, 16),      S(29, 40),      S(23, 27),      S(-13, 41),     //
    S(-65, -46),    S(56, -93),     S(64, -57),     S(54, -20),     S(58, -19),     S(39, 0),       S(29, -12),     S(-2, -4),      //
    S(-6, -51),     S(19, -26),     S(82, -46),     S(89, -38),     S(91, -28),     S(66, -5),      S(61, -11),     S(39, -5),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(88, 141),     S(149, 125),    S(50, 282),     S(-15, 391),    S(22, 337),     S(57, 252),     S(71, 147),     S(23, 186),     //
    S(63, 164),     S(74, 222),     S(23, 315),     S(-106, 444),   S(-58, 400),    S(6, 275),      S(53, 150),     S(41, 118),     //
    S(20, 219),     S(54, 241),     S(11, 333),     S(-36, 374),    S(-18, 360),    S(33, 244),     S(70, 137),     S(59, 98),      //
    S(14, 154),     S(13, 225),     S(-28, 291),    S(-35, 347),    S(-20, 342),    S(3, 221),      S(44, 137),     S(28, 102),     //
    S(10, 125),     S(3, 144),      S(-11, 191),    S(-38, 264),    S(-26, 276),    S(-2, 212),     S(7, 150),      S(28, 64),      //
    S(3, 17),       S(30, 21),      S(24, 96),      S(0, 122),      S(13, 137),     S(19, 157),     S(37, 87),      S(16, 76),      //
    S(-22, -122),   S(9, -145),     S(12, -72),     S(40, -17),     S(39, 23),      S(42, 4),       S(16, 49),      S(24, 20),      //
    S(-45, -100),   S(-12, -273),   S(16, -289),    S(25, -159),    S(31, -77),     S(30, -88),     S(29, -74),     S(-2, -29),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(165, -577),   S(472, 74),     S(307, 192),    S(9, 190),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(362, -189),   S(356, 190),    S(202, 204),    S(15, 158),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(200, 41),     S(231, 173),    S(110, 202),    S(-48, 176),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(41, 6),       S(116, 112),    S(-18, 171),    S(-117, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-106, -5),    S(-16, 76),     S(-81, 145),    S(-180, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-48, -33),    S(17, 32),      S(-64, 113),    S(-124, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(24, -88),     S(31, -10),     S(-29, 49),     S(-104, 106),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-26, -209),   S(1, -88),      S(-78, -26),    S(-87, -40),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-76, -455); 

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -3), S(10, 13), S(10, 6), S(4, 2), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(5, 5), S(2, 2), S(3, -0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -20), S(-6, 5), S(-3, -10), S(7, -17), S(12, -30), S(6, -55), S(-3, -49), }},
  {{ S(3, 4), S(-20, 1), S(-16, 9), S(-9, 17), S(-6, 8), S(-9, -12), S(-18, -21), }},
  {{ S(-4, -1), S(-13, -9), S(-14, 17), S(-9, 18), S(-8, 10), S(-8, -17), S(-24, -37), }},
  {{ S(6, 10), S(-10, 18), S(-7, 39), S(-2, 44), S(-2, 41), S(3, 22), S(9, -12), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 23), S(-6, 2), S(-8, 9), S(-7, 28), S(1, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, 11), S(-42, -113), S(-9, -38), S(-1, 4), S(-4, 4), S(-7, 11), S(-6, 10), }},
  {{ S(7, -1), S(-25, -121), S(-7, -32), S(-5, 1), S(-4, -2), S(-10, 4), S(-1, 3), }},
  {{ S(-1, 11), S(-7, -71), S(6, -15), S(-0, 8), S(-5, 11), S(-11, 18), S(-7, 21), }},
  {{ S(-1, -1), S(3, -69), S(-1, 21), S(-3, 24), S(-7, 7), S(-13, 10), S(-10, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
	1422, 892, -24, -5
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(104);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(77);
inline VParam WINNABLE_BIAS = V(-404);

// Epoch duration: 9.17128s
// clang-format on
}  // namespace Clockwork
