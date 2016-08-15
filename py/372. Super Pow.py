# Your task is to calculate ab mod 1337 where a is a positive integer
# and b is an extremely large positive integer given in the form of an array.

class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        a = a % 1337
        t = 1
        for exp in b:
            t = reduce(lambda x, y: (x * y) % 1337, [t] * 10 + [a] * exp)

        return t
