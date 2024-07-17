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
    TreeNode *solve(TreeNode *root, set<int> &s, vector<TreeNode *> &ans)
    {
        if (root == NULL)
            return root;
        root->left = solve(root->left, s, ans);
        root->right = solve(root->right, s, ans);
        if (s.find(root->val) != s.end())
        {
            if (root->left != NULL)
                ans.push_back(root->left);
            if (root->right != NULL)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        set<int> s(to_delete.begin(), to_delete.end());
        TreeNode *res = solve(root, s, ans);
        if (res != NULL)
            ans.push_back(res);
        return ans;
    }
};