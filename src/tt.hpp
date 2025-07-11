#pragma once

#include "position.hpp"

namespace Clockwork {

enum Bound : u8 {
    None,
    Lower,
    Upper,
    Exact,
};

struct TTEntry {
    HashKey key;
    Move    move;
    i16     score;
    u8      depth;
    Bound   bound;
};


struct TTData {
    Move  move;
    Value score;
    Depth depth;
    Bound bound;
};

class TT {
public:
    static constexpr size_t DEFAULT_SIZE_MB = 16;
    static constexpr size_t TT_ALIGNMENT    = 64;

    TT(size_t mb = DEFAULT_SIZE_MB);
    ~TT();

    std::optional<TTData> probe(const Position& pos, i32 ply) const;
    void store(const Position& pos, i32 ply, Move move, Value score, Depth depth, Bound bound);
    void resize(size_t mb);
    void clear();

private:
    TTEntry* m_entries;
    size_t   m_size;
};

}
