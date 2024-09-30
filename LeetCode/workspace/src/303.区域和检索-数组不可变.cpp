/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode.cn/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (78.75%)
 * Likes:    645
 * Dislikes: 0
 * Total Accepted:    282.2K
 * Total Submissions: 358.3K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，处理以下类型的多个查询:
 * 
 * 
 * 计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
 * 
 * 
 * 实现 NumArray 类：
 * 
 * 
 * NumArray(int[] nums) 使用数组 nums 初始化对象
 * int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，包含 left 和
 * right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * 输出：
 * [null, 1, -1, -3]
 * 
 * 解释：
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
 * numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
 * numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 0 <= i <= j < nums.length
 * 最多调用 10^4 次 sumRange 方法
 * 
 * 
 */

 #include <vector>

// @lc code=start
class NumArray {

    std::vector<int> tree = {};

    // 线段树
    void build_tree(int s, int t, int p, std::vector<int> const& in_data) {
        if (s == t) {
            this->tree[p] = in_data[s];
            return;
        }
        int m = (s + t) / 2;
        build_tree(s, m, 2 * p, in_data);
        build_tree(m + 1, t, 2 * p + 1, in_data);
        this->tree[p] = this->tree[2 * p] + this->tree[2 * p + 1];
    }

    int get_sum(int s, int t, int p, int l, int r) {
        if (l <= s && r >= t) {
            return this->tree[p];
        }
        int m = s + ((t - s) >> 1);
        int res = 0;
        if (l <= m) {
            res += get_sum(s, m, 2 * p, l, r);
        }
        if (r > m) {
            res += get_sum(m + 1, t, 2 * p + 1, l, r);
        }
        return res;
    }

    int len = 0;

    // TODO: 前缀和

public:
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        this->len = n;
        tree = std::vector<int>(4 * n, 0);
        build_tree(0, n - 1, 1, nums);
    }

    int sumRange(int left, int right) {
        return get_sum(0, this->len - 1, 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

