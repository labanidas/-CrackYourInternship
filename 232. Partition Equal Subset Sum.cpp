class Solution{
public:
    vector<vector<int>> dp;
    
    bool solve(int n, int arr[], int sum, int i){
        if(sum < 0 || i>= n) return false;
        
        if(sum==0) return true;
        
        if(dp[i][sum] != -1) return dp[i][sum] == 2;
        
        bool take = solve(n, arr, sum - arr[i], i+1);
        
        bool not_take = solve(n, arr, sum, i+1);
        
        dp[i][sum] = (take || not_take) ? 2: 1;
        
        return dp[i][sum] == 2; // 1 = false, 2 = true
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        
        if( sum%2 != 0) return false;
        
        sum = sum/2;
        
        dp.resize(N, vector<int>(sum+1, -1));
        
        return solve(N, arr, sum, 0) ? 1: 0;
        
    }
};
