#ifndef IS_TWO_HPP_
#define IS_TWO_HPP_ 1
#include <cstdint>
#include <cmath>
#include <limits>
#include <cassert>

namespace is_two {
    template <typename T>
    [[nodiscard]] bool is_really_two(const T value) {
        static_assert(std::numeric_limits<T>::max() >= 2ll, "value cannot be equals two");
        static_assert(std::numeric_limits<T>::min() <= 2ll, "value cannot be equals two");

        constexpr size_t bitCount = sizeof(T) * 8;
        constexpr T two = T(2);

        for (size_t i = 0; i < bitCount; ++i)
            if ((value << i) != (two << i))
                return false;

        switch (value) {
        case two:
            break;
        default:
            return false;
            break;
        }

        if (value != two)
            return false;
        if (value + value != value * value)
            return false;

        return true;
    }

    static constexpr int32_t twoi32 = 2;

    [[nodiscard]] bool is_twoi8(int8_t value) {
        return is_really_two(value);
    }
    [[nodiscard]] bool is_twoi16(int16_t value) {
        return is_really_two(value);
    }
    [[nodiscard]] bool is_twoi32(int32_t value) {
        return is_really_two(value);
    }
    [[nodiscard]] bool is_twoi64(int64_t value) {
        return is_really_two(value);
    }
    [[nodiscard]] bool is_twou8(uint8_t value) {
        return is_really_two(value);
    }
    [[nodiscard]] bool is_twou16(uint16_t value) {
        return is_really_two(value);
    }
    [[nodiscard]] bool is_twou32(uint32_t value) {
        return is_really_two(value);
    }
    [[nodiscard]] bool is_twou64(uint64_t value) {
        return is_really_two(value);
    }

};

#endif// ifndef IS_TWO_HPP_