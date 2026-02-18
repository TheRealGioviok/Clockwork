#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 203);
inline const PParam KNIGHT_MAT = S(571, 620);
inline const PParam BISHOP_MAT = S(606, 649);
inline const PParam ROOK_MAT   = S(466, 678);
inline const PParam QUEEN_MAT  = S(1092, 1086);
inline const PParam TEMPO_VAL  = S(57, 21);

inline const PParam BISHOP_PAIR_VAL   = S(54, 194);
inline const PParam ROOK_OPEN_VAL     = S(105, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 22);
inline const PParam MINOR_BEHIND_PAWN = S(10, 41);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(36, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 42);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 6);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(52, -23);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -38);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -0), S(38, 24), S(57, 48), S(133, 144), S(378, 203), S(456, 691),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 34), S(44, 27), S(53, 55), S(115, 142), S(399, 95),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-71, -122), S(-69, -99), S(-47, 11), S(7, 118), S(91, 267), S(263, 379),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -44), S(34, -4), S(22, 32), S(1, 110), S(45, 223), S(196, 289),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(22, -31), S(3, 20), S(3, -12), S(2, -42), S(-5, -116), S(-212, -222),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-6, 148), S(-17, 113), S(-12, 45), S(-4, 9), S(1, 8), S(37, 6), S(10, 1),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-309, -59), S(-41, 27), S(-24, 59), S(13, 96), S(31, 113), S(49, 114), S(31, 106),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(61, 13), S(131, 178), S(165, 268), S(192, 302), S(232, 319), S(255, 352), S(287, 348), S(317, 361), S(369, 275),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(82, -8), S(126, 167), S(181, 232), S(208, 277), S(232, 309), S(249, 333), S(256, 352), S(270, 362), S(276, 380), S(301, 361), S(311, 363), S(358, 312), S(356, 328), S(388, 273),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(314, 249), S(232, 423), S(257, 450), S(275, 460), S(285, 473), S(291, 484), S(297, 494), S(306, 496), S(311, 506), S(322, 507), S(334, 509), S(341, 514), S(347, 513), S(364, 485), S(447, 382),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(493, 523), S(636, 536), S(661, 647), S(679, 760), S(694, 806), S(703, 851), S(709, 883), S(716, 893), S(720, 918), S(723, 931), S(728, 939), S(732, 947), S(741, 940), S(743, 946), S(748, 940), S(746, 943), S(748, 940), S(754, 935), S(762, 923), S(770, 918), S(780, 893), S(802, 853), S(800, 851), S(797, 799), S(785, 785), S(779, 753), S(711, 813), S(735, 718),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(490, -181), S(109, -107), S(29, -24), S(15, 8), S(-5, 8), S(-20, 1), S(-27, 9), S(-42, 15), S(-30, -25),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(15, -15), S(13, -12), S(6, -8), S(2, 189),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 392),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 92);
inline const PParam PAWN_THREAT_BISHOP = S(189, 141);
inline const PParam PAWN_THREAT_ROOK   = S(190, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(166, -14);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 99);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 71);
inline const PParam KNIGHT_THREAT_QUEEN  = S(150, 2);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 103);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -33), S(-3, -6), S(-5, -14), S(-8, -23), S(-12, -31), S(-16, -35), S(-18, -46), S(-25, -43), S(-36, -43),
};

inline const PParam ROOK_LINEUP = S(12, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(297, 343),    S(149, 445),    S(290, 415),    S(297, 284),    S(320, 238),    S(214, 323),    S(157, 356),    S(264, 308),    //
    S(117, 208),    S(149, 249),    S(187, 166),    S(172, 105),    S(153, 86),     S(125, 139),    S(99, 194),     S(48, 220),     //
    S(81, 173),     S(70, 176),     S(112, 102),    S(112, 81),     S(100, 79),     S(73, 111),     S(25, 160),     S(11, 187),     //
    S(56, 125),     S(47, 150),     S(81, 97),      S(79, 89),      S(57, 94),      S(39, 118),     S(-20, 162),    S(-20, 153),    //
    S(55, 100),     S(92, 108),     S(76, 137),     S(69, 124),     S(41, 119),     S(19, 127),     S(-15, 144),    S(-23, 137),    //
    S(66, 102),     S(155, 118),    S(139, 173),    S(90, 155),     S(61, 143),     S(40, 137),     S(12, 150),     S(-6, 151),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-253, -72),   S(-145, 191),   S(-97, 52),     S(105, 180),    S(34, 192),     S(-109, 193),   S(-244, 242),   S(-290, -1),    //
    S(75, 167),     S(118, 193),    S(209, 153),    S(203, 163),    S(198, 172),    S(113, 200),    S(77, 209),     S(49, 187),     //
    S(155, 152),    S(201, 152),    S(207, 212),    S(211, 201),    S(170, 238),    S(110, 247),    S(116, 190),    S(80, 179),     //
    S(226, 175),    S(234, 195),    S(233, 224),    S(218, 257),    S(218, 267),    S(176, 249),    S(166, 213),    S(160, 186),    //
    S(209, 179),    S(245, 166),    S(214, 225),    S(209, 243),    S(186, 247),    S(185, 234),    S(182, 181),    S(145, 184),    //
    S(156, 146),    S(181, 163),    S(170, 202),    S(177, 227),    S(174, 225),    S(138, 206),    S(129, 174),    S(101, 136),    //
    S(162, 151),    S(183, 144),    S(152, 158),    S(155, 185),    S(148, 184),    S(120, 139),    S(106, 154),    S(95, 69),      //
    S(95, 91),      S(142, 163),    S(156, 131),    S(175, 132),    S(156, 156),    S(124, 127),    S(108, 145),    S(69, 56),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-2, 298),     S(-16, 309),    S(-270, 348),   S(-142, 290),   S(-149, 308),   S(-161, 304),   S(-49, 304),    S(30, 278),     //
    S(119, 213),    S(64, 292),     S(96, 245),     S(45, 261),     S(60, 262),     S(82, 263),     S(122, 258),    S(96, 237),     //
    S(184, 227),    S(196, 247),    S(194, 253),    S(173, 257),    S(145, 253),    S(153, 256),    S(165, 246),    S(158, 217),    //
    S(159, 223),    S(193, 230),    S(196, 254),    S(193, 293),    S(222, 284),    S(154, 258),    S(165, 220),    S(125, 222),    //
    S(189, 178),    S(206, 215),    S(211, 239),    S(212, 267),    S(189, 282),    S(175, 261),    S(145, 235),    S(139, 191),    //
    S(215, 186),    S(249, 206),    S(258, 230),    S(202, 257),    S(197, 234),    S(193, 246),    S(202, 225),    S(141, 216),    //
    S(177, 152),    S(275, 170),    S(233, 192),    S(201, 213),    S(182, 217),    S(186, 191),    S(186, 182),    S(181, 175),    //
    S(209, 158),    S(197, 181),    S(194, 212),    S(211, 184),    S(201, 195),    S(200, 234),    S(197, 214),    S(188, 180),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(424, 386),    S(438, 404),    S(413, 418),    S(433, 380),    S(415, 384),    S(379, 397),    S(375, 413),    S(368, 416),    //
    S(300, 470),    S(376, 467),    S(451, 432),    S(399, 436),    S(385, 444),    S(364, 449),    S(298, 479),    S(280, 486),    //
    S(271, 463),    S(370, 451),    S(429, 412),    S(410, 398),    S(360, 429),    S(319, 452),    S(323, 447),    S(256, 488),    //
    S(275, 421),    S(349, 434),    S(387, 405),    S(361, 410),    S(352, 420),    S(313, 442),    S(309, 436),    S(234, 466),    //
    S(257, 355),    S(321, 372),    S(309, 393),    S(289, 391),    S(266, 415),    S(256, 427),    S(225, 422),    S(206, 418),    //
    S(250, 298),    S(310, 326),    S(295, 352),    S(282, 349),    S(269, 359),    S(243, 381),    S(241, 356),    S(207, 363),    //
    S(142, 310),    S(272, 277),    S(283, 306),    S(273, 329),    S(258, 335),    S(251, 338),    S(233, 324),    S(209, 335),    //
    S(206, 296),    S(229, 316),    S(285, 306),    S(298, 303),    S(287, 311),    S(267, 326),    S(256, 323),    S(236, 332),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(553, 642),    S(605, 593),    S(526, 722),    S(493, 792),    S(477, 776),    S(515, 714),    S(534, 639),    S(490, 673),    //
    S(552, 699),    S(515, 798),    S(505, 830),    S(361, 926),    S(368, 915),    S(432, 861),    S(476, 737),    S(485, 716),    //
    S(515, 766),    S(560, 791),    S(494, 894),    S(445, 909),    S(419, 904),    S(471, 821),    S(508, 739),    S(528, 658),    //
    S(553, 686),    S(556, 776),    S(493, 848),    S(486, 875),    S(477, 875),    S(489, 780),    S(530, 717),    S(518, 676),    //
    S(568, 654),    S(556, 726),    S(527, 781),    S(497, 824),    S(496, 827),    S(498, 772),    S(517, 690),    S(543, 614),    //
    S(548, 597),    S(584, 644),    S(573, 716),    S(544, 711),    S(541, 699),    S(535, 723),    S(551, 640),    S(528, 616),    //
    S(530, 485),    S(566, 498),    S(571, 565),    S(583, 603),    S(570, 631),    S(564, 595),    S(527, 633),    S(537, 612),    //
    S(512, 498),    S(544, 347),    S(567, 370),    S(582, 478),    S(577, 555),    S(575, 502),    S(564, 526),    S(532, 555),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-60, -325),   S(287, 175),    S(156, 136),    S(29, -31),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(231, -67),    S(348, 160),    S(201, 154),    S(119, 3),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(224, 28),     S(381, 105),    S(266, 108),    S(161, 7),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(80, -3),      S(334, 42),     S(181, 64),     S(118, 27),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -26),    S(233, 7),      S(159, 17),     S(43, 24),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-26, -15),    S(210, -2),     S(112, 9),      S(62, -9),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-5, -17),     S(80, 37),      S(-4, 40),      S(-60, 15),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-118, -69),   S(-18, -22),    S(-120, -15),   S(-122, -87),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(11, -18), S(-7, 18), S(-11, 20), S(-4, 5), S(-4, 2), S(-11, 19), S(-5, 19), }},
  {{ S(1, -5), S(-27, 28), S(-23, 21), S(-13, 3), S(-13, 4), S(-22, 26), S(-26, 36), }},
  {{ S(-9, -3), S(-21, 22), S(-19, 3), S(-15, -11), S(-15, -9), S(-18, 3), S(-19, 19), }},
  {{ S(-4, -15), S(-21, -15), S(-12, -19), S(-7, -23), S(-8, -21), S(-13, -17), S(-17, -16), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(4, 23), S(-19, 34), S(-16, 23), S(-8, 11), S(-8, -5),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, 5), S(-15, 14), S(-13, 12), S(-12, 13), S(-13, 7), S(-11, 3), S(-15, 12), }},
  {{ S(-3, 4), S(-11, 10), S(-18, 15), S(-15, 12), S(-15, 9), S(-17, 12), S(-11, 9), }},
  {{ S(-10, 8), S(-14, 6), S(-15, 13), S(-11, 12), S(-11, 11), S(-15, 11), S(-14, 6), }},
  {{ S(-10, 10), S(-15, 12), S(-16, 11), S(-11, 15), S(-10, 15), S(-15, 11), S(-17, 11), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1190, 548, -25, 54
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(138);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(225);
inline VParam WINNABLE_BIAS = V(-657);

// Epoch duration: 7.63952s
// clang-format on
}  // namespace Clockwork
