class Solution {
public:
    int n;
    vector<int> dp;
    int solve(string s, int idx) {
        if (idx == n)
            return 1;

        if (s[idx] == '0')
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ways = solve(s, idx + 1);

        if (idx + 1 < n &&
            (s[idx] == '1' || s[idx] == '2' && s[idx + 1] <= '6'))
            ways += solve(s, idx + 2);

        return dp[idx] = ways;
    }

    int numDecodings(string s) {
        n = s.size();
        dp.resize(n, -1);
        return solve(s, 0);
    }
};
