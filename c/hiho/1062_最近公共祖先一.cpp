#include <iostream>
#include <algorithm>
#include <map>
#include <set>

// �Բۡ��������ڣ�����ѯ�ʵ�ʱ�����һ��û�г��ֹ������֣�
// ���� yeqing yeqing������yeqing yeqing�Ĺ�������Ҳ��yeqing������ҲӦ�����yeqing
// �����˺þ�
// �������Ǿ��������⣬��Ϊ�������������Ҫ���Լ��ĸ��׿�ʼ����ѽ����
// �ܾ����Լ����Լ��������ֹ۵�ͺ��ѽ��ܡ�

using namespace std;

class NameNode {
public:
    string name;
    NameNode *father;

    NameNode(string &_name, NameNode *_ptr) {
        name = _name;
        father = _ptr;
    }
};

int main() {
    map<string, NameNode*> nameMap;

    int N, Q;
    cin >> N;
    while (N -- ) {
        string s;
        cin >> s;
        cin.get();
        NameNode *fatherNode = nullptr;
        NameNode *sonNode = nullptr;
        if (nameMap.find(s) != nameMap.end())
            fatherNode = nameMap[s];
        else {
            fatherNode = new NameNode(s, nullptr);
            nameMap[s] = fatherNode;
        }

        cin >> s;
        cin.get();
        if (nameMap.find(s) != nameMap.end()) {
            sonNode = nameMap[s];
            sonNode->father = fatherNode;
        }
        else {
            sonNode = new NameNode(s, fatherNode);
            nameMap[s] = sonNode;
        }
    }

    cin >> Q;
    while (Q --) {
        set<NameNode*> nameSet;
        string s1, s2;
        cin >> s1;
        cin.get();
        cin >> s2;
        cin.get();

        NameNode *node1 = nullptr;
        NameNode *node2 = nullptr;

        if (nameMap.find(s1) != nameMap.end())
            node1 = nameMap[s1];
        if (nameMap.find(s2) != nameMap.end())
            node2 = nameMap[s2];

        if (s1 == s2) {
            cout << s1 << endl;
        }
        else if (node1 && node2) {
            int flag = false;
            NameNode *t1 = node1;
            NameNode *t2 = node2;
            while (t1 != nullptr) {
                nameSet.insert(t1);
                t1 = t1->father;
            }
            while (t2 != nullptr) {
                if (nameSet.find(t2) != nameSet.end()) {
                    cout << t2->name << endl;
                    flag = true;
                    break;
                }
                t2 = t2->father;
            }
            if (!flag)
                cout << -1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
