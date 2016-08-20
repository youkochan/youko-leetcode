class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        from collections import defaultdict
        
        d1 = defaultdict(int)
        d2 = defaultdict(int)
        s = set()
        for e in nums1:
            d1[e] += 1
            s.add(e)
        for e in nums2:
            d2[e] += 1
            s.add(e)
        
        # print d1, d2
        
        result = []
        for _ in s:
            result += [_ for x in range(0, min(d1[_], d2[_]))]
        return result
