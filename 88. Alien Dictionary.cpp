// User function Template for C++

class Solution {
  public:
    vector<int> topoSort(vector<int> adj[], int V){
        
        vector<int> indegree(V, 0);
        
        // -------find indegree---------
        for(int i=0; i<V; i++){
            for(auto& v: adj[i]){
                indegree[v]++;
            }
        }
        
        //------- queue work---------
        queue<int> q;
        // push all nodes with indegree 1
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        // populate topo vector
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            
            for(auto& v: adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        
        return topo;
    }
    string findOrder(string dict[], int n, int k) {
       
       vector<int>adj[k];
       
       // convert to adj matrix
       for(int i=0; i<n-1; i++){
           string s1 = dict[i];
           string s2 = dict[i+1];
           
           int len = min(s1.size(), s2.size());
           
           for(int ptr = 0; ptr<len; ptr++){
               if(s1[ptr]!= s2[ptr]){
                   adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                   break;
               }
           }
       }
       
       // find topological order
       vector<int> topo = topoSort(adj, k);
       
       // convert to string
       string ans="";
       for(auto& v: topo){
           ans = ans +  char(v +'a');
       }
       return ans;
    }
};
