#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(135, 205);
inline const PParam KNIGHT_MAT = S(580, 608);
inline const PParam BISHOP_MAT = S(615, 634);
inline const PParam ROOK_MAT   = S(477, 657);
inline const PParam QUEEN_MAT  = S(1036, 464);
inline const PParam TEMPO_VAL  = S(58, 20);

inline const PParam BISHOP_PAIR_VAL   = S(55, 192);
inline const PParam ROOK_OPEN_VAL     = S(105, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 24);
inline const PParam MINOR_BEHIND_PAWN = S(11, 39);

inline const PParam DOUBLED_PAWN_VAL = S(-6, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(44, 50);
inline const PParam OUTPOST_BISHOP_VAL    = S(52, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(53, -23);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(28, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(69, -45);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 2), S(39, 24), S(59, 48), S(133, 146), S(376, 207), S(420, 727),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 33), S(45, 26), S(55, 53), S(118, 138), S(423, 76),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-79, -105), S(-74, -87), S(-47, 13), S(15, 106), S(103, 244), S(282, 354),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -41), S(37, -6), S(26, 28), S(4, 106), S(61, 205), S(218, 262),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -24), S(1, 23), S(2, -9), S(-0, -39), S(-2, -121), S(-227, -207),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(1, 144), S(-18, 115), S(-11, 42), S(-3, 5), S(1, 6), S(36, 5), S(10, -2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-320, -33), S(-39, 29), S(-32, 73), S(16, 85), S(36, 101), S(53, 101), S(35, 93),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(63, 2), S(133, 172), S(167, 262), S(193, 300), S(233, 316), S(258, 348), S(289, 345), S(320, 358), S(364, 288),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(87, -12), S(130, 163), S(184, 233), S(210, 280), S(235, 312), S(251, 336), S(258, 356), S(272, 367), S(278, 384), S(303, 365), S(315, 364), S(363, 315), S(364, 325), S(394, 281),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(321, 240), S(234, 419), S(259, 447), S(276, 457), S(286, 470), S(292, 482), S(298, 493), S(306, 495), S(311, 506), S(322, 507), S(333, 507), S(340, 512), S(346, 510), S(364, 481), S(442, 386),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(439, 196), S(587, 201), S(612, 312), S(630, 429), S(646, 477), S(654, 522), S(660, 555), S(667, 565), S(671, 590), S(674, 604), S(680, 610), S(683, 619), S(691, 615), S(694, 619), S(699, 614), S(698, 616), S(699, 615), S(704, 610), S(711, 600), S(719, 595), S(726, 572), S(745, 536), S(737, 542), S(741, 478), S(723, 477), S(718, 441), S(656, 490), S(681, 388),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(488, -209), S(105, -125), S(23, -26), S(11, 4), S(-6, 1), S(-14, -1), S(-15, 2), S(-29, 13), S(-30, -0),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -35), S(13, -24), S(12, -5), S(5, -11), S(2, 141),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -23), S(5, -35), S(5, -21), S(5, -5), S(5, 286),
};

inline const PParam KS_NO_QUEEN = S(-69, -730);
inline const PParam PAWN_THREAT_KNIGHT = S(212, 95);
inline const PParam PAWN_THREAT_BISHOP = S(191, 138);
inline const PParam PAWN_THREAT_ROOK   = S(193, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(171, -23);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(153, -8);

inline const PParam BISHOP_THREAT_KNIGHT = S(106, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 127);
inline const PParam BISHOP_THREAT_QUEEN  = S(181, 87);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -32), S(-3, -6), S(-5, -14), S(-8, -23), S(-11, -32), S(-16, -36), S(-17, -47), S(-24, -44), S(-35, -45),
};

inline const PParam ROOK_LINEUP = S(12, 70);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(326, 311),    S(183, 397),    S(308, 372),    S(303, 289),    S(328, 240),    S(216, 332),    S(154, 378),    S(271, 310),    //
    S(117, 216),    S(163, 237),    S(195, 176),    S(162, 137),    S(147, 112),    S(114, 173),    S(90, 224),     S(43, 242),     //
    S(92, 162),     S(82, 175),     S(114, 128),    S(106, 111),    S(95, 103),     S(70, 130),     S(23, 174),     S(10, 200),     //
    S(65, 114),     S(55, 147),     S(80, 117),     S(74, 111),     S(53, 111),     S(36, 133),     S(-22, 171),    S(-22, 162),    //
    S(60, 91),      S(97, 97),      S(78, 135),     S(69, 132),     S(41, 128),     S(17, 136),     S(-17, 155),    S(-24, 145),    //
    S(75, 90),      S(157, 110),    S(137, 157),    S(88, 165),     S(60, 152),     S(39, 141),     S(10, 158),     S(-7, 157),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-265, -69),   S(-163, 209),   S(14, -75),     S(90, 211),     S(47, 191),     S(-98, 182),    S(-252, 253),   S(-304, 9),     //
    S(75, 165),     S(123, 186),    S(211, 162),    S(203, 185),    S(201, 188),    S(120, 200),    S(84, 199),     S(52, 183),     //
    S(154, 159),    S(198, 160),    S(216, 209),    S(213, 214),    S(174, 247),    S(114, 245),    S(115, 195),    S(85, 177),     //
    S(224, 186),    S(229, 213),    S(229, 236),    S(213, 273),    S(217, 274),    S(174, 255),    S(165, 223),    S(160, 195),    //
    S(207, 193),    S(244, 178),    S(216, 227),    S(212, 247),    S(188, 251),    S(187, 234),    S(182, 191),    S(145, 193),    //
    S(158, 148),    S(183, 164),    S(174, 200),    S(181, 222),    S(178, 221),    S(142, 202),    S(133, 171),    S(103, 138),    //
    S(164, 154),    S(182, 152),    S(153, 163),    S(156, 188),    S(150, 185),    S(121, 143),    S(105, 163),    S(94, 78),      //
    S(94, 102),     S(143, 163),    S(156, 136),    S(175, 139),    S(156, 159),    S(124, 134),    S(109, 151),    S(70, 61),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-6, 301),     S(-12, 299),    S(-280, 357),   S(-144, 295),   S(-143, 306),   S(-163, 307),   S(-50, 304),    S(31, 276),     //
    S(117, 215),    S(65, 284),     S(97, 240),     S(45, 268),     S(62, 265),     S(84, 257),     S(118, 262),    S(95, 237),     //
    S(176, 240),    S(196, 244),    S(191, 260),    S(171, 259),    S(138, 262),    S(148, 264),    S(163, 248),    S(154, 227),    //
    S(153, 229),    S(190, 235),    S(196, 255),    S(188, 299),    S(219, 285),    S(149, 263),    S(162, 229),    S(123, 226),    //
    S(187, 180),    S(204, 220),    S(209, 245),    S(211, 271),    S(188, 282),    S(173, 265),    S(139, 242),    S(137, 198),    //
    S(211, 193),    S(249, 208),    S(258, 232),    S(203, 260),    S(197, 238),    S(193, 245),    S(201, 226),    S(137, 224),    //
    S(174, 161),    S(274, 172),    S(233, 193),    S(202, 215),    S(183, 218),    S(186, 194),    S(185, 184),    S(179, 180),    //
    S(207, 165),    S(193, 192),    S(194, 212),    S(209, 190),    S(200, 198),    S(199, 236),    S(198, 215),    S(187, 185),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(423, 390),    S(435, 410),    S(423, 419),    S(434, 392),    S(412, 399),    S(382, 405),    S(378, 419),    S(371, 421),    //
    S(304, 474),    S(378, 469),    S(461, 434),    S(407, 443),    S(388, 455),    S(370, 455),    S(302, 487),    S(289, 488),    //
    S(278, 465),    S(377, 450),    S(436, 418),    S(414, 405),    S(366, 435),    S(325, 458),    S(325, 456),    S(267, 489),    //
    S(280, 431),    S(356, 439),    S(396, 409),    S(367, 415),    S(363, 420),    S(321, 447),    S(316, 444),    S(244, 471),    //
    S(262, 368),    S(327, 383),    S(313, 406),    S(297, 397),    S(278, 415),    S(267, 431),    S(234, 429),    S(213, 431),    //
    S(253, 316),    S(310, 346),    S(299, 366),    S(286, 361),    S(275, 368),    S(247, 396),    S(245, 371),    S(209, 382),    //
    S(143, 331),    S(275, 293),    S(287, 318),    S(280, 339),    S(265, 345),    S(256, 353),    S(238, 339),    S(214, 349),    //
    S(211, 307),    S(232, 331),    S(289, 322),    S(302, 317),    S(292, 323),    S(272, 340),    S(262, 337),    S(243, 343),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(494, 443),    S(547, 390),    S(481, 492),    S(450, 560),    S(441, 531),    S(468, 488),    S(488, 415),    S(431, 471),    //
    S(498, 490),    S(463, 583),    S(460, 603),    S(318, 693),    S(329, 675),    S(384, 639),    S(427, 517),    S(435, 499),    //
    S(462, 559),    S(512, 571),    S(454, 657),    S(403, 674),    S(379, 665),    S(428, 588),    S(465, 508),    S(479, 437),    //
    S(509, 458),    S(513, 546),    S(450, 621),    S(442, 646),    S(433, 646),    S(447, 549),    S(487, 486),    S(474, 449),    //
    S(523, 424),    S(510, 503),    S(483, 552),    S(454, 594),    S(453, 595),    S(456, 536),    S(471, 466),    S(498, 388),    //
    S(501, 370),    S(537, 414),    S(527, 483),    S(497, 481),    S(496, 466),    S(492, 484),    S(505, 407),    S(482, 385),    //
    S(482, 248),    S(521, 254),    S(525, 320),    S(535, 370),    S(523, 396),    S(517, 360),    S(480, 398),    S(488, 382),    //
    S(464, 251),    S(494, 103),    S(518, 126),    S(533, 236),    S(529, 312),    S(528, 260),    S(517, 285),    S(486, 314),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-177, -161),  S(180, 290),    S(104, 281),    S(-61, 204),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(106, 55),     S(256, 206),    S(161, 233),    S(111, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(103, 108),    S(268, 154),    S(227, 159),    S(173, 81),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-11, 36),     S(234, 64),     S(154, 96),     S(140, 84),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-79, -29),    S(167, -6),     S(134, 40),     S(51, 88),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-27, -64),    S(177, -45),    S(103, 15),     S(62, 55),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(9, -80),      S(87, -39),     S(12, 9),       S(-38, 39),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-106, -115),  S(-9, -71),     S(-101, -35),   S(-97, -52),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(11, 53), S(-4, 55), S(-8, 55), S(-1, 18), S(-1, 14), S(-8, 55), S(-3, 54), }},
  {{ S(3, 122), S(-21, 101), S(-17, 87), S(-8, 45), S(-7, 51), S(-16, 90), S(-20, 105), }},
  {{ S(-11, 114), S(-22, 105), S(-19, 82), S(-15, 56), S(-15, 47), S(-18, 81), S(-21, 103), }},
  {{ S(4, 111), S(-13, 55), S(-4, 69), S(-0, 59), S(-2, 58), S(-5, 65), S(-9, 65), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, -149), S(-17, 96), S(-14, 45), S(-8, 106), S(-9, 71),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, 128), S(-14, 116), S(-13, 93), S(-12, 93), S(-12, 99), S(-12, 95), S(-14, 118), }},
  {{ S(-5, 67), S(-11, 53), S(-17, 45), S(-13, 16), S(-14, 5), S(-16, 31), S(-10, 49), }},
  {{ S(-10, 78), S(-14, 61), S(-15, 61), S(-11, 52), S(-11, 43), S(-15, 54), S(-13, 60), }},
  {{ S(-10, 82), S(-16, 74), S(-17, 54), S(-11, 52), S(-10, 53), S(-16, 61), S(-17, 70), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1388, 1632, -26, 133
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(239);
inline VParam WINNABLE_BIAS = V(-649);

// Epoch duration: 7.70156s
// clang-format on
}  // namespace Clockwork
