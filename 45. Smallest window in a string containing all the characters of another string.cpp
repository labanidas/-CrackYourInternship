string smallestWindow(string s, string p) {
    int n = s.length();
    int m = p.length();
    
    if (m > n) return "-1";

    vector<int> mp_target(128, 0);
    vector<int> mp_curr(128, 0);
    
    for (char c : p) mp_target[c]++;

    int required = 0, formed = 0;
    for (int count : mp_target) if (count > 0) required++;

    int left = 0, right = 0;
    int minLength = INT_MAX;
    int minLeft = 0;

    while (right < n) {
        char c = s[right];
        mp_curr[c]++;

        if (mp_target[c] > 0 && mp_curr[c] == mp_target[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            if (minLength > right - left + 1) {
                minLength = right - left + 1;
                minLeft = left;
            }

            char lc = s[left];
            mp_curr[lc]--;
            if (mp_target[lc] > 0 && mp_curr[lc] < mp_target[lc]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return minLength == INT_MAX ? "-1" : s.substr(minLeft, minLength);
}
