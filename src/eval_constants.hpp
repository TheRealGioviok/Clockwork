#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(138, 205);
inline const PParam KNIGHT_MAT = S(581, 628);
inline const PParam BISHOP_MAT = S(607, 648);
inline const PParam ROOK_MAT   = S(471, 677);
inline const PParam QUEEN_MAT  = S(1100, 1084);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(54, 193);
inline const PParam ROOK_OPEN_VAL     = S(104, -12);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 22);
inline const PParam MINOR_BEHIND_PAWN = S(10, 40);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -73);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -17);
inline const PParam PRESSURED_CHAIN_BASE = S(-8, -21);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -24);
inline const PParam OUTPOST_KNIGHT_VAL    = S(37, 62);
inline const PParam OUTPOST_BISHOP_VAL    = S(51, 44);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(41, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(52, -25);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(26, 54);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(67, -40);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(16, -1), S(38, 23), S(57, 47), S(133, 144), S(377, 199), S(447, 694),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(54, 33), S(45, 25), S(53, 52), S(114, 139), S(398, 91),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-72, -123), S(-69, -100), S(-48, 10), S(7, 116), S(88, 265), S(264, 379),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(35, -40), S(33, -1), S(21, 34), S(-1, 111), S(48, 221), S(202, 284),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(21, -30), S(2, 22), S(3, -11), S(1, -41), S(-4, -117), S(-214, -220),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-5, 147), S(-16, 112), S(-12, 47), S(-4, 11), S(2, 9), S(37, 8), S(10, 4),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-309, -54), S(-40, 30), S(-23, 60), S(14, 98), S(32, 115), S(49, 116), S(31, 108),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(54, 3), S(124, 170), S(157, 260), S(184, 295), S(224, 311), S(248, 342), S(279, 338), S(310, 350), S(361, 266),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(82, -7), S(125, 168), S(180, 233), S(207, 278), S(232, 310), S(248, 333), S(256, 352), S(269, 362), S(275, 379), S(300, 359), S(311, 360), S(358, 310), S(360, 317), S(384, 275),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(311, 250), S(230, 423), S(255, 449), S(272, 459), S(283, 472), S(289, 483), S(295, 492), S(303, 494), S(309, 504), S(320, 505), S(331, 506), S(339, 510), S(344, 508), S(362, 479), S(445, 380),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(489, 535), S(633, 535), S(658, 648), S(676, 759), S(691, 805), S(700, 849), S(706, 880), S(713, 890), S(717, 915), S(720, 928), S(725, 934), S(729, 942), S(738, 936), S(740, 940), S(745, 934), S(744, 936), S(746, 932), S(752, 925), S(760, 914), S(768, 909), S(779, 882), S(799, 844), S(798, 841), S(795, 788), S(784, 772), S(776, 743), S(712, 793), S(734, 704),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(489, -177), S(111, -110), S(30, -26), S(16, 7), S(-4, 7), S(-20, 1), S(-27, 9), S(-42, 14), S(-31, -26),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(12, -8), S(15, -15), S(13, -12), S(6, -8), S(2, 213),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -0), S(7, -11), S(6, -9), S(5, -5), S(6, 411),
};

inline const PParam PAWN_THREAT_KNIGHT = S(211, 91);
inline const PParam PAWN_THREAT_BISHOP = S(189, 138);
inline const PParam PAWN_THREAT_ROOK   = S(191, 128);
inline const PParam PAWN_THREAT_QUEEN  = S(168, -18);

inline const PParam KNIGHT_THREAT_BISHOP = S(107, 100);
inline const PParam KNIGHT_THREAT_ROOK   = S(224, 70);
inline const PParam KNIGHT_THREAT_QUEEN  = S(152, -5);

inline const PParam BISHOP_THREAT_KNIGHT = S(105, 59);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 126);
inline const PParam BISHOP_THREAT_QUEEN  = S(175, 102);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(11, -34), S(-3, -6), S(-5, -14), S(-8, -23), S(-12, -32), S(-16, -36), S(-18, -48), S(-25, -45), S(-36, -44),
};

inline const PParam ROOK_LINEUP = S(13, 65);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(299, 341),    S(150, 446),    S(293, 419),    S(300, 290),    S(326, 241),    S(220, 324),    S(160, 357),    S(266, 305),    //
    S(117, 211),    S(151, 254),    S(189, 172),    S(175, 111),    S(157, 92),     S(126, 145),    S(102, 198),    S(49, 222),     //
    S(82, 174),     S(71, 180),     S(112, 106),    S(112, 85),     S(100, 83),     S(73, 115),     S(26, 165),     S(12, 188),     //
    S(56, 124),     S(46, 151),     S(79, 99),      S(78, 92),      S(56, 97),      S(38, 121),     S(-21, 166),    S(-21, 153),    //
    S(54, 99),      S(91, 108),     S(74, 139),     S(67, 126),     S(40, 122),     S(17, 129),     S(-16, 148),    S(-24, 138),    //
    S(65, 100),     S(154, 118),    S(137, 174),    S(88, 156),     S(60, 143),     S(38, 136),     S(11, 150),     S(-7, 149),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-254, -78),   S(-148, 190),   S(-90, 37),     S(100, 179),    S(31, 186),     S(-112, 189),   S(-245, 239),   S(-290, -7),    //
    S(75, 164),     S(119, 188),    S(208, 149),    S(202, 159),    S(200, 164),    S(112, 193),    S(78, 204),     S(49, 184),     //
    S(154, 148),    S(201, 147),    S(206, 205),    S(210, 196),    S(170, 230),    S(110, 239),    S(116, 185),    S(78, 176),     //
    S(225, 173),    S(232, 190),    S(231, 219),    S(217, 250),    S(218, 258),    S(174, 242),    S(166, 205),    S(160, 181),    //
    S(208, 178),    S(244, 162),    S(213, 221),    S(209, 239),    S(185, 243),    S(184, 228),    S(181, 178),    S(143, 181),    //
    S(156, 144),    S(181, 161),    S(169, 200),    S(177, 223),    S(173, 222),    S(137, 205),    S(129, 171),    S(101, 132),    //
    S(161, 150),    S(182, 142),    S(152, 156),    S(154, 183),    S(147, 182),    S(119, 137),    S(105, 153),    S(95, 67),      //
    S(93, 93),      S(141, 162),    S(155, 129),    S(174, 129),    S(155, 152),    S(123, 123),    S(107, 142),    S(68, 53),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-3, 299),     S(-13, 301),    S(-269, 341),   S(-143, 287),   S(-152, 306),   S(-161, 300),   S(-49, 301),    S(31, 273),     //
    S(119, 213),    S(63, 293),     S(98, 240),     S(47, 258),     S(61, 257),     S(82, 261),     S(123, 257),    S(98, 234),     //
    S(185, 226),    S(196, 245),    S(194, 252),    S(174, 253),    S(144, 251),    S(154, 254),    S(164, 246),    S(159, 216),    //
    S(160, 221),    S(194, 227),    S(196, 251),    S(193, 289),    S(224, 280),    S(155, 254),    S(166, 216),    S(126, 218),    //
    S(190, 175),    S(207, 212),    S(211, 237),    S(214, 263),    S(189, 280),    S(176, 257),    S(145, 233),    S(140, 188),    //
    S(216, 184),    S(250, 204),    S(259, 228),    S(202, 255),    S(198, 232),    S(193, 244),    S(202, 222),    S(142, 214),    //
    S(177, 151),    S(275, 169),    S(234, 189),    S(202, 210),    S(183, 213),    S(186, 187),    S(186, 180),    S(181, 173),    //
    S(210, 156),    S(198, 179),    S(194, 209),    S(211, 180),    S(201, 192),    S(200, 230),    S(198, 210),    S(188, 178),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(427, 374),    S(437, 396),    S(411, 410),    S(430, 371),    S(415, 371),    S(375, 389),    S(377, 402),    S(372, 404),    //
    S(304, 462),    S(380, 455),    S(456, 422),    S(402, 425),    S(386, 434),    S(365, 440),    S(299, 471),    S(283, 480),    //
    S(274, 458),    S(374, 443),    S(433, 404),    S(412, 391),    S(361, 423),    S(320, 445),    S(324, 440),    S(260, 482),    //
    S(277, 421),    S(352, 429),    S(389, 402),    S(364, 405),    S(355, 416),    S(315, 439),    S(309, 435),    S(236, 464),    //
    S(258, 356),    S(322, 372),    S(311, 392),    S(291, 390),    S(267, 415),    S(257, 426),    S(226, 421),    S(206, 420),    //
    S(250, 300),    S(310, 327),    S(297, 351),    S(282, 350),    S(270, 358),    S(244, 380),    S(242, 354),    S(207, 365),    //
    S(143, 312),    S(274, 276),    S(285, 307),    S(275, 328),    S(259, 334),    S(251, 339),    S(234, 324),    S(209, 336),    //
    S(207, 299),    S(231, 318),    S(286, 309),    S(299, 305),    S(288, 312),    S(268, 328),    S(257, 324),    S(237, 334),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(556, 628),    S(601, 586),    S(524, 711),    S(492, 778),    S(477, 760),    S(516, 696),    S(531, 633),    S(490, 662),    //
    S(553, 693),    S(516, 791),    S(504, 824),    S(360, 920),    S(371, 900),    S(432, 854),    S(479, 725),    S(487, 711),    //
    S(516, 766),    S(562, 788),    S(495, 894),    S(446, 903),    S(422, 896),    S(472, 817),    S(509, 736),    S(529, 657),    //
    S(555, 688),    S(556, 781),    S(498, 842),    S(488, 873),    S(479, 873),    S(490, 779),    S(533, 711),    S(519, 679),    //
    S(569, 656),    S(557, 729),    S(529, 780),    S(497, 827),    S(496, 827),    S(500, 770),    S(519, 689),    S(544, 615),    //
    S(550, 598),    S(584, 649),    S(574, 718),    S(545, 710),    S(542, 697),    S(536, 722),    S(552, 637),    S(529, 616),    //
    S(531, 490),    S(569, 500),    S(574, 564),    S(585, 602),    S(572, 630),    S(566, 592),    S(528, 632),    S(539, 610),    //
    S(513, 505),    S(545, 352),    S(568, 373),    S(583, 480),    S(579, 555),    S(577, 500),    S(566, 524),    S(534, 557),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-56, -323),   S(292, 175),    S(161, 135),    S(32, -30),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(232, -64),    S(355, 156),    S(207, 150),    S(124, -0),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(229, 27),     S(388, 103),    S(275, 102),    S(173, -2),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(87, -6),      S(342, 39),     S(192, 60),     S(125, 23),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -25),    S(241, 5),      S(165, 15),     S(50, 21),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-24, -13),    S(213, -1),     S(115, 8),      S(65, -11),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-7, -13),     S(81, 38),      S(-4, 40),      S(-60, 15),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-120, -64),   S(-20, -21),    S(-122, -14),   S(-124, -87),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(14, -19), S(-4, 16), S(-8, 18), S(-0, 4), S(-1, 1), S(-8, 17), S(-2, 17), }},
  {{ S(4, -7), S(-23, 26), S(-20, 20), S(-10, 2), S(-10, 2), S(-19, 24), S(-22, 34), }},
  {{ S(-14, 0), S(-25, 26), S(-24, 7), S(-20, -7), S(-20, -5), S(-23, 7), S(-24, 23), }},
  {{ S(-0, -17), S(-18, -17), S(-9, -20), S(-4, -25), S(-5, -23), S(-10, -18), S(-14, -18), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(7, 23), S(-16, 32), S(-13, 22), S(-5, 10), S(-5, -6),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-2, 5), S(-12, 13), S(-10, 11), S(-9, 12), S(-10, 6), S(-8, 2), S(-12, 11), }},
  {{ S(-0, 3), S(-8, 9), S(-15, 14), S(-12, 11), S(-12, 8), S(-13, 11), S(-8, 8), }},
  {{ S(-7, 7), S(-11, 5), S(-12, 12), S(-8, 11), S(-8, 10), S(-12, 10), S(-11, 5), }},
  {{ S(-8, 9), S(-12, 11), S(-13, 10), S(-8, 14), S(-7, 14), S(-12, 11), S(-14, 10), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1199, 552, -35, 56
);

inline VParam WINNABLE_PAWNS = V(-16);
inline VParam WINNABLE_SYM = V(139);
inline VParam WINNABLE_ASYM = V(125);
inline VParam WINNABLE_PAWN_ENDGAME = V(223);
inline VParam WINNABLE_BIAS = V(-654);

// Epoch duration: 7.62732s
// clang-format on
}  // namespace Clockwork
