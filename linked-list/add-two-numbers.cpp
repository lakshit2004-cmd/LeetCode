/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;

        while (l1 || l2) {
            if (!l1) {
                prev->next = l2;
                l1 = l2;
                l2 = nullptr;
            }

            int sum = l1->val + (l2 ? l2->val : 0) + carry;

            // Faster carry handling than / and %
            carry = (sum >= 10);
            l1->val = sum - carry * 10;

            prev = l1;
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry)
            prev->next = new ListNode(1);

        return head;
    }
};