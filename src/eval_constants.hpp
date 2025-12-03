#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(184, 169);
inline const PParam KNIGHT_MAT = S(844, 634);
inline const PParam BISHOP_MAT = S(863, 581);
inline const PParam ROOK_MAT   = S(754, 718);
inline const PParam QUEEN_MAT  = S(1725, 1232);
inline const PParam TEMPO_VAL  = S(58, 15);

inline const PParam BISHOP_PAIR_VAL   = S(79, 178);
inline const PParam ROOK_OPEN_VAL     = S(105, -28);
inline const PParam ROOK_SEMIOPEN_VAL = S(39, 13);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -78);

inline const PParam POTENTIAL_CHECKER_VAL = S(-75, -2);
inline const PParam OUTPOST_KNIGHT_VAL    = S(5, 52);
inline const PParam OUTPOST_BISHOP_VAL    = S(29, 27);

inline const PParam KNIGHT_PROTECTOR = S(-24, -14);
inline const PParam BISHOP_PROTECTOR = S(-18, -5);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(53, 17);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -14);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(34, 33);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(54, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 20), S(63, 31), S(73, 71), S(187, 143), S(545, 252), S(790, 889),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(63, 43), S(60, 32), S(66, 58), S(146, 122), S(667, -76),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-68, -98), S(-59, -80), S(-33, -4), S(22, 76), S(44, 217), S(285, 308),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(50, -45), S(36, -7), S(21, 27), S(23, 75), S(90, 153), S(147, 295),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(15, -46), S(4, 3), S(0, -27), S(7, -48), S(4, -97), S(-189, -149),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(11, 101), S(-20, 87), S(-13, 36), S(-0, 7), S(9, 12), S(38, 10), S(15, 0),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-187, -56), S(29, -8), S(-15, 41), S(9, 72), S(14, 97), S(36, 96), S(-7, 114),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(9, -32), S(116, 132), S(173, 185), S(216, 220), S(262, 235), S(288, 273), S(324, 269), S(358, 271), S(404, 214),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(43, -65), S(116, 119), S(191, 183), S(227, 233), S(258, 264), S(275, 287), S(295, 301), S(314, 308), S(333, 312), S(347, 309), S(373, 297), S(437, 252), S(469, 229), S(528, 197),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(170, 257), S(311, 429), S(361, 493), S(392, 503), S(420, 527), S(433, 550), S(450, 562), S(469, 569), S(485, 581), S(502, 591), S(520, 593), S(531, 596), S(552, 599), S(563, 586), S(709, 457),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(1, 3), S(789, 345), S(890, 445), S(947, 620), S(956, 821), S(996, 918), S(1001, 1025), S(1026, 1037), S(1031, 1091), S(1043, 1115), S(1052, 1139), S(1058, 1153), S(1077, 1144), S(1088, 1155), S(1095, 1149), S(1109, 1144), S(1117, 1134), S(1117, 1139), S(1145, 1092), S(1169, 1052), S(1187, 1030), S(1243, 952), S(1257, 941), S(1408, 774), S(1401, 759), S(1440, 735), S(1173, 869), S(1117, 869),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(390, 118), S(156, -121), S(48, -29), S(30, 10), S(-1, 13), S(-38, 18), S(-20, 20), S(-32, 15), S(-36, -33),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(0, 0), S(88, -31), S(159, -78),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(0, 0), S(35, -5), S(133, -43),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(0, 0), S(70, -47), S(52, -62), S(101, -63), S(154, -128),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(0, 0), S(-40, 34), S(-62, 49), S(-11, 7), S(137, -69), S(300, -187),
};

inline const PParam PAWN_THREAT_KNIGHT = S(239, 57);
inline const PParam PAWN_THREAT_BISHOP = S(206, 103);
inline const PParam PAWN_THREAT_ROOK   = S(197, 58);
inline const PParam PAWN_THREAT_QUEEN  = S(177, -59);

inline const PParam KNIGHT_THREAT_BISHOP = S(104, 77);
inline const PParam KNIGHT_THREAT_ROOK   = S(240, 10);
inline const PParam KNIGHT_THREAT_QUEEN  = S(154, -64);

inline const PParam BISHOP_THREAT_KNIGHT = S(110, 38);
inline const PParam BISHOP_THREAT_ROOK   = S(242, 58);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 47);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-1, -11), S(-3, -6), S(-3, -15), S(-8, -26), S(-14, -32), S(-19, -39), S(-21, -45), S(-27, -41), S(-36, -46),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(232, 325),    S(227, 371),    S(292, 337),    S(360, 216),    S(308, 210),    S(290, 276),    S(185, 299),    S(242, 276),    //
    S(185, 192),    S(297, 220),    S(273, 164),    S(276, 105),    S(229, 89),     S(173, 137),    S(135, 183),    S(84, 186),     //
    S(103, 159),    S(123, 163),    S(140, 119),    S(127, 105),    S(110, 101),    S(68, 107),     S(27, 154),     S(0, 175),      //
    S(77, 110),     S(95, 139),     S(92, 106),     S(73, 110),     S(48, 100),     S(27, 108),     S(-24, 157),    S(-43, 145),    //
    S(74, 81),      S(138, 84),     S(89, 128),     S(59, 131),     S(38, 122),     S(-1, 120),     S(-21, 133),    S(-45, 126),    //
    S(82, 88),      S(211, 93),     S(167, 130),    S(112, 148),    S(75, 136),     S(39, 130),     S(13, 152),     S(-25, 139),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-174, 3),     S(-129, 211),   S(-244, 399),   S(83, 229),     S(-44, 253),    S(-118, 260),   S(-345, 244),   S(-313, 149),   //
    S(186, 149),    S(253, 156),    S(356, 88),     S(299, 156),    S(300, 166),    S(241, 143),    S(178, 171),    S(161, 135),    //
    S(216, 110),    S(257, 155),    S(351, 140),    S(303, 165),    S(301, 160),    S(222, 175),    S(214, 159),    S(135, 178),    //
    S(244, 134),    S(236, 153),    S(267, 157),    S(245, 187),    S(255, 178),    S(225, 182),    S(216, 151),    S(211, 172),    //
    S(208, 110),    S(233, 100),    S(229, 124),    S(204, 145),    S(198, 161),    S(212, 167),    S(206, 154),    S(216, 113),    //
    S(104, 95),     S(126, 78),     S(123, 97),     S(139, 146),    S(161, 150),    S(123, 144),    S(153, 119),    S(137, 126),    //
    S(84, 109),     S(97, 77),      S(83, 83),      S(97, 106),     S(107, 107),    S(104, 102),    S(140, 103),    S(105, 48),     //
    S(56, 60),      S(84, 97),      S(88, 73),      S(111, 87),     S(117, 103),    S(97, 87),      S(108, 123),    S(85, 84),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(41, 260),     S(12, 243),     S(-229, 268),   S(-116, 284),   S(-66, 289),    S(-233, 315),   S(21, 296),     S(76, 269),     //
    S(182, 150),    S(167, 221),    S(183, 203),    S(163, 207),    S(137, 225),    S(175, 218),    S(152, 211),    S(121, 219),    //
    S(193, 203),    S(239, 189),    S(316, 196),    S(246, 194),    S(220, 201),    S(197, 216),    S(256, 194),    S(169, 215),    //
    S(190, 154),    S(205, 184),    S(239, 185),    S(238, 210),    S(245, 213),    S(186, 216),    S(188, 197),    S(155, 211),    //
    S(173, 125),    S(179, 160),    S(190, 175),    S(189, 200),    S(184, 220),    S(157, 216),    S(157, 184),    S(170, 147),    //
    S(171, 135),    S(205, 146),    S(211, 159),    S(156, 202),    S(151, 210),    S(168, 210),    S(215, 171),    S(200, 154),    //
    S(151, 101),    S(190, 120),    S(160, 136),    S(145, 166),    S(151, 153),    S(171, 147),    S(170, 166),    S(207, 107),    //
    S(155, 120),    S(133, 164),    S(132, 171),    S(152, 140),    S(172, 133),    S(187, 177),    S(197, 154),    S(198, 155),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(573, 489),    S(637, 488),    S(570, 516),    S(571, 511),    S(579, 500),    S(527, 513),    S(531, 518),    S(538, 523),    //
    S(480, 546),    S(567, 521),    S(644, 496),    S(572, 539),    S(586, 528),    S(531, 538),    S(470, 557),    S(461, 563),    //
    S(472, 522),    S(620, 481),    S(648, 476),    S(648, 472),    S(603, 481),    S(530, 522),    S(546, 510),    S(427, 560),    //
    S(440, 516),    S(517, 509),    S(547, 501),    S(569, 465),    S(538, 488),    S(477, 536),    S(458, 536),    S(388, 543),    //
    S(377, 466),    S(458, 471),    S(443, 489),    S(426, 490),    S(421, 487),    S(402, 527),    S(373, 523),    S(354, 512),    //
    S(354, 444),    S(428, 419),    S(424, 449),    S(403, 451),    S(420, 432),    S(370, 486),    S(367, 469),    S(344, 465),    //
    S(292, 456),    S(391, 396),    S(416, 412),    S(421, 414),    S(413, 419),    S(393, 435),    S(373, 412),    S(342, 429),    //
    S(326, 455),    S(356, 461),    S(412, 426),    S(435, 411),    S(422, 426),    S(408, 437),    S(393, 428),    S(376, 444),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(826, 856),    S(873, 814),    S(885, 821),    S(764, 956),    S(828, 882),    S(765, 912),    S(822, 833),    S(757, 857),    //
    S(794, 915),    S(722, 1011),   S(719, 1073),   S(639, 1100),   S(663, 1050),   S(646, 1051),   S(694, 956),    S(730, 891),    //
    S(756, 948),    S(841, 952),    S(785, 1029),   S(767, 1044),   S(725, 1026),   S(692, 1025),   S(762, 916),    S(728, 885),    //
    S(818, 870),    S(822, 940),    S(785, 978),    S(773, 1048),   S(750, 1034),   S(741, 963),    S(778, 870),    S(767, 832),    //
    S(781, 898),    S(816, 862),    S(789, 937),    S(748, 997),    S(735, 986),    S(743, 939),    S(755, 858),    S(757, 806),    //
    S(788, 747),    S(815, 789),    S(815, 859),    S(761, 888),    S(773, 846),    S(776, 849),    S(788, 777),    S(764, 780),    //
    S(768, 649),    S(806, 543),    S(795, 676),    S(812, 749),    S(786, 768),    S(802, 698),    S(777, 759),    S(760, 758),    //
    S(708, 734),    S(766, 494),    S(777, 481),    S(805, 573),    S(806, 657),    S(809, 613),    S(797, 650),    S(746, 721),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-209, -357),  S(58, -6),      S(-102, 45),    S(-198, 68),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(158, -99),    S(-21, 155),    S(-9, 138),     S(99, 66),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-61, 69),     S(37, 144),     S(67, 112),     S(54, 65),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-275, 92),    S(3, 103),      S(-24, 101),    S(-86, 84),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-233, 46),    S(-73, 76),     S(-78, 81),     S(-176, 117),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-128, 13),    S(38, 18),      S(-82, 71),     S(-142, 97),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(98, -78),     S(123, -33),    S(3, 16),       S(-96, 60),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, -108),   S(84, -89),     S(-47, -47),    S(-83, -44),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};
// clang-format on
}  // namespace Clockwork
