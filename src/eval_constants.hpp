#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(171, 324);
inline const PParam KNIGHT_MAT = S(751, 835);
inline const PParam BISHOP_MAT = S(819, 923);
inline const PParam ROOK_MAT   = S(1072, 1529);
inline const PParam QUEEN_MAT  = S(2582, 1716);
inline const PParam TEMPO_VAL  = S(60, 21);

inline const PParam BISHOP_PAIR_VAL   = S(54, 197);
inline const PParam ROOK_OPEN_VAL     = S(117, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 29);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);
inline const PParam RESTRICTED_SQUARES = S(-25, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-11, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 49);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 37);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(48, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 43);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -1), S(30, 26), S(57, 50), S(141, 145), S(371, 209), S(476, 663),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 33), S(44, 28), S(59, 53), S(121, 139), S(409, 82),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-87, -103), S(-84, -82), S(-51, 14), S(11, 105), S(102, 244), S(372, 440),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -34), S(21, 3), S(13, 36), S(0, 113), S(84, 196), S(252, 248),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(16, -22), S(1, 25), S(-2, -9), S(1, -41), S(-9, -122), S(-259, -195),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(3, 144), S(-22, 121), S(-13, 50), S(-5, 13), S(4, 12), S(40, 9), S(31, -5),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-315, -38), S(-39, 19), S(-25, 67), S(27, 73), S(50, 89), S(63, 90), S(41, 91),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-5, -91), S(62, 76), S(94, 163), S(120, 196), S(152, 211), S(167, 240), S(189, 238), S(208, 249), S(245, 178),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-2, -124), S(41, 40), S(92, 107), S(116, 151), S(140, 183), S(154, 205), S(162, 222), S(173, 228), S(177, 242), S(196, 223), S(199, 224), S(245, 168), S(244, 171), S(266, 129),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(135, -24), S(51, 136), S(73, 163), S(88, 173), S(99, 187), S(103, 197), S(108, 208), S(115, 211), S(120, 223), S(128, 225), S(136, 226), S(139, 231), S(143, 230), S(154, 203), S(236, 102),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-123, -296), S(7, -201), S(32, -92), S(51, 13), S(67, 54), S(75, 93), S(82, 120), S(89, 129), S(93, 148), S(96, 161), S(102, 164), S(104, 170), S(110, 165), S(109, 170), S(112, 168), S(107, 168), S(104, 169), S(107, 160), S(111, 147), S(112, 141), S(112, 122), S(127, 86), S(105, 96), S(100, 36), S(71, 35), S(66, -5), S(-0, 26), S(11, -25),
};

inline const PParam PAWN_THREAT_KNIGHT = S(209, 93);
inline const PParam PAWN_THREAT_BISHOP = S(205, 133);
inline const PParam PAWN_THREAT_ROOK   = S(196, 124);
inline const PParam PAWN_THREAT_QUEEN  = S(182, -19);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -22);

inline const PParam BISHOP_THREAT_KNIGHT = S(103, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(210, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 85);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -30), S(-3, -2), S(-5, -12), S(-7, -22), S(-11, -32), S(-14, -40), S(-15, -52), S(-20, -53), S(-36, -49),
};

inline const PParam ROOK_LINEUP = S(14, 68);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(190, 98),     S(-5, 189),     S(121, 167),    S(135, 80),     S(172, 28),     S(57, 129),     S(-7, 174),     S(155, 93),     //
    S(56, 102),     S(78, 124),     S(100, 59),     S(75, 21),      S(67, -3),      S(35, 58),      S(17, 108),     S(-13, 129),    //
    S(45, 44),      S(24, 53),      S(57, 4),       S(40, -8),      S(33, -19),     S(10, 13),      S(-38, 61),     S(-37, 83),     //
    S(15, -8),      S(-7, 23),      S(22, -8),      S(9, -9),       S(-14, -6),     S(-21, 15),     S(-78, 53),     S(-69, 46),     //
    S(14, -31),     S(40, -25),     S(27, 11),      S(15, 12),      S(-15, 9),      S(-32, 17),     S(-71, 38),     S(-68, 28),     //
    S(34, -33),     S(109, -18),    S(96, 28),      S(47, 41),      S(17, 29),      S(-5, 22),      S(-39, 43),     S(-48, 43),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-300, -260),  S(-241, 76),    S(-128, -147),  S(9, 87),       S(-61, 87),     S(-181, 66),    S(-353, 132),   S(-370, -160),  //
    S(-10, 38),     S(14, 68),      S(125, 43),     S(128, 71),     S(126, 75),     S(54, 86),      S(-7, 79),      S(-29, 57),     //
    S(55, 38),      S(91, 32),      S(117, 103),    S(128, 108),    S(99, 130),     S(53, 125),     S(45, 64),      S(-2, 55),      //
    S(119, 64),     S(133, 85),     S(139, 119),    S(140, 149),    S(146, 150),    S(104, 135),    S(82, 97),      S(66, 73),      //
    S(100, 63),     S(143, 43),     S(125, 109),    S(120, 127),    S(99, 132),     S(105, 117),    S(92, 67),      S(48, 76),      //
    S(43, 25),      S(66, 47),      S(66, 85),      S(80, 107),     S(74, 106),     S(45, 87),      S(39, 54),      S(0, 21),       //
    S(58, 29),      S(70, 27),      S(45, 42),      S(53, 65),      S(49, 63),      S(24, 21),      S(2, 44),       S(-10, -41),    //
    S(-10, -32),    S(41, 27),      S(56, 6),       S(72, 11),      S(56, 31),      S(20, 6),       S(10, 22),      S(-31, -70),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-123, 133),   S(-132, 144),   S(-409, 196),   S(-258, 141),   S(-248, 137),   S(-270, 131),   S(-170, 127),   S(-92, 109),    //
    S(-12, 57),     S(-47, 128),    S(-16, 89),     S(-68, 118),    S(-46, 105),    S(-23, 94),     S(16, 83),      S(-9, 49),      //
    S(55, 75),      S(52, 90),      S(61, 107),     S(44, 113),     S(29, 106),     S(38, 102),     S(52, 76),      S(45, 59),      //
    S(41, 57),      S(77, 73),      S(86, 99),      S(86, 139),     S(119, 122),    S(66, 90),      S(71, 57),      S(31, 50),      //
    S(79, 8),       S(79, 53),      S(100, 82),     S(105, 111),    S(87, 121),     S(81, 102),     S(49, 69),      S(45, 29),      //
    S(94, 26),      S(110, 43),     S(122, 74),     S(87, 99),      S(80, 83),      S(81, 90),      S(91, 67),      S(44, 53),      //
    S(56, -6),      S(139, 11),     S(103, 31),     S(82, 52),      S(65, 55),      S(71, 30),      S(69, 23),      S(71, 14),      //
    S(82, -4),      S(68, 22),      S(71, 45),      S(87, 23),      S(71, 34),      S(77, 68),      S(77, 48),      S(73, 19),      //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(180, 102),    S(212, 115),    S(166, 129),    S(170, 99),     S(202, 100),    S(168, 111),    S(186, 118),    S(170, 124),    //
    S(69, 170),     S(154, 166),    S(216, 132),    S(153, 149),    S(192, 141),    S(160, 150),    S(107, 175),    S(91, 176),     //
    S(30, 172),     S(155, 146),    S(198, 109),    S(170, 108),    S(170, 128),    S(121, 155),    S(126, 154),    S(63, 185),     //
    S(0, 146),      S(88, 144),     S(115, 118),    S(90, 129),     S(124, 118),    S(81, 151),     S(85, 149),     S(13, 173),     //
    S(-22, 80),     S(55, 89),      S(44, 102),     S(18, 103),     S(31, 111),     S(19, 135),     S(-3, 130),     S(-20, 127),    //
    S(-5, 1),       S(69, 22),      S(59, 38),      S(36, 39),      S(49, 44),      S(16, 80),      S(28, 54),      S(-11, 62),     //
    S(-99, 6),      S(43, -32),     S(42, -8),      S(33, 16),      S(38, 21),      S(23, 34),      S(18, 18),      S(-12, 29),     //
    S(-36, -8),     S(-9, 12),      S(48, -1),      S(59, -5),      S(60, 6),       S(40, 24),      S(38, 18),      S(18, 23),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(68, 43),      S(161, -14),    S(89, 70),      S(45, 128),     S(75, 98),      S(75, 78),      S(98, 4),       S(15, 85),      //
    S(56, 84),      S(70, 167),     S(42, 179),     S(-85, 244),    S(-47, 247),    S(-5, 214),     S(43, 109),     S(23, 104),     //
    S(21, 123),     S(54, 158),     S(19, 219),     S(-17, 229),    S(-6, 239),     S(44, 170),     S(62, 117),     S(68, 43),      //
    S(45, 4),       S(42, 95),      S(2, 146),      S(-14, 206),    S(-7, 236),     S(30, 134),     S(72, 68),      S(45, 46),      //
    S(47, -28),     S(29, 33),      S(8, 88),       S(-13, 144),    S(-4, 186),     S(11, 147),     S(33, 73),      S(53, 9),       //
    S(33, -84),     S(52, -54),     S(48, 19),      S(28, 36),      S(30, 65),      S(32, 103),     S(47, 57),      S(40, 13),      //
    S(5, -193),     S(33, -181),    S(40, -128),    S(61, -71),     S(49, -17),     S(50, -33),     S(18, 18),      S(36, -6),      //
    S(-7, -175),    S(21, -313),    S(44, -296),    S(59, -188),    S(53, -93),     S(60, -139),    S(56, -111),    S(30, -79),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(9, -165),     S(326, 267),    S(213, 270),    S(85, 159),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(246, 48),     S(333, 215),    S(191, 252),    S(141, 131),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(179, 98),     S(236, 181),    S(152, 198),    S(105, 124),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, 40),      S(124, 106),    S(17, 148),     S(8, 140),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-79, -42),    S(14, 20),      S(-32, 64),     S(-105, 113),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -87),    S(46, -32),     S(-33, 28),     S(-81, 70),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(37, -126),    S(45, -69),     S(-28, -21),    S(-94, 19),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -202),   S(16, -120),    S(-71, -82),    S(-73, -102),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-82, -479);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -19), S(13, -16), S(12, -3), S(5, -6), S(1, 36),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -19), S(5, -24), S(3, -10), S(3, -2), S(4, 15),
};

inline const PParam KS_FLANK_ATTACK = S(2, -4);
inline const PParam KS_FLANK_DEFENSE = S(-4, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -10);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -4);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, 28), S(-2, 25), S(-2, 25), S(8, -1), S(7, -6), S(-3, 25), S(-1, 26), }},
  {{ S(2, 70), S(-25, 46), S(-17, 43), S(-5, 17), S(-5, 20), S(-17, 42), S(-24, 50), }},
  {{ S(3, 74), S(-10, 59), S(-4, 45), S(2, 27), S(2, 24), S(-4, 44), S(-8, 61), }},
  {{ S(8, 65), S(-9, 28), S(1, 35), S(6, 22), S(5, 19), S(-0, 30), S(-6, 26), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, -48), S(-10, 55), S(-6, 50), S(1, 72), S(4, 49),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 82), S(-6, 63), S(-5, 59), S(-5, 61), S(-5, 59), S(-5, 56), S(-7, 58), }},
  {{ S(8, 44), S(2, 26), S(-6, 27), S(-5, 23), S(-5, 23), S(-6, 19), S(1, 26), }},
  {{ S(2, 60), S(-1, 40), S(-5, 47), S(-3, 47), S(-3, 39), S(-6, 42), S(-1, 42), }},
  {{ S(1, 52), S(-5, 45), S(-8, 38), S(-3, 42), S(-2, 40), S(-7, 37), S(-7, 36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1219, 1691, -8, 105
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(136);
inline VParam WINNABLE_ASYM = V(122);
inline VParam WINNABLE_PAWN_ENDGAME = V(227);
inline VParam WINNABLE_BIAS = V(-639);

// Epoch duration: 5.12126s
// clang-format on
}  // namespace Clockwork
