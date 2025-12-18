#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(178, 165);
inline const PParam KNIGHT_MAT = S(573, 377);
inline const PParam BISHOP_MAT = S(619, 376);
inline const PParam ROOK_MAT   = S(566, 514);
inline const PParam QUEEN_MAT  = S(1291, 920);
inline const PParam TEMPO_VAL  = S(59, 13);

inline const PParam BISHOP_PAIR_VAL   = S(75, 181);
inline const PParam ROOK_OPEN_VAL     = S(98, -16);
inline const PParam ROOK_SEMIOPEN_VAL = S(37, 25);

inline const PParam DOUBLED_PAWN_VAL = S(-36, -76);

inline const PParam POTENTIAL_CHECKER_VAL = S(-75, -5);
inline const PParam OUTPOST_KNIGHT_VAL    = S(6, 50);
inline const PParam OUTPOST_BISHOP_VAL    = S(31, 19);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(54, 17);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(55, -12);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(36, 35);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(53, -50);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(20, 23), S(62, 34), S(71, 77), S(177, 176), S(529, 454), S(792, 915),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(62, 46), S(59, 31), S(67, 54), S(151, 101), S(606, -52),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(2, 10), S(-19, 43), S(-18, 100), S(21, 157), S(52, 266), S(200, 329),
};
inline const std::array<PParam, 6> CANDIDATE_PASSED_PAWN = {
    S(55, -1), S(-42, -24), S(-101, -47), S(-47, -157), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(-25, 1), S(46, -18), S(46, 14), S(-64, 10), S(0, 0), S(0, 0),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(41, 35), S(-28, 5), S(9, 5), S(0, 0), S(0, 0), S(0, 0),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-216, -86), S(12, -95), S(108, 5), S(1, 7), S(-29, -4), S(-45, -51), S(-28, -18),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(6, 25), S(2, -5), S(76, -31), S(-9, -136), S(-171, -60), S(-11, 34), S(-65, -51),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-34, -82), S(70, 82), S(126, 137), S(168, 172), S(213, 191), S(239, 230), S(275, 229), S(309, 233), S(352, 182),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-28, -153), S(44, 29), S(117, 93), S(152, 144), S(183, 175), S(200, 198), S(219, 215), S(237, 223), S(257, 228), S(271, 225), S(295, 214), S(359, 172), S(393, 144), S(453, 116),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(14, 96), S(151, 270), S(202, 335), S(234, 345), S(261, 364), S(275, 385), S(292, 398), S(312, 400), S(331, 408), S(348, 417), S(367, 419), S(382, 417), S(405, 416), S(414, 405), S(549, 287),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(0, 3), S(506, 133), S(609, 204), S(668, 368), S(679, 557), S(718, 654), S(723, 759), S(748, 770), S(753, 824), S(765, 849), S(774, 873), S(781, 887), S(800, 877), S(812, 888), S(819, 881), S(834, 874), S(842, 864), S(844, 866), S(874, 817), S(899, 777), S(920, 750), S(977, 672), S(982, 669), S(1074, 557), S(1052, 552), S(1030, 555), S(811, 629), S(757, 625),
};
inline const std::array<PParam, 9> KING_MOBILITY = {
    S(395, 265), S(148, -73), S(43, -0), S(27, 30), S(-1, 25), S(-34, 14), S(-18, 24), S(-26, 5), S(-22, -62),
};

inline const std::array<PParam, 3> KNIGHT_KING_RING = {
    S(233, 267), S(321, 232), S(391, 185),
};
inline const std::array<PParam, 3> BISHOP_KING_RING = {
    S(275, 327), S(312, 312), S(412, 277),
};
inline const std::array<PParam, 5> ROOK_KING_RING = {
    S(474, 517), S(543, 452), S(532, 441), S(574, 454), S(626, 393),
};
inline const std::array<PParam, 6> QUEEN_KING_RING = {
    S(784, 821), S(745, 843), S(725, 856), S(780, 803), S(942, 706), S(1091, 604),
};

inline const PParam PAWN_THREAT_KNIGHT = S(237, 59);
inline const PParam PAWN_THREAT_BISHOP = S(205, 102);
inline const PParam PAWN_THREAT_ROOK   = S(208, 58);
inline const PParam PAWN_THREAT_QUEEN  = S(176, -58);

inline const PParam KNIGHT_THREAT_BISHOP = S(104, 72);
inline const PParam KNIGHT_THREAT_ROOK   = S(241, 0);
inline const PParam KNIGHT_THREAT_QUEEN  = S(158, -78);

inline const PParam BISHOP_THREAT_KNIGHT = S(108, 37);
inline const PParam BISHOP_THREAT_ROOK   = S(239, 54);
inline const PParam BISHOP_THREAT_QUEEN  = S(192, 41);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(-0, -15), S(-2, -12), S(-1, -22), S(-7, -33), S(-12, -39), S(-18, -46), S(-19, -52), S(-26, -47), S(-35, -50),
};

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(132, 380),    S(94, 428),     S(210, 369),    S(285, 202),    S(257, 188),    S(265, 271),    S(129, 323),    S(189, 303),    //
    S(172, 218),    S(277, 252),    S(263, 174),    S(269, 91),     S(224, 74),     S(178, 138),    S(139, 200),    S(96, 208),     //
    S(103, 164),    S(123, 169),    S(141, 122),    S(127, 102),    S(108, 101),    S(72, 111),     S(34, 165),     S(18, 186),     //
    S(80, 108),     S(97, 137),     S(93, 107),     S(73, 111),     S(46, 104),     S(29, 114),     S(-18, 167),    S(-28, 153),    //
    S(78, 75),      S(140, 75),     S(92, 121),     S(59, 128),     S(37, 120),     S(0, 124),      S(-14, 140),    S(-30, 132),    //
    S(87, 80),      S(215, 78),     S(170, 117),    S(112, 140),    S(74, 132),     S(40, 133),     S(19, 159),     S(-12, 146),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-276, -35),   S(-235, 187),   S(-311, 340),   S(-13, 190),    S(-138, 212),   S(-224, 224),   S(-438, 196),   S(-418, 107),   //
    S(105, 129),    S(170, 138),    S(275, 66),     S(219, 129),    S(222, 137),    S(163, 111),    S(105, 129),    S(82, 88),      //
    S(161, 101),    S(207, 142),    S(297, 130),    S(249, 151),    S(250, 136),    S(173, 142),    S(162, 121),    S(66, 130),     //
    S(217, 131),    S(209, 152),    S(241, 153),    S(219, 177),    S(229, 163),    S(197, 155),    S(172, 116),    S(148, 121),    //
    S(208, 113),    S(234, 107),    S(230, 130),    S(203, 144),    S(195, 152),    S(192, 145),    S(166, 118),    S(150, 65),     //
    S(123, 97),     S(153, 82),     S(149, 101),    S(160, 145),    S(166, 142),    S(110, 119),    S(115, 82),     S(75, 77),      //
    S(121, 119),    S(144, 82),     S(130, 85),     S(130, 107),    S(117, 103),    S(91, 81),      S(99, 74),      S(43, 8),       //
    S(74, 72),      S(113, 107),    S(131, 82),     S(140, 88),     S(133, 96),     S(87, 66),      S(73, 91),      S(23, 44),      //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-61, 208),    S(-84, 187),    S(-316, 211),   S(-199, 226),   S(-160, 234),   S(-320, 261),   S(-70, 238),    S(-19, 208),    //
    S(105, 101),    S(88, 170),     S(111, 150),    S(91, 147),     S(64, 171),     S(100, 164),    S(79, 150),     S(45, 153),     //
    S(132, 157),    S(181, 147),    S(258, 148),    S(188, 148),    S(164, 149),    S(140, 160),    S(198, 138),    S(96, 155),     //
    S(148, 113),    S(163, 143),    S(199, 145),    S(197, 166),    S(204, 164),    S(143, 163),    S(133, 140),    S(86, 144),     //
    S(150, 85),     S(158, 122),    S(166, 136),    S(167, 158),    S(158, 174),    S(119, 168),    S(105, 127),    S(100, 86),     //
    S(162, 92),     S(203, 101),    S(208, 115),    S(150, 155),    S(132, 163),    S(133, 158),    S(162, 112),    S(129, 94),     //
    S(149, 64),     S(200, 77),     S(170, 91),     S(143, 122),    S(134, 108),    S(135, 98),     S(117, 113),    S(135, 52),     //
    S(144, 84),     S(132, 125),    S(138, 130),    S(148, 95),     S(157, 84),     S(154, 124),    S(145, 100),    S(127, 99),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(414, 334),    S(479, 334),    S(409, 365),    S(414, 352),    S(426, 333),    S(375, 344),    S(386, 344),    S(396, 349),    //
    S(327, 392),    S(415, 371),    S(487, 351),    S(417, 386),    S(435, 368),    S(386, 374),    S(327, 391),    S(321, 393),    //
    S(315, 364),    S(466, 330),    S(494, 322),    S(501, 308),    S(454, 314),    S(382, 355),    S(401, 340),    S(288, 384),    //
    S(290, 349),    S(365, 351),    S(398, 340),    S(421, 298),    S(391, 317),    S(334, 362),    S(316, 361),    S(248, 364),    //
    S(228, 300),    S(308, 306),    S(294, 325),    S(279, 322),    S(274, 316),    S(257, 356),    S(230, 352),    S(211, 340),    //
    S(207, 274),    S(281, 249),    S(276, 280),    S(256, 282),    S(273, 262),    S(223, 318),    S(222, 300),    S(200, 293),    //
    S(143, 291),    S(243, 224),    S(268, 240),    S(271, 246),    S(265, 252),    S(246, 268),    S(226, 245),    S(195, 260),    //
    S(178, 291),    S(209, 294),    S(261, 259),    S(287, 242),    S(273, 258),    S(261, 270),    S(245, 262),    S(228, 277),    //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(652, 623),    S(689, 604),    S(695, 610),    S(592, 725),    S(647, 659),    S(596, 678),    S(646, 611),    S(583, 623),    //
    S(610, 712),    S(535, 818),    S(538, 860),    S(463, 871),    S(482, 830),    S(466, 831),    S(514, 739),    S(558, 663),    //
    S(566, 748),    S(652, 758),    S(597, 819),    S(583, 826),    S(543, 803),    S(510, 802),    S(581, 699),    S(553, 656),    //
    S(635, 652),    S(637, 728),    S(600, 766),    S(589, 824),    S(569, 805),    S(562, 737),    S(600, 642),    S(593, 594),    //
    S(600, 676),    S(632, 646),    S(607, 717),    S(566, 773),    S(554, 761),    S(562, 716),    S(577, 631),    S(580, 577),    //
    S(611, 517),    S(634, 564),    S(633, 637),    S(580, 664),    S(591, 625),    S(596, 626),    S(607, 556),    S(586, 552),    //
    S(594, 415),    S(627, 312),    S(613, 453),    S(630, 529),    S(604, 548),    S(621, 481),    S(595, 542),    S(579, 539),    //
    S(541, 495),    S(601, 246),    S(596, 257),    S(623, 350),    S(625, 436),    S(628, 394),    S(615, 433),    S(562, 506),    //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(-163, -381),  S(70, 17),      S(-29, 35),     S(-126, 57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(155, -85),    S(-23, 214),    S(47, 183),     S(178, 103),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-49, 72),     S(54, 197),     S(137, 157),    S(150, 105),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-264, 84),    S(21, 145),     S(46, 141),     S(29, 121),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-238, 45),    S(-66, 113),    S(-36, 120),    S(-92, 157),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-150, 3),     S(31, 37),      S(-61, 100),    S(-94, 132),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(57, -96),     S(105, -29),    S(15, 28),      S(-66, 78),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-66, -154),   S(59, -114),    S(-42, -76),    S(-58, -75),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

// Epoch duration: 6.91774s
// clang-format on
}  // namespace Clockwork
