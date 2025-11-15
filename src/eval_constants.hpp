#pragma once

#include "eval_types.hpp"

namespace Clockwork {
// clang-format off
inline const PParam PAWN_MAT   = S(308, 325);
inline const PParam KNIGHT_MAT = S(1127, 918);
inline const PParam BISHOP_MAT = S(1249, 975);
inline const PParam ROOK_MAT   = S(1697, 1715);
inline const PParam QUEEN_MAT  = S(3647, 2941);
inline const PParam TEMPO_VAL  = S(59, 16);

inline const PParam BISHOP_PAIR_VAL   = S(80, 178);
inline const PParam ROOK_OPEN_VAL     = S(103, -28);
inline const PParam ROOK_SEMIOPEN_VAL = S(38, 13);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -77);

inline const PParam POTENTIAL_CHECKER_VAL = S(-75, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(7, 51);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 18);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(56, -13);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(33, 32);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(54, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 19), S(62, 30), S(75, 70), S(190, 141), S(557, 244), S(900, 1049)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(64, 43), S(61, 32), S(66, 57), S(146, 121), S(686, -89)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-67, -97), S(-57, -79), S(-30, -2), S(23, 77), S(44, 217), S(285, 307)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(35, -6), S(22, 27), S(24, 75), S(93, 152), S(142, 298)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -46), S(3, 2), S(1, -26), S(5, -47), S(4, -96), S(-191, -146)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(12, 100), S(-21, 88), S(-13, 37), S(0, 8), S(9, 11), S(39, 9), S(18, -1)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-186, -54), S(30, -7), S(-11, 41), S(11, 72), S(15, 96), S(34, 96), S(-14, 116)
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-231, -227), S(-124, -64), S(-67, -11), S(-25, 22), S(22, 38), S(49, 75), S(87, 73), S(120, 74),
    S(165, 17)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-258, -292), S(-184, -107), S(-109, -44), S(-73, 6), S(-43, 37), S(-25, 57), S(-6, 72), S(13, 76),
    S(32, 79), S(46, 76), S(71, 63), S(135, 17), S(167, -4), S(228, -38)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-303, -247), S(-151, -97), S(-99, -33), S(-66, -23), S(-40, -1), S(-25, 23), S(-6, 36), S(11, 41),
    S(29, 53), S(47, 62), S(66, 64), S(77, 66), S(99, 70), S(110, 56), S(256, -72)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-1089, -882), S(-287, -606), S(-185, -510), S(-129, -309), S(-121, -106), S(-82, -1), S(-77, 109), S(-53, 121),
    S(-48, 176), S(-35, 201), S(-27, 226), S(-22, 240), S(-2, 233), S(8, 244), S(15, 239), S(29, 235),
    S(36, 225), S(35, 233), S(61, 188), S(82, 151), S(98, 133), S(138, 69), S(152, 60), S(310, -112),
    S(338, -151), S(472, -232), S(185, -75), S(203, -92)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(375, 68), S(83, -113), S(-20, -21), S(-36, 14), S(-62, 19), S(-97, 22), S(-75, 25), S(-86, 17),
    S(-85, -29)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(89, -30), S(159, -78)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(36, -6), S(138, -43)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(68, -48), S(53, -64), S(104, -63), S(162, -129)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-37, 27), S(-55, 37), S(0, -8), S(161, -97), S(355, -237)
};

inline const PParam PAWN_THREAT_KNIGHT = S(239, 58);
inline const PParam PAWN_THREAT_BISHOP = S(205, 101);
inline const PParam PAWN_THREAT_ROOK   = S(200, 56);
inline const PParam PAWN_THREAT_QUEEN  = S(179, -60);

inline const PParam KNIGHT_THREAT_BISHOP = S(105, 74);
inline const PParam KNIGHT_THREAT_ROOK   = S(243, 6);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -68);

inline const PParam BISHOP_THREAT_KNIGHT = S(110, 34);
inline const PParam BISHOP_THREAT_ROOK   = S(243, 54);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 50);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -7), S(0, 0), S(0, -11), S(-5, -21), S(-12, -28), S(-15, -32), S(-19, -39), S(-23, -36),
    S(-33, -44)
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(114, 166), S(105, 213), S(171, 179), S(236, 60), S(182, 54), S(168, 119), S(64, 143), S(122, 118),
    S(62, 34), S(175, 62), S(151, 5), S(153, -52), S(107, -71), S(52, -20), S(12, 26), S(-39, 28),
    S(-19, 2), S(0, 5), S(17, -39), S(6, -53), S(-12, -57), S(-56, -52), S(-94, -3), S(-121, 18),
    S(-45, -46), S(-26, -17), S(-31, -51), S(-48, -48), S(-75, -58), S(-94, -49), S(-145, -1), S(-163, -11),
    S(-46, -76), S(17, -73), S(-33, -30), S(-65, -28), S(-85, -37), S(-122, -38), S(-141, -25), S(-166, -32),
    S(-36, -70), S(95, -64), S(51, -28), S(-9, -9), S(-47, -22), S(-82, -28), S(-107, -4), S(-144, -18)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-390, -162), S(-343, 59), S(-455, 237), S(-121, 68), S(-248, 93), S(-333, 99), S(-563, 84), S(-534, -20),
    S(5, -1), S(71, 12), S(173, -57), S(118, 9), S(120, 17), S(59, -9), S(-3, 10), S(-20, -35),
    S(62, -29), S(106, 19), S(197, 10), S(149, 32), S(147, 23), S(68, 31), S(56, 5), S(-39, 12),
    S(116, 5), S(107, 28), S(138, 35), S(117, 61), S(125, 48), S(93, 41), S(65, -1), S(42, 6),
    S(105, -14), S(131, -16), S(125, 9), S(98, 28), S(91, 35), S(86, 29), S(59, 2), S(45, -55),
    S(19, -23), S(49, -34), S(43, -14), S(54, 30), S(61, 27), S(3, 5), S(9, -35), S(-29, -42),
    S(20, -7), S(42, -35), S(25, -29), S(24, -11), S(13, -16), S(-16, -37), S(-3, -52), S(-60, -122),
    S(-29, -60), S(9, -16), S(28, -39), S(36, -33), S(29, -24), S(-18, -54), S(-31, -31), S(-78, -84)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-173, 69), S(-193, 50), S(-436, 76), S(-315, 90), S(-267, 94), S(-433, 120), S(-178, 95), S(-130, 70),
    S(-2, -45), S(-17, 35), S(0, 15), S(-20, 20), S(-44, 35), S(-8, 26), S(-29, 17), S(-64, 17),
    S(28, 13), S(74, 1), S(153, 13), S(82, 10), S(57, 14), S(32, 27), S(90, -3), S(-13, 14),
    S(45, -33), S(59, 0), S(93, 4), S(93, 28), S(98, 28), S(37, 28), S(24, 1), S(-24, 8),
    S(45, -61), S(54, -22), S(59, -6), S(62, 20), S(53, 36), S(11, 26), S(-4, -11), S(-9, -55),
    S(59, -52), S(104, -31), S(107, -20), S(50, 23), S(30, 29), S(30, 24), S(61, -19), S(23, -49),
    S(45, -87), S(96, -62), S(66, -50), S(38, -20), S(28, -36), S(29, -48), S(10, -33), S(31, -98),
    S(42, -67), S(27, -23), S(31, -15), S(43, -50), S(52, -59), S(48, -18), S(40, -47), S(22, -49)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(107, 4), S(173, 3), S(103, 33), S(103, 28), S(110, 16), S(59, 30), S(65, 32), S(74, 37),
    S(17, 61), S(103, 37), S(178, 14), S(101, 57), S(119, 46), S(67, 54), S(6, 72), S(-1, 80),
    S(4, 37), S(153, -3), S(183, -8), S(184, -12), S(138, -3), S(63, 37), S(81, 25), S(-38, 76),
    S(-25, 34), S(53, 27), S(83, 18), S(105, -19), S(74, 4), S(13, 53), S(-6, 53), S(-77, 60),
    S(-89, -15), S(-8, -12), S(-24, 7), S(-40, 6), S(-45, 4), S(-64, 44), S(-93, 39), S(-113, 29),
    S(-113, -36), S(-38, -63), S(-45, -33), S(-65, -33), S(-48, -50), S(-97, 3), S(-98, -15), S(-122, -17),
    S(-175, -27), S(-74, -85), S(-51, -72), S(-46, -69), S(-54, -65), S(-72, -48), S(-93, -70), S(-124, -54),
    S(-141, -26), S(-110, -20), S(-55, -56), S(-31, -73), S(-45, -57), S(-56, -44), S(-74, -55), S(-90, -38)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(37, 33), S(78, -2), S(81, 3), S(-39, 133), S(33, 52), S(-24, 79), S(39, -6), S(-23, 20),
    S(23, 72), S(-50, 167), S(-54, 223), S(-142, 255), S(-113, 199), S(-125, 198), S(-75, 103), S(-40, 44),
    S(-19, 103), S(70, 100), S(10, 176), S(-5, 188), S(-48, 169), S(-78, 168), S(-9, 63), S(-43, 35),
    S(49, 16), S(53, 85), S(17, 120), S(6, 186), S(-18, 169), S(-26, 105), S(13, 12), S(-2, -21),
    S(15, 44), S(48, 6), S(21, 76), S(-18, 133), S(-28, 119), S(-24, 77), S(-13, -3), S(-9, -51),
    S(24, -114), S(48, -71), S(48, -1), S(-3, 26), S(8, -17), S(11, -13), S(22, -84), S(-2, -76),
    S(8, -220), S(43, -320), S(30, -184), S(47, -111), S(21, -92), S(38, -162), S(12, -102), S(-6, -98),
    S(-47, -143), S(14, -391), S(11, -379), S(37, -284), S(41, -202), S(43, -246), S(30, -208), S(-23, -132)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-162, -380), S(84, -25), S(-69, 26), S(-180, 50), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(187, -119), S(2, 140), S(19, 125), S(122, 53), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-41, 52), S(62, 131), S(101, 99), S(86, 53), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-262, 76), S(28, 91), S(18, 89), S(-34, 74), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-233, 33), S(-50, 64), S(-34, 69), S(-118, 104), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-139, 3), S(53, 5), S(-38, 58), S(-80, 82), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(76, -87), S(129, -48), S(41, -2), S(-39, 42), S(16, -16), S(16, -16), S(16, -16), S(16, -16),
    S(-47, -117), S(83, -105), S(-15, -69), S(-35, -71), S(16, -16), S(16, -16), S(16, -16), S(16, -16)
};
// Epoch duration: 77.462s
// clang-format on
}  // namespace Clockwork
