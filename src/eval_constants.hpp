#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(138, 201);
inline const PParam KNIGHT_MAT = S(566, 627);
inline const PParam BISHOP_MAT = S(602, 655);
inline const PParam ROOK_MAT   = S(475, 690);
inline const PParam QUEEN_MAT  = S(1098, 1102);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(53, 197);
inline const PParam ROOK_OPEN_VAL     = S(107, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 21);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -70);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(36, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(48, 42);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(43, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(53, -17);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 58);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(68, -37);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, 1), S(38, 27), S(58, 52), S(138, 146), S(380, 215), S(579, 644),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 35), S(44, 27), S(54, 55), S(120, 143), S(414, 85),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -122), S(-70, -100), S(-45, 10), S(10, 117), S(92, 272), S(262, 382),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -44), S(35, -5), S(21, 34), S(1, 111), S(48, 220), S(203, 286),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(20, -34), S(4, 13), S(2, -21), S(0, -54), S(-9, -126), S(-211, -234),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-4, 148), S(-18, 115), S(-12, 46), S(-4, 9), S(1, 9), S(37, 8), S(13, -1),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-303, -54), S(-39, 26), S(-24, 61), S(13, 98), S(31, 115), S(49, 116), S(27, 112),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(73, 4), S(142, 177), S(177, 269), S(206, 304), S(245, 322), S(269, 357), S(301, 356), S(332, 369), S(385, 283),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(103, 20), S(147, 186), S(199, 245), S(226, 290), S(251, 322), S(266, 347), S(275, 365), S(289, 374), S(295, 391), S(317, 376), S(326, 378), S(379, 323), S(378, 333), S(407, 285),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(316, 258), S(231, 429), S(256, 452), S(274, 462), S(285, 474), S(291, 485), S(297, 495), S(306, 497), S(312, 507), S(323, 509), S(334, 510), S(342, 515), S(347, 514), S(363, 488), S(448, 384),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(489, 486), S(639, 539), S(662, 656), S(681, 768), S(697, 812), S(706, 856), S(711, 887), S(719, 899), S(722, 921), S(725, 938), S(732, 943), S(736, 951), S(744, 946), S(747, 950), S(751, 946), S(750, 950), S(752, 945), S(758, 938), S(766, 929), S(771, 925), S(780, 901), S(801, 865), S(795, 867), S(796, 808), S(782, 798), S(779, 763), S(716, 803), S(737, 741),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(464, -198), S(103, -98), S(25, -20), S(13, 12), S(-6, 11), S(-20, 2), S(-24, 9), S(-39, 13), S(-21, -32),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -6), S(15, -15), S(13, -12), S(6, -8), S(2, 209),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 417),
};

inline const PParam PAWN_THREAT_KNIGHT = S(214, 89);
inline const PParam PAWN_THREAT_BISHOP = S(193, 139);
inline const PParam PAWN_THREAT_ROOK   = S(188, 128);
inline const PParam PAWN_THREAT_QUEEN  = S(166, -14);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 103);
inline const PParam KNIGHT_THREAT_ROOK   = S(229, 65);
inline const PParam KNIGHT_THREAT_QUEEN  = S(152, -6);

inline const PParam BISHOP_THREAT_KNIGHT = S(104, 57);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 123);
inline const PParam BISHOP_THREAT_QUEEN  = S(173, 100);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -18), S(-9, -28), S(-13, -37), S(-18, -43), S(-20, -55), S(-26, -55), S(-42, -50),
};

inline const PParam ROOK_LINEUP = S(12, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(298, 344),    S(132, 450),    S(287, 413),    S(308, 281),    S(327, 232),    S(219, 318),    S(149, 362),    S(264, 315),    //
    S(122, 204),    S(151, 240),    S(186, 158),    S(174, 98),     S(154, 78),     S(124, 134),    S(97, 189),     S(49, 220),     //
    S(80, 175),     S(67, 175),     S(111, 101),    S(112, 80),     S(100, 77),     S(70, 110),     S(23, 161),     S(12, 188),     //
    S(56, 126),     S(46, 148),     S(82, 97),      S(81, 89),      S(57, 93),      S(40, 118),     S(-19, 160),    S(-20, 152),    //
    S(55, 100),     S(96, 104),     S(80, 137),     S(74, 123),     S(46, 119),     S(21, 127),     S(-14, 143),    S(-20, 137),    //
    S(68, 102),     S(160, 116),    S(145, 173),    S(95, 156),     S(67, 142),     S(45, 138),     S(16, 150),     S(-4, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-222, -113),  S(-139, 178),   S(-143, 87),    S(112, 180),    S(30, 194),     S(-111, 196),   S(-268, 254),   S(-286, -30),   //
    S(75, 169),     S(117, 191),    S(211, 147),    S(201, 158),    S(199, 164),    S(113, 196),    S(71, 209),     S(50, 190),     //
    S(167, 162),    S(210, 152),    S(212, 212),    S(210, 203),    S(172, 231),    S(112, 248),    S(126, 189),    S(90, 186),     //
    S(234, 183),    S(240, 202),    S(236, 226),    S(221, 255),    S(223, 264),    S(181, 248),    S(172, 218),    S(165, 196),    //
    S(214, 184),    S(252, 163),    S(220, 226),    S(213, 245),    S(192, 249),    S(190, 234),    S(187, 179),    S(147, 199),    //
    S(160, 151),    S(185, 161),    S(175, 198),    S(185, 224),    S(179, 225),    S(143, 204),    S(133, 173),    S(106, 142),    //
    S(173, 154),    S(191, 153),    S(161, 160),    S(161, 185),    S(152, 184),    S(126, 138),    S(112, 164),    S(97, 77),      //
    S(107, 104),    S(150, 174),    S(167, 138),    S(184, 129),    S(164, 154),    S(131, 123),    S(118, 152),    S(80, 68),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-1, 293),     S(-13, 299),    S(-297, 347),   S(-139, 285),   S(-146, 303),   S(-159, 297),   S(-47, 297),    S(32, 279),     //
    S(124, 204),    S(61, 288),     S(106, 234),    S(44, 254),     S(60, 254),     S(87, 254),     S(124, 248),    S(104, 222),    //
    S(197, 232),    S(207, 248),    S(204, 253),    S(176, 251),    S(149, 251),    S(152, 261),    S(172, 249),    S(164, 227),    //
    S(164, 223),    S(198, 236),    S(200, 256),    S(196, 294),    S(226, 282),    S(160, 256),    S(174, 221),    S(131, 222),    //
    S(189, 187),    S(208, 216),    S(213, 242),    S(217, 269),    S(194, 285),    S(178, 263),    S(148, 234),    S(145, 197),    //
    S(219, 192),    S(253, 202),    S(261, 233),    S(207, 259),    S(202, 238),    S(198, 249),    S(206, 225),    S(148, 221),    //
    S(186, 161),    S(284, 181),    S(241, 196),    S(207, 213),    S(187, 219),    S(195, 190),    S(195, 190),    S(186, 179),    //
    S(215, 163),    S(201, 184),    S(200, 221),    S(216, 179),    S(205, 190),    S(204, 234),    S(203, 209),    S(194, 187),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(426, 385),    S(436, 409),    S(418, 417),    S(433, 380),    S(413, 389),    S(380, 397),    S(377, 414),    S(368, 418),    //
    S(307, 468),    S(370, 473),    S(454, 434),    S(398, 440),    S(391, 443),    S(363, 448),    S(294, 480),    S(284, 484),    //
    S(270, 468),    S(380, 451),    S(431, 410),    S(409, 399),    S(361, 428),    S(319, 451),    S(323, 447),    S(256, 486),    //
    S(277, 425),    S(350, 436),    S(384, 412),    S(359, 411),    S(355, 416),    S(311, 445),    S(306, 440),    S(235, 467),    //
    S(256, 356),    S(319, 377),    S(311, 394),    S(289, 390),    S(267, 413),    S(257, 429),    S(227, 422),    S(207, 417),    //
    S(248, 298),    S(312, 326),    S(301, 349),    S(281, 348),    S(269, 356),    S(243, 382),    S(241, 358),    S(208, 361),    //
    S(143, 310),    S(276, 275),    S(286, 305),    S(275, 327),    S(262, 330),    S(253, 335),    S(237, 320),    S(210, 331),    //
    S(206, 295),    S(227, 315),    S(285, 306),    S(298, 301),    S(286, 312),    S(267, 327),    S(257, 321),    S(238, 331),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(546, 661),    S(606, 603),    S(522, 732),    S(501, 791),    S(486, 766),    S(508, 731),    S(532, 645),    S(489, 680),    //
    S(553, 706),    S(513, 808),    S(497, 848),    S(359, 937),    S(369, 919),    S(430, 865),    S(468, 750),    S(485, 722),    //
    S(515, 773),    S(563, 801),    S(494, 904),    S(444, 920),    S(418, 910),    S(470, 823),    S(507, 746),    S(523, 663),    //
    S(557, 691),    S(553, 790),    S(496, 852),    S(479, 891),    S(474, 885),    S(490, 787),    S(536, 711),    S(520, 680),    //
    S(569, 662),    S(553, 737),    S(528, 784),    S(494, 831),    S(494, 832),    S(500, 773),    S(519, 692),    S(543, 620),    //
    S(553, 596),    S(585, 652),    S(576, 719),    S(545, 712),    S(539, 704),    S(537, 727),    S(549, 652),    S(530, 621),    //
    S(531, 483),    S(572, 494),    S(574, 566),    S(585, 607),    S(571, 634),    S(565, 602),    S(526, 639),    S(540, 605),    //
    S(512, 511),    S(545, 344),    S(566, 372),    S(582, 480),    S(577, 564),    S(577, 505),    S(566, 523),    S(533, 558),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-49, -325),   S(297, 165),    S(159, 140),    S(35, -22),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(242, -67),    S(347, 166),    S(199, 160),    S(120, 8),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(237, 26),     S(378, 112),    S(266, 115),    S(167, 12),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(83, -2),      S(332, 47),     S(185, 69),     S(111, 35),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-20, -27),    S(229, 14),     S(151, 23),     S(35, 29),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-22, -18),    S(208, 3),      S(108, 13),     S(54, -6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-1, -22),     S(80, 37),      S(-5, 40),      S(-65, 14),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-112, -72),   S(-16, -26),    S(-119, -17),   S(-117, -94),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(14, -19), S(-5, 18), S(-8, 20), S(-0, 3), S(-1, 1), S(-8, 19), S(-3, 19), }},
  {{ S(4, -8), S(-24, 24), S(-20, 18), S(-11, 0), S(-10, 0), S(-19, 23), S(-23, 33), }},
  {{ S(-11, 2), S(-22, 28), S(-21, 9), S(-17, -5), S(-16, -4), S(-20, 8), S(-21, 24), }},
  {{ S(-0, -19), S(-18, -20), S(-10, -23), S(-4, -28), S(-6, -26), S(-11, -21), S(-14, -21), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(-0, 317), S(-20, 32), S(-18, 22), S(-11, 10), S(-10, -9),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-6, 1), S(-17, 10), S(-16, 9), S(-14, 9), S(-15, 4), S(-13, 0), S(-17, 8), }},
  {{ S(-6, 2), S(-14, 9), S(-20, 14), S(-17, 11), S(-17, 7), S(-19, 11), S(-13, 8), }},
  {{ S(-12, 6), S(-17, 4), S(-18, 10), S(-13, 10), S(-13, 9), S(-17, 9), S(-17, 5), }},
  {{ S(-12, 9), S(-18, 11), S(-19, 11), S(-13, 14), S(-12, 14), S(-18, 11), S(-19, 11), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1189, 558, -22, 62
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(222);
inline VParam WINNABLE_BIAS = V(-661);

// Epoch duration: 7.52381s
// clang-format on
}  // namespace Clockwork
