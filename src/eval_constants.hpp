#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(186, 453);
inline const PParam KNIGHT_MAT = S(865, 1310);
inline const PParam BISHOP_MAT = S(908, 1387);
inline const PParam ROOK_MAT   = S(1101, 2257);
inline const PParam QUEEN_MAT  = S(2530, 4061);
inline const PParam TEMPO_VAL  = S(63, 22);

inline const PParam BISHOP_XRAY_PAWNS   = S(-15, 15);
inline const PParam BISHOP_PAIR_VAL   = S(56, 229);
inline const PParam ROOK_OPEN_VAL     = S(122, -8);
inline const PParam ROOK_SEMIOPEN_VAL = S(42, 40);
inline const PParam MINOR_BEHIND_PAWN = S(15, 43);
inline const PParam RESTRICTED_SQUARES = S(-23, -7);

inline const PParam DOUBLED_PAWN_VAL = S(-15, -85);
inline const PParam ISOLATED_PAWN_VAL = S(-17, -26);

inline const PParam POTENTIAL_CHECKER_VAL = S(3, 4);
inline const PParam OUTPOST_KNIGHT_VAL    = S(55, 59);
inline const PParam OUTPOST_BISHOP_VAL    = S(60, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 3);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(46, -18);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(29, 45);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -49);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(14, -4), S(31, 31), S(58, 63), S(127, 192), S(302, 467), S(614, 652),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(47, 42), S(44, 36), S(64, 66), S(111, 181), S(355, 236),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-99, -230), S(-92, -199), S(-65, -82), S(-10, 20), S(76, 243), S(253, 320),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -35), S(18, 4), S(7, 43), S(3, 120), S(110, 177), S(195, 346),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(18, -27), S(9, 7), S(1, -29), S(5, -64), S(-33, -105), S(-238, -201),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(3, 218), S(-14, 179), S(-7, 99), S(4, 60), S(19, 54), S(57, 50), S(44, 38),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-236, 32), S(-20, 58), S(-5, 107), S(34, 136), S(51, 162), S(67, 162), S(43, 158),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-94, -317), S(-30, -122), S(2, -20), S(27, 17), S(57, 35), S(74, 65), S(96, 60), S(116, 61), S(151, -21),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-58, -274), S(-11, -119), S(38, -54), S(59, -1), S(80, 38), S(92, 66), S(98, 86), S(105, 97), S(106, 110), S(117, 98), S(123, 90), S(159, 37), S(164, 30), S(183, -51),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(109, -170), S(20, -6), S(42, 22), S(58, 36), S(68, 53), S(72, 66), S(77, 80), S(84, 83), S(89, 94), S(96, 100), S(103, 103), S(106, 108), S(105, 112), S(110, 89), S(182, -24),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-168, -108), S(-46, 79), S(-20, 198), S(1, 313), S(17, 351), S(24, 397), S(30, 428), S(36, 442), S(40, 465), S(42, 483), S(47, 490), S(51, 497), S(54, 499), S(55, 504), S(55, 505), S(51, 507), S(47, 506), S(47, 497), S(46, 492), S(49, 482), S(45, 462), S(57, 424), S(26, 452), S(4, 410), S(-14, 390), S(-43, 393), S(-90, 407), S(-77, 340),
};

inline const PParam PAWN_THREAT_KNIGHT = S(210, 118);
inline const PParam PAWN_THREAT_BISHOP = S(190, 171);
inline const PParam PAWN_THREAT_ROOK   = S(212, 118);
inline const PParam PAWN_THREAT_QUEEN  = S(176, 3);

inline const PParam KNIGHT_THREAT_BISHOP = S(110, 115);
inline const PParam KNIGHT_THREAT_ROOK   = S(222, 86);
inline const PParam KNIGHT_THREAT_QUEEN  = S(153, -10);

inline const PParam BISHOP_THREAT_KNIGHT = S(99, 75);
inline const PParam BISHOP_THREAT_ROOK   = S(212, 148);
inline const PParam BISHOP_THREAT_QUEEN  = S(181, 90);

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(8, -25), S(0, -7), S(-3, -17), S(-7, -27), S(-11, -37), S(-15, -44), S(-16, -57), S(-21, -58), S(-27, -69),
};

inline const PParam ROOK_LINEUP = S(17, 72);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(202, 228),    S(50, 320),     S(77, 252),     S(135, 204),    S(184, 130),    S(110, 208),    S(79, 261),     S(228, 199),    //
    S(15, 51),      S(17, 98),      S(-3, 40),      S(43, -64),     S(38, -100),    S(-5, -40),     S(-17, 26),     S(-40, 60),     //
    S(21, -2),      S(-7, 23),      S(19, -15),     S(19, -79),     S(13, -103),    S(-11, -74),    S(-50, -28),    S(-53, 9),      //
    S(-15, -59),    S(-41, -18),    S(-3, -39),     S(-9, -83),     S(-24, -99),    S(-36, -79),    S(-91, -41),    S(-83, -44),    //
    S(-19, -93),    S(24, -100),    S(10, -35),     S(-1, -66),     S(-27, -76),    S(-44, -77),    S(-80, -61),    S(-85, -62),    //
    S(5, -75),      S(90, -105),    S(83, -96),     S(36, -46),     S(10, -64),     S(-14, -73),    S(-48, -47),    S(-62, -46),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-288, -448),  S(-265, 16),    S(-312, -87),   S(6, -6),       S(-91, 6),      S(-261, 34),    S(-392, 85),    S(-377, -327),  //
    S(-24, -36),    S(-2, 1),       S(89, -18),     S(92, 0),       S(100, -3),     S(41, 1),       S(-21, 2),      S(-38, -22),    //
    S(47, -50),     S(47, -0),      S(82, 40),      S(88, 51),      S(72, 70),      S(28, 70),      S(13, 8),       S(-36, -7),     //
    S(107, -2),     S(103, 32),     S(117, 58),     S(118, 91),     S(134, 84),     S(83, 74),      S(65, 26),      S(45, 8),       //
    S(74, 5),       S(121, -15),    S(105, 51),     S(103, 73),     S(83, 74),      S(81, 69),      S(72, -4),      S(21, 12),      //
    S(12, -39),     S(38, -2),      S(37, 49),      S(54, 69),      S(47, 66),      S(18, 39),      S(12, -2),      S(-30, -47),    //
    S(33, -41),     S(33, -26),     S(18, -15),     S(22, 12),      S(20, 11),      S(-6, -36),     S(-33, -12),    S(-42, -107),   //
    S(-40, -93),    S(7, -38),      S(26, -59),     S(46, -45),     S(26, -26),     S(-11, -56),    S(-23, -34),    S(-64, -134),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-132, 20),    S(-173, 84),    S(-486, 172),   S(-304, 82),    S(-308, 103),   S(-318, 111),   S(-207, 100),   S(-132, 53),    //
    S(-45, -24),    S(-94, 79),     S(-47, 23),     S(-105, 56),    S(-86, 45),     S(-49, 29),     S(-26, 27),     S(-54, -0),     //
    S(24, 8),       S(21, 34),      S(28, 47),      S(26, 30),      S(13, 22),      S(11, 35),      S(12, 28),      S(12, -8),      //
    S(16, -19),     S(46, 8),       S(67, 20),      S(69, 57),      S(102, 45),     S(43, 16),      S(47, -14),     S(1, -17),      //
    S(50, -61),     S(52, -18),     S(79, 9),       S(92, 31),      S(78, 39),      S(73, 17),      S(23, -5),      S(22, -46),     //
    S(62, -37),     S(86, -26),     S(100, 3),      S(70, 27),      S(66, 7),       S(64, 11),      S(76, -14),     S(21, -30),     //
    S(37, -100),    S(120, -70),    S(79, -35),     S(51, -12),     S(35, -8),      S(54, -49),     S(53, -63),     S(46, -63),     //
    S(56, -88),     S(28, -36),     S(28, -12),     S(53, -35),     S(35, -29),     S(40, 8),       S(50, -27),     S(44, -59),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(191, 91),     S(234, 88),     S(188, 109),    S(185, 85),     S(235, 64),     S(185, 88),     S(205, 97),     S(176, 114),    //
    S(86, 166),     S(160, 163),    S(241, 114),    S(167, 145),    S(212, 129),    S(174, 142),    S(109, 172),    S(92, 173),     //
    S(47, 161),     S(181, 117),    S(215, 96),     S(198, 76),     S(194, 99),     S(130, 136),    S(130, 140),    S(60, 183),     //
    S(21, 118),     S(98, 132),     S(122, 110),    S(103, 109),    S(136, 90),     S(94, 128),     S(88, 134),     S(14, 157),     //
    S(-9, 46),      S(68, 60),      S(51, 85),      S(24, 81),      S(40, 82),      S(30, 103),     S(6, 103),      S(-16, 98),     //
    S(4, -37),      S(82, -11),     S(66, 13),      S(49, 8),       S(61, 8),       S(35, 36),      S(43, 14),      S(-9, 26),      //
    S(-86, -32),    S(54, -81),     S(54, -39),     S(44, -14),     S(52, -20),     S(37, -10),     S(29, -29),     S(-7, -14),     //
    S(-19, -71),    S(-4, -35),     S(64, -47),     S(76, -53),     S(75, -44),     S(54, -24),     S(53, -35),     S(33, -30),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(43, 194),     S(158, 106),    S(57, 250),     S(-2, 352),     S(36, 305),     S(71, 218),     S(59, 161),     S(-20, 228),    //
    S(46, 196),     S(64, 259),     S(29, 334),     S(-111, 448),   S(-60, 423),    S(-5, 325),     S(34, 199),     S(6, 188),      //
    S(17, 238),     S(31, 309),     S(-3, 383),     S(-33, 404),    S(-15, 392),    S(24, 300),     S(56, 198),     S(57, 118),     //
    S(25, 160),     S(10, 268),     S(-25, 331),    S(-48, 402),    S(-27, 406),    S(12, 272),     S(53, 172),     S(29, 137),     //
    S(5, 163),      S(-2, 197),     S(-24, 262),    S(-45, 326),    S(-30, 353),    S(-2, 269),     S(8, 191),      S(35, 93),      //
    S(9, 55),       S(28, 85),      S(16, 169),     S(-7, 191),     S(4, 194),      S(8, 220),      S(34, 142),     S(27, 95),      //
    S(-24, -88),    S(11, -92),     S(10, 0),       S(27, 43),      S(21, 86),      S(27, 60),      S(4, 82),       S(21, 59),      //
    S(-35, -73),    S(-15, -223),   S(10, -209),    S(24, -98),     S(27, -22),     S(33, -62),     S(31, -34),     S(4, 4),        //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(67, -395),    S(345, 224),    S(222, 293),    S(8, 218),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(261, -83),    S(290, 199),    S(116, 287),    S(-10, 231),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(157, 68),     S(185, 187),    S(56, 279),     S(-54, 262),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-27, 30),     S(61, 134),     S(-93, 261),    S(-138, 301),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-123, -20),   S(-35, 63),     S(-128, 201),   S(-222, 295),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-43, -94),    S(15, -12),     S(-108, 147),   S(-169, 235),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(36, -178),    S(29, -80),     S(-64, 53),     S(-139, 153),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-7, -281),    S(8, -159),     S(-94, -36),    S(-83, -12),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-42, 57);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(5, -2), S(6, 3), S(6, 3), S(4, -1), S(2, -3),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(2, -1), S(2, 2), S(2, 0), S(2, -0), S(2, -0),
};

inline const PParam KS_FLANK_ATTACK = S(2, -2);
inline const PParam KS_FLANK_DEFENSE = S(-2, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(2, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-1, 1);

inline const std::array<std::array<PParam, 2>, 4> KS_SAFE_CHECKS = {{
  {{ S(11, 5), S(15, -9), }},
  {{ S(4, 12), S(13, 8), }},
  {{ S(8, 6), S(8, 3), }},
  {{ S(6, 3), S(15, -5), }},
}};

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(9, -10), S(-5, 1), S(-3, -5), S(4, -10), S(8, -17), S(2, -22), S(-2, -21), }},
  {{ S(-2, -2), S(-15, -3), S(-12, 0), S(-6, 0), S(-4, -4), S(-9, -9), S(-13, -15), }},
  {{ S(-6, -4), S(-10, -11), S(-10, 4), S(-7, 3), S(-6, -1), S(-10, -9), S(-18, -20), }},
  {{ S(-0, 11), S(-7, 8), S(-5, 13), S(-2, 13), S(-1, 10), S(-0, 11), S(1, -1), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(2, 20), S(-7, 8), S(-10, 13), S(-10, 23), S(-2, 21),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(-1, 12), S(-17, -44), S(0, -27), S(1, -2), S(-4, 6), S(-8, 11), S(-7, 11), }},
  {{ S(2, 6), S(-10, -39), S(5, -29), S(-1, -4), S(-2, 1), S(-8, 7), S(-2, 6), }},
  {{ S(-5, 10), S(-0, -33), S(11, -23), S(-2, 4), S(-6, 8), S(-10, 13), S(-8, 15), }},
  {{ S(-2, 3), S(13, -42), S(10, -25), S(-1, 5), S(-7, 8), S(-10, 8), S(-9, 11), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        2153, 1581, -28, -7
);

inline VParam WINNABLE_PAWNS = V(-24);
inline VParam WINNABLE_SYM = V(128);
inline VParam WINNABLE_ASYM = V(113);
inline VParam WINNABLE_PAWN_ENDGAME = V(172);
inline VParam WINNABLE_BIAS = V(-494);

// Epoch duration: 8.29556s
// clang-format on
}  // namespace Clockwork
