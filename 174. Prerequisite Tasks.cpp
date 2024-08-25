class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	   
	   unordered_map<int, vector<int>> adj;
	   vector<int> indegree(N, 0);
	   int count = 0;
	   
	   for(auto& item: prerequisites){
	       int u = item.first;
	       int v = item.second;
	       adj[u].push_back(v);
	       indegree[v]++;
	   }
	   
	   queue<int> q;
	    for(int i=0; i<N; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        count++;
	        
	        for(auto& v: adj[u]){
	            indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    
	    return count == N;
	}
};
