#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(132, 214);
inline const PParam KNIGHT_MAT = S(616, 745);
inline const PParam BISHOP_MAT = S(606, 717);
inline const PParam ROOK_MAT   = S(525, 835);
inline const PParam QUEEN_MAT  = S(1204, 1217);
inline const PParam TEMPO_VAL  = S(58, 23);

inline const PParam BISHOP_PAIR_VAL   = S(59, 191);
inline const PParam ROOK_OPEN_VAL     = S(76, 69);
inline const PParam ROOK_SEMIOPEN_VAL = S(52, 5);
inline const PParam SEE_CONTROL_VALUE = S(-4, 4);
inline const PParam SEE_CONTROL_OPENFILE_VALUE = S(16, -35);
inline const PParam SEE_CONTROL_SEMIOPENFILE_VALUE = S(-1, 7);
inline const PParam SEE_RESTRICTED_SQUARES = S(11, 4);

inline const PParam DOUBLED_PAWN_VAL = S(-4, -89);
inline const PParam ISOLATED_PAWN_VAL = S(-27, -2);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(41, 57);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(36, 14);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(47, -4);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(22, 56);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -26);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(13, 7), S(36, 28), S(64, 46), S(147, 141), S(374, 209), S(428, 709),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 38), S(46, 25), S(57, 52), S(120, 134), S(429, 52),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-73, -116), S(-67, -98), S(-44, 11), S(8, 121), S(95, 268), S(263, 389),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(43, -61), S(41, -21), S(31, 13), S(8, 94), S(60, 208), S(214, 282),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(20, -36), S(2, 9), S(2, -24), S(1, -59), S(-9, -134), S(-213, -248),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(1, 140), S(-14, 110), S(-13, 47), S(-7, 13), S(-1, 10), S(37, 5), S(13, -3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-311, -48), S(-42, 24), S(-23, 57), S(12, 93), S(30, 110), S(46, 114), S(31, 103),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(16, -61), S(89, 117), S(124, 205), S(151, 241), S(189, 259), S(208, 292), S(233, 295), S(256, 314), S(293, 253),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(73, -17), S(120, 154), S(177, 219), S(204, 263), S(228, 295), S(244, 318), S(250, 338), S(259, 353), S(262, 373), S(277, 366), S(281, 375), S(305, 354), S(301, 366), S(283, 372),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(281, 191), S(199, 367), S(224, 392), S(241, 402), S(253, 413), S(260, 423), S(266, 434), S(275, 437), S(280, 449), S(290, 452), S(300, 456), S(304, 465), S(306, 471), S(313, 459), S(375, 388),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(451, 517), S(588, 528), S(614, 630), S(633, 742), S(651, 785), S(661, 826), S(668, 855), S(676, 864), S(682, 884), S(686, 897), S(693, 903), S(698, 910), S(706, 907), S(709, 912), S(714, 910), S(711, 917), S(710, 922), S(715, 921), S(715, 926), S(722, 926), S(723, 917), S(742, 885), S(730, 897), S(717, 861), S(696, 862), S(683, 844), S(615, 904), S(628, 827),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(498, -196), S(111, -114), S(33, -31), S(22, -3), S(3, -5), S(-17, -9), S(-27, 5), S(-50, 24), S(-53, 3),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -9), S(14, -13), S(12, -10), S(5, -7), S(2, 298),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(6, -9), S(5, -7), S(5, -5), S(6, 485),
};

inline const PParam PAWN_THREAT_KNIGHT = S(204, 112);
inline const PParam PAWN_THREAT_BISHOP = S(188, 152);
inline const PParam PAWN_THREAT_ROOK   = S(192, 128);
inline const PParam PAWN_THREAT_QUEEN  = S(170, -10);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 104);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 75);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -7);

inline const PParam BISHOP_THREAT_KNIGHT = S(104, 63);
inline const PParam BISHOP_THREAT_ROOK   = S(215, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 91);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(7, -28), S(-2, -10), S(-5, -20), S(-8, -30), S(-13, -40), S(-18, -46), S(-21, -58), S(-28, -56), S(-37, -60),
};

inline const PParam ROOK_LINEUP = S(11, 69);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(313, 321),    S(137, 451),    S(285, 413),    S(281, 298),    S(303, 258),    S(192, 352),    S(131, 391),    S(272, 304),    //
    S(123, 197),    S(138, 254),    S(178, 166),    S(157, 117),    S(136, 105),    S(109, 161),    S(82, 219),     S(50, 225),     //
    S(93, 158),     S(67, 175),     S(113, 94),     S(106, 90),     S(94, 90),      S(66, 125),     S(14, 180),     S(16, 189),     //
    S(61, 117),     S(42, 153),     S(77, 97),      S(69, 102),     S(46, 109),     S(28, 137),     S(-32, 185),    S(-20, 159),    //
    S(60, 92),      S(89, 115),     S(75, 141),     S(64, 138),     S(35, 136),     S(12, 144),     S(-24, 167),    S(-20, 142),    //
    S(75, 95),      S(156, 120),    S(143, 175),    S(89, 165),     S(60, 156),     S(41, 152),     S(9, 168),      S(-0, 156),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-263, -125),  S(-160, 137),   S(-60, -58),    S(75, 149),     S(6, 159),      S(-122, 145),   S(-261, 200),   S(-304, -47),   //
    S(69, 102),     S(99, 150),     S(176, 127),    S(177, 128),    S(168, 141),    S(82, 174),     S(54, 175),     S(31, 141),     //
    S(141, 107),    S(176, 124),    S(171, 194),    S(171, 177),    S(136, 206),    S(73, 231),     S(83, 177),     S(59, 151),     //
    S(210, 135),    S(212, 168),    S(210, 201),    S(204, 230),    S(200, 245),    S(150, 235),    S(136, 203),    S(136, 163),    //
    S(198, 142),    S(224, 142),    S(200, 205),    S(189, 227),    S(169, 232),    S(166, 221),    S(153, 177),    S(128, 161),    //
    S(138, 112),    S(167, 131),    S(159, 167),    S(166, 195),    S(160, 198),    S(127, 177),    S(112, 149),    S(81, 111),     //
    S(152, 112),    S(174, 113),    S(142, 127),    S(141, 153),    S(132, 153),    S(103, 114),    S(88, 133),     S(76, 46),      //
    S(86, 69),      S(130, 133),    S(145, 100),    S(160, 94),     S(141, 120),    S(106, 98),     S(93, 119),     S(57, 41),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-6, 283),     S(-20, 290),    S(-274, 329),   S(-152, 276),   S(-146, 283),   S(-161, 281),   S(-45, 274),    S(31, 253),     //
    S(110, 200),    S(55, 277),     S(86, 236),     S(33, 257),     S(45, 260),     S(71, 257),     S(110, 248),    S(89, 219),     //
    S(184, 222),    S(195, 238),    S(186, 253),    S(164, 252),    S(133, 251),    S(141, 259),    S(152, 255),    S(154, 219),    //
    S(156, 213),    S(196, 232),    S(197, 252),    S(196, 279),    S(226, 266),    S(149, 261),    S(164, 227),    S(114, 229),    //
    S(187, 168),    S(202, 213),    S(211, 238),    S(219, 259),    S(196, 274),    S(175, 261),    S(133, 248),    S(131, 200),    //
    S(212, 179),    S(243, 198),    S(258, 228),    S(205, 258),    S(203, 235),    S(192, 250),    S(195, 226),    S(137, 218),    //
    S(179, 150),    S(275, 173),    S(234, 190),    S(201, 214),    S(181, 217),    S(184, 194),    S(183, 189),    S(177, 181),    //
    S(210, 156),    S(196, 174),    S(194, 212),    S(208, 175),    S(197, 187),    S(197, 230),    S(195, 208),    S(188, 183),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(425, 389),    S(441, 400),    S(421, 403),    S(427, 376),    S(419, 373),    S(373, 402),    S(374, 419),    S(371, 422),    //
    S(303, 473),    S(381, 461),    S(462, 418),    S(413, 419),    S(390, 438),    S(367, 451),    S(298, 487),    S(281, 496),    //
    S(276, 466),    S(383, 445),    S(445, 400),    S(420, 401),    S(374, 431),    S(326, 462),    S(327, 461),    S(261, 496),    //
    S(277, 423),    S(365, 422),    S(394, 404),    S(369, 415),    S(356, 433),    S(314, 457),    S(312, 449),    S(233, 479),    //
    S(257, 359),    S(325, 370),    S(313, 392),    S(290, 394),    S(268, 420),    S(256, 437),    S(226, 430),    S(208, 423),    //
    S(246, 301),    S(308, 328),    S(295, 351),    S(279, 354),    S(263, 367),    S(239, 391),    S(238, 366),    S(201, 377),    //
    S(137, 313),    S(271, 269),    S(281, 303),    S(270, 329),    S(254, 338),    S(247, 345),    S(228, 334),    S(203, 346),    //
    S(204, 291),    S(229, 307),    S(283, 300),    S(298, 294),    S(287, 303),    S(266, 323),    S(256, 319),    S(235, 330),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(539, 635),    S(589, 594),    S(520, 710),    S(486, 790),    S(477, 771),    S(509, 716),    S(520, 647),    S(463, 694),    //
    S(550, 679),    S(529, 776),    S(524, 807),    S(372, 923),    S(380, 915),    S(442, 864),    S(483, 737),    S(474, 722),    //
    S(503, 767),    S(566, 781),    S(514, 870),    S(471, 897),    S(435, 913),    S(477, 842),    S(505, 759),    S(514, 677),    //
    S(537, 691),    S(556, 771),    S(504, 833),    S(495, 874),    S(481, 889),    S(485, 806),    S(523, 743),    S(501, 702),    //
    S(547, 655),    S(540, 728),    S(515, 783),    S(484, 837),    S(487, 832),    S(482, 797),    S(498, 716),    S(519, 639),    //
    S(520, 599),    S(550, 660),    S(547, 724),    S(511, 736),    S(512, 723),    S(506, 751),    S(521, 669),    S(498, 644),    //
    S(491, 494),    S(530, 500),    S(531, 583),    S(542, 629),    S(531, 658),    S(524, 628),    S(491, 657),    S(499, 645),    //
    S(472, 505),    S(505, 351),    S(524, 387),    S(536, 509),    S(533, 579),    S(535, 525),    S(526, 549),    S(494, 578),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-68, -356),   S(302, 138),    S(165, 116),    S(13, -26),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(229, -86),    S(365, 133),    S(209, 146),    S(133, 2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(233, 10),     S(397, 93),     S(283, 103),    S(172, 13),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(88, -20),     S(333, 48),     S(181, 75),     S(128, 38),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -32),    S(235, 10),     S(163, 23),     S(51, 34),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-25, -20),    S(217, -3),     S(114, 16),     S(67, 2),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-6, -22),     S(89, 29),      S(1, 38),       S(-53, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, -74),   S(-22, -21),    S(-125, -8),    S(-124, -77),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, -16), S(3, 18), S(-2, 19), S(5, 7), S(5, 4), S(-1, 18), S(4, 19), }},
  {{ S(8, -2), S(-17, 26), S(-14, 21), S(-6, 5), S(-5, 5), S(-14, 24), S(-16, 34), }},
  {{ S(-9, 2), S(-19, 24), S(-19, 7), S(-15, -6), S(-15, -5), S(-18, 7), S(-18, 21), }},
  {{ S(6, -14), S(-11, -14), S(-3, -16), S(2, -19), S(0, -17), S(-4, -14), S(-7, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(5, 32), S(-16, 40), S(-13, 29), S(-5, 17), S(-5, 1),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 8), S(-12, 21), S(-10, 20), S(-10, 22), S(-10, 18), S(-9, 12), S(-11, 19), }},
  {{ S(-0, 6), S(-8, 17), S(-14, 21), S(-12, 20), S(-12, 16), S(-13, 18), S(-7, 16), }},
  {{ S(-7, 11), S(-11, 13), S(-12, 19), S(-8, 19), S(-8, 19), S(-12, 18), S(-11, 14), }},
  {{ S(-7, 13), S(-12, 19), S(-13, 19), S(-9, 23), S(-7, 24), S(-13, 20), S(-14, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1233, 577, -49, 26
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(136);
inline VParam WINNABLE_ASYM = V(122);
inline VParam WINNABLE_NEUTRAL_SQUARES = V(1);
inline VParam WINNABLE_PAWN_ENDGAME = V(208);
inline VParam WINNABLE_BIAS = V(-665);

// Epoch duration: 8.29935s
// clang-format on
}  // namespace Clockwork
