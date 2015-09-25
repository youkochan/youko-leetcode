/**
 * Given two numbers represented as strings,
 * return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    string add(string s1, string s2) {
        if(s1 == "0")
            return s2;
        if(s2 == "0")
            return s1;

        string s;
        int len1 = s1.size();
        int len2 = s2.size();
        int len = max(len1, len2);
        int d = 0;

        for(int i = 0; i <= len-1; i ++) {
            int pos1 = len1 - 1 - i;
            int pos2 = len2 - 1 - i;
            int r = 0;
            if(pos1 >= 0 && pos2 >= 0)
                r = (s1[pos1] - '0') + (s2[pos2] - '0') + d;
            else if(pos1 < 0)
                r = (s2[pos2] - '0') + d;
            else
                r = (s1[pos1] - '0') + d;

            d = r / 10;
            r = r % 10;
            s = (char)(r + '0') + s;
        }
        if(d)
            s = '1' + s;
        return s;
    }

    string mul(string s, char c) {
        //cout << "mul:" << s << " and " << c << endl;
        if(c == '0')
            return "0";
        if(s == "0")
            return "0";
        int d = 0;
        for(int i = s.size()-1; i >= 0; i --) {
            int r = (c - '0') * (s[i] - '0') + d;
            d = r / 10;
            r = r % 10;
            s[i] = r + '0';
        }
        if(d) {
            s = (char)(d + '0') + s;
        }
        return s;
    }

public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string result = "0";
        for(int i = 0; i < num2.size(); i ++) {
            string tmp = mul(num1, num2[num2.size()-1-i]);
            cout << "tmp:" << tmp << endl;
            int zeroNum = i;
            while(zeroNum-->0) {
                tmp = tmp + '0';
            }
            cout << "tmp:" << tmp << endl;
            result = add(result, tmp);
        }

        return result;
    }
};

int main() {
    string s1 = "1121";
    string s2 = "0";
    Solution s;

    cout << s.multiply(s1, s2) << endl;

    return 0;
}
