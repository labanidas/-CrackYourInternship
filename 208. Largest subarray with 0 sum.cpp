
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
       unordered_map<int, int> mp;
       int max_len = 0;
       int sum = 0;
       
       
       for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0){
                max_len = i+1;
            }
            
           if(mp.find(sum) != mp.end()){
               max_len = max(max_len, i-mp[sum] );
           }else{
               mp[sum] = i;
           }
       }
       
       return max_len;
    }
};
