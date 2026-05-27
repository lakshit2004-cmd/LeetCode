class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || k == 1) return head;

        ListNode* curr = head;
        ListNode* prevGroupEnd = nullptr;
        ListNode* newHead = nullptr;

        while(curr) {

            // check k nodes
            ListNode* temp = curr;
            int count = 0;
            while(temp && count < k) {
                temp = temp->next;
                count++;
            }

            if(count < k) {
                if(prevGroupEnd) prevGroupEnd->next = curr;
                break;
            }

            // reverse k nodes
            ListNode* prev = nullptr;
            ListNode* node = curr;

            for(int i = 0; i < k; i++) {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }

            // connect groups
            if(!newHead) newHead = prev;
            if(prevGroupEnd) prevGroupEnd->next = prev;

            prevGroupEnd = curr;
            curr = temp;
        }

        return newHead ? newHead : head;
    }
};