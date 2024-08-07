// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool func(int* arr, int n){
    int front, back;
    
    vector<int> temp(arr, arr+n);
    
    sort(temp.begin(), temp.end());
    
    for(front=0; front<n; front++){
        if(temp[front] != arr[front])
            break;
    }
    for(back=n-1; back>=0; back--){
        if(temp[back] != arr[back])
            break;
    }
    
    if(front >= back) return true;
    
    do{
        front++;
        if(arr[front-1] < arr[front])
        return false;
        
    }while(front != back);
    
    return true;
    
    
}

int main() {
    int arr[] = { 1, 2, 5, 4, 3 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    func(arr, n) ? cout<<"true" : cout<<"false";
    return 0;
}
