#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(304, 284);
inline const PParam KNIGHT_MAT = S(1319, -46);
inline const PParam BISHOP_MAT = S(1408, 42);
inline const PParam ROOK_MAT   = S(1803, -238);
inline const PParam QUEEN_MAT  = S(3917, -522);
inline const PParam TEMPO_VAL  = S(64, 11);

inline const PParam BISHOP_PAIR_VAL   = S(73, 163);
inline const PParam ROOK_OPEN_VAL     = S(107, -24);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 13);

inline const PParam DOUBLED_PAWN_VAL = S(-34, -71);

inline const PParam POTENTIAL_CHECKER_VAL = S(-56, -14);
inline const PParam OUTPOST_KNIGHT_VAL    = S(41, 48);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 23);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(48, 14);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -22);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 57);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(72, -64);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(28, 5), S(53, 38), S(67, 79), S(164, 162), S(463, 204), S(597, 383)
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(65, 43), S(52, 46), S(65, 79), S(141, 154), S(497, 60)
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-97, -100), S(-83, -78), S(-43, -2), S(26, 75), S(131, 178), S(322, 251)
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(28, -21), S(28, -2), S(19, 20), S(10, 69), S(72, 139), S(126, 228)
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -28), S(6, 6), S(-3, -16), S(-10, -37), S(-22, -100), S(-259, -142)
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(34, 81), S(10, 67), S(-6, 30), S(-11, 12), S(-9, 19), S(25, 16), S(7, -11)
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-241, -98), S(-1, -21), S(-9, 35), S(13, 77), S(31, 95), S(48, 101), S(23, 96)
};

inline const PParam MOB_KNIGHT_SCALE = S(0,0);
inline const PParam MOB_BISHOP_SCALE = S(0,0);
inline const PParam MOB_ROOK_SCALE = S(0,0);
inline const PParam MOB_QUEEN_SCALE = S(0,0);
inline const PParam MOB_BIAS_SCALE = S(0,0);

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-184, 337), S(-124, 380), S(-94, 403), S(-72, 409), S(-50, 409), S(-33, 415), S(-19, 409), S(-5, 407),
    S(-6, 404)
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-213, 319), S(-160, 369), S(-120, 387), S(-98, 401), S(-80, 409), S(-68, 412), S(-60, 412), S(-52, 410),
    S(-45, 411), S(-40, 408), S(-36, 407), S(-33, 406), S(-29, 405), S(-39, 405)
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-51, 354), S(-56, 402), S(-39, 410), S(-26, 412), S(-18, 416), S(-13, 420), S(-7, 423), S(-3, 424),
    S(2, 424), S(7, 423), S(12, 422), S(14, 422), S(17, 421), S(17, 420), S(11, 417)
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-175, 455), S(-184, 695), S(-161, 710), S(-142, 729), S(-130, 743), S(-119, 738), S(-113, 749), S(-108, 747),
    S(-103, 755), S(-99, 754), S(-95, 751), S(-92, 750), S(-89, 747), S(-87, 744), S(-86, 745), S(-86, 744),
    S(-86, 744), S(-85, 743), S(-86, 744), S(-86, 744), S(-88, 744), S(-93, 745), S(-93, 744), S(-105, 743),
    S(48, 503), S(54, 501), S(294, 181), S(-183, 752)
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(162, -77), S(25, -19), S(5, 5), S(5, 4), S(-2, 1), S(-3, -5), S(5, -4), S(3, -6),
    S(-6, -11)
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(-12, 89), S(3, 70), S(7, 52)
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(-3, 111), S(-9, 52), S(-17, -4)
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(-13, 77), S(4, 72), S(8, 94), S(18, 101), S(24, 90)
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(27, 2158), S(10, 2139), S(-6, 2097), S(2, -1166), S(-8, -1237), S(-22, -1263)
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(5, 143), S(0, 11), S(14, 49), S(-8, -14), S(16, 46)
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(1, 156), S(3, -8), S(2, -7), S(3, -4), S(4, -9)
};

inline const PParam PAWN_THREAT_KNIGHT = S(235, 75);
inline const PParam PAWN_THREAT_BISHOP = S(214, 118);
inline const PParam PAWN_THREAT_ROOK   = S(209, 109);
inline const PParam PAWN_THREAT_QUEEN  = S(189, -46);

inline const PParam KNIGHT_THREAT_BISHOP = S(118, 81);
inline const PParam KNIGHT_THREAT_ROOK   = S(255, 18);
inline const PParam KNIGHT_THREAT_QUEEN  = S(168, -53);

inline const PParam BISHOP_THREAT_KNIGHT = S(118, 43);
inline const PParam BISHOP_THREAT_ROOK   = S(243, 81);
inline const PParam BISHOP_THREAT_QUEEN  = S(196, 66);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -20), S(-2, -9), S(-5, -16), S(-10, -23), S(-16, -28), S(-22, -31), S(-27, -39), S(-34, -38),
    S(-46, -36)
};

inline const PParam ROOK_LINEUP = S(12, 86);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(262, 54), S(106, 160), S(176, 162), S(185, 98), S(208, 63), S(153, 104), S(100, 134), S(205, 64),
    S(18, 7), S(84, 38), S(78, 9), S(38, -9), S(22, -25), S(16, -10), S(6, 21), S(-54, 33),
    S(-18, -11), S(-9, -1), S(13, -36), S(-5, -45), S(-19, -51), S(-41, -38), S(-72, -4), S(-94, 9),
    S(-54, -44), S(-34, -21), S(-20, -46), S(-37, -46), S(-60, -45), S(-70, -36), S(-113, -3), S(-131, -14),
    S(-62, -74), S(1, -68), S(-31, -33), S(-44, -31), S(-73, -30), S(-93, -31), S(-112, -12), S(-132, -33),
    S(-42, -64), S(65, -64), S(22, -21), S(-15, -2), S(-44, -8), S(-67, -13), S(-80, -1), S(-116, -9)
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-380, -190), S(-319, 72), S(-340, 2), S(-102, 39), S(-155, 36), S(-277, 36), S(-443, 89), S(-446, -119),
    S(-46, -1), S(11, 7), S(72, -12), S(76, -10), S(60, 7), S(-6, 17), S(-32, 17), S(-69, -3),
    S(47, -21), S(87, -7), S(107, 23), S(92, 14), S(57, 39), S(17, 49), S(4, 27), S(-32, 9),
    S(103, -3), S(122, 19), S(118, 37), S(107, 59), S(107, 64), S(67, 58), S(59, 37), S(45, -8),
    S(100, -16), S(129, -2), S(111, 31), S(108, 47), S(85, 55), S(81, 50), S(66, 13), S(37, -9),
    S(28, -27), S(57, -1), S(63, 30), S(74, 45), S(70, 46), S(29, 41), S(10, 4), S(-24, -45),
    S(43, -34), S(65, -15), S(34, -1), S(40, 8), S(30, 8), S(-3, -21), S(-5, -29), S(-38, -96),
    S(-10, -106), S(27, -35), S(43, -30), S(58, -44), S(42, -36), S(3, -59), S(-4, -65), S(-52, -119)
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-153, 67), S(-183, 62), S(-430, 103), S(-334, 71), S(-310, 77), S(-364, 93), S(-231, 93), S(-128, 60),
    S(-27, -6), S(-75, 57), S(-58, 23), S(-109, 39), S(-101, 43), S(-69, 45), S(-32, 34), S(-54, 10),
    S(47, 2), S(64, 13), S(64, 25), S(26, 25), S(-3, 29), S(14, 28), S(37, 16), S(15, -4),
    S(28, -16), S(53, 10), S(57, 24), S(59, 47), S(85, 33), S(12, 24), S(20, 5), S(-18, -3),
    S(49, -53), S(62, -11), S(72, 11), S(80, 24), S(58, 34), S(33, 30), S(-5, 11), S(-6, -34),
    S(78, -56), S(108, -29), S(121, -9), S(70, 20), S(60, 10), S(53, 14), S(62, -18), S(9, -27),
    S(61, -102), S(137, -65), S(99, -48), S(66, -25), S(46, -20), S(49, -48), S(49, -54), S(51, -83),
    S(96, -122), S(70, -66), S(75, -47), S(84, -69), S(80, -73), S(87, -60), S(77, -67), S(71, -92)
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(99, 6), S(123, 17), S(80, 38), S(98, 11), S(109, -10), S(80, -2), S(81, 5), S(72, 12),
    S(-9, 58), S(72, 47), S(139, 26), S(87, 33), S(85, 29), S(67, 31), S(1, 58), S(-16, 62),
    S(-23, 49), S(94, 14), S(139, -5), S(121, -15), S(87, -4), S(42, 22), S(40, 25), S(-32, 65),
    S(-33, 36), S(56, 26), S(92, 3), S(77, 0), S(67, 6), S(23, 32), S(9, 35), S(-62, 60),
    S(-65, 2), S(2, 2), S(2, 7), S(-15, 6), S(-34, 21), S(-47, 41), S(-77, 39), S(-98, 39),
    S(-83, -42), S(-22, -31), S(-21, -22), S(-33, -25), S(-41, -24), S(-69, 6), S(-79, -7), S(-115, 0),
    S(-168, -36), S(-52, -72), S(-34, -62), S(-34, -55), S(-47, -51), S(-62, -39), S(-80, -54), S(-109, -40),
    S(-118, -51), S(-97, -27), S(-35, -59), S(-21, -64), S(-32, -55), S(-52, -36), S(-65, -40), S(-84, -24)
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(0, 48), S(23, 50), S(-21, 102), S(-66, 169), S(-45, 115), S(-47, 108), S(-17, 50), S(-66, 93),
    S(11, 65), S(-16, 133), S(-53, 199), S(-176, 258), S(-158, 227), S(-102, 191), S(-56, 84), S(-47, 65),
    S(-14, 95), S(22, 107), S(-39, 203), S(-85, 206), S(-100, 179), S(-67, 138), S(-18, 45), S(-6, -8),
    S(43, -2), S(60, 45), S(0, 112), S(-2, 122), S(-12, 114), S(-17, 61), S(32, -20), S(14, -39),
    S(52, -40), S(56, -5), S(29, 49), S(7, 75), S(5, 68), S(3, 28), S(11, -28), S(29, -90),
    S(30, -102), S(62, -59), S(65, -7), S(34, -17), S(29, -22), S(29, -10), S(34, -74), S(13, -96),
    S(11, -215), S(36, -197), S(44, -141), S(65, -118), S(52, -94), S(44, -121), S(14, -89), S(18, -107),
    S(-6, -245), S(14, -329), S(37, -327), S(54, -228), S(57, -168), S(54, -213), S(45, -197), S(9, -167)
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-496, -228), S(146, 22), S(181, -24), S(-107, -16), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9),
    S(133, -109), S(318, 40), S(238, 43), S(163, -13), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9),
    S(89, 5), S(331, 45), S(297, 48), S(176, 23), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9),
    S(-83, 11), S(194, 51), S(126, 70), S(86, 70), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9),
    S(-159, 12), S(66, 51), S(73, 76), S(-7, 111), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9),
    S(-111, 0), S(61, 32), S(20, 73), S(-12, 99), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9),
    S(-30, -64), S(13, -2), S(-54, 47), S(-115, 86), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9),
    S(-127, -138), S(-31, -77), S(-117, -33), S(-132, -37), S(-36, -9), S(-36, -9), S(-36, -9), S(-36, -9)
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-7, -322), S(-17, -196), S(-20, -205), S(-15, -231), S(-15, -229), S(-19, -222), S(-16, -205), }},
  {{ S(-9, -313), S(-27, -174), S(-23, -195), S(-16, -225), S(-16, -220), S(-22, -201), S(-26, -175), }},
  {{ S(-12, -335), S(-25, -208), S(-19, -247), S(-14, -262), S(-14, -260), S(-18, -250), S(-24, -214), }},
  {{ S(-10, -258), S(-23, -158), S(-17, -166), S(-12, -187), S(-13, -182), S(-17, -166), S(-21, -156), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, -473), S(-7, -392), S(-7, -204), S(-1, -164), S(-5, -208)
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-1, -226), S(-8, -215), S(-6, -241), S(-5, -226), S(-6, -241), S(-5, -261), S(-8, -223), }},
  {{ S(0, -242), S(-4, -86), S(-8, -139), S(-6, -188), S(-7, -254), S(-7, -154), S(-4, -87), }},
  {{ S(-2, -293), S(-6, -108), S(-6, -163), S(-5, -245), S(-5, -246), S(-7, -139), S(-6, -138), }},
  {{ S(-3, -285), S(-8, -85), S(-9, -113), S(-5, -220), S(-4, -194), S(-9, -178), S(-9, -61), }},
}};

inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1856, 579, -8, -458
);
inline const PParam KS_MOBILITY_WEIGHT = S(8, 299);

inline TunableSigmoid<32> MOBILITY_ACTIVATION(
        1856, 579, -8, -458
);
// Epoch duration: 9.63747s
// clang-format on
}  // namespace Clockwork
