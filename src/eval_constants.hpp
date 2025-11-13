#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(291, 312);
inline const PParam KNIGHT_MAT = S(1190, 941);
inline const PParam BISHOP_MAT = S(1273, 962);
inline const PParam ROOK_MAT   = S(1706, 1687);
inline const PParam QUEEN_MAT  = S(3655, 2904);
inline const PParam TEMPO_VAL  = S(59, 15);

inline const PParam BISHOP_PAIR_VAL   = S(81, 176);
inline const PParam ROOK_OPEN_VAL     = S(105, -28);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 12);

inline const PParam DOUBLED_PAWN_VAL = S(-37, -78);

inline const PParam POTENTIAL_CHECKER_VAL = S(-73, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(5, 52);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 44);

inline const PParam KNIGHT_PROTECTOR = S(-23, -13);
inline const PParam BISHOP_PROTECTOR = S(-17, -3);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 17);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -14);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(55, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 20), S(63, 31), S(74, 70), S(191, 142), S(557, 245), S(920, 1154),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(64, 43), S(61, 31), S(67, 58), S(147, 121), S(685, -86),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -103), S(-61, -84), S(-35, -8), S(19, 70), S(42, 211), S(310, 315),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(36, -5), S(21, 27), S(24, 75), S(92, 151), S(143, 294),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -46), S(3, 2), S(0, -27), S(6, -47), S(3, -97), S(-190, -148),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(13, 103), S(-17, 90), S(-10, 39), S(1, 10), S(11, 15), S(39, 13), S(16, 3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    CS(0, 0), S(-185, -52), S(31, -4), S(-12, 44), S(11, 74), S(17, 99), S(39, 99), S(-4, 117),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-208, -219), S(-99, -56), S(-42, -2), S(0, 31), S(47, 45), S(73, 83), S(109, 79), S(143, 81), S(190, 23),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-228, -284), S(-153, -99), S(-77, -36), S(-41, 13), S(-10, 43), S(6, 65), S(25, 79), S(44, 84), S(64, 88), S(77, 84), S(103, 71), S(168, 26), S(201, 4), S(259, -26),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-304, -227), S(-145, -81), S(-96, -16), S(-64, -6), S(-36, 17), S(-23, 39), S(-5, 52), S(12, 58), S(29, 71), S(46, 80), S(64, 82), S(76, 85), S(96, 88), S(107, 74), S(253, -53),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-964, -875), S(-252, -659), S(-156, -519), S(-102, -314), S(-95, -103), S(-55, -1), S(-51, 108), S(-26, 122), S(-21, 176), S(-9, 202), S(0, 227), S(5, 242), S(23, 234), S(34, 246), S(40, 241), S(54, 237), S(60, 229), S(60, 236), S(86, 192), S(108, 156), S(123, 137), S(166, 72), S(179, 64), S(338, -109), S(370, -151), S(609, -304), S(481, -248), S(856, -449),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(460, -1), S(115, -123), S(5, -29), S(-12, 9), S(-44, 13), S(-81, 18), S(-63, 20), S(-75, 15), S(-79, -32),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(89, -30), S(159, -77),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    CS(0, 0), S(37, -5), S(135, -42),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    CS(0, 0), S(70, -46), S(53, -63), S(103, -64), S(156, -130),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    CS(0, 0), S(-36, 27), S(-53, 35), S(2, -14), S(164, -105), S(356, -249),
};

inline const PParam PAWN_THREAT_KNIGHT = S(240, 55);
inline const PParam PAWN_THREAT_BISHOP = S(205, 98);
inline const PParam PAWN_THREAT_ROOK   = S(199, 57);
inline const PParam PAWN_THREAT_QUEEN  = S(178, -60);

inline const PParam KNIGHT_THREAT_BISHOP = S(105, 75);
inline const PParam KNIGHT_THREAT_ROOK   = S(243, 8);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -63);

inline const PParam BISHOP_THREAT_KNIGHT = S(111, 36);
inline const PParam BISHOP_THREAT_ROOK   = S(244, 56);
inline const PParam BISHOP_THREAT_QUEEN  = S(193, 47);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(1, -6), S(-1, -1), S(0, -11), S(-5, -22), S(-11, -27), S(-16, -33), S(-18, -40), S(-24, -38), S(-33, -45),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(108, 161),    S(101, 207),    S(166, 174),    S(232, 53),     S(180, 48),     S(162, 114),    S(58, 137),     S(116, 114),    //
    S(83, 46),      S(196, 74),     S(171, 17),     S(173, -40),    S(126, -57),    S(70, -7),      S(32, 38),      S(-18, 41),     //
    S(0, 14),       S(20, 17),      S(35, -25),     S(23, -40),     S(5, -44),      S(-36, -37),    S(-76, 9),      S(-103, 30),    //
    S(-26, -34),    S(-7, -5),      S(-11, -39),    S(-30, -35),    S(-55, -44),    S(-76, -36),    S(-127, 12),    S(-146, 0),     //
    S(-28, -63),    S(35, -61),     S(-14, -16),    S(-44, -14),    S(-65, -23),    S(-105, -25),   S(-124, -11),   S(-148, -17),   //
    S(-20, -56),    S(110, -51),    S(65, -15),     S(10, 3),       S(-28, -8),     S(-63, -13),    S(-89, 9),      S(-128, -4),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-295, -118),  S(-250, 88),    S(-363, 272),   S(-29, 100),    S(-159, 126),   S(-235, 133),   S(-468, 122),   S(-436, 28),    //
    S(74, 20),      S(141, 27),     S(244, -41),    S(188, 26),     S(188, 36),     S(129, 14),     S(65, 42),      S(48, 6),       //
    S(104, -18),    S(146, 24),     S(242, 9),      S(193, 35),     S(191, 29),     S(111, 45),     S(102, 29),     S(22, 49),      //
    S(133, 4),      S(125, 23),     S(157, 26),     S(135, 56),     S(146, 47),     S(115, 52),     S(105, 21),     S(99, 44),      //
    S(96, -19),     S(123, -30),    S(118, -5),     S(94, 14),      S(87, 31),      S(101, 37),     S(95, 25),      S(103, -15),    //
    S(-7, -33),     S(15, -51),     S(10, -32),     S(27, 16),      S(49, 21),      S(10, 16),      S(41, -8),      S(24, -2),      //
    S(-27, -20),    S(-13, -52),    S(-28, -46),    S(-13, -23),    S(-4, -22),     S(-7, -26),     S(28, -25),     S(-8, -79),     //
    S(-55, -69),    S(-28, -31),    S(-23, -55),    S(0, -42),      S(5, -25),      S(-15, -41),    S(-4, -4),      S(-27, -44),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-86, 84),     S(-115, 67),    S(-359, 93),    S(-244, 108),   S(-194, 112),   S(-361, 139),   S(-105, 119),   S(-52, 93),     //
    S(56, -26),     S(43, 47),      S(57, 28),      S(38, 32),      S(14, 49),      S(48, 43),      S(27, 37),      S(-5, 42),      //
    S(67, 25),      S(114, 11),     S(193, 19),     S(122, 17),     S(95, 24),      S(73, 40),      S(131, 16),     S(43, 37),      //
    S(64, -22),     S(80, 6),       S(115, 9),      S(114, 34),     S(120, 37),     S(61, 40),      S(61, 20),      S(29, 33),      //
    S(47, -52),     S(54, -16),     S(65, 0),       S(64, 24),      S(59, 44),      S(31, 40),      S(32, 7),       S(44, -31),     //
    S(46, -41),     S(89, -25),     S(91, -14),     S(37, 32),      S(30, 39),      S(46, 39),      S(96, 1),       S(74, -23),     //
    S(25, -76),     S(65, -57),     S(35, -40),     S(19, -11),     S(25, -24),     S(45, -30),     S(44, -12),     S(81, -72),     //
    S(29, -57),     S(6, -13),      S(6, -7),       S(26, -38),     S(46, -45),     S(61, -1),      S(72, -25),     S(73, -24),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(107, 11),     S(171, 10),     S(103, 38),     S(105, 33),     S(112, 22),     S(60, 35),      S(64, 40),      S(71, 45),      //
    S(12, 69),      S(99, 44),      S(177, 19),     S(104, 62),     S(118, 51),     S(63, 61),      S(2, 80),       S(-7, 86),      //
    S(4, 45),       S(152, 3),      S(181, -1),     S(181, -5),     S(135, 4),      S(62, 45),      S(77, 33),      S(-40, 83),     //
    S(-27, 39),     S(49, 32),      S(80, 24),      S(102, -11),    S(70, 11),      S(9, 59),       S(-9, 59),      S(-80, 66),     //
    S(-91, -9),     S(-9, -5),      S(-24, 12),     S(-41, 13),     S(-47, 10),     S(-65, 50),     S(-95, 46),     S(-114, 36),    //
    S(-114, -31),   S(-39, -56),    S(-45, -27),    S(-64, -25),    S(-48, -43),    S(-99, 10),     S(-101, -7),    S(-124, -10),   //
    S(-177, -19),   S(-77, -79),    S(-52, -64),    S(-47, -62),    S(-54, -57),    S(-75, -40),    S(-95, -63),    S(-127, -46),   //
    S(-143, -19),   S(-112, -13),   S(-56, -49),    S(-32, -64),    S(-46, -49),    S(-60, -38),    S(-76, -46),    S(-93, -30),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(43, 35),      S(78, 5),       S(87, 12),      S(-34, 147),    S(39, 62),      S(-20, 89),     S(43, 3),       S(-18, 24),     //
    S(24, 75),      S(-46, 170),    S(-52, 236),    S(-135, 265),   S(-108, 211),   S(-122, 209),   S(-73, 111),    S(-38, 49),     //
    S(-14, 109),    S(72, 110),     S(15, 189),     S(-2, 203),     S(-43, 184),    S(-74, 179),    S(-5, 69),      S(-39, 41),     //
    S(51, 26),      S(56, 94),      S(19, 132),     S(8, 200),      S(-14, 184),    S(-23, 114),    S(14, 19),      S(1, -14),      //
    S(16, 52),      S(51, 14),      S(24, 88),      S(-14, 144),    S(-27, 131),    S(-20, 86),     S(-9, 7),       S(-6, -43),     //
    S(23, -101),    S(50, -60),     S(49, 10),      S(-2, 36),      S(9, -6),       S(12, -3),      S(23, -74),     S(0, -69),      //
    S(3, -200),     S(42, -308),    S(31, -174),    S(48, -103),    S(22, -84),     S(38, -154),    S(13, -93),     S(-4, -91),     //
    S(-58, -113),   S(0, -358),     S(12, -370),    S(41, -279),    S(42, -196),    S(46, -240),    S(33, -202),    S(-19, -127),   //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-129, -380),  S(109, -22),    S(-67, 34),     S(-175, 59),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(197, -112),   S(7, 143),      S(21, 126),     S(126, 54),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-30, 57),     S(66, 132),     S(98, 100),     S(82, 54),      S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-244, 80),    S(32, 92),      S(6, 90),       S(-54, 73),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-205, 35),    S(-43, 65),     S(-48, 70),     S(-146, 106),   S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(-100, 3),     S(67, 7),       S(-53, 60),     S(-113, 86),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(125, -88),    S(152, -44),    S(31, 5),       S(-68, 48),     S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
    S(8, -117),     S(112, -99),    S(-19, -56),    S(-55, -54),    S(20, -10),     S(20, -10),     S(20, -10),     S(20, -10),     //
};
// Epoch duration: 78.62s
// clang-format on
}  // namespace Clockwork
