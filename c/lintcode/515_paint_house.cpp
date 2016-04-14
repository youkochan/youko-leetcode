class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int rsize = costs.size();
        if (rsize == 0)
            return 0;

        vector<vector<int>> dp(rsize, vector<int>(3, 0));
        int idx = 0;
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        while (++idx < rsize) {
            dp[idx][0] = min(dp[idx-1][1], dp[idx-1][2]) + costs[idx][0];
            dp[idx][1] = min(dp[idx-1][0], dp[idx-1][2]) + costs[idx][1];
            dp[idx][2] = min(dp[idx-1][0], dp[idx-1][1]) + costs[idx][2];
        }

        return min(min(dp[rsize-1][0], dp[rsize-1][1]), dp[rsize-1][2]);
    }
};
