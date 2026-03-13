#pragma once

#include "eval_types.hpp"
#include "position.hpp"

#include <algorithm>
#include <array>
#include <concepts>
#include <optional>

namespace Clockwork {

// ─────────────────────────────────────────────────────────────────────────────
// EgCount — per-piece-type count constraint
// ─────────────────────────────────────────────────────────────────────────────

struct EgCount {
    u8 min = 0;
    u8 max = 0xFF;  // 0xFF = unbounded

    [[nodiscard]] static constexpr EgCount any() {
        return {0, 0xFF};
    }
    [[nodiscard]] static constexpr EgCount none() {
        return {0, 0};
    }
    [[nodiscard]] static constexpr EgCount exact(u8 n) {
        return {n, n};
    }
    [[nodiscard]] static constexpr EgCount at_least(u8 n) {
        return {n, 0xFF};
    }
    [[nodiscard]] static constexpr EgCount at_most(u8 n) {
        return {0, n};
    }
    [[nodiscard]] static constexpr EgCount between(u8 lo, u8 hi) {
        return {lo, hi};
    }

    [[nodiscard]] constexpr bool matches(u8 actual) const {
        return actual >= min && (max == 0xFF || actual <= max);
    }
};

// Shorthand aliases — keeps table entries terse
namespace eg {
inline constexpr auto    Any      = EgCount::any();
inline constexpr auto    None     = EgCount::none();
inline constexpr auto    One      = EgCount::exact(1);
inline constexpr auto    Two      = EgCount::exact(2);
inline constexpr auto    AtLeast1 = EgCount::at_least(1);
inline constexpr auto    AtLeast2 = EgCount::at_least(2);
inline constexpr EgCount Exact(u8 n) {
    return EgCount::exact(n);
}
inline constexpr EgCount AtLeast(u8 n) {
    return EgCount::at_least(n);
}
inline constexpr EgCount AtMost(u8 n) {
    return EgCount::at_most(n);
}
inline constexpr EgCount Between(u8 lo, u8 hi) {
    return EgCount::between(lo, hi);
}
}  // namespace eg

// ─────────────────────────────────────────────────────────────────────────────
// EgMaterial — material signature for the strong side
//
// All fields default to eg::Any, so you only specify what matters.
// The router normalises orientation so you always write entries as if the
// stronger side (the one with more material) is Color::White.
// ─────────────────────────────────────────────────────────────────────────────

struct EgMaterial {
    // Strong side
    EgCount queens  = eg::Any;
    EgCount rooks   = eg::Any;
    EgCount bishops = eg::Any;
    EgCount knights = eg::Any;
    EgCount pawns   = eg::Any;

    // Weak side
    EgCount opp_queens  = eg::Any;
    EgCount opp_rooks   = eg::Any;
    EgCount opp_bishops = eg::Any;
    EgCount opp_knights = eg::Any;
    EgCount opp_pawns   = eg::Any;

    // Higher priority entries are checked first. Assign higher values to more
    // specific patterns so they shadow broader wildcard entries.
    u8 priority = 0;

    [[nodiscard]] constexpr bool matches(const Position& pos, Color strong) const {
        Color weak = ~strong;
        auto  cnt  = [&](Color c, PieceType pt) -> u8 {
            return static_cast<u8>(pos.piece_count(c, pt));
        };
        return queens.matches(cnt(strong, PieceType::Queen))
            && rooks.matches(cnt(strong, PieceType::Rook))
            && bishops.matches(cnt(strong, PieceType::Bishop))
            && knights.matches(cnt(strong, PieceType::Knight))
            && pawns.matches(cnt(strong, PieceType::Pawn))
            && opp_queens.matches(cnt(weak, PieceType::Queen))
            && opp_rooks.matches(cnt(weak, PieceType::Rook))
            && opp_bishops.matches(cnt(weak, PieceType::Bishop))
            && opp_knights.matches(cnt(weak, PieceType::Knight))
            && opp_pawns.matches(cnt(weak, PieceType::Pawn));
    }
};

// ─────────────────────────────────────────────────────────────────────────────
// Function signatures
//
//  EgEvalFn  — completely replaces the main eval. Must return a Score from
//               white's POV. Receives `strong` so you can negate if needed.
//
//  EgScaleFn — scales the endgame component of the tapered score.
//               128 = identity, 0 = forced draw, 64 = half strength, etc.
//               Applied as: eg_score = eg_score * scale / 128
// ─────────────────────────────────────────────────────────────────────────────

using EgEvalFn  = Score (*)(const Position& pos, Color strong);
using EgScaleFn = i32 (*)(const Position& pos, Color strong);

// ─────────────────────────────────────────────────────────────────────────────
// EndgameEntry — one row in the registry
// ─────────────────────────────────────────────────────────────────────────────

enum class EgKind : u8 {
    Eval,
    Scale
};

struct EndgameEntry {
    EgMaterial material{};
    EgKind     kind{};
    union {
        EgEvalFn  eval_fn = nullptr;
        EgScaleFn scale_fn;
    };

    // Sentinel: default-constructed entry with null fn pointer is inert
    [[nodiscard]] constexpr bool is_valid() const {
        return kind == EgKind::Eval ? eval_fn != nullptr : scale_fn != nullptr;
    }
};

// ─────────────────────────────────────────────────────────────────────────────
// Registration helpers — the only thing you touch in endgame_entries.cpp
//
// Using constexpr functions instead of macros avoids the classic preprocessor
// bug where commas inside a braced initializer list are misread as argument
// separators, causing cryptic "too many arguments" errors.
// ─────────────────────────────────────────────────────────────────────────────

[[nodiscard]] constexpr EndgameEntry EG_EVAL(EgMaterial mat, EgEvalFn fn) {
    EndgameEntry e;
    e.material = mat;
    e.kind     = EgKind::Eval;
    e.eval_fn  = fn;
    return e;
}

[[nodiscard]] constexpr EndgameEntry EG_SCALE(EgMaterial mat, EgScaleFn fn) {
    EndgameEntry e;
    e.material = mat;
    e.kind     = EgKind::Scale;
    e.scale_fn = fn;
    return e;
}

// ─────────────────────────────────────────────────────────────────────────────
// Registry helpers
//
// kEndgameTable is defined in endgame_entries.cpp.
// make_sorted_endgame_table() returns a copy sorted by priority descending so
// the router can simply iterate and take the first match.
// ─────────────────────────────────────────────────────────────────────────────


// Defined in endgame_entries.cpp.
// Entries are partitioned at startup: eval entries first, scale entries second.
// Each probe function receives only the relevant slice — no kind-check in the loop.
extern const std::span<const EndgameEntry> kEgEvalTable;
extern const std::span<const EndgameEntry> kEgScaleTable;

// ─────────────────────────────────────────────────────────────────────────────
// probe_eg_eval — call BEFORE the main eval
//
// Checks only EgKind::Eval entries. If one matches, returns the Score
// immediately and the caller must skip the normal eval entirely.
//
//   if (auto eg = probe_eg_eval(pos))
//       return *eg;
//   // ... run normal eval ...
//
// ─────────────────────────────────────────────────────────────────────────────

[[nodiscard]] std::optional<Score> probe_eg_eval(const Position& pos);

// ─────────────────────────────────────────────────────────────────────────────
// probe_eg_scale — call AFTER the main eval, before returning
//
// Checks only EgKind::Scale entries. If one matches, modifies inout_score
// in-place and returns true. The caller always returns inout_score afterwards.
//
//   Score final = static_cast<Score>(eval.phase<24>(phase));
//   probe_eg_scale(pos, final);
//   return final;
//
// ─────────────────────────────────────────────────────────────────────────────

bool probe_eg_scale(const Position& pos, Score& inout_score);

}  // namespace Clockwork
