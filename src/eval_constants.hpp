#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(196, 383);
inline const PParam KNIGHT_MAT = S(909, 1020);
inline const PParam BISHOP_MAT = S(950, 1068);
inline const PParam ROOK_MAT   = S(1149, 1716);
inline const PParam QUEEN_MAT  = S(2679, 2699);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 14);
inline const PParam BISHOP_PAIR_VAL   = S(54, 198);
inline const PParam ROOK_OPEN_VAL     = S(118, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 26);
inline const PParam MINOR_BEHIND_PAWN = S(12, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(47, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 44);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -3), S(32, 27), S(61, 48), S(144, 141), S(382, 208), S(438, 527),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 33), S(46, 27), S(63, 50), S(121, 141), S(416, 80),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-108, -184), S(-108, -157), S(-81, -51), S(-23, 45), S(72, 181), S(261, 258),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -37), S(21, 2), S(15, 32), S(1, 111), S(82, 202), S(256, 255),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -17), S(-0, 24), S(-3, -9), S(-1, -39), S(-6, -128), S(-251, -212),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 180), S(-5, 153), S(1, 85), S(8, 51), S(15, 51), S(52, 47), S(45, 29),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-273, -36), S(-10, 35), S(-3, 90), S(39, 113), S(60, 131), S(71, 136), S(51, 134),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-112, -245), S(-47, -75), S(-15, 13), S(11, 43), S(43, 59), S(60, 88), S(83, 83), S(103, 94), S(148, 6),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-76, -235), S(-29, -75), S(25, -10), S(48, 36), S(70, 68), S(83, 92), S(88, 110), S(98, 120), S(99, 136), S(117, 117), S(118, 121), S(164, 65), S(159, 72), S(191, 20),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -114), S(15, 45), S(37, 73), S(54, 83), S(64, 96), S(69, 107), S(74, 118), S(81, 121), S(86, 131), S(94, 134), S(102, 135), S(106, 140), S(110, 138), S(123, 109), S(208, 4),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-126, -82), S(14, -22), S(40, 88), S(61, 193), S(76, 232), S(85, 272), S(91, 302), S(99, 311), S(102, 332), S(104, 348), S(110, 352), S(112, 362), S(117, 360), S(118, 365), S(119, 363), S(116, 363), S(112, 365), S(116, 353), S(121, 341), S(123, 333), S(120, 319), S(138, 278), S(114, 291), S(111, 229), S(81, 223), S(75, 188), S(17, 211), S(27, 161),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 85);
inline const PParam PAWN_THREAT_BISHOP = S(197, 139);
inline const PParam PAWN_THREAT_ROOK   = S(197, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -9);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -18);

inline const PParam BISHOP_THREAT_KNIGHT = S(101, 60);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(172, 92);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(13, -32), S(-1, -5), S(-4, -13), S(-7, -23), S(-11, -32), S(-15, -39), S(-17, -50), S(-23, -51), S(-39, -46),
};

inline const PParam ROOK_LINEUP = S(14, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(229, 181),    S(65, 237),     S(194, 193),    S(174, 171),    S(220, 104),    S(113, 191),    S(55, 229),     S(196, 174),    //
    S(48, 19),      S(75, 37),      S(73, 16),      S(47, -33),     S(42, -63),     S(21, -18),     S(3, 32),       S(-28, 58),     //
    S(23, -16),     S(-2, -7),      S(29, -45),     S(18, -69),     S(13, -82),     S(-10, -55),    S(-56, -11),    S(-53, 12),     //
    S(-10, -63),    S(-31, -35),    S(-3, -59),     S(-14, -66),    S(-37, -66),    S(-42, -51),    S(-100, -14),   S(-88, -23),    //
    S(-10, -91),    S(24, -91),     S(6, -42),      S(-6, -46),     S(-35, -53),    S(-53, -48),    S(-86, -32),    S(-86, -39),    //
    S(11, -89),     S(90, -90),     S(67, -48),     S(27, -16),     S(-2, -32),     S(-23, -44),    S(-56, -25),    S(-68, -25),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-332, -308),  S(-269, 20),    S(-251, -88),   S(-4, 17),      S(-77, 18),     S(-230, 35),    S(-397, 91),    S(-407, -202),  //
    S(-45, -9),     S(-18, 18),     S(100, -19),    S(107, 2),      S(102, 11),     S(24, 29),      S(-42, 34),     S(-66, 13),     //
    S(23, -11),     S(57, -17),     S(87, 44),      S(103, 44),     S(65, 75),      S(18, 75),      S(8, 17),       S(-40, 12),     //
    S(91, 9),       S(103, 30),     S(108, 62),     S(113, 90),     S(118, 93),     S(72, 81),      S(46, 50),      S(34, 21),      //
    S(71, 9),       S(114, -10),    S(95, 57),      S(90, 73),      S(70, 78),      S(73, 67),      S(60, 15),      S(14, 27),      //
    S(7, -22),      S(33, 1),       S(30, 43),      S(46, 61),      S(40, 60),      S(9, 44),       S(4, 8),        S(-36, -25),    //
    S(24, -17),     S(33, -16),     S(8, 0),        S(16, 21),      S(14, 19),      S(-11, -27),    S(-31, -8),     S(-45, -93),    //
    S(-49, -73),    S(-0, -12),     S(22, -41),     S(38, -35),     S(20, -15),     S(-15, -41),    S(-28, -22),    S(-69, -115),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-161, 84),    S(-161, 87),    S(-442, 142),   S(-288, 85),    S(-284, 87),    S(-309, 84),    S(-214, 86),    S(-137, 69),    //
    S(-53, 11),     S(-83, 81),     S(-41, 25),     S(-96, 53),     S(-76, 46),     S(-57, 43),     S(-20, 35),     S(-60, 19),     //
    S(22, 26),      S(17, 41),      S(35, 44),      S(24, 45),      S(2, 45),       S(9, 43),       S(10, 37),      S(5, 17),       //
    S(9, 6),        S(45, 19),      S(59, 39),      S(66, 73),      S(98, 58),      S(37, 33),      S(37, 4),       S(-10, 9),      //
    S(41, -40),     S(51, -3),      S(73, 23),      S(87, 46),      S(69, 56),      S(58, 40),      S(16, 16),      S(7, -17),      //
    S(60, -26),     S(81, -11),     S(96, 17),      S(62, 39),      S(58, 21),      S(57, 31),      S(62, 12),      S(8, 3),        //
    S(27, -58),     S(109, -41),    S(71, -20),     S(47, 2),       S(31, 5),       S(43, -26),     S(41, -33),     S(40, -41),     //
    S(50, -58),     S(32, -28),     S(27, 6),       S(46, -19),     S(31, -9),      S(36, 26),      S(46, -5),      S(41, -34),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(195, 88),     S(231, 97),     S(187, 111),    S(183, 83),     S(221, 76),     S(179, 94),     S(202, 98),     S(182, 107),    //
    S(84, 159),     S(170, 151),    S(230, 117),    S(170, 130),    S(208, 122),    S(176, 131),    S(120, 160),    S(102, 165),    //
    S(48, 157),     S(171, 130),    S(218, 89),     S(185, 92),     S(182, 113),    S(136, 137),    S(138, 139),    S(75, 172),     //
    S(17, 132),     S(108, 125),    S(136, 99),     S(108, 113),    S(142, 99),     S(95, 136),     S(99, 133),     S(25, 161),     //
    S(-6, 64),      S(74, 68),      S(65, 81),      S(34, 87),      S(42, 99),      S(35, 118),     S(8, 117),      S(-8, 113),     //
    S(9, -7),       S(84, 12),      S(74, 24),      S(51, 28),      S(62, 34),      S(30, 67),      S(39, 45),      S(-2, 55),      //
    S(-86, -2),     S(55, -38),     S(60, -18),     S(48, 5),       S(51, 9),       S(38, 20),      S(30, 7),       S(-3, 22),      //
    S(-23, -18),    S(4, 0),        S(63, -13),     S(74, -17),     S(73, -5),      S(53, 12),      S(49, 8),       S(28, 14),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(91, 109),     S(188, 43),     S(112, 142),    S(53, 225),     S(91, 182),     S(85, 166),     S(112, 79),     S(36, 148),     //
    S(70, 168),     S(84, 248),     S(54, 269),     S(-73, 337),    S(-30, 328),    S(13, 286),     S(60, 178),     S(36, 180),     //
    S(39, 202),     S(64, 257),     S(33, 310),     S(0, 315),      S(8, 322),      S(58, 249),     S(76, 188),     S(84, 108),     //
    S(60, 99),      S(59, 183),     S(11, 250),     S(-5, 312),     S(9, 325),      S(45, 213),     S(86, 145),     S(59, 120),     //
    S(61, 66),      S(42, 133),     S(23, 186),     S(-3, 250),     S(11, 275),     S(27, 228),     S(52, 141),     S(69, 78),      //
    S(52, 2),       S(67, 44),      S(62, 118),     S(44, 126),     S(46, 149),     S(48, 182),     S(66, 123),     S(60, 74),      //
    S(26, -110),    S(41, -56),     S(48, -10),     S(76, 14),      S(67, 62),      S(67, 42),      S(37, 83),      S(58, 49),      //
    S(11, -101),    S(34, -216),    S(62, -214),    S(77, -117),    S(71, -24),     S(77, -65),     S(72, -37),     S(47, -11),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-63, -202),   S(302, 245),    S(204, 226),    S(72, 120),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(235, 25),     S(320, 207),    S(187, 221),    S(133, 100),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(179, 87),     S(236, 170),    S(155, 186),    S(105, 118),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(12, 36),      S(134, 101),    S(17, 154),     S(-11, 165),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-89, -15),    S(-1, 51),      S(-58, 105),    S(-145, 167),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -46),    S(29, 9),       S(-64, 78),     S(-114, 125),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -86),     S(29, -24),     S(-45, 24),     S(-109, 72),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -173),   S(1, -86),      S(-81, -45),    S(-75, -57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -563);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -26), S(14, -27), S(14, -7), S(5, -10), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -28), S(4, -18), S(4, -2), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 44), S(-3, 56), S(-1, -14), S(10, -26), S(9, -20), S(-2, -6), S(-2, 57), }},
  {{ S(-1, 168), S(-19, -253), S(-20, 3), S(-8, 50), S(-7, 66), S(-19, -7), S(-18, -238), }},
  {{ S(-2, 146), S(-8, -241), S(-9, 130), S(-3, 109), S(-2, 108), S(-9, 135), S(-7, -215), }},
  {{ S(8, 126), S(-10, 81), S(2, 92), S(8, 70), S(6, 73), S(-0, 92), S(-6, 80), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 60), S(-11, 52), S(-10, 78), S(-2, 84), S(3, 31),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 117), S(-8, 36), S(-9, 37), S(-6, 36), S(-6, 30), S(-8, 35), S(-9, 47), }},
  {{ S(9, 4), S(1, -35), S(-8, -23), S(-3, -55), S(-4, -57), S(-7, -25), S(1, -27), }},
  {{ S(0, 60), S(-4, 35), S(-7, 38), S(-4, 36), S(-3, 19), S(-7, 35), S(-3, 24), }},
  {{ S(-1, 56), S(-7, 35), S(-11, 37), S(-5, 45), S(-4, 46), S(-10, 32), S(-8, 36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1074, 248, -14, 94
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-653);

// Epoch duration: 6.07503s
// clang-format on
}  // namespace Clockwork
