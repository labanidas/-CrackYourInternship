class Solution {
  public:
    void DFS(int u, auto adj, vector<bool>& visited, vector<int>& res){
      if(visited[u]) return;
      
      visited[u] = true;
      res.push_back(u);
      
      for(auto v: adj[u]){
          DFS(v, adj, visited, res);
      }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> res;
       vector<bool> visited(V, false);
       
       DFS(0, adj, visited, res); // 0 -  start index
        
        
        return res;
    }
};
