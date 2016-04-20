/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    void findPath(TreeNode *node, string str, vector<string> &results) {
        if (str.size() == 0)
            str = to_string(node->val);
        else
            str = str + "->" + to_string(node->val);
        
        if (!node->left && !node->right)
            results.push_back(str);
        else {
            if (node->left)
                findPath(node->left, str, results);
            if (node->right)
                findPath(node->right, str, results);
        }
    }

    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> results;
        if (root)
            findPath(root, "", results);
        
        return results;
    }
};
