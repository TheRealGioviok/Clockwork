#pragma once

#include "tuning/pgn.hpp"
#include "util/types.hpp"
#include <optional>
#include <ostream>
#include <span>

namespace Clockwork::Tuning {

// .ckg binary game file
//
// All integers are little-endian. Layout:
//   header:  magic u32 ("CKGF"), version u32, game_count u64
//   records: board u8[32] (nibble per square: 0 empty, 1-6 white pawn..king,
//            7-12 black pawn..king), stm u8, ep u8 (0xFF = none), rook_info u8[4]
//            (white aside/hside, black aside/hside; 0xFF = none), halfmove_clock u8,
//            result u8, ply u16, move_count u16, moves u16[move_count] (Move::raw),
//            flags u8[move_count], one padding byte if move_count is odd.
//
// The version must be bumped whenever the Move::raw encoding or the flag byte
// meaning changes.

constexpr u32 CKG_MAGIC   = 0x46474B43;  // "CKGF"
constexpr u32 CKG_VERSION = 1;

struct CkgGameView {
    std::array<u8, 32>   board;
    u8                   stm;
    u8                   ep;
    std::array<u8, 4>    rook_info;
    u8                   halfmove_clock;
    GameResult           result;
    u16                  ply;
    std::span<const u16> moves;
    std::span<const u8>  flags;
};

class CkgWriter {
public:
    // Writes a placeholder header. finish() must be called to patch the game count,
    // so the stream must be seekable.
    explicit CkgWriter(std::ostream& stream);

    void write(const PgnGame& game);
    void finish();

    [[nodiscard]] u64 games_written() const {
        return m_count;
    }

private:
    std::ostream&   m_stream;
    std::vector<u8> m_buffer;
    u64             m_count = 0;
};

class CkgReader {
public:
    // data must outlive the reader and any views it returns.
    static std::optional<CkgReader> open(std::span<const u8> data);

    [[nodiscard]] u64 game_count() const {
        return m_count;
    }
    [[nodiscard]] u64 games_read() const {
        return m_read;
    }

    // Returns nullopt at end of data or on a corrupt record; compare games_read()
    // against game_count() to distinguish.
    std::optional<CkgGameView> next();

private:
    CkgReader(std::span<const u8> data, u64 count) :
        m_data(data),
        m_count(count) {
    }

    std::span<const u8> m_data;
    usize               m_offset = 16;
    u64                 m_count;
    u64                 m_read = 0;
};

// Rebuilds the full start position (including attack tables) from a view.
// Expensive: intended to be called once per game at tuner startup.
std::optional<Position> reconstruct_start_position(const CkgGameView& view);

}  // namespace Clockwork::Tuning
