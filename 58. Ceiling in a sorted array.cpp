// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int findCeil(int x, int* arr, int n){
    int ans = -1;
    
    for(int i=0; i<n; i++){
        if(arr[i] <= x) ans=arr[i];
    }
    return ans;
}

int findFloor(int x, int* arr, int n){
    for(int i=0; i<n; i++){
        if(arr[i] >= x) return arr[i];
    }
    
    return -1;
    
}

int main() {

   int arr[] = {1,2,3,5,6}; // sorted arr in non descreasing order
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 4;
   
   int c = findCeil(x, arr, n);
   int f = findFloor(x, arr, n);
   
   cout<<"Ceiling of "<<x<<" : "<<c<<endl;
   cout<<"Floor of "<<x<<" : "<<f<<endl;
   

    return 0;
}
