class Solution {
public:
    int n;
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& temp) {
        ans.push_back(temp);

        for (int i = index; i < n; i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            solve(i + 1, nums, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, ans, temp);

        return ans;
    }
};
