class RandomizedCollection(object):

    import collections
    import random

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._s = collections.defaultdict(int)
        self._sum = 0

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        f = val in self._s
        self._s[val] += 1
        self._sum += 1
        return not f

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        f = val in self._s
        if f:
            self._s[val] -= 1
            self._sum -= 1
            if self._s[val] == 0:
                del self._s[val]
        return f

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        idx = random.randint(1, self._sum)
        for e in self._s:
            result = e
            idx -= self._s[e]
            if idx <= 0:
                break
        return result


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
