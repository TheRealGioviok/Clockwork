#include "evaluation.hpp"
#include "bitboard.hpp"
#include "common.hpp"
#include "dbg_tools.hpp"
#include "eval_constants.hpp"
#include "eval_types.hpp"
#include "kogge_stone.hpp"
#include "position.hpp"
#include "psqt_state.hpp"
#include "square.hpp"
#include <array>
#include <ranges>

namespace Clockwork {


struct EvalData {

    Bitboard any_attacks_by[2];
    Bitboard any2_attacks_by[2];
    Bitboard attacks_by_pt[2][7];

    // Mobility area
    Bitboard mobility_area[2];
    Bitboard rook_area[2];
    Bitboard queen_area[2];

    i32 m_piece_count[2][6];
    i32 wcount = 0;
    i32 bcount = 0;

    u64      reach_raw[2][16];
    Bitboard reach_all[2] = {};
    Bitboard reach_2[2]   = {};

    // Trapped piece candidates: restricted mobility of at most 3 squares.
    PieceMask trap_candidates[2];

    Bitboard area_for(Color color, PieceType pt) const {
        const usize c = static_cast<usize>(color);
        return pt == PieceType::Queen ? queen_area[c]
             : pt == PieceType::Rook  ? rook_area[c]
                                      : mobility_area[c];
    }

    void init(const Position& pos) {
        any_attacks_by[0]  = pos.attack_table(Color::White).get_attacked_bitboard();
        any_attacks_by[1]  = pos.attack_table(Color::Black).get_attacked_bitboard();
        any2_attacks_by[0] = pos.attacked_by_two_or_more(Color::White);
        any2_attacks_by[1] = pos.attacked_by_two_or_more(Color::Black);

        for (PieceType pt : {PieceType::Pawn, PieceType::Knight, PieceType::Bishop, PieceType::Rook,
                             PieceType::Queen}) {
            m_piece_count[static_cast<usize>(Color::White)][static_cast<usize>(pt)] =
              pos.i32piece_count(Color::White, pt);
            m_piece_count[static_cast<usize>(Color::Black)][static_cast<usize>(pt)] =
              pos.i32piece_count(Color::Black, pt);

            attacks_by_pt[static_cast<usize>(Color::White)][static_cast<usize>(pt)] =
              pos.attacked_by(Color::White, pt);
            attacks_by_pt[static_cast<usize>(Color::Black)][static_cast<usize>(pt)] =
              pos.attacked_by(Color::Black, pt);

            wcount += m_piece_count[static_cast<usize>(Color::White)][static_cast<usize>(pt)];
            bcount += m_piece_count[static_cast<usize>(Color::Black)][static_cast<usize>(pt)];
        }

        attacks_by_pt[static_cast<usize>(Color::White)][static_cast<usize>(PieceType::King)] =
          pos.attacked_by(Color::White, PieceType::King);
        attacks_by_pt[static_cast<usize>(Color::Black)][static_cast<usize>(PieceType::King)] =
          pos.attacked_by(Color::Black, PieceType::King);
    }

    inline i32 piece_count(const Color color, const PieceType pt) const {
        return m_piece_count[static_cast<usize>(color)][static_cast<usize>(pt)];
    }

    inline i32 piece_count(const Color color) const {
        return color == Color::White ? wcount : bcount;
    }

    inline Bitboard attacked_by(const Color color, const PieceType pt) const {
        return attacks_by_pt[static_cast<usize>(color)][static_cast<usize>(pt)];
    }

    inline Bitboard attacked_by(const Color color) const {
        return any_attacks_by[static_cast<usize>(color)];
    }

    inline Bitboard attacked_by_2(const Color color) const {
        return any2_attacks_by[static_cast<usize>(color)];
    }

    Bitboard reach(Color color, PieceId id) const {
        return Bitboard{reach_raw[static_cast<usize>(color)][id.raw]};
    }

    inline void add_reach(Color color, PieceId id, Bitboard r) {
        const usize c        = static_cast<usize>(color);
        reach_raw[c][id.raw] = r.value();
        reach_2[c] |= reach_all[c] & r;
        reach_all[c] |= r;
    }
};

static i32 chebyshev_distance(Square a, Square b) {
    i32 file_dist = std::abs(a.file() - b.file());
    i32 rank_dist = std::abs(a.rank() - b.rank());
    return std::max(file_dist, rank_dist);
}

template<Color color>
Bitboard pawn_spans(const Bitboard pawns) {
    Bitboard res = pawns;
    // rank 1 -> 2
    res |= res.shift_relative(color, Direction::North);
    // rank 2 -> 4
    res |= res.shift_relative(color, Direction::North, 2);
    // rank 4 -> 7
    res |= res.shift_relative(color, Direction::North, 4);

    return res;
}

template<Color color>
Bitboard static_pawn_attacks(const Bitboard pawns) {
    Bitboard attacks = pawns.shift_relative(color, Direction::NorthEast)
                     | pawns.shift_relative(color, Direction::NorthWest);
    return attacks;
}

template<Color color>
Bitboard pawn_spans(const Bitboard pawns, Bitboard blockers) {
    Bitboard res = pawns;
    // rank 1 -> 2
    res |= res.shift_relative(color, Direction::North) & ~blockers;
    blockers |= blockers.shift_relative(color, Direction::North);
    // rank 2 -> 4
    res |= res.shift_relative(color, Direction::North, 2) & ~blockers;
    blockers |= blockers.shift_relative(color, Direction::North, 2);
    // rank 4 -> 7
    res |= res.shift_relative(color, Direction::North, 4) & ~blockers;

    return res;
}

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

std::array<Bitboard, 64> extended_ring_table = []() {
    std::array<Bitboard, 64> extended_ring_table{};
    for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
        Bitboard sq_bb         = king_ring_table[sq_idx];
        Bitboard extended_ring = sq_bb;
        extended_ring |= sq_bb.shift(Direction::North);
        extended_ring |= sq_bb.shift(Direction::South);
        extended_ring |= sq_bb.shift(Direction::East);
        extended_ring |= sq_bb.shift(Direction::West);
        extended_ring |= sq_bb.shift(Direction::NorthEast);
        extended_ring |= sq_bb.shift(Direction::SouthEast);
        extended_ring |= sq_bb.shift(Direction::NorthWest);
        extended_ring |= sq_bb.shift(Direction::SouthWest);
        extended_ring_table[sq_idx] = extended_ring;
    }
    return extended_ring_table;
}();


std::array<Bitboard, 64> orthogonal_squares_table = []() {
    std::array<Bitboard, 64> orthogonal_squares_table{};
    for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
        Square sq = Square{sq_idx};
        orthogonal_squares_table[sq_idx] =
          Bitboard::file_mask(sq.file()) | Bitboard::rank_mask(sq.rank());
    }
    return orthogonal_squares_table;
}();

std::array<Bitboard, 64> diagonal_squares_table = []() {
    std::array<Bitboard, 64> diagonal_squares_table{};
    for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
        Square sq = Square{sq_idx};

        for (Direction dir : {Direction::NorthEast, Direction::NorthWest, Direction::SouthEast,
                              Direction::SouthWest}) {
            Bitboard sqb = Bitboard::from_square(sq);
            sqb |= sqb.shift(dir);
            sqb |= sqb.shift(dir).shift(dir);
            sqb |= sqb.shift(dir).shift(dir).shift(dir).shift(dir);
            diagonal_squares_table[sq_idx] |= sqb ^ Bitboard::from_square(sq);
        }
    }
    return diagonal_squares_table;
}();

std::array<Bitboard, 64> knight_squares_table = []() {
    std::array<Bitboard, 64> knight_squares_table{};
    for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
        Square   sq                  = Square{sq_idx};
        Bitboard sqb                 = Bitboard::from_square(sq);
        knight_squares_table[sq_idx] = sqb.shift(Direction::North).shift(Direction::NorthEast)
                                     | sqb.shift(Direction::North).shift(Direction::NorthWest)
                                     | sqb.shift(Direction::South).shift(Direction::SouthEast)
                                     | sqb.shift(Direction::South).shift(Direction::SouthWest)
                                     | sqb.shift(Direction::West).shift(Direction::NorthWest)
                                     | sqb.shift(Direction::West).shift(Direction::SouthWest)
                                     | sqb.shift(Direction::East).shift(Direction::NorthEast)
                                     | sqb.shift(Direction::East).shift(Direction::SouthEast);
    }
    return knight_squares_table;
}();

std::array<std::array<Bitboard, 64>, 2> passed_pawn_spans = []() {
    std::array<std::array<Bitboard, 64>, 2> passed_pawn_masks{};
    for (Color color : {Color::White, Color::Black}) {
        for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
            Bitboard sq_bb = Bitboard::from_square(Square{sq_idx});
            Bitboard mask  = sq_bb.shift_relative(color, Direction::North);
            mask |= mask.shift(Direction::East) | mask.shift(Direction::West);
            for (u8 i = 0; i < 8; i++) {
                mask |= mask.shift_relative(color, Direction::North);
            }
            passed_pawn_masks[static_cast<usize>(color)][sq_idx] = mask;
        }
    }
    return passed_pawn_masks;
}();

template<Color color>
PScore king_shelter(const Position& pos, const EvalData& eval_data) {
    constexpr Color opp = ~color;

    Square king_square = pos.king_sq(color);

    Bitboard b = ~Bitboard::forward_ranks(opp, king_square);  // Squares ahead or on king's rank
    Bitboard our_pawns =
      pos.bitboard_for(color, PieceType::Pawn) & b & ~eval_data.attacked_by(opp, PieceType::Pawn);
    Bitboard their_pawns = pos.bitboard_for(opp, PieceType::Pawn) & b;

    PScore score = PSCORE_ZERO;

    i32 shelter_center = std::clamp(king_square.file(), 1, 6);

    for (i32 offset = -1; offset <= 1; offset++) {
        i32      file    = shelter_center + offset;
        Bitboard file_bb = Bitboard::file_mask(file);

        // Our pawns
        b            = our_pawns & file_bb;
        i32 our_rank = b.any() ? b.frontmost_square(opp).relative_rank(color) : 0;

        // Opponent pawns
        b              = their_pawns & file_bb;
        i32 their_rank = b.any() ? b.frontmost_square(opp).relative_rank(color) : 0;

        i32 edge_idx = std::min(file, 7 - file);

        score += KING_SHELTER[static_cast<usize>(edge_idx)][static_cast<usize>(our_rank)];
        if (our_rank && (our_rank == their_rank - 1)) {
            score += BLOCKED_SHELTER_STORM[static_cast<usize>(their_rank)];
        } else {
            score += SHELTER_STORM[static_cast<usize>(edge_idx)][static_cast<usize>(their_rank)];
        }
    }

    return score;
}

template<Color color>
std::tuple<PScore, i32> evaluate_pawns(const Position& pos, const EvalData& data) {
    constexpr i32   RANK_2 = 1;
    constexpr i32   RANK_3 = 2;
    constexpr Color them   = color == Color::White ? Color::Black : Color::White;

    Square our_king   = pos.king_sq(color);
    Square their_king = pos.king_sq(them);
    PScore eval       = PSCORE_ZERO;

    i32 passers = 0;

    Bitboard pawns     = pos.board().bitboard_for(color, PieceType::Pawn);
    Bitboard opp_pawns = pos.board().bitboard_for(~color, PieceType::Pawn);

    Bitboard pawn_files = Bitboard::fill_verticals(pawns);
    Bitboard doubled    = pawns & pawns.shift(Direction::North);
    Bitboard isolated =
      pawns & ~(pawn_files.shift(Direction::East) | pawn_files.shift(Direction::West));
    eval += DOUBLED_PAWN_VAL * doubled.ipopcount();
    eval += ISOLATED_PAWN_VAL * isolated.ipopcount();

    for (Square sq : pawns) {
        Square   push     = sq.push<color>();
        Bitboard stoppers = opp_pawns & passed_pawn_spans[static_cast<usize>(color)][sq.raw];
        if (stoppers.empty()) {
            ++passers;

            eval += PASSED_PAWN[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];

            if ((passed_pawn_spans[static_cast<usize>(color)][sq.raw] & data.attacked_by(them))
                  .empty()) {
                eval +=
                  PASSED_CLEAR_STOPPERS[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
            } else if ((Bitboard::forward_ranks(color, sq) & Bitboard::file_mask(sq.file())
                        & data.attacked_by(them))
                         .empty()) {
                eval +=
                  PASSED_CLEAR_FORWARD[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
            } else if (pos.attack_table(color).read(push).popcount()
                       > pos.attack_table(them).read(push).popcount()) {
                eval +=
                  DEFENDED_PASSED_PUSH[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
            }

            if (pos.piece_at(push) != PieceType::None) {
                eval +=
                  BLOCKED_PASSED_PAWN[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
            }

            i32 our_king_dist   = chebyshev_distance(our_king, sq);
            i32 their_king_dist = chebyshev_distance(their_king, sq);

            eval += FRIENDLY_KING_PASSED_PAWN_DISTANCE[static_cast<usize>(our_king_dist)];
            eval += ENEMY_KING_PASSED_PAWN_DISTANCE[static_cast<usize>(their_king_dist)];
        }
    }


    Bitboard phalanx = pawns & pawns.shift(Direction::East);
    for (Square sq : phalanx) {
        eval += PAWN_PHALANX[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
    }

    Bitboard defended = pawns & data.attacked_by(color, PieceType::Pawn);
    for (Square sq : defended) {
        eval += DEFENDED_PAWN[static_cast<usize>(sq.relative_sq(color).rank() - RANK_3)];
    }

    return {eval, passers};
}

template<Color color>
PScore evaluate_pawn_push_threats(const Position& pos) {
    constexpr Color opp  = ~color;
    PScore          eval = PSCORE_ZERO;

    Bitboard our_pawns  = pos.bitboard_for(color, PieceType::Pawn);
    Bitboard all_pieces = pos.board().get_occupied_bitboard();

    Bitboard pushable = our_pawns & ~all_pieces.shift_relative(color, Direction::South);

    Bitboard push_attacks =
      pushable.shift_relative(color, Direction::North).shift_relative(color, Direction::NorthEast)
      | pushable.shift_relative(color, Direction::North)
          .shift_relative(color, Direction::NorthWest);

    eval += PAWN_PUSH_THREAT_KNIGHT
          * (push_attacks & pos.bitboard_for(opp, PieceType::Knight)).ipopcount();
    eval += PAWN_PUSH_THREAT_BISHOP
          * (push_attacks & pos.bitboard_for(opp, PieceType::Bishop)).ipopcount();
    eval +=
      PAWN_PUSH_THREAT_ROOK * (push_attacks & pos.bitboard_for(opp, PieceType::Rook)).ipopcount();
    eval +=
      PAWN_PUSH_THREAT_QUEEN * (push_attacks & pos.bitboard_for(opp, PieceType::Queen)).ipopcount();

    return eval;
}

template<typename Table>
static inline PScore reach_score(const Table& table, Bitboard novel) {
    return table[std::min(novel.popcount(), table.size() - 1)];
}

template<Color color>
PScore evaluate_pieces(const Position& pos, EvalData& data) {
    constexpr Color opp       = ~color;
    PScore          eval      = PSCORE_ZERO;
    Bitboard        own_pawns = pos.bitboard_for(color, PieceType::Pawn);
    Bitboard        blocked_pawns =
      own_pawns & pos.board().get_occupied_bitboard().shift_relative(color, Direction::South);
    constexpr Bitboard early_ranks     = color == Color::White
                                         ? Bitboard::rank_mask(1) | Bitboard::rank_mask(2)
                                         : Bitboard::rank_mask(5) | Bitboard::rank_mask(6);
    Bitboard           own_early_pawns = own_pawns & early_ranks;
    Bitboard bb = (blocked_pawns | own_early_pawns) | data.attacked_by(opp, PieceType::Pawn);
    data.mobility_area[static_cast<usize>(color)] = ~bb;
    Bitboard bb2                                  = bb;

    const Bitboard empty       = pos.board().get_empty_bitboard();
    const Bitboard all_pieces  = ~empty;
    const Bitboard own         = pos.board().get_color_bitboard(color);
    const Bitboard opp_attacks = data.attacked_by(opp);
    // Trap candidates
    const Bitboard own_nonpawn    = own & ~own_pawns;
    const auto     trap_candidate = [&](PieceId id, Bitboard m, Bitboard moves) {
        if (m.popcount() > 3 || (moves & ~own).empty()) {
            return false;
        }
        if (m.any() && (moves & own_nonpawn).any()) {
            return false;
        }
        return (opp_attacks & Bitboard::from_square(pos.piece_list_sq(color)[id.raw])).empty();
    };

    // Squares contested 1 to 1 by both sides (no pawns) and that we can attack with reach.
    const Bitboard contested = data.attacked_by(color) & ~data.attacked_by_2(color)
                             & ~data.attacked_by(color, PieceType::Pawn) & data.attacked_by(opp)
                             & ~data.attacked_by_2(opp);

    for (PieceId id : pos.get_piece_mask(color, PieceType::Knight)) {
        Bitboard moves    = pos.moves_of(color, id);
        Bitboard mobility = moves & ~bb;
        Bitboard reach    = knights_setwise(mobility & empty) & ~own;
        data.add_reach(color, id, reach);

        eval += KNIGHT_MOBILITY[mobility.popcount()];
        data.trap_candidates[static_cast<usize>(color)].set(id,
                                                            trap_candidate(id, mobility, moves));
        eval += reach_score(KNIGHT_REACH, reach & ~bb & ~moves);
        eval += REACH_CONTEST[0] * (reach & ~moves & contested).ipopcount();
    }

    for (PieceId id : pos.get_piece_mask(color, PieceType::Bishop)) {
        Bitboard moves    = pos.moves_of(color, id);
        Bitboard mobility = moves & ~bb;
        Bitboard reach    = bishops_setwise(mobility & empty, all_pieces) & ~own;
        data.add_reach(color, id, reach);

        eval += BISHOP_MOBILITY[mobility.popcount()];
        data.trap_candidates[static_cast<usize>(color)].set(id,
                                                            trap_candidate(id, mobility, moves));
        eval += reach_score(BISHOP_REACH, reach & ~bb & ~moves);
        eval += REACH_CONTEST[1] * (reach & ~moves & contested).ipopcount();

        Square sq = pos.piece_list_sq(color)[id.raw];
        eval +=
          BISHOP_PAWNS[std::min(static_cast<usize>(8),
                                (own_pawns & Bitboard::squares_of_color(sq.color())).popcount())]
          * (!pos.is_square_attacked_by(sq, color, PieceType::Pawn)
             + (blocked_pawns & Bitboard::central_files()).ipopcount());

        Bitboard xray = diagonal_squares_table[sq.raw];
        eval += BISHOP_XRAY_PAWNS * (xray & pos.bitboard_for(opp, PieceType::Pawn)).ipopcount();
    }

    bb2 |= data.attacked_by(opp, PieceType::Knight) | data.attacked_by(opp, PieceType::Bishop);
    data.rook_area[static_cast<usize>(color)] = ~bb2;
    for (PieceId id : pos.get_piece_mask(color, PieceType::Rook)) {
        Bitboard moves      = pos.moves_of(color, id);
        Bitboard mobility_a = moves & ~bb;
        Bitboard mobility_b = moves & ~bb2;
        Bitboard reach      = rooks_setwise(mobility_b & empty, all_pieces) & ~own;
        data.add_reach(color, id, reach);

        eval += ROOK_MOBILITY[mobility_a.popcount()];
        eval += ROOK_MOBILITY[mobility_b.popcount()];
        data.trap_candidates[static_cast<usize>(color)].set(id,
                                                            trap_candidate(id, mobility_b, moves));
        eval += reach_score(ROOK_REACH, reach & ~bb2 & ~moves);
        eval += REACH_CONTEST[2] * (reach & ~moves & contested).ipopcount();

        Bitboard rook_file = Bitboard::file_mask(pos.piece_list_sq(color)[id].file());
        eval += ROOK_LINEUP
              * (rook_file
                 & (pos.bitboard_for(opp, PieceType::Queen)
                    | pos.bitboard_for(color, PieceType::Queen)))
                  .ipopcount();
    }

    bb2 |= data.attacked_by(opp, PieceType::Rook);
    data.queen_area[static_cast<usize>(color)] = ~bb2;
    for (PieceId id : pos.get_piece_mask(color, PieceType::Queen)) {
        Bitboard moves      = pos.moves_of(color, id);
        Bitboard mobility_a = moves & ~bb;
        Bitboard mobility_b = moves & ~bb2;
        Bitboard reach      = queens_setwise(mobility_b & empty, all_pieces) & ~own;
        data.add_reach(color, id, reach);

        eval += QUEEN_MOBILITY[mobility_a.popcount()];
        eval += QUEEN_MOBILITY[mobility_b.popcount()];
        data.trap_candidates[static_cast<usize>(color)].set(id,
                                                            trap_candidate(id, mobility_b, moves));
        eval += reach_score(QUEEN_REACH, reach & ~bb2 & ~moves);
        eval += REACH_CONTEST[3] * (reach & ~moves & contested).ipopcount();
    }

    if (pos.piece_count(color, PieceType::Bishop) >= 2) {
        eval += BISHOP_PAIR_VAL;
    }

    return eval;
}

template<Color color>
PScore evaluate_outposts(const Position& pos, const EvalData& data) {
    // First calculate all the viable outpost squares
    // A viable outpost square is one that is not attackable by enemy pawns and is:
    // - on ranks 4,5,6 for white (5,4,3 for black)
    // - not attackable by enemy pawns (now or never)
    // - additional conditions will be added as we go
    constexpr Color    opp = ~color;
    constexpr Bitboard viable_outposts_ranks =
      color == Color::White
        ? Bitboard::rank_mask(3) | Bitboard::rank_mask(4) | Bitboard::rank_mask(5)
        : Bitboard::rank_mask(2) | Bitboard::rank_mask(3) | Bitboard::rank_mask(4);
    // Get enemy pawns to calculate the attacks and attack spans
    Bitboard opp_pawns             = pos.bitboard_for(opp, PieceType::Pawn);
    Bitboard opp_pawn_span         = pawn_spans<opp>(opp_pawns);
    Bitboard opp_pawn_span_attacks = static_pawn_attacks<opp>(
      opp_pawn_span);  // Note, this does NOT consider pins! Might need to test this more thoroughly.
    Bitboard pawn_defended_squares = data.attacked_by(color, PieceType::Pawn);
    Bitboard viable_outposts =
      viable_outposts_ranks & pawn_defended_squares & ~opp_pawn_span_attacks;
    // Check for minor pieces on outposts
    PScore eval = PSCORE_ZERO;
    eval += OUTPOST_KNIGHT_VAL
          * (pos.bitboard_for(color, PieceType::Knight) & viable_outposts).ipopcount();
    eval += OUTPOST_BISHOP_VAL
          * (pos.bitboard_for(color, PieceType::Bishop) & viable_outposts).ipopcount();
    return eval;
}


template<Color color>
PScore evaluate_potential_checkers(const Position& pos) {
    constexpr Color opp = ~color;

    const PieceMask orth   = pos.get_piece_mask<PieceType::Rook, PieceType::Queen>(opp);
    const PieceMask diag   = pos.get_piece_mask<PieceType::Bishop, PieceType::Queen>(opp);
    const PieceMask knight = pos.get_piece_mask<PieceType::Knight>(opp);

    CreateSuperpieceMaskInfo cmi;
    cmi.knight     = knight.value();
    cmi.orth       = orth.value();
    cmi.orth_near  = orth.value();
    cmi.wpawn_near = diag.value();
    cmi.bpawn_near = diag.value();
    cmi.diag       = diag.value();

    Wordboard mask = pos.create_attack_table_superpiece_mask(pos.king_sq(color), cmi);
    mask           = mask & pos.attack_table(opp);
    return POTENTIAL_CHECKER_VAL * mask.popcount();
}

template<Color color>
PScore evaluate_king_safety(const Position& pos, const EvalData& data) {
    constexpr Color opp = ~color;

    // Iterate over the opponent's attack bbs
    PScore eval = PSCORE_ZERO;

    Bitboard king_ring     = king_ring_table[pos.king_sq(color).raw];
    Bitboard extended_ring = extended_ring_table[pos.king_sq(color).raw];

    Bitboard flank =
      king_flank[static_cast<usize>(color)][static_cast<usize>(pos.king_sq(color).file())];

    // Piece attacks in inner/outer ring
    for (PieceType pt : {PieceType::Pawn, PieceType::Knight, PieceType::Bishop, PieceType::Rook,
                         PieceType::Queen}) {
        Bitboard attacked = data.attacked_by(opp, pt);
        Bitboard inner    = attacked & king_ring;
        Bitboard outer    = attacked & extended_ring & ~king_ring;
        eval += PT_INNER_RING_ATTACKS[static_cast<usize>(pt) - static_cast<usize>(PieceType::Pawn)]
              * inner.ipopcount();
        eval += PT_OUTER_RING_ATTACKS[static_cast<usize>(pt) - static_cast<usize>(PieceType::Pawn)]
              * outer.ipopcount();
    }

    const Bitboard opp_reach = data.reach_all[static_cast<usize>(opp)];
    eval += REACH_INNER_RING * (opp_reach & king_ring).ipopcount();
    eval += REACH_OUTER_RING * (opp_reach & extended_ring & ~king_ring).ipopcount();
    eval +=
      REACH_RING_DEFENSE * (data.reach_all[static_cast<usize>(color)] & king_ring).ipopcount();
    eval += REACH_RING_TWICE * (data.reach_2[static_cast<usize>(opp)] & king_ring).ipopcount();

    // Flank attack / defense status
    Bitboard defended_by_us        = data.attacked_by(color);
    Bitboard double_defended_by_us = data.attacked_by_2(color);

    Bitboard attacked_by_them        = data.attacked_by(opp);
    Bitboard double_attacked_by_them = data.attacked_by_2(opp);

    eval += KS_FLANK_DEFENSE * (defended_by_us & flank).ipopcount();
    eval += KS_FLANK_ATTACK * (attacked_by_them & flank).ipopcount();
    eval += KS_FLANK_DOUBLE_DEFENSE * (double_defended_by_us & flank).ipopcount();
    eval += KS_FLANK_DOUBLE_ATTACK * (double_attacked_by_them & flank).ipopcount();

    // King shelter evaluation
    eval += king_shelter<color>(pos, data);

    eval += KS_NO_QUEEN * (pos.bitboard_for(opp, PieceType::Queen).empty());

    return eval;
}

template<Color color>
PScore evaluate_threats(const Position& pos, const EvalData& data) {
    constexpr Color opp  = ~color;
    PScore          eval = PSCORE_ZERO;

    Bitboard b, weak, defended, opp_pawn, opp_non_pawn, strongly_protected;
    opp_pawn     = pos.bitboard_for(opp, PieceType::Pawn);
    opp_non_pawn = pos.board().get_color_bitboard(opp) & ~opp_pawn;

    strongly_protected = data.attacked_by(opp, PieceType::Pawn)
                       | (data.attacked_by_2(opp) & ~data.attacked_by_2(color));

    defended = opp_non_pawn & strongly_protected;

    weak = pos.board().get_color_bitboard(opp) & ~strongly_protected & data.attacked_by(color);

    if ((defended | weak).any()) {
        // Minor threats
        b = (defended | weak)
          & (data.attacked_by(color, PieceType::Knight)
             | data.attacked_by(color, PieceType::Bishop));
        for (Square sq : b) {
            PieceType pt = pos.piece_at(sq);
            eval += MINOR_THREAT[pos.active_color() == color]
                                [static_cast<usize>(pt) - static_cast<usize>(PieceType::Pawn)];
        }

        // Rook threats
        b = weak & data.attacked_by(color, PieceType::Rook);
        for (Square sq : b) {
            PieceType pt = pos.piece_at(sq);
            eval += ROOK_THREAT[pos.active_color() == color]
                               [static_cast<usize>(pt) - static_cast<usize>(PieceType::Pawn)];
        }

        // King threats
        if ((weak & data.attacked_by(color, PieceType::King)).any()) {
            eval += KING_THREAT;
        }

        // Hanging pieces
        b = weak & (~data.attacked_by(opp) | (opp_non_pawn & data.attacked_by_2(color)));
        eval += HANGING_PAWN * (b & opp_pawn).ipopcount();
        eval += HANGING_NON_PAWN * (b & opp_non_pawn).ipopcount();
    }

    // Two-move threats
    Bitboard reach_targets =
      data.reach_all[static_cast<usize>(color)] & opp_non_pawn & ~data.attacked_by(color);
    eval += REACH_THREAT * (reach_targets & data.attacked_by(opp)).ipopcount();
    eval += REACH_THREAT_LOOSE * (reach_targets & ~data.attacked_by(opp)).ipopcount();

    eval += RESTRICTED_SQUARES
          * (data.attacked_by(color) & ~strongly_protected & data.attacked_by(opp)).ipopcount();

    Bitboard pawn_attacks = data.attacked_by(color, PieceType::Pawn);
    eval +=
      PAWN_THREAT_KNIGHT * (pos.bitboard_for(opp, PieceType::Knight) & pawn_attacks).ipopcount();
    eval +=
      PAWN_THREAT_BISHOP * (pos.bitboard_for(opp, PieceType::Bishop) & pawn_attacks).ipopcount();
    eval += PAWN_THREAT_ROOK * (pos.bitboard_for(opp, PieceType::Rook) & pawn_attacks).ipopcount();
    eval +=
      PAWN_THREAT_QUEEN * (pos.bitboard_for(opp, PieceType::Queen) & pawn_attacks).ipopcount();

    // Our attacks on enemy queen
    if (data.piece_count(opp, PieceType::Queen) == 1) {

        Bitboard opp_queens = pos.bitboard_for(opp, PieceType::Queen);

        bool queen_imbalance = data.piece_count(color, PieceType::Queen) == 0;

        Square   sq   = opp_queens.lsb();
        Bitboard safe = data.mobility_area[static_cast<usize>(color)]
                      & ~pos.bitboard_for(color, PieceType::Pawn) & ~strongly_protected;


        b = knight_squares_table[sq.raw] & data.attacked_by(color, PieceType::Knight) & safe;
        eval += KNIGHT_ON_QUEEN[queen_imbalance] * b.ipopcount();

        safe &= data.attacked_by_2(color);

        Bitboard attacks = data.attacked_by(opp, PieceType::Queen);

        Bitboard a = attacks & diagonal_squares_table[sq.raw];

        b = a & data.attacked_by(color, PieceType::Bishop) & safe;
        eval += BISHOP_ON_QUEEN[queen_imbalance] * b.ipopcount();

        a = attacks ^ a;

        b = a & data.attacked_by(color, PieceType::Rook) & safe;
        eval += ROOK_ON_QUEEN[queen_imbalance] * b.ipopcount();
    }

    return eval;
}

template<Color color>
PScore evaluate_space(const Position& pos, const EvalData& data) {
    PScore          eval       = PSCORE_ZERO;
    constexpr Color them       = color == Color::White ? Color::Black : Color::White;
    Bitboard        ourfiles   = Bitboard::fill_verticals(pos.bitboard_for(color, PieceType::Pawn));
    Bitboard        theirfiles = Bitboard::fill_verticals(pos.bitboard_for(them, PieceType::Pawn));
    Bitboard        openfiles  = ~(ourfiles | theirfiles);
    Bitboard        half_open_files = (~ourfiles) & theirfiles;
    Bitboard        ourminors =
      pos.bitboard_for(color, PieceType::Knight) | pos.bitboard_for(color, PieceType::Bishop);

    eval += ROOK_OPEN_VAL * (openfiles & pos.bitboard_for(color, PieceType::Rook)).ipopcount();
    eval +=
      ROOK_SEMIOPEN_VAL * (half_open_files & pos.bitboard_for(color, PieceType::Rook)).ipopcount();

    eval += MINOR_BEHIND_PAWN
          * (ourminors.shift_relative(color, Direction::North)
             & (pos.bitboard_for(them, PieceType::Pawn) | pos.bitboard_for(color, PieceType::Pawn)))
              .ipopcount();

    return eval;
}

// SFC-style space
template<Color color>
PScore evaluate_sf_space(const Position& pos, const EvalData& data, i32 blocked_pawns) {
    constexpr Color    opp = ~color;
    constexpr Bitboard space_mask =
      Bitboard::central_files()
      & (color == Color::White
           ? Bitboard::rank_mask(1) | Bitboard::rank_mask(2) | Bitboard::rank_mask(3)
           : Bitboard::rank_mask(6) | Bitboard::rank_mask(5) | Bitboard::rank_mask(4));

    Bitboard own_pawns = pos.bitboard_for(color, PieceType::Pawn);
    Bitboard safe      = space_mask & ~own_pawns & ~data.attacked_by(opp, PieceType::Pawn);

    // Squares at most three squares behind one of our pawns
    Bitboard behind = own_pawns;
    behind |= behind.shift_relative(color, Direction::South);
    behind |= behind.shift_relative(color, Direction::South, 2);

    i32 bonus  = safe.ipopcount() + (behind & safe & ~data.attacked_by(opp)).ipopcount();
    i32 weight = pos.board().get_color_bitboard(color).ipopcount() - 3 + std::min(blocked_pawns, 9);

    return mul_div(SPACE_VAL, bonus * weight * weight, 1024);
}

template<Color color>
PScore king_safety_activation(PScore& king_safety_score) {
    // Apply sigmoid activation to king safety score
    PScore activated = KING_SAFETY_ACTIVATION(king_safety_score);
    return activated;
}

PScore apply_winnable(const Position& pos, PScore& score, i32 phase) {

    bool pawn_endgame = phase == 0;

    Bitboard white_pawns = pos.bitboard_for(Color::White, PieceType::Pawn);
    Bitboard black_pawns = pos.bitboard_for(Color::Black, PieceType::Pawn);

    i32 pawn_count = (white_pawns | black_pawns).ipopcount();

    Bitboard white_files = Bitboard::fill_verticals(white_pawns);
    Bitboard black_files = Bitboard::fill_verticals(black_pawns);

    i32 sym_files  = (white_files & black_files).ipopcount() / 8;
    i32 asym_files = (white_files ^ black_files).ipopcount() / 8;

    Score symmetry = static_cast<Score>(WINNABLE_SYM * sym_files + WINNABLE_ASYM * asym_files);

    Score winnable = static_cast<Score>(WINNABLE_PAWNS * pawn_count + symmetry
                                        + WINNABLE_PAWN_ENDGAME * pawn_endgame + WINNABLE_BIAS);

    if (score.eg() < 0) {
        winnable = static_cast<Score>(-winnable);
    }

    return score.complexity_add(winnable);
}

PScore apply_eg_scale(const Position& pos,
                      PScore&         eval,
                      i32             strong_phase,
                      i32             weak_phase,
                      i32             strong_passers,
                      i32             weak_passers,
                      EvalData&       eval_data) {
    // Strong pawn scaling
    const Color strong_side = eval.eg() > 0 ? Color::White : Color::Black;

    // Swap phases if we're in the weak side's perspective
    if (strong_side == Color::Black) {
        std::swap(strong_phase, weak_phase);
        std::swap(strong_passers, weak_passers);
    }

    const i32 strong_pawn_count = eval_data.piece_count(strong_side, PieceType::Pawn);
    const i32 weak_pawn_count   = eval_data.piece_count(~strong_side, PieceType::Pawn);

    // Pawnless position scaling: if our material advantage is very thin and we have no pawns, scale down the eval significantly, as trading can lead to KBK or KNK draws
    if (strong_pawn_count == 0) {
        if (strong_phase - weak_phase <= 1) {
            return eval.scale_eg<128>(strong_phase < 2 ? 0 : weak_phase <= 1 ? 8 : 28);
        }
    } else if (pos.is_opposite_bishops()) {
        // Opposite bishops scaling: pure bishops endgame / other pieces present
        if (strong_phase == 1 && weak_phase == 1) {
            return eval.scale_eg<128>(28 + 8 * strong_passers
                                      + 8 * (strong_pawn_count >= weak_pawn_count + 2));
        } else {
            return eval.scale_eg<128>(44 + 3 * pos.piece_count(strong_side));
        }
    }

    const isize pcmul = 8 - strong_pawn_count;

    return eval.scale_eg<128>(static_cast<i32>(128 - pcmul * pcmul));  // 64 - 128
}


// Setwise attacks of a piece type from a set of squares.
static inline Bitboard piece_setwise(PieceType pt, Bitboard from, Bitboard occ) {
    switch (pt) {
    case PieceType::Knight:
        return knights_setwise(from);
    case PieceType::Bishop:
        return bishops_setwise(from, occ);
    case PieceType::Rook:
        return rooks_setwise(from, occ);
    default:
        return queens_setwise(from, occ);
    }
}

// NOTE: this is a CLUSTERFUCK of terms tried to find stuff from puzzles
// Handpicked values do solve all them, but ideally we should be able to solve with tuned values as well.
// TODO: not for merge before simplifications and handpick test on values is done

// Trapped pieces: a non-pawn piece that cannot get out of a small pocket of safe squares.
// Candidates are the pieces with at most 3 restricted-mobility squares.

// Two types:
//  - entombed: no restricted-mobility square at all (TRAPPED_PIECE);
//  - confined: the zone of safe squares it can flood to is closed and holds at most 3 squares,
//    and only enemy control and own pawns form the wall (TRAPPED_CONFINED, less malus if the
//    zone still attacks an enemy piece or a movable own pawn is part of the wall; TODO: some pawn moves
//    don't increase the zone still, detect them maybe)

// Don't consider:
//  - pieces already attacked (threats term)
//  - not merely boxed in by own men (noisy, they usually can move)

// Other considerations:
// - Relief: another own piece (not this one, not the king) attacks, or can reach in one move,
//   one of the mobarea attackers; the cage can then be contested, so it is not scored.
// - Walls of own blocked pawns and pawn-only cages are given extra score.

template<Color color>
PScore evaluate_trapped(const Position& pos, const EvalData& data) {
    constexpr Color opp  = ~color;
    PScore          eval = PSCORE_ZERO;

    const PieceMask candidates = data.trap_candidates[static_cast<usize>(color)];
    if (candidates.empty()) {
        return eval;
    }

    const Bitboard own        = pos.board().get_color_bitboard(color);
    const Bitboard occ        = pos.board().get_occupied_bitboard();
    const Bitboard empty      = ~occ;
    const Bitboard own_pawns  = pos.bitboard_for(color, PieceType::Pawn);
    const Bitboard opp_pawns  = pos.bitboard_for(opp, PieceType::Pawn);
    const Bitboard opp_rooks  = pos.bitboard_for(opp, PieceType::Rook);
    const Bitboard opp_queens = pos.bitboard_for(opp, PieceType::Queen);
    const Bitboard opp_nonpawn =
      pos.board().get_color_bitboard(opp) & ~opp_pawns & ~Bitboard::from_square(pos.king_sq(opp));
    const Bitboard blocked_pawns = own_pawns & occ.shift_relative(color, Direction::South);
    const Bitboard opp_attacks   = data.attacked_by(opp);
    const Bitboard hanging       = opp_attacks & ~data.attacked_by(color);

    // Attack tables: which pieces hit a square. Own knights to queens (no pawns, no king) serve the
    // relief test; the enemy table names the pieces that keep a pocket shut.
    const Wordboard& own_attacks   = pos.attack_table(color);
    const Wordboard& opp_attacks_t = pos.attack_table(opp);
    const PieceMask  own_pieces =
      pos.piece_list(color)
        .mask_eq<PieceType::Knight, PieceType::Bishop, PieceType::Rook, PieceType::Queen>();
    const PieceMask opp_pawn_ids = pos.piece_list(opp).mask_eq(PieceType::Pawn);
    const Bitboard  base_relief =
      data.attacked_by(color, PieceType::Pawn) | data.reach_all[static_cast<usize>(color)];

    for (PieceId id : candidates) {
        const PieceType pt    = pos.piece_list(color)[id];
        const Square    sq    = pos.piece_list_sq(color)[id];
        const Bitboard  sq_bb = Bitboard::from_square(sq);
        const Bitboard moves   = pos.moves_of(color, id);
        const Bitboard escapes = moves & ~own;

        // Captures that always count as escapes: pieces worth at least as much as this one.
        const Bitboard big_caps = pt == PieceType::Queen ? opp_queens
                                : pt == PieceType::Rook  ? opp_rooks | opp_queens
                                                         : opp_nonpawn;

        // Restricted mobility (what evaluate_pieces scored) is the move set inside the piece's area.
        const Bitboard mobility = moves & data.area_for(color, pt);
        const bool     entombed = mobility.empty();
        const Bitboard unsafe   = ~data.area_for(color, pt) | hanging;
        // Wall squares
        Bitboard boundary = escapes;
        Bitboard walls_bb = king_ring_table[sq.raw];
        Bitboard reached  = Bitboard{};
        if (!entombed) {
            // 2 step floodfill. End early if big enough, no new steps or we find a target
            const auto safe_of = [&](Bitboard b) {
                return (b & ~own) & (~unsafe | big_caps);
            };
            reached = safe_of(moves);
            if ((reached & big_caps).any()) {
                continue;
            }
            // Kogge-Stone pass is only needed if the zone turns out closed.
            Bitboard spread;
            Bitboard next;
            if ((reached & empty) == (mobility & empty)) {
                next = safe_of(data.reach(color, id)) & ~sq_bb & ~reached;
                if (next.empty()) {
                    spread = piece_setwise(pt, reached & empty, occ);
                }
            } else {
                spread = piece_setwise(pt, reached & empty, occ);
                next   = safe_of(spread) & ~sq_bb & ~reached;
            }
            if (next.any()) {
                reached |= next;
                if (reached.popcount() > 3 || (reached & big_caps).any()) {
                    continue;
                }
                // Second step: closed only if it adds nothing.
                spread = piece_setwise(pt, reached & empty, occ);
                if ((safe_of(spread) & ~sq_bb & ~reached).any()) {
                    continue;
                }
            }
            boundary = (moves | spread) & ~reached & ~sq_bb;
            if ((boundary & own & ~own_pawns).any()) {
                continue;
            }
            walls_bb = boundary;
        }
        const Bitboard unsafe_boundary = boundary & ~own & unsafe;

        // The enemy pieces keeping the pocket shut (supporting wall squares).
        PieceMask attackers{};
        for (Square s : unsafe_boundary) {
            attackers |= opp_attacks_t.read(s);
        }
        attackers &= ~PieceMask::king();

        // Relief: another own piece attacks or reach onto one of those supports
        // The cage can then be contested, so it is not scored.
        const Bitboard relief =
          base_relief | own_attacks.get_piece_mask_bitboard(own_pieces & ~id.to_piece_mask());
        bool relieved = false;
        for (PieceId aid : attackers) {
            relieved |= (relief & Bitboard::from_square(pos.piece_list_sq(opp)[aid])).any();
        }
        if (relieved) {
            continue;
        }

        const usize idx   = static_cast<usize>(pt) - static_cast<usize>(PieceType::Knight);
        const i32   walls = std::min<i32>(2, (walls_bb & blocked_pawns).ipopcount());
        // Wizard formula from data, TODO: TRY TO SIMPLIFY THIS
        eval += entombed ? TRAPPED_PIECE[idx] : TRAPPED_CONFINED[idx];
        eval += TRAPPED_WALL * walls;
        if (!entombed) {
            // If the piece is not entombed AND still does something (the trap zone is not useless), less malus
            if (((piece_setwise(pt, reached, occ) | moves) & opp_nonpawn).any()) {
                eval += TRAPPED_ZONE_UTIL;
            }
            if ((boundary & own_pawns & ~blocked_pawns).any()) {
                eval += TRAPPED_SOFT_WALL;
            }
        }
        // Only pawns keep it in: no piece has to stay behind to hold the cage.
        if ((attackers & ~opp_pawn_ids).empty()) {
            eval += TRAPPED_PAWN_CAGE;
        }
    }
    return eval;
}

Score evaluate_white_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();

    EvalData eval_data;
    eval_data.init(pos);

    const i32 white_phase = eval_data.piece_count(Color::White, PieceType::Knight)
                          + eval_data.piece_count(Color::White, PieceType::Bishop)
                          + eval_data.piece_count(Color::White, PieceType::Rook) * 2
                          + eval_data.piece_count(Color::White, PieceType::Queen) * 4;

    const i32 black_phase = eval_data.piece_count(Color::Black, PieceType::Knight)
                          + eval_data.piece_count(Color::Black, PieceType::Bishop)
                          + eval_data.piece_count(Color::Black, PieceType::Rook) * 2
                          + eval_data.piece_count(Color::Black, PieceType::Queen) * 4;

    i32 phase = std::min<i32>(white_phase + black_phase, 24);

    PScore eval = psqt_state.score();  // Used for linear components

    // pawn eval
    auto [white_pawn_eval, white_passers] = evaluate_pawns<Color::White>(pos, eval_data);
    auto [black_pawn_eval, black_passers] = evaluate_pawns<Color::Black>(pos, eval_data);
    eval += white_pawn_eval - black_pawn_eval;

    // pieces & space
    eval +=
      evaluate_pieces<Color::White>(pos, eval_data) - evaluate_pieces<Color::Black>(pos, eval_data);
    eval += evaluate_trapped<Color::White>(pos, eval_data)
          - evaluate_trapped<Color::Black>(pos, eval_data);
    eval += evaluate_outposts<Color::White>(pos, eval_data)
          - evaluate_outposts<Color::Black>(pos, eval_data);
    eval +=
      evaluate_space<Color::White>(pos, eval_data) - evaluate_space<Color::Black>(pos, eval_data);

    // SFC-style space, phase switch
    if (phase >= 18) {
        const Bitboard white_pawns = pos.bitboard_for(Color::White, PieceType::Pawn);
        const Bitboard black_pawns = pos.bitboard_for(Color::Black, PieceType::Pawn);
        const Bitboard white_pawn_double_attacks =
          white_pawns.shift(Direction::NorthEast) & white_pawns.shift(Direction::NorthWest);
        const Bitboard black_pawn_double_attacks =
          black_pawns.shift(Direction::SouthEast) & black_pawns.shift(Direction::SouthWest);

        const i32 blocked_pawns =
          (white_pawns.shift(Direction::North) & (black_pawns | black_pawn_double_attacks))
            .ipopcount()
          + (black_pawns.shift(Direction::South) & (white_pawns | white_pawn_double_attacks))
              .ipopcount();
        eval += evaluate_sf_space<Color::White>(pos, eval_data, blocked_pawns)
              - evaluate_sf_space<Color::Black>(pos, eval_data, blocked_pawns);
    }

    // Threats
    eval += evaluate_threats<Color::White>(pos, eval_data)
          - evaluate_threats<Color::Black>(pos, eval_data);
    eval +=
      evaluate_pawn_push_threats<Color::White>(pos) - evaluate_pawn_push_threats<Color::Black>(pos);

    // King safety
    eval += evaluate_potential_checkers<Color::White>(pos)
          - evaluate_potential_checkers<Color::Black>(pos);

    // Nonlinear king safety components
    PScore white_king_attack_total = evaluate_king_safety<Color::Black>(pos, eval_data);
    PScore black_king_attack_total = evaluate_king_safety<Color::White>(pos, eval_data);

    // Nonlinear adjustment
    eval += king_safety_activation<Color::White>(white_king_attack_total)
          - king_safety_activation<Color::Black>(black_king_attack_total);

    eval += (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;

    // Winnable
    eval = apply_winnable(pos, eval, phase);

    // Eg scaling
    eval =
      apply_eg_scale(pos, eval, white_phase, black_phase, white_passers, black_passers, eval_data);

    return static_cast<Score>(eval.phase<24>(static_cast<i32>(phase)));
};

Score evaluate_stm_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();
    return static_cast<Score>((us == Color::White) ? evaluate_white_pov(pos, psqt_state)
                                                   : -evaluate_white_pov(pos, psqt_state));
}

}  // namespace Clockwork
