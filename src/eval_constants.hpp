#pragma once

#include "eval_types.hpp"

namespace Clockwork {
// clang-format off
inline const PParam PAWN_MAT   = S(308, 325);
inline const PParam KNIGHT_MAT = S(1130, 916);
inline const PParam BISHOP_MAT = S(1251, 972);
inline const PParam ROOK_MAT   = S(1701, 1711);
inline const PParam QUEEN_MAT  = S(3665, 2925);
inline const PParam TEMPO_VAL  = S(59, 15);

inline const PParam BISHOP_PAIR_VAL   = S(80, 177);
inline const PParam ROOK_OPEN_VAL     = S(104, -28);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 13);

inline const PParam DOUBLED_PAWN_VAL = S(-37, -78);

inline const PParam POTENTIAL_CHECKER_VAL = S(-74, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(7, 51);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 44);

inline const PParam KNIGHT_PROTECTOR = S(0,0);
inline const PParam BISHOP_PROTECTOR = S(0,0);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 18);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(56, -14);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(55, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 19), S(63, 31), S(74, 70), S(190, 141), S(559, 243), S(910, 1066)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(64, 43), S(61, 31), S(67, 58), S(146, 120), S(687, -89)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-67, -97), S(-57, -79), S(-31, -2), S(22, 76), S(44, 218), S(286, 307)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(36, -5), S(21, 27), S(24, 76), S(92, 152), S(142, 297)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -45), S(3, 2), S(0, -27), S(7, -47), S(4, -96), S(-191, -146)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(12, 100), S(-21, 87), S(-13, 37), S(0, 7), S(9, 12), S(39, 9), S(18, -2)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-185, -54), S(30, -7), S(-12, 41), S(10, 71), S(15, 96), S(35, 96), S(-14, 115)
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-231, -225), S(-124, -63), S(-67, -10), S(-24, 23), S(23, 38), S(50, 76), S(86, 72), S(120, 75),
    S(166, 17)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-258, -290), S(-183, -106), S(-108, -44), S(-73, 6), S(-42, 37), S(-25, 58), S(-6, 72), S(13, 77),
    S(32, 81), S(46, 77), S(71, 63), S(136, 17), S(167, -4), S(228, -37)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-304, -245), S(-151, -97), S(-99, -33), S(-67, -23), S(-40, 1), S(-26, 23), S(-7, 35), S(11, 41),
    S(28, 53), S(47, 62), S(65, 64), S(77, 67), S(98, 70), S(109, 56), S(255, -72)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-1092, -878), S(-288, -611), S(-187, -511), S(-132, -310), S(-123, -104), S(-84, -1), S(-80, 109), S(-56, 122),
    S(-50, 177), S(-38, 203), S(-30, 227), S(-24, 242), S(-5, 234), S(6, 246), S(12, 240), S(26, 236),
    S(32, 227), S(32, 234), S(58, 190), S(80, 153), S(94, 135), S(136, 71), S(148, 62), S(306, -109),
    S(336, -150), S(489, -245), S(202, -85), S(231, -108)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(381, 60), S(83, -113), S(-21, -22), S(-36, 15), S(-63, 18), S(-97, 23), S(-75, 25), S(-85, 19),
    S(-86, -29)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(88, -31), S(158, -78)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(37, -6), S(137, -43)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(68, -48), S(53, -64), S(104, -63), S(162, -129)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-37, 27), S(-55, 37), S(0, -9), S(162, -98), S(358, -240)
};

inline const PParam PAWN_THREAT_KNIGHT = S(239, 58);
inline const PParam PAWN_THREAT_BISHOP = S(205, 99);
inline const PParam PAWN_THREAT_ROOK   = S(199, 56);
inline const PParam PAWN_THREAT_QUEEN  = S(178, -62);

inline const PParam KNIGHT_THREAT_BISHOP = S(105, 72);
inline const PParam KNIGHT_THREAT_ROOK   = S(243, 6);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -68);

inline const PParam BISHOP_THREAT_KNIGHT = S(110, 34);
inline const PParam BISHOP_THREAT_ROOK   = S(243, 55);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 49);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -6), S(-1, 0), S(0, -11), S(-5, -21), S(-11, -27), S(-17, -33), S(-18, -40), S(-24, -37),
    S(-34, -43)
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(115, 166), S(106, 213), S(172, 179), S(236, 59), S(182, 54), S(167, 119), S(63, 142), S(122, 119),
    S(63, 35), S(175, 62), S(152, 5), S(153, -53), S(107, -70), S(51, -21), S(12, 27), S(-38, 30),
    S(-18, 2), S(1, 5), S(18, -39), S(5, -53), S(-12, -57), S(-55, -51), S(-95, -3), S(-121, 18),
    S(-44, -47), S(-26, -18), S(-31, -52), S(-49, -49), S(-75, -58), S(-95, -50), S(-145, 0), S(-163, -12),
    S(-46, -76), S(17, -73), S(-33, -30), S(-64, -28), S(-85, -37), S(-123, -39), S(-141, -25), S(-165, -31),
    S(-36, -70), S(95, -65), S(50, -29), S(-9, -10), S(-46, -23), S(-82, -28), S(-107, -4), S(-144, -18)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-392, -161), S(-344, 60), S(-456, 237), S(-122, 69), S(-250, 93), S(-333, 100), S(-565, 85), S(-537, -20),
    S(5, -2), S(71, 11), S(172, -57), S(118, 9), S(119, 16), S(58, -9), S(-2, 11), S(-21, -35),
    S(62, -28), S(104, 18), S(196, 9), S(147, 32), S(146, 22), S(66, 30), S(54, 4), S(-40, 12),
    S(117, 6), S(107, 29), S(137, 34), S(115, 61), S(124, 48), S(92, 41), S(65, -1), S(41, 5),
    S(106, -14), S(131, -16), S(125, 10), S(98, 27), S(89, 35), S(85, 29), S(59, 1), S(44, -55),
    S(18, -23), S(48, -34), S(42, -14), S(54, 30), S(60, 27), S(3, 5), S(9, -35), S(-31, -41),
    S(20, -8), S(41, -36), S(25, -29), S(24, -10), S(12, -17), S(-16, -37), S(-5, -52), S(-62, -121),
    S(-29, -59), S(9, -16), S(27, -39), S(36, -32), S(28, -25), S(-19, -55), S(-32, -31), S(-81, -84)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-174, 68), S(-194, 49), S(-436, 76), S(-316, 89), S(-267, 93), S(-434, 118), S(-177, 96), S(-129, 70),
    S(-2, -45), S(-18, 34), S(0, 15), S(-19, 19), S(-43, 34), S(-8, 26), S(-28, 16), S(-65, 17),
    S(27, 13), S(74, 3), S(153, 12), S(82, 10), S(57, 14), S(32, 26), S(90, -3), S(-12, 14),
    S(44, -33), S(58, -1), S(93, 3), S(92, 28), S(98, 28), S(37, 27), S(25, 2), S(-23, 8),
    S(45, -61), S(54, -22), S(61, -5), S(61, 19), S(53, 36), S(12, 26), S(-3, -11), S(-8, -56),
    S(60, -52), S(106, -32), S(107, -20), S(50, 24), S(29, 29), S(30, 24), S(61, -18), S(23, -48),
    S(45, -88), S(95, -64), S(66, -50), S(37, -21), S(28, -36), S(30, -47), S(11, -33), S(31, -98),
    S(41, -68), S(28, -22), S(32, -15), S(43, -50), S(52, -60), S(48, -19), S(40, -47), S(23, -50)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(108, 5), S(173, 3), S(103, 34), S(103, 28), S(111, 17), S(59, 30), S(66, 33), S(74, 38),
    S(17, 62), S(104, 37), S(178, 15), S(103, 58), S(119, 45), S(67, 55), S(7, 73), S(-2, 79),
    S(5, 39), S(154, -2), S(184, -8), S(184, -12), S(139, -2), S(64, 39), S(81, 27), S(-38, 77),
    S(-25, 33), S(51, 26), S(82, 18), S(105, -19), S(74, 5), S(12, 53), S(-6, 53), S(-77, 60),
    S(-90, -16), S(-8, -11), S(-23, 7), S(-40, 7), S(-45, 4), S(-63, 44), S(-92, 41), S(-112, 30),
    S(-113, -36), S(-38, -63), S(-44, -33), S(-64, -32), S(-47, -50), S(-97, 4), S(-98, -14), S(-121, -17),
    S(-175, -26), S(-75, -86), S(-51, -71), S(-46, -68), S(-53, -64), S(-72, -47), S(-93, -70), S(-124, -53),
    S(-140, -25), S(-109, -19), S(-56, -55), S(-31, -72), S(-44, -57), S(-57, -45), S(-73, -53), S(-90, -37)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(36, 33), S(75, -2), S(80, 4), S(-40, 134), S(31, 52), S(-25, 79), S(40, -5), S(-23, 18),
    S(23, 71), S(-50, 166), S(-55, 222), S(-143, 254), S(-114, 199), S(-125, 197), S(-75, 102), S(-40, 42),
    S(-19, 103), S(70, 99), S(11, 176), S(-6, 187), S(-47, 169), S(-79, 167), S(-9, 62), S(-43, 34),
    S(49, 17), S(53, 84), S(17, 120), S(6, 184), S(-16, 168), S(-26, 103), S(12, 10), S(-2, -22),
    S(14, 43), S(49, 5), S(23, 75), S(-17, 132), S(-29, 118), S(-23, 76), S(-12, -2), S(-9, -52),
    S(24, -115), S(49, -72), S(48, -2), S(-4, 24), S(8, -19), S(11, -14), S(22, -84), S(-2, -78),
    S(9, -222), S(42, -321), S(30, -185), S(47, -112), S(20, -93), S(37, -164), S(12, -102), S(-6, -100),
    S(-46, -143), S(15, -392), S(11, -380), S(38, -285), S(40, -203), S(44, -248), S(31, -208), S(-23, -133)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-158, -381), S(86, -25), S(-68, 26), S(-179, 51), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(187, -119), S(1, 139), S(18, 124), S(123, 54), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-41, 52), S(62, 131), S(102, 99), S(86, 54), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-261, 76), S(27, 91), S(19, 89), S(-35, 73), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-233, 33), S(-50, 64), S(-34, 69), S(-117, 105), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-139, 3), S(52, 6), S(-38, 57), S(-81, 83), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(76, -88), S(129, -47), S(41, -2), S(-40, 42), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-46, -116), S(82, -106), S(-17, -70), S(-34, -69), S(16, -16), S(16, -16), S(16, -16), S(16, -16)
};
// Epoch duration: 78.8026s
// clang-format on
}  // namespace Clockwork
