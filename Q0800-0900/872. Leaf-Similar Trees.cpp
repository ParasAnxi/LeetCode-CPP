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
    void solve(TreeNode *root, vector<int> &mp)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            mp.push_back(root->val);
        solve(root->left, mp);
        solve(root->right, mp);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> m1, m2;
        solve(root1, m1);
        solve(root2, m2);
        int n = m1.size(), m = m2.size();
        if (n != m)
            return false;
        for (int i = 0; i < n; i++)
        {
            if (m1[i] != m2[i])
                return false;
        }
        return true;
    }
};