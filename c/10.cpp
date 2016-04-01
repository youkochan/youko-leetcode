#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool check(string &s, int sidx, string &p, int pidx) {
        if (sidx == -1 && pidx == -1)
            return true;
        if (sidx != -1 && pidx == -1)
            return false;
        if (sidx == -1 && pidx != -1) {
            // s:
            // p: c*c*c*
            if (p[pidx] == '*')
                return check(s, sidx, p, pidx-2);
            return false;
        }

        if (p[pidx] != '*') {
            if (p[pidx] == '.')
                return check(s, sidx-1, p, pidx-1);
            if (p[pidx] == s[sidx])
                return check(s, sidx-1, p, pidx-1);
            return false;
        }
        else {
            // s: abccd
            // p: abc*d
            bool tag = false;
            if (p[pidx-1] == s[sidx] || p[pidx-1] == '.') {
                tag = check(s, sidx-1, p, pidx);
            }
            if (tag)
                return true;
            return check(s, sidx, p, pidx-2);
        }
    }

public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        return check(s, slen, p, plen);
    }
};

int main() {
    Solution s;
    cout << (s.isMatch("aa","a") ? "true" : "false") << endl;
    cout << (s.isMatch("aab", "c*a*b") ? "true" : "false") << endl;
    return 0;
}
