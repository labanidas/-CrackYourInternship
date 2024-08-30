class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;

        int rem = nums.size()-k;

        for(auto num: nums){
            while(ans.size() && rem && num <  ans.back()){
                ans.pop_back();
                rem--;
            }

            ans.push_back(num);
        }

        while(rem--){
            ans.pop_back();
        }

        return ans;
    }
};
