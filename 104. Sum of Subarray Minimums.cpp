class Solution {
public:
    int n;
    vector<int> getLeftMin(vector<int>& arr) {

        vector<int> vect(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] > curr)
                st.pop();

            if (!st.empty())
                vect[i] = st.top();

            st.push(i);
        }
        return vect;
    }
    vector<int> getRightMin(vector<int>& arr) {
        vector<int> vect(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] >= curr)
                st.pop();

            if (!st.empty())
                vect[i] = st.top();

            st.push(i);
        }
        return vect;
    }

    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();

        vector<int> leftMin = getLeftMin(arr);
        vector<int> rightMin = getRightMin(arr);

        int ans = 0;
        int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int right = rightMin[i] - i;
            int left = i - leftMin[i];
            ans = (ans + (long long)arr[i] * right * left) % MOD;
        }

        return ans;
    }
};
