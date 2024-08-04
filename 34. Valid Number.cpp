class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();
        bool isNumeric = false;

        auto isDigit = [](char ch) { return ch >= '0' && ch <= '9'; };

        while(i<n && s[i] == ' ') i++;  

        if (i < n && (s[i] == '+' || s[i] == '-'))  i++;

        while (i < n && isDigit(s[i])) {
            i++;
            isNumeric = true;
        }

        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isDigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }

        if (isNumeric && i < n  && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isNumeric = false;

            if(i<n && (s[i] == '+' || s[i] == '-')) i++;
            
            while (i < n && isDigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }

        while (i < n && s[i] == ' ')
            i++;

        return isNumeric && i == n;
    }
};
