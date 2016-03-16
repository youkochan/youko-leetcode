#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getNext(string p, vector<int>& next) {
    int plen = static_cast<int>(p.size());
    int k = -1;
    int j = 0;
    next[0] = -1;
    while (j < plen - 1) {
        if (k == -1 || p[k] == p[j]) {
            ++k;
            ++j;
            // 采用优化的next数组方式，当发现下一个匹配肯定失败时，
            // 继续往前寻找next
            if (p[k] != p[j])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
            k = next[k];
    }
    return;
}

/*
 kmp算法，匹配成功时返回匹配字串下标
 否则返回 -1
 */
int kmp(string s, string p) {
    if (s.size() == 0 || p.size() == 0) {
        return -1;
    }
    vector<int> next(p.size());
    getNext(p, next);
    int slen = static_cast<int>(s.size());
    int plen = static_cast<int>(p.size());
    int i = 0, j = 0;
    while (i < slen && j < plen) {
        if (j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }
    if (j == plen)
        return i - j;
    else
        return -1;
}

int main() {
    string s = "your mage gets mine!";
    string p = "mage";

    cout << kmp(s, p) << endl;

    return 0;
}
