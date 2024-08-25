class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        if(x>=n || y>=n || x<0 || y<0) return false;
        if(grid[x][y]) return false;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        // if q is empty of contains only land or water
        if (q.empty() || q.size() == n * n)
            return -1;

        while (!q.empty()) {
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            for(auto d: dir){
                int nx = x+d.first;
                int ny = y+d.second;

                if(isValid(nx, ny, grid)){
                    grid[nx][ny] = grid[x][y] + 1;
                    ans = grid[nx][ny] -1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};
