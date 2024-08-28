class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = beginWord.size();

        map<string, vector<string>> adj;

        for (int i = 0; i < wordList.size(); i++) {
             string s = wordList[i];
            for (int j = 0; j < n; j++) {
                string intermediate = s.substr(0,j) + "*" + s.substr(j + 1);
                adj[intermediate].push_back(s);
            }
        }

        for (int i = 0; i < n; i++) {
            string s = beginWord;
            string intermediate = s.substr(0, i) + "*" + s.substr(i + 1);
            adj[intermediate].push_back(s);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            string str = q.front().first;
            int level = q.front().second;
            q.pop();

            for (int i = 0; i < n; i++) {
                string intermediate =
                    str.substr(0, i) + "*" + str.substr(i + 1);
                for (string neighbour : adj[intermediate]) {
                    if (neighbour == endWord)
                        return level + 1;
                    if (visited.count(neighbour) == 0) {
                        visited.insert(neighbour);
                        q.push({neighbour, level + 1});
                    }
                }
            }
        }

        return 0;
    }
};
