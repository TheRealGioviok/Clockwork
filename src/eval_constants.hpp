#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(183, 449);
inline const PParam KNIGHT_MAT = S(820, 1324);
inline const PParam BISHOP_MAT = S(855, 1391);
inline const PParam ROOK_MAT   = S(1012, 2185);
inline const PParam QUEEN_MAT  = S(2456, 3433);
inline const PParam TEMPO_VAL  = S(59, 23);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 14);
inline const PParam BISHOP_PAIR_VAL   = S(54, 227);
inline const PParam ROOK_OPEN_VAL     = S(113, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 32);
inline const PParam MINOR_BEHIND_PAWN = S(14, 40);
inline const PParam RESTRICTED_SQUARES = S(-22, -8);

inline const PParam DOUBLED_PAWN_VAL = S(-15, -77);
inline const PParam ISOLATED_PAWN_VAL = S(-16, -27);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -28);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 56);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(43, -14);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -42);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, 4), S(28, 38), S(57, 66), S(135, 180), S(364, 272), S(474, 538),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(44, 45), S(43, 38), S(58, 68), S(111, 182), S(394, 130),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-99, -226), S(-99, -195), S(-76, -67), S(-25, 53), S(59, 226), S(240, 329),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -42), S(25, -6), S(18, 31), S(8, 119), S(76, 242), S(175, 384),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -31), S(3, 20), S(2, -21), S(4, -55), S(-0, -157), S(-240, -262),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(19, 213), S(-4, 177), S(-2, 97), S(4, 57), S(12, 59), S(50, 54), S(40, 37),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-249, -56), S(-8, 51), S(1, 104), S(38, 132), S(55, 156), S(65, 162), S(45, 155),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-101, -304), S(-41, -99), S(-12, 8), S(12, 50), S(41, 74), S(56, 109), S(76, 110), S(96, 121), S(125, 50),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-73, -275), S(-26, -91), S(25, -12), S(47, 40), S(68, 79), S(80, 107), S(85, 129), S(92, 143), S(94, 160), S(105, 150), S(110, 149), S(143, 101), S(136, 114), S(165, 51),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(102, -130), S(21, 48), S(42, 80), S(58, 93), S(68, 109), S(73, 122), S(78, 135), S(85, 138), S(89, 150), S(97, 154), S(103, 159), S(106, 168), S(106, 170), S(113, 146), S(178, 47),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-160, -56), S(-37, 72), S(-13, 199), S(7, 313), S(22, 362), S(30, 405), S(36, 439), S(44, 450), S(47, 474), S(50, 490), S(55, 496), S(58, 506), S(63, 504), S(63, 511), S(64, 508), S(60, 511), S(59, 506), S(61, 496), S(63, 488), S(65, 478), S(60, 463), S(77, 416), S(54, 432), S(37, 389), S(20, 362), S(-1, 347), S(-42, 333), S(-40, 308),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 117);
inline const PParam PAWN_THREAT_BISHOP = S(190, 164);
inline const PParam PAWN_THREAT_ROOK   = S(194, 143);
inline const PParam PAWN_THREAT_QUEEN  = S(176, -11);

inline const PParam KNIGHT_THREAT_BISHOP = S(106, 121);
inline const PParam KNIGHT_THREAT_ROOK   = S(220, 93);
inline const PParam KNIGHT_THREAT_QUEEN  = S(149, 3);

inline const PParam BISHOP_THREAT_KNIGHT = S(96, 77);
inline const PParam BISHOP_THREAT_ROOK   = S(204, 154);
inline const PParam BISHOP_THREAT_QUEEN  = S(163, 123);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -27), S(0, -8), S(-2, -19), S(-6, -30), S(-10, -39), S(-14, -47), S(-16, -60), S(-21, -63), S(-34, -60),
};

inline const PParam ROOK_LINEUP = S(16, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(208, 242),    S(47, 291),     S(191, 221),    S(166, 201),    S(221, 107),    S(120, 197),    S(51, 256),     S(192, 199),    //
    S(42, 41),      S(70, 53),      S(75, 20),      S(54, -49),     S(48, -86),     S(29, -36),     S(10, 22),      S(-23, 57),     //
    S(24, -13),     S(4, -14),      S(34, -57),     S(21, -86),     S(17, -102),    S(-6, -71),     S(-49, -24),    S(-48, 9),      //
    S(-6, -73),     S(-23, -49),    S(3, -72),      S(-10, -81),    S(-32, -83),    S(-38, -65),    S(-91, -29),    S(-83, -32),    //
    S(-5, -106),    S(30, -111),    S(12, -52),     S(-4, -56),     S(-33, -64),    S(-49, -61),    S(-80, -48),    S(-80, -52),    //
    S(15, -104),    S(95, -109),    S(71, -57),     S(29, -20),     S(-0, -39),     S(-22, -53),    S(-50, -38),    S(-62, -36),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-296, -410),  S(-280, 42),    S(-204, -218),  S(-32, 47),     S(-119, 63),    S(-244, 50),    S(-415, 132),   S(-370, -287),  //
    S(-46, -9),     S(-26, 31),     S(83, -2),      S(86, 29),      S(88, 25),      S(18, 36),      S(-47, 44),     S(-68, 18),     //
    S(23, -16),     S(38, 8),       S(72, 66),      S(88, 66),      S(60, 90),      S(14, 87),      S(2, 26),       S(-46, 24),     //
    S(84, 22),      S(93, 48),      S(102, 78),     S(103, 118),    S(110, 118),    S(68, 95),      S(42, 62),      S(26, 38),      //
    S(64, 22),      S(104, 3),      S(90, 69),      S(86, 88),      S(67, 91),      S(70, 79),      S(53, 27),      S(10, 40),      //
    S(8, -29),      S(34, -5),      S(35, 38),      S(47, 65),      S(42, 62),      S(14, 39),      S(4, 6),        S(-36, -28),    //
    S(23, -16),     S(33, -19),     S(11, -9),      S(19, 15),      S(17, 12),      S(-10, -33),    S(-35, 1),      S(-48, -97),    //
    S(-49, -81),    S(4, -21),      S(20, -42),     S(35, -35),     S(20, -16),     S(-14, -43),    S(-25, -27),    S(-69, -124),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-151, 84),    S(-181, 129),   S(-460, 182),   S(-314, 121),   S(-317, 129),   S(-339, 123),   S(-235, 121),   S(-119, 48),    //
    S(-48, 2),      S(-86, 93),     S(-62, 58),     S(-113, 81),    S(-91, 71),     S(-60, 54),     S(-21, 39),     S(-58, 19),     //
    S(20, 30),      S(7, 61),       S(22, 68),      S(15, 64),      S(-3, 58),      S(8, 48),       S(8, 43),       S(4, 19),       //
    S(7, 10),       S(43, 23),      S(56, 47),      S(63, 87),      S(97, 66),      S(35, 39),      S(37, 3),       S(-10, 12),     //
    S(39, -44),     S(49, -1),      S(73, 25),      S(88, 49),      S(69, 62),      S(58, 44),      S(15, 19),      S(6, -18),      //
    S(59, -28),     S(80, -13),     S(96, 19),      S(62, 42),      S(58, 21),      S(57, 31),      S(61, 12),      S(7, 6),        //
    S(28, -71),     S(108, -48),    S(70, -21),     S(47, 1),       S(32, 3),       S(43, -30),     S(42, -43),     S(38, -43),     //
    S(49, -66),     S(31, -30),     S(28, 6),       S(45, -22),     S(31, -9),      S(37, 26),      S(45, -5),      S(41, -42),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(187, 112),    S(227, 118),    S(186, 132),    S(186, 95),     S(223, 85),     S(175, 113),    S(194, 122),    S(181, 125),    //
    S(85, 179),     S(165, 179),    S(229, 138),    S(166, 155),    S(195, 156),    S(161, 169),    S(113, 191),    S(96, 194),     //
    S(48, 183),     S(179, 142),    S(206, 121),    S(181, 112),    S(177, 136),    S(126, 171),    S(128, 175),    S(63, 215),     //
    S(25, 142),     S(106, 152),    S(130, 125),    S(110, 129),    S(139, 118),    S(90, 164),     S(93, 163),     S(20, 195),     //
    S(4, 63),       S(77, 76),      S(67, 92),      S(40, 95),      S(47, 108),     S(34, 138),     S(10, 134),     S(-2, 124),     //
    S(18, -20),     S(90, 5),       S(76, 27),      S(57, 26),      S(65, 35),      S(35, 70),      S(42, 47),      S(3, 56),       //
    S(-74, -17),    S(63, -57),     S(65, -28),     S(53, 0),       S(54, 8),       S(41, 20),      S(32, 5),       S(3, 16),       //
    S(-10, -39),    S(15, -14),     S(70, -25),     S(79, -27),     S(79, -16),     S(60, 4),       S(56, -2),      S(36, 4),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(52, 194),     S(124, 157),    S(62, 241),     S(15, 316),     S(45, 279),     S(43, 252),     S(69, 161),     S(-4, 239),     //
    S(47, 222),     S(57, 322),     S(29, 344),     S(-97, 423),    S(-56, 410),    S(-11, 357),    S(35, 239),     S(16, 230),     //
    S(18, 259),     S(43, 317),     S(20, 371),     S(-25, 399),    S(-17, 403),    S(37, 309),     S(57, 235),     S(60, 159),     //
    S(34, 155),     S(35, 247),     S(-13, 324),    S(-21, 377),    S(-11, 398),    S(18, 285),     S(61, 200),     S(33, 179),     //
    S(35, 119),     S(21, 185),     S(0, 248),      S(-19, 306),    S(-6, 334),     S(10, 279),     S(28, 199),     S(47, 122),     //
    S(27, 46),      S(45, 85),      S(40, 168),     S(22, 179),     S(25, 204),     S(28, 234),     S(45, 170),     S(36, 125),     //
    S(1, -78),      S(19, -28),     S(26, 28),      S(51, 58),      S(44, 107),     S(44, 86),      S(17, 123),     S(32, 100),     //
    S(-11, -71),    S(12, -203),    S(36, -192),    S(53, -87),     S(49, 13),      S(54, -33),     S(49, -2),      S(24, 28),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-53, -213),   S(229, 344),    S(98, 357),     S(-32, 240),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(179, 75),     S(232, 273),    S(76, 326),     S(-3, 239),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(130, 130),    S(140, 263),    S(40, 305),     S(-34, 250),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-40, 74),     S(51, 171),     S(-75, 244),    S(-119, 268),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-115, -9),    S(-41, 81),     S(-119, 155),   S(-203, 220),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -75),    S(31, -2),      S(-72, 87),     S(-132, 148),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(42, -134),    S(49, -56),     S(-28, 5),      S(-93, 63),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-5, -233),    S(22, -130),    S(-60, -80),    S(-54, -94),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-84, -538);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -22), S(15, -27), S(14, -4), S(6, -8), S(1, -31),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -8), S(6, -22), S(4, -13), S(4, 1), S(4, 6),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-5, 1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -2);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -6);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, 41), S(-3, 57), S(-1, -18), S(11, -25), S(9, -15), S(-2, -4), S(-2, 57), }},
  {{ S(-1, 160), S(-20, -231), S(-20, -1), S(-7, 52), S(-7, 72), S(-18, -8), S(-18, -222), }},
  {{ S(-4, 140), S(-9, -222), S(-10, 135), S(-4, 112), S(-3, 111), S(-10, 138), S(-9, -201), }},
  {{ S(8, 123), S(-10, 86), S(1, 95), S(8, 76), S(6, 79), S(-1, 94), S(-6, 86), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 63), S(-11, 43), S(-11, 71), S(-2, 76), S(3, 36),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 116), S(-9, 38), S(-10, 38), S(-6, 31), S(-7, 21), S(-8, 35), S(-10, 47), }},
  {{ S(9, 7), S(0, -24), S(-9, -17), S(-4, -63), S(-5, -60), S(-8, -17), S(1, -18), }},
  {{ S(0, 58), S(-4, 39), S(-7, 39), S(-4, 32), S(-3, 16), S(-8, 36), S(-4, 31), }},
  {{ S(-1, 53), S(-7, 37), S(-11, 37), S(-6, 39), S(-4, 38), S(-11, 33), S(-9, 39), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1051, 271, -16, 90
);

inline VParam WINNABLE_PAWNS = V(-24);
inline VParam WINNABLE_SYM = V(93);
inline VParam WINNABLE_ASYM = V(69);
inline VParam WINNABLE_BOTH_SIDES = V(535);
inline VParam WINNABLE_PAWN_ENDGAME = V(215);
inline VParam WINNABLE_BIAS = V(-803);

// Epoch duration: 5.70354s
// clang-format on
}  // namespace Clockwork
