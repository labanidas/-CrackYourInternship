class Solution {
public:
    int n;
    pair<int, int> getCoord(int s) {
        int row = n - 1 - (s - 1) / n;

        int col = (s - 1) % n;

        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0))
            col = n - 1 - col;

        return make_pair(row, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        vector<vector<int>> visited(n, vector<int>(n, false));

        visited[n - 1][0] = true;

        int steps = 0;
        q.push(1);

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int x = q.front();
                q.pop();

                if (x == n * n)
                    return steps;

                for (int i = 1; i <= 6; i++) {
                    if (x + i > n * n)
                        break;

                    pair<int, int> coord = getCoord(x + i);
                    int a = coord.first;
                    int b = coord.second;

                    if (visited[a][b])
                        continue;

                    visited[a][b] = true;
                    if (board[a][b] == -1)
                        q.push(x + i);
                    else
                        q.push(board[a][b]);
                }
            }
            steps++;
        }
        return -1;
    }
};
