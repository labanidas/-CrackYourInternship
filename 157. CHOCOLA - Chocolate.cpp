// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int solve(int arr1[], int arr2[], int m, int n){
       
      sort(arr1, arr1+m, greater<int>());
      sort(arr2, arr2+n, greater<int>());
      
      int ans = 0, i=0, j=0, vertical_count=1, horizontal_count=1;
      
      while(i<m && j<n ){
          if(arr1[i] >= arr2[j]){
              ans += arr1[i] * vertical_count;
              horizontal_count++;
              i++;
          }else {
              ans+= arr2[j] * horizontal_count;
              vertical_count++;
              j++;
          }
      }
      
      while(i<m){
          ans += arr1[i] * vertical_count;
          i++;
      }
      while(j<n){
          ans += arr2[i] * horizontal_count;
          j++;
      }
      
      return ans;
}

int main() {
    int arr1[] = {4, 1, 2};
    int arr2[] = {2, 1, 3, 1, 4};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    
    cout<<solve(arr1, arr2, m, n);
    
    return 0;
}
