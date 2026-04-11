#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(139, 207);
inline const PParam KNIGHT_MAT = S(582, 591);
inline const PParam BISHOP_MAT = S(616, 605);
inline const PParam ROOK_MAT   = S(483, 654);
inline const PParam QUEEN_MAT  = S(1034, 480);
inline const PParam TEMPO_VAL  = S(61, 28);

inline const PParam BISHOP_PAIR_VAL   = S(51, 199);
inline const PParam ROOK_OPEN_VAL     = S(109, -5);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 26);
inline const PParam MINOR_BEHIND_PAWN = S(10, 42);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-18, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -21);
inline const PParam OUTPOST_KNIGHT_VAL    = S(33, 61);
inline const PParam OUTPOST_BISHOP_VAL    = S(53, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(44, 10);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(51, -22);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(30, 48);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -43);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, 1), S(38, 25), S(61, 46), S(139, 142), S(361, 209), S(539, 663),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 30), S(44, 19), S(57, 42), S(115, 129), S(427, 58),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-67, -123), S(-71, -95), S(-48, 14), S(8, 115), S(96, 250), S(278, 372),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(34, -41), S(30, -0), S(19, 35), S(6, 113), S(77, 212), S(240, 272),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -21), S(3, 21), S(-1, -10), S(-0, -39), S(3, -130), S(-237, -226),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 139), S(-19, 115), S(-11, 45), S(-3, 10), S(7, 9), S(43, 7), S(33, -8),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-292, -58), S(-31, 9), S(-24, 61), S(15, 93), S(34, 116), S(45, 123), S(29, 116),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(76, -6), S(142, 166), S(177, 257), S(207, 290), S(245, 307), S(270, 337), S(302, 332), S(333, 341), S(389, 248),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(106, 1), S(149, 164), S(198, 229), S(222, 275), S(246, 307), S(261, 331), S(269, 349), S(282, 359), S(291, 372), S(316, 355), S(326, 355), S(386, 294), S(382, 306), S(437, 238),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(329, 251), S(244, 412), S(267, 439), S(283, 449), S(293, 462), S(297, 473), S(302, 485), S(309, 487), S(314, 498), S(322, 501), S(330, 503), S(335, 509), S(342, 506), S(359, 477), S(449, 371),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(482, 204), S(611, 326), S(635, 435), S(653, 546), S(667, 589), S(675, 630), S(680, 660), S(686, 671), S(689, 694), S(691, 708), S(697, 712), S(700, 719), S(706, 716), S(707, 721), S(710, 717), S(707, 723), S(706, 723), S(712, 715), S(719, 705), S(720, 705), S(721, 690), S(738, 656), S(722, 666), S(715, 615), S(691, 611), S(687, 580), S(624, 615), S(629, 579),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(517, -245), S(90, -113), S(25, -30), S(8, 7), S(-9, 4), S(-12, 2), S(-19, 11), S(-43, 23), S(-23, -15),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -5), S(14, 1), S(13, 8), S(5, -22), S(1, 116),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, 0), S(6, 3), S(4, -6), S(4, -12), S(4, 398),
};

inline const PParam KS_NO_QUEEN = S(-98, -1333);

inline const PParam KS_FLANK_ATTACK = S(2, 3);
inline const PParam KS_FLANK_DEFENSE = S(-4, 4);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(5, 0);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-4, 4);

inline const PParam PAWN_THREAT_KNIGHT = S(213, 72);
inline const PParam PAWN_THREAT_BISHOP = S(191, 126);
inline const PParam PAWN_THREAT_ROOK   = S(193, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(173, -15);

inline const PParam KNIGHT_THREAT_BISHOP = S(99, 95);
inline const PParam KNIGHT_THREAT_ROOK   = S(214, 75);
inline const PParam KNIGHT_THREAT_QUEEN  = S(153, -16);

inline const PParam BISHOP_THREAT_KNIGHT = S(99, 51);
inline const PParam BISHOP_THREAT_ROOK   = S(209, 132);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 115);

inline const PParam HANGING_PAWN_VAL = S(32, 90);
inline const PParam HANGING_NONPAWN_VAL = S(95, 162);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -31), S(-3, -3), S(-5, -11), S(-8, -20), S(-11, -29), S(-15, -35), S(-16, -46), S(-22, -46), S(-38, -40),
};

inline const PParam ROOK_LINEUP = S(13, 76);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(318, 326),    S(145, 435),    S(286, 385),    S(279, 323),    S(323, 257),    S(231, 327),    S(168, 370),    S(282, 317),    //
    S(130, 209),    S(159, 247),    S(171, 198),    S(143, 155),    S(140, 123),    S(115, 169),    S(100, 213),    S(55, 236),     //
    S(97, 169),     S(84, 184),     S(120, 136),    S(103, 116),    S(97, 101),     S(79, 123),     S(30, 167),     S(21, 190),     //
    S(65, 120),     S(51, 153),     S(85, 120),     S(72, 114),     S(49, 112),     S(41, 128),     S(-17, 163),    S(-15, 156),    //
    S(62, 87),      S(98, 94),      S(83, 130),     S(68, 130),     S(37, 124),     S(22, 128),     S(-16, 145),    S(-18, 138),    //
    S(71, 90),      S(160, 102),    S(136, 145),    S(92, 163),     S(62, 149),     S(42, 133),     S(14, 150),     S(-3, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-192, -139),  S(-116, 187),   S(-127, 113),   S(161, 165),    S(82, 171),     S(-63, 181),    S(-249, 259),   S(-266, -35),   //
    S(95, 167),     S(126, 180),    S(241, 140),    S(239, 151),    S(238, 155),    S(163, 180),    S(103, 191),    S(77, 185),     //
    S(167, 147),    S(189, 143),    S(203, 197),    S(218, 195),    S(180, 227),    S(133, 224),    S(146, 169),    S(111, 161),    //
    S(235, 179),    S(242, 188),    S(237, 211),    S(226, 246),    S(235, 249),    S(194, 233),    S(190, 200),    S(184, 181),    //
    S(216, 179),    S(253, 151),    S(223, 207),    S(225, 227),    S(199, 233),    S(200, 220),    S(205, 168),    S(161, 192),    //
    S(157, 151),    S(170, 163),    S(164, 200),    S(180, 219),    S(172, 220),    S(142, 200),    S(140, 170),    S(115, 141),    //
    S(175, 159),    S(185, 150),    S(156, 161),    S(162, 186),    S(159, 182),    S(131, 138),    S(120, 159),    S(108, 79),     //
    S(108, 100),    S(156, 164),    S(170, 135),    S(188, 139),    S(170, 159),    S(136, 129),    S(126, 147),    S(88, 58),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(5, 300),      S(4, 284),      S(-259, 341),   S(-117, 285),   S(-124, 297),   S(-140, 291),   S(-44, 289),    S(33, 285),     //
    S(124, 213),    S(77, 281),     S(109, 229),    S(60, 249),     S(77, 250),     S(94, 249),     S(136, 245),    S(113, 229),    //
    S(183, 236),    S(178, 244),    S(182, 253),    S(163, 251),    S(143, 250),    S(156, 253),    S(170, 241),    S(166, 233),    //
    S(165, 220),    S(195, 227),    S(197, 246),    S(197, 284),    S(231, 267),    S(174, 241),    S(186, 209),    S(150, 218),    //
    S(198, 176),    S(203, 210),    S(216, 235),    S(221, 258),    S(200, 269),    S(195, 250),    S(165, 226),    S(164, 194),    //
    S(217, 188),    S(242, 200),    S(252, 225),    S(207, 250),    S(198, 231),    S(206, 237),    S(217, 220),    S(166, 213),    //
    S(182, 155),    S(275, 170),    S(236, 188),    S(212, 206),    S(192, 212),    S(202, 182),    S(204, 177),    S(199, 172),    //
    S(211, 160),    S(196, 191),    S(203, 212),    S(221, 185),    S(206, 195),    S(206, 232),    S(205, 206),    S(201, 178),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(418, 398),    S(457, 405),    S(416, 426),    S(422, 392),    S(460, 380),    S(420, 391),    S(429, 402),    S(401, 417),    //
    S(303, 468),    S(382, 457),    S(442, 427),    S(382, 441),    S(424, 424),    S(390, 433),    S(332, 463),    S(317, 474),    //
    S(258, 467),    S(375, 441),    S(415, 403),    S(387, 396),    S(383, 415),    S(345, 431),    S(349, 437),    S(287, 476),    //
    S(242, 438),    S(323, 431),    S(349, 407),    S(324, 412),    S(355, 398),    S(317, 429),    S(314, 431),    S(247, 463),    //
    S(222, 372),    S(293, 382),    S(285, 391),    S(265, 390),    S(270, 402),    S(259, 421),    S(234, 419),    S(216, 420),    //
    S(234, 312),    S(304, 333),    S(297, 347),    S(282, 342),    S(289, 348),    S(254, 383),    S(260, 360),    S(224, 367),    //
    S(134, 328),    S(279, 284),    S(285, 307),    S(278, 325),    S(280, 325),    S(267, 336),    S(256, 321),    S(227, 339),    //
    S(200, 309),    S(226, 331),    S(287, 320),    S(300, 309),    S(300, 316),    S(279, 333),    S(275, 328),    S(255, 335),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(521, 558),    S(601, 504),    S(526, 597),    S(481, 653),    S(513, 607),    S(511, 594),    S(541, 509),    S(472, 582),    //
    S(510, 594),    S(493, 675),    S(458, 686),    S(323, 762),    S(363, 754),    S(408, 716),    S(463, 612),    S(471, 601),    //
    S(468, 630),    S(487, 662),    S(440, 713),    S(386, 735),    S(395, 737),    S(453, 664),    S(490, 601),    S(506, 540),    //
    S(496, 520),    S(481, 594),    S(423, 650),    S(412, 689),    S(417, 709),    S(452, 610),    S(502, 553),    S(490, 544),    //
    S(509, 479),    S(484, 535),    S(462, 576),    S(436, 620),    S(441, 653),    S(459, 609),    S(486, 542),    S(512, 487),    //
    S(498, 435),    S(524, 457),    S(520, 518),    S(498, 519),    S(496, 541),    S(501, 574),    S(517, 522),    S(503, 496),    //
    S(480, 332),    S(513, 340),    S(524, 383),    S(542, 431),    S(532, 470),    S(532, 450),    S(502, 498),    S(516, 478),    //
    S(468, 355),    S(500, 214),    S(524, 231),    S(542, 327),    S(539, 415),    S(542, 359),    S(536, 376),    S(507, 420),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(62, -309),    S(376, 182),    S(296, 132),    S(197, -4),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(307, -42),    S(380, 171),    S(277, 156),    S(237, 22),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(219, 44),     S(297, 129),    S(241, 128),    S(199, 45),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(38, 5),       S(191, 65),     S(103, 100),    S(76, 102),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-99, -15),    S(28, 41),      S(-11, 83),     S(-86, 135),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-56, -37),    S(38, 12),      S(-32, 66),     S(-78, 109),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, -67),     S(48, -17),     S(-27, 31),     S(-94, 70),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-63, -130),   S(6, -75),      S(-85, -37),    S(-87, -54),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, 16), S(-2, 38), S(-3, 23), S(8, 20), S(7, 11), S(-4, 18), S(-0, 35), }},
  {{ S(3, -12), S(-27, -15), S(-19, -4), S(-6, 7), S(-5, -4), S(-18, -8), S(-25, -19), }},
  {{ S(-3, 14), S(-17, -9), S(-11, 27), S(-5, 47), S(-4, 39), S(-11, 36), S(-16, -9), }},
  {{ S(8, 47), S(-11, 70), S(1, 79), S(6, 77), S(5, 72), S(-1, 120), S(-7, 79), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(4, -14), S(-18, -38), S(-17, -26), S(-8, 9), S(-2, -27),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 19), S(-15, -17), S(-15, -18), S(-13, -24), S(-14, -23), S(-14, -21), S(-15, -18), }},
  {{ S(0, 11), S(-7, 24), S(-17, -7), S(-14, -17), S(-15, -21), S(-16, -19), S(-7, 18), }},
  {{ S(-6, 13), S(-9, 66), S(-14, -4), S(-12, -12), S(-12, -12), S(-15, -8), S(-9, 54), }},
  {{ S(-6, -45), S(-13, -37), S(-17, -8), S(-12, -4), S(-10, -36), S(-17, -41), S(-15, -41), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1131, 1251, 11, 9
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(126);
inline VParam WINNABLE_PAWN_ENDGAME = V(215);
inline VParam WINNABLE_BIAS = V(-668);

// Epoch duration: 9.40425s
// clang-format on
}  // namespace Clockwork
