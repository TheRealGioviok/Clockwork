#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(134, 209);
inline const PParam KNIGHT_MAT = S(568, 621);
inline const PParam BISHOP_MAT = S(609, 648);
inline const PParam ROOK_MAT   = S(473, 680);
inline const PParam QUEEN_MAT  = S(1107, 1085);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(52, 198);
inline const PParam ROOK_OPEN_VAL     = S(106, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 23);

inline const PParam DOUBLED_PAWN_VAL = S(-6, -78);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -14);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 66);
inline const PParam OUTPOST_BISHOP_VAL    = S(48, 42);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -19);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(23, 59);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(66, -32);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(17, -2), S(42, 15), S(63, 32), S(137, 117), S(361, 173), S(476, 624),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 27), S(47, 16), S(53, 58), S(95, 217), S(463, 368),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-86, -173), S(-81, -167), S(-68, -44), S(-11, 89), S(84, 269), S(254, 377),
};
inline const std::array<PParam, 5> CANDIDATE_PASSED_PAWN = {
    S(-50, 27), S(-29, 7), S(-12, 44), S(7, 47), S(73, 62),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(31, -53), S(35, -23), S(27, 19), S(6, 96), S(45, 217), S(202, 271),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(8, -9), S(2, 17), S(2, -12), S(-4, -44), S(-6, -124), S(-209, -236),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-11, 165), S(-10, 138), S(-6, 63), S(2, 16), S(6, 12), S(42, 14), S(24, 12),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-299, -68), S(-27, 26), S(-7, 64), S(26, 116), S(44, 145), S(54, 153), S(45, 140),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(61, -1), S(132, 171), S(167, 260), S(195, 296), S(235, 315), S(260, 348), S(291, 347), S(323, 360), S(375, 277),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(89, -2), S(132, 174), S(187, 237), S(214, 282), S(239, 313), S(255, 337), S(263, 357), S(276, 367), S(283, 385), S(307, 367), S(318, 370), S(364, 320), S(361, 337), S(393, 284),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(308, 243), S(228, 420), S(253, 445), S(271, 454), S(282, 467), S(288, 478), S(294, 488), S(303, 490), S(309, 501), S(320, 502), S(331, 504), S(339, 509), S(344, 508), S(358, 483), S(444, 378),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(492, 501), S(631, 526), S(656, 637), S(674, 750), S(690, 794), S(699, 839), S(705, 871), S(712, 882), S(716, 905), S(720, 919), S(725, 926), S(730, 933), S(738, 928), S(741, 932), S(745, 929), S(743, 933), S(746, 927), S(751, 924), S(758, 914), S(768, 907), S(774, 887), S(798, 844), S(792, 850), S(793, 792), S(780, 780), S(774, 749), S(702, 814), S(733, 707),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(463, -0), S(96, -93), S(20, -13), S(10, 16), S(-7, 15), S(-20, 1), S(-18, 1), S(-26, -1), S(-11, -53),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(11, -4), S(15, -14), S(13, -11), S(6, -7), S(2, 200),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, 0), S(7, -10), S(5, -8), S(5, -5), S(6, 421),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 93);
inline const PParam PAWN_THREAT_BISHOP = S(190, 145);
inline const PParam PAWN_THREAT_ROOK   = S(189, 129);
inline const PParam PAWN_THREAT_QUEEN  = S(165, -11);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 100);
inline const PParam KNIGHT_THREAT_ROOK   = S(227, 66);
inline const PParam KNIGHT_THREAT_QUEEN  = S(152, -6);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 124);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 98);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -18), S(-9, -29), S(-13, -39), S(-17, -45), S(-19, -58), S(-26, -56), S(-37, -57),
};

inline const PParam ROOK_LINEUP = S(12, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(289, 336),    S(145, 453),    S(289, 411),    S(283, 292),    S(309, 241),    S(210, 314),    S(157, 341),    S(258, 286),    //
    S(117, 191),    S(138, 246),    S(180, 152),    S(159, 93),     S(141, 73),     S(121, 116),    S(95, 174),     S(53, 194),     //
    S(82, 177),     S(66, 186),     S(108, 110),    S(109, 88),     S(97, 87),      S(70, 116),     S(24, 164),     S(14, 188),     //
    S(56, 137),     S(43, 171),     S(78, 116),     S(74, 109),     S(53, 113),     S(37, 136),     S(-21, 178),    S(-19, 165),    //
    S(54, 113),     S(92, 131),     S(77, 156),     S(68, 145),     S(40, 140),     S(18, 146),     S(-14, 163),    S(-20, 149),    //
    S(69, 107),     S(160, 130),    S(145, 180),    S(94, 165),     S(65, 153),     S(44, 148),     S(17, 161),     S(-1, 157),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-248, -73),   S(-152, 197),   S(-91, 45),     S(93, 191),     S(39, 182),     S(-113, 195),   S(-240, 239),   S(-286, 2),     //
    S(75, 167),     S(121, 187),    S(204, 154),    S(199, 162),    S(197, 167),    S(118, 188),    S(77, 208),     S(52, 181),     //
    S(162, 162),    S(210, 155),    S(213, 208),    S(213, 194),    S(173, 229),    S(112, 247),    S(123, 194),    S(92, 179),     //
    S(232, 179),    S(240, 199),    S(236, 224),    S(224, 255),    S(224, 263),    S(180, 248),    S(172, 217),    S(169, 184),    //
    S(214, 184),    S(249, 168),    S(220, 224),    S(215, 244),    S(192, 248),    S(189, 234),    S(187, 183),    S(150, 188),    //
    S(159, 150),    S(184, 160),    S(175, 198),    S(183, 225),    S(179, 224),    S(143, 204),    S(133, 172),    S(104, 138),    //
    S(170, 155),    S(191, 153),    S(159, 161),    S(161, 184),    S(152, 182),    S(124, 140),    S(112, 161),    S(97, 85),      //
    S(106, 104),    S(151, 170),    S(167, 136),    S(183, 129),    S(164, 152),    S(131, 124),    S(117, 150),    S(79, 71),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(0, 286),      S(-16, 301),    S(-274, 341),   S(-141, 280),   S(-148, 298),   S(-168, 302),   S(-52, 301),    S(30, 271),     //
    S(120, 202),    S(61, 283),     S(95, 236),     S(43, 253),     S(57, 254),     S(80, 256),     S(118, 252),    S(94, 229),     //
    S(191, 231),    S(204, 244),    S(199, 249),    S(173, 252),    S(145, 247),    S(154, 253),    S(169, 246),    S(164, 222),    //
    S(160, 225),    S(196, 233),    S(197, 256),    S(196, 289),    S(227, 277),    S(155, 258),    S(168, 221),    S(127, 220),    //
    S(191, 179),    S(205, 216),    S(211, 238),    S(216, 264),    S(192, 280),    S(176, 260),    S(144, 236),    S(140, 195),    //
    S(215, 190),    S(248, 203),    S(260, 229),    S(205, 256),    S(200, 234),    S(195, 246),    S(201, 223),    S(142, 220),    //
    S(181, 161),    S(280, 181),    S(237, 194),    S(204, 213),    S(184, 216),    S(188, 192),    S(188, 190),    S(182, 186),    //
    S(213, 165),    S(200, 184),    S(199, 217),    S(213, 178),    S(202, 190),    S(203, 231),    S(199, 211),    S(191, 190),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(422, 382),    S(441, 395),    S(409, 415),    S(435, 372),    S(421, 373),    S(382, 390),    S(378, 405),    S(372, 408),    //
    S(300, 465),    S(379, 456),    S(452, 426),    S(403, 427),    S(387, 437),    S(366, 442),    S(299, 474),    S(283, 479),    //
    S(271, 460),    S(373, 445),    S(431, 405),    S(412, 390),    S(364, 420),    S(322, 443),    S(326, 439),    S(257, 484),    //
    S(276, 420),    S(354, 426),    S(388, 402),    S(365, 402),    S(356, 413),    S(315, 438),    S(311, 433),    S(238, 460),    //
    S(258, 352),    S(326, 365),    S(313, 388),    S(291, 386),    S(269, 410),    S(259, 422),    S(230, 414),    S(208, 414),    //
    S(252, 292),    S(313, 319),    S(300, 346),    S(283, 346),    S(272, 351),    S(246, 375),    S(243, 351),    S(209, 358),    //
    S(144, 305),    S(277, 267),    S(287, 299),    S(277, 321),    S(262, 327),    S(254, 333),    S(236, 318),    S(212, 328),    //
    S(209, 290),    S(232, 310),    S(289, 300),    S(300, 297),    S(289, 306),    S(270, 320),    S(259, 316),    S(239, 326),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(556, 639),    S(611, 580),    S(533, 705),    S(493, 785),    S(478, 769),    S(524, 697),    S(545, 620),    S(496, 661),    //
    S(555, 696),    S(516, 793),    S(506, 828),    S(366, 914),    S(375, 899),    S(440, 845),    S(481, 724),    S(491, 706),    //
    S(517, 765),    S(565, 784),    S(496, 889),    S(448, 901),    S(419, 902),    S(474, 813),    S(512, 730),    S(533, 648),    //
    S(557, 683),    S(560, 774),    S(498, 843),    S(492, 865),    S(484, 863),    S(495, 771),    S(538, 702),    S(523, 671),    //
    S(573, 647),    S(560, 721),    S(530, 777),    S(499, 822),    S(499, 820),    S(502, 767),    S(519, 690),    S(546, 613),    //
    S(552, 593),    S(586, 645),    S(576, 715),    S(547, 706),    S(544, 692),    S(538, 719),    S(554, 636),    S(533, 607),    //
    S(534, 479),    S(574, 484),    S(575, 559),    S(586, 598),    S(573, 625),    S(568, 589),    S(531, 627),    S(540, 608),    //
    S(516, 494),    S(548, 343),    S(573, 357),    S(584, 475),    S(581, 548),    S(580, 494),    S(567, 521),    S(537, 547),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-47, -356),   S(300, 159),    S(175, 118),    S(47, -39),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(238, -80),    S(345, 175),    S(203, 164),    S(131, 13),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(237, 24),     S(377, 129),    S(275, 119),    S(176, 16),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(101, -8),     S(340, 62),     S(192, 77),     S(130, 40),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-4, -31),     S(237, 26),     S(166, 29),     S(48, 39),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-11, -25),    S(211, 11),     S(112, 18),     S(58, 5),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(5, -30),      S(75, 45),      S(-9, 44),      S(-67, 26),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-105, -87),   S(-11, -34),    S(-112, -30),   S(-115, -96),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -12), S(-1, 22), S(-4, 22), S(3, 6), S(3, 3), S(-4, 20), S(1, 23), }},
  {{ S(7, -4), S(-20, 27), S(-16, 21), S(-7, 1), S(-6, 1), S(-15, 24), S(-19, 35), }},
  {{ S(-14, 4), S(-26, 28), S(-24, 10), S(-20, -4), S(-20, -3), S(-23, 10), S(-24, 24), }},
  {{ S(4, -15), S(-15, -15), S(-6, -19), S(-1, -24), S(-2, -22), S(-7, -17), S(-10, -17), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(6, 24), S(-17, 31), S(-15, 23), S(-8, 14), S(-10, 2),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, 2), S(-14, 14), S(-13, 13), S(-12, 12), S(-12, 6), S(-11, 2), S(-14, 12), }},
  {{ S(-4, 2), S(-11, 10), S(-18, 14), S(-14, 10), S(-14, 6), S(-16, 10), S(-10, 9), }},
  {{ S(-10, 7), S(-14, 8), S(-15, 14), S(-11, 12), S(-10, 11), S(-15, 11), S(-13, 8), }},
  {{ S(-10, 11), S(-15, 14), S(-16, 13), S(-11, 15), S(-9, 16), S(-15, 12), S(-16, 13), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1234, 612, -35, 50
);

inline VParam WINNABLE_PAWNS = V(-13);
inline VParam WINNABLE_SYM = V(132);
inline VParam WINNABLE_ASYM = V(123);
inline VParam WINNABLE_PAWN_ENDGAME = V(220);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 7.46153s

// Epoch duration: 7.52381s
// clang-format on
}  // namespace Clockwork
