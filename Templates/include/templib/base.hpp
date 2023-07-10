#ifndef TEMP_BASE_HPP
#define TEMP_BASE_HPP

// #include <bits/utility.h>
#include <initializer_list>

#include <iostream>
#include <iterator>
#include <vector>

namespace temp {

    template<int... x>
    struct t_list {};

    template<typename T, T... x>
    struct t_make_list {};

    template<typename T, T... x>
    struct t_make_list<std::integer_sequence<T, x...>> {
            using value = t_list<x...>;
    };

    template<bool cond, class if_then, class if_alt>
    struct t_if {};

    template<class if_then, class if_alt>
    struct t_if<true, if_then, if_alt> {
            using value = if_then;
    };

    template<class if_then, class if_alt>
    struct t_if<false, if_then, if_alt> {
            using value = if_alt;
    };

    template<class t_list>
    struct t_accumulate {
            static constexpr int value = 0;
    };

    template<>
    struct t_accumulate<t_list<>> {
            static constexpr int value = 0;
    };

    template<int x, int... y>
    struct t_accumulate<t_list<x, y...>> {
            static constexpr int value = x + t_accumulate<t_list<y...>>::value;
    };

    template<class lhs, class mid, class rhs>
    struct t_concat {};

    template<int... lhs, int... mid, int... rhs>
    struct t_concat<t_list<lhs...>, t_list<mid...>, t_list<rhs...>> {
            using value = t_list<lhs..., mid..., rhs...>;
    };

    template<template<int T> class f, class t_list>
    struct t_filter {};

    template<template<int T> class f>
    struct t_filter<f, t_list<>> {
            using value = t_list<>;
    };

    template<template<int T> class f, int x, int... y>
    struct t_filter<f, t_list<x, y...>> {
            using curr = typename t_if<f<x>::value, t_list<x>, t_list<>>::value;
            using next = typename t_filter<f, t_list<y...>>::value;
            using value = typename t_concat<t_list<>, curr, next>::value;
    };

    template<int x, typename t_list>
    struct t_push {};

    template<int x>
    struct t_push<x, t_list<>> {
            using value = t_list<x>;
    };

    template<int x, int... y>
    struct t_push<x, t_list<y...>> {
            using value = t_list<x, y...>;
    };

    template<typename t_list>
    struct t_pop {};

    template<>
    struct t_pop<t_list<>> {
            using value = t_list<>;
    };

    template<int x, int... y>
    struct t_pop<t_list<x, y...>> {
            using value = t_list<y...>;
    };

    template<template<int T> class f, class t_list>
    struct t_map {};

    template<template<int T> class f>
    struct t_map<f, t_list<>> {
            using value = t_list<>;
    };

    template<template<int T> class f, int x, int... y>
    struct t_map<f, t_list<x, y...>> {
            using value = typename t_push<f<x>::value, typename t_map<f, t_list<y...>>::value>::value;
    };

    template<bool val>
    struct t_not {
            static constexpr bool value = !val;
    };

    template<int lhs>
    struct t_less {
            template<int rhs>
            struct t_less_partial {
                    static constexpr bool value = lhs < rhs;
            };

            template<int rhs>
            using value = typename t_less_partial<rhs>::value;
    };

    template<int lhs>
    struct t_greater {
            template<int rhs>
            struct t_greater_partial {
                    static constexpr bool value = lhs > rhs;
            };

            template<int rhs>
            using value = typename t_greater_partial<rhs>::value;
    };

    template<int... x>
    auto t_print(t_list<x...>) -> void {
        static constexpr int vec[] = {x...};
        std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));
        std::endl(std::cout);
    }

    template<int... x>
    auto t_index(t_list<x...>) -> const int * {
        static constexpr int vec[] = {x...};
        return vec;
    }

} // namespace temp

#endif // TEMP_BASE_HPP
