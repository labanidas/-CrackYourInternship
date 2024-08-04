class Solution {
public:
    string s, t;
    int dp[1001][1001];

    int func(int i, int j) {
        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if (s[i] == t[j]) {
            ans += func(i + 1, j + 1);
        }
        ans += func(i + 1, j);

        return dp[i][j] = ans;
    }

    int numDistinct(string S, string T) {
        memset(dp, -1, sizeof(dp));
        s = S;
        t = T;
        return func(0, 0);
    }
};
