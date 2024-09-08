class Solution {
public:
    int n;
    void solve(int index, vector<int>& nums, int target,
               vector<vector<int>>& ans, vector<int>& temp) {
                
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < n; i++) {
            if (i > index && nums[i] == nums[i-1])
                continue;

            if(target - nums[i] < 0) break;

            temp.push_back(nums[i]);
            solve(i+1, nums, target - nums[i], ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, ans, temp);

        return ans;
    }
};
