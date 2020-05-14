class Trie {
  private:
    unordered_map<char, Trie *> children;
    bool end = false;

  public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for (char &ch : word) {
            if (!node->children.count(ch))
                node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = this;
        for (char &ch : word) {
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto node = this;
        for (char &ch : prefix) {
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
