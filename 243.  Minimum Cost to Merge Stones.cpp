;
class Solution {
public:
    int n;
    int mergeStones(vector<int>& stones, int k) {
        n = stones.size();
        if ((n - 1) % (k - 1) != 0)
            return -1;

        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int length = k; length <= n; length++) {
            for (int i = 0; i + length <= n; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;

                for (int mid = i; mid < j; mid += (k - 1)) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }

                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }
        return dp[0][n - 1];
    }
};
