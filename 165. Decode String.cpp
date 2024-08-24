class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> strstack;
        string currstr = "";
        int currnum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currnum = currnum * 10 + (ch - '0');
            } else if (ch == '[') {
                numstack.push(currnum);
                strstack.push(currstr);

                currstr = "";
                currnum = 0;
            } else if (ch == ']') {
                int repeat = numstack.top();
                numstack.pop();
                string prev = strstack.top();
                strstack.pop();

                for (int i = 0; i < repeat; i++) {
                    prev += currstr;
                }
                currstr = prev;
            }else{
                currstr += ch;
            }
        }

        return currstr;
    }
};
