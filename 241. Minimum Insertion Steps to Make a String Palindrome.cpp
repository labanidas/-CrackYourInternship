class Solution {
public:
    vector<vector<int>> dp;

    int solve(string s, int i, int j) {
        if (i >= j)
            return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j])
            return solve(s, i + 1, j - 1);

        return dp[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    }

    int minInsertions(string s) {
        int n = s.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n - 1);
    }
};
