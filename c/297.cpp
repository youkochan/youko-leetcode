/**
 * Serialize and Deserialize Binary Tree
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 */

#include <iostream>
#include <queue>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

string to_string(int i) {
    ostringstream os;
    os << i;
    return os.str();
}

int stoi(string s) {
    istringstream ss(s);
    int i;
    ss >> i;
    return i;
}

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
private:
    string _s(TreeNode *root) {
        if (root == nullptr)
            return "";
        if (!root->left && !root->right)
            return to_string(root->val);
        else
            return to_string(root->val) +
                    "(" + _s(root->left) +
                    "," + _s(root->right) +
                    ")";
    }

    TreeNode* _d(string data) {
        if (data.size() == 0)
            return nullptr;
        int lidx = data.find_first_of("(");
        // Ñ°ÕÒ·Ö¸îµÄ¶ººÅ
        int midx = -1;
        int count = 0;
        for (int i = data.size()-2; i >= 0; i --) {
            if (count == 0 && data[i] == ',') {
                midx = i;
                break;
            }
            else if (data[i] == ')')
                count ++;
            else if (data[i] == '(')
                count --;
        }
        if (lidx == string::npos) {
            return new TreeNode(stoi(data));
        }
        else {
            TreeNode *newnode = new TreeNode(stoi(data.substr(0,lidx)));
            newnode->left = _d(data.substr(lidx+1,midx-lidx-1));
            newnode->right = _d(data.substr(midx+1,data.size()-midx-2));
            return newnode;
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return _s(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return _d(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main() {
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(1);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;

    Codec codec;
    cout << codec.serialize(p1) << endl;
    TreeNode *root = codec.deserialize(codec.serialize(p1));

    cout << root->val << endl;
    cout << root->right->val << endl;

    return 0;
}
