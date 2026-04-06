#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(135, 208);
inline const PParam KNIGHT_MAT = S(571, 617);
inline const PParam BISHOP_MAT = S(608, 640);
inline const PParam ROOK_MAT   = S(477, 666);
inline const PParam QUEEN_MAT  = S(1057, 462);
inline const PParam TEMPO_VAL  = S(58, 21);

inline const PParam BISHOP_PAIR_VAL   = S(57, 190);
inline const PParam ROOK_OPEN_VAL     = S(112, -14);
inline const PParam ROOK_SEMIOPEN_VAL = S(47, 22);
inline const PParam MINOR_BEHIND_PAWN = S(11, 38);

inline const PParam DOUBLED_PAWN_VAL = S(-7, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-19, -16);

inline const PParam POTENTIAL_CHECKER_VAL = S(-49, -26);
inline const PParam OUTPOST_KNIGHT_VAL    = S(46, 49);
inline const PParam OUTPOST_BISHOP_VAL    = S(48, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(44, 5);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(51, -20);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(28, 55);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(72, -48);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, 4), S(39, 24), S(60, 48), S(135, 146), S(377, 217), S(615, 597),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(55, 33), S(45, 27), S(55, 54), S(120, 140), S(417, 78),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-81, -105), S(-76, -87), S(-46, 11), S(16, 104), S(105, 245), S(283, 354),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(39, -42), S(39, -6), S(25, 30), S(4, 108), S(62, 201), S(227, 257),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -24), S(2, 24), S(-2, -8), S(-1, -40), S(-4, -121), S(-224, -206),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-0, 146), S(-20, 117), S(-11, 43), S(-2, 4), S(2, 6), S(40, 4), S(16, -5),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-320, -33), S(-36, 27), S(-30, 74), S(18, 86), S(36, 103), S(55, 103), S(32, 98),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(91, 29), S(157, 183), S(187, 275), S(214, 301), S(244, 322), S(265, 351), S(290, 353), S(316, 354), S(361, 282),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(102, 21), S(152, 185), S(194, 248), S(219, 289), S(240, 321), S(251, 348), S(258, 364), S(270, 372), S(276, 388), S(298, 370), S(302, 374), S(352, 320), S(350, 335), S(379, 281),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(235, 372), S(258, 425), S(276, 454), S(285, 467), S(289, 477), S(291, 489), S(297, 501), S(303, 502), S(310, 512), S(320, 512), S(328, 512), S(336, 514), S(341, 514), S(350, 492), S(439, 389),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(497, 54), S(589, 251), S(606, 377), S(630, 441), S(641, 493), S(647, 537), S(654, 558), S(658, 577), S(662, 600), S(667, 608), S(671, 617), S(678, 620), S(686, 619), S(689, 621), S(693, 617), S(693, 619), S(698, 611), S(705, 606), S(708, 600), S(715, 588), S(722, 570), S(737, 537), S(720, 546), S(723, 492), S(720, 474), S(701, 448), S(645, 498), S(669, 428),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(256, -183), S(97, -109), S(30, -34), S(15, -2), S(-3, -6), S(-20, 4), S(-17, 3), S(-33, 17), S(-29, 5),
};

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(10, -34), S(13, -24), S(12, -5), S(6, -11), S(2, -6),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -22), S(5, -36), S(5, -21), S(5, -5), S(5, 21),
};

inline const PParam KS_NO_QUEEN = S(-68, -733);
inline const PParam PAWN_THREAT_KNIGHT = S(208, 96);
inline const PParam PAWN_THREAT_BISHOP = S(194, 135);
inline const PParam PAWN_THREAT_ROOK   = S(186, 132);
inline const PParam PAWN_THREAT_QUEEN  = S(181, -27);

inline const PParam KNIGHT_THREAT_BISHOP = S(104, 102);
inline const PParam KNIGHT_THREAT_ROOK   = S(225, 71);
inline const PParam KNIGHT_THREAT_QUEEN  = S(157, -12);

inline const PParam BISHOP_THREAT_KNIGHT = S(103, 60);
inline const PParam BISHOP_THREAT_ROOK   = S(211, 127);
inline const PParam BISHOP_THREAT_QUEEN  = S(179, 91);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(10, -31), S(-1, -6), S(-3, -15), S(-6, -24), S(-10, -32), S(-14, -37), S(-16, -47), S(-22, -47), S(-37, -42),
};

inline const PParam ROOK_LINEUP = S(13, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(324, 313),    S(171, 398),    S(299, 373),    S(314, 285),    S(330, 239),    S(220, 326),    S(152, 380),    S(274, 313),    //
    S(118, 213),    S(165, 230),    S(192, 172),    S(167, 131),    S(148, 109),    S(113, 167),    S(90, 219),     S(42, 243),     //
    S(91, 162),     S(82, 174),     S(115, 126),    S(109, 109),    S(98, 100),     S(70, 129),     S(23, 175),     S(11, 198),     //
    S(64, 113),     S(55, 144),     S(80, 116),     S(76, 110),     S(54, 111),     S(35, 133),     S(-20, 169),    S(-21, 159),    //
    S(55, 93),      S(94, 97),      S(77, 135),     S(67, 133),     S(41, 127),     S(16, 135),     S(-19, 154),    S(-27, 146),    //
    S(68, 95),      S(154, 112),    S(133, 160),    S(86, 167),     S(58, 152),     S(38, 141),     S(8, 160),      S(-14, 160),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-260, -116),  S(-171, 207),   S(-31, -33),    S(116, 195),    S(40, 199),     S(-94, 185),    S(-286, 269),   S(-332, -11),   //
    S(68, 169),     S(117, 189),    S(225, 155),    S(208, 185),    S(203, 192),    S(128, 204),    S(72, 206),     S(42, 193),     //
    S(156, 161),    S(204, 163),    S(232, 214),    S(227, 225),    S(189, 253),    S(132, 250),    S(127, 192),    S(82, 183),     //
    S(219, 194),    S(234, 218),    S(242, 240),    S(222, 277),    S(226, 279),    S(189, 257),    S(171, 227),    S(155, 199),    //
    S(202, 198),    S(250, 182),    S(228, 234),    S(219, 253),    S(200, 253),    S(199, 238),    S(185, 191),    S(139, 201),    //
    S(170, 164),    S(195, 168),    S(208, 196),    S(203, 222),    S(196, 223),    S(162, 200),    S(141, 172),    S(102, 141),    //
    S(160, 161),    S(179, 154),    S(160, 162),    S(174, 192),    S(157, 190),    S(132, 144),    S(103, 167),    S(80, 83),      //
    S(90, 94),      S(121, 167),    S(140, 142),    S(164, 144),    S(144, 164),    S(110, 136),    S(87, 152),     S(67, 49),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-10, 305),    S(-7, 300),     S(-294, 360),   S(-134, 298),   S(-128, 307),   S(-152, 307),   S(-43, 309),    S(22, 295),     //
    S(130, 213),    S(74, 291),     S(116, 238),    S(52, 273),     S(72, 267),     S(98, 261),     S(134, 260),    S(112, 231),    //
    S(187, 241),    S(209, 249),    S(210, 263),    S(182, 261),    S(154, 267),    S(161, 269),    S(178, 250),    S(161, 235),    //
    S(163, 231),    S(199, 242),    S(208, 262),    S(202, 303),    S(232, 289),    S(167, 262),    S(178, 232),    S(135, 227),    //
    S(189, 191),    S(215, 223),    S(218, 254),    S(225, 275),    S(203, 290),    S(184, 274),    S(153, 239),    S(145, 200),    //
    S(218, 204),    S(257, 217),    S(269, 241),    S(215, 266),    S(208, 247),    S(204, 251),    S(209, 229),    S(143, 225),    //
    S(191, 180),    S(280, 181),    S(249, 203),    S(217, 216),    S(195, 224),    S(196, 194),    S(192, 188),    S(176, 179),    //
    S(205, 165),    S(176, 205),    S(178, 224),    S(199, 197),    S(190, 205),    S(183, 237),    S(190, 218),    S(186, 182),    //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(415, 393),    S(425, 416),    S(421, 420),    S(430, 392),    S(406, 404),    S(375, 409),    S(368, 425),    S(358, 428),    //
    S(307, 477),    S(373, 477),    S(460, 439),    S(405, 449),    S(392, 457),    S(363, 461),    S(295, 491),    S(290, 488),    //
    S(276, 469),    S(382, 450),    S(434, 417),    S(408, 408),    S(359, 438),    S(320, 458),    S(322, 456),    S(263, 490),    //
    S(278, 436),    S(353, 443),    S(388, 419),    S(359, 419),    S(361, 415),    S(315, 450),    S(308, 448),    S(239, 475),    //
    S(257, 371),    S(322, 390),    S(308, 411),    S(292, 400),    S(276, 413),    S(262, 435),    S(229, 432),    S(210, 429),    //
    S(247, 317),    S(311, 346),    S(298, 368),    S(281, 362),    S(271, 368),    S(242, 398),    S(242, 372),    S(206, 381),    //
    S(131, 341),    S(276, 300),    S(284, 327),    S(277, 347),    S(265, 347),    S(253, 357),    S(236, 340),    S(209, 350),    //
    S(214, 321),    S(238, 339),    S(296, 329),    S(304, 324),    S(292, 331),    S(272, 349),    S(262, 344),    S(242, 351),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(471, 473),    S(540, 406),    S(471, 511),    S(446, 574),    S(439, 534),    S(459, 505),    S(468, 442),    S(412, 496),    //
    S(495, 505),    S(459, 603),    S(448, 631),    S(316, 710),    S(327, 688),    S(383, 647),    S(418, 541),    S(432, 513),    //
    S(464, 565),    S(517, 586),    S(458, 668),    S(405, 687),    S(382, 671),    S(432, 592),    S(465, 519),    S(474, 449),    //
    S(512, 469),    S(514, 564),    S(458, 623),    S(444, 658),    S(433, 663),    S(453, 558),    S(500, 479),    S(476, 454),    //
    S(529, 434),    S(514, 514),    S(492, 557),    S(466, 593),    S(466, 593),    S(464, 542),    S(478, 469),    S(503, 388),    //
    S(509, 382),    S(547, 427),    S(542, 488),    S(516, 477),    S(504, 475),    S(509, 479),    S(512, 415),    S(490, 387),    //
    S(497, 264),    S(535, 259),    S(541, 325),    S(554, 370),    S(546, 390),    S(527, 368),    S(492, 398),    S(499, 370),    //
    S(493, 277),    S(522, 100),    S(530, 145),    S(559, 236),    S(550, 332),    S(550, 267),    S(534, 287),    S(496, 324),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-160, -181),  S(185, 285),    S(106, 285),    S(-59, 216),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(119, 48),     S(253, 206),    S(153, 238),    S(110, 116),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(112, 107),    S(264, 154),    S(223, 163),    S(171, 88),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-18, 41),     S(228, 66),     S(152, 98),     S(133, 88),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-84, -28),    S(159, -4),     S(125, 41),     S(41, 91),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-39, -60),    S(166, -45),    S(94, 15),      S(49, 56),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-1, -79),     S(84, -44),     S(4, 6),        S(-35, 33),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-102, -121),  S(-4, -71),     S(-101, -27),   S(-99, -48),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(10, 21), S(-6, 23), S(-10, 22), S(-3, -14), S(-3, -17), S(-10, 23), S(-5, 23), }},
  {{ S(1, 145), S(-23, 123), S(-20, 109), S(-10, 74), S(-10, 67), S(-19, 111), S(-22, 127), }},
  {{ S(-6, 114), S(-17, 104), S(-14, 81), S(-11, 51), S(-10, 49), S(-14, 80), S(-16, 102), }},
  {{ S(2, 114), S(-15, 61), S(-6, 69), S(-3, 62), S(-4, 60), S(-7, 66), S(-11, 69), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(3, 85), S(-16, -113), S(-14, 43), S(-8, 97), S(-8, 63),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-5, 161), S(-14, 148), S(-13, 123), S(-12, 124), S(-12, 131), S(-12, 121), S(-14, 148), }},
  {{ S(-5, 46), S(-10, 29), S(-16, 21), S(-13, -4), S(-14, -15), S(-16, 8), S(-10, 27), }},
  {{ S(-10, 82), S(-14, 62), S(-15, 62), S(-11, 52), S(-11, 42), S(-15, 57), S(-14, 62), }},
  {{ S(-10, 80), S(-16, 71), S(-17, 54), S(-11, 50), S(-10, 53), S(-17, 57), S(-17, 68), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1383, 1655, -28, 130
);

inline VParam WINNABLE_PAWNS = V(-15);
inline VParam WINNABLE_SYM = V(137);
inline VParam WINNABLE_ASYM = V(124);
inline VParam WINNABLE_PAWN_ENDGAME = V(232);
inline VParam WINNABLE_BIAS = V(-653);

// Epoch duration: 8.6318s
// clang-format on
}  // namespace Clockwork
