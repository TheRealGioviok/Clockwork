#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <optional>
#include <string>
#include <unordered_set>
#include "../util/types.hpp"

namespace Clockwork::Autograd {

// The Node class handles the correct propagation of gradient for backward purposes. 
// Each node keeps track of its data, their gradient (if it requires it), the name and a list of parents to backward to.
class Node : public std::enable_shared_from_this<Node> {
public:
    f64 data;
    f64 grad_ = 0.0;
    bool requires_grad;
    std::optional<std::string> name;
    std::vector<std::shared_ptr<Node>> parents;
    std::function<void()> backward_fn;
    bool backward_called = false;

    Node(f64 d, std::optional<std::string> n, bool req_grad)
        : data(d), requires_grad(req_grad), name(std::move(n)) {}

    f64 get() const { return data; }
    bool requiresGrad() const { return requires_grad; }
    f64 grad() const { return grad_; }
    f64& gradRef() { return grad_; }

    void accumulateGrad(f64 g) { grad_ += g; }
    void setBackwardFn(std::function<void()> fn) { backward_fn = std::move(fn); }

    void backward() {
        if (backward_called) return;
        backward_called = true;

        if (!requires_grad) return;
        if (grad_ == 0.0) grad_ = 1.0;

        if (backward_fn) backward_fn();
        for (auto& parent : parents) {
            if (parent) parent->backward();
        }
    }

    void zeroGrad() {
        grad_ = 0.0;
        backward_called = false;
        for (auto& parent : parents) {
            if (parent) parent->zeroGrad();
        }
    }

    std::string nameStr() const {
        return name ? *name : std::to_string(data);
    }

    friend std::ostream& operator<<(std::ostream& os, const Node& n) {
        return os << "Node" << (n.name ? "(" + *n.name + ")" : "")
                  << " = " << n.data << ", grad = " << n.grad_;
    }
};

class Value {
public:
    std::shared_ptr<Node> node;

    Value() : node(std::make_shared<Node>(0.0, std::nullopt, false)) {}
    explicit Value(f64 d, std::optional<std::string> n = std::nullopt)
        : node(std::make_shared<Node>(d, std::move(n), false)) {}

    f64 get() const { return node->get(); }
    std::shared_ptr<Node> getNode() const { return node; }
    std::string nameStr() const { return node->nameStr(); }

    friend std::ostream& operator<<(std::ostream& os, const Value& v) {
        return os << "Value" << (v.node->name ? "(" + *v.node->name + ")" : "")
                  << " = " << v.node->data;
    }
};

class Parameter {
public:
    std::shared_ptr<Node> node;

    Parameter() : node(std::make_shared<Node>(0.0, std::nullopt, true)) {}
    explicit Parameter(f64 d, std::optional<std::string> n = std::nullopt, bool req_grad = true)
        : node(std::make_shared<Node>(d, std::move(n), req_grad)) {}
    explicit Parameter(std::shared_ptr<Node> n) : node(std::move(n)) {}

    f64 get() const { return node->get(); }
    bool requiresGrad() const { return node->requiresGrad(); }
    f64 grad() const { return node->grad(); }
    f64& gradRef() { return node->gradRef(); }

    void accumulateGrad(f64 g) { node->accumulateGrad(g); }
    void setBackwardFn(std::function<void()> fn) { node->setBackwardFn(std::move(fn)); }

    void backward() { node->backward(); }
    void zeroGrad() { node->zeroGrad(); }

    std::string nameStr() const { return node->nameStr(); }

    Parameter& setName(const std::string& n) {
        node->name = n;
        return *this;
    }

    std::shared_ptr<Node> getNode() const { return node; }

    friend std::ostream& operator<<(std::ostream& os, const Parameter& p) {
        return os << "Parameter" << (p.node->name ? "(" + *p.node->name + ")" : "")
                  << " = " << p.node->data << ", grad = " << p.node->grad_;
    }
};

// Helper function to create a binary operation node
template<typename Left, typename Right>
Parameter makeBinaryOp(
    const Left& a, const Right& b,
    std::function<f64(f64, f64)> forward,
    std::function<void(Parameter&)> backward,
    const std::string& op) {

    f64 val = forward(a.get(), b.get());
    bool req_grad = a.getNode()->requires_grad || b.getNode()->requires_grad;
    auto result_node = std::make_shared<Node>(val, std::nullopt, req_grad);
    Parameter result(result_node);

    // Add parents if they require grad
    if (a.getNode()->requires_grad) {
        result_node->parents.push_back(a.getNode());
    }
    if (b.getNode()->requires_grad) {
        result_node->parents.push_back(b.getNode());
    }

    // Set name
    std::string a_name = a.nameStr();
    std::string b_name = b.nameStr();
    result_node->name = "(" + a_name + " " + op + " " + b_name + ")";

    // Capture shared_ptrs to nodes to avoid const issues
    auto a_node = a.getNode();
    auto b_node = b.getNode();

    result_node->setBackwardFn([result_node, backward, a_node, b_node]() {
        Parameter result_param(result_node);
        backward(result_param);
    });

    return result;
}

// Operators for Parameter and Value (all const refs)

// Addition operators
inline Parameter operator+(const Parameter& a, const Parameter& b) {
    auto a_node = a.getNode();
    auto b_node = b.getNode();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x + y; },
        [a_node, b_node](Parameter& result) {
            Parameter a(a_node);
            Parameter b(b_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad());
            if (b.requiresGrad()) b.accumulateGrad(result.grad());
        },
        "+");
}

inline Parameter operator+(const Parameter& a, const Value& b) {
    auto a_node = a.getNode();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x + y; },
        [a_node](Parameter& result) {
            Parameter a(a_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad());
        },
        "+");
}

inline Parameter operator+(const Value& a, const Parameter& b) {
    auto b_node = b.getNode();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x + y; },
        [b_node](Parameter& result) {
            Parameter b(b_node);
            if (b.requiresGrad()) b.accumulateGrad(result.grad());
        },
        "+");
}

inline Parameter operator+(double a, const Parameter& b) {
    Value v(a);
    return v + b;
}

inline Parameter operator+(const Parameter& a, double b) {
    Value v(b);
    return a + v;
}

// Subtraction operators
inline Parameter operator-(const Parameter& a, const Parameter& b) {
    auto a_node = a.getNode();
    auto b_node = b.getNode();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x - y; },
        [a_node, b_node](Parameter& result) {
            Parameter a(a_node);
            Parameter b(b_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad());
            if (b.requiresGrad()) b.accumulateGrad(-result.grad());
        },
        "-");
}

inline Parameter operator-(const Parameter& a, const Value& b) {
    auto a_node = a.getNode();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x - y; },
        [a_node](Parameter& result) {
            Parameter a(a_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad());
        },
        "-");
}

inline Parameter operator-(const Value& a, const Parameter& b) {
    auto b_node = b.getNode();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x - y; },
        [b_node](Parameter& result) {
            Parameter b(b_node);
            if (b.requiresGrad()) b.accumulateGrad(-result.grad());
        },
        "-");
}

inline Parameter operator-(double a, const Parameter& b) {
    Value v(a);
    return v - b;
}

inline Parameter operator-(const Parameter& a, double b) {
    Value v(b);
    return a - v;
}

// Multiplication operators
inline Parameter operator*(const Parameter& a, const Parameter& b) {
    auto a_node = a.getNode();
    auto b_node = b.getNode();

    f64 a_val = a.get();
    f64 b_val = b.get();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x * y; },
        [a_node, b_node, a_val, b_val](Parameter& result) {
            Parameter a(a_node);
            Parameter b(b_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad() * b_val);
            if (b.requiresGrad()) b.accumulateGrad(result.grad() * a_val);
        },
        "*");
}

inline Parameter operator*(const Parameter& a, const Value& b) {
    auto a_node = a.getNode();
    f64 b_val = b.get();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x * y; },
        [a_node, b_val](Parameter& result) {
            Parameter a(a_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad() * b_val);
        },
        "*");
}

inline Parameter operator*(const Value& a, const Parameter& b) {
    auto b_node = b.getNode();
    f64 a_val = a.get();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x * y; },
        [b_node, a_val](Parameter& result) {
            Parameter b(b_node);
            if (b.requiresGrad()) b.accumulateGrad(result.grad() * a_val);
        },
        "*");
}

inline Parameter operator*(double a, const Parameter& b) {
    Value v(a);
    return v * b;
}

inline Parameter operator*(const Parameter& a, double b) {
    Value v(b);
    return a * v;
}

// Division operators
inline Parameter operator/(const Parameter& a, const Parameter& b) {
    auto a_node = a.getNode();
    auto b_node = b.getNode();

    f64 a_val = a.get();
    f64 b_val = b.get();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x / y; },
        [a_node, b_node, a_val, b_val](Parameter& result) {
            Parameter a(a_node);
            Parameter b(b_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad() / b_val);
            if (b.requiresGrad()) b.accumulateGrad(-result.grad() * a_val / (b_val * b_val));
        },
        "/");
}

inline Parameter operator/(const Parameter& a, const Value& b) {
    auto a_node = a.getNode();
    f64 b_val = b.get();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x / y; },
        [a_node, b_val](Parameter& result) {
            Parameter a(a_node);
            if (a.requiresGrad()) a.accumulateGrad(result.grad() / b_val);
        },
        "/");
}

inline Parameter operator/(const Value& a, const Parameter& b) {
    auto b_node = b.getNode();
    f64 a_val = a.get();
    f64 b_val = b.get();

    return makeBinaryOp(a, b,
        [](f64 x, f64 y) { return x / y; },
        [b_node, a_val, b_val](Parameter& result) {
            Parameter b(b_node);
            if (b.requiresGrad()) b.accumulateGrad(-result.grad() * a_val / (b_val * b_val));
        },
        "/");
}

inline Parameter operator/(double a, const Parameter& b) {
    Value v(a);
    return v / b;
}

inline Parameter operator/(const Parameter& a, double b) {
    Value v(b);
    return a / v;
}

// Utility function to print computation graph
inline void printGraph(const Parameter& param,
                std::unordered_set<const Node*>& visited,
                int indent = 0) {
    auto node = param.getNode();
    if (!node || visited.count(node.get())) return;
    visited.insert(node.get());

    std::cout << std::string(indent * 2, ' ')
              << (node->name ? *node->name : "(unnamed)")
              << " val=" << node->get() << " grad=" << node->grad() << std::endl;

    for (auto& parent : node->parents) {
        Parameter temp(parent);
        printGraph(temp, visited, indent + 1);
    }
}

class SGD {
    public:
        std::vector<Clockwork::Autograd::Parameter*> params;
        std::unordered_map<Clockwork::Autograd::Node*, double> velocities;
        double lr;
        double momentum;
    
        SGD(std::vector<Clockwork::Autograd::Parameter*>& parameters,
            double learning_rate = 0.01, double momentum_coeff = 0.9)
            : params(parameters), lr(learning_rate), momentum(momentum_coeff) {
            for (auto* param : params) {
                velocities[param->getNode().get()] = 0.0;
            }
        }
    
        void step() {
            for (auto* param : params) {
                if (param->requiresGrad()) {
                    auto* node = param->getNode().get();
                    double& v = velocities[node];
                    v = momentum * v - lr * param->grad(); // Update velocity
                    node->data += v; // Apply update
                }
            }
        }
    
        void zeroGrad() {
            for (auto* param : params) {
                param->zeroGrad();
            }
        }
    };
    

Parameter MSE(const Parameter& prediction, const Parameter& target) {
    auto diff = prediction - target;
    return diff * diff; // Mean squared error (MSE)
}

    

} // namespace Clockwork::Autograd
