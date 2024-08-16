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
    int ans = INT_MAX;
    TreeNode* prevNode = nullptr;

    int getMinimumDifference(TreeNode* root) {

        if (!root)
            return ans;

        getMinimumDifference(root->left);

        if (prevNode)
            ans = min(ans, abs(root->val - prevNode->val));

        prevNode = root;

        getMinimumDifference(root->right);

        return ans;
    }
};
