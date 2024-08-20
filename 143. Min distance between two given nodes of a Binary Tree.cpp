/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    Node* findLCA(Node* root, int a, int b) {
        if (!root || root->data == a || root->data == b)
            return root;
    
        Node* left = findLCA(root->left, a, b);
        Node* right = findLCA(root->right, a, b);
    
        if (left && right)
            return root;
    
        return left == nullptr ? right : left;
    }
    
    int findDistLCA(Node* root, int n, int d) {
        if (!root)
            return -1;
    
        if (root->data == n)
            return d;
    
        int left = findDistLCA(root->left, n, d + 1);
        if (left != -1)
            return left;
    
        return findDistLCA(root->right, n, d + 1);
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
    
        // 1 find lowest common ancestor
        Node* lca = findLCA(root, a, b);
        // 2 find distance of a from LCA
        int d1 = findDistLCA(lca, a, 0);
        // 3 find distance of b from LCA
        int d2 = findDistLCA(lca, b, 0);
    
        return d1 + d2;
    }
};
