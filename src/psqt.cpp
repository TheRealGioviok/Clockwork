#include "psqt.hpp"
#include <algorithm>
#include <bit>
#include <cstdlib>

namespace Clockwork {

// PSQ^T (transposed psq tables) implementation
// The idea is to have a the psq score be assigned not as a simple pointwise op, but also as a "diffusion" over squares in mobility

// Table entry for a square
const PParam& mobility_psqt(usize blend_index, usize flipped_sq) {
    return MOBILITY_PSQT[blend_index][psqt_mirror_index(flipped_sq)];
}

#ifndef EVAL_TUNING

namespace {

struct Centered {
    i64 mg = 0;
    i64 eg = 0;
};

// Per-square contribution MOBILITY_PSQT_t[mirror(sq)]
std::array<Centered, 64> centered_plane(usize blend_index) {
    std::array<Centered, 64> plane;
    for (usize sq = 0; sq < 64; ++sq) {
        const PParam& p = mobility_psqt(blend_index, sq);
        plane[sq].mg    = p.mg();
        plane[sq].eg    = p.eg();
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

#endif

}  // namespace Clockwork
