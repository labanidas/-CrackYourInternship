
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
       map<string, int> mp;
       vector<vector<string>> result;
       
       for(int i=0; i<n ;i++){
           mp[contact[i]]++;
       }
       
       for(int i=0; i<s.size(); i++){
           vector<string> temp;
           
           for(auto& it: mp){
               if(it.first.substr(0, i+1) == s.substr(0,i+1)){
                   temp.push_back(it.first);
               }
           }
           
           if(temp.size() == 0) temp.push_back("0");
            result.push_back(temp);
       }
       
       return result;
    }
};
