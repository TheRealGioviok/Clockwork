#include "tune/autodiff.hpp"
#include "uci.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

    // Load fens.
    std::vector<std::string> fens;
    std::vector<Clockwork::Autograd::Score> results;
    std::ifstream fenFile("fens.book");
    if (!fenFile) {
        std::cerr << "Error opening fens.book" << std::endl;
        return 1;
    };
    std::string line;
    while (std::getline(fenFile, line)) {
        // The line is : FEN;(w/d/b)
        size_t pos = line.find(';');
        if (pos != std::string::npos) {
            std::string fen = line.substr(0, pos);
            fens.push_back(fen);
            std::string result = line.substr(pos + 1);
            if (result == "w") {
                results.push_back(Clockwork::Autograd::Score(1.0));  // Win
            } else if (result == "d") {
                results.push_back(Clockwork::Autograd::Score(0.5));  // Draw
            } else if (result == "b") {
                results.push_back(Clockwork::Autograd::Score(0.0));  // Loss
            } else {
                std::cerr << "Invalid result in line: " << line << std::endl;
            }
        } else {
            std::cerr << "Invalid line format: " << line << std::endl;  
        }
    }
    fenFile.close();

    // Print the number of fens loaded
    std::cout << "Loaded " << fens.size() << " FENs." << std::endl;
    
    // Evaluator
    Clockwork::HCE::MyEvaluator evaluator;

    // SGD
    Clockwork::Autograd::SGD optim(evaluator.get_parameters(), 0.0001, 0.9);

    // MSE loss
    Clockwork::Autograd::MSELoss mse_loss;

    // Sigmoid function
    Clockwork::Autograd::Sigmoid<650.0> sigmoid;

    // Training loop using batched sgd

    // Lambda to get a batch of fens
    auto get_batch = [&fens](size_t start, size_t batch_size) {
        std::vector<std::string> batch;
        for (size_t i = start; i < start + batch_size && i < fens.size(); ++i) {
            batch.push_back(fens[i]);   
        }
        return batch;
    };

    size_t batch_size = 128;
    size_t num_batches = fens.size() / batch_size;
    for (size_t epoch = 0; epoch < 10; ++epoch) {
        for (size_t batch_idx = 0; batch_idx < num_batches; ++batch_idx) {
            std::vector<std::string> batch_fens = get_batch(batch_idx * batch_size, batch_size);

            // Evaluate the batch
            std::vector<Clockwork::Autograd::Score> scores = evaluator.evaluate(batch_fens);
            // Pass through sigmoid
            for (auto& score : scores) {
                score = sigmoid.compute(score);
            }

            // Compute loss and gradients
            for (size_t i = 0; i < scores.size(); ++i) {
                Clockwork::Autograd::Score loss = mse_loss.compute(scores[i], results[batch_idx * batch_size + i]);
                loss.backward();
            }

            // Step the optimizer
            optim.step();
            optim.zero_grad();
            optim.clear_graph(); 

            if (batch_idx % 10 == 0) {
                // Print values of parameters
                std::cout << "Pawn Material: " << Clockwork::HCE::PAWN_MAT.mg.value() << ", " 
                        << Clockwork::HCE::PAWN_MAT.eg.value() << std::endl;
                std::cout << "Knight Material: " << Clockwork::HCE::KNIGHT_MAT.mg.value() << ", " 
                        << Clockwork::HCE::KNIGHT_MAT.eg.value() << std::endl;
                std::cout << "Bishop Material: " << Clockwork::HCE::BISHOP_MAT.mg.value() << ", " 
                        << Clockwork::HCE::BISHOP_MAT.eg.value() << std::endl;
                std::cout << "Rook Material: " << Clockwork::HCE::ROOK_MAT.mg.value() << ", " 
                        << Clockwork::HCE::ROOK_MAT.eg.value() << std::endl;
                std::cout << "Queen Material: " << Clockwork::HCE::QUEEN_MAT.mg.value() << ", " 
                        << Clockwork::HCE::QUEEN_MAT.eg.value() << std::endl;
                std::cout << "Mobility Value: " << Clockwork::HCE::MOBILITY_VAL.mg.value() << ", " 
                        << Clockwork::HCE::MOBILITY_VAL.eg.value() << std::endl;
                std::cout << "Tempo Value: " << Clockwork::HCE::TEMPO_VAL.mg.value() << ", " 
                        << Clockwork::HCE::TEMPO_VAL.eg.value() << std::endl; 
            }

        }
        std::cout << "Epoch " << epoch + 1 << " completed." << std::endl;

        // Print values of parameters
        std::cout << "Pawn Material: " << Clockwork::HCE::PAWN_MAT.mg.value() << ", " 
                  << Clockwork::HCE::PAWN_MAT.eg.value() << std::endl;
        std::cout << "Knight Material: " << Clockwork::HCE::KNIGHT_MAT.mg.value() << ", " 
                  << Clockwork::HCE::KNIGHT_MAT.eg.value() << std::endl;
        std::cout << "Bishop Material: " << Clockwork::HCE::BISHOP_MAT.mg.value() << ", " 
                  << Clockwork::HCE::BISHOP_MAT.eg.value() << std::endl;
        std::cout << "Rook Material: " << Clockwork::HCE::ROOK_MAT.mg.value() << ", " 
                  << Clockwork::HCE::ROOK_MAT.eg.value() << std::endl;
        std::cout << "Queen Material: " << Clockwork::HCE::QUEEN_MAT.mg.value() << ", " 
                  << Clockwork::HCE::QUEEN_MAT.eg.value() << std::endl;
        std::cout << "Mobility Value: " << Clockwork::HCE::MOBILITY_VAL.mg.value() << ", " 
                  << Clockwork::HCE::MOBILITY_VAL.eg.value() << std::endl;
        std::cout << "Tempo Value: " << Clockwork::HCE::TEMPO_VAL.mg.value() << ", " 
                  << Clockwork::HCE::TEMPO_VAL.eg.value() << std::endl; 
        
    }

    std::cout << "If we see this we haven't crashed (hooray!)." << std::endl;
    return 0;


}
