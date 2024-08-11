
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   vector<pair<int, int>> vect;
        int n = nums.size();
    
        for(int i=0; i<n; i++){
          vect.push_back({nums[i], i});
        }
        sort(vect.begin(), vect.end());
    
        int swaps=0;
        for(int i=0; i<n; i++){
            pair<int, int> p = vect[i];
            
            int index = p.second;
            
            if(i!=index){
                 swaps++;
                 swap(vect[i], vect[index]);
                 i--;
            } 
              
        }
        return swaps;
	}
};
