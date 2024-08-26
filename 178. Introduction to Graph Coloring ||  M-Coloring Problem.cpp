class Solution{
public:
    bool isSafe(int node, int n, auto& graph, auto& color, int col){
    
        for(int i=0; i<n; i++){
            if(graph[node][i] == 1 && color[i] == col)
                return false;
        }   
        
        return true;
    }
    bool solve(int node, auto& graph, int m, int n, auto& color){
        if(node == n) return true;
        
        for( int c = 1; c<=m; c++){
            if(isSafe(node, n, graph, color, c)){
                color[node] = c;
                
                if(solve(node+1, graph, m, n, color) == true) return true;
                
                color[node] = 0;
            }
        }
        
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
       
      int color[101] = {0};
       
       return solve(0, graph, m, n, color);
    }
};
