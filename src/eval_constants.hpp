#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(177, 447);
inline const PParam KNIGHT_MAT = S(761, 1347);
inline const PParam BISHOP_MAT = S(859, 1579);
inline const PParam ROOK_MAT   = S(1011, 2479);
inline const PParam QUEEN_MAT  = S(2377, 3779);

inline const PParam TEMPO_VAL  = S(69, 49);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -4);
inline const PParam BISHOP_PAIR_VAL   = S(65, 230);
inline const PParam ROOK_OPEN_VAL     = S(110, -2);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 12);
inline const PParam MINOR_BEHIND_PAWN = S(15, 38);
inline const PParam RESTRICTED_SQUARES = S(-19, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-18, -86);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -35);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -40);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 40);
inline const PParam OUTPOST_BISHOP_VAL    = S(41, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 48);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(22, 58);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -9), S(39, 21), S(58, 65), S(133, 204), S(444, 269), S(567, 537),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 26), S(35, 27), S(60, 58), S(95, 179), S(412, 87),
};
inline const std::array<PParam, 6> BACKWARD_PAWN_VAL = {
    S(-9, -42), S(14, -31), S(-8, 0), S(19, 0), S(6, -7), S(0, 0),
};
inline const std::array<PParam, 5> PASSED_PAWN = {
    S(14, -95), S(18, -64), S(34, 85), S(79, 242), S(177, 449),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -37), S(24, 1), S(13, 42), S(11, 120), S(78, 247), S(110, 450),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -37), S(2, 10), S(-5, -22), S(-1, -58), S(-10, -166), S(-164, -340),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-47, 135), S(-59, 87), S(-62, 10), S(-51, -32), S(-40, -30), S(0, -32), S(-5, -56),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-180, -134), S(-27, -69), S(-40, 33), S(-15, 84), S(-2, 121), S(10, 126), S(-8, 116),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-51, -251), S(11, -7), S(40, 113), S(64, 160), S(92, 191), S(107, 227), S(125, 235), S(143, 244), S(162, 199),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-59, -251), S(-11, -74), S(38, 1), S(60, 52), S(81, 92), S(93, 121), S(98, 144), S(101, 163), S(104, 177), S(110, 184), S(116, 179), S(136, 161), S(138, 160), S(117, 136),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(117, -152), S(33, 37), S(53, 70), S(69, 87), S(79, 104), S(83, 118), S(88, 133), S(93, 138), S(98, 151), S(104, 158), S(109, 162), S(111, 170), S(113, 174), S(116, 165), S(141, 120),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-173, -135), S(-20, 44), S(4, 171), S(26, 294), S(43, 334), S(49, 387), S(56, 419), S(62, 435), S(66, 459), S(69, 477), S(75, 485), S(79, 492), S(82, 498), S(84, 504), S(85, 507), S(84, 510), S(81, 509), S(86, 500), S(85, 499), S(88, 493), S(85, 475), S(90, 456), S(58, 484), S(13, 471), S(-16, 473), S(-46, 492), S(-88, 501), S(-56, 431),
};

inline const PParam PAWN_THREAT_KNIGHT = S(195, 146);
inline const PParam PAWN_THREAT_BISHOP = S(170, 212);
inline const PParam PAWN_THREAT_ROOK   = S(195, 137);
inline const PParam PAWN_THREAT_QUEEN  = S(155, 17);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 56), S(91, 91), S(102, 124), S(203, 122), S(159, 11), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 56), S(52, 93), S(72, 94), S(21, -5), S(148, -51), S(0, 0),
};
inline const PParam KING_THREAT  = S(-19, 156);
inline const PParam HANGING_PAWN  = S(32, 87);
inline const PParam HANGING_NON_PAWN  = S(69, 21);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -19), S(26, -2),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(40, 46), S(124, -121),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(36, 12), S(48, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -16), S(4, -15), S(-0, -21), S(-6, -29), S(-11, -37), S(-16, -44), S(-18, -55), S(-23, -58), S(-27, -72),
};

inline const PParam ROOK_LINEUP = S(17, 78);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(-241, -424),  S(-388, -308),  S(-364, -337),  S(-283, -439),  S(-232, -541),  S(-305, -473),  S(-342, -430),  S(-200, -499),  //
    S(50, 89),      S(65, 130),     S(47, 72),      S(63, -5),      S(54, -38),     S(25, 1),       S(19, 55),      S(-12, 85),     //
    S(52, 24),      S(24, 28),      S(59, -14),     S(42, -38),     S(33, -57),     S(13, -40),     S(-27, -6),     S(-28, 38),     //
    S(14, -18),     S(-10, 9),      S(25, -12),     S(17, -25),     S(-4, -35),     S(-16, -21),    S(-64, -1),     S(-58, 5),      //
    S(2, -44),      S(32, -40),     S(20, 18),      S(6, 11),       S(-23, 2),      S(-37, -7),     S(-69, -1),     S(-68, -7),     //
    S(29, -48),     S(101, -35),    S(90, 13),      S(47, 37),      S(16, 18),      S(-2, -5),      S(-32, 5),      S(-44, 3),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-232, -433),  S(-227, 116),   S(-244, -11),   S(60, 77),      S(-67, 102),    S(-236, 134),   S(-341, 181),   S(-322, -329),  //
    S(17, 60),      S(26, 97),      S(121, 81),     S(105, 117),    S(108, 113),    S(78, 85),      S(-3, 95),      S(-6, 81),      //
    S(73, 34),      S(61, 92),      S(94, 110),     S(95, 134),     S(84, 131),     S(44, 120),     S(31, 98),      S(-17, 82),     //
    S(120, 88),     S(114, 114),    S(127, 128),    S(124, 175),    S(129, 175),    S(94, 139),     S(74, 107),     S(62, 100),     //
    S(102, 82),     S(128, 70),     S(123, 115),    S(114, 148),    S(101, 149),    S(98, 130),     S(85, 79),      S(47, 97),      //
    S(42, 28),      S(70, 47),      S(73, 88),      S(86, 123),     S(80, 121),     S(54, 83),      S(40, 56),      S(0, 32),       //
    S(65, 39),      S(68, 55),      S(52, 51),      S(59, 79),      S(56, 75),      S(29, 27),      S(-4, 63),      S(-14, -23),    //
    S(-17, -6),     S(32, 44),      S(51, 27),      S(69, 39),      S(49, 57),      S(13, 20),      S(5, 46),       S(-39, -59),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-122, 44),    S(-174, 130),   S(-416, 201),   S(-252, 103),   S(-288, 159),   S(-291, 167),   S(-205, 144),   S(-118, 89),    //
    S(-25, 7),      S(-72, 114),    S(-31, 74),     S(-63, 88),     S(-62, 93),     S(-30, 64),     S(-2, 58),      S(-39, 44),     //
    S(41, 47),      S(19, 85),      S(36, 94),      S(30, 85),      S(27, 67),      S(22, 71),      S(16, 69),      S(21, 38),      //
    S(20, 22),      S(57, 44),      S(67, 63),      S(80, 82),      S(106, 68),     S(50, 43),      S(55, 19),      S(7, 20),       //
    S(48, -22),     S(52, 26),      S(84, 37),      S(98, 49),      S(81, 67),      S(73, 48),      S(25, 32),      S(23, -10),     //
    S(64, -6),      S(88, -4),      S(102, 28),     S(70, 56),      S(68, 38),      S(64, 41),      S(70, 18),      S(23, 6),       //
    S(35, -57),     S(120, -28),    S(75, 7),       S(53, 24),      S(35, 26),      S(57, -19),     S(55, -28),     S(48, -31),     //
    S(55, -54),     S(24, 12),      S(30, 19),      S(52, -7),      S(35, 4),       S(41, 39),      S(50, 7),       S(46, -32),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(198, 106),    S(229, 123),    S(169, 156),    S(156, 136),    S(222, 86),     S(184, 111),    S(196, 118),    S(172, 121),    //
    S(102, 164),    S(153, 166),    S(212, 127),    S(156, 130),    S(197, 111),    S(159, 135),    S(108, 165),    S(104, 166),    //
    S(68, 159),     S(184, 107),    S(211, 88),     S(189, 69),     S(186, 93),     S(128, 131),    S(128, 140),    S(76, 181),     //
    S(42, 128),     S(103, 133),    S(132, 104),    S(104, 110),    S(135, 93),     S(95, 137),     S(86, 148),     S(31, 173),     //
    S(9, 71),       S(73, 78),      S(66, 93),      S(37, 103),     S(46, 108),     S(35, 134),     S(17, 132),     S(-4, 137),     //
    S(22, -5),      S(89, 19),      S(80, 42),      S(60, 50),      S(69, 60),      S(42, 87),      S(42, 71),      S(0, 79),       //
    S(-58, -4),     S(69, -42),     S(74, -5),      S(63, 28),      S(67, 26),      S(50, 43),      S(39, 28),      S(10, 36),      //
    S(2, -25),      S(17, 14),      S(88, -3),      S(98, -5),      S(97, 2),       S(74, 27),      S(72, 16),      S(53, 21),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(93, 189),     S(166, 162),    S(79, 299),     S(24, 393),     S(67, 337),     S(96, 255),     S(88, 180),     S(26, 235),     //
    S(76, 212),     S(98, 248),     S(64, 320),     S(-69, 450),    S(-17, 411),    S(28, 314),     S(73, 183),     S(44, 186),     //
    S(34, 263),     S(72, 292),     S(35, 373),     S(-2, 409),     S(20, 388),     S(68, 271),     S(98, 175),     S(77, 136),     //
    S(34, 194),     S(36, 277),     S(5, 323),      S(-6, 392),     S(9, 393),      S(37, 262),     S(75, 174),     S(45, 150),     //
    S(26, 186),     S(23, 207),     S(13, 255),     S(-12, 321),    S(-2, 343),     S(23, 270),     S(25, 206),     S(49, 116),     //
    S(18, 91),      S(47, 104),     S(44, 176),     S(22, 196),     S(30, 203),     S(32, 229),     S(52, 159),     S(31, 135),     //
    S(-11, -49),    S(18, -41),     S(26, 26),      S(49, 64),      S(45, 103),     S(47, 80),      S(21, 111),     S(33, 89),      //
    S(-22, -34),    S(-6, -178),    S(24, -179),    S(39, -71),     S(47, 4),       S(46, -29),     S(43, -6),      S(15, 41),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(98, -576),    S(480, 6),      S(295, 176),    S(0, 153),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(340, -178),   S(377, 134),    S(206, 179),    S(17, 138),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(185, 44),     S(226, 160),    S(119, 190),    S(-37, 164),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(16, 10),      S(94, 114),     S(-18, 160),    S(-93, 177),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-115, -2),    S(-32, 77),     S(-89, 139),    S(-174, 188),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-53, -30),    S(14, 33),      S(-73, 116),    S(-124, 159),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(21, -80),     S(28, -4),      S(-35, 57),     S(-111, 112),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -197),   S(3, -81),      S(-80, -15),    S(-77, -37),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-86, -438);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -5), S(10, 12), S(10, 5), S(5, 1), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 4), S(2, 2), S(3, -1), S(4, -1),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -21), S(-6, 5), S(-2, -9), S(8, -16), S(13, -28), S(7, -55), S(-5, -45), }},
  {{ S(3, 1), S(-21, -0), S(-16, 7), S(-9, 17), S(-6, 7), S(-10, -11), S(-20, -25), }},
  {{ S(-3, -0), S(-12, -9), S(-13, 20), S(-8, 19), S(-7, 11), S(-8, -15), S(-25, -43), }},
  {{ S(7, 10), S(-10, 19), S(-7, 41), S(-2, 45), S(-2, 41), S(4, 17), S(8, -13), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 25), S(-5, 0), S(-8, 11), S(-5, 28), S(2, 49),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 11), S(-46, -145), S(-8, -45), S(-1, 6), S(-2, 4), S(-5, 10), S(-5, 8), }},
  {{ S(9, -0), S(-25, -128), S(-6, -31), S(-5, 3), S(-1, -2), S(-8, 4), S(2, 2), }},
  {{ S(-0, 10), S(-10, -82), S(7, -16), S(0, 10), S(-3, 10), S(-10, 18), S(-6, 20), }},
  {{ S(2, -2), S(3, -65), S(-1, 26), S(-2, 25), S(-6, 7), S(-12, 10), S(-10, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1369, 846, -21, -4
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(84);
inline VParam WINNABLE_PAWN_ENDGAME = V(104);
inline VParam WINNABLE_BIAS = V(-376);

// Epoch duration: 6.44289s
// clang-format on
}  // namespace Clockwork
