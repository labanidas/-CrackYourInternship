class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int sum = 0;

        for (int i = 0; i < n; i++)
            dp[i][0] = mat[i][0];
        for (int i = 0; i < m; i++)
            dp[0][i] = mat[0][i];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += dp[i][j];
            }
        }

        return sum;
    }
};
