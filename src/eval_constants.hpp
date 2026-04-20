#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(196, 383);
inline const PParam KNIGHT_MAT = S(912, 1020);
inline const PParam BISHOP_MAT = S(946, 1070);
inline const PParam ROOK_MAT   = S(1150, 1716);
inline const PParam QUEEN_MAT  = S(2680, 2701);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_PAIR_VAL   = S(52, 200);
inline const PParam ROOK_OPEN_VAL     = S(118, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 27);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);
inline const PParam RESTRICTED_SQUARES = S(-24, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(59, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 46);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -2), S(32, 27), S(61, 48), S(144, 141), S(381, 208), S(438, 526),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 33), S(47, 26), S(62, 51), S(121, 141), S(415, 81),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-107, -185), S(-108, -158), S(-81, -52), S(-23, 45), S(73, 180), S(262, 258),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -38), S(21, 2), S(15, 32), S(1, 111), S(82, 203), S(257, 255),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -16), S(0, 24), S(-2, -10), S(0, -40), S(-5, -129), S(-251, -212),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 183), S(-5, 156), S(1, 88), S(8, 53), S(14, 54), S(51, 50), S(45, 32),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-274, -37), S(-11, 34), S(-4, 89), S(38, 111), S(60, 130), S(71, 134), S(49, 133),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-113, -245), S(-48, -76), S(-16, 12), S(10, 44), S(42, 60), S(59, 88), S(81, 84), S(101, 94), S(146, 7),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-80, -228), S(-35, -66), S(18, -0), S(43, 44), S(67, 75), S(81, 97), S(89, 113), S(100, 119), S(104, 133), S(124, 113), S(129, 113), S(177, 55), S(176, 58), S(210, 5),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(98, -113), S(14, 46), S(37, 73), S(53, 83), S(64, 96), S(68, 108), S(74, 119), S(81, 121), S(86, 132), S(94, 134), S(102, 136), S(106, 141), S(110, 138), S(123, 110), S(208, 4),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-127, -82), S(13, -25), S(39, 86), S(60, 192), S(75, 231), S(84, 271), S(90, 301), S(98, 310), S(101, 331), S(103, 347), S(109, 351), S(111, 361), S(117, 359), S(117, 364), S(118, 362), S(115, 363), S(111, 364), S(115, 353), S(121, 339), S(123, 332), S(118, 319), S(137, 278), S(113, 290), S(110, 229), S(80, 222), S(74, 188), S(17, 208), S(26, 161),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 85);
inline const PParam PAWN_THREAT_BISHOP = S(208, 128);
inline const PParam PAWN_THREAT_ROOK   = S(198, 124);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -10);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(228, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -18);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 56);
inline const PParam BISHOP_THREAT_ROOK   = S(214, 122);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 89);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -30), S(-3, -3), S(-5, -12), S(-7, -23), S(-11, -32), S(-14, -40), S(-15, -52), S(-20, -54), S(-35, -50),
};

inline const PParam ROOK_LINEUP = S(15, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(228, 182),    S(65, 236),     S(196, 190),    S(175, 169),    S(221, 103),    S(115, 188),    S(56, 228),     S(196, 174),    //
    S(48, 20),      S(75, 37),      S(74, 16),      S(49, -34),     S(44, -64),     S(21, -18),     S(3, 33),       S(-28, 58),     //
    S(23, -16),     S(-0, -7),      S(31, -46),     S(19, -70),     S(14, -83),     S(-9, -56),     S(-56, -10),    S(-52, 12),     //
    S(-10, -63),    S(-29, -36),    S(-2, -59),     S(-12, -67),    S(-35, -67),    S(-41, -51),    S(-98, -15),    S(-87, -24),    //
    S(-7, -93),     S(24, -91),     S(8, -43),      S(-5, -46),     S(-34, -53),    S(-51, -49),    S(-86, -32),    S(-83, -41),    //
    S(12, -89),     S(91, -91),     S(68, -48),     S(27, -16),     S(-2, -32),     S(-23, -44),    S(-54, -26),    S(-67, -25),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-334, -308),  S(-270, 20),    S(-253, -87),   S(-4, 17),      S(-79, 21),     S(-229, 33),    S(-397, 89),    S(-408, -203),  //
    S(-45, -9),     S(-18, 18),     S(100, -19),    S(106, 2),      S(101, 11),     S(23, 30),      S(-42, 33),     S(-67, 13),     //
    S(22, -10),     S(57, -18),     S(87, 43),      S(103, 43),     S(66, 73),      S(19, 73),      S(8, 17),       S(-41, 12),     //
    S(90, 9),       S(103, 29),     S(109, 61),     S(113, 89),     S(119, 92),     S(72, 81),      S(47, 48),      S(32, 22),      //
    S(70, 9),       S(113, -10),    S(95, 56),      S(90, 72),      S(69, 77),      S(72, 67),      S(60, 14),      S(13, 26),      //
    S(7, -23),      S(32, 0),       S(31, 42),      S(46, 60),      S(40, 59),      S(9, 43),       S(3, 8),        S(-37, -25),    //
    S(24, -17),     S(32, -15),     S(7, -1),       S(16, 21),      S(14, 18),      S(-11, -28),    S(-32, -7),     S(-46, -91),    //
    S(-50, -73),    S(-1, -13),     S(20, -39),     S(36, -35),     S(19, -15),     S(-16, -41),    S(-28, -23),    S(-69, -116),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-155, 78),    S(-159, 82),    S(-442, 140),   S(-290, 86),    S(-285, 87),    S(-308, 82),    S(-212, 83),    S(-131, 63),    //
    S(-47, 5),      S(-84, 82),     S(-44, 27),     S(-100, 57),    S(-79, 49),     S(-59, 44),     S(-20, 36),     S(-54, 14),     //
    S(27, 20),      S(16, 41),      S(30, 49),      S(20, 49),      S(-2, 48),      S(4, 48),       S(8, 39),       S(10, 13),      //
    S(12, 2),       S(45, 19),      S(52, 45),      S(55, 83),      S(87, 68),      S(30, 40),      S(38, 3),       S(-6, 5),       //
    S(45, -43),     S(51, -3),      S(68, 29),      S(73, 59),      S(55, 69),      S(51, 47),      S(16, 16),      S(11, -21),     //
    S(64, -30),     S(80, -11),     S(90, 23),      S(54, 47),      S(49, 29),      S(48, 39),      S(59, 14),      S(11, -0),      //
    S(26, -57),     S(104, -36),    S(67, -15),     S(49, 1),       S(31, 5),       S(38, -22),     S(35, -29),     S(39, -40),     //
    S(47, -56),     S(30, -26),     S(35, -2),      S(53, -26),     S(39, -17),     S(42, 19),      S(43, -3),      S(38, -32),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(195, 87),     S(232, 95),     S(187, 110),    S(181, 84),     S(223, 73),     S(179, 94),     S(201, 97),     S(181, 107),    //
    S(83, 159),     S(169, 151),    S(230, 116),    S(169, 130),    S(207, 122),    S(175, 131),    S(120, 159),    S(101, 165),    //
    S(48, 157),     S(172, 128),    S(218, 89),     S(185, 91),     S(182, 112),    S(136, 136),    S(139, 138),    S(75, 171),     //
    S(16, 132),     S(107, 125),    S(136, 98),     S(109, 110),    S(141, 99),     S(95, 136),     S(99, 132),     S(24, 160),     //
    S(-6, 65),      S(74, 67),      S(65, 81),      S(34, 86),      S(43, 97),      S(34, 118),     S(7, 118),      S(-9, 113),     //
    S(9, -9),       S(84, 12),      S(74, 23),      S(51, 27),      S(62, 32),      S(30, 67),      S(39, 44),      S(-3, 54),      //
    S(-86, -3),     S(55, -40),     S(60, -18),     S(48, 4),       S(51, 9),       S(38, 20),      S(30, 6),       S(-2, 21),      //
    S(-23, -19),    S(4, -0),       S(62, -13),     S(73, -17),     S(72, -6),      S(52, 12),      S(49, 7),       S(28, 13),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(91, 111),     S(187, 46),     S(112, 142),    S(54, 226),     S(93, 180),     S(85, 167),     S(112, 81),     S(36, 148),     //
    S(70, 169),     S(84, 249),     S(54, 270),     S(-71, 336),    S(-29, 328),    S(14, 286),     S(61, 178),     S(37, 179),     //
    S(40, 203),     S(64, 257),     S(33, 313),     S(1, 315),      S(9, 322),      S(58, 249),     S(77, 187),     S(85, 108),     //
    S(60, 99),      S(60, 184),     S(11, 252),     S(-5, 313),     S(9, 327),      S(44, 215),     S(85, 147),     S(59, 122),     //
    S(61, 68),      S(43, 132),     S(23, 187),     S(-2, 251),     S(12, 276),     S(27, 229),     S(52, 143),     S(69, 80),      //
    S(53, 2),       S(67, 46),      S(63, 119),     S(44, 128),     S(47, 150),     S(48, 185),     S(66, 125),     S(60, 76),      //
    S(27, -109),    S(41, -54),     S(49, -10),     S(77, 15),      S(67, 63),      S(67, 44),      S(37, 85),      S(58, 51),      //
    S(11, -98),     S(35, -218),    S(62, -213),    S(77, -115),    S(71, -22),     S(76, -63),     S(72, -35),     S(48, -11),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-62, -204),   S(302, 245),    S(203, 225),    S(70, 119),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(235, 24),     S(318, 207),    S(187, 220),    S(133, 99),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(178, 86),     S(235, 169),    S(154, 185),    S(104, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(11, 36),      S(134, 100),    S(18, 153),     S(-12, 164),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-90, -16),    S(-1, 50),      S(-58, 104),    S(-144, 165),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -48),    S(29, 8),       S(-63, 77),     S(-114, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -87),     S(29, -25),     S(-45, 23),     S(-109, 72),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -174),   S(0, -87),      S(-82, -45),    S(-76, -57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
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
  {{ S(18, 44), S(-3, 55), S(-1, -14), S(10, -26), S(9, -21), S(-2, -6), S(-2, 57), }},
  {{ S(-1, 167), S(-19, -254), S(-20, 1), S(-8, 50), S(-7, 66), S(-19, -8), S(-18, -238), }},
  {{ S(-3, 147), S(-9, -239), S(-10, 130), S(-4, 109), S(-3, 108), S(-10, 135), S(-8, -215), }},
  {{ S(7, 126), S(-10, 81), S(1, 93), S(8, 71), S(6, 74), S(-1, 92), S(-7, 81), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 60), S(-10, 53), S(-10, 78), S(-1, 84), S(4, 31),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 118), S(-8, 36), S(-9, 37), S(-5, 35), S(-6, 30), S(-7, 36), S(-9, 48), }},
  {{ S(9, 4), S(1, -34), S(-8, -21), S(-3, -55), S(-4, -55), S(-7, -24), S(1, -26), }},
  {{ S(1, 60), S(-3, 35), S(-6, 39), S(-3, 35), S(-3, 19), S(-7, 35), S(-3, 24), }},
  {{ S(-0, 56), S(-6, 35), S(-10, 37), S(-5, 45), S(-3, 46), S(-9, 32), S(-8, 36), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1075, 247, -14, 93
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-653);

#define SF_MAX 128
inline VParam SF_GENERIC_BASE = V(72);
inline VParam SF_SSIDEPAWNS = V(14);

// Epoch duration: 7.03101s
// clang-format on
}  // namespace Clockwork
