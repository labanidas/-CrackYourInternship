class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int area = INT_MIN;

        while( left < right){
            bool right_max = height[left] < height[right] ?  true : false;

            int curr_area = (right-left) * min(height[left], height[right]); // widht kam kar rahe to area to bada chuno

            area = max(area, curr_area);

            // widht kam kar rahe to area to bada chuno
            if(right_max)
                left++;
            else right--;
        }

        return area;
    }
};
