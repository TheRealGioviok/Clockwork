#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(138, 201);
inline const PParam KNIGHT_MAT = S(581, 592);
inline const PParam BISHOP_MAT = S(619, 611);
inline const PParam ROOK_MAT   = S(482, 656);
inline const PParam QUEEN_MAT  = S(1016, 899);
inline const PParam TEMPO_VAL  = S(59, 18);

inline const PParam BISHOP_PAIR_VAL   = S(50, 197);
inline const PParam ROOK_OPEN_VAL     = S(108, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(41, 24);
inline const PParam MINOR_BEHIND_PAWN = S(11, 39);

inline const PParam DOUBLED_PAWN_VAL = S(-12, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -19);
inline const PParam OUTPOST_KNIGHT_VAL    = S(41, 54);
inline const PParam OUTPOST_BISHOP_VAL    = S(60, 30);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(50, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(30, 52);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, 2), S(37, 25), S(59, 47), S(141, 139), S(378, 208), S(573, 644),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(53, 35), S(45, 25), S(59, 49), S(121, 137), S(436, 70),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -127), S(-67, -100), S(-45, 13), S(9, 116), S(90, 261), S(272, 370),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(33, -44), S(28, -0), S(19, 33), S(7, 110), S(73, 209), S(244, 269),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(17, -24), S(7, 18), S(4, -16), S(4, -43), S(3, -130), S(-234, -223),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-1, 145), S(-18, 113), S(-12, 44), S(-3, 8), S(6, 9), S(43, 7), S(32, -7),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-280, -72), S(-24, 14), S(-22, 60), S(13, 94), S(34, 115), S(44, 122), S(27, 117),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(76, 6), S(143, 172), S(177, 263), S(206, 296), S(245, 312), S(269, 343), S(300, 340), S(331, 351), S(386, 260),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(101, 2), S(143, 167), S(192, 231), S(216, 276), S(240, 308), S(254, 332), S(263, 348), S(276, 357), S(284, 370), S(308, 352), S(318, 351), S(377, 289), S(376, 296), S(434, 228),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(333, 245), S(243, 410), S(266, 439), S(281, 449), S(291, 462), S(296, 474), S(301, 485), S(307, 489), S(312, 499), S(320, 502), S(329, 504), S(333, 510), S(339, 508), S(358, 477), S(449, 372),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(470, 354), S(609, 442), S(633, 558), S(652, 667), S(666, 712), S(673, 754), S(678, 783), S(685, 794), S(688, 815), S(690, 831), S(695, 834), S(698, 842), S(705, 838), S(707, 840), S(709, 838), S(706, 840), S(704, 840), S(710, 829), S(715, 819), S(716, 815), S(718, 797), S(732, 763), S(718, 770), S(708, 719), S(688, 713), S(683, 678), S(622, 710), S(630, 676),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(482, -165), S(86, -81), S(21, -7), S(7, 20), S(-11, 12), S(-11, -1), S(-13, 4), S(-35, 12), S(-15, -31),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, 19), S(16, 20), S(15, 19), S(6, 9), S(1, 7),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, 6), S(7, 7), S(4, 6), S(5, 5), S(5, 422),
};

inline const PParam KS_NO_QUEEN = S(-617, -1056);

inline const PParam KS_FLANK_ATTACK = S(2, 13);
inline const PParam KS_FLANK_DEFENSE = S(-5, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(5, 13);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-4, -3);

inline const PParam PAWN_THREAT_KNIGHT = S(219, 84);
inline const PParam PAWN_THREAT_BISHOP = S(200, 130);
inline const PParam PAWN_THREAT_ROOK   = S(199, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(173, -13);

inline const PParam KNIGHT_THREAT_BISHOP = S(105, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 69);
inline const PParam KNIGHT_THREAT_QUEEN  = S(153, -12);

inline const PParam BISHOP_THREAT_KNIGHT = S(104, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(177, 86);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -33), S(-3, -5), S(-5, -12), S(-8, -22), S(-11, -30), S(-15, -36), S(-16, -46), S(-23, -46), S(-39, -40),
};

inline const PParam ROOK_LINEUP = S(13, 72);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(311, 325),    S(140, 434),    S(283, 385),    S(270, 325),    S(321, 249),    S(222, 326),    S(162, 362),    S(278, 310),    //
    S(134, 193),    S(163, 235),    S(175, 181),    S(145, 140),    S(144, 105),    S(118, 150),    S(100, 197),    S(51, 223),     //
    S(96, 162),     S(82, 180),     S(120, 128),    S(107, 102),    S(99, 92),      S(76, 117),     S(25, 163),     S(16, 183),     //
    S(62, 119),     S(45, 157),     S(82, 119),     S(72, 109),     S(48, 109),     S(39, 124),     S(-23, 163),    S(-20, 149),    //
    S(61, 87),      S(94, 99),      S(79, 131),     S(66, 128),     S(36, 123),     S(20, 125),     S(-21, 146),    S(-22, 134),    //
    S(69, 89),      S(157, 106),    S(135, 147),    S(89, 162),     S(59, 149),     S(39, 132),     S(10, 151),     S(-7, 149),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-199, -155),  S(-134, 183),   S(-153, 106),   S(128, 173),    S(56, 175),     S(-93, 191),    S(-263, 258),   S(-277, -38),   //
    S(87, 150),     S(115, 175),    S(216, 134),    S(224, 140),    S(225, 145),    S(147, 175),    S(89, 193),     S(71, 174),     //
    S(153, 145),    S(183, 126),    S(194, 187),    S(212, 180),    S(174, 215),    S(123, 228),    S(138, 161),    S(102, 159),    //
    S(228, 170),    S(236, 182),    S(229, 209),    S(223, 239),    S(226, 249),    S(185, 238),    S(182, 203),    S(176, 179),    //
    S(208, 174),    S(247, 148),    S(215, 209),    S(213, 229),    S(186, 238),    S(190, 226),    S(197, 170),    S(153, 191),    //
    S(150, 144),    S(163, 158),    S(158, 196),    S(172, 215),    S(164, 220),    S(136, 201),    S(134, 169),    S(109, 136),    //
    S(166, 151),    S(175, 143),    S(146, 157),    S(154, 181),    S(149, 180),    S(123, 136),    S(112, 157),    S(101, 72),     //
    S(98, 96),      S(148, 156),    S(163, 132),    S(180, 135),    S(163, 154),    S(130, 124),    S(119, 142),    S(81, 52),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(6, 291),      S(6, 289),      S(-283, 350),   S(-124, 285),   S(-129, 296),   S(-149, 292),   S(-43, 293),    S(31, 279),     //
    S(120, 205),    S(74, 282),     S(107, 229),    S(52, 251),     S(75, 244),     S(87, 258),     S(130, 251),    S(105, 233),    //
    S(182, 229),    S(178, 242),    S(184, 247),    S(163, 249),    S(143, 250),    S(152, 258),    S(169, 248),    S(163, 230),    //
    S(161, 217),    S(193, 222),    S(199, 245),    S(197, 284),    S(230, 271),    S(174, 248),    S(182, 215),    S(145, 223),    //
    S(195, 172),    S(198, 212),    S(212, 240),    S(218, 266),    S(195, 283),    S(191, 259),    S(166, 227),    S(162, 193),    //
    S(215, 183),    S(239, 201),    S(247, 230),    S(204, 255),    S(195, 238),    S(204, 244),    S(217, 223),    S(163, 212),    //
    S(177, 153),    S(269, 171),    S(230, 192),    S(206, 210),    S(186, 217),    S(197, 189),    S(199, 181),    S(194, 173),    //
    S(207, 161),    S(192, 193),    S(199, 213),    S(217, 188),    S(202, 199),    S(204, 232),    S(202, 212),    S(198, 178),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(422, 378),    S(461, 389),    S(423, 402),    S(417, 375),    S(467, 358),    S(424, 375),    S(436, 384),    S(410, 400),    //
    S(303, 461),    S(389, 454),    S(453, 420),    S(393, 431),    S(435, 423),    S(403, 430),    S(338, 463),    S(322, 470),    //
    S(263, 459),    S(381, 436),    S(420, 400),    S(395, 393),    S(389, 418),    S(349, 437),    S(353, 441),    S(291, 476),    //
    S(241, 437),    S(324, 436),    S(352, 410),    S(327, 415),    S(354, 413),    S(317, 442),    S(315, 443),    S(249, 468),    //
    S(220, 373),    S(292, 383),    S(281, 395),    S(260, 396),    S(269, 409),    S(259, 428),    S(235, 425),    S(217, 423),    //
    S(228, 315),    S(300, 333),    S(291, 350),    S(274, 348),    S(283, 356),    S(252, 387),    S(257, 366),    S(222, 372),    //
    S(127, 332),    S(272, 284),    S(277, 309),    S(271, 329),    S(276, 330),    S(263, 341),    S(253, 325),    S(225, 339),    //
    S(195, 306),    S(219, 329),    S(280, 314),    S(293, 307),    S(294, 317),    S(274, 334),    S(271, 326),    S(253, 333),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(522, 595),    S(605, 548),    S(524, 650),    S(482, 708),    S(506, 682),    S(512, 649),    S(545, 558),    S(472, 634),    //
    S(503, 642),    S(498, 736),    S(461, 765),    S(333, 830),    S(367, 838),    S(412, 795),    S(467, 683),    S(467, 667),    //
    S(467, 673),    S(488, 718),    S(437, 790),    S(380, 825),    S(392, 830),    S(454, 750),    S(491, 678),    S(508, 598),    //
    S(498, 551),    S(479, 651),    S(423, 720),    S(410, 768),    S(414, 799),    S(454, 695),    S(502, 627),    S(493, 596),    //
    S(507, 516),    S(481, 582),    S(457, 636),    S(433, 690),    S(435, 737),    S(455, 689),    S(483, 616),    S(510, 554),    //
    S(495, 465),    S(523, 485),    S(514, 559),    S(492, 574),    S(488, 604),    S(495, 638),    S(512, 589),    S(500, 560),    //
    S(472, 359),    S(508, 349),    S(517, 408),    S(535, 468),    S(523, 519),    S(524, 504),    S(493, 552),    S(510, 527),    //
    S(463, 367),    S(494, 220),    S(517, 243),    S(534, 347),    S(531, 445),    S(535, 393),    S(528, 419),    S(501, 457),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(15, -337),    S(321, 163),    S(273, 112),    S(187, -19),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(256, -61),    S(319, 163),    S(239, 142),    S(199, 9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(176, 28),     S(240, 132),    S(196, 121),    S(143, 37),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-3, -4),      S(137, 68),     S(45, 95),      S(-1, 97),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-116, -20),   S(-2, 48),      S(-61, 82),     S(-145, 132),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -38),    S(28, 24),      S(-48, 65),     S(-92, 102),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(19, -67),     S(45, 3),       S(-25, 39),     S(-89, 73),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-50, -140),   S(19, -74),     S(-68, -46),    S(-71, -64),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(30, 117), S(9, 115), S(8, 126), S(20, 140), S(19, 134), S(7, 130), S(11, 126), }},
  {{ S(11, 90), S(-21, 96), S(-12, 100), S(2, 108), S(3, 105), S(-11, 108), S(-19, 102), }},
  {{ S(14, 113), S(-2, 120), S(5, 124), S(13, 128), S(14, 131), S(6, 128), S(1, 125), }},
  {{ S(19, 104), S(-2, 106), S(11, 106), S(17, 105), S(16, 105), S(9, 109), S(2, 119), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, 161), S(-22, 94), S(-20, 83), S(-10, 74), S(-5, 90),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-4, 86), S(-19, 91), S(-18, 83), S(-16, 96), S(-17, 95), S(-17, 86), S(-19, 88), }},
  {{ S(-1, 99), S(-9, 90), S(-21, 73), S(-17, 85), S(-18, 85), S(-19, 77), S(-9, 90), }},
  {{ S(-7, 75), S(-10, 92), S(-17, 83), S(-14, 93), S(-13, 97), S(-17, 84), S(-10, 91), }},
  {{ S(-7, 55), S(-17, 81), S(-21, 62), S(-15, 86), S(-13, 93), S(-20, 69), S(-19, 74), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1000, 536, 6, 166
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(126);
inline VParam WINNABLE_PAWN_ENDGAME = V(215);
inline VParam WINNABLE_BIAS = V(-657);

// Epoch duration: 10.156s
// clang-format on
}  // namespace Clockwork
