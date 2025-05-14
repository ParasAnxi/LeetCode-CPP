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
  void solve(TreeNode *root, string s, vector<string> &ans) {
    if (!root)
      return;
    if (root->left || root->right) {
      s += to_string(root->val);
      s += "->";
    }
    if (root->left)
      solve(root->left, s, ans);
    if (root->right)
      solve(root->right, s, ans);
    if (!root->left && !root->right) {
      s += to_string(root->val);
      ans.push_back(s);
      s = "";
    }
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    string s = "";
    solve(root, s, ans);
    return ans;
  }
};