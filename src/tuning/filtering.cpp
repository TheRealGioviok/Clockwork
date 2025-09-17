// pgn_filter.cpp
#include "pgn_filter.hpp"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <random>
#include <sstream>
#include <vector>

#include "move.h"
#include "position.h"

namespace fs = std::filesystem;

namespace Clockwork::Filter {

std::string extract_header_value(const std::string& line) {
    auto start = line.find('"');
    auto end   = line.rfind('"');
    if (start != std::string::npos && end != std::string::npos && end > start) {
        return line.substr(start + 1, end - start - 1);
    }
    return {};
}

bool is_mate_token(const std::string& token) {
    return (!token.empty()
            && (token[0] == 'M' || (token.size() > 1 && token[0] == '-' && token[1] == 'M')));
}

GameData parse_game(std::istream& in) {
    GameData game;
    game.start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    std::ostringstream move_text;
    std::string        line;

    while (std::getline(in, line)) {
        if (line.empty()) {
            break;
        }
        if (line.front() == '[') {
            if (line.find("FEN") != std::string::npos) {
                game.start_fen = extract_header_value(line);
            } else if (line.find("Result") != std::string::npos) {
                std::string res = extract_header_value(line);
                if (res == "1-0") {
                    game.result = 'w';
                } else if (res == "0-1") {
                    game.result = 'b';
                } else if (res == "1/2-1/2") {
                    game.result = 'd';
                } else {
                    return game;
                }
            }
        }
    }

    while (std::getline(in, line)) {
        if (line.empty()) {
            break;
        }
        move_text << line << ' ';
        if (line.find("1-0") != std::string::npos || line.find("0-1") != std::string::npos
            || line.find("1/2-1/2") != std::string::npos) {
            break;
        }
    }

    std::istringstream ms(move_text.str());
    std::string        token;
    while (ms >> token) {
        if (token.front() == '{') {
            std::string comment = token;
            while (!comment.empty() && comment.back() != '}' && ms >> token) {
                comment += ' ' + token;
            }
            std::istringstream cs(comment.substr(1, comment.size() - 2));
            std::string        first_token;
            cs >> first_token;
            if (is_mate_token(first_token)) {
                break;
            }
        } else if (token.find('.') == std::string::npos && token != "1-0" && token != "0-1"
                   && token != "1/2-1/2") {
            game.moves.push_back(token);
        }
    }

    return game;
}

void filter_pgn(std::istringstream& is) {
    std::string folder;
    is >> folder;
    if (folder.empty()) {
        std::cerr << "filter command requires a folder argument\n";
        return;
    }

    std::mt19937 rng(std::random_device{}());

    for (const auto& entry : fs::directory_iterator(folder)) {
        if (!entry.is_regular_file() || entry.path().extension() != ".pgn") {
            continue;
        }

        std::ifstream pgn(entry.path());
        if (!pgn) {
            std::cerr << "Failed to open " << entry.path() << "\n";
            continue;
        }

        std::string   out_name = entry.path().stem().string() + "_positions.txt";
        std::ofstream out(out_name);
        if (!out) {
            std::cerr << "Failed to open output file for " << entry.path() << "\n";
            continue;
        }

        while (pgn) {
            GameData game = parse_game(pgn);
            if (game.moves.empty()) {
                continue;
            }

            auto pos_opt = Position::parse(game.start_fen);
            if (!pos_opt) {
                continue;
            }
            Position pos = *pos_opt;

            std::vector<std::string> candidates;

            for (size_t i = 0; i < game.moves.size(); i++) {
                const auto& san      = game.moves[i];
                auto        move_opt = Move::parseSan(san, pos);
                if (!move_opt) {
                    break;
                }
                Move move = *move_opt;

                pos.do_move(move);

                bool next_noisy = false;
                if (i + 1 < game.moves.size()) {
                    auto next_move_opt = Move::parseSan(game.moves[i + 1], pos);
                    if (next_move_opt) {
                        next_noisy = is_noisy(*next_move_opt);
                    }
                }

                if (!next_noisy && !pos.in_check()) {
                    std::ostringstream fen;
                    fen << pos;
                    candidates.push_back(fen.str());
                }
            }

            std::shuffle(candidates.begin(), candidates.end(), rng);
            int sample_count = std::min((int)candidates.size(), 10);
            for (int i = 0; i < sample_count; i++) {
                out << candidates[i] << ";" << game.result << "\n";
            }
        }
    }
}

}