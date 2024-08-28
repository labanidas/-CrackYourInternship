class Solution {
public:
    int findPivot(auto& nums, int l, int r) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }

    int binarySearch(auto& nums, int l, int h, int target) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums, 0, n - 1);

        if (nums[pivot] == target)
            return pivot;

        int idx = -1;

        idx = binarySearch(nums, pivot + 1, n - 1, target);

        if (idx != -1)
            return idx;

        idx = binarySearch(nums, 0, pivot - 1, target);

        return idx;
    }
};
