class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int i, auto& nums) {
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i + 1, nums);
        temp.pop_back();
        solve(i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};
