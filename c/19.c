/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 */ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    struct ListNode* slow = NULL;
    
    while(fast->next != NULL) {
        n--;
        if(n > 0) {
            fast = fast->next;
        }
        else if(n == 0) {
            fast = fast->next;
            slow = head;
        }
        else {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    if(slow == NULL) {  // delete first element
        return head->next;
    }
    else {
        slow->next = slow->next->next;
        return head;
    }
}
