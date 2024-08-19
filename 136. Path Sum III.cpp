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
    long long  helper(TreeNode* root, long long  sum) {
        if (!root)
            return 0;

        long long  res = 0;

        if (root->val == sum)
            res++;
        res += helper(root->left, sum - root->val);
        res += helper(root->right, sum - root->val);
        return res;
    }

    long long  pathSum(TreeNode* root, long long  targetSum) {
        if (!root)
            return 0;

        return pathSum(root->left, targetSum) + helper(root, targetSum) +
               pathSum(root->right, targetSum);
    }
};
