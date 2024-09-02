class Solution
{
    public:
    
    vector<int> dp;
    
    int solve(int n, int x, int y, int z){
        
        if(n<0) return INT_MIN;
        
        if( n==0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int x_segment = 1 + solve(n-x, x, y, z);
        int y_segment = 1 + solve(n-y, x, y, z);
        int z_segment = 1 + solve(n-z, x, y, z);
        
        return dp[n] = max({x_segment, y_segment, z_segment});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {   
        dp.resize(n+1, -1);
        int result = solve(n, x, y, z);
        return result < 0 ? 0 : result;
    }
};
