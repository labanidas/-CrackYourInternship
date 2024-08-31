class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int n = stations.size(), count = 0, i = 0, max_reach = startFuel;
        priority_queue<int> pq; // max- heap

        while (max_reach < target) {
            while (i < n && stations[i][0] <= max_reach) {
                pq.push(stations[i][1]);
                i++;
            }

            if (pq.empty())
                return -1;

            max_reach += pq.top();
            pq.pop();
            count++;
        }

        return count;
    }
};
