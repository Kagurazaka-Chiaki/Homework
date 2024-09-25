

#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "minicoro.hpp"


minicoro::generator<int> sequence() {
    int i = 0;
    while (i < 5) {
        co_await i++;
    }
}

TEST_CASE("sequence") {
    auto generator = sequence();
    for (int i = 0; i < 15; ++i) {
        if (generator.has_next()) {
            std::cout << generator.next() << std::endl;
        } else {
            break;
        }
    }
}


TEST_CASE("flat_map") {
    minicoro::generator<int>::from(1, 2, 3, 4)
            .flat_map([](auto i) -> minicoro::generator<int> {
                for (int j = 0; j < i; ++j) {
                    co_yield j;
                }
            })
            .for_each([](auto i) {
                if (i == 0) {
                    std::cout << std::endl;
                }
                std::cout << "* ";
            });

    std::cout << std::endl;
}


TEST_CASE("map") {
    minicoro::generator<int>::from(1, 2, 3, 4)
            .map([](auto i) {
                return i * 2;
            })
            .for_each([](auto i) {
                std::cout << i << " ";
            });

    std::cout << std::endl;
}


TEST_CASE("fold") {
    auto result = minicoro::generator<int>::from(1, 2, 3, 4, 5, 6)
            .fold(1, [](auto acc, auto i) {
                return acc * i;
            });
    CHECK(result == 720);
}

minicoro::generator<int> fibonacci() {
    co_yield 0; // fib(0)
    co_yield 1; // fib(1)

    int a = 0;
    int b = 1;
    while (true) {
        co_yield a + b; // fib(N), N > 1
        b = a + b;
        a = b - a;
    }
}

TEST_CASE("take_until") {
    fibonacci().take_until([](auto i) {
        return i < 100;
    }).for_each([](auto i) {
        std::cout << i << " ";
    });
}

