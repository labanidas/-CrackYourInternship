class Solution {
public:
    int M = 1e9 + 7;
    int N;
    vector<vector<int>> dp;
    vector<vector<int>> adj = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {3, 9, 0},
                               {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

    int solve(int n, int curr_node) {

        if (n == 0)
            return 1;

        if (dp[n][curr_node] != -1)
            return dp[n][curr_node];

        int ans = 0;

        for (auto& next_node : adj[curr_node]) {
            ans = (ans + solve(n - 1, next_node)) % M;
        }

        return dp[n][curr_node] = ans;
    }
    int knightDialer(int n) {
        // N = n;
        dp.resize(n, vector<int>(10, -1));

        int result = 0;

        for (int i = 0; i <= 9; i++) {
            result = (result + solve(n - 1, i)) % M;
        }

        return result;
    }
};
