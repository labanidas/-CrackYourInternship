class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> tfreq;
        for (auto c : t)
            tfreq[c]++;

        unordered_map<char, int> windowFreq;

        int left = 0, right = 0;
        int required = tfreq.size(), formed = 0;

        int minLen = INT_MAX;
        int minLeft = 0, minRight = 0;

        while (right < s.size()) {
            char c = s[right];
            windowFreq[c]++;

            // character matched
            if (tfreq.find(c) != tfreq.end() && windowFreq[c] == tfreq[c]) {
                formed++;
            }

            // window shrink when all characters found
            while (left <= right && formed == required) {
                c = s[left];
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                    minRight = right;
                }

                // remove leftmost char from window
                windowFreq[c]--;
                if (tfreq.find(c) != tfreq.end() && windowFreq[c] < tfreq[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
