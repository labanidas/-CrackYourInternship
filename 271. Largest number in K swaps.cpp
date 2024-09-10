
class Solution
{
    public:
    string max_num;
    int n;
    void solve(string str, int k, int idx){
        
        if(k == 0 || idx >= n) return;
        
        char max_digit = str[idx];
        
        for(int i=idx+1; i<n; i++){
            if(str[i] > max_digit){
                max_digit = str[i];
            }
        }
        
        if(max_digit != str[idx]){
            for(int i=idx + 1; i<n; i++){
                if(str[i] == max_digit){
                    swap(str[i], str[idx]);
                    
                    if(str.compare(max_num) > 0){
                        max_num = str;
                    }
                    
                    solve(str, k-1, idx+1);
                    
                    swap(str[i], str[idx]);
                    
                }
            }
        }else{
            solve(str, k, idx+1);
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        max_num = str;
        n = str.size();
        solve(str, k, 0);
        return max_num;
       // code here.
    }
};
