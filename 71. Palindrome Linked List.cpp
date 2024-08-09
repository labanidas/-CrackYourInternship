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
    bool isPalindrome(ListNode* head) {
        // find middle of linked list
        // reverse half of it
        // compare and return ans

        if(head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && slow){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing
        ListNode* prev = nullptr;
        while(slow){
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // comparing
        ListNode* left = head;
        ListNode* right = prev;
        while(right){
            if(left->val != right->val)
                return false;
            left  = left->next;
            right = right->next;
        }
        return true;
    }
};
