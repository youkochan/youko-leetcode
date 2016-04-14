#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

// ��̬�滮��ʹ�� dp[i] ��ʾ i ��Ҫ�����������
// Ȼ���ĳ�����ֵĿ�ƽ�����������ӿ�ʼ����С��������
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
