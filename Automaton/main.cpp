
#include "automaton.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    using Sym = int; // 用 0/1 表示字符
    Automaton<Sym, BooleanSemiring> A;
    int                             s0 = A.add_state(), s1 = A.add_state(), s2 = A.add_state();
    A.set_start(s0);
    A.set_final(s0, true); // 余数 0 为接受
    // 读一位 = (余数*2 + bit) mod 3
    A.add_edge(s0, s0, 0);
    A.add_edge(s0, s1, 1);
    A.add_edge(s1, s2, 0);
    A.add_edge(s1, s0, 1);
    A.add_edge(s2, s1, 0);
    A.add_edge(s2, s2, 1);

    std::vector<Sym> w  = {1, 1, 0, 0, 1}; // 二进制 25
    bool             ok = A.simulate(w);
    std::cout << (ok ? "ACCEPT\n" : "REJECT\n");

    return EXIT_SUCCESS;
}
