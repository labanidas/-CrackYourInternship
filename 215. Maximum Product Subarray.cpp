class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //  brute force --  generate all sub arrays
        int n = nums.size();
        int max_product = INT_MIN;
        int pref = 1, suffi = 1;

        for (int i = 0; i < n; i++) {

            if (pref == 0)
                pref = 1;
            if (suffi == 0)
                suffi = 1;

            pref *= nums[i];
            suffi *= nums[n - i - 1];
            max_product = max({max_product, pref, suffi});
        }

        return max_product;
    }
};
