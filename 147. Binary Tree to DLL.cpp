/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
    Node* prev = nullptr;
    Node* head = nullptr;
    
      void convert(Node* root){
        if(!root) return;
        
        convert(root->left);
        
        if(!prev){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        
        convert(root->right);
      }
    Node* bToDLL(Node* root) {
        
        convert(root);
        
        return head;
    }
};
