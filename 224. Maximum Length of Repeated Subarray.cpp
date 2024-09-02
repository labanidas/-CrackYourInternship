class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {

        if (i >= n || j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int len = 0;

        if (nums1[i] == nums2[j]) 
            len = 1 + solve(nums1, nums2, i + 1, j + 1);

            return dp[i][j] = len;
    }
        int findLength(vector<int> & nums1, vector<int> & nums2) {
            n = nums1.size();
            m = nums2.size();
            int max_len = INT_MIN;

            dp.resize(n, vector<int>(m, -1));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    max_len = max(max_len, solve(nums1, nums2, i, j));
                }
            }
            return max_len;
        }
    };
