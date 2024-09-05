class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());

        vector<int> points(max_num + 1, 0);
        vector<int> dp(max_num + 1, 0);

        for (auto num : nums) {
            points[num] += num; //  points I can earn
        }

        dp[0] = points[0];
        dp[1] = points[1];

        for (int i = 2; i <= max_num; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
        }

        return dp[max_num];
    }
};
