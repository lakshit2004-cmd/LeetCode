class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // move fast n steps
        for(int i = 0; i < n; i++)
            fast = fast->next;

        // if removing head
        if(!fast)
            return head->next;

        // move both
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // remove node
        slow->next = slow->next->next;

        return head;
    }
};