#pragma once

#include "bitboard.hpp"
#include "square.hpp"
#include "util/types.hpp"

namespace Clockwork {

// Pawn-structure classification for the auxiliary structure-conditioned PSQT term.
enum class StructBucket : u8 {
    LockedChain      = 0,  // own d+e pawns locked in a diagonal ram chain (KID/French)
    CenterDeficitOwn = 1,  // d-pawn center imbalance (missing side)
    CenterDeficitOpp = 2,  // d-pawn center imbalance (full side)
    OpenCenter       = 3,  // no pawns of either color on the d/e files
    None             = 4,
};

inline constexpr usize NUM_STRUCT_BUCKETS = 4;

struct StructInfo {
    StructBucket bucket = StructBucket::None;
    bool         flip   = false;
    // Fianchetto complexes
    bool fian_g3   = false;  // own pawn on relative g3
    bool fian_b3   = false;  // own pawn on relative b3
    bool king_side = false;  // own king on files e-h
};

[[nodiscard]] inline Bitboard flip_vertical(Bitboard bb) {
    return Bitboard{__builtin_bswap64(bb.value())};
}

[[nodiscard]] inline StructInfo classify_structure(Bitboard own, Bitboard opp, bool own_king_side) {
    constexpr Bitboard file_d = Bitboard::file_mask(3);
    constexpr Bitboard file_e = Bitboard::file_mask(4);
    constexpr Bitboard g3_sq  = Bitboard::from_square(Square::from_file_and_rank(6, 2));
    constexpr Bitboard b3_sq  = Bitboard::from_square(Square::from_file_and_rank(1, 2));

    StructInfo info;
    info.fian_g3   = (own & g3_sq).any();
    info.fian_b3   = (own & b3_sq).any();
    info.king_side = own_king_side;

    const bool own_d = (own & file_d).any();
    const bool own_e = (own & file_e).any();
    const bool opp_d = (opp & file_d).any();
    const bool opp_e = (opp & file_e).any();

    // 1) LockedChain: both center files rammed, rammed pawns on different ranks mirrored wrt chain head.
    const Bitboard rams   = own & opp.shift(Direction::South);
    const Bitboard d_rams = rams & file_d;
    const Bitboard e_rams = rams & file_e;
    if (d_rams.any() && e_rams.any()) {
        const i32 d_rank = d_rams.msb().rank();
        const i32 e_rank = e_rams.msb().rank();
        if (d_rank != e_rank) {
            info.bucket = StructBucket::LockedChain;
            info.flip   = d_rank > e_rank;
            return info;
        }
    } 

    // 2/3) Center imbalance: one side misses a center pawn while the other keeps both
    if (opp_d && opp_e && (!own_d || !own_e)) {
        info.bucket = StructBucket::CenterDeficitOwn;
        info.flip   = own_d;  // own_d implies the e-pawn is the missing one
        return info;
    }
    if (own_d && own_e && (!opp_d || !opp_e)) {
        info.bucket = StructBucket::CenterDeficitOpp;
        info.flip   = opp_d;
        return info;
    }

    // 4) Open Center (d and e)
    if (!own_d && !own_e && !opp_d && !opp_e) {
        info.bucket = StructBucket::OpenCenter;
        info.flip   = own_king_side;
        return info;
    }

    return info;
}

}  // namespace Clockwork
