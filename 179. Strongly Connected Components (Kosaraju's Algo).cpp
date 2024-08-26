class Solution
{
	public:
    void dfsfill(int u, auto& adj, auto& visited, auto& st){
        visited[u] = true;
        
        for(auto& v: adj[u]){
            if(!visited[v])
                dfsfill(v, adj, visited, st);
        }
        
        st.push(u);
    }
   
   void dfstraverse(int u, auto& adj, auto& visited){
       visited[u]  = true;
       
       for(auto& v : adj[u]){
           if(!visited[v])
            dfstraverse(v, adj, visited);
       }
   }
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<bool> visited(V, false);
        int count = 0;
        
        for(int i=0; i<V; i++){
            if(!visited[i])
                dfsfill(i, adj, visited, st);
        }
        
        vector<vector<int>> adjRev(V);
        
        for(int u=0; u<V; u++){
            for(auto& v : adj[u]){
                adjRev[v].push_back(u);
            }
        }
        
        visited = vector<bool>(V, false);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                count++;
                dfstraverse(node, adjRev, visited);
            }
        }
        
        return count;
    }
};
