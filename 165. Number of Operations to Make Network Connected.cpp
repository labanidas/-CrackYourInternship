class Solution {
public:
    void DFS(int u, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {
        visited[u] = true;

        for (auto v : adj[u]) {
            if (!visited[v]) {
                DFS(v, adj, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()  < n - 1)
            return -1;

        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        int ans = 0;

        for (auto pair : connections) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                DFS(i, adj, visited);
            }
        }

        return ans - 1;
    }
};
