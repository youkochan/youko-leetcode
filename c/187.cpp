#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    unsigned int trans(char c) {
        if (c == 'A')
            return 0;
        if (c == 'C')
            return 1;
        if (c == 'G')
            return 2;
        if (c == 'T')
            return 3;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        set<int> dup;
        set<int> tag;
        if (s.size() < 10)
            return result;
        unsigned int num = 0x00;
        for (int i = 0; i <= 9; i ++) {
            num = (num << 2) & 0x000FFFFF | trans(s[i]);
        }
        dup.insert(num);
        //cout << "num:" << num << endl;
        for (int i = 10; i < s.size(); i ++) {
            num = (num << 2) & 0x000FFFFF | trans(s[i]);
            //cout << "num:" << num << endl;
            if (dup.find(num) != dup.end() && tag.find(num) == tag.end()) {
                result.push_back(s.substr(i-9, 10));
                tag.insert(num);
            }
            else
                dup.insert(num);
        }
        return result;
    }
};

int main() {
    string str = "GAGAGAGAGAGA";
    Solution s;
    vector<string> result = s.findRepeatedDnaSequences(str);
    for (auto ss : result)
        cout << ss << endl;
    return 0;
}
