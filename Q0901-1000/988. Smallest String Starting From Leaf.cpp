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
    void solve(TreeNode *root, string &ans, string temp)
    {
        if (!root)
            return;
        temp = char('a' + root->val) + temp;
        if (!root->left && !root->right)
        {
            ans = ans == "" ? temp : min(ans, temp);
            return;
        }
        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "";
        solve(root, ans, "");
        return ans;
    }
};