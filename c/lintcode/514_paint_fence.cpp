class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        // dp[0][i] no adjacent
        // dp[1][i] adjacent
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = k;
        dp[1][0] = 0;
        int idx = 0;
        while (++ idx < n) {
            // ��������Ŀ�����ˣ���Ϊ�����з���ֻ���ڽ�һ��
            // ��ʵ��Ŀ��˼�����ֻ�������������ڽ�
            dp[0][idx] = (k-1) * dp[1][idx-1] + (k-1) * dp[0][idx-1];
            dp[1][idx] = dp[0][idx-1];
        }
        return dp[0][n-1] + dp[1][n-1];
    }
};
