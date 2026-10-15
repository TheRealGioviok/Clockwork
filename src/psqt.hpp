#pragma once

#include "bitboard.hpp"
#include "eval_constants.hpp"
#include "eval_types.hpp"
#include "square.hpp"
#include "util/types.hpp"
#include <array>
#include <bit>

namespace Clockwork {


// PSQ^T (transposed psq tables) implementation
// The idea is to have a the psq score be assigned not as a simple pointwise op, but also as a "diffusion" over squares in mobility

// for every square t in a piece's mobility set, the piece receives
//      BLEND_pt * (PSQT_pt[t] - mean(PSQT_pt)).
// over the reachable squares of all pieces of one type this becomrs
//      BLEND * (64 * sum(PSQT[t]) - count * sum(PSQT)) / PSQT_BLEND_DENOM.


constexpr usize PSQT_BLEND_KNIGHT = 0;
constexpr usize PSQT_BLEND_BISHOP = 1;
constexpr usize PSQT_BLEND_ROOK   = 2;
constexpr usize PSQT_BLEND_QUEEN  = 3;

constexpr i64 PSQT_BLEND_DENOM = 64 * 1024;

const std::array<PParam, 64>& psqt_table(usize blend_index);

#ifndef EVAL_TUNING

using PsqtPlane = std::array<i8, 128>;

constexpr usize psqt_plane_index(usize sq, bool endgame) {
    // which 32-byte half of the count vector
    const usize half = sq / 32;
    // 128-bit lane within that half
    const usize lane = (sq % 32) / 16;
    // zip_low (squares 0-7 of the lane) or zip_high
    const usize low   = (sq % 16) < 8;
    const usize pair  = (sq % 8) / 2;
    const usize block = (low ? 0 : 2) + half;
    return 32 * block + 16 * lane + 4 * pair + (endgame ? 2 : 0) + (sq & 1);
}

// flips (file x ranks)
constexpr std::array<u8, 4> PSQT_FLIPS = {0, 7, 56, 63};

constexpr usize psqt_flip_index(u8 flip) {
    return static_cast<usize>((flip & 7 ? 1 : 0) | (flip & 56 ? 2 : 0));
}

struct PsqtPlaneSet {
    // [blend_index][psqt_flip_index(flip)]
    alignas(32) std::array<std::array<PsqtPlane, 4>, 4> planes;
    // fp shift
    i32 shift;
};

extern const PsqtPlaneSet PSQT_PLANES;

// selectors
inline const u8x64 PSQT_BYTE_SELECT = [] {
    std::array<u8, 64> a{};
    for (usize sq = 0; sq < 64; ++sq) {
        a[sq] = static_cast<u8>(sq / 8);  // which mask byte holds this square
    }
    return u8x64{a};
}();
inline const u8x64 PSQT_BIT_SELECT = [] {
    std::array<u8, 64> a{};
    for (usize sq = 0; sq < 64; ++sq) {
        a[sq] = static_cast<u8>(1 << (sq % 8));  // which bit of that byte is this square
    }
    return u8x64{a};
}();

// Sum of adjacent unsigned-byte times signed-byte products into i16 lanes (vpmaddubsw)
inline i16x32 psqt_maddubs(const u8x64& counts, const i8x64& plane) {
    #if LPS_AVX512
    return i16x32{_mm512_maddubs_epi16(counts.raw, plane.raw)};
    #elif LPS_AVX2
    i16x32 result;
    result.raw[0] = i16x16{_mm256_maddubs_epi16(counts.raw[0].raw, plane.raw[0].raw)};
    result.raw[1] = i16x16{_mm256_maddubs_epi16(counts.raw[1].raw, plane.raw[1].raw)};
    return result;
    #else
    const std::array<u8, 64> c = counts.to_array();
    const std::array<i8, 64> p = plane.to_array();
    std::array<i16, 32>      r{};
    for (usize i = 0; i < 32; ++i) {
        r[i] = static_cast<i16>(c[2 * i] * p[2 * i] + c[2 * i + 1] * p[2 * i + 1]);
    }
    return i16x32{r};
    #endif
}

// Accumulates, per square, how many pieces of the current type reach it
struct PsqtMobilityAccumulator {
    explicit PsqtMobilityAccumulator(u8 flip) :
        m_flip_index(psqt_flip_index(flip)) {
    }

    // u64 to u8x64 (bitboard to byte counts)
    void add(Bitboard reach) {
        // 16-byte source for the byte shuffle (only the first 8 bytes matter).
        const u8x16 mask  = std::bit_cast<u8x16>(std::array<u64, 2>{reach.value(), reach.value()});
        const u8x64 bytes = PSQT_BYTE_SELECT.swizzle(mask);
        // Keep bit i % 8 and compare, sub since it returns -1 or 0
        m_counts -=
          std::bit_cast<u8x64>((bytes & PSQT_BIT_SELECT).eq_vm(PSQT_BIT_SELECT).to_vector());
        m_dirty = true;
    }

    // Actually apply the psqtscores (counts x plane) for one piece type
    void flush(usize blend_index) {
        if (!m_dirty) {
            // Early exit if no update for the current index
            return;
        }
        const PsqtPlane& plane = PSQT_PLANES.planes[blend_index][m_flip_index];
        // [c_a, c_b] -> [c_a, c_b, c_a, c_b]
        const u16x32 pairs = std::bit_cast<u16x32>(m_counts);
        const u8x64  low   = std::bit_cast<u8x64>(pairs.zip_low_128lanes(pairs));
        const u8x64  high  = std::bit_cast<u8x64>(pairs.zip_high_128lanes(pairs));
        // [c_a, c_b, c_a, c_b] . [mg_a, mg_b, eg_a, eg_b] with adjacent products summed -> one mg lane and one eg lane per square pair
        m_acc += psqt_maddubs(low, i8x64::load(plane.data()));
        m_acc += psqt_maddubs(high, i8x64::load(plane.data() + 64));
        m_counts = u8x64::zero();
        m_dirty  = false;
    }

    // reduce the packed lanes to score
    PScore score() const {
        const i32x16 packed = std::bit_cast<i32x16>(m_acc);
        const i32    mg     = packed.shl<16>().shr<16>().reduce_add();
        const i32    eg     = packed.shr<16>().reduce_add();
        // The remaining part of the / PSQT_BLEND_DENOM not already folded into the planes
        const i32 shift = 16 - PSQT_PLANES.shift;
        return PScore(static_cast<Score>(mg >> shift), static_cast<Score>(eg >> shift));
    }

private:
    u8x64  m_counts = u8x64::zero();
    i16x32 m_acc    = i16x32::zero();
    bool   m_dirty  = false;
    usize  m_flip_index;
};

#else

// Tuner version is trivial loop sum
// TODO: this can definitely be done with standard mm and become quite faster
PScore psqt_total_handle(usize blend_index);

struct PsqtMobilityAccumulator {
    explicit PsqtMobilityAccumulator(u8 flip) :
        m_flip(flip) {
    }

    void add(Bitboard reach) {
        m_pending[m_pending_count++] = reach;
    }

    void flush(usize blend_index) {
        if (m_pending_count == 0) {
            return;
        }
        const std::array<PParam, 64>& table = psqt_table(blend_index);
        PScore                        sum   = PSCORE_ZERO;
        i64                           count = 0;
        for (usize i = 0; i < m_pending_count; ++i) {
            count += static_cast<i64>(m_pending[i].popcount());
            for (Square sq : m_pending[i]) {
                sum += table[static_cast<usize>(sq.raw ^ m_flip)];
            }
        }
        m_pending_count    = 0;
        const PScore blend = PSQT_MOBILITY_BLEND[blend_index];
        const PScore centered =
          sum * 64.0 - psqt_total_handle(blend_index) * static_cast<f64>(count);
        m_eval += (blend * centered) / static_cast<f64>(PSQT_BLEND_DENOM);
    }

    PScore score() const {
        return m_eval;
    }

private:
    // Reach sets of the current type, applied on flush once the type is known.
    std::array<Bitboard, 16> m_pending{};
    usize                    m_pending_count = 0;
    PScore                   m_eval          = PSCORE_ZERO;
    u8                       m_flip;
};

#endif

}  // namespace Clockwork
