class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> List;
        if (nums.size() == 0) {
            return List;
        } 
        else if (nums.size() == 1) {
            if (nums[0] + nums[0] == target) {
                List.push_back(0);
                List.push_back(0);
            }
            return List;
        }
        else {
            int value = 0;
            for (int i = 0; i < nums.size(); i++) {
                value = target - nums[i];
                for (int j = i + 1; j < nums.size(); j++) {
                    if (value == nums[j]) {
                        List.push_back(i);
                        List.push_back(j);
                    }
                }
            }
            return List;
        }
        

    }
};