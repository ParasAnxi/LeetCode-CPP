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
    void pre(TreeNode *root, string &str)
    {
        if (root == NULL)
        {
            return;
        }
        str += to_string(root->val);

        if (root->left || root->right)
        {
            str += '(';
            pre(root->left, str);
            str += ')';
        }

        if (root->right)
        {
            str += '(';
            pre(root->right, str);
            str += ')';
        }
    }

public:
    string tree2str(TreeNode *root)
    {
        string str = "";
        pre(root, str);
        return str;
    }
};