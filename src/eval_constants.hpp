#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(309, 325);
inline const PParam KNIGHT_MAT = S(1234, 964);
inline const PParam BISHOP_MAT = S(1327, 988);
inline const PParam ROOK_MAT   = S(1696, 1717);
inline const PParam QUEEN_MAT  = S(3660, 2941);
inline const PParam TEMPO_VAL  = S(59, 15);

inline const PParam BISHOP_PAIR_VAL   = S(80, 177);
inline const PParam ROOK_OPEN_VAL     = S(105, -28);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 12);

inline const PParam DOUBLED_PAWN_VAL = S(-37, -78);

inline const PParam POTENTIAL_CHECKER_VAL = S(-73, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(6, 52);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 45);

inline const PParam KNIGHT_PROTECTOR = S(-23, -13);
inline const PParam BISHOP_PROTECTOR = S(-17, -3);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 17);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -14);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(55, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 20), S(63, 31), S(74, 71), S(190, 142), S(554, 247), S(910, 1066)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(63, 43), S(61, 32), S(67, 58), S(147, 121), S(684, -85)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-68, -97), S(-57, -78), S(-31, -2), S(23, 76), S(45, 218), S(287, 307)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(36, -6), S(21, 27), S(24, 75), S(92, 151), S(142, 296)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -46), S(3, 2), S(0, -27), S(6, -47), S(3, -97), S(-189, -148)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(11, 101), S(-19, 87), S(-11, 36), S(0, 7), S(9, 12), S(38, 10), S(15, 0)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-187, -55), S(29, -7), S(-14, 41), S(9, 71), S(15, 96), S(36, 96), S(-6, 114)
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-231, -227), S(-123, -64), S(-66, -11), S(-23, 23), S(24, 38), S(50, 76), S(86, 72), S(120, 74),
    S(166, 16)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-259, -293), S(-184, -108), S(-109, -45), S(-73, 5), S(-42, 36), S(-25, 57), S(-6, 71), S(13, 77),
    S(33, 80), S(46, 77), S(72, 64), S(136, 19), S(169, -3), S(227, -34)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-303, -248), S(-147, -99), S(-98, -34), S(-65, -24), S(-37, 0), S(-24, 22), S(-7, 35), S(12, 41),
    S(28, 54), S(46, 63), S(63, 66), S(75, 68), S(95, 71), S(106, 58), S(252, -71)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-1095, -882), S(-286, -619), S(-186, -509), S(-132, -312), S(-124, -103), S(-84, -2), S(-80, 108), S(-55, 121),
    S(-50, 176), S(-38, 201), S(-29, 226), S(-23, 241), S(-5, 233), S(6, 245), S(12, 240), S(26, 236),
    S(32, 228), S(32, 235), S(58, 191), S(80, 155), S(94, 137), S(136, 74), S(149, 65), S(307, -108),
    S(336, -148), S(483, -238), S(212, -87), S(214, -94)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(391, 60), S(95, -117), S(-14, -23), S(-33, 15), S(-63, 18), S(-100, 24), S(-82, 26), S(-95, 20),
    S(-98, -27)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(89, -30), S(159, -77)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(37, -5), S(135, -42)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(70, -46), S(53, -63), S(103, -64), S(157, -130)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-36, 26), S(-53, 34), S(3, -15), S(164, -106), S(358, -252)
};

inline const PParam PAWN_THREAT_KNIGHT = S(240, 56);
inline const PParam PAWN_THREAT_BISHOP = S(205, 99);
inline const PParam PAWN_THREAT_ROOK   = S(199, 57);
inline const PParam PAWN_THREAT_QUEEN  = S(178, -59);

inline const PParam KNIGHT_THREAT_BISHOP = S(104, 75);
inline const PParam KNIGHT_THREAT_ROOK   = S(242, 9);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -63);

inline const PParam BISHOP_THREAT_KNIGHT = S(110, 36);
inline const PParam BISHOP_THREAT_ROOK   = S(244, 56);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 48);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -7), S(-1, -1), S(0, -11), S(-5, -22), S(-11, -27), S(-16, -33), S(-18, -40), S(-23, -38),
    S(-33, -45)
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(114, 166), S(107, 212), S(172, 178), S(239, 58), S(186, 52), S(169, 118), S(65, 141), S(122, 118),
    S(64, 34), S(178, 62), S(152, 5), S(155, -53), S(108, -70), S(52, -21), S(14, 26), S(-37, 28),
    S(-19, 1), S(1, 5), S(17, -39), S(5, -53), S(-13, -57), S(-55, -51), S(-95, -4), S(-122, 18),
    S(-45, -47), S(-27, -19), S(-30, -52), S(-49, -49), S(-75, -58), S(-95, -50), S(-145, 0), S(-164, -13),
    S(-47, -76), S(17, -74), S(-33, -30), S(-63, -27), S(-85, -36), S(-123, -38), S(-142, -25), S(-166, -31),
    S(-39, -69), S(92, -65), S(47, -28), S(-9, -9), S(-47, -21), S(-82, -27), S(-108, -4), S(-145, -18)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-319, -133), S(-274, 75), S(-390, 262), S(-57, 89), S(-185, 115), S(-261, 123), S(-492, 110), S(-460, 15),
    S(47, 9), S(114, 17), S(218, -52), S(161, 16), S(161, 26), S(102, 4), S(39, 32), S(22, -5),
    S(78, -30), S(119, 14), S(215, -1), S(166, 24), S(164, 19), S(84, 35), S(75, 19), S(-4, 39),
    S(106, -6), S(98, 13), S(130, 16), S(108, 46), S(119, 37), S(88, 41), S(78, 11), S(72, 33),
    S(69, -31), S(96, -42), S(92, -17), S(67, 4), S(60, 20), S(74, 27), S(68, 14), S(77, -27),
    S(-35, -45), S(-12, -63), S(-17, -43), S(0, 6), S(23, 10), S(-16, 5), S(14, -20), S(-2, -14),
    S(-55, -32), S(-41, -64), S(-55, -57), S(-41, -35), S(-32, -34), S(-35, -37), S(1, -37), S(-35, -91),
    S(-83, -81), S(-55, -43), S(-51, -67), S(-27, -54), S(-21, -37), S(-42, -52), S(-31, -16), S(-54, -55)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-116, 71), S(-145, 54), S(-387, 79), S(-273, 95), S(-222, 99), S(-390, 126), S(-134, 106), S(-81, 80),
    S(27, -41), S(14, 34), S(28, 15), S(9, 18), S(-15, 36), S(20, 30), S(-1, 24), S(-34, 28),
    S(38, 12), S(85, -2), S(164, 6), S(93, 4), S(66, 11), S(44, 26), S(103, 3), S(14, 24),
    S(35, -37), S(51, -7), S(86, -5), S(85, 20), S(91, 24), S(32, 27), S(33, 7), S(1, 19),
    S(19, -66), S(25, -30), S(36, -15), S(36, 11), S(31, 31), S(3, 26), S(3, -6), S(15, -45),
    S(18, -56), S(60, -40), S(62, -29), S(8, 19), S(1, 25), S(18, 26), S(67, -12), S(46, -38),
    S(-4, -91), S(37, -71), S(7, -55), S(-9, -25), S(-3, -39), S(17, -45), S(15, -27), S(53, -87),
    S(1, -72), S(-22, -28), S(-22, -21), S(-2, -52), S(18, -59), S(32, -16), S(43, -39), S(44, -38)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(109, 5), S(173, 4), S(106, 32), S(108, 26), S(115, 16), S(63, 29), S(67, 34), S(74, 39),
    S(15, 63), S(102, 37), S(179, 13), S(107, 55), S(121, 44), S(66, 54), S(5, 73), S(-4, 80),
    S(7, 38), S(155, -3), S(184, -8), S(184, -12), S(138, -2), S(65, 39), S(81, 26), S(-38, 77),
    S(-25, 33), S(52, 25), S(83, 18), S(105, -18), S(73, 5), S(12, 53), S(-7, 52), S(-77, 60),
    S(-89, -17), S(-7, -12), S(-22, 6), S(-39, 7), S(-44, 4), S(-63, 44), S(-92, 40), S(-111, 29),
    S(-112, -38), S(-37, -64), S(-42, -34), S(-62, -32), S(-46, -51), S(-96, 3), S(-99, -14), S(-122, -17),
    S(-175, -27), S(-75, -87), S(-50, -72), S(-45, -69), S(-52, -64), S(-72, -48), S(-93, -71), S(-124, -54),
    S(-140, -27), S(-110, -21), S(-54, -56), S(-30, -72), S(-44, -57), S(-57, -46), S(-73, -54), S(-90, -38)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(40, 25), S(75, -4), S(84, 3), S(-37, 138), S(36, 53), S(-23, 80), S(40, -5), S(-21, 14),
    S(22, 66), S(-50, 161), S(-56, 227), S(-139, 257), S(-111, 202), S(-126, 199), S(-76, 101), S(-42, 40),
    S(-18, 100), S(68, 101), S(12, 179), S(-5, 193), S(-47, 174), S(-77, 169), S(-9, 60), S(-42, 31),
    S(48, 17), S(53, 85), S(17, 123), S(6, 189), S(-17, 173), S(-26, 104), S(12, 10), S(-1, -25),
    S(13, 43), S(48, 5), S(21, 78), S(-17, 135), S(-30, 121), S(-23, 76), S(-12, -3), S(-10, -54),
    S(21, -112), S(48, -71), S(47, 0), S(-5, 26), S(7, -17), S(10, -14), S(21, -85), S(-3, -80),
    S(1, -211), S(39, -318), S(29, -185), S(46, -114), S(20, -95), S(36, -165), S(11, -104), S(-7, -102),
    S(-60, -125), S(-2, -369), S(10, -381), S(38, -290), S(40, -207), S(43, -251), S(31, -213), S(-22, -139)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-149, -382), S(96, -26), S(-79, 30), S(-189, 56), S(20, -15), S(20, -15), S(20, -15), S(20, -15),
    S(189, -116), S(-2, 139), S(11, 122), S(117, 51), S(20, -15), S(20, -15), S(20, -15), S(20, -15),
    S(-40, 53), S(56, 128), S(87, 96), S(72, 50), S(20, -15), S(20, -15), S(20, -15), S(20, -15),
    S(-254, 77), S(23, 88), S(-3, 86), S(-65, 69), S(20, -15), S(20, -15), S(20, -15), S(20, -15),
    S(-214, 31), S(-53, 61), S(-58, 66), S(-155, 102), S(20, -15), S(20, -15), S(20, -15), S(20, -15),
    S(-109, -1), S(57, 3), S(-63, 56), S(-122, 82), S(20, -15), S(20, -15), S(20, -15), S(20, -15),
    S(116, -92), S(142, -48), S(22, 1), S(-77, 45), S(20, -15), S(20, -15), S(20, -15), S(20, -15),
    S(0, -121), S(102, -103), S(-28, -60), S(-64, -58), S(20, -15), S(20, -15), S(20, -15), S(20, -15)
};
// Epoch duration: 76.3788s
// clang-format on
}  // namespace Clockwork
