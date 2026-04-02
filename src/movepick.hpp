#pragma once

#include "history.hpp"
#include "movegen.hpp"
#include "position.hpp"
#include "search.hpp"
#include <array>
#include <optional>

namespace Clockwork {

bool quiet_move(Move move);

class MovePicker {
public:
    struct MainSearchTag { };
    struct QSearchTag { };
    struct QSearchEvasionsTag { };
    struct ProbCutTag { };

    static constexpr MainSearchTag      MainSearch{};
    static constexpr QSearchTag         QSearch{};
    static constexpr QSearchEvasionsTag QSearchEvasions{};
    static constexpr ProbCutTag         ProbCut{};

    explicit MovePicker(MainSearchTag,
                        const Position& pos,
                        const History&  history,
                        Move            tt_move,
                        i32             ply,
                        Search::Stack*  ss) :
        m_stage(Stage::EmitTTMove),
        m_pos(pos),
        m_history(history),
        m_movegen(pos),
        m_tt_move(tt_move),
        m_killer(ss->killer),
        m_ply(ply),
        m_stack(ss) {
    }

    explicit MovePicker(QSearchTag,
                        const Position& pos,
                        const History&  history,
                        Move            tt_move,
                        i32             ply,
                        Search::Stack*  ss) :
        m_stage(Stage::QSearchEmitTTMove),
        m_pos(pos),
        m_history(history),
        m_movegen(pos),
        m_tt_move(tt_move),
        m_killer(Move::none()),
        m_ply(ply),
        m_stack(ss) {
    }

    explicit MovePicker(QSearchEvasionsTag,
                        const Position& pos,
                        const History&  history,
                        Move            tt_move,
                        i32             ply,
                        Search::Stack*  ss) :
        m_stage(Stage::EvasionsEmitTTMove),
        m_pos(pos),
        m_history(history),
        m_movegen(pos),
        m_tt_move(tt_move),
        m_killer(Move::none()),
        m_ply(ply),
        m_stack(ss) {
    }

    explicit MovePicker(
      ProbCutTag, const Position& pos, const History& history, Move tt_move, Value threshold) :
        m_stage(Stage::ProbCutEmitTTMove),
        m_pos(pos),
        m_history(history),
        m_movegen(pos),
        m_tt_move(tt_move),
        m_killer(Move::none()),
        m_ply(0),
        m_stack(nullptr),
        m_threshold(threshold) {
    }

    enum class Stage {
        EmitTTMove,
        GenerateMoves,
        ScoreNoisy,
        EmitGoodNoisy,
        EmitKiller,
        ScoreQuiet,
        EmitQuiet,
        EmitBadNoisy,

        QSearchEmitTTMove,
        QSearchGenerateMoves,
        QSearchScoreNoisy,
        QSearchEmitNoisy,

        EvasionsEmitTTMove,
        EvasionsGenerateMoves,
        EvasionsScoreNoisy,
        EvasionsEmitNoisy,
        EvasionsScoreQuiet,
        EvasionsEmitQuiet,

        ProbCutEmitTTMove,
        ProbCutGenerateMoves,
        ProbCutScoreNoisy,
        ProbCutEmitNoisy,

        End,
    };

    void skip_quiets();

    Move next();

    [[nodiscard]] Stage stage() const {
        return m_stage;
    }

    [[nodiscard]] bool is_legal(Move m) const {
        return m_movegen.is_legal(m);
    }

private:
    std::pair<Move, i32> pick_next(MoveList& moves);

    template<bool quiets>
    i32 score_move(Move move) const;

    template<bool quiets>
    inline void score_moves(MoveList& moves) {
        for (usize i = 0; i < moves.size(); i++) {
            m_scores[i] = score_move<quiets>(moves[i]);
        }
    }

    Stage m_stage;

    const Position&      m_pos;
    const History&       m_history;
    MoveGen              m_movegen;
    MoveList             m_noisy;
    MoveList             m_quiet;
    MoveList             m_bad_noisy;
    usize                m_current_index = 0;
    bool                 m_skip_quiets   = false;
    std::array<i32, 256> m_scores;

    Move                 m_tt_move;
    Move                 m_killer;
    i32                  m_ply;
    Search::Stack*       m_stack;
    std::optional<Value> m_threshold;
};

// Random movepicker class for data generation. It won't score moves, just pick them randomly.
class RandomMovePicker {
public:
    explicit RandomMovePicker(const Position& pos) :
        m_movegen(pos) {
        m_movegen.generate_moves(m_noisy, m_quiet);
    };

    Move next();

private:
    MoveGen  m_movegen;
    MoveList m_noisy;
    MoveList m_quiet;
};

}  // namespace Clockwork
