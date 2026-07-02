#pragma once

#include "move.hpp"
#include "position.hpp"
#include "util/types.hpp"
#include <istream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace Clockwork::Tuning {

enum class GameResult : u8 {
    WhiteWin,
    Draw,
    BlackWin,
};

// Per-position flag byte: bit 0 = eligible for training, bits 1-5 = phase (0-24).
constexpr u8 make_position_flags(bool eligible, u8 phase) {
    return static_cast<u8>(static_cast<u8>(eligible) | (phase << 1));
}

constexpr bool is_eligible(u8 flags) {
    return flags & 1;
}

constexpr u8 phase_of(u8 flags) {
    return flags >> 1;
}

constexpr u8 MAX_PHASE = 24;

struct PgnGame {
    Position          start;
    std::vector<Move> moves;
    // flags[i] describes the position reached after playing moves[0..i].
    // A position is eligible iff it is not in check, has legal moves, the next played
    // move is not a capture or promotion, and no mate score was reported at any
    // earlier or current ply.
    std::vector<u8> flags;
    GameResult      result = GameResult::Draw;
};

// Parses a single PGN game (header section + movetext). Returns nullopt if the game
// is malformed, has no [Result], contains a variation, or a move fails to parse.
std::optional<PgnGame> parse_pgn_game(std::string_view text);

// Splits a PGN stream into single-game text chunks on "[Event" boundaries.
class PgnSplitter {
public:
    explicit PgnSplitter(std::istream& stream) :
        m_stream(stream) {
    }

    std::optional<std::string> next();

private:
    std::istream& m_stream;
    std::string   m_pending;
};

}  // namespace Clockwork::Tuning
