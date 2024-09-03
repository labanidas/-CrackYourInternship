class Solution {
public:
    unordered_map<int, int> mp; 
    vector<vector<int>> dp; 
    int n; 

    bool solve(int idx, int last_jump, const vector<int>& stones) {
        if (idx == n - 1) return true; 
        if (dp[idx][last_jump] != -1) return dp[idx][last_jump]; 

        bool result = false;

        for (int jump = last_jump - 1; jump <= last_jump + 1; ++jump) {
            if (jump > 0) { 
                int next_stone = stones[idx] + jump;
                if (mp.find(next_stone) != mp.end()) { 
                    int next_idx = mp[next_stone];
                    result = result || solve(next_idx, jump, stones); 
                }
            }
        }

        return dp[idx][last_jump] = result; 
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        dp.resize(n, vector<int>(n, -1)); 

        for (int i = 0; i < n; ++i) {
            mp[stones[i]] = i;
        }

        if (stones[1] != 1) return false;

        return solve(0, 0, stones);
    }
};
