#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(212, 343);
inline const PParam KNIGHT_MAT = S(948, 1047);
inline const PParam BISHOP_MAT = S(980, 1121);
inline const PParam ROOK_MAT   = S(1180, 1702);
inline const PParam QUEEN_MAT  = S(2613, 2936);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(52, 196);
inline const PParam ROOK_OPEN_VAL     = S(105, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 21);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -70);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 66);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 41);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -36);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 2), S(38, 27), S(58, 51), S(135, 146), S(373, 208), S(428, 523),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 35), S(44, 27), S(54, 54), S(116, 143), S(398, 94),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-83, -134), S(-79, -111), S(-58, 1), S(-1, 108), S(80, 255), S(224, 311),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -44), S(34, -4), S(22, 31), S(1, 109), S(49, 219), S(202, 282),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(22, -37), S(3, 12), S(2, -20), S(-1, -53), S(-9, -124), S(-212, -231),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-1, 155), S(-13, 119), S(-8, 50), S(-2, 15), S(4, 13), S(39, 12), S(14, 6),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-296, -47), S(-33, 33), S(-17, 67), S(20, 102), S(39, 119), S(56, 120), S(38, 112),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-170, -261), S(-99, -91), S(-64, -1), S(-37, 35), S(4, 53), S(28, 88), S(60, 85), S(91, 99), S(144, 13),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-122, -267), S(-79, -94), S(-24, -31), S(3, 14), S(27, 46), S(43, 71), S(50, 90), S(64, 100), S(70, 119), S(95, 99), S(105, 102), S(153, 50), S(152, 63), S(182, 11),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(73, -117), S(-8, 62), S(17, 87), S(35, 96), S(45, 109), S(52, 120), S(58, 130), S(67, 132), S(73, 143), S(84, 144), S(95, 145), S(103, 150), S(108, 149), S(125, 121), S(210, 18),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-84, -86), S(75, -132), S(100, -20), S(118, 92), S(134, 138), S(142, 183), S(148, 215), S(156, 225), S(160, 248), S(163, 263), S(169, 270), S(173, 278), S(182, 271), S(184, 277), S(189, 272), S(187, 276), S(190, 271), S(196, 264), S(202, 258), S(212, 249), S(220, 226), S(242, 187), S(240, 185), S(239, 132), S(227, 116), S(220, 85), S(159, 134), S(178, 48),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(362, -5), S(109, -113), S(29, -30), S(16, 3), S(-4, 2), S(-21, -2), S(-29, 10), S(-45, 19), S(-35, -19),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(16, -14), S(14, -11), S(6, -7), S(3, -23),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -1), S(7, -10), S(6, -8), S(5, -5), S(6, 69),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 91);
inline const PParam PAWN_THREAT_BISHOP = S(190, 142);
inline const PParam PAWN_THREAT_ROOK   = S(190, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(164, -12);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 68);
inline const PParam KNIGHT_THREAT_QUEEN  = S(148, 3);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 95);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -17), S(-9, -28), S(-13, -37), S(-18, -42), S(-20, -54), S(-27, -52), S(-39, -52),
};

inline const PParam ROOK_LINEUP = S(12, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(249, 260),    S(99, 360),     S(243, 329),    S(255, 194),    S(276, 150),    S(168, 235),    S(107, 271),    S(216, 224),    //
    S(42, 69),      S(73, 109),     S(113, 25),     S(98, -40),     S(78, -57),     S(51, -3),      S(23, 53),      S(-26, 79),     //
    S(5, 33),       S(-8, 35),      S(34, -39),     S(35, -61),     S(24, -65),     S(-4, -32),     S(-52, 17),     S(-64, 46),     //
    S(-19, -15),    S(-29, 8),      S(7, -44),      S(4, -53),      S(-18, -50),    S(-34, -25),    S(-95, 19),     S(-95, 11),     //
    S(-20, -40),    S(19, -33),     S(4, -3),       S(-3, -19),     S(-31, -23),    S(-53, -17),    S(-87, -0),     S(-96, -6),     //
    S(-7, -39),     S(83, -23),     S(68, 33),      S(19, 12),      S(-9, -1),      S(-29, -7),     S(-59, 5),      S(-78, 8),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-395, -237),  S(-297, 34),    S(-241, -117),  S(-48, 20),     S(-114, 26),    S(-254, 26),    S(-388, 76),    S(-434, -166),  //
    S(-69, -2),     S(-28, 27),     S(59, -14),     S(54, -6),      S(49, 3),       S(-34, 28),     S(-69, 41),     S(-96, 19),     //
    S(14, -3),      S(61, -8),      S(63, 48),      S(64, 33),      S(24, 68),      S(-37, 84),     S(-24, 27),     S(-59, 19),     //
    S(82, 19),      S(89, 39),      S(85, 64),      S(73, 94),      S(74, 102),     S(28, 88),      S(21, 56),      S(17, 27),      //
    S(66, 22),      S(101, 5),      S(70, 63),      S(66, 82),      S(43, 87),      S(41, 71),      S(38, 20),      S(1, 27),       //
    S(11, -13),     S(36, -1),      S(26, 36),      S(35, 62),      S(31, 61),      S(-5, 41),      S(-15, 9),      S(-44, -24),    //
    S(22, -9),      S(44, -12),     S(11, -3),      S(13, 21),      S(4, 19),       S(-23, -25),    S(-36, -4),     S(-48, -87),    //
    S(-42, -58),    S(3, 8),        S(19, -27),     S(35, -34),     S(16, -9),      S(-17, -38),    S(-32, -12),    S(-69, -92),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-162, 89),    S(-177, 101),   S(-433, 140),   S(-301, 79),    S(-314, 102),   S(-324, 97),    S(-209, 95),    S(-130, 69),    //
    S(-41, 1),      S(-98, 81),     S(-66, 36),     S(-120, 54),    S(-103, 52),    S(-78, 51),     S(-40, 46),     S(-66, 27),     //
    S(30, 31),      S(43, 42),      S(36, 52),      S(12, 52),      S(-17, 47),     S(-9, 56),      S(7, 46),       S(3, 18),       //
    S(0, 21),       S(35, 33),      S(36, 53),      S(34, 90),      S(63, 80),      S(-6, 56),      S(6, 20),       S(-35, 20),     //
    S(28, -20),     S(45, 13),      S(50, 37),      S(54, 66),      S(30, 80),      S(16, 57),      S(-17, 35),     S(-20, -9),     //
    S(55, -12),     S(88, 1),       S(99, 28),      S(45, 54),      S(41, 31),      S(35, 43),      S(42, 20),      S(-18, 17),     //
    S(21, -39),     S(121, -23),    S(78, -10),     S(45, 9),       S(25, 13),      S(29, -12),     S(29, -14),     S(22, -19),     //
    S(53, -38),     S(41, -22),     S(40, 13),      S(53, -24),     S(43, -13),     S(43, 29),      S(40, 8),       S(31, -15),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(192, 81),     S(205, 100),    S(180, 115),    S(199, 77),     S(179, 83),     S(147, 91),     S(141, 110),    S(137, 111),    //
    S(67, 166),     S(142, 163),    S(221, 125),    S(164, 134),    S(149, 142),    S(128, 147),    S(63, 176),     S(46, 182),     //
    S(36, 161),     S(137, 148),    S(196, 107),    S(174, 96),     S(126, 125),    S(84, 148),     S(88, 144),     S(21, 185),     //
    S(41, 120),     S(117, 129),    S(152, 104),    S(127, 107),    S(118, 118),    S(78, 140),     S(75, 134),     S(1, 162),      //
    S(23, 53),      S(87, 70),      S(76, 91),      S(56, 87),      S(32, 112),     S(23, 124),     S(-7, 117),     S(-27, 115),    //
    S(16, -6),      S(76, 25),      S(63, 49),      S(49, 46),      S(35, 55),      S(10, 77),      S(7, 53),       S(-27, 59),     //
    S(-92, 6),      S(40, -29),     S(51, 0),       S(40, 25),      S(26, 29),      S(18, 33),      S(-0, 20),      S(-25, 30),     //
    S(-27, -9),     S(-4, 11),      S(52, 2),       S(64, -1),      S(53, 7),       S(33, 22),      S(22, 18),      S(3, 27),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(163, 109),    S(214, 59),     S(138, 182),    S(107, 249),    S(92, 232),     S(126, 175),    S(147, 101),    S(99, 143),     //
    S(163, 166),    S(125, 264),    S(115, 295),    S(-26, 383),    S(-18, 370),    S(41, 328),     S(86, 202),     S(96, 186),     //
    S(127, 235),    S(173, 249),    S(105, 356),    S(59, 365),     S(32, 364),     S(84, 280),     S(117, 206),    S(136, 132),    //
    S(165, 151),    S(172, 233),    S(109, 303),    S(99, 335),     S(91, 334),     S(101, 242),    S(144, 176),    S(130, 143),    //
    S(179, 125),    S(167, 193),    S(138, 246),    S(108, 288),    S(106, 289),    S(108, 239),    S(126, 162),    S(154, 85),     //
    S(159, 66),     S(193, 117),    S(184, 183),    S(155, 175),    S(151, 163),    S(145, 191),    S(159, 111),    S(139, 83),     //
    S(140, -45),    S(178, -34),    S(182, 32),     S(193, 70),     S(179, 98),     S(173, 64),     S(135, 104),    S(147, 81),     //
    S(122, -32),    S(154, -182),   S(177, -162),   S(191, -50),    S(187, 22),     S(186, -32),    S(174, -6),     S(142, 24),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-99, -309),   S(265, 181),    S(142, 140),    S(4, -22),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(208, -62),    S(337, 151),    S(194, 145),    S(107, -1),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(209, 31),     S(372, 96),     S(259, 99),     S(153, -1),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(65, -2),      S(320, 35),     S(172, 56),     S(106, 21),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-37, -25),    S(218, 1),      S(147, 8),      S(28, 19),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-34, -16),    S(202, -9),     S(107, -0),     S(49, -14),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, -15),    S(75, 31),      S(-7, 30),      S(-69, 6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-128, -64),   S(-28, -19),    S(-128, -16),   S(-132, -89),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -12), S(-2, 22), S(-5, 23), S(2, 10), S(3, 7), S(-5, 23), S(1, 22), }},
  {{ S(8, -2), S(-20, 28), S(-16, 23), S(-7, 6), S(-6, 7), S(-16, 28), S(-19, 36), }},
  {{ S(2, -3), S(-9, 21), S(-7, 4), S(-3, -10), S(-3, -9), S(-7, 3), S(-8, 18), }},
  {{ S(3, -9), S(-15, -10), S(-6, -13), S(-1, -16), S(-2, -15), S(-7, -11), S(-10, -11), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(12, 20), S(-10, 22), S(-7, 13), S(0, 2), S(1, -13),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(4, -3), S(-6, 5), S(-5, 3), S(-4, 3), S(-4, -2), S(-3, -5), S(-6, 4), }},
  {{ S(5, -4), S(-3, 3), S(-10, 7), S(-6, 4), S(-6, 0), S(-8, 4), S(-3, 2), }},
  {{ S(-1, -1), S(-6, -2), S(-7, 4), S(-3, 3), S(-2, 2), S(-7, 2), S(-6, -1), }},
  {{ S(-2, 1), S(-7, 2), S(-8, 2), S(-3, 6), S(-1, 6), S(-7, 2), S(-9, 2), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1134, 570, -73, 66
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(225);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 7.52381s
// clang-format on
}  // namespace Clockwork
