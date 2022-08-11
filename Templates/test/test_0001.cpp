
#include "templib/base.hpp"
#include "templib/sort.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("template quicksort") {
    using l_q_1 = temp::t_list<1, 2, 3>;
    using l_q_2 = temp::t_list<4, 5, 6>;

    using l_q_3 = temp::t_concat<l_q_2, temp::t_list<>, l_q_1>::value;

    int r = temp::t_accumulate<l_q_1>::value;

    std::cout << r << std::endl;

    temp::t_print(l_q_3());

    using l_q_4 = temp::t_less<5>::t_less_partial<4>;

    using l_q_5 = temp::t_not<l_q_4::value>;

    std::cout << l_q_5::value << std::endl;

    using l_q_6 = temp::t_qsort<l_q_3>::value;

    temp::t_print(l_q_6());


}