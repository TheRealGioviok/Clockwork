#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(141, 192);
inline const PParam KNIGHT_MAT = S(589, 596);
inline const PParam BISHOP_MAT = S(630, 618);
inline const PParam ROOK_MAT   = S(494, 642);
inline const PParam QUEEN_MAT  = S(1157, 1017);
inline const PParam TEMPO_VAL  = S(59, 19);

inline const PParam BISHOP_PAIR_VAL   = S(54, 191);
inline const PParam ROOK_OPEN_VAL     = S(106, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 22);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -66);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -20);

inline const PParam POTENTIAL_CHECKER_VAL = S(-51, -21);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 64);
inline const PParam OUTPOST_BISHOP_VAL    = S(50, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(28, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(69, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -1), S(40, 24), S(58, 49), S(136, 149), S(352, 253), S(439, 742),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(56, 32), S(46, 24), S(55, 51), S(120, 142), S(418, 80),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -111), S(-75, -88), S(-48, 17), S(13, 118), S(102, 260), S(282, 358),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(34, -41), S(32, 0), S(20, 41), S(2, 114), S(57, 213), S(206, 278),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(23, -47), S(6, 3), S(0, -23), S(-7, -48), S(-18, -113), S(-227, -211),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-4, 149), S(-15, 116), S(-10, 46), S(-4, 10), S(0, 8), S(33, 7), S(4, 4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-321, -41), S(-43, 23), S(-25, 59), S(13, 100), S(34, 119), S(54, 120), S(34, 118),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(68, -4), S(139, 166), S(174, 253), S(202, 288), S(243, 305), S(267, 338), S(300, 336), S(331, 350), S(383, 267),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(90, -2), S(133, 167), S(189, 228), S(216, 271), S(241, 302), S(257, 324), S(265, 344), S(279, 353), S(285, 370), S(310, 354), S(322, 354), S(370, 303), S(372, 312), S(393, 278),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(315, 236), S(236, 411), S(261, 434), S(279, 443), S(290, 456), S(296, 466), S(303, 476), S(312, 477), S(318, 487), S(330, 488), S(342, 489), S(351, 491), S(357, 490), S(373, 464), S(477, 344),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(502, 525), S(657, 497), S(682, 608), S(700, 720), S(716, 767), S(725, 810), S(731, 841), S(738, 851), S(742, 876), S(745, 888), S(752, 892), S(756, 900), S(765, 894), S(769, 897), S(773, 893), S(773, 893), S(775, 891), S(783, 880), S(791, 870), S(797, 870), S(808, 842), S(833, 799), S(826, 806), S(827, 746), S(812, 739), S(806, 711), S(739, 776), S(762, 672),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(480, -171), S(105, -105), S(27, -23), S(14, 8), S(-5, 7), S(-21, 2), S(-23, 5), S(-37, 12), S(-24, -31),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -7), S(15, -16), S(13, -12), S(6, -8), S(2, 180),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 416),
};

inline const PParam PAWN_THREAT_KNIGHT = S(216, 87);
inline const PParam PAWN_THREAT_BISHOP = S(193, 139);
inline const PParam PAWN_THREAT_ROOK   = S(196, 117);
inline const PParam PAWN_THREAT_QUEEN  = S(176, -37);

inline const PParam KNIGHT_THREAT_BISHOP = S(113, 95);
inline const PParam KNIGHT_THREAT_ROOK   = S(233, 56);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -7);

inline const PParam BISHOP_THREAT_KNIGHT = S(107, 55);
inline const PParam BISHOP_THREAT_ROOK   = S(217, 116);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 93);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -32), S(-3, -10), S(-6, -18), S(-9, -27), S(-14, -36), S(-18, -42), S(-21, -53), S(-28, -50), S(-39, -50),
};

inline const PParam ROOK_LINEUP = S(11, 72);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(318, 324),    S(168, 421),    S(300, 404),    S(312, 269),    S(334, 224),    S(229, 306),    S(169, 339),    S(269, 303),    //
    S(122, 202),    S(152, 237),    S(194, 155),    S(176, 95),     S(155, 78),     S(129, 129),    S(101, 184),    S(54, 213),     //
    S(83, 168),     S(70, 169),     S(112, 100),    S(112, 80),     S(100, 78),     S(72, 108),     S(25, 154),     S(14, 183),     //
    S(56, 126),     S(47, 145),     S(82, 100),     S(80, 90),      S(58, 93),      S(42, 116),     S(-18, 157),    S(-17, 150),    //
    S(55, 101),     S(96, 105),     S(80, 138),     S(73, 123),     S(45, 118),     S(23, 123),     S(-11, 139),    S(-19, 135),    //
    S(69, 102),     S(162, 112),    S(146, 169),    S(96, 151),     S(67, 140),     S(47, 133),     S(18, 144),     S(-1, 149),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-263, -64),   S(-142, 183),   S(-139, 90),    S(96, 180),     S(39, 176),     S(-118, 199),   S(-230, 214),   S(-300, 4),     //
    S(70, 167),     S(120, 180),    S(204, 146),    S(190, 168),    S(183, 180),    S(112, 188),    S(74, 205),     S(53, 175),     //
    S(165, 149),    S(197, 169),    S(210, 205),    S(204, 201),    S(172, 224),    S(112, 239),    S(122, 188),    S(88, 178),     //
    S(231, 174),    S(239, 194),    S(236, 216),    S(223, 248),    S(224, 254),    S(179, 241),    S(171, 210),    S(167, 179),    //
    S(214, 178),    S(247, 163),    S(219, 216),    S(216, 235),    S(192, 241),    S(189, 226),    S(188, 174),    S(150, 181),    //
    S(158, 147),    S(185, 153),    S(175, 191),    S(184, 217),    S(180, 214),    S(144, 196),    S(133, 165),    S(103, 135),    //
    S(169, 150),    S(192, 144),    S(160, 154),    S(163, 175),    S(153, 175),    S(125, 133),    S(110, 158),    S(98, 76),      //
    S(103, 105),    S(150, 165),    S(167, 131),    S(183, 124),    S(164, 145),    S(131, 120),    S(115, 145),    S(76, 72),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-1, 292),     S(-7, 299),     S(-279, 356),   S(-149, 293),   S(-159, 316),   S(-178, 320),   S(-53, 307),    S(24, 285),     //
    S(126, 200),    S(69, 282),     S(96, 243),     S(36, 271),     S(51, 269),     S(81, 261),     S(122, 253),    S(105, 223),    //
    S(197, 230),    S(206, 248),    S(204, 251),    S(179, 252),    S(150, 248),    S(156, 259),    S(175, 244),    S(170, 217),    //
    S(167, 220),    S(203, 228),    S(201, 255),    S(201, 287),    S(232, 274),    S(161, 255),    S(173, 220),    S(134, 217),    //
    S(195, 179),    S(212, 210),    S(217, 235),    S(223, 260),    S(199, 275),    S(183, 255),    S(150, 233),    S(145, 196),    //
    S(221, 189),    S(257, 197),    S(268, 225),    S(213, 250),    S(209, 229),    S(203, 240),    S(211, 216),    S(148, 218),    //
    S(189, 159),    S(289, 176),    S(246, 189),    S(212, 209),    S(192, 211),    S(197, 186),    S(196, 187),    S(190, 180),    //
    S(220, 162),    S(208, 181),    S(207, 212),    S(223, 172),    S(211, 186),    S(211, 226),    S(208, 206),    S(198, 184),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(431, 376),    S(457, 383),    S(426, 402),    S(443, 368),    S(420, 378),    S(387, 388),    S(384, 403),    S(374, 409),    //
    S(310, 458),    S(393, 447),    S(469, 410),    S(415, 417),    S(393, 433),    S(381, 428),    S(307, 467),    S(286, 477),    //
    S(278, 454),    S(381, 439),    S(438, 399),    S(421, 384),    S(373, 413),    S(331, 434),    S(332, 436),    S(264, 476),    //
    S(284, 415),    S(363, 420),    S(397, 395),    S(375, 394),    S(365, 406),    S(328, 425),    S(323, 421),    S(245, 453),    //
    S(266, 348),    S(334, 359),    S(322, 381),    S(301, 378),    S(281, 399),    S(270, 414),    S(237, 412),    S(217, 408),    //
    S(257, 292),    S(321, 316),    S(308, 340),    S(294, 337),    S(279, 349),    S(256, 368),    S(249, 350),    S(213, 359),    //
    S(152, 300),    S(283, 268),    S(294, 297),    S(285, 317),    S(270, 322),    S(259, 331),    S(245, 312),    S(218, 325),    //
    S(213, 291),    S(236, 312),    S(294, 300),    S(307, 296),    S(295, 305),    S(275, 320),    S(264, 316),    S(244, 325),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(567, 612),    S(619, 561),    S(545, 684),    S(510, 758),    S(498, 737),    S(523, 693),    S(550, 608),    S(494, 661),    //
    S(565, 673),    S(531, 767),    S(513, 813),    S(374, 900),    S(380, 887),    S(445, 834),    S(484, 719),    S(501, 686),    //
    S(528, 741),    S(570, 771),    S(516, 851),    S(456, 887),    S(430, 881),    S(478, 805),    S(521, 712),    S(540, 633),    //
    S(571, 649),    S(575, 740),    S(510, 816),    S(500, 848),    S(488, 856),    S(501, 757),    S(552, 672),    S(532, 653),    //
    S(583, 624),    S(574, 689),    S(542, 752),    S(514, 791),    S(510, 797),    S(510, 750),    S(533, 659),    S(557, 588),    //
    S(564, 566),    S(598, 619),    S(592, 680),    S(559, 680),    S(556, 667),    S(551, 690),    S(566, 611),    S(544, 583),    //
    S(544, 458),    S(584, 466),    S(590, 528),    S(600, 572),    S(584, 603),    S(578, 568),    S(543, 600),    S(553, 581),    //
    S(528, 468),    S(558, 326),    S(583, 344),    S(597, 456),    S(593, 528),    S(592, 474),    S(580, 497),    S(546, 533),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-72, -351),   S(285, 195),    S(183, 115),    S(51, -51),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(255, -98),    S(352, 177),    S(195, 172),    S(144, -19),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(250, 10),     S(400, 89),     S(292, 86),     S(189, -19),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(97, -16),     S(346, 32),     S(187, 56),     S(118, 23),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -26),    S(240, 2),      S(154, 19),     S(28, 33),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -16),    S(214, -3),     S(108, 14),     S(58, -2),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-2, -17),     S(81, 36),      S(-7, 43),      S(-63, 21),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-115, -69),   S(-17, -22),    S(-120, -12),   S(-122, -79),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(13, -17), S(-5, 19), S(-8, 21), S(-2, 7), S(-1, 3), S(-8, 20), S(-3, 20), }},
  {{ S(2, -6), S(-25, 27), S(-21, 21), S(-12, 4), S(-12, 4), S(-20, 27), S(-24, 36), }},
  {{ S(-12, 2), S(-23, 28), S(-22, 9), S(-18, -4), S(-18, -3), S(-21, 10), S(-22, 25), }},
  {{ S(-1, -14), S(-19, -14), S(-10, -17), S(-5, -21), S(-6, -19), S(-11, -14), S(-15, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-1, 230), S(-20, 32), S(-17, 21), S(-10, 9), S(-10, -8),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-7, 4), S(-17, 13), S(-15, 10), S(-14, 10), S(-14, 5), S(-13, 2), S(-16, 9), }},
  {{ S(-5, 3), S(-13, 9), S(-20, 14), S(-17, 12), S(-16, 7), S(-19, 11), S(-13, 8), }},
  {{ S(-12, 6), S(-16, 4), S(-17, 10), S(-13, 10), S(-13, 8), S(-17, 9), S(-16, 5), }},
  {{ S(-12, 8), S(-18, 10), S(-18, 10), S(-14, 13), S(-12, 14), S(-18, 10), S(-19, 9), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1208, 552, -19, 55
);

inline VParam WINNABLE_PAWNS = V(47);
inline VParam WINNABLE_PAWN_ENDGAME = V(169);
inline VParam WINNABLE_BIAS = V(-460);
// Epoch duration: 7.46582s
// clang-format on
}  // namespace Clockwork
