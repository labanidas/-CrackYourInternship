class Solution {
public:
    bool isValid(int x, int y, int n, vector<vector<bool>>& visited) {
        if (x < 0 || x >= n || y < 0 || y >= n)
            return false;
        if (visited[x][y])
            return false;
        return true;
    }

    void DFS(int x, int y, int n, queue<pair<int, int>>& q,
             vector<vector<bool>>& visited, vector<vector<int>>& grid) {

        if (!isValid(x, y, n, visited) || grid[x][y] == 0)
            return;

        visited[x][y] = true;
        q.push({x, y});

        DFS(x + 1, y, n, q, visited, grid);
        DFS(x - 1, y, n, q, visited, grid);
        DFS(x, y + 1, n, q, visited, grid);
        DFS(x, y - 1, n, q, visited, grid);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int xs[] = {0, 1, 0, -1};
        int ys[] = {1, 0, -1, 0};
        int level = 0;
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    found = true;
                    DFS(i, j, n, q, visited, grid);
                    break;
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;

                for (int i = 0; i < 4; i++) {
                    int nx = x + xs[i];
                    int ny = y + ys[i];

                    if (isValid(nx, ny, n, visited)) {
                        if (grid[nx][ny] == 1)
                            return level;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
