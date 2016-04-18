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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if (head == nullptr || head->next == nullptr)
            return true;

        bool result = true;

        ListNode *mid = head;
        ListNode *tail = head;

        while (tail->next && tail->next->next) {
            mid = mid->next;
            tail = tail->next->next;
        }

        ListNode *pre = mid;
        ListNode *now = mid->next;
        while (now) {
            ListNode *temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }

        ListNode *pl = head;
        ListNode *pr = pre;

        while (pr != mid) {
            if (pl->val != pr->val)
                result = false;
            pr = pr->next;
            pl = pl->next;
        }

        now = pre;
        pre = nullptr;

        while (now != mid) {
            ListNode *temp = now->next;
            now->next = pre;
            pre = now;
            now = temp;
        }

        return result;
    }
};
