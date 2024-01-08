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
class Solution
{
public:
    void solve(TreeNode *root, int s, int e, int &ans)
    {
        if (root == NULL)
            return;

        if (root->val >= s && root->val <= e)
        {
            ans += root->val;
            solve(root->left, s, e, ans);
            solve(root->right, s, e, ans);
        }
        else if ((root->val < s) && root->right)
            solve(root->right, s, e, ans);
        else if ((root->val > e) && root->left)
            solve(root->left, s, e, ans);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        solve(root, low, high, ans);
        return ans;
    }
};