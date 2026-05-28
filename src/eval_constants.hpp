#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(187, 491);
inline const PParam KNIGHT_MAT = S(801, 1527);
inline const PParam BISHOP_MAT = S(844, 1627);
inline const PParam ROOK_MAT   = S(1008, 2565);
inline const PParam QUEEN_MAT  = S(2381, 3878);
inline const PParam TEMPO_VAL  = S(65, 33);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -7);
inline const PParam BISHOP_PAIR_VAL   = S(62, 226);
inline const PParam ROOK_OPEN_VAL     = S(106, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, -1);
inline const PParam MINOR_BEHIND_PAWN = S(15, 35);
inline const PParam RESTRICTED_SQUARES = S(-23, -4);
inline const PParam LATENT_INVASION_SQUARES = S(8, 14);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -77);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -37);
inline const PParam OUTPOST_KNIGHT_VAL    = S(56, 45);
inline const PParam OUTPOST_BISHOP_VAL    = S(46, 38);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 50);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -42);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -3), S(31, 38), S(56, 68), S(125, 199), S(428, 281), S(587, 609),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 34), S(38, 27), S(53, 63), S(99, 191), S(408, 131),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-86, -265), S(-84, -230), S(-63, -95), S(-24, 40), S(72, 232), S(211, 391),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -42), S(26, -7), S(13, 31), S(12, 109), S(74, 237), S(141, 422),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -40), S(2, 6), S(-6, -26), S(-5, -58), S(-10, -167), S(-166, -325),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(14, 231), S(-3, 181), S(-5, 105), S(5, 64), S(15, 68), S(57, 64), S(46, 48),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-123, -149), S(17, 21), S(4, 111), S(28, 157), S(36, 193), S(48, 199), S(33, 178),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-82, -364), S(-23, -134), S(6, -18), S(30, 22), S(58, 47), S(72, 79), S(90, 82), S(109, 87), S(127, 38),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-56, -273), S(-10, -110), S(39, -40), S(60, 9), S(81, 45), S(93, 69), S(99, 89), S(102, 104), S(105, 114), S(111, 118), S(120, 107), S(133, 89), S(138, 90), S(116, 58),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(108, -203), S(24, -16), S(45, 17), S(61, 32), S(71, 51), S(75, 65), S(79, 80), S(85, 85), S(89, 97), S(95, 103), S(100, 107), S(103, 113), S(103, 117), S(106, 107), S(134, 59),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-210, -127), S(-63, -20), S(-37, 100), S(-15, 221), S(1, 263), S(7, 314), S(14, 347), S(19, 364), S(23, 389), S(25, 407), S(30, 415), S(32, 424), S(35, 428), S(35, 434), S(35, 434), S(29, 440), S(24, 440), S(23, 433), S(23, 426), S(23, 420), S(17, 406), S(18, 383), S(-13, 410), S(-55, 391), S(-88, 397), S(-126, 419), S(-168, 436), S(-145, 361),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 147);
inline const PParam PAWN_THREAT_BISHOP = S(191, 216);
inline const PParam PAWN_THREAT_ROOK   = S(205, 156);
inline const PParam PAWN_THREAT_QUEEN  = S(174, 20);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 71), S(96, 90), S(113, 127), S(215, 135), S(180, 32), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(5, 68), S(67, 85), S(78, 95), S(-23, 38), S(205, -15), S(0, 0),
};
inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -18), S(4, -15), S(-0, -21), S(-5, -29), S(-11, -37), S(-16, -44), S(-18, -57), S(-23, -60), S(-26, -79),
};

inline const PParam ROOK_LINEUP = S(15, 76);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(183, 263),    S(38, 366),     S(72, 338),     S(136, 241),    S(193, 151),    S(118, 215),    S(83, 256),     S(221, 209),    //
    S(42, 51),      S(48, 91),      S(32, 34),      S(45, -41),     S(38, -75),     S(9, -34),      S(2, 22),       S(-21, 55),     //
    S(36, -15),     S(9, -7),       S(40, -52),     S(27, -74),     S(18, -93),     S(-4, -79),     S(-38, -44),    S(-40, -2),     //
    S(-7, -71),     S(-32, -39),    S(3, -63),      S(-6, -73),     S(-27, -84),    S(-37, -74),    S(-85, -53),    S(-76, -50),    //
    S(-12, -104),   S(20, -103),    S(6, -46),      S(-11, -52),    S(-36, -64),    S(-52, -73),    S(-80, -68),    S(-81, -70),    //
    S(10, -100),    S(79, -90),     S(68, -40),     S(21, -17),     S(-8, -42),     S(-27, -64),    S(-52, -57),    S(-62, -53),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-257, -524),  S(-257, 27),    S(-282, -115),  S(15, -10),     S(-88, 4),      S(-262, 47),    S(-384, 99),    S(-346, -396),  //
    S(-12, -35),    S(-12, 9),      S(91, -16),     S(76, 29),      S(88, 17),      S(47, -1),      S(-28, 12),     S(-36, -8),     //
    S(38, -44),     S(36, 19),      S(70, 42),      S(79, 50),      S(65, 54),      S(21, 57),      S(12, 18),      S(-38, -5),     //
    S(97, 8),       S(90, 35),      S(102, 61),     S(105, 101),    S(112, 101),    S(75, 72),      S(51, 33),      S(39, 19),      //
    S(75, 10),      S(105, 1),      S(102, 54),     S(93, 84),      S(80, 85),      S(78, 68),      S(65, 8),       S(25, 20),      //
    S(19, -37),     S(47, -11),     S(51, 36),      S(65, 67),      S(60, 64),      S(33, 31),      S(20, -5),      S(-22, -41),    //
    S(39, -25),     S(45, -12),     S(28, -3),      S(35, 24),      S(32, 19),      S(7, -34),      S(-25, -2),     S(-31, -111),   //
    S(-39, -88),    S(9, -26),      S(30, -38),     S(48, -29),     S(29, -8),      S(-7, -45),     S(-17, -26),    S(-59, -141),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-120, 7),     S(-176, 96),    S(-461, 187),   S(-278, 74),    S(-297, 121),   S(-301, 133),   S(-203, 107),   S(-121, 45),    //
    S(-32, -29),    S(-80, 87),     S(-37, 38),     S(-77, 60),     S(-68, 58),     S(-37, 35),     S(-10, 27),     S(-48, 8),      //
    S(36, 17),      S(14, 62),      S(34, 67),      S(32, 55),      S(25, 36),      S(20, 42),      S(11, 44),      S(19, 3),       //
    S(15, -12),     S(57, 16),      S(68, 36),      S(80, 56),      S(107, 40),     S(49, 25),      S(54, -7),      S(6, -14),      //
    S(51, -63),     S(51, -6),      S(83, 10),      S(102, 28),     S(84, 45),      S(73, 19),      S(25, 5),       S(23, -43),     //
    S(64, -45),     S(88, -29),     S(101, 8),      S(72, 38),      S(70, 19),      S(67, 21),      S(75, -11),     S(25, -30),     //
    S(36, -98),     S(118, -54),    S(76, -10),     S(54, 4),       S(37, 6),       S(57, -40),     S(55, -52),     S(49, -73),     //
    S(53, -89),     S(23, -15),     S(27, -2),      S(51, -27),     S(34, -20),     S(41, 14),      S(50, -21),     S(46, -63),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(154, 86),     S(196, 92),     S(145, 121),    S(135, 94),     S(190, 57),     S(149, 83),     S(167, 89),     S(137, 101),    //
    S(77, 126),     S(142, 113),    S(191, 82),     S(140, 87),     S(186, 66),     S(138, 95),     S(92, 122),     S(83, 128),     //
    S(57, 123),     S(179, 64),     S(205, 48),     S(183, 28),     S(180, 51),     S(124, 90),     S(126, 96),     S(70, 142),     //
    S(38, 94),      S(101, 101),    S(127, 70),     S(106, 75),     S(134, 63),     S(96, 103),     S(94, 108),     S(31, 138),     //
    S(11, 42),      S(82, 49),      S(68, 69),      S(44, 74),      S(53, 82),      S(41, 108),     S(21, 107),     S(-1, 107),     //
    S(23, -27),     S(94, -9),      S(83, 17),      S(63, 22),      S(73, 28),      S(43, 62),      S(50, 39),      S(4, 51),       //
    S(-64, -23),    S(70, -66),     S(73, -26),     S(60, 8),       S(64, 4),       S(49, 19),      S(39, 2),       S(11, 8),       //
    S(-2, -55),     S(11, -12),     S(83, -31),     S(92, -31),     S(92, -25),     S(70, -1),      S(70, -13),     S(52, -7),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(48, 161),     S(136, 105),    S(31, 264),     S(-26, 364),    S(17, 314),     S(53, 221),     S(49, 148),     S(-14, 199),    //
    S(45, 168),     S(55, 236),     S(15, 314),     S(-125, 446),   S(-71, 414),    S(-20, 312),    S(32, 165),     S(7, 157),      //
    S(-3, 230),     S(25, 276),     S(-6, 355),     S(-50, 394),    S(-29, 381),    S(21, 268),     S(53, 159),     S(49, 91),      //
    S(15, 138),     S(5, 244),      S(-26, 308),    S(-46, 386),    S(-27, 389),    S(6, 251),      S(48, 150),     S(24, 116),     //
    S(6, 136),      S(-1, 174),     S(-16, 238),    S(-34, 307),    S(-23, 335),    S(0, 255),      S(10, 169),     S(35, 77),      //
    S(6, 36),       S(28, 64),      S(22, 154),     S(-1, 177),     S(11, 179),     S(13, 212),     S(35, 130),     S(23, 86),      //
    S(-24, -113),   S(4, -87),      S(9, -4),       S(32, 31),      S(28, 73),      S(32, 47),      S(7, 74),       S(21, 49),      //
    S(-37, -93),    S(-22, -231),   S(8, -231),     S(24, -119),    S(31, -43),     S(33, -75),     S(30, -48),     S(4, -12),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(114, -587),   S(448, 7),      S(264, 168),    S(-8, 132),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(307, -169),   S(308, 143),    S(144, 197),    S(-26, 152),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(143, 71),     S(157, 200),    S(63, 218),     S(-75, 175),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, 28),     S(47, 153),     S(-55, 188),    S(-109, 195),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, 2),     S(-45, 90),     S(-109, 155),   S(-181, 195),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-44, -34),    S(13, 41),      S(-66, 116),    S(-116, 158),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(29, -90),     S(33, -8),      S(-27, 55),     S(-101, 106),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, -201),   S(9, -85),      S(-71, -24),    S(-66, -46),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-101, -438);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -7), S(10, 9), S(10, 2), S(4, 0), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(4, 3), S(2, 2), S(3, -0), S(3, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -20), S(-6, 5), S(-2, -9), S(9, -17), S(15, -30), S(8, -54), S(-2, -45), }},
  {{ S(1, 3), S(-22, 3), S(-17, 10), S(-10, 18), S(-7, 8), S(-8, -18), S(-18, -24), }},
  {{ S(-2, -3), S(-10, -10), S(-12, 17), S(-7, 16), S(-6, 9), S(-6, -19), S(-22, -39), }},
  {{ S(7, 7), S(-9, 16), S(-6, 36), S(-2, 42), S(-2, 37), S(7, 12), S(11, -19), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 27), S(-4, 3), S(-7, 11), S(-4, 28), S(2, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 11), S(-46, -156), S(-9, -54), S(0, 4), S(-1, 3), S(-5, 10), S(-4, 8), }},
  {{ S(11, -2), S(-26, -171), S(-5, -35), S(-2, 1), S(1, -3), S(-6, 3), S(3, 1), }},
  {{ S(1, 10), S(-10, -93), S(8, -21), S(1, 9), S(-2, 10), S(-9, 18), S(-5, 20), }},
  {{ S(3, 1), S(4, -69), S(-1, 29), S(-2, 26), S(-5, 10), S(-11, 12), S(-9, 21), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1390, 887, -18, -6
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_PASSERS = V(18);
inline VParam WINNABLE_SYM = V(105);
inline VParam WINNABLE_ASYM = V(80);
inline VParam WINNABLE_PAWN_ENDGAME = V(110);
inline VParam WINNABLE_BIAS = V(-399);

// Epoch duration: 8.28111s
// clang-format on
}  // namespace Clockwork
