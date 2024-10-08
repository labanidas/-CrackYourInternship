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
    bool isValidBST(TreeNode* root, TreeNode* min = nullptr,
                    TreeNode* max = nullptr) {

        // if(!root) return true;

        // isValidBST(root->left);

        // if(root->right && root->val >= root->right->val)
        //     return false;

        //  isValidBST(root->right);

        // return true;

        if (!root)
            return true;

        // Check if the current node's value violates the min/max constraints
        // return false if does satisfy
        if ((min && root->val <= min->val) ||
            (max && root->val >= max->val)) {
            return false;
        }

        return isValidBST(root->left, min, root) &&
               isValidBST(root->right, root, max);
    }
};
