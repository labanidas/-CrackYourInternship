class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;

        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int n1 = st.top(); st.pop();
                int n2 = st.top(); st.pop();

                if (token == "+") {
                    st.push(n2 + n1);
                } else if (token == "-") {
                    st.push(n2 - n1);
                } else if (token == "*") {
                    st.push(n2 * n1);
                } else if (token == "/") {
                    st.push(n2 / n1);
                }
            } else {  
                st.push(stoi(token)); 
            }
        }
        
        return st.top();
    }
};
