class Solution {
public:
    bool DFS(int u, vector<vector<int>>& adj, vector<bool>& in_recursion,
             vector<bool>& visited) {

        in_recursion[u] = true;
        visited[u] = true;

        for (auto v : adj[u]) {
            if (visited[v] && in_recursion[v])
                return true;
            if (!visited[v] && DFS(v, adj, in_recursion, visited))
                return true;
        }

        in_recursion[u] = false;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> in_recursion(V, false);
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                DFS(i, graph, in_recursion, visited);
        }

        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (in_recursion[i] == false)
                ans.push_back(i);
        }
        return ans;
    }
};
