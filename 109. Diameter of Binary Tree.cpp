/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int  func(TreeNode* root, int& diameter){
        if(root==nullptr) return 0;

        int left = func(root->left, diameter);
        int right = func(root->right, diameter);
        diameter = max(diameter, left+right);

        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        func(root, diameter);
        return diameter;
    }
};
