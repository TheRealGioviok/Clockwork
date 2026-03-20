#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(136, 203);
inline const PParam KNIGHT_MAT = S(569, 625);
inline const PParam BISHOP_MAT = S(613, 644);
inline const PParam ROOK_MAT   = S(466, 674);
inline const PParam QUEEN_MAT  = S(1095, 1085);
inline const PParam TEMPO_VAL  = S(57, 21);

inline const PParam BISHOP_PAIR_VAL   = S(53, 194);
inline const PParam ROOK_OPEN_VAL     = S(105, -3);
inline const PParam ROOK_SEMIOPEN_VAL = S(45, 24);
inline const PParam MINOR_BEHIND_PAWN = S(10, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-8, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(37, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 43);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(52, -24);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -0), S(38, 24), S(57, 48), S(133, 143), S(374, 201), S(450, 686),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 34), S(45, 27), S(54, 55), S(116, 143), S(403, 97),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-69, -125), S(-68, -99), S(-49, 11), S(4, 118), S(83, 269), S(260, 383),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -41), S(35, -2), S(24, 34), S(4, 113), S(51, 227), S(199, 295),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(23, -33), S(3, 19), S(4, -13), S(1, -44), S(-7, -120), S(-215, -240),
};

inline const PParam PASSED_TARRASH_RULE = S(16, 39);

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-7, 148), S(-19, 113), S(-16, 46), S(-8, 9), S(-1, 7), S(33, 7), S(7, 3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-309, -59), S(-43, 28), S(-27, 61), S(10, 98), S(29, 115), S(46, 115), S(30, 108),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(64, 6), S(134, 172), S(167, 262), S(194, 297), S(234, 314), S(258, 346), S(290, 342), S(320, 355), S(372, 269),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(78, -5), S(121, 170), S(176, 235), S(203, 280), S(228, 313), S(244, 336), S(252, 355), S(265, 366), S(272, 382), S(297, 364), S(307, 366), S(354, 316), S(353, 329), S(384, 277),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(315, 250), S(233, 423), S(258, 450), S(276, 460), S(286, 473), S(292, 483), S(298, 493), S(307, 495), S(312, 505), S(323, 506), S(335, 507), S(343, 511), S(349, 510), S(365, 483), S(449, 382),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(489, 522), S(632, 532), S(658, 644), S(676, 755), S(691, 802), S(699, 848), S(705, 879), S(713, 889), S(716, 914), S(720, 927), S(725, 935), S(729, 943), S(738, 936), S(740, 941), S(745, 936), S(743, 939), S(745, 936), S(751, 930), S(759, 920), S(768, 914), S(777, 890), S(800, 850), S(797, 849), S(794, 797), S(782, 783), S(773, 757), S(707, 814), S(732, 718),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(490, -184), S(108, -106), S(28, -24), S(15, 8), S(-5, 8), S(-21, 1), S(-27, 8), S(-43, 15), S(-31, -26),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(15, -15), S(13, -12), S(6, -8), S(2, 217),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -10), S(6, -9), S(5, -5), S(6, 413),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 91);
inline const PParam PAWN_THREAT_BISHOP = S(189, 141);
inline const PParam PAWN_THREAT_ROOK   = S(192, 123);
inline const PParam PAWN_THREAT_QUEEN  = S(167, -18);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 99);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 71);
inline const PParam KNIGHT_THREAT_QUEEN  = S(150, 3);

inline const PParam BISHOP_THREAT_KNIGHT = S(106, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 102);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -33), S(-3, -6), S(-5, -13), S(-8, -23), S(-12, -31), S(-16, -35), S(-18, -47), S(-25, -43), S(-36, -43),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(292, 348),    S(154, 447),    S(289, 418),    S(292, 288),    S(317, 241),    S(215, 326),    S(160, 359),    S(257, 313),    //
    S(117, 209),    S(151, 250),    S(188, 166),    S(173, 103),    S(155, 84),     S(128, 137),    S(101, 195),    S(49, 221),     //
    S(82, 173),     S(72, 176),     S(113, 102),    S(113, 81),     S(101, 78),     S(74, 111),     S(26, 161),     S(12, 188),     //
    S(57, 125),     S(48, 150),     S(82, 96),      S(80, 89),      S(58, 94),      S(40, 118),     S(-19, 162),    S(-20, 152),    //
    S(56, 99),      S(93, 107),     S(77, 136),     S(70, 122),     S(42, 118),     S(20, 126),     S(-14, 144),    S(-22, 137),    //
    S(67, 100),     S(157, 118),    S(141, 172),    S(91, 154),     S(62, 142),     S(41, 136),     S(13, 150),     S(-5, 150),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-252, -72),   S(-144, 191),   S(-95, 50),     S(107, 178),    S(34, 191),     S(-107, 192),   S(-242, 240),   S(-288, -2),    //
    S(76, 165),     S(121, 191),    S(212, 150),    S(205, 162),    S(202, 168),    S(114, 198),    S(80, 205),     S(50, 185),     //
    S(158, 147),    S(203, 151),    S(209, 211),    S(213, 200),    S(173, 236),    S(111, 247),    S(118, 188),    S(81, 178),     //
    S(228, 173),    S(235, 193),    S(234, 223),    S(220, 255),    S(220, 265),    S(178, 247),    S(168, 211),    S(162, 184),    //
    S(210, 178),    S(246, 165),    S(216, 223),    S(211, 241),    S(187, 246),    S(186, 232),    S(184, 179),    S(147, 182),    //
    S(158, 144),    S(183, 161),    S(172, 200),    S(179, 225),    S(175, 223),    S(140, 205),    S(131, 172),    S(102, 135),    //
    S(164, 147),    S(184, 142),    S(153, 158),    S(156, 183),    S(149, 183),    S(121, 138),    S(107, 153),    S(96, 68),      //
    S(96, 91),      S(144, 161),    S(158, 130),    S(176, 130),    S(157, 153),    S(125, 125),    S(110, 143),    S(70, 54),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-3, 300),     S(-18, 312),    S(-269, 345),   S(-141, 287),   S(-150, 309),   S(-162, 304),   S(-50, 305),    S(30, 276),     //
    S(118, 212),    S(63, 292),     S(95, 245),     S(46, 260),     S(59, 262),     S(81, 263),     S(120, 260),    S(95, 235),     //
    S(184, 226),    S(196, 245),    S(194, 252),    S(172, 256),    S(144, 253),    S(152, 255),    S(163, 246),    S(157, 217),    //
    S(157, 223),    S(192, 229),    S(194, 255),    S(192, 293),    S(222, 283),    S(154, 257),    S(164, 219),    S(125, 220),    //
    S(188, 176),    S(205, 214),    S(210, 239),    S(212, 266),    S(188, 281),    S(174, 260),    S(143, 235),    S(138, 191),    //
    S(213, 186),    S(248, 206),    S(257, 230),    S(201, 256),    S(196, 234),    S(191, 245),    S(201, 224),    S(140, 216),    //
    S(176, 152),    S(273, 170),    S(232, 191),    S(200, 212),    S(181, 216),    S(185, 190),    S(184, 182),    S(180, 176),    //
    S(208, 157),    S(196, 179),    S(193, 210),    S(210, 182),    S(200, 194),    S(199, 232),    S(196, 213),    S(187, 179),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(425, 382),    S(436, 403),    S(413, 416),    S(433, 375),    S(416, 377),    S(376, 393),    S(375, 406),    S(367, 411),    //
    S(302, 465),    S(377, 464),    S(451, 431),    S(400, 431),    S(384, 439),    S(363, 444),    S(298, 475),    S(280, 481),    //
    S(271, 459),    S(371, 449),    S(430, 409),    S(409, 395),    S(360, 424),    S(320, 446),    S(324, 441),    S(258, 481),    //
    S(275, 417),    S(351, 429),    S(386, 403),    S(361, 404),    S(352, 414),    S(313, 437),    S(309, 432),    S(234, 460),    //
    S(257, 351),    S(322, 368),    S(309, 390),    S(289, 386),    S(265, 411),    S(256, 423),    S(225, 419),    S(206, 415),    //
    S(248, 296),    S(310, 323),    S(296, 348),    S(281, 345),    S(269, 354),    S(243, 378),    S(241, 353),    S(207, 360),    //
    S(141, 306),    S(272, 273),    S(283, 303),    S(273, 324),    S(258, 330),    S(250, 335),    S(232, 323),    S(207, 333),    //
    S(205, 294),    S(228, 314),    S(285, 304),    S(297, 300),    S(286, 308),    S(265, 324),    S(255, 321),    S(235, 329),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(559, 646),    S(615, 591),    S(531, 727),    S(498, 794),    S(485, 772),    S(521, 712),    S(541, 637),    S(498, 667),    //
    S(557, 704),    S(522, 801),    S(511, 836),    S(369, 926),    S(374, 914),    S(440, 859),    S(484, 735),    S(492, 716),    //
    S(521, 771),    S(568, 792),    S(501, 898),    S(452, 910),    S(426, 905),    S(478, 822),    S(515, 740),    S(533, 662),    //
    S(560, 688),    S(563, 778),    S(501, 849),    S(492, 878),    S(486, 871),    S(497, 779),    S(539, 715),    S(527, 675),    //
    S(576, 653),    S(563, 726),    S(534, 781),    S(504, 825),    S(503, 826),    S(505, 773),    S(525, 689),    S(551, 614),    //
    S(556, 595),    S(591, 645),    S(579, 718),    S(551, 712),    S(547, 700),    S(542, 723),    S(557, 642),    S(535, 617),    //
    S(536, 486),    S(573, 501),    S(579, 564),    S(590, 604),    S(577, 630),    S(571, 596),    S(534, 634),    S(544, 612),    //
    S(519, 499),    S(551, 349),    S(573, 373),    S(588, 480),    S(583, 555),    S(581, 504),    S(571, 527),    S(539, 557),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-56, -326),   S(290, 177),    S(159, 137),    S(34, -32),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(236, -68),    S(353, 161),    S(206, 155),    S(121, 5),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(229, 27),     S(386, 106),    S(274, 106),    S(165, 7),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(85, -5),      S(339, 41),     S(184, 65),     S(120, 27),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -26),    S(236, 7),      S(163, 16),     S(46, 24),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -15),    S(213, -2),     S(116, 9),      S(65, -10),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-3, -16),     S(82, 38),      S(-2, 41),      S(-58, 15),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-116, -68),   S(-17, -22),    S(-119, -14),   S(-120, -87),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -20), S(-4, 16), S(-7, 18), S(0, 4), S(0, 0), S(-7, 17), S(-2, 17), }},
  {{ S(4, -7), S(-23, 27), S(-20, 20), S(-10, 2), S(-10, 2), S(-19, 24), S(-22, 34), }},
  {{ S(-11, -0), S(-22, 25), S(-20, 6), S(-16, -8), S(-16, -6), S(-20, 6), S(-20, 21), }},
  {{ S(0, -17), S(-18, -17), S(-9, -21), S(-4, -25), S(-5, -23), S(-10, -18), S(-13, -18), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(5, 24), S(-17, 32), S(-14, 22), S(-7, 10), S(-7, -6),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 5), S(-14, 13), S(-12, 11), S(-11, 12), S(-11, 6), S(-10, 2), S(-13, 11), }},
  {{ S(-2, 2), S(-10, 9), S(-17, 14), S(-14, 11), S(-13, 7), S(-15, 11), S(-9, 8), }},
  {{ S(-8, 7), S(-13, 5), S(-14, 12), S(-10, 11), S(-10, 10), S(-14, 10), S(-12, 5), }},
  {{ S(-9, 9), S(-14, 11), S(-15, 10), S(-10, 14), S(-8, 14), S(-14, 10), S(-15, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1196, 548, -35, 58
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(222);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 7.32358s
// clang-format on
}  // namespace Clockwork
