#pragma once

#include "value.hpp"
#include <stdexcept>
#include <vector>

namespace Clockwork::Autograd {

enum class Reduction {
    None,
    Sum,
    Mean
};

template<typename Target = f64, Reduction R = Reduction::Mean>
auto mse(const std::vector<ValueHandle>& predictions, const std::vector<Target>& targets) {
    if (predictions.size() != targets.size()) {
        throw std::invalid_argument("MSE: predictions and targets must have the same size.");
    }

    if constexpr (R == Reduction::None) {
        std::vector<ValueHandle> losses;
        losses.reserve(predictions.size());
        for (size_t i = 0; i < predictions.size(); ++i) {
            ValueHandle diff = predictions[i] - targets[i];
            losses.push_back(diff * diff);
        }
        return losses;
    } else {
        std::vector<ValueHandle> losses;
        losses.reserve(predictions.size());
        for (size_t i = 0; i < predictions.size(); ++i) {
            ValueHandle diff = predictions[i] - targets[i];
            losses.push_back(diff * diff);
        }
        ValueHandle total_loss = ValueHandle::sum(losses);

        if constexpr (R == Reduction::Mean) {
            f64 n = static_cast<f64>(predictions.size());
            return total_loss * (1.0 / n);
        } else {
            return total_loss;
        }
    }
}

template<typename Target = f64, Reduction R = Reduction::Mean>
auto cross_entropy(const std::vector<ValueHandle>& logits,
                   const std::vector<Target>&      targets,
                   f64                             smoothing = 0.0) {
    if (logits.size() != targets.size()) {
        throw std::invalid_argument(
          "CrossEntropy: predictions and targets must have the same size.");
    }
    if (smoothing < 0.0 || smoothing >= 1.0) {
        throw std::invalid_argument("CrossEntropy: smoothing must be in [0, 1).");
    }

    std::vector<ValueHandle> losses;
    losses.reserve(logits.size());
    for (size_t i = 0; i < logits.size(); ++i) {
        f64 y        = static_cast<f64>(targets[i]);
        f64 y_smooth = y * (1.0 - smoothing) + 0.5 * smoothing;
        losses.push_back(logits[i].bce_with_logits(y_smooth));
    }

    if constexpr (R == Reduction::None) {
        return losses;
    } else {
        ValueHandle total_loss = ValueHandle::sum(losses);
        if constexpr (R == Reduction::Mean) {
            f64 n = static_cast<f64>(logits.size());
            return total_loss * (1.0 / n);
        } else {
            return total_loss;
        }
    }
}

}  // namespace Clockwork::Autograd
