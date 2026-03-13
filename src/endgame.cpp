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

[[nodiscard]] constexpr i32 corner_distance(Square sq, Color corner_color) {
    if (corner_color == Color::White){
        return std::min({
          chebyshev(sq, Square{u8{7}}),   // h1
          chebyshev(sq, Square{u8{56}}),  // a8
        });
    }
    else {
        return std::min({
          chebyshev(sq, Square{u8{0}}),   // a1
          chebyshev(sq, Square{u8{63}})   // h8
        });
    }
}

template<Score weight>
Score push_to_any_corner(Square sq) {
    return static_cast<Score>(-weight * corner_distance(sq));
}

template<Score weight>
Score push_to_color_corner(Square sq, Color c) {
    return static_cast<Score>(-weight * corner_distance(sq, c));
}

template<Score weight>
Score centralize(Square sq) {
    return static_cast<Score>(-weight * -corner_distance(sq));
}

template<Score weight>
Score keep_on_edge(Square sq){
    return static_cast<Score>(weight * (sq.rank() == 0 || sq.rank() == 7 || sq.file() == 0 || sq.file() == 7));
}

template<Score weight>
Score push_to_edge(Square sq) {
    return static_cast<Score>(
      weight * std::min(std::min(sq.file(), 7 - sq.file()), std::min(sq.rank(), 7 - sq.rank())));
}

template<Score weight>
Score keep_close(Square sq1, Square sq2) {
    return static_cast<Score>(-weight * chebyshev(sq1, sq2));
}

}  // namespace

// KR v Q: drive the weak king to a corner while keeping kings close. Don't blunder the piece away.
[[nodiscard]] static Score eg_KQK(const Position& pos, Color strong) {
    Color           weak = invert(strong);
    constexpr Score base = KNOWN_WIN + 3000;

    Square sk = pos.king_sq(strong);
    Square wk = pos.king_sq(weak);

    Bitboard safe = pos.attack_table(strong).get_attacked_bitboard()
                  | ~pos.attack_table(weak).get_attacked_bitboard();

    bool safe_piece = (pos.bitboard_for(strong, PieceType::Queen) & safe).any();

    Score result = static_cast<Score>(std::max(0,
                            base * safe_piece  // Always known win if the enemy king can't capture
                              + push_to_any_corner<20>(wk)  // push weak king to corner
                              + keep_close<5>(wk, sk)       // keep our king close
    ));

    return strong == Color::White ? result : static_cast<Score>(-result);
}

// KR v K: drive the weak king to a corner while keeping kings close. Don't blunder the piece away.
[[nodiscard]] static Score eg_KRK(const Position& pos, Color strong) {
    Color           weak = invert(strong);
    constexpr Score base = KNOWN_WIN + 1400;

    Square sk = pos.king_sq(strong);
    Square wk = pos.king_sq(weak);

    Bitboard safe = pos.attack_table(strong).get_attacked_bitboard()
                  | ~pos.attack_table(weak).get_attacked_bitboard();

    bool safe_piece = (pos.bitboard_for(strong, PieceType::Rook) & safe).any();

    Score result = static_cast<Score>(std::max(0,
                            base * safe_piece  // Always known win if the enemy king can't capture
                              + push_to_any_corner<20>(wk)  // push weak king to corner
                              + keep_close<5>(wk, sk)       // keep our king close
    ));

    return strong == Color::White ? result : static_cast<Score>(-result);
}

// KBB v K: drive the weak king to a corner while keeping kings close. Bishops must be opposite side. Don't blunder the pieces away.
[[nodiscard]] static Score eg_KBBK(const Position& pos, Color strong) {

    // If same color bishops immediately return draw.
    Bitboard strong_bishops = pos.bitboard_for(strong, PieceType::Bishop);

    if((strong_bishops & Bitboard::squares_of_color(Color::White)).popcount() != 1) {
        return 0; // Instant draw
    }

    Color           weak = invert(strong);
    constexpr Score base = KNOWN_WIN + 1100;

    Square sk = pos.king_sq(strong);
    Square wk = pos.king_sq(weak);

    Bitboard safe = pos.attack_table(strong).get_attacked_bitboard()
                  | ~pos.attack_table(weak).get_attacked_bitboard();

    bool safe_pieces = (strong_bishops & safe).popcount() == 2;

    Score result = static_cast<Score>(std::max(0,
                            base * safe_pieces  // Always known win if the enemy king can't capture
                              + keep_on_edge<300>(wk)      // push weak king to edge and don't let it escape
                              + push_to_any_corner<15>(wk)  // push weak king to corner
                              + keep_close<25>(wk, sk)       // keep our king close
    ));

    return strong == Color::White ? result : static_cast<Score>(-result);
}

// KBN v K: drive the weak king to the edge, then to the corner of correct color, while keeping kings close. Don't blunder the pieces away.
[[nodiscard]] static Score eg_KBNK(const Position& pos, Color strong) {

    Color           weak = invert(strong);
    constexpr Score base = KNOWN_WIN + 900;

    Square sk = pos.king_sq(strong);
    Square wk = pos.king_sq(weak);

    Bitboard safe = pos.attack_table(strong).get_attacked_bitboard()
                  | ~pos.attack_table(weak).get_attacked_bitboard();

    bool safe_pieces = (pos.board().get_color_bitboard(strong) & safe).popcount() == 3; // KBN all safe

    Square sb = pos.bitboard_for(strong, PieceType::Bishop).lsb();
    Square sn = pos.bitboard_for(strong, PieceType::Knight).lsb();
    Color correct_color = sb.color();

    Score result = static_cast<Score>(
      std::max(0,
               base * safe_pieces         // Always known win if the enemy king can't capture
                 + centralize<5>(sk)
                 + centralize<5>(sn)
                 + centralize<5>(sb)
                 + keep_close<5>(sk, sn)
                 + keep_close<15>(sk, wk)
                 + push_to_edge<50>(wk)
                 + keep_on_edge<300>(wk)
                 + push_to_color_corner<120>(wk, correct_color)
               ));

    return strong == Color::White ? result : static_cast<Score>(-result);
}

// clang-format off
static constexpr auto kRawTable = std::array{

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
        eg_KRK
    ),

    EG_EVAL(
        EgMaterial{
            .queens  = eg::None,  .rooks   = eg::None, .bishops = eg::Two,
            .knights = eg::None, .pawns   = eg::None,
            .opp_queens  = eg::None, .opp_rooks   = eg::None, .opp_bishops = eg::None,
            .opp_knights = eg::None, .opp_pawns   = eg::None,
            .priority = 20
        },
        eg_KBBK
    ),

    EG_EVAL(
        EgMaterial{
            .queens  = eg::None,  .rooks   = eg::None, .bishops = eg::One,
            .knights = eg::One, .pawns   = eg::None,
            .opp_queens  = eg::None, .opp_rooks   = eg::None, .opp_bishops = eg::None,
            .opp_knights = eg::None, .opp_pawns   = eg::None,
            .priority = 20
        },
        eg_KBNK
    ),

};
// clang-format on

// Partition and sort at compile time into two typed arrays.

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

bool probe_eg_scale(const Position& pos, Score& inout_score) {
    const Color strong = inout_score > 0 ? Color::White : Color::Black;
    for (const EndgameEntry& entry : kEgScaleTable) {
        if (!entry.material.matches(pos, strong)) {
            continue;
        }
        inout_score = static_cast<Score>(inout_score * entry.scale_fn(pos, strong) / 128);
        return true;
    }
    return false;
}

}  // namespace Clockwork
