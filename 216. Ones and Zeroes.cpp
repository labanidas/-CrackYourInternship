class Solution {
public:
    int size;
    vector<vector<vector<int>>> dp;

    int solve(auto& counts, int m, int n, int index) {

        if (index >= size)
            return 0;

        int zero_count = counts[index].first;
        int one_count = counts[index].second;

        if (dp[index][m][n] != -1)
            return dp[index][m][n];

        int include = 0;
        if (m >= zero_count && n >= one_count)
            include =
                1 + solve(counts, m - zero_count, n - one_count, index + 1);

        int exclude = solve(counts, m, n, index + 1);

        return dp[index][m][n] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        size = strs.size();
        dp.resize(strs.size() + 2,
                  vector<vector<int>>(m + 2, vector<int>(n + 2, -1)));
        vector<pair<int, int>> counts;

        for (auto str : strs) {
            int zero_count = count(str.begin(), str.end(), '0');
            int one_count = str.size() - zero_count;
            counts.push_back({zero_count, one_count});
        }
        return solve(counts, m, n, 0);
    }
};
