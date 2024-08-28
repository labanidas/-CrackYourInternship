
class Solution {
public:
    int findParent(int node, vector<int>& ds) {
        if (ds[node] == node)
            return node;
        return findParent(ds[node], ds);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> ds(n + 1);

        for(int i=0; i<=n; i++){
            ds[i] = i;
        }
        
        for(auto it: edges){
            int p1 = findParent(it[0], ds);
            int p2 = findParent(it[1], ds);
            if(p1==p2) return it;

            ds[p1] = p2;
        }

        return {};
    }
};
