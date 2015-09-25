/**
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    void find(vector<string> &ret, string prefix, string &digits, int pos) {
        cout << "TEST" << endl;
        if(pos == digits.size()) {
            ret.push_back(prefix);
            return;
        }
        switch(digits[pos]) {
            case '1':
            case '0':
                find(ret, prefix, digits, pos+1);
                break;
            case '2':
                find(ret, prefix+'a', digits, pos+1);
                find(ret, prefix+'b', digits, pos+1);
                find(ret, prefix+'c', digits, pos+1);
                break;
            case '3':
                find(ret, prefix+'d', digits, pos+1);
                find(ret, prefix+'e', digits, pos+1);
                find(ret, prefix+'f', digits, pos+1);
                break;
            case '4':
                find(ret, prefix+'g', digits, pos+1);
                find(ret, prefix+'h', digits, pos+1);
                find(ret, prefix+'i', digits, pos+1);
                break;
            case '5':
                find(ret, prefix+'j', digits, pos+1);
                find(ret, prefix+'k', digits, pos+1);
                find(ret, prefix+'l', digits, pos+1);
                break;
            case '6':
                find(ret, prefix+'m', digits, pos+1);
                find(ret, prefix+'n', digits, pos+1);
                find(ret, prefix+'o', digits, pos+1);
                break;
            case '7':
                find(ret, prefix+'p', digits, pos+1);
                find(ret, prefix+'q', digits, pos+1);
                find(ret, prefix+'r', digits, pos+1);
                find(ret, prefix+'s', digits, pos+1);
                break;
            case '8':
                find(ret, prefix+'t', digits, pos+1);
                find(ret, prefix+'u', digits, pos+1);
                find(ret, prefix+'v', digits, pos+1);
                break;
            case '9':
                find(ret, prefix+'w', digits, pos+1);
                find(ret, prefix+'x', digits, pos+1);
                find(ret, prefix+'y', digits, pos+1);
                find(ret, prefix+'z', digits, pos+1);
                break;
            default:
                cout << "test" << endl;
                break;
        }
        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;

        find(ret, "", digits, 0);

        return ret;
    }
};


int main() {
    Solution s;
    vector<string> ret = s.letterCombinations("2");

    for(int i = 0; i < ret.size(); i ++) {
        cout << ret[i] << endl;
    }

    return 0;
}
