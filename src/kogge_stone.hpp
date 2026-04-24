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
    Bitboard attacks{};

    attacks |= (knights << 17) & NOT_A_FILE;
    attacks |= (knights << 15) & NOT_H_FILE;
    attacks |= (knights << 10) & NOT_AB_FILE;
    attacks |= (knights << 6) & NOT_GH_FILE;

    attacks |= (knights >> 17) & NOT_H_FILE;
    attacks |= (knights >> 15) & NOT_A_FILE;
    attacks |= (knights >> 10) & NOT_GH_FILE;
    attacks |= (knights >> 6) & NOT_AB_FILE;

    return attacks & ~occ;
}
};  // namespace Clockwork
