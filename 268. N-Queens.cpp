class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board) {
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size();
             i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solvequeen(int row, vector<string>& board,
                    vector<vector<string>>& res) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                solvequeen(row + 1, board, res);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solvequeen(0, board, res);
        return res;
    }
};
