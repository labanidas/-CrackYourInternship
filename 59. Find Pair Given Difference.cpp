class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
    
        unordered_set<int> s;
        
        for(auto num: arr){
            if(s.count(num+x) > 0 || s.count(num-x) > 0)
                return 1;
            
            s.insert(num);
        }
        
        return -1;
    }
};
