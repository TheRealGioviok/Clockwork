// pgn_filter.hpp
#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace Clockwork::Filter {

struct GameData {
    std::string              start_fen;
    char                     result;  // 'w', 'b', 'd'
    std::vector<std::string> moves;
};

std::string extract_header_value(const std::string& line);
bool        is_mate_token(const std::string& token);
GameData    parse_game(std::istream& in);
void        filter_pgn(std::istringstream& is);

}