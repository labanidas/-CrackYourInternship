class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {

        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> ans;

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (!st.empty() && st.top().first <= curr)
                st.pop();

            if (st.empty())
                ans.push_back(0);
            else
                ans.push_back(st.top().second - i);

            st.push({curr, i});
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
