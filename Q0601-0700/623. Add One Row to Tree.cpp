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
    void solve(TreeNode *root, int val, int depth, int count)
    {
        if (!root)
            return;
        if (count == depth - 1)
        {
            TreeNode *temp = new TreeNode(val);
            temp->left = root->left;
            root->left = temp;
            TreeNode *temp2 = new TreeNode(val);
            temp2->right = root->right;
            root->right = temp2;
            return;
        }
        solve(root->left, val, depth, count + 1);
        solve(root->right, val, depth, count + 1);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        solve(root, val, depth, 1);
        return root;
    }
};