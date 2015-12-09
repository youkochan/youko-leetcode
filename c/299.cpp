/**
 * Bulls and Cows
 * https://leetcode.com/problems/bulls-and-cows/
 * easy
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int size1 = secret.size();
        int size2 = guess.size();
        int ca = 0;
        int cb = 0;
        vector<char> s1;
        vector<char> s2;
        if (!size1 || !size2 || size1 != size2)
            return "";
        for (int i = 0; i < size1; i ++) {
            if (secret[i] == guess[i]) {
                ca ++;
            }
            else {
                s1.push_back(secret[i]);
                s2.push_back(guess[i]);
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int p1 = 0, p2 = 0;
        while (p1 < s1.size() && p2 < s1.size()) {
            if (s1[p1] == s2[p2]) {
                p1 ++;
                p2 ++;
                cb ++;
            }
            else if (s1[p1] > s2[p2]) {
                p2 ++;
            }
            else {
                p1 ++;
            }
        }

        string result;
        ostringstream os;
        os << ca;
        result += os.str()  + "A";
        os.str("");
        os << cb;
        result += os.str()  + "B";
        return result;
    }
};

int main() {
    Solution s;
    cout << s.getHint("1", "1");
    return 0;
}
