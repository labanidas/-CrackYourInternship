/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    
    
    void populateArr(vector<int>& arr, Node* head){
        if(!head) return;
        
        arr.push_back(head->data);
        
        populateArr(arr, head->bottom);
        
        populateArr(arr, head->next);
    }

    // Function which returns the root of the flattened linked list.
    Node* flatten(Node* root) {
        
        vector<int> arr;
        
        populateArr(arr, root);
        
        if(arr.empty()) return nullptr;
        
        sort(arr.begin(), arr.end());
        
        Node* head = new Node(arr[0]);
        Node* curr = head;
        
        for(int i=1; i<arr.size(); i++){
            curr->bottom = new Node(arr[i]);
            curr=curr->bottom;
        }
        
        return head;
    }
};
