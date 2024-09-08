class Solution{
public:
    bool isSafe(int node, int n, bool graph[101][101],  int color[101], int c){
        
        for(int i=0; i<n; i++){
            if(graph[node][i] == 1 && color[i] == c)
                return false;
        }
        
        return true;
    }
    bool solve(int node, int m, int n, bool graph[101][101], int color[101] ){
        if(node == n) return true;
        
        for(int c=1; c<=m; c++){
            if(isSafe( node , n, graph,color,  c)){
                
                color[node] = c;
                
                if ( solve(node+1, m, n, graph, color) ) return true;
                
                color[node] = 0;
            }
        }
        
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
       
        int color[101] = {0};
        
        return solve(0, m, n, graph, color);
    }
};
