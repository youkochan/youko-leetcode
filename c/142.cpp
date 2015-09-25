/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Follow up:
 * Can you solve it without using extra space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 可以证明，若有环，第一次相遇时，将慢指针指向头节点，然后每次移动一次快指针与慢指针
 * 两指针会在环入口处相遇
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                slow = head;
                
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow;
            }
        }
        
        return nullptr;
    }
};