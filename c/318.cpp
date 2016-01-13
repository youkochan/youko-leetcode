/**
 * Maximum Product of Word Lengths
 * https://leetcode.com/problems/maximum-product-of-word-lengths/
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (!n)
            return 0;
        vector<long long> bitmaps;
        for (string &s : words) {
            long long bitmap = 0;
            for (char &c : s) {
                bitmap |= (0x01 << (c - 'a'));
            }
            bitmaps.push_back(bitmap);
        }
        int result = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int n1 = words[i].size();
                int n2 = words[j].size();
                if (n1 * n2 > result && !(bitmaps[i] & bitmaps[j])) {
                    result = n1 * n2;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    Solution s;
    cout << s.maxProduct(words) << endl;
    return 0;
}
