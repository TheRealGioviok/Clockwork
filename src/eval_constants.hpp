#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(174, 148);
inline const PParam KNIGHT_MAT = S(1113, 187);
inline const PParam BISHOP_MAT = S(1163, 230);
inline const PParam ROOK_MAT   = S(1346, 171);
inline const PParam QUEEN_MAT  = S(2987, 222);
inline const PParam TEMPO_VAL  = S(63, 11);

inline const PParam BISHOP_PAIR_VAL   = S(70, 171);
inline const PParam ROOK_OPEN_VAL     = S(107, -24);
inline const PParam ROOK_SEMIOPEN_VAL = S(41, 10);

inline const PParam DOUBLED_PAWN_VAL = S(-31, -72);

inline const PParam POTENTIAL_CHECKER_VAL = S(-61, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(39, 51);
inline const PParam OUTPOST_BISHOP_VAL    = S(53, 28);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(51, 14);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(51, -17);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(22, 62);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(23, 7), S(49, 41), S(66, 83), S(153, 172), S(424, 215), S(498, 278),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(61, 47), S(50, 51), S(61, 86), S(126, 169), S(460, 70),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-90, -106), S(-80, -83), S(-45, -4), S(23, 74), S(130, 178), S(316, 255),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(29, -20), S(28, -3), S(19, 20), S(11, 70), S(74, 141), S(145, 226),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -30), S(2, 5), S(-3, -16), S(-9, -36), S(-21, -102), S(-271, -131),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(32, 75), S(13, 62), S(-4, 28), S(-9, 14), S(-8, 23), S(28, 19), S(11, -12),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-223, -116), S(4, -26), S(-5, 32), S(16, 78), S(30, 99), S(41, 108), S(18, 103),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(34, -732), S(23, -756), S(18, -767), S(14, -759), S(11, -754), S(8, -760), S(6, -746), S(4, -738), S(5, -731),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(38, -665), S(27, -730), S(20, -739), S(16, -748), S(13, -750), S(11, -750), S(10, -747), S(9, -739), S(8, -740), S(7, -732), S(7, -734), S(6, -728), S(6, -727), S(8, -727),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(14, -668), S(14, -786), S(11, -790), S(9, -788), S(7, -789), S(6, -793), S(5, -793), S(4, -793), S(4, -792), S(3, -791), S(2, -788), S(2, -787), S(2, -784), S(2, -784), S(3, -775),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(25, -622), S(29, -1590), S(25, -1563), S(21, -1558), S(19, -1566), S(17, -1564), S(16, -1558), S(15, -1554), S(14, -1563), S(14, -1559), S(13, -1559), S(13, -1558), S(12, -1560), S(12, -1556), S(12, -1554), S(12, -1555), S(12, -1558), S(12, -1558), S(12, -1557), S(12, -1558), S(12, -1555), S(12, -1554), S(13, -1555), S(14, -1553), S(16, -1554), S(16, -1549), S(17, -1544), S(40, -2014),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(-18, -214), S(-2, -54), S(1, -47), S(0, -13), S(2, -5), S(2, 15), S(1, 13), S(2, 18), S(4, 32),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(-10, 38), S(-0, 24), S(2, 7),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(-4, 61), S(-2, 37), S(-2, 3),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(-13, 38), S(-1, 46), S(2, 67), S(11, 74), S(15, 82),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(5, 71), S(-10, 55), S(-23, 32), S(-33, 6), S(-40, -24), S(-53, -40),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(4, 68), S(1, 14), S(4, 26), S(-6, -15), S(14, 15),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(1, 66), S(2, -1), S(1, -1), S(2, -1), S(3, -5),
};

inline const PParam PAWN_THREAT_KNIGHT = S(226, 88);
inline const PParam PAWN_THREAT_BISHOP = S(207, 129);
inline const PParam PAWN_THREAT_ROOK   = S(197, 124);
inline const PParam PAWN_THREAT_QUEEN  = S(180, -34);

inline const PParam KNIGHT_THREAT_BISHOP = S(114, 84);
inline const PParam KNIGHT_THREAT_ROOK   = S(248, 25);
inline const PParam KNIGHT_THREAT_QUEEN  = S(163, -39);

inline const PParam BISHOP_THREAT_KNIGHT = S(114, 51);
inline const PParam BISHOP_THREAT_ROOK   = S(234, 89);
inline const PParam BISHOP_THREAT_QUEEN  = S(191, 72);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(5, -22), S(-1, -10), S(-3, -18), S(-9, -24), S(-15, -29), S(-22, -32), S(-26, -40), S(-32, -39), S(-44, -37),
};

inline const PParam ROOK_LINEUP = S(13, 78);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(385, 190),    S(224, 302),    S(271, 322),    S(297, 251),    S(325, 213),    S(275, 246),    S(225, 275),    S(334, 200),    //
    S(140, 146),    S(200, 182),    S(187, 158),    S(149, 140),    S(135, 127),    S(133, 136),    S(125, 166),    S(67, 179),     //
    S(105, 133),    S(113, 145),    S(129, 112),    S(112, 101),    S(100, 96),     S(80, 107),     S(50, 141),     S(29, 154),     //
    S(69, 101),     S(88, 125),     S(97, 103),     S(81, 102),     S(59, 103),     S(51, 111),     S(10, 143),     S(-9, 131),     //
    S(60, 70),      S(122, 78),     S(85, 116),     S(72, 123),     S(45, 123),     S(26, 119),     S(9, 137),      S(-10, 113),    //
    S(80, 82),      S(182, 80),     S(126, 128),    S(98, 153),     S(70, 148),     S(51, 140),     S(40, 148),     S(4, 140),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-169, -158),  S(-133, 139),   S(-123, 36),    S(71, 108),     S(14, 107),     S(-99, 105),    S(-250, 154),   S(-229, -90),   //
    S(129, 70),     S(180, 81),     S(238, 62),     S(244, 60),     S(231, 75),     S(161, 91),     S(137, 92),     S(100, 73),     //
    S(215, 55),     S(257, 61),     S(278, 93),     S(263, 78),     S(227, 104),    S(193, 119),    S(174, 102),    S(136, 85),     //
    S(264, 79),     S(289, 92),     S(287, 107),    S(275, 127),    S(275, 135),    S(239, 126),    S(228, 111),    S(206, 74),     //
    S(259, 71),     S(290, 82),     S(277, 108),    S(273, 127),    S(253, 132),    S(252, 124),    S(229, 96),     S(198, 76),     //
    S(190, 58),     S(226, 78),     S(239, 101),    S(246, 121),    S(242, 122),    S(205, 112),    S(181, 81),     S(140, 37),     //
    S(202, 54),     S(227, 71),     S(200, 79),     S(205, 90),     S(196, 89),     S(165, 57),     S(157, 52),     S(123, -14),    //
    S(153, -33),    S(186, 52),     S(204, 55),     S(217, 44),     S(201, 49),     S(162, 27),     S(155, 20),     S(113, -44),    //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(25, 187),     S(-7, 186),     S(-248, 221),   S(-154, 189),   S(-130, 194),   S(-182, 210),   S(-48, 209),    S(54, 174),     //
    S(148, 118),    S(101, 179),    S(117, 145),    S(64, 159),     S(74, 163),     S(111, 163),    S(146, 155),    S(123, 130),    //
    S(221, 122),    S(236, 134),    S(238, 141),    S(200, 142),    S(176, 143),    S(192, 144),    S(214, 134),    S(191, 116),    //
    S(200, 107),    S(228, 129),    S(232, 141),    S(235, 162),    S(261, 149),    S(191, 138),    S(196, 122),    S(158, 117),    //
    S(221, 69),     S(234, 113),    S(246, 132),    S(253, 145),    S(232, 154),    S(208, 150),    S(169, 131),    S(168, 86),     //
    S(249, 68),     S(276, 99),     S(290, 119),    S(241, 146),    S(233, 134),    S(225, 138),    S(232, 108),    S(182, 93),     //
    S(233, 19),     S(304, 66),     S(266, 81),     S(235, 104),    S(216, 107),    S(218, 79),     S(220, 71),     S(221, 43),     //
    S(271, -4),     S(238, 60),     S(243, 83),     S(250, 62),     S(246, 56),     S(252, 70),     S(244, 63),     S(245, 27),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(561, 163),    S(582, 177),    S(535, 201),    S(558, 170),    S(565, 151),    S(537, 160),    S(541, 165),    S(535, 168),    //
    S(458, 211),    S(535, 203),    S(599, 183),    S(552, 187),    S(550, 182),    S(532, 185),    S(468, 210),    S(452, 213),    //
    S(445, 202),    S(560, 169),    S(606, 147),    S(587, 137),    S(554, 149),    S(511, 175),    S(506, 178),    S(436, 216),    //
    S(435, 189),    S(522, 180),    S(559, 156),    S(541, 154),    S(533, 160),    S(489, 186),    S(476, 188),    S(405, 212),    //
    S(405, 152),    S(469, 157),    S(468, 162),    S(450, 160),    S(432, 176),    S(419, 196),    S(389, 192),    S(369, 191),    //
    S(389, 105),    S(446, 122),    S(447, 131),    S(431, 129),    S(425, 130),    S(396, 159),    S(387, 145),    S(353, 150),    //
    S(306, 108),    S(416, 78),     S(434, 87),     S(431, 95),     S(418, 99),     S(404, 111),    S(387, 95),     S(360, 106),    //
    S(356, 89),     S(375, 115),    S(433, 87),     S(446, 82),     S(436, 90),     S(417, 109),    S(405, 103),    S(388, 118),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(668, 264),    S(693, 250),    S(654, 276),    S(616, 324),    S(631, 287),    S(631, 285),    S(665, 224),    S(613, 281),    //
    S(679, 289),    S(651, 366),    S(633, 381),    S(499, 442),    S(515, 423),    S(578, 390),    S(614, 311),    S(620, 292),    //
    S(653, 306),    S(702, 317),    S(654, 363),    S(604, 386),    S(581, 377),    S(610, 341),    S(654, 269),    S(656, 230),    //
    S(696, 241),    S(715, 283),    S(663, 330),    S(652, 363),    S(640, 368),    S(638, 308),    S(687, 229),    S(667, 218),    //
    S(701, 217),    S(703, 258),    S(679, 299),    S(654, 336),    S(654, 331),    S(652, 292),    S(661, 239),    S(680, 174),    //
    S(682, 159),    S(713, 204),    S(717, 253),    S(684, 244),    S(682, 236),    S(683, 250),    S(687, 188),    S(664, 172),    //
    S(663, 49),     S(694, 55),     S(700, 115),    S(719, 140),    S(706, 165),    S(699, 136),    S(670, 168),    S(671, 156),    //
    S(649, 12),     S(670, -78),    S(693, -74),    S(711, 25),     S(713, 87),     S(709, 41),     S(700, 60),     S(667, 86),     //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-424, -204),  S(178, 15),     S(215, -31),    S(-109, -13),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(152, -95),    S(325, 42),     S(276, 44),     S(195, -6),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(77, 17),      S(322, 63),     S(329, 58),     S(199, 36),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-98, 29),     S(212, 72),     S(155, 85),     S(107, 84),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-160, 32),    S(99, 74),      S(117, 95),     S(19, 127),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-90, 14),     S(100, 56),     S(64, 95),      S(11, 119),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(8, -65),      S(63, 9),       S(-5, 58),      S(-78, 97),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-77, -163),   S(7, -80),      S(-78, -35),    S(-101, -44),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(-4, -145), S(-11, -71), S(-14, -76), S(-10, -86), S(-10, -83), S(-13, -75), S(-11, -76), }},
  {{ S(-5, -136), S(-18, -45), S(-15, -55), S(-10, -76), S(-10, -74), S(-14, -60), S(-17, -43), }},
  {{ S(-9, -144), S(-20, -58), S(-15, -84), S(-11, -95), S(-11, -96), S(-14, -86), S(-19, -60), }},
  {{ S(-6, -133), S(-16, -60), S(-12, -75), S(-9, -89), S(-10, -85), S(-12, -76), S(-15, -61), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(6, -158), S(-7, -125), S(-7, -88), S(-3, -92), S(-7, -81),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, -96), S(-8, -77), S(-7, -87), S(-6, -65), S(-7, -76), S(-6, -98), S(-8, -82), }},
  {{ S(-3, -111), S(-5, -37), S(-8, -54), S(-7, -73), S(-7, -89), S(-7, -40), S(-5, -23), }},
  {{ S(-5, -121), S(-7, -50), S(-7, -54), S(-6, -67), S(-6, -68), S(-7, -55), S(-6, -55), }},
  {{ S(-5, -106), S(-8, -56), S(-9, -70), S(-6, -84), S(-5, -95), S(-9, -64), S(-9, -53), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        2207, 844, 10, -158
);
// Epoch duration: 9.86598s
// clang-format on
}  // namespace Clockwork
