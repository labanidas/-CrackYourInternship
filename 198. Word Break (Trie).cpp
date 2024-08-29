class Solution{
    public:
    int n;
    unordered_set<string> st;
    unordered_map<int, bool> dp;
    
    // A : given string to search
    // B : vector of available strings
    
    bool solve(string& s, int idx){
        if(idx >= n) return true;
        
        
        if(dp.find(idx) != dp.end()) return dp[idx];
        
        
        for(int i=1; i<=n; i++){
            string temp = s.substr(idx, i);
            if(st.count(temp) && solve(s, idx+i))
                return dp[idx] =   true;
        }
        return dp[idx] = false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        n = A.size();
        
        
        for(auto word: B){
            st.insert(word);
        }
        
        
        return solve(A, 0);
    }
};
