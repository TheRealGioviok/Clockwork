#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(287, 340);
inline const PParam KNIGHT_MAT = S(911, 683);
inline const PParam BISHOP_MAT = S(876, 588);
inline const PParam ROOK_MAT   = S(1291, 1277);
inline const PParam QUEEN_MAT  = S(2703, 1863);
inline const PParam TEMPO_VAL  = S(59, 16);

inline const PParam BISHOP_PAIR_VAL   = S(78, 183);
inline const PParam ROOK_OPEN_VAL     = S(101, -27);
inline const PParam ROOK_SEMIOPEN_VAL = S(36, 15);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -77);

inline const PParam POTENTIAL_CHECKER_VAL = S(-66, -8);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 27);
inline const PParam OUTPOST_BISHOP_VAL    = S(72, -1);

inline const PParam SUPER_KNIGHT_OUTPOST_VAL = S(0, 33);
inline const PParam SUPER_BISHOP_OUTPOST_VAL = S(-36, 121);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(48, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 31);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 19), S(62, 30), S(76, 70), S(186, 145), S(538, 262), S(944, 1142)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(66, 40), S(60, 31), S(67, 58), S(150, 121), S(688, -83)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-78, -91), S(-77, -70), S(-51, 6), S(25, 75), S(89, 197), S(293, 304)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(32, -2), S(20, 28), S(27, 72), S(106, 142), S(152, 291)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -43), S(-1, 6), S(-3, -21), S(3, -43), S(-3, -88), S(-212, -130)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 113), S(-14, 85), S(-7, 32), S(2, 4), S(11, 8), S(38, 7), S(17, -5)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-272, -19), S(-34, 18), S(-13, 45), S(29, 55), S(32, 82), S(50, 84), S(3, 103)
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-233, -223), S(-125, -62), S(-68, -10), S(-25, 24), S(22, 38), S(50, 76), S(87, 71), S(122, 73),
    S(168, 16)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-245, -299), S(-173, -116), S(-102, -51), S(-68, 0), S(-40, 33), S(-24, 55), S(-7, 71), S(11, 78),
    S(29, 82), S(42, 79), S(66, 67), S(130, 23), S(157, 3), S(217, -30)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-301, -248), S(-148, -98), S(-96, -34), S(-63, -25), S(-38, 0), S(-24, 22), S(-6, 34), S(13, 40),
    S(29, 53), S(46, 62), S(63, 65), S(74, 68), S(94, 71), S(105, 57), S(249, -68)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-788, -504), S(-306, -660), S(-216, -505), S(-163, -301), S(-156, -95), S(-120, 11), S(-118, 121), S(-93, 133),
    S(-89, 189), S(-77, 213), S(-69, 238), S(-64, 253), S(-46, 244), S(-36, 255), S(-30, 249), S(-17, 244),
    S(-11, 234), S(-12, 240), S(13, 197), S(35, 158), S(52, 137), S(97, 69), S(109, 61), S(272, -117),
    S(308, -161), S(545, -315), S(369, -228), S(612, -360)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(563, -78), S(169, -163), S(38, -56), S(0, -6), S(-49, 12), S(-112, 36), S(-159, 78), S(-207, 100),
    S(-242, 78)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(213, 236), S(315, 190), S(388, 132)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(373, 389), S(225, 249), S(143, 78)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(414, 433), S(513, 417), S(535, 431), S(614, 467), S(686, 440)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(1033, 1003), S(716, 813), S(424, 618), S(207, 352), S(108, 38), S(31, -330)
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-110, 64), S(8, -15), S(-181, -134), S(33, 33), S(-278, -206)
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-27, 23), S(-21, 18), S(-25, 14), S(-15, 9), S(-22, -8)
};

inline const PParam PAWN_THREAT_KNIGHT = S(234, 62);
inline const PParam PAWN_THREAT_BISHOP = S(204, 105);
inline const PParam PAWN_THREAT_ROOK   = S(199, 56);
inline const PParam PAWN_THREAT_QUEEN  = S(175, -53);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 71);
inline const PParam KNIGHT_THREAT_ROOK   = S(245, 5);
inline const PParam KNIGHT_THREAT_QUEEN  = S(161, -69);

inline const PParam BISHOP_THREAT_KNIGHT = S(111, 35);
inline const PParam BISHOP_THREAT_ROOK   = S(244, 57);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 54);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(0, -12), S(-3, -6), S(-3, -16), S(-8, -27), S(-14, -32), S(-19, -40), S(-20, -47), S(-26, -42),
    S(-34, -49)
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(132, 152), S(98, 213), S(182, 175), S(246, 55), S(194, 49), S(185, 110), S(73, 135), S(152, 99),
    S(21, 51), S(113, 90), S(92, 36), S(99, -23), S(61, -44), S(11, 1), S(-24, 43), S(-60, 39),
    S(-23, 1), S(-14, 13), S(-2, -27), S(-7, -44), S(-18, -51), S(-54, -49), S(-93, -3), S(-111, 13),
    S(-29, -59), S(-17, -24), S(-19, -57), S(-35, -55), S(-57, -66), S(-74, -59), S(-125, -9), S(-143, -22),
    S(-33, -87), S(26, -78), S(-25, -31), S(-49, -33), S(-68, -43), S(-105, -47), S(-124, -33), S(-146, -40),
    S(-34, -76), S(90, -66), S(42, -27), S(-6, -14), S(-38, -30), S(-67, -40), S(-93, -15), S(-127, -28)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-395, -159), S(-342, 57), S(-453, 231), S(-123, 68), S(-255, 95), S(-322, 91), S(-564, 82), S(-534, -24),
    S(6, -4), S(73, 10), S(166, -50), S(114, 11), S(121, 15), S(51, -3), S(10, 5), S(-10, -42),
    S(59, -28), S(85, 27), S(167, 25), S(121, 47), S(118, 38), S(46, 43), S(43, 10), S(-38, 9),
    S(107, 10), S(93, 38), S(110, 53), S(91, 78), S(104, 63), S(71, 55), S(58, 4), S(38, 5),
    S(100, -7), S(124, -4), S(110, 31), S(90, 40), S(78, 51), S(83, 40), S(61, 7), S(49, -56),
    S(28, -31), S(57, -39), S(50, -17), S(62, 27), S(70, 22), S(15, -3), S(22, -43), S(-16, -52),
    S(37, -20), S(59, -47), S(40, -38), S(39, -19), S(27, -26), S(-2, -46), S(11, -61), S(-46, -130),
    S(-14, -69), S(22, -23), S(44, -49), S(53, -43), S(43, -35), S(-4, -65), S(-18, -41), S(-65, -95)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-179, 73), S(-197, 52), S(-442, 78), S(-317, 89), S(-274, 93), S(-435, 117), S(-175, 93), S(-131, 71),
    S(-4, -40), S(-18, 32), S(-2, 17), S(-35, 24), S(-55, 37), S(-3, 23), S(-24, 13), S(-60, 16),
    S(32, 13), S(72, 2), S(139, 14), S(69, 13), S(41, 19), S(24, 26), S(91, -6), S(0, 10),
    S(37, -27), S(36, 13), S(73, 12), S(75, 36), S(86, 33), S(24, 31), S(21, 4), S(-18, 7),
    S(31, -50), S(51, -15), S(59, 2), S(61, 22), S(55, 37), S(22, 25), S(4, -11), S(-9, -52),
    S(54, -48), S(101, -38), S(111, -26), S(46, 17), S(33, 20), S(37, 13), S(62, -29), S(26, -47),
    S(46, -83), S(110, -69), S(81, -56), S(51, -25), S(38, -38), S(39, -48), S(21, -35), S(36, -95),
    S(46, -67), S(31, -18), S(46, -18), S(56, -52), S(64, -62), S(53, -17), S(48, -47), S(27, -48)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(104, 6), S(173, 4), S(100, 34), S(97, 31), S(110, 18), S(61, 30), S(73, 31), S(79, 36),
    S(17, 60), S(100, 38), S(171, 18), S(93, 63), S(116, 48), S(67, 55), S(10, 71), S(5, 75),
    S(-4, 43), S(140, 4), S(165, 2), S(162, 1), S(123, 7), S(55, 44), S(77, 29), S(-40, 77),
    S(-28, 33), S(47, 28), S(74, 22), S(92, -11), S(70, 7), S(14, 51), S(-1, 49), S(-74, 57),
    S(-89, -16), S(-9, -10), S(-26, 9), S(-43, 10), S(-41, 3), S(-58, 41), S(-84, 36), S(-106, 27),
    S(-110, -38), S(-37, -62), S(-42, -33), S(-62, -32), S(-42, -53), S(-90, 0), S(-91, -18), S(-115, -20),
    S(-169, -29), S(-67, -89), S(-46, -73), S(-44, -68), S(-49, -65), S(-68, -49), S(-86, -73), S(-118, -56),
    S(-133, -31), S(-105, -24), S(-51, -58), S(-28, -74), S(-40, -59), S(-52, -48), S(-68, -57), S(-85, -40)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(31, 30), S(71, -8), S(69, 0), S(-56, 132), S(16, 49), S(-29, 71), S(46, -15), S(-18, 14),
    S(19, 75), S(-52, 172), S(-64, 219), S(-166, 250), S(-137, 199), S(-120, 194), S(-71, 113), S(-33, 50),
    S(-23, 102), S(54, 99), S(-17, 177), S(-41, 187), S(-78, 168), S(-102, 171), S(-13, 63), S(-41, 36),
    S(42, 9), S(31, 78), S(-6, 116), S(-17, 175), S(-23, 156), S(-29, 97), S(13, 2), S(6, -25),
    S(8, 38), S(41, 3), S(14, 71), S(-21, 123), S(-25, 116), S(-17, 78), S(-2, -3), S(-1, -53),
    S(24, -114), S(49, -57), S(54, 4), S(2, 18), S(19, -17), S(26, -10), S(37, -80), S(8, -75),
    S(14, -212), S(52, -304), S(46, -181), S(60, -116), S(33, -92), S(50, -158), S(26, -95), S(6, -95),
    S(-40, -123), S(24, -374), S(28, -374), S(55, -291), S(56, -197), S(56, -245), S(43, -202), S(-11, -125)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-276, -302), S(22, 18), S(-125, 71), S(-230, 98), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4),
    S(112, -70), S(83, 87), S(128, 65), S(236, -4), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4),
    S(-77, 87), S(175, 70), S(242, 28), S(219, -13), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4),
    S(-284, 108), S(163, 22), S(173, 11), S(114, -6), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4),
    S(-256, 62), S(94, -10), S(149, -26), S(61, 8), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4),
    S(-190, 44), S(156, -48), S(114, -22), S(85, -7), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4),
    S(-30, -18), S(158, -62), S(110, -39), S(46, -6), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4),
    S(-230, 3), S(-49, -16), S(-127, 6), S(-141, 5), S(-19, -4), S(-19, -4), S(-19, -4), S(-19, -4)
};
// Epoch duration: 6.87929s
// clang-format on
}  // namespace Clockwork
