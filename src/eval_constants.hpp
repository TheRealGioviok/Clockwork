#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(192, 452);
inline const PParam KNIGHT_MAT = S(853, 1342);
inline const PParam BISHOP_MAT = S(898, 1420);
inline const PParam ROOK_MAT   = S(1077, 2308);
inline const PParam QUEEN_MAT  = S(2445, 3508);
inline const PParam TEMPO_VAL  = S(63, 22);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, 14);
inline const PParam BISHOP_PAIR_VAL   = S(57, 225);
inline const PParam ROOK_OPEN_VAL     = S(120, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 32);
inline const PParam MINOR_BEHIND_PAWN = S(14, 43);
inline const PParam RESTRICTED_SQUARES = S(-24, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-17, -80);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -27);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -32);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 58);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(44, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(59, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -2), S(28, 33), S(60, 59), S(132, 174), S(444, 231), S(562, 609),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(45, 42), S(43, 36), S(64, 64), S(118, 169), S(452, 93),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-92, -243), S(-89, -207), S(-69, -79), S(-25, 44), S(75, 217), S(233, 334),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -43), S(20, -0), S(11, 39), S(6, 121), S(74, 239), S(151, 404),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -28), S(5, 14), S(-5, -17), S(-3, -45), S(-17, -140), S(-193, -287),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(11, 221), S(-10, 180), S(-5, 99), S(7, 57), S(20, 57), S(59, 54), S(46, 44),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-173, -100), S(5, 27), S(3, 102), S(31, 143), S(44, 174), S(58, 179), S(34, 175),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-93, -326), S(-30, -130), S(0, -23), S(25, 15), S(56, 36), S(72, 70), S(93, 69), S(113, 76), S(148, -3),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-62, -272), S(-15, -118), S(36, -55), S(57, -2), S(80, 35), S(93, 62), S(99, 83), S(106, 95), S(107, 110), S(118, 100), S(124, 93), S(162, 40), S(167, 33), S(188, -43),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(111, -186), S(24, -15), S(45, 16), S(62, 28), S(73, 45), S(77, 57), S(83, 70), S(89, 74), S(94, 85), S(102, 90), S(110, 93), S(113, 97), S(114, 98), S(122, 72), S(194, -36),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-194, -147), S(-43, -63), S(-16, 51), S(5, 169), S(21, 208), S(28, 257), S(34, 289), S(40, 304), S(44, 328), S(46, 346), S(51, 354), S(53, 364), S(56, 367), S(57, 373), S(55, 377), S(51, 382), S(46, 383), S(48, 374), S(47, 370), S(51, 360), S(50, 339), S(64, 302), S(37, 327), S(15, 288), S(2, 267), S(-23, 267), S(-57, 270), S(-48, 215),
};

inline const PParam PAWN_THREAT_KNIGHT = S(208, 122);
inline const PParam PAWN_THREAT_BISHOP = S(191, 174);
inline const PParam PAWN_THREAT_ROOK   = S(209, 131);
inline const PParam PAWN_THREAT_QUEEN  = S(175, 15);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 116);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 87);
inline const PParam KNIGHT_THREAT_QUEEN  = S(161, -19);

inline const PParam BISHOP_THREAT_KNIGHT = S(100, 72);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 152);
inline const PParam BISHOP_THREAT_QUEEN  = S(180, 96);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -26), S(-0, -8), S(-3, -17), S(-7, -28), S(-11, -38), S(-16, -45), S(-17, -58), S(-23, -59), S(-29, -70),
};

inline const PParam ROOK_LINEUP = S(15, 76);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(207, 219),    S(65, 314),     S(93, 294),     S(141, 218),    S(195, 133),    S(115, 207),    S(82, 245),     S(225, 187),    //
    S(35, 41),      S(45, 79),      S(27, 22),      S(43, -50),     S(36, -83),     S(1, -34),      S(-7, 21),      S(-30, 49),     //
    S(27, -22),     S(3, -11),      S(35, -59),     S(22, -83),     S(12, -100),    S(-11, -79),    S(-49, -37),    S(-52, -4),     //
    S(-15, -74),    S(-38, -40),    S(0, -68),      S(-9, -79),     S(-31, -88),    S(-42, -75),    S(-96, -43),    S(-86, -49),    //
    S(-15, -104),   S(21, -103),    S(10, -50),     S(-6, -57),     S(-33, -68),    S(-50, -71),    S(-84, -60),    S(-87, -67),    //
    S(10, -100),    S(85, -88),     S(73, -45),     S(26, -20),     S(-2, -44),     S(-22, -62),    S(-52, -47),    S(-65, -50),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-287, -450),  S(-270, 34),    S(-311, -75),   S(6, 11),       S(-99, 28),     S(-266, 48),    S(-400, 102),   S(-381, -327),  //
    S(-27, -23),    S(-13, 19),     S(88, -9),      S(80, 25),      S(89, 17),      S(40, 9),       S(-26, 13),     S(-43, -6),     //
    S(42, -37),     S(45, 2),       S(83, 44),      S(87, 63),      S(71, 77),      S(21, 75),      S(13, 11),      S(-37, -1),     //
    S(100, 5),      S(105, 34),     S(112, 58),     S(116, 95),     S(118, 95),     S(80, 75),      S(59, 35),      S(39, 20),      //
    S(76, 2),       S(114, -13),    S(104, 47),     S(91, 73),      S(78, 73),      S(77, 66),      S(66, 3),       S(22, 16),      //
    S(16, -43),     S(47, -15),     S(46, 29),      S(61, 53),      S(54, 53),      S(25, 27),      S(17, -6),      S(-27, -45),    //
    S(38, -37),     S(44, -30),     S(23, -21),     S(28, 5),       S(25, 3),       S(1, -47),      S(-29, -15),    S(-37, -113),   //
    S(-41, -92),    S(7, -34),      S(32, -60),     S(50, -48),     S(30, -28),     S(-7, -61),     S(-20, -33),    S(-62, -138),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-134, 22),    S(-178, 92),    S(-493, 188),   S(-306, 94),    S(-317, 120),   S(-324, 123),   S(-209, 104),   S(-136, 60),    //
    S(-48, -16),    S(-91, 77),     S(-43, 28),     S(-97, 59),     S(-83, 50),     S(-46, 33),     S(-25, 28),     S(-50, 2),      //
    S(34, 10),      S(21, 40),      S(33, 50),      S(25, 43),      S(18, 30),      S(11, 39),      S(17, 29),      S(15, -3),      //
    S(13, -13),     S(55, 6),       S(68, 26),      S(75, 62),      S(102, 51),     S(48, 20),      S(48, -10),     S(-0, -12),     //
    S(56, -66),     S(53, -15),     S(84, 5),       S(94, 31),      S(79, 46),      S(70, 23),      S(23, 3),       S(20, -39),     //
    S(66, -39),     S(93, -32),     S(105, -2),     S(74, 23),      S(68, 6),       S(67, 13),      S(75, -9),      S(24, -27),     //
    S(42, -101),    S(121, -67),    S(80, -34),     S(53, -13),     S(38, -11),     S(56, -51),     S(54, -58),     S(50, -69),     //
    S(57, -91),     S(30, -36),     S(30, -13),     S(57, -39),     S(38, -30),     S(44, 4),       S(53, -29),     S(49, -65),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(197, 80),     S(237, 76),     S(187, 94),     S(177, 71),     S(232, 45),     S(187, 69),     S(205, 82),     S(182, 96),     //
    S(97, 152),     S(161, 148),    S(237, 98),     S(170, 123),    S(216, 108),    S(180, 122),    S(115, 155),    S(103, 160),    //
    S(60, 147),     S(190, 100),    S(222, 73),     S(204, 55),     S(201, 79),     S(138, 120),    S(138, 126),    S(72, 172),     //
    S(32, 108),     S(109, 116),    S(138, 85),     S(115, 86),     S(146, 76),     S(103, 121),    S(95, 128),     S(23, 154),     //
    S(4, 34),       S(81, 46),      S(69, 60),      S(40, 63),      S(51, 72),      S(39, 100),     S(15, 99),      S(-7, 97),      //
    S(14, -43),     S(92, -23),     S(80, -4),      S(57, 0),       S(67, 7),       S(39, 40),      S(44, 20),      S(-5, 32),      //
    S(-76, -42),    S(62, -86),     S(63, -50),     S(51, -20),     S(56, -20),     S(41, -9),      S(32, -25),     S(-1, -13),     //
    S(-17, -68),    S(-2, -32),     S(69, -51),     S(79, -52),     S(79, -40),     S(58, -18),     S(56, -30),     S(37, -23),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(44, 149),     S(150, 80),     S(51, 226),     S(-8, 321),     S(32, 277),     S(64, 193),     S(60, 123),     S(-19, 189),    //
    S(53, 160),     S(60, 233),     S(25, 298),     S(-124, 429),   S(-71, 403),    S(-17, 304),    S(34, 165),     S(15, 150),     //
    S(13, 203),     S(41, 260),     S(-5, 356),     S(-43, 385),    S(-23, 375),    S(24, 272),     S(61, 162),     S(59, 85),      //
    S(32, 108),     S(17, 220),     S(-22, 295),    S(-45, 371),    S(-28, 379),    S(11, 241),     S(56, 139),     S(33, 102),     //
    S(21, 101),     S(11, 140),     S(-6, 204),     S(-32, 278),    S(-22, 312),    S(6, 230),      S(15, 153),     S(44, 56),      //
    S(23, -1),      S(43, 29),      S(35, 113),     S(11, 137),     S(19, 146),     S(21, 179),     S(42, 108),     S(34, 60),      //
    S(-6, -152),    S(22, -128),    S(22, -45),     S(45, -10),     S(37, 38),      S(40, 17),      S(14, 46),      S(31, 20),      //
    S(-22, -123),   S(-4, -267),    S(27, -270),    S(42, -159),    S(45, -73),     S(49, -110),    S(45, -81),     S(19, -44),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(13, -318),    S(303, 272),    S(257, 255),    S(61, 136),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(229, -27),    S(274, 231),    S(169, 230),    S(69, 110),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(147, 90),     S(177, 201),    S(116, 197),    S(19, 127),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, 44),     S(68, 135),     S(-25, 168),    S(-72, 168),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-124, 4),     S(-53, 84),     S(-103, 138),   S(-191, 189),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-47, -41),    S(7, 29),       S(-75, 100),    S(-136, 147),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(29, -99),     S(32, -21),     S(-29, 34),     S(-105, 86),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, -196),   S(8, -92),      S(-70, -38),    S(-63, -61),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-91, -418);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(9, 10), S(10, 5), S(4, 2), S(3, -8),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -6), S(4, 3), S(2, 2), S(3, 1), S(3, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-10, 24), S(3, -1), S(1, 13), S(-5, 22), S(-9, 39), S(-5, 62), S(1, 49), }},
  {{ S(-1, 7), S(11, 10), S(8, 5), S(4, -1), S(2, 8), S(2, 39), S(10, 33), }},
  {{ S(-0, -2), S(4, 6), S(5, -21), S(2, -19), S(1, -9), S(1, 19), S(11, 37), }},
  {{ S(-5, -12), S(4, -22), S(2, -48), S(-1, -57), S(-0, -52), S(-5, -14), S(-8, 16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-12, -19), S(-3, -2), S(-2, -11), S(-3, -29), S(-7, -48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-10, -8), S(18, 153), S(-1, 46), S(-7, 2), S(-5, -2), S(-3, -11), S(-3, -9), }},
  {{ S(-11, 1), S(7, 171), S(-4, 37), S(-5, 4), S(-6, 4), S(-2, -3), S(-7, -3), }},
  {{ S(-6, -7), S(-1, 122), S(-11, 25), S(-7, -5), S(-4, -8), S(-1, -17), S(-3, -18), }},
  {{ S(-7, 14), S(-7, 57), S(-6, -20), S(-5, -18), S(-2, 1), S(1, -1), S(-1, -5), }},
}};

inline const PParam KING_EXPOSED = S(-2, 4);
inline TunableSigmoid<32> KING_SHELTER_ACTIVATION(
        -263, -129, -4, -12
);
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1290, 920, 70, 61
);

inline VParam WINNABLE_PAWNS = V(-24);
inline VParam WINNABLE_SYM = V(130);
inline VParam WINNABLE_ASYM = V(114);
inline VParam WINNABLE_PAWN_ENDGAME = V(172);
inline VParam WINNABLE_BIAS = V(-508);

// Epoch duration: 9.12835s
// clang-format on
}  // namespace Clockwork
