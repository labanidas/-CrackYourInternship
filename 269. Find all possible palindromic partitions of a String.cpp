 class Solution {
  public:
  
    int n;
    
    bool isPalindrome(string s, int l, int r){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        
        return true;
    }
  
    void solve(int idx, string s, vector<vector<string>>& ans, vector<string>& curr ){
        if(idx == n){
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, ans, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> allPalindromicPerms(string s) {
       n = s.size();
       
       vector<vector<string>> ans;
       vector<string> temp;
       
       solve(0, s, ans, temp);
       return ans;
    }
};
