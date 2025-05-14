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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return NULL;
    if ((p->val < root->val) && (root->val > q->val))
      return lowestCommonAncestor(root->left, p, q);
    else if ((p->val > root->val) && (root->val < q->val))
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};