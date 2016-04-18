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
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        if (k == 1)
            return head;
        if (head == nullptr)
            return nullptr;
        ListNode *next;
        ListNode *new_head = nullptr;
        ListNode *new_tail = nullptr;

        int len = 0;
        ListNode *temp = head;
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

        ListNode *next_step_head = reverseKGroup(head, k);
        new_tail->next = next_step_head;
        return new_head;
    }
};
