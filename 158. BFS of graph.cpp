class Solution {
  public:
  
    void BFS(int u, auto adj, vector<bool>& visited, vector<int>& res){
        queue<int> q;
        q.push(u);
        res.push_back(u);
        visited[u] =true;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto v: adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    res.push_back(v);
                    q.push(v);
                }   
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> res;
        
        BFS(0, adj, visited, res); // 0 -- source
        
        return res;
        
        
    }
};
