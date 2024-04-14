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
    void solve(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return;
        if (root->left && root->left->left == NULL && root->left->right == NULL)
        {
            sum += root->left->val;
        }
        if (root->left)
            solve(root->left, sum);
        if (root->right)
            solve(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int s = 0;
        solve(root, s);
        return s;
    }
};