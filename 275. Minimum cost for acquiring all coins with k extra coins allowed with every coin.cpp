

// C++ program to acquire all n coins  
#include<bits/stdc++.h> 
using namespace std; 

int minCost(int coin[], int n, int k){
    int ans = 0;
    sort(coin, coin+n);
    int min_coins = ceil((1.0 * n) /(k+1) );
    
    for(int i=0; i< min_coins; i++){
        ans += coin[i];
    }
    
    return ans;
}

// Driver Code 
int main() 
{ 
    int coin[] = {100, 20, 50, 10, 2, 5}; 
    int n = sizeof(coin) / sizeof(coin[0]); 
    int k = 3; 
    cout << minCost(coin, n, k); 
    return 0; 
}  
