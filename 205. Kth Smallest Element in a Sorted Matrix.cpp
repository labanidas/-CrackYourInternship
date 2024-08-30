class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Define a custom comparator for the priority queue.
        // The priority queue will act as a min-heap, so the smallest element
        // should be at the top.
        auto compare = [](pair<int, pair<int, int>> a,
                          pair<int, pair<int, int>> b) {
            return a.first > b.first; // Compare based on the first element of the pair.
        };

        // Initialize the priority queue with the custom comparator.
        // The priority queue stores pairs where:
        // - The first element is the value from the matrix.
        // - The second element is a pair of indices (row, column).
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, decltype(compare)>
            pq(compare);

        int n = matrix.size(); 
        // Push the first element of each row into the priority queue.
        // This sets up the initial state for the min-heap.
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        // Extract the minimum element k - 1 times to get to the kth smallest element.
        for (int i = 0; i < k - 1; i++) {
            // Get the smallest element from the priority queue.
            auto elem = pq.top();
            pq.pop(); // Remove the smallest element from the heap.

            int row = elem.second.first; // Row index of the element.
            int col = elem.second.second; // Column index of the element.

            // If there's another element in the same row, push it into the priority queue.
            if (col + 1 < n)
                pq.push({matrix[row][col + 1], {row, col + 1}});
        }

        // The top element of the priority queue is now the kth smallest element.
        return pq.top().first;
    }
};
