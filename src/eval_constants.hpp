#pragma once

#include "eval_types.hpp"

namespace Clockwork {
// clang-format off
inline const PParam PAWN_MAT   = S(298, 321);
inline const PParam KNIGHT_MAT = S(1089, 896);
inline const PParam BISHOP_MAT = S(1206, 950);
inline const PParam ROOK_MAT   = S(1641, 1671);
inline const PParam QUEEN_MAT  = S(3374, 2936);
inline const PParam TEMPO_VAL  = S(58, 15);

inline const PParam BISHOP_PAIR_VAL   = S(77, 174);
inline const PParam ROOK_OPEN_VAL     = S(101, -25);
inline const PParam ROOK_SEMIOPEN_VAL = S(38, 14);

inline const PParam DOUBLED_PAWN_VAL = S(-37, -79);

inline const PParam POTENTIAL_CHECKER_VAL = S(-76, -1);
inline const PParam OUTPOST_KNIGHT_VAL    = S(7, 51);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 43);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 18);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(33, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(51, -46);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 19), S(62, 31), S(72, 69), S(185, 139), S(517, 250), S(627, 709)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(63, 42), S(59, 31), S(65, 57), S(143, 117), S(611, -53)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-69, -94), S(-59, -76), S(-32, -3), S(22, 75), S(50, 206), S(281, 301)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -43), S(36, -5), S(20, 29), S(21, 78), S(83, 157), S(163, 283)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -46), S(4, 2), S(-1, -27), S(6, -46), S(0, -91), S(-191, -141)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(12, 98), S(-21, 86), S(-14, 36), S(0, 7), S(9, 12), S(39, 9), S(18, -3)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-184, -54), S(27, -7), S(-13, 40), S(10, 69), S(15, 94), S(35, 93), S(-13, 113)
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-224, -226), S(-120, -64), S(-66, -12), S(-24, 22), S(22, 38), S(47, 76), S(83, 72), S(116, 75),
    S(162, 17)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-251, -288), S(-179, -105), S(-106, -44), S(-71, 6), S(-41, 36), S(-24, 57), S(-6, 71), S(12, 77),
    S(31, 80), S(45, 76), S(69, 63), S(134, 16), S(163, -3), S(227, -40)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-278, -289), S(-149, -94), S(-99, -29), S(-67, -19), S(-40, 4), S(-27, 26), S(-9, 38), S(9, 44),
    S(26, 56), S(44, 65), S(62, 67), S(74, 69), S(95, 71), S(106, 57), S(248, -68)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-996, -889), S(-274, -536), S(-179, -406), S(-119, -243), S(-108, -59), S(-68, 34), S(-63, 136), S(-37, 144),
    S(-31, 195), S(-19, 217), S(-9, 238), S(-2, 250), S(17, 237), S(30, 244), S(38, 233), S(54, 223),
    S(64, 208), S(69, 205), S(101, 150), S(131, 100), S(159, 65), S(227, -31), S(231, -34), S(326, -163),
    S(293, -164), S(245, -163), S(-7, -82), S(-86, -114)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(285, 142), S(91, -119), S(-10, -32), S(-24, 4), S(-51, 7), S(-84, 12), S(-64, 14), S(-73, 8),
    S(-73, -40)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(85, -29), S(154, -74)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(35, -5), S(134, -42)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(66, -46), S(48, -59), S(96, -56), S(143, -116)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-53, 64), S(-85, 99), S(-49, 77), S(81, 24), S(212, -62)
};

inline const PParam PAWN_THREAT_KNIGHT = S(234, 57);
inline const PParam PAWN_THREAT_BISHOP = S(200, 99);
inline const PParam PAWN_THREAT_ROOK   = S(194, 57);
inline const PParam PAWN_THREAT_QUEEN  = S(174, -64);

inline const PParam KNIGHT_THREAT_BISHOP = S(102, 71);
inline const PParam KNIGHT_THREAT_ROOK   = S(238, 5);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -77);

inline const PParam BISHOP_THREAT_KNIGHT = S(108, 34);
inline const PParam BISHOP_THREAT_ROOK   = S(237, 55);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 34);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -7), S(-2, -1), S(-1, -11), S(-6, -22), S(-12, -27), S(-17, -33), S(-18, -40), S(-24, -38),
    S(-34, -43)
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(115, 160), S(112, 204), S(169, 175), S(232, 58), S(181, 52), S(164, 116), S(64, 138), S(121, 115),
    S(60, 37), S(169, 65), S(147, 9), S(146, -46), S(101, -62), S(48, -16), S(11, 30), S(-39, 33),
    S(-17, 0), S(2, 4), S(18, -40), S(6, -54), S(-11, -57), S(-52, -51), S(-92, -4), S(-118, 17),
    S(-42, -47), S(-26, -20), S(-31, -53), S(-48, -49), S(-73, -58), S(-93, -50), S(-142, -1), S(-160, -13),
    S(-44, -77), S(16, -74), S(-33, -31), S(-64, -29), S(-83, -38), S(-122, -39), S(-139, -25), S(-162, -31),
    S(-35, -69), S(91, -64), S(47, -29), S(-10, -11), S(-46, -24), S(-81, -28), S(-106, -4), S(-142, -17)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-378, -152), S(-318, 49), S(-392, 196), S(-117, 66), S(-236, 86), S(-314, 92), S(-523, 68), S(-512, -22),
    S(2, 1), S(67, 12), S(166, -54), S(115, 7), S(117, 15), S(56, -9), S(-3, 12), S(-22, -32),
    S(58, -26), S(103, 13), S(189, 10), S(142, 31), S(141, 22), S(62, 31), S(52, 5), S(-41, 13),
    S(112, 7), S(104, 27), S(132, 34), S(112, 59), S(119, 48), S(88, 42), S(62, 0), S(38, 7),
    S(102, -12), S(126, -15), S(120, 9), S(92, 27), S(85, 35), S(81, 30), S(55, 2), S(41, -52),
    S(15, -21), S(46, -34), S(39, -14), S(50, 30), S(57, 27), S(1, 5), S(7, -34), S(-32, -39),
    S(17, -6), S(38, -35), S(22, -29), S(22, -10), S(9, -16), S(-17, -36), S(-7, -50), S(-62, -116),
    S(-31, -53), S(7, -13), S(24, -38), S(33, -31), S(25, -23), S(-20, -53), S(-34, -28), S(-82, -77)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-167, 65), S(-190, 47), S(-418, 70), S(-303, 84), S(-255, 87), S(-416, 111), S(-172, 92), S(-121, 65),
    S(-1, -44), S(-18, 34), S(2, 14), S(-17, 18), S(-41, 33), S(-6, 25), S(-27, 15), S(-62, 16),
    S(26, 13), S(72, 3), S(149, 12), S(78, 11), S(55, 14), S(31, 26), S(87, -2), S(-12, 14),
    S(43, -32), S(55, 0), S(90, 4), S(89, 29), S(95, 29), S(35, 27), S(23, 3), S(-23, 9),
    S(43, -59), S(51, -22), S(58, -5), S(57, 19), S(50, 36), S(10, 27), S(-5, -11), S(-9, -54),
    S(58, -51), S(103, -32), S(104, -20), S(47, 24), S(28, 29), S(28, 24), S(59, -17), S(21, -46),
    S(43, -85), S(92, -62), S(63, -50), S(35, -21), S(26, -36), S(28, -46), S(10, -31), S(29, -95),
    S(39, -65), S(26, -21), S(31, -15), S(41, -49), S(50, -59), S(45, -18), S(38, -45), S(20, -47)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(100, 8), S(164, 6), S(95, 36), S(97, 30), S(106, 18), S(54, 31), S(63, 34), S(71, 38),
    S(17, 61), S(102, 37), S(173, 16), S(104, 56), S(118, 44), S(67, 53), S(9, 71), S(0, 77),
    S(6, 39), S(151, -1), S(181, -7), S(181, -11), S(136, -2), S(65, 38), S(80, 27), S(-36, 75),
    S(-25, 33), S(50, 26), S(81, 18), S(105, -19), S(73, 5), S(13, 52), S(-6, 52), S(-74, 60),
    S(-87, -16), S(-8, -10), S(-23, 6), S(-39, 7), S(-45, 4), S(-62, 44), S(-91, 40), S(-109, 30),
    S(-110, -37), S(-37, -63), S(-43, -33), S(-63, -32), S(-46, -50), S(-95, 3), S(-96, -14), S(-118, -17),
    S(-170, -26), S(-73, -85), S(-50, -71), S(-46, -68), S(-52, -64), S(-70, -47), S(-90, -69), S(-121, -53),
    S(-137, -23), S(-107, -19), S(-55, -53), S(-30, -70), S(-44, -55), S(-56, -43), S(-71, -52), S(-88, -35)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(86, -58), S(138, -101), S(145, -88), S(43, 26), S(84, -20), S(32, 1), S(76, -62), S(3, -30),
    S(29, 48), S(-37, 135), S(-25, 166), S(-100, 186), S(-88, 156), S(-113, 173), S(-76, 98), S(-38, 31),
    S(-9, 77), S(74, 80), S(24, 146), S(4, 161), S(-40, 151), S(-80, 167), S(-13, 67), S(-45, 35),
    S(47, 9), S(47, 82), S(13, 116), S(-3, 191), S(-28, 182), S(-36, 115), S(-3, 33), S(-10, -11),
    S(6, 46), S(37, 15), S(9, 88), S(-37, 161), S(-50, 152), S(-42, 105), S(-27, 22), S(-25, -26),
    S(11, -98), S(34, -54), S(32, 21), S(-24, 56), S(-13, 17), S(-11, 25), S(4, -52), S(-17, -54),
    S(-6, -194), S(24, -287), S(11, -153), S(26, -74), S(-1, -54), S(17, -125), S(-8, -64), S(-21, -74),
    S(-60, -110), S(-2, -351), S(-7, -344), S(17, -244), S(20, -159), S(23, -203), S(12, -169), S(-39, -99)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-212, -340), S(48, -13), S(-81, 28), S(-151, 45), S(17, -16), S(17, -16), S(17, -16), S(17, -16),
    S(144, -103), S(0, 136), S(19, 121), S(135, 50), S(17, -16), S(17, -16), S(17, -16), S(17, -16),
    S(-46, 53), S(66, 128), S(104, 97), S(91, 52), S(17, -16), S(17, -16), S(17, -16), S(17, -16),
    S(-258, 75), S(28, 89), S(21, 88), S(-32, 72), S(17, -16), S(17, -16), S(17, -16), S(17, -16),
    S(-229, 31), S(-50, 63), S(-31, 68), S(-112, 103), S(17, -16), S(17, -16), S(17, -16), S(17, -16),
    S(-135, 0), S(52, 6), S(-37, 57), S(-78, 82), S(17, -16), S(17, -16), S(17, -16), S(17, -16),
    S(76, -88), S(127, -46), S(41, 0), S(-38, 42), S(17, -16), S(17, -16), S(17, -16), S(17, -16),
    S(-44, -119), S(83, -105), S(-15, -71), S(-32, -70), S(17, -16), S(17, -16), S(17, -16), S(17, -16)
};
// clang-format on
}  // namespace Clockwork
