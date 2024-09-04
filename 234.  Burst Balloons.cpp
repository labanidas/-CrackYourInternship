class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        // Pad nums with 1 at both ends
        vector<int> padded_nums(n+2, 1);
        for(int i=0; i<n; i++){
            padded_nums[i+1] = nums[i];
        }

        for(int length = 1; length <= n; length++){
            for(int left = 1; left<= n - length+1; left++){
                int right = left+length-1;
                for(int i=left; i<=right; i++){
                    dp[left][right] = max(dp[left][right],
                        dp[left][i-1] + padded_nums[left-1] *padded_nums[i]*padded_nums[right+1] + dp[i+1][right]);
                    
                }
            }
        }

        return dp[1][n];
    }
};
