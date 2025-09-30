
/**
 * @file 3027.cpp
 * @author
 * @brief https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-ii/
 * @version 0.1
 * @date
 *
 * @copyright Copyright (c) 2025
 *
 **/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {

    struct Point {
        int x;
        int y;

        friend auto &operator<<(std::ostream &os, Point const &p) {
            os << "(" << p.x << ", " << p.y << ")";
            return os;
        }
    };

  public:
    int numberOfPairs(std::vector<std::vector<int>> &points) {
        int                n = points.size();
        std::vector<Point> P{};
        P.reserve(n);
        for (auto const &p: points) {
            P.emplace_back(p[0], p[1]);
        }

        std::sort(P.begin(), P.end(), [](auto &A, auto &B) {
            return A.x < B.x || (A.x == B.x && A.y > B.y);
        });

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            auto &A     = P[i];
            int   x_min = A.x - 1;
            int   x_max = std::numeric_limits<int>::max();
            int   y_min = std::numeric_limits<int>::min();
            int   y_max = A.y + 1;

            for (int j = i + 1; j < n; ++j) {
                auto &B = P[j];
                if (B.x > x_min && B.x < x_max && B.y > y_min && B.y < y_max) {
                    ans++;
                    x_min = B.x;
                    y_min = B.y;
                }
            }
        }
        return ans;
    }
};