class Solution(object):
    
    import random

    def __init__(self, nums):
        """
        :type nums: List[int]
        :type size: int
        """
        self._origin_list = list(nums)
        self._present_list = list(nums)
        
    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return list(self._origin_list)

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        random.shuffle(self._present_list)
        return list(self._present_list)


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
