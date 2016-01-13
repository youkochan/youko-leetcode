/**
 * Coin Change
 * https://leetcode.com/problems/coin-change/
 */

/*
 * ˼·����̬�滮���´ճ�ÿһ��amount��Ҫ����СӲ����Ŀ
 * dp[i] ��ʾ�ճ� i ��Ҫ����С��Ŀ i �� 0 ������ amount
 * dp����0���ⶼ��ʼ��Ϊ -1
 * ��ѭ�����е� i ʱ��dp[i] ��Ϊ -1 ��˵�����ɴ�
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 0; i <= amount; i ++) {
            if (dp[i] < 0)
                continue;
            for (int j = 0; j < coins.size(); j ++) {
                if (i + coins[j] <= amount && (dp[i+coins[j]] < 0 || dp[i+coins[j]] > dp[i] + 1))
                    dp[i+coins[j]] = dp[i] + 1;
            }
        }

        return dp[amount];
    }
};
