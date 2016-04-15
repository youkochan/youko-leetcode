#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        vector<int> dp(s.size(), 0);
        if (s.size() == 0)
            return 0;

        if (s[0] == '0')
            return 0;
        dp[0] = 1;

        for (int i = 1; i < s.size(); i ++) {
            int temp = 0;
            if (s[i] != '0')
                temp += dp[i-1];
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')) {
                temp += i - 2 > 0 ? dp[i-2] : 1;
            }
            // can not be decoded
            if (temp == 0)
                return 0;
            dp[i] = temp;
        }

        return dp[s.size()-1];
    }
};

int main() {
    Solution s;
    string ss = "26";
    cout << s.numDecodings(ss) << endl;
}
