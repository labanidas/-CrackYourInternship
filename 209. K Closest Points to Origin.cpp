class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, pair<int, int>> > pq; //  max heap

        for(auto& point: points){
            int x = point[0], y = point[1];
            // double eu = sqrt( pow(x, 2) + pow(y,2));
            int eu = x*x + y*y;
            pq.push({eu, {x, y}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            auto p = pq.top().second;
            pq.pop();
            result.push_back({p.first, p.second});
        }

        return result;
    }
};
