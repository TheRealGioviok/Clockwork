#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(200, 458);
inline const PParam KNIGHT_MAT = S(911, 1338);
inline const PParam BISHOP_MAT = S(950, 1395);
inline const PParam ROOK_MAT   = S(1135, 2199);
inline const PParam QUEEN_MAT  = S(2706, 3454);
inline const PParam TEMPO_VAL  = S(65, 24);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, 14);
inline const PParam BISHOP_PAIR_VAL   = S(58, 238);
inline const PParam ROOK_OPEN_VAL     = S(124, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(46, 33);
inline const PParam MINOR_BEHIND_PAWN = S(14, 47);
inline const PParam RESTRICTED_SQUARES = S(-25, -6);

inline const PParam DOUBLED_PAWN_VAL = S(-20, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -27);

inline const PParam POTENTIAL_CHECKER_VAL = S(-51, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(55, 63);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 43);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(51, -23);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 56);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -43);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -0), S(35, 31), S(64, 60), S(131, 176), S(524, 170), S(411, 497),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(49, 40), S(46, 38), S(64, 69), S(114, 178), S(481, 93),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-99, -237), S(-96, -202), S(-72, -67), S(-30, 59), S(82, 230), S(250, 346),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(29, -40), S(19, 6), S(8, 42), S(14, 116), S(85, 236), S(156, 423),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -21), S(3, 17), S(-7, -12), S(2, -52), S(-19, -133), S(-230, -266),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(16, 217), S(-10, 185), S(-3, 100), S(8, 56), S(20, 55), S(60, 46), S(59, 32),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-228, -62), S(-5, 27), S(0, 99), S(35, 133), S(52, 163), S(63, 171), S(36, 174),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-108, -305), S(-45, -85), S(-14, 9), S(12, 49), S(44, 73), S(59, 109), S(79, 112), S(98, 123), S(133, 48),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-78, -283), S(-30, -79), S(26, 4), S(54, 48), S(75, 89), S(89, 118), S(95, 140), S(100, 153), S(100, 172), S(116, 154), S(117, 157), S(146, 107), S(139, 116), S(190, 5),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(110, -141), S(18, 58), S(40, 91), S(58, 106), S(68, 123), S(74, 135), S(79, 150), S(85, 155), S(91, 164), S(99, 170), S(106, 173), S(108, 182), S(109, 183), S(115, 158), S(177, 64),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-178, -118), S(-26, 37), S(2, 168), S(23, 287), S(41, 330), S(47, 387), S(52, 426), S(61, 438), S(65, 460), S(68, 474), S(74, 482), S(79, 486), S(80, 494), S(82, 496), S(79, 501), S(79, 499), S(72, 502), S(75, 489), S(79, 477), S(81, 465), S(76, 452), S(98, 414), S(71, 415), S(43, 380), S(14, 384), S(-8, 374), S(-1, 326), S(-8, 288),
};

inline const PParam PAWN_THREAT_KNIGHT = S(217, 126);
inline const PParam PAWN_THREAT_BISHOP = S(196, 180);
inline const PParam PAWN_THREAT_ROOK   = S(217, 121);
inline const PParam PAWN_THREAT_QUEEN  = S(183, 17);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 128);
inline const PParam KNIGHT_THREAT_ROOK   = S(232, 81);
inline const PParam KNIGHT_THREAT_QUEEN  = S(170, -30);

inline const PParam BISHOP_THREAT_KNIGHT = S(103, 77);
inline const PParam BISHOP_THREAT_ROOK   = S(225, 149);
inline const PParam BISHOP_THREAT_QUEEN  = S(185, 112);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -30), S(1, -11), S(-4, -19), S(-7, -30), S(-12, -39), S(-16, -48), S(-19, -56), S(-24, -61), S(-43, -42),
};

inline const PParam ROOK_LINEUP = S(16, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(214, 243),    S(66, 336),     S(136, 278),    S(186, 185),    S(206, 135),    S(131, 211),    S(83, 261),     S(221, 207),    //
    S(33, 47),      S(42, 79),      S(47, 18),      S(49, -54),     S(40, -89),     S(-4, -21),     S(-17, 37),     S(-40, 63),     //
    S(26, -16),     S(11, -16),     S(34, -57),     S(23, -89),     S(15, -99),     S(-8, -71),     S(-53, -27),    S(-58, 9),      //
    S(-9, -79),     S(-34, -53),    S(-1, -72),     S(-11, -87),    S(-32, -92),    S(-40, -71),    S(-100, -35),   S(-92, -40),    //
    S(-10, -111),   S(23, -110),    S(6, -43),      S(-10, -57),    S(-37, -63),    S(-54, -61),    S(-90, -47),    S(-93, -56),    //
    S(13, -105),    S(93, -110),    S(74, -51),     S(32, -23),     S(0, -40),      S(-22, -50),    S(-57, -36),    S(-72, -39),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-363, -372),  S(-307, 110),   S(-170, -262),  S(-23, 46),     S(-97, 55),     S(-278, 65),    S(-377, 100),   S(-427, -273),  //
    S(-47, -7),     S(-8, 1),       S(68, 21),      S(106, 31),     S(85, 49),      S(34, 30),      S(-55, 52),     S(-74, 4),      //
    S(27, -19),     S(41, 27),      S(85, 65),      S(89, 86),      S(68, 91),      S(19, 91),      S(-2, 41),      S(-45, 10),     //
    S(88, 16),      S(98, 60),      S(107, 86),     S(117, 118),    S(124, 116),    S(75, 93),      S(43, 62),      S(24, 40),      //
    S(75, 16),      S(108, 9),      S(101, 67),     S(91, 91),      S(76, 92),      S(71, 78),      S(49, 40),      S(10, 33),      //
    S(-1, -29),     S(32, -3),      S(38, 41),      S(50, 70),      S(45, 65),      S(16, 37),      S(6, -3),       S(-42, -36),    //
    S(21, -36),     S(31, -10),     S(11, -9),      S(21, 12),      S(13, 12),      S(-15, -28),    S(-41, -16),    S(-63, -92),    //
    S(-56, -84),    S(-1, -34),     S(14, -51),     S(29, -28),     S(15, -19),     S(-24, -41),    S(-35, -26),    S(-80, -127),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-163, 42),    S(-217, 145),   S(-431, 181),   S(-292, 118),   S(-363, 155),   S(-366, 151),   S(-261, 146),   S(-142, 71),    //
    S(-62, 1),      S(-92, 90),     S(-64, 73),     S(-99, 88),     S(-96, 88),     S(-58, 64),     S(-44, 59),     S(-69, 20),     //
    S(27, 27),      S(14, 55),      S(34, 72),      S(26, 74),      S(17, 53),      S(10, 58),      S(1, 55),       S(-7, 12),      //
    S(5, 11),       S(47, 30),      S(62, 49),      S(79, 89),      S(99, 77),      S(45, 39),      S(39, 14),      S(-13, 13),     //
    S(49, -57),     S(51, 3),       S(77, 37),      S(90, 56),      S(73, 66),      S(69, 40),      S(15, 25),      S(10, -23),     //
    S(60, -26),     S(89, -15),     S(99, 20),      S(70, 45),      S(63, 30),      S(54, 35),      S(59, 18),      S(10, 3),       //
    S(32, -66),     S(112, -44),    S(72, -21),     S(48, 7),       S(25, 11),      S(45, -33),     S(41, -41),     S(35, -32),     //
    S(50, -62),     S(33, -26),     S(27, 1),       S(47, -24),     S(30, -9),      S(34, 24),      S(44, -2),      S(38, -41),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(187, 128),    S(237, 108),    S(190, 136),    S(182, 111),    S(230, 82),     S(218, 88),     S(195, 122),    S(172, 145),    //
    S(86, 194),     S(162, 187),    S(222, 161),    S(176, 168),    S(203, 164),    S(182, 172),    S(122, 199),    S(102, 202),    //
    S(51, 184),     S(183, 136),    S(219, 121),    S(194, 108),    S(196, 129),    S(140, 167),    S(138, 167),    S(62, 220),     //
    S(23, 146),     S(117, 149),    S(132, 137),    S(110, 132),    S(147, 118),    S(97, 166),     S(100, 166),    S(25, 194),     //
    S(-6, 79),      S(73, 81),      S(65, 110),     S(33, 116),     S(39, 125),     S(33, 144),     S(9, 147),      S(-5, 134),     //
    S(11, -12),     S(96, 5),       S(74, 32),      S(52, 45),      S(61, 53),      S(34, 73),      S(42, 61),      S(-9, 67),      //
    S(-80, -14),    S(66, -53),     S(63, -20),     S(52, 6),       S(56, 14),      S(37, 29),      S(28, 15),      S(-8, 24),      //
    S(-17, -34),    S(12, -15),     S(69, -21),     S(80, -19),     S(81, -9),      S(58, 12),      S(53, 5),       S(32, 13),      //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(94, 166),     S(147, 150),    S(76, 219),     S(15, 303),     S(47, 281),     S(64, 232),     S(79, 159),     S(18, 238),     //
    S(62, 237),     S(69, 315),     S(49, 323),     S(-88, 431),    S(-43, 419),    S(3, 350),      S(50, 233),     S(42, 202),     //
    S(39, 248),     S(62, 311),     S(33, 360),     S(-3, 374),     S(11, 382),     S(59, 303),     S(64, 259),     S(76, 177),     //
    S(54, 146),     S(48, 235),     S(13, 309),     S(-4, 370),     S(11, 390),     S(37, 270),     S(58, 230),     S(56, 158),     //
    S(46, 119),     S(34, 171),     S(13, 243),     S(-17, 322),    S(-2, 354),     S(19, 303),     S(27, 222),     S(54, 140),     //
    S(33, 58),      S(53, 84),      S(51, 161),     S(26, 191),     S(33, 224),     S(37, 241),     S(59, 175),     S(38, 136),     //
    S(14, -92),     S(25, -24),     S(31, 30),      S(52, 70),      S(49, 117),     S(49, 98),      S(31, 114),     S(43, 100),     //
    S(-6, -62),     S(19, -199),    S(41, -179),    S(52, -77),     S(55, 11),      S(58, -38),     S(55, -2),      S(25, 41),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-38, -259),   S(328, 336),    S(186, 355),    S(-62, 258),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(167, 32),     S(244, 362),    S(109, 345),    S(-55, 248),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(119, 134),    S(151, 263),    S(38, 285),     S(-83, 226),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, 59),     S(49, 157),     S(-93, 233),    S(-186, 249),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-89, -32),    S(-29, 60),     S(-134, 150),   S(-252, 216),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -78),    S(31, -11),     S(-85, 88),     S(-160, 154),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(47, -140),    S(52, -62),     S(-30, 3),      S(-106, 64),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(2, -241),     S(28, -134),    S(-61, -81),    S(-58, -90),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-86, -430);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -4), S(15, -18), S(14, -1), S(6, -5), S(1, -23),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -8), S(6, -22), S(4, -11), S(4, -0), S(4, 6),
};

inline const PParam KS_FLANK_ATTACK = S(4, -8);
inline const PParam KS_FLANK_DEFENSE = S(-5, -1);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -5);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -6);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, 22), S(-6, 24), S(-5, -43), S(5, -25), S(6, -22), S(-11, -7), S(-24, 1), }},
  {{ S(-2, 108), S(-20, -196), S(-19, -34), S(-10, 40), S(-7, 47), S(-21, 72), S(-39, 62), }},
  {{ S(-6, 87), S(-11, -174), S(-11, 86), S(-4, 60), S(-5, 47), S(-13, 51), S(-39, 45), }},
  {{ S(6, 99), S(-11, 70), S(-0, 71), S(6, 59), S(4, 42), S(5, 46), S(2, 39), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(15, 101), S(-8, 63), S(-11, 85), S(-2, 103), S(13, 61),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 121), S(-56, -355), S(-10, -276), S(8, -253), S(-6, 59), S(-10, 75), S(-8, 80), }},
  {{ S(9, 44), S(-26, -408), S(1, -361), S(-3, -26), S(-3, 9), S(-10, 29), S(1, 28), }},
  {{ S(0, 71), S(-10, -367), S(7, -31), S(3, 11), S(-3, 38), S(-9, 56), S(-3, 49), }},
  {{ S(-2, 63), S(-5, -109), S(7, -28), S(5, 22), S(-7, 46), S(-14, 51), S(-11, 55), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1097, 307, -14, 60
);

inline VParam WINNABLE_PAWNS = V(-25);
inline VParam WINNABLE_SYM = V(131);
inline VParam WINNABLE_ASYM = V(115);
inline VParam WINNABLE_PAWN_ENDGAME = V(175);
inline VParam WINNABLE_BIAS = V(-504);

// Epoch duration: 5.22011s
// clang-format on
}  // namespace Clockwork
