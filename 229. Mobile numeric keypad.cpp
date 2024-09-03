class Solution {
  public:
  vector<vector<long long >> dp;
    vector<vector<int>> adj = {
        {0, 8},       // 0
        {1, 2, 4},    // 1
        {2, 1, 3, 5}, // 2
        {3, 2, 6},    // 3
        {4, 1, 5, 7}, // 4
        {5, 2, 4, 6, 8}, // 5
        {6, 3, 5, 9}, // 6
        {7, 4, 8},    // 7
        {8, 5, 7, 9, 0}, // 8
        {9, 6, 8}     // 9
    };

    long long solve(int n, int i) {
        if (n == 1) return 1;

        if (dp[n][i] != -1) return dp[n][i];

        long long count = 0;

        for (auto neighbor : adj[i]) {
            count += solve(n - 1, neighbor);
        }

        return dp[n][i] = count;
    }

    long long getCount(int n) {
        long long ans = 0;

        dp.resize(n + 1, vector<long long>(10, -1));

        for (int i = 0; i <= 9; i++) {
            ans += solve(n, i);
        }

        return ans;
    }
};
