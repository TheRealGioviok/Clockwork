#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(173, 175);
inline const PParam KNIGHT_MAT = S(626, 410);
inline const PParam BISHOP_MAT = S(577, 342);
inline const PParam ROOK_MAT   = S(651, 567);
inline const PParam QUEEN_MAT  = S(1366, 809);
inline const PParam TEMPO_VAL  = S(59, 16);

inline const PParam BISHOP_PAIR_VAL   = S(80, 177);
inline const PParam ROOK_OPEN_VAL     = S(101, -27);
inline const PParam ROOK_SEMIOPEN_VAL = S(36, 15);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -78);

inline const PParam POTENTIAL_CHECKER_VAL = S(-66, -8);
inline const PParam OUTPOST_KNIGHT_VAL    = S(53, 32);
inline const PParam OUTPOST_BISHOP_VAL    = S(62, 22);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(48, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -22);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(35, 31);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(21, 18), S(62, 30), S(76, 70), S(186, 145), S(538, 260), S(943, 1138),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(66, 40), S(60, 31), S(67, 58), S(150, 121), S(689, -85),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-78, -92), S(-77, -69), S(-51, 5), S(25, 75), S(89, 196), S(291, 304),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -44), S(33, -3), S(20, 28), S(27, 71), S(105, 143), S(152, 290),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -43), S(-1, 6), S(-3, -22), S(4, -44), S(-2, -89), S(-212, -130),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 114), S(-13, 85), S(-7, 32), S(3, 4), S(11, 8), S(39, 8), S(17, -5),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-272, -17), S(-34, 19), S(-14, 45), S(29, 56), S(33, 82), S(50, 84), S(3, 102),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-36, -58), S(72, 102), S(130, 154), S(173, 188), S(220, 203), S(247, 240), S(284, 236), S(319, 237), S(365, 181),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-37, -166), S(36, 17), S(107, 82), S(140, 133), S(169, 165), S(185, 188), S(202, 203), S(220, 210), S(238, 215), S(250, 213), S(274, 201), S(339, 155), S(366, 134), S(427, 101),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(30, 132), S(182, 285), S(234, 349), S(267, 358), S(292, 382), S(306, 404), S(324, 416), S(343, 422), S(359, 435), S(377, 444), S(394, 447), S(404, 450), S(424, 453), S(436, 439), S(581, 312),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(33, 23), S(533, -121), S(623, 34), S(676, 238), S(682, 444), S(719, 550), S(721, 660), S(745, 672), S(749, 728), S(761, 753), S(770, 778), S(775, 792), S(793, 784), S(803, 794), S(809, 788), S(822, 783), S(828, 773), S(827, 779), S(852, 735), S(875, 696), S(891, 676), S(936, 608), S(948, 600), S(1112, 421), S(1149, 376), S(1384, 224), S(1208, 311), S(1454, 178),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(647, -105), S(254, -192), S(123, -85), S(86, -36), S(37, -19), S(-26, 6), S(-73, 47), S(-121, 69), S(-155, 47),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(193, 222), S(297, 172), S(372, 109),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(369, 377), S(205, 217), S(106, 28),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(384, 410), S(484, 390), S(507, 399), S(587, 430), S(661, 399),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(985, 956), S(676, 777), S(390, 592), S(181, 336), S(89, 32), S(19, -326),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-83, 40), S(31, -38), S(-173, -167), S(48, 20), S(-249, -187),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-27, 23), S(-21, 18), S(-25, 13), S(-15, 9), S(-22, -8),
};

inline const PParam PAWN_THREAT_KNIGHT = S(234, 62);
inline const PParam PAWN_THREAT_BISHOP = S(204, 104);
inline const PParam PAWN_THREAT_ROOK   = S(199, 56);
inline const PParam PAWN_THREAT_QUEEN  = S(175, -53);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 73);
inline const PParam KNIGHT_THREAT_ROOK   = S(246, 4);
inline const PParam KNIGHT_THREAT_QUEEN  = S(161, -70);

inline const PParam BISHOP_THREAT_KNIGHT = S(112, 34);
inline const PParam BISHOP_THREAT_ROOK   = S(245, 56);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 54);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-0, -12), S(-3, -6), S(-3, -16), S(-8, -27), S(-14, -32), S(-19, -40), S(-20, -47), S(-26, -42), S(-34, -48),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(247, 317),    S(213, 378),    S(296, 340),    S(360, 220),    S(308, 214),    S(300, 275),    S(188, 299),    S(266, 264),    //
    S(135, 216),    S(227, 255),    S(206, 200),    S(212, 142),    S(175, 121),    S(125, 166),    S(90, 208),     S(54, 205),     //
    S(91, 165),     S(99, 178),     S(112, 138),    S(107, 121),    S(96, 114),     S(60, 116),     S(21, 162),     S(3, 178),      //
    S(85, 106),     S(97, 141),     S(95, 108),     S(79, 110),     S(57, 99),      S(39, 106),     S(-11, 155),    S(-29, 143),    //
    S(81, 78),      S(140, 86),     S(89, 134),     S(65, 132),     S(46, 122),     S(9, 118),      S(-10, 132),    S(-32, 124),    //
    S(80, 88),      S(204, 99),     S(156, 138),    S(108, 150),    S(76, 134),     S(47, 125),     S(21, 150),     S(-13, 136),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-289, -33),   S(-235, 180),   S(-348, 356),   S(-17, 192),    S(-148, 219),   S(-216, 215),   S(-458, 206),   S(-429, 102),   //
    S(112, 120),    S(179, 133),    S(273, 72),     S(220, 135),    S(227, 139),    S(158, 121),    S(117, 128),    S(96, 82),      //
    S(165, 96),     S(191, 151),    S(274, 148),    S(227, 170),    S(225, 160),    S(153, 166),    S(149, 133),    S(69, 132),     //
    S(214, 133),    S(199, 161),    S(217, 176),    S(198, 201),    S(211, 185),    S(178, 178),    S(165, 127),    S(145, 128),    //
    S(207, 116),    S(231, 119),    S(216, 154),    S(197, 163),    S(185, 174),    S(190, 163),    S(167, 130),    S(156, 67),     //
    S(135, 93),     S(163, 84),     S(156, 106),    S(169, 150),    S(177, 145),    S(122, 120),    S(128, 80),     S(91, 72),      //
    S(144, 104),    S(166, 77),     S(147, 85),     S(146, 105),    S(133, 98),     S(105, 78),     S(118, 63),     S(60, -7),      //
    S(92, 55),      S(128, 100),    S(151, 74),     S(159, 81),     S(150, 89),     S(102, 58),     S(89, 82),      S(42, 28),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-85, 202),    S(-104, 181),   S(-348, 207),   S(-224, 219),   S(-181, 223),   S(-342, 247),   S(-82, 223),    S(-38, 202),    //
    S(89, 89),      S(76, 161),     S(92, 145),     S(59, 153),     S(38, 167),     S(90, 153),     S(70, 142),     S(33, 146),     //
    S(125, 143),    S(164, 132),    S(232, 144),    S(162, 143),    S(135, 147),    S(117, 156),    S(184, 124),    S(93, 140),     //
    S(131, 102),    S(130, 141),    S(167, 141),    S(168, 165),    S(180, 161),    S(117, 160),    S(115, 133),    S(75, 136),     //
    S(124, 79),     S(145, 113),    S(152, 131),    S(154, 152),    S(149, 166),    S(115, 155),    S(97, 118),     S(84, 77),      //
    S(147, 82),     S(194, 92),     S(204, 104),    S(139, 146),    S(126, 150),    S(130, 143),    S(155, 100),    S(119, 82),     //
    S(139, 47),     S(203, 61),     S(174, 74),     S(144, 105),    S(131, 92),     S(132, 82),     S(114, 95),     S(129, 34),     //
    S(139, 63),     S(124, 112),    S(139, 112),    S(149, 78),     S(157, 68),     S(146, 113),    S(141, 83),     S(120, 82),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(446, 352),    S(515, 350),    S(442, 381),    S(438, 377),    S(452, 365),    S(403, 377),    S(414, 378),    S(421, 383),    //
    S(359, 407),    S(443, 384),    S(513, 365),    S(435, 410),    S(458, 394),    S(409, 402),    S(352, 418),    S(346, 422),    //
    S(337, 390),    S(482, 351),    S(506, 349),    S(503, 347),    S(464, 354),    S(397, 390),    S(419, 375),    S(302, 424),    //
    S(313, 380),    S(389, 375),    S(415, 369),    S(433, 336),    S(411, 354),    S(355, 398),    S(340, 396),    S(268, 404),    //
    S(252, 331),    S(333, 337),    S(316, 355),    S(298, 357),    S(300, 350),    S(284, 388),    S(257, 382),    S(235, 374),    //
    S(231, 310),    S(305, 285),    S(300, 314),    S(279, 315),    S(300, 294),    S(251, 347),    S(250, 329),    S(227, 327),    //
    S(172, 318),    S(274, 257),    S(295, 275),    S(297, 278),    S(292, 281),    S(273, 298),    S(255, 274),    S(223, 291),    //
    S(208, 317),    S(237, 324),    S(291, 290),    S(314, 274),    S(301, 288),    S(289, 299),    S(274, 291),    S(256, 307),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(585, 578),    S(625, 541),    S(622, 548),    S(497, 680),    S(570, 597),    S(524, 620),    S(599, 534),    S(535, 563),    //
    S(573, 624),    S(501, 721),    S(489, 768),    S(388, 799),    S(416, 748),    S(434, 742),    S(482, 662),    S(520, 598),    //
    S(530, 651),    S(607, 648),    S(536, 727),    S(512, 736),    S(475, 718),    S(451, 721),    S(540, 612),    S(513, 585),    //
    S(595, 558),    S(584, 627),    S(547, 665),    S(536, 724),    S(530, 705),    S(524, 646),    S(565, 552),    S(559, 524),    //
    S(561, 587),    S(594, 552),    S(568, 620),    S(532, 671),    S(528, 665),    S(536, 627),    S(551, 546),    S(552, 496),    //
    S(577, 434),    S(602, 492),    S(607, 553),    S(555, 567),    S(572, 532),    S(579, 539),    S(590, 469),    S(561, 474),    //
    S(568, 337),    S(606, 245),    S(600, 368),    S(613, 433),    S(586, 457),    S(603, 391),    S(579, 454),    S(559, 453),    //
    S(513, 426),    S(577, 175),    S(582, 174),    S(608, 258),    S(609, 352),    S(610, 305),    S(596, 347),    S(542, 424),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-267, -296),  S(31, 22),      S(-113, 74),    S(-223, 101),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(125, -68),    S(94, 91),      S(137, 69),     S(244, 0),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-64, 89),     S(186, 73),     S(254, 31),     S(232, -10),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-271, 110),   S(174, 25),     S(186, 13),     S(126, -3),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-242, 64),    S(107, -8),     S(162, -23),    S(75, 10),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-176, 46),    S(169, -46),    S(127, -20),    S(99, -4),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -16),    S(171, -60),    S(124, -36),    S(59, -4),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-216, 4),     S(-35, -15),    S(-113, 7),     S(-127, 6),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 9.10014s
// clang-format on
}  // namespace Clockwork
