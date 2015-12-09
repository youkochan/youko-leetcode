/**
 * Best Time to Buy and Sell Stock with Cooldown
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

/**
 * 思路，用s0[i] s1[i] s2[i] 分别表示
 * 第 i 天处于 “未买入” “已买入” “已卖出” 状态时能获得的最大收益
 * 可知，
 * s0[i] 为 s0[i-1] 与 s2[i-1] 中的最大值
 * s1[i] 为 s1[i-1] 与 s0[i-1] - prices[i] 中的最大值。因为第 i 天进行了买入操作。
 * s2[i] 为 s1[i-1] + prices[i]，因为需要第 i 天达到 s2 状态，
 *      则必须从 s1 状态执行卖出操作，不能由 s2 状态到达 s2 状态
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;

        vector<int> s0(n);
        vector<int> s1(n);
        vector<int> s2(n);

        s0[0] = 0;
        s1[0] = - prices[0];
        s2[0] = INT_MIN;

        for (int i = 1; i < n; i ++) {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }

        return max(s0[n-1], max(s1[n-1], s2[n-1]));
    }
};

int main() {
    Solution s;
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(0);
    prices.push_back(2);

    cout << s.maxProfit(prices) << endl;

    return 0;
}
