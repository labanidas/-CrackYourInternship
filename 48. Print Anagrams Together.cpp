class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;


        for(string str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }

        for(auto it: mp){
            result.push_back(it.second);
        }

        return result;
    }
};
