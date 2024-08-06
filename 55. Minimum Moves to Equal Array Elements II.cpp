class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // two pointer
        // [1,2,9,11]
        // 1 + x = 11 - y = n
        // x+y = n = 10

        int n = nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());

        int left = 0, right = n-1;
        
        while(left < right){
            ans += nums[right] - nums[left];
            left++;
            right--;
        }

        return ans;
    }
};
