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
     * @param v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode *n1 = nullptr;
        ListNode *p1 = nullptr;
        ListNode *n2 = nullptr;
        ListNode *p2 = nullptr;
        ListNode *t = head;

        while (t) {
            if (t->val == v1 || t->val == v2) {
                if (!n1)
                    n1 = t;
                else
                    n2 = t;
            }
            if (!n1)
                p1 = t;
            if (!n2)
                p2 = t;
            t = t->next;
        }

        // do nothing
        if (!n1 || !n2)
            return head;

        // consider that the n1 is the first node of this list
        if (!p1) {
            // consider that n2 is the next node after n1
            if (n1->next == n2) {
                n1->next = n2->next;
                n2->next = n1;
                return n2;
            }
            else {
                ListNode *temp = n1->next;
                n1->next = n2->next;
                p2->next = n1;
                n2->next = temp;
                return n2;
            }
        }
        // consider that the n1 is not the first node of this list
        else {
            // consider that n2 is the next node after n1
            if (n1->next == n2) {
                n1->next = n2->next;
                p1->next = n2;
                n2->next = n1;
                return head;
            }
            ListNode *temp = n1->next;
            n1->next = n2->next;
            p2->next = n1;
            n2->next = temp;
            p1->next = n2;

            return head;
        }
    }
};
