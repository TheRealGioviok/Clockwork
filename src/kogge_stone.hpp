#include "bitboard.hpp"
#include "util/types.hpp"

namespace Clockwork {

constexpr Bitboard NOT_A_FILE  = ~Bitboard::file_mask(0);
constexpr Bitboard NOT_H_FILE  = ~Bitboard::file_mask(7);
constexpr Bitboard NOT_AB_FILE = ~(Bitboard::file_mask(0) | Bitboard::file_mask(1));
constexpr Bitboard NOT_GH_FILE = ~(Bitboard::file_mask(6) | Bitboard::file_mask(7));


static inline Bitboard knightknight_attacks(Bitboard knights, Bitboard occ) {

    // Horizontal then Vertical split optimization
    Bitboard l1 = (knights >> 1) & NOT_H_FILE;
    Bitboard l2 = (knights >> 2) & NOT_GH_FILE;
    Bitboard r1 = (knights << 1) & NOT_A_FILE;
    Bitboard r2 = (knights << 2) & NOT_AB_FILE;

    Bitboard h1 = l1 | r1;
    Bitboard h2 = l2 | r2;

    Bitboard attacks = (h1 << 16) | (h1 >> 16) | (h2 << 8) | (h2 >> 8);

    return attacks & ~occ;
}

};  // namespace Clockwork
