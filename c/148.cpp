/**
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode * sortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *mid = getMidNode(head);
        ListNode *list1 = head;
        ListNode *list2 = mid->next;
        
        mid->next = nullptr;
        
        return merge(sortList(list1), sortList(list2));
    }
    
    ListNode * getMidNode(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode * merge(ListNode *list1, ListNode *list2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        
        while(list1 != nullptr && list2 != nullptr) {
            ListNode *tmp = nullptr;
            if(list1->val < list2->val) {
                tmp = list1;
                list1 = list1->next;
                tmp->next = nullptr;
            }
            else {
                tmp = list2;
                list2 = list2->next;
                tmp->next = nullptr;
            }
            
            if(head == nullptr) {
                head = tmp;
                tail = head;
            }
            else {
                tail->next = tmp;
                tail = tail->next;
            }
        }
        
        if(list1 != nullptr) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }
        
        return head;
    }
};