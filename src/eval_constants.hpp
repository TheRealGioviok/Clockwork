#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(212, 342);
inline const PParam KNIGHT_MAT = S(948, 1049);
inline const PParam BISHOP_MAT = S(978, 1122);
inline const PParam ROOK_MAT   = S(1180, 1703);
inline const PParam QUEEN_MAT  = S(2613, 2936);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(53, 196);
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
    S(16, 2), S(38, 28), S(58, 51), S(135, 146), S(375, 206), S(429, 522),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 35), S(44, 27), S(54, 54), S(116, 142), S(399, 92),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-83, -133), S(-80, -111), S(-59, 1), S(-2, 108), S(80, 255), S(224, 311),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -45), S(34, -5), S(22, 31), S(1, 109), S(49, 219), S(203, 282),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(23, -38), S(3, 11), S(3, -21), S(-1, -53), S(-9, -125), S(-212, -231),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-1, 155), S(-12, 119), S(-8, 51), S(-1, 15), S(4, 14), S(39, 13), S(14, 6),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-297, -48), S(-34, 32), S(-17, 66), S(20, 102), S(39, 119), S(56, 120), S(38, 112),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-171, -261), S(-99, -91), S(-64, -2), S(-37, 35), S(3, 53), S(28, 87), S(60, 85), S(91, 99), S(143, 13),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-121, -268), S(-78, -94), S(-24, -31), S(3, 14), S(28, 47), S(44, 71), S(51, 91), S(65, 100), S(70, 119), S(96, 100), S(106, 103), S(154, 51), S(152, 64), S(182, 13),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(73, -117), S(-8, 62), S(17, 87), S(34, 96), S(45, 109), S(51, 120), S(58, 130), S(67, 132), S(72, 143), S(84, 144), S(95, 146), S(103, 151), S(108, 150), S(125, 122), S(210, 19),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-83, -87), S(76, -133), S(100, -20), S(118, 92), S(134, 138), S(143, 183), S(149, 215), S(156, 225), S(160, 248), S(163, 263), S(169, 270), S(173, 278), S(183, 271), S(185, 276), S(190, 272), S(188, 276), S(191, 271), S(197, 264), S(203, 257), S(213, 249), S(221, 226), S(243, 187), S(241, 185), S(239, 131), S(228, 115), S(221, 85), S(161, 133), S(179, 47),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(362, -3), S(106, -107), S(27, -26), S(15, 6), S(-4, 5), S(-21, -2), S(-27, 8), S(-42, 15), S(-32, -25),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(24, -14), S(31, -27), S(27, -22), S(12, -14), S(5, -45),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(8, -1), S(14, -20), S(12, -16), S(10, -9), S(11, 133),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 91);
inline const PParam PAWN_THREAT_BISHOP = S(190, 142);
inline const PParam PAWN_THREAT_ROOK   = S(189, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(164, -13);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 68);
inline const PParam KNIGHT_THREAT_QUEEN  = S(149, 2);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 96);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -17), S(-9, -28), S(-13, -37), S(-18, -42), S(-20, -54), S(-27, -52), S(-39, -52),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(249, 260),    S(99, 361),     S(242, 331),    S(254, 195),    S(276, 151),    S(168, 235),    S(107, 271),    S(216, 224),    //
    S(42, 69),      S(72, 110),     S(112, 26),     S(97, -39),     S(78, -56),     S(51, -4),      S(23, 53),      S(-26, 79),     //
    S(5, 33),       S(-7, 35),      S(34, -39),     S(35, -61),     S(24, -64),     S(-4, -32),     S(-52, 17),     S(-64, 46),     //
    S(-18, -15),    S(-29, 8),      S(7, -44),      S(4, -53),      S(-17, -50),    S(-34, -25),    S(-94, 18),     S(-94, 11),     //
    S(-20, -41),    S(19, -33),     S(4, -3),       S(-2, -19),     S(-30, -23),    S(-53, -17),    S(-87, -0),     S(-95, -6),     //
    S(-7, -39),     S(83, -24),     S(68, 33),      S(19, 12),      S(-8, -1),      S(-29, -7),     S(-59, 5),      S(-77, 8),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-395, -237),  S(-297, 33),    S(-241, -117),  S(-49, 22),     S(-115, 26),    S(-255, 26),    S(-388, 76),    S(-434, -165),  //
    S(-70, -1),     S(-29, 27),     S(59, -14),     S(54, -5),      S(50, 2),       S(-35, 29),     S(-70, 42),     S(-96, 19),     //
    S(13, -3),      S(60, -7),      S(63, 48),      S(63, 34),      S(23, 69),      S(-37, 84),     S(-25, 28),     S(-59, 20),     //
    S(82, 19),      S(89, 39),      S(85, 64),      S(73, 95),      S(73, 102),     S(28, 89),      S(21, 56),      S(16, 27),      //
    S(66, 21),      S(101, 4),      S(70, 63),      S(66, 83),      S(42, 87),      S(41, 71),      S(38, 20),      S(1, 27),       //
    S(11, -14),     S(36, -2),      S(26, 36),      S(35, 62),      S(31, 61),      S(-5, 41),      S(-15, 9),      S(-44, -25),    //
    S(22, -9),      S(44, -12),     S(11, -3),      S(13, 21),      S(4, 19),       S(-23, -25),    S(-36, -4),     S(-48, -87),    //
    S(-42, -58),    S(3, 8),        S(19, -27),     S(35, -34),     S(15, -9),      S(-17, -38),    S(-32, -13),    S(-69, -92),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-162, 89),    S(-176, 100),   S(-433, 140),   S(-300, 78),    S(-314, 102),   S(-324, 97),    S(-209, 95),    S(-130, 69),    //
    S(-41, 2),      S(-98, 81),     S(-65, 36),     S(-119, 54),    S(-103, 52),    S(-78, 51),     S(-40, 47),     S(-65, 27),     //
    S(31, 30),      S(44, 43),      S(37, 51),      S(13, 52),      S(-16, 47),     S(-8, 55),      S(7, 46),       S(4, 18),       //
    S(1, 22),       S(35, 33),      S(37, 52),      S(34, 90),      S(63, 80),      S(-5, 56),      S(7, 20),       S(-34, 20),     //
    S(29, -20),     S(46, 13),      S(51, 37),      S(55, 65),      S(30, 80),      S(16, 57),      S(-16, 35),     S(-19, -9),     //
    S(55, -12),     S(89, 1),       S(100, 28),     S(45, 53),      S(42, 31),      S(36, 43),      S(43, 19),      S(-17, 17),     //
    S(21, -39),     S(122, -23),    S(79, -10),     S(46, 9),       S(26, 13),      S(30, -12),     S(30, -14),     S(23, -19),     //
    S(53, -38),     S(41, -22),     S(41, 13),      S(54, -24),     S(44, -14),     S(44, 29),      S(40, 8),       S(32, -15),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(193, 80),     S(205, 101),    S(181, 114),    S(200, 76),     S(179, 83),     S(148, 91),     S(141, 110),    S(137, 112),    //
    S(67, 166),     S(143, 163),    S(221, 126),    S(164, 134),    S(149, 143),    S(129, 147),    S(64, 176),     S(47, 183),     //
    S(36, 161),     S(137, 148),    S(196, 107),    S(174, 97),     S(126, 126),    S(84, 149),     S(88, 145),     S(21, 186),     //
    S(41, 120),     S(118, 130),    S(153, 104),    S(127, 108),    S(118, 119),    S(78, 141),     S(75, 135),     S(2, 162),      //
    S(23, 53),      S(88, 71),      S(77, 91),      S(56, 87),      S(32, 113),     S(23, 124),     S(-6, 117),     S(-27, 115),    //
    S(16, -6),      S(76, 24),      S(63, 49),      S(49, 47),      S(36, 55),      S(10, 78),      S(8, 53),       S(-27, 59),     //
    S(-91, 6),      S(41, -29),     S(52, 0),       S(41, 25),      S(26, 29),      S(19, 33),      S(-0, 20),      S(-24, 30),     //
    S(-26, -9),     S(-3, 11),      S(53, 2),       S(65, -1),      S(54, 7),       S(34, 22),      S(23, 18),      S(4, 27),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(165, 107),    S(215, 59),     S(138, 183),    S(107, 249),    S(92, 231),     S(127, 175),    S(147, 101),    S(99, 143),     //
    S(163, 167),    S(124, 266),    S(115, 295),    S(-26, 383),    S(-17, 370),    S(41, 328),     S(86, 202),     S(96, 186),     //
    S(127, 236),    S(173, 250),    S(105, 356),    S(60, 364),     S(32, 364),     S(84, 279),     S(117, 206),    S(136, 133),    //
    S(166, 151),    S(172, 233),    S(109, 303),    S(100, 334),    S(91, 334),     S(101, 242),    S(145, 176),    S(130, 143),    //
    S(179, 125),    S(167, 193),    S(138, 246),    S(108, 289),    S(106, 290),    S(109, 240),    S(126, 162),    S(154, 86),     //
    S(159, 66),     S(193, 118),    S(185, 183),    S(155, 176),    S(151, 164),    S(145, 191),    S(160, 112),    S(140, 83),     //
    S(140, -44),    S(178, -33),    S(182, 32),     S(193, 71),     S(180, 99),     S(174, 64),     S(136, 105),    S(147, 82),     //
    S(122, -31),    S(154, -181),   S(178, -162),   S(191, -49),    S(187, 23),     S(186, -32),    S(174, -5),     S(143, 25),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-93, -317),   S(269, 177),    S(146, 134),    S(8, -27),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(211, -65),    S(338, 154),    S(196, 145),    S(108, 0),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(213, 28),     S(373, 100),    S(261, 99),     S(152, 1),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(70, -5),      S(324, 38),     S(174, 57),     S(105, 23),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-33, -28),    S(222, 4),      S(151, 9),      S(28, 21),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-32, -18),    S(203, -6),     S(109, 1),      S(48, -12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-13, -17),    S(74, 34),      S(-8, 31),      S(-71, 9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-126, -68),   S(-28, -21),    S(-127, -19),   S(-132, -90),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(35, -23), S(-3, 43), S(-10, 45), S(5, 19), S(5, 13), S(-9, 44), S(1, 44), }},
  {{ S(17, -7), S(-38, 53), S(-30, 43), S(-11, 9), S(-11, 10), S(-29, 51), S(-36, 66), }},
  {{ S(5, -6), S(-18, 41), S(-14, 7), S(-6, -18), S(-5, -16), S(-13, 7), S(-15, 35), }},
  {{ S(6, -16), S(-29, -18), S(-12, -23), S(-2, -30), S(-4, -27), S(-14, -19), S(-20, -20), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(23, 37), S(-19, 42), S(-14, 24), S(1, 5), S(2, -25),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(9, -5), S(-12, 11), S(-9, 7), S(-7, 7), S(-7, -4), S(-5, -9), S(-12, 8), }},
  {{ S(10, -6), S(-6, 7), S(-19, 16), S(-13, 8), S(-12, 2), S(-17, 10), S(-5, 5), }},
  {{ S(-2, -2), S(-12, -3), S(-13, 7), S(-5, 6), S(-4, 4), S(-12, 4), S(-11, -2), }},
  {{ S(-2, -0), S(-13, 4), S(-14, 2), S(-5, 9), S(-1, 10), S(-13, 3), S(-16, 3), }},
}};
inline TunableSigmoid<64> KING_SAFETY_ACTIVATION(
        1182, 600, -150, 133
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(225);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 7.67733s
// clang-format on
}  // namespace Clockwork
