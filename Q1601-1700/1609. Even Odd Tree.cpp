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
    bool bfs(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int siz = q.size();
            int t = INT_MIN;
            int t1 = INT_MAX;
            for (int i = 0; i < siz; i++)
            {

                TreeNode *front = q.front();
                q.pop();
                if (level % 2 == 0)
                {
                    if (front->val % 2 == 0)
                        return false;
                    if (front->val <= t)
                        return false;
                    t = front->val;
                }
                else
                {
                    if (front->val % 2 != 0)
                        return false;
                    if (front->val >= t1)
                        return false;
                    t1 = front->val;
                }
                if (front->left != NULL)
                {
                    q.push(front->left);
                }
                if (front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            level++;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode *root)
    {
        return bfs(root);
    }
};