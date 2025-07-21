#pragma once

#include "../util/types.hpp"
#include "../common.hpp"
#include "../position.hpp"
#include <cmath>
#include <cstring>
#include <functional>
#include <future>
#include <memory>
#include <optional>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <vector>

#define ENABLE_TUNING

#ifdef ENABLE_TUNING // Wow i wonder if this is enabled
namespace Clockwork::Autograd {

// Forward decl
class Node;
using NodePtr = std::shared_ptr<Node>;

// Batch-aware Node that can hold multiple values
class Node : public std::enable_shared_from_this<Node> {
public:
    std::vector<f64> data;
    std::vector<f64> grad;
    bool requires_grad;
    std::string name;
    std::vector<std::weak_ptr<Node>> parents; // <-- gpt told me to use weak_ptr here to fix the leak. It did not. Clearly my cleanup is not working
    std::function<void()> backward_fn;
    bool backward_called{false};
    size_t batch_size{1};

    Node(f64 v, const std::string& n = {}, bool req = false)
        : data({v}), grad({0}), requires_grad(req), name(n), batch_size(1) {}
    
    Node(const std::vector<f64>& v, const std::string& n = {}, bool req = false)
        : data(v), grad(std::vector<f64>(v.size(), 0)), requires_grad(req), name(n), batch_size(v.size()) {}

    void backward() {
        if (!requires_grad || backward_called) return;
        backward_called = true;
        for (size_t i = 0; i < batch_size; ++i) {
            if (grad[i] == 0) grad[i] = 1;
        }
        if (backward_fn) backward_fn();
        for (auto& wp : parents) {
            if (auto p = wp.lock()) p->backward();
        }
    }

    void zero_grad() {
        std::fill(grad.begin(), grad.end(), 0);
        backward_called = false;
        for (auto& wp : parents) {
            if (auto p = wp.lock()) p->zero_grad(); // Something something lock here not good
        }
    }

    void clear_graph() {
        parents.clear();
        backward_fn = nullptr;
        backward_called = false;
        std::fill(grad.begin(), grad.end(), 0); // ?
    }

};

// Scalar with gradient support
class Var {
public:
    NodePtr node;
    size_t batch_idx{0}; // Index in the batch for this variable

    explicit Var(f64 v = 0, const std::string& n = {}, bool req = false)
        : node(std::make_shared<Node>(v, n, req)), batch_idx(0) {}
    
    // Batch constructor
    explicit Var(const std::vector<f64>& v, const std::string& n = {}, bool req = false)
        : node(std::make_shared<Node>(v, n, req)), batch_idx(0) {}

    // NodePtr constructor
    explicit Var(NodePtr n, size_t idx = 0) : node(n), batch_idx(idx) {}

    f64 value() const { return batch_idx < node->data.size() ? node->data[batch_idx] : 0; }
    bool needs_grad() const { return node->requires_grad; }
    f64 gradient() const { return batch_idx < node->grad.size() ? node->grad[batch_idx] : 0; }
    
    void backward() { node->backward(); }
    void zero_grad() { node->zero_grad(); }
    void clear_graph() { node->clear_graph(); }

    size_t batch_size() const { return node->batch_size; }

    // Unary negation because i need it in eval i think
    Var operator-() const { 
        if (node->batch_size == 1) {
            return Var(-value(), "(-" + node->name + ")", needs_grad()); 
        } else {
            std::vector<f64> neg_data(node->data.size());
            for (size_t i = 0; i < node->data.size(); ++i) {
                neg_data[i] = -node->data[i];
            }
            return Var(neg_data, "(-" + node->name + ")", needs_grad());
        }
    }
};

// Alias for evaluation returns. My handling of aliases is very confusing probably
using Score = Var;

// There is probably a design pattern name for this. Most of the headaches to come probably come from me trying to handle batches rather than doing per position graph book keeping (to cite jw).
inline Var make_batch_op(const Var& a, const Var& b,
                        std::function<f64(f64, f64)> fwd,
                        std::function<void(size_t, const Var&, const Var&, const Var&)> bwd,
                        const std::string& op_name) {
    bool req = a.needs_grad() || b.needs_grad();
    
    // Determine batch size
    size_t max_batch = std::max(a.batch_size(), b.batch_size());
    
    std::vector<f64> result_data(max_batch);
    
    // Handle broadcasting
    for (size_t i = 0; i < max_batch; ++i) {
        f64 a_val = (a.batch_size() == 1) ? a.node->data[0] : a.node->data[i];
        f64 b_val = (b.batch_size() == 1) ? b.node->data[0] : b.node->data[i];
        result_data[i] = fwd(a_val, b_val);
    }
    
    Var out(result_data, "(" + a.node->name + op_name + b.node->name + ")", req);
    
    if (a.needs_grad()) out.node->parents.push_back(a.node);
    if (b.needs_grad()) out.node->parents.push_back(b.node);
    
    // Capture nodes for backward pass
    auto an = a.node;
    auto bn = b.node;
    auto a_batch_size = a.batch_size();
    auto b_batch_size = b.batch_size();
    
    // Set the backward function. I have never had to use a mutable lambda before, which is telling
    out.node->backward_fn = [out_node = out.node, bwd, an, bn, a_batch_size, b_batch_size, req_a = a.needs_grad(), req_b = b.needs_grad()]() mutable {
        for (size_t i = 0; i < out_node->batch_size; ++i) {
            Var out_view(out_node);
            out_view.batch_idx = i;
            Var a_view(an);
            a_view.batch_idx = (a_batch_size == 1) ? 0 : i;
            Var b_view(bn);
            b_view.batch_idx = (b_batch_size == 1) ? 0 : i;
            
            bwd(i, out_view, a_view, b_view);
        }
    };
    
    return out;
}

// Binary op helper for single values 
inline Var make_op(const Var& a, const Var& b,
                   std::function<f64(f64, f64)> fwd,
                   std::function<void(const Var&)> bwd,
                   const std::string& op_name) {
    // Convert to batch-aware version
    auto batch_bwd = [bwd](size_t idx, const Var& out, const Var& a_view, const Var& b_view) {
        // Pass output gradient to both a_view and b_view if they need grad
        if (a_view.needs_grad()) {
            Var temp_a(a_view.value(), a_view.node->name, false);
            temp_a.node->grad[0] = out.gradient();
            bwd(temp_a);
            a_view.node->grad[a_view.batch_idx] += temp_a.node->grad[0];
        }
        if (b_view.needs_grad()) {
            Var temp_b(b_view.value(), b_view.node->name, false);
            temp_b.node->grad[0] = out.gradient();
            bwd(temp_b);
            b_view.node->grad[b_view.batch_idx] += temp_b.node->grad[0];
        }
    };
    return make_batch_op(a, b, fwd, batch_bwd, op_name);
}

// Arithmetic operators. Maybe optimizable by having different operators for different combinations of needs_grad, no need to do that now
inline Var operator+(const Var& a, const Var& b) { 
    return make_batch_op(a, b, [](f64 x, f64 y){return x+y;},
        [](size_t i, const Var& o, const Var& a_view, const Var& b_view){ 
            if(a_view.needs_grad()) {
                size_t a_idx = (a_view.node->batch_size == 1) ? 0 : i;
                a_view.node->grad[a_idx] += o.gradient(); 
            }
            if(b_view.needs_grad()) {
                size_t b_idx = (b_view.node->batch_size == 1) ? 0 : i;
                b_view.node->grad[b_idx] += o.gradient(); 
            }
        }, "+"); 
}

inline Var operator-(const Var& a, const Var& b) { 
    return make_batch_op(a, b, [](f64 x, f64 y){return x-y;},
        [](size_t i, const Var& o, const Var& a_view, const Var& b_view){ 
            if(a_view.needs_grad()) {
                size_t a_idx = (a_view.node->batch_size == 1) ? 0 : i;
                a_view.node->grad[a_idx] += o.gradient(); 
            }
            if(b_view.needs_grad()) {
                size_t b_idx = (b_view.node->batch_size == 1) ? 0 : i;
                b_view.node->grad[b_idx] -= o.gradient(); 
            }
        }, "-"); 
}

inline Var operator*(const Var& a, const Var& b) {
    return make_batch_op(a, b, [](f64 x, f64 y){return x*y;},
        [](size_t i, const Var& o, const Var& a_view, const Var& b_view){ 
            f64 a_val = a_view.value();
            f64 b_val = b_view.value();
            if(a_view.needs_grad()) {
                size_t a_idx = (a_view.node->batch_size == 1) ? 0 : i;
                a_view.node->grad[a_idx] += o.gradient() * b_val; 
            }
            if(b_view.needs_grad()) {
                size_t b_idx = (b_view.node->batch_size == 1) ? 0 : i;
                b_view.node->grad[b_idx] += o.gradient() * a_val; 
            }
        }, "*");
}

inline Var operator/(const Var& a, const Var& b) {
    return make_batch_op(a, b, [](f64 x, f64 y){return x/y;},
        [](size_t i, const Var& o, const Var& a_view, const Var& b_view){ 
            f64 a_val = a_view.value();
            f64 b_val = b_view.value();
            if(a_view.needs_grad()) {
                size_t a_idx = (a_view.node->batch_size == 1) ? 0 : i;
                a_view.node->grad[a_idx] += o.gradient() / b_val; 
            }
            if(b_view.needs_grad()) {
                size_t b_idx = (b_view.node->batch_size == 1) ? 0 : i;
                b_view.node->grad[b_idx] -= o.gradient() * a_val / (b_val * b_val); 
            }
        }, "/");
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

// PhasedParam for innate handling of phase params
class PhasedParam {
public:
    Var mg, eg;
    explicit PhasedParam(f64 m=0, f64 e=0, const std::string& n="") : mg(m,n+".mg",true), eg(e,n+".eg",true) {}
    
    // Batch constructor
    explicit PhasedParam(const std::vector<f64>& m_vals, const std::vector<f64>& e_vals, const std::string& n="") 
        : mg(m_vals, n+".mg", true), eg(e_vals, n+".eg", true) {}
    
    // Var constructor
    PhasedParam(const Var& m, const Var& e, const std::string& n = "")
        : mg(m), eg(e) {}

    // Unary negation
    PhasedParam operator-() const { return PhasedParam(-mg, -eg); }
    
    // Binary ops
    PhasedParam operator+(const PhasedParam& o) const { return PhasedParam(mg+o.mg, eg+o.eg); }
    PhasedParam operator-(const PhasedParam& o) const { return PhasedParam(mg-o.mg, eg-o.eg); }
    PhasedParam operator*(f64 s) const { return PhasedParam(mg*s, eg*s); }
    friend PhasedParam operator*(f64 s, const PhasedParam& p) { return p * s; }
    
    // Dot product
    Var dot(const PhasedParam& o) const { return mg*o.mg + eg*o.eg; }

    // Training stuff
    void backward() { mg.backward(); eg.backward(); }
    void zero_grad() { mg.zero_grad(); eg.zero_grad(); }
    
    // Pack/unpack
    i32 pack() const { int16_t m=int16_t(std::round(mg.value())), e=int16_t(std::round(eg.value())); return (i32(m)<<16)|uint16_t(e); }
    static PhasedParam unpack(i32 p,const std::string& n="") { int16_t m=int16_t(p>>16), e=int16_t(p&0xFFFF); return PhasedParam(m,e,n); }
    
    // Phased util (with clamp because of early promotions (cpw slop))
    template<i32 MAX>
    Var phased(const Var& phase) const {
        f64 raw=phase.value(); f64 c=raw<0?0:(raw>MAX?MAX:raw);
        Var p(c);
        Var norm=p/static_cast<f64>(MAX);
        return mg*norm + eg*(Var(static_cast<f64>(MAX))-p)/static_cast<f64>(MAX);
    }
};
using S = PhasedParam; // Told you i suck at alias handling

class SGD{
public:
    std::vector<Var*> params;
    f64 lr,m;
    std::unordered_map<Node*,std::vector<f64>>vel;
    
    SGD(const std::vector<Var*>&p,f64 lr_=1e-2,f64 m_=0.9):params(p),lr(lr_),m(m_){
        for(auto*v:params) {
            if(v->needs_grad()) {
                vel[v->node.get()] = std::vector<f64>(v->node->batch_size, 0);
            }
        }
    }
    
    void step(){
        for(auto*v:params) {
            if(v->needs_grad()) {
                auto*n=v->node.get();
                auto&vv=vel[n]; 
                
                // Ensure velocity vector matches current batch size
                if (vv.size() != n->batch_size) {
                    vv.resize(n->batch_size, 0);
                }
                
                for (size_t i = 0; i < n->batch_size; ++i) {
                    vv[i] = m * vv[i] - lr * n->grad[i]; 
                    n->data[i] += vv[i];
                }
            }
        }
    }
    
    void zero_grad(){for(auto*v:params)v->zero_grad();}

    void clear_graph() { for (auto* v : params) v->clear_graph(); }
};

// MSE loss function (multi thread not supported yet but that's for later)
class MSELoss {
public:
    // Compute MSE loss between two batched variables
    static Var compute(const Var& pred, const Var& target) {
        if (pred.batch_size() != target.batch_size()) {
            throw std::runtime_error("Batch sizes do not match for MSE loss");
        }
        std::vector<f64> loss_data(pred.batch_size());
        for (size_t i = 0; i < pred.batch_size(); ++i) {
            f64 diff = pred.node->data[i] - target.node->data[i];
            loss_data[i] = diff * diff;
        }
        Var loss(loss_data, "MSELoss(" + pred.node->name + ", " + target.node->name + ")", pred.needs_grad() || target.needs_grad());
        if (pred.needs_grad() || target.needs_grad()) {
            loss.node->parents.push_back(pred.node);
            loss.node->parents.push_back(target.node);
            auto pred_node = pred.node;
            auto target_node = target.node;
            loss.node->backward_fn = [loss_node = loss.node, pred_node, target_node]() {
                for (size_t i = 0; i < loss_node->batch_size; ++i) {
                    f64 grad = 2 * (loss_node->data[i] - target_node->data[i]) / loss_node->batch_size;
                    if (pred_node->requires_grad) {
                        pred_node->grad[i] += grad;
                    }
                    if (target_node->requires_grad) {
                        target_node->grad[i] -= grad;
                    }
                }
            };
        }
        return loss;
    }
};

// Fucked up impl for now bc stuff
template<f64 K>
class Sigmoid {
public:
    static Var compute(const Var& x) {
        std::vector<f64> sigmoid_data(x.batch_size());
        for (size_t i = 0; i < x.batch_size(); ++i) {
            f64 val = x.node->data[i];
            sigmoid_data[i] = K / (1 + std::exp(-val));
        }
        Var sigmoid(sigmoid_data, "Sigmoid(" + x.node->name + ")", x.needs_grad());
        if (x.needs_grad()) {
            sigmoid.node->parents.push_back(x.node);
            auto x_node = x.node;
            sigmoid.node->backward_fn = [sigmoid_node = sigmoid.node, x_node]() {
                for (size_t i = 0; i < sigmoid_node->batch_size; ++i) {
                    f64 val = sigmoid_node->data[i];
                    f64 grad = (K * std::exp(-val)) / ((1 + std::exp(-val)) * (1 + std::exp(-val)));
                    x_node->grad[i] += grad * sigmoid_node->grad[i];
                }
            };
        }
        return sigmoid;
    }
};

#endif // ENABLE_TUNING

}; // namespace Clockwork::Autograd

// --- Inference-mode PhasedParam and Evaluator -----------------------------
namespace Clockwork::HCE {

#ifdef ENABLE_TUNING
using Var   = Clockwork::Autograd::Var;
using Score = Clockwork::Autograd::Score;
using S     = Clockwork::Autograd::PhasedParam;
#else
using Score = double;
using S     = PhasedParam;

// Inference-mode PhasedParam backed by packed i32. I am doing this just because i want to avoid fixing the autograd stuff
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

#endif

// Evaluator interface for user-defined evaluation functions
// Ideally, we should implement our own evaluator based of this interface and use it for tuning. This allows the user (who am i kidding, the devs) to define hce evaluation functions easily
class Evaluator {
public:
    Evaluator()=default; virtual ~Evaluator()=default;
    virtual Score user_eval(const Clockwork::Position& pos) const = 0;
    
    // Batch evaluation method (internal use)
    std::vector<Score> batch_user_eval(const std::vector<Clockwork::Position>& positions) const {
        std::vector<Score> results;
        results.reserve(positions.size());
        for (const auto& pos : positions) {
            results.push_back(user_eval(pos));
        }
        return results;
    }
    
    Score evaluate(const Clockwork::Position& pos) const { return user_eval(pos); }
    Score evaluate(const std::string& fen) const { 
        auto pos = Clockwork::Position::parse(fen); 
        if (!pos) throw std::runtime_error("Invalid FEN string: " + fen);
        return evaluate(*pos); 
    }

    // get_parameters() is used to retrieve the parameters for tuning, it should be implemented in derived classes
    virtual std::vector<Var*> get_parameters() const = 0;
    
    template<typename Position>
    std::vector<Score> evaluate(const std::vector<Position>& v, int threads=1) const {
        std::vector<std::future<Score>> f;
        std::vector<Score> out; out.reserve(v.size());
        if (threads > 1) {
            for (size_t i = 0; i < v.size(); ++i)
                f.push_back(std::async(std::launch::async, [this, &v, i]() { return evaluate(v[i]); }));
            for (auto& X : f) out.push_back(X.get());
        } else {
            #ifdef ENABLE_TUNING
            // Only batch if Position is Clockwork::Position
            if constexpr (std::is_same_v<Position, Clockwork::Position>) {
                return batch_user_eval(v);
            } else {
                for (auto& p : v) out.push_back(evaluate(p));
            }
            #else
            for (auto& p : v) out.push_back(evaluate(p));
            #endif
        }
        return out;
    }

    template<typename Position>
    std::vector<Score> evaluate(const std::vector<std::string>&v,int threads=1) const {
        std::vector<Clockwork::Position> positions;
        positions.reserve(v.size());
        for (const auto& fen : v) {
            auto pos = Clockwork::Position::parse(fen);
            if (pos) {
                positions.push_back(*pos);
            } else {
                throw std::runtime_error("Invalid FEN string: " + fen);
            }
        }
        return evaluate(positions, threads);
    }
};

// Lets replicate our current eval to an evaluator so we can train it. Removing the random component bc it doesn't make sense in this context and replacing with tempo.
Clockwork::Autograd::S PAWN_MAT = S(100, 100);
Clockwork::Autograd::S KNIGHT_MAT = S(300, 300);
Clockwork::Autograd::S BISHOP_MAT = S(300, 300);
Clockwork::Autograd::S ROOK_MAT = S(500, 500);
Clockwork::Autograd::S QUEEN_MAT = S(900, 900);
Clockwork::Autograd::S MOBILITY_VAL = S(10, 10);
Clockwork::Autograd::S TEMPO_VAL = S(0, 0);

class MyEvaluator : public Evaluator {
public:
    MyEvaluator() = default;
    ~MyEvaluator() override = default;

    Score user_eval(const Clockwork::Position& pos) const override {
        const Clockwork::Color us   = pos.active_color();
        const Clockwork::Color them = invert(us);

        Clockwork::Autograd::Var phase = Var((pos.piece_count(us, PieceType::Knight) + pos.piece_count(them, PieceType::Knight))
                    + (pos.piece_count(us, PieceType::Bishop) + pos.piece_count(them, PieceType::Bishop))
                    + 2 * (pos.piece_count(us, PieceType::Rook) + pos.piece_count(them, PieceType::Rook))
                    + 4 * (pos.piece_count(us, PieceType::Queen) + pos.piece_count(them, PieceType::Queen)));
        
        Clockwork::Autograd::S material = 
            PAWN_MAT * (pos.piece_count(us, PieceType::Pawn) - pos.piece_count(them, PieceType::Pawn)) +
            KNIGHT_MAT * (pos.piece_count(us, PieceType::Knight) - pos.piece_count(them, PieceType::Knight)) +
            BISHOP_MAT * (pos.piece_count(us, PieceType::Bishop) - pos.piece_count(them, PieceType::Bishop)) +
            ROOK_MAT * (pos.piece_count(us, PieceType::Rook) - pos.piece_count(them, PieceType::Rook)) +
            QUEEN_MAT * (pos.piece_count(us, PieceType::Queen) - pos.piece_count(them, PieceType::Queen));
        
        Clockwork::Autograd::S mobility = S(0,0);
        for (u64 x : std::bit_cast<std::array<u64, 16>>(pos.attack_table(us))) {
            mobility = mobility + MOBILITY_VAL * std::popcount(x);
        }
        for (u64 x : std::bit_cast<std::array<u64, 16>>(pos.attack_table(them))) {
            mobility = mobility - MOBILITY_VAL * std::popcount(x);
        }   

        // Combine all features
        Clockwork::Autograd::S total = material + mobility + TEMPO_VAL;

        total = (us == Clockwork::Color::White) ? total : -total;

        // Get the final score
        Score score = total.phased<24>(phase);

        return score;

    }

    // Get parameters for tuning. This is used mainly as arguments to the optimizer
    std::vector<Var*> get_parameters() const override {
        std::vector<Var*> params;
        params.push_back(&PAWN_MAT.mg);
        params.push_back(&PAWN_MAT.eg);
        params.push_back(&KNIGHT_MAT.mg);
        params.push_back(&KNIGHT_MAT.eg);
        params.push_back(&BISHOP_MAT.mg);
        params.push_back(&BISHOP_MAT.eg);
        params.push_back(&ROOK_MAT.mg);
        params.push_back(&ROOK_MAT.eg);
        params.push_back(&QUEEN_MAT.mg);
        params.push_back(&QUEEN_MAT.eg);
        params.push_back(&MOBILITY_VAL.mg);
        params.push_back(&MOBILITY_VAL.eg);
        params.push_back(&TEMPO_VAL.mg);
        params.push_back(&TEMPO_VAL.eg);
        return params;
    }

};

} // namespace Clockwork::HCE
