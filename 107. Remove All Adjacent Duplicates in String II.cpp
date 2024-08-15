class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first, p.second + 1});

                if (st.top().second == k)
                    st.pop();
            } else {
                st.push({c, 1});
            }
        }

        string ans;
        while (!st.empty()) {
            char c = st.top().first;
            int freq = st.top().second;
            st.pop();
            while (freq--) {
                ans += c;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
