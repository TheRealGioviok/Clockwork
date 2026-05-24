#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(194, 483);
inline const PParam KNIGHT_MAT = S(804, 1521);
inline const PParam BISHOP_MAT = S(840, 1615);
inline const PParam ROOK_MAT   = S(1016, 2562);
inline const PParam QUEEN_MAT  = S(2375, 3860);
inline const PParam TEMPO_VAL  = S(61, 26);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 13);
inline const PParam BISHOP_PAIR_VAL   = S(63, 228);
inline const PParam ROOK_OPEN_VAL     = S(118, -10);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 37);
inline const PParam MINOR_BEHIND_PAWN = S(17, 40);
inline const PParam RESTRICTED_SQUARES = S(-24, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -77);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(57, 55);
inline const PParam OUTPOST_BISHOP_VAL    = S(55, 45);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 10);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(38, -2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(21, 61);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(12, -3), S(34, 44), S(65, 83), S(117, 223), S(331, 288), S(535, 568),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(45, 44), S(44, 42), S(64, 85), S(101, 221), S(347, 149),
};
inline const std::array<PParam, 6> BACKWARD_PAWN = {
    S(-7, 1), S(9, 12), S(6, 17), S(-8, 22), S(-116, -46), S(-100, -176),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-75, -245), S(-71, -207), S(-50, -67), S(-18, 76), S(-11, 200), S(218, 395),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -41), S(25, -9), S(16, 30), S(17, 107), S(83, 233), S(145, 431),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(20, -36), S(0, 4), S(-9, -35), S(7, -74), S(111, -122), S(-72, -154),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(10, 219), S(-8, 172), S(-10, 95), S(-0, 54), S(13, 55), S(52, 53), S(41, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-122, -161), S(13, 10), S(-4, 103), S(20, 151), S(31, 187), S(43, 193), S(28, 173),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-87, -367), S(-27, -147), S(1, -30), S(25, 15), S(53, 42), S(68, 80), S(86, 86), S(105, 96), S(124, 45),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-57, -288), S(-10, -124), S(38, -53), S(60, 1), S(82, 43), S(94, 71), S(100, 95), S(105, 112), S(108, 123), S(113, 126), S(121, 115), S(135, 94), S(135, 97), S(114, 63),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(108, -191), S(25, -12), S(45, 21), S(62, 35), S(72, 53), S(76, 67), S(81, 81), S(88, 85), S(93, 97), S(101, 101), S(108, 105), S(111, 111), S(109, 116), S(110, 100), S(136, 46),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-213, -133), S(-66, -27), S(-39, 93), S(-18, 215), S(-3, 257), S(4, 309), S(11, 341), S(16, 358), S(20, 382), S(22, 401), S(27, 409), S(30, 418), S(32, 424), S(32, 431), S(32, 432), S(26, 440), S(21, 440), S(23, 430), S(22, 426), S(25, 417), S(19, 403), S(22, 379), S(-8, 404), S(-51, 388), S(-85, 395), S(-121, 416), S(-164, 429), S(-137, 353),
};

inline const PParam PAWN_THREAT_KNIGHT = S(199, 143);
inline const PParam PAWN_THREAT_BISHOP = S(185, 194);
inline const PParam PAWN_THREAT_ROOK   = S(202, 149);
inline const PParam PAWN_THREAT_QUEEN  = S(170, 23);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 126);
inline const PParam KNIGHT_THREAT_ROOK   = S(223, 97);
inline const PParam KNIGHT_THREAT_QUEEN  = S(163, -25);

inline const PParam BISHOP_THREAT_KNIGHT = S(97, 80);
inline const PParam BISHOP_THREAT_ROOK   = S(209, 163);
inline const PParam BISHOP_THREAT_QUEEN  = S(181, 91);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -20), S(3, -18), S(-1, -24), S(-6, -33), S(-11, -41), S(-16, -47), S(-18, -59), S(-23, -61), S(-27, -76),
};

inline const PParam ROOK_LINEUP = S(17, 75);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(186, 263),    S(38, 367),     S(67, 345),     S(134, 249),    S(192, 153),    S(122, 215),    S(84, 259),     S(225, 207),    //
    S(134, 97),     S(134, 139),    S(116, 82),     S(126, 11),     S(123, -25),    S(97, 16),      S(93, 69),      S(75, 98),      //
    S(30, -36),     S(2, -28),      S(33, -72),     S(20, -95),     S(11, -114),    S(-9, -98),     S(-44, -63),    S(-45, -23),    //
    S(-22, -83),    S(-45, -50),    S(-11, -72),    S(-21, -83),    S(-41, -95),    S(-50, -84),    S(-97, -63),    S(-89, -63),    //
    S(-24, -109),   S(10, -108),    S(-1, -47),     S(-19, -54),    S(-45, -66),    S(-59, -74),    S(-89, -72),    S(-91, -78),    //
    S(2, -101),     S(77, -91),     S(66, -39),     S(19, -14),     S(-10, -38),    S(-30, -58),    S(-54, -56),    S(-67, -57),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-264, -514),  S(-284, 62),    S(-303, -80),   S(-9, 27),      S(-112, 41),    S(-282, 74),    S(-408, 125),   S(-357, -380),  //
    S(-27, -22),    S(-20, 29),     S(80, -0),      S(62, 46),      S(77, 29),      S(37, 12),      S(-31, 23),     S(-47, 3),      //
    S(32, -25),     S(31, 22),      S(73, 54),      S(79, 73),      S(71, 76),      S(25, 69),      S(9, 17),       S(-46, 14),     //
    S(94, 19),      S(97, 51),      S(106, 69),     S(110, 109),    S(115, 104),    S(81, 75),      S(56, 43),      S(36, 29),      //
    S(70, 12),      S(104, 3),      S(100, 55),     S(90, 78),      S(78, 76),      S(78, 66),      S(61, 12),      S(19, 23),      //
    S(15, -43),     S(45, -14),     S(49, 23),      S(62, 54),      S(56, 49),      S(30, 17),      S(18, -9),      S(-26, -47),    //
    S(35, -32),     S(41, -25),     S(23, -23),     S(31, 0),       S(27, -2),      S(2, -51),      S(-31, -9),     S(-39, -115),   //
    S(-44, -87),    S(8, -36),      S(29, -57),     S(47, -45),     S(28, -26),     S(-8, -61),     S(-19, -36),    S(-63, -142),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-124, 13),    S(-185, 116),   S(-479, 213),   S(-300, 104),   S(-325, 152),   S(-328, 160),   S(-216, 130),   S(-126, 51),    //
    S(-46, -21),    S(-98, 95),     S(-53, 51),     S(-103, 76),    S(-88, 69),     S(-48, 42),     S(-26, 36),     S(-57, 16),     //
    S(29, 15),      S(7, 68),       S(23, 70),      S(19, 61),      S(12, 43),      S(10, 46),      S(6, 51),       S(10, 4),       //
    S(9, -2),       S(52, 16),      S(62, 43),      S(76, 66),      S(106, 51),     S(46, 28),      S(48, -8),      S(-1, -9),      //
    S(49, -59),     S(47, -3),      S(81, 13),      S(96, 31),      S(81, 46),      S(71, 23),      S(22, 4),       S(18, -37),     //
    S(63, -37),     S(88, -26),     S(101, 4),      S(71, 29),      S(67, 8),       S(65, 15),      S(75, -9),      S(23, -22),     //
    S(34, -92),     S(117, -66),    S(74, -29),     S(52, -13),     S(36, -10),     S(54, -51),     S(53, -60),     S(47, -66),     //
    S(53, -89),     S(24, -26),     S(29, -12),     S(54, -38),     S(37, -32),     S(43, 5),       S(52, -28),     S(47, -65),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(199, 82),     S(229, 95),     S(172, 123),    S(166, 94),     S(228, 52),     S(185, 79),     S(210, 84),     S(188, 94),     //
    S(96, 160),     S(167, 148),    S(232, 112),    S(174, 126),    S(218, 112),    S(176, 134),    S(117, 159),    S(105, 162),    //
    S(61, 152),     S(198, 95),     S(218, 83),     S(205, 57),     S(200, 83),     S(138, 125),    S(141, 127),    S(73, 176),     //
    S(34, 116),     S(107, 128),    S(134, 98),     S(111, 99),     S(142, 86),     S(101, 131),    S(94, 138),     S(27, 160),     //
    S(2, 44),       S(78, 52),      S(65, 72),      S(39, 71),      S(49, 80),      S(37, 108),     S(13, 109),     S(-7, 107),     //
    S(10, -39),     S(89, -20),     S(75, 5),       S(52, 8),       S(65, 10),      S(35, 47),      S(41, 27),      S(-7, 39),      //
    S(-77, -42),    S(59, -86),     S(59, -48),     S(47, -14),     S(53, -17),     S(38, -3),      S(28, -19),     S(-2, -12),     //
    S(-16, -74),    S(-2, -34),     S(68, -52),     S(76, -51),     S(77, -42),     S(57, -19),     S(56, -33),     S(38, -25),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(28, 183),     S(126, 122),    S(32, 265),     S(-34, 376),    S(8, 329),      S(42, 236),     S(42, 156),     S(-29, 215),    //
    S(41, 180),     S(49, 252),     S(11, 328),     S(-133, 462),   S(-77, 427),    S(-24, 323),    S(26, 180),     S(7, 167),      //
    S(-7, 241),     S(24, 289),     S(-10, 369),    S(-53, 413),    S(-31, 396),    S(17, 286),     S(53, 173),     S(47, 104),     //
    S(14, 144),     S(2, 255),      S(-31, 317),    S(-53, 397),    S(-34, 399),    S(3, 261),      S(47, 157),     S(24, 120),     //
    S(5, 127),      S(-5, 171),     S(-20, 236),    S(-41, 305),    S(-26, 329),    S(-2, 249),     S(7, 169),      S(34, 73),      //
    S(6, 27),       S(28, 51),      S(22, 138),     S(-2, 162),     S(9, 168),      S(12, 199),     S(35, 122),     S(25, 77),      //
    S(-23, -128),   S(7, -113),     S(8, -28),      S(32, 10),      S(26, 56),      S(31, 29),      S(5, 62),       S(21, 38),      //
    S(-34, -107),   S(-17, -256),   S(12, -256),    S(28, -146),    S(35, -64),     S(37, -96),     S(34, -67),     S(7, -24),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(131, -582),   S(469, 20),     S(288, 174),    S(21, 133),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(329, -159),   S(346, 145),    S(181, 200),    S(14, 153),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(166, 70),     S(187, 207),    S(93, 226),     S(-41, 183),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-6, 29),      S(62, 156),     S(-42, 191),    S(-95, 199),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-123, 4),     S(-45, 92),     S(-108, 155),   S(-179, 196),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-49, -36),    S(8, 38),       S(-75, 115),    S(-121, 155),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -92),     S(28, -11),     S(-33, 50),     S(-104, 99),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -199),   S(4, -85),      S(-76, -25),    S(-69, -49),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-97, -441);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -7), S(9, 10), S(10, 4), S(4, 0), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(4, 3), S(2, 2), S(3, -0), S(3, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -19), S(-6, 4), S(-2, -9), S(9, -17), S(14, -30), S(8, -55), S(-3, -46), }},
  {{ S(1, 2), S(-21, 3), S(-17, 9), S(-9, 16), S(-7, 7), S(-9, -19), S(-19, -26), }},
  {{ S(-2, -3), S(-10, -10), S(-12, 17), S(-7, 17), S(-6, 9), S(-7, -20), S(-22, -41), }},
  {{ S(7, 5), S(-9, 15), S(-6, 35), S(-1, 40), S(-2, 35), S(6, 9), S(11, -21), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, 26), S(-3, 4), S(-6, 9), S(-5, 27), S(2, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(7, 10), S(-44, -150), S(-12, -52), S(1, 3), S(-0, 3), S(-4, 10), S(-4, 8), }},
  {{ S(11, -1), S(-26, -168), S(-7, -36), S(-2, 0), S(1, -4), S(-5, 3), S(3, 1), }},
  {{ S(1, 9), S(-10, -90), S(6, -21), S(1, 9), S(-2, 10), S(-8, 17), S(-4, 19), }},
  {{ S(3, 1), S(4, -63), S(-3, 29), S(-2, 26), S(-5, 10), S(-11, 12), S(-9, 20), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1412, 890, -18, -4
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(82);
inline VParam WINNABLE_PAWN_ENDGAME = V(105);
inline VParam WINNABLE_BIAS = V(-364);

// Epoch duration: 7.56631s
// clang-format on
}  // namespace Clockwork
