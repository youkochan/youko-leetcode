#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 这种解法在数据规模巨大时候会超时
class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();

        vector<vector<int>> dp(n, vector<int>(k, 0));
        int idx = 0;

        for (int i = 0; i < k; i ++)
            dp[idx][i] = costs[0][i];

        while (++idx < n) {
            for (int i = 0; i < k; i ++) {
                dp[idx][i] = INT_MAX;
                for (int j = 0; j < k; j ++) {
                    if (i != j)
                        dp[idx][i] = min(dp[idx][i], dp[idx-1][j]);
                }
                dp[idx][i] += costs[idx][i];
            }
        }

        int minResult = INT_MAX;
        for (int i = 0; i < k; i ++)
            minResult = min(minResult, dp[n-1][i]);

        return minResult;
    }
};


int main() {
    Solution s;
    vector<vector<int>> costs = {{1, 2, 3}, {1, 4, 6}};
    cout << s.minCostII(costs) << endl;
    return 0;
}
