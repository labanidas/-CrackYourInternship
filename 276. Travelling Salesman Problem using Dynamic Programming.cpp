class Solution {
public:
    int n;
    int tsp(int mask, int pos, vector<vector<int>>& cost, vector<vector<int>>& dp){
        if(mask == (1<<n) - 1){
            return cost[pos][0];
        }         
        
        if(dp[mask][pos] != -1) return dp[mask][pos];
        
        int ans = INT_MAX;
        
        for(int city = 0; city<n; city++){
            if( (mask & (1 << city) ) == 0 ){
                int newAns = cost[pos][city] + tsp(mask | (1 << city), city, cost, dp);
                ans = min(ans, newAns);
            }
        }
         return dp[mask][pos] = ans;
        
    }
    int total_cost(vector<vector<int>>cost){
       n = cost.size();
       vector<vector<int>> dp(1 << n, vector<int>(n, -1));
       
       return tsp(1, 0, cost, dp);
    }
};

