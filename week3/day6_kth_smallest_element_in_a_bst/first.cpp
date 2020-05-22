class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> path;
        inorder(root, path);

        return path[k - 1];
    }

    void inorder(TreeNode *node, vector<int> &path) {
        if (!node)
            return;

        inorder(node->left, path);
        path.push_back(node->val);
        inorder(node->right, path);
    }
};
