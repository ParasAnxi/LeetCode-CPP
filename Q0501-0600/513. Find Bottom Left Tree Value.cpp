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
    int findBottomLeftValue(TreeNode *root)
    {
        if (root == NULL)
            return -1;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *leftAns = NULL;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            leftAns = curr;
            if (curr->right)
                q.push(curr->right);
            if (curr->left)
                q.push(curr->left);
        }
        return leftAns->val;
    }
};