#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(201, 504);
inline const PParam KNIGHT_MAT = S(812, 1582);
inline const PParam BISHOP_MAT = S(863, 1668);
inline const PParam ROOK_MAT   = S(1034, 2653);
inline const PParam QUEEN_MAT  = S(2402, 4096);

inline const PParam TEMPO_VAL  = S(69, 53);

inline const PParam BISHOP_XRAY_PAWNS   = S(-13, -3);
inline const PParam BISHOP_PAIR_VAL   = S(61, 239);
inline const PParam ROOK_OPEN_VAL     = S(109, -4);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 11);
inline const PParam MINOR_BEHIND_PAWN = S(15, 41);
inline const PParam RESTRICTED_SQUARES = S(19, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-21, -81);
inline const PParam ISOLATED_PAWN_VAL = S(-13, -39);

inline const PParam POTENTIAL_CHECKER_VAL = S(-45, -42);
inline const PParam OUTPOST_KNIGHT_VAL    = S(49, 44);
inline const PParam OUTPOST_BISHOP_VAL    = S(42, 39);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(39, 50);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(42, 3);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(17, 70);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(62, -51);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(15, -1), S(33, 35), S(59, 65), S(121, 212), S(386, 402), S(672, 816),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(48, 32), S(39, 25), S(53, 56), S(90, 180), S(384, 121),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-93, -259), S(-94, -217), S(-67, -86), S(-22, 39), S(87, 199), S(227, 404),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-80, 53), S(-92, 35), S(-58, 104), S(-88, 228), S(-55, 339), S(51, 221),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-16, 68), S(-28, 59), S(-60, 107), S(-32, 134), S(73, 158), S(34, 192),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(24, -39), S(24, -2), S(16, 34), S(21, 103), S(70, 270), S(332, 215),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(14, -36), S(2, 8), S(-3, -27), S(-0, -68), S(-14, -175), S(-166, -450),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(20, 233), S(9, 181), S(4, 106), S(12, 67), S(20, 72), S(58, 67), S(61, 38),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-132, -47), S(14, -4), S(1, 99), S(27, 149), S(43, 183), S(54, 192), S(40, 172),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-91, -392), S(-23, -140), S(7, -26), S(30, 23), S(57, 55), S(73, 92), S(90, 99), S(109, 108), S(129, 61),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-71, -349), S(-18, -129), S(35, -40), S(59, 14), S(78, 56), S(90, 87), S(95, 110), S(98, 131), S(102, 142), S(109, 148), S(117, 142), S(131, 125), S(131, 130), S(116, 95),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(99, -215), S(23, -13), S(44, 21), S(60, 39), S(71, 58), S(75, 72), S(79, 88), S(85, 94), S(90, 106), S(95, 114), S(99, 120), S(99, 130), S(102, 134), S(107, 121), S(127, 82),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-192, -206), S(-38, -93), S(-14, 49), S(5, 189), S(22, 231), S(29, 284), S(36, 322), S(43, 339), S(47, 362), S(51, 379), S(57, 387), S(61, 394), S(64, 401), S(67, 406), S(67, 409), S(67, 411), S(63, 414), S(66, 406), S(67, 402), S(71, 394), S(61, 385), S(72, 359), S(38, 387), S(-8, 379), S(-42, 378), S(-76, 400), S(-135, 428), S(-101, 364),
};

inline const PParam PAWN_THREAT_KNIGHT = S(196, 154);
inline const PParam PAWN_THREAT_BISHOP = S(171, 221);
inline const PParam PAWN_THREAT_ROOK   = S(187, 155);
inline const PParam PAWN_THREAT_QUEEN  = S(159, 13);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(7, 57), S(93, 94), S(103, 125), S(205, 123), S(162, 3), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(7, 57), S(53, 96), S(74, 95), S(17, 11), S(150, -48), S(0, 0),
};
inline const PParam KING_THREAT  = S(-11, 156);
inline const PParam HANGING_PAWN  = S(31, 93);
inline const PParam HANGING_NON_PAWN  = S(69, 28);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(21, -17), S(22, 9),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(42, 45), S(108, -105),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(37, 11), S(47, -6),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -17), S(4, -15), S(-1, -21), S(-6, -29), S(-12, -37), S(-17, -43), S(-19, -55), S(-25, -56), S(-30, -73),
};

inline const PParam ROOK_LINEUP = S(17, 80);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(182, 274),    S(62, 395),     S(68, 383),     S(155, 269),    S(189, 168),    S(142, 209),    S(121, 239),    S(221, 178),    //
    S(41, 63),      S(55, 108),     S(33, 61),      S(47, -6),      S(39, -42),     S(12, -14),     S(14, 26),      S(-20, 53),     //
    S(38, -13),     S(15, -5),      S(44, -45),     S(25, -69),     S(17, -87),     S(3, -75),      S(-36, -44),    S(-38, -5),     //
    S(-6, -73),     S(-31, -43),    S(1, -62),      S(-10, -78),    S(-31, -87),    S(-36, -75),    S(-82, -57),    S(-76, -52),    //
    S(-14, -110),   S(18, -106),    S(3, -45),      S(-13, -50),    S(-40, -60),    S(-53, -71),    S(-79, -72),    S(-83, -74),    //
    S(9, -107),     S(82, -95),     S(71, -40),     S(25, -11),     S(-5, -32),     S(-24, -60),    S(-50, -59),    S(-62, -58),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-259, -499),  S(-256, 50),    S(-263, -30),   S(0, 41),       S(-91, 42),     S(-265, 82),    S(-344, 98),    S(-346, -403),  //
    S(-2, -12),     S(2, 27),       S(86, 25),      S(84, 60),      S(89, 48),      S(51, 28),      S(-16, 24),     S(-44, 22),     //
    S(40, -25),     S(42, 28),      S(57, 60),      S(73, 70),      S(57, 71),      S(21, 56),      S(8, 35),       S(-34, 9),      //
    S(89, 22),      S(91, 47),      S(101, 68),     S(104, 108),    S(108, 107),    S(72, 71),      S(52, 37),      S(33, 31),      //
    S(78, 15),      S(101, 2),      S(99, 49),      S(94, 79),      S(81, 82),      S(73, 63),      S(58, 18),      S(24, 24),      //
    S(19, -42),     S(44, -25),     S(51, 20),      S(63, 52),      S(58, 50),      S(31, 14),      S(15, -18),     S(-23, -41),    //
    S(37, -25),     S(39, -11),     S(27, -19),     S(37, 8),       S(34, 6),       S(5, -44),      S(-30, -1),     S(-49, -82),    //
    S(-44, -92),    S(10, -29),     S(28, -43),     S(44, -33),     S(28, -19),     S(-9, -51),     S(-20, -27),    S(-71, -140),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-128, 20),    S(-189, 101),   S(-398, 165),   S(-270, 97),    S(-300, 139),   S(-301, 151),   S(-223, 125),   S(-126, 70),    //
    S(-26, -21),    S(-64, 86),     S(-46, 62),     S(-67, 60),     S(-65, 74),     S(-38, 46),     S(-10, 41),     S(-51, 24),     //
    S(35, 18),      S(17, 57),      S(31, 68),      S(28, 53),      S(23, 43),      S(21, 47),      S(10, 42),      S(11, 12),      //
    S(17, -7),      S(50, 20),      S(61, 35),      S(80, 55),      S(103, 40),     S(42, 19),      S(45, -4),      S(-1, -3),      //
    S(37, -45),     S(45, 2),       S(77, 13),      S(92, 26),      S(76, 37),      S(66, 24),      S(21, 4),       S(10, -38),     //
    S(57, -30),     S(81, -25),     S(96, 5),       S(64, 28),      S(61, 13),      S(57, 13),      S(59, -4),      S(17, -23),     //
    S(27, -73),     S(113, -57),    S(66, -19),     S(48, -2),      S(31, -2),      S(45, -44),     S(45, -58),     S(38, -50),     //
    S(43, -72),     S(23, -25),     S(30, -10),     S(44, -32),     S(28, -19),     S(38, 14),      S(44, -17),     S(39, -61),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(174, 107),    S(201, 128),    S(155, 157),    S(140, 130),    S(201, 84),     S(158, 112),    S(167, 127),    S(151, 125),    //
    S(87, 149),     S(144, 153),    S(185, 126),    S(140, 112),    S(177, 98),     S(145, 123),    S(98, 155),     S(88, 156),     //
    S(57, 143),     S(177, 86),     S(202, 71),     S(173, 57),     S(178, 73),     S(120, 114),    S(115, 129),    S(62, 169),     //
    S(30, 111),     S(92, 118),     S(111, 93),     S(95, 94),      S(122, 76),     S(83, 118),     S(75, 131),     S(20, 157),     //
    S(5, 44),       S(63, 54),      S(56, 76),      S(25, 85),      S(35, 89),      S(24, 114),     S(7, 111),      S(-14, 115),    //
    S(17, -36),     S(84, -10),     S(72, 15),      S(50, 27),      S(59, 35),      S(37, 57),      S(33, 42),      S(-5, 48),      //
    S(-63, -41),    S(61, -77),     S(67, -40),     S(56, -6),      S(59, -6),      S(45, 8),       S(35, -8),      S(4, -5),       //
    S(0, -63),      S(24, -32),     S(86, -43),     S(95, -43),     S(97, -38),     S(74, -16),     S(68, -22),     S(47, -17),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(89, 154),     S(145, 154),    S(57, 295),     S(-3, 394),     S(34, 348),     S(72, 255),     S(71, 174),     S(26, 205),     //
    S(58, 182),     S(77, 237),     S(37, 319),     S(-81, 434),    S(-41, 407),    S(19, 286),     S(58, 173),     S(40, 144),     //
    S(20, 232),     S(59, 260),     S(28, 336),     S(-9, 370),     S(11, 358),     S(50, 257),     S(81, 154),     S(62, 118),     //
    S(16, 170),     S(28, 236),     S(-12, 303),    S(-12, 356),    S(5, 350),      S(22, 235),     S(60, 153),     S(35, 116),     //
    S(13, 143),     S(11, 165),     S(3, 215),      S(-22, 284),    S(-11, 300),    S(11, 234),     S(16, 173),     S(36, 80),      //
    S(4, 50),       S(34, 59),      S(31, 134),     S(10, 155),     S(19, 162),     S(22, 185),     S(41, 114),     S(21, 94),      //
    S(-24, -94),    S(5, -94),      S(13, -26),     S(40, 13),      S(36, 52),      S(39, 24),      S(12, 63),      S(25, 36),      //
    S(-41, -80),    S(-10, -240),   S(21, -243),    S(33, -134),    S(40, -55),     S(38, -74),     S(36, -61),     S(5, -7),       //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(167, -550),   S(473, 83),     S(313, 194),    S(20, 190),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(366, -181),   S(363, 189),    S(209, 203),    S(26, 156),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(197, 46),     S(230, 175),    S(114, 198),    S(-49, 179),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, 8),       S(113, 114),    S(-21, 171),    S(-117, 201),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-112, -0),    S(-22, 78),     S(-85, 147),    S(-180, 198),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-54, -32),    S(12, 34),      S(-68, 115),    S(-123, 160),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(23, -91),     S(29, -11),     S(-33, 51),     S(-108, 107),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-23, -208),   S(3, -90),      S(-73, -26),    S(-82, -39),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-80, -447);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(7, -4), S(10, 12), S(10, 5), S(4, 2), S(3, -9),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(4, -7), S(5, 5), S(2, 2), S(3, -0), S(4, -2),
};

inline const PParam KS_FLANK_ATTACK = S(3, -2);
inline const PParam KS_FLANK_DEFENSE = S(-3, -0);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -1);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, 2);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(16, -19), S(-6, 5), S(-3, -9), S(7, -16), S(12, -29), S(7, -53), S(-4, -45), }},
  {{ S(2, 4), S(-21, 2), S(-17, 10), S(-10, 18), S(-6, 8), S(-9, -12), S(-19, -21), }},
  {{ S(-5, -1), S(-13, -8), S(-14, 18), S(-10, 19), S(-8, 10), S(-8, -16), S(-24, -37), }},
  {{ S(6, 9), S(-10, 18), S(-7, 38), S(-2, 43), S(-2, 38), S(3, 19), S(9, -14), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(9, 23), S(-6, 3), S(-7, 10), S(-6, 28), S(1, 48),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(5, 11), S(-41, -123), S(-9, -39), S(-1, 5), S(-3, 4), S(-6, 11), S(-5, 10), }},
  {{ S(8, -1), S(-25, -125), S(-6, -29), S(-4, 1), S(-2, -3), S(-9, 4), S(1, 3), }},
  {{ S(-0, 11), S(-8, -69), S(7, -15), S(0, 9), S(-4, 11), S(-9, 19), S(-6, 21), }},
  {{ S(0, 0), S(3, -63), S(-1, 25), S(-3, 25), S(-6, 8), S(-12, 11), S(-9, 19), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1422, 904, -21, -4
);

inline VParam WINNABLE_PAWNS = V(-20);
inline VParam WINNABLE_SYM = V(101);
inline VParam WINNABLE_ASYM = V(87);
inline VParam WINNABLE_PAWN_ENDGAME = V(75);
inline VParam WINNABLE_BIAS = V(-386);

// Epoch duration: 7.65336s
// clang-format on
}  // namespace Clockwork
