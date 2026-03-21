#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(136, 203);
inline const PParam KNIGHT_MAT = S(594, 635);
inline const PParam BISHOP_MAT = S(611, 652);
inline const PParam ROOK_MAT   = S(573, 872);
inline const PParam QUEEN_MAT  = S(1116, 1096);
inline const PParam TEMPO_VAL  = S(57, 21);

inline const PParam BISHOP_PAIR_VAL   = S(52, 199);
inline const PParam ROOK_OPEN_VAL     = S(105, -15);
inline const PParam ROOK_SEMIOPEN_VAL = S(40, 22);
inline const PParam MINOR_BEHIND_PAWN = S(8, 42);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -72);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(38, 66);
inline const PParam OUTPOST_BISHOP_VAL    = S(55, 41);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 7);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -24);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(24, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -37);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, 2), S(38, 25), S(58, 48), S(133, 143), S(379, 202), S(444, 710),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 34), S(44, 27), S(54, 54), S(117, 140), S(401, 90),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-70, -124), S(-69, -100), S(-48, 11), S(7, 118), S(92, 265), S(264, 379),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -43), S(35, -4), S(22, 33), S(-0, 112), S(50, 217), S(203, 279),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(20, -30), S(2, 19), S(2, -11), S(0, -41), S(-8, -113), S(-215, -217),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-6, 148), S(-17, 113), S(-11, 45), S(-4, 8), S(2, 7), S(38, 5), S(10, 1),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-310, -58), S(-42, 28), S(-24, 60), S(14, 97), S(31, 114), S(48, 116), S(30, 108),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(77, 10), S(146, 178), S(157, 261), S(184, 295), S(224, 312), S(247, 343), S(278, 339), S(308, 353), S(361, 264),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(99, -6), S(148, 169), S(181, 232), S(209, 277), S(234, 310), S(251, 334), S(261, 354), S(275, 364), S(284, 382), S(311, 362), S(325, 364), S(373, 312), S(374, 329), S(407, 268),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(264, 503), S(294, 546), S(318, 552), S(346, 579), S(366, 602), S(378, 621), S(394, 639), S(409, 647), S(420, 667), S(434, 677), S(452, 679), S(463, 689), S(474, 689), S(493, 668), S(590, 564),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(660, 389), S(658, 525), S(668, 623), S(685, 732), S(689, 806), S(698, 840), S(702, 876), S(708, 888), S(712, 912), S(714, 927), S(720, 934), S(724, 942), S(732, 937), S(735, 940), S(740, 935), S(739, 937), S(741, 933), S(747, 927), S(752, 921), S(762, 914), S(771, 889), S(790, 852), S(786, 854), S(784, 799), S(767, 791), S(760, 762), S(704, 793), S(722, 727),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(512, -171), S(136, -110), S(63, -32), S(12, 7), S(-8, 7), S(-24, 0), S(-32, 8), S(-48, 15), S(-37, -25),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(15, -15), S(13, -12), S(6, -8), S(2, 173),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 415),
};

inline const PParam PAWN_THREAT_KNIGHT = S(210, 91);
inline const PParam PAWN_THREAT_BISHOP = S(193, 141);
inline const PParam PAWN_THREAT_ROOK   = S(191, 125);
inline const PParam PAWN_THREAT_QUEEN  = S(168, -21);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(222, 72);
inline const PParam KNIGHT_THREAT_QUEEN  = S(153, -8);

inline const PParam BISHOP_THREAT_KNIGHT = S(104, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(207, 129);
inline const PParam BISHOP_THREAT_QUEEN  = S(176, 95);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -34), S(-3, -6), S(-5, -14), S(-8, -23), S(-12, -31), S(-16, -35), S(-18, -47), S(-25, -43), S(-36, -44),
};

inline const PParam ROOK_LINEUP = S(13, 66);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(307, 334),    S(157, 437),    S(295, 409),    S(287, 292),    S(317, 238),    S(215, 322),    S(159, 354),    S(267, 306),    //
    S(119, 208),    S(150, 249),    S(187, 165),    S(171, 105),    S(151, 87),     S(125, 138),    S(99, 193),     S(49, 219),     //
    S(84, 172),     S(71, 176),     S(113, 102),    S(112, 80),     S(100, 77),     S(73, 110),     S(25, 159),     S(12, 187),     //
    S(58, 124),     S(48, 149),     S(81, 96),      S(79, 88),      S(58, 92),      S(40, 117),     S(-19, 161),    S(-20, 152),    //
    S(56, 99),      S(94, 106),     S(77, 135),     S(71, 122),     S(42, 118),     S(20, 126),     S(-14, 143),    S(-21, 136),    //
    S(64, 102),     S(157, 115),    S(141, 170),    S(93, 153),     S(65, 140),     S(42, 135),     S(14, 148),     S(-7, 151),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-274, -89),   S(-155, 184),   S(-112, 57),    S(97, 173),     S(27, 182),     S(-116, 187),   S(-254, 236),   S(-310, -19),   //
    S(70, 159),     S(117, 184),    S(216, 145),    S(214, 150),    S(208, 161),    S(121, 194),    S(76, 200),     S(47, 175),     //
    S(157, 142),    S(212, 143),    S(225, 204),    S(229, 191),    S(187, 231),    S(129, 240),    S(126, 185),    S(84, 164),     //
    S(218, 165),    S(230, 185),    S(230, 218),    S(214, 250),    S(215, 261),    S(173, 244),    S(162, 205),    S(153, 175),    //
    S(196, 169),    S(237, 158),    S(207, 220),    S(203, 238),    S(179, 242),    S(178, 229),    S(176, 174),    S(133, 174),    //
    S(149, 137),    S(173, 155),    S(165, 195),    S(170, 220),    S(166, 219),    S(130, 201),    S(121, 165),    S(91, 126),     //
    S(149, 139),    S(171, 134),    S(144, 150),    S(148, 176),    S(139, 175),    S(110, 132),    S(96, 144),     S(84, 58),      //
    S(81, 72),      S(118, 145),    S(142, 123),    S(160, 123),    S(143, 146),    S(110, 119),    S(84, 128),     S(58, 40),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-4, 289),     S(-10, 306),    S(-266, 341),   S(-139, 284),   S(-148, 304),   S(-158, 300),   S(-40, 299),    S(26, 269),     //
    S(128, 203),    S(77, 285),     S(115, 236),    S(62, 252),     S(77, 253),     S(100, 257),    S(134, 253),    S(104, 228),    //
    S(193, 221),    S(209, 239),    S(210, 246),    S(190, 251),    S(161, 248),    S(169, 252),    S(178, 239),    S(169, 210),    //
    S(166, 213),    S(199, 223),    S(205, 247),    S(200, 290),    S(231, 278),    S(164, 251),    S(172, 215),    S(132, 216),    //
    S(191, 172),    S(210, 209),    S(213, 234),    S(217, 260),    S(193, 275),    S(178, 256),    S(149, 232),    S(142, 187),    //
    S(216, 181),    S(251, 200),    S(260, 223),    S(204, 250),    S(199, 228),    S(194, 241),    S(203, 221),    S(145, 211),    //
    S(177, 143),    S(276, 161),    S(234, 183),    S(202, 204),    S(183, 209),    S(186, 184),    S(186, 176),    S(181, 171),    //
    S(209, 145),    S(190, 174),    S(192, 204),    S(206, 179),    S(200, 188),    S(200, 225),    S(194, 207),    S(189, 172),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(517, 524),    S(524, 550),    S(502, 562),    S(526, 518),    S(511, 518),    S(479, 527),    S(471, 546),    S(468, 545),    //
    S(393, 609),    S(463, 609),    S(540, 572),    S(487, 576),    S(471, 585),    S(453, 587),    S(388, 618),    S(375, 621),    //
    S(363, 604),    S(454, 597),    S(514, 555),    S(492, 539),    S(444, 568),    S(406, 590),    S(412, 585),    S(349, 627),    //
    S(362, 565),    S(433, 576),    S(473, 544),    S(445, 550),    S(437, 559),    S(399, 581),    S(396, 576),    S(322, 607),    //
    S(345, 496),    S(409, 510),    S(398, 530),    S(376, 529),    S(353, 553),    S(344, 564),    S(314, 560),    S(296, 557),    //
    S(343, 438),    S(402, 464),    S(388, 488),    S(373, 487),    S(360, 496),    S(335, 519),    S(334, 492),    S(301, 500),    //
    S(232, 447),    S(366, 415),    S(379, 443),    S(368, 467),    S(352, 472),    S(344, 476),    S(327, 461),    S(302, 471),    //
    S(301, 439),    S(329, 456),    S(387, 447),    S(396, 444),    S(386, 451),    S(365, 467),    S(355, 463),    S(335, 474),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(542, 642),    S(594, 593),    S(515, 720),    S(489, 782),    S(475, 764),    S(513, 700),    S(530, 631),    S(477, 673),    //
    S(547, 693),    S(509, 792),    S(497, 826),    S(356, 919),    S(365, 903),    S(427, 854),    S(474, 722),    S(483, 706),    //
    S(512, 757),    S(558, 779),    S(493, 880),    S(442, 898),    S(417, 893),    S(471, 806),    S(507, 725),    S(524, 650),    //
    S(550, 677),    S(553, 767),    S(493, 834),    S(483, 868),    S(477, 861),    S(487, 770),    S(529, 704),    S(516, 665),    //
    S(563, 649),    S(554, 715),    S(526, 769),    S(497, 813),    S(496, 813),    S(498, 760),    S(517, 675),    S(540, 606),    //
    S(543, 592),    S(581, 635),    S(572, 704),    S(544, 699),    S(541, 686),    S(534, 713),    S(549, 629),    S(524, 608),    //
    S(524, 486),    S(568, 486),    S(573, 551),    S(584, 589),    S(571, 618),    S(565, 579),    S(528, 618),    S(535, 601),    //
    S(497, 516),    S(539, 353),    S(566, 360),    S(582, 464),    S(578, 539),    S(577, 486),    S(559, 520),    S(523, 559),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-59, -343),   S(270, 190),    S(150, 142),    S(4, -8),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(236, -79),    S(323, 184),    S(186, 167),    S(122, -1),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(222, 23),     S(371, 110),    S(262, 109),    S(174, -6),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(79, -7),      S(337, 37),     S(188, 57),     S(122, 22),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-28, -26),    S(235, 4),      S(162, 13),     S(52, 17),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-32, -15),    S(211, -4),     S(118, 4),      S(69, -15),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-9, -17),     S(82, 35),      S(0, 36),       S(-55, 11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-129, -66),   S(-24, -20),    S(-122, -16),   S(-123, -88),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(14, -15), S(-4, 20), S(-8, 22), S(-1, 7), S(-1, 4), S(-8, 21), S(-2, 21), }},
  {{ S(4, -3), S(-23, 29), S(-20, 23), S(-10, 5), S(-10, 5), S(-19, 27), S(-22, 37), }},
  {{ S(-13, 1), S(-24, 26), S(-22, 7), S(-18, -7), S(-18, -5), S(-22, 7), S(-22, 22), }},
  {{ S(-0, -14), S(-18, -14), S(-9, -18), S(-4, -22), S(-5, -20), S(-10, -15), S(-14, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(6, 25), S(-16, 34), S(-14, 24), S(-6, 11), S(-6, -4),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-3, 6), S(-13, 14), S(-12, 13), S(-11, 13), S(-11, 8), S(-9, 3), S(-12, 12), }},
  {{ S(-1, 4), S(-9, 11), S(-16, 16), S(-13, 13), S(-13, 9), S(-15, 12), S(-9, 10), }},
  {{ S(-8, 8), S(-12, 6), S(-13, 13), S(-9, 12), S(-9, 12), S(-13, 11), S(-12, 7), }},
  {{ S(-9, 11), S(-14, 13), S(-14, 12), S(-9, 16), S(-8, 16), S(-13, 12), S(-15, 12), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1195, 553, -34, 46
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(224);
inline VParam WINNABLE_BIAS = V(-655);

// Epoch duration: 7.58714s

// Epoch duration: 7.72358s
// clang-format on
}  // namespace Clockwork
