class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // ------------   brute force
        // for (int i = 0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n;j++){
        //         int sum = accumulate(nums.begin()+i, nums.begin()+j+1, 0);
        //         if(sum == k) count++;
        //     }
        // }

        unordered_map<int, int> mp;
        // vector<int> cumulativeSum(n, 0);
        // cumulativeSum[0] = nums[0];
        int cumulativeSum = 0;
        mp[0] = 1;

        // cumulative sum
        // for(int i=1; i<n; i++){
        //     cumulativeSum[i] = cumulativeSum[i-1]  + nums[i];
        // }

        for (int i = 0; i < n; i++) {
            cumulativeSum += nums[i];

            if (mp.find(cumulativeSum - k) != mp.end())
                count += mp[cumulativeSum - k];

            mp[cumulativeSum]++;
        }
        return count;
    }
};
