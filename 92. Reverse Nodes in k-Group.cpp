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
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1; 
        while(temp != NULL && k > 0){
            k--; 
            temp = temp -> next; 
        }
        return temp; 
    }
    ListNode* reverse(ListNode *head)
    {
        ListNode* temp = head;  
        ListNode* prev = NULL;  
        
        while(temp != NULL){  
            ListNode* next = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = next; 
        }
        return prev;  
    }
   ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == nullptr){
                if(prev){
                    prev->next = temp;
                    break;
                } 
            }
            ListNode* next = kthNode->next;
            kthNode->next = nullptr;
            kthNode = reverse(temp);

            if(temp==head){
                head = kthNode;
            }else{
                prev->next = kthNode;
            }
            prev = temp;
            temp = next;
        }
        return head;
    }
};
