#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(134, 206);
inline const PParam KNIGHT_MAT = S(580, 616);
inline const PParam BISHOP_MAT = S(613, 635);
inline const PParam ROOK_MAT   = S(486, 667);
inline const PParam QUEEN_MAT  = S(1043, 458);
inline const PParam TEMPO_VAL  = S(58, 20);

inline const PParam BISHOP_PAIR_VAL   = S(56, 192);
inline const PParam ROOK_OPEN_VAL     = S(106, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 24);
inline const PParam MINOR_BEHIND_PAWN = S(11, 39);

inline const PParam DOUBLED_PAWN_VAL = S(-6, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(44, 49);
inline const PParam OUTPOST_BISHOP_VAL    = S(50, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(27, -30);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(34, -51);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(5, 1);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -68);

inline const PParam SAFE_PAWN_PUSH_THREAT_KNIGHT = S(19, 47);
inline const PParam SAFE_PAWN_PUSH_THREAT_BISHOP = S(24, 68);
inline const PParam SAFE_PAWN_PUSH_THREAT_ROOK   = S(33, 68);
inline const PParam SAFE_PAWN_PUSH_THREAT_QUEEN  = S(17, 51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 1), S(37, 22), S(56, 45), S(130, 144), S(367, 212), S(620, 592),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(56, 33), S(45, 27), S(56, 54), S(121, 139), S(431, 73),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -105), S(-76, -87), S(-47, 13), S(17, 105), S(109, 246), S(282, 357),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -41), S(38, -6), S(24, 30), S(1, 108), S(55, 204), S(223, 263),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -23), S(3, 24), S(1, -10), S(-1, -40), S(-11, -118), S(-227, -207),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(2, 145), S(-19, 117), S(-11, 42), S(-2, 4), S(2, 6), S(38, 5), S(16, -7),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-318, -34), S(-36, 28), S(-30, 73), S(18, 84), S(36, 102), S(54, 102), S(32, 97),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(71, 5), S(139, 175), S(173, 268), S(201, 303), S(240, 320), S(265, 352), S(296, 351), S(326, 363), S(371, 293),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(92, 7), S(137, 174), S(189, 240), S(215, 287), S(240, 318), S(255, 343), S(263, 361), S(276, 371), S(282, 386), S(304, 371), S(314, 371), S(366, 319), S(371, 319), S(396, 286),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(325, 256), S(235, 424), S(260, 451), S(276, 462), S(287, 475), S(292, 486), S(298, 497), S(306, 499), S(312, 510), S(323, 511), S(334, 511), S(340, 517), S(347, 513), S(364, 486), S(442, 390),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(446, 121), S(591, 208), S(615, 326), S(634, 443), S(649, 488), S(658, 531), S(663, 565), S(670, 576), S(673, 600), S(675, 616), S(682, 620), S(685, 629), S(693, 625), S(695, 630), S(699, 627), S(699, 628), S(699, 627), S(706, 619), S(712, 612), S(718, 607), S(724, 587), S(744, 550), S(733, 559), S(737, 495), S(717, 496), S(716, 455), S(648, 504), S(674, 435),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(462, -216), S(105, -120), S(24, -26), S(11, 6), S(-7, 3), S(-13, 1), S(-15, 5), S(-33, 17), S(-29, 3),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -34), S(13, -24), S(12, -5), S(5, -11), S(2, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -23), S(5, -36), S(5, -21), S(5, -5), S(5, 22),
};

inline const PParam KS_NO_QUEEN = S(-69, -753);
inline const PParam PAWN_THREAT_KNIGHT = S(-2, 78);
inline const PParam PAWN_THREAT_BISHOP = S(314, 167);
inline const PParam PAWN_THREAT_ROOK   = S(89, 50);
inline const PParam PAWN_THREAT_QUEEN  = S(86, 11);

inline const PParam SAFE_PAWN_THREAT_KNIGHT = S(220, 17);
inline const PParam SAFE_PAWN_THREAT_BISHOP = S(-123, -38);
inline const PParam SAFE_PAWN_THREAT_ROOK   = S(108, 79);
inline const PParam SAFE_PAWN_THREAT_QUEEN  = S(92, -34);

inline const PParam KNIGHT_THREAT_BISHOP = S(106, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 69);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -15);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 89);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -31), S(-3, -6), S(-4, -15), S(-7, -24), S(-11, -32), S(-15, -37), S(-17, -47), S(-23, -47), S(-38, -43),
};

inline const PParam ROOK_LINEUP = S(13, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(327, 313),    S(170, 400),    S(303, 373),    S(311, 288),    S(329, 240),    S(218, 332),    S(149, 383),    S(273, 314),    //
    S(119, 215),    S(165, 234),    S(190, 176),    S(166, 136),    S(148, 112),    S(113, 170),    S(89, 222),     S(42, 244),     //
    S(91, 165),     S(81, 177),     S(116, 129),    S(108, 112),    S(98, 103),     S(70, 131),     S(23, 178),     S(11, 201),     //
    S(65, 115),     S(55, 148),     S(81, 119),     S(77, 112),     S(54, 113),     S(37, 134),     S(-19, 172),    S(-21, 162),    //
    S(60, 93),      S(98, 98),      S(79, 137),     S(71, 134),     S(43, 129),     S(18, 138),     S(-17, 157),    S(-23, 146),    //
    S(74, 93),      S(157, 113),    S(136, 160),    S(89, 167),     S(61, 154),     S(39, 143),     S(11, 162),     S(-7, 159),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-240, -110),  S(-162, 205),   S(-33, -35),    S(112, 196),    S(41, 199),     S(-99, 188),    S(-277, 266),   S(-308, -12),   //
    S(75, 167),     S(121, 186),    S(216, 156),    S(206, 181),    S(200, 188),    S(122, 201),    S(76, 203),     S(50, 191),     //
    S(158, 164),    S(199, 158),    S(217, 209),    S(212, 218),    S(174, 247),    S(115, 243),    S(120, 190),    S(87, 178),     //
    S(228, 190),    S(233, 217),    S(233, 236),    S(213, 273),    S(219, 273),    S(179, 252),    S(170, 225),    S(162, 198),    //
    S(209, 190),    S(249, 173),    S(220, 225),    S(212, 245),    S(190, 248),    S(190, 232),    S(184, 188),    S(144, 201),    //
    S(160, 150),    S(186, 163),    S(176, 197),    S(184, 217),    S(179, 218),    S(143, 198),    S(135, 171),    S(106, 141),    //
    S(166, 155),    S(181, 153),    S(155, 160),    S(157, 187),    S(150, 185),    S(122, 141),    S(104, 169),    S(91, 80),      //
    S(97, 99),      S(144, 165),    S(158, 137),    S(177, 138),    S(158, 161),    S(125, 130),    S(111, 151),    S(73, 56),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-3, 309),     S(-8, 303),     S(-302, 368),   S(-137, 303),   S(-130, 309),   S(-155, 311),   S(-44, 309),    S(34, 292),     //
    S(125, 219),    S(67, 296),     S(110, 243),    S(47, 277),     S(66, 273),     S(92, 264),     S(128, 263),    S(109, 234),    //
    S(185, 245),    S(204, 251),    S(202, 265),    S(175, 266),    S(146, 271),    S(152, 273),    S(171, 253),    S(157, 239),    //
    S(161, 235),    S(200, 245),    S(205, 265),    S(198, 308),    S(227, 292),    S(161, 265),    S(176, 233),    S(133, 229),    //
    S(191, 189),    S(210, 224),    S(215, 254),    S(219, 279),    S(196, 292),    S(178, 274),    S(148, 242),    S(144, 204),    //
    S(217, 199),    S(257, 211),    S(264, 239),    S(208, 267),    S(202, 246),    S(200, 253),    S(208, 231),    S(145, 229),    //
    S(181, 164),    S(281, 176),    S(238, 200),    S(208, 220),    S(188, 227),    S(195, 197),    S(194, 189),    S(183, 182),    //
    S(213, 166),    S(197, 197),    S(198, 219),    S(215, 193),    S(205, 203),    S(203, 243),    S(204, 218),    S(192, 189),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(423, 391),    S(433, 412),    S(427, 417),    S(439, 386),    S(414, 398),    S(382, 406),    S(380, 418),    S(370, 423),    //
    S(308, 473),    S(372, 475),    S(462, 435),    S(406, 446),    S(394, 454),    S(368, 455),    S(299, 485),    S(294, 483),    //
    S(277, 468),    S(381, 451),    S(439, 411),    S(412, 405),    S(364, 436),    S(324, 456),    S(326, 455),    S(265, 489),    //
    S(280, 435),    S(357, 443),    S(394, 415),    S(367, 415),    S(365, 415),    S(321, 446),    S(315, 447),    S(243, 472),    //
    S(258, 369),    S(324, 385),    S(314, 403),    S(297, 394),    S(279, 410),    S(266, 430),    S(234, 428),    S(212, 427),    //
    S(251, 314),    S(310, 343),    S(302, 360),    S(284, 357),    S(274, 363),    S(244, 396),    S(244, 371),    S(210, 378),    //
    S(142, 333),    S(275, 292),    S(286, 319),    S(278, 338),    S(266, 341),    S(254, 351),    S(240, 335),    S(214, 346),    //
    S(210, 306),    S(228, 330),    S(287, 323),    S(300, 316),    S(289, 324),    S(270, 342),    S(261, 336),    S(244, 343),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(487, 467),    S(551, 402),    S(480, 508),    S(461, 563),    S(447, 532),    S(469, 501),    S(482, 434),    S(430, 484),    //
    S(498, 505),    S(463, 597),    S(452, 626),    S(320, 706),    S(330, 686),    S(383, 649),    S(421, 535),    S(435, 510),    //
    S(464, 569),    S(516, 584),    S(456, 671),    S(403, 689),    S(379, 676),    S(432, 590),    S(465, 518),    S(476, 445),    //
    S(515, 466),    S(511, 563),    S(460, 621),    S(441, 658),    S(432, 659),    S(453, 553),    S(496, 482),    S(478, 451),    //
    S(524, 433),    S(509, 512),    S(485, 557),    S(456, 597),    S(455, 598),    S(458, 542),    S(474, 467),    S(499, 392),    //
    S(505, 375),    S(540, 419),    S(531, 487),    S(502, 482),    S(497, 472),    S(495, 490),    S(505, 418),    S(484, 395),    //
    S(483, 255),    S(525, 256),    S(529, 323),    S(537, 377),    S(525, 402),    S(521, 366),    S(482, 405),    S(491, 379),    //
    S(464, 267),    S(495, 104),    S(517, 136),    S(535, 242),    S(530, 326),    S(529, 271),    S(520, 286),    S(488, 320),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-182, -156),  S(176, 286),    S(100, 286),    S(-63, 216),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(112, 53),     S(253, 205),    S(159, 234),    S(119, 111),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(107, 107),    S(264, 153),    S(227, 158),    S(177, 83),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-17, 37),     S(230, 63),     S(155, 95),     S(137, 85),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-81, -33),    S(160, -6),     S(129, 37),     S(47, 87),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-34, -65),    S(172, -48),    S(98, 11),      S(57, 53),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(5, -82),      S(84, -42),     S(11, 5),       S(-44, 37),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-110, -117),  S(-13, -72),    S(-108, -34),   S(-97, -57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(13, 33), S(-2, 35), S(-6, 34), S(1, -2), S(1, -6), S(-6, 35), S(-1, 35), }},
  {{ S(6, 146), S(-19, 124), S(-15, 109), S(-6, 72), S(-5, 70), S(-14, 111), S(-18, 128), }},
  {{ S(-2, 119), S(-14, 110), S(-11, 87), S(-7, 60), S(-7, 55), S(-10, 85), S(-13, 108), }},
  {{ S(6, 117), S(-10, 61), S(-2, 73), S(2, 66), S(-0, 65), S(-3, 70), S(-7, 70), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, 81), S(-15, -129), S(-13, 52), S(-7, 98), S(-7, 65),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 152), S(-13, 139), S(-12, 116), S(-11, 116), S(-11, 121), S(-11, 116), S(-13, 140), }},
  {{ S(-4, 47), S(-9, 31), S(-15, 22), S(-12, -0), S(-13, -15), S(-15, 9), S(-9, 29), }},
  {{ S(-9, 77), S(-13, 58), S(-14, 59), S(-10, 49), S(-10, 39), S(-14, 53), S(-13, 60), }},
  {{ S(-9, 79), S(-15, 72), S(-16, 54), S(-10, 48), S(-9, 52), S(-16, 58), S(-16, 70), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1394, 1641, -42, 145
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(234);
inline VParam WINNABLE_BIAS = V(-655);

// Epoch duration: 9.41563s
// clang-format on
}  // namespace Clockwork
