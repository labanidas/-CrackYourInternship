class Solution
{
	public:
	void utilFunc(int node, auto& adj, auto& visited, auto& st){
	    visited[node] = true;
	    
	    for(auto& v: adj[node]){
	        if(!visited[v])
	            utilFunc(v, adj, visited, st);
	            
	    }
	    
	    st.push(node);
	    return;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<int> ans;
	    vector<bool> visited(V, false);
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i])
	            utilFunc(i, adj, visited, st);
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	  
	}
};
