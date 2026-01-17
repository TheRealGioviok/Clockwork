#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(216, 252);
inline const PParam KNIGHT_MAT = S(617, 428);
inline const PParam BISHOP_MAT = S(597, 417);
inline const PParam ROOK_MAT   = S(1023, 925);
inline const PParam QUEEN_MAT  = S(2613, 1543);
inline const PParam TEMPO_VAL  = S(63, 13);

inline const PParam BISHOP_PAIR_VAL   = S(77, 162);
inline const PParam ROOK_OPEN_VAL     = S(113, -25);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 18);

inline const PParam DOUBLED_PAWN_VAL = S(-19, -85);

inline const PParam POTENTIAL_CHECKER_VAL = S(-66, -11);
inline const PParam OUTPOST_KNIGHT_VAL    = S(50, 40);
inline const PParam OUTPOST_BISHOP_VAL    = S(60, 26);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(47, 4);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(56, -24);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(37, 35);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 11), S(55, 36), S(70, 70), S(168, 158), S(454, 236), S(472, 562),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(64, 41), S(57, 35), S(73, 64), S(175, 115), S(557, 5),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-82, -93), S(-81, -73), S(-56, 7), S(21, 79), S(108, 211), S(387, 342),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(40, -34), S(35, -6), S(29, 19), S(28, 64), S(94, 131), S(199, 218),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(11, -34), S(1, 6), S(-1, -22), S(-4, -42), S(-14, -89), S(-262, -108),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(16, 112), S(-10, 91), S(-9, 37), S(-6, 11), S(3, 10), S(47, 4), S(7, -3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-284, -19), S(-21, 13), S(-3, 42), S(38, 55), S(39, 75), S(47, 79), S(23, 73),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-83, -124), S(14, 28), S(68, 100), S(103, 130), S(151, 140), S(179, 171), S(216, 164), S(252, 165), S(299, 105),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-61, -167), S(6, -7), S(67, 34), S(95, 82), S(124, 111), S(142, 130), S(151, 146), S(170, 151), S(181, 162), S(201, 151), S(223, 141), S(281, 98), S(285, 97), S(347, 56),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(121, -45), S(42, 116), S(71, 134), S(90, 137), S(104, 146), S(109, 159), S(117, 166), S(127, 165), S(135, 171), S(146, 173), S(159, 171), S(169, 170), S(176, 169), S(196, 148), S(303, 54),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-29, -86), S(50, -30), S(100, -1), S(129, 91), S(140, 150), S(157, 181), S(160, 224), S(169, 229), S(172, 253), S(178, 263), S(182, 276), S(187, 279), S(199, 268), S(204, 270), S(208, 267), S(212, 262), S(217, 255), S(217, 255), S(229, 234), S(248, 216), S(262, 197), S(277, 165), S(302, 147), S(409, 42), S(436, 4), S(402, 10), S(266, 85), S(271, 60),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(377, -87), S(126, -111), S(42, -40), S(26, -7), S(3, -7), S(-25, 5), S(-44, 27), S(-69, 40), S(-83, 15),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(324, 250), S(367, 236), S(392, 205),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(443, 344), S(249, 205), S(107, 39),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(322, 258), S(379, 281), S(357, 314), S(408, 383), S(511, 365),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(611, 615), S(370, 492), S(156, 356), S(8, 165), S(-6, -88), S(-24, -363),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-82, 39), S(-46, 12), S(-234, -131), S(1, 60), S(-196, -142),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-25, 19), S(-20, 19), S(-19, 15), S(-16, 9), S(-21, -13),
};

inline const PParam PAWN_THREAT_KNIGHT = S(240, 62);
inline const PParam PAWN_THREAT_BISHOP = S(215, 116);
inline const PParam PAWN_THREAT_ROOK   = S(200, 101);
inline const PParam PAWN_THREAT_QUEEN  = S(182, -38);

inline const PParam KNIGHT_THREAT_BISHOP = S(117, 74);
inline const PParam KNIGHT_THREAT_ROOK   = S(252, 17);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -17);

inline const PParam BISHOP_THREAT_KNIGHT = S(114, 38);
inline const PParam BISHOP_THREAT_ROOK   = S(235, 74);
inline const PParam BISHOP_THREAT_QUEEN  = S(197, 53);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -20), S(-3, -8), S(-4, -18), S(-9, -24), S(-15, -31), S(-21, -34), S(-24, -45), S(-29, -46), S(-38, -50),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(137, 152),    S(9, 220),      S(114, 174),    S(149, 76),     S(200, 15),     S(116, 90),     S(64, 119),     S(175, 72),     //
    S(56, 96),      S(103, 146),    S(117, 92),     S(104, 12),     S(91, -13),     S(67, 25),      S(51, 66),      S(17, 81),      //
    S(29, 65),      S(34, 80),      S(41, 49),      S(44, 1),       S(36, -12),     S(6, 15),       S(-9, 46),      S(-27, 67),     //
    S(7, 23),       S(26, 53),      S(22, 35),      S(24, -6),      S(5, -13),      S(-6, 9),       S(-43, 49),     S(-57, 35),     //
    S(-2, -2),      S(48, 11),      S(26, 60),      S(24, 16),      S(0, 10),       S(-28, 14),     S(-41, 25),     S(-60, 17),     //
    S(33, -4),      S(121, 0),      S(46, 37),      S(52, 36),      S(27, 24),      S(12, 9),       S(-6, 34),      S(-42, 32),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-379, -128),  S(-287, 89),    S(-521, 339),   S(-6, 66),      S(-76, 70),     S(-202, 49),    S(-441, 100),   S(-438, -48),   //
    S(10, 41),      S(58, 43),      S(141, 3),      S(120, 35),     S(111, 48),     S(43, 44),      S(22, 53),      S(-6, 27),      //
    S(81, 11),      S(97, 53),      S(151, 70),     S(112, 87),     S(84, 96),      S(24, 105),     S(30, 48),      S(7, 39),       //
    S(134, 55),     S(120, 72),     S(126, 96),     S(97, 128),     S(116, 118),    S(84, 104),     S(84, 61),      S(80, 38),      //
    S(124, 42),     S(162, 31),     S(137, 74),     S(123, 97),     S(108, 94),     S(109, 84),     S(107, 35),     S(70, 35),      //
    S(68, 16),      S(101, 12),     S(82, 48),      S(102, 73),     S(104, 68),     S(52, 57),      S(52, 22),      S(18, 4),       //
    S(81, 6),       S(103, -9),     S(75, 11),      S(73, 33),      S(62, 36),      S(40, -7),      S(45, 5),       S(3, -56),      //
    S(20, -12),     S(58, 45),      S(82, -3),      S(102, -16),    S(83, 5),       S(34, -13),     S(27, 19),      S(-28, -37),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-100, 105),   S(-129, 87),    S(-413, 158),   S(-281, 128),   S(-250, 139),   S(-339, 167),   S(-169, 139),   S(-94, 115),    //
    S(15, 33),      S(-41, 96),     S(-9, 54),      S(-77, 104),    S(-88, 107),    S(-34, 85),     S(-6, 68),      S(-24, 57),     //
    S(67, 54),      S(103, 47),     S(95, 79),      S(59, 71),      S(25, 72),      S(25, 80),      S(65, 59),      S(43, 38),      //
    S(54, 31),      S(72, 51),      S(95, 60),      S(72, 100),     S(101, 87),     S(34, 73),      S(45, 46),      S(11, 40),      //
    S(70, 7),       S(81, 34),      S(87, 54),      S(96, 74),      S(82, 82),      S(48, 72),      S(9, 55),       S(17, 22),      //
    S(88, 9),       S(124, 15),     S(139, 32),     S(86, 70),      S(79, 54),      S(82, 52),      S(91, 28),      S(30, 34),      //
    S(72, -40),     S(156, -19),    S(114, -4),     S(84, 22),      S(64, 33),      S(73, 4),       S(73, 12),      S(62, -27),     //
    S(74, -28),     S(57, 21),      S(69, 45),      S(87, 2),       S(92, -10),     S(84, 49),      S(79, 5),       S(56, -2),      //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(227, 73),     S(262, 81),     S(217, 107),    S(226, 89),     S(222, 89),     S(166, 103),    S(183, 104),    S(179, 107),    //
    S(127, 126),    S(190, 115),    S(275, 92),     S(208, 115),    S(208, 118),    S(163, 126),    S(83, 155),     S(80, 154),     //
    S(102, 117),    S(232, 82),     S(261, 75),     S(236, 77),     S(196, 88),     S(149, 111),    S(143, 115),    S(66, 147),     //
    S(76, 106),     S(152, 106),    S(195, 88),     S(165, 89),     S(161, 97),     S(118, 117),    S(95, 119),     S(34, 133),     //
    S(37, 61),      S(107, 72),     S(91, 86),      S(77, 79),      S(68, 86),      S(53, 114),     S(21, 104),     S(-5, 103),     //
    S(6, 32),       S(69, 30),      S(71, 53),      S(52, 48),      S(57, 42),      S(28, 78),      S(16, 58),      S(-25, 73),     //
    S(-78, 46),     S(38, -11),     S(52, 15),      S(56, 20),      S(47, 22),      S(34, 36),      S(11, 20),      S(-17, 35),     //
    S(-32, 37),     S(-21, 59),     S(50, 22),      S(73, 7),       S(54, 25),      S(42, 41),      S(26, 34),      S(6, 56),       //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(95, 97),      S(173, 34),     S(154, 69),     S(77, 169),     S(89, 133),     S(79, 127),     S(113, 63),     S(16, 135),     //
    S(118, 129),    S(65, 225),     S(64, 239),     S(-74, 297),    S(-70, 290),    S(-9, 254),     S(17, 174),     S(36, 152),     //
    S(47, 189),     S(143, 176),    S(70, 241),     S(40, 255),     S(-11, 262),    S(4, 217),      S(69, 130),     S(49, 99),      //
    S(121, 95),     S(117, 161),    S(83, 196),     S(55, 248),     S(45, 250),     S(42, 186),     S(92, 97),      S(87, 67),      //
    S(104, 96),     S(115, 114),    S(90, 161),     S(61, 206),     S(62, 200),     S(58, 163),     S(74, 93),      S(87, 43),      //
    S(92, 17),      S(126, 48),     S(125, 117),    S(88, 97),      S(84, 91),      S(91, 111),     S(95, 55),      S(80, 28),      //
    S(72, -101),    S(116, -141),   S(116, -57),    S(124, -9),     S(106, 19),     S(107, -14),    S(76, 35),      S(77, 21),      //
    S(29, -66),     S(73, -250),    S(77, -227),    S(105, -141),   S(111, -64),    S(113, -115),   S(103, -83),    S(54, -35),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-310, -270),  S(7, 82),       S(138, 17),     S(-70, -2),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(136, -104),   S(200, 42),     S(170, 59),     S(96, -3),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(67, 34),      S(227, 57),     S(214, 53),     S(79, 28),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-185, 51),    S(137, 36),     S(53, 46),      S(12, 44),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-212, 26),    S(69, 10),      S(78, 7),       S(-41, 52),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-98, 11),     S(144, -17),    S(101, 0),      S(40, 24),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(6, -25),      S(121, -18),    S(78, -10),     S(-3, 18),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-123, -45),   S(-14, -14),    S(-83, -11),    S(-91, -42),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-70, 43), S(-6, -19), S(43, -30), S(17, -11), S(21, -11), S(40, -30), S(-2, -28), }},
  {{ S(-83, 43), S(33, -9), S(45, -31), S(-9, 16), S(-7, 3), S(48, -41), S(30, -18), }},
  {{ S(-60, 35), S(41, -5), S(-19, -18), S(-17, 5), S(-17, -2), S(-23, -27), S(40, -9), }},
  {{ S(-65, 18), S(3, 34), S(-8, 11), S(-12, 16), S(-5, 10), S(1, 4), S(3, 9), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-19, -79), S(33, -18), S(11, -8), S(-16, -4), S(10, 23),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-33, -1), S(0, -3), S(9, -7), S(-1, 6), S(6, 13), S(-0, -1), S(-1, -3), }},
  {{ S(-41, 10), S(-19, -6), S(5, -4), S(-12, 30), S(-2, 22), S(5, -6), S(-19, -10), }},
  {{ S(-4, -4), S(21, -32), S(7, -6), S(-5, 10), S(0, 14), S(9, -5), S(17, -31), }},
  {{ S(-12, 22), S(6, 17), S(28, 9), S(1, 1), S(-1, 2), S(26, 12), S(19, 12), }},
}};
// Epoch duration: 5.23s
// clang-format on
}  // namespace Clockwork
