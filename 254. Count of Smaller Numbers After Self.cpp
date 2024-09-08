    void mergeCountSmaller(vector<int>& indices, int left, int right, vector<int>& counts, vector<int>& nums) {
        if (right - left <= 1) return;

        int mid = (left + right) / 2;
        mergeCountSmaller(indices, left, mid, counts, nums);
        mergeCountSmaller(indices, mid, right, counts, nums);

        vector<int> temp(right - left);
        int i = left, j = mid, k = 0, rightCount = 0;

        while (i < mid && j < right) {
            if (nums[indices[j]] < nums[indices[i]]) {
                temp[k++] = indices[j++];
                rightCount++;
            } else {
                counts[indices[i]] += rightCount;
                temp[k++] = indices[i++];
            }
        }

        while (i < mid) {
            counts[indices[i]] += rightCount;
            temp[k++] = indices[i++];
        }

        while (j < right) {
            temp[k++] = indices[j++];
        }

        for (int i = left; i < right; i++) {
            indices[i] = temp[i - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> indices(n, 0);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        mergeCountSmaller(indices, 0, n, counts, nums);

        return counts;
    }
};
