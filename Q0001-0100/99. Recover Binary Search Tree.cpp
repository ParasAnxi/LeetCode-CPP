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
private:
  TreeNode *s;
  TreeNode *prev;
  TreeNode *mid;
  TreeNode *e;

  void inorder(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    inorder(root->left);
    if (prev != NULL && (root->val < prev->val)) {
      if (s == NULL) {
        s = prev;
        mid = root;
      } else {
        e = root;
      }
    }
    prev = root;
    inorder(root->right);
  }

public:
  void recoverTree(TreeNode *root) {
    s = mid = e = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if (s != NULL && e != NULL) {
      swap(s->val, e->val);
    } else if (s != NULL && mid != NULL) {
      swap(s->val, mid->val);
    }
  }
};