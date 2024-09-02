class Solution {
public:
    vector<vector<int>> dp;
    int n, m;

    int solve(int i, int j, auto& grid) {

        if (i < 0 || j < 0 || i >= n || j >= m)
            return INT_MAX;

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = solve(i + 1, j, grid);
        int right = solve(i, j + 1, grid);

        return dp[i][j] = grid[i][j] + min({down, right});
    }

    int minPathSum(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        dp.resize(n, vector<int>(m, -1));

        return solve(0, 0, grid);
    }
};
