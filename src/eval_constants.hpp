#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(187, 490);
inline const PParam KNIGHT_MAT = S(799, 1530);
inline const PParam BISHOP_MAT = S(846, 1629);
inline const PParam ROOK_MAT   = S(1009, 2569);
inline const PParam QUEEN_MAT  = S(2377, 3888);
inline const PParam TEMPO_VAL  = S(65, 33);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -7);
inline const PParam BISHOP_PAIR_VAL   = S(62, 225);
inline const PParam ROOK_OPEN_VAL     = S(106, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, -0);
inline const PParam MINOR_BEHIND_PAWN = S(15, 35);
inline const PParam RESTRICTED_SQUARES = S(-23, -4);
inline const PParam LATENT_INVASION_SQUARES = S(8, 14);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -75);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -38);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -37);
inline const PParam OUTPOST_KNIGHT_VAL    = S(56, 45);
inline const PParam OUTPOST_BISHOP_VAL    = S(46, 37);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 52);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 51);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -3), S(31, 38), S(56, 69), S(124, 201), S(423, 292), S(588, 605),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 34), S(38, 27), S(53, 63), S(98, 194), S(404, 135),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-91, -263), S(-88, -228), S(-66, -94), S(-25, 41), S(71, 233), S(212, 393),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(25, -42), S(25, -5), S(12, 34), S(12, 111), S(77, 236), S(147, 422),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -39), S(2, 6), S(-6, -26), S(-6, -57), S(-10, -167), S(-166, -327),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(15, 233), S(-1, 183), S(-3, 107), S(7, 66), S(17, 69), S(58, 65), S(47, 48),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-126, -149), S(14, 23), S(2, 114), S(27, 160), S(37, 197), S(50, 202), S(33, 184),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-81, -365), S(-22, -134), S(7, -19), S(30, 22), S(58, 48), S(73, 80), S(91, 83), S(109, 87), S(127, 39),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-58, -272), S(-12, -109), S(37, -39), S(58, 9), S(79, 46), S(91, 70), S(96, 89), S(100, 105), S(103, 115), S(109, 118), S(118, 108), S(132, 89), S(137, 90), S(115, 58),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(107, -205), S(23, -16), S(44, 17), S(59, 33), S(70, 51), S(73, 65), S(78, 80), S(84, 85), S(88, 97), S(94, 103), S(99, 107), S(101, 113), S(102, 117), S(104, 107), S(132, 59),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-210, -128), S(-62, -20), S(-36, 100), S(-14, 218), S(1, 262), S(8, 314), S(14, 346), S(20, 363), S(24, 387), S(25, 406), S(31, 413), S(33, 423), S(36, 426), S(36, 433), S(36, 433), S(30, 438), S(25, 439), S(25, 430), S(24, 425), S(24, 419), S(17, 405), S(20, 381), S(-11, 407), S(-55, 391), S(-90, 399), S(-126, 419), S(-167, 435), S(-144, 359),
};

inline const PParam PAWN_THREAT_KNIGHT = S(200, 147);
inline const PParam PAWN_THREAT_BISHOP = S(192, 216);
inline const PParam PAWN_THREAT_ROOK   = S(206, 154);
inline const PParam PAWN_THREAT_QUEEN  = S(174, 23);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(8, 71), S(96, 90), S(113, 126), S(215, 134), S(180, 33), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(5, 68), S(67, 85), S(79, 95), S(-22, 36), S(206, -18), S(0, 0),
};
inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -18), S(4, -16), S(-0, -21), S(-5, -29), S(-11, -37), S(-16, -44), S(-18, -57), S(-24, -60), S(-26, -79),
};

inline const PParam ROOK_LINEUP = S(15, 76);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(183, 264),    S(40, 366),     S(72, 340),     S(135, 244),    S(190, 153),    S(118, 215),    S(83, 255),     S(220, 206),    //
    S(42, 50),      S(48, 91),      S(33, 33),      S(45, -41),     S(38, -76),     S(9, -34),      S(2, 22),       S(-21, 54),     //
    S(36, -16),     S(9, -8),       S(40, -52),     S(27, -74),     S(18, -94),     S(-4, -79),     S(-38, -45),    S(-40, -3),     //
    S(-7, -71),     S(-32, -39),    S(3, -63),      S(-6, -73),     S(-27, -84),    S(-37, -74),    S(-85, -54),    S(-76, -51),    //
    S(-12, -104),   S(20, -103),    S(6, -45),      S(-10, -52),    S(-36, -64),    S(-52, -73),    S(-80, -69),    S(-80, -71),    //
    S(10, -100),    S(79, -90),     S(68, -39),     S(21, -17),     S(-8, -42),     S(-27, -64),    S(-52, -58),    S(-61, -54),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-256, -526),  S(-256, 27),    S(-291, -101),  S(14, -8),      S(-91, 9),      S(-262, 48),    S(-382, 97),    S(-345, -398),  //
    S(-12, -34),    S(-12, 10),     S(92, -17),     S(76, 30),      S(89, 16),      S(47, 1),       S(-27, 11),     S(-36, -6),     //
    S(39, -44),     S(35, 22),      S(71, 41),      S(78, 52),      S(65, 54),      S(21, 57),      S(13, 17),      S(-38, -4),     //
    S(97, 8),       S(91, 35),      S(103, 62),     S(106, 100),    S(112, 101),    S(76, 72),      S(51, 33),      S(40, 20),      //
    S(76, 11),      S(106, 1),      S(102, 54),     S(94, 84),      S(81, 86),      S(79, 67),      S(65, 8),       S(25, 21),      //
    S(19, -36),     S(48, -11),     S(52, 36),      S(66, 66),      S(61, 64),      S(33, 31),      S(20, -5),      S(-21, -41),    //
    S(40, -25),     S(46, -12),     S(29, -3),      S(36, 24),      S(33, 19),      S(7, -33),      S(-25, -1),     S(-31, -110),   //
    S(-39, -88),    S(10, -26),     S(30, -37),     S(49, -28),     S(29, -8),      S(-7, -45),     S(-16, -26),    S(-58, -141),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-121, 9),     S(-175, 95),    S(-461, 188),   S(-279, 77),    S(-298, 124),   S(-302, 134),   S(-204, 108),   S(-122, 45),    //
    S(-33, -27),    S(-81, 88),     S(-38, 39),     S(-78, 62),     S(-69, 59),     S(-37, 35),     S(-11, 29),     S(-48, 6),      //
    S(36, 17),      S(13, 63),      S(33, 67),      S(32, 55),      S(24, 36),      S(19, 44),      S(9, 47),       S(18, 4),       //
    S(15, -12),     S(57, 17),      S(68, 36),      S(79, 57),      S(106, 41),     S(48, 25),      S(53, -5),      S(5, -14),      //
    S(51, -62),     S(51, -6),      S(83, 10),      S(101, 28),     S(83, 46),      S(72, 21),      S(25, 5),       S(22, -43),     //
    S(63, -44),     S(87, -29),     S(100, 9),      S(71, 39),      S(69, 20),      S(67, 21),      S(74, -10),     S(24, -30),     //
    S(35, -98),     S(117, -52),    S(75, -10),     S(53, 5),       S(36, 7),       S(56, -39),     S(54, -52),     S(49, -73),     //
    S(52, -89),     S(22, -15),     S(27, -2),      S(49, -25),     S(34, -20),     S(40, 14),      S(50, -21),     S(46, -62),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(155, 85),     S(196, 92),     S(145, 122),    S(134, 96),     S(190, 58),     S(148, 85),     S(168, 89),     S(139, 100),    //
    S(77, 127),     S(142, 114),    S(192, 81),     S(141, 86),     S(187, 66),     S(137, 97),     S(93, 121),     S(84, 127),     //
    S(57, 123),     S(179, 65),     S(205, 48),     S(183, 29),     S(179, 54),     S(123, 92),     S(127, 95),     S(70, 143),     //
    S(38, 94),      S(102, 100),    S(127, 71),     S(107, 75),     S(134, 63),     S(97, 101),     S(94, 107),     S(31, 138),     //
    S(11, 42),      S(82, 50),      S(69, 67),      S(45, 73),      S(54, 81),      S(41, 108),     S(21, 106),     S(-0, 107),     //
    S(23, -28),     S(95, -9),      S(83, 17),      S(64, 23),      S(74, 27),      S(43, 63),      S(50, 39),      S(4, 51),       //
    S(-64, -22),    S(71, -65),     S(73, -25),     S(60, 9),       S(64, 4),       S(49, 21),      S(39, 2),       S(12, 8),       //
    S(-1, -56),     S(12, -13),     S(83, -31),     S(93, -32),     S(93, -25),     S(71, -1),      S(70, -14),     S(52, -7),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(49, 160),     S(138, 104),    S(35, 260),     S(-25, 363),    S(17, 316),     S(54, 221),     S(50, 149),     S(-13, 198),    //
    S(45, 168),     S(57, 235),     S(15, 314),     S(-125, 447),   S(-70, 413),    S(-20, 313),    S(32, 166),     S(8, 157),      //
    S(-3, 231),     S(26, 275),     S(-5, 354),     S(-50, 396),    S(-29, 382),    S(22, 268),     S(53, 161),     S(49, 92),      //
    S(17, 136),     S(5, 246),      S(-25, 307),    S(-44, 383),    S(-26, 387),    S(7, 251),      S(49, 151),     S(24, 116),     //
    S(7, 135),      S(-0, 173),     S(-15, 238),    S(-33, 307),    S(-21, 333),    S(1, 255),      S(11, 169),     S(36, 76),      //
    S(6, 36),       S(29, 63),      S(23, 153),     S(1, 176),      S(12, 179),     S(15, 211),     S(36, 132),     S(25, 85),      //
    S(-23, -114),   S(5, -86),      S(10, -4),      S(33, 31),      S(28, 73),      S(32, 47),      S(8, 73),       S(22, 48),      //
    S(-36, -92),    S(-21, -230),   S(9, -232),     S(25, -120),    S(32, -43),     S(34, -76),     S(32, -49),     S(5, -11),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(119, -599),   S(455, -0),     S(268, 164),    S(-8, 130),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(313, -175),   S(313, 139),    S(149, 191),    S(-25, 148),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(145, 68),     S(160, 197),    S(65, 216),     S(-76, 174),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, 28),     S(49, 151),     S(-58, 188),    S(-111, 195),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, 3),     S(-46, 91),     S(-111, 155),   S(-184, 196),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-44, -33),    S(12, 42),      S(-70, 119),    S(-120, 160),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(27, -88),     S(31, -6),      S(-30, 57),     S(-103, 107),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, -199),   S(7, -84),      S(-73, -23),    S(-68, -45),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-101, -439);

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
  {{ S(18, -20), S(-6, 5), S(-2, -10), S(9, -18), S(14, -30), S(8, -55), S(-2, -45), }},
  {{ S(1, 3), S(-22, 3), S(-17, 9), S(-10, 17), S(-7, 9), S(-8, -18), S(-19, -23), }},
  {{ S(-2, -2), S(-10, -9), S(-12, 17), S(-7, 17), S(-6, 10), S(-6, -18), S(-21, -39), }},
  {{ S(7, 7), S(-9, 15), S(-6, 36), S(-2, 42), S(-2, 38), S(6, 12), S(11, -19), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 29), S(-4, 5), S(-7, 12), S(-4, 29), S(2, 49),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(6, 12), S(-46, -155), S(-9, -53), S(0, 5), S(-1, 4), S(-5, 11), S(-4, 10), }},
  {{ S(11, -1), S(-27, -171), S(-5, -34), S(-2, 2), S(1, -2), S(-6, 4), S(3, 2), }},
  {{ S(1, 11), S(-10, -94), S(8, -20), S(1, 10), S(-2, 12), S(-9, 19), S(-5, 21), }},
  {{ S(3, 2), S(4, -71), S(-1, 30), S(-2, 27), S(-5, 11), S(-11, 13), S(-9, 22), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1389, 886, -18, -9
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(100);
inline VParam WINNABLE_ASYM = V(83);
inline VParam WINNABLE_PAWN_ENDGAME = V(105);
inline VParam WINNABLE_BIAS = V(-372);

// Epoch duration: 8.95509s
// clang-format on
}  // namespace Clockwork
