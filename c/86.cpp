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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
            return nullptr;
        ListNode *lhead = nullptr;
        ListNode *ltail = nullptr;
        ListNode *rhead = nullptr;
        ListNode *rtail = nullptr;
        ListNode *next = head->next;
        
        while (head) {
            head->next = nullptr;
            if (head->val < x) {
                if (lhead == nullptr) {
                    lhead = head;
                    ltail = head;
                }
                else {
                    ltail->next = head;
                    ltail = head;
                }
            } 
            else {
                if (rhead == nullptr) {
                    rhead = head;
                    rtail = head;
                }
                else {
                    rtail->next = head;
                    rtail = head;
                }
            }
            head = next;
            if (next)
                next = next->next;
        }
        
        if (!lhead)
            return rhead;
        
        ltail->next = rhead;
        return lhead;
    }
};