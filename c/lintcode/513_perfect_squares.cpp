#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

// 动态规划，使用 dp[i] 表示 i 需要几个数字组合
// 然后从某个数字的开平方后的最大因子开始找最小步数即可
class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i ++) {
            int factor = floor(sqrt(i));
            dp[i] = INT_MAX;
            for (int j = 1; j <= factor; j ++) {
                //cout << dp[i-j*j] << endl;
                dp[i] = min(dp[i], dp[i-j*j]);
            }
            dp[i] += 1;
        }

        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
}
