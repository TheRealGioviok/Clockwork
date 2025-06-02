import random
import torch

random.seed(42)

VAR_NAMES = ["a", "b", "c", "d"]
OPERATORS = ["+", "-", "*", "/"]

def safe_div_expr(lhs, rhs):
    if lhs == rhs:
        rhs += " + 1.0"
    return f"({lhs}) / ({rhs})"

def random_expr(depth=0):
    if depth > 2:
        return random.choice(VAR_NAMES)
    if random.random() < 0.3:
        return random.choice(VAR_NAMES)
    op = random.choice(OPERATORS)
    left = random_expr(depth + 1)
    right = random_expr(depth + 1)
    if op == "/":
        return safe_div_expr(left, right)
    return f"({left} {op} {right})"

def evaluate_expr(expr_str):
    a = torch.tensor(1.5, requires_grad=True)
    b = torch.tensor(-2.0, requires_grad=True)
    c = torch.tensor(0.75, requires_grad=True)
    d = torch.tensor(4.0, requires_grad=True)

    result = eval(expr_str)
    result.backward()

    def grad_or_zero(x):
        return x.grad.item() if x.grad is not None else 0.0

    return {
        "value": result.item(),
        "a": grad_or_zero(a),
        "b": grad_or_zero(b),
        "c": grad_or_zero(c),
        "d": grad_or_zero(d)
    }


def generate_test_case(idx, expr_str, expected):
    return f"""
void test_{idx}() {{
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = {expr_str};
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {{
        if (std::abs(actual - expected) > 1e-6) {{
            std::cerr << "Test {idx} failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\\n";
            std::exit(1);
        }}
    }};

    expect_close(t.get(), {expected['value']}, "value");
    expect_close(a.grad(), {expected['a']}, "a.grad");
    expect_close(b.grad(), {expected['b']}, "b.grad");
    expect_close(c.grad(), {expected['c']}, "c.grad");
    expect_close(d.grad(), {expected['d']}, "d.grad");
}}
"""

def generate_cpp_tests(filename="generated_autodiff_tests.cpp", num_tests=20):
    header = """
#include "../src/tune/autodiff.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>
"""

    tests = ""
    main_calls = "int main() {\n"

    for idx in range(num_tests):
        expr = random_expr()
        torch_expr = expr.replace("/", "/")  # identity, but just for clarity
        expected = evaluate_expr(torch_expr)
        tests += generate_test_case(idx, expr, expected)
        main_calls += f"    test_{idx}();\n"

    main_calls += '    std::cout << "All tests passed!\\n";\n    return 0;\n}'

    with open(filename, "w") as f:
        f.write(header + tests + "\n" + main_calls)

    print(f"Generated {num_tests} tests in {filename}")

if __name__ == "__main__":
    generate_cpp_tests()
