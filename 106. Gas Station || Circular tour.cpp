/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
    //   int n = petrolPump.size();
        int tot_tank = 0, curr_tank = 0, start_index = 0;

        for (int i = 0; i < n; i++) {
            
            int gas = p[i].petrol;
            int cost = p[i].distance;
            
            tot_tank += gas- cost;
            curr_tank += gas- cost;

            if (curr_tank < 0) {
                curr_tank = 0;
                start_index = i + 1;
            }
        }
        return tot_tank < 0 ? -1 : start_index;
    }
};
