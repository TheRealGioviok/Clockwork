#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(192, 477);
inline const PParam KNIGHT_MAT = S(822, 1391);
inline const PParam BISHOP_MAT = S(866, 1482);
inline const PParam ROOK_MAT   = S(1000, 2428);
inline const PParam QUEEN_MAT  = S(2648, 3682);

inline const PParam TEMPO_VAL  = S(78, 54);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, -2);
inline const PParam BISHOP_PAIR_VAL   = S(51, 234);
inline const PParam ROOK_OPEN_VAL     = S(123, -10);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 9);
inline const PParam MINOR_BEHIND_PAWN = S(13, 42);
inline const PParam RESTRICTED_SQUARES = S(19, 11);

inline const PParam DOUBLED_PAWN_VAL = S(-15, -89);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -28);

inline const PParam POTENTIAL_CHECKER_VAL = S(-61, -19);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 46);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 45);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 48);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(45, -3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(18, 69);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -47);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, -8), S(34, 28), S(64, 57), S(130, 187), S(389, 284), S(488, 693),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 22), S(43, 19), S(57, 49), S(103, 150), S(395, 74),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-87, -243), S(-91, -211), S(-71, -80), S(-24, 34), S(89, 192), S(233, 313),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-135, 99), S(-148, 84), S(-109, 136), S(-179, 268), S(-173, 384), S(-93, 292),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-49, 94), S(-64, 81), S(-86, 116), S(-81, 158), S(10, 182), S(62, 150),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -45), S(25, -0), S(13, 38), S(9, 112), S(29, 295), S(242, 205),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(11, -26), S(-2, 21), S(0, -24), S(3, -68), S(-6, -170), S(-164, -429),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 224), S(2, 175), S(2, 90), S(15, 47), S(28, 48), S(67, 47), S(73, 0),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-116, -25), S(23, 15), S(3, 108), S(35, 137), S(48, 167), S(55, 178), S(30, 179),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-86, -365), S(-22, -151), S(9, -44), S(37, -10), S(69, 9), S(85, 40), S(106, 38), S(126, 45), S(154, -19),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-57, -309), S(-7, -131), S(43, -65), S(67, -22), S(89, 14), S(102, 39), S(109, 57), S(117, 67), S(120, 79), S(135, 69), S(147, 60), S(186, 11), S(208, -14), S(202, -57),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(128, -239), S(31, -43), S(52, -15), S(68, 1), S(79, 16), S(83, 28), S(88, 42), S(94, 44), S(98, 56), S(105, 61), S(111, 65), S(114, 71), S(122, 67), S(128, 50), S(212, -67),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-202, -220), S(-39, -82), S(-11, 31), S(11, 148), S(28, 188), S(35, 238), S(43, 266), S(49, 281), S(52, 307), S(56, 319), S(62, 328), S(66, 331), S(70, 337), S(76, 334), S(79, 333), S(81, 327), S(80, 323), S(90, 307), S(102, 288), S(116, 265), S(128, 230), S(175, 143), S(150, 174), S(163, 69), S(107, 130), S(152, 2), S(29, 146), S(223, -225),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 138);
inline const PParam PAWN_THREAT_BISHOP = S(188, 233);
inline const PParam PAWN_THREAT_ROOK   = S(211, 170);
inline const PParam PAWN_THREAT_QUEEN  = S(154, 80);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(4, 56), S(93, 84), S(102, 119), S(208, 125), S(158, 58), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(6, 51), S(57, 76), S(80, 76), S(9, 27), S(159, -63), S(0, 0),
};
inline const PParam KING_THREAT  = S(-8, 151);
inline const PParam HANGING_PAWN  = S(26, 88);
inline const PParam HANGING_NON_PAWN  = S(74, 32);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(17, 1), S(103, -78),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(41, 44), S(187, -232),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(40, 3), S(57, -39),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -28), S(2, -10), S(-2, -15), S(-6, -24), S(-12, -32), S(-17, -38), S(-19, -49), S(-25, -51), S(-31, -61),
};

inline const PParam ROOK_LINEUP = S(19, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(268, 179),    S(52, 386),     S(125, 383),    S(155, 298),    S(193, 206),    S(122, 274),    S(79, 311),     S(300, 132),    //
    S(66, 5),       S(64, 71),      S(52, 18),      S(54, -42),     S(41, -67),     S(20, -34),     S(12, 17),      S(-18, 43),     //
    S(44, -36),     S(19, -29),     S(48, -76),     S(37, -99),     S(26, -108),    S(3, -82),      S(-40, -36),    S(-43, -1),     //
    S(6, -98),      S(-29, -76),    S(-2, -92),     S(-4, -102),    S(-29, -100),   S(-39, -74),    S(-91, -45),    S(-83, -46),    //
    S(8, -137),     S(29, -132),    S(8, -72),      S(-5, -74),     S(-32, -79),    S(-52, -67),    S(-84, -59),    S(-86, -63),    //
    S(22, -128),    S(83, -122),    S(54, -65),     S(29, -34),     S(-3, -54),     S(-24, -60),    S(-54, -45),    S(-69, -44),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-249, -419),  S(-230, 12),    S(438, -1273),  S(10, 25),      S(-122, 47),    S(-202, -12),   S(-373, 98),    S(-336, -334),  //
    S(30, -44),     S(5, 26),       S(113, 16),     S(116, 37),     S(136, 4),      S(65, 32),      S(-30, 33),     S(-22, 7),      //
    S(80, -45),     S(69, -3),      S(92, 50),      S(105, 45),     S(85, 57),      S(29, 67),      S(16, 29),      S(-31, 16),     //
    S(116, 10),     S(116, 31),     S(124, 61),     S(122, 104),    S(119, 108),    S(80, 81),      S(55, 47),      S(46, 33),      //
    S(87, 5),       S(119, -6),     S(111, 48),     S(98, 89),      S(83, 87),      S(73, 77),      S(65, 20),      S(22, 33),      //
    S(20, -39),     S(45, -23),     S(46, 26),      S(59, 60),      S(52, 59),      S(24, 35),      S(11, 8),       S(-26, -26),    //
    S(38, -22),     S(36, -10),     S(21, -10),     S(30, 23),      S(26, 21),      S(1, -29),      S(-34, 5),      S(-47, -75),    //
    S(-38, -85),    S(11, -19),     S(27, -53),     S(45, -39),     S(23, -14),     S(-14, -49),    S(-21, -18),    S(-63, -135),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-106, -4),    S(-179, 71),    S(-439, 145),   S(-264, 49),    S(-306, 97),    S(-280, 41),    S(-188, 39),    S(-101, 13),    //
    S(-10, -43),    S(-63, 74),     S(-16, 27),     S(-51, 40),     S(-42, 25),     S(-20, 10),     S(6, 10),       S(-29, -8),     //
    S(61, -11),     S(55, -10),     S(45, 47),      S(46, 33),      S(36, 23),      S(24, 38),      S(42, -3),      S(35, -12),     //
    S(37, -29),     S(72, -3),      S(98, 2),       S(95, 49),      S(119, 32),     S(68, -1),      S(63, -17),     S(15, -19),     //
    S(60, -68),     S(61, -27),     S(91, -5),      S(112, 9),      S(92, 23),      S(77, 21),      S(31, -2),      S(31, -46),     //
    S(76, -54),     S(96, -55),     S(109, -22),    S(77, 14),      S(76, -4),      S(69, 11),      S(76, -15),     S(30, -27),     //
    S(44, -102),    S(120, -65),    S(77, -44),     S(54, -11),     S(35, -9),      S(64, -60),     S(58, -58),     S(54, -64),     //
    S(63, -108),    S(38, -63),     S(33, -20),     S(53, -52),     S(37, -45),     S(43, 0),       S(59, -48),     S(52, -74),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(183, 113),    S(237, 114),    S(195, 116),    S(181, 88),     S(231, 79),     S(197, 96),     S(197, 128),    S(157, 152),    //
    S(109, 157),    S(171, 154),    S(251, 83),     S(194, 77),     S(233, 85),     S(184, 110),    S(118, 164),    S(108, 174),    //
    S(71, 143),     S(197, 96),     S(238, 48),     S(213, 27),     S(202, 75),     S(135, 119),    S(130, 141),    S(73, 184),     //
    S(48, 86),      S(114, 92),     S(145, 56),     S(120, 53),     S(141, 60),     S(98, 108),     S(91, 123),     S(30, 155),     //
    S(19, 21),      S(92, 25),      S(82, 38),      S(45, 45),      S(50, 70),      S(41, 100),     S(26, 101),     S(3, 104),      //
    S(36, -60),     S(108, -38),    S(97, -27),     S(72, -17),     S(79, 11),      S(53, 39),      S(57, 26),      S(15, 30),      //
    S(-47, -69),    S(84, -102),    S(90, -75),     S(77, -44),     S(77, -29),     S(63, -12),     S(54, -25),     S(26, -24),     //
    S(13, -72),     S(32, -44),     S(100, -62),    S(111, -65),    S(108, -46),    S(87, -23),     S(85, -29),     S(67, -25),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(128, 92),     S(193, 93),     S(107, 228),    S(51, 313),     S(74, 286),     S(87, 230),     S(88, 147),     S(37, 180),     //
    S(78, 197),     S(97, 253),     S(78, 277),     S(-62, 370),    S(-22, 370),    S(21, 302),     S(63, 199),     S(42, 191),     //
    S(44, 208),     S(91, 241),     S(48, 309),     S(4, 333),      S(16, 345),     S(59, 272),     S(100, 178),    S(80, 129),     //
    S(44, 133),     S(54, 193),     S(0, 271),      S(-18, 347),    S(-11, 375),    S(24, 251),     S(71, 174),     S(42, 152),     //
    S(42, 87),      S(34, 113),     S(17, 172),     S(-19, 261),    S(-15, 307),    S(14, 252),     S(20, 190),     S(46, 115),     //
    S(26, 12),      S(54, 10),      S(47, 98),      S(20, 132),     S(23, 168),     S(27, 200),     S(46, 150),     S(29, 115),     //
    S(0, -145),     S(16, -96),     S(20, -34),     S(47, 18),      S(42, 62),      S(43, 52),      S(17, 83),      S(36, 52),      //
    S(-9, -142),    S(8, -283),     S(26, -253),    S(38, -127),    S(43, -24),     S(46, -68),     S(44, -47),     S(16, -2),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(35, -105),    S(349, 186),    S(211, 318),    S(-90, 370),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(211, 35),     S(396, 24),     S(224, 155),    S(7, 247),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(130, 135),    S(219, 147),    S(107, 203),    S(-58, 250),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-44, 97),     S(67, 149),     S(-89, 247),    S(-141, 259),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-134, 28),    S(-64, 92),     S(-131, 164),   S(-227, 232),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -32),    S(25, 14),      S(-83, 108),    S(-151, 170),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(37, -97),     S(41, -31),     S(-39, 24),     S(-115, 91),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, -182),   S(25, -108),    S(-70, -51),    S(-59, -70),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-53, -702);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -32), S(20, -27), S(19, -6), S(8, -16), S(2, -13),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, -23), S(8, -25), S(4, -15), S(5, -4), S(6, 8),
};

inline const PParam KS_FLANK_ATTACK = S(4, -9);
inline const PParam KS_FLANK_DEFENSE = S(-8, 4);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-4, -10);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(34, 37), S(8, 18), S(12, -90), S(23, -59), S(18, -12), S(-8, 42), S(-30, 12), }},
  {{ S(8, 197), S(-18, -341), S(-14, -64), S(-4, 1), S(-8, 101), S(-26, 159), S(-42, 134), }},
  {{ S(11, 138), S(-5, -280), S(-0, 128), S(7, 95), S(5, 83), S(-8, 99), S(-30, 103), }},
  {{ S(20, 160), S(-4, 114), S(8, 125), S(15, 105), S(9, 95), S(14, 105), S(12, 88), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(33, 135), S(2, 95), S(-1, 106), S(10, 119), S(28, 77),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(16, 178), S(-112, -521), S(-14, -333), S(21, -512), S(1, 63), S(-3, 99), S(-3, 110), }},
  {{ S(22, 34), S(-31, -636), S(-10, -306), S(-1, -6), S(1, -2), S(-6, 25), S(6, 16), }},
  {{ S(13, 81), S(-19, -362), S(9, -13), S(12, 33), S(3, 42), S(-3, 56), S(3, 52), }},
  {{ S(10, 80), S(0, -161), S(10, 39), S(11, 76), S(-2, 60), S(-11, 67), S(-5, 68), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        774, 329, 1, 91
);

inline VParam WINNABLE_PAWNS = V(-30);
inline VParam WINNABLE_SYM = V(129);
inline VParam WINNABLE_ASYM = V(110);
inline VParam WINNABLE_PAWN_ENDGAME = V(121);
inline VParam WINNABLE_BIAS = V(-390);

// Epoch duration: 9.7172s
// clang-format on
}  // namespace Clockwork
