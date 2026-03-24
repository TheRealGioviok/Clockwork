#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(138, 205);
inline const PParam KNIGHT_MAT = S(581, 627);
inline const PParam BISHOP_MAT = S(607, 647);
inline const PParam ROOK_MAT   = S(471, 678);
inline const PParam QUEEN_MAT  = S(1099, 1085);
inline const PParam TEMPO_VAL  = S(58, 22);

inline const PParam BISHOP_PAIR_VAL   = S(54, 193);
inline const PParam ROOK_OPEN_VAL     = S(104, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 23);
inline const PParam MINOR_BEHIND_PAWN = S(10, 40);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -18);
inline const PParam PRESSURED_CHAIN_BASE = S(-8, -20);

inline const PParam POTENTIAL_CHECKER_VAL = S(-50, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(37, 62);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(52, -25);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(25, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -1), S(38, 23), S(57, 47), S(133, 144), S(377, 200), S(447, 693),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 33), S(45, 25), S(53, 52), S(114, 140), S(398, 92),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -123), S(-68, -100), S(-48, 10), S(7, 116), S(88, 265), S(265, 379),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(36, -41), S(33, -1), S(21, 34), S(-1, 111), S(48, 221), S(202, 283),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -29), S(2, 22), S(3, -10), S(1, -41), S(-4, -117), S(-215, -220),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-5, 148), S(-16, 112), S(-12, 47), S(-4, 11), S(2, 9), S(37, 8), S(11, 2),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-308, -53), S(-39, 30), S(-23, 60), S(14, 97), S(32, 115), S(49, 115), S(31, 108),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(54, 2), S(123, 170), S(157, 260), S(184, 294), S(224, 311), S(248, 343), S(279, 338), S(310, 350), S(361, 266),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(82, -7), S(125, 168), S(181, 233), S(207, 277), S(232, 310), S(248, 334), S(256, 352), S(270, 362), S(275, 378), S(300, 360), S(311, 360), S(358, 310), S(360, 317), S(384, 275),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(312, 251), S(230, 422), S(255, 449), S(272, 459), S(283, 472), S(289, 483), S(295, 493), S(303, 494), S(309, 504), S(320, 505), S(332, 506), S(339, 511), S(344, 508), S(362, 479), S(445, 380),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(489, 535), S(633, 535), S(658, 648), S(676, 760), S(691, 805), S(699, 849), S(706, 880), S(713, 890), S(716, 915), S(720, 928), S(725, 934), S(729, 943), S(738, 936), S(740, 940), S(745, 934), S(744, 936), S(746, 932), S(752, 925), S(759, 914), S(768, 909), S(778, 881), S(799, 844), S(798, 841), S(795, 788), S(784, 773), S(776, 743), S(711, 795), S(733, 705),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(490, -177), S(113, -113), S(32, -29), S(18, 5), S(-4, 6), S(-21, 1), S(-28, 10), S(-43, 17), S(-34, -22),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -9), S(16, -16), S(14, -12), S(6, -8), S(2, 213),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 411),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 90);
inline const PParam PAWN_THREAT_BISHOP = S(189, 139);
inline const PParam PAWN_THREAT_ROOK   = S(191, 127);
inline const PParam PAWN_THREAT_QUEEN  = S(168, -17);

inline const PParam KNIGHT_THREAT_BISHOP = S(108, 100);
inline const PParam KNIGHT_THREAT_ROOK   = S(224, 70);
inline const PParam KNIGHT_THREAT_QUEEN  = S(152, -5);

inline const PParam BISHOP_THREAT_KNIGHT = S(106, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 101);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -34), S(-3, -6), S(-5, -13), S(-8, -23), S(-11, -32), S(-17, -36), S(-18, -48), S(-25, -45), S(-36, -44),
};

inline const PParam ROOK_LINEUP = S(13, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(299, 341),    S(151, 445),    S(293, 419),    S(300, 289),    S(326, 241),    S(220, 324),    S(160, 357),    S(265, 306),    //
    S(118, 211),    S(152, 254),    S(190, 171),    S(176, 110),    S(157, 92),     S(127, 145),    S(102, 198),    S(49, 222),     //
    S(82, 174),     S(71, 180),     S(112, 105),    S(112, 85),     S(100, 83),     S(73, 115),     S(26, 165),     S(12, 188),     //
    S(56, 124),     S(46, 151),     S(80, 98),      S(78, 92),      S(56, 97),      S(38, 121),     S(-21, 166),    S(-22, 154),    //
    S(54, 99),      S(91, 109),     S(74, 139),     S(67, 126),     S(40, 121),     S(18, 129),     S(-16, 148),    S(-24, 137),    //
    S(65, 100),     S(155, 118),    S(137, 174),    S(88, 155),     S(60, 143),     S(38, 136),     S(10, 150),     S(-7, 150),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-254, -77),   S(-147, 188),   S(-90, 38),     S(100, 179),    S(32, 186),     S(-112, 188),   S(-245, 240),   S(-289, -8),    //
    S(75, 163),     S(120, 187),    S(208, 148),    S(202, 158),    S(200, 165),    S(111, 194),    S(78, 204),     S(49, 183),     //
    S(154, 147),    S(202, 146),    S(206, 205),    S(210, 195),    S(170, 230),    S(111, 238),    S(116, 185),    S(79, 176),     //
    S(224, 173),    S(232, 190),    S(231, 219),    S(217, 250),    S(218, 258),    S(174, 241),    S(166, 206),    S(160, 180),    //
    S(208, 178),    S(244, 163),    S(214, 221),    S(209, 239),    S(185, 242),    S(184, 228),    S(181, 177),    S(143, 182),    //
    S(156, 144),    S(180, 161),    S(169, 200),    S(177, 224),    S(173, 222),    S(137, 205),    S(128, 170),    S(100, 133),    //
    S(161, 150),    S(182, 142),    S(152, 157),    S(154, 183),    S(147, 182),    S(119, 137),    S(105, 153),    S(94, 67),      //
    S(93, 93),      S(141, 162),    S(156, 129),    S(174, 129),    S(155, 152),    S(123, 123),    S(107, 142),    S(68, 53),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-2, 298),     S(-13, 301),    S(-269, 341),   S(-142, 286),   S(-152, 307),   S(-161, 300),   S(-49, 300),    S(31, 274),     //
    S(119, 212),    S(64, 292),     S(98, 240),     S(47, 257),     S(61, 258),     S(82, 260),     S(124, 257),    S(97, 234),     //
    S(185, 226),    S(197, 245),    S(195, 251),    S(174, 254),    S(144, 251),    S(153, 254),    S(165, 245),    S(159, 216),    //
    S(160, 220),    S(194, 227),    S(196, 251),    S(194, 289),    S(224, 280),    S(155, 254),    S(166, 215),    S(126, 218),    //
    S(189, 175),    S(207, 212),    S(212, 237),    S(214, 263),    S(189, 280),    S(176, 257),    S(145, 233),    S(140, 189),    //
    S(215, 184),    S(250, 204),    S(259, 228),    S(202, 255),    S(198, 232),    S(192, 244),    S(202, 222),    S(142, 214),    //
    S(177, 151),    S(275, 169),    S(234, 189),    S(202, 210),    S(183, 213),    S(186, 187),    S(185, 181),    S(181, 173),    //
    S(209, 157),    S(197, 178),    S(194, 209),    S(211, 181),    S(201, 192),    S(200, 230),    S(198, 210),    S(188, 178),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(427, 374),    S(437, 396),    S(411, 410),    S(431, 371),    S(415, 371),    S(374, 390),    S(377, 402),    S(371, 405),    //
    S(305, 462),    S(380, 455),    S(456, 422),    S(403, 425),    S(387, 435),    S(365, 440),    S(299, 470),    S(282, 481),    //
    S(275, 458),    S(375, 443),    S(433, 404),    S(412, 391),    S(362, 423),    S(320, 445),    S(324, 440),    S(260, 482),    //
    S(276, 421),    S(352, 428),    S(389, 402),    S(364, 405),    S(356, 416),    S(315, 439),    S(310, 434),    S(236, 464),    //
    S(258, 356),    S(322, 372),    S(311, 393),    S(291, 390),    S(267, 415),    S(257, 425),    S(226, 421),    S(206, 420),    //
    S(250, 301),    S(310, 327),    S(297, 351),    S(282, 350),    S(270, 358),    S(244, 380),    S(242, 354),    S(207, 365),    //
    S(143, 312),    S(274, 276),    S(285, 307),    S(275, 328),    S(260, 334),    S(251, 338),    S(234, 323),    S(209, 336),    //
    S(207, 299),    S(230, 317),    S(286, 309),    S(299, 306),    S(288, 312),    S(268, 328),    S(257, 324),    S(237, 334),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(556, 629),    S(601, 587),    S(524, 711),    S(492, 779),    S(477, 760),    S(516, 697),    S(531, 633),    S(491, 661),    //
    S(553, 693),    S(516, 793),    S(504, 825),    S(360, 920),    S(372, 900),    S(432, 854),    S(479, 726),    S(487, 711),    //
    S(516, 767),    S(562, 788),    S(495, 894),    S(447, 903),    S(422, 895),    S(472, 817),    S(508, 736),    S(529, 657),    //
    S(555, 688),    S(557, 781),    S(497, 843),    S(488, 874),    S(479, 873),    S(490, 779),    S(533, 712),    S(519, 679),    //
    S(570, 656),    S(557, 729),    S(529, 780),    S(497, 827),    S(497, 827),    S(500, 769),    S(519, 688),    S(544, 615),    //
    S(550, 598),    S(584, 649),    S(574, 718),    S(546, 710),    S(543, 696),    S(536, 722),    S(552, 637),    S(529, 616),    //
    S(530, 490),    S(569, 499),    S(573, 564),    S(585, 601),    S(572, 630),    S(566, 592),    S(528, 633),    S(539, 610),    //
    S(513, 504),    S(545, 352),    S(568, 372),    S(583, 480),    S(578, 554),    S(577, 500),    S(565, 524),    S(534, 557),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-59, -319),   S(290, 177),    S(159, 138),    S(29, -26),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(231, -62),    S(355, 154),    S(208, 150),    S(124, -1),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(227, 29),     S(387, 100),    S(276, 101),    S(172, -3),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(84, -4),      S(339, 37),     S(191, 58),     S(125, 22),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-21, -23),    S(238, 3),      S(163, 14),     S(50, 20),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-25, -12),    S(211, -3),     S(115, 8),      S(64, -11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-7, -11),     S(82, 36),      S(-2, 39),      S(-59, 13),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-121, -62),   S(-19, -20),    S(-121, -13),   S(-124, -86),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(14, -20), S(-4, 15), S(-8, 19), S(-0, 4), S(-1, 0), S(-8, 17), S(-2, 17), }},
  {{ S(4, -7), S(-24, 28), S(-20, 21), S(-11, 3), S(-10, 3), S(-19, 25), S(-23, 35), }},
  {{ S(-15, 0), S(-26, 27), S(-24, 7), S(-20, -6), S(-20, -6), S(-23, 7), S(-24, 23), }},
  {{ S(-0, -17), S(-18, -17), S(-9, -21), S(-4, -25), S(-5, -23), S(-10, -19), S(-14, -19), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(7, 25), S(-16, 34), S(-13, 22), S(-5, 10), S(-5, -7),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 5), S(-12, 13), S(-10, 11), S(-10, 12), S(-10, 6), S(-8, 1), S(-12, 10), }},
  {{ S(-0, 3), S(-8, 9), S(-15, 14), S(-12, 11), S(-11, 7), S(-14, 11), S(-8, 8), }},
  {{ S(-7, 7), S(-11, 5), S(-12, 12), S(-8, 11), S(-8, 10), S(-12, 10), S(-11, 5), }},
  {{ S(-7, 10), S(-13, 11), S(-13, 10), S(-8, 14), S(-6, 15), S(-13, 11), S(-14, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1149, 529, -35, 56
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(222);
inline VParam WINNABLE_BIAS = V(-654);

// clang-format on
}  // namespace Clockwork
