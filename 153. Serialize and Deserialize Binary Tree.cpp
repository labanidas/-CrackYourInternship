/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr)
                s += "#,";
            else
                s += to_string(curr->val) + ',';

            if (curr) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        cout<<s<<endl;

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        stringstream s(data); // allow to iterate over string as objects
        string str;
        getline(s, str, ','); // seperate each object using ',' delimeter
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
                node->left = nullptr;
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s, str, ',');
            if (str == "#")
                node->right = nullptr;
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
