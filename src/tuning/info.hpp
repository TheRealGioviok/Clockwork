#pragma once

#include "util/types.hpp"
#include "util/vec/sse2.hpp"
#include <cassert>
#include <vector>

namespace Clockwork::Autograd {

struct ParameterCountInfo {
    usize parameter_count;
    usize pair_parameter_count;
};

struct Parameters {
    std::vector<f64>  parameters;
    std::vector<f128> pair_parameters;

    static Parameters zeros(ParameterCountInfo counts) {
        Parameters result;
        result.parameters.resize(counts.parameter_count, 0.0);
        result.pair_parameters.resize(counts.pair_parameter_count, f128::zero());
        return result;
    }

    void accumulate(const Parameters& b) {
        assert(b.parameters.size() == parameters.size());
        assert(b.pair_parameters.size() == pair_parameters.size());
        for (usize i = 0; i < parameters.size(); i++) {
            parameters[i] += b.parameters[i];
        }
        for (usize i = 0; i < pair_parameters.size(); i++) {
            pair_parameters[i] = f128::add(pair_parameters[i], b.pair_parameters[i]);
        }
    }

    void weighted_accumulate(f64 weight, const Parameters& b) {
        assert(b.parameters.size() == parameters.size());
        assert(b.pair_parameters.size() == pair_parameters.size());
        for (usize i = 0; i < parameters.size(); i++) {
            parameters[i] += weight * b.parameters[i];
        }
        for (usize i = 0; i < pair_parameters.size(); i++) {
            pair_parameters[i] =
              f128::madd(pair_parameters[i], f128::broadcast(weight), b.pair_parameters[i]);
        }
    }

    void scale(f64 factor) {
        for (usize i = 0; i < parameters.size(); i++) {
            parameters[i] *= factor;
        }
        f128 factor_f128 = f128::broadcast(factor);
        for (usize i = 0; i < pair_parameters.size(); i++) {
            pair_parameters[i] = f128::mul(pair_parameters[i], factor_f128);
        }
    }
};

}  // namespace Clockwork::Autograd
