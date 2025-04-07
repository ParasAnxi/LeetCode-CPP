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
  void solve(TreeNode *root, bool &ans, int data) {
    if (root == NULL) {
      return;
    }
    solve(root->left, ans, data);
    if (root->val != data) {
      ans = false;
    }
    solve(root->right, ans, data);
  }
  bool isUnivalTree(TreeNode *root) {
    bool ans = true;
    int val = root->val;
    solve(root, ans, val);
    return ans;
  }
};