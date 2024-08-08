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
    int getDecimalValue(ListNode* head) {
        
        vector<int> temp;
        int num = 0;
        int ind = 0;

        while(head!=nullptr){
            temp.push_back(head->val);
            head = head->next;
        }
        int size = temp.size();

       for(int i=size-1; i>=0; i--){
            int n1 = temp[i];
            num+= (n1==1) ? pow(2,ind) : 0;
            ind++;

        }

        return num;
    }
};
