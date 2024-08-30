class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {

        int n = h.size();
        priority_queue<int> pq;
        int i = 0;

        for (i = 0; i < n - 1; i++) {

            // Calculate the height difference between the current building and
            // the next one
            int diff = h[i + 1] - h[i];

            // If the next building is not taller, no resources are needed, so
            // continue
            if (diff <= 0)
                continue;

            // Use bricks to cover the height difference
            b -= diff;

            // Store the used brick amount in the priority queue
            pq.push(diff);

            // If bricks are insufficient (b < 0), try to replace the largest
            // brick usage with a ladder
            if (b < 0) {
                l--;           // Use one ladder
                b += pq.top(); // Recover the largest brick usage by replacing
                               // it with a ladder
                pq.pop(); // Remove the largest brick usage from the priority
                          // queue
            }

            // If no ladders are left, stop and return the current building
            // index
            if (l < 0)
                break;
        }

        return i;
    }
};
