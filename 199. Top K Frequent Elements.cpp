class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto i : nums) {
            mp[i]++;
        }

        priority_queue<pair<int, int>> pq; // max heap

        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }

        vector<int> ans;

        while (k--) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }

        return ans;
    }
};
