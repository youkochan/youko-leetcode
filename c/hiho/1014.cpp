/**
1014 : TrieÊ÷
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TrieTreeNode {
public:
    TrieTreeNode() {
        this->n = 0;
        this->tag = false;
    }

    int n;
    bool tag;
    map<char, TrieTreeNode*> _map;
};

int main() {
    int n, m;
    cin >> n;
    TrieTreeNode* root = new TrieTreeNode();
    while (n-- > 0) {
        string s;
        cin >> s;
        TrieTreeNode* p = root;
        for (int i = 0; i < s.size(); i ++) {
            char c = s[i];
            if (p->_map.find(c) != p->_map.end()) {
                p = p->_map[c];
                p->n = p->n + 1;
            }
            else {
                p->_map[c] = new TrieTreeNode();
                p = p->_map[c];
                p->n = p->n + 1;
            }
            if (i == s.size() - 1) {
                p->tag = true;
            }
        }
    }
    cin >> m;
    while (m -- > 0) {
        bool flag = true;
        string s;
        cin >> s;
        TrieTreeNode* p = root;
        for (int i = 0; i < s.size(); i ++) {
            char c = s[i];
            //cout << "c:" << c << endl;
            if (p->_map.find(c) == p->_map.end()) {
                flag = false;
                //cout << "false" << endl;
                break;
            }
            else {
                p = p->_map[c];
            }
        }
        if (!flag)
            cout << 0 << endl;
        else {
            cout << p->n << endl;
        }
    }

    return 0;
}
