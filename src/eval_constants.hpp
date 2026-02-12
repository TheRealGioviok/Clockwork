#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(136, 218);
inline const PParam KNIGHT_MAT = S(627, 751);
inline const PParam BISHOP_MAT = S(618, 713);
inline const PParam ROOK_MAT   = S(526, 831);
inline const PParam QUEEN_MAT  = S(1212, 1216);
inline const PParam TEMPO_VAL  = S(62, 31);

inline const PParam BISHOP_PAIR_VAL   = S(60, 190);
inline const PParam ROOK_OPEN_VAL     = S(76, 61);
inline const PParam ROOK_SEMIOPEN_VAL = S(52, -3);
inline const PParam SEE_CONTROL_VALUE = S(-6, 2);
inline const PParam SEE_CONTROL_OPENFILE_VALUE = S(16, -32);
inline const PParam SEE_CONTROL_SEMIOPENFILE_VALUE = S(-1, 7);
inline const PParam SEE_RESTRICTED_SQUARES = S(10, 1);

inline const PParam DOUBLED_PAWN_VAL = S(-4, -89);
inline const PParam ISOLATED_PAWN_VAL = S(-27, -3);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -23);
inline const PParam OUTPOST_KNIGHT_VAL    = S(40, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(37, 36);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(22, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -30);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, 6), S(38, 28), S(64, 46), S(147, 141), S(368, 210), S(427, 714),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 31), S(44, 19), S(53, 45), S(118, 123), S(425, 40),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-73, -115), S(-68, -99), S(-45, 10), S(6, 119), S(94, 263), S(267, 391),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(45, -62), S(40, -17), S(30, 17), S(7, 96), S(55, 212), S(183, 285),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(16, -34), S(0, 8), S(2, -22), S(-1, -58), S(-9, -132), S(-209, -250),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-0, 143), S(-14, 111), S(-12, 48), S(-6, 14), S(1, 10), S(38, 6), S(11, 1),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-314, -32), S(-40, 24), S(-22, 57), S(13, 94), S(31, 111), S(47, 115), S(33, 103),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(16, -72), S(88, 111), S(123, 201), S(150, 238), S(187, 257), S(207, 289), S(232, 292), S(256, 311), S(292, 255),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(67, -27), S(114, 146), S(171, 212), S(200, 255), S(225, 289), S(241, 313), S(248, 335), S(258, 353), S(262, 378), S(280, 376), S(286, 389), S(315, 370), S(312, 390), S(302, 400),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(296, 189), S(198, 365), S(223, 391), S(241, 401), S(253, 413), S(260, 423), S(266, 434), S(275, 437), S(281, 450), S(291, 454), S(300, 459), S(305, 469), S(310, 475), S(319, 467), S(380, 401),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(466, 486), S(594, 512), S(620, 619), S(640, 730), S(657, 773), S(667, 814), S(674, 845), S(684, 852), S(689, 874), S(693, 887), S(700, 893), S(705, 902), S(714, 898), S(716, 906), S(721, 905), S(718, 914), S(718, 919), S(722, 921), S(723, 927), S(731, 928), S(731, 923), S(751, 893), S(738, 909), S(725, 876), S(702, 880), S(691, 862), S(626, 921), S(637, 853),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(512, -202), S(115, -111), S(35, -30), S(23, -2), S(3, -3), S(-17, -9), S(-26, 5), S(-50, 24), S(-54, 5),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -10), S(14, -13), S(12, -10), S(5, -7), S(2, 283),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(6, -9), S(5, -7), S(5, -5), S(6, 480),
};

inline const PParam PAWN_THREAT_KNIGHT = S(165, 61);
inline const PParam PAWN_THREAT_BISHOP = S(149, 94);
inline const PParam PAWN_THREAT_ROOK   = S(165, 69);
inline const PParam PAWN_THREAT_QUEEN  = S(80, -3);

inline const PParam KNIGHT_THREAT_BISHOP = S(83, 62);
inline const PParam KNIGHT_THREAT_ROOK   = S(205, 18);
inline const PParam KNIGHT_THREAT_QUEEN  = S(89, -3);

inline const PParam BISHOP_THREAT_KNIGHT = S(98, 52);
inline const PParam BISHOP_THREAT_ROOK   = S(197, 77);
inline const PParam BISHOP_THREAT_QUEEN  = S(125, 104);

inline const PParam HANGING_PAWN = S(-7, -53);
inline const PParam HANGING_KNIGHT = S(-45, -76);
inline const PParam HANGING_BISHOP = S(-40, -56);
inline const PParam HANGING_ROOK = S(-29, -68);
inline const PParam HANGING_QUEEN = S(-94, -0);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -27), S(-1, -8), S(-4, -18), S(-8, -28), S(-12, -37), S(-18, -43), S(-20, -55), S(-28, -52), S(-37, -55),
};

inline const PParam ROOK_LINEUP = S(11, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(310, 325),    S(143, 451),    S(289, 415),    S(288, 299),    S(313, 254),    S(195, 358),    S(134, 398),    S(270, 307),    //
    S(127, 204),    S(147, 259),    S(185, 174),    S(163, 126),    S(142, 113),    S(113, 172),    S(88, 227),     S(54, 230),     //
    S(96, 164),     S(72, 179),     S(119, 99),     S(112, 94),     S(99, 94),      S(70, 131),     S(18, 185),     S(20, 194),     //
    S(64, 121),     S(45, 156),     S(80, 100),     S(73, 104),     S(49, 111),     S(31, 141),     S(-29, 188),    S(-19, 163),    //
    S(61, 96),      S(89, 118),     S(75, 144),     S(64, 140),     S(36, 138),     S(13, 147),     S(-24, 170),    S(-20, 145),    //
    S(72, 97),      S(154, 125),    S(140, 180),    S(87, 168),     S(58, 159),     S(39, 154),     S(7, 171),      S(-2, 159),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-254, -120),  S(-143, 133),   S(-52, -52),    S(93, 139),     S(25, 146),     S(-100, 132),   S(-235, 187),   S(-296, -37),   //
    S(79, 105),     S(107, 147),    S(192, 125),    S(193, 128),    S(183, 141),    S(97, 171),     S(63, 171),     S(40, 141),     //
    S(150, 100),    S(185, 125),    S(185, 181),    S(176, 166),    S(140, 193),    S(81, 222),     S(91, 178),     S(66, 144),     //
    S(212, 132),    S(212, 161),    S(213, 193),    S(204, 223),    S(202, 238),    S(153, 228),    S(137, 197),    S(138, 158),    //
    S(197, 143),    S(224, 141),    S(202, 198),    S(192, 223),    S(173, 230),    S(170, 216),    S(157, 173),    S(130, 160),    //
    S(136, 115),    S(164, 132),    S(156, 170),    S(164, 197),    S(159, 199),    S(125, 178),    S(110, 148),    S(78, 115),     //
    S(151, 122),    S(177, 120),    S(143, 136),    S(139, 161),    S(129, 158),    S(103, 116),    S(87, 133),     S(72, 56),      //
    S(80, 74),      S(126, 140),    S(140, 109),    S(155, 99),     S(137, 122),    S(101, 103),    S(89, 125),     S(52, 47),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(2, 294),      S(-8, 291),     S(-254, 331),   S(-133, 273),   S(-131, 285),   S(-145, 283),   S(-37, 280),    S(39, 263),     //
    S(120, 212),    S(70, 278),     S(96, 240),     S(50, 256),     S(57, 263),     S(82, 257),     S(122, 249),    S(93, 233),     //
    S(189, 236),    S(201, 241),    S(194, 255),    S(168, 257),    S(138, 255),    S(147, 261),    S(159, 254),    S(157, 232),    //
    S(158, 223),    S(197, 238),    S(200, 251),    S(197, 273),    S(225, 261),    S(150, 261),    S(166, 232),    S(116, 239),    //
    S(185, 183),    S(201, 219),    S(209, 239),    S(219, 254),    S(195, 266),    S(172, 262),    S(134, 252),    S(130, 213),    //
    S(210, 192),    S(239, 204),    S(253, 233),    S(201, 259),    S(201, 239),    S(190, 251),    S(194, 230),    S(136, 228),    //
    S(178, 159),    S(273, 189),    S(232, 205),    S(198, 226),    S(179, 226),    S(182, 201),    S(181, 196),    S(174, 191),    //
    S(207, 167),    S(192, 190),    S(190, 229),    S(204, 190),    S(194, 200),    S(195, 241),    S(192, 218),    S(185, 193),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(426, 393),    S(436, 412),    S(421, 412),    S(434, 382),    S(427, 375),    S(378, 406),    S(375, 423),    S(368, 430),    //
    S(304, 468),    S(377, 457),    S(455, 411),    S(404, 412),    S(385, 426),    S(362, 442),    S(298, 477),    S(280, 491),    //
    S(282, 462),    S(384, 440),    S(446, 394),    S(420, 395),    S(375, 424),    S(330, 451),    S(331, 453),    S(267, 493),    //
    S(283, 424),    S(363, 420),    S(399, 394),    S(373, 407),    S(360, 425),    S(319, 450),    S(317, 442),    S(241, 477),    //
    S(264, 361),    S(329, 368),    S(317, 390),    S(297, 392),    S(274, 419),    S(262, 436),    S(233, 430),    S(215, 428),    //
    S(251, 307),    S(310, 333),    S(298, 355),    S(283, 359),    S(271, 370),    S(244, 395),    S(242, 371),    S(208, 382),    //
    S(142, 322),    S(279, 279),    S(287, 315),    S(276, 339),    S(260, 347),    S(254, 353),    S(236, 339),    S(209, 357),    //
    S(210, 302),    S(234, 318),    S(289, 313),    S(305, 306),    S(294, 313),    S(273, 333),    S(261, 330),    S(240, 342),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(538, 643),    S(585, 604),    S(521, 717),    S(483, 800),    S(484, 768),    S(504, 733),    S(515, 662),    S(460, 708),    //
    S(550, 677),    S(525, 763),    S(518, 789),    S(366, 902),    S(377, 890),    S(441, 840),    S(484, 713),    S(477, 711),    //
    S(505, 762),    S(566, 773),    S(518, 850),    S(468, 883),    S(437, 890),    S(485, 812),    S(507, 746),    S(517, 670),    //
    S(541, 685),    S(557, 763),    S(506, 816),    S(501, 847),    S(485, 862),    S(491, 780),    S(527, 729),    S(502, 703),    //
    S(548, 658),    S(544, 720),    S(520, 768),    S(491, 819),    S(493, 815),    S(490, 781),    S(504, 709),    S(524, 637),    //
    S(523, 603),    S(555, 651),    S(551, 717),    S(517, 728),    S(518, 717),    S(513, 745),    S(527, 666),    S(503, 646),    //
    S(496, 504),    S(536, 507),    S(538, 583),    S(550, 628),    S(539, 658),    S(533, 625),    S(501, 651),    S(507, 645),    //
    S(477, 515),    S(511, 357),    S(531, 389),    S(542, 511),    S(540, 585),    S(543, 528),    S(534, 550),    S(499, 584),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-65, -354),   S(295, 150),    S(161, 119),    S(1, -20),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(227, -81),    S(365, 139),    S(209, 148),    S(126, 4),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(232, 14),     S(403, 94),     S(284, 105),    S(170, 11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(83, -13),     S(337, 50),     S(186, 75),     S(123, 38),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-27, -27),    S(238, 14),     S(165, 27),     S(49, 36),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-26, -19),    S(219, 4),      S(115, 20),     S(64, 3),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-7, -23),     S(89, 34),      S(-2, 42),      S(-60, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-122, -81),   S(-23, -20),    S(-128, -8),    S(-130, -82),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -18), S(0, 16), S(-4, 19), S(4, 5), S(3, 3), S(-3, 18), S(2, 17), }},
  {{ S(7, -4), S(-20, 25), S(-16, 19), S(-7, 3), S(-7, 3), S(-16, 23), S(-19, 33), }},
  {{ S(-5, 5), S(-16, 27), S(-15, 8), S(-11, -5), S(-11, -3), S(-14, 9), S(-15, 24), }},
  {{ S(3, -17), S(-14, -18), S(-6, -20), S(-1, -22), S(-2, -21), S(-7, -18), S(-9, -19), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(4, 32), S(-18, 43), S(-15, 31), S(-7, 19), S(-7, 2),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 9), S(-14, 23), S(-13, 22), S(-12, 24), S(-12, 19), S(-11, 14), S(-14, 20), }},
  {{ S(-2, 7), S(-10, 18), S(-16, 23), S(-14, 22), S(-14, 19), S(-15, 20), S(-9, 17), }},
  {{ S(-9, 13), S(-13, 13), S(-14, 21), S(-10, 21), S(-10, 21), S(-14, 20), S(-12, 15), }},
  {{ S(-9, 15), S(-14, 20), S(-15, 21), S(-11, 25), S(-9, 26), S(-14, 21), S(-16, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1228, 539, -44, 23
);

inline VParam WINNABLE_PAWNS = V(-14);
inline VParam WINNABLE_SYM = V(135);
inline VParam WINNABLE_ASYM = V(123);
inline VParam WINNABLE_NEUTRAL_SQUARES = V(1);
inline VParam WINNABLE_PAWN_ENDGAME = V(210);
inline VParam WINNABLE_BIAS = V(-669);

// Epoch duration: 8.75036s
// clang-format on
}  // namespace Clockwork
