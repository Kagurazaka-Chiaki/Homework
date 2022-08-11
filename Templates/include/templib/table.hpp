#ifndef TEMP_TABLE_HPP
#define TEMP_TABLE_HPP

#include "templib/base.hpp"

#include <array>


namespace temp {

    template<int x>
    struct t_func {
            static constexpr int value = x + t_func<x - 1>::value;
    };

    template<>
    struct t_func<0> {
            static constexpr int value = 0;
    };

    template<typename T, T... x>
    constexpr auto t_table(std::integer_sequence<T, x...>) -> std::array<T, sizeof...(x)> {
        return {t_func<x>::value...};
    };


} // namespace temp

#endif // TEMP_TABLE_HPP
