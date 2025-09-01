#include <vector>
#include <deque>



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型vector
     * @param size int整型
     * @return int整型vector
     */
    std::vector<int> maxInWindows(std::vector<int>& num, int size) {
        int n = num.size();
        auto res = std::vector<int>(0, 0);
        if (size > n || size <= 0) { return res; }
        auto dq = std::deque<int>();
        for (int i = 0; i < size; ++i) {
            while(!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = size; i < num.size(); ++i) {
            res.push_back(num[dq.front()]);
            while (!dq.empty() && dq.front() < (i - size + 1)) {
                dq.pop_front();
            }
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(num[dq.front()]);
        return res;
    }
};