import torch
import random
torch.manual_seed(47)
random.seed(47)
def run_test(a_val, b_val, expr, expr_label):
    a = torch.tensor(a_val, dtype=torch.float64, requires_grad=True)
    b = torch.tensor(b_val, dtype=torch.float64, requires_grad=True)

    z = eval(expr)
    z.backward()

    return {
        "label": expr_label,
        "expr": expr,
        "cpp_expr": expr.replace("**2", " * ").replace("a", "a").replace("b", "b"),  # placeholder
        "a": float(a.item()),
        "b": float(b.item()),
        "z": float(z.item()),
        "grad_a": float(a.grad.item()),
        "grad_b": float(b.grad.item())
    }

test_exprs = [
    ("a + b", "a + b"),
    ("a * b", "a * b"),
    ("a - b", "a - b"),
    ("a / b", "a / b"),
    ("a * a + b * b", "a² + b²"),
    ("(a + b) * (a - b)", "(a + b)(a - b)"),
    ("(a + b)**2", "(a + b)²"),
    ("(a - b)**2 + a / b", "(a - b)² + a/b")
]

cases = []
for _ in range(5):
    a_val = random.uniform(0.5, 5.0)
    b_val = random.uniform(0.5, 5.0)
    for expr, label in test_exprs:
        result = run_test(a_val, b_val, expr, label)
        result["cpp_expr"] = expr.replace("**2", "*").replace("a", "a").replace("b", "b")
        result["cpp_expr"] = expr.replace("**2", "*").replace("a", "a").replace("b", "b")
        cases.append(result)

# Dump to C++ code
for i, case in enumerate(cases):
    print(f"""// Test {i}: {case["label"]}
{{
    using namespace Clockwork::Autograd;
    Parameter a({case["a"]}, "a");
    Parameter b({case["b"]}, "b");

    auto z = {case["expr"]};
    z.backward();

    std::cout << "Test {i}: {case['label']}\\n";
    std::cout << "  z = " << z.get() << " (expected {case['z']})\\n";
    std::cout << "  a.grad = " << a.grad() << " (expected {case['grad_a']})\\n";
    std::cout << "  b.grad = " << b.grad() << " (expected {case['grad_b']})\\n";

    assert(std::abs(z.get() - {case['z']}) < 1e-6);
    assert(std::abs(a.grad() - {case['grad_a']}) < 1e-6);
    assert(std::abs(b.grad() - {case['grad_b']}) < 1e-6);
}}
""")
