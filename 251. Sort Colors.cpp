class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x=0,y=0,z=0;

        for(auto& num: nums){
            if(num == 0) x++;
            if(num == 1) y++;
            if(num == 2) z++;
        }

        for(int i=0; i<x; i++) nums[i] = 0;
        for(int i=x; i<x+y; i++) nums[i] = 1;
        for(int i=x+y; i<x+y+z; i++) nums[i] = 2;
        
    }
};
