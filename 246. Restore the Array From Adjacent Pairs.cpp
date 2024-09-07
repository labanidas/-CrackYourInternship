class Solution {
public:
    vector<int> ans;
    unordered_set<int>
        visited; //  because n is no. of distince elements not no. of nodes
    unordered_map<int, vector<int>> adj;

    void dfs(int u) {
        ans.push_back(u);
        visited.insert(u);

        for (auto& v : adj[u]) {
            if (visited.count(v) == 0) {
                dfs(v);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& arr) {

        for (auto nums : arr) {
            int u = nums[0], v = nums[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (auto it : adj) {
            if (it.second.size() == 1) {
                dfs(it.first);
                break;
            }
        }

        return ans;
    }
};
