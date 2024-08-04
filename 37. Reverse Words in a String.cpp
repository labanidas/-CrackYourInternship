class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();
        int start = 0, end = n - 1;
        string result = "";
        string curr_word = "";
        vector<string> words;

        // omit spaces
        while (start < end && s[start] == ' ')
            start++;
        while (end > start && s[end] == ' ')
            end--;

        for (int i = start; i <= end; i++) {
            char c = s[i];

            if (c != ' ') {
                curr_word += c; // form word
            } else if (!curr_word.empty()) {
                words.push_back(curr_word);
                curr_word = "";
            }
        }
        if (!curr_word.empty())
            words.push_back(curr_word);

        reverse(words.begin(), words.end()); //  reverse words

        for (int i = 0; i < words.size(); i++) {
            if (i > 0)
                result += " ";
            result += words[i];
        }

        return result;
    }
};
