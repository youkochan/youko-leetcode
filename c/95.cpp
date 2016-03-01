/**
 * 95. Unique Binary Search Trees II
 * 给定一个整数 n 返回所有包含 1..n 的所有 BST 树
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
    vector<TreeNode*> gen(int left, int right) {
        // [left, right)
        vector<TreeNode*> result;

        if (left == right) {
            TreeNode *node = nullptr;
            result.push_back(node);
        }
        else if (right == left + 1) {
            TreeNode *node = new TreeNode(left);
            result.push_back(node);
        }
        else {
            for (int i = left; i < right; i ++) {
                vector<TreeNode*> vl;
                vector<TreeNode*> vr;

                if (i != left) {
                    vl = gen(left, i);
                }
                if (i != right - 1) {
                    vr = gen(i + 1, right);
                }

                if (vl.size() == 0) {
                    for (int j = 0; j < vr.size(); j ++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = nullptr;
                        root->right = vr[j];
                        result.push_back(root);
                    }
                }
                else if (vr.size() == 0) {
                    for (int j = 0; j < vl.size(); j ++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = vl[j];
                        root->right = nullptr;
                        result.push_back(root);
                    }
                }
                else {
                    for (int j1 = 0; j1 < vl.size(); j1 ++) {
                        for (int j2 = 0; j2 < vr.size(); j2 ++) {
                            TreeNode *root = new TreeNode(i);
                            root->left = vl[j1];
                            root->right = vr[j2];
                            result.push_back(root);
                        }
                    }
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        return gen(1, n+1);
    }
};

