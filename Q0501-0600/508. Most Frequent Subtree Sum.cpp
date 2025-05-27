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
  void solve(TreeNode *root, unordered_map<TreeNode *, int> &mp) {
    if (root == NULL) {
      return;
    }
    solve(root->left, mp);
    solve(root->right, mp);
    if (!root->left && !root->right) {
      mp[root] = root->val;
    } else if (!root->left && root->right) {
      mp[root] = root->val + mp[root->right];
    } else if (root->left && !root->right) {
      mp[root] = root->val + mp[root->left];
    } else {
      mp[root] = root->val + mp[root->left] + mp[root->right];
    }
  }
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<TreeNode *, int> mp;
    unordered_map<int, int> mp2;
    solve(root, mp);
    vector<int> ans;
    for (auto &i : mp) {
      mp2[i.second]++;
    }
    int maxi = INT_MIN;
    for (auto &i : mp2) {
      if (i.second > maxi) {
        maxi = i.second;
        ans.clear();
      }
      if (i.second == maxi) {
        ans.push_back(i.first);
      }
    }
    return ans;
  }
};