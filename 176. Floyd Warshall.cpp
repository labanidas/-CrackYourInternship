class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	 int n = matrix.size();
        
        // Initialize the matrix, converting -1 to a large value (infinity).
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1 && i != j) {
                    matrix[i][j] = 1e9; // Use a large number to represent infinity
                }
            }
        }

        // Floyd-Warshall Algorithm to update the matrix with shortest distances.
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
                }
            }
        }

        // Convert any remaining 'infinity' values back to -1.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
	}
};
