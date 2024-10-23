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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (!root) return NULL;
        std::queue<TreeNode *> q;
        q.push(root);
        root->val = 0;
        while (!q.empty())
        {
            int n = q.size();
            int sum = 0;
            vector<TreeNode *> nodes;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                nodes.push_back(curr);
                if (curr->left)
                {
                    sum += curr->left->val;
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    sum += curr->right->val;
                    q.push(curr->right);
                }
            }
            for (auto node : nodes)
            {
                int sibSum = 0;
                if (node->left)
                    sibSum += node->left->val;
                if (node->right)
                    sibSum += node->right->val;
                int couSum = sum - sibSum;
                if (node->left)
                    node->left->val = couSum;
                if (node->right)
                    node->right->val = couSum;
            }
        }
        return root;
    }
};