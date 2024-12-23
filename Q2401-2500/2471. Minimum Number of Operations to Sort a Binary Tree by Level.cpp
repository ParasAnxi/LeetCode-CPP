/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int minimumOperations(TreeNode *root)
    {
        int swaps = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<pair<int, int>> v;
            v.reserve(n);
            while (n)
            {
                TreeNode *curr = q.front();
                v.emplace_back(curr->val, v.size());
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                q.pop();
                --n;
            }
            sort(v.begin(), v.end());
            int i = 0;
            while (i < v.size())
            {
                auto [value, id] = v[i];
                if (id != i)
                {
                    swap(v[i], v[id]);
                    ++swaps;
                }
                else
                    ++i;
            }
        }
        return swaps;
    }
};