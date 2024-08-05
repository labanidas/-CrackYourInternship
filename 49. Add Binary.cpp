class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int l1 = a.size() - 1, l2 = b.size() - 1;
        int carry = 0;

        while (l1 >= 0 || l2 >= 0 || carry) {
            int n1 = l1 >= 0 ? a[l1] - '0' : 0;
            int n2 = l2 >= 0 ? b[l2] - '0' : 0;

            int temp = n1 + n2 + carry;
            carry = temp / 2;
            temp = temp % 2;

            l1--;
            l2--;

            ans.push_back(temp + '0');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
