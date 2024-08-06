class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        
        int n = nums.size();
        vector<long long int> ans(n);
       vector<long long int> left_product(n, 1);
       vector<long long int> right_product(n, 1);
       
       for(int i=1; i<n; i++){
           left_product[i] = left_product[i-1]*nums[i-1];
       }
       
       for(int i=n-2; i>= 0; i--){
           right_product[i] = right_product[i+1]*nums[i+1];
       }
       
       for(int i=0; i<n; i++){
           ans[i] = left_product[i]*right_product[i];
       }
       
       
       return ans;
    }
};
