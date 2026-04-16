#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(126, 214);
inline const PParam KNIGHT_MAT = S(576, 638);
inline const PParam BISHOP_MAT = S(603, 635);
inline const PParam ROOK_MAT   = S(466, 688);
inline const PParam QUEEN_MAT  = S(947, 1171);
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
    S(14, 1), S(30, 26), S(59, 48), S(140, 142), S(378, 200), S(600, 637),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(51, 35), S(45, 27), S(60, 50), S(120, 136), S(438, 67),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -106), S(-78, -86), S(-46, 11), S(16, 101), S(108, 246), S(283, 349),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -30), S(22, 3), S(14, 34), S(1, 111), S(82, 198), S(258, 247),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -24), S(-0, 25), S(-1, -11), S(1, -42), S(-9, -122), S(-256, -200),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(3, 143), S(-18, 117), S(-12, 42), S(-5, 6), S(3, 5), S(41, 1), S(32, -14),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-327, -27), S(-44, 30), S(-30, 77), S(20, 82), S(43, 98), S(56, 100), S(34, 100),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(88, 3), S(155, 173), S(187, 260), S(213, 293), S(245, 308), S(261, 339), S(283, 336), S(303, 347), S(342, 273),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(100, -2), S(143, 168), S(194, 238), S(219, 284), S(241, 317), S(255, 340), S(263, 357), S(275, 362), S(278, 377), S(299, 356), S(302, 358), S(351, 299), S(355, 297), S(372, 261),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(331, 248), S(244, 411), S(266, 439), S(282, 450), S(292, 464), S(297, 476), S(302, 487), S(309, 490), S(312, 502), S(320, 505), S(328, 507), S(332, 513), S(335, 512), S(347, 486), S(430, 380),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(486, 464), S(613, 575), S(637, 689), S(656, 796), S(672, 837), S(680, 877), S(686, 904), S(693, 913), S(697, 931), S(700, 945), S(706, 947), S(708, 954), S(714, 951), S(714, 956), S(716, 952), S(712, 953), S(709, 954), S(713, 944), S(717, 934), S(719, 927), S(718, 909), S(733, 872), S(709, 889), S(700, 834), S(671, 833), S(660, 806), S(595, 845), S(605, 798),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(473, -206), S(80, -99), S(23, -18), S(9, 11), S(-3, 4), S(-3, -1), S(-14, 4), S(-43, 21), S(-51, 11),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -20), S(12, -14), S(11, -2), S(5, -6), S(1, -10),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -17), S(4, -20), S(3, -8), S(3, -2), S(4, -2),
};

inline const PParam KS_NO_QUEEN = S(-79, 3);

inline const PParam KS_FLANK_ATTACK = S(3, -4);
inline const PParam KS_FLANK_DEFENSE = S(-4, 0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -10);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -1);

inline const PParam PAWN_THREAT_KNIGHT = S(211, 93);
inline const PParam PAWN_THREAT_BISHOP = S(205, 135);
inline const PParam PAWN_THREAT_ROOK   = S(199, 122);
inline const PParam PAWN_THREAT_QUEEN  = S(182, -17);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 74);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -21);

inline const PParam BISHOP_THREAT_KNIGHT = S(103, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 87);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(12, -32), S(-3, -3), S(-5, -12), S(-8, -22), S(-11, -32), S(-14, -40), S(-15, -52), S(-21, -53), S(-36, -48),
};

inline const PParam ROOK_LINEUP = S(14, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(328, 321),    S(135, 409),    S(267, 383),    S(272, 298),    S(313, 237),    S(202, 331),    S(136, 379),    S(296, 299),    //
    S(108, 211),    S(128, 235),    S(143, 183),    S(120, 139),    S(115, 111),    S(84, 168),     S(66, 218),     S(38, 240),     //
    S(92, 158),     S(71, 172),     S(103, 124),    S(87, 109),     S(81, 98),      S(58, 128),     S(9, 176),      S(11, 197),     //
    S(61, 106),     S(39, 139),     S(66, 109),     S(55, 106),     S(32, 108),     S(26, 131),     S(-32, 169),    S(-22, 159),    //
    S(59, 81),      S(86, 87),      S(71, 125),     S(61, 125),     S(31, 122),     S(14, 131),     S(-24, 151),    S(-21, 141),    //
    S(77, 83),      S(152, 95),     S(136, 139),    S(93, 146),     S(64, 135),     S(44, 132),     S(10, 153),     S(-1, 152),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-219, -148),  S(-156, 183),   S(-53, -24),    S(104, 190),    S(37, 186),     S(-95, 175),    S(-269, 235),   S(-286, -57),   //
    S(77, 143),     S(102, 174),    S(217, 149),    S(223, 171),    S(220, 176),    S(145, 191),    S(80, 185),     S(61, 156),     //
    S(139, 149),    S(181, 135),    S(203, 214),    S(219, 215),    S(187, 239),    S(140, 233),    S(134, 167),    S(85, 160),     //
    S(209, 170),    S(223, 192),    S(230, 228),    S(231, 260),    S(238, 260),    S(194, 243),    S(173, 201),    S(156, 176),    //
    S(190, 167),    S(233, 151),    S(214, 217),    S(210, 237),    S(189, 239),    S(194, 223),    S(183, 169),    S(138, 177),    //
    S(130, 126),    S(153, 152),    S(153, 190),    S(167, 214),    S(162, 211),    S(134, 191),    S(128, 156),    S(88, 121),     //
    S(147, 131),    S(159, 128),    S(134, 142),    S(141, 167),    S(138, 165),    S(112, 122),    S(91, 145),     S(76, 61),      //
    S(81, 63),      S(129, 125),    S(144, 106),    S(160, 111),    S(144, 130),    S(109, 107),    S(98, 119),     S(59, 29),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(3, 289),      S(-7, 300),     S(-286, 355),   S(-134, 298),   S(-126, 297),   S(-147, 290),   S(-46, 285),    S(31, 267),     //
    S(112, 215),    S(79, 283),     S(110, 245),    S(57, 274),     S(79, 265),     S(102, 250),    S(140, 239),    S(115, 205),    //
    S(179, 234),    S(173, 249),    S(186, 266),    S(171, 272),    S(153, 266),    S(163, 260),    S(176, 233),    S(170, 215),    //
    S(167, 213),    S(202, 233),    S(212, 257),    S(210, 302),    S(244, 281),    S(191, 247),    S(196, 214),    S(156, 207),    //
    S(203, 167),    S(204, 213),    S(224, 243),    S(229, 273),    S(212, 278),    S(206, 260),    S(175, 224),    S(170, 185),    //
    S(220, 185),    S(236, 202),    S(247, 234),    S(211, 260),    S(205, 241),    S(206, 248),    S(217, 225),    S(169, 210),    //
    S(180, 151),    S(265, 167),    S(229, 186),    S(206, 208),    S(189, 211),    S(196, 187),    S(194, 179),    S(196, 174),    //
    S(207, 152),    S(192, 180),    S(197, 200),    S(212, 180),    S(197, 190),    S(201, 226),    S(202, 205),    S(197, 178),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(411, 396),    S(446, 407),    S(397, 427),    S(400, 395),    S(433, 395),    S(401, 401),    S(415, 415),    S(401, 417),    //
    S(300, 465),    S(387, 460),    S(448, 431),    S(384, 445),    S(423, 439),    S(392, 445),    S(338, 471),    S(322, 472),    //
    S(262, 466),    S(385, 443),    S(430, 407),    S(400, 405),    S(399, 426),    S(352, 449),    S(355, 450),    S(293, 480),    //
    S(231, 443),    S(318, 443),    S(344, 421),    S(320, 429),    S(355, 415),    S(312, 446),    S(317, 443),    S(243, 468),    //
    S(208, 378),    S(284, 389),    S(273, 404),    S(246, 404),    S(261, 408),    S(252, 429),    S(228, 425),    S(211, 421),    //
    S(227, 293),    S(300, 317),    S(289, 334),    S(266, 335),    S(280, 338),    S(248, 373),    S(260, 346),    S(220, 354),    //
    S(132, 297),    S(275, 258),    S(273, 286),    S(264, 308),    S(269, 313),    S(256, 326),    S(250, 310),    S(220, 322),    //
    S(197, 281),    S(222, 302),    S(279, 291),    S(291, 285),    S(292, 296),    S(273, 314),    S(270, 308),    S(251, 311),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(537, 667),    S(629, 619),    S(546, 722),    S(500, 782),    S(529, 757),    S(536, 724),    S(556, 652),    S(476, 728),    //
    S(518, 722),    S(532, 808),    S(501, 828),    S(371, 901),    S(411, 902),    S(453, 864),    S(503, 756),    S(483, 749),    //
    S(483, 763),    S(515, 797),    S(482, 859),    S(438, 888),    S(448, 900),    S(502, 819),    S(523, 758),    S(528, 687),    //
    S(507, 645),    S(501, 741),    S(461, 798),    S(444, 857),    S(452, 886),    S(489, 781),    S(532, 713),    S(508, 684),    //
    S(507, 620),    S(487, 685),    S(467, 739),    S(446, 796),    S(456, 833),    S(473, 794),    S(496, 717),    S(515, 652),    //
    S(495, 557),    S(515, 586),    S(510, 661),    S(490, 677),    S(493, 705),    S(495, 742),    S(512, 692),    S(505, 647),    //
    S(470, 438),    S(498, 449),    S(505, 505),    S(524, 563),    S(513, 618),    S(513, 605),    S(483, 651),    S(501, 627),    //
    S(457, 455),    S(486, 312),    S(509, 334),    S(523, 444),    S(516, 541),    S(525, 496),    S(520, 524),    S(494, 555),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-21, -170),   S(320, 281),    S(211, 289),    S(84, 186),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(237, 63),     S(364, 225),    S(219, 267),    S(162, 152),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(164, 116),    S(258, 192),    S(171, 213),    S(121, 144),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-10, 59),     S(144, 113),    S(28, 165),     S(19, 160),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-101, -25),   S(30, 25),      S(-24, 78),     S(-100, 132),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-41, -69),    S(52, -21),     S(-27, 43),     S(-73, 87),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -107),    S(57, -55),     S(-14, -8),     S(-76, 31),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-57, -150),   S(9, -102),     S(-78, -61),    S(-75, -80),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -33), S(0, -26), S(-1, -35), S(8, -62), S(7, -67), S(-2, -31), S(2, -26), }},
  {{ S(1, 22), S(-23, 8), S(-16, -1), S(-4, -24), S(-4, -19), S(-15, 1), S(-21, 12), }},
  {{ S(3, 3), S(-9, -3), S(-3, -13), S(2, -32), S(3, -31), S(-3, -12), S(-7, -3), }},
  {{ S(8, 15), S(-6, -13), S(3, -6), S(7, -16), S(6, -16), S(2, -7), S(-4, -9), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(8, 7), S(-10, 0), S(-7, -0), S(0, 9), S(3, -24),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 32), S(-8, 19), S(-7, 14), S(-5, 4), S(-6, 2), S(-6, 14), S(-8, 19), }},
  {{ S(7, -19), S(1, -30), S(-7, -31), S(-5, -53), S(-5, -54), S(-6, -34), S(1, -30), }},
  {{ S(1, -2), S(-2, -13), S(-6, -14), S(-3, -24), S(-3, -29), S(-6, -17), S(-2, -13), }},
  {{ S(0, -8), S(-6, -9), S(-9, -18), S(-3, -17), S(-2, -16), S(-8, -17), S(-7, -10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1297, 1952, -15, -30
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(247);
inline VParam WINNABLE_BIAS = V(-648);

// Epoch duration: 9.89795s
// clang-format on
}  // namespace Clockwork
