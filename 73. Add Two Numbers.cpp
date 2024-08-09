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
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* curr = head;

        while (l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            int num = n1 + n2 + carry;
            carry = num / 10;
            num = num % 10;
            curr->next = new ListNode(num);

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            curr = curr->next;
        }

        // if (carry)
        //     curr->next = new ListNode(carry);

        return head->next;
    }
};
