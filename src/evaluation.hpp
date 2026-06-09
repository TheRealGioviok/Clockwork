#pragma once

#include "eval_types.hpp"
#include "position.hpp"
#include "psqt_state.hpp"
#include <array>

namespace Clockwork {


struct alignas(16) PawnCacheEntry {
    u32      key;           // Upper key
    PScore   pawn_score;    // Stored eval
    Bitboard passed_pawns;  // Grouped passers
};

static u64 mulhi64(u64 a, u64 b) {
    u128 result = static_cast<u128>(a) * static_cast<u128>(b);
    return static_cast<u64>(result >> 64);
}

static u32 shrink_key(HashKey key) {
    return static_cast<u32>(key);
}

// Pawn evaluation cache
class PawnEvalCache {
private:
    static constexpr usize CACHE_SIZE = 32768;  // 2^14 entries
    alignas(16) std::array<PawnCacheEntry, CACHE_SIZE> m_cache;

public:
    [[nodiscard]] std::optional<PawnCacheEntry> probe(HashKey pawn_key) const {
        const usize idx   = mulhi64(pawn_key, CACHE_SIZE);
        const auto  key   = shrink_key(pawn_key);
        const auto& entry = m_cache[idx];
        if (entry.key == key) {
            return entry;
        }
        return std::nullopt;
    }

    void store(HashKey pawn_key, PScore pawn_score, Bitboard passed_pawns) {
        const usize idx = mulhi64(pawn_key, CACHE_SIZE);
        m_cache[idx]    = {shrink_key(pawn_key), pawn_score, passed_pawns};
    }

    void clear() {
        for (auto& entry : m_cache) {
            entry.key = 0;
        }
    }
};

template<bool use_pawn_cache>
Score evaluate_stm_pov(const Position&  pos,
                       const PsqtState& psqt_state,
                       PawnEvalCache*   pawn_eval_cache);
template<bool use_pawn_cache>
Score evaluate_white_pov(const Position&  pos,
                         const PsqtState& psqt_state,
                         PawnEvalCache*   pawn_eval_cache);

inline Score evaluate_stm_pov(const Position& pos) {
    return evaluate_stm_pov<false>(pos, PsqtState{pos}, nullptr);
}
inline Score evaluate_white_pov(const Position& pos) {
    return evaluate_white_pov<false>(pos, PsqtState{pos}, nullptr);
}
static constexpr std::array<std::array<Bitboard, 8>, 2> king_flank = []() {
    std::array<std::array<Bitboard, 8>, 2> result{};

    // Queenside files (0-2), Center files (3-4), Kingside files (5-7)
    constexpr std::array<i32, 8> flank_start = {0, 0, 0, 2, 2, 4, 4, 4};
    constexpr std::array<i32, 8> flank_width = {4, 4, 4, 4, 4, 4, 4, 4};
    constexpr Bitboard           white_ranks = Bitboard::rank_mask(0) | Bitboard::rank_mask(1)
                                   | Bitboard::rank_mask(2) | Bitboard::rank_mask(3)
                                   | Bitboard::rank_mask(4);
    constexpr Bitboard black_ranks = Bitboard::rank_mask(3) | Bitboard::rank_mask(4)
                                   | Bitboard::rank_mask(5) | Bitboard::rank_mask(6)
                                   | Bitboard::rank_mask(7);

    for (usize file_idx = 0; file_idx < 8; file_idx++) {
        Bitboard flank{};
        for (i32 f = flank_start[file_idx]; f < flank_start[file_idx] + flank_width[file_idx];
             f++) {
            flank |= Bitboard::file_mask(f);
        }

        result[0][file_idx] = flank & white_ranks;
        result[1][file_idx] = flank & black_ranks;
    }

    return result;
}();

};  // namespace Clockwork
