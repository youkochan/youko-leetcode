#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <climits>
#include <map>
#include <set>

using namespace std;

// ǰ׺�������ݽṹ
class TrieTreeNode {
public:
    int count;                      // ���Ա���ǰ׺����ǰ�ַ������ִ���
    map<char, TrieTreeNode*> next;  // ���Ա���ǰ׺����һ�����ڵ�

    TrieTreeNode(): count(0) {}
    TrieTreeNode(char c): count(0) {}

    // ����������ڵ㣬��������ӵĽڵ�
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

// ���ڴ�ӡǰ׺��
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

// DFS �ݹ�����м�¼���ս����Ŀ
// ͬʱҪע�������һ���ַ������ɹ�����Ӧ�ðѵ�ǰ�ڵ����һ������
// �Ӷ���֤������ᱻ�ظ����
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
