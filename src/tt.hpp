#pragma once

#include "position.hpp"

namespace Clockwork {

enum Bound : u8 {
    None  = 0,
    Lower = 1,
    Upper = 2,
    Exact = 3,
};

struct TTEntry {
    HashKey key;
    Move    move;
    i16     score;
    u8      depth;
    u8      ttpv_bound;
};


struct TTData {
    Move  move;
    Value score;
    Depth depth;
    u8    ttpv_bound;

    [[nodiscard]] Bound bound() const {
        return static_cast<Bound>(ttpv_bound & 0b011);
    }
    [[nodiscard]] bool ttpv() const {
        return static_cast<bool>(ttpv_bound & 0b100);
    }
};

class TT {
public:
    static constexpr size_t DEFAULT_SIZE_MB = 16;
    static constexpr size_t TT_ALIGNMENT    = 64;

    TT(size_t mb = DEFAULT_SIZE_MB);
    ~TT();

    std::optional<TTData> probe(const Position& pos, i32 ply) const;
    void                  store(
                       const Position& pos, i32 ply, Move move, Value score, Depth depth, bool ttpv, Bound bound);
    void resize(size_t mb);
    void clear();

private:
    TTEntry* m_entries;
    size_t   m_size;
};

}
