  void dfs(int i, int j, vector<vector<bool>>& vis, int n, int m, vector<vector<char>>& mat){
        if(i>=n || i<0 || j>=m || j<0 || vis[i][j] || mat[i][j] == 'X')
            return;
            
        vis[i][j] = true;
        
        dfs(i+1, j, vis, n, m, mat);
        dfs(i-1, j, vis, n, m, mat);
        dfs(i, j+1, vis, n, m, mat);
        dfs(i, j-1, vis, n, m, mat);
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // corner columns
        for(int j=0; j<m; j++){
            // first column
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0, j, vis, n, m, mat);
            }
            // last column
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1, j, vis, n, m, mat);
            }
        }
        
        // corner rows
        for(int i=0; i<n; i++){
            // first column
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0, vis, n, m, mat);
            }
            // last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, vis, n, m, mat);
            }
        }
        
        // changing 0 to X
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
