#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(118, 186);
inline const PParam KNIGHT_MAT = S(510, 643);
inline const PParam BISHOP_MAT = S(507, 660);
inline const PParam ROOK_MAT   = S(311, 627);
inline const PParam QUEEN_MAT  = S(718, 1057);
inline const PParam TEMPO_VAL  = S(65, 29);

inline const PParam BISHOP_PAIR_VAL   = S(51, 179);
inline const PParam ROOK_OPEN_VAL     = S(102, -13);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 23);
inline const PParam MINOR_BEHIND_PAWN = S(11, 34);

inline const PParam DOUBLED_PAWN_VAL = S(-14, -56);
inline const PParam ISOLATED_PAWN_VAL = S(-22, -13);

inline const PParam POTENTIAL_CHECKER_VAL = S(-34, -27);
inline const PParam OUTPOST_KNIGHT_VAL    = S(44, 45);
inline const PParam OUTPOST_BISHOP_VAL    = S(47, 43);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(34, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(39, -8);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(21, 50);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(53, -26);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(18, 1), S(42, 25), S(55, 53), S(111, 150), S(358, 222), S(835, 524),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(56, 42), S(43, 36), S(57, 58), S(119, 142), S(488, 59),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-66, -129), S(-66, -111), S(-38, 0), S(16, 104), S(69, 288), S(184, 402),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(32, -41), S(32, -3), S(15, 29), S(-6, 103), S(24, 209), S(254, 275),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -19), S(8, 25), S(0, -4), S(0, -27), S(-0, -106), S(-157, -244),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-2, 141), S(-16, 113), S(-11, 46), S(2, 6), S(16, 1), S(51, -5), S(34, -17),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-279, -57), S(-38, 19), S(-17, 60), S(17, 92), S(31, 112), S(40, 117), S(8, 131),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(53, 25), S(100, 166), S(128, 263), S(158, 287), S(192, 306), S(214, 334), S(240, 340), S(263, 352), S(295, 307),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(100, 144), S(134, 204), S(176, 235), S(190, 278), S(215, 296), S(227, 316), S(236, 329), S(245, 336), S(250, 346), S(260, 344), S(258, 352), S(305, 315), S(312, 286), S(344, 292),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(314, 340), S(236, 434), S(257, 454), S(269, 463), S(277, 474), S(280, 483), S(286, 491), S(292, 493), S(299, 499), S(306, 503), S(314, 503), S(317, 510), S(320, 510), S(332, 495), S(366, 444),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(519, 268), S(604, 658), S(654, 701), S(687, 752), S(693, 807), S(695, 856), S(700, 872), S(703, 894), S(706, 908), S(708, 924), S(713, 927), S(715, 937), S(717, 944), S(719, 944), S(720, 944), S(719, 948), S(717, 949), S(724, 945), S(730, 931), S(728, 931), S(724, 935), S(746, 913), S(734, 915), S(721, 913), S(710, 899), S(714, 876), S(674, 871), S(698, 890),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(419, -129), S(100, -51), S(34, -3), S(17, 18), S(-5, 16), S(-10, 0), S(-11, 8), S(-25, 9), S(13, -27),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -5), S(15, -16), S(13, -10), S(5, -9), S(3, 186),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -8), S(5, -5), S(6, 394),
};

inline const PParam PAWN_THREAT_KNIGHT = S(187, 96);
inline const PParam PAWN_THREAT_BISHOP = S(168, 144);
inline const PParam PAWN_THREAT_ROOK   = S(159, 112);
inline const PParam PAWN_THREAT_QUEEN  = S(136, 48);

inline const PParam KNIGHT_THREAT_BISHOP = S(86, 95);
inline const PParam KNIGHT_THREAT_ROOK   = S(196, 70);
inline const PParam KNIGHT_THREAT_QUEEN  = S(131, 1);

inline const PParam BISHOP_THREAT_KNIGHT = S(80, 55);
inline const PParam BISHOP_THREAT_ROOK   = S(181, 117);
inline const PParam BISHOP_THREAT_QUEEN  = S(168, 53);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -26), S(1, -8), S(-1, -15), S(-4, -22), S(-8, -28), S(-11, -35), S(-14, -40), S(-16, -43), S(-29, -39),
};

inline const PParam ROOK_LINEUP = S(17, 44);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(261, 376),    S(73, 483),     S(244, 423),    S(252, 333),    S(317, 227),    S(194, 328),    S(143, 362),    S(264, 325),    //
    S(127, 187),    S(115, 235),    S(169, 137),    S(189, 72),     S(155, 55),     S(112, 119),    S(84, 175),     S(51, 207),     //
    S(75, 174),     S(65, 173),     S(102, 107),    S(107, 88),     S(94, 87),      S(64, 116),     S(30, 166),     S(19, 183),     //
    S(59, 123),     S(50, 143),     S(76, 100),     S(79, 98),      S(62, 98),      S(38, 117),     S(-12, 157),    S(-12, 143),    //
    S(63, 94),      S(93, 102),     S(66, 135),     S(60, 130),     S(38, 122),     S(21, 129),     S(-15, 141),    S(-15, 129),    //
    S(79, 94),      S(141, 121),    S(129, 180),    S(80, 158),     S(59, 133),     S(37, 142),     S(13, 154),     S(1, 146),      //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-77, -185),   S(-73, 169),    S(-337, 387),   S(164, 169),    S(61, 189),     S(-83, 203),    S(-269, 258),   S(-186, -96),   //
    S(118, 163),    S(71, 205),     S(201, 146),    S(160, 190),    S(171, 199),    S(113, 190),    S(64, 206),     S(88, 176),     //
    S(158, 176),    S(147, 175),    S(186, 206),    S(164, 233),    S(150, 221),    S(105, 221),    S(116, 172),    S(132, 147),    //
    S(224, 183),    S(198, 202),    S(203, 221),    S(177, 251),    S(182, 247),    S(163, 224),    S(161, 205),    S(179, 175),    //
    S(189, 177),    S(207, 175),    S(192, 215),    S(166, 233),    S(160, 226),    S(160, 223),    S(167, 159),    S(147, 190),    //
    S(140, 146),    S(166, 153),    S(153, 175),    S(164, 200),    S(155, 202),    S(126, 177),    S(124, 166),    S(102, 144),    //
    S(156, 128),    S(143, 161),    S(140, 151),    S(138, 172),    S(126, 175),    S(104, 132),    S(104, 143),    S(95, 49),      //
    S(103, 43),     S(125, 147),    S(145, 132),    S(157, 140),    S(155, 144),    S(104, 105),    S(107, 135),    S(21, -1),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(104, 196),    S(18, 277),     S(-291, 354),   S(-83, 281),    S(-120, 318),   S(-132, 323),   S(-5, 307),     S(74, 284),     //
    S(116, 201),    S(78, 265),     S(121, 249),    S(66, 257),     S(62, 269),     S(100, 258),    S(113, 248),    S(137, 180),    //
    S(185, 208),    S(190, 247),    S(185, 242),    S(170, 247),    S(174, 234),    S(130, 268),    S(163, 234),    S(148, 215),    //
    S(165, 202),    S(183, 222),    S(188, 260),    S(185, 280),    S(207, 276),    S(175, 231),    S(164, 222),    S(136, 196),    //
    S(187, 175),    S(185, 223),    S(198, 235),    S(199, 266),    S(197, 268),    S(175, 253),    S(150, 217),    S(143, 199),    //
    S(201, 183),    S(239, 194),    S(229, 239),    S(194, 246),    S(185, 243),    S(193, 244),    S(207, 215),    S(155, 198),    //
    S(185, 140),    S(253, 178),    S(223, 191),    S(185, 215),    S(168, 219),    S(197, 177),    S(196, 178),    S(181, 147),    //
    S(207, 168),    S(186, 170),    S(164, 220),    S(186, 179),    S(180, 185),    S(182, 211),    S(208, 148),    S(183, 163),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(401, 416),    S(415, 435),    S(410, 433),    S(384, 431),    S(405, 410),    S(388, 404),    S(367, 429),    S(350, 448),    //
    S(365, 466),    S(337, 511),    S(429, 449),    S(380, 468),    S(384, 461),    S(347, 467),    S(278, 496),    S(305, 487),    //
    S(286, 478),    S(381, 456),    S(394, 429),    S(374, 417),    S(348, 428),    S(317, 452),    S(310, 467),    S(273, 487),    //
    S(287, 430),    S(334, 453),    S(371, 422),    S(324, 421),    S(333, 411),    S(306, 450),    S(289, 456),    S(255, 462),    //
    S(249, 373),    S(292, 400),    S(291, 406),    S(271, 394),    S(261, 407),    S(261, 422),    S(238, 424),    S(229, 418),    //
    S(247, 322),    S(300, 335),    S(289, 357),    S(259, 361),    S(264, 358),    S(243, 381),    S(235, 376),    S(213, 367),    //
    S(155, 330),    S(274, 276),    S(272, 317),    S(262, 335),    S(255, 340),    S(240, 348),    S(228, 338),    S(219, 327),    //
    S(217, 289),    S(204, 336),    S(269, 313),    S(283, 305),    S(264, 327),    S(261, 336),    S(259, 316),    S(248, 321),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(525, 726),    S(566, 697),    S(561, 702),    S(510, 799),    S(503, 777),    S(520, 746),    S(489, 728),    S(494, 713),    //
    S(545, 764),    S(507, 831),    S(478, 886),    S(413, 902),    S(409, 905),    S(451, 847),    S(463, 786),    S(493, 744),    //
    S(510, 782),    S(576, 823),    S(494, 909),    S(485, 881),    S(450, 880),    S(491, 802),    S(502, 778),    S(510, 693),    //
    S(546, 730),    S(532, 802),    S(518, 817),    S(465, 911),    S(478, 869),    S(506, 770),    S(539, 715),    S(532, 673),    //
    S(548, 698),    S(532, 738),    S(522, 773),    S(501, 803),    S(508, 796),    S(510, 765),    S(510, 719),    S(533, 668),    //
    S(548, 620),    S(570, 657),    S(562, 714),    S(542, 695),    S(537, 703),    S(537, 724),    S(553, 668),    S(531, 647),    //
    S(544, 462),    S(601, 428),    S(576, 564),    S(573, 621),    S(566, 636),    S(566, 609),    S(538, 629),    S(542, 609),    //
    S(525, 575),    S(502, 361),    S(519, 449),    S(554, 504),    S(560, 588),    S(563, 533),    S(564, 511),    S(520, 584),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(35, -213),    S(132, 197),    S(74, 182),     S(53, 72),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(148, 24),     S(178, 224),    S(91, 219),     S(89, 69),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(122, 113),    S(183, 198),    S(144, 179),    S(169, 51),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(10, 61),      S(175, 110),    S(147, 86),     S(76, 45),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-51, 7),      S(113, 55),     S(72, 30),      S(-9, 10),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-52, -9),     S(138, 12),     S(34, 14),      S(4, -29),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-16, -25),    S(43, 32),      S(-40, 24),     S(-102, -13),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-108, -76),   S(-27, -25),    S(-133, -21),   S(-103, -130),  S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(28, -16), S(6, 20), S(2, 20), S(16, 2), S(14, 8), S(3, 19), S(7, 23), }},
  {{ S(20, -6), S(-18, 29), S(-10, 25), S(4, 3), S(5, 3), S(-9, 27), S(-17, 36), }},
  {{ S(-20, -2), S(-36, 24), S(-34, 3), S(-27, -9), S(-26, -8), S(-33, 1), S(-34, 20), }},
  {{ S(13, -24), S(-6, -29), S(-1, -26), S(7, -31), S(6, -30), S(-1, -27), S(-2, -30), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-3, 206), S(-20, 29), S(-22, 25), S(-15, 15), S(-14, -6),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-10, 3), S(-21, 11), S(-19, 8), S(-15, 6), S(-16, 4), S(-17, 3), S(-21, 9), }},
  {{ S(-10, 5), S(-18, 8), S(-26, 17), S(-19, 9), S(-18, 9), S(-25, 12), S(-18, 9), }},
  {{ S(-17, 12), S(-24, 7), S(-23, 16), S(-17, 13), S(-16, 13), S(-22, 13), S(-24, 9), }},
  {{ S(-15, 13), S(-28, 20), S(-25, 17), S(-18, 18), S(-15, 15), S(-25, 17), S(-25, 18), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        910, 473, -21, 46
);

inline VParam WINNABLE_PAWNS = V(-13);
inline VParam WINNABLE_SYM = V(111);
inline VParam WINNABLE_ASYM = V(98);
inline VParam WINNABLE_PAWN_ENDGAME = V(170);
inline VParam WINNABLE_BIAS = V(-549);
// clang-format on
}  // namespace Clockwork
