class Solution(object):
    
    def _f(self, d, x):
        d[x] += 1
    
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        import collections
        from operator import and_
        
        d1 = collections.defaultdict(int)
        d2 = collections.defaultdict(int)
        map(lambda x: self._f(d1, x), magazine)
        map(lambda x: self._f(d2, x), ransomNote)
        
        return reduce(and_, map(lambda x: d1[x] >= d2[x], d2), True)
