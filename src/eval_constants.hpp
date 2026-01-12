#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(167, 156);
inline const PParam KNIGHT_MAT = S(506, 311);
inline const PParam BISHOP_MAT = S(466, 279);
inline const PParam ROOK_MAT   = S(542, 410);
inline const PParam QUEEN_MAT  = S(1083, 560);
inline const PParam TEMPO_VAL  = S(63, 14);

inline const PParam BISHOP_PAIR_VAL   = S(77, 163);
inline const PParam ROOK_OPEN_VAL     = S(114, -26);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 17);

inline const PParam DOUBLED_PAWN_VAL = S(-31, -74);

inline const PParam POTENTIAL_CHECKER_VAL = S(-69, -10);
inline const PParam OUTPOST_KNIGHT_VAL    = S(53, 41);
inline const PParam OUTPOST_BISHOP_VAL    = S(61, 26);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(47, 1);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(54, -26);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(38, 34);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(70, -53);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 13), S(57, 33), S(74, 70), S(182, 153), S(482, 224), S(669, 679),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(69, 38), S(59, 33), S(72, 64), S(174, 117), S(593, -10),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-80, -96), S(-80, -74), S(-53, 7), S(28, 76), S(103, 196), S(304, 277),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(44, -38), S(39, -6), S(30, 20), S(27, 66), S(97, 129), S(211, 209),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(12, -32), S(-2, 12), S(-5, -19), S(-10, -40), S(-18, -89), S(-269, -107),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-3, 114), S(-15, 90), S(-9, 33), S(-1, 5), S(11, 6), S(57, 2), S(19, -6),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-296, -9), S(-35, 23), S(-13, 50), S(34, 60), S(40, 80), S(48, 88), S(19, 84),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(16, -58), S(113, 94), S(169, 165), S(205, 194), S(252, 204), S(280, 236), S(316, 228), S(353, 229), S(399, 169),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-15, -122), S(57, 36), S(121, 79), S(149, 126), S(177, 156), S(196, 175), S(205, 192), S(223, 196), S(235, 207), S(254, 196), S(277, 186), S(336, 142), S(342, 141), S(411, 96),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(280, 99), S(203, 257), S(232, 279), S(249, 283), S(262, 294), S(267, 306), S(275, 313), S(285, 313), S(292, 318), S(302, 320), S(315, 319), S(325, 318), S(331, 317), S(351, 296), S(459, 202),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(461, 124), S(527, 233), S(576, 271), S(604, 364), S(616, 424), S(632, 455), S(636, 497), S(645, 501), S(648, 525), S(654, 535), S(657, 549), S(662, 552), S(673, 541), S(678, 543), S(682, 540), S(685, 535), S(691, 528), S(690, 528), S(702, 507), S(721, 489), S(737, 468), S(752, 435), S(781, 415), S(900, 303), S(952, 249), S(947, 242), S(863, 290), S(963, 218),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(658, -336), S(246, -190), S(121, -86), S(79, -36), S(27, -21), S(-28, 4), S(-78, 40), S(-132, 69), S(-172, 57),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(233, 230), S(352, 183), S(455, 120),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(445, 366), S(273, 231), S(159, 67),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(316, 319), S(442, 311), S(486, 317), S(589, 367), S(747, 326),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(867, 744), S(583, 607), S(327, 458), S(136, 253), S(78, -13), S(12, -297),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(-119, 61), S(28, -18), S(-211, -126), S(57, 37), S(-241, -153),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(-28, 22), S(-21, 20), S(-20, 15), S(-15, 9), S(-21, -12),
};

inline const PParam PAWN_THREAT_KNIGHT = S(245, 59);
inline const PParam PAWN_THREAT_BISHOP = S(218, 115);
inline const PParam PAWN_THREAT_ROOK   = S(204, 100);
inline const PParam PAWN_THREAT_QUEEN  = S(189, -47);

inline const PParam KNIGHT_THREAT_BISHOP = S(115, 75);
inline const PParam KNIGHT_THREAT_ROOK   = S(257, 16);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -19);

inline const PParam BISHOP_THREAT_KNIGHT = S(115, 38);
inline const PParam BISHOP_THREAT_ROOK   = S(237, 72);
inline const PParam BISHOP_THREAT_QUEEN  = S(200, 51);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(3, -20), S(-4, -8), S(-4, -18), S(-9, -25), S(-14, -32), S(-19, -35), S(-22, -45), S(-26, -47), S(-33, -52),
};

inline const PParam KNIGHT_BEHIND_PAWN_VAL = S(22, 28);
inline const PParam KNIGHT_BEHIND_DEFENDED_PAWN_VAL = S(-2, 15);
inline const PParam BISHOP_BEHIND_PAWN_VAL = S(17, 10);
inline const PParam BISHOP_BEHIND_DEFENDED_PAWN_VAL = S(11, 4);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(294, 277),    S(198, 347),    S(308, 313),    S(293, 250),    S(344, 180),    S(250, 255),    S(206, 278),    S(310, 230),    //
    S(160, 173),    S(211, 218),    S(202, 165),    S(166, 130),    S(149, 99),     S(119, 140),    S(98, 178),     S(63, 185),     //
    S(101, 138),    S(102, 157),    S(114, 116),    S(99, 108),     S(85, 96),      S(55, 109),     S(27, 143),     S(11, 161),     //
    S(88, 93),      S(101, 123),    S(103, 96),     S(88, 98),      S(59, 93),      S(39, 100),     S(-7, 142),     S(-22, 128),    //
    S(87, 68),      S(142, 74),     S(90, 119),     S(73, 119),     S(42, 112),     S(13, 112),     S(-12, 127),    S(-26, 114),    //
    S(84, 76),      S(208, 85),     S(149, 130),    S(104, 147),    S(73, 131),     S(47, 118),     S(29, 136),     S(-8, 130),     //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-284, -46),   S(-217, 186),   S(-453, 438),   S(95, 148),     S(22, 155),     S(-106, 133),   S(-366, 194),   S(-338, 33),    //
    S(114, 121),    S(166, 121),    S(247, 83),     S(222, 118),    S(219, 130),    S(152, 123),    S(134, 130),    S(107, 104),    //
    S(184, 91),     S(196, 139),    S(254, 153),    S(216, 170),    S(189, 177),    S(132, 186),    S(143, 125),    S(113, 120),    //
    S(241, 133),    S(226, 150),    S(230, 176),    S(205, 209),    S(223, 198),    S(195, 184),    S(196, 139),    S(192, 114),    //
    S(233, 116),    S(268, 106),    S(246, 150),    S(230, 173),    S(218, 172),    S(220, 161),    S(219, 109),    S(182, 110),    //
    S(178, 86),     S(208, 85),     S(190, 124),    S(207, 147),    S(208, 144),    S(160, 132),    S(161, 96),     S(127, 77),     //
    S(181, 81),     S(193, 65),     S(178, 82),     S(179, 105),    S(167, 112),    S(144, 66),     S(148, 75),     S(108, 15),     //
    S(123, 59),     S(157, 117),    S(182, 71),     S(204, 64),     S(189, 83),     S(137, 64),     S(124, 96),     S(74, 31),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-24, 186),    S(-58, 169),    S(-346, 242),   S(-211, 210),   S(-178, 219),   S(-277, 253),   S(-93, 221),    S(-21, 196),    //
    S(88, 115),     S(37, 175),     S(69, 134),     S(7, 181),      S(-8, 187),     S(49, 163),     S(80, 145),     S(62, 136),     //
    S(157, 127),    S(182, 126),    S(178, 157),    S(140, 151),    S(111, 148),    S(110, 157),    S(155, 134),    S(130, 114),    //
    S(134, 109),    S(153, 127),    S(174, 139),    S(154, 178),    S(184, 164),    S(123, 148),    S(129, 123),    S(101, 113),    //
    S(150, 82),     S(159, 110),    S(170, 129),    S(176, 151),    S(164, 160),    S(131, 150),    S(93, 130),     S(101, 97),     //
    S(163, 85),     S(200, 92),     S(217, 108),    S(163, 146),    S(153, 133),    S(161, 127),    S(173, 104),    S(110, 108),    //
    S(139, 39),     S(221, 56),     S(190, 70),     S(159, 98),     S(142, 109),    S(148, 81),     S(146, 85),     S(137, 45),     //
    S(154, 48),     S(140, 99),     S(140, 121),    S(165, 79),     S(172, 67),     S(162, 125),    S(157, 82),     S(137, 71),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(398, 245),    S(433, 254),    S(394, 278),    S(405, 260),    S(401, 260),    S(349, 271),    S(364, 272),    S(360, 275),    //
    S(291, 301),    S(355, 291),    S(446, 265),    S(382, 288),    S(384, 290),    S(344, 295),    S(264, 323),    S(261, 323),    //
    S(280, 287),    S(404, 254),    S(438, 246),    S(421, 245),    S(382, 254),    S(335, 278),    S(334, 280),    S(256, 312),    //
    S(255, 274),    S(331, 275),    S(372, 259),    S(352, 255),    S(347, 264),    S(305, 284),    S(286, 285),    S(226, 298),    //
    S(214, 229),    S(284, 240),    S(265, 258),    S(263, 245),    S(253, 255),    S(238, 282),    S(208, 272),    S(183, 270),    //
    S(182, 203),    S(244, 202),    S(249, 223),    S(235, 216),    S(240, 210),    S(211, 246),    S(203, 225),    S(162, 238),    //
    S(94, 220),     S(209, 163),    S(232, 184),    S(241, 187),    S(233, 188),    S(219, 202),    S(197, 185),    S(170, 200),    //
    S(145, 208),    S(161, 229),    S(234, 189),    S(261, 172),    S(242, 191),    S(229, 206),    S(214, 198),    S(195, 221),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(457, 412),    S(536, 347),    S(525, 380),    S(442, 485),    S(458, 446),    S(447, 441),    S(484, 371),    S(383, 449),    //
    S(480, 440),    S(424, 544),    S(427, 557),    S(284, 619),    S(290, 612),    S(360, 567),    S(390, 482),    S(409, 461),    //
    S(418, 496),    S(509, 485),    S(436, 556),    S(402, 576),    S(355, 580),    S(374, 531),    S(448, 435),    S(425, 406),    //
    S(493, 395),    S(489, 463),    S(449, 508),    S(424, 559),    S(414, 562),    S(417, 496),    S(471, 401),    S(468, 369),    //
    S(476, 397),    S(487, 417),    S(462, 466),    S(435, 510),    S(437, 506),    S(433, 468),    S(454, 397),    S(465, 348),    //
    S(463, 318),    S(498, 349),    S(499, 420),    S(465, 399),    S(461, 391),    S(467, 414),    S(473, 357),    S(458, 331),    //
    S(445, 199),    S(487, 152),    S(491, 242),    S(503, 290),    S(486, 316),    S(485, 286),    S(454, 336),    S(455, 322),    //
    S(404, 239),    S(454, 40),     S(453, 68),     S(482, 160),    S(490, 233),    S(490, 185),    S(480, 218),    S(432, 267),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-607, -152),  S(-137, 155),   S(53, 73),      S(-140, 42),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(18, -41),     S(174, 58),     S(174, 68),     S(140, -12),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-45, 88),     S(211, 61),     S(229, 54),     S(125, 18),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-296, 102),   S(133, 35),     S(64, 45),      S(57, 33),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-301, 69),    S(74, 1),       S(94, 5),       S(11, 39),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-155, 37),    S(159, -34),    S(119, -7),     S(91, 12),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-5, -25),     S(181, -56),    S(136, -29),    S(64, 6),       S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-192, -16),   S(-18, -21),    S(-108, 11),    S(-111, -4),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 14.7037s
// clang-format on
}  // namespace Clockwork
