class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int curr = 0;

        // for(auto ni: cardPoints) total_pts+= ni;

        for(int i=0; i<k; i++) curr += cardPoints[i];
        
        int ans = curr;

        for(int i=0; i<k; i++){
            curr -= cardPoints[k-i-1]; // remove from begining
            curr += cardPoints[n-i-1]; // add from end

            ans = max(ans, curr);
        } 
        return ans;
    }
};




