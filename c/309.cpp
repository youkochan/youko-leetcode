/**
 * Best Time to Buy and Sell Stock with Cooldown
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

/**
 * ˼·����s0[i] s1[i] s2[i] �ֱ��ʾ
 * �� i �촦�� ��δ���롱 �������롱 ���������� ״̬ʱ�ܻ�õ��������
 * ��֪��
 * s0[i] Ϊ s0[i-1] �� s2[i-1] �е����ֵ
 * s1[i] Ϊ s1[i-1] �� s0[i-1] - prices[i] �е����ֵ����Ϊ�� i ����������������
 * s2[i] Ϊ s1[i-1] + prices[i]����Ϊ��Ҫ�� i ��ﵽ s2 ״̬��
 *      ������ s1 ״ִ̬������������������ s2 ״̬���� s2 ״̬
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
