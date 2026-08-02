#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(204, 507);
inline const PParam KNIGHT_MAT = S(812, 1596);
inline const PParam BISHOP_MAT = S(871, 1677);
inline const PParam ROOK_MAT   = S(1040, 2669);
inline const PParam QUEEN_MAT  = S(2419, 4120);

inline const PParam TEMPO_VAL  = S(70, 54);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -3);
inline const PParam BISHOP_PAIR_VAL   = S(61, 242);
inline const PParam ROOK_OPEN_VAL     = S(109, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-23, -80);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -40);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -42);
inline const PParam OUTPOST_KNIGHT_UNDEFENDED_VAL    = S(31, -25);
inline const PParam OUTPOST_BISHOP_UNDEFENDED_VAL    = S(36, 15);
inline const PParam OUTPOST_KNIGHT_DEFENDED_VAL    = S(30, 59);
inline const PParam OUTPOST_BISHOP_DEFENDED_VAL    = S(20, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(34, 54);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(35, -5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 71);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -1), S(33, 36), S(60, 66), S(122, 214), S(389, 403), S(674, 819),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 33), S(39, 27), S(55, 59), S(92, 185), S(394, 126),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-94, -262), S(-91, -221), S(-67, -88), S(-22, 38), S(84, 199), S(226, 407),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-80, 53), S(-94, 36), S(-60, 105), S(-91, 230), S(-54, 340), S(52, 223),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-17, 69), S(-29, 59), S(-61, 108), S(-33, 136), S(73, 159), S(34, 194),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(22, -39), S(23, -1), S(15, 35), S(19, 105), S(69, 273), S(334, 218),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -37), S(-3, 10), S(-4, -26), S(-2, -68), S(-15, -176), S(-168, -454),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 236), S(10, 183), S(4, 107), S(12, 68), S(20, 73), S(58, 68), S(62, 39),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-131, -48), S(14, -3), S(1, 100), S(28, 150), S(44, 185), S(54, 194), S(41, 174),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-92, -400), S(-24, -144), S(6, -28), S(30, 23), S(57, 56), S(72, 94), S(90, 103), S(108, 112), S(128, 67),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-74, -357), S(-20, -133), S(32, -43), S(56, 12), S(76, 55), S(88, 86), S(92, 109), S(94, 130), S(98, 141), S(104, 147), S(111, 141), S(122, 123), S(121, 129), S(102, 91),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -218), S(24, -13), S(45, 21), S(61, 40), S(71, 59), S(76, 74), S(80, 89), S(86, 95), S(90, 108), S(96, 116), S(100, 122), S(100, 132), S(103, 136), S(109, 122), S(128, 84),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-194, -207), S(-39, -96), S(-14, 47), S(4, 189), S(22, 232), S(29, 285), S(36, 323), S(43, 341), S(47, 365), S(51, 382), S(57, 390), S(61, 397), S(65, 404), S(67, 409), S(68, 412), S(67, 415), S(63, 417), S(66, 410), S(67, 406), S(71, 398), S(61, 389), S(73, 362), S(38, 391), S(-8, 383), S(-42, 382), S(-76, 404), S(-136, 433), S(-101, 368),
};

inline const PParam PAWN_THREAT_KNIGHT = S(190, 161);
inline const PParam PAWN_THREAT_BISHOP = S(162, 212);
inline const PParam PAWN_THREAT_ROOK   = S(189, 155);
inline const PParam PAWN_THREAT_QUEEN  = S(159, 12);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(9, 54), S(93, 95), S(103, 125), S(204, 125), S(163, 2), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(8, 56), S(55, 95), S(75, 97), S(17, 11), S(151, -49), S(0, 0),
};
inline const PParam KING_THREAT  = S(-9, 156);
inline const PParam HANGING_PAWN  = S(32, 94);
inline const PParam HANGING_NON_PAWN  = S(70, 28);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(20, 11),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 45), S(109, -107),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 11), S(46, -5),
};

inline const PParam SEMIOPEN_PAWN_CHAIN_BASE = S(18, 1);
inline const PParam STRONGLY_PROTECTED_PAWN_CHAIN_BASE = S(-2, -17);
inline const PParam PRESSURED_PAWN_CHAIN_BASE = S(-2, 14);
inline const PParam PRESSURED_WEAK_PAWN_CHAIN_BASE = S(-4, -8);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -17), S(3, -15), S(-1, -21), S(-7, -29), S(-13, -37), S(-18, -44), S(-20, -56), S(-26, -57), S(-32, -75),
};

inline const PParam ROOK_LINEUP = S(17, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(183, 276),    S(61, 398),     S(68, 385),     S(157, 269),    S(191, 169),    S(143, 210),    S(121, 241),    S(222, 180),    //
    S(43, 64),      S(58, 110),     S(37, 61),      S(51, -5),      S(43, -42),     S(16, -13),     S(17, 27),      S(-19, 54),     //
    S(39, -12),     S(15, -5),      S(46, -45),     S(27, -69),     S(19, -88),     S(5, -75),      S(-36, -44),    S(-38, -4),     //
    S(-6, -72),     S(-30, -43),    S(3, -62),      S(-8, -78),     S(-29, -87),    S(-34, -75),    S(-82, -57),    S(-77, -52),    //
    S(-13, -111),   S(18, -106),    S(4, -44),      S(-13, -50),    S(-38, -60),    S(-52, -70),    S(-79, -71),    S(-83, -74),    //
    S(9, -107),     S(84, -95),     S(73, -40),     S(25, -11),     S(-4, -32),     S(-23, -59),    S(-50, -58),    S(-63, -57),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-254, -504),  S(-251, 48),    S(-258, -33),   S(7, 38),       S(-83, 38),     S(-260, 80),    S(-339, 95),    S(-341, -406),  //
    S(6, -14),      S(8, 26),       S(95, 20),      S(91, 56),      S(97, 43),      S(58, 25),      S(-9, 22),      S(-37, 19),     //
    S(20, -5),      S(26, 44),      S(41, 75),      S(58, 84),      S(42, 85),      S(5, 70),       S(-7, 49),      S(-55, 28),     //
    S(78, 34),      S(88, 51),      S(96, 74),      S(101, 112),    S(103, 113),    S(67, 77),      S(47, 44),      S(20, 45),      //
    S(75, 20),      S(101, 4),      S(99, 49),      S(94, 80),      S(80, 85),      S(72, 65),      S(57, 21),      S(19, 32),      //
    S(24, -44),     S(49, -27),     S(56, 15),      S(68, 47),      S(64, 44),      S(37, 9),       S(20, -20),     S(-18, -43),    //
    S(42, -25),     S(46, -14),     S(34, -23),     S(44, 5),       S(40, 3),       S(11, -48),     S(-23, -4),     S(-43, -84),    //
    S(-38, -94),    S(16, -31),     S(35, -47),     S(51, -37),     S(34, -22),     S(-3, -54),     S(-15, -28),    S(-66, -141),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-126, 25),    S(-186, 105),   S(-396, 170),   S(-268, 102),   S(-298, 142),   S(-298, 154),   S(-220, 128),   S(-124, 74),    //
    S(-22, -17),    S(-60, 91),     S(-42, 67),     S(-63, 64),     S(-62, 80),     S(-34, 51),     S(-5, 45),      S(-47, 26),     //
    S(4, 7),        S(-10, 49),     S(7, 59),       S(4, 43),       S(-2, 33),      S(-3, 36),      S(-17, 34),     S(-19, 1),      //
    S(-4, -19),     S(42, 8),       S(48, 24),      S(69, 44),      S(90, 29),      S(27, 8),       S(35, -16),     S(-24, -14),    //
    S(27, -57),     S(41, -6),      S(75, 6),       S(88, 19),      S(70, 29),      S(62, 16),      S(14, -3),      S(-4, -50),     //
    S(60, -26),     S(81, -21),     S(98, 8),       S(66, 31),      S(62, 17),      S(59, 17),      S(60, -0),      S(19, -18),     //
    S(29, -69),     S(116, -54),    S(69, -16),     S(50, 2),       S(34, 1),       S(48, -40),     S(48, -54),     S(41, -44),     //
    S(46, -68),     S(26, -21),     S(32, -6),      S(46, -29),     S(31, -16),     S(40, 18),      S(46, -13),     S(42, -56),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(175, 108),    S(203, 129),    S(157, 158),    S(143, 130),    S(204, 85),     S(161, 112),    S(170, 128),    S(153, 126),    //
    S(89, 150),     S(147, 153),    S(189, 125),    S(144, 111),    S(180, 98),     S(147, 125),    S(100, 156),    S(91, 156),     //
    S(58, 145),     S(178, 86),     S(204, 70),     S(175, 57),     S(179, 73),     S(121, 114),    S(115, 131),    S(63, 171),     //
    S(31, 111),     S(94, 118),     S(114, 94),     S(96, 94),      S(123, 77),     S(85, 118),     S(76, 133),     S(22, 158),     //
    S(7, 43),       S(64, 53),      S(57, 75),      S(26, 85),      S(36, 89),      S(25, 115),     S(7, 113),      S(-12, 116),    //
    S(18, -36),     S(86, -12),     S(73, 14),      S(51, 27),      S(61, 33),      S(38, 57),      S(34, 41),      S(-4, 48),      //
    S(-62, -43),    S(62, -78),     S(68, -42),     S(57, -8),      S(60, -7),      S(46, 6),       S(36, -9),      S(5, -6),       //
    S(2, -63),      S(25, -32),     S(88, -44),     S(97, -43),     S(99, -38),     S(75, -16),     S(70, -22),     S(49, -17),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(91, 156),     S(148, 155),    S(57, 301),     S(-2, 398),     S(36, 350),     S(72, 259),     S(73, 176),     S(27, 207),     //
    S(60, 184),     S(80, 237),     S(39, 320),     S(-80, 437),    S(-39, 407),    S(21, 287),     S(60, 174),     S(43, 145),     //
    S(22, 235),     S(61, 260),     S(29, 338),     S(-8, 373),     S(11, 362),     S(51, 258),     S(83, 155),     S(64, 120),     //
    S(17, 170),     S(29, 237),     S(-13, 306),    S(-12, 360),    S(5, 351),      S(22, 237),     S(60, 157),     S(35, 120),     //
    S(14, 146),     S(11, 167),     S(3, 216),      S(-22, 286),    S(-11, 302),    S(11, 237),     S(16, 176),     S(37, 82),      //
    S(4, 51),       S(35, 58),      S(31, 133),     S(9, 156),      S(19, 164),     S(22, 187),     S(41, 116),     S(22, 95),      //
    S(-24, -95),    S(4, -95),      S(12, -25),     S(39, 13),      S(36, 51),      S(39, 24),      S(12, 63),      S(26, 35),      //
    S(-41, -78),    S(-10, -241),   S(21, -246),    S(33, -133),    S(40, -54),     S(39, -73),     S(36, -58),     S(6, -4),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(165, -555),   S(474, 83),     S(314, 194),    S(17, 192),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(367, -184),   S(362, 189),    S(209, 204),    S(23, 157),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(196, 44),     S(230, 174),    S(112, 198),    S(-52, 179),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(36, 7),       S(111, 113),    S(-24, 172),    S(-121, 202),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-114, -2),    S(-25, 78),     S(-88, 147),    S(-183, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-56, -34),    S(9, 33),       S(-70, 115),    S(-125, 160),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -93),     S(29, -13),     S(-34, 50),     S(-108, 106),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -211),   S(3, -92),      S(-74, -28),    S(-83, -40),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -448);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 1), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -19), S(-6, 4), S(-3, -9), S(7, -16), S(12, -29), S(7, -53), S(-3, -45), }},
  {{ S(2, 3), S(-20, 2), S(-16, 10), S(-10, 17), S(-6, 8), S(-9, -12), S(-19, -21), }},
  {{ S(-4, -1), S(-12, -9), S(-14, 17), S(-9, 19), S(-8, 10), S(-8, -16), S(-23, -37), }},
  {{ S(6, 8), S(-10, 16), S(-7, 37), S(-2, 41), S(-2, 37), S(4, 18), S(10, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 23), S(-6, 2), S(-7, 9), S(-6, 27), S(1, 47),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 10), S(-41, -123), S(-9, -39), S(-1, 4), S(-3, 3), S(-6, 10), S(-5, 9), }},
  {{ S(9, -2), S(-25, -122), S(-6, -30), S(-4, 0), S(-2, -3), S(-8, 3), S(1, 3), }},
  {{ S(-0, 11), S(-7, -68), S(7, -14), S(0, 8), S(-4, 11), S(-9, 18), S(-6, 21), }},
  {{ S(0, 0), S(2, -61), S(-1, 24), S(-3, 25), S(-6, 8), S(-12, 10), S(-9, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1430, 920, -22, -1
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(102);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(75);
inline VParam WINNABLE_BIAS = V(-389);

// Epoch duration: 7.3547s
// clang-format on
}  // namespace Clockwork
