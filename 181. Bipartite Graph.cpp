class Solution {
public:
    bool util(auto& adj, int u, auto& color, int curr_color) {
        color[u] = curr_color;

        for (auto& v : adj[u]) {
            if (color[v] == color[u])
                return false;

            if (color[v] == -1) {
                int colorofv = 1 - curr_color;

                if (util(adj, v, color, colorofv) == false)
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (util(adj, i, color, 1) == false)
                    return false;
            }
        }
        return true;
    }
};
