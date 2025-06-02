
#include "../../src/tune/autodiff.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>

void test_0() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = ((a - (d + a)) + b);
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 0 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -6.0, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 1.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), -1.0, "d.grad");
}

void test_1() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = a;
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 1 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 1.5, "value");
    expect_close(a.grad(), 1.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_2() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (c) / (((d - c) + b));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 2 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 0.6000000238418579, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), -0.48000001907348633, "b.grad");
    expect_close(c.grad(), 1.2799999713897705, "c.grad");
    expect_close(d.grad(), -0.48000001907348633, "d.grad");
}

void test_3() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (d * c);
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 3 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 3.0, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 4.0, "c.grad");
    expect_close(d.grad(), 0.75, "d.grad");
}

void test_4() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (((a) / (c) + (b * a)) + b);
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 4 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -3.0, "value");
    expect_close(a.grad(), -0.6666666269302368, "a.grad");
    expect_close(b.grad(), 2.5, "b.grad");
    expect_close(c.grad(), -2.6666667461395264, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_5() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (((c) / (b) + (c - a)) + ((b - d) - (c - a)));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 5 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -6.375, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 0.8125, "b.grad");
    expect_close(c.grad(), -0.5, "c.grad");
    expect_close(d.grad(), -1.0, "d.grad");
}

void test_6() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = a;
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 6 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 1.5, "value");
    expect_close(a.grad(), 1.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_7() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (b) / ((d * (b) / (c)));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 7 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 0.1875, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 0.25, "c.grad");
    expect_close(d.grad(), -0.046875, "d.grad");
}

void test_8() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = c;
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 8 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 0.75, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 1.0, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_9() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (((d - a)) / ((b + b))) / (((d) / (d + 1.0)) / ((a + c)));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 9 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -1.7578125, "value");
    expect_close(a.grad(), -0.07812505960464478, "a.grad");
    expect_close(b.grad(), -0.87890625, "b.grad");
    expect_close(c.grad(), -0.7812500596046448, "c.grad");
    expect_close(d.grad(), -0.615234375, "d.grad");
}

void test_10() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (d * a);
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 10 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 6.0, "value");
    expect_close(a.grad(), 4.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), 1.5, "d.grad");
}

void test_11() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (((c + b) - b) * ((a) / (a + 1.0) + (b * a)));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 11 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -1.8000000715255737, "value");
    expect_close(a.grad(), -1.380000114440918, "a.grad");
    expect_close(b.grad(), 1.125, "b.grad");
    expect_close(c.grad(), -2.4000000953674316, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_12() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = a;
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 12 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 1.5, "value");
    expect_close(a.grad(), 1.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_13() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = d;
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 13 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 4.0, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), 1.0, "d.grad");
}

void test_14() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (d - (d - (c - d)));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 14 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -3.25, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 1.0, "c.grad");
    expect_close(d.grad(), -1.0, "d.grad");
}

void test_15() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = ((b) / (a) * ((a + a) - a));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 15 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -2.0, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 1.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_16() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (((b - d) * d) + (d - (d) / (a)));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 16 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -22.66666603088379, "value");
    expect_close(a.grad(), 1.7777777910232544, "a.grad");
    expect_close(b.grad(), 4.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), -9.666666030883789, "d.grad");
}

void test_17() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = (c + (b + (d - b)));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 17 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), 4.75, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 0.0, "b.grad");
    expect_close(c.grad(), 1.0, "c.grad");
    expect_close(d.grad(), 1.0, "d.grad");
}

void test_18() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = b;
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 18 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -2.0, "value");
    expect_close(a.grad(), 0.0, "a.grad");
    expect_close(b.grad(), 1.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), 0.0, "d.grad");
}

void test_19() {
    using namespace Clockwork::Autograd;
    Parameter a(1.5, "a");
    Parameter b(-2.0, "b");
    Parameter c(0.75, "c");
    Parameter d(4.0, "d");

    auto t = ((a + (b - d)) + ((b + d) - d));
    t.backward();

    auto expect_close = [](double actual, double expected, const char* label) {
        if (std::abs(actual - expected) > 1e-6) {
            std::cerr << "Test 19 failed: " << label << " mismatch. Got " << actual << ", expected " << expected << "\n";
            std::exit(1);
        }
    };

    expect_close(t.get(), -6.5, "value");
    expect_close(a.grad(), 1.0, "a.grad");
    expect_close(b.grad(), 2.0, "b.grad");
    expect_close(c.grad(), 0.0, "c.grad");
    expect_close(d.grad(), -1.0, "d.grad");
}

int main() {
    test_0();
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
    test_10();
    test_11();
    test_12();
    test_13();
    test_14();
    test_15();
    test_16();
    test_17();
    test_18();
    test_19();
    std::cout << "All tests passed!\n";
    return 0;
}