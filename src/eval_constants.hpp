#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(281, 315);
inline const PParam KNIGHT_MAT = S(940, 689);
inline const PParam BISHOP_MAT = S(1203, 951);
inline const PParam ROOK_MAT   = S(1660, 1682);
inline const PParam QUEEN_MAT  = S(3511, 3128);
inline const PParam TEMPO_VAL  = S(59, 14);

inline const PParam BISHOP_PAIR_VAL   = S(73, 178);
inline const PParam ROOK_OPEN_VAL     = S(111, -35);
inline const PParam ROOK_SEMIOPEN_VAL = S(41, 11);

inline const PParam DOUBLED_PAWN_VAL = S(-30, -79);

inline const PParam POTENTIAL_CHECKER_VAL = S(-81, 3);
inline const PParam OUTPOST_KNIGHT_VAL    = S(2, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(41, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 16);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(59, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 30);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -60);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, 21), S(61, 31), S(69, 71), S(183, 140), S(551, 241), S(910, 1151),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(60, 43), S(59, 31), S(65, 56), S(142, 119), S(688, -93),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -103), S(-59, -85), S(-38, -4), S(15, 72), S(37, 213), S(299, 318),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(64, -52), S(46, -12), S(28, 23), S(26, 73), S(80, 155), S(122, 305),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -48), S(3, 1), S(-7, -24), S(4, -44), S(8, -98), S(-181, -150),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(4, 108), S(-24, 93), S(-14, 39), S(1, 8), S(10, 11), S(42, 9), S(20, -2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-173, -52), S(35, -5), S(-8, 45), S(15, 76), S(16, 102), S(37, 103), S(-10, 121),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-101, -66), S(0, 101), S(54, 151), S(98, 182), S(145, 193), S(172, 231), S(210, 225), S(245, 223), S(295, 163),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-233, -283), S(-165, -98), S(-93, -37), S(-58, 15), S(-29, 44), S(-11, 67), S(9, 81), S(31, 86), S(53, 87), S(70, 81), S(100, 66), S(174, 14), S(218, -14), S(290, -52),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-296, -226), S(-146, -82), S(-100, -13), S(-63, -4), S(-41, 17), S(-27, 41), S(-12, 54), S(6, 58), S(23, 70), S(40, 77), S(58, 77), S(74, 77), S(96, 79), S(108, 65), S(252, -61),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-925, -872), S(33, -141), S(-1, -27), S(-13, 26), S(-8, -13), S(6, -20), S(0, 11), S(0, -17), S(2, -9), S(2, -12), S(1, -10), S(-1, -4), S(3, -8), S(0, -10), S(-10, 12), S(-15, 17), S(-13, 9), S(-12, 15), S(-6, 11), S(0, 1), S(9, -10), S(-8, 13), S(-8, 21), S(14, -4), S(16, -10), S(101, -41), S(310, -175), S(649, -363),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(447, -5), S(110, -121), S(5, -29), S(-9, 10), S(-41, 13), S(-76, 19), S(-61, 24), S(-78, 21), S(-82, -27),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(-4, -3), S(-3, -5),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(-2, -4), S(-2, -1),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(-2, -5), S(0, -6), S(-6, 1), S(-1, -6),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-29, 26), S(-47, 31), S(-16, 7), S(153, -93), S(370, -258),
};

inline const PParam PAWN_THREAT_KNIGHT = S(231, 50);
inline const PParam PAWN_THREAT_BISHOP = S(201, 97);
inline const PParam PAWN_THREAT_ROOK   = S(189, 54);
inline const PParam PAWN_THREAT_QUEEN  = S(183, -65);

inline const PParam KNIGHT_THREAT_BISHOP = S(100, 71);
inline const PParam KNIGHT_THREAT_ROOK   = S(246, -3);
inline const PParam KNIGHT_THREAT_QUEEN  = S(145, -71);

inline const PParam BISHOP_THREAT_KNIGHT = S(101, 33);
inline const PParam BISHOP_THREAT_ROOK   = S(240, 48);
inline const PParam BISHOP_THREAT_QUEEN  = S(178, 45);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -8), S(0, 0), S(0, -12), S(-4, -22), S(-11, -27), S(-16, -34), S(-17, -43), S(-23, -37), S(-32, -46),
};

inline const std::array<PParam, 6> COORDINATION_POS_COUNT_MG = {
    S(-4, 9), S(-1, 4), S(-8, 14), S(10, -5), S(14, 3), S(35, 14),
};
inline const std::array<PParam, 6> COORDINATION_POS_COUNT_EG = {
    S(13, -19), S(22, -19), S(21, -15), S(22, 20), S(-9, 98), S(0, 0),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(109, 158),    S(95, 207),     S(163, 172),    S(225, 50),     S(174, 47),     S(158, 110),    S(52, 137),     S(116, 111),    //
    S(83, 42),      S(199, 68),     S(178, 11),     S(182, -48),    S(136, -66),    S(74, -12),     S(37, 32),      S(-21, 40),     //
    S(4, 8),        S(29, 10),      S(47, -34),     S(34, -48),     S(16, -52),     S(-27, -44),    S(-70, 5),      S(-101, 28),    //
    S(-20, -37),    S(1, -10),      S(-5, -44),     S(-22, -41),    S(-50, -48),    S(-72, -40),    S(-125, 9),     S(-143, -1),    //
    S(-28, -67),    S(32, -63),     S(-20, -17),    S(-52, -13),    S(-77, -21),    S(-115, -23),   S(-131, -10),   S(-151, -16),   //
    S(-18, -59),    S(105, -53),    S(56, -13),     S(-4, 9),       S(-43, -2),     S(-79, -7),     S(-99, 11),     S(-133, -3),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-316, -109),  S(-285, 118),   S(-371, 286),   S(-6, 104),     S(-149, 137),   S(-275, 160),   S(-507, 146),   S(-467, 37),    //
    S(82, 41),      S(144, 59),     S(271, -17),    S(250, 34),     S(241, 48),     S(135, 42),     S(63, 62),      S(41, 20),      //
    S(160, 9),      S(216, 45),     S(308, 43),     S(288, 52),     S(271, 50),     S(145, 81),     S(126, 54),     S(37, 59),      //
    S(194, 53),     S(221, 56),     S(228, 80),     S(223, 97),     S(205, 98),     S(164, 92),     S(132, 53),     S(104, 59),     //
    S(145, 52),     S(172, 50),     S(158, 81),     S(130, 100),    S(119, 107),    S(115, 103),    S(95, 69),      S(82, 10),      //
    S(47, 45),      S(73, 39),      S(63, 64),      S(72, 108),     S(78, 104),     S(25, 78),      S(35, 36),      S(5, 27),       //
    S(49, 56),      S(67, 35),      S(44, 45),      S(42, 68),      S(30, 60),      S(1, 39),       S(21, 17),      S(-27, -56),    //
    S(8, 2),        S(41, 47),      S(54, 27),      S(61, 37),      S(53, 44),      S(6, 15),       S(-2, 35),      S(-41, -23),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-163, 83),    S(-176, 62),    S(-406, 88),    S(-274, 100),   S(-239, 105),   S(-410, 132),   S(-164, 109),   S(-118, 85),    //
    S(18, -37),     S(2, 41),       S(38, 18),      S(16, 28),      S(-14, 45),     S(10, 37),      S(-12, 28),     S(-52, 30),     //
    S(99, 2),       S(123, 0),      S(210, 8),      S(139, 9),      S(104, 16),     S(65, 33),      S(114, 5),      S(19, 19),      //
    S(77, -25),     S(74, 11),      S(123, 11),     S(128, 35),     S(132, 36),     S(61, 37),      S(34, 15),      S(-5, 21),      //
    S(61, -46),     S(59, -5),      S(63, 12),      S(72, 33),      S(62, 51),      S(19, 41),      S(5, 5),        S(5, -41),      //
    S(67, -32),     S(109, -14),    S(103, -1),     S(44, 44),      S(26, 46),      S(27, 42),      S(66, -3),      S(36, -31),     //
    S(52, -71),     S(95, -44),     S(60, -29),     S(28, 2),       S(19, -13),     S(24, -28),     S(11, -13),     S(38, -82),     //
    S(49, -53),     S(31, -5),      S(32, 0),       S(37, -31),     S(47, -44),     S(40, 0),       S(39, -30),     S(31, -37),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(129, 4),      S(196, -3),     S(125, 25),     S(133, 12),     S(133, 6),      S(77, 25),      S(81, 30),      S(90, 38),      //
    S(40, 53),      S(131, 24),     S(215, -4),     S(148, 35),     S(155, 24),     S(98, 40),      S(31, 62),      S(18, 71),      //
    S(19, 34),      S(178, -15),    S(211, -26),    S(200, -25),    S(155, -13),    S(75, 32),      S(87, 24),      S(-33, 76),     //
    S(-23, 38),     S(65, 21),      S(95, 9),       S(104, -19),    S(71, 7),       S(12, 57),      S(-7, 56),      S(-82, 70),     //
    S(-92, -5),     S(-6, -6),      S(-17, 6),      S(-45, 15),     S(-54, 13),     S(-69, 52),     S(-95, 52),     S(-120, 42),    //
    S(-123, -22),   S(-40, -53),    S(-48, -25),    S(-77, -19),    S(-62, -35),    S(-109, 16),    S(-104, -1),    S(-127, -3),    //
    S(-186, -9),    S(-82, -72),    S(-62, -58),    S(-64, -49),    S(-72, -44),    S(-89, -29),    S(-103, -55),   S(-131, -38),   //
    S(-146, -11),   S(-114, -4),    S(-63, -41),    S(-44, -56),    S(-58, -39),    S(-70, -26),    S(-84, -37),    S(-96, -22),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(-13, 119),    S(52, 71),      S(82, 64),      S(-36, 188),    S(50, 93),      S(-7, 121),     S(30, 55),      S(-60, 97),     //
    S(9, 113),      S(-27, 194),    S(-27, 253),    S(-111, 276),   S(-78, 218),    S(-82, 215),    S(-40, 126),    S(-44, 82),     //
    S(-36, 140),    S(81, 136),     S(39, 194),     S(27, 202),     S(-9, 180),     S(-38, 179),    S(7, 98),       S(-45, 73),     //
    S(34, 47),      S(52, 126),     S(33, 144),     S(43, 180),     S(24, 169),     S(-1, 124),     S(24, 46),      S(-11, 28),     //
    S(-3, 66),      S(51, 38),      S(38, 101),     S(15, 140),     S(3, 123),      S(0, 98),       S(2, 34),       S(-12, -13),    //
    S(-5, -99),     S(38, -43),     S(53, 29),      S(11, 53),      S(24, 11),      S(31, 17),      S(23, -45),     S(-16, -40),    //
    S(-37, -205),   S(44, -287),    S(40, -153),    S(54, -75),     S(30, -55),     S(45, -123),    S(21, -65),     S(-25, -44),    //
    S(-138, -102),  S(-26, -342),   S(-12, -320),   S(35, -226),    S(40, -143),    S(36, -183),    S(2, -139),     S(-92, -27),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-134, -379),  S(79, -13),     S(-64, 31),     S(-188, 58),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(174, -111),   S(-10, 152),    S(6, 132),      S(121, 55),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-53, 61),     S(37, 144),     S(77, 110),     S(69, 62),      S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-270, 84),    S(2, 102),      S(-16, 101),    S(-69, 88),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-238, 42),    S(-78, 79),     S(-83, 90),     S(-171, 128),   S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-137, 9),     S(31, 18),      S(-74, 75),     S(-124, 102),   S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(91, -90),     S(138, -46),    S(41, 0),       S(-42, 48),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-17, -122),   S(104, -113),   S(3, -74),      S(-14, -70),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
};
// Epoch duration: 61.8411s
// clang-format on
}  // namespace Clockwork
