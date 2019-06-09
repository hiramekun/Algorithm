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
        ListNode* slow = NULL;
        ListNode* fast = head;
        while(fast != NULL) {
            while (fast->next != NULL && slow->val == fast->next->val) {
                fast = fast->next;
            }
            if (slow == NULL) slow = new ListNode(fast->val);
            else slow->next = fast;
        }
        
        return head;
    }
};
