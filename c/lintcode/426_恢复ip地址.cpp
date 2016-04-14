#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

// 需要注意的是除了单个的0,其他不允许0开头
class Solution {
public:
    bool check(string s) {
        return s <= "255";
    }

    void findIpAddresses(string &s,
                        int pos,
                        int count,
                        string str,
                        vector<string> &results) {
        if (pos == s.size() && count == 4) {
            results.push_back(str);
            return;
        }
        if (count == 4 || pos >= s.size())
            return;

        if (str.size())
            str += '.';

        string temp;
        temp = s.substr(pos, 1);
        findIpAddresses(s, pos+1, count+1, str+temp, results);

        if (s[pos] != '0' && pos <= s.size() - 2) {
            temp = s.substr(pos, 2);
            findIpAddresses(s, pos+2, count+1, str+temp, results);
        }

        if (s[pos] != '0' && pos <= s.size() - 3) {
            temp = s.substr(pos, 3);
            if (check(temp))
                findIpAddresses(s, pos+3, count+1, str+temp, results);
        }

        return;
    }

    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> results;
        findIpAddresses(s, 0, 0, "", results);

        return results;
    }
};

int main() {
    Solution s;
    string ss = "010010";
    vector<string> results = s.restoreIpAddresses(ss);

    for (auto _s : results)
        cout << _s << endl;
}
