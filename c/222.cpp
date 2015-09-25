/**
 * Given a complete binary tree, count the number of nodes.
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, 
 * and all nodes in the last level are as far left as possible. 
 * It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode *root) {
        if(root == nullptr)
            return 0;
        
        int lh = getLHeight(root);
        int rh = getRHeight(root);
        
        if(lh == rh) {  // 左右子树高度一致
            return pow(2, lh) - 1;
        }
        else {          // 左右子树高度不一致，总数为左子树总数加右子树总数加一
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
    
    int getLHeight(TreeNode *root) {
        int height = 0;
        while(root) {
            height ++;
            root = root->left;
        }
        return height;
    }
    
    int getRHeight(TreeNode *root) {
        int height = 0;
        while(root) {
            height ++;
            root = root->right;
        }
        return height;
    }
};