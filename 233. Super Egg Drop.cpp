class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int floor = 1; floor <= n; floor++)
            dp[1][floor] = floor;

        for (int eggs = 2; eggs <= k; eggs++) {
            for (int floor = 1; floor <= n; floor++) {
                int low = 1, high = floor, min_moves = floor;

                while (low <= high) {
                    int mid = (low + high) / 2;

                    int breaks = dp[eggs - 1][mid - 1];
                    int not_breaks = dp[eggs][floor - mid];

                    int worse_case = max(breaks, not_breaks);

                    min_moves = min(min_moves, worse_case + 1);

                    if (breaks > not_breaks) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }

                    dp[eggs][floor] = min_moves;
                }
            }
        }

        return dp[k][n];
    }
};
