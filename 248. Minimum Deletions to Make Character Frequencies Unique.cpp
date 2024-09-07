class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        int deletions = 0;

        for (char c : s) {
            freq[c]++;
        }

        unordered_set<int> used_freq;

        for (auto it : freq) {
            int curr_freq = it.second;

            while (used_freq.count(curr_freq) > 0 && curr_freq > 0) {
                curr_freq--;
                deletions++;
            }
            
            used_freq.insert(curr_freq);
        }
        return deletions;
    }
};
