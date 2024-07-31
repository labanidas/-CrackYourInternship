class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row0(m, 1);
        vector<int> col0(n, 1);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    row0[i] = 0;
                    col0[j] = 0;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row0[i] == 0 || col0[j] == 0){
                   mat[i][j]  = 0;
                }
            }
        }
    }
};
