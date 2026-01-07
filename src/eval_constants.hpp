#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(171, 155);
inline const PParam KNIGHT_MAT = S(528, 327);
inline const PParam BISHOP_MAT = S(480, 286);
inline const PParam ROOK_MAT   = S(552, 416);
inline const PParam QUEEN_MAT  = S(1102, 573);
inline const PParam TEMPO_VAL  = S(63, 14);

inline const PParam BISHOP_PAIR_VAL   = S(77, 163);
inline const PParam ROOK_OPEN_VAL     = S(115, -27);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 16);

inline const PParam DOUBLED_PAWN_VAL = S(-33, -75);

inline const PParam POTENTIAL_CHECKER_VAL = S(-68, -10);
inline const PParam OUTPOST_KNIGHT_VAL    = S(52, 39);
inline const PParam OUTPOST_BISHOP_VAL    = S(62, 25);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(49, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(57, -24);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(37, 35);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(69, -52);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(21, 9), S(58, 31), S(72, 67), S(182, 150), S(478, 228), S(664, 691),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(69, 37), S(58, 34), S(71, 64), S(176, 115), S(592, -9),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-85, -93), S(-81, -72), S(-57, 7), S(28, 73), S(108, 191), S(305, 273),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(41, -32), S(36, -2), S(30, 19), S(28, 62), S(102, 122), S(221, 197),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(8, -28), S(-2, 13), S(-8, -10), S(-9, -35), S(-17, -82), S(-272, -99),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(8, 95), S(-27, 92), S(-6, 41), S(-1, 10), S(9, 8), S(54, 3), S(16, -4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-302, -14), S(-37, 19), S(-14, 48), S(36, 61), S(43, 80), S(52, 87), S(22, 83),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(17, -60), S(116, 94), S(172, 166), S(210, 195), S(257, 206), S(285, 239), S(322, 232), S(359, 234), S(405, 173),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-6, -113), S(64, 46), S(128, 89), S(156, 138), S(184, 167), S(203, 187), S(212, 204), S(231, 208), S(243, 219), S(262, 208), S(286, 197), S(344, 154), S(349, 153), S(419, 108),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(283, 104), S(205, 264), S(233, 284), S(250, 288), S(263, 299), S(269, 311), S(276, 318), S(287, 317), S(295, 323), S(305, 325), S(317, 324), S(327, 323), S(334, 322), S(354, 302), S(461, 207),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(470, 133), S(534, 244), S(582, 279), S(610, 375), S(621, 434), S(638, 464), S(642, 507), S(651, 510), S(654, 534), S(660, 544), S(664, 557), S(669, 561), S(680, 549), S(685, 552), S(689, 549), S(693, 544), S(698, 537), S(698, 537), S(710, 516), S(729, 497), S(745, 477), S(760, 444), S(788, 424), S(908, 312), S(960, 259), S(955, 251), S(875, 298), S(968, 228),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(785, -555), S(353, -383), S(197, -231), S(122, -131), S(36, -65), S(-53, 8), S(-143, 93), S(-237, 172), S(-310, 205),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(211, 212), S(327, 167), S(427, 106),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(436, 342), S(259, 223), S(143, 72),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(294, 299), S(419, 294), S(458, 303), S(556, 354), S(710, 314),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(826, 717), S(548, 586), S(299, 442), S(114, 242), S(60, -18), S(-0, -299),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-128, 89), S(46, -35), S(-195, -126), S(70, 30), S(-213, -138),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-27, 19), S(-20, 19), S(-20, 15), S(-15, 9), S(-22, -11),
};

inline const PParam INNER_SHELTER_PAWNS = S(-43, 52);
inline const PParam OUTER_SHELTER_PAWNS = S(27, 7);

inline const PParam PAWN_THREAT_KNIGHT = S(244, 62);
inline const PParam PAWN_THREAT_BISHOP = S(217, 118);
inline const PParam PAWN_THREAT_ROOK   = S(203, 101);
inline const PParam PAWN_THREAT_QUEEN  = S(186, -44);

inline const PParam KNIGHT_THREAT_BISHOP = S(118, 73);
inline const PParam KNIGHT_THREAT_ROOK   = S(257, 15);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -18);

inline const PParam BISHOP_THREAT_KNIGHT = S(115, 38);
inline const PParam BISHOP_THREAT_ROOK   = S(238, 71);
inline const PParam BISHOP_THREAT_QUEEN  = S(199, 52);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -19), S(-3, -8), S(-4, -18), S(-9, -25), S(-15, -31), S(-21, -34), S(-24, -45), S(-29, -46), S(-37, -52),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(296, 273),    S(199, 342),    S(311, 307),    S(297, 245),    S(348, 175),    S(250, 253),    S(203, 278),    S(309, 229),    //
    S(155, 171),    S(206, 214),    S(197, 160),    S(161, 128),    S(144, 98),     S(111, 140),    S(91, 180),     S(57, 187),     //
    S(101, 131),    S(101, 147),    S(115, 105),    S(100, 99),     S(84, 89),      S(53, 106),     S(24, 142),     S(9, 160),      //
    S(84, 81),      S(100, 104),    S(106, 75),     S(89, 81),      S(61, 80),      S(42, 93),      S(-7, 139),     S(-21, 125),    //
    S(66, 63),      S(121, 67),     S(67, 113),     S(53, 113),     S(35, 107),     S(7, 109),      S(-11, 125),    S(-27, 112),    //
    S(68, 69),      S(189, 78),     S(132, 121),    S(85, 140),     S(64, 124),     S(43, 115),     S(30, 136),     S(-9, 128),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-287, -44),   S(-218, 185),   S(-459, 440),   S(93, 148),     S(20, 155),     S(-108, 133),   S(-373, 197),   S(-340, 33),    //
    S(112, 123),    S(162, 122),    S(245, 81),     S(221, 117),    S(217, 129),    S(150, 122),    S(130, 131),    S(104, 106),    //
    S(179, 94),     S(193, 140),    S(249, 153),    S(212, 171),    S(186, 176),    S(127, 185),    S(139, 124),    S(109, 120),    //
    S(238, 135),    S(223, 152),    S(225, 178),    S(200, 211),    S(218, 199),    S(191, 183),    S(192, 139),    S(190, 114),    //
    S(230, 120),    S(267, 108),    S(243, 151),    S(228, 175),    S(215, 173),    S(217, 161),    S(217, 110),    S(179, 113),    //
    S(175, 93),     S(205, 89),     S(188, 127),    S(208, 150),    S(210, 147),    S(160, 133),    S(159, 98),     S(125, 82),     //
    S(187, 86),     S(200, 74),     S(182, 88),     S(180, 109),    S(168, 115),    S(147, 70),     S(153, 82),     S(112, 18),     //
    S(129, 66),     S(161, 126),    S(189, 76),     S(206, 64),     S(190, 84),     S(140, 64),     S(130, 100),    S(80, 38),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-35, 192),    S(-67, 174),    S(-356, 246),   S(-221, 214),   S(-190, 224),   S(-289, 258),   S(-104, 226),   S(-30, 200),    //
    S(78, 121),     S(25, 180),     S(57, 140),     S(-4, 186),     S(-19, 192),    S(38, 167),     S(68, 149),     S(51, 140),     //
    S(146, 132),    S(171, 131),    S(167, 163),    S(129, 156),    S(100, 152),    S(97, 161),     S(144, 138),    S(119, 118),    //
    S(125, 113),    S(144, 133),    S(164, 146),    S(144, 184),    S(173, 169),    S(113, 152),    S(120, 127),    S(91, 117),     //
    S(141, 87),     S(151, 115),    S(161, 134),    S(169, 156),    S(156, 164),    S(123, 153),    S(85, 134),     S(92, 101),     //
    S(158, 91),     S(194, 98),     S(212, 114),    S(160, 151),    S(152, 136),    S(157, 131),    S(167, 108),    S(106, 113),    //
    S(144, 42),     S(227, 63),     S(189, 76),     S(157, 103),    S(139, 112),    S(147, 85),     S(148, 90),     S(138, 50),     //
    S(149, 55),     S(135, 103),    S(140, 127),    S(159, 83),     S(166, 71),     S(158, 129),    S(152, 86),     S(132, 77),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(406, 253),    S(441, 262),    S(401, 286),    S(412, 268),    S(408, 267),    S(355, 280),    S(370, 281),    S(367, 284),    //
    S(300, 308),    S(363, 298),    S(454, 272),    S(389, 295),    S(391, 297),    S(351, 302),    S(269, 331),    S(268, 330),    //
    S(286, 294),    S(413, 261),    S(446, 254),    S(429, 253),    S(390, 262),    S(341, 286),    S(341, 287),    S(261, 320),    //
    S(264, 281),    S(340, 282),    S(380, 267),    S(360, 264),    S(353, 272),    S(312, 291),    S(293, 291),    S(233, 303),    //
    S(221, 236),    S(294, 246),    S(274, 264),    S(270, 252),    S(259, 262),    S(245, 288),    S(215, 279),    S(190, 276),    //
    S(191, 210),    S(255, 208),    S(258, 231),    S(244, 222),    S(247, 217),    S(219, 253),    S(210, 231),    S(168, 245),    //
    S(102, 226),    S(219, 169),    S(240, 191),    S(249, 195),    S(239, 196),    S(226, 208),    S(205, 192),    S(177, 207),    //
    S(153, 213),    S(170, 234),    S(242, 195),    S(269, 178),    S(248, 197),    S(236, 212),    S(221, 203),    S(202, 227),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(461, 418),    S(540, 354),    S(530, 387),    S(447, 493),    S(462, 454),    S(450, 449),    S(487, 379),    S(389, 452),    //
    S(484, 446),    S(427, 551),    S(432, 564),    S(291, 627),    S(296, 619),    S(365, 574),    S(394, 489),    S(415, 464),    //
    S(423, 503),    S(514, 492),    S(441, 565),    S(408, 585),    S(361, 587),    S(377, 539),    S(452, 440),    S(430, 410),    //
    S(497, 403),    S(493, 473),    S(453, 518),    S(429, 569),    S(418, 571),    S(421, 503),    S(475, 408),    S(474, 373),    //
    S(480, 405),    S(491, 425),    S(466, 475),    S(438, 520),    S(440, 514),    S(437, 475),    S(458, 401),    S(469, 353),    //
    S(468, 324),    S(502, 357),    S(504, 427),    S(468, 407),    S(463, 399),    S(472, 419),    S(477, 361),    S(463, 335),    //
    S(450, 206),    S(493, 158),    S(495, 249),    S(506, 297),    S(489, 323),    S(488, 291),    S(459, 340),    S(461, 326),    //
    S(407, 245),    S(457, 46),     S(458, 72),     S(487, 165),    S(493, 240),    S(494, 191),    S(485, 222),    S(437, 271),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-713, 21),    S(-173, 225),   S(14, 145),     S(-174, 113),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, 31),     S(252, -17),    S(247, -7),     S(213, -87),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-78, 157),    S(284, -16),    S(296, -23),    S(190, -58),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-329, 169),   S(204, -49),    S(121, -35),    S(115, -46),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-338, 134),   S(136, -86),    S(139, -79),    S(55, -42),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-189, 103),   S(220, -117),   S(163, -87),    S(135, -65),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-38, 50),     S(244, -126),   S(183, -97),    S(112, -60),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-283, 157),   S(-47, 53),     S(-147, 87),    S(-152, 74),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 14.5871s
// clang-format on
}  // namespace Clockwork
