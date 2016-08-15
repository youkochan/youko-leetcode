class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s = {-1: set()}
        for x in sorted(nums):
            s[x] = max((s[d] for d in s if x % d == 0), key=len) | {x}

        return list(max(s.values(), key=len))
