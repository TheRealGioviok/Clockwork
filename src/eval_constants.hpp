#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(192, 506);
inline const PParam KNIGHT_MAT = S(828, 1546);
inline const PParam BISHOP_MAT = S(868, 1635);
inline const PParam ROOK_MAT   = S(1031, 2566);
inline const PParam QUEEN_MAT  = S(2452, 3876);

inline const PParam TEMPO_VAL  = S(69, 50);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -4);
inline const PParam BISHOP_PAIR_VAL   = S(66, 230);
inline const PParam ROOK_OPEN_VAL     = S(113, -5);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 10);
inline const PParam MINOR_BEHIND_PAWN = S(15, 39);
inline const PParam RESTRICTED_SQUARES = S(-22, -3);

inline const PParam DOUBLED_PAWN_VAL = S(-16, -86);
inline const PParam ISOLATED_PAWN_VAL = S(-3, -48);

inline const std::array<PParam, 5> PAWN_ISLANDS = {
    S(0, 0), S(318, -207), S(266, -128), S(231, -104), S(207, -78),
};

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -41);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 40);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 37);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 50);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(41, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 56);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(11, 2), S(26, 41), S(56, 68), S(124, 200), S(444, 262), S(569, 554),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(41, 39), S(33, 30), S(50, 59), S(95, 175), S(406, 96),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-78, -277), S(-80, -240), S(-60, -97), S(-24, 45), S(71, 241), S(211, 422),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -39), S(25, -0), S(13, 40), S(10, 121), S(73, 248), S(88, 467),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -36), S(2, 10), S(-4, -23), S(-2, -57), S(-10, -162), S(-160, -342),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(9, 234), S(-1, 185), S(1, 104), S(13, 61), S(24, 63), S(63, 61), S(55, 39),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-151, -54), S(11, 8), S(5, 105), S(33, 153), S(48, 188), S(60, 193), S(39, 183),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-89, -375), S(-29, -133), S(-0, -14), S(24, 33), S(52, 64), S(68, 100), S(86, 108), S(106, 115), S(126, 70),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-65, -282), S(-16, -103), S(34, -29), S(57, 21), S(79, 62), S(91, 91), S(98, 112), S(103, 131), S(107, 145), S(115, 150), S(122, 147), S(144, 126), S(148, 126), S(126, 103),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(110, -179), S(25, 10), S(45, 42), S(61, 60), S(72, 78), S(76, 92), S(81, 107), S(87, 111), S(92, 124), S(99, 130), S(105, 134), S(108, 142), S(112, 144), S(116, 134), S(136, 94),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-217, -152), S(-62, 20), S(-37, 144), S(-16, 271), S(1, 310), S(7, 363), S(14, 396), S(21, 412), S(25, 437), S(27, 455), S(32, 465), S(36, 472), S(38, 480), S(39, 487), S(39, 490), S(36, 495), S(33, 494), S(37, 487), S(35, 488), S(40, 476), S(39, 459), S(40, 442), S(15, 462), S(-32, 450), S(-59, 450), S(-85, 461), S(-117, 468), S(-102, 408),
};

inline const PParam PAWN_THREAT_KNIGHT = S(192, 150);
inline const PParam PAWN_THREAT_BISHOP = S(170, 213);
inline const PParam PAWN_THREAT_ROOK   = S(198, 136);
inline const PParam PAWN_THREAT_QUEEN  = S(149, 26);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 56), S(92, 92), S(103, 124), S(204, 123), S(159, 18), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(8, 57), S(53, 93), S(72, 95), S(21, -9), S(173, -56), S(0, 0),
};
inline const PParam KING_THREAT  = S(-15, 153);
inline const PParam HANGING_PAWN  = S(31, 89);
inline const PParam HANGING_NON_PAWN  = S(67, 23);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(6, -18), S(5, -15), S(0, -22), S(-5, -29), S(-11, -37), S(-16, -44), S(-19, -55), S(-25, -58), S(-31, -70),
};

inline const PParam ROOK_LINEUP = S(16, 79);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(185, 278),    S(30, 403),     S(59, 370),     S(146, 262),    S(197, 161),    S(124, 226),    S(86, 268),     S(239, 189),    //
    S(41, 69),      S(44, 117),     S(26, 59),      S(46, -21),     S(40, -56),     S(11, -19),     S(8, 31),       S(-12, 56),     //
    S(39, -10),     S(7, 4),        S(39, -42),     S(26, -65),     S(19, -86),     S(-1, -71),     S(-39, -37),    S(-32, -3),     //
    S(-1, -74),     S(-35, -36),    S(-2, -57),     S(-11, -68),    S(-29, -81),    S(-39, -69),    S(-85, -51),    S(-69, -55),    //
    S(-4, -113),    S(21, -104),    S(6, -43),      S(-9, -48),     S(-35, -60),    S(-51, -69),    S(-78, -69),    S(-72, -79),    //
    S(17, -108),    S(82, -91),     S(66, -37),     S(25, -12),     S(-6, -33),     S(-25, -58),    S(-49, -55),    S(-53, -61),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-259, -497),  S(-254, 54),    S(-271, -70),   S(36, 13),      S(-92, 41),     S(-262, 75),    S(-362, 110),   S(-351, -390),  //
    S(-6, -2),      S(2, 33),       S(99, 17),      S(85, 52),      S(90, 44),      S(57, 20),      S(-25, 28),     S(-29, 17),     //
    S(48, -29),     S(38, 30),      S(72, 48),      S(76, 68),      S(67, 62),      S(26, 53),      S(10, 32),      S(-40, 17),     //
    S(94, 26),      S(91, 49),      S(105, 64),     S(107, 108),    S(111, 108),    S(74, 73),      S(51, 41),      S(36, 38),      //
    S(75, 17),      S(103, 6),      S(99, 51),      S(92, 83),      S(80, 84),      S(74, 66),      S(61, 14),      S(22, 32),      //
    S(16, -36),     S(43, -16),     S(46, 25),      S(60, 60),      S(54, 58),      S(28, 20),      S(14, -7),      S(-27, -29),    //
    S(39, -24),     S(39, -6),      S(24, -10),     S(32, 17),      S(29, 13),      S(2, -36),      S(-30, -1),     S(-40, -86),    //
    S(-45, -71),    S(4, -17),      S(24, -35),     S(42, -23),     S(22, -5),      S(-14, -42),    S(-23, -15),    S(-66, -125),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-129, 31),    S(-180, 117),   S(-424, 188),   S(-260, 90),    S(-292, 142),   S(-292, 144),   S(-205, 122),   S(-119, 66),    //
    S(-27, -13),    S(-76, 98),     S(-36, 60),     S(-68, 73),     S(-67, 79),     S(-32, 46),     S(-8, 43),      S(-38, 20),     //
    S(40, 27),      S(15, 68),      S(33, 77),      S(26, 69),      S(25, 49),      S(19, 53),      S(14, 51),      S(18, 21),      //
    S(18, 3),       S(54, 26),      S(65, 42),      S(77, 65),      S(102, 52),     S(49, 23),      S(53, -2),      S(4, 3),        //
    S(46, -41),     S(48, 9),       S(83, 16),      S(95, 32),      S(79, 46),      S(70, 28),      S(23, 14),      S(20, -29),     //
    S(62, -25),     S(86, -22),     S(99, 10),      S(68, 36),      S(65, 19),      S(62, 21),      S(67, -0),      S(21, -13),     //
    S(32, -74),     S(114, -45),    S(71, -10),     S(50, 6),       S(34, 6),       S(53, -38),     S(51, -45),     S(45, -50),     //
    S(51, -73),     S(22, -8),      S(27, 2),       S(49, -24),     S(32, -13),     S(38, 22),      S(46, -10),     S(43, -51),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(188, 93),     S(220, 111),    S(172, 133),    S(152, 118),    S(213, 74),     S(178, 95),     S(190, 101),    S(165, 104),    //
    S(96, 149),     S(150, 149),    S(213, 107),    S(154, 111),    S(197, 91),     S(157, 115),    S(105, 146),    S(100, 148),    //
    S(66, 141),     S(186, 89),     S(215, 68),     S(194, 48),     S(190, 71),     S(133, 110),    S(132, 120),    S(76, 161),     //
    S(39, 112),     S(106, 114),    S(135, 86),     S(109, 90),     S(140, 72),     S(100, 115),    S(90, 127),     S(31, 154),     //
    S(3, 56),       S(74, 58),      S(70, 72),      S(39, 83),      S(49, 89),      S(37, 115),     S(18, 112),     S(-8, 120),     //
    S(17, -22),     S(90, 0),       S(78, 25),      S(60, 31),      S(70, 39),      S(42, 67),      S(43, 49),      S(-4, 61),      //
    S(-67, -17),    S(66, -60),     S(70, -21),     S(58, 10),      S(63, 8),       S(46, 26),      S(34, 10),      S(3, 18),       //
    S(-6, -41),     S(10, -1),      S(81, -18),     S(91, -22),     S(91, -15),     S(68, 11),      S(65, 1),       S(46, 6),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(68, 184),     S(139, 159),    S(49, 298),     S(-4, 389),     S(35, 340),     S(66, 254),     S(56, 184),     S(4, 225),      //
    S(51, 208),     S(54, 262),     S(16, 337),     S(-122, 469),   S(-69, 428),    S(-21, 329),    S(26, 200),     S(19, 182),     //
    S(5, 264),      S(35, 295),     S(-8, 385),     S(-49, 422),    S(-26, 401),    S(23, 284),     S(60, 181),     S(45, 138),     //
    S(17, 178),     S(5, 273),      S(-26, 322),    S(-50, 405),    S(-35, 407),    S(4, 262),      S(42, 177),     S(25, 140),     //
    S(8, 170),      S(1, 196),      S(-14, 249),    S(-39, 316),    S(-28, 339),    S(-4, 267),     S(2, 200),      S(31, 104),     //
    S(7, 67),       S(31, 85),      S(26, 159),     S(2, 181),      S(11, 193),     S(12, 221),     S(35, 146),     S(19, 119),     //
    S(-19, -76),    S(9, -73),      S(14, 0),       S(37, 43),      S(32, 84),      S(35, 60),      S(9, 95),       S(21, 73),      //
    S(-30, -55),    S(-14, -204),   S(16, -210),    S(31, -100),    S(38, -22),     S(38, -54),     S(35, -27),     S(6, 24),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(47, -533),    S(453, 39),     S(280, 197),    S(-1, 163),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(303, -145),   S(354, 158),    S(196, 194),    S(22, 138),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(165, 57),     S(218, 165),    S(121, 190),    S(-35, 163),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(2, 16),       S(89, 114),     S(-21, 162),    S(-93, 177),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-115, -7),    S(-33, 75),     S(-87, 137),    S(-172, 187),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-51, -35),    S(16, 29),      S(-69, 112),    S(-123, 157),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -84),     S(31, -8),      S(-32, 53),     S(-108, 109),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -200),   S(6, -85),      S(-76, -19),    S(-73, -40),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-88, -439);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 11), S(10, 5), S(5, 1), S(3, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 4), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(17, -21), S(-7, 5), S(-3, -9), S(7, -16), S(12, -28), S(6, -57), S(-4, -49), }},
  {{ S(2, 2), S(-22, -0), S(-17, 7), S(-10, 16), S(-7, 7), S(-10, -13), S(-20, -24), }},
  {{ S(-3, -1), S(-12, -10), S(-13, 19), S(-8, 19), S(-7, 11), S(-7, -17), S(-24, -45), }},
  {{ S(6, 9), S(-10, 19), S(-7, 41), S(-2, 44), S(-2, 39), S(4, 16), S(9, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(10, 25), S(-6, 2), S(-8, 11), S(-6, 29), S(1, 51),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 11), S(-43, -137), S(-8, -45), S(-0, 4), S(-2, 4), S(-6, 11), S(-5, 9), }},
  {{ S(9, -0), S(-23, -129), S(-5, -33), S(-4, -0), S(-1, -3), S(-8, 4), S(1, 2), }},
  {{ S(-1, 11), S(-9, -83), S(7, -17), S(0, 9), S(-4, 10), S(-10, 19), S(-6, 20), }},
  {{ S(1, -1), S(4, -65), S(-1, 27), S(-3, 25), S(-6, 9), S(-13, 11), S(-10, 20), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1371, 847, -19, -3
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(98);
inline VParam WINNABLE_ASYM = V(81);
inline VParam WINNABLE_PAWN_ENDGAME = V(124);
inline VParam WINNABLE_BIAS = V(-366);

// Epoch duration: 6.05426s
// clang-format on
}  // namespace Clockwork
