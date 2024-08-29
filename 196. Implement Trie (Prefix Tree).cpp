class Trie {
public:
unordered_map<string, int> word_map, prefix_map;

    Trie() {
        
    }
    
    void insert(string word) {
        word_map[word]++;

        string s = "";
        for(char c: word){
            s+= c;
            if (prefix_map[s] == 0) prefix_map[s]++;
        }
    }
    
    bool search(string word) {
        return (word_map[word]) ? 
            true : false;
    }
    
    bool startsWith(string prefix) {
        return (prefix_map[prefix]) ? 
            true : false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
