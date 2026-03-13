#pragma once

#include "eval_types.hpp"
#include "position.hpp"

#include <algorithm>
#include <array>
#include <concepts>
#include <optional>

namespace Clockwork {

// EgCount contains the boilerplate for material matching
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

// Shorthand aliases
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

// Material signature for the strong side. Default fields are any for ease of declaration of scaling fns

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

    // Higher priority entries are checked first. This is useful if for example we define large wildcards (eg KRP+ v KRP+ ) but we also have specific heuristics for subsets.
    // This MIGHT be doable in an automated way, but i can't figure out how.
    // TODO: look into this

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

// Eg fn signatures
using EgEvalFn  = Score (*)(const Position& pos, Color strong);
using EgScaleFn = i32 (*)(const Position& pos, Color strong);


enum class EgKind : u8 {
    Eval,
    Scale
};

// EndgameEntry has the relevant routing information for the endgame eval / scaling function (union)
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

// Registration helpers

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

// Entries are partitioned at startup: eval entries first, scale entries second.
extern const std::span<const EndgameEntry> kEgEvalTable;
extern const std::span<const EndgameEntry> kEgScaleTable;


[[nodiscard]] std::optional<Score> probe_eg_eval(const Position& pos);

bool probe_eg_scale(const Position& pos, Score& inout_score);

}  // namespace Clockwork
