class Solution {
  public:
    int n, m;
    vector<vector<int>> dp;
    
    // int solve(int i, int j, string s1, string s2){
        
    //     if(i>=n || j>= m) return 0;
        
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int len = 0;
        
    //     if(s1[i] == s2[j]){
    //         len = 1 + solve(i+1, j+1, s1, s2);
    //     }
        
    //     return dp[i][j]  = len;
    // }
  
    int longestCommonSubstr(string str1, string str2) {
        n = str1.size();
        m = str2.size();
        int max_len = INT_MIN;
        
        dp.resize(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    max_len = max(max_len, dp[i][j]);
                }
                max_len = max(max_len, solve(i, j, str1, str2));
            }
        }
        
        return max_len;
        
    }
};
