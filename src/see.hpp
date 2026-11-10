#pragma once

#include "common.hpp"
#include "geometry.hpp"
#include "move.hpp"
#include "position.hpp"
#include "util/types.hpp"
#include <array>
#include <bit>
#include <cassert>
#include <immintrin.h>
#include <tuned.hpp>
#include <tuple>

namespace Clockwork::SEE {

inline Value value(PieceType ptype) {
#if (CLOCKWORK_IS_TUNING == 0)
    constexpr std::array<Value, 7> TABLE{{0, tuned::see_pawn_val, tuned::see_knight_val,
                                          tuned::see_bishop_val, tuned::see_rook_val,
                                          tuned::see_queen_val, 10000}};
    return TABLE[static_cast<usize>(ptype)];
#else
    switch (ptype) {
    case PieceType::None:
        return 0;
    case PieceType::Pawn:
        return tuned::see_pawn_val;
    case PieceType::Knight:
        return tuned::see_knight_val;
    case PieceType::Bishop:
        return tuned::see_bishop_val;
    case PieceType::Rook:
        return tuned::see_rook_val;
    case PieceType::Queen:
        return tuned::see_queen_val;
    case PieceType::King:
        return 10000;
    default:
        unreachable();
    }
#endif
}

inline Value gain(const Position& pos, Move move) {
    if (move.is_castle()) {
        return 0;
    }
    if (move.is_en_passant()) {
        return value(PieceType::Pawn);
    }

    Value score = value(pos.board()[move.to()].ptype());
    if (move.is_promotion()) {
        score += value(*move.promo()) - value(PieceType::Pawn);
    }
    return score;
}

namespace internal {

constexpr u64 KNIGHT_LANES = 0x0101010101010101;

// 32-bit mask into 32 bytes of 0b11111111 / 0b00000000
forceinline u8x32 expand_bits32(u32 bits) {
    static const u8x32 BYTE_IDX{{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,  //
                                 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3}};
    static const u8x32 BIT{{0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,  //
                            0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,  //
                            0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,  //
                            0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}};
    u8x32              bytes = BYTE_IDX.swizzle(std::bit_cast<u8x32>(vector<u32, 8>::splat(bits)));
    return std::bit_cast<u8x32>(bytes.test(BIT).to_vector());
}

// Fills every ray AND antiray that contains a set bit (no knight lanes)
forceinline u64 fill_ray_lines(u64 x) {
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;
    x &= KNIGHT_LANES;
    x *= 0xFF;
    return (x | std::rotl(x, 32)) & ~KNIGHT_LANES;
}


forceinline u32 color_id_bits(const std::array<PieceMask, 2>& masks) {
    return masks[0].value()
         | static_cast<u32>(masks[1].value())
             << 16;  // White ids in bits 0-15, black ids in bits 16-31
}

}

inline bool see(const Position& pos, Move move, Value threshold, const PinInfo& pins) {
    Square sq  = move.to();
    Color  stm = pos.active_color();

    Value score = gain(pos, move) - threshold;
    if (score < 0) {
        return false;
    }

    PieceType next = move.promo().value_or(pos.board()[move.from()].ptype());
    score -= value(next);
    stm = invert(stm);

    if (score >= 0) {
        return true;
    }

    // Extract all possible attackers to our position
    auto [ray_coords, ray_valid] = geometry::superpiece_rays(sq);
    u8x64 ray_places             = ray_coords.swizzle(pos.board().to_vector());
    u8x64 ray_attackers          = geometry::attackers_from_rays(ray_places).mask(ray_places);
    u8x64 ptypes                 = ray_valid.mask(ray_attackers & u8x64::splat(Place::PTYPE_MASK));

    // Bitrays (not bitboards)
    u64 color     = ray_places.test(u8x64::splat(Place::COLOR_MASK)).to_bits();
    u64 occupied  = (ray_places.nonzeros() & ray_valid).to_bits();
    u64 attackers = (ray_attackers.nonzeros() & ray_valid).to_bits();

    // Remove already moved piece
    occupied ^= ray_coords.eq(u8x64::splat(move.from().raw)).to_bits();
    if (move.is_en_passant()) {
        occupied &= pos.active_color() == Color::Black ? 0xFFFFFFFFFFFFFFFD : 0xFFFFFFFDFFFFFFFF;
    }

    auto color_bits = [&](Color c) {
        return c == Color::Black ? color : ~color;
    };

    // Approximate pinned piece handling, using the pins of the current position.
    // A piece pinned to its king is kept out of the exchange unless the capture
    // square lies on the pin line.
    // Unpinning approximation: release all at once when the enemy has no pinner left.
    // TODO: explore doing more precise pin handling?

    // A pinner that is not on any ray from sq can never leave during the exchange (TODO: weird ideas to explore SEE moves on different squares but its fucked up),
    // so if the enemy has one of those pinners, our blocked pieces stay blocked throughout.

    std::array<u64, 2>  blocked{};         // pinned lanes of color c that may not capture on sq
    std::array<u64, 2>  pinner_lanes{};    // lanes holding pinners of color c (on rays from sq)
    std::array<bool, 2> off_ray_pinner{};  // color c has a pinner that can never leave
    if ((pins.pinned[0] | pins.pinned[1]).value() != 0) {
        u8x32 table =
          (internal::expand_bits32(internal::color_id_bits(pins.pinned)) & u8x32::splat(1))
          | (internal::expand_bits32(internal::color_id_bits(pins.pinners)) & u8x32::splat(2));
        u8x64 keys  = ray_places & u8x64::splat(Place::COLOR_MASK | Place::ID_MASK);
        u8x64 flags = ray_valid.mask(keys.swizzle(u8x64::splat(table)));

        u64 pinned_lanes = flags.test(u8x64::splat(1)).to_bits();
        u64 pinner_all   = flags.test(u8x64::splat(2)).to_bits();
        u64 kings        = ((ray_places & u8x64::splat(Place::PTYPE_MASK))
                       .eq(u8x64::splat(static_cast<u8>(PieceType::King) << Place::PTYPE_SHIFT))
                     & ray_valid)
                      .to_bits()
                  & ~internal::KNIGHT_LANES;

        // Discount eventual captured piece separately for pin stuff
        Place captured = pos.board()[sq];

        for (Color c : {Color::White, Color::Black}) {
            usize ci = static_cast<usize>(c);
            u64   cb = color_bits(c);

            blocked[ci]      = pinned_lanes & cb & ~internal::fill_ray_lines(kings & cb);
            pinner_lanes[ci] = pinner_all & cb;

            usize on_ray       = static_cast<usize>(std::popcount(pinner_lanes[ci]));
            usize on_sq        = captured.color() == c && pins.pinners[ci].is_set(captured.id());
            off_ray_pinner[ci] = pins.pinners[ci].popcount() > on_ray + on_sq;
        }
    }

    // Does color c still have a pinner on the board
    auto pinners_remaining = [&](Color c) {
        usize ci = static_cast<usize>(c);
        return off_ray_pinner[ci] || (pinner_lanes[ci] & occupied) != 0;
    };

    std::array<u64, 8> ptype_bits{
      0,  // None
      ptypes.eq(u8x64::splat(static_cast<u8>(PieceType::Pawn) << Place::PTYPE_SHIFT)).to_bits(),
      internal::KNIGHT_LANES,
      ptypes.eq(u8x64::splat(static_cast<u8>(PieceType::Bishop) << Place::PTYPE_SHIFT)).to_bits(),
      ptypes.eq(u8x64::splat(static_cast<u8>(PieceType::Rook) << Place::PTYPE_SHIFT)).to_bits(),
      ptypes.eq(u8x64::splat(static_cast<u8>(PieceType::Queen) << Place::PTYPE_SHIFT)).to_bits(),
      ptypes.eq(u8x64::splat(static_cast<u8>(PieceType::King) << Place::PTYPE_SHIFT)).to_bits(),
      0,  // Invalid
    };
    u64x8 ptype_vec{ptype_bits};

    auto all_attackers = [&]() {
        return geometry::closest(occupied) & color_bits(stm) & attackers;
    };

    auto current_attackers = [&]() {
        u64 current = all_attackers();
        u64 b       = blocked[static_cast<usize>(stm)];
        if (b != 0 && pinners_remaining(invert(stm))) {
            current &= ~b;
        }
        return current;
    };

    while (u64 current = current_attackers()) {
        i32  next  = std::countr_zero((ptype_vec & u64x8::splat(current)).nonzeros().to_bits());
        auto ptype = static_cast<PieceType>(next);
        u64  br    = ptype_bits[static_cast<size_t>(next)] & current;
        occupied ^= lowest_bit(br);

        score = -score - 1 - value(ptype);
        stm   = invert(stm);

        if (score >= 0) {
            if (ptype == PieceType::King && all_attackers() != 0) {
                // We'd be in check if we actually did that.
                stm = invert(stm);
            }
            break;
        }
    }

    return stm != pos.active_color();
}

inline bool see(const Position& pos, Move move, Value threshold) {
    return see(pos, move, threshold, pos.calc_pin_info());
}

}  // namespace Clockwork::SEE
