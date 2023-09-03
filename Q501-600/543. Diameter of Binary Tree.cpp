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
private:
    pair<int, int> diameter(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);

        int d1 = left.first;
        int d2 = right.first;
        int d3 = left.second + right.second;

        pair<int, int> ans;
        ans.second = max(left.second, right.second) + 1;
        ans.first = max(d1, max(d2, d3));

        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return diameter(root).first;
    }
};