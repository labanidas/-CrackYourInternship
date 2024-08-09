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
    void reorderList(ListNode* head) {
        // put the values into array

        int size = 0;
        ListNode* ptr = head;

        while (ptr) {
            ptr = ptr->next;
            size++;
        }

        ptr = head;
        int arr[size];
        int i1 = 0, i2 = size % 2 == 0 ? size - 1 : size - 2;


        while (i1 < size) {
            arr[i1] = ptr->val;
            i1 += 2;
            ptr = ptr->next;
        }
        while (i2 > 0) {
            arr[i2] = ptr->val;
            i2 -= 2;
            ptr = ptr->next;
        }

        ptr = head;
        int i = 0;
        while (ptr) {
            ptr->val = arr[i];
            i++;
            ptr = ptr->next;
        }
    }
};
