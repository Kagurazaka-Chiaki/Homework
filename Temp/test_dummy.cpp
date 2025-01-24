
#include <type_traits>
#include <catch2/catch_test_macros.hpp>


struct Dummy {
    int var;
};

decltype(auto) fun_0(Dummy& d) {
    return d.var;
}

// Note that if the name of an object is parenthesized, 
// it is treated as an ordinary lvalue expression, thus decltype(x) and decltype((x)) are often different types.
// https://en.cppreference.com/w/cpp/language/decltype
decltype(auto) fun_1(Dummy& d) {
    return (d.var);
}


TEST_CASE("dummy decltype(auto) test", "[dummy]") {
    Dummy d{42};
    static_assert(std::is_same_v<decltype(fun_0(d)), int>, "fun_0 return type is not int");
    static_assert(std::is_same_v<decltype(fun_1(d)), int &>, "fun_1 return type is not int &");
    REQUIRE(fun_0(d) == 42);
    REQUIRE(fun_1(d) == 42);
}
