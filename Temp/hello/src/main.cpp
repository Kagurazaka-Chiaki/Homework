#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

int factorial (int n) {
  if (n <= 1) return n;
  return factorial(n-1) * n;
}

TEST_CASE("testing factorial") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}