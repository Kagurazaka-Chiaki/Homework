
#include <unordered_map>

#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto get_curr_path(std::string const &folder_name) -> std::filesystem::path {
    auto bin_path     = std::filesystem::current_path();
    auto build_path   = bin_path.parent_path();
    auto project_path = build_path.parent_path();
    return project_path / folder_name;
}

void m_op1(std::unordered_map<int, std::vector<int>> &M, int n, int m, int x, int y) {
    if (M.find(x) == M.end() && M.find(y) == M.end()) {
        M[x] = std::vector<int>(m, 0);
        M[y] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[y][j] = ((x + 1) - 1) * m + (j + 1);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((y + 1) - 1) * m + (j + 1);
        }
    } else if (M.find(x) != M.end() && M.find(y) == M.end()) {
        M[y] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[y][j] = ((x + 1) - 1) * m + (j + 1);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((y + 1) - 1) * m + (j + 1);
        }
    } else if (M.find(x) == M.end() && M.find(y) != M.end()) {
        M[x] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[y][j] = ((x + 1) - 1) * m + (j + 1);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((y + 1) - 1) * m + (j + 1);
        }
    } else if (M.find(x) != M.end() && M.find(y) != M.end()) {
        for (int j = 0; j < m; ++j) {
            std::swap(M[x][j], M[y][j]);
        }
    }
}

void m_op2(std::unordered_map<int, std::vector<int>> &M, int n, int m, int x, int y) {
    if (M.find(x) == M.end()) {
        M[x] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            int i   = (j + (y + 1)) % m;
            M[x][j] = ((x + 1) - 1) * m + (i + 1);
        }
    } else {
        std::vector<int> save = {};
        for (int j = 0; j < m; ++j) {
            save.push_back(M[x][j]);
        }
        for (int j = 0; j < m; ++j) {
            M[x][j] = save[(j + (y + 1)) % m];
        }
    }
}

void m_op3(std::unordered_map<int, std::vector<int>> &M, int n, int m, int x, int y) {
    if (M.find(x) == M.end()) {
        M[x] = std::vector<int>(m, 0);
        for (int j = 0; j < m; ++j) {
            M[x][j] = ((x + 1) - 1) * m + (j + 1);
        }
    }
    if (M.find(x) != M.end()) {
        printf("[%d]\n", M[x][y]);
    }
}

// x 行与 y 行交换
void v_op1(std::vector<std::vector<int>> &M, int n, int m, int x, int y) {
    for (int j = 0; j < m; ++j) {
        std::swap(M[x][j], M[y][j]);
    }
}

// x 行左移 y 格
void v_op2(std::vector<std::vector<int>> &M, int n, int m, int x, int y) {
    std::vector<int> save = {};
    for (int j = 0; j < m; ++j) {
        save.push_back(M[x][j]);
    }
    for (int j = 0; j < m; ++j) {
        M[x][j] = save[(j + (y + 1)) % m];
    }
}

// 输出 M[x][y]
void v_op3(std::vector<std::vector<int>> &M, int n, int m, int x, int y) {
    printf("[%d]\n", M[x][y]);
}

void print_vec(std::vector<std::vector<int>> const &M) {
    for (auto const &row: M) {
        for (auto const &col: row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

void print_map(std::unordered_map<int, std::vector<int>> const &M) {
    for (auto const &row: M) {
        std::cout << row.first << " -> ";
        if (row.second.empty()) {
            std::cout << "empty" << std::endl;
            continue;
        }
        for (auto const &col: row.second) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

void compute(std::fstream &fcin, std::fstream &fcout) {

    int n, m, T;
    fcin >> n >> m >> T;
    fcout << n << " " << m << " " << T << std::endl;


    std::unordered_map<int, std::vector<int>> M = {};

    // // vector 超过限制内存
    // std::vector<std::vector<int>> M = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         M[i][j] = ((i + 1) - 1) * m + (j + 1);
    //     }
    // }

    // print_vec(M);

    for (int i = 0; i < T; ++i) {
        int t, x, y;
        fcin >> t >> x >> y;
        fcout << t << " " << x << " " << y << " -> " << std::endl;
        switch (t) {
            case 1:
                m_op1(M, n, m, x - 1, y - 1);
                print_map(M);
                // v_op1(M, n, m, x - 1, y - 1);
                // print_vec(M);
                break;
            case 2:
                m_op2(M, n, m, x - 1, y - 1);
                print_map(M);
                // v_op2(M, n, m, x - 1, y - 1);
                // print_vec(M);
                break;
            case 3:
                m_op3(M, n, m, x - 1, y - 1);
                // v_op3(M, n, m, x - 1, y - 1);
                // print_vec(M);
                break;
            default:
                break;
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