class Solution {
public:
    int dp[1001][2001];
    int func(int i, int rem, vector<int>& arr, int &k){
        
        if(i==arr.size()) return 0;
        
        if(dp[i][rem]!=-1) return dp[i][rem] ;
        
        int ans ;
        
        if(arr[i]>rem){
            ans = (rem+1)* (rem+1) + func(i+1, k-arr[i]-1, arr, k);
        }else{
            int c1 = (rem+1)* (rem+1) + func(i+1, k-arr[i]-1, arr, k);
            int c2 = func(i+1, rem-arr[i]-1, arr, k);
            ans = min(c1, c2);
        }
        return dp[i][rem] =  ans;
    }
    int solveWordWrap(vector<int> &arr, int k) {
        memset(dp, -1, sizeof(dp));
        return func(0, k, arr, k);
   }
};
