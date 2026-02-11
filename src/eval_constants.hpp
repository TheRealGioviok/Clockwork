#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(136, 196);
inline const PParam KNIGHT_MAT = S(558, 607);
inline const PParam BISHOP_MAT = S(586, 626);
inline const PParam ROOK_MAT   = S(467, 659);
inline const PParam QUEEN_MAT  = S(1076, 1074);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(52, 197);
inline const PParam ROOK_OPEN_VAL     = S(105, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 21);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -70);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 66);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -36);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 1), S(38, 27), S(57, 51), S(135, 146), S(379, 203), S(459, 686),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 35), S(44, 27), S(54, 54), S(117, 142), S(406, 87),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -122), S(-68, -99), S(-47, 12), S(10, 119), S(92, 267), S(263, 381),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -44), S(35, -5), S(22, 32), S(1, 109), S(47, 222), S(198, 285),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(22, -37), S(3, 11), S(3, -22), S(-1, -55), S(-8, -127), S(-211, -232),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-5, 148), S(-17, 113), S(-12, 45), S(-5, 9), S(0, 9), S(36, 7), S(10, 2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-306, -55), S(-42, 26), S(-25, 61), S(12, 98), S(31, 114), S(48, 115), S(30, 108),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(62, 7), S(133, 179), S(168, 268), S(195, 305), S(235, 323), S(260, 358), S(292, 355), S(323, 369), S(376, 283),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(93, 8), S(136, 182), S(190, 246), S(217, 291), S(242, 323), S(258, 347), S(265, 366), S(279, 376), S(285, 394), S(310, 376), S(321, 378), S(368, 326), S(366, 341), S(396, 287),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(309, 248), S(228, 427), S(253, 452), S(270, 461), S(281, 474), S(287, 484), S(294, 495), S(303, 497), S(308, 508), S(320, 509), S(331, 510), S(339, 515), S(344, 514), S(361, 486), S(446, 383),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(492, 512), S(632, 531), S(657, 644), S(675, 755), S(691, 802), S(699, 847), S(705, 878), S(713, 889), S(717, 912), S(720, 927), S(726, 934), S(730, 942), S(739, 935), S(741, 940), S(746, 935), S(744, 940), S(747, 934), S(753, 927), S(759, 920), S(769, 912), S(778, 888), S(800, 848), S(797, 847), S(795, 794), S(783, 781), S(778, 747), S(710, 806), S(733, 712),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(490, -193), S(99, -95), S(23, -17), S(11, 14), S(-7, 12), S(-21, 1), S(-23, 5), S(-36, 8), S(-21, -38),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -6), S(15, -14), S(13, -11), S(6, -7), S(2, 209),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(6, -10), S(5, -8), S(5, -5), S(6, 384),
};

inline const PParam PAWN_THREAT_KNIGHT = S(212, 93);
inline const PParam PAWN_THREAT_BISHOP = S(190, 143);
inline const PParam PAWN_THREAT_ROOK   = S(191, 124);
inline const PParam PAWN_THREAT_QUEEN  = S(166, -16);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 67);
inline const PParam KNIGHT_THREAT_QUEEN  = S(151, -3);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 125);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 101);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -18), S(-9, -28), S(-13, -37), S(-18, -42), S(-21, -54), S(-28, -52), S(-39, -53),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(298, 348),    S(148, 447),    S(293, 416),    S(300, 287),    S(323, 242),    S(218, 324),    S(156, 360),    S(265, 314),    //
    S(118, 213),    S(149, 253),    S(187, 172),    S(172, 108),    S(153, 90),     S(127, 142),    S(99, 199),     S(50, 225),     //
    S(83, 177),     S(70, 180),     S(111, 107),    S(112, 85),     S(100, 81),     S(73, 114),     S(25, 163),     S(13, 191),     //
    S(59, 129),     S(48, 153),     S(83, 103),     S(80, 94),      S(59, 97),      S(42, 121),     S(-18, 165),    S(-18, 157),    //
    S(57, 103),     S(97, 110),     S(81, 141),     S(73, 128),     S(45, 123),     S(23, 129),     S(-12, 146),    S(-19, 140),    //
    S(71, 104),     S(160, 119),    S(146, 175),    S(95, 159),     S(67, 147),     S(46, 141),     S(17, 152),     S(-2, 154),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-240, -62),   S(-139, 204),   S(-87, 59),     S(104, 199),    S(45, 198),     S(-102, 204),   S(-234, 253),   S(-278, 10),    //
    S(85, 177),     S(129, 201),    S(218, 158),    S(211, 168),    S(210, 172),    S(123, 202),    S(87, 218),     S(60, 195),     //
    S(171, 171),    S(218, 166),    S(221, 222),    S(221, 207),    S(182, 241),    S(121, 258),    S(133, 202),    S(98, 195),     //
    S(240, 191),    S(249, 211),    S(244, 236),    S(231, 267),    S(233, 275),    S(187, 262),    S(180, 229),    S(175, 201),    //
    S(223, 196),    S(258, 178),    S(228, 236),    S(224, 255),    S(200, 260),    S(199, 244),    S(196, 193),    S(159, 200),    //
    S(168, 161),    S(193, 171),    S(184, 209),    S(192, 236),    S(188, 235),    S(152, 215),    S(142, 183),    S(113, 149),    //
    S(180, 164),    S(202, 161),    S(169, 170),    S(170, 194),    S(161, 193),    S(134, 149),    S(122, 169),    S(110, 86),     //
    S(115, 116),    S(160, 183),    S(176, 148),    S(192, 140),    S(173, 164),    S(140, 136),    S(126, 161),    S(88, 82),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(16, 311),     S(3, 320),      S(-257, 362),   S(-123, 300),   S(-134, 321),   S(-147, 318),   S(-33, 318),    S(49, 289),     //
    S(137, 224),    S(80, 303),     S(114, 255),    S(60, 273),     S(77, 270),     S(100, 273),    S(138, 268),    S(114, 248),    //
    S(209, 251),    S(221, 265),    S(215, 272),    S(192, 272),    S(163, 267),    S(171, 275),    S(186, 268),    S(182, 240),    //
    S(179, 243),    S(215, 252),    S(216, 273),    S(213, 311),    S(242, 301),    S(174, 277),    S(186, 241),    S(144, 242),    //
    S(207, 202),    S(224, 234),    S(229, 258),    S(234, 286),    S(209, 301),    S(195, 279),    S(162, 257),    S(159, 214),    //
    S(234, 209),    S(268, 222),    S(278, 250),    S(224, 275),    S(220, 252),    S(214, 264),    S(221, 241),    S(162, 237),    //
    S(200, 181),    S(300, 199),    S(257, 213),    S(224, 231),    S(204, 234),    S(208, 210),    S(208, 207),    S(202, 201),    //
    S(232, 184),    S(220, 201),    S(219, 235),    S(233, 198),    S(222, 209),    S(222, 251),    S(219, 230),    S(211, 206),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(434, 396),    S(446, 418),    S(423, 430),    S(441, 392),    S(421, 398),    S(387, 409),    S(382, 427),    S(378, 427),    //
    S(308, 483),    S(384, 479),    S(460, 444),    S(407, 449),    S(391, 458),    S(371, 462),    S(304, 493),    S(288, 499),    //
    S(277, 478),    S(379, 465),    S(436, 425),    S(417, 411),    S(368, 441),    S(327, 464),    S(330, 461),    S(263, 502),    //
    S(283, 435),    S(359, 446),    S(395, 420),    S(369, 423),    S(360, 435),    S(321, 456),    S(317, 451),    S(243, 479),    //
    S(265, 369),    S(330, 387),    S(319, 406),    S(297, 405),    S(274, 429),    S(264, 441),    S(235, 435),    S(214, 432),    //
    S(257, 311),    S(319, 340),    S(305, 366),    S(290, 364),    S(277, 372),    S(252, 394),    S(249, 369),    S(215, 375),    //
    S(150, 323),    S(282, 288),    S(293, 317),    S(282, 341),    S(267, 347),    S(260, 350),    S(242, 336),    S(217, 346),    //
    S(215, 309),    S(238, 329),    S(294, 319),    S(306, 316),    S(295, 324),    S(275, 339),    S(264, 335),    S(245, 344),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(581, 658),    S(632, 608),    S(554, 734),    S(524, 801),    S(505, 789),    S(541, 730),    S(562, 653),    S(519, 685),    //
    S(581, 714),    S(544, 809),    S(533, 844),    S(389, 940),    S(396, 927),    S(461, 874),    S(505, 747),    S(515, 728),    //
    S(544, 779),    S(592, 798),    S(522, 907),    S(471, 925),    S(446, 919),    S(497, 837),    S(534, 756),    S(555, 673),    //
    S(583, 699),    S(586, 789),    S(523, 860),    S(515, 887),    S(508, 885),    S(518, 793),    S(561, 725),    S(548, 691),    //
    S(598, 665),    S(584, 741),    S(555, 796),    S(525, 839),    S(523, 840),    S(528, 783),    S(545, 705),    S(572, 628),    //
    S(577, 611),    S(612, 661),    S(603, 730),    S(573, 723),    S(570, 710),    S(564, 738),    S(579, 654),    S(558, 627),    //
    S(560, 497),    S(597, 510),    S(600, 579),    S(612, 616),    S(599, 643),    S(593, 608),    S(555, 647),    S(567, 623),    //
    S(542, 512),    S(574, 357),    S(597, 379),    S(612, 490),    S(606, 567),    S(605, 513),    S(594, 537),    S(563, 565),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-44, -337),   S(296, 170),    S(168, 126),    S(43, -39),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(239, -73),    S(347, 167),    S(202, 157),    S(123, 8),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(235, 21),     S(384, 110),    S(268, 111),    S(163, 12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(91, -11),     S(337, 47),     S(181, 68),     S(118, 33),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-15, -32),    S(236, 12),     S(160, 20),     S(40, 31),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, -23),    S(213, 2),      S(114, 11),     S(60, -3),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(1, -25),      S(80, 39),      S(-5, 41),      S(-62, 20),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-109, -80),   S(-14, -30),    S(-115, -24),   S(-117, -91),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(12, -13), S(-5, 23), S(-9, 24), S(-2, 9), S(-2, 6), S(-8, 23), S(-3, 23), }},
  {{ S(2, -3), S(-25, 29), S(-21, 22), S(-12, 4), S(-11, 5), S(-20, 26), S(-24, 36), }},
  {{ S(-11, 2), S(-22, 26), S(-20, 8), S(-16, -5), S(-16, -3), S(-19, 8), S(-20, 23), }},
  {{ S(-2, -12), S(-19, -11), S(-10, -15), S(-5, -19), S(-7, -17), S(-11, -13), S(-15, -12), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(2, 24), S(-19, 32), S(-17, 21), S(-9, 10), S(-9, -6),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-6, 3), S(-16, 12), S(-14, 10), S(-13, 11), S(-14, 5), S(-12, 2), S(-16, 11), }},
  {{ S(-5, 3), S(-12, 9), S(-19, 14), S(-16, 11), S(-16, 7), S(-18, 11), S(-12, 8), }},
  {{ S(-11, 7), S(-15, 5), S(-16, 11), S(-12, 11), S(-12, 10), S(-16, 10), S(-15, 6), }},
  {{ S(-11, 9), S(-16, 11), S(-17, 11), S(-12, 14), S(-11, 14), S(-16, 10), S(-18, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1259, 596, -24, 49
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(226);
inline VParam WINNABLE_BIAS = V(-656);

// Epoch duration: 7.73765s
// clang-format on
}  // namespace Clockwork
