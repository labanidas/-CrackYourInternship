class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> count(26, 0);
        string result = "";

        for (char c : s) {
            count[c - 'a']++;
            if (count[c - 'a'] > (n + 1) / 2)
                return "";
        }

        priority_queue<pair<int, int>> pq; // max heap

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'])
                pq.push({count[ch - 'a'], ch});
        }

        while (pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            result += p1.second;
            result += p2.second;

            p1.first--;
            p2.first--;

            if (p1.first > 0)
                pq.push({p1.first, p1.second});
            if (p2.first > 0)
                pq.push({p2.first, p2.second});
        }

        if (pq.size()) {
            auto p = pq.top();
            pq.pop();
            result += p.second;
        }

        return result;
    }
};
