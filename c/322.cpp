/**
 * Coin Change
 * https://leetcode.com/problems/coin-change/
 */

/*
 * 思路：动态规划更新凑成每一个amount需要的最小硬币数目
 * dp[i] 表示凑成 i 需要的最小数目 i 从 0 递增到 amount
 * dp除了0以外都初始化为 -1
 * 若循环进行到 i 时，dp[i] 仍为 -1 则说明不可达
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
