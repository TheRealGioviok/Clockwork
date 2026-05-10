#include "bitboard.hpp"
#include "util/types.hpp"
#include <lps/lps.hpp>
#include <utility>
#ifdef LPS_AVX512
    #include <immintrin.h>
#endif

namespace Clockwork {

using namespace lps::prelude;
using u64x4 = vector<u64, 4>;

constexpr Bitboard NOT_A_FILE  = ~Bitboard::file_mask(0);
constexpr Bitboard NOT_H_FILE  = ~Bitboard::file_mask(7);
constexpr Bitboard NOT_AB_FILE = ~(Bitboard::file_mask(0) | Bitboard::file_mask(1));
constexpr Bitboard NOT_GH_FILE = ~(Bitboard::file_mask(6) | Bitboard::file_mask(7));

constexpr u64 A  = Bitboard::file_mask(0).value();
constexpr u64 B  = Bitboard::file_mask(1).value();
constexpr u64 G  = Bitboard::file_mask(6).value();
constexpr u64 H  = Bitboard::file_mask(7).value();
constexpr u64 R1 = Bitboard::rank_mask(0).value();
constexpr u64 R2 = Bitboard::rank_mask(1).value();
constexpr u64 R7 = Bitboard::rank_mask(6).value();
constexpr u64 R8 = Bitboard::rank_mask(7).value();

template<bool orth1, bool orth2>
static inline std::pair<Bitboard, Bitboard>
sliders_setwise(Bitboard src1, Bitboard src2, Bitboard occ) {
#ifdef LPS_AVX512
    auto shift1 = _mm512_setr_epi64(orth1 ? 8 : 7, orth1 ? 1 : 9, orth1 ? -8 : -7, orth1 ? -1 : -9,
                                    orth2 ? 8 : 7, orth2 ? 1 : 9, orth2 ? -8 : -7, orth2 ? -1 : -9);
    auto shift2 = _mm512_add_epi64(shift1, shift1);
    auto shift4 = _mm512_add_epi64(shift2, shift2);

    auto mask = _mm512_setr_epi64(orth1 ? R1 : R1 | H, orth1 ? A : R1 | A, orth1 ? R8 : R8 | A,
                                  orth1 ? H : R8 | H, orth2 ? R1 : R1 | H, orth2 ? A : R1 | A,
                                  orth2 ? R8 : R8 | A, orth2 ? H : R8 | H);
    auto gen   = _mm512_setr_epi64(src1.value(), src1.value(), src1.value(), src1.value(),
                                   src2.value(), src2.value(), src2.value(), src2.value());
    auto block = _mm512_or_si512(mask, _mm512_set1_epi64(occ.value()));

    // 242 <=> a | (!b & c)
    gen   = _mm512_ternarylogic_epi64(gen, block, _mm512_rolv_epi64(gen, shift1), 242);
    block = _mm512_or_si512(block, _mm512_rolv_epi64(block, shift1));

    gen   = _mm512_ternarylogic_epi64(gen, block, _mm512_rolv_epi64(gen, shift2), 242);
    block = _mm512_or_si512(block, _mm512_rolv_epi64(block, shift2));

    gen = _mm512_ternarylogic_epi64(gen, block, _mm512_rolv_epi64(gen, shift4), 242);

    // 2 <=> !a & !b & c
    gen = _mm512_andnot_si512(mask, _mm_rolv_epi64(gen, shift1));

    auto attacks1 = u64x4{_mm512_castsi512_si256(gen)}.reduce_or();
    auto attacks2 = u64x4{_mm512_extracti64x4_epi64(gen, 1)}.reduce_or();

    return {Bitboard{attacks1}, Bitboard{attacks2}};
#else
    u64x4 shift1{std::array<u64, 4>{orth1 ? 8 : 7, orth1 ? 1 : 9, orth2 ? 8 : 7, orth2 ? 1 : 9}};
    u64x4 shift2 = shift1 + shift1;
    u64x4 shift4 = shift2 + shift2;

    constexpr u64x4 filemask1{std::array<u64, 4>{orth1 ? 0 : A, H, orth2 ? 0 : A, H}};
    constexpr u64x4 filemask2{std::array<u64, 4>{orth1 ? 0 : H, A, orth2 ? 0 : H, A}};

    u64x4 gen1{std::array{src1.value(), src1.value(), src2.value(), src2.value()}};
    u64x4 block1 = filemask1 | u64x4::splat(occ.value());

    u64x4 gen2   = gen1;
    u64x4 block2 = filemask2 | u64x4::splat(occ.value());

    gen1 |= (gen1 >> shift1) & ~block1;
    gen2 |= (gen2 << shift1) & ~block2;

    block1 |= block1 >> shift1;
    block2 |= block2 << shift1;

    gen1 |= (gen1 >> shift2) & ~block1;
    gen2 |= (gen2 << shift2) & ~block2;

    block1 |= block1 >> shift2;
    block2 |= block2 << shift2;

    gen1 |= (gen1 >> shift4) & ~block1;
    gen2 |= (gen2 << shift4) & ~block2;

    gen1 = (gen1 >> shift1) & ~filemask1;
    gen2 = (gen2 << shift1) & ~filemask2;

    u64x4 attacks1 = u64x4{std::array<u64, 4>{0, 1, 4, 5}}.swizzle(gen1, gen2);
    u64x4 attacks2 = u64x4{std::array<u64, 4>{2, 3, 6, 7}}.swizzle(gen1, gen2);

    return {Bitboard{attacks1.reduce_or()}, Bitboard{attacks2.reduce_or()}};
#endif
}

static inline std::pair<Bitboard, Bitboard>
rookbishop_setwise(Bitboard rooks, Bitboard bishops, Bitboard occ) {
    return sliders_setwise<true, false>(rooks, bishops, occ);
}

static inline std::pair<Bitboard, Bitboard>
rookrook_setwise(Bitboard rooks1, Bitboard rooks2, Bitboard occ) {
    return sliders_setwise<true, true>(rooks1, rooks2, occ);
}

static inline std::pair<Bitboard, Bitboard>
bishopbishop_setwise(Bitboard bishops1, Bitboard bishops2, Bitboard occ) {
    return sliders_setwise<false, false>(bishops1, bishops2, occ);
}

static inline Bitboard queens_setwise(Bitboard queens, Bitboard occ) {
    auto [rook_attacks, bishop_attacks] = sliders_setwise<true, false>(queens, queens, occ);
    return rook_attacks | bishop_attacks;
}

static inline Bitboard rooks_setwise(Bitboard rooks, Bitboard occ) {
    return rookbishop_setwise(rooks, rooks, occ).first;
}

static inline Bitboard bishops_setwise(Bitboard bishops, Bitboard occ) {
    return rookbishop_setwise(bishops, bishops, occ).second;
}

static inline Bitboard knights_setwise(Bitboard knights) {
#ifdef LPS_AVX512
    // knight moves are done clockwise, starting at wnw.
    auto rotates = _mm512_setr_epi64(6, 15, 17, 10, -6, -15, -17, -10);
    // mask containing the files+ranks that need to be removed for each shift
    // (e.g. a knight that is on files a or b or on rank 8 cannot move wnw).
    auto mask    = _mm512_setr_epi64(A | B | R8, A | R7 | R8, H | R7 | R8, G | H | R8, G | H | R1,
                                     H | R1 | R2, A | R1 | R2, A | B | R1);
    auto attacks = _mm512_reduce_or_epi64(
      _mm512_rolv_epi64(_mm512_andnot_si512(mask, _mm512_set1_epi64(knights.value())), rotates));
    return Bitboard{static_cast<u64>(attacks)};
#else
    u64x4 filemask1{std::array{A | B, A, H, G | H}};
    u64x4 filemask2{std::array{G | H, H, A, A | B}};
    u64x4 shifts{std::array<u64, 4>{6, 15, 17, 10}};
    auto  sq = u64x4::splat(knights.value());
    auto  lo = (sq & ~filemask1) << shifts;
    auto  hi = (sq & ~filemask2) >> shifts;

    return Bitboard{(lo | hi).reduce_or()};
#endif
}

};  // namespace Clockwork
