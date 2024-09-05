class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int idx, int buy, int k, auto& p) {
        if (idx >= n || k <= 0)
            return 0;

        if (dp[idx][k][buy] != -1)
            return dp[idx][k][buy];

        if (buy) {
            return dp[idx][k][buy] = max(-p[idx] + solve(idx + 1, 0, k, p),
                                         solve(idx + 1, 1, k, p));
        }

        return dp[idx][k][buy] = max(p[idx] + solve(idx + 1, 1, k - 1, p),
                                     solve(idx + 1, 0, k, p));
    }
    int maxProfit(int k, vector<int>& p) {
        n = p.size();

        dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        return solve(0, 1, k, p);
    }
};
