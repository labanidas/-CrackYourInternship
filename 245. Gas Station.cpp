
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tot_tank = 0, curr_tank = 0, start_index = 0;

        for (int i = 0; i < n; i++) {
            tot_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];

            if (curr_tank < 0) {
                curr_tank = 0;
                start_index = i + 1;
            }
        }
        return tot_tank < 0 ? -1 : start_index;
    }
};
