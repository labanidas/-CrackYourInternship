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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        while(curr->next && curr->next->next){
            
            if(curr->next && curr->next->val == curr->next->next->val){
                int duplicate = curr->next->val;
                while(curr->next && curr->next->val == duplicate){
                curr->next = curr->next->next;
            }
            }else{
                curr = curr->next;
            }            
        }
        return dummy->next;
    }
};
