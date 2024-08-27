class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool isSafe(int x, int y) { return x < n && y < m && x >= 0 && y >= 0; }

    int dfs(int i, int j, int id, auto& grid) {
        int size = 1;
        grid[i][j] = id;

        for (auto dir : directions) {
            int x = i + dir[0], y = j + dir[1];
            if (isSafe(x, y) && grid[x][y] == 1)
                size += dfs(x, y, id, grid);
        }

        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        unordered_map<int, int> islandSize;
        int id = 2; // to not get confused with 1 or 0
        int max_size = 0;

        //  get size of each island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, id, grid);
                    islandSize[id] = size;
                    max_size = max(max_size, size); // foe cases when all cells are 1
                    id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> currIslandSizes;
                    int potential_size = 1;

                    for (auto dir : directions) {
                        int x = i + dir[0], y = j + dir[1];
                        if (isSafe(x, y) && grid[x][y] > 1)
                            currIslandSizes.insert(grid[x][y]);
                    }

                    for (auto& id : currIslandSizes) {
                        potential_size += islandSize[id];
                    }
                    max_size = max(max_size, potential_size);
                }
            }
        }

        return max_size;
    }
};
