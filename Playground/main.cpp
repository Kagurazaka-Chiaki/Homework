
#include <unordered_map>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

template<typename T>
void print_vector(std::vector<T> const &vec) {
    for (auto const &v: vec) {
        std::cout << "[" << v << "]";
    }
    std::cout << std::endl;
}

template<typename T>
void print_matrix(std::vector<std::vector<T>> const &mat) {
    std::cout << "[" << std::endl;
    for (auto const &m: mat) {
        print_vector(m);
    }
    std::cout << "]" << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &vec) {
    os << "vec: " << "size: {" << vec.size() << "} ";
    for (auto const &v: vec) {
        os << "[" << v << "]";
    }
    return os << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::pair<T, T> const &pair) {
    os << "pair: " << "{" << pair.first << ", " << pair.second << "}";
}

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &map) {
    auto all_key_vec = std::vector<K>(map.size());
    std::transform(map.begin(), map.end(), all_key_vec.begin(), [](auto const &pair) { return pair.first; });
    std::sort(all_key_vec.begin(), all_key_vec.end());
    std::cout << "map: " << "size: [" << map.size() << "]" << std::endl;
    for (auto const &key: all_key_vec) {
        std::cout << "[" << key << "]: " << map.at(key) << std::endl;
    }
}

auto get_curr_path(std::string const &folder_name) -> std::filesystem::path {
    auto bin_path = std::filesystem::current_path();
    auto build_path = bin_path.parent_path();
    auto project_path = build_path.parent_path();
    return project_path / folder_name;
}

int get_sum(std::vector<int> const &tree, int s, int t, int p, int l, int r) {
    if (l <= s && t <= r) {
        return tree[p];
    }
    int m = (s + t) / 2;
    int res = 0;
    if (l <= m) {
        res += get_sum(tree, s, m, 2 * p, l, r);
    }
    if (r > m) {
        res += get_sum(tree, m + 1, t, 2 * p + 1, l, r);
    }
    return res;
}

void build_tree(std::vector<int> &tree, std::vector<int> const &d, int s, int t, int p) {
    if (s == t) {
        tree[p] = d[s];
        return;
    }
    int m = (s + t) / 2;
    build_tree(tree, d, s, m, 2 * p);
    build_tree(tree, d, m + 1, t, 2 * p + 1);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

namespace global {
    std::unordered_map<int, std::vector<std::vector<int>>> v = {};

    int ans = 0;
} // namespace global


struct node {
    int from = 0;
    int to = 0;
    int val = 0;
};

struct state {
    int x = 0;
    int y = 0;
    int dist = 0;
    int hp = 0;
};

void compute(std::fstream &fcin, std::fstream &fcout) {

    int n, m, h;
    fcin >> n >> m >> h;

    std::cout << "n: " << n << " m: " << m << std::endl;

    auto raw_map = std::vector<std::vector<char>>(n, std::vector<char>(m, '\0'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fcin >> raw_map[i][j];
        }
    }

    std::cout << "map: " << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << raw_map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    auto dir = std::vector<std::pair<int, int>>({
        {-1,  0}, // 上
        { 1,  0}, // 下
        { 0, -1}, // 左
        { 0,  1}  // 右
    });

    // bfs
    auto q = std::deque<state>();
    //
    auto flag = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));

    // 起始状态
    q.push_back({0, 0, 0, h});

    while (!q.empty()) {
        state cur = q.front();
        q.pop_front();

        std::cout << "cur: " << cur.x << " " << cur.y << " " << cur.dist << " " << cur.hp << std::endl;

        if (cur.x == n - 1 && cur.y == m - 1) { 
            std::cout << "ans: " << cur.dist << std::endl;
            break; 
        }

        for (auto const &d: dir) {
            int nx = cur.x + d.first;
            int ny = cur.y + d.second;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }

            printf("(%d, %d) -> [%c] %d\n", nx, ny, raw_map[nx][ny], flag[nx][ny]);

            if (raw_map[nx][ny] == '*') { continue; }

            if (raw_map[nx][ny] == '.') {
                q.push_back({nx, ny, cur.dist + 1, cur.hp});
            }

            if (raw_map[nx][ny] >= '0' && raw_map[nx][ny] <= '9') {
                int nhp = cur.hp - (raw_map[nx][ny] - '0');
                printf("nhp: %d\n", nhp);
                if (nhp <= 0) { continue; }
                q.push_back({nx, ny, cur.dist + 1, nhp});
            }
        }
    }
}

int main() {
    auto playground_path = get_curr_path("Playground");

    // read the content of input.txt
    auto input_path = playground_path / "input.txt";
    std::fstream input_file(input_path, std::ios::in);

    if (!input_file.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return EXIT_FAILURE;
    }

    // create a output.txt file
    auto output_path = playground_path / "output.txt";
    std::fstream output_file(output_path, std::ios::out | std::ios::trunc);

    if (!output_file.is_open()) {
        std::cerr << "Failed to open output.txt" << std::endl;
        return EXIT_FAILURE;
    }

    compute(input_file, output_file);

    input_file.close();
    output_file.close();
    return EXIT_SUCCESS;
}