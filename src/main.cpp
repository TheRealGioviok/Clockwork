#include "tune/autodiff.hpp"
#include "uci.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace Clockwork::Autograd;

int main(int argc, char* argv[]) {

    // Let's train material values
    PhasedParam pawnValue(100, 100);
    PhasedParam knightValue(300, 300);
    PhasedParam bishopValue(300, 300);
    PhasedParam rookValue(500, 500);
    PhasedParam queenValue(900, 900);

    vector<PhasedParam> params = {pawnValue, knightValue, bishopValue, rookValue, queenValue};
    
    // Initialize evaluator
    Evaluator evaluator;
    evaluator.set_params(params);

    // Load fens.
    vector<string> fens;
    ifstream fenFile("fens.txt");
    if (!fenFile) {
        std::cerr << "Error opening fens.txt" << endl;
        return 1;
    };
    string line;
    while (getline(fenFile, line)) {
        if (!line.empty()) {
            fens.push_back(line);
        }
    }
    fenFile.close();

    // SGD
    SGD optimizer(evaluator, 0.01);

    for (int epoch = 0; epoch < 100; ++epoch) {
        for (const auto& fen : fens) {
            evaluator.set_position(fen);
            auto features = evaluator.extract_features();
            auto loss = evaluator.eval(features);

            // Backpropagation
            loss.backward();

            // Update parameters
            optimizer.step();
            optimizer.zero_grad();
        }
        std::cout << "Epoch " << epoch + 1 << " completed." << std::endl;
    }

    
}
