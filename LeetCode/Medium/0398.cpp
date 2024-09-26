class Solution {
    unordered_map<int, vector<int>> hash_list;

  public:
    Solution(vector<int> &nums) {
        hash_list.clear();
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (hash_list.find(x) == hash_list.end()) {
                hash_list[x] = {i};
            } else {
                hash_list[x].push_back(i);
            }
        }
    }

    int pick(int target) {
        int size = hash_list[target].size();
        return hash_list[target][rand() % size];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */