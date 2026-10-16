#include "psqt.hpp"
#include <algorithm>
#include <bit>
#include <cstdlib>

namespace Clockwork {

// PSQ^T (transposed psq tables) implementation
// The idea is to have a the psq score be assigned not as a simple pointwise op, but also as a "diffusion" over squares in mobility

// Blend weight selector
const std::array<PParam, 64>& psqt_table(usize blend_index) {
    switch (blend_index) {
    case PSQT_BLEND_KNIGHT:
        return KNIGHT_PSQT;
    case PSQT_BLEND_BISHOP:
        return BISHOP_PSQT;
    case PSQT_BLEND_ROOK:
        return ROOK_PSQT;
    default:
        return QUEEN_PSQT;
    }
}

#ifndef EVAL_TUNING

namespace {

struct Centered {
    i64 mg = 0;
    i64 eg = 0;
};

// Per-square contribution BLEND_t * (64 * PSQT_t[sq] - sum(PSQT_t)) stored as fp
std::array<Centered, 64> centered_plane(usize blend_index) {
    const std::array<PParam, 64>& table = psqt_table(blend_index);
    const PParam                  blend = PSQT_MOBILITY_BLEND[blend_index];

    Centered total;
    for (const PParam& p : table) {
        total.mg += p.mg();
        total.eg += p.eg();
    }

    std::array<Centered, 64> plane;
    for (usize sq = 0; sq < 64; ++sq) {
        plane[sq].mg = blend.mg() * (64 * i64{table[sq].mg()} - total.mg);
        plane[sq].eg = blend.eg() * (64 * i64{table[sq].eg()} - total.eg);
    }
    return plane;
}

}  // namespace

const PsqtPlaneSet PSQT_PLANES = [] {
    std::array<std::array<Centered, 64>, 4> centered;
    i64                                     max_abs = 0;
    for (usize i = 0; i < 4; ++i) {
        centered[i] = centered_plane(i);
        for (const Centered& c : centered[i]) {
            max_abs = std::max({max_abs, std::abs(c.mg), std::abs(c.eg)});
        }
    }

    PsqtPlaneSet set;
    set.shift = std::max(0, static_cast<i32>(std::bit_width(static_cast<u64>(max_abs))) - 7);
    assert(set.shift <= 16);
    const i64  half     = set.shift ? i64{1} << (set.shift - 1) : 0;
    const auto quantise = [&](i64 value) {
        return static_cast<i8>((value + half) >> set.shift);
    };

    for (usize i = 0; i < 4; ++i) {
        for (usize f = 0; f < PSQT_FLIPS.size(); ++f) {
            PsqtPlane& plane = set.planes[i][f];
            for (usize sq = 0; sq < 64; ++sq) {
                const Centered& c                  = centered[i][sq ^ PSQT_FLIPS[f]];
                plane[psqt_plane_index(sq, false)] = quantise(c.mg);
                plane[psqt_plane_index(sq, true)]  = quantise(c.eg);
            }
        }
    }
    return set;
}();

#else
// TODO: this can be done with mm in tuner but requires a decent tuner overhaul
PScore psqt_total_handle(usize blend_index) {
    thread_local std::array<PScore, 4> totals;
    thread_local usize                 generation = static_cast<usize>(-1);
    if (generation != Autograd::Graph::get().generation()) {
        generation = Autograd::Graph::get().generation();
        for (usize i = 0; i < 4; ++i) {
            PScore total = PSCORE_ZERO;
            for (const PParam& p : psqt_table(i)) {
                total += p;
            }
            totals[i] = total;
        }
    }
    return totals[blend_index];
}

#endif

}  // namespace Clockwork
