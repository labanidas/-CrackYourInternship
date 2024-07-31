class Solution {
public:
    vector<int> prevsmaller(int n, auto nums) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top()!=-1 && nums[st.top()] >= nums[i]) {
                st.pop();
            }            
                ans[i] = st.top();
                st.push(i);            
        }
        return ans;
    }
    vector<int> nextsmaller(int n, auto nums) {
        stack<int> st;
        st.push(n);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            while (!st.empty() && st.top()!=n && nums[st.top()] >= nums[i]) {
                st.pop();
            } 
             ans[i] = st.top();
            st.push(i);   

        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = INT_MIN;
        vector<int> prevs = prevsmaller(n, heights);
        vector<int> nexts = nextsmaller(n, heights);

        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = nexts[i] - prevs[i] - 1;

            int curr_area = height * width;
            max_area = max(max_area, curr_area);
        }

        return max_area;
    }
};
