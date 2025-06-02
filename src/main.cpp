#include "uci.hpp"
#include "tune/autodiff.hpp"
#include <vector>

using namespace Clockwork::Autograd;

int main(int argc, char* argv[]) {
    
    Parameter w(0.5, "w");
    Parameter b(0.0, "b");

    std::vector<Parameter*> params = { &w, &b };
    SGD optimizer(params, 0.001);

    std::vector<std::pair<double, double>> data = {
        {1.0, 2.0},
        {2.0, 4.0},
        {3.0, 6.0}
    };

    for (int epoch = 0; epoch < 100; ++epoch) {
        double total_loss = 0.0;
        optimizer.zeroGrad();

        for (const auto& [x_val, y_val] : data) {
            Value x(x_val);
            Value y(y_val);

            auto pred = w * x + b;
            auto loss = (pred - y) * (pred - y);

            total_loss += loss.get();
            loss.backward();
        }

        optimizer.step();

        std::cout << "Epoch " << epoch
                    << ": loss = " << total_loss << ", w = " << w.get()
                    << ", b = " << b.get() << std::endl;
    }
}

