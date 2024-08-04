// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    unordered_map<char, int> mp;
    
     string str = "test string";
    
        for(auto& c: str){
            mp[c]++;
        }
    for(auto& it: mp){
        if(it.second > 1){
            cout<<it.first<<", Count = "<<it.second<<endl;
        }
    }
}
