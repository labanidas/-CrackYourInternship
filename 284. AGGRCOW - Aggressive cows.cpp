// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> &stalls, int minDist, int k)
{
    int cows=1;               
    int lastCowPosition=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCowPosition>=minDist)
        {
            cows++;
            lastCowPosition=stalls[i];
            if(cows>=k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];             
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossible(stalls,mid,k))
        {
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}


int main() {
    vector<int> arr = {1,2,4,8,9};
    int k = 3;
    cout<<aggressiveCows(arr, k);
    return 0;
}
