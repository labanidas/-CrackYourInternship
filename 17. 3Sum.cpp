class Solution {
public:
    int n;
    void twoSum(int i, int target, auto nums, auto& ans) {
        int left = i, right = n - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else if (sum == target) {
                ans.push_back({nums[i - 1], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();

        if (n < 3)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            twoSum(i + 1, -nums[i], nums, ans);
        }

        return ans;
    }
};
