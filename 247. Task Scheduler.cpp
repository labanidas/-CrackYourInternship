class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        if (p == 0)
            return n;

        int counter[26] = {0};

        for (char c : tasks) {
            counter[c - 'A']++;
        }

        sort(begin(counter), end(counter));

        int chunks = counter[25] - 1;
        int idol_spots = chunks * p;

        for (int i = 24; i >= 0; i--) {
            idol_spots -= min(chunks, counter[i]);
        }

        if (idol_spots > 0)
            return n + idol_spots;

        return n;
    }
};
