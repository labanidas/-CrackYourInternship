class Solution {
public:
    int n;
    vector<bool> used;
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1])
                continue;

            used[i] = true;
            temp.push_back(nums[i]);

            solve(nums);

            used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        used.resize(n, false);

        solve(nums);
        return ans;
    }
};
