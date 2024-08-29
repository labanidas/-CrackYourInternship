class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;

        for (int i = 1; i < n; i++) {
            int two_multiple = 2 * dp[p1];
            int three_multiple = 3 * dp[p2];
            int five_multiple = 5 * dp[p3];

            dp[i] = min({two_multiple, three_multiple, five_multiple});

            if (dp[i] == two_multiple)
                p1++;
            if (dp[i] == three_multiple)
                p2++;
            if (dp[i] == five_multiple)
                p3++;
        }

        return dp[n - 1];
    }
};
