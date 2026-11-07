#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(112, 289);
inline const PParam KNIGHT_MAT = S(570, 1083);
inline const PParam BISHOP_MAT = S(521, 1026);
inline const PParam ROOK_MAT   = S(395, 1097);
inline const PParam QUEEN_MAT  = S(856, 1912);

inline const PParam TEMPO_VAL  = S(72, 60);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -4);
inline const PParam BISHOP_PAIR_VAL   = S(65, 242);
inline const PParam ROOK_OPEN_VAL     = S(115, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(48, 10);
inline const PParam MINOR_BEHIND_PAWN = S(16, 45);
inline const PParam RESTRICTED_SQUARES = S(20, 5);
inline const PParam SPACE_VAL = S(96, -106);

inline const PParam DOUBLED_PAWN_VAL = S(-16, -90);
inline const PParam ISOLATED_PAWN_VAL = S(-12, -43);

inline const PParam POTENTIAL_CHECKER_VAL = S(-43, -50);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 46);
inline const PParam OUTPOST_BISHOP_VAL    = S(43, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 53);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 2);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 66);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(61, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, -13), S(40, 24), S(52, 78), S(116, 225), S(403, 453), S(870, 985),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 23), S(42, 22), S(41, 73), S(84, 188), S(399, 137),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -186), S(-73, -143), S(-38, -19), S(8, 102), S(92, 329), S(235, 546),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-62, 51), S(-63, 25), S(-48, 93), S(-84, 215), S(-33, 292), S(92, 186),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(3, 54), S(-3, 46), S(-58, 103), S(-10, 108), S(110, 98), S(40, 189),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -34), S(17, 8), S(10, 43), S(27, 94), S(92, 232), S(415, 116),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(6, -27), S(-1, 12), S(-8, -26), S(-3, -71), S(-21, -163), S(-189, -453),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(16, 184), S(-1, 138), S(-7, 61), S(2, 23), S(19, 19), S(54, 11), S(64, -19),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-139, -39), S(-3, -14), S(-11, 79), S(23, 115), S(37, 151), S(44, 162), S(31, 138),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(52, -33), S(130, 239), S(161, 362), S(181, 417), S(204, 457), S(218, 498), S(238, 505), S(257, 510), S(278, 463),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(91, 25), S(154, 261), S(208, 352), S(226, 425), S(243, 477), S(253, 516), S(258, 543), S(258, 568), S(262, 578), S(268, 586), S(280, 577), S(282, 570), S(280, 583), S(244, 532),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(327, 401), S(240, 615), S(262, 649), S(278, 671), S(289, 691), S(292, 707), S(295, 726), S(299, 735), S(304, 747), S(308, 759), S(311, 768), S(309, 780), S(310, 788), S(316, 773), S(329, 740),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(446, 473), S(562, 776), S(587, 926), S(608, 1074), S(627, 1114), S(635, 1164), S(641, 1210), S(642, 1243), S(644, 1271), S(647, 1291), S(649, 1306), S(657, 1307), S(659, 1319), S(665, 1317), S(665, 1322), S(667, 1322), S(662, 1328), S(665, 1314), S(665, 1311), S(674, 1296), S(653, 1301), S(676, 1259), S(634, 1299), S(588, 1298), S(555, 1287), S(515, 1315), S(462, 1350), S(480, 1278),
};

inline const PParam PAWN_THREAT_KNIGHT = S(206, 167);
inline const PParam PAWN_THREAT_BISHOP = S(169, 248);
inline const PParam PAWN_THREAT_ROOK   = S(193, 153);
inline const PParam PAWN_THREAT_QUEEN  = S(161, 25);

inline const std::array<std::array<PParam, 5>, 2> MINOR_THREAT = {{
  {{ S(9, 58), S(98, 101), S(102, 133), S(181, 94), S(170, 25), }},
  {{ S(6, 61), S(90, 91), S(102, 124), S(210, 635), S(163, -69), }},
}};
inline const std::array<std::array<PParam, 5>, 2> ROOK_THREAT = {{
  {{ S(9, 67), S(46, 118), S(66, 112), S(15, 21), S(162, -74), }},
  {{ S(-1, 57), S(63, 82), S(103, 69), S(13, 12), S(182, 1308), }},
}};
inline const PParam KING_THREAT  = S(18, 129);
inline const PParam HANGING_PAWN  = S(32, 92);
inline const PParam HANGING_NON_PAWN  = S(73, 30);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(19, -4), S(38, -10),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(50, 37), S(111, -115),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(42, 7), S(49, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(6, -21), S(6, -19), S(1, -24), S(-5, -31), S(-12, -39), S(-17, -43), S(-20, -53), S(-24, -50), S(-21, -96),
};

inline const PParam ROOK_LINEUP = S(20, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(294, 467),    S(182, 571),    S(167, 456),    S(254, 502),    S(266, 430),    S(221, 471),    S(223, 485),    S(321, 417),    //
    S(128, 293),    S(129, 345),    S(100, 314),    S(110, 247),    S(102, 211),    S(80, 234),     S(87, 278),     S(65, 296),     //
    S(118, 245),    S(86, 272),     S(97, 264),     S(76, 200),     S(63, 183),     S(55, 204),     S(34, 214),     S(39, 249),     //
    S(74, 182),     S(43, 219),     S(66, 209),     S(57, 156),     S(37, 144),     S(32, 181),     S(-7, 191),     S(-4, 196),     //
    S(61, 141),     S(92, 142),     S(72, 225),     S(66, 183),     S(46, 174),     S(20, 185),     S(-11, 184),    S(-19, 182),    //
    S(85, 164),     S(163, 135),    S(160, 165),    S(120, 199),    S(94, 176),     S(64, 179),     S(23, 191),     S(8, 194),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-167, -306),  S(-180, 286),   S(-203, 342),   S(116, 280),    S(28, 277),     S(-207, 350),   S(-256, 329),   S(-272, -220),  //
    S(93, 225),     S(83, 256),     S(187, 239),    S(181, 313),    S(204, 282),    S(155, 250),    S(87, 236),     S(41, 245),     //
    S(130, 201),    S(134, 266),    S(136, 300),    S(165, 322),    S(150, 319),    S(106, 294),    S(98, 260),     S(48, 226),     //
    S(180, 260),    S(177, 297),    S(186, 314),    S(194, 361),    S(199, 344),    S(164, 303),    S(146, 252),    S(119, 263),    //
    S(169, 244),    S(194, 226),    S(198, 277),    S(185, 322),    S(183, 303),    S(162, 288),    S(155, 231),    S(117, 227),    //
    S(114, 161),    S(142, 177),    S(144, 236),    S(154, 278),    S(152, 271),    S(126, 225),    S(109, 190),    S(71, 153),     //
    S(134, 174),    S(126, 212),    S(122, 178),    S(133, 215),    S(129, 212),    S(101, 160),    S(60, 206),     S(43, 111),     //
    S(46, 104),     S(109, 160),    S(122, 157),    S(134, 180),    S(120, 185),    S(79, 154),     S(67, 183),     S(5, 71),       //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(75, 321),     S(-54, 474),    S(-223, 547),   S(-109, 478),   S(-105, 494),   S(-93, 503),    S(-6, 448),     S(31, 445),     //
    S(146, 330),    S(100, 454),    S(121, 434),    S(115, 432),    S(120, 437),    S(145, 394),    S(161, 389),    S(123, 359),    //
    S(217, 373),    S(199, 399),    S(211, 419),    S(203, 412),    S(206, 393),    S(197, 402),    S(176, 402),    S(198, 336),    //
    S(186, 349),    S(222, 389),    S(246, 385),    S(259, 426),    S(273, 418),    S(219, 379),    S(215, 363),    S(173, 347),    //
    S(211, 319),    S(212, 365),    S(251, 370),    S(269, 391),    S(256, 391),    S(242, 378),    S(195, 362),    S(178, 322),    //
    S(232, 324),    S(254, 327),    S(268, 355),    S(241, 390),    S(237, 369),    S(233, 366),    S(234, 350),    S(196, 324),    //
    S(203, 281),    S(297, 268),    S(236, 328),    S(223, 342),    S(211, 336),    S(219, 304),    S(228, 279),    S(209, 310),    //
    S(211, 282),    S(197, 324),    S(204, 339),    S(209, 325),    S(199, 319),    S(211, 361),    S(215, 334),    S(206, 297),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(349, 623),    S(374, 644),    S(339, 685),    S(320, 649),    S(371, 623),    S(331, 637),    S(347, 652),    S(341, 635),    //
    S(292, 639),    S(320, 668),    S(385, 621),    S(334, 616),    S(375, 607),    S(341, 621),    S(288, 658),    S(287, 647),    //
    S(263, 624),    S(378, 573),    S(408, 564),    S(366, 552),    S(381, 565),    S(316, 606),    S(295, 631),    S(257, 658),    //
    S(233, 593),    S(297, 601),    S(300, 601),    S(284, 596),    S(314, 570),    S(280, 604),    S(271, 617),    S(224, 634),    //
    S(209, 522),    S(259, 548),    S(244, 582),    S(210, 588),    S(230, 579),    S(219, 600),    S(207, 599),    S(181, 599),    //
    S(222, 425),    S(291, 458),    S(267, 498),    S(240, 518),    S(252, 517),    S(234, 537),    S(240, 506),    S(194, 522),    //
    S(144, 418),    S(273, 376),    S(266, 431),    S(248, 478),    S(256, 475),    S(241, 486),    S(230, 473),    S(204, 461),    //
    S(208, 383),    S(228, 421),    S(287, 421),    S(295, 420),    S(300, 427),    S(276, 451),    S(274, 436),    S(255, 436),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(494, 832),    S(576, 794),    S(454, 970),    S(408, 1032),   S(430, 1024),   S(483, 916),    S(471, 858),    S(426, 879),    //
    S(467, 835),    S(478, 888),    S(432, 977),    S(327, 1071),   S(373, 1060),   S(440, 905),    S(471, 819),    S(456, 784),    //
    S(433, 861),    S(468, 898),    S(422, 986),    S(405, 993),    S(424, 1003),   S(463, 903),    S(503, 779),    S(485, 750),    //
    S(430, 803),    S(440, 863),    S(396, 936),    S(406, 976),    S(430, 965),    S(431, 869),    S(480, 773),    S(455, 745),    //
    S(419, 783),    S(422, 775),    S(418, 826),    S(395, 898),    S(405, 919),    S(430, 861),    S(442, 784),    S(453, 717),    //
    S(420, 667),    S(457, 647),    S(446, 740),    S(420, 772),    S(438, 776),    S(436, 818),    S(458, 746),    S(440, 730),    //
    S(393, 483),    S(434, 461),    S(432, 557),    S(457, 618),    S(456, 655),    S(458, 639),    S(436, 670),    S(445, 657),    //
    S(367, 504),    S(416, 297),    S(435, 355),    S(443, 468),    S(461, 532),    S(457, 538),    S(453, 547),    S(419, 614),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(339, -637),   S(550, 73),     S(424, 285),    S(12, 424),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(424, -257),   S(358, 170),    S(194, 326),    S(-53, 371),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(216, -18),    S(216, 143),    S(44, 313),     S(-188, 411),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(41, -43),     S(114, 69),     S(-92, 289),    S(-255, 424),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-94, -71),    S(-18, 24),     S(-107, 212),   S(-253, 348),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-41, -107),   S(22, -34),     S(-78, 161),    S(-162, 274),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(45, -178),    S(46, -95),     S(-29, 52),     S(-119, 172),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-8, -279),    S(19, -165),    S(-71, -23),    S(-81, 12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-291, -305);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(28, -6), S(46, 2), S(41, 4), S(21, -4), S(10, -20),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(14, -7), S(25, -6), S(12, -4), S(12, -0), S(12, 1),
};

inline const PParam KS_FLANK_ATTACK = S(17, -12);
inline const PParam KS_FLANK_DEFENSE = S(-10, -6);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(12, -4);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-9, 3);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(48, -5), S(-34, 50), S(-17, -2), S(21, -15), S(46, -48), S(4, -66), S(17, -159), }},
  {{ S(2, 57), S(-77, 28), S(-56, 45), S(-19, 50), S(-8, 34), S(-32, 4), S(-38, -78), }},
  {{ S(-9, 85), S(-41, 44), S(-30, 96), S(-5, 86), S(-3, 79), S(-26, 60), S(-9, -1309), }},
  {{ S(0, 112), S(-37, 71), S(-8, 88), S(11, 82), S(12, 69), S(11, 89), S(10, 65), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-25, 106), S(-76, 31), S(-80, 51), S(-65, 73), S(-10, 65),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-27, 47), S(-199, -1197), S(-57, -215), S(-31, -14), S(-52, 9), S(-65, 33), S(-63, 30), }},
  {{ S(-13, 13), S(-120, -1112), S(-33, -250), S(-33, -49), S(-44, -15), S(-77, 18), S(-39, 17), }},
  {{ S(-41, 30), S(-21, -1034), S(21, -136), S(-19, -28), S(-48, 13), S(-72, 34), S(-58, 41), }},
  {{ S(-36, 7), S(12, -304), S(20, -102), S(-23, 14), S(-64, 29), S(-84, 17), S(-71, 24), }},
}};
inline TunableSigmoid<128> KING_SAFETY_ACTIVATION(
	1495, 1332, -70, -24
);

inline VParam WINNABLE_PAWNS = V(-21);
inline VParam WINNABLE_SYM = V(107);
inline VParam WINNABLE_ASYM = V(94);
inline VParam WINNABLE_PAWN_ENDGAME = V(73);
inline VParam WINNABLE_BIAS = V(-416);

// Epoch duration: 3.91726s
// clang-format on
}  // namespace Clockwork
