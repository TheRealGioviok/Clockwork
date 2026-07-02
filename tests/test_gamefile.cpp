#include "test.hpp"
#include "tuning/gamefile.hpp"
#include "tuning/pgn.hpp"
#include <sstream>
#include <string_view>
#include <vector>

using namespace Clockwork;
using namespace Clockwork::Tuning;

namespace {

std::vector<PgnGame> sample_games() {
    std::vector<std::string_view> pgns{
      // Odd move count, standard position
      "[Result \"1-0\"]\n"
      "\n"
      "e4 {+0.2/10} e5 {-0.1/10} Nf3 {+0.3/11} Nc6 {-0.2/11} Bb5 {+0.4/12} 1-0\n",
      // Even move count, capture + en passant square along the way
      "[Result \"1/2-1/2\"]\n"
      "\n"
      "e4 d5 exd5 Qxd5 1/2-1/2\n",
      // DFRC-style start position with partial castling rights and a castle move
      "[FEN \"r2k1br1/1pp2ppp/2n4n/p3p3/2B1P1b1/1P3N1P/P1PN1PPR/R1B1K3 b Q - 0 10\"]\n"
      "[Result \"0-1\"]\n"
      "\n"
      "Bd7 {-0.46/10} Bb2 {+0.43/9} Bd6 {-0.53/10} O-O-O {+0.50/10} a4 {-0.49/11} 0-1\n",
      // Promotion, sparse board, black to move first
      "[FEN \"8/4P3/8/8/8/8/k7/2K5 w - - 3 42\"]\n"
      "[Result \"1-0\"]\n"
      "\n"
      "Kd2 Ka3 e8=Q Ka2 1-0\n",
    };

    std::vector<PgnGame> games;
    for (std::string_view pgn : pgns) {
        auto game = parse_pgn_game(pgn);
        REQUIRE(game);
        games.push_back(std::move(*game));
    }
    return games;
}

std::vector<u8> to_bytes(const std::string& s) {
    return std::vector<u8>(s.begin(), s.end());
}

void roundtrip() {
    std::vector<PgnGame> games = sample_games();

    std::stringstream stream;
    CkgWriter         writer{stream};
    for (const PgnGame& game : games) {
        writer.write(game);
    }
    writer.finish();
    REQUIRE(writer.games_written() == games.size());

    std::vector<u8> data   = to_bytes(stream.str());
    auto            reader = CkgReader::open(data);
    REQUIRE(reader);
    REQUIRE(reader->game_count() == games.size());

    for (const PgnGame& game : games) {
        auto view = reader->next();
        REQUIRE(view);
        REQUIRE(view->result == game.result);

        REQUIRE(view->moves.size() == game.moves.size());
        for (usize i = 0; i < game.moves.size(); i++) {
            REQUIRE(view->moves[i] == game.moves[i].raw);
        }

        REQUIRE(view->flags.size() == game.flags.size());
        for (usize i = 0; i < game.flags.size(); i++) {
            REQUIRE(view->flags[i] == game.flags[i]);
        }

        auto start = reconstruct_start_position(*view);
        REQUIRE(start);
        REQUIRE(*start == game.start);
    }

    REQUIRE(!reader->next());
    REQUIRE(reader->games_read() == games.size());
}

void rejects_bad_data() {
    std::vector<PgnGame> games = sample_games();

    std::stringstream stream;
    CkgWriter         writer{stream};
    for (const PgnGame& game : games) {
        writer.write(game);
    }
    writer.finish();
    std::vector<u8> data = to_bytes(stream.str());

    // Bad magic
    {
        std::vector<u8> bad = data;
        bad[0] ^= 0xFF;
        REQUIRE(!CkgReader::open(bad));
    }
    // Bad version
    {
        std::vector<u8> bad = data;
        bad[4] ^= 0xFF;
        REQUIRE(!CkgReader::open(bad));
    }
    // Truncated mid-record: reader stops early instead of reading out of bounds
    {
        std::vector<u8> bad{data.begin(), data.begin() + static_cast<isize>(data.size() - 7)};
        auto            reader = CkgReader::open(bad);
        REQUIRE(reader);
        while (reader->next()) {}
        REQUIRE(reader->games_read() < reader->game_count());
    }
    // Too short for a header
    {
        std::vector<u8> bad{data.begin(), data.begin() + 8};
        REQUIRE(!CkgReader::open(bad));
    }
}

}  // namespace

int main() {
    roundtrip();
    rejects_bad_data();
    return 0;
}
