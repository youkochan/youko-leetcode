# Given a non-negative integer n, count all numbers with unique digits

class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        if n > 10:
            return 0
        
        s = 0
        r = 1
        for i in range(1, n + 1):
            # for the first number, it can be [0, 1, 2, ..., 9]
            if i == 1:
                r = r * 10
            # for the second number, it can not start with 0, so r - 1
            elif i == 2:
                r = (r - 1) * 9
            # for the other numbers, (i-1) numbers have been chosen
            else:
                r = r * (10 - i + 1)
            s += r
        
        return s
