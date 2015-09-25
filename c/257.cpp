/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode *node, vector<string> &vs, string s) {
        s = s + "->" + to_string(node->val);
        if (!node->left && !node->right) {
            vs.push_back(s);
            return;
        }
        if (node->left)
            f(node->left, vs, s);
        if (node->right)
            f(node->right, vs, s);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vs;
        if (root)
            f(root, vs, "");
        return vs;
    }
};
