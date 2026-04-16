#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(125, 214);
inline const PParam KNIGHT_MAT = S(576, 639);
inline const PParam BISHOP_MAT = S(602, 637);
inline const PParam ROOK_MAT   = S(465, 689);
inline const PParam QUEEN_MAT  = S(945, 1175);
inline const PParam TEMPO_VAL  = S(60, 21);

inline const PParam BISHOP_PAIR_VAL   = S(54, 199);
inline const PParam ROOK_OPEN_VAL     = S(119, -16);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 29);
inline const PParam MINOR_BEHIND_PAWN = S(12, 38);
inline const PParam RESTRICTED_SQUARES = S(-25, -4);

inline const PParam DOUBLED_PAWN_VAL = S(-11, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -15);

inline const PParam POTENTIAL_CHECKER_VAL = S(-48, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(51, 47);
inline const PParam OUTPOST_BISHOP_VAL    = S(57, 35);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 2);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(49, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(27, 43);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(63, -41);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, 1), S(30, 26), S(59, 49), S(141, 143), S(380, 199), S(605, 629),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(51, 35), S(45, 27), S(60, 51), S(121, 136), S(439, 65),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -106), S(-78, -86), S(-46, 10), S(16, 101), S(107, 245), S(283, 350),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -30), S(21, 3), S(13, 35), S(1, 111), S(83, 197), S(257, 248),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -24), S(-1, 25), S(-2, -11), S(1, -42), S(-8, -123), S(-254, -202),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(4, 143), S(-18, 117), S(-12, 43), S(-5, 7), S(3, 6), S(41, 1), S(32, -13),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-324, -27), S(-43, 30), S(-30, 77), S(21, 81), S(44, 97), S(56, 100), S(34, 100),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(87, 4), S(154, 174), S(186, 261), S(213, 293), S(245, 309), S(261, 339), S(283, 337), S(303, 347), S(341, 274),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(99, -2), S(142, 169), S(193, 238), S(218, 284), S(241, 317), S(255, 340), S(263, 357), S(275, 362), S(278, 378), S(298, 357), S(301, 359), S(349, 300), S(351, 301), S(370, 262),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(331, 249), S(244, 411), S(266, 440), S(282, 451), S(292, 465), S(297, 476), S(302, 487), S(309, 490), S(313, 502), S(320, 505), S(328, 507), S(332, 513), S(336, 511), S(347, 486), S(431, 380),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(484, 469), S(612, 575), S(636, 689), S(656, 796), S(671, 838), S(679, 878), S(686, 904), S(693, 913), S(697, 931), S(699, 945), S(706, 947), S(708, 954), S(714, 951), S(714, 956), S(716, 952), S(712, 952), S(709, 953), S(712, 944), S(717, 933), S(718, 927), S(717, 910), S(733, 871), S(709, 889), S(700, 834), S(671, 833), S(659, 807), S(594, 844), S(605, 797),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(468, -201), S(80, -99), S(23, -18), S(9, 12), S(-3, 4), S(-3, -0), S(-14, 4), S(-43, 20), S(-50, 10),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(9, -20), S(12, -15), S(11, -2), S(5, -6), S(1, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -18), S(5, -21), S(3, -9), S(3, -2), S(4, -2),
};

inline const PParam KS_NO_QUEEN = S(-79, 5);

inline const PParam KS_FLANK_ATTACK = S(3, -4);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -10);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -1);

inline const PParam PAWN_THREAT_KNIGHT = S(212, 92);
inline const PParam PAWN_THREAT_BISHOP = S(205, 134);
inline const PParam PAWN_THREAT_ROOK   = S(199, 122);
inline const PParam PAWN_THREAT_QUEEN  = S(183, -19);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 74);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -22);

inline const PParam BISHOP_THREAT_KNIGHT = S(103, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 87);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(12, -31), S(-3, -3), S(-5, -12), S(-8, -23), S(-11, -33), S(-14, -40), S(-15, -52), S(-21, -54), S(-36, -49),
};

inline const PParam ROOK_LINEUP = S(14, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(327, 322),    S(137, 407),    S(267, 383),    S(273, 297),    S(313, 238),    S(202, 331),    S(136, 379),    S(295, 300),    //
    S(109, 212),    S(130, 234),    S(145, 182),    S(122, 139),    S(117, 110),    S(86, 168),     S(68, 219),     S(39, 240),     //
    S(92, 158),     S(71, 172),     S(103, 124),    S(87, 110),     S(81, 99),      S(58, 128),     S(9, 177),      S(11, 198),     //
    S(62, 106),     S(39, 139),     S(67, 108),     S(55, 107),     S(32, 108),     S(26, 131),     S(-32, 170),    S(-22, 159),    //
    S(60, 81),      S(86, 87),      S(71, 125),     S(61, 125),     S(31, 123),     S(14, 131),     S(-24, 152),    S(-21, 141),    //
    S(78, 83),      S(152, 95),     S(137, 140),    S(93, 147),     S(64, 136),     S(44, 132),     S(11, 154),     S(-1, 153),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-220, -146),  S(-156, 183),   S(-58, -18),    S(104, 189),    S(36, 186),     S(-95, 176),    S(-271, 237),   S(-285, -56),   //
    S(77, 143),     S(102, 173),    S(216, 149),    S(222, 172),    S(220, 176),    S(144, 191),    S(80, 185),     S(61, 156),     //
    S(139, 150),    S(180, 137),    S(203, 213),    S(218, 215),    S(187, 239),    S(140, 233),    S(134, 167),    S(85, 161),     //
    S(209, 170),    S(222, 192),    S(230, 228),    S(231, 259),    S(237, 260),    S(194, 242),    S(172, 201),    S(156, 176),    //
    S(190, 167),    S(232, 151),    S(214, 217),    S(210, 237),    S(188, 239),    S(194, 223),    S(182, 170),    S(138, 178),    //
    S(131, 126),    S(154, 151),    S(153, 190),    S(168, 213),    S(162, 211),    S(134, 191),    S(128, 156),    S(88, 121),     //
    S(147, 132),    S(159, 128),    S(134, 143),    S(141, 167),    S(138, 165),    S(112, 123),    S(92, 145),     S(77, 61),      //
    S(81, 63),      S(129, 125),    S(144, 106),    S(160, 111),    S(144, 130),    S(109, 107),    S(98, 119),     S(59, 29),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(2, 289),      S(-9, 302),     S(-287, 355),   S(-134, 298),   S(-126, 297),   S(-149, 291),   S(-46, 285),    S(31, 268),     //
    S(111, 216),    S(79, 282),     S(109, 246),    S(57, 275),     S(78, 265),     S(101, 250),    S(140, 239),    S(115, 204),    //
    S(179, 234),    S(173, 251),    S(185, 266),    S(171, 271),    S(152, 266),    S(163, 260),    S(175, 233),    S(169, 216),    //
    S(167, 213),    S(201, 233),    S(212, 258),    S(210, 301),    S(244, 281),    S(191, 248),    S(196, 214),    S(155, 207),    //
    S(203, 167),    S(205, 213),    S(224, 243),    S(229, 272),    S(211, 279),    S(206, 260),    S(175, 224),    S(170, 185),    //
    S(219, 185),    S(236, 202),    S(246, 234),    S(211, 260),    S(205, 241),    S(206, 248),    S(216, 225),    S(169, 210),    //
    S(180, 152),    S(265, 167),    S(228, 186),    S(206, 208),    S(189, 212),    S(196, 188),    S(194, 179),    S(196, 174),    //
    S(207, 153),    S(192, 179),    S(197, 201),    S(212, 180),    S(196, 190),    S(201, 226),    S(201, 206),    S(197, 178),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(410, 396),    S(446, 406),    S(397, 426),    S(399, 395),    S(433, 393),    S(400, 402),    S(415, 414),    S(400, 417),    //
    S(300, 465),    S(387, 460),    S(447, 430),    S(384, 445),    S(424, 438),    S(391, 445),    S(338, 470),    S(322, 471),    //
    S(262, 465),    S(385, 442),    S(430, 406),    S(400, 405),    S(399, 425),    S(351, 449),    S(355, 450),    S(292, 479),    //
    S(231, 442),    S(317, 443),    S(344, 420),    S(320, 428),    S(355, 415),    S(312, 446),    S(316, 442),    S(243, 468),    //
    S(208, 377),    S(284, 388),    S(273, 403),    S(246, 404),    S(261, 408),    S(251, 429),    S(227, 425),    S(211, 421),    //
    S(226, 293),    S(300, 317),    S(289, 333),    S(265, 335),    S(279, 338),    S(247, 373),    S(259, 346),    S(220, 353),    //
    S(132, 298),    S(274, 259),    S(273, 287),    S(263, 308),    S(268, 313),    S(255, 327),    S(249, 310),    S(219, 321),    //
    S(197, 281),    S(222, 302),    S(278, 291),    S(291, 285),    S(292, 296),    S(273, 314),    S(270, 308),    S(251, 311),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(538, 665),    S(628, 620),    S(547, 720),    S(499, 783),    S(528, 757),    S(537, 723),    S(557, 650),    S(476, 727),    //
    S(518, 722),    S(533, 806),    S(502, 828),    S(371, 902),    S(412, 900),    S(453, 864),    S(504, 755),    S(483, 749),    //
    S(483, 763),    S(515, 797),    S(482, 859),    S(439, 887),    S(449, 898),    S(503, 818),    S(523, 760),    S(529, 687),    //
    S(507, 644),    S(501, 741),    S(461, 797),    S(445, 856),    S(453, 885),    S(489, 780),    S(532, 712),    S(507, 686),    //
    S(507, 620),    S(488, 683),    S(468, 739),    S(446, 796),    S(457, 833),    S(473, 793),    S(496, 717),    S(515, 652),    //
    S(495, 557),    S(516, 586),    S(510, 661),    S(490, 678),    S(493, 705),    S(495, 743),    S(512, 692),    S(505, 649),    //
    S(470, 439),    S(498, 449),    S(505, 506),    S(524, 563),    S(513, 619),    S(513, 606),    S(483, 652),    S(501, 629),    //
    S(457, 457),    S(486, 314),    S(509, 334),    S(523, 444),    S(516, 542),    S(524, 497),    S(521, 524),    S(494, 556),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-10, -177),   S(329, 277),    S(223, 279),    S(95, 183),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(244, 58),     S(371, 223),    S(227, 263),    S(171, 150),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(171, 112),    S(265, 190),    S(179, 210),    S(126, 144),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-3, 57),      S(148, 113),    S(34, 164),     S(23, 161),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-97, -27),    S(33, 26),      S(-18, 78),     S(-95, 133),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-40, -69),    S(55, -21),     S(-24, 43),     S(-69, 87),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(22, -107),    S(56, -53),     S(-14, -6),     S(-77, 33),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-59, -149),   S(7, -100),     S(-79, -60),    S(-77, -78),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -28), S(1, -21), S(-1, -30), S(8, -59), S(8, -64), S(-2, -27), S(2, -21), }},
  {{ S(2, 22), S(-22, 7), S(-16, -3), S(-4, -27), S(-4, -21), S(-15, -1), S(-21, 11), }},
  {{ S(3, 5), S(-9, -2), S(-3, -14), S(2, -34), S(3, -33), S(-3, -13), S(-7, -2), }},
  {{ S(8, 16), S(-6, -14), S(3, -7), S(7, -17), S(6, -17), S(2, -8), S(-3, -10), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(8, 6), S(-11, 3), S(-8, 2), S(-0, 12), S(3, -22),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 30), S(-8, 16), S(-7, 10), S(-5, 2), S(-6, 0), S(-6, 10), S(-8, 17), }},
  {{ S(7, -17), S(1, -28), S(-7, -29), S(-5, -49), S(-6, -50), S(-7, -33), S(1, -28), }},
  {{ S(0, -2), S(-2, -14), S(-6, -13), S(-4, -21), S(-4, -26), S(-7, -16), S(-2, -13), }},
  {{ S(-0, -6), S(-6, -7), S(-9, -16), S(-4, -14), S(-3, -12), S(-9, -14), S(-8, -8), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1299, 1551, -14, -29
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(246);
inline VParam WINNABLE_BIAS = V(-648);

// Epoch duration: 9.73532s
// clang-format on
}  // namespace Clockwork
