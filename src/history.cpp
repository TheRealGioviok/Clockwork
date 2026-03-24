#include "history.hpp"
#include "position.hpp"
#include "search.hpp"

namespace Clockwork {

i32 History::get_conthist(const Position& pos, Move move, i32 ply, Search::Stack* ss) const {
    const usize stm_idx = static_cast<usize>(pos.active_color());
    const usize pt_idx =
      static_cast<usize>(pos.piece_at(move.from())) - static_cast<usize>(PieceType::Pawn);
    const usize to = move.to().raw;

    i32 stats = 0;
    if (ply >= 1 && (ss - 1)->cont_hist_entry) {
        stats += (*(ss - 1)->cont_hist_entry)[stm_idx][pt_idx][to];
    }
    if (ply >= 2 && (ss - 2)->cont_hist_entry) {
        stats += (*(ss - 2)->cont_hist_entry)[stm_idx][pt_idx][to];
    }
    if (ply >= 4 && (ss - 4)->cont_hist_entry) {
        stats += (*(ss - 4)->cont_hist_entry)[stm_idx][pt_idx][to];
    }
    if (ply >= 6 && (ss - 6)->cont_hist_entry) {
        stats += (*(ss - 6)->cont_hist_entry)[stm_idx][pt_idx][to];
    }
    return stats;
}

i32 History::get_quiet_stats(const Position& pos, Move move, i32 ply, Search::Stack* ss) const {
    const auto  to_attacked   = pos.is_square_attacked_by(move.to(), ~pos.active_color());
    const auto  from_attacked = pos.is_square_attacked_by(move.from(), ~pos.active_color());
    const usize stm_idx       = static_cast<usize>(pos.active_color());

    i32 stats = m_main_hist[stm_idx][move.from_to()][from_attacked * 2 + to_attacked];
    stats += 2 * get_conthist(pos, move, ply, ss);
    return stats;
}

void History::update_cont_hist(
  const Position& pos, Move move, i32 ply, Search::Stack* ss, i32 bonus) {
    const i32   conthist = get_conthist(pos, move, ply, ss);
    const usize pt_idx =
      static_cast<usize>(pos.piece_at(move.from())) - static_cast<usize>(PieceType::Pawn);
    const usize stm_idx = static_cast<usize>(pos.active_color());
    const usize to      = move.to().raw;

    if (ply >= 1 && (ss - 1)->cont_hist_entry) {
        update_hist_entry_banger((*(ss - 1)->cont_hist_entry)[stm_idx][pt_idx][to], conthist,
                                 bonus);
    }
    if (ply >= 2 && (ss - 2)->cont_hist_entry) {
        update_hist_entry_banger((*(ss - 2)->cont_hist_entry)[stm_idx][pt_idx][to], conthist,
                                 bonus);
    }

    // Updates past ply 2 only when not in check
    if (!pos.is_in_check()) {
        if (ply >= 4 && (ss - 4)->cont_hist_entry) {
            update_hist_entry_banger((*(ss - 4)->cont_hist_entry)[stm_idx][pt_idx][to], conthist,
                                     bonus);
        }
        if (ply >= 6 && (ss - 6)->cont_hist_entry) {
            update_hist_entry_banger((*(ss - 6)->cont_hist_entry)[stm_idx][pt_idx][to], conthist,
                                     bonus);
        }
    }
}

void History::update_quiet_stats(
  const Position& pos, Move move, i32 ply, Search::Stack* ss, i32 bonus) {
    const auto  to_attacked   = pos.is_square_attacked_by(move.to(), ~pos.active_color());
    const auto  from_attacked = pos.is_square_attacked_by(move.from(), ~pos.active_color());
    const usize stm_idx       = static_cast<usize>(pos.active_color());

    update_hist_entry(m_main_hist[stm_idx][move.from_to()][from_attacked * 2 + to_attacked], bonus);
    update_cont_hist(pos, move, ply, ss, bonus / 2);
}

i32 History::get_noisy_stats(const Position& pos, Move move) const {
    const usize stm_idx = static_cast<usize>(pos.active_color());
    const usize pt_idx =
      static_cast<usize>(pos.piece_at(move.from())) - static_cast<usize>(PieceType::Pawn);
    const PieceType captured = move.is_en_passant() ? PieceType::Pawn : pos.piece_at(move.to());
    return m_capt_hist[stm_idx][pt_idx][static_cast<usize>(captured)][move.to().raw];
}

void History::update_noisy_stats(const Position& pos, Move move, i32 bonus) {
    const usize stm_idx = static_cast<usize>(pos.active_color());
    const usize pt_idx =
      static_cast<usize>(pos.piece_at(move.from())) - static_cast<usize>(PieceType::Pawn);
    const PieceType captured = move.is_en_passant() ? PieceType::Pawn : pos.piece_at(move.to());
    update_hist_entry(m_capt_hist[stm_idx][pt_idx][static_cast<usize>(captured)][move.to().raw],
                      bonus);
}

void History::prefetch_corrhists(const Position& pos) const {
    const usize side_index = static_cast<usize>(pos.active_color());

    prefetch(&m_pawn_corr_hist[side_index][pos.get_pawn_key() % CORRECTION_HISTORY_ENTRY_NB]);
    prefetch(
      &m_non_pawn_corr_hist[0][pos.get_non_pawn_key(Color::White) % CORRECTION_HISTORY_ENTRY_NB]);
    prefetch(
      &m_non_pawn_corr_hist[1][pos.get_non_pawn_key(Color::Black) % CORRECTION_HISTORY_ENTRY_NB]);
    prefetch(&m_major_corr_hist[side_index][pos.get_major_key() % CORRECTION_HISTORY_ENTRY_NB]);
    prefetch(&m_minor_corr_hist[side_index][pos.get_minor_key() % CORRECTION_HISTORY_ENTRY_NB]);
}

void History::update_correction_history(const Position& pos, i32 depth, i32 diff) {
    const usize side = static_cast<usize>(pos.active_color());
    const usize pawn = static_cast<usize>(pos.get_pawn_key() % CORRECTION_HISTORY_ENTRY_NB);
    const usize white_np =
      static_cast<usize>(pos.get_non_pawn_key(Color::White) % CORRECTION_HISTORY_ENTRY_NB);
    const usize black_np =
      static_cast<usize>(pos.get_non_pawn_key(Color::Black) % CORRECTION_HISTORY_ENTRY_NB);
    const usize major = static_cast<usize>(pos.get_major_key() % CORRECTION_HISTORY_ENTRY_NB);
    const usize minor = static_cast<usize>(pos.get_minor_key() % CORRECTION_HISTORY_ENTRY_NB);

    const i32 new_weight  = std::min(16, 1 + depth);
    const i32 scaled_diff = diff * CORRECTION_HISTORY_GRAIN;

    auto update_entry = [=](i32& entry) {
        i32 update =
          entry * (CORRECTION_HISTORY_WEIGHT_SCALE - new_weight) + scaled_diff * new_weight;
        entry = std::clamp(update / CORRECTION_HISTORY_WEIGHT_SCALE, -CORRECTION_HISTORY_MAX,
                           CORRECTION_HISTORY_MAX);
    };

    update_entry(m_pawn_corr_hist[side][pawn]);
    update_entry(m_non_pawn_corr_hist[0][side][white_np]);
    update_entry(m_non_pawn_corr_hist[1][side][black_np]);
    update_entry(m_major_corr_hist[side][major]);
    update_entry(m_minor_corr_hist[side][minor]);
}

i32 History::get_correction(const Position& pos) const {
    const usize side = static_cast<usize>(pos.active_color());
    const usize pawn = static_cast<usize>(pos.get_pawn_key() % CORRECTION_HISTORY_ENTRY_NB);
    const usize white_np =
      static_cast<usize>(pos.get_non_pawn_key(Color::White) % CORRECTION_HISTORY_ENTRY_NB);
    const usize black_np =
      static_cast<usize>(pos.get_non_pawn_key(Color::Black) % CORRECTION_HISTORY_ENTRY_NB);
    const usize major = static_cast<usize>(pos.get_major_key() % CORRECTION_HISTORY_ENTRY_NB);
    const usize minor = static_cast<usize>(pos.get_minor_key() % CORRECTION_HISTORY_ENTRY_NB);

    i32 correction = 0;
    correction += m_pawn_corr_hist[side][pawn];
    correction += m_non_pawn_corr_hist[0][side][white_np];
    correction += m_non_pawn_corr_hist[1][side][black_np];
    correction += m_major_corr_hist[side][major];
    correction += m_minor_corr_hist[side][minor];
    return correction / CORRECTION_HISTORY_GRAIN;
}

void History::clear() {
    std::memset(&m_main_hist, 0, sizeof(MainHistory));
    std::memset(&m_cont_hist, 0, sizeof(ContHistory));
    std::memset(&m_capt_hist, 0, sizeof(CaptHistory));
    std::memset(&m_pawn_corr_hist, 0, sizeof(CorrectionHistory));
    std::memset(&m_non_pawn_corr_hist[0], 0, sizeof(CorrectionHistory));
    std::memset(&m_non_pawn_corr_hist[1], 0, sizeof(CorrectionHistory));
    std::memset(&m_major_corr_hist, 0, sizeof(CorrectionHistory));
    std::memset(&m_minor_corr_hist, 0, sizeof(CorrectionHistory));
}

}  // namespace Clockwork
