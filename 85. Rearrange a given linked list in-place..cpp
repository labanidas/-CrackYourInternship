// https://leetcode.com/problems/reorder-list/
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

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    } 

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

         ListNode* slow = head;
        ListNode* fast = head;

        // finding middle of linked list
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split and reverse 2nd part
        ListNode* temp = slow->next;
        slow->next = nullptr;

        temp = reverse(temp);

        ListNode* list1 = head;
        ListNode* list2 = temp;

        // Alternate merge
        while (list1 && list2) {
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;

            list1->next = list2;
            list2->next = temp1;

            list1 = temp1;
            list2 = temp2;
        }
    }
};
