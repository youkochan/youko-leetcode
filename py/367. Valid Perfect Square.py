class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        l = 1
        r = num
        while l <= r:
            m = (l + r) / 2
            n = m ** 2
            if n == num:
                return True
            elif n < num:
                l = m + 1
            else:
                r = m - 1
        
        return False
