class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& visited, vector<int> adj[], int time[],
             int low[], vector<vector<int>>& bridges) {
        visited[node] = 1;
        time[node] = low[node] = timer;
        timer++;

        for (auto& v : adj[node]) {
            if (v == parent)
                continue;
            if (visited[v] == 0) {
                dfs(v, node, visited, adj, time, low, bridges);
                low[node] = min(low[node], low[v]);
                if (low[v] > time[node]) {
                    bridges.push_back({v, node});
                }
            } else {
                low[node] = min(low[node], low[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto& item : connections) {
            int u = item[0], v = item[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int time[n], low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, visited, adj, time, low, bridges);

        return bridges;
    }
};
