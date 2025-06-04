#pragma once

#include "util/types.hpp"
#include <bit>
#include <cassert>

namespace Clockwork {

template<typename T>
[[nodiscard]] constexpr T clear_lowest_bit(T x) {
    return x & (x - 1);
}

template <typename T>
[[nodiscard]] constexpr i32 pop_lsb(T& x){
    assert(x != 0);
    auto ret = std::countr_zero(x);
    x = clear_lowest_bit(x);
    return ret;
}

}