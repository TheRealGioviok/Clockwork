#pragma once

#include <array>
#include <optional>

#include "history.hpp"
#include "movegen.hpp"
#include "position.hpp"


namespace Clockwork {

bool quiet_move(Move move);

class MovePicker {
public:
    explicit MovePicker(const Position& pos,
                        const History&  history,
                        Move            tt_move = Move::none(),
                        Move            killer  = Move::none()) :
        m_pos(pos),
        m_history(history),
        m_movegen(pos),
        m_tt_move(tt_move),
        m_killer(killer) {
    }

    void skip_quiets();

    Move next();

    [[nodiscard]] bool is_legal(Move m) const {
        return m_movegen.is_legal(m);
    }

private:
    enum class Stage {
        EmitTTMove,
        GenerateMoves,
        ScoreNoisy,
        EmitGoodNoisy,
        EmitKiller,
        ScoreQuiet,
        EmitQuiet,
        EmitBadNoisy,
        End,
    };

    void generate_moves();
    Move pick_next(MoveList& moves);
    void score_moves(MoveList& moves);

    i32 score_move(Move move) const;

    Stage m_stage = Stage::EmitTTMove;

    const Position&      m_pos;
    const History&       m_history;
    MoveGen              m_movegen;
    MoveList             m_noisy;
    MoveList             m_quiet;
    MoveList             m_bad_noisy;
    usize                m_current_index = 0;
    bool                 m_skip_quiets   = false;
    std::array<i32, 256> m_scores;

    Move m_tt_move;
    Move m_killer;
};

}
