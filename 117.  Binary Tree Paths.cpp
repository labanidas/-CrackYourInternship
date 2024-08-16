class Solution {
public:
    vector<string> ans;
    
    void helper(TreeNode* root, string temp = "") {
        if(!root) return;

        temp += to_string(root->val);

        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }

        temp += "->";

        helper(root->left, temp);
        helper(root->right, temp);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root);
        return ans;
    }
};
