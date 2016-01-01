/**
 * Add and Search Word - Data structure design
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/
 */

/* 解题思路使用前缀树 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class PreTreeNode {
public:
    int count;
    map<char, PreTreeNode*> _map;
};

class WordDictionary {
public:
    PreTreeNode *root;

    WordDictionary() {
        root = new PreTreeNode();
    }

    void _addWord(PreTreeNode *node, string &s, int pos) {
        if (pos == s.size()) {
            node->count ++;
            return;
        }
        char c = s[pos];

        if (node->_map.find(c) == node->_map.end()) {
            PreTreeNode *newPreTreeNode = new PreTreeNode();
            (node->_map)[c] = newPreTreeNode;
            _addWord(newPreTreeNode, s, pos+1);
        }
        else {
            _addWord((node->_map)[c], s, pos+1);
        }
    }

    bool _search(PreTreeNode *node, string &s, int pos) {
        if (pos == s.size()) {
            if (node->count)
                return true;
            else
                return false;
        }
        char c = s[pos];
        if (c == '.') {
            map<char, PreTreeNode*>::iterator it = node->_map.begin();
            for (it; it != node->_map.end(); it ++) {
                PreTreeNode* tp = it->second;
                if (_search(tp, s, pos+1))
                    return true;
            }
            return false;
        }
        else {
            if (node->_map.find(c) == node->_map.end()) {
                return false;
            }
            return _search((node->_map)[c], s, pos+1);
        }
    }


    // Adds a word into the data structure.
    void addWord(string word) {
        _addWord(root, word, 0);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return _search(root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("and");
    wd.search("a") ? cout << "yes" << endl : cout << "no" << endl;

    return 0;
}
