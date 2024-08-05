class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    // Max-heap to store pairs (yi - xi, xi)
    priority_queue<pair<int, int>> maxHeap;
    int maxValue = INT_MIN;

    for (const auto& point : points) {
        int xj = point[0];
        int yj = point[1];

        // Remove points from the heap where (xj - xi) > k
        while (!maxHeap.empty() && xj - maxHeap.top().second > k) {
            maxHeap.pop();
        }

        // If the heap is not empty, compute the value of the equation using the top of the heap
        if (!maxHeap.empty()) {
            maxValue = max(maxValue, yj + xj + maxHeap.top().first);
        }

        // Push the current point (yj - xj, xj) onto the heap
        maxHeap.emplace(yj - xj, xj);
    }

    return maxValue;
}
};
