#include "bitboard.hpp"
#include "util/types.hpp"

namespace Clockwork {

constexpr Bitboard NOT_A_FILE  = ~Bitboard::file_mask(0);
constexpr Bitboard NOT_H_FILE  = ~Bitboard::file_mask(7);
constexpr Bitboard NOT_AB_FILE = ~(Bitboard::file_mask(0) | Bitboard::file_mask(1));
constexpr Bitboard NOT_GH_FILE = ~(Bitboard::file_mask(6) | Bitboard::file_mask(7));

static inline Bitboard rookrook_attacks(Bitboard rooks, Bitboard occ) {
    Bitboard empty = ~occ;
    Bitboard attacks{0};


    {
        Bitboard gen  = rooks;
        Bitboard prop = empty;
        gen |= prop & (gen << 8);
        prop &= (prop << 8);
        gen |= prop & (gen << 16);
        prop &= (prop << 16);
        gen |= prop & (gen << 32);
        attacks |= gen << 8;
    }
    {
        Bitboard gen  = rooks;
        Bitboard prop = empty;
        gen |= prop & (gen >> 8);
        prop &= (prop >> 8);
        gen |= prop & (gen >> 16);
        prop &= (prop >> 16);
        gen |= prop & (gen >> 32);
        attacks |= gen >> 8;
    }
    {
        Bitboard gen  = rooks;
        Bitboard prop = empty & NOT_H_FILE;
        gen |= prop & (gen << 1);
        prop &= (prop << 1);
        gen |= prop & (gen << 2);
        prop &= (prop << 2);
        gen |= prop & (gen << 4);
        attacks |= (gen << 1) & NOT_A_FILE;
    }
    {
        Bitboard gen  = rooks;
        Bitboard prop = empty & NOT_A_FILE;
        gen |= prop & (gen >> 1);
        prop &= (prop >> 1);
        gen |= prop & (gen >> 2);
        prop &= (prop >> 2);
        gen |= prop & (gen >> 4);
        attacks |= (gen >> 1) & NOT_H_FILE;
    }

    return attacks & ~occ;
}

static inline Bitboard bishopbishop_attacks(Bitboard bishops, Bitboard occ) {
    Bitboard empty = ~occ;
    Bitboard attacks{};

    {
        Bitboard gen  = bishops;
        Bitboard prop = empty & NOT_H_FILE;
        gen |= prop & (gen << 9);
        prop &= (prop << 9);
        gen |= prop & (gen << 18);
        prop &= (prop << 18);
        gen |= prop & (gen << 36);
        attacks |= (gen << 9) & NOT_A_FILE;
    }
    {
        Bitboard gen  = bishops;
        Bitboard prop = empty & NOT_A_FILE;
        gen |= prop & (gen << 7);
        prop &= (prop << 7);
        gen |= prop & (gen << 14);
        prop &= (prop << 14);
        gen |= prop & (gen << 28);
        attacks |= (gen << 7) & NOT_H_FILE;
    }
    {
        Bitboard gen  = bishops;
        Bitboard prop = empty & NOT_H_FILE;
        gen |= prop & (gen >> 7);
        prop &= (prop >> 7);
        gen |= prop & (gen >> 14);
        prop &= (prop >> 14);
        gen |= prop & (gen >> 28);
        attacks |= (gen >> 7) & NOT_A_FILE;
    }
    {
        Bitboard gen  = bishops;
        Bitboard prop = empty & NOT_A_FILE;
        gen |= prop & (gen >> 9);
        prop &= (prop >> 9);
        gen |= prop & (gen >> 18);
        prop &= (prop >> 18);
        gen |= prop & (gen >> 36);
        attacks |= (gen >> 9) & NOT_H_FILE;
    }

    return attacks & ~occ;
}

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
