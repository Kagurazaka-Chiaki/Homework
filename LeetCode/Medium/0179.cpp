#include <algorithm>
#include <string>
#include <vector>

/**
 * @brief 179. 最大数
 * https://leetcode-cn.com/problems/largest-number/
**/

class Solution {
  public:
    std::string largestNumber(std::vector<int> &nums) {
        std::vector<std::string> v{};
        v.reserve(nums.size());
        std::for_each(nums.begin(), nums.end(), [&v](int x) {
            v.emplace_back(std::to_string(x));
        });
        std::sort(v.begin(), v.end(), [](std::string a, std::string b) {
            return a + b > b + a;
        });
        if (!v.empty() && v.front() == "0") {
            return "0";
        }
        std::size_t total = 0;
        std::for_each(v.begin(), v.end(), [&total](std::string const &s) {
            total += s.size();
        });
        std::string res;
        res.reserve(total);
        std::for_each(v.begin(), v.end(), [&res](std::string const &s) {
            res += s;
        });
        return res;
    }
};