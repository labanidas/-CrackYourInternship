#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256


void badCharheuristic(string t, int m, int badchar[]){
    int i;
    for(i=0; i<NO_OF_CHARS; i++){
        badchar[i] = -1;
    }
    
    for(i=0; i<m; i++){
        badchar[(int)t[i]] = i;
    }
}

vector<int> search(string s, string t){
    vector<int> ans;
    int m = t.size(), n = s.size();
    int badchar[NO_OF_CHARS];
    
    badCharheuristic(t, m, badchar);
    
    int k = 0;
    
    while(k <= (n-m)){
        int j = m -1;
        while(j >=0 && t[j] == s[k + j])
        j--;
        
        if(j<0){
            ans.push_back(k);
            k += (k + m < n) ? m - badchar[(int)s[k + m] ] : 1;
        }else{
           k += max(1, j-badchar[(int)s[k + j]]);
        }
    }
    
    return ans;
}

/* Driver code */
int main()
{
    string txt = "ABAAABCD";
    string pat = "ABC";
    vector<int> ans = search(txt, pat);
    
    for(auto num: ans) cout<<num<<" ";
    
    
    txt = "GFGKKKKKGFGKKKKKGFG";
    pat = "GFG";
    ans = search(txt, pat);
    
    for(auto num: ans) cout<<num<<" ";
    
    return 0;
}
 
