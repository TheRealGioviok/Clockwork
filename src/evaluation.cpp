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
const PScore PAWN_MAT   = S(287, 530);
const PScore KNIGHT_MAT = S(842, 1008);
const PScore BISHOP_MAT = S(858, 1108);
const PScore ROOK_MAT   = S(1276, 1809);
const PScore QUEEN_MAT  = S(2781, 3307);
const PScore TEMPO_VAL  = S(28, 15);

const PScore BISHOP_PAIR_VAL  = S(53, 217);
const PScore DOUBLED_PAWN_VAL = S(-72, -117);

const std::array<PScore, 9> KNIGHT_MOBILITY = {
    S(-219, -261), S(-138, -129), S(-84, -37), S(-45, 0), S(0, 19), S(23, 65), S(51, 68), S(85, 60), S(133, -18),
};
const std::array<PScore, 14> BISHOP_MOBILITY = {
    S(-188, -288), S(-133, -186), S(-71, -141), S(-49, -81), S(-9, -43), S(7, -16), S(34, -15), S(44, -2), S(51, 15), S(47, 13), S(76, 2), S(177, -76), S(207, -116), S(372, -218),
};
const std::array<PScore, 15> ROOK_MOBILITY = {
    S(-270, -363), S(-109, -104), S(-67, -46), S(-53, -31), S(-35, -9), S(-22, -2), S(-3, 16), S(27, 10), S(59, 11), S(81, 32), S(108, 24), S(120, 35), S(177, 20), S(137, 36), S(237, -64),
};
const std::array<PScore, 28> QUEEN_MOBILITY = {
    S(-110, 12), S(-273, -78), S(-201, -483), S(-176, -263), S(-130, -326), S(-113, -244), S(-143, -43), S(-113, -70), S(-95, -44), S(-80, -27), S(-86, 25), S(-76, 52), S(-45, 39), S(-43, 52), S(-23, 48), S(-28, 68), S(-32, 99), S(-14, 68), S(-4, 54), S(45, -10), S(80, -47), S(145, -120), S(129, -101), S(450, -417), S(402, -400), S(1021, -703), S(619, -426), S(1450, -1048),
};
const std::array<PScore, 9> KING_MOBILITY = {
    S(408, 752), S(149, 438), S(32, 480), S(22, 506), S(-7, 491), S(-36, 467), S(-45, 480), S(-38, 450), S(59, 315),
};

const std::array<PScore, 3> KNIGHT_KING_RING = {
    CS(0, 0), S(90, -45), S(125, -93),
};
const std::array<PScore, 3> BISHOP_KING_RING = {
    CS(0, 0), S(65, -10), S(150, -57),
};
const std::array<PScore, 5> ROOK_KING_RING = {
    CS(0, 0), S(77, -56), S(175, -93), S(229, -92), S(320, -145),
};
const std::array<PScore, 6> QUEEN_KING_RING = {
    CS(0, 0), S(3, 49), S(94, 30), S(266, -36), S(548, -116), S(802, -243),
};

const std::array<PScore, 48> PAWN_PSQT = {
    S(-189, 471),   S(9, 439),      S(86, 464),     S(244, 222),    S(186, 233),    S(245, 324),    S(86, 365),     S(174, 337),    //
    S(-30, 107),    S(122, 173),    S(89, 56),      S(183, -12),    S(106, -2),     S(8, 55),       S(-49, 102),    S(-96, 57),     //
    S(-70, -57),    S(-39, -48),    S(-41, -101),   S(-38, -141),   S(-50, -120),   S(-97, -124),   S(-130, -52),   S(-165, -32),   //
    S(-54, -166),   S(1, -129),     S(-44, -171),   S(-64, -160),   S(-62, -185),   S(-109, -167),  S(-152, -87),   S(-188, -103),  //
    S(-16, -205),   S(88, -197),    S(-9, -162),    S(-62, -141),   S(-82, -148),   S(-132, -152),  S(-137, -112),  S(-186, -125),  //
    S(-65, -202),   S(137, -213),   S(36, -172),    S(-78, -105),   S(-96, -154),   S(-136, -143),  S(-144, -97),   S(-188, -120),  //
};
const std::array<PScore, 64> KNIGHT_PSQT = {
    S(-325, -164),  S(12, -127),    S(-541, 282),   S(5, 67),       S(-245, 146),   S(-294, 171),   S(-244, -43),   S(-410, 0),     //
    S(63, -62),     S(55, 87),      S(224, -40),    S(70, 54),      S(159, 51),     S(135, -52),    S(-1, -22),     S(70, -83),     //
    S(22, 57),      S(63, 129),     S(234, 100),    S(147, 80),     S(132, 86),     S(63, 68),      S(12, 77),      S(-94, 46),     //
    S(115, 27),     S(11, 116),     S(118, 99),     S(46, 121),     S(127, 87),     S(52, 86),      S(-20, 40),     S(-12, 56),     //
    S(52, 33),      S(153, 26),     S(64, 64),      S(57, 68),      S(22, 90),      S(21, 75),      S(-21, 61),     S(-18, -41),    //
    S(-41, -3),     S(-4, -26),     S(-31, -15),    S(5, 52),       S(10, 42),      S(-86, 13),     S(-68, -18),    S(-99, -20),    //
    S(0, 28),       S(12, 19),      S(-44, -1),     S(-44, 12),     S(-48, -12),    S(-105, -6),    S(-82, -33),    S(-139, -107),  //
    S(-123, 14),    S(-24, -55),    S(7, -77),      S(24, -36),     S(11, -47),     S(-37, -135),   S(-86, -18),    S(-220, -11),   //
};
const std::array<PScore, 64> BISHOP_PSQT = {
    S(-140, 67),    S(-81, 16),     S(-616, 155),   S(-304, 110),   S(-370, 162),   S(-482, 143),   S(-62, 98),     S(20, 55),      //
    S(-53, -19),    S(-55, 93),     S(13, 36),      S(11, 7),       S(-7, 51),      S(-6, 43),      S(1, 23),       S(-117, 41),    //
    S(-30, 83),     S(26, 73),      S(215, 42),     S(80, 49),      S(42, 60),      S(-9, 86),      S(93, 13),      S(-10, 47),     //
    S(39, -26),     S(17, 48),      S(97, 21),      S(72, 66),      S(122, 34),     S(27, 56),      S(21, 36),      S(-99, 91),     //
    S(39, -52),     S(23, 15),      S(35, 21),      S(58, 59),      S(35, 88),      S(8, 40),       S(-17, 7),      S(-16, -55),    //
    S(64, -28),     S(86, -19),     S(87, -18),     S(16, 46),      S(-1, 58),      S(-27, 66),     S(50, -26),     S(18, -53),     //
    S(-6, -51),     S(109, -51),    S(59, -39),     S(4, 3),        S(-10, -16),    S(25, -21),     S(-17, -8),     S(55, -144),    //
    S(3, 52),       S(-14, 21),     S(-16, 33),     S(12, -56),     S(-30, -49),    S(10, -9),      S(7, -63),      S(-41, 7),      //
};
const std::array<PScore, 64> ROOK_PSQT = {
    S(115, 11),     S(305, -11),    S(6, 92),       S(28, 88),      S(91, 47),      S(-1, 81),      S(64, 57),      S(64, 62),      //
    S(160, 31),     S(119, 76),     S(243, 31),     S(97, 116),     S(118, 101),    S(13, 130),     S(-17, 121),    S(19, 108),     //
    S(38, 67),      S(262, 6),      S(210, 26),     S(205, 21),     S(128, 34),     S(40, 100),     S(65, 63),      S(-36, 87),     //
    S(-15, 64),     S(23, 56),      S(43, 63),      S(116, -2),     S(62, 19),      S(-9, 114),     S(-12, 73),     S(-109, 91),    //
    S(-103, -23),   S(30, -36),     S(-64, 54),     S(-40, 26),     S(-70, 31),     S(-100, 84),    S(-134, 75),    S(-145, 54),    //
    S(-112, -47),   S(28, -113),    S(-63, -21),    S(-77, -9),     S(-58, -37),    S(-133, 38),    S(-143, 14),    S(-164, 13),    //
    S(-141, -1),    S(-43, -97),    S(-33, -69),    S(-49, -43),    S(-54, -41),    S(-93, -13),    S(-145, -30),   S(-163, -40),   //
    S(-124, -28),   S(-80, -3),     S(-53, -33),    S(-28, -44),    S(-55, -19),    S(-64, -28),    S(-83, -44),    S(-112, -36),   //
};
const std::array<PScore, 64> QUEEN_PSQT = {
    S(47, 3),       S(46, -8),      S(-6, 154),     S(-36, 134),    S(-50, 134),    S(-102, 209),   S(-22, 74),     S(-62, 9),      //
    S(77, 72),      S(-146, 297),   S(-6, 261),     S(-196, 413),   S(-91, 270),    S(-172, 299),   S(-109, 145),   S(-42, 67),     //
    S(-64, 216),    S(68, 177),     S(74, 235),     S(34, 243),     S(-62, 288),    S(-65, 230),    S(-19, 103),    S(-24, 30),     //
    S(41, 79),      S(41, 144),     S(4, 163),      S(-31, 270),    S(-41, 241),    S(-6, 98),      S(-4, 47),      S(-37, 59),     //
    S(13, 80),      S(71, 37),      S(-16, 189),    S(-17, 166),    S(-60, 183),    S(-46, 112),    S(2, -57),      S(-35, -29),    //
    S(50, -132),    S(45, -31),     S(20, 42),      S(-46, 92),     S(-14, 6),      S(-19, -25),    S(-1, -71),     S(-27, -34),    //
    S(39, -249),    S(56, -318),    S(15, -148),    S(33, -98),     S(-19, -49),    S(21, -163),    S(-13, -102),   S(-62, -24),    //
    S(-137, -38),   S(-6, -451),    S(-32, -266),   S(-7, -227),    S(23, -156),    S(37, -230),    S(-23, -126),   S(-90, -21),    //
};
const std::array<PScore, 64> KING_PSQT = {
    S(601, -706),   S(420, -205),   S(-634, 221),   S(-604, 192),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(198, -86),    S(-259, 240),   S(-233, 264),   S(-77, 215),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-180, 76),    S(2, 150),      S(25, 140),     S(96, 70),      S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-386, 102),   S(-224, 196),   S(-1, 122),     S(-51, 96),     S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-299, 12),    S(-168, 105),   S(-69, 87),     S(-287, 171),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(-179, -54),   S(44, -26),     S(-85, 47),     S(-194, 126),   S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(109, -149),   S(167, -82),    S(37, -10),     S(-101, 65),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
    S(40, -255),    S(132, -189),   S(-10, -137),   S(18, -170),    S(0, 0),        S(0, 0),        S(0, 0),        S(0, 0),        //
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

    phase = std::clamp<i32>(phase, 4, 24);

    PScore mobility    = PSCORE_ZERO;
    PScore king_attack = PSCORE_ZERO;

    auto add_mobility = [&](Color c, PScore& mob_count, PScore& k_attack) {
        Bitboard bb = pos.bitboard_for(c, PieceType::Pawn) | pos.attacked_by(~c, PieceType::Pawn);
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

    const std::array<Bitboard, 2> pawns = {pos.board().bitboard_for(Color::White, PieceType::Pawn),
                                           pos.board().bitboard_for(Color::Black, PieceType::Pawn)};

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
