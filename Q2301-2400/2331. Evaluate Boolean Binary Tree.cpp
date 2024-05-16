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
    bool solve(TreeNode *root)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return root->val;

        if (root->val == 2)
            return solve(root->left) | solve(root->right);
        return solve(root->left) & solve(root->right);
    }
    bool evaluateTree(TreeNode *root)
    {
        return solve(root);
    }
};