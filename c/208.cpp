/**
 * Implement Trie (Prefix Tree)
 * https://leetcode.com/problems/implement-trie-prefix-tree/
 */

class TrieNode {
public:
    bool isend;
    map<char, TrieNode*> hashmap;

    // Initialize your data structure here.
    TrieNode() {
        isend = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (char c : word) {
            if (p->hashmap.find(c) == p->hashmap.end()) {
                TrieNode *temp = new TrieNode();
                p->hashmap[c] = temp;
                p = temp;
            }
            else {
                p = p->hashmap[c];
            }
        }
        p->isend = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (char c : word) {
            if (p->hashmap.find(c) == p->hashmap.end()) {
                return false;
            }
            else {
                p = p->hashmap[c];
            }
        }
        return p->isend;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c : prefix) {
            if (p->hashmap.find(c) == p->hashmap.end()) {
                return false;
            }
            else {
                p = p->hashmap[c];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
