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
  pair<TreeNode *, int> solve(TreeNode *root) {
    bool left = false, right = false;
    pair<TreeNode *, int> l, r;

    if (root->left) {
      leftAns = solve(root->left);
      left = true;
    }
    if (root->right) {
      rightAns = solve(root->right);
      right = true;
    }

    if (left && right) {
      if (leftAns.second == rightAns.second) {
        return {root, leftAns.second + 1};
      } else if (leftAns.second > rightAns.second) {
        return {leftAns.first, leftAns.second + 1};
      } else {
        return {rightAns.first, rightAns.second + 1};
      }
    } else if (left) {
      return {leftAns.first, leftAns.second + 1};
    } else if (right) {
      return {rightAns.first, rightAns.second + 1};
    }

    return {root, 0};
  }
  TreeNode *lcaDeepestLeaves(TreeNode *root) { return solve(root).first; }
};