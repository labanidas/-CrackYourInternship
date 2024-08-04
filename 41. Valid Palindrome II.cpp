class Solution {
public:
    string s;
    bool isvalid(int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string S) {
        s = S;
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return isvalid(i + 1, j) || isvalid(i, j - 1);
            }
        }

        return true;
    }
};
