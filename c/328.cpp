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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode *p = head;
        bool tag = true;
        ListNode *head1 = nullptr;
        ListNode *head2 = nullptr;
        ListNode *tail1 = nullptr;
        ListNode *tail2 = nullptr;
        
        while (p) {
            ListNode *temp = p->next;
            p->next = nullptr;
            
            if (tag) {
                if (!head1) {
                    head1 = p;
                    tail1 = p;
                }
                else {
                    tail1->next = p;
                    tail1 = p;
                }
            }
            else {
                if (!head2) {
                    head2 = p;
                    tail2 = p;
                }
                else {
                    tail2->next = p;
                    tail2 = p;
                }
            }
            tag = !tag;
            p = temp;
        }
        
        tail1->next = head2;
        
        return head1;
    }
};