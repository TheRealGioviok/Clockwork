#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(203, 491);
inline const PParam KNIGHT_MAT = S(859, 1513);
inline const PParam BISHOP_MAT = S(902, 1569);
inline const PParam ROOK_MAT   = S(1104, 2365);
inline const PParam QUEEN_MAT  = S(2586, 3560);

inline const PParam TEMPO_VAL  = S(72, 57);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -2);
inline const std::array<PParam, 2> BISHOP_PAIR_VAL = {
    S(62, 236), S(212, 310),
};
inline const PParam ROOK_OPEN_VAL     = S(113, -6);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 8);
inline const PParam MINOR_BEHIND_PAWN = S(16, 44);
inline const PParam RESTRICTED_SQUARES = S(19, 8);
inline const PParam SPACE_VAL = S(82, -77);

inline const PParam DOUBLED_PAWN_VAL = S(-18, -85);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -42);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(44, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 54);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -45);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -9), S(39, 26), S(53, 72), S(121, 210), S(441, 380), S(564, 639),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 23), S(42, 21), S(42, 68), S(88, 179), S(408, 113),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -250), S(-92, -210), S(-60, -82), S(-15, 42), S(75, 220), S(217, 434),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-73, 51), S(-92, 40), S(-48, 95), S(-91, 221), S(-66, 336), S(44, 229),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-1, 57), S(-13, 54), S(-60, 106), S(-20, 122), S(78, 148), S(40, 196),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(23, -39), S(20, 2), S(14, 36), S(24, 96), S(73, 263), S(312, 256),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(7, -29), S(-2, 14), S(-12, -18), S(-8, -60), S(-15, -172), S(-181, -461),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(24, 221), S(9, 171), S(2, 96), S(14, 56), S(26, 61), S(61, 55), S(69, 26),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-119, -58), S(19, -8), S(4, 99), S(32, 145), S(46, 183), S(57, 190), S(41, 170),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-114, -362), S(-38, -97), S(-7, 21), S(13, 74), S(36, 111), S(50, 151), S(69, 157), S(88, 162), S(108, 116),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-88, -286), S(-26, -66), S(31, 16), S(50, 82), S(68, 129), S(80, 161), S(85, 185), S(87, 206), S(91, 214), S(97, 221), S(110, 210), S(115, 197), S(123, 198), S(81, 165),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(90, -103), S(8, 107), S(29, 141), S(45, 160), S(57, 179), S(60, 193), S(65, 210), S(70, 217), S(74, 229), S(80, 237), S(83, 244), S(82, 252), S(85, 257), S(92, 241), S(107, 208),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-176, -99), S(-22, 14), S(3, 176), S(21, 332), S(41, 373), S(49, 425), S(54, 471), S(57, 497), S(60, 523), S(63, 542), S(66, 555), S(72, 559), S(75, 567), S(80, 567), S(81, 571), S(83, 570), S(79, 573), S(79, 565), S(80, 561), S(90, 548), S(75, 544), S(99, 503), S(66, 535), S(28, 526), S(5, 508), S(-30, 534), S(-11, 487), S(-4, 432),
};

inline const PParam PAWN_THREAT_KNIGHT = S(204, 160);
inline const PParam PAWN_THREAT_BISHOP = S(170, 234);
inline const PParam PAWN_THREAT_ROOK   = S(195, 148);
inline const PParam PAWN_THREAT_QUEEN  = S(160, 24);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(10, 54), S(98, 98), S(105, 121), S(184, 84), S(175, 3), }},
  {{ S(6, 58), S(89, 90), S(104, 117), S(218, 591), S(151, -27), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(9, 64), S(45, 115), S(64, 110), S(16, 20), S(165, -82), }},
  {{ S(-0, 53), S(63, 79), S(103, 65), S(14, 15), S(428, 615), }},
}};
inline const PParam KING_THREAT  = S(-1, 152);
inline const PParam HANGING_PAWN  = S(31, 94);
inline const PParam HANGING_NON_PAWN  = S(72, 31);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(22, -16), S(96, -76),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(50, 32), S(215, -249),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(41, 8), S(127, -110),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -18), S(4, -16), S(0, -22), S(-6, -29), S(-13, -36), S(-19, -40), S(-21, -49), S(-27, -45), S(-26, -93),
};

inline const PParam ROOK_LINEUP = S(17, 88);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(196, 276),    S(63, 402),     S(72, 389),     S(175, 272),    S(183, 195),    S(153, 221),    S(137, 245),    S(226, 199),    //
    S(55, 68),      S(53, 114),     S(33, 73),      S(37, 15),      S(28, -23),     S(7, 0),        S(9, 42),       S(-15, 66),     //
    S(37, 0),       S(9, 7),        S(28, -21),     S(-1, -35),     S(-17, -49),    S(-22, -45),    S(-46, -31),    S(-44, 10),     //
    S(-9, -60),     S(-37, -31),    S(-7, -45),     S(-26, -55),    S(-49, -65),    S(-51, -55),    S(-91, -44),    S(-87, -38),    //
    S(-21, -94),    S(10, -87),     S(-3, -24),     S(-20, -32),    S(-43, -43),    S(-66, -48),    S(-95, -50),    S(-101, -53),   //
    S(4, -90),      S(80, -75),     S(84, -29),     S(31, 3),       S(2, -22),      S(-25, -44),    S(-62, -36),    S(-77, -36),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-295, -448),  S(-244, 57),    S(-290, 132),   S(28, 51),      S(-74, 61),     S(-300, 134),   S(-333, 117),   S(-387, -361),  //
    S(3, 17),       S(-7, 52),      S(83, 33),      S(83, 90),      S(96, 69),      S(49, 44),      S(-8, 38),      S(-52, 46),     //
    S(36, -6),      S(44, 44),      S(50, 72),      S(73, 94),      S(57, 91),      S(13, 83),      S(-2, 59),      S(-44, 25),     //
    S(83, 50),      S(87, 65),      S(90, 93),      S(99, 129),     S(101, 120),    S(67, 89),      S(45, 49),      S(17, 61),      //
    S(70, 39),      S(91, 21),      S(99, 62),      S(84, 104),     S(79, 100),     S(61, 86),      S(48, 40),      S(14, 37),      //
    S(11, -28),     S(42, -18),     S(47, 34),      S(57, 71),      S(51, 73),      S(23, 31),      S(6, -1),       S(-35, -26),    //
    S(26, -2),      S(21, 22),      S(20, -8),      S(30, 24),      S(25, 24),      S(-4, -25),     S(-48, 24),     S(-67, -62),    //
    S(-65, -69),    S(-3, -12),     S(15, -18),     S(31, -7),      S(15, 1),       S(-27, -29),    S(-42, 6),      S(-102, -108),  //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-121, 23),    S(-226, 143),   S(-407, 216),   S(-273, 137),   S(-280, 156),   S(-261, 168),   S(-193, 135),   S(-153, 128),   //
    S(-37, 16),     S(-76, 127),    S(-56, 103),    S(-62, 98),     S(-59, 106),    S(-36, 78),     S(-21, 73),     S(-62, 62),     //
    S(41, 45),      S(19, 82),      S(28, 95),      S(23, 87),      S(25, 68),      S(14, 84),      S(-4, 80),      S(14, 25),      //
    S(9, 23),       S(46, 55),      S(61, 61),      S(81, 86),      S(94, 81),      S(37, 58),      S(33, 40),      S(-9, 33),      //
    S(33, -10),     S(34, 39),      S(70, 45),      S(86, 64),      S(72, 72),      S(57, 62),      S(10, 44),      S(-2, 1),       //
    S(48, 9),       S(76, 4),       S(89, 34),      S(60, 60),      S(53, 53),      S(49, 48),      S(52, 29),      S(15, 3),       //
    S(22, -38),     S(110, -34),    S(55, 16),      S(38, 32),      S(24, 30),      S(38, -14),     S(41, -26),     S(27, -11),     //
    S(26, -34),     S(14, 7),       S(17, 28),      S(30, 6),       S(14, 13),      S(27, 47),      S(32, 17),      S(25, -26),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(162, 174),    S(182, 194),    S(148, 224),    S(136, 188),    S(182, 160),    S(135, 183),    S(153, 198),    S(147, 186),    //
    S(91, 210),     S(131, 217),    S(185, 174),    S(136, 172),    S(173, 163),    S(140, 183),    S(86, 219),     S(79, 219),     //
    S(67, 195),     S(174, 143),    S(215, 118),    S(174, 107),    S(174, 130),    S(112, 171),    S(92, 200),     S(51, 233),     //
    S(29, 171),     S(88, 182),     S(99, 161),     S(85, 155),     S(109, 141),    S(75, 181),     S(57, 203),     S(11, 220),     //
    S(2, 106),      S(56, 118),     S(41, 150),     S(9, 156),      S(23, 155),     S(13, 178),     S(-5, 184),     S(-31, 186),    //
    S(5, 35),       S(80, 50),      S(60, 82),      S(35, 101),     S(42, 108),     S(26, 126),     S(22, 109),     S(-23, 122),    //
    S(-71, 29),     S(52, -13),     S(54, 29),      S(40, 69),      S(46, 66),      S(29, 79),      S(20, 66),      S(-10, 58),     //
    S(-10, -4),     S(10, 32),      S(74, 23),      S(83, 23),      S(85, 30),      S(60, 55),      S(56, 45),      S(35, 49),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(109, 222),    S(173, 211),    S(81, 356),     S(46, 412),     S(51, 422),     S(106, 311),    S(75, 265),     S(31, 282),     //
    S(73, 259),     S(72, 320),     S(45, 390),     S(-55, 479),    S(-18, 467),    S(40, 335),     S(63, 262),     S(50, 224),     //
    S(51, 264),     S(95, 294),     S(53, 378),     S(22, 403),     S(33, 415),     S(64, 332),     S(100, 223),    S(80, 192),     //
    S(43, 222),     S(48, 291),     S(7, 359),      S(8, 411),      S(28, 405),     S(30, 311),     S(70, 237),     S(53, 196),     //
    S(26, 211),     S(28, 212),     S(25, 260),     S(-2, 339),     S(1, 373),      S(25, 306),     S(26, 251),     S(43, 168),     //
    S(21, 118),     S(56, 101),     S(48, 189),     S(19, 229),     S(30, 240),     S(27, 275),     S(47, 208),     S(30, 184),     //
    S(-15, -33),    S(22, -47),     S(27, 32),      S(51, 82),      S(46, 127),     S(48, 102),     S(24, 137),     S(38, 105),     //
    S(-46, 1),      S(-0, -191),    S(25, -166),    S(35, -59),     S(50, 12),      S(46, 7),       S(42, 17),      S(8, 82),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(121, -432),   S(480, 112),    S(433, 134),    S(65, 191),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(327, -167),   S(327, 186),    S(228, 174),    S(23, 126),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(186, 27),     S(202, 161),    S(75, 183),     S(-91, 166),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(30, 2),       S(107, 93),     S(-49, 162),    S(-165, 194),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-113, -4),    S(-38, 75),     S(-96, 141),    S(-207, 192),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-58, -29),    S(1, 37),       S(-80, 119),    S(-140, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(32, -97),     S(32, -13),     S(-33, 52),     S(-115, 112),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -204),   S(9, -92),      S(-71, -24),    S(-77, -42),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-88, -431);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -1), S(12, 15), S(12, 7), S(5, 3), S(3, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -5), S(6, 5), S(3, 2), S(3, 0), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(4, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 1);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -14), S(-10, 7), S(-5, -9), S(5, -13), S(14, -30), S(8, -53), S(-4, -51), }},
  {{ S(1, 10), S(-25, 4), S(-20, 13), S(-12, 21), S(-8, 13), S(-11, -13), S(-23, -22), }},
  {{ S(-5, 3), S(-14, -5), S(-16, 22), S(-10, 22), S(-8, 11), S(-8, -14), S(-22, -54), }},
  {{ S(6, 14), S(-13, 22), S(-9, 47), S(-3, 51), S(-3, 46), S(2, 27), S(15, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 28), S(-9, 6), S(-9, 12), S(-8, 34), S(3, 53),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 16), S(-55, -117), S(-12, -40), S(1, 2), S(-4, 7), S(-7, 13), S(-7, 13), }},
  {{ S(10, 1), S(-32, -109), S(-7, -40), S(-4, -1), S(-3, -1), S(-12, 6), S(-0, 6), }},
  {{ S(-0, 14), S(-5, -83), S(8, -9), S(2, 9), S(-4, 16), S(-12, 22), S(-7, 24), }},
  {{ S(1, 0), S(2, -69), S(0, 25), S(-4, 35), S(-8, 14), S(-16, 11), S(-11, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1122, 866, -24, 2
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(46);
inline VParam WINNABLE_BIAS = V(-381);

// Epoch duration: 3.75111s
// clang-format on
}  // namespace Clockwork
