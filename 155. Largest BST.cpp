/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeVal{
    public:
    int min, max, size;
    NodeVal(int min, int max, int size){
        this->min = min;
        this->max = max;
        this->size = size;
    }
    
};
class Solution{
    public:
    NodeVal helper(Node* root){
        if(!root) return NodeVal(INT_MAX, INT_MIN, 0);
        
        NodeVal left = helper(root->left);
        NodeVal right = helper(root->right);
        
        if(left.max < root->data && root->data < right.min){
            //bst
            return NodeVal(min(left.min, root->data), 
                max(root->data, right.max), left.size+right.size+1);
        }
        
        return NodeVal(INT_MIN, INT_MAX, max(left.size, right.size));
        
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return helper(root).size;
    }
};
