#include <bits/stdc++.h>
using namespace std;



vector<vector<char>> matrix = {
    // // 1.
    //     {'0', '1', '1', '0'},
    //     {'1', '1', '1', '1'},
    //     {'1', '1', '1', '1'},
    //     {'1', '1', '0', '0'}
    
    // // 2.
    
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
    };


int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> heights(m+1, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            
            
            for(int p=0; p<(m+1); p++){
                int minHeight = INT_MAX;
                for(int q=p; q<(m+1); q++){
                    minHeight = min(minHeight, heights[q]);
                    int area = minHeight * (q-p+1);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    
    
int main() {
    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout<<maximalRectangle(matrix)<<endl;
    
    return 0;
}
