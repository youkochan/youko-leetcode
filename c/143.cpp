/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    ListNode * findMid(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode * reverseList(ListNode *head) {
        ListNode *pos = head;
        ListNode *right = nullptr;
        ListNode *left = nullptr;
        
        while(pos != nullptr) {
            right = pos->next;
            pos->next = left;
            left = pos;
            pos = right;
        }
        
        return left;
    }

    void reorderList(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return;
        
        ListNode *mid = findMid(head);
        
        ListNode *list1 = head;
        ListNode *list2 = mid->next;
        
        mid->next = nullptr;
        
        list1 = list1->next;
        list2 = reverseList(list2);
        
        ListNode *tail = head;
        tail->next = nullptr;
        
        while(list2 != nullptr && list1 != nullptr) {
            ListNode *node1 = list1;
            ListNode *node2 = list2;
            
            list1 = list1->next;
            list2 = list2->next;
            
            node1->next = nullptr;
            node2->next = nullptr;
            
            tail->next = node2;
            tail = tail->next;
            tail->next = node1;
            tail = tail->next;
        }
        
        if(list2 != nullptr) {
            tail->next = list2;
        }
        
    }
};