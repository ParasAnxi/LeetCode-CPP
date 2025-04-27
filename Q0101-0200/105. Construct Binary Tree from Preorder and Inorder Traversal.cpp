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
  TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex,
                  int inStart, int inEnd, unordered_map<int, int> &mp) {
    if (inStart > inEnd)
      return NULL;

    int val = preorder[preIndex++];
    TreeNode *root = new TreeNode(val);

    int inIndex = mp[val];

    root->left = solve(preorder, inorder, preIndex, inStart, inIndex - 1, mp);
    root->right = solve(preorder, inorder, preIndex, inIndex + 1, inEnd, mp);

    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }
    int preIndex = 0;
    return solve(preorder, inorder, preIndex, 0, inorder.size() - 1, mp);
  }
};
