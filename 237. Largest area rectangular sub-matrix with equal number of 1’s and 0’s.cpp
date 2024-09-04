// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

  int area(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Transform 0's to -1's
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) mat[i][j] = -1;
            }
        }

        int max_area = 0;

        for (int top = 0; top < rows; top++) {
            vector<int> colSum(cols, 0);
            for (int bottom = top; bottom < rows; bottom++) {

                for (int col = 0; col < cols; col++) {
                    colSum[col] += mat[bottom][col];
                }

                unordered_map<int, int> sumMap;
                sumMap[0] = -1; 
                int sum = 0;
                for (int i = 0; i < cols; i++) {
                    sum += colSum[i];

                    if (sumMap.find(sum) != sumMap.end()) {
                        int length = i - sumMap[sum];
                        int height = bottom - top + 1;
                        int area = length * height;
                        max_area = max(max_area, area);
                    } else {
                        sumMap[sum] = i;
                    }
                }
            }
        }

        return max_area;
    }
    
int main() {
    vector<vector<int>> mat = { {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 1} };
                    
    cout<<area(mat);
    return 0;
}
