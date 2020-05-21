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
    int kthSmallest(TreeNode *root, int k) {
        vector<int> path;
        inorder(root, path);
        return path[k - 1];
    }

    void inorder(TreeNode *node, vector<int> &path) {
        if (!node) {
            return;
        }

        inorder(node->left, path);
        path.push_back(node->val);
        inorder(node->right, path);
    }
};
