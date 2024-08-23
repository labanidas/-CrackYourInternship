class Solution {
  public:
  
  int n;
  
  void solve(vector<vector<int>> &mat, int i, int j, string &temp, vector<string>& ans){
      if(i>=n || i<0 || j>= n || j<0 || mat[i][j] == 0)
        return;
        
        if(i == n -1 && j == n-1){
            ans.push_back(temp);
            return;
        }
        
        mat[i][j] = 0;
        
        temp.push_back('U');
        solve(mat, i-1, j, temp, ans);
        temp.pop_back();
        
        temp.push_back('R');
         solve(mat, i, j+1, temp, ans);
        temp.pop_back();
        
        temp.push_back('L');
        solve(mat, i, j-1, temp, ans);
        temp.pop_back();
        
        temp.push_back('D');
        solve(mat, i+1, j, temp, ans);
        temp.pop_back();
        
         mat[i][j] = 1;
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        string temp = "";
        n = mat.size();
        
        solve(mat, 0, 0, temp, ans);
        
        return ans;
    }
};
