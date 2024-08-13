class Solution {
public:
int mctFromLeafValues(vector<int>& arr) {
    stack<int> st;
    int ans=0;

    for(auto num: arr){

        while(!st.empty() && st.top() <= num){
            int top = st.top();
            st.pop();
            if(!st.empty())
                ans += top * min(st.top(), num);
            else ans += top*num;
        }

        st.push(num);
    }

    while(st.size() > 1){
        int temp = st.top();
        st.pop();
        ans += temp * st.top();
    }

    return ans;
}
};
