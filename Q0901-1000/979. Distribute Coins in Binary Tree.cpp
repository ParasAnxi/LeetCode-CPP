/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int &ans) {
      int res = 0;
      if(root == NULL) return 0;
      if(root -> left == NULL && root -> right == NULL) {
          res = root -> val - 1;
      } else {                           
          int left = solve(root -> left,ans); 
          int right = solve(root -> right,ans);
          res = root -> val + left + right - 1;
      }
      ans = ans + abs(res);
      return res;
    }

    int distributeCoins(TreeNode* root) {
      int ans = 0;
      solve(root,ans);
      return ans;
    }
};