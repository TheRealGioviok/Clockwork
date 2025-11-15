#pragma once

#include "eval_types.hpp"

namespace Clockwork {
// clang-format off
inline const PParam PAWN_MAT   = S(307, 326);
inline const PParam KNIGHT_MAT = S(1127, 920);
inline const PParam BISHOP_MAT = S(1246, 976);
inline const PParam ROOK_MAT   = S(1695, 1716);
inline const PParam QUEEN_MAT  = S(3638, 2952);
inline const PParam TEMPO_VAL  = S(59, 18);

inline const PParam BISHOP_PAIR_VAL   = S(79, 178);
inline const PParam ROOK_OPEN_VAL     = S(104, -28);
inline const PParam ROOK_SEMIOPEN_VAL = S(38, 12);

inline const PParam DOUBLED_PAWN_VAL = S(-38, -79);

inline const PParam POTENTIAL_CHECKER_VAL = S(-75, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(8, 53);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(55, 19);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(56, -14);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(33, 34);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(55, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, 19), S(64, 33), S(75, 71), S(190, 142), S(557, 244), S(890, 1033)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(64, 43), S(59, 31), S(67, 57), S(146, 120), S(686, -88)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-67, -98), S(-57, -79), S(-31, -3), S(23, 76), S(44, 218), S(285, 308)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(35, -7), S(21, 27), S(23, 75), S(90, 151), S(142, 298)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -47), S(3, 1), S(-1, -28), S(7, -46), S(4, -96), S(-191, -147)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(12, 100), S(-21, 87), S(-14, 36), S(0, 8), S(9, 12), S(39, 9), S(17, -2)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-184, -54), S(30, -7), S(-12, 41), S(10, 70), S(14, 96), S(34, 96), S(-13, 115)
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-232, -226), S(-123, -64), S(-66, -10), S(-24, 23), S(23, 39), S(48, 75), S(86, 73), S(120, 74),
    S(165, 19)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-257, -292), S(-185, -108), S(-109, -44), S(-73, 5), S(-41, 37), S(-23, 58), S(-5, 72), S(12, 76),
    S(32, 80), S(45, 76), S(71, 64), S(135, 18), S(167, -5), S(229, -37)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-303, -248), S(-151, -96), S(-101, -33), S(-66, -23), S(-39, 1), S(-25, 23), S(-9, 35), S(12, 43),
    S(28, 53), S(47, 64), S(65, 65), S(77, 66), S(99, 71), S(110, 57), S(255, -71)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-1087, -887), S(-284, -602), S(-182, -507), S(-129, -311), S(-120, -106), S(-80, -3), S(-76, 108), S(-51, 121),
    S(-47, 173), S(-32, 202), S(-27, 222), S(-19, 241), S(-1, 232), S(10, 242), S(17, 237), S(31, 233),
    S(37, 224), S(36, 231), S(62, 186), S(84, 149), S(99, 131), S(141, 65), S(154, 55), S(314, -117),
    S(340, -152), S(458, -225), S(173, -68), S(182, -82)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(371, 73), S(84, -114), S(-20, -22), S(-36, 12), S(-61, 17), S(-95, 22), S(-75, 22), S(-85, 17),
    S(-83, -28)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(88, -31), S(159, -78)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(36, -6), S(139, -43)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(68, -50), S(54, -62), S(104, -64), S(162, -129)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-37, 28), S(-56, 37), S(0, -7), S(158, -96), S(351, -233)
};

inline const PParam PAWN_THREAT_KNIGHT = S(238, 59);
inline const PParam PAWN_THREAT_BISHOP = S(207, 102);
inline const PParam PAWN_THREAT_ROOK   = S(200, 58);
inline const PParam PAWN_THREAT_QUEEN  = S(176, -62);

inline const PParam KNIGHT_THREAT_BISHOP = S(106, 74);
inline const PParam KNIGHT_THREAT_ROOK   = S(244, 7);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -68);

inline const PParam BISHOP_THREAT_KNIGHT = S(111, 33);
inline const PParam BISHOP_THREAT_ROOK   = S(243, 55);
inline const PParam BISHOP_THREAT_QUEEN  = S(190, 48);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(2, -5), S(-1, -1), S(0, -11), S(-7, -22), S(-12, -26), S(-15, -32), S(-18, -39), S(-24, -38),
    S(-34, -43)
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(114, 165), S(105, 212), S(171, 178), S(237, 59), S(182, 53), S(168, 120), S(62, 140), S(123, 119),
    S(63, 33), S(176, 61), S(151, 4), S(153, -52), S(107, -70), S(50, -23), S(12, 27), S(-40, 29),
    S(-17, 2), S(3, 6), S(16, -42), S(5, -55), S(-13, -58), S(-54, -52), S(-94, -4), S(-119, 18),
    S(-46, -50), S(-26, -18), S(-33, -55), S(-49, -49), S(-73, -56), S(-95, -50), S(-146, -3), S(-163, -13),
    S(-46, -77), S(17, -74), S(-32, -31), S(-63, -27), S(-85, -39), S(-125, -41), S(-141, -25), S(-165, -32),
    S(-36, -69), S(94, -67), S(49, -30), S(-9, -13), S(-47, -24), S(-81, -27), S(-107, -6), S(-144, -17)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-390, -163), S(-343, 59), S(-456, 238), S(-121, 69), S(-247, 91), S(-332, 101), S(-563, 83), S(-536, -22),
    S(7, -1), S(69, 10), S(174, -57), S(119, 11), S(119, 17), S(57, -10), S(-1, 14), S(-17, -33),
    S(65, -28), S(103, 18), S(197, 10), S(147, 33), S(146, 22), S(66, 31), S(55, 5), S(-39, 12),
    S(115, 5), S(106, 29), S(139, 35), S(117, 63), S(125, 49), S(91, 40), S(67, 0), S(41, 7),
    S(107, -13), S(133, -15), S(126, 10), S(100, 27), S(90, 36), S(86, 28), S(59, 3), S(47, -55),
    S(19, -23), S(50, -33), S(43, -13), S(55, 32), S(61, 28), S(3, 5), S(8, -36), S(-31, -43),
    S(21, -8), S(41, -37), S(28, -29), S(25, -11), S(11, -17), S(-14, -37), S(-4, -51), S(-59, -120),
    S(-29, -60), S(10, -15), S(28, -38), S(36, -30), S(29, -24), S(-19, -56), S(-32, -29), S(-80, -85)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-171, 69), S(-192, 52), S(-435, 76), S(-316, 89), S(-268, 93), S(-433, 119), S(-177, 97), S(-131, 68),
    S(0, -45), S(-18, 34), S(0, 18), S(-20, 20), S(-42, 33), S(-8, 25), S(-29, 17), S(-64, 18),
    S(26, 12), S(72, 3), S(153, 12), S(81, 12), S(56, 12), S(34, 27), S(90, -1), S(-13, 12),
    S(43, -31), S(57, 0), S(93, 6), S(94, 29), S(98, 29), S(37, 29), S(24, 1), S(-24, 9),
    S(45, -62), S(53, -23), S(59, -5), S(60, 19), S(54, 37), S(12, 27), S(-2, -10), S(-8, -55),
    S(60, -52), S(103, -32), S(107, -20), S(47, 24), S(28, 28), S(31, 26), S(62, -18), S(23, -48),
    S(44, -87), S(95, -64), S(66, -50), S(38, -21), S(31, -35), S(28, -50), S(12, -32), S(31, -97),
    S(40, -70), S(27, -20), S(31, -15), S(41, -52), S(50, -59), S(45, -19), S(41, -45), S(23, -49)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(110, 6), S(171, 3), S(103, 33), S(103, 29), S(111, 16), S(60, 31), S(66, 31), S(75, 38),
    S(17, 61), S(103, 37), S(177, 13), S(103, 57), S(120, 46), S(68, 55), S(7, 73), S(-3, 78),
    S(5, 38), S(155, -3), S(185, -9), S(185, -11), S(138, -3), S(65, 40), S(82, 27), S(-37, 76),
    S(-26, 34), S(51, 25), S(82, 17), S(105, -19), S(74, 5), S(13, 53), S(-6, 53), S(-76, 59),
    S(-87, -15), S(-6, -11), S(-24, 5), S(-40, 8), S(-43, 5), S(-63, 43), S(-91, 41), S(-111, 30),
    S(-113, -38), S(-38, -63), S(-43, -33), S(-63, -32), S(-45, -49), S(-97, 3), S(-97, -12), S(-122, -18),
    S(-175, -26), S(-74, -87), S(-51, -72), S(-45, -67), S(-53, -64), S(-73, -48), S(-93, -72), S(-123, -53),
    S(-139, -24), S(-108, -18), S(-54, -55), S(-30, -73), S(-44, -58), S(-56, -44), S(-72, -54), S(-90, -39)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(36, 32), S(78, -5), S(82, 0), S(-37, 132), S(33, 49), S(-24, 78), S(40, -6), S(-25, 17),
    S(23, 72), S(-52, 165), S(-54, 222), S(-143, 254), S(-116, 199), S(-125, 198), S(-78, 102), S(-40, 43),
    S(-19, 104), S(71, 101), S(10, 176), S(-6, 189), S(-49, 168), S(-79, 167), S(-9, 63), S(-44, 35),
    S(47, 17), S(51, 85), S(16, 121), S(5, 187), S(-18, 169), S(-25, 105), S(12, 11), S(-3, -24),
    S(10, 43), S(47, 5), S(22, 76), S(-19, 132), S(-31, 119), S(-24, 78), S(-13, 0), S(-9, -50),
    S(23, -115), S(48, -71), S(48, 0), S(-5, 24), S(7, -17), S(11, -11), S(20, -84), S(-3, -77),
    S(9, -220), S(41, -321), S(29, -185), S(46, -112), S(18, -93), S(36, -164), S(11, -102), S(-8, -99),
    S(-47, -142), S(14, -391), S(8, -380), S(37, -284), S(39, -203), S(42, -246), S(30, -206), S(-24, -133)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-166, -380), S(83, -25), S(-70, 26), S(-179, 51), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(186, -121), S(0, 138), S(18, 127), S(122, 54), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-41, 52), S(62, 132), S(102, 100), S(86, 53), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-262, 76), S(26, 90), S(19, 90), S(-34, 72), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-232, 33), S(-49, 64), S(-32, 70), S(-117, 106), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-139, 2), S(51, 2), S(-37, 57), S(-82, 82), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(75, -90), S(131, -45), S(40, -3), S(-39, 43), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-46, -116), S(83, -106), S(-18, -70), S(-33, -69), S(16, -16), S(16, -16), S(16, -16), S(16, -16)
};
// clang-format on
}  // namespace Clockwork
