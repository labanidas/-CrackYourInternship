class Solution {
  public:
  
    bool DFS(int u, int parent, vector<int> adj[], vector<bool>& visited){
        visited[u]=true;
        
        for(auto v: adj[u]){
            if(v==parent) continue;
            if(visited[v]) return true;
            if(DFS(v, u, adj, visited) == true) return true;
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && DFS(i, -1, adj, visited))
                return true;
            
        }
        
        return false;
    }
};
