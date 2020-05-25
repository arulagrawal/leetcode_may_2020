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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        TreeNode *root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++)
            make(root, preorder[i]);
        return root;
    }

    TreeNode *make(TreeNode *node, int value) {
        if (!node)
            node = new TreeNode(value);

        if (value < node->val)
            node->left = make(node->left, value);
        else if (value > node->val)
            node->right = make(node->right, value);

        return node;
    }
};
