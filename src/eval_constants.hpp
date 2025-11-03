#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(281, 365);
inline const PParam KNIGHT_MAT = S(1029, 1144);
inline const PParam BISHOP_MAT = S(1144, 1195);
inline const PParam ROOK_MAT   = S(1467, 2171);
inline const PParam QUEEN_MAT  = S(2963, 4033);
inline const PParam TEMPO_VAL  = S(95, 85);

inline const PParam BISHOP_PAIR_VAL  = S(70, 202);
inline const PParam ROOK_OPEN_VAL  = S(107, 6);
inline const PParam ROOK_SEMIOPEN_VAL  = S(41, 28);

inline const PParam DOUBLED_PAWN_VAL = S(-25, -91);

inline const PParam POTENTIAL_CHECKER_VAL = S(-67, -32);
inline const PParam OUTPOST_KNIGHT_VAL = S(19, 71);
inline const PParam OUTPOST_BISHOP_VAL = S(51, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(60, 39);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(66, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK = S(56, 36);
inline const PParam PAWN_PUSH_THREAT_QUEEN = S(63, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(23, 16), S(61, 45), S(71, 90), S(158, 222), S(540, 368), S(618, 822),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(70, 59), S(56, 53), S(62, 90), S(83, 194), S(594, 128),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-70, -158), S(-46, -130), S(-32, -16), S(35, 112), S(-40, 392), S(141, 473),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(64, -57), S(59, -34), S(44, 3), S(-6, 69), S(-9, 235), S(-230, 681),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(4, -53), S(24, -1), S(16, -41), S(30, -79), S(91, -271), S(-52, -338),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-32, 150), S(-67, 124), S(-36, 59), S(-10, 29), S(5, 32), S(66, 25), S(22, 21),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-206, -74), S(19, -15), S(-22, 68), S(6, 107), S(5, 141), S(16, 163), S(-44, 173),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-227, -214), S(-117, -45), S(-67, 53), S(-30, 91), S(0, 123), S(26, 166), S(54, 174), S(81, 190), S(104, 167),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-224, -69), S(-148, -25), S(-103, 32), S(-78, 87), S(-46, 114), S(-26, 143), S(-13, 161), S(1, 169), S(8, 177), S(26, 174), S(55, 158), S(90, 145), S(104, 145), S(140, 119),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-105, -462), S(-107, -47), S(-61, 22), S(-51, 65), S(-34, 85), S(-28, 109), S(-23, 140), S(-8, 155), S(-4, 174), S(8, 183), S(20, 190), S(21, 204), S(23, 213), S(44, 201), S(46, 185),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-1002, -891), S(-429, -706), S(-172, -384), S(-108, -8), S(-84, 134), S(-63, 148), S(-57, 222), S(-46, 281), S(-34, 322), S(-20, 329), S(-10, 347), S(0, 353), S(3, 370), S(16, 370), S(15, 382), S(32, 369), S(29, 385), S(30, 391), S(37, 385), S(70, 354), S(92, 338), S(136, 278), S(163, 285), S(281, 153), S(201, 244), S(685, -122), S(572, -65), S(778, -243),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(188, 110), S(52, -151), S(-17, -38), S(-16, 9), S(-47, 14), S(-49, 9), S(-54, 30), S(-61, 21), S(-16, -32),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(62, -22), S(124, -75),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(29, -7), S(135, -39),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(80, -69), S(91, -109), S(169, -97), S(142, -158),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-40, 4), S(-55, -17), S(-23, -56), S(123, -162), S(316, -267),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 82);
inline const PParam PAWN_THREAT_BISHOP = S(201, 153);
inline const PParam PAWN_THREAT_ROOK   = S(281, 18);
inline const PParam PAWN_THREAT_QUEEN  = S(269, -122);

inline const PParam KNIGHT_THREAT_BISHOP = S(101, 113);
inline const PParam KNIGHT_THREAT_ROOK   = S(235, 58);
inline const PParam KNIGHT_THREAT_QUEEN  = S(187, -75);

inline const PParam BISHOP_THREAT_KNIGHT = S(79, 77);
inline const PParam BISHOP_THREAT_ROOK   = S(179, 90);
inline const PParam BISHOP_THREAT_QUEEN  = S(226, 182);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-3, 6), S(0, 0), S(-1, -14), S(-6, -26), S(-10, -39), S(-12, -55), S(-15, -67), S(-18, -83), S(-25, -93),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(-57, 298),    S(39, 237),     S(184, 233),    S(187, 114),    S(212, 66),     S(70, 137),     S(64, 168),     S(14, 223),     //
    S(119, 90),     S(178, 85),     S(245, -27),    S(148, -95),    S(121, -111),   S(95, -62),     S(0, 53),       S(-17, 61),     //
    S(21, 15),      S(15, 16),      S(43, -42),     S(20, -68),     S(-26, -72),    S(-58, -41),    S(-74, 3),      S(-112, 33),    //
    S(-27, -18),    S(-15, 7),      S(-11, -42),    S(-27, -41),    S(-55, -51),    S(-77, -38),    S(-108, 0),     S(-144, -6),    //
    S(-16, -46),    S(30, -31),     S(-31, -21),    S(-46, -19),    S(-76, -23),    S(-96, -32),    S(-126, -12),   S(-164, -10),   //
    S(8, -39),      S(117, -22),    S(67, -7),      S(-11, 33),     S(-33, -7),     S(-60, -3),     S(-85, 21),     S(-133, 20),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-313, -235),  S(-271, -55),   S(-233, -26),   S(-37, -5),     S(-183, 49),    S(-297, 57),    S(-416, 59),    S(-363, -132),  //
    S(-52, -13),    S(49, 18),      S(63, -5),      S(-29, 23),     S(-25, 40),     S(-26, 46),     S(-20, 82),     S(-55, 47),     //
    S(37, 2),       S(-16, 24),     S(151, 0),      S(68, 64),      S(53, 74),      S(22, 70),      S(27, 26),      S(-14, 44),     //
    S(92, 42),      S(45, 98),      S(72, 89),      S(69, 97),      S(61, 101),     S(92, 74),      S(52, 63),      S(42, 77),      //
    S(64, 42),      S(51, 38),      S(85, 44),      S(47, 90),      S(74, 68),      S(50, 76),      S(62, 34),      S(18, 56),      //
    S(26, 17),      S(51, 6),       S(44, 16),      S(62, 69),      S(38, 73),      S(5, 41),       S(-13, 22),     S(-39, 18),     //
    S(26, 34),      S(12, 17),      S(11, 12),      S(17, 17),      S(6, 19),       S(-18, 21),     S(-20, 8),      S(-57, 6),      //
    S(-24, 17),     S(-17, 30),     S(27, 14),      S(14, 48),      S(18, 31),      S(-55, 5),      S(-25, 10),     S(-158, 9),     //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-147, 22),    S(-180, 85),    S(-214, 55),    S(-321, 93),    S(-313, 105),   S(-265, 77),    S(-141, 69),    S(-75, 76),     //
    S(-88, 21),     S(-121, 85),    S(-29, 45),     S(-43, 45),     S(-83, 72),     S(4, 46),       S(-1, 56),      S(-9, 34),      //
    S(24, 77),      S(25, 53),      S(103, 70),     S(4, 71),       S(34, 38),      S(12, 66),      S(44, 50),      S(4, 59),       //
    S(-22, 47),     S(54, 34),      S(41, 73),      S(55, 92),      S(48, 113),     S(49, 58),      S(26, 61),      S(-20, 63),     //
    S(71, -9),      S(-3, 50),      S(43, 51),      S(25, 91),      S(54, 85),      S(-3, 91),      S(-20, 66),     S(-9, 46),      //
    S(62, 14),      S(106, 25),     S(78, 61),      S(61, 87),      S(20, 83),      S(48, 87),      S(58, 75),      S(-7, 33),      //
    S(68, -6),      S(106, 0),      S(74, 15),      S(29, 40),      S(17, 51),      S(53, 1),       S(38, 10),      S(40, 13),      //
    S(107, -51),    S(70, 10),      S(18, 59),      S(49, 37),      S(9, 29),       S(39, 56),      S(69, 56),      S(37, 4),       //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(18, 81),      S(-90, 139),    S(27, 109),     S(-38, 101),    S(-115, 148),   S(-82, 143),    S(-36, 112),    S(-64, 131),    //
    S(78, 54),      S(54, 96),      S(64, 106),     S(-48, 132),    S(4, 135),      S(-50, 171),    S(-84, 161),    S(-80, 148),    //
    S(29, 46),      S(166, 44),     S(83, 51),      S(58, 71),      S(-23, 100),    S(-31, 126),    S(5, 111),      S(-86, 134),    //
    S(1, 62),       S(22, 76),      S(41, 65),      S(-1, 74),      S(-15, 96),     S(-22, 118),    S(-19, 112),    S(-78, 138),    //
    S(-62, 47),     S(4, 47),       S(-74, 73),     S(-55, 68),     S(-73, 81),     S(-84, 96),     S(-107, 100),   S(-118, 102),   //
    S(-20, 3),      S(35, -15),     S(-26, 22),     S(-48, 32),     S(-89, 61),     S(-92, 54),     S(-89, 48),     S(-123, 67),    //
    S(-62, -14),    S(10, -38),     S(-35, -1),     S(-40, 10),     S(-60, 24),     S(-67, 35),     S(-99, 42),     S(-114, 37),    //
    S(-96, -13),    S(-64, 25),     S(-51, 20),     S(-24, -2),     S(-42, 18),     S(-64, 43),     S(-67, 27),     S(-83, 44),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(-61, 29),     S(140, -88),    S(-10, 116),    S(-101, 173),   S(-47, 111),    S(-119, 146),   S(-149, 97),    S(-128, 117),   //
    S(109, 59),     S(-71, 155),    S(-89, 245),    S(-230, 332),   S(-171, 262),   S(-88, 167),    S(-52, 89),     S(-9, 61),      //
    S(-38, 111),    S(43, 85),      S(-46, 211),    S(-56, 211),    S(-59, 196),    S(-24, 145),    S(6, 44),       S(5, 50),       //
    S(51, 65),      S(45, 136),     S(17, 141),     S(-26, 194),    S(-25, 201),    S(2, 111),      S(28, 67),      S(5, 54),       //
    S(65, 48),      S(35, 101),     S(16, 119),     S(-14, 177),    S(-29, 196),    S(-20, 148),    S(-10, 110),    S(-4, 54),      //
    S(59, -8),      S(65, 48),      S(46, 83),      S(-3, 123),     S(-12, 113),    S(0, 128),      S(9, 76),       S(13, 12),      //
    S(48, -121),    S(62, -145),    S(47, -60),     S(30, 37),      S(26, 42),      S(20, 18),      S(18, 14),      S(43, -55),     //
    S(14, -145),    S(-22, -112),   S(-28, -36),    S(12, -30),     S(5, 43),       S(10, -7),      S(10, -23),     S(-25, 12),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(216, -325),   S(171, -121),   S(76, -65),     S(-76, -13),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-200, 39),    S(17, 126),     S(-37, 151),    S(197, 76),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-148, 57),    S(63, 141),     S(110, 150),    S(-41, 177),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-275, 44),    S(-128, 118),   S(-172, 154),   S(-275, 176),   S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-308, 2),     S(-136, 53),    S(-132, 90),    S(-271, 142),   S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-116, -33),   S(40, -6),      S(-42, 46),     S(-85, 82),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(102, -108),   S(139, -49),    S(41, 9),       S(-38, 44),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(47, -166),    S(94, -119),    S(-2, -48),     S(-4, -54),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
};
// Epoch duration: 61.8411s
// clang-format on
}
