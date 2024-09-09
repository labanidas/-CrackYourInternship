
class Solution {
public:
    int n, m;
    int empty_cells = 0;
    int result = 0;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    void solve(int i, int j, int count, auto& grid) {
        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == -1) {
            return;
        }

        if (grid[i][j] == 2) {
            if (count == empty_cells) {
                result++;
            }
            return;
        }

        grid[i][j] = -1;

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            solve(ni, nj, count + 1, grid);
        }

        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int x, y;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }

                if (grid[i][j] == 0) {
                    empty_cells++;
                }
            }
        }
        empty_cells += 1; // start point

        solve(x, y, 0, grid);
        
        return result;
    }
};
