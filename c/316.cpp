/**
 * Remove Duplicate Letters
 * https://leetcode.com/problems/remove-duplicate-letters/
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.size() == 0)
            return "";
        vector<int> pos(26, INT_MAX);
        vector<int> flg(26, 0);
        for (int i = 0; i < s.size(); i ++) {
            pos[s[i] - 'a'] = i;
            flg[s[i] - 'a'] = 1;
        }
        
        
        int start = 0;
        string result = "";
        while (start < s.size()) {
            int end = INT_MAX;
            int tag1 = -1;
            int tag2 = -1;
            for (int i = 0; i < pos.size(); i ++) {
                if (pos[i] < end && pos[i] >= start) {
                    end = pos[i];
                }
            }
            if (end == INT_MAX) {
                break;
            }

            char c = 'z' + 1;
            for (int i = start; i <= end; i ++) {
                if (s[i] < c && flg[s[i] - 'a']) {
                    c = s[i];
                    tag1 = i;
                    tag2 = s[i] - 'a';
                }
            }
            if (tag1 == -1) {
                start ++;
                continue;
            }

            result += c;
            
            // cout << "=====" << endl;
            // cout << result << endl;
            // cout << start << " " << end << endl;
            // cout << tag1 << " " << tag2 << endl;

            pos[c - 'a'] = INT_MAX;
            flg[tag2] = 0;
            start = tag1 + 1;


        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.removeDuplicateLetters("bddbccd") << endl; // 2 6 7 4
}
