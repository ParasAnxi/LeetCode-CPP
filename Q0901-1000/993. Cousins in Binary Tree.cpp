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
    queue<pair<TreeNode *, TreeNode *>> q;
    q.push({root, NULL});

    int lvlX = -1;
    int lvlY = -1;
    TreeNode *prevX = NULL;
    TreeNode *prevY = NULL;

    int lvl = 0;
    while (!q.empty()) {
      int n = q.size();
      while (n > 0) {
        auto front = q.front();
        q.pop();
        n--;

        if (front.first->val == x) {
          lvlX = lvl;
          prevX = front.second;
        }
        if (front.first->val == y) {
          lvlY = lvl;
          prevY = front.second;
        }
        if (lvlX != -1 && lvlY != -1) {
          return lvlX == lvlY && prevX != prevY;
        }

        if (front.first->left != NULL) {
          q.push({front.first->left, front.first});
        }
        if (front.first->right != NULL) {
          q.push({front.first->right, front.first});
        }
      }
      lvl++;
    }
    return false;
  }
};