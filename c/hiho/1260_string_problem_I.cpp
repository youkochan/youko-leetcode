#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <climits>
#include <map>
#include <set>

using namespace std;

// 前缀树的数据结构
class TrieTreeNode {
public:
    int count;                      // 用以保存前缀树当前字符串出现次数
    map<char, TrieTreeNode*> next;  // 用以保存前缀树下一个树节点

    TrieTreeNode(): count(0) {}
    TrieTreeNode(char c): count(0) {}

    // 用于添加树节点，返回新添加的节点
    TrieTreeNode *addTrieTreeNode(char c) {
        if (next.find(c) != next.end())
            return next[c];
        else {
            TrieTreeNode *newNode = new TrieTreeNode(c);
            next[c] = newNode;
            return newNode;
        }
    }
};

// 用于打印前缀树
void printTrieTree(TrieTreeNode *root, string s) {
    if (root == nullptr)
        return;
    if (root->count) {
        cout << s << ":" << root->count << endl;
    }
    map<char, TrieTreeNode*>::iterator it = root->next.begin();
    while (it != root->next.end()) {
        printTrieTree(it->second, s + it->first);
        it ++;
    }
    return;
}

// DFS 递归过程中记录最终结果数目
// 同时要注意如果有一个字符串检测成功，则应该把当前节点加入一个集合
// 从而保证结果不会被重复添加
void check(TrieTreeNode *node, string &s, int pos, int flag, int &result, set<TrieTreeNode*> &mSet) {
    if (pos == s.size() && flag && node->count) {
        if (mSet.find(node) == mSet.end()) {
            mSet.insert(node);
            result ++;
        }
        return;
    }
    if (pos != s.size() &&
        node->next.find(s[pos]) != node->next.end())
        check(node->next[s[pos]], s, pos+1, flag, result, mSet);
    if (!flag) {
        map<char, TrieTreeNode*>::iterator it = node->next.begin();
        while (it != node->next.end()) {
            check(it->second, s, pos, 1, result, mSet);
            it ++;
        }
    }
    return;
}

int main() {
    int strCount = 0;
    int askCount = 0;
    cin >> strCount >> askCount;

    TrieTreeNode *root = new TrieTreeNode();
    while (strCount --) {
        string s;
        cin >> s;
        cin.get();
        //cout << s << ", len:" << s.size() << endl;
        TrieTreeNode *tempNode = root;
        for (int i = 0; i < s.size(); i ++) {
            tempNode = tempNode->addTrieTreeNode(s[i]);
        }
        tempNode->count ++;
    }
    //printTrieTree(root, "");

    while (askCount --) {
        string s;
        cin >> s;
        cin.get();
        int result = 0;
        set<TrieTreeNode*> mSet;
        check(root, s, 0, 0, result, mSet);
        cout << result << endl;
    }

    return 0;
}
