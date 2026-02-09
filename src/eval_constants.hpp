#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(139, 202);
inline const PParam KNIGHT_MAT = S(550, 610);
inline const PParam BISHOP_MAT = S(592, 643);
inline const PParam ROOK_MAT   = S(494, 705);
inline const PParam QUEEN_MAT  = S(1091, 1092);
inline const PParam TEMPO_VAL  = S(57, 22);

inline const PParam BISHOP_PAIR_VAL   = S(51, 198);
inline const PParam ROOK_OPEN_VAL     = S(94, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 24);
inline const std::array<PParam, 2> OPEN_FILE_ACCESS_VAL = {
    S(44, 19), S(46, 55),
};
inline const std::array<PParam, 2> SEMIOPEN_FILE_ACCESS_VAL = {
    S(4, -42), S(-4, -6),
};

inline const PParam DOUBLED_PAWN_VAL = S(-5, -69);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(36, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 40);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 53);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -35);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -1), S(37, 27), S(57, 52), S(135, 147), S(378, 205), S(450, 690),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(53, 35), S(43, 27), S(53, 56), S(117, 142), S(406, 90),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -124), S(-69, -100), S(-48, 11), S(8, 119), S(91, 269), S(261, 382),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(35, -43), S(34, -5), S(22, 32), S(-0, 110), S(45, 224), S(205, 284),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(22, -37), S(3, 10), S(2, -22), S(-2, -55), S(-9, -128), S(-208, -234),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-5, 151), S(-15, 114), S(-11, 45), S(-4, 10), S(1, 8), S(36, 8), S(10, 3),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-304, -54), S(-39, 27), S(-24, 62), S(13, 99), S(32, 116), S(49, 116), S(31, 110),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(74, 10), S(145, 182), S(179, 272), S(207, 309), S(247, 328), S(271, 363), S(303, 361), S(333, 376), S(387, 290),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(97, 5), S(140, 182), S(194, 244), S(222, 289), S(246, 322), S(262, 346), S(270, 366), S(284, 376), S(289, 394), S(315, 375), S(326, 377), S(374, 326), S(374, 337), S(402, 286),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(297, 258), S(218, 422), S(242, 444), S(259, 448), S(269, 457), S(275, 465), S(281, 473), S(289, 472), S(294, 482), S(305, 483), S(316, 485), S(324, 490), S(330, 489), S(348, 461), S(432, 359),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(500, 509), S(638, 538), S(662, 651), S(680, 762), S(695, 810), S(704, 854), S(710, 886), S(717, 896), S(721, 920), S(724, 934), S(730, 940), S(734, 949), S(744, 941), S(745, 948), S(750, 943), S(747, 948), S(750, 943), S(757, 936), S(764, 928), S(773, 921), S(783, 895), S(804, 857), S(800, 858), S(801, 801), S(788, 788), S(781, 758), S(717, 810), S(737, 720),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(496, -197), S(109, -104), S(28, -23), S(15, 11), S(-5, 9), S(-21, 1), S(-25, 8), S(-39, 13), S(-27, -30),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -7), S(16, -15), S(13, -12), S(6, -8), S(2, 188),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 402),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 95);
inline const PParam PAWN_THREAT_BISHOP = S(189, 145);
inline const PParam PAWN_THREAT_ROOK   = S(192, 119);
inline const PParam PAWN_THREAT_QUEEN  = S(166, -17);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 101);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 67);
inline const PParam KNIGHT_THREAT_QUEEN  = S(150, -1);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 98);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -37), S(-4, -9), S(-6, -18), S(-9, -28), S(-13, -37), S(-18, -43), S(-21, -55), S(-28, -53), S(-40, -53),
};

inline const PParam ROOK_LINEUP = S(12, 62);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(298, 347),    S(144, 447),    S(288, 415),    S(298, 284),    S(320, 236),    S(213, 322),    S(152, 359),    S(264, 313),    //
    S(117, 209),    S(145, 250),    S(185, 168),    S(170, 103),    S(150, 85),     S(123, 139),    S(96, 195),     S(47, 223),     //
    S(79, 174),     S(66, 176),     S(108, 102),    S(109, 80),     S(97, 76),      S(70, 108),     S(21, 158),     S(10, 188),     //
    S(55, 126),     S(44, 149),     S(81, 97),      S(77, 88),      S(55, 91),      S(39, 116),     S(-22, 160),    S(-21, 153),    //
    S(52, 99),      S(93, 106),     S(78, 136),     S(71, 122),     S(42, 118),     S(20, 124),     S(-15, 141),    S(-24, 135),    //
    S(64, 100),     S(155, 117),    S(139, 172),    S(92, 155),     S(63, 141),     S(43, 136),     S(13, 148),     S(-7, 149),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-238, -66),   S(-142, 204),   S(-93, 60),     S(101, 195),    S(37, 199),     S(-107, 201),   S(-244, 259),   S(-274, 1),     //
    S(82, 175),     S(127, 195),    S(212, 158),    S(208, 166),    S(208, 169),    S(121, 197),    S(84, 213),     S(57, 193),     //
    S(168, 168),    S(215, 163),    S(218, 216),    S(218, 201),    S(179, 235),    S(117, 253),    S(129, 199),    S(96, 189),     //
    S(237, 189),    S(244, 210),    S(240, 235),    S(228, 265),    S(229, 272),    S(184, 259),    S(176, 227),    S(170, 199),    //
    S(218, 196),    S(253, 179),    S(224, 234),    S(220, 254),    S(196, 259),    S(194, 243),    S(191, 193),    S(154, 200),    //
    S(163, 161),    S(189, 171),    S(179, 208),    S(188, 234),    S(184, 233),    S(148, 214),    S(137, 182),    S(109, 148),    //
    S(174, 165),    S(196, 162),    S(164, 170),    S(166, 193),    S(157, 192),    S(130, 148),    S(117, 171),    S(105, 83),     //
    S(112, 114),    S(155, 184),    S(172, 150),    S(189, 144),    S(170, 167),    S(138, 138),    S(123, 165),    S(84, 81),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(9, 301),      S(-8, 313),     S(-268, 353),   S(-136, 292),   S(-146, 312),   S(-159, 308),   S(-44, 308),    S(42, 278),     //
    S(128, 213),    S(67, 296),     S(103, 245),    S(49, 262),     S(66, 259),     S(90, 260),     S(126, 260),    S(104, 236),    //
    S(199, 240),    S(210, 253),    S(202, 263),    S(182, 261),    S(152, 257),    S(159, 266),    S(174, 257),    S(170, 229),    //
    S(168, 234),    S(204, 241),    S(206, 262),    S(202, 301),    S(231, 293),    S(164, 266),    S(174, 231),    S(133, 231),    //
    S(197, 190),    S(213, 224),    S(218, 248),    S(222, 278),    S(199, 291),    S(184, 270),    S(151, 248),    S(148, 202),    //
    S(223, 199),    S(257, 212),    S(267, 241),    S(212, 266),    S(208, 245),    S(203, 255),    S(210, 233),    S(150, 228),    //
    S(189, 169),    S(288, 190),    S(245, 204),    S(212, 222),    S(193, 225),    S(196, 202),    S(197, 198),    S(191, 190),    //
    S(222, 173),    S(209, 192),    S(207, 231),    S(223, 192),    S(212, 203),    S(213, 250),    S(208, 222),    S(200, 196),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(401, 366),    S(414, 386),    S(394, 397),    S(413, 360),    S(395, 364),    S(356, 379),    S(349, 395),    S(343, 395),    //
    S(287, 450),    S(366, 443),    S(440, 410),    S(388, 414),    S(372, 424),    S(350, 429),    S(284, 458),    S(261, 467),    //
    S(258, 448),    S(357, 434),    S(416, 392),    S(394, 382),    S(347, 410),    S(304, 433),    S(307, 428),    S(237, 473),    //
    S(263, 410),    S(339, 414),    S(374, 388),    S(348, 392),    S(337, 404),    S(297, 426),    S(293, 420),    S(219, 450),    //
    S(246, 343),    S(310, 354),    S(297, 376),    S(275, 373),    S(251, 398),    S(242, 409),    S(211, 404),    S(191, 406),    //
    S(239, 282),    S(299, 308),    S(284, 331),    S(268, 328),    S(255, 336),    S(228, 360),    S(227, 336),    S(191, 346),    //
    S(134, 289),    S(263, 253),    S(271, 282),    S(259, 303),    S(245, 309),    S(237, 313),    S(218, 301),    S(194, 312),    //
    S(200, 276),    S(223, 293),    S(275, 278),    S(286, 277),    S(275, 287),    S(255, 301),    S(244, 297),    S(224, 306),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(557, 650),    S(609, 596),    S(528, 727),    S(495, 795),    S(474, 786),    S(512, 724),    S(535, 645),    S(491, 681),    //
    S(556, 707),    S(518, 805),    S(507, 841),    S(367, 930),    S(374, 919),    S(435, 871),    S(479, 743),    S(489, 723),    //
    S(517, 776),    S(565, 795),    S(496, 904),    S(448, 917),    S(422, 913),    S(473, 830),    S(509, 751),    S(528, 671),    //
    S(557, 694),    S(560, 784),    S(497, 854),    S(490, 883),    S(481, 883),    S(492, 788),    S(535, 721),    S(521, 687),    //
    S(571, 662),    S(559, 733),    S(529, 790),    S(500, 833),    S(499, 832),    S(502, 778),    S(520, 698),    S(545, 624),    //
    S(550, 603),    S(585, 656),    S(577, 724),    S(547, 717),    S(545, 702),    S(538, 730),    S(552, 650),    S(531, 621),    //
    S(532, 489),    S(571, 503),    S(573, 572),    S(586, 610),    S(573, 635),    S(567, 601),    S(530, 639),    S(539, 618),    //
    S(516, 500),    S(548, 356),    S(571, 376),    S(587, 487),    S(581, 571),    S(581, 511),    S(568, 534),    S(536, 560),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-57, -328),   S(290, 174),    S(158, 134),    S(29, -27),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(231, -67),    S(348, 162),    S(202, 155),    S(120, 9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(226, 27),     S(383, 107),    S(267, 110),    S(164, 12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(86, -8),      S(335, 44),     S(180, 67),     S(118, 33),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -31),    S(234, 8),      S(156, 19),     S(41, 30),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -20),    S(214, -2),     S(111, 10),     S(60, -4),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-2, -22),     S(83, 36),      S(-8, 40),      S(-62, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-114, -75),   S(-14, -27),    S(-115, -19),   S(-117, -82),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(19, -17), S(1, 19), S(-2, 20), S(5, 5), S(5, 2), S(-2, 19), S(3, 19), }},
  {{ S(8, -6), S(-20, 27), S(-16, 20), S(-6, 2), S(-6, 3), S(-15, 25), S(-19, 34), }},
  {{ S(-5, 1), S(-17, 27), S(-15, 8), S(-11, -5), S(-10, -4), S(-14, 9), S(-15, 23), }},
  {{ S(4, -15), S(-14, -15), S(-5, -19), S(0, -23), S(-1, -21), S(-6, -17), S(-9, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(6, 27), S(-16, 33), S(-13, 22), S(-6, 11), S(-6, -7),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 5), S(-12, 14), S(-11, 11), S(-10, 12), S(-10, 6), S(-9, 2), S(-12, 12), }},
  {{ S(-1, 3), S(-9, 10), S(-16, 15), S(-13, 12), S(-12, 8), S(-14, 12), S(-9, 9), }},
  {{ S(-8, 8), S(-12, 6), S(-13, 12), S(-9, 12), S(-9, 11), S(-13, 10), S(-12, 6), }},
  {{ S(-8, 10), S(-13, 11), S(-14, 11), S(-9, 15), S(-7, 15), S(-13, 11), S(-15, 11), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1192, 565, -52, 53
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(140);
inline VParam WINNABLE_ASYM = V(128);
inline VParam WINNABLE_PAWN_ENDGAME = V(231);
inline VParam WINNABLE_BIAS = V(-673);

// Epoch duration: 7.39398s
// clang-format on
}  // namespace Clockwork
