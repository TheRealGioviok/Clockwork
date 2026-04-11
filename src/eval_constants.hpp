#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(143, 203);
inline const PParam KNIGHT_MAT = S(587, 603);
inline const PParam BISHOP_MAT = S(621, 614);
inline const PParam ROOK_MAT   = S(493, 663);
inline const PParam QUEEN_MAT  = S(1027, 1116);
inline const PParam TEMPO_VAL  = S(56, 19);

inline const PParam BISHOP_PAIR_VAL   = S(64, 197);
inline const PParam ROOK_OPEN_VAL     = S(97, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 25);
inline const PParam MINOR_BEHIND_PAWN = S(13, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-17, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -18);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -22);
inline const PParam OUTPOST_KNIGHT_VAL    = S(41, 59);
inline const PParam OUTPOST_BISHOP_VAL    = S(55, 36);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(40, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(44, -22);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(32, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(58, -39);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, 2), S(36, 26), S(59, 48), S(140, 141), S(357, 207), S(599, 632),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(51, 35), S(44, 25), S(59, 51), S(122, 141), S(400, 77),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -126), S(-71, -97), S(-41, 14), S(19, 117), S(111, 254), S(277, 376),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(27, -44), S(26, -2), S(20, 32), S(13, 113), S(80, 215), S(243, 267),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(13, -21), S(7, 19), S(2, -14), S(0, -44), S(-5, -136), S(-230, -229),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(8, 145), S(-8, 113), S(-6, 42), S(-2, 7), S(5, 8), S(40, 4), S(29, -11),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-277, -71), S(-31, 17), S(-18, 62), S(20, 94), S(40, 115), S(50, 122), S(33, 119),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(63, 11), S(139, 174), S(178, 264), S(208, 296), S(245, 313), S(270, 343), S(299, 338), S(328, 348), S(371, 253),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(86, 13), S(138, 172), S(188, 236), S(215, 281), S(239, 312), S(255, 336), S(264, 353), S(277, 361), S(285, 374), S(306, 354), S(315, 352), S(362, 291), S(359, 301), S(403, 230),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(326, 251), S(257, 418), S(281, 445), S(296, 455), S(306, 468), S(311, 480), S(317, 491), S(323, 494), S(328, 505), S(336, 508), S(344, 510), S(348, 516), S(353, 514), S(367, 483), S(438, 379),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(459, 484), S(604, 531), S(632, 663), S(655, 787), S(671, 834), S(682, 874), S(689, 905), S(696, 915), S(701, 936), S(705, 950), S(710, 954), S(714, 961), S(719, 957), S(721, 961), S(723, 958), S(720, 962), S(719, 960), S(722, 951), S(727, 940), S(726, 940), S(727, 921), S(737, 887), S(723, 897), S(711, 845), S(689, 838), S(681, 809), S(626, 838), S(628, 805),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(434, -207), S(70, -97), S(19, -21), S(7, 13), S(-9, 7), S(-10, -0), S(-18, 12), S(-37, 21), S(-22, -23),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, 149), S(14, 129), S(13, 131), S(5, 118), S(1, 63),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, 172), S(6, 134), S(4, 166), S(4, 147), S(5, 344),
};

inline const PParam KS_NO_QUEEN = S(-97, -407);

inline const PParam KS_FLANK_ATTACK = S(2, 117);
inline const PParam KS_FLANK_DEFENSE = S(-4, 152);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(5, 123);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-3, 128);

inline const PParam PAWN_THREAT_KNIGHT = S(207, 84);
inline const PParam PAWN_THREAT_BISHOP = S(195, 129);
inline const PParam PAWN_THREAT_ROOK   = S(194, 121);
inline const PParam PAWN_THREAT_QUEEN  = S(157, -14);

inline const PParam KNIGHT_THREAT_BISHOP = S(106, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(214, 69);
inline const PParam KNIGHT_THREAT_QUEEN  = S(140, -9);

inline const PParam BISHOP_THREAT_KNIGHT = S(101, 54);
inline const PParam BISHOP_THREAT_ROOK   = S(205, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(172, 82);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(6, -32), S(-4, -4), S(-6, -11), S(-9, -21), S(-13, -29), S(-17, -35), S(-19, -45), S(-25, -45), S(-38, -41),
};

inline const PParam ROOK_LINEUP = S(19, 71);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(312, 327),    S(157, 434),    S(288, 385),    S(278, 321),    S(317, 250),    S(235, 324),    S(177, 369),    S(284, 314),    //
    S(131, 202),    S(157, 244),    S(165, 193),    S(137, 150),    S(133, 116),    S(114, 160),    S(101, 207),    S(63, 228),     //
    S(98, 163),     S(87, 180),     S(115, 132),    S(101, 110),    S(95, 96),      S(78, 116),     S(37, 161),     S(31, 182),     //
    S(66, 116),     S(55, 151),     S(83, 120),     S(73, 113),     S(52, 110),     S(46, 124),     S(-5, 159),     S(-4, 149),     //
    S(62, 86),      S(93, 93),      S(82, 130),     S(71, 129),     S(43, 122),     S(29, 126),     S(-4, 143),     S(-7, 134),     //
    S(70, 89),      S(151, 103),    S(135, 147),    S(96, 162),     S(68, 147),     S(48, 132),     S(24, 148),     S(8, 149),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-192, -162),  S(-107, 181),   S(-128, 103),   S(137, 166),    S(67, 172),     S(-70, 189),    S(-221, 257),   S(-251, -51),   //
    S(91, 153),     S(120, 170),    S(208, 135),    S(215, 144),    S(216, 149),    S(148, 174),    S(96, 189),     S(78, 172),     //
    S(151, 148),    S(176, 134),    S(191, 198),    S(204, 195),    S(173, 228),    S(131, 229),    S(139, 162),    S(104, 161),    //
    S(222, 168),    S(230, 183),    S(227, 209),    S(221, 239),    S(228, 243),    S(191, 231),    S(184, 199),    S(176, 174),    //
    S(204, 167),    S(238, 143),    S(212, 204),    S(215, 221),    S(191, 228),    S(193, 218),    S(195, 164),    S(155, 185),    //
    S(148, 141),    S(161, 155),    S(159, 193),    S(175, 210),    S(169, 212),    S(140, 196),    S(136, 165),    S(109, 132),    //
    S(165, 145),    S(172, 140),    S(146, 151),    S(154, 177),    S(151, 175),    S(123, 131),    S(114, 154),    S(99, 64),      //
    S(97, 88),      S(148, 152),    S(159, 125),    S(175, 129),    S(161, 150),    S(128, 120),    S(120, 139),    S(78, 47),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(36, 284),     S(31, 287),     S(-228, 349),   S(-91, 287),    S(-97, 301),    S(-110, 291),   S(-12, 286),    S(58, 271),     //
    S(127, 209),    S(92, 284),     S(115, 235),    S(69, 255),     S(88, 251),     S(103, 254),    S(142, 247),    S(118, 226),    //
    S(184, 231),    S(183, 249),    S(189, 255),    S(170, 256),    S(151, 255),    S(162, 260),    S(176, 245),    S(170, 227),    //
    S(166, 217),    S(195, 225),    S(201, 250),    S(202, 291),    S(232, 277),    S(180, 248),    S(185, 214),    S(154, 216),    //
    S(193, 171),    S(200, 209),    S(215, 237),    S(222, 264),    S(204, 279),    S(198, 256),    S(172, 225),    S(165, 192),    //
    S(213, 183),    S(236, 200),    S(247, 228),    S(209, 253),    S(199, 236),    S(208, 242),    S(217, 224),    S(167, 211),    //
    S(174, 154),    S(263, 167),    S(228, 189),    S(208, 207),    S(190, 214),    S(197, 186),    S(198, 179),    S(193, 171),    //
    S(204, 156),    S(193, 190),    S(201, 210),    S(215, 186),    S(203, 196),    S(207, 231),    S(204, 208),    S(197, 177),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(417, 391),    S(451, 397),    S(413, 416),    S(419, 378),    S(453, 369),    S(416, 384),    S(428, 394),    S(406, 411),    //
    S(314, 467),    S(388, 460),    S(446, 426),    S(393, 440),    S(430, 427),    S(401, 433),    S(348, 463),    S(334, 471),    //
    S(276, 463),    S(378, 441),    S(413, 403),    S(390, 398),    S(389, 415),    S(353, 437),    S(359, 439),    S(304, 476),    //
    S(257, 435),    S(330, 433),    S(353, 408),    S(331, 412),    S(360, 401),    S(328, 433),    S(326, 436),    S(267, 462),    //
    S(234, 366),    S(299, 377),    S(290, 390),    S(273, 387),    S(282, 398),    S(275, 417),    S(250, 418),    S(235, 415),    //
    S(238, 304),    S(303, 324),    S(297, 338),    S(282, 337),    S(291, 342),    S(266, 374),    S(268, 354),    S(236, 362),    //
    S(149, 315),    S(276, 271),    S(282, 295),    S(278, 316),    S(282, 318),    S(271, 328),    S(261, 313),    S(237, 327),    //
    S(208, 292),    S(232, 314),    S(286, 300),    S(297, 295),    S(299, 303),    S(282, 320),    S(278, 313),    S(262, 321),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(545, 703),    S(614, 654),    S(546, 753),    S(514, 806),    S(539, 769),    S(541, 744),    S(561, 660),    S(503, 736),    //
    S(531, 753),    S(532, 843),    S(501, 863),    S(387, 930),    S(420, 933),    S(459, 895),    S(500, 786),    S(499, 770),    //
    S(496, 783),    S(521, 821),    S(483, 880),    S(435, 913),    S(443, 920),    S(493, 843),    S(523, 773),    S(529, 701),    //
    S(514, 661),    S(507, 752),    S(464, 814),    S(457, 861),    S(463, 891),    S(488, 793),    S(527, 726),    S(514, 704),    //
    S(520, 626),    S(504, 684),    S(488, 735),    S(471, 787),    S(480, 825),    S(493, 783),    S(510, 712),    S(528, 660),    //
    S(506, 575),    S(533, 596),    S(533, 665),    S(515, 676),    S(515, 703),    S(525, 733),    S(535, 687),    S(519, 664),    //
    S(475, 475),    S(509, 464),    S(523, 519),    S(544, 576),    S(538, 625),    S(538, 608),    S(514, 653),    S(527, 630),    //
    S(469, 479),    S(490, 315),    S(511, 346),    S(533, 458),    S(540, 548),    S(538, 501),    S(534, 524),    S(512, 562),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(32, -314),    S(364, 169),    S(280, 128),    S(185, -8),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(282, -44),    S(369, 166),    S(271, 152),    S(219, 31),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(205, 46),     S(282, 139),    S(228, 136),    S(191, 51),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(33, 9),       S(175, 76),     S(97, 108),     S(80, 105),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-91, -17),    S(30, 43),      S(-4, 84),      S(-63, 132),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-50, -40),    S(42, 10),      S(-20, 63),     S(-56, 104),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(8, -75),      S(45, -19),     S(-19, 28),     S(-76, 65),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-66, -138),   S(4, -80),      S(-76, -45),    S(-80, -61),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(28, 79), S(7, 51), S(7, 44), S(18, 2), S(17, 48), S(6, 91), S(9, 159), }},
  {{ S(12, 150), S(-18, 71), S(-10, 9), S(4, -4), S(4, 170), S(-9, 185), S(-17, 170), }},
  {{ S(10, 255), S(-5, 20), S(2, 41), S(9, 83), S(10, 161), S(2, 177), S(-3, 169), }},
  {{ S(18, 222), S(-1, 41), S(11, 56), S(16, 60), S(15, 141), S(9, 110), S(2, 144), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(0, 20), S(-23, 52), S(-20, -22), S(-11, 55), S(-6, -9),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-6, 25), S(-19, 141), S(-19, 116), S(-17, 124), S(-18, 41), S(-17, 28), S(-19, 27), }},
  {{ S(-3, 72), S(-10, 195), S(-21, 167), S(-18, 148), S(-19, -14), S(-20, 37), S(-10, 15), }},
  {{ S(-9, 161), S(-12, 167), S(-17, 138), S(-15, 175), S(-15, 36), S(-18, 36), S(-11, 4), }},
  {{ S(-10, 195), S(-17, 86), S(-21, 106), S(-15, 104), S(-14, 121), S(-21, -97), S(-19, -64), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1040, 486, -6, 208
);

inline VParam WINNABLE_PAWNS = V(-17);
inline VParam WINNABLE_SYM = V(153);
inline VParam WINNABLE_ASYM = V(138);
inline VParam WINNABLE_PAWN_ENDGAME = V(230);
inline VParam WINNABLE_BIAS = V(-716);

// Epoch duration: 9.5337s
// clang-format on
}  // namespace Clockwork
