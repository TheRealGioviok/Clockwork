#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(197, 382);
inline const PParam KNIGHT_MAT = S(912, 1020);
inline const PParam BISHOP_MAT = S(945, 1070);
inline const PParam ROOK_MAT   = S(1150, 1717);
inline const PParam QUEEN_MAT  = S(2684, 2706);
inline const PParam TEMPO_VAL  = S(61, 20);

inline const PParam BISHOP_PAIR_VAL   = S(52, 200);
inline const PParam ROOK_OPEN_VAL     = S(118, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 27);
inline const PParam MINOR_BEHIND_PAWN = S(12, 39);
inline const PParam RESTRICTED_SQUARES = S(-24, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -19);

inline const PParam POTENTIAL_CHECKER_VAL = S(-52, -20);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(60, 33);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(48, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, -1), S(32, 26), S(64, 38), S(140, 93), S(351, 209), S(438, 526),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 33), S(46, 26), S(64, 51), S(126, 139), S(417, 80),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-111, -181), S(-112, -156), S(-85, -49), S(-26, 50), S(82, 183), S(261, 259),
};
inline const std::array<PParam, 6> CANDIDATE_PASSER = {
    S(-51, 16), S(-27, 11), S(-14, 55), S(20, 85), S(63, 75), S(0, 0),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(28, -38), S(22, 1), S(15, 32), S(-1, 118), S(82, 204), S(257, 255),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -16), S(-0, 24), S(-2, -11), S(0, -41), S(-5, -129), S(-251, -212),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 183), S(-2, 156), S(4, 87), S(11, 52), S(18, 53), S(54, 49), S(48, 31),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-270, -38), S(-7, 33), S(-3, 88), S(38, 110), S(59, 129), S(71, 133), S(49, 132),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-113, -245), S(-48, -76), S(-16, 12), S(10, 43), S(42, 59), S(59, 88), S(82, 84), S(101, 94), S(147, 6),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-81, -229), S(-36, -66), S(18, -0), S(42, 44), S(66, 75), S(81, 97), S(89, 113), S(100, 119), S(104, 133), S(124, 113), S(129, 113), S(177, 55), S(178, 56), S(210, 5),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -114), S(15, 46), S(37, 73), S(54, 83), S(64, 96), S(69, 107), S(75, 118), S(82, 120), S(86, 131), S(94, 133), S(103, 135), S(106, 140), S(110, 138), S(124, 109), S(208, 4),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-129, -84), S(12, -29), S(38, 83), S(59, 188), S(75, 226), S(83, 267), S(89, 297), S(97, 305), S(101, 327), S(103, 343), S(108, 348), S(111, 357), S(116, 355), S(116, 360), S(117, 358), S(114, 359), S(110, 360), S(115, 348), S(120, 336), S(122, 328), S(117, 315), S(135, 275), S(111, 287), S(108, 225), S(78, 220), S(72, 184), S(14, 207), S(23, 159),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 86);
inline const PParam PAWN_THREAT_BISHOP = S(208, 128);
inline const PParam PAWN_THREAT_ROOK   = S(196, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(181, -10);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 73);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -16);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(214, 122);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 88);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -30), S(-3, -3), S(-5, -12), S(-7, -23), S(-11, -32), S(-14, -40), S(-15, -52), S(-20, -54), S(-35, -50),
};

inline const PParam ROOK_LINEUP = S(15, 63);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(227, 181),    S(65, 236),     S(195, 190),    S(174, 169),    S(220, 102),    S(112, 190),    S(54, 228),     S(193, 175),    //
    S(39, 19),      S(61, 37),      S(60, 16),      S(31, -34),     S(28, -64),     S(8, -18),      S(-10, 33),     S(-36, 57),     //
    S(22, -19),     S(-2, -9),      S(29, -49),     S(17, -73),     S(12, -86),     S(-11, -59),    S(-59, -12),    S(-53, 10),     //
    S(-10, -64),    S(-28, -37),    S(-1, -60),     S(-12, -69),    S(-35, -69),    S(-41, -52),    S(-98, -15),    S(-87, -24),    //
    S(-6, -93),     S(27, -91),     S(10, -43),     S(-4, -47),     S(-33, -54),    S(-49, -49),    S(-84, -33),    S(-82, -41),    //
    S(12, -91),     S(93, -93),     S(70, -51),     S(28, -18),     S(-2, -35),     S(-22, -46),    S(-54, -28),    S(-66, -27),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-335, -305),  S(-270, 20),    S(-252, -88),   S(-5, 18),      S(-79, 20),     S(-229, 32),    S(-398, 89),    S(-408, -202),  //
    S(-46, -9),     S(-17, 16),     S(101, -21),    S(105, 2),      S(102, 10),     S(23, 28),      S(-42, 32),     S(-67, 13),     //
    S(21, -9),      S(57, -18),     S(86, 44),      S(103, 43),     S(66, 72),      S(19, 73),      S(8, 16),       S(-43, 13),     //
    S(89, 9),       S(102, 29),     S(108, 61),     S(112, 90),     S(118, 92),     S(71, 81),      S(46, 48),      S(32, 22),      //
    S(70, 8),       S(113, -11),    S(94, 56),      S(90, 72),      S(68, 77),      S(72, 66),      S(59, 15),      S(12, 27),      //
    S(6, -24),      S(32, 0),       S(30, 42),      S(45, 60),      S(39, 59),      S(8, 43),       S(2, 7),        S(-37, -25),    //
    S(22, -16),     S(31, -16),     S(7, -1),       S(15, 20),      S(13, 18),      S(-12, -28),    S(-33, -7),     S(-46, -91),    //
    S(-51, -74),    S(-1, -13),     S(20, -40),     S(36, -35),     S(18, -15),     S(-17, -40),    S(-29, -22),    S(-70, -117),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-154, 78),    S(-159, 82),    S(-441, 140),   S(-289, 85),    S(-283, 85),    S(-308, 83),    S(-211, 83),    S(-129, 61),    //
    S(-46, 4),      S(-83, 80),     S(-43, 26),     S(-98, 55),     S(-78, 48),     S(-57, 43),     S(-20, 36),     S(-54, 14),     //
    S(27, 20),      S(16, 41),      S(30, 48),      S(20, 49),      S(-2, 48),      S(4, 48),       S(9, 38),       S(10, 12),      //
    S(13, 1),       S(45, 18),      S(52, 45),      S(55, 82),      S(87, 67),      S(31, 38),      S(38, 3),       S(-6, 4),       //
    S(45, -43),     S(51, -3),      S(68, 28),      S(73, 58),      S(55, 68),      S(51, 46),      S(16, 16),      S(10, -21),     //
    S(64, -31),     S(80, -11),     S(90, 22),      S(54, 47),      S(49, 28),      S(48, 38),      S(60, 13),      S(11, -1),      //
    S(26, -59),     S(104, -37),    S(67, -16),     S(49, 0),       S(31, 4),       S(38, -22),     S(36, -30),     S(40, -42),     //
    S(48, -57),     S(30, -27),     S(35, -3),      S(53, -27),     S(39, -17),     S(43, 18),      S(44, -4),      S(38, -32),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(194, 87),     S(232, 94),     S(185, 111),    S(181, 83),     S(223, 71),     S(177, 93),     S(200, 96),     S(180, 107),    //
    S(83, 157),     S(168, 150),    S(229, 117),    S(169, 129),    S(208, 121),    S(176, 129),    S(120, 158),    S(101, 164),    //
    S(47, 156),     S(170, 128),    S(217, 89),     S(185, 90),     S(181, 111),    S(136, 135),    S(139, 136),    S(74, 169),     //
    S(15, 132),     S(107, 123),    S(134, 98),     S(108, 110),    S(141, 97),     S(94, 134),     S(97, 131),     S(23, 160),     //
    S(-7, 64),      S(73, 67),      S(64, 80),      S(33, 86),      S(41, 97),      S(32, 118),     S(7, 117),      S(-10, 113),    //
    S(8, -8),       S(83, 12),      S(73, 23),      S(50, 27),      S(61, 32),      S(29, 66),      S(38, 44),      S(-3, 53),      //
    S(-86, -4),     S(54, -40),     S(59, -18),     S(48, 3),       S(50, 9),       S(37, 19),      S(29, 6),       S(-3, 20),      //
    S(-23, -19),    S(3, -1),       S(62, -14),     S(73, -18),     S(72, -6),      S(52, 11),      S(48, 6),       S(28, 13),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(91, 112),     S(188, 47),     S(113, 144),    S(53, 230),     S(92, 184),     S(85, 168),     S(113, 81),     S(36, 151),     //
    S(71, 171),     S(85, 251),     S(56, 270),     S(-71, 339),    S(-28, 328),    S(15, 287),     S(61, 180),     S(37, 181),     //
    S(40, 204),     S(65, 258),     S(35, 312),     S(2, 316),      S(8, 325),      S(59, 251),     S(77, 189),     S(85, 109),     //
    S(61, 101),     S(60, 186),     S(12, 253),     S(-3, 312),     S(10, 326),     S(45, 217),     S(86, 148),     S(59, 123),     //
    S(62, 69),      S(44, 134),     S(24, 189),     S(-1, 253),     S(12, 277),     S(28, 231),     S(52, 145),     S(70, 81),      //
    S(53, 4),       S(67, 48),      S(63, 120),     S(44, 131),     S(48, 151),     S(48, 187),     S(66, 127),     S(59, 80),      //
    S(27, -108),    S(42, -54),     S(49, -8),      S(77, 15),      S(68, 64),      S(67, 46),      S(38, 87),      S(58, 53),      //
    S(11, -96),     S(35, -217),    S(63, -214),    S(77, -113),    S(72, -20),     S(77, -61),     S(72, -33),     S(48, -9),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-64, -206),   S(301, 243),    S(202, 224),    S(73, 117),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(234, 21),     S(317, 205),    S(188, 217),    S(135, 97),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(177, 84),     S(234, 167),    S(154, 184),    S(109, 114),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, 33),      S(133, 97),     S(19, 150),     S(-10, 162),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-92, -16),    S(-2, 49),      S(-61, 104),    S(-143, 164),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -49),    S(29, 7),       S(-62, 76),     S(-113, 124),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(20, -88),     S(30, -26),     S(-43, 22),     S(-108, 71),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -174),   S(2, -87),      S(-80, -46),    S(-74, -58),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -560);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -26), S(14, -26), S(14, -7), S(6, -10), S(1, -30),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -20), S(6, -28), S(4, -18), S(4, -2), S(4, 7),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 3);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 45), S(-3, 55), S(-1, -14), S(10, -26), S(9, -20), S(-2, -6), S(-2, 56), }},
  {{ S(-1, 166), S(-19, -252), S(-20, 2), S(-7, 49), S(-7, 64), S(-18, -8), S(-18, -237), }},
  {{ S(-3, 146), S(-8, -238), S(-9, 130), S(-3, 109), S(-2, 107), S(-9, 135), S(-8, -212), }},
  {{ S(8, 127), S(-9, 82), S(2, 93), S(8, 72), S(7, 75), S(-0, 93), S(-6, 81), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(12, 65), S(-10, 54), S(-10, 77), S(-2, 79), S(1, 23),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 117), S(-8, 37), S(-9, 38), S(-5, 36), S(-6, 30), S(-7, 36), S(-8, 48), }},
  {{ S(10, 6), S(1, -33), S(-8, -21), S(-3, -54), S(-4, -54), S(-6, -23), S(2, -25), }},
  {{ S(1, 59), S(-3, 33), S(-6, 38), S(-3, 35), S(-2, 19), S(-7, 34), S(-3, 23), }},
  {{ S(-0, 55), S(-6, 34), S(-10, 36), S(-5, 44), S(-3, 45), S(-9, 32), S(-8, 35), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1074, 247, -17, 91
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(224);
inline VParam WINNABLE_BIAS = V(-653);

// Epoch duration: 5.28868s
// clang-format on
}  // namespace Clockwork
