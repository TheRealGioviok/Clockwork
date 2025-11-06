#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(292, 313);
inline const PParam KNIGHT_MAT = S(1134, 907);
inline const PParam BISHOP_MAT = S(1231, 952);
inline const PParam ROOK_MAT   = S(1712, 1683);
inline const PParam QUEEN_MAT  = S(3663, 2886);
inline const PParam TEMPO_VAL  = S(59, 15);

inline const PParam BISHOP_PAIR_VAL    = S(80, 177);
inline const PParam ROOK_OPEN_VAL      = S(104, -28);
inline const PParam ROOK_SEMIOPEN_VAL  = S(39, 13);

inline const PParam DOUBLED_PAWN_VAL = S(-37, -78);

inline const PParam POTENTIAL_CHECKER_VAL = S(-74, -2);
inline const PParam OUTPOST_KNIGHT_VAL = S(14, 42);
inline const PParam OUTPOST_INNER_KNIGHT_VAL = S(-9, 16);
inline const PParam OUTPOST_BISHOP_VAL = S(31, 51);
inline const PParam OUTPOST_INNER_BISHOP_VAL = S(18, -8);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 18);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(56, -15);
inline const PParam PAWN_PUSH_THREAT_ROOK = S(34, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN = S(55, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 19), S(63, 31), S(74, 70), S(191, 141), S(561, 240), S(923, 1153),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(64, 43), S(61, 31), S(67, 57), S(147, 120), S(688, -89),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -102), S(-61, -84), S(-36, -8), S(18, 71), S(40, 212), S(307, 315),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(36, -5), S(21, 27), S(24, 75), S(92, 152), S(143, 295),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -45), S(3, 2), S(0, -27), S(7, -47), S(3, -96), S(-192, -145),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(12, 103), S(-21, 90), S(-14, 39), S(0, 10), S(9, 14), S(39, 12), S(17, 0),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-181, -51), S(35, -4), S(-7, 43), S(15, 74), S(20, 99), S(40, 98), S(-9, 118),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-226, -222), S(-118, -59), S(-61, -6), S(-17, 27), S(29, 41), S(55, 79), S(92, 75), S(125, 78), S(171, 21),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-238, -285), S(-164, -99), S(-89, -37), S(-53, 11), S(-22, 42), S(-5, 62), S(13, 76), S(32, 81), S(52, 85), S(65, 81), S(91, 67), S(157, 21), S(189, 0), S(250, -33),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-305, -229), S(-150, -82), S(-98, -18), S(-66, -8), S(-39, 14), S(-24, 37), S(-6, 48), S(12, 55), S(29, 67), S(47, 76), S(65, 78), S(78, 80), S(99, 83), S(110, 69), S(256, -57),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-962, -874), S(-253, -656), S(-157, -521), S(-102, -314), S(-94, -105), S(-56, 0), S(-51, 110), S(-27, 123), S(-22, 178), S(-10, 204), S(-1, 229), S(4, 244), S(23, 236), S(33, 247), S(40, 242), S(54, 238), S(60, 229), S(60, 236), S(86, 192), S(108, 155), S(122, 136), S(165, 70), S(178, 62), S(338, -110), S(372, -154), S(615, -310), S(489, -256), S(886, -469),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(453, 1), S(107, -119), S(3, -28), S(-11, 9), S(-39, 12), S(-73, 18), S(-52, 19), S(-61, 13), S(-62, -35),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(88, -31), S(158, -78),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(37, -6), S(137, -43),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(68, -48), S(53, -64), S(104, -63), S(161, -129),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-38, 27), S(-55, 38), S(0, -8), S(161, -97), S(357, -237),
};

inline const PParam PAWN_THREAT_KNIGHT = S(240, 57);
inline const PParam PAWN_THREAT_BISHOP = S(205, 99);
inline const PParam PAWN_THREAT_ROOK   = S(199, 56);
inline const PParam PAWN_THREAT_QUEEN  = S(178, -62);

inline const PParam KNIGHT_THREAT_BISHOP = S(105, 72);
inline const PParam KNIGHT_THREAT_ROOK   = S(244, 5);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -68);

inline const PParam BISHOP_THREAT_KNIGHT = S(110, 34);
inline const PParam BISHOP_THREAT_ROOK   = S(244, 55);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 49);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -6), S(-1, 0), S(0, -11), S(-5, -21), S(-11, -26), S(-17, -32), S(-18, -39), S(-24, -37), S(-34, -43),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(110, 160),    S(100, 207),    S(168, 173),    S(230, 55),     S(176, 49),     S(161, 114),    S(57, 137),     S(116, 114),    //
    S(81, 45),      S(194, 72),     S(170, 15),     S(171, -41),    S(124, -58),    S(68, -9),      S(30, 37),      S(-19, 40),     //
    S(0, 12),       S(19, 16),      S(35, -28),     S(23, -42),     S(5, -46),      S(-36, -40),    S(-76, 7),      S(-102, 29),    //
    S(-26, -35),    S(-7, -7),      S(-12, -41),    S(-31, -38),    S(-56, -47),    S(-77, -38),    S(-127, 11),    S(-146, -1),    //
    S(-27, -65),    S(35, -62),     S(-14, -19),    S(-45, -17),    S(-66, -26),    S(-105, -27),   S(-123, -13),   S(-148, -19),   //
    S(-17, -58),    S(113, -54),    S(67, -18),     S(9, 0),        S(-28, -11),    S(-63, -16),    S(-89, 6),      S(-126, -6),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-399, -157),  S(-350, 61),    S(-459, 236),   S(-125, 70),    S(-254, 94),    S(-338, 101),   S(-572, 87),    S(-543, -16),   //
    S(0, 0),        S(66, 11),      S(168, -55),    S(114, 10),     S(116, 17),     S(54, -7),      S(-6, 12),      S(-24, -33),    //
    S(58, -23),     S(98, 21),      S(194, 7),      S(144, 30),     S(143, 20),     S(63, 28),      S(47, 8),       S(-42, 16),     //
    S(113, 12),     S(99, 33),      S(135, 32),     S(113, 58),     S(122, 45),     S(89, 39),      S(58, 4),       S(39, 13),      //
    S(100, -4),     S(124, -11),    S(123, 7),      S(95, 25),      S(87, 33),      S(83, 27),      S(52, 5),       S(42, -42),     //
    S(13, -21),     S(44, -32),     S(38, -12),     S(50, 31),      S(56, 28),      S(0, 5),        S(5, -33),      S(-34, -39),    //
    S(16, -6),      S(37, -34),     S(21, -28),     S(20, -9),      S(7, -15),      S(-19, -35),    S(-8, -50),     S(-65, -118),   //
    S(-32, -57),    S(5, -14),      S(23, -37),     S(32, -30),     S(24, -23),     S(-23, -53),    S(-35, -29),    S(-84, -82),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-168, 79),    S(-188, 60),    S(-431, 87),    S(-311, 100),   S(-261, 103),   S(-429, 129),   S(-171, 106),   S(-123, 80),    //
    S(4, -33),      S(-11, 45),     S(6, 26),       S(-12, 30),     S(-36, 45),     S(-1, 36),      S(-22, 27),     S(-58, 27),     //
    S(34, 24),      S(83, 11),      S(157, 23),     S(85, 21),      S(60, 25),      S(36, 37),      S(99, 5),       S(-4, 26),      //
    S(51, -20),     S(67, 7),       S(97, 14),      S(95, 40),      S(101, 40),     S(40, 38),      S(34, 10),      S(-14, 21),     //
    S(54, -49),     S(64, -14),     S(64, 6),       S(64, 30),      S(56, 47),      S(16, 37),      S(7, -3),       S(0, -41),      //
    S(66, -41),     S(112, -21),    S(114, -9),     S(56, 35),      S(35, 39),      S(37, 34),      S(67, -7),      S(29, -37),     //
    S(51, -76),     S(101, -52),    S(72, -39),     S(43, -10),     S(34, -25),     S(36, -36),     S(17, -21),     S(37, -86),     //
    S(47, -57),     S(33, -11),     S(38, -4),      S(49, -39),     S(57, -49),     S(54, -8),      S(46, -36),     S(28, -38),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(104, 10),     S(170, 9),      S(99, 39),      S(99, 34),      S(107, 22),     S(55, 36),      S(62, 39),      S(70, 44),      //
    S(13, 68),      S(100, 43),     S(174, 21),     S(99, 64),      S(115, 51),     S(63, 61),      S(3, 79),       S(-5, 85),      //
    S(1, 45),       S(150, 4),      S(181, -1),     S(180, -5),     S(135, 4),      S(60, 45),      S(77, 33),      S(-41, 83),     //
    S(-29, 39),     S(47, 32),      S(79, 24),      S(101, -12),    S(70, 11),      S(8, 59),       S(-9, 59),      S(-80, 66),     //
    S(-93, -9),     S(-11, -4),     S(-26, 13),     S(-43, 13),     S(-48, 10),     S(-66, 50),     S(-96, 47),     S(-115, 36),    //
    S(-116, -29),   S(-41, -56),    S(-47, -26),    S(-67, -25),    S(-50, -43),    S(-100, 10),    S(-101, -7),    S(-125, -10),   //
    S(-178, -18),   S(-78, -78),    S(-54, -64),    S(-49, -61),    S(-56, -57),    S(-76, -40),    S(-96, -63),    S(-128, -47),   //
    S(-143, -17),   S(-113, -12),   S(-59, -48),    S(-34, -65),    S(-48, -50),    S(-61, -38),    S(-76, -46),    S(-94, -30),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(38, 41),      S(78, 7),       S(83, 12),      S(-37, 142),    S(34, 60),      S(-22, 88),     S(43, 3),       S(-20, 28),     //
    S(25, 80),      S(-46, 174),    S(-51, 230),    S(-139, 262),   S(-111, 208),   S(-121, 206),   S(-72, 111),    S(-37, 51),     //
    S(-15, 111),    S(73, 107),     S(14, 185),     S(-2, 195),     S(-44, 177),    S(-75, 176),    S(-6, 71),      S(-40, 43),     //
    S(52, 25),      S(56, 93),      S(20, 128),     S(8, 194),      S(-14, 179),    S(-23, 113),    S(14, 19),      S(1, -13),      //
    S(16, 52),      S(51, 13),      S(25, 83),      S(-14, 141),    S(-26, 127),    S(-20, 85),     S(-9, 7),       S(-6, -42),     //
    S(26, -105),    S(51, -62),     S(50, 7),       S(-1, 33),      S(10, -9),      S(13, -4),      S(24, -75),     S(0, -68),      //
    S(11, -212),    S(45, -311),    S(32, -175),    S(49, -103),    S(22, -83),     S(39, -154),    S(14, -93),     S(-3, -90),     //
    S(-44, -131),   S(17, -383),    S(13, -370),    S(40, -276),    S(42, -193),    S(46, -238),    S(33, -199),    S(-20, -122),   //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-134, -377),  S(101, -20),    S(-57, 31),     S(-166, 56),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(195, -113),   S(10, 144),     S(28, 130),     S(133, 59),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-32, 57),     S(73, 136),     S(112, 105),    S(96, 59),      S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-250, 82),    S(37, 96),      S(30, 94),      S(-24, 79),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-224, 39),    S(-40, 69),     S(-24, 75),     S(-107, 110),   S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-129, 8),     S(62, 11),      S(-28, 63),     S(-71, 88),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(86, -82),     S(139, -42),    S(51, 4),       S(-30, 48),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-37, -110),   S(92, -101),    S(-7, -65),     S(-24, -63),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
};
// Epoch duration: 61.8411s
// clang-format on
}  // namespace Clockwork
