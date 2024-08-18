/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    void helper(Node* root, unordered_set<int>& nodes, unordered_set<int>& leaves){
        if(!root) return;
        
        helper(root->left, nodes, leaves);
        
        if(root->left || root->right) 
            nodes.insert(root->data);
        else leaves.insert(root->data);
        
        helper(root->right, nodes, leaves);
    }
    
   
    bool isDeadEnd(Node *root)
    {   
        unordered_set<int> nodes, leaves;
        nodes.insert(0);
        helper(root, nodes, leaves);
        
        for(int leaf: leaves){
            if(nodes.count(leaf-1) != 0 && nodes.count(leaf+1) != 0)
                return true;
        }
        
        return false;
    }
};
