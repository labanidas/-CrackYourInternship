class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_num = prices[0];
        int profit = 0;

        for(int i=0; i<n; i++){
            if(prices[i] < min_num){
                min_num = prices[i];
            }else{
                profit = max(profit, prices[i] - min_num);
            }
        }

        return profit;
    }
};
