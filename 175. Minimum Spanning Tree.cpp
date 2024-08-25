
class Solution {
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
     int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minH;
        vector<bool> visited(V, false);
        minH.push({0, 0, -1}); // {weight, current node, parent node}
        
        
        // prims algorithm
        while(!minH.empty()){
            auto& curr = minH.top();
            int w = curr[0];
            int u = curr[1];
            int v = curr[2];
            minH.pop();
            
            if(visited[u]) continue;
            
            visited[u] = true;
            
            ans+= w;
            
            for(auto& vp: adj[u]){
                int cv = vp[0];
                int cw = vp[1];
                
                if(!visited[cv]){
                    minH.push({cw, cv, u});
                }
            }
        }
        
        return ans;
    }
};
