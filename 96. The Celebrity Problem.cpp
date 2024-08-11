class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int ans = -1;
        
        vector<int> i_know(n, 0);
        vector<int> others_know(n, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    i_know[i]+=1;
                    others_know[j]+=1;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(i_know[i] == 0 && others_know[i]==n-1)
                return i;
        }
        
        return ans;
    }
};
