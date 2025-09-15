#include <array>
#include <ranges>

#include "bitboard.hpp"
#include "common.hpp"
#include "eval_constants.hpp"
#include "position.hpp"
#include "psqt_state.hpp"

#include "evaluation.hpp"

#include "eval_types.hpp"
#include "square.hpp"

namespace Clockwork {

// clang-format off
const PScore PAWN_MAT   = S(265, 541);
const PScore KNIGHT_MAT = S(835, 996);
const PScore BISHOP_MAT = S(854, 1086);
const PScore ROOK_MAT   = S(1280, 1798);
const PScore QUEEN_MAT  = S(2783, 3289);
const PScore TEMPO_VAL  = S(27, 15);

const PScore BISHOP_PAIR_VAL  = S(52, 218);
const PScore DOUBLED_PAWN_VAL = S(-64, -120);

const std::array<PScore, 9> KNIGHT_MOBILITY = {
    S(-469, 82), S(-175, -220), S(-118, -56), S(-57, 6), S(-3, 11), S(19, 55), S(51, 68), S(97, 62), S(152, 17),
};
const std::array<PScore, 14> BISHOP_MOBILITY = {
    S(-150, -843), S(-205, -324), S(-111, -149), S(-56, -95), S(-15, -55), S(15, -24), S(39, -2), S(57, 4), S(61, 24), S(72, 21), S(77, 34), S(143, -12), S(236, -90), S(239, -114),
};
const std::array<PScore, 15> ROOK_MOBILITY = {
    S(-379, -242), S(-81, -214), S(-70, -110), S(-56, -33), S(-35, -8), S(-12, -6), S(-8, 18), S(19, 25), S(52, 6), S(81, 22), S(107, 28), S(123, 37), S(179, 20), S(134, 40), S(262, -67),
};
const std::array<PScore, 28> QUEEN_MOBILITY = {
    S(-133, 0), S(-387, -217), S(-141, -404), S(-346, -374), S(-278, -92), S(-153, -243), S(-102, -265), S(-109, -114), S(-93, -98), S(-89, -28), S(-67, -10), S(-64, 24), S(-49, 21), S(-42, 56), S(-28, 52), S(-13, 52), S(-22, 72), S(1, 57), S(21, 52), S(25, 27), S(39, -11), S(88, -61), S(68, -5), S(273, -206), S(324, -349), S(959, -631), S(687, -367), S(1399, -947),
};
const std::array<PScore, 9> KING_MOBILITY = {
    S(541, 782), S(-149, 536), S(-22, 596), S(-50, 493), S(-55, 508), S(-1, 408), S(-12, 450), S(-13, 422), S(67, 341),
};

const std::array<PScore, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(92, -43), S(128, -89),
};
const std::array<PScore, 3> BISHOP_KING_RING = {
    CS(0, 0), S(68, -12), S(151, -54),
};
const std::array<PScore, 5> ROOK_KING_RING = {
    CS(0, 0), S(88, -67), S(191, -104), S(232, -86), S(308, -126),
};
const std::array<PScore, 6> QUEEN_KING_RING = {
    CS(0, 0), S(7, 44), S(106, 21), S(279, -46), S(572, -130), S(802, -234),
};

const std::array<PScore, 48> PAWN_PSQT = {
    S(-162, 451),   S(-9, 428),     S(61, 462),     S(214, 227),    S(172, 225),    S(248, 300),    S(87, 340),     S(184, 315),    //
    S(-68, 127),    S(108, 183),    S(49, 90),      S(136, 10),     S(77, 3),       S(-7, 56),      S(-52, 93),     S(-109, 56),    //
    S(-77, -52),    S(-52, -47),    S(-59, -94),    S(-57, -138),   S(-64, -123),   S(-102, -132),  S(-132, -63),   S(-163, -43),   //
    S(-57, -163),   S(-7, -124),    S(-58, -166),   S(-79, -160),   S(-74, -188),   S(-110, -179),  S(-150, -100),  S(-185, -114),  //
    S(-17, -200),   S(92, -189),    S(-27, -143),   S(-73, -136),   S(-87, -150),   S(-135, -161),  S(-130, -125),  S(-189, -134),  //
    S(-43, -202),   S(160, -206),   S(56, -167),    S(-76, -107),   S(-112, -162),  S(-129, -155),  S(-141, -108),  S(-185, -128),  //
};
const std::array<PScore, 64> KNIGHT_PSQT = {
    S(-268, -89),   S(5, -106),     S(-509, 282),   S(47, 57),      S(-220, 146),   S(-275, 171),   S(-207, -43),   S(-343, 42),    //
    S(122, -69),    S(89, 89),      S(241, -26),    S(90, 63),      S(158, 70),     S(152, -42),    S(17, -13),     S(122, -88),    //
    S(58, 53),      S(82, 129),     S(226, 105),    S(141, 78),     S(135, 81),     S(66, 61),      S(28, 82),      S(-71, 43),     //
    S(130, 26),     S(16, 118),     S(108, 100),    S(54, 117),     S(134, 83),     S(50, 85),      S(-15, 46),     S(3, 55),       //
    S(60, 23),      S(132, 29),     S(52, 67),      S(37, 70),      S(17, 89),      S(11, 79),      S(-28, 63),     S(-11, -48),    //
    S(-40, -10),    S(8, -21),      S(-54, -2),     S(-14, 57),     S(-19, 52),     S(-106, 23),    S(-58, -13),    S(-80, -23),    //
    S(19, 42),      S(24, 14),      S(-39, -10),    S(-46, 7),      S(-36, -21),    S(-101, -11),   S(-60, -29),    S(-106, -103),  //
    S(-101, 24),    S(-22, -56),    S(-17, -81),    S(2, -45),      S(-34, -47),    S(-52, -123),   S(-88, -22),    S(-214, 34),    //
};
const std::array<PScore, 64> BISHOP_PSQT = {
    S(-128, 78),    S(-56, 14),     S(-568, 122),   S(-272, 92),    S(-325, 137),   S(-457, 124),   S(-56, 94),     S(18, 74),      //
    S(-30, -11),    S(-49, 92),     S(19, 31),      S(11, 7),       S(-21, 59),     S(-8, 48),      S(1, 23),       S(-100, 47),    //
    S(-21, 88),     S(34, 69),      S(218, 35),     S(69, 49),      S(32, 58),      S(0, 72),       S(89, 14),      S(5, 47),       //
    S(49, -17),     S(20, 49),      S(94, 16),      S(62, 63),      S(113, 33),     S(18, 53),      S(28, 34),      S(-87, 95),     //
    S(34, -36),     S(21, 15),      S(24, 20),      S(53, 51),      S(24, 83),      S(1, 38),       S(-21, 6),      S(-7, -51),     //
    S(72, -8),      S(51, -18),     S(77, -17),     S(5, 43),       S(-4, 54),      S(-34, 63),     S(31, -30),     S(34, -44),     //
    S(37, -27),     S(109, -47),    S(58, -40),     S(6, 3),        S(-9, -19),     S(29, -18),     S(-19, -3),     S(97, -111),    //
    S(58, 88),      S(-40, 40),     S(-33, 28),     S(1, -57),      S(-34, -47),    S(-3, -24),     S(15, -54),     S(-12, 33),     //
};
const std::array<PScore, 64> ROOK_PSQT = {
    S(117, 6),      S(308, -17),    S(12, 84),      S(37, 79),      S(94, 42),      S(2, 76),       S(69, 51),      S(66, 57),      //
    S(164, 25),     S(133, 64),     S(246, 32),     S(94, 117),     S(120, 98),     S(18, 128),     S(-7, 116),     S(32, 98),      //
    S(34, 72),      S(263, 2),      S(215, 26),     S(210, 22),     S(134, 32),     S(48, 99),      S(68, 63),      S(-34, 88),     //
    S(-21, 67),     S(18, 54),      S(42, 62),      S(125, -6),     S(68, 17),      S(-3, 111),     S(-9, 68),      S(-107, 85),    //
    S(-115, -21),   S(16, -39),     S(-75, 51),     S(-45, 23),     S(-75, 28),     S(-109, 82),    S(-139, 69),    S(-152, 51),    //
    S(-125, -49),   S(4, -111),     S(-86, -22),    S(-89, -17),    S(-70, -41),    S(-146, 31),    S(-154, 7),     S(-177, 9),     //
    S(-166, 5),     S(-74, -87),    S(-61, -68),    S(-71, -49),    S(-74, -45),    S(-111, -17),   S(-155, -34),   S(-186, -39),   //
    S(-142, -26),   S(-84, 0),      S(-60, -33),    S(-25, -42),    S(-51, -18),    S(-63, -28),    S(-84, -46),    S(-121, -37),   //
};
const std::array<PScore, 64> QUEEN_PSQT = {
    S(64, 0),       S(56, -10),     S(-1, 156),     S(-22, 129),    S(-36, 126),    S(-81, 197),    S(-10, 72),     S(-51, 15),     //
    S(100, 60),     S(-127, 287),   S(3, 259),      S(-186, 405),   S(-83, 265),    S(-152, 290),   S(-95, 142),    S(-25, 64),     //
    S(-59, 221),    S(82, 171),     S(81, 234),     S(42, 239),     S(-59, 291),    S(-50, 227),    S(-12, 102),    S(-9, 29),      //
    S(48, 73),      S(48, 140),     S(0, 172),      S(-29, 270),    S(-30, 234),    S(1, 95),       S(2, 50),       S(-29, 61),     //
    S(7, 77),       S(71, 30),      S(-22, 187),    S(-15, 165),    S(-60, 185),    S(-47, 117),    S(3, -52),      S(-34, -28),    //
    S(34, -125),    S(25, -33),     S(5, 44),       S(-49, 89),     S(-17, 11),     S(-27, -20),    S(-12, -66),    S(-35, -25),    //
    S(40, -255),    S(38, -307),    S(6, -148),     S(27, -101),    S(-21, -59),    S(15, -158),    S(-16, -100),   S(-53, -35),    //
    S(-116, -40),   S(-14, -446),   S(-30, -265),   S(0, -234),     S(33, -160),    S(41, -228),    S(-20, -121),   S(-80, -22),    //
};
const std::array<PScore, 64> KING_PSQT = {
    S(521, -630),   S(403, -139),   S(-506, 192),   S(-542, 187),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(214, -46),    S(-179, 188),   S(-160, 211),   S(-62, 181),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-163, 83),    S(-32, 154),    S(16, 135),     S(-50, 105),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-290, 74),    S(-166, 172),   S(6, 120),      S(-106, 103),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-219, -13),   S(-128, 94),    S(-46, 81),     S(-219, 143),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-126, -69),   S(8, 1),        S(-107, 60),    S(-197, 120),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(129, -138),   S(96, -39),     S(-21, 14),     S(-155, 75),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(145, -317),   S(134, -163),   S(-14, -117),   S(3, -158),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
};
// clang-format on

std::array<Bitboard, 64> king_ring_table = []() {
    std::array<Bitboard, 64> king_ring_table{};
    for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
        Bitboard sq_bb     = Bitboard::from_square(Square{sq_idx});
        Bitboard king_ring = sq_bb;
        king_ring |= sq_bb.shift(Direction::North);
        king_ring |= sq_bb.shift(Direction::South);
        king_ring |= sq_bb.shift(Direction::East);
        king_ring |= sq_bb.shift(Direction::West);
        king_ring |= sq_bb.shift(Direction::NorthEast);
        king_ring |= sq_bb.shift(Direction::SouthEast);
        king_ring |= sq_bb.shift(Direction::NorthWest);
        king_ring |= sq_bb.shift(Direction::SouthWest);
        king_ring_table[sq_idx] = king_ring;
    }
    return king_ring_table;
}();

Score evaluate_white_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us    = pos.active_color();
    i32         phase = pos.piece_count(Color::White, PieceType::Knight)
              + pos.piece_count(Color::Black, PieceType::Knight)
              + pos.piece_count(Color::White, PieceType::Bishop)
              + pos.piece_count(Color::Black, PieceType::Bishop)
              + 2
                  * (pos.piece_count(Color::White, PieceType::Rook)
                     + pos.piece_count(Color::Black, PieceType::Rook))
              + 4
                  * (pos.piece_count(Color::White, PieceType::Queen)
                     + pos.piece_count(Color::Black, PieceType::Queen));

    phase = std::min<i32>(phase, 24);

    PScore mobility    = PSCORE_ZERO;
    PScore king_attack = PSCORE_ZERO;

    const std::array<Bitboard, 2> pawns = {
      pos.board().bitboard_for(Color::White, PieceType::Pawn),
      pos.board().bitboard_for(Color::Black, PieceType::Pawn),
    };

    const std::array<Bitboard, 2> blocked_pawns = {
      pawns[0] & (pawns[1].shift(Direction::South)),
      pawns[1] & (pawns[0].shift(Direction::North)),
    };

    auto add_mobility = [&](Color c, PScore& mob_count, PScore& k_attack) {
        
        Bitboard bb = blocked_pawns[static_cast<usize>(c)] | pos.attacked_by(~c, PieceType::Pawn);
        Bitboard king_ring = king_ring_table[pos.king_sq(~c).raw];
        for (PieceId id : pos.get_piece_mask(c, PieceType::Knight)) {
            mobility += KNIGHT_MOBILITY[pos.mobility_of(c, id, ~bb)];
            k_attack += KNIGHT_KING_RING[pos.mobility_of(c, id, king_ring)];
        }
        for (PieceId id : pos.get_piece_mask(c, PieceType::Bishop)) {
            mobility += BISHOP_MOBILITY[pos.mobility_of(c, id, ~bb)];
            k_attack += BISHOP_KING_RING[pos.mobility_of(c, id, king_ring)];
        }
        for (PieceId id : pos.get_piece_mask(c, PieceType::Rook)) {
            mobility += ROOK_MOBILITY[pos.mobility_of(c, id, ~bb)];
            k_attack += ROOK_KING_RING[pos.mobility_of(c, id, king_ring)];
        }
        for (PieceId id : pos.get_piece_mask(c, PieceType::Queen)) {
            mobility += QUEEN_MOBILITY[pos.mobility_of(c, id, ~bb)];
            k_attack += QUEEN_KING_RING[pos.mobility_of(c, id, king_ring)];
        }
        mobility += KING_MOBILITY[pos.mobility_of(c, PieceId::king(), ~bb)];
    };

    add_mobility(Color::Black, mobility, king_attack);
    mobility *= -1;  // Persy trick
    king_attack *= -1;
    add_mobility(Color::White, mobility, king_attack);

    PScore doubled_pawns_bonus = DOUBLED_PAWN_VAL
                               * ((pawns[0] & pawns[0].shift(Direction::North)).popcount()
                                  - (pawns[1] & pawns[1].shift(Direction::South)).popcount());

    PScore bishop_pair_bonus = BISHOP_PAIR_VAL
                             * ((pos.piece_count(Color::White, PieceType::Bishop) >= 2)
                                - (pos.piece_count(Color::Black, PieceType::Bishop) >= 2));

    PScore tempo = (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;
    PScore sum =
      psqt_state.score() + mobility + king_attack + tempo + bishop_pair_bonus + doubled_pawns_bonus;
    return sum->phase<24>(phase);
};

Score evaluate_stm_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();
    return (us == Color::White) ? evaluate_white_pov(pos, psqt_state)
                                : -evaluate_white_pov(pos, psqt_state);
}

}  // namespace Clockwork
