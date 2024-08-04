class Solution {
public:
    void permut(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[index]) continue; // Skip duplicates
            swap(nums[index], nums[i]);
            permut(index + 1, nums, ans);
            swap(nums[index], nums[i]); // backtrack
        }
    }

    vector<vector<int>> uniquePerms(vector<int>& arr, int n) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        permut(0, arr, ans);
        return ans;
    }
};
