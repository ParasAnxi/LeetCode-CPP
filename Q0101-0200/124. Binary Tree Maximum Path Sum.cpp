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
  int solve(TreeNode *&root, int &ans) {
    if (!root)
      return 0;
    int leftAns = solve(root->left, ans);
    int rightAns = solve(root->right, ans);
    ans = max(ans, max(root->val + leftAns + rightAns,
                       max(root->val,
                           max(root->val + leftAns, root->val + rightAns))));
    return max(max(leftAns, rightAns) + root->val, root->val);
  }
  int maxPathSum(TreeNode *root) {
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
  }
};