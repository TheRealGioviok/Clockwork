#include "gamefile.hpp"

#include <algorithm>
#include <bit>
#include <cstring>
#include <string>

namespace Clockwork::Tuning {

static_assert(std::endian::native == std::endian::little,
              "the .ckg format assumes a little-endian host");

namespace {

constexpr u8 NO_SQUARE = 0xFF;

constexpr std::string_view WHITE_PIECES = "PNBRQK";
constexpr std::string_view BLACK_PIECES = "pnbrqk";

void push_u16(std::vector<u8>& out, u16 value) {
    out.push_back(static_cast<u8>(value & 0xFF));
    out.push_back(static_cast<u8>(value >> 8));
}

u16 read_u16(const u8* p) {
    return static_cast<u16>(p[0] | (p[1] << 8));
}

u8 pack_square(Square sq) {
    return sq.is_valid() ? sq.raw : NO_SQUARE;
}

}  // namespace

CkgWriter::CkgWriter(std::ostream& stream) :
    m_stream(stream) {
    std::array<u8, 16> header{};
    std::memcpy(header.data(), &CKG_MAGIC, 4);
    std::memcpy(header.data() + 4, &CKG_VERSION, 4);
    m_stream.write(reinterpret_cast<const char*>(header.data()),
                   static_cast<std::streamsize>(header.size()));
}

void CkgWriter::write(const PgnGame& game) {
    m_buffer.clear();

    const Position& pos = game.start;

    std::array<u8, 32> board{};
    for (u8 sq = 0; sq < 64; sq++) {
        Place p = pos.board()[Square{sq}];
        if (!p.is_empty()) {
            u8 code =
              static_cast<u8>(static_cast<u8>(p.ptype()) + (p.color() == Color::Black ? 6 : 0));
            board[sq / 2] |= static_cast<u8>(code << ((sq % 2) * 4));
        }
    }
    m_buffer.insert(m_buffer.end(), board.begin(), board.end());

    m_buffer.push_back(static_cast<u8>(pos.active_color()));
    m_buffer.push_back(pack_square(pos.en_passant()));
    for (Color color : {Color::White, Color::Black}) {
        m_buffer.push_back(pack_square(pos.rook_info(color).aside));
        m_buffer.push_back(pack_square(pos.rook_info(color).hside));
    }
    m_buffer.push_back(static_cast<u8>(std::min<u16>(pos.get_50mr_counter(), 100)));
    m_buffer.push_back(static_cast<u8>(game.result));
    push_u16(m_buffer, pos.get_ply());

    u16 move_count = static_cast<u16>(game.moves.size());
    push_u16(m_buffer, move_count);
    for (Move m : game.moves) {
        push_u16(m_buffer, m.raw);
    }
    m_buffer.insert(m_buffer.end(), game.flags.begin(), game.flags.end());
    if (move_count % 2 != 0) {
        m_buffer.push_back(0);
    }

    m_stream.write(reinterpret_cast<const char*>(m_buffer.data()),
                   static_cast<std::streamsize>(m_buffer.size()));
    m_count++;
}

void CkgWriter::finish() {
    std::streampos end = m_stream.tellp();
    m_stream.seekp(8);
    m_stream.write(reinterpret_cast<const char*>(&m_count), 8);
    m_stream.seekp(end);
    m_stream.flush();
}

std::optional<CkgReader> CkgReader::open(std::span<const u8> data) {
    if (data.size() < 16 || reinterpret_cast<uintptr_t>(data.data()) % 2 != 0) {
        return std::nullopt;
    }
    u32 magic, version;
    std::memcpy(&magic, data.data(), 4);
    std::memcpy(&version, data.data() + 4, 4);
    if (magic != CKG_MAGIC || version != CKG_VERSION) {
        return std::nullopt;
    }
    u64 count;
    std::memcpy(&count, data.data() + 8, 8);
    return CkgReader{data, count};
}

std::optional<CkgGameView> CkgReader::next() {
    if (m_read == m_count || m_offset + 44 > m_data.size()) {
        return std::nullopt;
    }

    const u8* rec = m_data.data() + m_offset;

    CkgGameView view;
    std::copy_n(rec, 32, view.board.begin());
    view.stm = rec[32];
    view.ep  = rec[33];
    std::copy_n(rec + 34, 4, view.rook_info.begin());
    view.halfmove_clock = rec[38];
    if (rec[39] > static_cast<u8>(GameResult::BlackWin) || view.stm > 1) {
        return std::nullopt;
    }
    view.result = static_cast<GameResult>(rec[39]);
    view.ply    = read_u16(rec + 40);

    u16   move_count  = read_u16(rec + 42);
    usize record_size = 44 + 3 * static_cast<usize>(move_count) + move_count % 2;
    if (move_count == 0 || m_offset + record_size > m_data.size()) {
        return std::nullopt;
    }

    view.moves = std::span{reinterpret_cast<const u16*>(rec + 44), move_count};
    view.flags = std::span{rec + 44 + 2 * static_cast<usize>(move_count), move_count};

    m_offset += record_size;
    m_read++;
    return view;
}

std::optional<Position> reconstruct_start_position(const CkgGameView& view) {
    std::string fen;
    fen.reserve(96);

    for (i32 rank = 7; rank >= 0; rank--) {
        i32 run = 0;
        for (i32 file = 0; file < 8; file++) {
            i32 sq   = rank * 8 + file;
            u8  code = (view.board[static_cast<usize>(sq) / 2] >> ((sq % 2) * 4)) & 0xF;
            if (code == 0) {
                run++;
                continue;
            }
            if (code > 12) {
                return std::nullopt;
            }
            if (run > 0) {
                fen += static_cast<char>('0' + run);
                run = 0;
            }
            fen += code <= 6 ? WHITE_PIECES[code - 1] : BLACK_PIECES[code - 7];
        }
        if (run > 0) {
            fen += static_cast<char>('0' + run);
        }
        fen += rank > 0 ? '/' : ' ';
    }

    fen += view.stm ? 'b' : 'w';
    fen += ' ';

    // Castling rights as Shredder-FEN file letters (DFRC-safe).
    usize castle_start = fen.size();
    if (view.rook_info[1] != NO_SQUARE) {
        fen += static_cast<char>('A' + (view.rook_info[1] & 7));
    }
    if (view.rook_info[0] != NO_SQUARE) {
        fen += static_cast<char>('A' + (view.rook_info[0] & 7));
    }
    if (view.rook_info[3] != NO_SQUARE) {
        fen += static_cast<char>('a' + (view.rook_info[3] & 7));
    }
    if (view.rook_info[2] != NO_SQUARE) {
        fen += static_cast<char>('a' + (view.rook_info[2] & 7));
    }
    if (fen.size() == castle_start) {
        fen += '-';
    }
    fen += ' ';

    if (view.ep != NO_SQUARE) {
        if (view.ep >= 64) {
            return std::nullopt;
        }
        fen += static_cast<char>('a' + (view.ep & 7));
        fen += static_cast<char>('1' + (view.ep >> 3));
    } else {
        fen += '-';
    }

    fen += ' ';
    fen += std::to_string(view.halfmove_clock);
    fen += ' ';
    fen += std::to_string(view.ply / 2 + 1);

    return Position::parse(fen);
}

}  // namespace Clockwork::Tuning
