#include "test.hpp"
#include "tuning/pgn.hpp"
#include <iostream>
#include <sstream>
#include <string_view>

using namespace Clockwork;
using namespace Clockwork::Tuning;

namespace {

void quiet_game_all_eligible() {
    auto game = parse_pgn_game("[Result \"1-0\"]\n"
                               "\n"
                               "e4 {+0.2/10} e5 {-0.1/10} Nf3 {+0.3/11} Nc6 {-0.2/11} "
                               "Bb5 {+0.4/12} 1-0\n");
    REQUIRE(game);
    REQUIRE(game->result == GameResult::WhiteWin);
    REQUIRE(game->moves.size() == 5);
    REQUIRE(game->flags.size() == 5);
    for (u8 flags : game->flags) {
        REQUIRE(is_eligible(flags));
        REQUIRE(phase_of(flags) == 24);
    }
}

void move_numbers_and_no_comments() {
    auto game = parse_pgn_game("[Result \"0-1\"]\n"
                               "\n"
                               "1. e4 e5 2. Nf3 Nc6 0-1\n");
    REQUIRE(game);
    REQUIRE(game->result == GameResult::BlackWin);
    REQUIRE(game->moves.size() == 4);
}

void captures_make_previous_position_ineligible() {
    auto game = parse_pgn_game("[Result \"1/2-1/2\"]\n"
                               "\n"
                               "e4 d5 exd5 Qxd5 1/2-1/2\n");
    REQUIRE(game);
    REQUIRE(game->result == GameResult::Draw);
    REQUIRE(game->flags.size() == 4);
    REQUIRE(is_eligible(game->flags[0]));   // after e4, next move d5 is quiet
    REQUIRE(!is_eligible(game->flags[1]));  // after d5, next move exd5 is a capture
    REQUIRE(!is_eligible(game->flags[2]));  // after exd5, next move Qxd5 is a capture
    REQUIRE(is_eligible(game->flags[3]));   // final position, legal moves exist
}

void checks_are_ineligible() {
    auto game = parse_pgn_game("[Result \"1-0\"]\n"
                               "\n"
                               "e4 e5 Qh5 Nc6 Qxf7+ 1-0\n");
    REQUIRE(game);
    REQUIRE(game->flags.size() == 5);
    REQUIRE(!is_eligible(game->flags[3]));  // after Nc6, next move Qxf7+ is a capture
    REQUIRE(!is_eligible(game->flags[4]));  // after Qxf7+, black is in check
}

void mate_scores_taint_rest_of_game() {
    auto game = parse_pgn_game("[Result \"1-0\"]\n"
                               "\n"
                               "e4 {+0.5/10} e5 {-0.5/10} Nf3 {+M5/12} Nc6 {-M4/12} "
                               "Bb5 {+M3/12} 1-0\n");
    REQUIRE(game);
    REQUIRE(game->flags.size() == 5);
    REQUIRE(is_eligible(game->flags[0]));
    REQUIRE(is_eligible(game->flags[1]));
    REQUIRE(!is_eligible(game->flags[2]));  // Nf3 carries the first mate annotation
    REQUIRE(!is_eligible(game->flags[3]));
    REQUIRE(!is_eligible(game->flags[4]));
}

void checkmate_final_position() {
    auto game = parse_pgn_game("[Result \"0-1\"]\n"
                               "\n"
                               "f3 e5 g4 Qh4# 0-1\n");
    REQUIRE(game);
    REQUIRE(game->flags.size() == 4);
    REQUIRE(is_eligible(game->flags[2]));   // after g4: quiet next move, not in check
    REQUIRE(!is_eligible(game->flags[3]));  // white is checkmated
}

void stalemate_final_position() {
    auto game = parse_pgn_game("[FEN \"k7/8/1Q6/8/8/8/8/K7 w - - 0 1\"]\n"
                               "[Result \"1/2-1/2\"]\n"
                               "\n"
                               "Qc7 {+0.0/10} 1/2-1/2\n");
    REQUIRE(game);
    REQUIRE(game->flags.size() == 1);
    REQUIRE(!is_eligible(game->flags[0]));  // stalemate: no legal moves
    REQUIRE(phase_of(game->flags[0]) == 4);
}

void promotion_next_move_ineligible() {
    auto game = parse_pgn_game("[FEN \"8/4P3/8/8/8/8/k7/2K5 w - - 0 1\"]\n"
                               "[Result \"1-0\"]\n"
                               "\n"
                               "Kd2 Ka3 e8=Q 1-0\n");
    REQUIRE(game);
    REQUIRE(game->flags.size() == 3);
    REQUIRE(is_eligible(game->flags[0]));
    REQUIRE(!is_eligible(game->flags[1]));  // after Ka3, next move e8=Q is a promotion
    REQUIRE(is_eligible(game->flags[2]));
    REQUIRE(phase_of(game->flags[0]) == 0);
    REQUIRE(phase_of(game->flags[2]) == 4);  // promoted queen
}

void frc_castling_game() {
    auto game = parse_pgn_game("[FEN \"r2k1br1/1pp2ppp/2n4n/p3p3/2B1P1b1/1P3N1P/P1PN1PPR/R1B1K3 b"
                               " Q - 0 10\"]\n"
                               "[Result \"1-0\"]\n"
                               "\n"
                               "Bd7 {-0.46/10} Bb2 {+0.43/9} Bd6 {-0.53/10} O-O-O {+0.50/10} "
                               "a4 {-0.49/11} 1-0\n");
    REQUIRE(game);
    REQUIRE(game->moves.size() == 5);
    REQUIRE(game->moves[3].is_castle());
}

void malformed_games_rejected() {
    // No result header
    REQUIRE(!parse_pgn_game("[Event \"x\"]\n\ne4 e5 *\n"));
    // Unknown result value
    REQUIRE(!parse_pgn_game("[Result \"*\"]\n\ne4 e5 *\n"));
    // Illegal move
    REQUIRE(!parse_pgn_game("[Result \"1-0\"]\n\ne4 e4 1-0\n"));
    // Unparseable move
    REQUIRE(!parse_pgn_game("[Result \"1-0\"]\n\ne4 zz9 1-0\n"));
    // Variations unsupported
    REQUIRE(!parse_pgn_game("[Result \"1-0\"]\n\ne4 ( d4 ) e5 1-0\n"));
    // No moves
    REQUIRE(!parse_pgn_game("[Result \"1-0\"]\n\n1-0\n"));
}

void splitter_splits_on_event() {
    std::istringstream stream("[Event \"a\"]\n"
                              "[Result \"1-0\"]\n"
                              "\n"
                              "e4 e5 1-0\n"
                              "\n"
                              "[Event \"b\"]\n"
                              "[Result \"0-1\"]\n"
                              "\n"
                              "d4 {+0.1/9\n"
                              "1.0s} d5 0-1\n");
    PgnSplitter        splitter{stream};

    auto first = splitter.next();
    REQUIRE(first);
    auto game1 = parse_pgn_game(*first);
    REQUIRE(game1);
    REQUIRE(game1->result == GameResult::WhiteWin);
    REQUIRE(game1->moves.size() == 2);

    auto second = splitter.next();
    REQUIRE(second);
    auto game2 = parse_pgn_game(*second);
    REQUIRE(game2);
    REQUIRE(game2->result == GameResult::BlackWin);
    REQUIRE(game2->moves.size() == 2);

    REQUIRE(!splitter.next());
}

}  // namespace

int main() {
    quiet_game_all_eligible();
    move_numbers_and_no_comments();
    captures_make_previous_position_ineligible();
    checks_are_ineligible();
    mate_scores_taint_rest_of_game();
    checkmate_final_position();
    stalemate_final_position();
    promotion_next_move_ineligible();
    frc_castling_game();
    malformed_games_rejected();
    splitter_splits_on_event();
    return 0;
}
