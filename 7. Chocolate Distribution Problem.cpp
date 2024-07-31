class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(), a.end());
    long long min_diff = INT_MAX;
    int left = 0;
    int right = m-1;
    
    while(right<a.size()){
        long long diff = a[right] - a[left];
        min_diff = min(min_diff, diff);
        right++;
        left++;
        
    }

    return min_diff;
    
    }   
};
