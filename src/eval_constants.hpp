#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(195, 379);
inline const PParam KNIGHT_MAT = S(900, 1022);
inline const PParam BISHOP_MAT = S(944, 1073);
inline const PParam ROOK_MAT   = S(1145, 1709);
inline const PParam QUEEN_MAT  = S(2642, 2822);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 13);
inline const PParam BISHOP_PAIR_VAL   = S(59, 189);
inline const PParam ROOK_OPEN_VAL     = S(120, -19);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 25);
inline const PParam MINOR_BEHIND_PAWN = S(13, 36);
inline const PParam RESTRICTED_SQUARES = S(-25, -5);
inline const std::array<PParam, 5> KNIGHT_CLOSED_BONUS = {
    S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
};

inline const PParam DOUBLED_PAWN_VAL = S(-12, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 49);
inline const PParam OUTPOST_BISHOP_VAL    = S(54, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(46, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -2), S(30, 25), S(58, 49), S(145, 140), S(388, 200), S(438, 518),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(50, 33), S(44, 27), S(60, 53), S(122, 138), S(422, 77),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-115, -175), S(-114, -149), S(-80, -57), S(-20, 34), S(67, 175), S(274, 231),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -33), S(20, 5), S(11, 39), S(1, 112), S(87, 193), S(262, 247),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -22), S(2, 17), S(-3, -10), S(1, -43), S(-4, -127), S(-258, -196),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(27, 165), S(-2, 151), S(1, 88), S(5, 56), S(13, 57), S(49, 55), S(41, 39),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-275, -31), S(-14, 40), S(-5, 92), S(41, 110), S(64, 127), S(74, 131), S(55, 129),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-111, -242), S(-44, -77), S(-12, 10), S(15, 41), S(47, 55), S(63, 85), S(85, 84), S(105, 94), S(132, 41),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-74, -236), S(-28, -76), S(25, -11), S(48, 34), S(70, 67), S(82, 91), S(88, 108), S(96, 118), S(98, 134), S(112, 122), S(113, 125), S(146, 90), S(154, 82), S(164, 64),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(103, -115), S(17, 43), S(39, 71), S(55, 81), S(65, 94), S(70, 105), S(75, 116), S(82, 119), S(86, 129), S(94, 131), S(103, 132), S(106, 139), S(110, 137), S(118, 116), S(181, 36),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-125, -81), S(13, -13), S(38, 100), S(58, 207), S(73, 249), S(81, 288), S(87, 315), S(95, 323), S(99, 343), S(101, 356), S(107, 358), S(110, 365), S(116, 360), S(116, 364), S(118, 361), S(114, 362), S(111, 361), S(115, 351), S(120, 338), S(119, 335), S(121, 313), S(136, 277), S(111, 294), S(105, 237), S(78, 236), S(68, 206), S(21, 231), S(28, 191),
};

inline const PParam PAWN_THREAT_KNIGHT = S(210, 92);
inline const PParam PAWN_THREAT_BISHOP = S(195, 141);
inline const PParam PAWN_THREAT_ROOK   = S(198, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(182, -18);

inline const PParam KNIGHT_THREAT_BISHOP = S(111, 99);
inline const PParam KNIGHT_THREAT_ROOK   = S(230, 66);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -19);

inline const PParam BISHOP_THREAT_KNIGHT = S(100, 61);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(173, 86);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(12, -29), S(-1, -6), S(-4, -14), S(-8, -23), S(-12, -32), S(-16, -38), S(-18, -49), S(-24, -50), S(-39, -46),
};

inline const PParam ROOK_LINEUP = S(14, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(251, 149),    S(47, 247),     S(199, 195),    S(188, 149),    S(225, 96),     S(115, 189),    S(45, 241),     S(212, 154),    //
    S(42, 34),      S(67, 53),      S(85, -6),      S(59, -44),     S(50, -66),     S(23, -14),     S(6, 34),       S(-24, 57),     //
    S(25, -17),     S(5, -11),      S(34, -55),     S(21, -73),     S(16, -84),     S(-5, -58),     S(-51, -15),    S(-48, 8),      //
    S(-9, -63),     S(-30, -35),    S(-1, -64),     S(-14, -67),    S(-33, -68),    S(-37, -54),    S(-94, -19),    S(-83, -26),    //
    S(-12, -87),    S(19, -84),     S(3, -46),      S(-8, -47),     S(-35, -54),    S(-52, -49),    S(-86, -34),    S(-85, -41),    //
    S(11, -90),     S(88, -77),     S(77, -34),     S(27, -17),     S(-2, -31),     S(-23, -44),    S(-56, -26),    S(-66, -26),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-340, -305),  S(-271, 21),    S(-188, -222),  S(-14, 29),     S(-85, 30),     S(-223, 19),    S(-402, 93),    S(-414, -200),  //
    S(-44, -12),    S(-20, 20),     S(91, -6),      S(99, 15),      S(92, 25),      S(20, 36),      S(-44, 37),     S(-63, 9),      //
    S(17, -2),      S(51, -6),      S(80, 53),      S(94, 55),      S(67, 74),      S(21, 70),      S(12, 17),      S(-36, 8),      //
    S(86, 17),      S(98, 38),      S(106, 66),     S(108, 97),     S(114, 98),     S(73, 80),      S(49, 49),      S(34, 23),      //
    S(67, 13),      S(106, 0),      S(91, 58),      S(87, 76),      S(66, 80),      S(72, 65),      S(60, 16),      S(15, 28),      //
    S(6, -18),      S(29, 4),       S(30, 39),      S(45, 60),      S(41, 58),      S(11, 40),      S(5, 9),        S(-34, -24),    //
    S(24, -14),     S(35, -18),     S(10, -2),      S(19, 20),      S(15, 19),      S(-11, -24),    S(-31, -3),     S(-44, -90),    //
    S(-44, -77),    S(6, -16),      S(22, -37),     S(37, -33),     S(22, -14),     S(-13, -39),    S(-25, -24),    S(-66, -113),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-167, 92),    S(-170, 98),    S(-444, 143),   S(-291, 88),    S(-285, 86),    S(-309, 84),    S(-213, 86),    S(-135, 66),    //
    S(-53, 11),     S(-85, 82),     S(-51, 39),     S(-102, 64),    S(-81, 55),     S(-59, 47),     S(-23, 39),     S(-55, 12),     //
    S(17, 29),      S(18, 38),      S(29, 53),      S(15, 56),      S(-1, 50),      S(9, 45),       S(16, 29),      S(3, 18),       //
    S(3, 11),       S(43, 21),      S(59, 39),      S(64, 73),      S(99, 54),      S(39, 30),      S(36, 6),       S(-6, 3),       //
    S(41, -41),     S(44, 3),       S(72, 23),      S(87, 41),      S(69, 52),      S(55, 40),      S(17, 14),      S(8, -19),      //
    S(57, -23),     S(76, -8),      S(94, 16),      S(61, 38),      S(56, 21),      S(57, 27),      S(60, 13),      S(8, 4),        //
    S(23, -58),     S(110, -44),    S(73, -24),     S(46, 2),       S(31, 4),       S(43, -27),     S(40, -33),     S(38, -37),     //
    S(50, -58),     S(36, -30),     S(29, 3),       S(45, -20),     S(30, -8),      S(36, 24),      S(45, -7),      S(41, -35),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(198, 81),     S(227, 98),     S(178, 117),    S(177, 92),     S(221, 79),     S(176, 101),    S(209, 92),     S(194, 96),     //
    S(87, 149),     S(171, 145),    S(228, 119),    S(173, 125),    S(208, 124),    S(173, 136),    S(124, 154),    S(109, 155),    //
    S(44, 157),     S(173, 126),    S(210, 97),     S(182, 97),     S(184, 113),    S(135, 139),    S(141, 136),    S(80, 163),     //
    S(12, 135),     S(100, 133),    S(124, 111),    S(103, 118),    S(138, 104),    S(96, 136),     S(100, 132),    S(28, 155),     //
    S(-12, 69),     S(67, 75),      S(56, 89),      S(30, 90),      S(42, 101),     S(32, 121),     S(11, 114),     S(-6, 111),     //
    S(5, -5),       S(80, 12),      S(69, 29),      S(47, 30),      S(63, 32),      S(30, 66),      S(42, 40),      S(2, 48),       //
    S(-89, -2),     S(55, -44),     S(54, -17),     S(45, 6),       S(50, 9),       S(37, 21),      S(32, 3),       S(0, 16),       //
    S(-24, -18),    S(3, 1),        S(60, -12),     S(72, -16),     S(72, -5),      S(53, 12),      S(51, 6),       S(30, 13),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 119),     S(178, 73),     S(101, 167),    S(52, 229),     S(83, 200),     S(85, 177),     S(111, 96),     S(30, 174),     //
    S(71, 173),     S(86, 252),     S(54, 273),     S(-77, 346),    S(-38, 347),    S(4, 313),      S(55, 204),     S(39, 191),     //
    S(38, 210),     S(74, 240),     S(35, 308),     S(-7, 331),     S(2, 343),      S(55, 268),     S(77, 208),     S(86, 128),     //
    S(60, 95),      S(58, 183),     S(15, 243),     S(-2, 302),     S(7, 329),      S(43, 227),     S(87, 157),     S(62, 130),     //
    S(60, 63),      S(42, 122),     S(22, 180),     S(-0, 237),     S(11, 275),     S(25, 238),     S(49, 161),     S(69, 96),      //
    S(49, 1),       S(68, 29),      S(61, 107),     S(43, 123),     S(46, 152),     S(48, 188),     S(64, 139),     S(60, 91),      //
    S(24, -114),    S(48, -96),     S(56, -41),     S(77, 13),      S(65, 69),      S(66, 51),      S(36, 97),      S(55, 71),      //
    S(11, -97),     S(41, -242),    S(61, -213),    S(76, -106),    S(70, -10),     S(78, -56),     S(73, -29),     S(46, 3),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-51, -219),   S(330, 223),    S(237, 229),    S(90, 160),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(250, 4),      S(353, 169),    S(209, 226),    S(145, 138),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(195, 66),     S(250, 163),    S(150, 202),    S(96, 152),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(14, 35),      S(113, 127),    S(2, 180),      S(-14, 186),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-95, -15),    S(-11, 61),     S(-69, 116),    S(-145, 172),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-38, -51),    S(17, 14),      S(-69, 79),     S(-113, 122),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(26, -96),     S(30, -31),     S(-47, 20),     S(-113, 62),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-25, -181),   S(6, -94),      S(-83, -57),    S(-86, -72),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-85, 75);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -8), S(13, -15), S(12, -5), S(5, -7), S(1, 2),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -10), S(5, -25), S(3, -14), S(4, -4), S(4, 3),
};

inline const PParam KS_FLANK_ATTACK = S(3, -6);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -9);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -5);

inline const PParam KS_FLANK_OPENNESS   = S(-0, -57);
inline const PParam KS_BOARD_CLOSENESS  = S(1, -49);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, -7), S(1, -28), S(1, -17), S(11, -41), S(10, -44), S(-0, -18), S(2, -20), }},
  {{ S(3, 31), S(-24, -14), S(-16, -7), S(-4, -27), S(-3, -24), S(-15, -11), S(-23, -12), }},
  {{ S(1, 12), S(-11, -30), S(-6, -31), S(-0, -45), S(0, -44), S(-5, -31), S(-10, -29), }},
  {{ S(10, 26), S(-7, -31), S(4, -22), S(9, -31), S(7, -30), S(2, -19), S(-4, -36), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 20), S(-9, 2), S(-6, 22), S(1, 36), S(3, 23),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 19), S(-7, -30), S(-6, -16), S(-4, 5), S(-4, 4), S(-5, -21), S(-7, -40), }},
  {{ S(8, -18), S(2, -33), S(-7, -30), S(-4, -22), S(-5, -20), S(-6, -39), S(2, -36), }},
  {{ S(2, 1), S(-1, -24), S(-5, -22), S(-2, -15), S(-2, -17), S(-6, -24), S(-1, -31), }},
  {{ S(2, -4), S(-5, -22), S(-8, -31), S(-2, -23), S(-1, -22), S(-8, -31), S(-7, -35), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1165, 1082, -12, -81
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(133);
inline VParam WINNABLE_ASYM = V(119);
inline VParam WINNABLE_PAWN_ENDGAME = V(213);
inline VParam WINNABLE_BIAS = V(-617);

// Epoch duration: 4.31543s
// clang-format on
}  // namespace Clockwork
