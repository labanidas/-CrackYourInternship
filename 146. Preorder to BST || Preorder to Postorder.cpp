/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
   // Helper function to construct BST from preorder traversal.
    Node* buildBST(int pre[], int size, int& index, int min, int max) {
        // Base case: If all elements are processed or the current element is out of the valid range.
        if(index>=size || pre[index] < min || pre[index] > max)
            return nullptr;
        
        int val = pre[index++];
        Node* node = newNode(val);
        
        node->left = buildBST(pre, size, index, min, val-1);
        node->right = buildBST(pre, size, index, val+1, max);
        
        return node;
        
    }

    
    Node* Bst(int pre[], int size) {
        int index = 0;
        return buildBST(pre, size, index, INT_MIN, INT_MAX);
    }
};
