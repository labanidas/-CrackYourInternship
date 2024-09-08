class Solution {
public:
    
    int countWithMergeSort(vector<long> &sums, int left, int right, int lower, int upper)
    {
        if (right - left <= 1) return 0;
        
        int mid = (left + right) / 2;
        int count = countWithMergeSort(sums, left, mid, lower, upper) +
                    countWithMergeSort(sums, mid, right, lower, upper);
        
        int j = mid, k = mid, t = mid;
        vector<long> cache(right - left);
        int r = 0;
        
        for (int i = left; i < mid; ++i) {
            while (k < right && sums[k] - sums[i] < lower) ++k;
            while (j < right && sums[j] - sums[i] <= upper) ++j;
            count += j - k;
            
            // Merge step
            while (t < right && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r++] = sums[i];
        }
        
        copy(cache.begin(), cache.begin() + r, sums.begin() + left);
        return count;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefixSum(n + 1, 0);  
        
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return countWithMergeSort(prefixSum, 0, n + 1, lower, upper);
    }
};
