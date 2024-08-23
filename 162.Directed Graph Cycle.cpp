class Solution {
  public:
  
  bool DFS(int u, auto adj,vector<bool>& in_recursion, vector<bool>& visited ){
    
        in_recursion[u] = true;
        visited[u] = true;
        
        for(auto v: adj[u]){
            if(visited[v] && in_recursion[v]) return true;
            if(!visited[v] && DFS(v, adj, in_recursion, visited))
                return true;
        }
        
        in_recursion[u] = false;
        
        return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<bool> in_recursion(V, false);
       vector<bool> visited(V, false);
       
       for(int i=0; i<V; i++){
           if(!visited[i] && DFS(i, adj, in_recursion, visited))
            return true;
       }
       
       return false;
    }
};
