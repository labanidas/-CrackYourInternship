class Solution {
public:
    void solve(int i, int n, vector<bool>& visited, int& ans) {

        if (i > n) {
            ans++;
            return;
        }

        for (int num = 1; num <= n; num++) {
            if (!visited[num] && (i % num == 0 || num % i == 0)) {
                visited[num] = true;
                solve(i + 1, n, visited, ans);
                visited[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> visited(n, false);
        int ans = 0;
        solve(1, n, visited, ans);
        return ans;
    }
};
