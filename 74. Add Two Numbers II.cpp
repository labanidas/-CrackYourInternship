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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //  easy by reversing list

        stack<int> st1;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        stack<int> st2;
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = new ListNode();
        ListNode* curr = head;
        int carry = 0;

        // stack
        while (!st1.empty() || !st2.empty() || carry) {
            int n1 = st1.empty() ? 0 : st1.top();
            int n2 = st2.empty() ? 0 : st2.top();

            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();

            int num = n1 + n2 + carry;
            carry = num / 10;
            num = num % 10;
            curr->next = new ListNode(num);
            curr = curr->next;
        }

        return reverse(head->next);
    }
};
