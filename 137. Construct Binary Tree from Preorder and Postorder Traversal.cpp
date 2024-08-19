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
    TreeNode* helper(vector<int>& pre, int preLow, int preHigh,
                     vector<int>& post, int postLow, int postHigh) {
        if (preLow > preHigh || postLow > postHigh)
            return nullptr;

        TreeNode* root = new TreeNode(pre[preLow]);

        if (preLow == preHigh)
            return root;

        int i = postLow;

        while (i <= postHigh) {
            if (post[i] == pre[preLow + 1])
                break;
            i++;
        }

        int leftCount = i - postLow;

        root->left =
            helper(pre, preLow + 1, preLow + leftCount + 1, post, postLow, i);
        root->right =
            helper(pre, preLow + leftCount + 2, preHigh, post, i + 1, postHigh);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size() - 1;
        return helper(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};
