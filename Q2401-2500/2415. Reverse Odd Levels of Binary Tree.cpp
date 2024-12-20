/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
       perfect binary tree means completely filled binary tree
 * };
 */
class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }

        queue<TreeNode*> p;
        p.push(root);
        int l = 0, t, i;
        while (!p.empty())
        {
            vector<TreeNode *> v;
            t = pow(2, l);
            for (i = 0; i < t; i++)
            {
                TreeNode *l = p.front()->left;
                TreeNode *r = p.front()->right;
                p.pop();
                if (l != NULL && r != NULL)
                {
                    p.push(l);
                    p.push(r);
                    v.push_back(l);
                    v.push_back(r);
                }
            }
            l++;
            if (l % 2)
            {
                for (i = 0; i < (v.size() / 2); i++)
                {
                    swap(v[i]->val, v[v.size() - i - 1]->val);
                }
            }
        }
        return root;
    }
};