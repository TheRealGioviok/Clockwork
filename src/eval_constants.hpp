#pragma once

#include "eval_types.hpp"

namespace Clockwork {
// clang-format off
inline const PParam PAWN_MAT   = S(308, 325);
inline const PParam KNIGHT_MAT = S(1130, 916);
inline const PParam BISHOP_MAT = S(1251, 972);
inline const PParam ROOK_MAT   = S(1699, 1711);
inline const PParam QUEEN_MAT  = S(3663, 2926);
inline const PParam TEMPO_VAL  = S(59, 15);

inline const PParam BISHOP_PAIR_VAL   = S(80, 177);
inline const PParam ROOK_OPEN_VAL     = S(103, -29);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 13);

inline const PParam DOUBLED_PAWN_VAL = S(-38, -79);

inline const PParam POTENTIAL_CHECKER_VAL = S(-75, -3);
inline const PParam OUTPOST_KNIGHT_VAL    = S(7, 51);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 18);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(56, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(55, -53);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 20), S(63, 31), S(74, 70), S(190, 141), S(559, 243), S(929, 1047)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(64, 43), S(61, 31), S(67, 58), S(146, 120), S(687, -89)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-68, -98), S(-58, -80), S(-32, -3), S(22, 76), S(45, 218), S(287, 307)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -45), S(36, -6), S(21, 27), S(24, 75), S(92, 152), S(142, 298)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -47), S(3, 2), S(-1, -28), S(7, -48), S(4, -97), S(-192, -147)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(12, 100), S(-22, 88), S(-14, 37), S(0, 7), S(9, 12), S(39, 9), S(18, -3)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-187, -55), S(29, -8), S(-13, 41), S(10, 71), S(14, 96), S(34, 96), S(-15, 116)
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-232, -227), S(-124, -63), S(-67, -11), S(-24, 23), S(23, 38), S(49, 76), S(86, 72), S(120, 75),
    S(165, 17)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-257, -291), S(-183, -106), S(-108, -44), S(-73, 6), S(-42, 37), S(-25, 57), S(-5, 72), S(13, 77),
    S(33, 80), S(46, 77), S(71, 63), S(136, 17), S(168, -4), S(228, -37)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-303, -245), S(-150, -97), S(-99, -33), S(-66, -23), S(-39, 1), S(-25, 23), S(-7, 35), S(12, 41),
    S(29, 54), S(47, 62), S(65, 64), S(78, 67), S(99, 70), S(110, 56), S(256, -72)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-1097, -880), S(-287, -611), S(-186, -511), S(-131, -311), S(-122, -105), S(-83, -1), S(-79, 108), S(-54, 122),
    S(-49, 176), S(-37, 202), S(-28, 227), S(-23, 241), S(-4, 233), S(7, 245), S(13, 239), S(27, 235),
    S(33, 226), S(33, 234), S(59, 189), S(81, 152), S(95, 134), S(137, 70), S(150, 61), S(308, -110),
    S(338, -151), S(478, -237), S(205, -87), S(220, -101)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(381, 63), S(84, -113), S(-21, -22), S(-35, 16), S(-63, 19), S(-97, 24), S(-76, 26), S(-85, 20),
    S(-86, -29)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(88, -32), S(158, -79)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(37, -7), S(137, -44)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(68, -49), S(53, -65), S(104, -64), S(162, -130)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-38, 27), S(-56, 37), S(-1, -10), S(162, -99), S(358, -241)
};

inline const PParam PAWN_THREAT_KNIGHT = S(239, 58);
inline const PParam PAWN_THREAT_BISHOP = S(205, 99);
inline const PParam PAWN_THREAT_ROOK   = S(198, 56);
inline const PParam PAWN_THREAT_QUEEN  = S(178, -62);

inline const PParam KNIGHT_THREAT_BISHOP = S(105, 72);
inline const PParam KNIGHT_THREAT_ROOK   = S(243, 5);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -69);

inline const PParam BISHOP_THREAT_KNIGHT = S(110, 34);
inline const PParam BISHOP_THREAT_ROOK   = S(243, 55);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 49);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -7), S(-2, -1), S(-1, -12), S(-6, -22), S(-12, -28), S(-17, -34), S(-19, -41), S(-25, -38),
    S(-35, -44)
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(115, 165), S(105, 212), S(172, 178), S(236, 58), S(182, 53), S(167, 118), S(63, 141), S(122, 118),
    S(63, 34), S(176, 62), S(152, 4), S(153, -54), S(107, -70), S(51, -21), S(13, 26), S(-38, 29),
    S(-18, 1), S(2, 4), S(18, -40), S(5, -54), S(-12, -58), S(-54, -52), S(-94, -4), S(-121, 17),
    S(-44, -47), S(-26, -19), S(-31, -53), S(-49, -50), S(-75, -59), S(-95, -50), S(-146, -1), S(-164, -13),
    S(-46, -77), S(18, -74), S(-33, -31), S(-64, -28), S(-84, -38), S(-124, -39), S(-142, -25), S(-166, -32),
    S(-36, -71), S(95, -66), S(50, -30), S(-9, -11), S(-46, -23), S(-82, -28), S(-107, -5), S(-145, -18)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-392, -162), S(-345, 60), S(-456, 237), S(-121, 69), S(-250, 93), S(-334, 100), S(-565, 85), S(-537, -20),
    S(5, -2), S(72, 11), S(173, -57), S(119, 9), S(120, 16), S(59, -9), S(-2, 11), S(-20, -35),
    S(63, -28), S(105, 18), S(197, 9), S(148, 32), S(147, 21), S(67, 30), S(55, 4), S(-40, 12),
    S(117, 6), S(107, 28), S(138, 34), S(116, 61), S(125, 48), S(92, 41), S(66, -1), S(42, 5),
    S(106, -14), S(132, -16), S(126, 10), S(99, 27), S(90, 35), S(86, 29), S(60, 1), S(45, -55),
    S(18, -23), S(49, -34), S(42, -14), S(54, 30), S(61, 27), S(3, 5), S(10, -35), S(-30, -41),
    S(21, -8), S(42, -36), S(26, -30), S(25, -11), S(12, -17), S(-15, -37), S(-4, -52), S(-61, -120),
    S(-28, -60), S(10, -16), S(28, -39), S(36, -32), S(28, -25), S(-19, -55), S(-31, -31), S(-80, -84)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-175, 68), S(-195, 50), S(-437, 76), S(-317, 90), S(-268, 93), S(-435, 119), S(-178, 96), S(-130, 70),
    S(-2, -44), S(-18, 35), S(0, 16), S(-20, 20), S(-44, 35), S(-8, 26), S(-29, 17), S(-65, 17),
    S(27, 13), S(74, 3), S(153, 12), S(81, 11), S(56, 14), S(32, 26), S(90, -2), S(-12, 14),
    S(44, -32), S(57, 0), S(93, 4), S(92, 29), S(98, 29), S(37, 27), S(24, 2), S(-23, 9),
    S(45, -61), S(53, -22), S(61, -5), S(60, 19), S(53, 36), S(12, 27), S(-4, -11), S(-8, -55),
    S(59, -51), S(105, -31), S(107, -19), S(49, 25), S(29, 30), S(30, 25), S(61, -18), S(23, -48),
    S(45, -87), S(95, -63), S(65, -50), S(37, -20), S(28, -36), S(30, -47), S(11, -32), S(30, -97),
    S(41, -68), S(27, -22), S(32, -15), S(42, -49), S(51, -60), S(47, -19), S(40, -46), S(22, -49)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(108, 4), S(174, 3), S(103, 33), S(103, 27), S(111, 16), S(59, 29), S(67, 32), S(74, 37),
    S(17, 61), S(104, 37), S(178, 14), S(104, 57), S(120, 45), S(67, 54), S(7, 72), S(-2, 79),
    S(6, 38), S(155, -3), S(185, -9), S(184, -12), S(139, -3), S(64, 38), S(82, 26), S(-37, 76),
    S(-25, 33), S(52, 25), S(83, 17), S(106, -19), S(74, 4), S(12, 52), S(-6, 52), S(-76, 60),
    S(-89, -16), S(-8, -11), S(-23, 6), S(-39, 7), S(-45, 4), S(-63, 43), S(-92, 40), S(-111, 30),
    S(-112, -37), S(-38, -63), S(-44, -34), S(-63, -32), S(-46, -51), S(-96, 3), S(-98, -14), S(-121, -17),
    S(-174, -26), S(-74, -87), S(-51, -72), S(-46, -69), S(-53, -65), S(-72, -48), S(-92, -71), S(-124, -54),
    S(-140, -25), S(-109, -20), S(-56, -56), S(-30, -73), S(-44, -58), S(-57, -46), S(-72, -54), S(-90, -38)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(36, 33), S(75, -1), S(80, 5), S(-40, 134), S(32, 52), S(-25, 80), S(40, -5), S(-24, 19),
    S(23, 71), S(-50, 166), S(-55, 222), S(-143, 254), S(-114, 199), S(-125, 197), S(-75, 102), S(-41, 42),
    S(-19, 103), S(70, 100), S(11, 176), S(-6, 187), S(-47, 169), S(-79, 167), S(-9, 62), S(-43, 34),
    S(49, 17), S(53, 84), S(17, 120), S(6, 184), S(-17, 169), S(-26, 103), S(12, 10), S(-2, -22),
    S(14, 43), S(48, 5), S(22, 75), S(-17, 132), S(-29, 118), S(-24, 76), S(-12, -2), S(-10, -52),
    S(24, -115), S(49, -72), S(48, -1), S(-4, 25), S(7, -18), S(10, -14), S(22, -84), S(-3, -77),
    S(9, -222), S(42, -321), S(30, -185), S(46, -112), S(20, -93), S(37, -164), S(11, -102), S(-7, -99),
    S(-46, -143), S(14, -392), S(10, -379), S(37, -285), S(40, -203), S(44, -248), S(30, -208), S(-23, -132)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-160, -382), S(85, -26), S(-70, 26), S(-180, 51), S(15, -16), S(15, -16), S(15, -16), S(15, -16),
    S(187, -120), S(0, 139), S(18, 124), S(123, 54), S(15, -16), S(15, -16), S(15, -16), S(15, -16),
    S(-42, 52), S(62, 131), S(102, 100), S(86, 54), S(15, -16), S(15, -16), S(15, -16), S(15, -16),
    S(-262, 76), S(26, 91), S(19, 89), S(-36, 73), S(15, -16), S(15, -16), S(15, -16), S(15, -16),
    S(-235, 33), S(-51, 64), S(-35, 69), S(-119, 105), S(15, -16), S(15, -16), S(15, -16), S(15, -16),
    S(-140, 3), S(52, 6), S(-39, 57), S(-82, 83), S(15, -16), S(15, -16), S(15, -16), S(15, -16),
    S(75, -88), S(129, -48), S(41, -1), S(-41, 42), S(15, -16), S(15, -16), S(15, -16), S(15, -16),
    S(-48, -117), S(82, -107), S(-18, -71), S(-35, -70), S(15, -16), S(15, -16), S(15, -16), S(15, -16)
};
// Epoch duration: 78.8026s
// clang-format on
}  // namespace Clockwork
