/**
 *
**/


#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
  public:
    bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target) {
        return true;
    }
};

bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target) {

    if (matrix.empty()) { return false; }

    bool found = false;

    int row = 0;
    int column = matrix[0].size() - 1;

    std::cout << row << " | " << column << std::endl;

    while (row < matrix.size() && column >= 0) {
        if (matrix[row][column] == target) {
            found = true;
            break;
        } else if (matrix[row][column] > target) {
            column--;
        } else {
            row--;
        }
    }

    return found;
}

std::vector<std::vector<int>> build_2d_vector() {
    std::vector<std::vector<int>> matrix;

    std::vector<int> data_1 = {1, 2, 8, 9};
    std::vector<int> data_2 = {2, 4, 9, 12};
    std::vector<int> data_3 = {4, 7, 10, 13};
    std::vector<int> data_4 = {6, 8, 11, 15};

    matrix.push_back(data_1);
    matrix.push_back(data_2);
    matrix.push_back(data_3);
    matrix.push_back(data_4);

    return matrix;
}

std::vector<std::vector<int>> build_2d_vector(int row, int column) {
    std::vector<std::vector<int>> matrix(row, std::vector<int>(column));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void print_2d_vector(std::vector<std::vector<int>> matrix) {
    // int a = matrix.size();
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("[%02d]", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {
    /* code */
    (void) argc;
    (void) argv;

    auto matrix = build_2d_vector();

    print_2d_vector(matrix);

    auto result = findNumberIn2DArray(matrix, 7);

    std::cout << "Hello 04 : " << result << std::endl;

    return 0;
}