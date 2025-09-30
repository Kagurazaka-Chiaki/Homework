
#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

#include <deque>
#include <ostream>
#include <iostream>
#include <utility>
#include <vector>

struct BooleanSemiring {
    using value = unsigned char;

    static constexpr value one() { return true; }

    static constexpr value zero() { return false; }

    static value add(value a, value b) { return a || b; }

    static value mul(value a, value b) { return a && b; }

    static value pow(value a, int n) {
        if (n == 0) {
            return one();
        }
        if (n & 1) {
            return mul(a, pow(a, n - 1));
        }
        value t = pow(a, n >> 1);
        return mul(t, t);
    }

    friend std::ostream &operator<<(std::ostream &os, value v) {
        return os << v;
    }
};

template<class Symbol, class Semi = BooleanSemiring>
struct Automaton {
    using value = typename Semi::value;

    struct Edge {
        int    to;
        Symbol symbol;
        value  weight;
    };

    int                                             n     = 0;
    int                                             start = 0;
    std::vector<std::vector<Edge>>                  adj;
    std::vector<std::vector<std::pair<int, value>>> eps;
    std::vector<value>                              final_w;

    explicit Automaton(int n = 0)
        : adj(n), eps(n), final_w(n, Semi::zero()) {}

    int add_state(value final_weight = Semi::zero()) {
        int id = n++;
        adj.emplace_back();
        eps.emplace_back();
        final_w.push_back(final_weight);
        return id;
    }

    void set_start(int s) { start = s; }

    void set_final(int s, value w) { final_w[s] = w; }

    void add_edge(int from, int to, Symbol c, value w = Semi::one()) {
        adj[from].push_back(Edge{to, std::move(c), w});
    }

    void add_eps(int from, int to, value w = Semi::one()) {
        eps[from].emplace_back(to, w);
    }

    auto closure(std::vector<value> const &vec) const -> std::vector<value> {
        std::vector<value> res = vec;
        std::deque<int>    dq;
        std::vector<char>  inq(n, 0);
        for (int i = 0; i < n; ++i) {
            if (res[i] != Semi::zero()) {
                dq.push_back(i);
                inq[i] = 1;
            }
        }
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            inq[u] = 0;
            for (auto [v, w]: eps[u]) {
                value nw = Semi::mul(res[u], w);
                value ov = res[v];
                if (ov != res[v]) {
                    res[v] = ov;
                    if (!inq[v]) {
                        dq.push_back(v);
                        inq[v] = 1;
                    }
                }
            }
        }
        return res;
    }

    auto simulate(std::vector<Symbol> const &input) const -> value {
        std::vector<value> cur(n, Semi::zero());
        if (start == -1) return Semi::zero();
        cur[start] = Semi::one();
        cur        = closure(cur);
        for (auto c: input) {
            std::cout << "After reading symbol " << c << ", state weights: ";
            for (const auto& weight : cur) {
                std::cout << weight << " ";
            }
            std::cout << std::endl;
            std::vector<value> next(n, Semi::zero());
            for (int u = 0; u < n; ++u) {
                if (cur[u] == Semi::zero()) {
                    continue;
                }
                for (auto &e: adj[u]) {
                    if (e.symbol == c) {
                        value nw = Semi::mul(cur[u], e.weight);
                        value ov = next[e.to];
                        if (nw != ov) {
                            next[e.to] = Semi::add(ov, nw);
                        }
                    }
                }
            }
            cur = closure(next);
        }
        value res = Semi::zero();
        for (int q = 0; q < n; ++q) {
            if (final_w[q] != Semi::zero() && cur[q] != Semi::zero()) {
                res = Semi::add(res, Semi::mul(cur[q], final_w[q]));
            }
        }
        return res;
    }
};


#endif // AUTOMATON_HPP
