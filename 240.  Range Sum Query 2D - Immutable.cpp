class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        prefix.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += mat[i][j];
                mat[i][j] = sum;
            }
        }

        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += mat[j][i];
                mat[j][i] = sum;
            }
        }

        prefix = mat;
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        int totsum = prefix[r2][c2];

        int leftsum = (c1 > 0) ? prefix[r2][c1 - 1] : 0;
        int topsum = (r1 > 0) ? prefix[r1 - 1][c2] : 0;
        int cornersum = (r1 > 0 && c1 > 0) ? prefix[r1 - 1][c1 - 1] : 0;

        int extrasum = leftsum + topsum - cornersum;

        return totsum - extrasum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
