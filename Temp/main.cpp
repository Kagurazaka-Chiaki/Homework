// #include <iostream>
// int f1(int x) {
//     if (x <= 1) {
//         return 1;
//     } else {
//         return 2 * f1(x - 1);
//     }
// }
// int f2(int x) {
//     if (x <= 1) {
//         return 1;
//     } else {
//         return f2(x - 1) + f1(x) + x / 2;
//     }
// }
// int f3(int x) {
//     if (x <= 1) {
//         return 1;
//     } else {
//         return f3(x - 1) + f2(x) + x;
//     }
// }
// auto main(int argc, char const *argv[]) -> int {
//     std::cout << f3(5) << std::endl;
//     return 0;
// }


// #include <array>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <iostream>
// #include <queue>
// #include <utility>
// #include <vector>
// #include <unordered_map>

// template<typename T>
// void pp(std::vector<T> const& vec) {
//     for (T const& v : vec) {
//         std::cout << v << ' ';
//     }
//     std::cout << '\n';
// }


// void ppp(std::unordered_map<int, std::pair<int, int>> const& map) {
//     for (auto const& it : map) {
//         std::cout << '[' << it.first << "-> {" << it.second.first << ", " << it.second.second << "} ]\n";
//     }
//     std::cout << '\n';
// }


// int map_str_to_int(char x) {
//     switch (x) {
//         case '.':
//             return 0;
//         case '#':
//             return 1;
//         default:
//             return x;
//     }
//     return x;
// }

// std::array<std::pair<int, int>, 4> dir4 = {
//     std::pair{-1,  0},
//     std::pair{ 0,  1},
//     std::pair{ 1,  0},
//     std::pair{ 0, -1},
// };

// auto h(std::pair<int, int> s, std::pair<int, int> t) {
//     return std::abs(s.first - t.first) +  std::abs(s.second - t.second);
// }

// void p(std::pair<int, int> pair) {
//     printf("[%d, %d]", pair.first, pair.second);
// }

// auto astar(
//     std::vector<std::vector<int>> &g, int n, int m,
//     std::pair<int, int> s, std::pair<int, int> t,
//     std::unordered_map<int, std::pair<int, int>> a, std::vector<int> b
// ) {
//     for (auto &it : a) {
//         int x = a[it.first].first;
//         int y = a[it.first].second;
//         if (b[it.first - '0' + 1] != 1) {
//             g[x][y] = 1;
//         }
//     }
//     std::vector<std::pair<int, int>> path;
//     std::queue<std::pair<int, int>> q;
//     std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
//     q.push(s);
//     // vis[s.first][s.second] = 1;
//     while (!q.empty()) {
//         auto curr = q.front();
//         q.pop();
//         // p(curr);
//         if (curr == t) {
//             break;
//         }
//         path.push_back(curr);
//         if (vis[s.first][s.second] == 1) { continue; }
//         vis[s.first][s.second] = 1;
//         for (auto const &[dx, dy] : dir4) {
//             int nx = dx + curr.first;
//             int ny = dy + curr.second;
//             // printf("[%d, %d]", nx, ny);
//             if (nx < 0 || nx > n - 1) { continue; }
//             if (ny < 0 || ny > m - 1) { continue; }
//             // printf("[%d, %d]", nx, ny);
//             if (g[nx][ny] == 0) {
//                 // printf("[%d, %d]", nx, ny);
//                 q.push(std::pair<int, int>(nx, ny));
//             }
//         }
//     }
//     return path;
// }

// int main() {
//     // int n, m;
//     // scanf("%d %d\n", &n, &m);
//     // // printf("%d x %d\n", n, m);
//     // std::vector<std::vector<int>> g(n, std::vector<int>(m, 0));
//     // std::unordered_map<int, std::pair<int, int>> eg{};
//     // for (int i = 0; i < n; ++i) {
//     //     for (int j = 0; j < m - 1; ++j) {
//     //         char x;
//     //         scanf("%c", &x);
//     //         // printf("[%c]", x);
//     //         if (x != '.' && x != '#') {
//     //             eg[x] = std::pair<int, int>{i, j};
//     //         }
//     //         g[i][j] = map_str_to_int(x);
//     //     }
//     //     char x;
//     //     scanf("%c\n", &x);
//     //     // printf("[%c]", x);
//     //     if (x != '.' && x != '#') {
//     //         eg[x] = std::pair<int, int>{i, m - 1};
//     //     }
//     //     g[i][m - 1] = map_str_to_int(x);
//     // }
//     // // for (int i = 0; i < n; ++i) {
//     // //     for (int j = 0; j < m; ++j) {
//     // //         printf("[%2d]", g[i][j]);
//     // //     }
//     // //     printf("\n");
//     // // }
//     // // ppp(eg);
//     // std::vector<int> b(5, 1);
//     // int ans = 0;
//     // auto path = astar(g, n, m, eg['S'], eg['1'], eg, b);
//     // b['1' - '0' - 1] = 0;
//     // // pp(b);
//     // // for (auto v : path) {
//     // //     p(v);
//     // // }
//     // // printf("\n");
//     // ans += path.size();
//     // // printf("%d", ans);
//     // for (int s = '1'; s < '6'; ++s) {
//     //     // printf("%d -> %d\n", s, s + 1);
//     //     auto path = astar(g, n, m, eg[s], eg[s + 1], eg, b);
//     //     b[s - '0' - 1] = 0;
//     //     // pp(b);
//     //     // for (auto v : path) {
//     //     //     p(v);
//     //     // }
//     //     // printf("\n");
//     //     ans += path.size() - 1;
//     // }
//     // printf("%d", ans + 2);
//     return EXIT_SUCCESS;
// }
// // 64 位输出请用 printf("%lld")

// MyProgram.cpp
// import std;

#include <iostream>

// import kemp;

int main() {
    // std::cout << "The result of f() is " << Example_NS::f() << std::endl; // 42
    // int i = Example_NS::f_internal(); // C2039
    // int j = ANSWER; //C2065


    return 0;
}
