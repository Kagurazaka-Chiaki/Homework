class Solution {
    // unordered_map<int, int> count_map;
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> hash;

        int ans = 0;

        for (int i: nums1) {
            for (int j: nums2) {
                ++hash[-(i + j)];
            }
        }

        for (int i: nums3) {
            for (int j: nums4) {
                ans += hash[(i + j)];
            }
        }

        return ans;
    }
};