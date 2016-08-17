class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        numset = set(nums)
        dp = [0] * (target + 1)
        dp[0] = 1
        
        for i in range(1, target + 1):
            for num in numset:
                if i >= num:
                    dp[i] += dp[i - num]
        
        return dp[-1]
