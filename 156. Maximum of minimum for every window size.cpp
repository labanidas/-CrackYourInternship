class Solution
    {
        public:
        //Function to find maximum of minimums of every window size.
        vector<int> maxOfMin(int arr[], int n) {
            
        vector<int> left(n, -1), right(n, n), result(n+1, 0);
        stack<int> s;
    
        // Fill left[] array
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
                
            if(!s.empty()) left[i] = s.top();
            s.push(i);
        }
    
        // Clear stack to reuse
        while (!s.empty())
            s.pop();
    
        // Fill right[] array
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                right[i] = s.top();
            s.push(i);
        }
    
        // Calculate max of minimums
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            result[len] = max(result[len], arr[i]);
        }
    
        // Fill the remaining entries in result
        for (int i = n-1; i >= 1; i--)
            result[i] = max(result[i], result[i+1]);
    
        // The result array starts from index 1 (window sizes 1 to n)
        vector<int> res(n);
        for (int i = 1; i <= n; i++)
            res[i-1] = result[i];
    
        return res;
    }

};
