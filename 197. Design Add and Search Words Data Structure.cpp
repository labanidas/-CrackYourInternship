class WordDictionary {
public:
    vector<string> words;

    WordDictionary() {}

    void addWord(string word) { words.push_back(word); }

    bool search(string word) {

        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == word.size()) {
                int count = 0;
                for (int j = 0; j < word.size(); j++) {
                    if (words[i][j] == word[j] || word[j] == '.') {
                        count++;
                    } else {
                        count = 0;
                        break;
                    }
                }
                if (count == word.size())
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
