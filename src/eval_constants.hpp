#pragma once

#include "eval_types.hpp"

namespace Clockwork {

// clang-format off
inline const PParam PAWN_MAT   = S(217, 471);
inline const PParam KNIGHT_MAT = S(851, 1457);
inline const PParam BISHOP_MAT = S(900, 1548);
inline const PParam ROOK_MAT   = S(1105, 2472);
inline const PParam QUEEN_MAT  = S(2695, 3980);

inline const PParam TEMPO_VAL  = S(64, 45);

inline const PParam BISHOP_XRAY_PAWNS   = S(-14, -1);
inline const PParam BISHOP_PAIR_VAL   = S(64, 218);
inline const PParam ROOK_OPEN_VAL     = S(108, -7);
inline const PParam ROOK_SEMIOPEN_VAL = S(43, 11);
inline const PParam MINOR_BEHIND_PAWN = S(16, 37);
inline const PParam RESTRICTED_SQUARES = S(18, 7);

inline const PParam DOUBLED_PAWN_VAL = S(-24, -74);
inline const PParam ISOLATED_PAWN_VAL = S(-15, -34);

inline const PParam POTENTIAL_CHECKER_VAL = S(-44, -29);
inline const PParam OUTPOST_KNIGHT_VAL    = S(54, 38);
inline const PParam OUTPOST_BISHOP_VAL    = S(47, 34);

inline const PParam PAWN_PUSH_THREAT_KNIGHT = S(38, 41);
inline const PParam PAWN_PUSH_THREAT_BISHOP = S(40, 0);
inline const PParam PAWN_PUSH_THREAT_ROOK   = S(19, 60);
inline const PParam PAWN_PUSH_THREAT_QUEEN  = S(60, -44);

inline const std::array<PParam, 6> PAWN_PHALANX = {
    S(19, 4), S(39, 31), S(62, 60), S(116, 198), S(435, 361), S(703, 1248),
};
inline const std::array<PParam, 5> DEFENDED_PAWN = {
    S(52, 27), S(43, 19), S(63, 44), S(118, 151), S(459, 80),
};
inline const std::array<PParam, 6> PASSED_PAWN = {
    S(-99, -220), S(-99, -189), S(-70, -70), S(-17, 38), S(91, 186), S(237, 335),
};
inline const std::array<PParam, 6> PASSED_CLEAR_STOPPERS = {
    S(-87, 54), S(-88, 43), S(-69, 107), S(-59, 198), S(-27, 297), S(106, 158),
};
inline const std::array<PParam, 6> PASSED_CLEAR_FORWARD = {
    S(-13, 57), S(-27, 55), S(-42, 94), S(-9, 116), S(91, 138), S(61, 173),
};
inline const std::array<PParam, 6> DEFENDED_PASSED_PUSH = {
    S(26, -40), S(24, 0), S(17, 37), S(23, 101), S(91, 254), S(377, 97),
};
inline const std::array<PParam, 6> BLOCKED_PASSED_PAWN = {
    S(6, -30), S(-3, 14), S(-11, -20), S(4, -64), S(-10, -159), S(-191, -396),
};

inline const std::array<PParam, 8> FRIENDLY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(22, 213), S(-0, 173), S(0, 95), S(10, 59), S(23, 62), S(66, 58), S(61, 35),
};
inline const std::array<PParam, 8> ENEMY_KING_PASSED_PAWN_DISTANCE = {
    S(0, 0), S(-141, -26), S(5, 14), S(4, 95), S(36, 126), S(50, 158), S(56, 172), S(36, 163),
};

inline const std::array<PParam, 9> KNIGHT_MOBILITY = {
    S(-81, -359), S(-21, -138), S(11, -32), S(37, 8), S(65, 37), S(80, 68), S(98, 75), S(114, 83), S(132, 39),
};
inline const std::array<PParam, 14> BISHOP_MOBILITY = {
    S(-35, -248), S(-2, -116), S(43, -62), S(60, -13), S(83, 24), S(94, 51), S(98, 72), S(101, 90), S(104, 104), S(110, 108), S(121, 104), S(133, 87), S(141, 91), S(88, 84),
};
inline const std::array<PParam, 15> ROOK_MOBILITY = {
    S(109, -200), S(27, -24), S(47, 5), S(62, 18), S(72, 35), S(76, 46), S(81, 59), S(87, 64), S(92, 75), S(98, 81), S(103, 87), S(102, 96), S(105, 98), S(111, 85), S(141, 31),
};
inline const std::array<PParam, 28> QUEEN_MOBILITY = {
    S(-138, -217), S(-34, -35), S(-6, 68), S(13, 168), S(27, 212), S(35, 253), S(41, 280), S(46, 300), S(51, 315), S(55, 328), S(59, 339), S(63, 344), S(67, 348), S(70, 348), S(71, 350), S(71, 349), S(71, 345), S(75, 335), S(79, 323), S(85, 307), S(82, 296), S(96, 263), S(61, 288), S(30, 268), S(-16, 290), S(-30, 283), S(-98, 328), S(-45, 253),
};

inline const PParam PAWN_THREAT_KNIGHT = S(203, 118);
inline const PParam PAWN_THREAT_BISHOP = S(176, 190);
inline const PParam PAWN_THREAT_ROOK   = S(183, 135);
inline const PParam PAWN_THREAT_QUEEN  = S(161, -13);

inline const std::array<PParam, 6> MINOR_THREAT = {
    S(11, 50), S(88, 87), S(100, 111), S(211, 93), S(150, 28), S(0, 0),
};
inline const std::array<PParam, 6> ROOK_THREAT = {
    S(11, 51), S(56, 86), S(77, 78), S(13, 18), S(132, -9), S(0, 0),
};
inline const PParam KING_THREAT  = S(17, 113);
inline const PParam HANGING_PAWN  = S(36, 85);
inline const PParam HANGING_NON_PAWN  = S(65, 25);

inline const std::array<PParam, 2> KNIGHT_ON_QUEEN = {
    S(17, -3), S(57, -51),
};
inline const std::array<PParam, 2> BISHOP_ON_QUEEN = {
    S(36, 56), S(148, -137),
};
inline const std::array<PParam, 2> ROOK_ON_QUEEN = {
    S(28, 33), S(51, 12),
};

inline const std::array<PParam, 9> BISHOP_PAWNS = {
    S(4, -16), S(5, -14), S(1, -21), S(-4, -29), S(-10, -37), S(-15, -46), S(-18, -55), S(-21, -65), S(-28, -77),
};

inline const PParam ROOK_LINEUP = S(15, 81);

inline const std::array<PParam, 48> PAWN_PSQT = {
    S(205, 186),    S(27, 342),     S(77, 334),     S(145, 235),    S(184, 156),    S(124, 211),    S(88, 242),     S(246, 140),    //
    S(52, 22),      S(45, 73),      S(35, 36),      S(36, -23),     S(26, -56),     S(0, -20),      S(-10, 20),     S(-13, 35),     //
    S(27, -17),     S(0, -12),      S(32, -48),     S(22, -68),     S(12, -79),     S(-11, -61),    S(-39, -35),    S(-38, -4),     //
    S(-10, -73),    S(-26, -50),    S(3, -65),      S(-0, -72),     S(-22, -79),    S(-37, -66),    S(-79, -45),    S(-73, -47),    //
    S(-14, -104),   S(22, -106),    S(9, -40),      S(-4, -45),     S(-31, -55),    S(-50, -58),    S(-74, -60),    S(-78, -62),    //
    S(8, -104),     S(83, -103),    S(69, -46),     S(30, -18),     S(-1, -37),     S(-22, -50),    S(-43, -51),    S(-57, -51),    //
};
inline const std::array<PParam, 64> KNIGHT_PSQT = {
    S(-271, -492),  S(-273, 57),    S(-191, -235),  S(18, 25),      S(-80, 53),     S(-280, 79),    S(-365, 97),    S(-374, -362),  //
    S(5, -29),      S(4, 21),       S(96, -3),      S(93, 52),      S(97, 50),      S(63, 20),      S(-23, 36),     S(-28, 12),     //
    S(23, -17),     S(29, 27),      S(78, 48),      S(79, 72),      S(73, 66),      S(27, 61),      S(5, 36),       S(-33, 10),     //
    S(100, 17),     S(88, 46),      S(97, 72),      S(96, 114),     S(105, 105),    S(73, 73),      S(56, 36),      S(52, 26),      //
    S(80, 11),      S(109, 0),      S(102, 46),     S(89, 80),      S(79, 80),      S(77, 61),      S(63, 16),      S(33, 24),      //
    S(18, -42),     S(50, -24),     S(52, 9),       S(68, 45),      S(58, 44),      S(36, 6),       S(23, -15),     S(-11, -34),    //
    S(38, -33),     S(39, -12),     S(34, -29),     S(39, -2),      S(34, 2),       S(10, -44),     S(-21, -17),    S(-31, -93),    //
    S(-30, -101),   S(20, -42),     S(31, -56),     S(53, -42),     S(36, -25),     S(4, -66),      S(-4, -33),     S(-47, -140),   //
};
inline const std::array<PParam, 64> BISHOP_PSQT = {
    S(-101, -1),    S(-172, 84),    S(-370, 160),   S(-220, 99),    S(-261, 120),   S(-283, 140),   S(-197, 124),   S(-113, 67),    //
    S(-27, -11),    S(-66, 77),     S(-30, 48),     S(-58, 69),     S(-63, 75),     S(-31, 47),     S(-11, 27),     S(-32, 23),     //
    S(44, 8),       S(32, 35),      S(38, 58),      S(32, 61),      S(25, 44),      S(15, 45),      S(15, 28),      S(11, 12),      //
    S(24, -7),      S(52, 15),      S(70, 27),      S(74, 49),      S(102, 35),     S(47, 23),      S(53, -1),      S(7, -0),       //
    S(54, -45),     S(50, -3),      S(76, 9),       S(96, 16),      S(83, 29),      S(73, 16),      S(27, 7),       S(24, -26),     //
    S(64, -31),     S(87, -32),     S(99, -0),      S(74, 23),      S(70, 9),       S(67, 10),      S(78, -12),     S(29, -19),     //
    S(39, -68),     S(117, -52),    S(77, -26),     S(58, -8),      S(37, -1),      S(60, -45),     S(58, -50),     S(60, -65),     //
    S(66, -76),     S(33, -42),     S(31, -11),     S(49, -37),     S(38, -27),     S(41, 7),       S(57, -34),     S(49, -56),     //
};
inline const std::array<PParam, 64> ROOK_PSQT = {
    S(179, 83),     S(197, 110),    S(162, 132),    S(133, 109),    S(184, 82),     S(173, 91),     S(177, 101),    S(148, 119),    //
    S(91, 127),     S(128, 136),    S(181, 102),    S(141, 98),     S(182, 83),     S(141, 108),    S(86, 141),     S(96, 134),     //
    S(42, 134),     S(163, 85),     S(185, 68),     S(164, 56),     S(168, 59),     S(117, 102),    S(122, 107),    S(67, 146),     //
    S(14, 103),     S(83, 100),     S(115, 76),     S(88, 73),      S(118, 67),     S(88, 103),     S(76, 112),     S(33, 128),     //
    S(-7, 39),      S(59, 45),      S(47, 58),      S(24, 65),      S(37, 64),      S(26, 95),      S(16, 88),      S(-0, 84),      //
    S(7, -38),      S(83, -38),     S(68, -8),      S(48, 7),       S(66, 5),       S(34, 40),      S(43, 18),      S(-2, 27),      //
    S(-77, -43),    S(55, -77),     S(73, -58),     S(65, -33),     S(64, -24),     S(54, -11),     S(38, -24),     S(12, -25),     //
    S(-3, -70),     S(6, -34),      S(77, -50),     S(91, -53),     S(87, -42),     S(72, -22),     S(68, -32),     S(55, -30),     //
};
inline const std::array<PParam, 64> QUEEN_PSQT = {
    S(91, 109),     S(157, 72),     S(80, 182),     S(31, 253),     S(58, 236),     S(88, 171),     S(97, 108),     S(7, 180),      //
    S(60, 182),     S(66, 235),     S(47, 250),     S(-65, 336),    S(-21, 318),    S(23, 239),     S(44, 164),     S(24, 151),     //
    S(22, 191),     S(70, 227),     S(35, 269),     S(4, 289),      S(18, 277),     S(55, 213),     S(73, 150),     S(51, 107),     //
    S(24, 123),     S(29, 190),     S(9, 219),      S(-3, 278),     S(3, 298),      S(26, 201),     S(64, 134),     S(37, 103),     //
    S(19, 89),      S(12, 138),     S(4, 173),      S(-20, 230),    S(-8, 253),     S(12, 203),     S(18, 148),     S(37, 78),      //
    S(14, 20),      S(35, 39),      S(28, 118),     S(9, 122),      S(16, 141),     S(19, 162),     S(36, 113),     S(24, 68),      //
    S(-10, -111),   S(4, -64),      S(17, -30),     S(32, 25),      S(29, 56),      S(31, 35),      S(13, 48),      S(26, 25),      //
    S(-6, -121),    S(-12, -239),   S(4, -214),     S(15, -97),     S(24, -9),      S(29, -58),     S(26, -50),     S(7, -23),      //
};
inline const std::array<PParam, 64> KING_PSQT = {
    S(202, -478),   S(430, 129),    S(269, 228),    S(27, 198),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(317, -156),   S(307, 170),    S(172, 209),    S(3, 182),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(168, 57),     S(206, 171),    S(99, 202),     S(-57, 208),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(39, 14),      S(108, 100),    S(-29, 189),    S(-118, 215),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-70, -30),    S(-1, 54),      S(-87, 130),    S(-178, 183),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-19, -51),    S(32, 4),       S(-66, 93),     S(-131, 140),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(32, -97),     S(41, -25),     S(-33, 31),     S(-110, 82),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-14, -188),   S(9, -87),      S(-89, -26),    S(-70, -57),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};

inline const PParam KS_NO_QUEEN = S(-92, -1010);

inline const std::array<PParam, 5> PT_INNER_RING_ATTACKS = {
    S(8, -26), S(15, -33), S(13, -2), S(6, -4), S(1, -23),
};
inline const std::array<PParam, 5> PT_OUTER_RING_ATTACKS = {
    S(3, -22), S(7, -38), S(4, -19), S(4, 0), S(4, 4),
};

inline const PParam KS_FLANK_ATTACK = S(4, -10);
inline const PParam KS_FLANK_DEFENSE = S(-4, 2);
inline const PParam KS_FLANK_DOUBLE_ATTACK   = S(3, -6);
inline const PParam KS_FLANK_DOUBLE_DEFENSE  = S(-2, -10);

inline const std::array<std::array<PParam, 7>, 4> KING_SHELTER = {{
  {{ S(13, 6), S(-9, 26), S(-7, -176), S(3, -43), S(7, -34), S(-10, -11), S(-28, -25), }},
  {{ S(0, 246), S(-20, -540), S(-17, -150), S(-8, 145), S(-7, 172), S(-18, 213), S(-41, 184), }},
  {{ S(-7, 178), S(-15, -433), S(-11, 165), S(-5, 138), S(-4, 129), S(-14, 151), S(-52, 148), }},
  {{ S(3, 217), S(-13, 159), S(-4, 166), S(3, 151), S(2, 146), S(6, 164), S(-4, 149), }},
}};
inline const std::array<PParam, 7> BLOCKED_SHELTER_STORM = {
    S(0, 0), S(0, 0), S(13, 207), S(-8, 138), S(-11, 156), S(-3, 177), S(11, 122),
};
inline const std::array<std::array<PParam, 7>, 4> SHELTER_STORM = {{
  {{ S(3, 323), S(-61, -746), S(-16, -567), S(7, -604), S(-5, 139), S(-9, 161), S(-9, 176), }},
  {{ S(7, 90), S(-33, -946), S(-5, -921), S(2, -869), S(-4, 38), S(-12, 78), S(-2, 77), }},
  {{ S(-2, 133), S(-11, -900), S(7, -336), S(2, -33), S(-5, 86), S(-11, 114), S(-6, 105), }},
  {{ S(-1, 131), S(-3, -595), S(3, 37), S(3, 85), S(-8, 89), S(-16, 105), S(-10, 113), }},
}};
inline TunableSigmoid<32> KING_SAFETY_ACTIVATION(
        1085, 277, -24, 122
);

inline VParam WINNABLE_PAWNS = V(-18);
inline VParam WINNABLE_SYM = V(104);
inline VParam WINNABLE_ASYM = V(89);
inline VParam WINNABLE_PAWN_ENDGAME = V(123);
inline VParam WINNABLE_BIAS = V(-410);

// Epoch duration: 7.41952s
// clang-format on
}  // namespace Clockwork
