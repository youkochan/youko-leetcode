class Solution(object):

    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        import sys

        dp = [[0 for _ in range(0, n + 1)] for _ in range(0, n + 1)]
        # for len less than 3, just choose the smaller number
        for i in range(0, n):
            dp[i][i+1] = i

        # len: [3, 4, 5, ..., n]
        for len in range(3, n + 1):
            # i: [1, 2, 3, ..., n - (len - 1)]
            for i in range(1, n - len + 2):
                j = i + len - 1
                dp[i][j] = reduce(min, map(lambda k: k + max(dp[i][k-1], dp[k+1][j]), range(i + 1, j)), sys.maxint)

        return dp[1][n]


if __name__ == '__main__':
    s = Solution()
    s.getMoneyAmount(3)
