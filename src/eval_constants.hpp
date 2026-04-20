#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(197, 382);
inline const PParam KNIGHT_MAT = S(908, 1019);
inline const PParam BISHOP_MAT = S(944, 1068);
inline const PParam ROOK_MAT   = S(1149, 1714);
inline const PParam QUEEN_MAT  = S(2685, 2702);
inline const PParam TEMPO_VAL  = S(62, 19);

inline const PParam BISHOP_PAIR_VAL   = S(51, 200);
inline const PParam ROOK_OPEN_VAL     = S(116, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 27);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);
inline const PParam RESTRICTED_SQUARES = S(-22, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -19);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(59, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(48, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(65, -43);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, -2), S(31, 27), S(61, 48), S(144, 140), S(381, 207), S(440, 529),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 33), S(47, 26), S(63, 50), S(122, 140), S(416, 81),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-108, -187), S(-110, -159), S(-83, -53), S(-26, 44), S(71, 178), S(262, 256),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(28, -37), S(21, 2), S(14, 33), S(1, 113), S(82, 203), S(256, 256),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -16), S(1, 24), S(-1, -11), S(1, -40), S(-4, -129), S(-252, -211),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(21, 182), S(-3, 155), S(2, 87), S(9, 53), S(16, 53), S(53, 49), S(46, 32),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-274, -35), S(-10, 35), S(-3, 90), S(39, 112), S(61, 131), S(72, 135), S(51, 133),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-111, -246), S(-47, -77), S(-15, 12), S(11, 43), S(43, 59), S(59, 89), S(81, 84), S(100, 95), S(145, 8),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-78, -230), S(-33, -67), S(19, -1), S(42, 44), S(65, 75), S(79, 98), S(85, 114), S(96, 121), S(99, 135), S(118, 115), S(122, 115), S(170, 57), S(169, 60), S(203, 6),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -115), S(16, 44), S(38, 71), S(54, 82), S(65, 95), S(69, 106), S(74, 117), S(81, 120), S(85, 131), S(92, 134), S(99, 136), S(102, 141), S(105, 139), S(119, 110), S(204, 5),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-128, -78), S(12, -22), S(38, 92), S(58, 196), S(74, 235), S(83, 276), S(89, 304), S(97, 312), S(101, 333), S(103, 348), S(109, 352), S(112, 360), S(118, 358), S(119, 363), S(123, 358), S(121, 358), S(120, 356), S(125, 344), S(132, 330), S(133, 323), S(128, 312), S(146, 272), S(120, 286), S(114, 226), S(86, 219), S(80, 182), S(20, 206), S(31, 155),
};

inline const PParam PAWN_THREAT_KNIGHT = S(215, 84);
inline const PParam PAWN_THREAT_BISHOP = S(208, 128);
inline const PParam PAWN_THREAT_ROOK   = S(198, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(184, -13);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(167, -24);

inline const PParam BISHOP_THREAT_KNIGHT = S(103, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(214, 123);
inline const PParam BISHOP_THREAT_QUEEN  = S(172, 80);

inline const PParam KNIGHT_ON_QUEEN  = S(29, -23);
inline const PParam BISHOP_ON_QUEEN  = S(38, 36);
inline const PParam ROOK_ON_QUEEN   = S(46, 8);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -30), S(-3, -3), S(-5, -12), S(-7, -23), S(-11, -32), S(-14, -40), S(-15, -52), S(-20, -54), S(-35, -50),
};

inline const PParam ROOK_LINEUP = S(15, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(228, 182),    S(68, 233),     S(194, 189),    S(174, 168),    S(220, 102),    S(113, 189),    S(56, 229),     S(196, 173),    //
    S(48, 21),      S(78, 36),      S(75, 16),      S(50, -33),     S(45, -63),     S(23, -17),     S(5, 32),       S(-28, 58),     //
    S(24, -16),     S(2, -8),       S(32, -46),     S(21, -70),     S(16, -83),     S(-7, -56),     S(-55, -10),    S(-52, 12),     //
    S(-9, -63),     S(-27, -37),    S(1, -60),      S(-9, -68),     S(-32, -68),    S(-39, -51),    S(-96, -15),    S(-86, -23),    //
    S(-6, -93),     S(27, -92),     S(10, -44),     S(-2, -47),     S(-32, -54),    S(-48, -49),    S(-83, -33),    S(-82, -41),    //
    S(12, -89),     S(93, -91),     S(69, -49),     S(29, -16),     S(0, -33),      S(-21, -44),    S(-52, -26),    S(-67, -25),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-331, -309),  S(-270, 21),    S(-252, -85),   S(-4, 18),      S(-81, 22),     S(-227, 31),    S(-397, 90),    S(-405, -204),  //
    S(-47, -6),     S(-20, 18),     S(98, -18),     S(101, 3),      S(96, 13),      S(21, 30),      S(-43, 32),     S(-68, 14),     //
    S(22, -10),     S(56, -18),     S(82, 46),      S(96, 47),      S(60, 75),      S(13, 76),      S(5, 19),       S(-41, 13),     //
    S(90, 9),       S(102, 29),     S(106, 62),     S(107, 92),     S(112, 95),     S(67, 83),      S(45, 49),      S(33, 22),      //
    S(71, 8),       S(113, -10),    S(92, 58),      S(87, 75),      S(65, 80),      S(70, 68),      S(58, 16),      S(13, 28),      //
    S(9, -24),      S(34, -1),      S(32, 41),      S(46, 60),      S(40, 59),      S(10, 43),      S(4, 7),        S(-35, -26),    //
    S(25, -17),     S(34, -16),     S(9, -1),       S(18, 20),      S(16, 17),      S(-9, -29),     S(-30, -8),     S(-45, -91),    //
    S(-47, -72),    S(3, -15),      S(23, -40),     S(38, -35),     S(21, -16),     S(-14, -41),    S(-25, -24),    S(-66, -116),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-156, 79),    S(-160, 83),    S(-441, 141),   S(-291, 86),    S(-286, 88),    S(-307, 83),    S(-213, 83),    S(-131, 63),    //
    S(-49, 5),      S(-86, 82),     S(-46, 28),     S(-102, 56),    S(-81, 49),     S(-62, 45),     S(-21, 35),     S(-55, 13),     //
    S(25, 20),      S(15, 42),      S(30, 47),      S(17, 51),      S(-4, 48),      S(3, 49),       S(7, 39),       S(8, 14),       //
    S(11, 2),       S(43, 19),      S(50, 46),      S(52, 84),      S(85, 68),      S(27, 41),      S(37, 3),       S(-8, 6),       //
    S(44, -44),     S(50, -2),      S(65, 29),      S(71, 59),      S(52, 70),      S(49, 47),      S(14, 17),      S(10, -21),     //
    S(63, -30),     S(80, -11),     S(90, 23),      S(51, 48),      S(49, 28),      S(47, 39),      S(59, 13),      S(10, -0),      //
    S(25, -58),     S(105, -37),    S(66, -16),     S(48, -0),      S(29, 5),       S(37, -22),     S(35, -29),     S(39, -40),     //
    S(48, -57),     S(29, -26),     S(35, -3),      S(52, -26),     S(38, -17),     S(41, 19),      S(43, -5),      S(37, -32),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(198, 86),     S(234, 94),     S(188, 109),    S(183, 84),     S(224, 73),     S(179, 94),     S(202, 97),     S(183, 107),    //
    S(85, 157),     S(167, 152),    S(227, 118),    S(167, 131),    S(205, 123),    S(173, 132),    S(118, 160),    S(102, 165),    //
    S(45, 158),     S(167, 130),    S(212, 90),     S(178, 94),     S(174, 115),    S(129, 139),    S(134, 140),    S(71, 172),     //
    S(14, 133),     S(101, 127),    S(129, 101),    S(102, 114),    S(134, 101),    S(88, 138),     S(92, 135),     S(21, 161),     //
    S(-8, 66),      S(70, 69),      S(60, 82),      S(29, 88),      S(37, 100),     S(28, 120),     S(2, 120),      S(-11, 114),    //
    S(7, -7),       S(79, 13),      S(70, 25),      S(46, 29),      S(57, 34),      S(25, 68),      S(33, 47),      S(-5, 55),      //
    S(-84, -5),     S(54, -41),     S(58, -19),     S(48, 3),       S(51, 8),       S(37, 20),      S(29, 6),       S(-3, 21),      //
    S(-21, -20),    S(5, -2),       S(63, -14),     S(74, -18),     S(72, -6),      S(53, 11),      S(49, 6),       S(30, 12),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(100, 106),    S(199, 40),     S(129, 131),    S(66, 222),     S(107, 175),    S(101, 158),    S(128, 71),     S(44, 146),     //
    S(83, 156),     S(110, 229),    S(86, 247),     S(-35, 313),    S(14, 295),     S(48, 262),     S(90, 156),     S(47, 173),     //
    S(48, 197),     S(83, 243),     S(55, 298),     S(31, 294),     S(38, 303),     S(85, 230),     S(98, 172),     S(95, 102),     //
    S(55, 109),     S(70, 179),     S(21, 248),     S(18, 295),     S(33, 307),     S(59, 205),     S(96, 140),     S(57, 127),     //
    S(55, 78),      S(44, 133),     S(25, 190),     S(-1, 253),     S(11, 279),     S(30, 228),     S(51, 147),     S(64, 86),      //
    S(41, 15),      S(61, 54),      S(56, 127),     S(38, 137),     S(40, 158),     S(40, 192),     S(59, 132),     S(48, 89),      //
    S(12, -91),     S(28, -35),     S(36, 7),       S(64, 31),      S(56, 75),      S(55, 56),      S(24, 97),      S(45, 63),      //
    S(-3, -86),     S(20, -199),    S(46, -191),    S(61, -94),     S(55, -2),      S(60, -43),     S(57, -21),     S(33, 0),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-67, -202),   S(300, 248),    S(202, 228),    S(68, 122),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(233, 27),     S(320, 210),    S(188, 222),    S(132, 102),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(180, 87),     S(238, 170),    S(155, 187),    S(105, 119),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(13, 36),      S(136, 101),    S(18, 154),     S(-11, 166),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-87, -16),    S(1, 51),       S(-58, 105),    S(-144, 167),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -47),    S(32, 7),       S(-63, 78),     S(-113, 125),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -87),     S(30, -25),     S(-45, 24),     S(-109, 72),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -173),   S(1, -87),      S(-83, -44),    S(-77, -56),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-79, -556);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -26), S(14, -26), S(14, -7), S(5, -10), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -28), S(4, -18), S(4, -2), S(4, 8),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 45), S(-3, 56), S(-1, -14), S(10, -24), S(9, -20), S(-2, -5), S(-2, 56), }},
  {{ S(-1, 164), S(-20, -250), S(-20, 2), S(-8, 49), S(-7, 64), S(-19, -7), S(-19, -233), }},
  {{ S(-3, 145), S(-9, -238), S(-10, 129), S(-4, 108), S(-3, 107), S(-10, 133), S(-9, -214), }},
  {{ S(8, 126), S(-10, 80), S(1, 92), S(8, 71), S(6, 74), S(-1, 91), S(-7, 80), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 62), S(-10, 52), S(-10, 77), S(-1, 83), S(4, 30),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 116), S(-8, 37), S(-8, 36), S(-5, 36), S(-6, 31), S(-7, 36), S(-8, 47), }},
  {{ S(10, 6), S(1, -32), S(-8, -19), S(-3, -53), S(-4, -51), S(-6, -22), S(1, -24), }},
  {{ S(1, 60), S(-3, 36), S(-6, 39), S(-3, 36), S(-2, 19), S(-7, 35), S(-3, 24), }},
  {{ S(-0, 56), S(-6, 35), S(-10, 37), S(-4, 45), S(-3, 46), S(-9, 33), S(-8, 36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1075, 249, -15, 90
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(126);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-652);

// Epoch duration: 7.25795s
// clang-format on
}  // namespace Clockwork
