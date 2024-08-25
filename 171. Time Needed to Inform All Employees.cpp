class Solution {
public:
    int max_ans = INT_MIN;

    void dfs(unordered_map<int, vector<int>>& adj, int& curr_emp, int curr_time, vector<int>& info){
        max_ans = max(max_ans, curr_time);

        for(auto& emp: adj[curr_emp]){
            dfs(adj, emp, curr_time + info[emp], info);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       unordered_map<int, vector<int>> adj;

       for(int i=0; i<n; i++){
        int emp = i;
        int mnger = manager[i];

        if(mnger != -1)
            adj[mnger].push_back(emp);
        
       }

       dfs(adj, headID, informTime[headID], informTime);

       return max_ans;
    }
};
