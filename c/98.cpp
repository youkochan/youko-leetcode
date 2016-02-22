/**
 * Validate Binary Search Tree
 * https://leetcode.com/problems/validate-binary-search-tree/
 */

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
    bool check(TreeNode* root, long long min, long long max) {
        if (!root)
            return true;
        if (root->val >= max)
            return false;
        if (root->val <= min)
            return false;
        if (root->left && root->val <= root->left->val)
            return false;
        if (root->right && root->val >= root->right->val)
            return false;
        return check(root->left, min, root->val) &&
               check(root->right, root->val, max);
        
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};