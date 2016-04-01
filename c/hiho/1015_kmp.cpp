#include <iostream>
#include <vector>

using namespace std;

void getNext(vector<int>& next, string& p) {
    int plen = p.size();
    next[0] = -1;
    int k = -1;    // 前缀的最后的idx
    int j = 0;     // 后缀的最后的idx
    while (j < plen) {
        if (k == -1 || p[k] == p[j]) {
            k ++;
            j ++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
}

int kmp(string& s, string& p) {
    int slen = s.size();
    int plen = p.size();
    if (plen > slen) {
        return 0;
    }
    vector<int> next(p.size());
    getNext(next, p);
    int count = 0;
    int sidx = 0, pidx = 0;
    while (sidx < slen) {
        //cout << "pidx,sidx:" << pidx << " " << sidx << endl;
        if (pidx == plen) {
            count += 1;
            pidx = next[pidx-1];
        }
        else if (pidx == -1) {
            pidx ++;
            sidx ++;
        }
        else if (s[sidx] == p[pidx]) {
            sidx ++;
            pidx ++;
        }
        else {
            pidx = next[pidx];
        }
    }
    if (pidx == plen)
        count ++;
    return count;
}

int main() {
    int t_count = 0;
    cin >> t_count;

    while (t_count-- > 0) {
        string p, s;
        cin >> p;
        cin.get();
        cin >> s;
        cin.get();
        //cout << "-------" << endl;
        //cout << "s:" << s << endl;
        //cout << "p:" << p << endl;
        //cout << "-------" << endl;
        cout << kmp(s, p) << endl;
    }
}
