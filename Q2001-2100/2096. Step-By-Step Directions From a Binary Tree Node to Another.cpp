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
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node = NULL;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->val == startValue)
            {
                node = curr;
                break;
            }

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        unordered_map<int, TreeNode *> parent;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                parent[curr->left->val] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right->val] = curr;
                q.push(curr->right);
            }
        }

        unordered_set<TreeNode *> visited;
        q.push(node);
        unordered_map<TreeNode *, pair<TreeNode *, char>> vis;

        TreeNode *des = NULL;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            visited.insert(curr);

            if (curr->val == destValue)
            {
                des = curr;
                break;
            }

            if (parent.find(curr->val) != parent.end() && visited.find(parent[curr->val]) == visited.end())
            {
                TreeNode *parent = parent[curr->val];
                q.push(parent);
                vis[parent] = make_pair(curr, 'U');
            }

            if (curr->left && visited.find(curr->left) == visited.end())
            {
                q.push(curr->left);
                vis[curr->left] = make_pair(curr, 'L');
            }

            if (curr->right && visited.find(curr->right) == visited.end())
            {
                q.push(curr->right);
                vis[curr->right] = make_pair(curr, 'R');
            }
        }

        stack<char> res;
        TreeNode *curr = des;

        while (curr != node)
        {
            auto it = vis.find(curr);
            if (it != vis.end())
            {
                res.push(it->second.second);
                curr = it->second.first;
            }
        }

        string ans;
        while (!res.empty())
        {
            ans += res.top();
            res.pop();
        }

        return ans;
    }
};