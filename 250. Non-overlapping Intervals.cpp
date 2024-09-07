class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {

        int n = nums.size();
        int prev = 0;
        int ans = 0;

        sort(nums.begin(), nums.end());
        
        for (int curr = 1; curr < n; curr++) {
            if (nums[curr][0] < nums[prev][1]) {
                ans++;
                if (nums[curr][1] <= nums[prev][1]) {
                    prev = curr;
                }
            } else {
                prev = curr;
            }
        }

        return ans;
    }
};
