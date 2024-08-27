class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int dfs(int i, int j, auto& mat) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int len = 1;

        for (auto& dir : directions) {
            int x = i + dir[0], y = j + dir[1];

            if ((x < n && y < m && x >= 0 && y >= 0) && mat[i][j] < mat[x][y])
                len = max(len, 1 + dfs(x, y, mat));
        }

        return dp[i][j] = len;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {

        n = mat.size();
        m = mat[0].size();

        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int max_len = 1;
        //  applying dfs for each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                max_len = max(max_len, dfs(i, j, mat));
            }
        }

        return max_len;
    }
};
