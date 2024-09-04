class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {

        int rows = mat.size(), cols = mat[0].size();

        vector<int> heights(cols + 1, 0);
        int max_area = 0;

        for (auto& row : mat) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            int n = heights.size();

            for (int i = 0; i < n; i++) {
                int min_height = INT_MAX;
                for (int j = i; j < n; j++) {
                    min_height = min(min_height, heights[j]);
                    int area = min_height * (j - i + 1);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};
