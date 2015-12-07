#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<char, string> _map_c_to_s;
    map<string, char> _map_s_to_c;

public:
    bool wordPattern(string pattern, string str) {
        int pos = 0;
        for (int i = 0; i < pattern.size(); i ++) {
            char c = pattern[i];
            string s;
            while (pos <= str.size() - 1 && str[pos] != ' ') {
                s = s + str[pos++];
            }
            pos ++;
            
            if (s.size() == 0) {
                return false;
            }

            // cout << c << " " << s << endl;

            if (_map_c_to_s.find(c) == _map_c_to_s.end() &&
                _map_s_to_c.find(s) == _map_s_to_c.end()) {
                _map_c_to_s[c] = s;
                _map_s_to_c[s] = c;
            }
            else if (_map_c_to_s.find(c) != _map_c_to_s.end() &&
                     _map_s_to_c.find(s) != _map_s_to_c.end()) {
                if (_map_s_to_c[s] != c || _map_c_to_s[c] != s) {
                    // cout << "test1" << endl;
                    return false;
                }
            }
            else {
                cout << "test2" << endl;
                return false;
            }
        }
        if (pos != str.size() + 1) {
            // cout << pos << " " << str.size() << endl;
            return false;
        }
        return true;
    }
};

int main () {

    string s1 = "abba";
    string s2 = "cat dog dog";

    Solution s;

    if (s.wordPattern(s1, s2))
        cout << "yes" << endl;
    else
        cout << "fuck" << endl;

}