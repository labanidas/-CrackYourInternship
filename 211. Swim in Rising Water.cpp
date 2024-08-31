class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,-1}, {0,1}};

    bool isSafe(int x, int y, int n, auto& visited) {
        if (x >= n || y >= n || x < 0 || y < 0)
            return false;
        if (visited[x][y])
            return false;
        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, false));
        priority_queue < pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, greater<>> pq; //  min heap
            
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [t, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            if (x == n - 1 && y == n - 1) {
                return t;
            }

            for (auto dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (isSafe(nx, ny, n, visited)) {
                    visited[nx][ny] = true;
                    pq.push({max(t, grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return -1;
    }
};
