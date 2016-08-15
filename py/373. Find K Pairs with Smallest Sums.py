class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        len1 = len(nums1)
        len2 = len(nums2)

        rlist = []
        candidate = set()
        selected = set()

        if (len1 != 0 and len2 != 0):
            candidate.add((nums1[0] + nums2[0], 0, 0))

        while k != 0 and len(candidate) != 0:
            smallest = min(candidate)
            k -= 1
            idx1 = smallest[1]
            idx2 = smallest[2]

            candidate.remove(smallest)
            selected.add(smallest)
            rlist.append([nums1[idx1], nums2[idx2]])

            if idx2 + 1 < len2 and (idx2 - 1 < 0 or (nums1[idx1] + nums2[idx2-1], idx1, idx2 - 1) in selected):
                candidate.add((nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1))
            if idx1 + 1 < len1 and (idx1 - 1 < 0 or (nums1[idx1-1] + nums2[idx2], idx1 - 1, idx2) in selected):
                candidate.add((nums1[idx1 + 1] + nums2[idx2], idx1 + 1, idx2))

        return rlist
