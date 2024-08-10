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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        for (auto list : lists) {
            ListNode* ptr = list;
            while (ptr) {
                arr.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
        
        // If the array is empty, return nullptr
        if(arr.empty()) return nullptr;

        sort(arr.begin(), arr.end());

        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;

        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }
};
