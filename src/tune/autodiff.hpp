#pragma once
#include "../util/types.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <unordered_set>
#include <vector>

namespace Clockwork::Autograd {

// The Node class handles the correct propagation of gradient for backward purposes.
// Each node keeps track of its data, their gradient (if it requires it), the name and a list of parents to backward to.
class Node : public std::enable_shared_from_this<Node> {
private:
    f64  m_data;
    f64  m_grad = 0.0;
    bool m_requires_grad;


public:
    std::optional<std::string>         name;
    std::vector<std::shared_ptr<Node>> parents;
    std::function<void()>              backward_fn;
    bool                               backward_called = false;


    Node(f64 data, std::optional<std::string> n, bool requires_grad) :
        m_data(data),
        m_requires_grad(requires_grad),
        name(std::move(n)) {
    }

    f64 get() const {
        return m_data;
    }
    bool requires_grad() const {
        return m_requires_grad;
    }
    f64 grad() const {
        return m_grad;
    }
    f64& grad_ref() {
        return m_grad;
    }

    void accumulate_grad(f64 g) {
        m_grad += g;
    }
    void set_backward_fn(std::function<void()> fn) {
        backward_fn = std::move(fn);
    }

    void backward() {
        if (backward_called) {
            return;
        }
        backward_called = true;

        if (!requires_grad()) {
            return;
        }
        if (m_grad == 0.0) {
            m_grad = 1.0;
        }

        if (backward_fn) {
            backward_fn();
        }
        for (auto& parent : parents) {
            if (parent) {
                parent->backward();
            }
        }
    }

    void zero_grad() {
        m_grad          = 0.0;
        backward_called = false;
        for (auto& parent : parents) {
            if (parent) {
                parent->zero_grad();
            }
        }
    }

    void apply(f64 amount) {
        m_data += amount;
    }

    std::string name_str() const {
        return name ? *name : std::to_string(m_data);
    }

    friend std::ostream& operator<<(std::ostream& os, const Node& n) {
        return os << "Node" << (n.name ? "(" + *n.name + ")" : "") << " = " << n.m_data
                  << ", grad = " << n.m_grad;
    }
};

class Value {
public:
    std::shared_ptr<Node> node;

    Value() :
        node(std::make_shared<Node>(0.0, std::nullopt, false)) {
    }
    explicit Value(f64 d, std::optional<std::string> n = std::nullopt) :
        node(std::make_shared<Node>(d, std::move(n), false)) {
    }

    [[nodiscard]] f64 get() const {
        return node->get();
    }
    [[nodiscard]] std::shared_ptr<Node> get_node() const {
        return node;
    }
    [[nodiscard]] std::string name_str() const {
        return node->name_str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Value& v) {
        return os << "Value" << (v.node->name ? "(" + *v.node->name + ")" : "") << " = "
                  << v.node->get();
    }
};

class Parameter {
public:
    std::shared_ptr<Node> node;

    Parameter() :
        node(std::make_shared<Node>(0.0, std::nullopt, true)) {
    }
    explicit Parameter(f64 d, std::optional<std::string> n = std::nullopt, bool req_grad = true) :
        node(std::make_shared<Node>(d, std::move(n), req_grad)) {
    }
    explicit Parameter(std::shared_ptr<Node> n) :
        node(std::move(n)) {
    }

    [[nodiscard]] f64 get() const {
        return node->get();
    }
    [[nodiscard]] bool requires_grad() const {
        return node->requires_grad();
    }
    [[nodiscard]] f64 grad() const {
        return node->grad();
    }
    f64& grad_ref() {
        return node->grad_ref();
    }

    void accumulate_grad(f64 g) {
        node->accumulate_grad(g);
    }
    void set_backward_fn(std::function<void()> fn) {
        node->set_backward_fn(std::move(fn));
    }

    void backward() {
        node->backward();
    }
    void zero_grad() {
        node->zero_grad();
    }

    [[nodiscard]] std::string name_str() const {
        return node->name_str();
    }

    Parameter& set_name(const std::string& n) {
        node->name = n;
        return *this;
    }

    [[nodiscard]] std::shared_ptr<Node> get_node() const {
        return node;
    }

    friend std::ostream& operator<<(std::ostream& os, const Parameter& p) {
        return os << "Parameter" << (p.node->name ? "(" + *p.node->name + ")" : "") << " = "
                  << p.node.get() << ", grad = " << p.node->grad();
    }
};

// Helper function to create a binary operation node
template<typename Left, typename Right>
Parameter make_binary_op(const Left&                     a,
                         const Right&                    b,
                         std::function<f64(f64, f64)>    forward,
                         std::function<void(Parameter&)> backward,
                         const std::string&              op) {

    f64       val         = forward(a.get(), b.get());
    bool      req_grad    = a.get_node()->requires_grad() || b.get_node()->requires_grad();
    auto      result_node = std::make_shared<Node>(val, std::nullopt, req_grad);
    Parameter result(result_node);

    // Add parents if they require grad
    if (a.get_node()->requires_grad()) {
        result_node->parents.push_back(a.get_node());
    }
    if (b.get_node()->requires_grad()) {
        result_node->parents.push_back(b.get_node());
    }

    // Set name
    std::string a_name = a.name_str();
    std::string b_name = b.name_str();
    result_node->name  = "(" + a_name + " " + op + " " + b_name + ")";

    // Capture shared_ptrs to nodes to avoid const issues
    auto a_node = a.get_node();
    auto b_node = b.get_node();

    result_node->set_backward_fn([result_node, backward, a_node, b_node]() {
        Parameter result_param(result_node);
        backward(result_param);
    });

    return result;
}

// Operators for Parameter and Value (all const refs)

// Addition operators
inline Parameter operator+(const Parameter& a, const Parameter& b) {
    auto a_node = a.get_node();
    auto b_node = b.get_node();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x + y;
      },
      [a_node, b_node](Parameter& result) {
          Parameter a(a_node);
          Parameter b(b_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad());
          }
          if (b.requires_grad()) {
              b.accumulate_grad(result.grad());
          }
      },
      "+");
}

inline Parameter operator+(const Parameter& a, const Value& b) {
    auto a_node = a.get_node();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x + y;
      },
      [a_node](Parameter& result) {
          Parameter a(a_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad());
          }
      },
      "+");
}

inline Parameter operator+(const Value& a, const Parameter& b) {
    auto b_node = b.get_node();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x + y;
      },
      [b_node](Parameter& result) {
          Parameter b(b_node);
          if (b.requires_grad()) {
              b.accumulate_grad(result.grad());
          }
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
    auto a_node = a.get_node();
    auto b_node = b.get_node();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x - y;
      },
      [a_node, b_node](Parameter& result) {
          Parameter a(a_node);
          Parameter b(b_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad());
          }
          if (b.requires_grad()) {
              b.accumulate_grad(-result.grad());
          }
      },
      "-");
}

inline Parameter operator-(const Parameter& a, const Value& b) {
    auto a_node = a.get_node();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x - y;
      },
      [a_node](Parameter& result) {
          Parameter a(a_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad());
          }
      },
      "-");
}

inline Parameter operator-(const Value& a, const Parameter& b) {
    auto b_node = b.get_node();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x - y;
      },
      [b_node](Parameter& result) {
          Parameter b(b_node);
          if (b.requires_grad()) {
              b.accumulate_grad(-result.grad());
          }
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
    auto a_node = a.get_node();
    auto b_node = b.get_node();

    f64 a_val = a.get();
    f64 b_val = b.get();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x * y;
      },
      [a_node, b_node, a_val, b_val](Parameter& result) {
          Parameter a(a_node);
          Parameter b(b_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad() * b_val);
          }
          if (b.requires_grad()) {
              b.accumulate_grad(result.grad() * a_val);
          }
      },
      "*");
}

inline Parameter operator*(const Parameter& a, const Value& b) {
    auto a_node = a.get_node();
    f64  b_val  = b.get();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x * y;
      },
      [a_node, b_val](Parameter& result) {
          Parameter a(a_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad() * b_val);
          }
      },
      "*");
}

inline Parameter operator*(const Value& a, const Parameter& b) {
    auto b_node = b.get_node();
    f64  a_val  = a.get();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x * y;
      },
      [b_node, a_val](Parameter& result) {
          Parameter b(b_node);
          if (b.requires_grad()) {
              b.accumulate_grad(result.grad() * a_val);
          }
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
    auto a_node = a.get_node();
    auto b_node = b.get_node();

    f64 a_val = a.get();
    f64 b_val = b.get();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x / y;
      },
      [a_node, b_node, a_val, b_val](Parameter& result) {
          Parameter a(a_node);
          Parameter b(b_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad() / b_val);
          }
          if (b.requires_grad()) {
              b.accumulate_grad(-result.grad() * a_val / (b_val * b_val));
          }
      },
      "/");
}

inline Parameter operator/(const Parameter& a, const Value& b) {
    auto a_node = a.get_node();
    f64  b_val  = b.get();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x / y;
      },
      [a_node, b_val](Parameter& result) {
          Parameter a(a_node);
          if (a.requires_grad()) {
              a.accumulate_grad(result.grad() / b_val);
          }
      },
      "/");
}

inline Parameter operator/(const Value& a, const Parameter& b) {
    auto b_node = b.get_node();
    f64  a_val  = a.get();
    f64  b_val  = b.get();

    return make_binary_op(
      a, b,
      [](f64 x, f64 y) {
          return x / y;
      },
      [b_node, a_val, b_val](Parameter& result) {
          Parameter b(b_node);
          if (b.requires_grad()) {
              b.accumulate_grad(-result.grad() * a_val / (b_val * b_val));
          }
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
inline void
print_graph(const Parameter& param, std::unordered_set<const Node*>& visited, int indent = 0) {
    auto node = param.get_node();
    if (!node || visited.count(node.get())) {
        return;
    }
    visited.insert(node.get());

    std::cout << std::string(indent * 2, ' ') << (node->name ? *node->name : "(unnamed)")
              << " val=" << node->get() << " grad=" << node->grad() << std::endl;

    for (auto& parent : node->parents) {
        Parameter temp(parent);
        print_graph(temp, visited, indent + 1);
    }
}

class SGD {
public:
    std::vector<Clockwork::Autograd::Parameter*>           params;
    std::unordered_map<Clockwork::Autograd::Node*, double> velocities;
    double                                                 lr;
    double                                                 momentum;

    SGD(std::vector<Clockwork::Autograd::Parameter*>& parameters,
        double                                        learning_rate  = 0.01,
        double                                        momentum_coeff = 0.9) :
        params(parameters),
        lr(learning_rate),
        momentum(momentum_coeff) {
        for (auto* param : params) {
            velocities[param->get_node().get()] = 0.0;
        }
    }

    void step() {
        for (auto* param : params) {
            if (param->requires_grad()) {
                auto*   node = param->get_node().get();
                double& v    = velocities[node];
                v            = momentum * v - lr * param->grad();  // Update velocity
                node->apply(v);                                    // Apply update
            }
        }
    }

    void zero_grad() {
        for (auto* param : params) {
            param->zero_grad();
        }
    }
};


Parameter MSE(const Parameter& prediction, const Parameter& target) {
    auto diff = prediction - target;
    return diff * diff;  // Mean squared error (MSE)
}


}  // namespace Clockwork::Autograd
