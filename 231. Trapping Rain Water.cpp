class Solution {
public:

    vector<int> leftMax(vector<int> h, int n){

        vector<int> temp(n);
        temp[0] = h[0];

        for(int i=1; i<n ;i++){
            temp[i] = max(temp[i-1], h[i]);
        }
        return temp;
    }

    vector<int> rightMax(vector<int> h, int n){
        vector<int> temp(n);
        temp[n-1] = h[n-1];
        
        for(int i=n-2; i>=0 ;i--){
            temp[i] = max(temp[i+1], h[i]);
        }
        return temp;
        
    }

    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> left_max = leftMax(h, n);
        vector<int> right_max = rightMax(h, n);
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += min(left_max[i], right_max[i]) - h[i];
        }

        return sum;
    }
};
