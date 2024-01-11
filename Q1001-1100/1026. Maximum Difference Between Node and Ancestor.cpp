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
    int solve(TreeNode *root, int maxNodeVal, int minNodeVal)
    {
        int leftD, rightD;
        if (root->left && root->right == NULL)
        {
            leftD = solve(root->left, max(maxNodeVal, root->left->val), min(minNodeVal, root->left->val));
            return leftD;
        }
        else if (root->left == NULL && root->right){
            rightD = solve(root->right, max(maxNodeVal, root->right->val), min(minNodeVal, root->right->val));
            return rightD;
        }
        else if (root->left && root->right)
        {
            leftD = solve(root->left, max(maxNodeVal, root->left->val), min(minNodeVal, root->left->val));
            rightD = solve(root->right, max(maxNodeVal, root->right->val), min(minNodeVal, root->right->val));
            return max(leftD, rightD);
        }
        else
        {
            return (maxNodeVal - minNodeVal);
        }
    }
    int maxAncestorDiff(TreeNode *root)
    {
        if (root)
        {
            return solve(root, root->val, root->val);
        }
        return 0;
    }
};