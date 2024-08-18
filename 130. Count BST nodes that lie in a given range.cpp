//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    int ans=0;
    
    void helper(Node* root, int l, int h){
        if(!root)
            return;
        
        helper(root->left, l, h);
        if(root->data >= l && root->data <= h) ans++;
        helper(root->right, l, h);
        
    }
    
    int getCount(Node *root, int l, int h)
    {
      helper(root, l, h);
      return ans;
    }
};
