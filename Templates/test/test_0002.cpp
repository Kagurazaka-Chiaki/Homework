
#include "templib/base.hpp"
#include "templib/sort.hpp"
#include "templib/table.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("template table") {

    auto n = 3;

    static constexpr auto table = temp::t_table(std::make_integer_sequence<int, 10001>{});

    using qlist = temp::t_make_list<std::make_integer_sequence<int, 20>>;
    temp::t_print(qlist::value());
    using mlist = temp::t_map<temp::t_func, qlist::value>;
    temp::t_print(mlist::value());
    auto v = temp::t_index(mlist::value());
    CHECK(table[n] == v[n]);

}