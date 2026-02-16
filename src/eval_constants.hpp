#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(137, 197);
inline const PParam KNIGHT_MAT = S(570, 628);
inline const PParam BISHOP_MAT = S(603, 654);
inline const PParam ROOK_MAT   = S(470, 684);
inline const PParam QUEEN_MAT  = S(1101, 1091);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(53, 196);
inline const PParam ROOK_OPEN_VAL     = S(106, -11);
inline const PParam ROOK_SEMIOPEN_VAL = S(44, 22);

inline const PParam DOUBLED_PAWN_VAL = S(-10, -58);
inline const PParam ISOLATED_PAWN_VAL = S(-20, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -25);
inline const PParam OUTPOST_KNIGHT_VAL    = S(35, 65);
inline const PParam OUTPOST_BISHOP_VAL    = S(49, 41);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(42, 8);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(23, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -36);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, 5), S(39, 27), S(61, 41), S(138, 113), S(346, 205), S(465, 674),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(53, 36), S(44, 27), S(55, 52), S(120, 129), S(409, 82),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-74, -123), S(-72, -105), S(-51, 9), S(5, 123), S(102, 275), S(262, 382),
};
inline const std::array<PParam, 5> CANDIDATE_PASSED_PAWN = {
    S(-53, 27), S(-33, 18), S(-15, 58), S(3, 63), S(60, 102),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(34, -46), S(36, -9), S(22, 31), S(1, 109), S(47, 219), S(198, 283),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(10, -17), S(2, 19), S(2, -12), S(-3, -48), S(-10, -122), S(-213, -231),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-8, 156), S(-15, 121), S(-9, 50), S(-2, 11), S(1, 11), S(40, 8), S(10, 6),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-301, -57), S(-39, 30), S(-24, 65), S(13, 105), S(32, 122), S(50, 123), S(32, 113),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(62, -3), S(132, 170), S(167, 260), S(194, 296), S(235, 314), S(259, 350), S(291, 347), S(322, 361), S(375, 275),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(91, 1), S(135, 174), S(189, 237), S(216, 283), S(241, 315), S(257, 339), S(264, 359), S(278, 369), S(283, 387), S(308, 368), S(318, 372), S(367, 320), S(364, 335), S(397, 279),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(310, 244), S(230, 423), S(254, 447), S(272, 457), S(283, 470), S(289, 480), S(295, 491), S(304, 493), S(310, 503), S(321, 505), S(333, 506), S(340, 511), S(345, 510), S(361, 483), S(447, 379),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(491, 516), S(632, 535), S(657, 644), S(675, 755), S(690, 802), S(699, 846), S(705, 878), S(713, 889), S(717, 912), S(720, 927), S(726, 934), S(730, 942), S(739, 935), S(741, 940), S(746, 935), S(744, 938), S(746, 935), S(752, 928), S(757, 922), S(768, 914), S(776, 891), S(799, 849), S(797, 848), S(794, 794), S(783, 780), S(777, 748), S(709, 810), S(732, 714),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(505, -212), S(104, -101), S(25, -20), S(14, 12), S(-5, 11), S(-20, 2), S(-23, 8), S(-36, 11), S(-23, -34),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -6), S(16, -15), S(13, -12), S(6, -8), S(2, 193),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -10), S(6, -8), S(5, -5), S(6, 429),
};

inline const PParam PAWN_THREAT_KNIGHT = S(213, 92);
inline const PParam PAWN_THREAT_BISHOP = S(190, 144);
inline const PParam PAWN_THREAT_ROOK   = S(190, 126);
inline const PParam PAWN_THREAT_QUEEN  = S(166, -15);

inline const PParam KNIGHT_THREAT_BISHOP = S(109, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(226, 68);
inline const PParam KNIGHT_THREAT_QUEEN  = S(151, -2);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 58);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 100);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(9, -36), S(-4, -9), S(-6, -18), S(-9, -28), S(-13, -37), S(-18, -42), S(-20, -55), S(-27, -52), S(-39, -52),
};

inline const PParam ROOK_LINEUP = S(12, 67);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(300, 341),    S(152, 447),    S(296, 415),    S(294, 290),    S(318, 242),    S(215, 321),    S(156, 353),    S(265, 305),    //
    S(113, 201),    S(139, 244),    S(176, 164),    S(156, 101),    S(140, 78),     S(115, 132),    S(86, 187),     S(44, 213),     //
    S(84, 168),     S(69, 176),     S(110, 104),    S(111, 79),     S(99, 74),      S(72, 107),     S(22, 157),     S(12, 182),     //
    S(59, 123),     S(49, 149),     S(85, 99),      S(81, 88),      S(59, 90),      S(42, 116),     S(-19, 159),    S(-18, 150),    //
    S(59, 97),      S(99, 105),     S(83, 136),     S(75, 122),     S(47, 117),     S(24, 123),     S(-11, 140),    S(-19, 133),    //
    S(72, 95),      S(164, 111),    S(149, 167),    S(97, 150),     S(69, 137),     S(48, 131),     S(18, 143),     S(-1, 145),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-248, -77),   S(-146, 186),   S(-98, 49),     S(92, 188),     S(33, 187),     S(-115, 194),   S(-238, 233),   S(-286, -7),    //
    S(74, 165),     S(119, 187),    S(207, 146),    S(198, 158),    S(196, 164),    S(112, 191),    S(75, 206),     S(49, 183),     //
    S(161, 157),    S(207, 154),    S(208, 211),    S(208, 198),    S(170, 230),    S(110, 245),    S(122, 190),    S(87, 182),     //
    S(228, 181),    S(236, 200),    S(233, 225),    S(220, 256),    S(221, 264),    S(176, 248),    S(169, 217),    S(164, 188),    //
    S(212, 183),    S(246, 168),    S(217, 224),    S(213, 244),    S(189, 248),    S(187, 233),    S(184, 182),    S(147, 190),    //
    S(157, 148),    S(182, 160),    S(173, 197),    S(181, 224),    S(177, 223),    S(141, 203),    S(130, 171),    S(102, 137),    //
    S(168, 153),    S(190, 150),    S(157, 159),    S(159, 182),    S(150, 181),    S(122, 138),    S(110, 159),    S(97, 78),      //
    S(103, 105),    S(149, 170),    S(164, 136),    S(180, 130),    S(162, 153),    S(129, 126),    S(114, 150),    S(76, 72),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(1, 288),      S(-15, 302),    S(-271, 340),   S(-138, 281),   S(-146, 298),   S(-165, 300),   S(-48, 297),    S(32, 270),     //
    S(121, 204),    S(62, 285),     S(97, 236),     S(44, 253),     S(61, 251),     S(83, 254),     S(121, 250),    S(97, 228),     //
    S(193, 231),    S(205, 244),    S(198, 253),    S(175, 252),    S(147, 246),    S(154, 256),    S(169, 248),    S(165, 220),    //
    S(162, 224),    S(198, 233),    S(199, 253),    S(196, 291),    S(226, 280),    S(157, 256),    S(169, 220),    S(126, 223),    //
    S(191, 181),    S(207, 215),    S(213, 238),    S(217, 266),    S(193, 281),    S(178, 258),    S(145, 237),    S(142, 193),    //
    S(217, 190),    S(250, 202),    S(262, 229),    S(207, 255),    S(203, 232),    S(197, 245),    S(204, 221),    S(145, 217),    //
    S(183, 161),    S(282, 179),    S(239, 194),    S(207, 211),    S(187, 215),    S(190, 191),    S(191, 188),    S(185, 182),    //
    S(215, 165),    S(202, 182),    S(201, 217),    S(215, 180),    S(205, 190),    S(205, 231),    S(202, 211),    S(193, 187),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(425, 382),    S(439, 401),    S(411, 418),    S(434, 376),    S(412, 384),    S(378, 395),    S(375, 410),    S(371, 411),    //
    S(301, 466),    S(377, 463),    S(453, 428),    S(399, 432),    S(384, 441),    S(365, 444),    S(296, 479),    S(281, 482),    //
    S(270, 461),    S(373, 447),    S(430, 407),    S(410, 395),    S(360, 425),    S(320, 446),    S(323, 444),    S(256, 485),    //
    S(276, 419),    S(352, 428),    S(386, 404),    S(362, 406),    S(352, 418),    S(312, 440),    S(309, 434),    S(236, 461),    //
    S(258, 351),    S(324, 367),    S(311, 390),    S(290, 387),    S(267, 411),    S(257, 424),    S(228, 417),    S(208, 414),    //
    S(250, 295),    S(312, 322),    S(298, 348),    S(282, 347),    S(270, 355),    S(245, 376),    S(242, 352),    S(207, 360),    //
    S(143, 306),    S(275, 271),    S(286, 301),    S(274, 327),    S(260, 330),    S(252, 334),    S(234, 321),    S(210, 330),    //
    S(207, 292),    S(231, 311),    S(287, 302),    S(299, 298),    S(288, 307),    S(268, 322),    S(257, 317),    S(238, 328),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(552, 645),    S(602, 595),    S(525, 721),    S(493, 789),    S(479, 771),    S(513, 715),    S(535, 636),    S(492, 669),    //
    S(553, 696),    S(515, 794),    S(504, 830),    S(362, 922),    S(368, 912),    S(432, 860),    S(476, 734),    S(486, 713),    //
    S(515, 765),    S(563, 782),    S(491, 896),    S(445, 906),    S(417, 905),    S(468, 824),    S(505, 742),    S(526, 658),    //
    S(554, 685),    S(559, 771),    S(496, 842),    S(487, 872),    S(479, 871),    S(489, 779),    S(533, 709),    S(519, 676),    //
    S(570, 651),    S(556, 725),    S(527, 781),    S(497, 823),    S(495, 825),    S(498, 771),    S(516, 691),    S(543, 614),    //
    S(549, 595),    S(584, 644),    S(574, 716),    S(544, 709),    S(541, 695),    S(535, 723),    S(551, 638),    S(530, 611),    //
    S(532, 480),    S(569, 493),    S(573, 562),    S(584, 601),    S(571, 627),    S(565, 593),    S(527, 632),    S(538, 610),    //
    S(513, 498),    S(546, 342),    S(569, 364),    S(583, 475),    S(578, 552),    S(577, 497),    S(565, 522),    S(534, 552),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-62, -333),   S(287, 172),    S(162, 128),    S(39, -37),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(230, -74),    S(345, 161),    S(198, 158),    S(119, 7),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(224, 23),     S(379, 106),    S(267, 108),    S(167, 6),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(83, -11),     S(332, 42),     S(176, 67),     S(115, 32),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -31),    S(227, 11),     S(152, 22),     S(37, 30),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -21),    S(207, 1),      S(109, 12),     S(57, -3),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-1, -22),     S(79, 39),      S(-6, 42),      S(-63, 20),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-112, -75),   S(-16, -26),    S(-117, -18),   S(-119, -87),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(18, -15), S(-0, 20), S(-4, 23), S(4, 7), S(4, 4), S(-3, 21), S(2, 21), }},
  {{ S(8, -4), S(-19, 29), S(-16, 23), S(-6, 5), S(-5, 5), S(-15, 26), S(-18, 36), }},
  {{ S(-14, 4), S(-25, 30), S(-23, 11), S(-19, -2), S(-19, -1), S(-23, 11), S(-23, 26), }},
  {{ S(4, -14), S(-14, -14), S(-5, -17), S(0, -21), S(-1, -19), S(-6, -15), S(-9, -15), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 18), S(-15, 30), S(-13, 19), S(-6, 7), S(-7, -8),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 2), S(-12, 10), S(-11, 9), S(-9, 9), S(-10, 3), S(-8, -0), S(-12, 8), }},
  {{ S(-1, 1), S(-8, 7), S(-15, 12), S(-12, 9), S(-11, 5), S(-14, 9), S(-8, 6), }},
  {{ S(-7, 5), S(-12, 3), S(-13, 9), S(-8, 8), S(-8, 7), S(-12, 7), S(-11, 3), }},
  {{ S(-8, 7), S(-13, 9), S(-14, 8), S(-8, 12), S(-7, 12), S(-13, 9), S(-14, 8), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1182, 567, -44, 55
);

inline VParam WINNABLE_PAWNS = V(-10);
inline VParam WINNABLE_SYM = V(126);
inline VParam WINNABLE_ASYM = V(119);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-655);

// Epoch duration: 7.71418s
// clang-format on
}  // namespace Clockwork
