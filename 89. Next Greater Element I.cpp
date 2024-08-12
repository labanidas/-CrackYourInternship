class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (!st.empty())
                mp[curr] = st.top();
            else
                mp[curr] = -1;

            st.push(curr);
        }

        vector<int> ans;
        for (auto num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
