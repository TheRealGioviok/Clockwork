#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 201);
inline const PParam KNIGHT_MAT = S(565, 614);
inline const PParam BISHOP_MAT = S(608, 645);
inline const PParam ROOK_MAT   = S(471, 676);
inline const PParam QUEEN_MAT  = S(1104, 1082);
inline const PParam TEMPO_VAL  = S(63, 11);

inline const PParam BISHOP_PAIR_VAL   = S(52, 196);
inline const PParam ROOK_OPEN_VAL     = S(106, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 20);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -69);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -37);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 2), S(38, 27), S(57, 51), S(135, 147), S(375, 207), S(460, 682),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 34), S(45, 26), S(54, 54), S(118, 140), S(407, 86),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -121), S(-69, -98), S(-47, 12), S(10, 119), S(93, 265), S(264, 378),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(35, -44), S(34, -5), S(22, 32), S(1, 109), S(48, 219), S(203, 279),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(22, -36), S(4, 11), S(2, -21), S(-1, -53), S(-8, -126), S(-212, -231),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-5, 148), S(-16, 112), S(-12, 45), S(-5, 9), S(1, 7), S(36, 7), S(9, 2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-306, -53), S(-42, 26), S(-25, 60), S(12, 97), S(31, 113), S(48, 115), S(30, 107),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(70, 4), S(140, 177), S(175, 266), S(203, 302), S(243, 320), S(268, 355), S(300, 352), S(331, 366), S(384, 280),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(90, 3), S(134, 175), S(188, 237), S(215, 282), S(240, 314), S(256, 338), S(263, 357), S(277, 367), S(283, 385), S(308, 366), S(319, 368), S(366, 318), S(365, 331), S(394, 279),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(313, 242), S(231, 421), S(256, 446), S(274, 455), S(285, 468), S(291, 479), S(297, 489), S(306, 491), S(312, 502), S(323, 503), S(335, 504), S(342, 509), S(347, 508), S(365, 480), S(450, 377),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(491, 510), S(631, 530), S(656, 638), S(675, 751), S(690, 797), S(699, 841), S(705, 873), S(712, 883), S(716, 907), S(720, 921), S(725, 929), S(730, 937), S(739, 930), S(741, 934), S(746, 930), S(744, 933), S(746, 929), S(752, 924), S(759, 914), S(769, 907), S(777, 883), S(799, 844), S(795, 844), S(792, 791), S(780, 778), S(771, 752), S(701, 811), S(728, 715),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(499, -203), S(107, -106), S(28, -25), S(16, 7), S(-4, 8), S(-20, 1), S(-26, 9), S(-40, 15), S(-27, -27),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(16, -15), S(13, -12), S(6, -8), S(2, 220),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 422),
};

inline const PParam PAWN_THREAT_KNIGHT = S(217, 84);
inline const PParam PAWN_THREAT_BISHOP = S(193, 137);
inline const PParam PAWN_THREAT_ROOK   = S(194, 118);
inline const PParam PAWN_THREAT_QUEEN  = S(172, -27);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 99);
inline const PParam KNIGHT_THREAT_ROOK   = S(230, 59);
inline const PParam KNIGHT_THREAT_QUEEN  = S(156, -13);

inline const PParam BISHOP_THREAT_KNIGHT = S(106, 55);
inline const PParam BISHOP_THREAT_ROOK   = S(215, 117);
inline const PParam BISHOP_THREAT_QUEEN  = S(180, 92);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -17), S(-9, -28), S(-14, -37), S(-18, -42), S(-21, -54), S(-28, -52), S(-39, -51),
};

inline const PParam ROOK_LINEUP = S(12, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(298, 341),    S(145, 443),    S(292, 410),    S(301, 279),    S(326, 230),    S(216, 318),    S(155, 353),    S(263, 309),    //
    S(118, 208),    S(148, 249),    S(188, 166),    S(173, 102),    S(153, 84),     S(125, 139),    S(99, 191),     S(50, 219),     //
    S(82, 171),     S(69, 174),     S(111, 100),    S(111, 79),     S(100, 76),     S(72, 108),     S(24, 157),     S(12, 186),     //
    S(57, 124),     S(47, 148),     S(83, 96),      S(80, 88),      S(58, 91),      S(41, 116),     S(-19, 159),    S(-19, 151),    //
    S(56, 99),      S(95, 106),     S(81, 136),     S(73, 121),     S(45, 118),     S(22, 124),     S(-13, 141),    S(-20, 135),    //
    S(69, 100),     S(159, 115),    S(144, 171),    S(95, 154),     S(66, 141),     S(46, 135),     S(16, 147),     S(-3, 150),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-251, -75),   S(-154, 198),   S(-96, 45),     S(95, 183),     S(30, 190),     S(-113, 190),   S(-246, 240),   S(-289, -5),    //
    S(75, 162),     S(119, 186),    S(203, 150),    S(198, 159),    S(197, 162),    S(111, 190),    S(74, 207),     S(49, 183),     //
    S(160, 158),    S(207, 152),    S(208, 210),    S(209, 195),    S(170, 229),    S(108, 246),    S(121, 190),    S(88, 180),     //
    S(228, 180),    S(236, 199),    S(232, 224),    S(220, 254),    S(220, 263),    S(176, 248),    S(169, 215),    S(162, 190),    //
    S(211, 184),    S(247, 166),    S(217, 223),    S(212, 243),    S(189, 247),    S(187, 232),    S(184, 181),    S(147, 189),    //
    S(156, 150),    S(182, 160),    S(172, 198),    S(181, 223),    S(176, 223),    S(140, 203),    S(130, 171),    S(101, 138),    //
    S(167, 154),    S(190, 149),    S(157, 159),    S(158, 183),    S(149, 181),    S(122, 138),    S(110, 159),    S(98, 74),      //
    S(102, 107),    S(147, 172),    S(164, 136),    S(180, 130),    S(161, 153),    S(129, 124),    S(113, 151),    S(75, 73),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-0, 291),     S(-18, 307),    S(-271, 341),   S(-142, 284),   S(-151, 302),   S(-164, 300),   S(-46, 294),    S(32, 270),     //
    S(121, 204),    S(62, 286),     S(96, 238),     S(43, 255),     S(59, 253),     S(84, 253),     S(121, 251),    S(97, 229),     //
    S(192, 233),    S(205, 245),    S(200, 252),    S(175, 253),    S(146, 249),    S(153, 259),    S(169, 248),    S(166, 221),    //
    S(163, 223),    S(198, 234),    S(199, 254),    S(197, 291),    S(227, 280),    S(157, 257),    S(169, 222),    S(127, 223),    //
    S(192, 180),    S(207, 215),    S(212, 239),    S(217, 266),    S(193, 282),    S(178, 261),    S(145, 238),    S(142, 195),    //
    S(218, 189),    S(250, 204),    S(262, 230),    S(207, 256),    S(203, 235),    S(197, 246),    S(205, 222),    S(145, 219),    //
    S(184, 162),    S(283, 181),    S(240, 195),    S(207, 212),    S(187, 216),    S(191, 191),    S(191, 190),    S(185, 183),    //
    S(215, 166),    S(202, 183),    S(201, 218),    S(215, 180),    S(205, 190),    S(205, 233),    S(202, 211),    S(193, 188),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(428, 378),    S(437, 401),    S(412, 415),    S(433, 375),    S(411, 383),    S(379, 392),    S(378, 405),    S(370, 410),    //
    S(302, 464),    S(377, 460),    S(455, 423),    S(401, 429),    S(383, 440),    S(363, 444),    S(298, 474),    S(280, 481),    //
    S(271, 459),    S(376, 441),    S(429, 407),    S(409, 394),    S(361, 423),    S(318, 447),    S(323, 441),    S(257, 481),    //
    S(275, 418),    S(353, 427),    S(390, 398),    S(362, 404),    S(352, 416),    S(313, 438),    S(310, 432),    S(234, 461),    //
    S(257, 351),    S(323, 368),    S(311, 389),    S(290, 386),    S(266, 411),    S(257, 422),    S(226, 418),    S(207, 413),    //
    S(249, 295),    S(311, 322),    S(297, 348),    S(283, 345),    S(270, 354),    S(244, 377),    S(241, 353),    S(206, 360),    //
    S(142, 305),    S(275, 271),    S(284, 302),    S(274, 325),    S(260, 329),    S(253, 332),    S(233, 321),    S(209, 329),    //
    S(206, 292),    S(229, 312),    S(286, 302),    S(298, 299),    S(287, 307),    S(267, 322),    S(256, 319),    S(236, 328),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(561, 635),    S(609, 591),    S(529, 721),    S(499, 785),    S(483, 770),    S(518, 712),    S(540, 634),    S(496, 668),    //
    S(558, 693),    S(518, 797),    S(507, 829),    S(362, 926),    S(374, 906),    S(436, 858),    S(481, 731),    S(493, 707),    //
    S(519, 764),    S(568, 781),    S(498, 889),    S(447, 908),    S(422, 903),    S(475, 816),    S(513, 733),    S(530, 658),    //
    S(558, 684),    S(562, 771),    S(500, 842),    S(491, 870),    S(485, 865),    S(494, 777),    S(537, 709),    S(523, 675),    //
    S(573, 651),    S(560, 724),    S(531, 779),    S(502, 821),    S(499, 825),    S(505, 764),    S(521, 688),    S(547, 615),    //
    S(554, 593),    S(588, 644),    S(579, 712),    S(549, 705),    S(545, 694),    S(540, 720),    S(555, 637),    S(534, 610),    //
    S(534, 483),    S(572, 496),    S(576, 563),    S(587, 601),    S(574, 626),    S(568, 591),    S(530, 632),    S(542, 608),    //
    S(516, 498),    S(549, 344),    S(572, 365),    S(586, 477),    S(582, 552),    S(581, 497),    S(568, 524),    S(537, 552),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-54, -325),   S(292, 174),    S(165, 132),    S(34, -29),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(230, -62),    S(349, 160),    S(206, 152),    S(126, 1),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(224, 30),     S(386, 102),    S(270, 107),    S(165, 6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(80, -2),      S(332, 42),     S(182, 64),     S(116, 29),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-26, -24),    S(231, 7),      S(157, 18),     S(40, 26),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -16),    S(210, -1),     S(112, 10),     S(60, -7),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-4, -18),     S(81, 35),      S(-3, 39),      S(-60, 14),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-117, -69),   S(-19, -23),    S(-119, -15),   S(-122, -85),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(15, -16), S(-3, 20), S(-7, 22), S(1, 7), S(1, 4), S(-7, 21), S(-1, 20), }},
  {{ S(5, -4), S(-23, 29), S(-19, 23), S(-10, 5), S(-9, 5), S(-18, 28), S(-22, 37), }},
  {{ S(-16, 3), S(-27, 28), S(-25, 9), S(-21, -4), S(-21, -3), S(-24, 9), S(-25, 24), }},
  {{ S(1, -14), S(-17, -14), S(-8, -18), S(-3, -22), S(-4, -20), S(-9, -16), S(-13, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(5, 26), S(-17, 33), S(-15, 22), S(-7, 9), S(-7, -7),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 4), S(-14, 12), S(-12, 10), S(-11, 11), S(-12, 5), S(-10, 1), S(-14, 10), }},
  {{ S(-2, 2), S(-10, 8), S(-17, 14), S(-14, 11), S(-13, 7), S(-16, 10), S(-10, 7), }},
  {{ S(-9, 7), S(-14, 4), S(-14, 11), S(-10, 11), S(-10, 10), S(-14, 9), S(-13, 5), }},
  {{ S(-9, 9), S(-14, 11), S(-15, 10), S(-10, 14), S(-9, 14), S(-14, 10), S(-16, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1179, 547, -29, 51
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-650);

// Epoch duration: 7.52381s
// clang-format on
}  // namespace Clockwork
