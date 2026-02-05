#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 187);
inline const PParam KNIGHT_MAT = S(606, 561);
inline const PParam BISHOP_MAT = S(648, 587);
inline const PParam ROOK_MAT   = S(503, 624);
inline const PParam QUEEN_MAT  = S(1144, 1027);
inline const PParam TEMPO_VAL  = S(59, 17);

inline const PParam BISHOP_PAIR_VAL   = S(52, 191);
inline const PParam ROOK_OPEN_VAL     = S(113, -18);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 19);

inline const PParam DOUBLED_PAWN_VAL = S(-0, -70);
inline const PParam ISOLATED_PAWN_VAL = S(-14, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-55, -13);
inline const PParam OUTPOST_KNIGHT_VAL    = S(33, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(56, 25);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 4);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 49);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -34);

inline const std::array<PParam, 6> CONNECTED_OPPOSED = {
    S(-73, 174), S(-42, 16), S(-45, -31), S(-45, -41), S(88, 87), S(0, 0),
};
inline const std::array<PParam, 6> CONNECTED_PHALANX = {
    S(-39, -237), S(-9, -37), S(3, 6), S(47, 58), S(289, 267), S(257, 277),
};
inline const std::array<PParam, 6> CONNECTED_SUPPORTED = {
    S(0, 0), S(29, -13), S(23, 3), S(53, 42), S(359, 362), S(331, 330),
};
inline const std::array<PParam, 6> CONNECTED_BLOCKED = {
    S(-163, -155), S(6, -26), S(10, -209), S(-48, -9), S(88, 87), S(0, 0),
};
inline const PParam CONNECTED_CORRECT_SUPPORTED_PHALANX  = S(29, 44);
inline TunableSigmoid<32> CONNECTED_SIGMOID(
        153, 130, -20, -33
);
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-79, -99), S(-75, -84), S(-53, 11), S(4, 108), S(115, 251), S(291, 351),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(39, -44), S(35, -8), S(20, 27), S(2, 104), S(60, 203), S(206, 259),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(25, -46), S(6, 7), S(2, -20), S(-4, -50), S(-5, -128), S(-206, -226),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-7, 148), S(-25, 119), S(-11, 43), S(-2, 6), S(2, 2), S(37, -2), S(14, -13),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-307, -51), S(-30, 8), S(-32, 62), S(10, 95), S(29, 116), S(48, 119), S(27, 116),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(71, -9), S(141, 160), S(175, 247), S(203, 283), S(245, 298), S(271, 328), S(304, 325), S(338, 333), S(393, 246),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(87, 1), S(131, 167), S(186, 227), S(215, 270), S(241, 298), S(260, 318), S(269, 335), S(286, 340), S(296, 351), S(322, 333), S(340, 324), S(390, 271), S(404, 267), S(440, 216),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(315, 227), S(236, 400), S(261, 423), S(278, 434), S(289, 447), S(295, 458), S(301, 467), S(310, 469), S(316, 479), S(328, 479), S(341, 477), S(352, 477), S(359, 474), S(378, 447), S(481, 328),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(494, 522), S(653, 475), S(678, 589), S(694, 701), S(709, 748), S(718, 792), S(724, 824), S(731, 836), S(734, 859), S(737, 873), S(743, 879), S(747, 888), S(755, 884), S(757, 888), S(761, 885), S(761, 885), S(761, 887), S(769, 878), S(778, 867), S(781, 871), S(791, 848), S(818, 806), S(803, 822), S(809, 757), S(792, 754), S(781, 731), S(708, 793), S(730, 701),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(393, -155), S(120, -99), S(38, -16), S(18, 9), S(-1, 8), S(-23, 7), S(-16, 0), S(-31, 10), S(-23, -25),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -54), S(15, -66), S(13, -24), S(5, -36), S(5, -922),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -11), S(5, -56), S(5, -47), S(5, -14), S(8, 1379),
};

inline const PParam PAWN_THREAT_KNIGHT = S(218, 83);
inline const PParam PAWN_THREAT_BISHOP = S(199, 129);
inline const PParam PAWN_THREAT_ROOK   = S(192, 122);
inline const PParam PAWN_THREAT_QUEEN  = S(174, -28);

inline const PParam KNIGHT_THREAT_BISHOP = S(112, 93);
inline const PParam KNIGHT_THREAT_ROOK   = S(230, 60);
inline const PParam KNIGHT_THREAT_QUEEN  = S(150, -1);

inline const PParam BISHOP_THREAT_KNIGHT = S(107, 52);
inline const PParam BISHOP_THREAT_ROOK   = S(216, 115);
inline const PParam BISHOP_THREAT_QUEEN  = S(178, 85);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -29), S(-4, -9), S(-7, -17), S(-10, -26), S(-14, -35), S(-19, -41), S(-21, -52), S(-27, -49), S(-37, -49),
};

inline const PParam ROOK_LINEUP = S(13, 62);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(322, 330),    S(212, 375),    S(333, 371),    S(319, 276),    S(341, 231),    S(228, 317),    S(169, 356),    S(253, 325),    //
    S(137, 177),    S(190, 190),    S(207, 144),    S(176, 107),    S(151, 93),     S(118, 147),    S(94, 200),     S(47, 223),     //
    S(96, 152),     S(83, 160),     S(111, 112),    S(107, 93),     S(96, 89),      S(65, 121),     S(17, 173),     S(11, 197),     //
    S(68, 114),     S(56, 139),     S(80, 104),     S(66, 99),      S(42, 103),     S(28, 127),     S(-30, 177),    S(-24, 165),    //
    S(70, 79),      S(113, 77),     S(86, 118),     S(62, 122),     S(30, 121),     S(6, 134),      S(-26, 159),    S(-26, 146),    //
    S(78, 94),      S(181, 83),     S(159, 143),    S(93, 150),     S(61, 143),     S(39, 141),     S(9, 156),      S(-8, 161),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-251, -84),   S(-139, 182),   S(-128, 79),    S(116, 158),    S(66, 149),     S(-103, 178),   S(-244, 226),   S(-302, 4),     //
    S(86, 144),     S(135, 158),    S(233, 113),    S(233, 126),    S(220, 143),    S(139, 153),    S(83, 185),     S(59, 158),     //
    S(183, 131),    S(224, 139),    S(247, 168),    S(253, 148),    S(206, 190),    S(137, 209),    S(136, 166),    S(99, 164),     //
    S(240, 163),    S(262, 171),    S(261, 186),    S(250, 215),    S(247, 226),    S(195, 219),    S(180, 199),    S(172, 169),    //
    S(210, 179),    S(255, 150),    S(228, 199),    S(222, 222),    S(197, 227),    S(190, 216),    S(187, 171),    S(143, 184),    //
    S(148, 154),    S(175, 157),    S(165, 195),    S(174, 216),    S(170, 215),    S(131, 202),    S(121, 172),    S(92, 142),     //
    S(158, 159),    S(177, 157),    S(147, 163),    S(149, 183),    S(139, 184),    S(111, 144),    S(98, 165),     S(88, 82),      //
    S(91, 118),     S(139, 174),    S(154, 141),    S(168, 138),    S(152, 155),    S(118, 132),    S(103, 156),    S(63, 85),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(1, 279),      S(-6, 275),     S(-277, 336),   S(-140, 268),   S(-151, 292),   S(-172, 296),   S(-59, 297),    S(30, 263),     //
    S(124, 194),    S(73, 266),     S(112, 214),    S(50, 246),     S(63, 247),     S(84, 244),     S(123, 240),    S(105, 208),    //
    S(206, 212),    S(213, 233),    S(217, 228),    S(200, 219),    S(163, 225),    S(162, 242),    S(178, 231),    S(168, 212),    //
    S(175, 201),    S(214, 206),    S(214, 231),    S(214, 263),    S(246, 249),    S(173, 230),    S(176, 205),    S(135, 204),    //
    S(201, 162),    S(215, 196),    S(220, 220),    S(226, 247),    S(203, 259),    S(184, 242),    S(150, 222),    S(146, 182),    //
    S(223, 176),    S(253, 189),    S(263, 219),    S(210, 241),    S(203, 225),    S(197, 236),    S(206, 208),    S(151, 203),    //
    S(189, 147),    S(280, 175),    S(240, 185),    S(201, 210),    S(183, 210),    S(188, 187),    S(190, 183),    S(186, 173),    //
    S(215, 158),    S(203, 180),    S(198, 215),    S(213, 175),    S(202, 187),    S(204, 223),    S(201, 204),    S(193, 183),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(436, 365),    S(464, 370),    S(440, 384),    S(461, 351),    S(433, 362),    S(401, 370),    S(389, 393),    S(377, 401),    //
    S(318, 443),    S(409, 424),    S(486, 389),    S(432, 398),    S(412, 411),    S(391, 413),    S(315, 451),    S(294, 461),    //
    S(288, 436),    S(404, 408),    S(464, 364),    S(445, 354),    S(394, 385),    S(347, 410),    S(341, 416),    S(270, 461),    //
    S(290, 399),    S(374, 400),    S(408, 372),    S(383, 376),    S(375, 384),    S(330, 412),    S(324, 410),    S(245, 443),    //
    S(262, 344),    S(335, 354),    S(328, 367),    S(301, 369),    S(280, 390),    S(270, 404),    S(236, 405),    S(212, 406),    //
    S(252, 294),    S(321, 314),    S(309, 335),    S(293, 332),    S(275, 346),    S(249, 372),    S(245, 350),    S(207, 363),    //
    S(142, 315),    S(277, 275),    S(290, 296),    S(280, 315),    S(263, 325),    S(254, 332),    S(237, 318),    S(212, 329),    //
    S(205, 299),    S(230, 318),    S(288, 304),    S(302, 297),    S(290, 307),    S(269, 323),    S(258, 321),    S(238, 330),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(559, 643),    S(619, 577),    S(522, 711),    S(485, 771),    S(492, 717),    S(519, 689),    S(539, 635),    S(487, 685),    //
    S(549, 714),    S(522, 795),    S(510, 799),    S(351, 883),    S(362, 868),    S(440, 837),    S(484, 733),    S(492, 714),    //
    S(512, 768),    S(559, 768),    S(499, 836),    S(439, 861),    S(418, 849),    S(469, 785),    S(515, 708),    S(531, 650),    //
    S(557, 664),    S(566, 728),    S(501, 797),    S(500, 806),    S(491, 820),    S(497, 743),    S(547, 667),    S(523, 666),    //
    S(579, 623),    S(572, 679),    S(543, 731),    S(522, 756),    S(515, 778),    S(514, 735),    S(533, 659),    S(556, 591),    //
    S(562, 568),    S(599, 618),    S(596, 672),    S(566, 657),    S(559, 662),    S(556, 685),    S(564, 619),    S(542, 595),    //
    S(548, 450),    S(587, 465),    S(593, 529),    S(604, 563),    S(588, 598),    S(581, 570),    S(545, 604),    S(553, 589),    //
    S(527, 470),    S(561, 321),    S(582, 351),    S(598, 452),    S(595, 526),    S(594, 473),    S(581, 504),    S(545, 542),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-162, -294),  S(161, 271),    S(89, 176),     S(-30, 27),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(144, -15),    S(234, 259),    S(104, 236),    S(82, 61),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(149, 75),     S(291, 168),    S(209, 150),    S(153, 59),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, 28),      S(274, 83),     S(130, 114),    S(78, 119),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-85, -4),     S(178, 42),     S(103, 84),     S(-17, 152),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-42, -41),    S(161, 7),      S(52, 62),      S(6, 111),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -94),     S(86, -25),     S(-19, 30),     S(-87, 84),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-90, -154),   S(11, -104),    S(-97, -59),    S(-106, -56),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -675), S(-1, 138), S(-4, -681), S(5, -821), S(5, -903), S(-3, -648), S(-1, 869), }},
  {{ S(2, 72), S(-25, 34), S(-21, -290), S(-13, -67), S(-11, -62), S(-21, 2), S(-24, 135), }},
  {{ S(-12, -66), S(-20, -1), S(-21, -123), S(-19, -148), S(-17, -162), S(-19, -116), S(-18, -25), }},
  {{ S(5, 90), S(-17, 25), S(-6, 0), S(-1, -1), S(-1, 2), S(-6, -15), S(-10, 15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(14, -140), S(-8, -1082), S(-12, 80), S(-10, 103), S(-7, 20),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 808), S(-11, -735), S(-9, -762), S(-7, -811), S(-8, -710), S(-10, 57), S(-10, -585), }},
  {{ S(-1, 61), S(-10, -5), S(-18, 4), S(-10, -1568), S(-10, -1595), S(-14, -675), S(-9, 40), }},
  {{ S(-9, 73), S(-14, 21), S(-14, 61), S(-9, 44), S(-8, 24), S(-13, 59), S(-13, 39), }},
  {{ S(-12, 82), S(-18, 97), S(-18, 59), S(-11, 61), S(-8, 66), S(-17, 56), S(-20, 83), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1036, 104, -48, -169
);

inline VParam WINNABLE_PAWNS = V(46);
inline VParam WINNABLE_BIAS = V(-440);

// Epoch duration: 7.46582s
// clang-format on
}  // namespace Clockwork
