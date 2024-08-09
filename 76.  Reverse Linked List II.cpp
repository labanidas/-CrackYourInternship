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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || !head->next || left==right)
            return head;

        // step 1 -- create dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        // step 2 - move pointer
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        //step 3 -- reverse
        ListNode* curr = prev->next;
        ListNode* reverse_prev = nullptr;

        for(int i=0; i<right-left+1; i++){
            ListNode* temp = curr->next;
            curr->next = reverse_prev;
            reverse_prev = curr;
            curr = temp;
        }
        prev->next->next = curr;
        prev->next = reverse_prev;
        
        return dummy->next;
    }
};
