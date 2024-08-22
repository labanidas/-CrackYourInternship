/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/

struct Node* constructTreeUtility(int& i, int n, int pre[], char preL[]){
    if(i>=n) return nullptr;
    
    Node* node = new Node(pre[i]);
    
    if(preL[i] == 'L'){
        i++;
        return node;
    }
    
    i++;
    node->left = constructTreeUtility(i, n, pre, preL);
    node->right = constructTreeUtility(i, n, pre, preL);
    
    return node;
}
// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{   
    int i = 0;
    return constructTreeUtility(i, n, pre, preLN);
    
}
