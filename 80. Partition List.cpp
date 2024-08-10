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
    ListNode* partition(ListNode* head, int x) {
        vector<int> temp1;
        vector<int> temp2;

        ListNode* ptr = head;

        while(ptr){
            if(ptr->val < x)
                temp1.push_back(ptr->val);
            else temp2.push_back(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;
        for(int i=0; i<temp1.size(); i++){
            ptr->val = temp1[i];
            ptr = ptr->next;
        }

        for(int i=0; i<temp2.size(); i++){
            ptr->val = temp2[i];
            ptr = ptr->next;
        }

        return head;
    }
};
