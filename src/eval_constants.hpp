#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(179, 139);
inline const PParam KNIGHT_MAT = S(1145, -80);
inline const PParam BISHOP_MAT = S(1222, -40);
inline const PParam ROOK_MAT   = S(1369, -318);
inline const PParam QUEEN_MAT  = S(3345, -582);
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
    S(28, 5), S(53, 38), S(67, 79), S(164, 162), S(463, 204), S(597, 383),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(65, 43), S(52, 46), S(65, 79), S(141, 154), S(497, 60),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-97, -100), S(-83, -78), S(-43, -2), S(26, 75), S(131, 178), S(322, 251),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(28, -21), S(28, -2), S(19, 20), S(10, 69), S(72, 139), S(126, 228),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -28), S(6, 6), S(-3, -16), S(-10, -37), S(-22, -100), S(-259, -142),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(34, 81), S(10, 67), S(-6, 30), S(-11, 12), S(-9, 19), S(25, 16), S(7, -11),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-241, -98), S(-1, -21), S(-9, 35), S(13, 77), S(31, 95), S(48, 101), S(23, 96),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-184, 337), S(-124, 380), S(-94, 403), S(-72, 409), S(-50, 409), S(-33, 415), S(-19, 409), S(-5, 407), S(-6, 404),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-213, 319), S(-160, 369), S(-120, 387), S(-98, 401), S(-80, 409), S(-68, 412), S(-60, 412), S(-52, 410), S(-45, 411), S(-40, 408), S(-36, 407), S(-33, 406), S(-29, 405), S(-39, 405),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(-51, 354), S(-56, 402), S(-39, 410), S(-26, 412), S(-18, 416), S(-13, 420), S(-7, 423), S(-3, 424), S(2, 424), S(7, 423), S(12, 422), S(14, 422), S(17, 421), S(17, 420), S(11, 417),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-175, 455), S(-184, 695), S(-161, 710), S(-142, 729), S(-130, 743), S(-119, 738), S(-113, 749), S(-108, 747), S(-103, 755), S(-99, 754), S(-95, 751), S(-92, 750), S(-89, 747), S(-87, 744), S(-86, 745), S(-86, 744), S(-86, 744), S(-85, 743), S(-86, 744), S(-86, 744), S(-88, 744), S(-93, 745), S(-93, 744), S(-105, 743), S(48, 503), S(54, 501), S(294, 181), S(-183, 752),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(162, -77), S(25, -19), S(5, 5), S(5, 4), S(-2, 1), S(-3, -5), S(5, -4), S(3, -6), S(-6, -11),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(-12, 89), S(3, 70), S(7, 52),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(-3, 111), S(-9, 52), S(-17, -4),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(-13, 77), S(4, 72), S(8, 94), S(18, 101), S(24, 90),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(27, 2158), S(10, 2139), S(-6, 2097), S(2, -1166), S(-8, -1237), S(-22, -1263),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(5, 143), S(0, 11), S(14, 49), S(-8, -14), S(16, 46),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(1, 156), S(3, -8), S(2, -7), S(3, -4), S(4, -9),
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
    S(4, -20), S(-2, -9), S(-5, -16), S(-10, -23), S(-16, -28), S(-22, -31), S(-27, -39), S(-34, -38), S(-46, -36),
};

inline const PParam ROOK_LINEUP = S(12, 86);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(387, 199),    S(231, 305),    S(301, 307),    S(310, 243),    S(333, 208),    S(278, 249),    S(225, 279),    S(330, 209),    //
    S(143, 152),    S(209, 183),    S(203, 154),    S(163, 136),    S(147, 120),    S(141, 135),    S(131, 166),    S(71, 178),     //
    S(107, 134),    S(116, 144),    S(138, 109),    S(120, 100),    S(106, 94),     S(84, 107),     S(53, 141),     S(31, 154),     //
    S(71, 101),     S(91, 124),     S(105, 99),     S(88, 99),      S(65, 100),     S(55, 109),     S(12, 142),     S(-6, 131),     //
    S(63, 71),      S(126, 77),     S(94, 112),     S(81, 114),     S(52, 115),     S(32, 114),     S(13, 133),     S(-7, 112),     //
    S(83, 81),      S(190, 81),     S(147, 124),    S(110, 143),    S(81, 137),     S(58, 132),     S(45, 144),     S(9, 136),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-206, -156),  S(-145, 106),   S(-166, 36),    S(72, 73),      S(19, 70),      S(-103, 70),    S(-269, 123),   S(-272, -85),   //
    S(128, 33),     S(185, 41),     S(246, 22),     S(250, 24),     S(234, 41),     S(168, 51),     S(142, 51),     S(105, 31),     //
    S(221, 13),     S(261, 27),     S(281, 57),     S(266, 48),     S(231, 73),     S(191, 83),     S(178, 61),     S(142, 43),     //
    S(277, 31),     S(296, 53),     S(292, 71),     S(281, 93),     S(281, 98),     S(241, 92),     S(233, 71),     S(219, 26),     //
    S(274, 18),     S(303, 32),     S(285, 65),     S(282, 81),     S(259, 89),     S(255, 84),     S(240, 47),     S(211, 25),     //
    S(202, 7),      S(231, 33),     S(237, 64),     S(248, 79),     S(244, 80),     S(203, 75),     S(184, 38),     S(150, -11),    //
    S(217, 0),      S(239, 19),     S(208, 33),     S(214, 42),     S(204, 42),     S(171, 13),     S(169, 5),      S(136, -62),    //
    S(164, -72),    S(201, -1),     S(217, 4),      S(232, -10),    S(216, -2),     S(177, -25),    S(170, -31),    S(122, -85),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(33, 149),     S(3, 144),      S(-244, 185),   S(-148, 153),   S(-124, 159),   S(-178, 175),   S(-45, 175),    S(58, 142),     //
    S(159, 76),     S(111, 139),    S(128, 105),    S(77, 121),     S(85, 125),     S(117, 127),    S(154, 116),    S(132, 92),     //
    S(233, 84),     S(250, 95),     S(250, 107),    S(212, 107),    S(183, 111),    S(200, 110),    S(223, 98),     S(201, 78),     //
    S(214, 66),     S(239, 92),     S(243, 106),    S(245, 129),    S(271, 115),    S(198, 106),    S(206, 87),     S(168, 79),     //
    S(235, 29),     S(248, 71),     S(258, 93),     S(266, 106),    S(244, 116),    S(219, 112),    S(181, 93),     S(180, 48),     //
    S(264, 26),     S(294, 53),     S(307, 73),     S(256, 102),    S(246, 92),     S(239, 96),     S(248, 64),     S(195, 55),     //
    S(247, -20),    S(323, 17),     S(285, 34),     S(252, 57),     S(232, 62),     S(235, 34),     S(235, 28),     S(237, -1),     //
    S(282, -40),    S(256, 16),     S(261, 35),     S(270, 13),     S(266, 9),      S(273, 22),     S(263, 15),     S(257, -10),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(533, 86),     S(557, 97),     S(514, 118),    S(532, 91),     S(543, 70),     S(514, 78),     S(515, 85),     S(506, 92),     //
    S(425, 138),    S(506, 127),    S(573, 106),    S(521, 113),    S(519, 109),    S(501, 111),    S(435, 138),    S(418, 142),    //
    S(411, 129),    S(528, 94),     S(573, 75),     S(555, 65),     S(521, 76),     S(476, 102),    S(474, 105),    S(402, 145),    //
    S(401, 116),    S(490, 106),    S(526, 83),     S(511, 80),     S(501, 86),     S(457, 112),    S(443, 115),    S(372, 140),    //
    S(369, 82),     S(436, 82),     S(436, 87),     S(419, 86),     S(400, 101),    S(387, 121),    S(357, 119),    S(336, 119),    //
    S(351, 38),     S(412, 49),     S(413, 58),     S(401, 55),     S(393, 56),     S(365, 86),     S(355, 73),     S(319, 80),     //
    S(266, 44),     S(382, 8),      S(400, 18),     S(400, 25),     S(387, 29),     S(372, 41),     S(354, 26),     S(325, 40),     //
    S(316, 29),     S(337, 53),     S(399, 21),     S(413, 16),     S(402, 25),     S(382, 44),     S(369, 40),     S(350, 56),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(572, 108),    S(595, 110),    S(551, 162),    S(506, 229),    S(527, 175),    S(525, 168),    S(555, 110),    S(506, 153),    //
    S(583, 125),    S(556, 193),    S(519, 259),    S(396, 318),    S(414, 287),    S(470, 251),    S(516, 144),    S(525, 125),    //
    S(558, 155),    S(594, 167),    S(533, 263),    S(487, 266),    S(472, 239),    S(505, 198),    S(554, 105),    S(566, 52),     //
    S(615, 58),     S(632, 105),    S(572, 172),    S(570, 182),    S(560, 174),    S(555, 121),    S(604, 40),     S(586, 21),     //
    S(624, 20),     S(628, 55),     S(601, 109),    S(579, 135),    S(577, 128),    S(575, 88),     S(583, 32),     S(601, -30),    //
    S(602, -42),    S(634, 1),      S(637, 53),     S(606, 43),     S(601, 38),     S(601, 50),     S(606, -14),    S(585, -36),    //
    S(583, -155),   S(608, -137),   S(616, -81),    S(637, -58),    S(624, -34),    S(616, -61),    S(586, -29),    S(590, -47),    //
    S(566, -185),   S(586, -269),   S(609, -267),   S(626, -168),   S(629, -108),   S(626, -153),   S(617, -137),   S(581, -107),   //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-460, -219),  S(182, 31),     S(217, -15),    S(-71, -7),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(169, -100),   S(354, 49),     S(274, 52),     S(199, -4),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(125, 14),     S(367, 54),     S(333, 57),     S(212, 32),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-47, 20),     S(230, 60),     S(162, 79),     S(122, 79),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-123, 21),    S(102, 60),     S(109, 85),     S(29, 120),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-75, 9),      S(97, 41),      S(56, 82),      S(24, 108),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(6, -55),      S(49, 7),       S(-18, 56),     S(-79, 95),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-91, -129),   S(5, -68),      S(-81, -24),    S(-96, -28),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-7, -322), S(-17, -196), S(-20, -205), S(-15, -231), S(-15, -229), S(-19, -222), S(-16, -205), }},
  {{ S(-9, -313), S(-27, -174), S(-23, -195), S(-16, -225), S(-16, -220), S(-22, -201), S(-26, -175), }},
  {{ S(-12, -335), S(-25, -208), S(-19, -247), S(-14, -262), S(-14, -260), S(-18, -250), S(-24, -214), }},
  {{ S(-10, -258), S(-23, -158), S(-17, -166), S(-12, -187), S(-13, -182), S(-17, -166), S(-21, -156), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(11, -473), S(-7, -392), S(-7, -204), S(-1, -164), S(-5, -208),
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
// Epoch duration: 9.63747s
// clang-format on
}  // namespace Clockwork
