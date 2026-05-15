#include "evaluation.hpp"
#include "bitboard.hpp"
#include "common.hpp"
#include "eval_constants.hpp"
#include "eval_types.hpp"
#include "position.hpp"
#include "psqt_state.hpp"
#include "square.hpp"
#include <array>
#include <ranges>

namespace Clockwork {

static i32 chebyshev_distance(Square a, Square b) {
    const i32 file_dist = std::abs(a.file() - b.file());
    const i32 rank_dist = std::abs(a.rank() - b.rank());
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
    const Bitboard attacks = pawns.shift_relative(color, Direction::NorthEast)
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
        const Bitboard sq_bb     = Bitboard::from_square(Square{sq_idx});
        Bitboard       king_ring = sq_bb;
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
        const Bitboard sq_bb         = king_ring_table[sq_idx];
        Bitboard       extended_ring = sq_bb;
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


std::array<Bitboard, 64> diagonal_squares_table = []() {
    std::array<Bitboard, 64> diagonal_squares_table{};
    for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
        const Square sq = Square{sq_idx};

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

std::array<std::array<Bitboard, 64>, 2> passed_pawn_spans = []() {
    std::array<std::array<Bitboard, 64>, 2> passed_pawn_masks{};
    for (Color color : {Color::White, Color::Black}) {
        for (u8 sq_idx = 0; sq_idx < 64; sq_idx++) {
            const Bitboard sq_bb = Bitboard::from_square(Square{sq_idx});
            Bitboard       mask  = sq_bb.shift_relative(color, Direction::North);
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
PScore evaluate_pawns(const Position& pos) {
    constexpr i32   RANK_2 = 1;
    constexpr i32   RANK_3 = 2;
    constexpr Color them   = color == Color::White ? Color::Black : Color::White;

    const Square our_king   = pos.king_sq(color);
    const Square their_king = pos.king_sq(them);
    PScore       eval       = PSCORE_ZERO;

    const Bitboard pawns     = pos.board().bitboard_for(color, PieceType::Pawn);
    const Bitboard opp_pawns = pos.board().bitboard_for(~color, PieceType::Pawn);

    const Bitboard pawn_files = Bitboard::fill_verticals(pawns);
    const Bitboard doubled    = pawns & pawns.shift(Direction::North);
    const Bitboard isolated =
      pawns & ~(pawn_files.shift(Direction::East) | pawn_files.shift(Direction::West));
    eval += DOUBLED_PAWN_VAL * doubled.ipopcount();
    eval += ISOLATED_PAWN_VAL * isolated.ipopcount();

    for (const Square sq : pawns) {
        const Square   push     = sq.push<color>();
        const Bitboard stoppers = opp_pawns & passed_pawn_spans[static_cast<usize>(color)][sq.raw];
        if (stoppers.empty()) {
            eval += PASSED_PAWN[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
            if (pos.attack_table(color).read(push).popcount()
                > pos.attack_table(them).read(push).popcount()) {
                eval +=
                  DEFENDED_PASSED_PUSH[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
            }
            if (pos.piece_at(push) != PieceType::None) {
                eval +=
                  BLOCKED_PASSED_PAWN[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
            }

            const i32 our_king_dist   = chebyshev_distance(our_king, sq);
            const i32 their_king_dist = chebyshev_distance(their_king, sq);

            eval += FRIENDLY_KING_PASSED_PAWN_DISTANCE[static_cast<usize>(our_king_dist)];
            eval += ENEMY_KING_PASSED_PAWN_DISTANCE[static_cast<usize>(their_king_dist)];
        }
    }


    const Bitboard phalanx = pawns & pawns.shift(Direction::East);
    for (const Square sq : phalanx) {
        eval += PAWN_PHALANX[static_cast<usize>(sq.relative_sq(color).rank() - RANK_2)];
    }

    const Bitboard defended = pawns & pos.attacked_by(color, PieceType::Pawn);
    for (const Square sq : defended) {
        eval += DEFENDED_PAWN[static_cast<usize>(sq.relative_sq(color).rank() - RANK_3)];
    }

    return eval;
}

template<Color color>
PScore evaluate_pawn_push_threats(const Position& pos) {
    constexpr Color opp  = ~color;
    PScore          eval = PSCORE_ZERO;

    const Bitboard our_pawns  = pos.bitboard_for(color, PieceType::Pawn);
    const Bitboard all_pieces = pos.board().get_occupied_bitboard();

    const Bitboard pushable = our_pawns & ~all_pieces.shift_relative(color, Direction::South);

    const Bitboard push_attacks =
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

template<Color color>
PScore king_shelter(const Position& pos) {
    constexpr Color opp = ~color;

    const Square king_square = pos.king_sq(color);
    const i32    king_file   = king_square.file();

    const Bitboard b_fwd =
      ~Bitboard::forward_ranks(opp, king_square);  // Squares ahead or on king's rank
    const Bitboard our_pawns =
      pos.bitboard_for(color, PieceType::Pawn) & b_fwd & ~pos.attacked_by(opp, PieceType::Pawn);
    const Bitboard their_pawns = pos.bitboard_for(opp, PieceType::Pawn) & b_fwd;

    PScore score = PSCORE_ZERO;

    const i32 shelter_center = std::clamp(king_file, 1, 6);

    for (i32 offset = -1; offset <= 1; offset++) {
        const i32      file    = shelter_center + offset;
        const Bitboard file_bb = Bitboard::file_mask(file);

        // Our pawns
        const Bitboard our_file_pawns = our_pawns & file_bb;
        const i32      our_rank =
          our_file_pawns.any() ? our_file_pawns.frontmost_square(opp).relative_rank(color) : 0;

        // Opponent pawns
        const Bitboard their_file_pawns = their_pawns & file_bb;
        const i32      their_rank =
          their_file_pawns.any() ? their_file_pawns.frontmost_square(opp).relative_rank(color) : 0;

        const i32 edge_idx = std::min(file, 7 - file);

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
struct CheckerInfo {
    Wordboard mask;
    Bitboard  undefended;
};

template<Color color>
CheckerInfo<color> make_checker_info(const Position& pos) {
    constexpr Color opp    = ~color;
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

    return CheckerInfo<color>{
      .mask       = mask,
      .undefended = ~pos.attack_table(color).get_attacked_bitboard(),
    };
}

template<Color color, PieceType pt>
PScore piece_safe_checks(PieceId id, const CheckerInfo<color>& ci) {
    const Bitboard safe_checks =
      ci.mask.get_piece_mask_bitboard(id.to_piece_mask()) & ci.undefended;

    if (!safe_checks.any()) {
        return PSCORE_ZERO;
    }

    const usize ptidx = static_cast<usize>(pt) - static_cast<usize>(PieceType::Knight);
    return KS_SAFE_CHECKS[ptidx][std::min(safe_checks.popcount() - 1, usize{1})];
}
template<Color color>
std::pair<PScore, PScore> evaluate_pieces_and_checkers(const Position& pos) {
    constexpr Color opp      = ~color;
    PScore          pieces   = PSCORE_ZERO;
    PScore          checkers = PSCORE_ZERO;

    // Precompute checker info for the opponent's king (our pieces threaten it)
    const CheckerInfo<opp> ci_opp = make_checker_info<opp>(pos);
    checkers += POTENTIAL_CHECKER_VAL * ci_opp.mask.popcount();

    const Bitboard own_pawns = pos.bitboard_for(color, PieceType::Pawn);
    const Bitboard blocked_pawns =
      own_pawns & pos.board().get_occupied_bitboard().shift_relative(color, Direction::South);
    constexpr Bitboard early_ranks     = color == Color::White
                                         ? Bitboard::rank_mask(1) | Bitboard::rank_mask(2)
                                         : Bitboard::rank_mask(5) | Bitboard::rank_mask(6);
    const Bitboard     own_early_pawns = own_pawns & early_ranks;
    Bitboard bb  = (blocked_pawns | own_early_pawns) | pos.attacked_by(opp, PieceType::Pawn);
    Bitboard bb2 = bb;

    for (PieceId id : pos.get_piece_mask(color, PieceType::Knight)) {
        pieces += KNIGHT_MOBILITY[pos.mobility_of(color, id, ~bb)];
        checkers += piece_safe_checks<opp, PieceType::Knight>(id, ci_opp);
    }

    for (PieceId id : pos.get_piece_mask(color, PieceType::Bishop)) {
        pieces += BISHOP_MOBILITY[pos.mobility_of(color, id, ~bb)];
        const Square sq = pos.piece_list_sq(color)[id];
        pieces +=
          BISHOP_PAWNS[std::min(static_cast<usize>(8),
                                (own_pawns & Bitboard::squares_of_color(sq.color())).popcount())]
          * (!pos.is_square_attacked_by(sq, color, PieceType::Pawn)
             + (blocked_pawns & Bitboard::central_files()).ipopcount());
        const Bitboard xray = diagonal_squares_table[sq.raw];
        pieces += BISHOP_XRAY_PAWNS * (xray & pos.bitboard_for(opp, PieceType::Pawn)).ipopcount();
        checkers += piece_safe_checks<opp, PieceType::Bishop>(id, ci_opp);
    }

    bb2 |= pos.attacked_by(opp, PieceType::Knight) | pos.attacked_by(opp, PieceType::Bishop);

    for (PieceId id : pos.get_piece_mask(color, PieceType::Rook)) {
        pieces += ROOK_MOBILITY[pos.mobility_of(color, id, ~bb)];
        pieces += ROOK_MOBILITY[pos.mobility_of(color, id, ~bb2)];
        const Bitboard rook_file = Bitboard::file_mask(pos.piece_list_sq(color)[id].file());
        pieces += ROOK_LINEUP
                * (rook_file
                   & (pos.bitboard_for(~color, PieceType::Queen)
                      | pos.bitboard_for(color, PieceType::Queen)))
                    .ipopcount();
        checkers += piece_safe_checks<opp, PieceType::Rook>(id, ci_opp);
    }

    bb2 |= pos.attacked_by(opp, PieceType::Rook);

    for (PieceId id : pos.get_piece_mask(color, PieceType::Queen)) {
        pieces += QUEEN_MOBILITY[pos.mobility_of(color, id, ~bb)];
        pieces += QUEEN_MOBILITY[pos.mobility_of(color, id, ~bb2)];
        checkers += piece_safe_checks<opp, PieceType::Queen>(id, ci_opp);
    }

    if (pos.piece_count(color, PieceType::Bishop) >= 2) {
        pieces += BISHOP_PAIR_VAL;
    }

    return {pieces, checkers};
}

template<Color color>
PScore evaluate_outposts(const Position& pos) {
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
    const Bitboard opp_pawns             = pos.bitboard_for(opp, PieceType::Pawn);
    const Bitboard opp_pawn_span         = pawn_spans<opp>(opp_pawns);
    const Bitboard opp_pawn_span_attacks = static_pawn_attacks<opp>(
      opp_pawn_span);  // Note, this does NOT consider pins! Might need to test this more thoroughly.
    const Bitboard pawn_defended_squares = pos.attacked_by(color, PieceType::Pawn);
    const Bitboard viable_outposts =
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
PScore evaluate_king_safety(const Position& pos) {
    constexpr Color opp = ~color;

    // Iterate over the opponent's attack bbs
    PScore eval = PSCORE_ZERO;

    const Bitboard king_ring     = king_ring_table[pos.king_sq(color).raw];
    const Bitboard extended_ring = extended_ring_table[pos.king_sq(color).raw];

    const Bitboard flank =
      king_flank[static_cast<usize>(color)][static_cast<usize>(pos.king_sq(color).file())];

    // Piece attacks in inner/outer ring
    for (PieceType pt : {PieceType::Pawn, PieceType::Knight, PieceType::Bishop, PieceType::Rook,
                         PieceType::Queen}) {
        const Bitboard attacked = pos.attacked_by(opp, pt);
        const Bitboard inner    = attacked & king_ring;
        const Bitboard outer    = attacked & extended_ring & ~king_ring;
        eval += PT_INNER_RING_ATTACKS[static_cast<usize>(pt) - static_cast<usize>(PieceType::Pawn)]
              * inner.ipopcount();
        eval += PT_OUTER_RING_ATTACKS[static_cast<usize>(pt) - static_cast<usize>(PieceType::Pawn)]
              * outer.ipopcount();
    }

    // Flank attack / defense status
    const Bitboard defended_by_us        = pos.attack_table(color).get_attacked_bitboard();
    const Bitboard double_defended_by_us = pos.attacked_by_two_or_more(color);

    const Bitboard attacked_by_them        = pos.attack_table(opp).get_attacked_bitboard();
    const Bitboard double_attacked_by_them = pos.attacked_by_two_or_more(opp);

    eval += KS_FLANK_DEFENSE * (defended_by_us & flank).ipopcount();
    eval += KS_FLANK_ATTACK * (attacked_by_them & flank).ipopcount();
    eval += KS_FLANK_DOUBLE_DEFENSE * (double_defended_by_us & flank).ipopcount();
    eval += KS_FLANK_DOUBLE_ATTACK * (double_attacked_by_them & flank).ipopcount();

    // King shelter evaluation
    eval += king_shelter<color>(pos);

    eval += KS_NO_QUEEN * (pos.bitboard_for(opp, PieceType::Queen).empty());

    return eval;
}

template<Color color>
PScore evaluate_threats(const Position& pos) {
    constexpr Color opp  = ~color;
    PScore          eval = PSCORE_ZERO;

    const Bitboard pawn_attacks = pos.attacked_by(color, PieceType::Pawn);
    eval +=
      PAWN_THREAT_KNIGHT * (pos.bitboard_for(opp, PieceType::Knight) & pawn_attacks).ipopcount();
    eval +=
      PAWN_THREAT_BISHOP * (pos.bitboard_for(opp, PieceType::Bishop) & pawn_attacks).ipopcount();
    eval += PAWN_THREAT_ROOK * (pos.bitboard_for(opp, PieceType::Rook) & pawn_attacks).ipopcount();
    eval +=
      PAWN_THREAT_QUEEN * (pos.bitboard_for(opp, PieceType::Queen) & pawn_attacks).ipopcount();

    const Bitboard knight_attacks = pos.attacked_by(color, PieceType::Knight);
    eval += KNIGHT_THREAT_BISHOP
          * (pos.bitboard_for(opp, PieceType::Bishop) & knight_attacks).ipopcount();
    eval +=
      KNIGHT_THREAT_ROOK * (pos.bitboard_for(opp, PieceType::Rook) & knight_attacks).ipopcount();
    eval +=
      KNIGHT_THREAT_QUEEN * (pos.bitboard_for(opp, PieceType::Queen) & knight_attacks).ipopcount();

    const Bitboard bishop_attacks = pos.attacked_by(color, PieceType::Bishop);
    eval += BISHOP_THREAT_KNIGHT
          * (pos.bitboard_for(opp, PieceType::Knight) & bishop_attacks).ipopcount();
    eval +=
      BISHOP_THREAT_ROOK * (pos.bitboard_for(opp, PieceType::Rook) & bishop_attacks).ipopcount();
    eval +=
      BISHOP_THREAT_QUEEN * (pos.bitboard_for(opp, PieceType::Queen) & bishop_attacks).ipopcount();

    return eval;
}

template<Color color>
PScore evaluate_space(const Position& pos) {
    PScore          eval       = PSCORE_ZERO;
    constexpr Color them       = color == Color::White ? Color::Black : Color::White;
    const Bitboard  ourfiles   = Bitboard::fill_verticals(pos.bitboard_for(color, PieceType::Pawn));
    const Bitboard  theirfiles = Bitboard::fill_verticals(pos.bitboard_for(them, PieceType::Pawn));
    const Bitboard  openfiles  = ~(ourfiles | theirfiles);
    const Bitboard  half_open_files = (~ourfiles) & theirfiles;
    const Bitboard  ourminors =
      pos.bitboard_for(color, PieceType::Knight) | pos.bitboard_for(color, PieceType::Bishop);

    eval += ROOK_OPEN_VAL * (openfiles & pos.bitboard_for(color, PieceType::Rook)).ipopcount();
    eval +=
      ROOK_SEMIOPEN_VAL * (half_open_files & pos.bitboard_for(color, PieceType::Rook)).ipopcount();

    eval += MINOR_BEHIND_PAWN
          * (ourminors.shift_relative(color, Direction::North)
             & (pos.bitboard_for(them, PieceType::Pawn) | pos.bitboard_for(color, PieceType::Pawn)))
              .ipopcount();

    const Bitboard strongly_defended =
      pos.attacked_by(color, PieceType::Pawn)
      | (pos.attacked_by_two_or_more(color) & ~pos.attacked_by_two_or_more(them));

    eval += RESTRICTED_SQUARES
          * (pos.attack_table(color).get_attacked_bitboard() & ~strongly_defended
             & pos.attack_table(them).get_attacked_bitboard())
              .ipopcount();

    return eval;
}

template<Color color>
PScore king_safety_activation(PScore& king_safety_score) {
    // Apply sigmoid activation to king safety score
    const PScore activated = KING_SAFETY_ACTIVATION(king_safety_score);
    return activated;
}

PScore apply_winnable(const Position& pos, PScore& score, usize phase) {

    const bool pawn_endgame = phase == 0;

    const Bitboard white_pawns = pos.bitboard_for(Color::White, PieceType::Pawn);
    const Bitboard black_pawns = pos.bitboard_for(Color::Black, PieceType::Pawn);

    const i32 pawn_count = (white_pawns | black_pawns).ipopcount();

    const Bitboard white_files = Bitboard::fill_verticals(white_pawns);
    const Bitboard black_files = Bitboard::fill_verticals(black_pawns);

    const i32 sym_files  = (white_files & black_files).ipopcount() / 8;
    const i32 asym_files = (white_files ^ black_files).ipopcount() / 8;

    const Score symmetry =
      static_cast<Score>(WINNABLE_SYM * sym_files + WINNABLE_ASYM * asym_files);

    Score winnable = static_cast<Score>(WINNABLE_PAWNS * pawn_count + symmetry
                                        + WINNABLE_PAWN_ENDGAME * pawn_endgame + WINNABLE_BIAS);

    if (score.eg() < 0) {
        winnable = static_cast<Score>(-winnable);
    }

    return score.complexity_add(winnable);
}

PScore apply_eg_scale(const Position& pos, PScore& eval, isize strong_phase, isize weak_phase) {
    // Strong pawn scaling
    const Color strong_side = eval.eg() > 0 ? Color::White : Color::Black;
    // Swap phases if we're in the weak side's perspective
    if (strong_side == Color::Black) {
        std::swap(strong_phase, weak_phase);
    }

    const isize strong_pawn_count = pos.ipiece_count(strong_side, PieceType::Pawn);

    // Pawnless position scaling: if our material advantage is very thin and we have no pawns, scale down the eval significantly, as trading can lead to KBK or KNK draws
    if (strong_pawn_count == 0) {
        if (strong_phase - weak_phase <= 1) {
            return eval.scale_eg<128>(strong_phase < 2 ? 0 : weak_phase <= 1 ? 8 : 28);
        }
    }

    const isize pcmul = 8 - strong_pawn_count;

    return eval.scale_eg<128>(static_cast<i32>(128 - pcmul * pcmul));  // 64 - 128
}


Score evaluate_white_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us          = pos.active_color();
    const isize white_phase = pos.ipiece_count(Color::White, PieceType::Knight)
                            + pos.ipiece_count(Color::White, PieceType::Bishop)
                            + pos.ipiece_count(Color::White, PieceType::Rook) * 2
                            + pos.ipiece_count(Color::White, PieceType::Queen) * 4;

    const isize black_phase = pos.ipiece_count(Color::Black, PieceType::Knight)
                            + pos.ipiece_count(Color::Black, PieceType::Bishop)
                            + pos.ipiece_count(Color::Black, PieceType::Rook) * 2
                            + pos.ipiece_count(Color::Black, PieceType::Queen) * 4;

    usize phase = std::min<usize>(white_phase + black_phase, 24);

    PScore eval = psqt_state.score();  // Used for linear components

    // pawn eval
    eval += evaluate_pawns<Color::White>(pos) - evaluate_pawns<Color::Black>(pos);

    // pieces & space
    const auto [wp, wc] = evaluate_pieces_and_checkers<Color::White>(pos);
    const auto [bp, bc] = evaluate_pieces_and_checkers<Color::Black>(pos);

    eval += wp - bp;
    eval += evaluate_outposts<Color::White>(pos) - evaluate_outposts<Color::Black>(pos);
    eval += evaluate_space<Color::White>(pos) - evaluate_space<Color::Black>(pos);

    // Threats
    eval += evaluate_threats<Color::White>(pos) - evaluate_threats<Color::Black>(pos);
    eval +=
      evaluate_pawn_push_threats<Color::White>(pos) - evaluate_pawn_push_threats<Color::Black>(pos);

    // King safety
    PScore white_king_attack_total = evaluate_king_safety<Color::Black>(pos) + wc;
    PScore black_king_attack_total = evaluate_king_safety<Color::White>(pos) + bc;

    // Nonlinear adjustment
    eval += king_safety_activation<Color::White>(white_king_attack_total)
          - king_safety_activation<Color::Black>(black_king_attack_total);

    eval += (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;

    // Winnable
    eval = apply_winnable(pos, eval, phase);

    // Eg scaling
    eval = apply_eg_scale(pos, eval, white_phase, black_phase);

    return static_cast<Score>(eval.phase<24>(static_cast<i32>(phase)));
};

Score evaluate_stm_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();
    return static_cast<Score>((us == Color::White) ? evaluate_white_pov(pos, psqt_state)
                                                   : -evaluate_white_pov(pos, psqt_state));
}

}  // namespace Clockwork
