#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(190, 451);
inline const PParam KNIGHT_MAT = S(850, 1363);
inline const PParam BISHOP_MAT = S(891, 1442);
inline const PParam ROOK_MAT   = S(1067, 2334);
inline const PParam QUEEN_MAT  = S(2583, 3691);
inline const PParam TEMPO_VAL  = S(63, 22);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 15);
inline const PParam BISHOP_PAIR_VAL   = S(56, 227);
inline const PParam ROOK_OPEN_VAL     = S(122, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 34);
inline const PParam MINOR_BEHIND_PAWN = S(14, 43);
inline const PParam RESTRICTED_SQUARES = S(-24, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -65);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -28);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(56, 57);
inline const PParam OUTPOST_BISHOP_VAL    = S(59, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(45, -16);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(21, 56);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, 3), S(32, 36), S(61, 62), S(133, 175), S(450, 239), S(568, 599),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(44, 47), S(42, 40), S(60, 58), S(89, 140), S(344, 206),
};
inline const std::array<std::array<PParam, 6>, 2> PASSED_PAWN = {{
  {{ S(-108, -224), S(-122, -178), S(-96, -67), S(-48, 44), S(84, 212), S(223, 329), }},
  {{ S(0, 0), S(-74, -254), S(-48, -109), S(4, 52), S(183, 235), S(344, 205), }},
}};
inline const std::array<std::array<PParam, 6>, 2> CANDIDATE_PASSED_PAWN = {{
  {{ S(-23, -14), S(-11, -27), S(20, -1), S(35, 28), S(99, 58), S(0, 0), }},
  {{ S(0, 0), S(-62, 6), S(-22, 30), S(-1, 70), S(146, 124), S(0, 0), }},
}};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(29, -49), S(23, -4), S(15, 35), S(13, 115), S(82, 229), S(176, 389),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(6, -1), S(3, 30), S(-6, -5), S(-5, -41), S(-16, -133), S(-218, -262),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(16, 223), S(-12, 194), S(-3, 107), S(11, 60), S(23, 59), S(70, 52), S(55, 39),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-210, -59), S(4, 36), S(2, 110), S(39, 140), S(55, 171), S(68, 177), S(41, 174),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-97, -326), S(-34, -124), S(-3, -19), S(23, 18), S(54, 39), S(70, 74), S(91, 74), S(110, 83), S(143, 8),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-64, -275), S(-14, -119), S(37, -54), S(59, -2), S(82, 36), S(94, 64), S(100, 86), S(107, 99), S(107, 115), S(119, 106), S(123, 104), S(160, 51), S(165, 46), S(183, -25),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(116, -189), S(24, -11), S(46, 19), S(62, 32), S(73, 48), S(77, 60), S(83, 73), S(89, 76), S(94, 87), S(102, 92), S(110, 95), S(112, 100), S(113, 103), S(119, 80), S(192, -31),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-190, -131), S(-41, -39), S(-14, 81), S(8, 197), S(24, 233), S(32, 280), S(38, 312), S(45, 325), S(48, 349), S(51, 365), S(55, 373), S(58, 382), S(62, 383), S(63, 385), S(63, 387), S(60, 388), S(55, 389), S(59, 374), S(61, 366), S(65, 353), S(66, 329), S(78, 294), S(56, 306), S(28, 275), S(6, 263), S(-16, 252), S(-58, 256), S(-58, 208),
};

inline const PParam PAWN_THREAT_KNIGHT = S(208, 121);
inline const PParam PAWN_THREAT_BISHOP = S(191, 179);
inline const PParam PAWN_THREAT_ROOK   = S(210, 129);
inline const PParam PAWN_THREAT_QUEEN  = S(177, 5);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 118);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 89);
inline const PParam KNIGHT_THREAT_QUEEN  = S(161, -6);

inline const PParam BISHOP_THREAT_KNIGHT = S(99, 75);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 151);
inline const PParam BISHOP_THREAT_QUEEN  = S(178, 99);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -28), S(0, -10), S(-2, -20), S(-6, -30), S(-11, -40), S(-15, -48), S(-16, -60), S(-21, -62), S(-27, -72),
};

inline const PParam ROOK_LINEUP = S(17, 73);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(221, 223),    S(66, 324),     S(142, 276),    S(168, 207),    S(207, 135),    S(122, 216),    S(86, 255),     S(234, 190),    //
    S(24, 49),      S(25, 92),      S(17, 25),      S(17, -47),     S(10, -78),     S(-19, -18),    S(-27, 39),     S(-41, 62),     //
    S(25, -20),     S(7, -14),      S(32, -59),     S(22, -87),     S(13, -101),    S(-12, -73),    S(-51, -26),    S(-53, 7),      //
    S(-10, -80),    S(-31, -55),    S(0, -74),      S(-8, -83),     S(-29, -89),    S(-42, -69),    S(-95, -38),    S(-87, -43),    //
    S(-8, -116),    S(28, -118),    S(12, -53),     S(-4, -60),     S(-31, -71),    S(-50, -67),    S(-83, -57),    S(-87, -63),    //
    S(11, -111),    S(91, -109),    S(70, -55),     S(27, -21),     S(-1, -46),     S(-23, -58),    S(-53, -44),    S(-67, -46),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-282, -451),  S(-270, 32),    S(-296, -84),   S(18, 20),      S(-89, 37),     S(-258, 50),    S(-392, 96),    S(-374, -331),  //
    S(-31, -16),    S(-20, 26),     S(86, 2),       S(87, 37),      S(98, 27),      S(36, 20),      S(-31, 21),     S(-44, -6),     //
    S(42, -36),     S(40, 12),      S(78, 56),      S(88, 74),      S(71, 85),      S(19, 81),      S(5, 21),       S(-41, 5),      //
    S(101, 10),     S(102, 45),     S(110, 68),     S(114, 107),    S(118, 105),    S(78, 84),      S(55, 43),      S(38, 23),      //
    S(76, 4),       S(113, -5),     S(103, 54),     S(90, 81),      S(78, 79),      S(76, 68),      S(65, 8),       S(21, 17),      //
    S(18, -52),     S(44, -17),     S(43, 25),      S(58, 55),      S(51, 52),      S(24, 23),      S(14, -6),      S(-28, -48),    //
    S(35, -36),     S(39, -27),     S(21, -27),     S(26, 1),       S(23, -0),      S(-1, -51),     S(-30, -18),    S(-37, -120),   //
    S(-38, -99),    S(11, -43),     S(30, -65),     S(47, -55),     S(29, -36),     S(-9, -66),     S(-20, -40),    S(-61, -145),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-129, 19),    S(-182, 99),    S(-484, 187),   S(-304, 104),   S(-313, 125),   S(-319, 121),   S(-209, 102),   S(-133, 52),    //
    S(-51, -12),    S(-98, 86),     S(-48, 36),     S(-99, 71),     S(-85, 60),     S(-45, 29),     S(-26, 28),     S(-52, -1),     //
    S(34, 11),      S(19, 43),      S(31, 53),      S(24, 50),      S(14, 35),      S(10, 38),      S(16, 28),      S(17, -7),      //
    S(12, -9),      S(52, 11),      S(70, 29),      S(77, 65),      S(103, 54),     S(49, 22),      S(47, -8),      S(-0, -10),     //
    S(52, -61),     S(53, -12),     S(83, 7),       S(96, 35),      S(83, 45),      S(71, 26),      S(23, 4),       S(20, -39),     //
    S(65, -37),     S(90, -32),     S(103, 0),      S(73, 25),      S(69, 7),       S(67, 15),      S(75, -7),      S(23, -22),     //
    S(41, -96),     S(118, -63),    S(77, -34),     S(52, -13),     S(37, -11),     S(56, -51),     S(54, -56),     S(49, -65),     //
    S(58, -92),     S(35, -45),     S(30, -13),     S(52, -39),     S(37, -32),     S(42, 5),       S(53, -30),     S(49, -63),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(192, 86),     S(235, 83),     S(185, 104),    S(168, 85),     S(227, 57),     S(179, 84),     S(202, 93),     S(181, 104),    //
    S(91, 160),     S(157, 157),    S(234, 109),    S(168, 133),    S(214, 119),    S(175, 134),    S(112, 165),    S(101, 166),    //
    S(57, 151),     S(187, 106),    S(220, 82),     S(200, 66),     S(193, 93),     S(130, 136),    S(134, 136),    S(70, 177),     //
    S(31, 109),     S(106, 122),    S(135, 94),     S(108, 97),     S(144, 81),     S(99, 128),     S(94, 131),     S(26, 152),     //
    S(1, 35),       S(78, 49),      S(66, 66),      S(34, 70),      S(46, 78),      S(36, 105),     S(16, 99),      S(-5, 96),      //
    S(16, -51),     S(95, -29),     S(77, -5),      S(56, -3),      S(66, 6),       S(38, 39),      S(47, 16),      S(-1, 25),      //
    S(-74, -51),    S(68, -91),     S(65, -55),     S(52, -24),     S(56, -22),     S(41, -9),      S(34, -28),     S(2, -19),      //
    S(-12, -77),    S(5, -44),      S(70, -56),     S(80, -59),     S(80, -47),     S(59, -24),     S(59, -36),     S(40, -30),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(47, 148),     S(157, 66),     S(67, 180),     S(11, 265),     S(51, 224),     S(73, 169),     S(67, 113),     S(-7, 175),     //
    S(49, 183),     S(55, 261),     S(34, 276),     S(-106, 375),   S(-55, 364),    S(-6, 290),     S(35, 186),     S(12, 180),     //
    S(19, 200),     S(43, 271),     S(10, 324),     S(-25, 341),    S(-9, 337),     S(35, 265),     S(66, 178),     S(63, 103),     //
    S(40, 96),      S(29, 201),     S(-15, 274),    S(-33, 340),    S(-16, 357),    S(20, 232),     S(64, 148),     S(36, 128),     //
    S(26, 90),      S(16, 134),     S(-2, 194),     S(-27, 269),    S(-14, 304),    S(8, 241),      S(19, 163),     S(45, 82),      //
    S(27, 3),       S(42, 37),      S(37, 120),     S(13, 141),     S(20, 165),     S(22, 198),     S(42, 135),     S(37, 75),      //
    S(-5, -128),    S(20, -83),     S(20, -17),     S(45, 15),      S(38, 66),      S(40, 46),      S(15, 71),      S(34, 37),      //
    S(-15, -117),   S(5, -259),     S(26, -237),    S(40, -126),    S(42, -28),     S(48, -80),     S(44, -50),     S(19, -15),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(34, -301),    S(323, 301),    S(207, 325),    S(-20, 224),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(245, -2),     S(269, 277),    S(119, 312),    S(-9, 208),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(143, 120),    S(170, 237),    S(64, 273),     S(-59, 223),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-31, 62),     S(63, 155),     S(-80, 232),    S(-141, 244),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-102, -16),   S(-42, 76),     S(-129, 154),   S(-233, 222),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -67),    S(30, -0),      S(-86, 96),     S(-157, 157),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, -125),    S(46, -48),     S(-34, 13),     S(-111, 73),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-5, -224),    S(20, -119),    S(-74, -62),    S(-58, -86),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-84, -530);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -6), S(14, -24), S(14, -2), S(6, -8), S(1, -26),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -11), S(6, -24), S(4, -13), S(4, -0), S(4, 4),
};

inline const PParam KS_FLANK_ATTACK = S(4, -8);
inline const PParam KS_FLANK_DEFENSE = S(-5, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -5);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -8);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, 28), S(-6, 25), S(-5, -50), S(6, -33), S(7, -21), S(-10, 14), S(-22, 13), }},
  {{ S(-2, 125), S(-20, -261), S(-19, -56), S(-8, 29), S(-8, 58), S(-21, 94), S(-37, 93), }},
  {{ S(-5, 106), S(-10, -223), S(-10, 101), S(-4, 73), S(-4, 64), S(-14, 71), S(-39, 63), }},
  {{ S(4, 118), S(-11, 79), S(-1, 89), S(5, 71), S(2, 58), S(5, 73), S(1, 71), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(17, 131), S(-7, 78), S(-10, 97), S(-3, 111), S(11, 73),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 142), S(-53, -431), S(-15, -369), S(8, -364), S(-5, 63), S(-8, 87), S(-8, 88), }},
  {{ S(8, 56), S(-27, -495), S(-2, -497), S(-3, -28), S(-2, 15), S(-9, 40), S(0, 38), }},
  {{ S(-0, 82), S(-10, -433), S(1, -3), S(2, 14), S(-3, 41), S(-9, 62), S(-4, 57), }},
  {{ S(-1, 72), S(-2, -152), S(4, -10), S(4, 32), S(-6, 48), S(-13, 58), S(-9, 61), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1145, 290, -14, 68
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(122);
inline VParam WINNABLE_ASYM = V(108);
inline VParam WINNABLE_PAWN_ENDGAME = V(185);
inline VParam WINNABLE_BIAS = V(-506);

// Epoch duration: 6.66415s
// clang-format on
}  // namespace Clockwork
