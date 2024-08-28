class Solution{
    public:
    
    
    int determinant(vector<vector<int>> matrix)
    {
        int det=0;
        if(matrix.size()==1)
            return matrix[0][0];
        else if(matrix.size()==2)
            return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
        else
        {
            for(int p=0;p<matrix[0].size();p++)
            {
                vector<vector<int>>temp;
                for(int i=1;i<matrix.size();i++)
                {
                    vector<int>row;
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        if(p!=j)
                            row.push_back(matrix[i][j]);
                    }
                    if(row.size()>0)
                        temp.push_back(row);
                }
                det=det+matrix[0][p]*pow(-1,p)*determinant(temp);
            }
            return det;
        }
    }
    
    int countSpanningTrees(vector<vector<int>>&graph, int n, int m){
        vector<vector<int>>laplacian(n, vector<int>(n, 0));
        vector<int> indegree(n, 0);
        
        for(auto it: graph){
            int u = it[0], v= it[1];
            laplacian[u][v] = -1;
            laplacian[v][u] = -1;
            indegree[u]++;
            indegree[v]++;
        }
        
        for(int i=0; i<n; i++){
            laplacian[i][i] = indegree[i];
        }
        
        vector<vector<int>> minorMatrix(n-1, vector<int>(n-1, 0));
        
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                minorMatrix[i-1][j-1] = laplacian[i][j];
            }
        }
        
        return determinant(minorMatrix);
    }
};
