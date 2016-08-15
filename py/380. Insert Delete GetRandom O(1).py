class RandomizedSet(object):

    import random

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._s = set()
        

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        f = val in self._s
        self._s.add(val)
        return not f

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        f = val in self._s
        if f:
            self._s.remove(val)
        return f

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        idx = random.randint(1, len(self._s))
        for e in self._s:
            result = e
            idx -= 1
            if idx == 0:
                break
        return result
        

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
