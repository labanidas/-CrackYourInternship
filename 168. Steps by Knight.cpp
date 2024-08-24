class Solution 
{
    public:
    bool isValid(int x, int y, int n, vector<vector<bool>>& visited){
        if(x>=n || x<0 || y>=n || y<0) return false;
        if(visited[x][y]) return false;
        return true;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int kx = KnightPos[0]-1, ky = KnightPos[1]-1;
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int x[] = { 1, 1, -1, -1, 2, -2, 2, -2};
	    int y[] = {2, -2, 2, -2,  1, 1, -1, -1,};
	    int ans = 0;
	    
	    if(kx == tx && ky == ty) return 0;
	    
	    vector<vector<bool>> visited(n, vector<bool>(n, false));
	    queue<pair<int, int>> q;
	    q.push({kx, ky});
	    visited[kx][ky] = true;
	    
	    while(!q.empty()){
	        int size = q.size();
	        ans++;
	        while(size--){
	            pair<int, int> p = q.front();
	            q.pop();
	            
	            int x1 = p.first;
	            int y1 = p.second;
	            
	            for(int i=0; i<8; i++){
	                int nx = x1 + x[i];
	                int ny = y1 + y[i];
	                
	                if(nx == tx && ny == ty) return ans;
	                
	                if(isValid(nx, ny, n, visited)){
	                    visited[nx][ny] = true;
	                    q.push({nx, ny});
	                }
	                    
	            }
	        }
	        
	    }
	    
	    return -1;
	}
};
