class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int max_sum) {
        int subarray_count = 1;
        int curr_sum = 0;

        for (auto num : nums) {
            if (curr_sum + num > max_sum) {
                subarray_count++;
                curr_sum = num;
                if (subarray_count > k)
                    return false;
            } else {
                curr_sum += num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int low = INT_MIN, high = 0;
        int mid;

        for (auto num : nums) {
            if (num > low)
                low = num;
            high += num;
        }
        
        while (low < high) {
            mid = (low + high) / 2;

            if (canSplit(nums, k, mid)) {
                high = mid;
            } else
                low = mid + 1;
        }
        return low;
    }
};
