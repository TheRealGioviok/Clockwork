#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(223, 435);
inline const PParam KNIGHT_MAT = S(899, 1348);
inline const PParam BISHOP_MAT = S(962, 1423);
inline const PParam ROOK_MAT   = S(1177, 2287);
inline const PParam QUEEN_MAT  = S(2861, 3666);

inline const PParam TEMPO_VAL  = S(62, 41);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -1);
inline const PParam BISHOP_PAIR_VAL   = S(62, 212);
inline const PParam ROOK_OPEN_VAL     = S(108, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 8);
inline const PParam MINOR_BEHIND_PAWN = S(16, 38);
inline const PParam RESTRICTED_SQUARES = S(16, 9);

inline const PParam DOUBLED_PAWN_VAL = S(-24, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -31);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -19);
inline const PParam OUTPOST_KNIGHT_VAL    = S(55, 37);
inline const PParam OUTPOST_BISHOP_VAL    = S(48, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 39);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, -5);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 60);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -47);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, -0), S(36, 27), S(63, 58), S(131, 181), S(457, 311), S(587, 789),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(50, 23), S(42, 18), S(60, 42), S(115, 142), S(444, 65),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-99, -213), S(-99, -182), S(-72, -66), S(-21, 36), S(89, 188), S(232, 315),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-79, 56), S(-61, 35), S(-41, 96), S(-43, 191), S(-33, 286), S(66, 163),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-21, 62), S(-24, 55), S(-40, 94), S(-23, 123), S(61, 137), S(70, 133),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(22, -42), S(24, -3), S(18, 33), S(26, 97), S(81, 246), S(290, 169),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(3, -22), S(-6, 18), S(-13, -15), S(1, -62), S(-10, -152), S(-194, -354),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(41, 198), S(11, 166), S(4, 90), S(12, 53), S(26, 53), S(67, 46), S(67, 24),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-105, -24), S(32, 0), S(13, 89), S(39, 121), S(51, 153), S(54, 169), S(36, 165),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-79, -346), S(-21, -131), S(12, -31), S(38, 5), S(65, 31), S(80, 59), S(98, 62), S(115, 66), S(132, 17),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-48, -225), S(-15, -98), S(29, -51), S(48, -4), S(71, 28), S(83, 52), S(89, 68), S(94, 80), S(98, 89), S(106, 87), S(119, 77), S(130, 53), S(146, 42), S(81, 40),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(100, -187), S(22, -15), S(41, 11), S(57, 23), S(66, 38), S(71, 49), S(76, 62), S(81, 65), S(86, 74), S(92, 80), S(98, 83), S(99, 90), S(103, 91), S(107, 76), S(141, 17),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-161, -102), S(-23, -40), S(8, 42), S(26, 129), S(40, 166), S(48, 206), S(54, 231), S(59, 248), S(64, 264), S(67, 277), S(71, 288), S(76, 293), S(80, 296), S(83, 295), S(84, 297), S(85, 292), S(85, 290), S(90, 278), S(95, 266), S(103, 249), S(99, 239), S(107, 211), S(74, 244), S(46, 222), S(-1, 256), S(-6, 244), S(-82, 312), S(13, 204),
};

inline const PParam PAWN_THREAT_KNIGHT = S(203, 106);
inline const PParam PAWN_THREAT_BISHOP = S(176, 170);
inline const PParam PAWN_THREAT_ROOK   = S(174, 133);
inline const PParam PAWN_THREAT_QUEEN  = S(162, -26);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(11, 48), S(86, 79), S(98, 103), S(216, 76), S(150, 7), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(12, 46), S(55, 81), S(76, 72), S(8, 25), S(129, -15), S(0, 0),
};
inline const PParam KING_THREAT  = S(-5, 137);
inline const PParam HANGING_PAWN  = S(33, 80);
inline const PParam HANGING_NON_PAWN  = S(63, 24);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(17, -5), S(48, -36),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(37, 48), S(128, -124),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(27, 38), S(19, 28),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -17), S(5, -13), S(2, -18), S(-4, -25), S(-10, -32), S(-15, -40), S(-19, -47), S(-21, -56), S(-29, -73),
};

inline const PParam ROOK_LINEUP = S(15, 71);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(231, 132),    S(42, 319),     S(87, 317),     S(139, 229),    S(170, 160),    S(115, 216),    S(86, 252),     S(256, 120),    //
    S(50, -3),      S(53, 46),      S(37, 15),      S(34, -34),     S(22, -65),     S(1, -28),      S(-12, 18),     S(-24, 36),     //
    S(23, -24),     S(1, -19),      S(31, -55),     S(20, -76),     S(8, -80),      S(-15, -57),    S(-45, -25),    S(-49, 5),      //
    S(-10, -77),    S(-28, -63),    S(-6, -70),     S(-7, -75),     S(-31, -77),    S(-44, -53),    S(-87, -31),    S(-83, -34),    //
    S(-9, -109),    S(25, -116),    S(2, -42),      S(-12, -43),    S(-37, -51),    S(-57, -43),    S(-81, -44),    S(-86, -47),    //
    S(10, -108),    S(80, -114),    S(58, -53),     S(22, -16),     S(-8, -34),     S(-31, -36),    S(-50, -35),    S(-67, -35),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-281, -453),  S(-272, 52),    S(-38, -456),   S(24, 6),       S(-62, 32),     S(-261, 64),    S(-370, 97),    S(-392, -318),  //
    S(3, -29),      S(5, 13),       S(104, -23),    S(106, 23),     S(109, 24),     S(68, 11),      S(-24, 32),     S(-35, 13),     //
    S(29, -28),     S(41, 3),       S(94, 29),      S(100, 42),     S(89, 39),      S(33, 52),      S(7, 29),       S(-35, 8),      //
    S(101, 5),      S(99, 20),      S(107, 53),     S(108, 89),     S(109, 88),     S(75, 65),      S(52, 32),      S(49, 24),      //
    S(75, 8),       S(110, -12),    S(104, 36),     S(88, 75),      S(74, 74),      S(71, 64),      S(59, 16),      S(25, 29),      //
    S(11, -33),     S(44, -27),     S(46, 12),      S(62, 46),      S(51, 46),      S(27, 19),      S(15, -2),      S(-19, -21),    //
    S(29, -21),     S(28, -4),      S(26, -19),     S(31, 9),       S(26, 12),      S(3, -33),      S(-26, -7),     S(-37, -79),    //
    S(-36, -84),    S(13, -24),     S(24, -47),     S(44, -30),     S(29, -18),     S(-4, -52),     S(-11, -13),    S(-53, -124),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-100, -9),    S(-167, 75),    S(-347, 144),   S(-203, 80),    S(-246, 105),   S(-272, 118),   S(-194, 111),   S(-112, 55),    //
    S(-34, -9),     S(-64, 81),     S(-31, 45),     S(-51, 59),     S(-57, 66),     S(-42, 48),     S(-16, 27),     S(-46, 28),     //
    S(41, -7),      S(38, 15),      S(34, 50),      S(29, 53),      S(21, 35),      S(7, 47),       S(13, 21),      S(-2, 16),      //
    S(24, -19),     S(51, 4),       S(72, 16),      S(76, 45),      S(98, 29),      S(42, 19),      S(42, -1),      S(-4, 1),       //
    S(48, -51),     S(44, -14),     S(68, 4),       S(91, 15),      S(76, 26),      S(61, 22),      S(19, 9),       S(14, -21),     //
    S(57, -37),     S(78, -42),     S(89, -4),      S(65, 23),      S(60, 11),      S(55, 20),      S(68, -6),      S(21, -16),     //
    S(30, -71),     S(100, -52),    S(62, -28),     S(44, -1),      S(24, 3),       S(50, -38),     S(46, -41),     S(51, -60),     //
    S(54, -79),     S(27, -48),     S(22, -4),      S(38, -30),     S(25, -21),     S(32, 13),      S(48, -33),     S(40, -55),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(172, 86),     S(190, 113),    S(159, 125),    S(136, 94),     S(187, 82),     S(174, 90),     S(172, 110),    S(142, 130),    //
    S(84, 132),     S(129, 145),    S(185, 97),     S(145, 89),     S(189, 87),     S(145, 109),    S(84, 154),     S(89, 149),     //
    S(40, 133),     S(163, 90),     S(193, 54),     S(170, 41),     S(172, 61),     S(116, 106),    S(116, 119),    S(60, 160),     //
    S(12, 89),      S(79, 86),      S(112, 59),     S(91, 52),      S(115, 61),     S(83, 98),      S(68, 114),     S(25, 131),     //
    S(-12, 33),     S(58, 36),      S(47, 45),      S(23, 52),      S(31, 65),      S(22, 94),      S(9, 95),       S(-6, 90),      //
    S(-2, -38),     S(74, -36),     S(66, -16),     S(40, 3),       S(55, 13),      S(26, 45),      S(32, 30),      S(-9, 35),      //
    S(-83, -38),    S(49, -75),     S(68, -66),     S(60, -43),     S(56, -21),     S(46, -9),      S(28, -14),     S(6, -17),      //
    S(-10, -63),    S(-1, -31),     S(70, -52),     S(83, -55),     S(78, -39),     S(64, -20),     S(60, -26),     S(47, -22),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(85, 131),     S(146, 103),    S(82, 196),     S(41, 249),     S(67, 240),     S(97, 172),     S(98, 122),     S(18, 187),     //
    S(65, 170),     S(82, 220),     S(66, 242),     S(-43, 318),    S(-4, 314),     S(32, 241),     S(53, 167),     S(36, 150),     //
    S(27, 179),     S(84, 204),     S(47, 258),     S(15, 281),     S(29, 281),     S(60, 222),     S(81, 157),     S(58, 109),     //
    S(34, 101),     S(39, 170),     S(19, 205),     S(7, 261),      S(10, 285),     S(30, 202),     S(69, 130),     S(44, 102),     //
    S(30, 53),      S(22, 96),      S(15, 137),     S(-12, 201),    S(-4, 236),     S(17, 192),     S(23, 143),     S(43, 77),      //
    S(20, -16),     S(43, -10),     S(37, 70),      S(16, 88),      S(20, 114),     S(24, 143),     S(39, 111),     S(30, 66),      //
    S(-5, -144),    S(3, -98),      S(19, -61),     S(38, -4),      S(34, 26),      S(36, 19),      S(18, 37),      S(32, 17),      //
    S(3, -160),     S(-3, -271),    S(10, -237),    S(22, -125),    S(31, -38),     S(35, -75),     S(33, -62),     S(12, -30),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(90, -378),    S(398, 160),    S(263, 261),    S(-1, 244),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(264, -86),    S(298, 176),    S(172, 230),    S(11, 206),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(158, 90),     S(210, 169),    S(98, 212),     S(-42, 221),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(49, 39),      S(115, 101),    S(-37, 208),    S(-108, 231),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-58, -16),    S(-13, 57),     S(-100, 139),   S(-187, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-12, -46),    S(26, -2),      S(-78, 95),     S(-143, 156),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(46, -110),    S(44, -46),     S(-37, 15),     S(-116, 84),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(4, -190),     S(27, -114),    S(-75, -47),    S(-58, -61),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-62, -540);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -14), S(21, -23), S(20, -6), S(7, -5), S(0, -12),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, -13), S(9, -20), S(4, -10), S(6, -2), S(6, 9),
};

inline const PParam KS_FLANK_ATTACK = S(4, -10);
inline const PParam KS_FLANK_DEFENSE = S(-9, 2);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -4);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-4, -7);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(37, 15), S(8, 19), S(11, -66), S(23, -33), S(20, -19), S(-14, 17), S(-39, -2), }},
  {{ S(9, 144), S(-22, -281), S(-18, -62), S(-6, 38), S(-11, 88), S(-33, 124), S(-62, 118), }},
  {{ S(15, 105), S(-3, -230), S(0, 98), S(9, 74), S(8, 70), S(-10, 91), S(-59, 116), }},
  {{ S(22, 134), S(-5, 94), S(7, 103), S(16, 88), S(9, 79), S(17, 96), S(7, 96), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(34, 120), S(2, 77), S(-0, 84), S(14, 96), S(36, 57),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(18, 149), S(-115, -368), S(-24, -238), S(19, -324), S(0, 70), S(-4, 95), S(-5, 101), }},
  {{ S(26, 38), S(-48, -486), S(-17, -238), S(3, -96), S(2, 4), S(-6, 28), S(7, 26), }},
  {{ S(16, 75), S(-25, -223), S(7, -36), S(13, 18), S(4, 42), S(-3, 60), S(4, 52), }},
  {{ S(12, 56), S(-8, -120), S(8, -14), S(14, 37), S(-2, 45), S(-12, 47), S(-3, 48), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        611, 291, 2, 77
);

inline VParam WINNABLE_PAWNS = V(-19);
inline VParam WINNABLE_SYM = V(108);
inline VParam WINNABLE_ASYM = V(93);
inline VParam WINNABLE_PAWN_ENDGAME = V(134);
inline VParam WINNABLE_BIAS = V(-408);

// Epoch duration: 10.6955s
// clang-format on
}  // namespace Clockwork
