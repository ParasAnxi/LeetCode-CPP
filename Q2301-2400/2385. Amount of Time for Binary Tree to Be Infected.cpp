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
    int burnTree(TreeNode *node, unordered_map<TreeNode *, TreeNode *> &m)
    {
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        int time = 0;
        q.push(node);
        visited[node] = 1;

        while (!q.empty())
        {
            bool isBurn = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = 1;
                    isBurn = 1;
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = 1;
                    isBurn = 1;
                }
                if (m[front] && !visited[m[front]])
                {
                    q.push(m[front]);
                    visited[m[front]] = 1;
                    isBurn = 1;
                }
            }
            if (isBurn)
                ++time;
        }
        return time;
    }

    TreeNode *mapping(TreeNode *root, int start, unordered_map<TreeNode *, TreeNode *> &m)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node = NULL;
        m[root] = NULL;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->val == start)
                node = front;
            if (front->left)
            {
                q.push(front->left);
                m[front->left] = front;
            }
            if (front->right)
            {
                q.push(front->right);
                m[front->right] = front;
            }
        }
        return node;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> m;
        TreeNode *startNode = mapping(root, start, m);
        return burnTree(startNode, m);
    }
};