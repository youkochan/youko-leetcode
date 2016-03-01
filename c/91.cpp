#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;

        // dp[i] 表示长度为 i 的s的前缀可以得到的最大解码方案数
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= s.size(); i ++) {
            if (s[i-1] > '0' && s[i-1] <= '9')
                dp[i] += dp[i-1];

            string t = s.substr(i-2, 2);
            if (t >= "10" && t <= "26")
                dp[i] += dp[i-2];
        }

        return dp[s.size()];
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("11") << endl;
    return 0;
}
