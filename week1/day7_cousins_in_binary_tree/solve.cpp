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
    bool isCousins(TreeNode *root, int x, int y) {
        auto dx = findDepth(root, 0, x, root->val);
        auto dy = findDepth(root, 0, y, root->val);
        if (dx.first == dy.first) {
            if (dx.second != dy.second)
                return true;
            return false;
        }
        return false;
    }

    pair<int, int> findDepth(TreeNode *node, int depth, int target,
                             int parent) {
        if (!node) {
            return make_pair(-1, parent);
        }

        if (target == node->val) {
            return make_pair(depth, parent);
        }

        auto left = findDepth(node->left, depth + 1, target, node->val);
        auto right = findDepth(node->right, depth + 1, target, node->val);
        if (left > right) {
            return left;
        }
        return right;
    }
};
