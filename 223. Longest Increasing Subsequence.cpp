class Solution {
public:
    vector<vector<int>> dp;
    int solve(auto& nums, int curr, int prev) {

        if (curr == nums.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int exclude = solve(nums, curr + 1, prev);

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solve(nums, curr + 1, curr);
        }

        return dp[curr][prev + 1] = max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size() + 1, vector<int>(nums.size() + 1, -1));

        return solve(nums, 0, -1);
    }
};
