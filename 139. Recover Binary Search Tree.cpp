/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> values;
    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }

    void solve(TreeNode* root, int& i) {
        if (!root)
            return;

        solve(root->left, i);
        root->val = values[i++];
        solve(root->right, i);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(values.begin(), values.end());
        int i = 0;
        solve(root, i);
    }
};
