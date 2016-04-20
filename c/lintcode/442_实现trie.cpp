/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
private:
    map<char, TrieNode*> _map;
    bool _tag;

public:
    // Initialize your data structure here.
    TrieNode() {
        _tag = false;
    }
    
    bool find(string &s, int pos) {
        if (pos == s.size())
            return _tag;
        if (_map.find(s[pos]) == _map.end())
            return false;
        else
            return _map[s[pos]]->find(s, pos+1);
    }
    
    void insert(string &s, int pos) {
        if (pos == s.size()) {
            _tag = true;
            return;
        }
        if (_map.find(s[pos]) == _map.end()) {
            TrieNode* _node = new TrieNode();
            _map[s[pos]] = _node;
            _node->insert(s, pos+1);
        }
        else {
            _map[s[pos]]->insert(s, pos+1);
        }
    }
    
    bool startsWith(string &s, int pos) {
        if (pos == s.size())
            return true;
        if (_map.find(s[pos]) == _map.end())
            return false;
        else
            return _map[s[pos]]->startsWith(s, pos+1);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        return root->insert(word, 0);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return root->find(word, 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return root->startsWith(prefix, 0);
    }

private:
    TrieNode* root;
};
