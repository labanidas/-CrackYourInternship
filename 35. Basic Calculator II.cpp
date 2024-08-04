class Solution {
public:
    int calculate(string s) {

        long long num = 0;
        stack<int> st;
        char op = '+';

        auto isDigit = [](char& c) { return c >= '0' && c <= '9'; };

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isDigit(c))
                num = num * 10 + (c - '0');

            if (!isDigit(c) && c != ' ' || i == s.length() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                op = c;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
