#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(135, 205);
inline const PParam KNIGHT_MAT = S(576, 613);
inline const PParam BISHOP_MAT = S(604, 623);
inline const PParam ROOK_MAT   = S(480, 656);
inline const PParam QUEEN_MAT  = S(1034, 461);
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
    S(16, 2), S(39, 24), S(59, 48), S(133, 146), S(376, 207), S(425, 724),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 33), S(45, 26), S(55, 53), S(118, 138), S(423, 76),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-79, -106), S(-74, -87), S(-47, 13), S(15, 106), S(103, 244), S(282, 355),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(35, -41), S(37, -6), S(26, 28), S(4, 106), S(61, 205), S(217, 262),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -24), S(1, 23), S(2, -9), S(-0, -39), S(-2, -121), S(-227, -207),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(1, 144), S(-18, 115), S(-11, 42), S(-4, 5), S(1, 6), S(36, 5), S(10, -2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-320, -33), S(-38, 29), S(-32, 73), S(16, 85), S(36, 101), S(54, 101), S(35, 94),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(65, -1), S(135, 169), S(169, 259), S(195, 297), S(235, 313), S(260, 345), S(291, 342), S(322, 354), S(366, 285),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(90, -7), S(133, 168), S(187, 238), S(213, 285), S(238, 317), S(254, 341), S(261, 361), S(275, 372), S(281, 389), S(305, 370), S(318, 370), S(366, 320), S(367, 330), S(397, 286),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(318, 240), S(232, 419), S(256, 447), S(273, 457), S(284, 470), S(289, 481), S(295, 492), S(303, 494), S(308, 506), S(319, 506), S(331, 507), S(338, 512), S(344, 510), S(361, 481), S(440, 386),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(439, 197), S(588, 201), S(613, 313), S(631, 430), S(646, 477), S(655, 522), S(660, 555), S(668, 566), S(671, 590), S(674, 605), S(680, 611), S(684, 619), S(692, 615), S(694, 620), S(699, 615), S(698, 616), S(699, 615), S(704, 610), S(711, 601), S(720, 595), S(727, 572), S(745, 536), S(738, 542), S(742, 478), S(723, 477), S(718, 441), S(656, 490), S(681, 389),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(486, -206), S(103, -122), S(22, -24), S(9, 7), S(-7, 4), S(-16, 2), S(-16, 5), S(-31, 16), S(-32, 3),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -35), S(13, -24), S(12, -5), S(5, -11), S(2, 148),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -23), S(5, -35), S(5, -21), S(5, -5), S(5, 288),
};

inline const PParam KS_NOQUEEN_VAL = S(-69, -735);

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
    S(326, 310),    S(183, 396),    S(308, 371),    S(303, 288),    S(328, 239),    S(216, 331),    S(154, 377),    S(271, 309),    //
    S(116, 216),    S(163, 237),    S(195, 175),    S(161, 137),    S(147, 112),    S(114, 173),    S(90, 223),     S(43, 242),     //
    S(92, 162),     S(81, 175),     S(113, 128),    S(106, 111),    S(95, 102),     S(69, 130),     S(22, 174),     S(9, 199),      //
    S(65, 113),     S(55, 147),     S(80, 117),     S(74, 111),     S(53, 111),     S(36, 132),     S(-22, 171),    S(-22, 162),    //
    S(60, 91),      S(96, 97),      S(78, 135),     S(69, 132),     S(40, 128),     S(17, 136),     S(-17, 154),    S(-24, 145),    //
    S(74, 90),      S(156, 110),    S(136, 157),    S(88, 165),     S(60, 152),     S(39, 141),     S(10, 158),     S(-7, 157),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-263, -70),   S(-160, 207),   S(16, -76),     S(92, 209),     S(49, 190),     S(-96, 181),    S(-250, 251),   S(-301, 8),     //
    S(77, 163),     S(125, 185),    S(213, 161),    S(206, 184),    S(203, 186),    S(122, 199),    S(86, 197),     S(54, 182),     //
    S(157, 158),    S(201, 159),    S(218, 208),    S(215, 213),    S(176, 246),    S(117, 244),    S(117, 194),    S(87, 176),     //
    S(226, 185),    S(231, 212),    S(232, 235),    S(216, 272),    S(219, 272),    S(176, 254),    S(168, 222),    S(162, 194),    //
    S(210, 192),    S(247, 177),    S(219, 226),    S(214, 246),    S(190, 250),    S(189, 233),    S(185, 190),    S(147, 192),    //
    S(160, 146),    S(186, 163),    S(176, 199),    S(184, 221),    S(180, 220),    S(145, 201),    S(135, 170),    S(105, 137),    //
    S(166, 153),    S(184, 150),    S(155, 161),    S(159, 187),    S(152, 184),    S(123, 142),    S(107, 162),    S(97, 77),      //
    S(97, 100),     S(146, 162),    S(158, 135),    S(177, 138),    S(159, 158),    S(126, 133),    S(111, 150),    S(73, 60),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(3, 307),      S(-3, 305),     S(-271, 363),   S(-135, 301),   S(-135, 313),   S(-155, 313),   S(-42, 310),    S(39, 282),     //
    S(125, 221),    S(74, 290),     S(106, 246),    S(53, 274),     S(71, 271),     S(93, 263),     S(127, 268),    S(104, 244),    //
    S(185, 246),    S(205, 250),    S(199, 267),    S(179, 265),    S(146, 268),    S(157, 270),    S(172, 254),    S(162, 233),    //
    S(162, 236),    S(198, 242),    S(204, 261),    S(197, 305),    S(227, 291),    S(158, 269),    S(170, 235),    S(132, 232),    //
    S(196, 186),    S(212, 226),    S(217, 252),    S(220, 277),    S(197, 288),    S(181, 271),    S(148, 248),    S(145, 204),    //
    S(220, 199),    S(258, 214),    S(267, 238),    S(211, 266),    S(206, 244),    S(202, 251),    S(210, 232),    S(145, 230),    //
    S(183, 168),    S(282, 178),    S(242, 199),    S(211, 221),    S(192, 224),    S(194, 200),    S(194, 190),    S(187, 186),    //
    S(216, 171),    S(201, 198),    S(203, 218),    S(218, 196),    S(209, 204),    S(208, 242),    S(206, 222),    S(195, 191),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(426, 392),    S(437, 411),    S(425, 420),    S(437, 393),    S(414, 400),    S(385, 406),    S(381, 420),    S(374, 422),    //
    S(307, 475),    S(381, 470),    S(463, 435),    S(410, 445),    S(391, 456),    S(373, 457),    S(305, 488),    S(292, 489),    //
    S(281, 466),    S(380, 452),    S(438, 419),    S(417, 406),    S(369, 436),    S(327, 459),    S(328, 457),    S(269, 491),    //
    S(283, 433),    S(359, 440),    S(399, 411),    S(370, 417),    S(365, 421),    S(324, 448),    S(319, 445),    S(247, 472),    //
    S(265, 369),    S(330, 384),    S(316, 408),    S(300, 398),    S(280, 416),    S(269, 432),    S(237, 430),    S(216, 432),    //
    S(256, 317),    S(313, 347),    S(302, 367),    S(289, 362),    S(278, 369),    S(249, 397),    S(248, 372),    S(212, 384),    //
    S(146, 333),    S(278, 294),    S(290, 319),    S(282, 340),    S(267, 346),    S(258, 354),    S(241, 340),    S(217, 350),    //
    S(214, 308),    S(235, 332),    S(292, 324),    S(305, 318),    S(295, 325),    S(275, 342),    S(264, 339),    S(246, 345),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(494, 444),    S(547, 391),    S(482, 493),    S(451, 561),    S(442, 532),    S(468, 489),    S(488, 416),    S(432, 473),    //
    S(498, 492),    S(464, 584),    S(460, 604),    S(319, 694),    S(329, 676),    S(385, 640),    S(428, 518),    S(436, 500),    //
    S(462, 560),    S(513, 572),    S(455, 658),    S(403, 675),    S(380, 666),    S(429, 590),    S(465, 509),    S(480, 438),    //
    S(509, 459),    S(514, 547),    S(450, 623),    S(443, 647),    S(434, 647),    S(447, 550),    S(488, 487),    S(474, 450),    //
    S(524, 425),    S(510, 504),    S(483, 553),    S(454, 596),    S(453, 596),    S(457, 537),    S(472, 467),    S(498, 389),    //
    S(501, 371),    S(537, 415),    S(528, 484),    S(498, 482),    S(496, 467),    S(492, 485),    S(505, 408),    S(482, 386),    //
    S(483, 249),    S(522, 255),    S(526, 321),    S(536, 371),    S(523, 397),    S(518, 361),    S(481, 399),    S(489, 383),    //
    S(465, 252),    S(495, 105),    S(519, 127),    S(534, 237),    S(530, 313),    S(528, 262),    S(517, 286),    S(487, 315),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-180, -161),  S(177, 291),    S(102, 282),    S(-64, 204),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(104, 55),     S(254, 206),    S(159, 233),    S(109, 117),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(101, 109),    S(266, 154),    S(225, 159),    S(171, 81),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-13, 37),     S(232, 64),     S(152, 96),     S(138, 84),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-81, -29),    S(165, -6),     S(132, 40),     S(49, 88),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-29, -64),    S(175, -45),    S(101, 15),     S(60, 55),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(7, -80),      S(85, -39),     S(10, 9),       S(-40, 39),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-109, -115),  S(-11, -71),    S(-103, -35),   S(-99, -52),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(8, 52), S(-7, 54), S(-11, 54), S(-4, 18), S(-4, 14), S(-11, 54), S(-5, 54), }},
  {{ S(0, 122), S(-24, 102), S(-20, 87), S(-10, 45), S(-10, 51), S(-19, 90), S(-23, 105), }},
  {{ S(-5, 112), S(-17, 103), S(-13, 80), S(-10, 54), S(-9, 45), S(-13, 79), S(-16, 102), }},
  {{ S(1, 111), S(-15, 55), S(-7, 69), S(-3, 59), S(-5, 58), S(-8, 66), S(-12, 66), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(5, -152), S(-15, 96), S(-12, 45), S(-6, 106), S(-7, 71),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 129), S(-12, 116), S(-11, 94), S(-10, 93), S(-10, 100), S(-10, 95), S(-12, 118), }},
  {{ S(-3, 66), S(-9, 53), S(-15, 44), S(-11, 15), S(-12, 4), S(-14, 31), S(-8, 49), }},
  {{ S(-8, 78), S(-12, 60), S(-13, 60), S(-9, 51), S(-9, 42), S(-13, 53), S(-11, 59), }},
  {{ S(-8, 81), S(-14, 73), S(-15, 54), S(-9, 51), S(-8, 52), S(-14, 60), S(-15, 69), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1388, 1633, -32, 141
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(239);
inline VParam WINNABLE_BIAS = V(-649);

// Epoch duration: 8.59547s
// clang-format on
}  // namespace Clockwork
