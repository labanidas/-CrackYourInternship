class Solution {
public:
    int n;
    void twoSum(int i, int j, auto& ans, long long  target, auto& nums) {
        int left = j + 1, right = n - 1;
        while (left < right) {
            long long sum = nums[left] + nums[right];
            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else if (sum == target) {
                ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();

        if (n < 4)
            return {};

        vector<vector<int>> ans;

        // brute force --- using FOUR for loops O(n^4)
        // optimal -- sort the array

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-3; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n-2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                twoSum(i, j, ans, target - (long long)(nums[i] + nums[j]), nums);
            }
        }

        return ans;
    }
};



