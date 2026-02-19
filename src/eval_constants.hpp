#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(134, 207);
inline const PParam KNIGHT_MAT = S(574, 615);
inline const PParam BISHOP_MAT = S(611, 631);
inline const PParam ROOK_MAT   = S(482, 665);
inline const PParam QUEEN_MAT  = S(1035, 464);
inline const PParam TEMPO_VAL  = S(58, 20);

inline const PParam BISHOP_PAIR_VAL   = S(57, 192);
inline const PParam ROOK_OPEN_VAL     = S(106, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 24);
inline const PParam MINOR_BEHIND_PAWN = S(11, 38);

inline const PParam DOUBLED_PAWN_VAL = S(-6, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(45, 48);
inline const PParam OUTPOST_BISHOP_VAL    = S(52, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(52, -21);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(70, -46);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 2), S(39, 24), S(60, 48), S(136, 146), S(382, 213), S(609, 596),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 32), S(45, 27), S(55, 53), S(121, 138), S(432, 72),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -105), S(-76, -87), S(-47, 13), S(15, 105), S(105, 246), S(281, 358),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -41), S(38, -6), S(25, 30), S(4, 108), S(64, 202), S(224, 262),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -23), S(2, 23), S(1, -9), S(1, -40), S(-5, -119), S(-227, -208),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(1, 145), S(-19, 117), S(-11, 42), S(-3, 5), S(2, 6), S(38, 5), S(16, -7),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-319, -33), S(-36, 28), S(-30, 73), S(18, 85), S(37, 102), S(54, 102), S(31, 99),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(77, 4), S(145, 176), S(179, 269), S(207, 304), S(246, 321), S(270, 353), S(302, 351), S(332, 364), S(376, 293),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(96, 10), S(141, 177), S(193, 243), S(219, 290), S(244, 322), S(259, 347), S(267, 366), S(281, 376), S(288, 392), S(310, 377), S(321, 376), S(372, 325), S(379, 325), S(404, 292),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(326, 254), S(235, 424), S(260, 451), S(277, 461), S(287, 474), S(293, 486), S(298, 497), S(307, 498), S(312, 509), S(323, 510), S(334, 511), S(341, 516), S(347, 513), S(364, 485), S(442, 390),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(447, 126), S(594, 204), S(618, 323), S(637, 439), S(652, 485), S(661, 529), S(666, 562), S(673, 574), S(676, 598), S(679, 613), S(686, 618), S(689, 627), S(697, 623), S(699, 628), S(703, 624), S(702, 627), S(703, 625), S(710, 617), S(716, 610), S(721, 606), S(728, 585), S(748, 549), S(737, 557), S(741, 493), S(722, 493), S(721, 452), S(654, 499), S(678, 433),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(461, -217), S(103, -118), S(22, -25), S(9, 6), S(-8, 3), S(-14, 1), S(-16, 5), S(-33, 17), S(-29, 2),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -35), S(13, -24), S(12, -5), S(6, -11), S(2, -7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -23), S(5, -35), S(5, -21), S(5, -5), S(5, 20),
};

inline const PParam KS_FLANK_ATTACK = S(211, 92);
inline const PParam KS_FLANK_DEFENSE = S(189, 141);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(190, 126);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(166, -14);

inline const PParam PAWN_THREAT_KNIGHT = S(211, 92);
inline const PParam PAWN_THREAT_BISHOP = S(189, 141);
inline const PParam PAWN_THREAT_ROOK   = S(190, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(166, -14);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 69);
inline const PParam KNIGHT_THREAT_QUEEN  = S(155, -15);

inline const PParam BISHOP_THREAT_KNIGHT = S(106, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(178, 90);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -31), S(-2, -6), S(-4, -15), S(-7, -24), S(-11, -32), S(-15, -38), S(-17, -48), S(-23, -48), S(-38, -43),
};

inline const PParam ROOK_LINEUP = S(12, 69);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(326, 313),    S(169, 400),    S(302, 374),    S(311, 287),    S(330, 239),    S(218, 331),    S(148, 384),    S(273, 314),    //
    S(119, 215),    S(163, 234),    S(189, 176),    S(162, 136),    S(146, 112),    S(111, 171),    S(88, 221),     S(42, 244),     //
    S(91, 164),     S(80, 177),     S(114, 129),    S(107, 112),    S(97, 103),     S(69, 131),     S(22, 177),     S(10, 200),     //
    S(64, 115),     S(55, 146),     S(80, 118),     S(76, 112),     S(53, 113),     S(36, 134),     S(-20, 171),    S(-22, 162),    //
    S(60, 93),      S(97, 97),      S(78, 137),     S(70, 133),     S(43, 129),     S(18, 137),     S(-17, 155),    S(-23, 146),    //
    S(74, 92),      S(156, 112),    S(136, 159),    S(89, 167),     S(61, 153),     S(40, 142),     S(11, 161),     S(-7, 159),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-240, -108),  S(-161, 203),   S(-32, -36),    S(112, 197),    S(45, 195),     S(-99, 188),    S(-277, 266),   S(-309, -9),    //
    S(74, 167),     S(121, 187),    S(217, 156),    S(206, 181),    S(200, 188),    S(123, 201),    S(75, 203),     S(50, 190),     //
    S(159, 162),    S(199, 157),    S(217, 210),    S(212, 220),    S(173, 248),    S(116, 245),    S(119, 191),    S(87, 178),     //
    S(228, 188),    S(230, 215),    S(231, 235),    S(212, 273),    S(218, 273),    S(178, 253),    S(167, 223),    S(162, 197),    //
    S(208, 191),    S(248, 173),    S(219, 227),    S(212, 246),    S(190, 249),    S(189, 234),    S(184, 188),    S(145, 201),    //
    S(160, 148),    S(185, 163),    S(176, 197),    S(184, 219),    S(179, 220),    S(143, 199),    S(134, 171),    S(106, 140),    //
    S(167, 155),    S(181, 152),    S(155, 161),    S(158, 188),    S(151, 186),    S(123, 142),    S(105, 168),    S(91, 80),      //
    S(97, 99),      S(144, 164),    S(157, 136),    S(177, 137),    S(158, 160),    S(125, 130),    S(111, 151),    S(73, 56),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-5, 307),     S(-12, 303),    S(-303, 364),   S(-140, 301),   S(-133, 308),   S(-159, 310),   S(-48, 308),    S(31, 291),     //
    S(122, 217),    S(64, 293),     S(108, 240),    S(44, 274),     S(63, 271),     S(89, 262),     S(125, 261),    S(105, 234),    //
    S(182, 244),    S(200, 249),    S(198, 263),    S(170, 265),    S(142, 269),    S(148, 271),    S(167, 252),    S(153, 238),    //
    S(156, 233),    S(191, 243),    S(197, 263),    S(190, 304),    S(221, 290),    S(155, 264),    S(168, 232),    S(128, 229),    //
    S(188, 189),    S(206, 226),    S(211, 253),    S(214, 276),    S(191, 290),    S(175, 272),    S(145, 242),    S(141, 204),    //
    S(214, 198),    S(254, 211),    S(260, 238),    S(205, 266),    S(198, 246),    S(196, 252),    S(205, 232),    S(142, 229),    //
    S(178, 165),    S(278, 176),    S(235, 200),    S(205, 220),    S(185, 227),    S(192, 197),    S(191, 189),    S(181, 182),    //
    S(210, 166),    S(193, 197),    S(195, 219),    S(212, 193),    S(202, 203),    S(200, 242),    S(200, 218),    S(189, 189),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(424, 396),    S(433, 418),    S(430, 420),    S(438, 392),    S(416, 402),    S(384, 409),    S(383, 422),    S(372, 426),    //
    S(311, 476),    S(374, 479),    S(465, 438),    S(409, 449),    S(398, 456),    S(370, 459),    S(301, 490),    S(295, 487),    //
    S(279, 471),    S(385, 455),    S(441, 416),    S(415, 409),    S(368, 438),    S(327, 459),    S(328, 459),    S(268, 491),    //
    S(282, 438),    S(357, 445),    S(395, 418),    S(367, 418),    S(367, 417),    S(322, 450),    S(315, 449),    S(245, 475),    //
    S(262, 372),    S(326, 389),    S(315, 409),    S(299, 398),    S(281, 414),    S(268, 435),    S(236, 432),    S(216, 431),    //
    S(253, 318),    S(313, 346),    S(304, 365),    S(287, 360),    S(276, 367),    S(247, 399),    S(247, 374),    S(213, 381),    //
    S(145, 336),    S(278, 294),    S(289, 322),    S(281, 342),    S(268, 346),    S(257, 354),    S(242, 338),    S(217, 349),    //
    S(213, 308),    S(231, 334),    S(290, 326),    S(303, 319),    S(292, 327),    S(273, 344),    S(264, 339),    S(247, 346),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(489, 462),    S(554, 395),    S(483, 501),    S(461, 561),    S(449, 528),    S(470, 499),    S(482, 432),    S(431, 483),    //
    S(500, 502),    S(465, 594),    S(455, 622),    S(322, 704),    S(332, 683),    S(385, 646),    S(423, 531),    S(437, 507),    //
    S(464, 569),    S(518, 582),    S(458, 669),    S(406, 685),    S(380, 675),    S(433, 588),    S(467, 515),    S(477, 443),    //
    S(512, 468),    S(511, 564),    S(458, 619),    S(440, 659),    S(431, 661),    S(451, 555),    S(495, 482),    S(478, 451),    //
    S(526, 434),    S(510, 514),    S(487, 556),    S(456, 597),    S(456, 599),    S(458, 543),    S(477, 465),    S(501, 391),    //
    S(507, 373),    S(541, 418),    S(532, 486),    S(502, 482),    S(498, 472),    S(496, 489),    S(506, 419),    S(486, 392),    //
    S(484, 254),    S(527, 253),    S(529, 324),    S(539, 375),    S(527, 401),    S(522, 366),    S(483, 403),    S(492, 378),    //
    S(466, 264),    S(497, 100),    S(518, 133),    S(535, 242),    S(531, 325),    S(531, 267),    S(521, 284),    S(488, 320),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-179, -158),  S(178, 285),    S(102, 284),    S(-61, 214),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(112, 53),     S(253, 205),    S(159, 233),    S(119, 111),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(108, 106),    S(265, 152),    S(229, 156),    S(177, 82),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, 36),     S(232, 62),     S(156, 95),     S(139, 83),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-78, -34),    S(164, -8),     S(130, 36),     S(49, 86),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-30, -67),    S(174, -49),    S(100, 10),     S(57, 53),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(6, -84),      S(85, -43),     S(11, 4),       S(-43, 36),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-109, -117),  S(-12, -73),    S(-107, -35),   S(-97, -57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(10, 24), S(-5, 27), S(-9, 25), S(-2, -11), S(-3, -15), S(-9, 26), S(-4, 26), }},
  {{ S(2, 142), S(-23, 122), S(-19, 106), S(-9, 71), S(-9, 67), S(-18, 108), S(-21, 125), }},
  {{ S(-8, 112), S(-20, 103), S(-16, 80), S(-13, 52), S(-12, 49), S(-15, 79), S(-18, 102), }},
  {{ S(3, 114), S(-13, 59), S(-5, 70), S(-2, 65), S(-3, 63), S(-6, 68), S(-10, 68), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, 83), S(-16, -117), S(-14, 51), S(-7, 98), S(-8, 66),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 158), S(-13, 146), S(-12, 124), S(-11, 122), S(-12, 128), S(-11, 123), S(-13, 147), }},
  {{ S(-4, 48), S(-10, 32), S(-16, 24), S(-12, 1), S(-13, -10), S(-15, 12), S(-9, 30), }},
  {{ S(-9, 78), S(-13, 60), S(-14, 60), S(-11, 50), S(-10, 40), S(-15, 55), S(-13, 62), }},
  {{ S(-9, 79), S(-15, 72), S(-17, 55), S(-10, 49), S(-9, 53), S(-16, 59), S(-16, 71), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1387, 1642, -29, 134
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(234);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 8.89058s
// clang-format on
}  // namespace Clockwork
