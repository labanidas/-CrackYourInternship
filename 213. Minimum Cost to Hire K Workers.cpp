class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {

        int n = quality.size();
        vector<pair<double, int>> worker_ratio(n);
        priority_queue<int, vector<int>>pq;
        double sum_quality = 0;

        for(int i=0; i<n; i++){
            worker_ratio[i] = {(double)min_wage[i]/quality[i], quality[i]};
        }

        sort(worker_ratio.begin(), worker_ratio.end());

        for(int i =0; i<k; i++){
            pq.push(worker_ratio[i].second);
            sum_quality += worker_ratio[i].second;

        }

        double manager_ratio = worker_ratio[k-1].first;
        double result = manager_ratio*sum_quality;


        for(int manager = k; manager<n; manager++){
            
            manager_ratio = worker_ratio[manager].first;
            pq.push(worker_ratio[manager].second);
            sum_quality += worker_ratio[manager].second;

            if(pq.size() > k){
                sum_quality -= pq.top();
                pq.pop();

            }

            result = min(result, manager_ratio*sum_quality);

        }


        return result;
    }
};
