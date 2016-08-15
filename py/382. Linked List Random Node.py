# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    import random

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self._len = 1
        node = head
        while node.next:
            self._len += 1
            node = node.next
        self._head = head

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        step = random.randint(0, self._len - 1)
        node = self._head
        while step != 0:
            node = node.next
            step -= 1
        return node.val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
