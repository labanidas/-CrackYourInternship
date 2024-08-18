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
    map<pair<int, int>, vector<TreeNode*>> mp;
    vector<TreeNode*> helper(int start, int end) {
        if (start > end)
            return {nullptr};

        if (start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        if (mp.find({start, end}) != mp.end()) {
            return mp[{start, end}];
        }

        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i - 1);
            vector<TreeNode*> right = helper(i + 1, end);
            for (TreeNode* leftRoot : left) {
                for (TreeNode* rightRoot : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    result.push_back(root);
                }
            }
        }

        return mp[{start, end}] = result;
    }
    vector<TreeNode*> generateTrees(int n) { 
        return helper(1, n); 
    }
};
