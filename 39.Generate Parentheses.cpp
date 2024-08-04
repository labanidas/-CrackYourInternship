class Solution {
public:
    vector<string> result;
    int N;
    void func(int open , int close, string str) {
        if (str.length() == N * 2) {
            result.push_back(str);
            return;
        }

        if (open < N)
            func(open + 1, close, str+'(');
        if (close < open)
            func(open, close + 1, str+')');
    }

    vector<string> generateParenthesis(int n) {

        N = n;
        func(0, 0, "");
        return result;
    }
};
