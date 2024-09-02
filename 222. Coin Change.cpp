
class Solution {
public:
    vector<int> dp;
    int solve(auto& coins, int amount) {
        if (amount < 0)
            return INT_MAX;

        if (amount == 0)
            return 0;

        if (dp[amount] != -1)
            return dp[amount];

        int min_result = INT_MAX;

        for (auto& coin : coins) {
            // result  = 1 + min (result, solve(coins, amount-coin)); //Adding 1
            // to INT_MAX exceeds the maximum value that an int can hold,
            // causing an overflow.
            int result = solve(coins, amount - coin);

            if (result != INT_MAX) {
                min_result = min(min_result, result + 1);
            }
        }

        return dp[amount] = min_result;
    }
    int coinChange(vector<int>& coins, int amount) {

        dp.resize(amount + 1, -1);

        int result = solve(coins, amount);
        
        return result == INT_MAX ? -1 : result;
    }
};
