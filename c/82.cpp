/**
 * Remove Duplicates from Sorted List II
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        ListNode *rh = nullptr;
        ListNode *rt = nullptr;
        ListNode *p = head;
        ListNode *n = head->next;
        
        while (n) {
            if (n->val != p->val) {
                if (!rh) {
                    rh = p;
                    rh->next = nullptr;
                    rt = rh;
                    p = n;
                    n = p->next;
                }
                else {
                    rt->next = p;
                    rt = p;
                    rt->next = nullptr;
                    p = n;
                    n = p->next;
                }
            }
            else {
                while (n && n->val == p->val) {
                    p = p->next;
                    n = n->next;
                }
                if (!n) {
                    return rh;
                }
                else {
                    p = n;
                    n = p->next;
                }
            }
        }
        
        if (rh == nullptr) {
            rh = p;
        }
        else {
            rt->next = p;
            rt = p;
            rt->next = nullptr;
        }
        
        return rh;
    }
};