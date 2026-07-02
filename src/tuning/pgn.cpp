#include "pgn.hpp"

#include "movegen.hpp"
#include <algorithm>
#include <sstream>

namespace Clockwork::Tuning {

namespace {

constexpr std::string_view STARTPOS_FEN =
  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

u8 position_phase(const Position& pos) {
    usize phase = 0;
    for (Color color : {Color::White, Color::Black}) {
        phase += pos.piece_count<PieceType::Knight, PieceType::Bishop>(color);
        phase += 2 * pos.piece_count(color, PieceType::Rook);
        phase += 4 * pos.piece_count(color, PieceType::Queen);
    }
    return static_cast<u8>(std::min<usize>(phase, MAX_PHASE));
}

bool is_result_token(std::string_view tok) {
    return tok == "1-0" || tok == "0-1" || tok == "1/2-1/2" || tok == "*";
}

bool has_legal_moves(const Position& pos) {
    MoveList noisy, quiet;
    MoveGen  movegen{pos};
    movegen.generate_moves(noisy, quiet);
    return !noisy.empty() || !quiet.empty();
}

}  // namespace

std::optional<PgnGame> parse_pgn_game(std::string_view text) {
    std::string               fen{STARTPOS_FEN};
    std::optional<GameResult> result;

    // Header section: lines starting with '['.
    usize offset = 0;
    while (offset < text.size()) {
        usize            eol  = text.find('\n', offset);
        usize            next = eol == std::string_view::npos ? text.size() : eol + 1;
        std::string_view line =
          text.substr(offset, (eol == std::string_view::npos ? text.size() : eol) - offset);
        if (!line.empty() && line.back() == '\r') {
            line.remove_suffix(1);
        }

        if (line.empty()) {
            offset = next;
            continue;
        }
        if (line[0] != '[') {
            break;  // movetext starts here
        }

        usize q1 = line.find('"');
        usize q2 = line.rfind('"');
        if (q1 != std::string_view::npos && q2 > q1) {
            std::string_view tag   = line.substr(1, line.find_first_of(" \t") - 1);
            std::string_view value = line.substr(q1 + 1, q2 - q1 - 1);
            if (tag == "FEN") {
                fen = value;
            } else if (tag == "Result") {
                if (value == "1-0") {
                    result = GameResult::WhiteWin;
                } else if (value == "0-1") {
                    result = GameResult::BlackWin;
                } else if (value == "1/2-1/2") {
                    result = GameResult::Draw;
                } else {
                    return std::nullopt;
                }
            }
        }
        offset = next;
    }

    if (!result) {
        return std::nullopt;
    }

    auto start = Position::parse(fen);
    if (!start) {
        return std::nullopt;
    }

    PgnGame game;
    game.start  = *start;
    game.result = *result;

    Position          pos = *start;
    std::vector<bool> checked;
    std::vector<u8>   phases;
    usize             first_mate_ply = SIZE_MAX;

    std::istringstream iss{std::string(text.substr(offset))};
    std::string        tok;
    bool               in_comment = false;
    while (iss >> tok) {
        if (in_comment || tok[0] == '{') {
            if (first_mate_ply == SIZE_MAX && tok.find('M') != std::string::npos) {
                first_mate_ply = game.moves.empty() ? 0 : game.moves.size() - 1;
            }
            in_comment = tok.back() != '}';
            continue;
        }
        if (is_result_token(tok)) {
            break;
        }
        if (tok[0] == '(' || tok[0] == ')') {
            return std::nullopt;  // variations are not supported
        }
        if (tok[0] == '$' || (tok[0] >= '0' && tok[0] <= '9')) {
            continue;  // NAG or move number
        }

        auto move = Move::parse_san(tok, pos);
        if (!move) {
            return std::nullopt;
        }
        // parse_san does not validate pawn pushes and castling for legality.
        MoveGen movegen{pos};
        if (!movegen.is_legal(*move)) {
            return std::nullopt;
        }

        pos = pos.move(*move);
        game.moves.push_back(*move);
        checked.push_back(pos.is_in_check());
        phases.push_back(position_phase(pos));
    }

    if (game.moves.empty()) {
        return std::nullopt;
    }

    usize n               = game.moves.size();
    bool  final_has_legal = has_legal_moves(pos);

    game.flags.resize(n);
    for (usize i = 0; i < n; i++) {
        bool next_quiet = i + 1 < n
                          ? !(game.moves[i + 1].is_capture() || game.moves[i + 1].is_promotion())
                          : final_has_legal;
        bool eligible   = !checked[i] && next_quiet && i < first_mate_ply;
        game.flags[i]   = make_position_flags(eligible, phases[i]);
    }
    return game;
}

std::optional<std::string> PgnSplitter::next() {
    std::string game = std::move(m_pending);
    m_pending.clear();

    bool        seen_movetext = false;
    std::string line;
    while (std::getline(m_stream, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        bool is_header = !line.empty() && line[0] == '[';
        if (is_header && seen_movetext && line.rfind("[Event", 0) == 0) {
            m_pending = line + '\n';
            return game;
        }
        if (!line.empty() && !is_header) {
            seen_movetext = true;
        }
        game += line;
        game += '\n';
    }

    if (game.find_first_not_of(" \t\r\n") == std::string::npos) {
        return std::nullopt;
    }
    return game;
}

}  // namespace Clockwork::Tuning
