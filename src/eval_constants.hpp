#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(164, 248);
inline const PParam KNIGHT_MAT = S(673, 628);
inline const PParam BISHOP_MAT = S(710, 715);
inline const PParam ROOK_MAT   = S(866, 1323);
inline const PParam QUEEN_MAT  = S(2077, 182);

inline const PParam TEMPO_VAL  = S(64, 18);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, 0);
inline const PParam BISHOP_PAIR_VAL   = S(57, 91);
inline const PParam ROOK_OPEN_VAL     = S(100, -9);
inline const PParam ROOK_SEMIOPEN_VAL = S(40, -1);
inline const PParam MINOR_BEHIND_PAWN = S(13, 17);
inline const PParam RESTRICTED_SQUARES = S(15, 4);

inline const PParam DOUBLED_PAWN_VAL = S(-13, -38);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -10);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -5);
inline const PParam OUTPOST_KNIGHT_VAL    = S(42, 15);
inline const PParam OUTPOST_BISHOP_VAL    = S(35, 15);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(32, 21);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(34, 0);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(11, 35);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(56, -29);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, -2), S(26, 10), S(50, 22), S(110, 69), S(317, 34), S(359, -8),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(40, 9), S(31, 6), S(44, 19), S(85, 55), S(273, -14),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-85, -82), S(-78, -72), S(-48, -24), S(-1, 18), S(84, 88), S(191, 87),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-244, 27), S(-240, 50), S(-172, 68), S(-197, 113), S(-211, 159), S(-175, 117),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-25, 28), S(-43, 36), S(-74, 56), S(-75, 71), S(-17, 72), S(25, 61),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(18, -17), S(23, -1), S(14, 16), S(14, 40), S(40, 95), S(73, 44),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(4, -4), S(-6, 16), S(-1, -9), S(6, -32), S(2, -77), S(-118, -152),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(18, 91), S(6, 71), S(4, 37), S(12, 18), S(26, 15), S(58, 12), S(53, -0),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-145, -1), S(-26, 14), S(-16, 43), S(29, 40), S(51, 48), S(61, 51), S(46, 49),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-82, -232), S(-26, -142), S(-1, -97), S(20, -82), S(45, -73), S(57, -59), S(72, -59), S(87, -55), S(101, -78),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-59, -245), S(-15, -169), S(24, -140), S(44, -121), S(60, -105), S(70, -92), S(74, -83), S(77, -76), S(80, -71), S(84, -70), S(91, -73), S(100, -81), S(120, -96), S(76, -88),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(90, -260), S(10, -164), S(28, -152), S(40, -145), S(48, -139), S(52, -133), S(56, -127), S(60, -125), S(62, -120), S(67, -116), S(70, -114), S(70, -110), S(74, -111), S(73, -115), S(61, -125),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-261, -502), S(-40, -634), S(-15, -593), S(6, -544), S(21, -531), S(29, -513), S(37, -505), S(43, -503), S(48, -495), S(53, -493), S(59, -494), S(66, -497), S(71, -500), S(78, -506), S(85, -515), S(92, -526), S(96, -538), S(111, -557), S(126, -580), S(139, -601), S(144, -625), S(109, -641), S(152, -659), S(28, -620), S(50, -633), S(-36, -612), S(-55, -599), S(-48, -646),
};

inline const PParam PAWN_THREAT_KNIGHT = S(167, 53);
inline const PParam PAWN_THREAT_BISHOP = S(149, 93);
inline const PParam PAWN_THREAT_ROOK   = S(160, 73);
inline const PParam PAWN_THREAT_QUEEN  = S(125, 25);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(5, 23), S(75, 33), S(87, 44), S(171, 38), S(145, -22), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(10, 19), S(48, 30), S(69, 27), S(6, 13), S(148, -80), S(0, 0),
};
inline const PParam KING_THREAT  = S(24, 45);
inline const PParam HANGING_PAWN  = S(23, 31);
inline const PParam HANGING_NON_PAWN  = S(57, 8);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(20, -12), S(77, -123),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(44, 4), S(144, -238),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(42, -14), S(155, -216),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -10), S(2, -5), S(-0, -7), S(-4, -10), S(-9, -12), S(-13, -14), S(-15, -18), S(-20, -19), S(-25, -23),
};

inline const PParam ROOK_LINEUP = S(21, 23);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(181, 56),     S(54, 120),     S(103, 112),    S(133, 78),     S(159, 41),     S(109, 75),     S(73, 96),      S(205, 45),     //
    S(42, -52),     S(54, -39),     S(39, -59),     S(51, -83),     S(40, -92),     S(20, -74),     S(14, -48),     S(-17, -31),    //
    S(36, -79),     S(13, -76),     S(37, -99),     S(28, -105),    S(19, -106),    S(2, -92),      S(-34, -67),    S(-39, -51),    //
    S(3, -104),     S(-28, -92),    S(-10, -105),   S(-7, -107),    S(-26, -103),   S(-33, -89),    S(-75, -71),    S(-72, -70),    //
    S(0, -118),     S(14, -117),    S(-6, -98),     S(-11, -97),    S(-31, -97),    S(-47, -87),    S(-74, -78),    S(-76, -78),    //
    S(12, -115),    S(65, -114),    S(47, -88),     S(19, -85),     S(-6, -90),     S(-25, -86),    S(-51, -73),    S(-61, -69),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-213, -186),  S(-196, -24),   S(57, -388),    S(-28, -24),    S(-123, -11),   S(-181, -20),   S(-280, 11),    S(-272, -150),  //
    S(12, -60),     S(-4, -31),     S(76, -35),     S(69, -22),     S(80, -31),     S(42, -26),     S(-30, -25),    S(-26, -36),    //
    S(47, -61),     S(42, -38),     S(58, -17),     S(69, -18),     S(58, -15),     S(19, -11),     S(10, -29),     S(-35, -30),    //
    S(81, -38),     S(83, -30),     S(90, -15),     S(88, 4),       S(89, 4),       S(60, -7),      S(40, -23),     S(30, -28),     //
    S(59, -42),     S(82, -47),     S(77, -23),     S(71, -4),      S(58, -4),      S(53, -11),     S(43, -33),     S(10, -28),     //
    S(10, -64),     S(30, -59),     S(34, -38),     S(43, -23),     S(37, -21),     S(18, -33),     S(5, -43),      S(-26, -56),    //
    S(23, -60),     S(20, -55),     S(14, -59),     S(24, -42),     S(20, -42),     S(-4, -61),     S(-35, -44),    S(-46, -77),    //
    S(-40, -83),    S(10, -57),     S(14, -77),     S(28, -68),     S(14, -58),     S(-17, -70),    S(-20, -53),    S(-60, -99),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-94, -51),    S(-171, -8),    S(-345, 27),    S(-249, -8),    S(-278, 15),    S(-265, 2),     S(-194, -5),    S(-85, -42),    //
    S(-23, -74),    S(-60, -26),    S(-28, -42),    S(-64, -29),    S(-61, -33),    S(-32, -51),    S(-7, -56),     S(-40, -63),    //
    S(28, -66),     S(23, -56),     S(21, -37),     S(17, -41),     S(16, -50),     S(13, -46),     S(17, -59),     S(13, -66),     //
    S(10, -70),     S(39, -59),     S(59, -55),     S(64, -42),     S(86, -55),     S(42, -64),     S(36, -68),     S(-3, -68),     //
    S(27, -87),     S(28, -70),     S(59, -66),     S(77, -62),     S(62, -56),     S(49, -55),     S(12, -63),     S(10, -80),     //
    S(43, -83),     S(60, -89),     S(72, -78),     S(50, -59),     S(49, -65),     S(44, -61),     S(48, -69),     S(9, -72),      //
    S(14, -107),    S(83, -97),     S(49, -90),     S(32, -71),     S(16, -70),     S(36, -90),     S(33, -88),     S(27, -88),     //
    S(33, -108),    S(16, -90),     S(14, -73),     S(24, -88),     S(12, -85),     S(22, -63),     S(30, -81),     S(27, -90),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(104, -76),    S(114, -65),    S(67, -55),     S(89, -82),     S(145, -95),    S(124, -87),    S(132, -78),    S(112, -70),    //
    S(67, -51),     S(96, -45),     S(148, -71),    S(111, -76),    S(148, -75),    S(120, -67),    S(78, -48),     S(77, -47),     //
    S(33, -47),     S(117, -63),    S(142, -81),    S(131, -95),    S(136, -80),    S(87, -60),     S(86, -53),     S(44, -35),     //
    S(12, -66),     S(50, -55),     S(73, -72),     S(63, -81),     S(89, -84),     S(62, -66),     S(55, -58),     S(8, -44),      //
    S(-8, -99),     S(38, -90),     S(30, -88),     S(9, -90),      S(22, -83),     S(14, -69),     S(3, -67),      S(-14, -66),    //
    S(9, -144),     S(62, -135),    S(54, -131),    S(35, -129),    S(45, -115),    S(26, -103),    S(31, -108),    S(-1, -106),    //
    S(-55, -147),   S(45, -165),    S(50, -155),    S(41, -143),    S(45, -136),    S(35, -127),    S(29, -132),    S(11, -132),    //
    S(-3, -149),    S(13, -137),    S(67, -148),    S(75, -150),    S(77, -143),    S(61, -132),    S(61, -135),    S(48, -133),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(172, -416),   S(195, -410),   S(112, -307),   S(68, -231),    S(76, -218),    S(110, -261),   S(113, -302),   S(87, -306),    //
    S(68, -221),    S(93, -210),    S(81, -207),    S(-34, -143),   S(-9, -132),    S(23, -158),    S(47, -193),    S(36, -209),    //
    S(43, -221),    S(93, -229),    S(57, -182),    S(10, -152),    S(21, -142),    S(55, -174),    S(86, -221),    S(67, -239),    //
    S(34, -248),    S(46, -227),    S(-1, -172),    S(-21, -120),   S(-15, -106),   S(14, -162),    S(52, -204),    S(31, -217),    //
    S(26, -262),    S(17, -247),    S(0, -214),     S(-42, -140),   S(-39, -107),   S(-11, -143),   S(-1, -175),    S(24, -219),    //
    S(4, -286),     S(30, -296),    S(18, -242),    S(-6, -214),    S(-7, -185),    S(-6, -159),    S(18, -193),    S(6, -211),     //
    S(-28, -340),   S(-8, -339),    S(1, -313),     S(19, -270),    S(12, -240),    S(12, -237),    S(-14, -212),   S(9, -237),     //
    S(-34, -322),   S(-17, -398),   S(-8, -384),    S(2, -319),     S(11, -266),    S(11, -286),    S(13, -278),    S(-10, -250),   //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(63, -43),     S(194, 94),     S(177, 131),    S(97, 140),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(124, 36),     S(111, 98),     S(91, 130),     S(71, 140),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(32, 101),     S(-12, 154),    S(-41, 166),    S(-18, 151),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-92, 89),     S(-61, 131),    S(-127, 153),   S(-130, 143),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-111, 28),    S(-80, 63),     S(-111, 84),    S(-171, 104),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -20),    S(7, 4),        S(-67, 42),     S(-112, 65),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(48, -63),     S(47, -34),     S(-23, -5),     S(-92, 23),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(5, -93),      S(37, -58),     S(-50, -34),    S(-58, -39),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-66, -615);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -45), S(20, -20), S(19, -4), S(8, -7), S(2, 67),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -31), S(8, -24), S(4, -13), S(5, -7), S(7, 105),
};

inline const PParam KS_FLANK_ATTACK = S(3, -5);
inline const PParam KS_FLANK_DEFENSE = S(-8, 2);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -16);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-5, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(35, 53), S(12, 50), S(11, 46), S(22, 24), S(20, 19), S(-8, 51), S(-26, 46), }},
  {{ S(15, 79), S(-26, 62), S(-12, 53), S(1, 34), S(-3, 37), S(-23, 61), S(-40, 62), }},
  {{ S(19, 75), S(-5, 67), S(5, 55), S(12, 42), S(10, 44), S(-6, 59), S(-27, 65), }},
  {{ S(25, 67), S(-2, 47), S(11, 43), S(17, 37), S(9, 45), S(14, 52), S(10, 55), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(36, 103), S(2, 103), S(4, 62), S(18, 64), S(34, 36),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(23, 87), S(-112, -34), S(-19, 14), S(9, 61), S(4, 56), S(3, 62), S(0, 60), }},
  {{ S(25, 68), S(-44, 35), S(-13, 33), S(-1, 58), S(2, 26), S(-2, 34), S(11, 25), }},
  {{ S(17, 79), S(-27, 7), S(10, 36), S(12, 59), S(5, 44), S(-0, 45), S(7, 38), }},
  {{ S(14, 75), S(-2, 43), S(6, 48), S(12, 73), S(1, 42), S(-8, 51), S(-2, 53), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        555, 2623, 10, 105
);

inline VParam WINNABLE_PAWNS = V(-30);
inline VParam WINNABLE_SYM = V(80);
inline VParam WINNABLE_ASYM = V(65);
inline VParam WINNABLE_PAWN_ENDGAME = V(5);
inline VParam WINNABLE_BIAS = V(126);

// Epoch duration: 6.9406s
// clang-format on
}  // namespace Clockwork
