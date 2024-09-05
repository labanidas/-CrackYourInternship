/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
         auto compare = [](Job& j1, Job& j2) {
            return j1.profit > j2.profit;
        };
        
        sort(arr, arr + n, compare);
        
        int jobs_done = 0, max_profit = 0;
        
        int max_deadline = 0;
        for(int i = 0; i<n; i++) {
            max_deadline = max(max_deadline, arr[i].dead);
        }
        
        // int slot [ max_deadline + 1 ] = {-1};
        vector<int> slot( max_deadline + 1, -1);
        
        for(int i = 0; i<n; i++){
            Job job = arr[i];
            
            for(int j = job.dead; j>0; j--){
                
                if(slot[j] == -1){
                    slot[j] = job.id;
                    jobs_done++;
                    max_profit +=  job.profit;
                    break;
                }
            }
        }
        
        return {jobs_done, max_profit};
    } 
};
