class Solution{
  public:
  int n, target_sum;
  
    bool solve(int nums[], bool visited[], int k, int curr_idx, int curr_sum){
        if( k == 1) return true;
        
        if(curr_sum == target_sum){
            return solve(nums, visited, k-1, 0, 0);
        }
        
        for(int i=curr_idx; i<n; i++){
            if(!visited[i] && curr_sum + nums[i] <= target_sum){
                visited[i] = true;
                if(solve(nums, visited, k, i+1, curr_sum + nums[i]) == true){
                    return true;
                }
                visited[i] = false;
            }
        }
        
        return false;
    }
    bool isKPartitionPossible(int nums[], int N, int k)
    {   
        n = N;
        int total = 0;
        
        for(int i=0; i<n; i++) total += nums[i];
        
        if(total % k != 0) return false;
        
        target_sum = total/k;
        
        bool visited[n] = {false};
        
        
        return solve(nums, visited, k, 0, 0);
    }
};
