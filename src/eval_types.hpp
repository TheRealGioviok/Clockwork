#pragma once

#include "util/types.hpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <limits>

#ifdef EVAL_TUNING
    #include "tuning/globals.hpp"
    #include "tuning/loss.hpp"
    #include "tuning/optim.hpp"
    #include "tuning/value.hpp"
#endif

namespace Clockwork {
#ifndef EVAL_TUNING

class Score {
private:
    i16 m_score;
public:
    constexpr Score() :
        m_score{} {
    }
    constexpr Score(i16 score) :
        m_score{score} {
    }

    [[nodiscard]] constexpr auto operator+(const Score& other) const {
        return Score{static_cast<i16>(m_score + other.m_score)};
    }
    [[nodiscard]] constexpr auto operator-(const Score& other) const {
        return Score{static_cast<i16>(m_score - other.m_score)};
    }
    [[nodiscard]] constexpr auto operator*(const Score& other) const {
        return Score{static_cast<i16>(m_score * other.m_score)};
    }
    [[nodiscard]] constexpr auto operator/(const Score& other) const {
        return Score{static_cast<i16>(m_score / other.m_score)};
    }
    constexpr auto operator+=(const Score& other) -> auto& {
        m_score = static_cast<i16>(m_score + other.m_score);
        return *this;
    }

    constexpr auto operator-=(const Score& other) -> auto& {
        m_score = static_cast<i16>(m_score - other.m_score);
        return *this;
    }

    [[nodiscard]] constexpr auto operator*=(const Score& other) -> auto& {
        m_score = static_cast<i16>(m_score * other.m_score);
        return *this;
    }
    [[nodiscard]] constexpr auto operator/=(const Score& other) -> auto& {
        m_score = static_cast<i16>(m_score / other.m_score);
        return *this;
    }
    [[nodiscard]] constexpr auto operator-() const {
        return Score{static_cast<i16>(-m_score)};
    }

    [[nodiscard]] constexpr bool operator==(const Score& other) const = default;

    [[nodiscard]] constexpr const Score* operator->() const {
        return this;
    }

    [[nodiscard]] constexpr i16 get_score() const {
        return m_score;
    }

    // Conversion to int
    explicit constexpr operator i16() const {
        return m_score;
    }
    explicit constexpr operator u16() const {
        return static_cast<u16>(m_score);
    }
    explicit constexpr operator i32() const {
        return static_cast<i32>(m_score);
    }
    explicit constexpr operator u32() const {
        return static_cast<u32>(m_score);
    }

    // i32 operators
    [[nodiscard]] constexpr auto operator+(i32 other) const {
        return Score{static_cast<i16>(m_score + other)};
    }
    [[nodiscard]] constexpr auto operator-(i32 other) const {
        return Score{static_cast<i16>(m_score - other)};
    }
    [[nodiscard]] constexpr auto operator*(i32 other) const {
        return Score{static_cast<i16>(m_score * other)};
    }
    [[nodiscard]] constexpr auto operator/(i32 other) const {
        return Score{static_cast<i16>(m_score / other)};
    }

    // i32 inplace operators
    constexpr auto operator+=(i32 other) -> auto& {
        m_score = static_cast<i16>(m_score + other);
        return *this;
    }
    constexpr auto operator-=(i32 other) -> auto& {
        m_score = static_cast<i16>(m_score - other);
        return *this;
    }
    constexpr auto operator*=(i32 other) -> auto& {
        m_score = static_cast<i16>(m_score * other);
        return *this;
    }
    constexpr auto operator/=(i32 other) -> auto& {
        m_score = static_cast<i16>(m_score / other);
        return *this;
    }

    // i16 operators
    [[nodiscard]] constexpr auto operator+(i16 other) const {
        return Score{static_cast<i16>(m_score + other)};
    }
    [[nodiscard]] constexpr auto operator-(i16 other) const {
        return Score{static_cast<i16>(m_score - other)};
    }
    [[nodiscard]] constexpr auto operator*(i16 other) const {
        return Score{static_cast<i16>(m_score * other)};
    }
    [[nodiscard]] constexpr auto operator/(i16 other) const {
        return Score{static_cast<i16>(m_score / other)};
    }

    // i16 inplace operators
    constexpr auto operator+=(i16 other) -> auto& {
        m_score = static_cast<i16>(m_score + other);
        return *this;
    }
    constexpr auto operator-=(i16 other) -> auto& {
        m_score = static_cast<i16>(m_score - other);
        return *this;
    }
    constexpr auto operator*=(i16 other) -> auto& {
        m_score = static_cast<i16>(m_score * other);
        return *this;
    }
    constexpr auto operator/=(i16 other) -> auto& {
        m_score = static_cast<i16>(m_score / other);
        return *this;
    }

    // sign
    Score sign() const {
        if (m_score > 0) {
            return Score{1};
        } else if (m_score < 0) {
            return Score{-1};
        } else {
            return Score{0};
        }
    }

    // relu
    Score relu() const {
        return Score{std::max<i16>(0, m_score)};
    }

    // abs
    Score abs() const {
        return Score{static_cast<i16>(std::abs(m_score))};
    }

    friend std::ostream& operator<<(std::ostream& os, const Score& score) {
        os << score.m_score;
        return os;
    }

    // friend i32 operators
    friend Score operator+(i32 a, const Score& b) {
        return Score{static_cast<i16>(a + b.m_score)};
    }
    friend Score operator-(i32 a, const Score& b) {
        return Score{static_cast<i16>(a - b.m_score)};
    }
    friend Score operator*(i32 a, const Score& b) {
        return Score{static_cast<i16>(a * b.m_score)};
    }
    friend Score operator/(i32 a, const Score& b) {
        return Score{static_cast<i16>(a / b.m_score)};
    }

};

class PScore {
private:
    i32 m_score;
    explicit constexpr PScore(i32 score) :
        m_score{score} {
    }

public:
    constexpr PScore() :
        m_score{} {
    }

    constexpr PScore(Score midgame, Score endgame) :
        m_score{static_cast<i32>(static_cast<u32>(endgame) << 16) + midgame} {
        assert(std::numeric_limits<i16>::min() <= midgame
               && std::numeric_limits<i16>::max() >= midgame);
        assert(std::numeric_limits<i16>::min() <= endgame
               && std::numeric_limits<i16>::max() >= endgame);
    }
    
    constexpr PScore(i16 midgame, i16 endgame) :
        m_score{static_cast<i32>(static_cast<u32>(static_cast<u16>(endgame)) << 16)
                + static_cast<u16>(midgame)} {
    }

    constexpr PScore(i32 midgame, i32 endgame) :
        m_score{(endgame << 16) + midgame} {
        assert(std::numeric_limits<i16>::min() <= midgame
               && std::numeric_limits<i16>::max() >= midgame);
        assert(std::numeric_limits<i16>::min() <= endgame
               && std::numeric_limits<i16>::max() >= endgame);
    }

    [[nodiscard]] inline auto mg() const {
        const auto mg = static_cast<u16>(m_score);

        i16 v{};
        std::memcpy(&v, &mg, sizeof(mg));

        return static_cast<Score>(v);
    }

    [[nodiscard]] inline auto eg() const {
        const auto eg = static_cast<u16>(static_cast<u32>(m_score + 0x8000) >> 16);

        i16 v{};
        std::memcpy(&v, &eg, sizeof(eg));

        return static_cast<Score>(v);
    }

    [[nodiscard]] constexpr auto operator+(const PScore& other) const {
        return PScore{m_score + other.m_score};
    }

    constexpr auto operator+=(const PScore& other) -> auto& {
        m_score += other.m_score;
        return *this;
    }

    [[nodiscard]] constexpr auto operator-(const PScore& other) const {
        return PScore{m_score - other.m_score};
    }

    constexpr auto operator-=(const PScore& other) -> auto& {
        m_score -= other.m_score;
        return *this;
    }

    [[nodiscard]] constexpr auto operator*(i32 v) const {
        return PScore{m_score * v};
    }

    constexpr auto operator*=(i32 v) -> auto& {
        m_score *= v;
        return *this;
    }

    [[nodiscard]] constexpr auto operator-() const {
        return PScore{-m_score};
    }

    [[nodiscard]] constexpr bool operator==(const PScore& other) const = default;

    [[nodiscard]] constexpr const PScore* operator->() const {
        return this;
    }

    // Phasing between two scores
    template<i32 max>
    Value phase(i32 alpha) const {
        assert(0 <= alpha && alpha <= max);
        return static_cast<Value>((mg() * alpha + eg() * (max - alpha)) / max);
    }

    friend std::ostream& operator<<(std::ostream& stream, const PScore& score) {
        stream << "(" << score.mg() << "\t" << score.eg() << ")";
        return stream;
    }
};

using PParam = PScore;

#else

using Score  = Autograd::ValuePtr;
using PScore = Autograd::PairPtr;
using PParam = Autograd::PairPlaceholder;

#endif

#ifdef EVAL_TUNING
    #define S(a, b) Autograd::PairPlaceholder::create_tunable((a), (b))  // Defines a tunable pscore
    #define CS(a, b) Autograd::PairPlaceholder::create((a), (b))
    #define PSCORE_ZERO Autograd::Pair::create(0, 0)
#else
    #define S(a, b) PScore((a), (b))  // Defines a constant pscore when not tuning
    #define CS(a, b) S((a), (b))
    #define PSCORE_ZERO CS(0, 0)
#endif

}  // namespace Clockwork
