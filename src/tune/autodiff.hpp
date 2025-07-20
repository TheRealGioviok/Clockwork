#pragma once

#include "../util/types.hpp"
#include <cmath>
#include <cstring>
#include <functional>
#include <future>
#include <memory>
#include <optional>
#include <string>
#include <unordered_set>
#include <array>
#include <vector>

// --- Autograd core ---------------------------------------------------------
#ifdef ENABLE_TUNING
namespace Clockwork::Autograd {

// Forward declarations
class Node;
using NodePtr = std::shared_ptr<Node>;

class Node : public std::enable_shared_from_this<Node> {
public:
    f64 data{};
    f64 grad{};
    bool requires_grad;
    std::string name;
    std::vector<NodePtr> parents;
    std::function<void()> backward_fn;
    bool backward_called{false};

    Node(f64 v, const std::string& n = {}, bool req = false)
        : data(v), requires_grad(req), name(n) {}

    void backward() {
        if (!requires_grad || backward_called) return;
        backward_called = true;
        if (grad == 0) grad = 1;
        if (backward_fn) backward_fn();
        for (auto& p : parents) p->backward();
    }

    void zero_grad() {
        grad = 0;
        backward_called = false;
        for (auto& p : parents) p->zero_grad();
    }
};

// Scalar with gradient support
class Var {
public:
    NodePtr node;
    explicit Var(f64 v = 0, const std::string& n = {}, bool req = false)
        : node(std::make_shared<Node>(v, n, req)) {}

    f64 value() const { return node->data; }
    bool needs_grad() const { return node->requires_grad; }
    f64 gradient() const { return node->grad; }
    void backward() { node->backward(); }
    void zero_grad() { node->zero_grad(); }

    // Unary negation
    Var operator-() const { return Var(-value(), "(-" + node->name + ")", needs_grad()); }
};

// Alias for evaluation returns
using Score = Var;

// Binary op helper
inline Var make_op(const Var& a, const Var& b,
                   std::function<f64(f64, f64)> fwd,
                   std::function<void(const Var&)> bwd,
                   const std::string& op_name) {
    bool req = a.needs_grad() || b.needs_grad();
    Var out(fwd(a.value(), b.value()), "(" + a.node->name + op_name + b.node->name + ")", req);
    if (a.needs_grad()) out.node->parents.push_back(a.node);
    if (b.needs_grad()) out.node->parents.push_back(b.node);
    auto an = a.node;
    auto bn = b.node;
    out.node->backward_fn = [out_node = out.node, bwd]() mutable {
        bwd(Var(out_node));
    };
    return out;
}

// Arithmetic operators
inline Var operator+(const Var& a, const Var& b) { return make_op(a, b, [](f64 x, f64 y){return x+y;},
    [&](const Var& o){ if(a.needs_grad()) a.node->grad += o.gradient(); if(b.needs_grad()) b.node->grad += o.gradient(); }, "+"); }

inline Var operator-(const Var& a, const Var& b) { return make_op(a, b, [](f64 x, f64 y){return x-y;},
    [&](const Var& o){ if(a.needs_grad()) a.node->grad += o.gradient(); if(b.needs_grad()) b.node->grad -= o.gradient(); }, "-"); }

inline Var operator*(const Var& a, const Var& b) {
    f64 av = a.value(), bv = b.value();
    return make_op(a, b, [=](f64 x, f64 y){return x*y;},
        [=](const Var& o){ if(a.needs_grad()) a.node->grad += o.gradient()*bv; if(b.needs_grad()) b.node->grad += o.gradient()*av; }, "*");
}

inline Var operator/(const Var& a, const Var& b) {
    f64 av = a.value(), bv = b.value();
    return make_op(a, b, [=](f64 x, f64 y){return x/y;},
        [=](const Var& o){ if(a.needs_grad()) a.node->grad += o.gradient()/bv; if(b.needs_grad()) b.node->grad -= o.gradient()*av/(bv*bv); }, "/");
}

// Scalar overloads
inline Var operator+(const Var& a, f64 b) { return a + Var(b); }
inline Var operator+(f64 a, const Var& b) { return Var(a) + b; }
inline Var operator-(const Var& a, f64 b) { return a - Var(b); }
inline Var operator-(f64 a, const Var& b) { return Var(a) - b; }
inline Var operator*(const Var& a, f64 b) { return a * Var(b); }
inline Var operator*(f64 a, const Var& b) { return Var(a) * b; }
inline Var operator/(const Var& a, f64 b) { return a / Var(b); }
inline Var operator/(f64 a, const Var& b) { return Var(a) / b; }

// Extra functions
inline Var exp(const Var& a) { f64 e = std::exp(a.value()); return make_op(a,a,[=](f64,f64){return e;},[=](const Var& o){ if(a.needs_grad()) a.node->grad += o.gradient()*e; },"exp"); }
inline Var log(const Var& a) { return make_op(a,a,[](f64 x,f64){return std::log(x);},[&](const Var& o){ if(a.needs_grad()) a.node->grad += o.gradient()/a.value(); },"log"); }
inline Var sqrt(const Var& a) { return exp(log(a) * 0.5); }

// PhasedParam and alias S
class PhasedParam {
public:
    Var mg, eg;
    explicit PhasedParam(f64 m=0, f64 e=0, const std::string& n="") : mg(m,n+".mg",true), eg(e,n+".eg",true) {}
    // Unary negation
    PhasedParam operator-() const { return PhasedParam(-mg, -eg); }
    // Binary ops
    PhasedParam operator+(const PhasedParam& o) const { return PhasedParam(mg+o.mg, eg+o.eg); }
    PhasedParam operator-(const PhasedParam& o) const { return PhasedParam(mg-o.mg, eg-o.eg); }
    PhasedParam operator*(f64 s) const { return PhasedParam(mg*s, eg*s); }
    friend PhasedParam operator*(f64 s, const PhasedParam& p) { return p * s; }
    // Dot product
    Var dot(const PhasedParam& o) const { return mg*o.mg + eg*o.eg; }
    void backward() { mg.backward(); eg.backward(); }
    void zero_grad() { mg.zero_grad(); eg.zero_grad(); }
    // Pack/unpack
    i32 pack() const { int16_t m=int16_t(std::round(mg.value())), e=int16_t(std::round(eg.value())); return (i32(m)<<16)|uint16_t(e); }
    static PhasedParam unpack(i32 p,const std::string& n="") { int16_t m=int16_t(p>>16), e=int16_t(p&0xFFFF); return PhasedParam(m,e,n); }
    // Phased mix (with clamp)
    template<i32 MAX>
    Var phased(const Var& phase) const {
        f64 raw=phase.value(); f64 c=raw<0?0:(raw>MAX?MAX:raw);
        Var p(c);
        Var norm=p/static_cast<f64>(MAX);
        return mg*norm + eg*(Var(static_cast<f64>(MAX))-p)/static_cast<f64>(MAX);
    }
};
using S = PhasedParam;

// PSQT and PSQTs
enum class PieceType:int{Pawn=0,Knight,Bishop,Rook,Queen,King,Count};
class PSQT{
public:
    std::array<PhasedParam,64> table;
    explicit PSQT(const std::string& prefix="psqt"){
        for(int i=0;i<64;++i) table[i]=PhasedParam(0,0,prefix+"["+std::to_string(i)+"]");
    }
    PhasedParam& operator[](size_t i){return table[i];}
    PSQT operator+(const PSQT&o)const{PSQT out; for(int i=0;i<64;++i)out.table[i]=table[i]+o.table[i]; return out;}
    PSQT operator*(f64 s)const{PSQT out; for(int i=0;i<64;++i)out.table[i]=table[i]*s; return out;}
    PhasedParam sum(const std::vector<size_t>&sq)const{PhasedParam a; for(auto i:sq)a=a+table[i]; return a;}
    std::vector<i32> pack_all()const{std::vector<i32>v(64); for(int i=0;i<64;++i)v[i]=table[i].pack(); return v;}
    void zero_grad(){ for(auto& p:table)p.zero_grad(); }
};
class PSQTs{
public:
    std::array<PSQT,size_t(PieceType::Count)> tables;
    PSQTs(){ const char*n[]={"pawn","knight","bishop","rook","queen","king"}; for(int i=0;i<size_t(PieceType::Count);++i)tables[i]=PSQT(std::string("psqt_")+n[i]); }
    PSQT& get(PieceType pt){return tables[size_t(pt)];}
    PSQTs operator+(const PSQTs&o)const{PSQTs out; for(int i=0;i<tables.size();++i)out.tables[i]=tables[i]+o.tables[i]; return out;}
    PSQTs operator*(f64 s)const{PSQTs out; for(int i=0;i<tables.size();++i)out.tables[i]=tables[i]*s; return out;}
    std::vector<i32> pack_all()const{std::vector<i32>v; v.reserve(tables.size()*64); for(auto&t:tables){auto u=t.pack_all(); v.insert(v.end(),u.begin(),u.end());} return v;}
    void zero_grad(){ for(auto&t:tables)t.zero_grad(); }
};

// Optimizer
class SGD{
public:
    std::vector<Var*> params;
    f64 lr,m;
    std::unordered_map<Node*,f64>vel;
    SGD(const std::vector<Var*>&p,f64 lr_=1e-2,f64 m_=0.9):params(p),lr(lr_),m(m_){for(auto*v:params)if(v->needs_grad())vel[v->node.get()]=0;}
    void step(){for(auto*v:params)if(v->needs_grad()){auto*n=v->node.get();auto&vv=vel[n]; vv=m*vv-lr*n->grad; n->data+=vv;}}
    void zero_grad(){for(auto*v:params)v->zero_grad();}
};

} // namespace Clockwork::Autograd
#endif // ENABLE_TUNING

// --- Inference-mode PhasedParam and Evaluator -----------------------------
namespace Clockwork::HCE {

#ifdef ENABLE_TUNING
using Var   = Clockwork::Autograd::Var;
using Score = Clockwork::Autograd::Score;
using S     = Clockwork::Autograd::PhasedParam;
using PSQT  = Clockwork::Autograd::PSQT;
using PSQTs = Clockwork::Autograd::PSQTs;
#else
using Score = double;

// Inference-mode PhasedParam backed by packed i32
struct PhasedParam {
    i32 packed;
    explicit PhasedParam(i32 p = 0) : packed(p) {}
    PhasedParam(int16_t m, int16_t e) : packed((i32(m) << 16) | uint16_t(e)) {}

    // Unary negation
    PhasedParam operator-() const {
        int16_t m = -mg();
        int16_t e = -eg();
        return PhasedParam(m, e);
    }
    // Elementwise
    PhasedParam operator+(const PhasedParam& o) const { return PhasedParam(packed + o.packed); }
    PhasedParam operator-(const PhasedParam& o) const { return PhasedParam(packed - o.packed); }
    PhasedParam operator*(int scalar) const { return PhasedParam(packed * scalar); }
    friend PhasedParam operator*(int scalar, const PhasedParam& p) { return p * scalar; }

    // Access
    int16_t mg() const { return int16_t(packed >> 16); }
    int16_t eg() const { return int16_t(packed & 0xFFFF); }

    // Phased mix with clamp
    template<i32 MAX>
    int phased(int phase) const {
        int p = phase < 0 ? 0 : (phase > MAX ? MAX : phase);
        int32_t val = int32_t(mg()) * p + int32_t(eg()) * (MAX - p);
        return val / MAX;
    }
};
using S = PhasedParam;
#endif // ENABLE_TUNING

class Evaluator {
public:
    Evaluator()=default; virtual ~Evaluator()=default;
    virtual Score user_eval(const Position& pos) const = 0;
    Score evaluate(const Position& pos) const { return user_eval(pos); }
    Score evaluate(const std::string& fen) const { auto pos=Position::parse(fen); return evaluate(pos); }
    template<typename Position>
    std::vector<Score> evaluate(const std::vector<Position>&v,int threads=1) const {
        std::vector<std::future<Score>>f;
        std::vector<Score>out; out.reserve(v.size());
        if(threads>1){for(size_t i=0;i<v.size();++i)f.push_back(std::async(std::launch::async,[this,&v,i](){return evaluate(v[i]);}));for(auto&X:f)out.push_back(X.get());}
        else for(auto&p:v) out.push_back(evaluate(p));
        return out;
    }
};

// Lets replicate our current eval to an evaluator so we can train it
PhasedParam PAWN_MAT = S(100, 100);
PhasedParam KNIGHT_MAT = S(300, 300);
PhasedParam BISHOP_MAT = S(300, 300);
PhasedParam ROOK_MAT = S(500, 500);
PhasedParam QUEEN_MAT = S(900, 900);
PhasedParam MOBILITY_VAL = S(10, 10);
PhasedParam TEMPO_VAL = S(0, 0);

class MyEvaluator : public Evaluator {
public:
    MyEvaluator() = default;
    ~MyEvaluator() override = default;

    Score user_eval(const Position& pos) const override {
        const Color us   = pos.active_color();
        const Color them = invert(us);

        Value phase = (pos.piece_count(us, PieceType::Knight) + pos.piece_count(them, PieceType::Knight))
                    + (pos.piece_count(us, PieceType::Bishop) + pos.piece_count(them, PieceType::Bishop))
                    + 2 * (pos.piece_count(us, PieceType::Rook) + pos.piece_count(them, PieceType::Rook))
                    + 4 * (pos.piece_count(us, PieceType::Queen) + pos.piece_count(them, PieceType::Queen));
        
        PhasedParam material = 
            PAWN_MAT * (pos.piece_count(us, PieceType::Pawn) - pos.piece_count(them, PieceType::Pawn)) +
            KNIGHT_MAT * (pos.piece_count(us, PieceType::Knight) - pos.piece_count(them, PieceType::Knight)) +
            BISHOP_MAT * (pos.piece_count(us, PieceType::Bishop) - pos.piece_count(them, PieceType::Bishop)) +
            ROOK_MAT * (pos.piece_count(us, PieceType::Rook) - pos.piece_count(them, PieceType::Rook)) +
            QUEEN_MAT * (pos.piece_count(us, PieceType::Queen) - pos.piece_count(them, PieceType::Queen));
        
        PhasedParam mobility = S(0,0);
        for (u64 x : std::bit_cast<std::array<u64, 16>>(pos.attack_table(us))) {
            mobility = mobility + MOBILITY_VAL * std::popcount(x);
        }
        for (u64 x : std::bit_cast<std::array<u64, 16>>(pos.attack_table(them))) {
            mobility = mobility - MOBILITY_VAL * std::popcount(x);
        }   

        PhasedParam tempoBonus = (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;

        // Combine all features
        PhasedParam total = material + mobility + tempoBonus;

        // Get the final score
        Score score = total.phased<24>(phase);

        return score;

    }
};

} // namespace Clockwork::HCE
