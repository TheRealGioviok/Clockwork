#include "endgame.hpp"

#include "bitboard.hpp"
#include "eval_types.hpp"
#include "position.hpp"
#include "square.hpp"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <span>

namespace Clockwork {

// ─────────────────────────────────────────────────────────────────────────────
// Internal helpers
// ─────────────────────────────────────────────────────────────────────────────

namespace {

[[nodiscard]] constexpr i32 chebyshev(Square a, Square b) {
    return std::max(std::abs(a.file() - b.file()), std::abs(a.rank() - b.rank()));
}

// Square indices: a1=0, h1=7, a8=56, h8=63
[[nodiscard]] constexpr i32 corner_distance(Square sq) {
    return std::min({
      chebyshev(sq, Square{u8{0}}),   // a1
      chebyshev(sq, Square{u8{7}}),   // h1
      chebyshev(sq, Square{u8{56}}),  // a8
      chebyshev(sq, Square{u8{63}})   // h8
    });
}

}  // namespace

// ─────────────────────────────────────────────────────────────────────────────
// ── Example 1: KQK — full eval replacement ───────────────────────────────────
//
//  Strong side has a queen; weak side has only a king.
//  Strategy: drive the weak king to a corner while keeping kings close.
//
//  EgMaterial:
//    strong: Q=1, R=0, B=0, N=0, P=0
//    weak:   Q=0, R=0, B=0, N=0, P=0
// ─────────────────────────────────────────────────────────────────────────────

[[nodiscard]] static Score eg_KQK(const Position& pos, Color strong) {
    constexpr Score base = KNOWN_WIN + 3000;

    Square sk = pos.king_sq(strong);
    Square wk = pos.king_sq(~strong);

    Score result = base - static_cast<Score>(corner_distance(wk) * 20)  // push weak king to corner
                 - static_cast<Score>(chebyshev(sk, wk) * 5);           // keep our king close

    return strong == Color::White ? result : static_cast<Score>(-result);
}

[[nodiscard]] static Score eg_KRK(const Position& pos, Color strong) {
    constexpr Score base = KNOWN_WIN + 1400;

    Square sk = pos.king_sq(strong);
    Square wk = pos.king_sq(~strong);

    Score result = base - static_cast<Score>(corner_distance(wk) * 20)  // push weak king to corner
                 - static_cast<Score>(chebyshev(sk, wk) * 5);           // keep our king close

    return strong == Color::White ? result : static_cast<Score>(-result);
}

// ─────────────────────────────────────────────────────────────────────────────
// ── Example 2: KBvKP* — scaling function ─────────────────────────────────────
//
//  Strong side has a lone bishop; weak side has any number of pawns (≥1).
//  A wrong-colour bishop can't stop a rook-pawn → scale toward draw.
//  The more pawns the weak side has, the harder it is to hold → scale down more.
//
//  EgMaterial:
//    strong: Q=0, R=0, B=1, N=0, P=0
//    weak:   Q=0, R=0, B=0, N=0, P=at_least(1)
//    priority=10  (more specific than a generic "KB vs K*" catch-all)
// ─────────────────────────────────────────────────────────────────────────────

[[nodiscard]] static i32 eg_scale_KBvKPn(const Position& pos, Color strong) {
    Color weak = ~strong;

    Bitboard bishops = pos.bitboard_for(strong, PieceType::Bishop);
    Bitboard pawns   = pos.bitboard_for(weak, PieceType::Pawn);

    if (bishops.empty() || pawns.empty()) {
        return 128;
    }

    Square bishop_sq = bishops.lsb();
    Square weak_king = pos.king_sq(weak);

    // For each opposing pawn, check if it's a rook pawn headed to the
    // wrong-colour promotion square that the bishop can't control
    i32 unstoppable = 0;
    for (Square pawn_sq : pawns) {
        // Promotion square for the weak side's pawn
        Square promo = weak == Color::White
                       ? Square{static_cast<u8>(pawn_sq.file() + 56)}  // rank 8 for white
                       : Square{static_cast<u8>(pawn_sq.file())};      // rank 1 for black

        bool rook_pawn      = (pawn_sq.file() == 0 || pawn_sq.file() == 7);
        bool wrong_colour   = (bishop_sq.color() != promo.color());
        bool king_at_corner = (chebyshev(weak_king, promo) <= 1);

        if (rook_pawn && wrong_colour && king_at_corner) {
            ++unstoppable;
        }
    }

    if (unstoppable > 0) {
        return 0;  // at least one pawn is an unstoppable draw
    }

    // General case: scale down proportionally to pawn count
    i32 pawn_count = static_cast<i32>(pawns.popcount());
    return std::max(0, 128 - pawn_count * 24);
}

// ─────────────────────────────────────────────────────────────────────────────
// ── Registry ──────────────────────────────────────────────────────────────────
//
//  • List entries from most specific (highest priority) to least specific.
//  • make_sorted_endgame_table() will sort by .priority descending at compile
//    time, so explicit ordering here is just a readability aid.
//  • Add/remove entries here; nothing else needs to change.
// ─────────────────────────────────────────────────────────────────────────────

// ─────────────────────────────────────────────────────────────────────────────
// Registry
// ─────────────────────────────────────────────────────────────────────────────

// clang-format off
static constexpr auto kRawTable = std::array{

    // ── Full-eval replacements ────────────────────────────────────────────────

    EG_EVAL(
        EgMaterial{
            .queens  = eg::One,  .rooks   = eg::None, .bishops = eg::None,
            .knights = eg::None, .pawns   = eg::None,
            .opp_queens  = eg::None, .opp_rooks   = eg::None, .opp_bishops = eg::None,
            .opp_knights = eg::None, .opp_pawns   = eg::None,
            .priority = 20
        },
        eg_KQK
    ),

    EG_EVAL(
        EgMaterial{
            .queens  = eg::None,  .rooks   = eg::One, .bishops = eg::None,
            .knights = eg::None, .pawns   = eg::None,
            .opp_queens  = eg::None, .opp_rooks   = eg::None, .opp_bishops = eg::None,
            .opp_knights = eg::None, .opp_pawns   = eg::None,
            .priority = 20
        },
        eg_KQK
    ),

    // ── Scaling functions ─────────────────────────────────────────────────────

    // KB vs K + any number of pawns (≥1)
    EG_SCALE(
        EgMaterial{
            .queens  = eg::None, .rooks   = eg::None, .bishops = eg::One,
            .knights = eg::None, .pawns   = eg::None,
            .opp_queens  = eg::None, .opp_rooks   = eg::None, .opp_bishops = eg::None,
            .opp_knights = eg::None, .opp_pawns   = eg::AtLeast1,
            .priority = 10
        },
        eg_scale_KBvKPn
    ),

};
// clang-format on

// Partition and sort at compile time into two typed arrays.
// probe_eg_eval and probe_eg_scale each iterate only their own slice —
// no runtime kind-check, no wasted iterations.

template<EgKind Kind, std::size_t N>
consteval auto filter_and_sort(const std::array<EndgameEntry, N>& src) {
    // Count matching entries
    std::size_t count = 0;
    for (const auto& e : src) {
        if (e.kind == Kind) {
            ++count;
        }
    }

    // Fill a same-sized array (unused tail stays default-constructed / invalid)
    std::array<EndgameEntry, N> out{};
    std::size_t                 i = 0;
    for (const auto& e : src) {
        if (e.kind == Kind) {
            out[i++] = e;
        }
    }

    // Sort by priority descending within the filled prefix
    // (std::sort is constexpr in C++20)
    std::sort(out.begin(), out.begin() + count, [](const EndgameEntry& a, const EndgameEntry& b) {
        return a.material.priority > b.material.priority;
    });
    return std::pair{out, count};
}

static constexpr auto kEvalPair  = filter_and_sort<EgKind::Eval>(kRawTable);
static constexpr auto kScalePair = filter_and_sort<EgKind::Scale>(kRawTable);

// Expose as spans so callers don't need to know the storage size
const std::span<const EndgameEntry> kEgEvalTable{kEvalPair.first.data(), kEvalPair.second};
const std::span<const EndgameEntry> kEgScaleTable{kScalePair.first.data(), kScalePair.second};

// ─────────────────────────────────────────────────────────────────────────────
// probe_eg_eval — runs before the main eval; iterates only Eval entries
// ─────────────────────────────────────────────────────────────────────────────

std::optional<Score> probe_eg_eval(const Position& pos) {
    for (const Color strong : {Color::White, Color::Black}) {
        for (const EndgameEntry& entry : kEgEvalTable) {
            if (!entry.material.matches(pos, strong)) {
                continue;
            }
            return entry.eval_fn(pos, strong);
        }
    }
    return std::nullopt;
}

// ─────────────────────────────────────────────────────────────────────────────
// probe_eg_scale — runs after the main eval; iterates only Scale entries
// ─────────────────────────────────────────────────────────────────────────────

bool probe_eg_scale(const Position& pos, Score& inout_score) {
    for (const Color strong : {Color::White, Color::Black}) {
        for (const EndgameEntry& entry : kEgScaleTable) {
            if (!entry.material.matches(pos, strong)) {
                continue;
            }
            inout_score = static_cast<Score>(inout_score * entry.scale_fn(pos, strong) / 128);
            return true;
        }
    }
    return false;
}

}  // namespace Clockwork
