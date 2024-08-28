class Solution {
     struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b) const{
            if(a.first == b.first){
                if(a.first < 0 && b.first < 0)return a.second < b.second;
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
  public:
    vector<vector<int>> minCashFlow(vector<vector<int>> &ts, int n) {
        // code here
        set<pair<int, int>, cmp> s;
        
        for(int i=0; i<n; i++){
            int amount = 0;
            
            for(int j=0; j<n; j++){
                amount += ts[j][i] - ts[i][j];
            }
            
            s.insert({amount, i});
        }
        
        vector<vector<int>> ans(n, vector<int>(n));
        
        while(s.size()>1){
            auto debit = s.begin(), credit=s.end();
            credit--;
            int ad = debit->first, ac = credit->first;
            int from = debit->second, to= credit->second;
            
            s.erase(debit);
            s.erase(credit);
            
            if(-ad<=ac){
                ans[from][to] = -ad;
                ac += ad;
                if(ac) s.insert({ac, to});
            }else{
                ans[from][to] = ac;
                ad += ac;
                if(ad) s.insert({ad, from});
            }
        }
        return ans;
    }
};
