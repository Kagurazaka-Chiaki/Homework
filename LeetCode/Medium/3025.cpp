#include <vector>

class Solution {

    struct Point {
        int x;
        int y;

        Point(std::vector<int> const &vec)
            : x(vec[0]), y(vec[1]) {}
    };

    struct Rect {
        Point lt;
        Point rb;
    };

    bool A_is_lt_B(Point const &a, Point const &b) {
        return (a.x <= b.x) and (a.y >= b.y);
    }

    bool contain(Rect const &r, Point const &p) {
        bool t1 = p.x >= r.lt.x && p.x <= r.rb.x;
        bool t2 = p.y >= r.rb.y && p.y <= r.lt.y;
        return t1 && t2;
    }

  public:
    int numberOfPairs(std::vector<std::vector<int>> &points) {
        int ans = 0;
        int n   = points.size();
        for (int i = 0; i < n; ++i) {
            Point p1(points[i]);
            for (int j = 0; j < n; ++j) {
                Point p2(points[j]);
                if (i == j) { continue; }
                if (!A_is_lt_B(p1, p2)) { continue; }
                if (n == 2) {
                    ans++;
                    continue;
                }
                Rect r(p1, p2);
                bool flag = false;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) { continue; }
                    Point p3(points[k]);
                    if (contain(r, p3)) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) { ans++; }
            }
        }
        return ans;
    }
};
