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
// 0 - uncovered
 //1 - covered
 // 2 - has camera
class Solution {
public:
    int ans;
    
    int dfs(TreeNode* node) {
        if(!node) return 1; //1 - covered

        int left = dfs(node->left);
        int right = dfs(node->right);

        if(left == 0 || right == 0){ // 0 - uncovered
            ans++;
            return 2; 
        }

        if(left == 2 || right == 2){ // 2 - has camera
            return 1; 
        }

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        ans = 0;
        if(dfs(root) == 0) ans++;

        return ans;
    }
};
