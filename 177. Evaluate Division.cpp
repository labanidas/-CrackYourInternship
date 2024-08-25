class Solution {
public:

    void dfs(auto& adj, string src, string dst, auto& visited, double product, double& ans ){
        if(visited.find(src) != visited.end()) return;

        visited.insert(src);

        if(src == dst){
            ans = product;
            return;
        }

        for(auto p: adj[src]){
            string v = p.first;
            double val = p.second;

            dfs(adj, v, dst, visited, product*val, ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& que) {
        int n = eq.size();

        unordered_map<string, vector<pair<string, double>>> adj;

        for(int i=0; i<n; i++){
            auto& item = eq[i];
            
            string u = item[0];
            string v = item[1];
            double data = val[i];

            adj[u].push_back({v, data});
            adj[v].push_back({u, 1.0/data});
        } 

        vector<double> result;

        for(auto& q: que){
            string src = q[0];
            string dst = q[1];

            double ans = -1.0;
            double product = 1.0;

            if(adj.find(src) != adj.end()){
                unordered_set<string> visited;

                dfs(adj, src, dst, visited, product, ans);
            }

            result.push_back(ans);

        }

        return result;
    }
};
