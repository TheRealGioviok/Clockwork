#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(200, 380);
inline const PParam KNIGHT_MAT = S(915, 1003);
inline const PParam BISHOP_MAT = S(950, 1050);
inline const PParam ROOK_MAT   = S(1148, 1726);
inline const PParam QUEEN_MAT  = S(2652, 2824);
inline const PParam TEMPO_VAL  = S(62, 19);

inline const PParam BISHOP_PAIR_VAL   = S(50, 206);
inline const PParam ROOK_OPEN_VAL     = S(118, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 26);
inline const PParam MINOR_BEHIND_PAWN = S(12, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -19);

inline const PParam POTENTIAL_CHECKER_VAL = S(-56, -12);
inline const PParam OUTPOST_KNIGHT_VAL    = S(47, 59);
inline const PParam OUTPOST_BISHOP_VAL    = S(62, 28);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(48, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(57, -25);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -3), S(29, 28), S(60, 50), S(142, 145), S(390, 199), S(434, 534),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 34), S(46, 28), S(63, 52), S(120, 146), S(410, 86),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-101, -196), S(-103, -166), S(-81, -56), S(-25, 47), S(64, 192), S(246, 279),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -39), S(22, -2), S(15, 32), S(-2, 118), S(68, 220), S(221, 278),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -21), S(2, 22), S(-2, -10), S(1, -43), S(1, -139), S(-240, -225),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 184), S(-3, 155), S(2, 88), S(7, 55), S(13, 56), S(51, 51), S(46, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-232, -76), S(8, 15), S(1, 85), S(33, 121), S(52, 142), S(61, 149), S(40, 148),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-113, -244), S(-47, -75), S(-16, 14), S(10, 45), S(43, 59), S(59, 86), S(83, 79), S(104, 85), S(154, -13),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-80, -217), S(-37, -56), S(17, 6), S(41, 49), S(66, 77), S(81, 97), S(90, 110), S(102, 114), S(107, 122), S(129, 99), S(134, 96), S(186, 30), S(187, 28), S(224, -34),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(97, -113), S(14, 43), S(36, 69), S(53, 78), S(63, 91), S(68, 102), S(74, 113), S(82, 115), S(87, 125), S(95, 127), S(104, 127), S(108, 131), S(111, 129), S(125, 97), S(210, -10),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-127, -99), S(7, -14), S(34, 94), S(54, 199), S(69, 241), S(78, 281), S(84, 308), S(91, 318), S(95, 337), S(97, 351), S(103, 355), S(106, 361), S(111, 359), S(111, 363), S(112, 362), S(107, 365), S(105, 362), S(106, 358), S(111, 348), S(111, 347), S(111, 331), S(134, 291), S(119, 300), S(123, 245), S(113, 229), S(111, 203), S(67, 219), S(87, 172),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 85);
inline const PParam PAWN_THREAT_BISHOP = S(206, 129);
inline const PParam PAWN_THREAT_ROOK   = S(192, 128);
inline const PParam PAWN_THREAT_QUEEN  = S(176, -1);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -13);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 54);
inline const PParam BISHOP_THREAT_ROOK   = S(214, 123);
inline const PParam BISHOP_THREAT_QUEEN  = S(171, 104);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -28), S(-4, -2), S(-6, -10), S(-8, -20), S(-12, -30), S(-15, -38), S(-17, -49), S(-22, -51), S(-37, -48),
};

inline const PParam ROOK_LINEUP = S(13, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(227, 168),    S(40, 263),     S(176, 234),    S(165, 171),    S(220, 98),     S(117, 181),    S(61, 217),     S(193, 175),    //
    S(43, 10),      S(75, 38),      S(87, -6),      S(54, -45),     S(46, -70),     S(27, -29),     S(13, 20),      S(-26, 49),     //
    S(19, -17),     S(-6, -2),      S(28, -46),     S(16, -70),     S(10, -84),     S(-10, -59),    S(-54, -16),    S(-52, 8),      //
    S(-13, -63),    S(-35, -34),    S(-2, -60),     S(-16, -67),    S(-39, -68),    S(-40, -53),    S(-96, -18),    S(-86, -24),    //
    S(-8, -95),     S(21, -91),     S(11, -51),     S(-9, -48),     S(-37, -56),    S(-50, -51),    S(-84, -35),    S(-83, -41),    //
    S(8, -90),      S(89, -91),     S(85, -51),     S(24, -23),     S(-5, -36),     S(-22, -46),    S(-54, -26),    S(-67, -24),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-340, -308),  S(-276, 23),    S(-286, -64),   S(-11, 2),      S(-91, 12),     S(-239, 35),    S(-411, 105),   S(-411, -208),  //
    S(-39, -17),    S(-12, 4),      S(107, -35),    S(119, -25),    S(110, -10),    S(29, 20),      S(-35, 21),     S(-65, 11),     //
    S(34, -30),     S(76, -40),     S(105, 24),     S(118, 16),     S(84, 50),      S(25, 69),      S(19, 6),       S(-30, 0),      //
    S(93, 0),       S(117, 6),      S(121, 39),     S(125, 66),     S(123, 80),     S(76, 75),      S(51, 42),      S(34, 20),      //
    S(71, 6),       S(119, -22),    S(99, 43),      S(90, 70),      S(67, 75),      S(71, 70),      S(58, 18),      S(10, 35),      //
    S(5, -15),      S(34, 1),       S(30, 46),      S(45, 64),      S(38, 65),      S(5, 57),       S(-1, 20),      S(-41, -14),    //
    S(21, -6),      S(32, -11),     S(7, 5),        S(15, 28),      S(10, 28),      S(-14, -16),    S(-34, 2),      S(-48, -83),    //
    S(-52, -61),    S(-1, 0),       S(17, -24),     S(33, -19),     S(16, -2),      S(-19, -28),    S(-32, -7),     S(-74, -99),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-155, 76),    S(-164, 78),    S(-450, 135),   S(-295, 76),    S(-295, 84),    S(-314, 78),    S(-211, 76),    S(-129, 61),    //
    S(-38, -3),     S(-78, 75),     S(-39, 18),     S(-91, 44),     S(-72, 37),     S(-57, 40),     S(-18, 34),     S(-52, 15),     //
    S(33, 3),       S(23, 33),      S(36, 37),      S(23, 37),      S(7, 34),       S(4, 49),       S(13, 37),      S(9, 14),       //
    S(17, -12),     S(53, 5),       S(57, 35),      S(58, 73),      S(88, 61),      S(31, 36),      S(38, 1),       S(-9, 9),       //
    S(48, -52),     S(53, -13),     S(70, 21),      S(74, 54),      S(52, 68),      S(47, 50),      S(14, 16),      S(8, -19),      //
    S(66, -36),     S(84, -21),     S(92, 17),      S(54, 45),      S(48, 30),      S(46, 43),      S(56, 18),      S(11, -2),      //
    S(27, -66),     S(104, -37),    S(69, -18),     S(46, 5),       S(29, 8),       S(37, -17),     S(33, -23),     S(37, -38),     //
    S(48, -58),     S(32, -25),     S(35, 4),       S(52, -19),     S(36, -11),     S(42, 23),      S(41, 1),       S(35, -29),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(195, 84),     S(226, 93),     S(173, 111),    S(185, 69),     S(221, 69),     S(182, 85),     S(197, 100),    S(180, 111),    //
    S(88, 146),     S(171, 142),    S(227, 105),    S(163, 119),    S(198, 119),    S(172, 124),    S(116, 157),    S(96, 167),     //
    S(51, 152),     S(175, 125),    S(217, 81),     S(188, 75),     S(181, 107),    S(137, 129),    S(138, 138),    S(69, 181),     //
    S(21, 119),     S(106, 116),    S(137, 82),     S(118, 90),     S(143, 91),     S(98, 127),     S(98, 132),     S(22, 164),     //
    S(-2, 54),      S(75, 58),      S(68, 65),      S(42, 68),      S(45, 91),      S(35, 112),     S(6, 119),      S(-11, 117),    //
    S(7, -7),       S(84, 8),       S(76, 15),      S(53, 19),      S(60, 34),      S(29, 66),      S(35, 52),      S(-6, 64),      //
    S(-87, -1),     S(53, -37),     S(60, -26),     S(50, -4),      S(51, 7),       S(39, 18),      S(27, 13),      S(-6, 29),      //
    S(-24, -15),    S(2, 4),        S(61, -14),     S(73, -19),     S(72, -5),      S(52, 13),      S(47, 12),      S(26, 21),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(96, 107),     S(180, 60),     S(106, 152),    S(62, 211),     S(85, 193),     S(82, 182),     S(104, 111),    S(32, 179),     //
    S(83, 139),     S(92, 230),     S(82, 198),     S(-56, 290),    S(-27, 308),    S(10, 285),     S(58, 189),     S(33, 196),     //
    S(50, 178),     S(95, 187),     S(54, 254),     S(19, 261),     S(13, 306),     S(55, 254),     S(77, 199),     S(79, 137),     //
    S(68, 86),      S(71, 162),     S(24, 228),     S(11, 274),     S(12, 315),     S(40, 232),     S(82, 167),     S(54, 152),     //
    S(67, 60),      S(48, 122),     S(30, 174),     S(3, 240),      S(5, 290),      S(21, 249),     S(41, 180),     S(62, 113),     //
    S(51, 11),      S(73, 36),      S(69, 108),     S(44, 133),     S(42, 168),     S(42, 206),     S(56, 159),     S(49, 116),     //
    S(20, -87),     S(41, -56),     S(52, -13),     S(72, 38),      S(61, 89),      S(58, 77),      S(28, 121),     S(45, 97),      //
    S(7, -82),      S(31, -196),    S(53, -177),    S(73, -90),     S(65, 11),      S(72, -37),     S(66, -7),      S(40, 19),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-48, -208),   S(248, 253),    S(214, 192),    S(141, 54),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(196, 34),     S(271, 208),    S(197, 180),    S(169, 49),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(183, 103),    S(237, 176),    S(220, 158),    S(198, 70),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(37, 55),      S(155, 104),    S(92, 129),     S(95, 123),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-77, 17),     S(-8, 63),      S(-17, 102),    S(-69, 153),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-26, -18),    S(-2, 28),      S(-50, 80),     S(-72, 126),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(17, -77),     S(-8, -24),     S(-78, 32),     S(-133, 77),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-7, -158),    S(4, -89),      S(-85, -40),    S(-78, -55),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-64, -103);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(4, 13), S(11, 18), S(10, 19), S(-2, 18), S(-3, 8),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(8, -5), S(6, 8), S(5, 4), S(4, 6), S(3, 10),
};

inline const PParam WEAK_SQUARE_INNER_RING = S(-6, -5);
inline const PParam WEAK_SQUARE_OUTER_RING = S(5, -8);

inline const PParam KS_FLANK_ATTACK = S(4, -1);
inline const PParam KS_FLANK_DEFENSE = S(-6, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -3);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, -0);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(42, -17), S(13, -11), S(14, -14), S(24, -5), S(24, -7), S(15, -18), S(13, -8), }},
  {{ S(5, 4), S(-33, -4), S(-33, 26), S(-22, 38), S(-19, 37), S(-30, 27), S(-32, -1), }},
  {{ S(4, 2), S(-8, -19), S(-11, 15), S(-11, 25), S(-10, 27), S(-10, 16), S(-7, -15), }},
  {{ S(19, 5), S(-3, -7), S(1, 28), S(5, 31), S(4, 32), S(-1, 28), S(-2, 1), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(8, 32), S(-8, 1), S(-7, 6), S(-2, 18), S(4, 12),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(14, 2), S(-2, -6), S(-7, 7), S(-2, 1), S(-5, 6), S(-9, 13), S(-5, -0), }},
  {{ S(19, -7), S(2, 8), S(-13, 14), S(-7, 8), S(-8, 8), S(-9, 12), S(4, 6), }},
  {{ S(9, -0), S(-4, 16), S(-7, 11), S(-2, 7), S(-1, 3), S(-6, 8), S(-2, 14), }},
  {{ S(5, 3), S(-6, 7), S(-12, 9), S(-6, 13), S(-4, 10), S(-12, 12), S(-9, 9), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        748, 1051, -10, 14
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(126);
inline VParam WINNABLE_PAWN_ENDGAME = V(212);
inline VParam WINNABLE_BIAS = V(-671);

// Epoch duration: 7.30985s
// clang-format on
}  // namespace Clockwork
