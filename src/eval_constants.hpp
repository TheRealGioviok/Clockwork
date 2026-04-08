#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(136, 199);
inline const PParam KNIGHT_MAT = S(583, 579);
inline const PParam BISHOP_MAT = S(612, 583);
inline const PParam ROOK_MAT   = S(493, 624);
inline const PParam QUEEN_MAT  = S(888, 1178);
inline const PParam TEMPO_VAL  = S(59, 18);

inline const PParam BISHOP_PAIR_VAL   = S(49, 196);
inline const PParam ROOK_OPEN_VAL     = S(108, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 25);
inline const PParam MINOR_BEHIND_PAWN = S(11, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-14, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-46, -28);
inline const PParam OUTPOST_KNIGHT_VAL    = S(41, 56);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(31, 49);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -45);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -1), S(34, 27), S(62, 46), S(140, 137), S(374, 198), S(595, 612),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(50, 34), S(45, 26), S(63, 48), S(122, 134), S(430, 72),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-68, -125), S(-71, -95), S(-49, 14), S(8, 113), S(102, 246), S(275, 362),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(29, -41), S(26, -3), S(16, 30), S(5, 106), S(71, 205), S(243, 252),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -20), S(5, 17), S(3, -15), S(4, -42), S(6, -129), S(-235, -217),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-1, 138), S(-16, 109), S(-10, 41), S(-3, 8), S(4, 9), S(38, 7), S(30, -8),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-298, -72), S(-30, 12), S(-25, 61), S(14, 94), S(36, 115), S(49, 119), S(31, 112),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(83, -5), S(147, 164), S(180, 255), S(208, 289), S(246, 305), S(270, 336), S(300, 332), S(330, 341), S(385, 248),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(116, 1), S(153, 168), S(201, 232), S(223, 280), S(247, 311), S(261, 335), S(269, 351), S(282, 359), S(289, 372), S(314, 352), S(323, 349), S(379, 288), S(376, 296), S(424, 231),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(326, 254), S(243, 411), S(266, 438), S(282, 448), S(292, 461), S(296, 473), S(301, 484), S(308, 487), S(313, 497), S(321, 499), S(330, 501), S(336, 505), S(341, 501), S(358, 471), S(452, 362),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(483, 229), S(609, 348), S(633, 461), S(650, 578), S(663, 623), S(669, 671), S(674, 702), S(680, 714), S(682, 739), S(683, 758), S(688, 765), S(690, 776), S(694, 777), S(694, 787), S(695, 788), S(692, 793), S(691, 792), S(694, 788), S(698, 780), S(698, 779), S(693, 770), S(708, 736), S(692, 744), S(674, 702), S(658, 686), S(643, 664), S(580, 698), S(586, 653),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(506, -231), S(91, -90), S(29, -20), S(12, 13), S(-5, 8), S(-15, 5), S(-23, 12), S(-49, 20), S(-36, -22),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -9), S(8, 7), S(9, 2), S(3, -1), S(3, -11),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(5, -6), S(4, 1), S(3, 0), S(3, -1), S(4, -2),
};

inline const PParam KS_NO_QUEEN = S(-91, -1455);

inline const PParam KS_FLANK_ATTACK = S(2, -2);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(4, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, 3);

inline const PParam KS_WEAK_FLANK = S(3, 1);

inline const PParam PAWN_THREAT_KNIGHT = S(216, 86);
inline const PParam PAWN_THREAT_BISHOP = S(201, 127);
inline const PParam PAWN_THREAT_ROOK   = S(200, 121);
inline const PParam PAWN_THREAT_QUEEN  = S(170, 3);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(229, 68);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -29);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 55);
inline const PParam BISHOP_THREAT_ROOK   = S(213, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(177, 90);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -31), S(-4, -3), S(-6, -11), S(-8, -20), S(-12, -28), S(-15, -34), S(-16, -44), S(-22, -45), S(-37, -41),
};

inline const PParam ROOK_LINEUP = S(13, 71);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(314, 324),    S(130, 429),    S(273, 382),    S(271, 324),    S(326, 251),    S(229, 321),    S(160, 363),    S(284, 310),    //
    S(123, 202),    S(145, 241),    S(165, 191),    S(135, 153),    S(132, 122),    S(108, 160),    S(90, 206),     S(50, 227),     //
    S(95, 165),     S(81, 183),     S(120, 138),    S(104, 117),    S(97, 100),     S(75, 120),     S(29, 161),     S(20, 182),     //
    S(59, 118),     S(46, 153),     S(84, 124),     S(72, 114),     S(49, 110),     S(42, 123),     S(-16, 156),    S(-14, 147),    //
    S(57, 88),      S(95, 91),      S(84, 130),     S(70, 129),     S(40, 123),     S(27, 123),     S(-11, 140),    S(-14, 131),    //
    S(69, 98),      S(151, 101),    S(126, 138),    S(93, 160),     S(63, 147),     S(45, 131),     S(18, 147),     S(-0, 147),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-202, -136),  S(-131, 190),   S(-167, 122),   S(127, 167),    S(46, 180),     S(-101, 197),   S(-259, 257),   S(-275, -29),   //
    S(90, 156),     S(121, 174),    S(216, 136),    S(217, 141),    S(208, 158),    S(152, 175),    S(95, 193),     S(76, 172),     //
    S(155, 149),    S(175, 140),    S(187, 198),    S(200, 197),    S(165, 229),    S(127, 228),    S(141, 165),    S(104, 161),    //
    S(227, 172),    S(232, 185),    S(228, 207),    S(220, 239),    S(227, 243),    S(189, 231),    S(186, 200),    S(179, 177),    //
    S(209, 170),    S(245, 147),    S(214, 206),    S(216, 221),    S(190, 228),    S(196, 218),    S(201, 164),    S(158, 185),    //
    S(149, 144),    S(165, 159),    S(161, 198),    S(175, 214),    S(169, 214),    S(141, 198),    S(141, 166),    S(114, 134),    //
    S(173, 143),    S(182, 138),    S(147, 160),    S(157, 181),    S(154, 179),    S(129, 132),    S(118, 156),    S(108, 67),     //
    S(98, 95),      S(146, 158),    S(170, 123),    S(188, 131),    S(168, 152),    S(135, 122),    S(123, 143),    S(83, 51),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(10, 298),     S(15, 291),     S(-279, 353),   S(-127, 294),   S(-131, 304),   S(-146, 297),   S(-42, 296),    S(35, 283),     //
    S(123, 215),    S(85, 285),     S(115, 235),    S(52, 261),     S(75, 255),     S(93, 261),     S(139, 251),    S(111, 232),    //
    S(187, 234),    S(181, 249),    S(185, 259),    S(170, 256),    S(148, 258),    S(160, 261),    S(176, 250),    S(172, 230),    //
    S(172, 216),    S(200, 229),    S(198, 254),    S(196, 296),    S(233, 278),    S(178, 253),    S(193, 213),    S(156, 218),    //
    S(203, 174),    S(204, 212),    S(218, 240),    S(220, 267),    S(200, 281),    S(203, 254),    S(177, 225),    S(170, 196),    //
    S(222, 182),    S(245, 202),    S(251, 233),    S(209, 256),    S(200, 238),    S(212, 244),    S(228, 222),    S(173, 208),    //
    S(183, 155),    S(278, 168),    S(237, 192),    S(216, 208),    S(195, 217),    S(205, 188),    S(208, 178),    S(204, 173),    //
    S(210, 161),    S(189, 198),    S(206, 211),    S(231, 184),    S(212, 196),    S(211, 233),    S(210, 208),    S(204, 180),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(423, 399),    S(470, 395),    S(418, 417),    S(420, 385),    S(473, 369),    S(430, 385),    S(438, 400),    S(412, 417),    //
    S(307, 471),    S(392, 459),    S(452, 427),    S(394, 438),    S(442, 424),    S(408, 433),    S(341, 469),    S(324, 478),    //
    S(264, 467),    S(381, 442),    S(421, 404),    S(397, 397),    S(399, 414),    S(354, 438),    S(359, 441),    S(294, 481),    //
    S(238, 442),    S(319, 436),    S(352, 406),    S(329, 413),    S(357, 406),    S(320, 437),    S(317, 440),    S(250, 468),    //
    S(219, 375),    S(289, 383),    S(281, 394),    S(263, 393),    S(272, 406),    S(263, 424),    S(236, 425),    S(217, 425),    //
    S(229, 314),    S(300, 330),    S(295, 345),    S(278, 345),    S(290, 349),    S(260, 380),    S(262, 362),    S(224, 371),    //
    S(132, 324),    S(273, 276),    S(281, 305),    S(274, 328),    S(281, 327),    S(267, 338),    S(257, 322),    S(228, 338),    //
    S(197, 306),    S(219, 326),    S(285, 312),    S(297, 307),    S(298, 316),    S(278, 332),    S(274, 326),    S(255, 334),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(512, 569),    S(596, 515),    S(494, 660),    S(425, 772),    S(472, 696),    S(484, 649),    S(529, 527),    S(458, 592),    //
    S(508, 587),    S(503, 674),    S(442, 761),    S(305, 870),    S(346, 839),    S(403, 758),    S(470, 596),    S(466, 584),    //
    S(451, 664),    S(471, 711),    S(410, 814),    S(370, 842),    S(377, 826),    S(441, 702),    S(475, 613),    S(498, 523),    //
    S(482, 567),    S(469, 665),    S(413, 744),    S(395, 802),    S(410, 792),    S(442, 677),    S(497, 568),    S(486, 526),    //
    S(495, 526),    S(475, 595),    S(449, 664),    S(426, 707),    S(437, 712),    S(458, 633),    S(482, 553),    S(514, 463),    //
    S(488, 455),    S(518, 484),    S(513, 554),    S(494, 549),    S(494, 556),    S(504, 563),    S(523, 491),    S(506, 471),    //
    S(474, 307),    S(505, 324),    S(515, 387),    S(540, 411),    S(530, 446),    S(534, 418),    S(504, 449),    S(515, 434),    //
    S(458, 316),    S(483, 184),    S(520, 172),    S(542, 266),    S(542, 341),    S(545, 301),    S(536, 332),    S(507, 367),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(26, -323),    S(360, 162),    S(271, 125),    S(158, 10),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(286, -51),    S(371, 170),    S(259, 157),    S(206, 34),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(204, 37),     S(282, 140),    S(219, 136),    S(175, 51),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(16, 6),       S(174, 78),     S(87, 107),     S(58, 105),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, -13),   S(21, 47),      S(-15, 86),     S(-92, 134),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-72, -36),    S(32, 15),      S(-26, 65),     S(-68, 104),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(1, -78),      S(40, -16),     S(-12, 27),     S(-72, 68),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-78, -138),   S(-9, -80),     S(-78, -39),    S(-80, -47),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(28, -9), S(5, 15), S(10, 3), S(19, -5), S(18, -5), S(9, 4), S(7, 14), }},
  {{ S(12, 6), S(-11, 11), S(-7, 17), S(0, 23), S(1, 21), S(-7, 19), S(-10, 13), }},
  {{ S(11, 8), S(1, 3), S(2, 22), S(4, 27), S(5, 26), S(1, 24), S(2, 3), }},
  {{ S(16, 16), S(2, 20), S(5, 36), S(7, 43), S(6, 45), S(3, 40), S(3, 25), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-7, 4), S(-17, -16), S(-18, -9), S(-15, 3), S(-3, -26),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, -13), S(-15, -12), S(-17, -9), S(-14, -14), S(-14, -13), S(-17, -7), S(-16, -10), }},
  {{ S(-0, -21), S(-9, -15), S(-18, -11), S(-13, -15), S(-14, -14), S(-16, -12), S(-8, -15), }},
  {{ S(-9, -13), S(-14, -3), S(-17, -5), S(-14, -9), S(-13, -11), S(-17, -7), S(-14, -4), }},
  {{ S(-8, -20), S(-17, -6), S(-19, -10), S(-15, -10), S(-14, -12), S(-19, -10), S(-19, -0), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1488, 912, -10, 20
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(134);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(207);
inline VParam WINNABLE_BIAS = V(-641);

// Epoch duration: 9.15337s
// Epoch duration: 9.72937s
// clang-format on
}  // namespace Clockwork