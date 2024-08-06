class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";

        while(columnNumber){
            columnNumber--;
            int remainder = columnNumber % 26;
            columnNumber /= 26;
            
            char c= 'A' + remainder ;
            ans += c;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
