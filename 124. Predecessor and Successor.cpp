/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
     void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Base Case
        if (!root) return;

        // Searching for Predecessor
        if (key < root->key) {
            // If key is smaller, successor might be the current node or in the left subtree
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        // Searching for Successor
        else if (key > root->key) {
            // If key is larger, predecessor might be the current node or in the right subtree
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
        // If the key is found
        else {
            // Predecessor: Max value in the left subtree
            if (root->left) {
                Node* temp = root->left;
                while (temp->right) temp = temp->right;
                pre = temp;
            }

            // Successor: Min value in the right subtree
            if (root->right) {
                Node* temp = root->right;
                while (temp->left) temp = temp->left;
                suc = temp;
            }
        }
    }
};
