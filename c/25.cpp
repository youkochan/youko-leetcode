/**
 * 25. Reverse Nodes in k-Group
 */

/**
 * Given a linked list, reverse the nodes of a linked list k at a time
 * and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes
 * in the end should remain as it is.
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        if (head == nullptr)
            return nullptr;
        ListNode *next;
        ListNode *new_head = nullptr;
        ListNode *new_tail = nullptr;

        int len = 0;
        ListNode *temp = head;
        // check the length of the list
        // if less than k, do nothing
        while (temp) {
            len ++;
            temp = temp->next;
            if (len == k) {
                break;
            }
        }
        if (len < k)
            return head;

        int count = k;
        // reverse the list
        while (head && count-- > 0) {
            next = head->next;
            head->next = nullptr;
            if (new_head == nullptr) {
                new_head = head;
                new_tail = head;
            }
            else {
                head->next = new_head;
                new_head = head;
            }
            head = next;
        }

        // reverse the remain list, and add its newhead in the tail.
        ListNode *next_step_head = reverseKGroup(head, k);
        new_tail->next = next_step_head;
        return new_head;
    }
};
