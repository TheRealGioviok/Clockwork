#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(198, 386);
inline const PParam KNIGHT_MAT = S(909, 1019);
inline const PParam BISHOP_MAT = S(950, 1067);
inline const PParam ROOK_MAT   = S(1147, 1716);
inline const PParam QUEEN_MAT  = S(2678, 2703);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 13);
inline const PParam BISHOP_PAIR_VAL   = S(53, 198);
inline const PParam ROOK_OPEN_VAL     = S(119, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 29);
inline const PParam MINOR_BEHIND_PAWN = S(12, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -5);

inline const PParam DOUBLED_PAWN_VAL = S(-16, -86);
inline const PParam DDOUBLED_PAWN_VAL = S(-12, -43);
inline const PParam DOUBLED_PAWN_DEFENDED_VAL = S(4, 32);
inline const PParam ISOLATED_PAWN_VAL = S(-17, -15);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 53);
inline const PParam OUTPOST_BISHOP_VAL    = S(58, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(47, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 44);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -6), S(31, 25), S(61, 46), S(143, 140), S(380, 210), S(439, 529),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 31), S(46, 24), S(62, 48), S(121, 141), S(416, 82),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-108, -187), S(-108, -160), S(-79, -54), S(-21, 43), S(74, 179), S(262, 258),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -37), S(21, 3), S(14, 32), S(-0, 112), S(82, 201), S(255, 256),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -16), S(-1, 25), S(-4, -9), S(-1, -39), S(-6, -127), S(-250, -210),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 181), S(-4, 155), S(1, 87), S(8, 52), S(14, 52), S(51, 48), S(45, 30),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-274, -40), S(-12, 31), S(-5, 86), S(37, 109), S(58, 127), S(69, 132), S(48, 130),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-112, -245), S(-47, -75), S(-16, 13), S(11, 44), S(43, 60), S(60, 89), S(83, 84), S(103, 95), S(148, 7),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-75, -235), S(-28, -73), S(25, -8), S(48, 37), S(71, 69), S(83, 93), S(88, 111), S(97, 120), S(99, 136), S(116, 118), S(118, 121), S(164, 64), S(159, 72), S(190, 20),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(101, -112), S(16, 46), S(38, 73), S(55, 83), S(65, 96), S(70, 107), S(75, 118), S(82, 121), S(87, 131), S(95, 134), S(103, 135), S(107, 141), S(111, 138), S(124, 110), S(208, 4),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-126, -84), S(14, -26), S(39, 86), S(60, 191), S(76, 230), S(84, 270), S(90, 300), S(98, 309), S(102, 330), S(104, 346), S(109, 350), S(112, 360), S(117, 359), S(117, 364), S(119, 361), S(116, 361), S(112, 362), S(116, 351), S(120, 340), S(122, 332), S(118, 318), S(136, 277), S(113, 289), S(109, 228), S(79, 223), S(72, 188), S(15, 210), S(24, 163),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 85);
inline const PParam PAWN_THREAT_BISHOP = S(197, 138);
inline const PParam PAWN_THREAT_ROOK   = S(198, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(181, -12);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -16);

inline const PParam BISHOP_THREAT_KNIGHT = S(101, 60);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(172, 92);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(13, -31), S(-1, -5), S(-3, -14), S(-7, -23), S(-12, -32), S(-15, -39), S(-17, -50), S(-23, -51), S(-38, -45),
};

inline const PParam ROOK_LINEUP = S(14, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(228, 181),    S(67, 236),     S(196, 191),    S(175, 170),    S(221, 102),    S(113, 190),    S(56, 229),     S(195, 173),    //
    S(48, 20),      S(77, 39),      S(75, 18),      S(48, -30),     S(43, -60),     S(21, -15),     S(4, 34),       S(-28, 58),     //
    S(23, -15),     S(2, -3),       S(31, -41),     S(19, -66),     S(14, -79),     S(-9, -53),     S(-54, -7),     S(-52, 13),     //
    S(-9, -62),     S(-28, -30),    S(1, -54),      S(-13, -64),    S(-36, -64),    S(-41, -47),    S(-98, -9),     S(-87, -21),    //
    S(-9, -90),     S(26, -86),     S(8, -39),      S(-5, -43),     S(-34, -50),    S(-52, -45),    S(-84, -28),    S(-85, -37),    //
    S(11, -87),     S(91, -85),     S(69, -44),     S(27, -13),     S(-2, -29),     S(-23, -40),    S(-55, -20),    S(-68, -23),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-333, -309),  S(-269, 20),    S(-253, -87),   S(-2, 15),      S(-78, 19),     S(-230, 34),    S(-397, 90),    S(-408, -203),  //
    S(-46, -8),     S(-19, 20),     S(101, -20),    S(107, 0),      S(100, 12),     S(23, 29),      S(-43, 35),     S(-67, 14),     //
    S(23, -11),     S(57, -18),     S(85, 45),      S(102, 43),     S(65, 74),      S(17, 75),      S(7, 18),       S(-40, 13),     //
    S(90, 10),      S(102, 30),     S(108, 62),     S(112, 89),     S(117, 94),     S(72, 80),      S(46, 50),      S(33, 22),      //
    S(70, 10),      S(113, -9),     S(94, 57),      S(90, 73),      S(69, 78),      S(72, 68),      S(60, 16),      S(14, 27),      //
    S(6, -22),      S(32, 1),       S(30, 43),      S(46, 61),      S(39, 60),      S(8, 45),       S(3, 8),        S(-37, -24),    //
    S(25, -18),     S(33, -16),     S(8, 0),        S(16, 21),      S(13, 19),      S(-11, -27),    S(-30, -8),     S(-44, -93),    //
    S(-49, -72),    S(-0, -11),     S(22, -40),     S(37, -34),     S(20, -14),     S(-15, -40),    S(-28, -21),    S(-69, -113),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-162, 85),    S(-163, 88),    S(-442, 141),   S(-289, 85),    S(-284, 86),    S(-311, 85),    S(-213, 85),    S(-138, 69),    //
    S(-55, 12),     S(-83, 80),     S(-41, 25),     S(-95, 51),     S(-76, 46),     S(-57, 42),     S(-20, 36),     S(-61, 20),     //
    S(21, 26),      S(17, 41),      S(35, 44),      S(23, 46),      S(0, 46),       S(9, 43),       S(9, 38),       S(4, 17),       //
    S(9, 5),        S(44, 20),      S(58, 40),      S(65, 73),      S(97, 59),      S(36, 35),      S(36, 5),       S(-10, 9),      //
    S(41, -41),     S(51, -3),      S(73, 23),      S(87, 46),      S(68, 57),      S(58, 41),      S(16, 17),      S(6, -17),      //
    S(60, -25),     S(81, -12),     S(96, 17),      S(62, 39),      S(57, 21),      S(56, 31),      S(61, 12),      S(8, 3),        //
    S(27, -59),     S(109, -41),    S(71, -19),     S(47, 3),       S(31, 5),       S(43, -26),     S(40, -33),     S(40, -41),     //
    S(49, -59),     S(31, -27),     S(26, 6),       S(45, -19),     S(31, -9),      S(35, 26),      S(45, -5),      S(40, -34),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(195, 86),     S(232, 94),     S(187, 110),    S(182, 83),     S(222, 74),     S(179, 92),     S(200, 98),     S(181, 107),    //
    S(82, 159),     S(170, 149),    S(230, 117),    S(169, 129),    S(207, 121),    S(175, 131),    S(119, 159),    S(100, 165),    //
    S(48, 156),     S(170, 129),    S(216, 89),     S(184, 91),     S(180, 113),    S(135, 135),    S(137, 139),    S(74, 170),     //
    S(16, 131),     S(107, 124),    S(134, 99),     S(107, 111),    S(140, 99),     S(94, 135),     S(98, 131),     S(23, 160),     //
    S(-7, 64),      S(73, 66),      S(64, 80),      S(32, 86),      S(40, 98),      S(33, 117),     S(6, 117),      S(-9, 112),     //
    S(8, -9),       S(83, 10),      S(72, 24),      S(49, 27),      S(61, 32),      S(29, 66),      S(38, 43),      S(-3, 53),      //
    S(-87, -4),     S(54, -40),     S(59, -19),     S(47, 4),       S(50, 8),       S(37, 18),      S(28, 6),       S(-3, 20),      //
    S(-24, -19),    S(3, -1),       S(62, -13),     S(73, -18),     S(71, -6),      S(52, 11),      S(48, 7),       S(27, 13),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(90, 112),     S(188, 46),     S(112, 142),    S(52, 229),     S(89, 186),     S(83, 170),     S(111, 83),     S(35, 150),     //
    S(70, 168),     S(83, 251),     S(55, 268),     S(-73, 339),    S(-29, 327),    S(13, 288),     S(60, 179),     S(36, 181),     //
    S(39, 203),     S(63, 259),     S(33, 312),     S(0, 315),      S(8, 323),      S(57, 250),     S(77, 188),     S(85, 108),     //
    S(60, 100),     S(60, 184),     S(12, 251),     S(-4, 312),     S(9, 325),      S(44, 215),     S(86, 145),     S(58, 124),     //
    S(61, 67),      S(42, 134),     S(23, 186),     S(-2, 251),     S(12, 275),     S(28, 228),     S(52, 142),     S(70, 79),      //
    S(52, 2),       S(67, 45),      S(63, 117),     S(44, 127),     S(47, 150),     S(48, 184),     S(67, 123),     S(60, 77),      //
    S(27, -111),    S(42, -55),     S(49, -8),      S(76, 15),      S(67, 63),      S(67, 43),      S(37, 84),      S(58, 51),      //
    S(11, -98),     S(34, -215),    S(62, -212),    S(78, -116),    S(72, -22),     S(78, -65),     S(73, -34),     S(48, -11),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-64, -205),   S(301, 244),    S(203, 224),    S(72, 118),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(234, 23),     S(319, 204),    S(186, 219),    S(134, 98),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(178, 84),     S(233, 168),    S(154, 184),    S(103, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(11, 34),      S(133, 99),     S(16, 152),     S(-13, 164),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-90, -16),    S(-2, 49),      S(-60, 104),    S(-145, 165),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -48),    S(29, 7),       S(-63, 76),     S(-114, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -87),     S(29, -25),     S(-45, 23),     S(-108, 70),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -175),   S(1, -88),      S(-81, -47),    S(-75, -59),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -559);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -26), S(14, -26), S(14, -7), S(5, -10), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -28), S(4, -18), S(4, -2), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, 43), S(-3, 55), S(-1, -16), S(10, -26), S(9, -21), S(-2, -6), S(-2, 56), }},
  {{ S(-1, 164), S(-19, -251), S(-20, 2), S(-7, 51), S(-7, 67), S(-19, -7), S(-18, -236), }},
  {{ S(-4, 145), S(-9, -238), S(-10, 129), S(-4, 111), S(-3, 109), S(-10, 134), S(-9, -214), }},
  {{ S(8, 125), S(-10, 82), S(1, 91), S(8, 71), S(6, 74), S(-0, 92), S(-7, 80), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 61), S(-11, 55), S(-10, 80), S(-2, 83), S(4, 32),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 119), S(-8, 36), S(-9, 37), S(-6, 37), S(-6, 32), S(-8, 37), S(-9, 48), }},
  {{ S(9, 7), S(1, -32), S(-8, -21), S(-3, -52), S(-4, -55), S(-7, -23), S(1, -25), }},
  {{ S(1, 61), S(-4, 35), S(-7, 38), S(-4, 37), S(-3, 19), S(-7, 34), S(-3, 23), }},
  {{ S(-0, 58), S(-7, 35), S(-11, 37), S(-5, 47), S(-4, 47), S(-10, 32), S(-8, 36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1074, 248, -13, 90
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(136);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 6.1272s
// clang-format on
}  // namespace Clockwork
